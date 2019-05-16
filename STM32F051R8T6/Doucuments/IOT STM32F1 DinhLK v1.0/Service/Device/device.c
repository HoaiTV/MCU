#include "uart.h"
#include "timer.h"
#include "parameter.h"
#include "system.h"
#include "string.h"
#include "io.h"
#include "device.h"

#define RS485_DE_PORT       GPIO_PORTB
#define RS485_RE_PORT       GPIO_PORTB
#define RS485_DE_PIN        GPIO_Pin_15
#define RS485_RE_PIN        GPIO_Pin_14

#define REGISTER_COUNT                  64
#define UPDATE_BUFFER_INTERVAL          100

#define MAX_REGISTER_PART               16

//rs 485 tranceiver timeout 50mss
#define RS485_TRANSCIEVER_TIMEOUT()     { WORD _nTimeout = GetTickCount(); \
    while ((GetTickCount() - _nTimeout) < 4); }

#define CONTROL_EVENT           0
#define SCHEDULE_EVENT          1

typedef struct tagDEVICEREGISTERPART {
    BYTE nRegister;
    BYTE nValue;
} DEVICEREGISTERPART, *PDEVICEREGISTERPART;

typedef struct tagDEVICEREGISTER {
    union {
        struct {
            BYTE nRegister;
            BYTE nValue;
        };
        DEVICEREGISTERPART pPart[1];
    };
} DEVICEREGISTER, *PDEVICEREGISTER;

#define _PDEVICEREGISTER(buffer) ((PDEVICEREGISTER)(buffer))
#define _PDEVICEPARAM(buffer) ((PDEVICEPARAM)(buffer))

typedef struct tagDEVICEPARAMPART {
    WORD nParam;
    WORD nValue;
} DEVICEPARAMPART, *PDEVICEPARAMPART;

typedef struct tagDEVICEPARAM {
    union {
        struct {
            WORD nParam;
            WORD nValue;
        };
        DEVICEPARAMPART pPart[1];
    };
} DEVICEPARAM, *PDEVICEPARAM;

//short buffer
#define PACKAGE_TYPE_DEFINITION_REQ     0x6A
#define PACKAGE_TYPE_REGISTER_REQ       0x68
#define PACKAGE_TYPE_PARAM_REQ          0x69

#define PACKAGE_TYPE_SCHEDULE_UPDATE    0x64
#define PACKAGE_TYPE_REGISTER_UPDATE    0x65
#define PACKAGE_TYPE_PARAM_UPDATE       0x66
#define PACKAGE_TYPE_RESET_WIFI         0x78

#define PACKAGE_TYPE_OTA_START          0x38
#define PACKAGE_TYPE_LOCATION           0x79
#define PACKAGE_TYPE_RESET_DEVICE       0x7A
#define PACKAGE_TYPE_REBOOT_DEVICE      0x7B

//long buffer
#define PACKAGE_TYPE_DEFINITION_RES     0x67
#define PACKAGE_TYPE_REGISTER_RES       0x65
#define PACKAGE_TYPE_PARAM_RES          0x66

INTERNAL BYTE g_nDeviceAddr = 0;

INTERNAL BYTE g_pRegisters[REGISTER_COUNT] = { 0 };
PBYTE REGISTERS = g_pRegisters;

INTERNAL PREGISTEREVENT g_pRegisterEvent = NULL;
INTERNAL BYTE g_nRegisterValue = 0;

INTERNAL DEVICEREGISTERPART g_pPendingRegisters[MAX_REGISTER_PART] = { 0 };
INTERNAL BYTE g_nPendingRegisterCount = 0;

INTERNAL SYSTEMCALLBACK g_pDeviceEvents[DEVICE_EVENT_COUNT] = { NULL };

INTERNAL VOID OnUartDataProc(PVOID pData);
INTERNAL VOID ProcessCustomRegister(PREGISTEREVENT pEvent);
INTERNAL VOID PopulateParameters();
INTERNAL VOID UpdateRegisterProc(PVOID pData);
INTERNAL VOID SendDefinitionProc();
INTERNAL VOID AllocatedBuffer(BYTE nType, BYTE nCommand, PVOID pData, WORD nLength);

VOID InitDevice(BYTE nDeviceAddr)
{
    g_nDeviceAddr = nDeviceAddr;
    
    SetDirPin(RS485_DE_PORT, 0, RS485_DE_PIN);
    SetDirPin(RS485_RE_PORT, 0, RS485_RE_PIN);
    SetPin(RS485_DE_PORT, 0, RS485_DE_PIN);
    SetPin(RS485_RE_PORT, 0, RS485_RE_PIN);

    RegisterUartCallback(UART_DATA_EVENT, OnUartDataProc);
    
    for (BYTE nIndex = 0; nIndex < REGISTER_COUNT; nIndex++)
        g_pRegisters[nIndex] = INVALID_REGISTER_VALUE;
    
    StartShortTimer(UPDATE_BUFFER_INTERVAL, UpdateRegisterProc, NULL);
}

VOID  RegisterDeviceCallback(BYTE nEvent, SYSTEMCALLBACK fnDeviceCallback)
{
    if (nEvent < DEVICE_EVENT_COUNT)
    {
        g_pDeviceEvents[nEvent] = fnDeviceCallback;
    }
}

VOID ResetDevice()
{
    ResetParams();
    Reboot();
}

BOOL IsFlashing()
{
    return TRUE;
}

BOOL IsConnected()
{
    return FALSE;
}

VOID SetRegister(BYTE nRegister, BYTE nValue)
{
    g_pRegisters[nRegister] = nValue;
//	AppendRegister(nRegister, nValue);
}

VOID RestoreRegister()
{
    if ((g_pRegisterEvent != NULL) && (g_pRegisterEvent->nValue != CURRENT_REGISTER_VALUE))
    {
        g_pRegisters[g_pRegisterEvent->nRegister] = g_nRegisterValue;
//        AppendRegister(g_pRegisterEvent->nRegister, g_nRegisterValue);
        g_pRegisterEvent = NULL;
    }
}

VOID PopulateRegisters()
{
    BYTE nSizeBuffer = 0;
    DEVICEREGISTERPART arTemp[REGISTER_COUNT] = { 0 };
    
    for (BYTE nIndex = 0; nIndex < REGISTER_COUNT; nIndex++)
    {
        if (g_pRegisters[nIndex] != INVALID_REGISTER_VALUE)
        {
            arTemp[nSizeBuffer].nRegister = nIndex;
            arTemp[nSizeBuffer].nValue = g_pRegisters[nIndex];
            nSizeBuffer++;
        }
    }
    
    if (nSizeBuffer != 0)
        AllocatedBuffer(LONG_BUFFER, PACKAGE_TYPE_REGISTER_UPDATE, (PVOID)arTemp, (WORD)(nSizeBuffer << 1));
}

//internal function
INTERNAL VOID OnUartDataProc(PVOID pData)
{
    PUARTBUFFER pBuffer = (PUARTBUFFER) pData;
    PBYTE pDataRemote = (PBYTE)pBuffer->pData;
    WORD nLength = pBuffer->nLength;
    
    if (pBuffer->nAddr != g_nDeviceAddr)
        return;

    switch (pBuffer->nCommand)
    {
    case PACKAGE_TYPE_DEFINITION_REQ:
        SendDefinitionProc();
        break;
        
    case PACKAGE_TYPE_REGISTER_REQ:
        PopulateRegisters();
        break;
        
    case PACKAGE_TYPE_PARAM_REQ:
        PopulateParameters();
        break;
        
    case PACKAGE_TYPE_RESET_DEVICE:
        ResetDevice();
        break;
        
    case PACKAGE_TYPE_REBOOT_DEVICE:
        Reboot();
        break;
        
    case PACKAGE_TYPE_REGISTER_UPDATE: case PACKAGE_TYPE_SCHEDULE_UPDATE:
        {
            BYTE nCount = nLength / sizeof(DEVICEREGISTERPART);
            for (BYTE nIndex = 0; nIndex < nCount; nIndex++)
            {
                REGISTEREVENT stEvent = {
                    0, 
                    _PDEVICEREGISTER(pDataRemote)->pPart[nIndex].nRegister,
                    _PDEVICEREGISTER(pDataRemote)->pPart[nIndex].nValue,
                    g_pRegisters[_PDEVICEREGISTER(pDataRemote)->pPart[nIndex].nRegister]
                };				
                ProcessCustomRegister(&stEvent);
            }
        }
        break;
        
    case PACKAGE_TYPE_PARAM_UPDATE:
        {
            BYTE nCount = nLength / sizeof(DEVICEPARAMPART); 
            for (BYTE nIndex = 0; nIndex < nCount; nIndex++)
            {   
                PARAMEVENT stEvent ={
                    DEVICE_PARAM_EVENT,
                    _PDEVICEPARAM(pDataRemote)->pPart[nIndex].nParam,
                    _PDEVICEPARAM(pDataRemote)->pPart[nIndex].nValue
                };
                
                if (g_pDeviceEvents[DEVICE_PARAM_EVENT] != NULL)
                {
                    g_pDeviceEvents[DEVICE_PARAM_EVENT]((PVOID)&stEvent);
                }
                
                if (stEvent.nValue != INVALID_PARAMETER_VALUE)
                {
                    if (!SetParam(stEvent.nParam, stEvent.nValue))
                        stEvent.nValue = INVALID_PARAMETER_VALUE;
                }
            }
        }
        break;
          
    case PACKAGE_TYPE_OTA_START:
        break;
        
    case PACKAGE_TYPE_LOCATION:
        if (g_pDeviceEvents[DEVICE_LOCATE_EVENT] != NULL)
            g_pDeviceEvents[DEVICE_LOCATE_EVENT](pDataRemote);
        break;
        
    default:
        break;
    }
}

INTERNAL VOID ProcessCustomRegister(PREGISTEREVENT pEvent)
{
    g_pRegisterEvent = pEvent;
    if ((g_pRegisterEvent->nValue != CURRENT_REGISTER_VALUE) && (g_pRegisterEvent->nRegister < REGISTER_COUNT))
    {
        g_nRegisterValue = g_pRegisters[g_pRegisterEvent->nRegister];
        g_pRegisters[g_pRegisterEvent->nRegister] = g_pRegisterEvent->nValue;
    }
    
    if (g_pDeviceEvents[DEVICE_REGISTER_EVENT] != NULL)
        g_pDeviceEvents[DEVICE_REGISTER_EVENT](g_pRegisterEvent);
    
    g_pRegisterEvent = NULL;
}

INTERNAL VOID PopulateParameters()
{ 
    WORD nCount = 0;
    DEVICEPARAMPART arDeviceParamPart[MAX_PARAM_ITEM];
    
    for (BYTE nIndex = 0; nIndex < g_nParamCount; nIndex++)
    {
        arDeviceParamPart[nCount].nParam = PARAM_ITEMS[nIndex]->nParam;
        arDeviceParamPart[nCount].nValue = PARAM_ITEMS[nIndex]->nValue;
        nCount++;  
    }
    AllocatedBuffer(LONG_BUFFER, PACKAGE_TYPE_PARAM_UPDATE, (PVOID)arDeviceParamPart, (nCount << 2));
}

//INTERNAL VOID AppendRegister(BYTE nRegister, BYTE nValue)
//{
//    g_pPendingRegisters[g_nPendingRegisterCount].nRegister = nRegister;
//	g_pPendingRegisters[g_nPendingRegisterCount].nValue = nValue;
//	g_nPendingRegisterCount++;
//	
//	if (g_nPendingRegisterCount == MAX_REGISTER_PART)
//		UpdateRegisterProc(NULL);
//}

INTERNAL VOID UpdateRegisterProc(PVOID pData)
{
    if (g_nPendingRegisterCount != 0)
    {
        AllocatedBuffer(SHORT_BUFFER, PACKAGE_TYPE_REGISTER_RES, g_pPendingRegisters, (g_nPendingRegisterCount << 1));
        g_nPendingRegisterCount = 0;
    }
    StartShortTimer(UPDATE_BUFFER_INTERVAL, UpdateRegisterProc, NULL);
}

INTERNAL VOID SendDefinitionProc()
{
    BYTE nAddress = g_nDeviceAddr;
    AllocatedBuffer(SHORT_BUFFER, PACKAGE_TYPE_DEFINITION_RES, &nAddress, 1);
}

INTERNAL VOID AllocatedBuffer(BYTE nType, BYTE nCommand, PVOID pData, WORD nLength)
{
    UARTBUFFER stBuffer = { 0 };
    
    stBuffer.nLength = nLength;
    stBuffer.nTypeBuffer = nType;
    stBuffer.nAddr = 0x01;
    stBuffer.nCommand = nCommand;
    stBuffer.pData = pData;
    
    RS485_TRANSCIEVER_TIMEOUT();
    SetPin(RS485_RE_PORT, RS485_RE_PIN, 0);
    SetPin(RS485_DE_PORT, RS485_DE_PIN, 0);
    
    //WriteUartIndirect(g_nUartPort, &stBuffer);
    
    RS485_TRANSCIEVER_TIMEOUT();
    SetPin(RS485_DE_PORT, 0, RS485_DE_PIN);
    SetPin(RS485_RE_PORT, 0, RS485_RE_PIN);
}