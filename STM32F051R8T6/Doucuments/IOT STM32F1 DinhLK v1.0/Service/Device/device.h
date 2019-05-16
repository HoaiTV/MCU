#ifndef __DEVICE_H__
#define __DEVICE_H__

#define ROOT                        0x0001

#define DEVICE_REGISTER_EVENT	    0
#define DEVICE_PARAM_EVENT		    1
#define DEVICE_LOCATE_EVENT         2

#define DEVICE_EVENT_COUNT		    3

#define INVALID_REGISTER_VALUE 	    0xFF
#define CURRENT_REGISTER_VALUE	    0xFF
#define INVALID_PARAMETER_VALUE	    0xFFFF

typedef struct tagREGISTEREVENT {
    BYTE nEvent;
    BYTE nRegister;
    BYTE nValue;
    BYTE nOldValue;
} REGISTEREVENT, *PREGISTEREVENT;

#pragma pack(1)
typedef struct tagPARAMEVENT {
    BYTE nEvent;
    WORD nParam;
    WORD nValue;
} PARAMEVENT, *PPARAMEVENT;

VOID InitDevice(BYTE nDeviceAddr);
VOID RegisterDeviceCallback(BYTE nEvent, SYSTEMCALLBACK fnDeviceCallback);
VOID ResetDevice();
BOOL IsFlashing();
BOOL IsConnected();

VOID SetRegister(BYTE nRegister, BYTE nValue);
VOID RestoreRegister();
VOID PopulateRegisters();

EXTERNAL PBYTE REGISTERS;

#endif // __DEVICE_H__