
/* Includes ------------------------------------------------------------------*/
#include "system.h"
#include "uart.h"
#include "device.h"
#include "timer.h"
#include "io.h"
#include "adc.h"
#include "service_io.h"
#include "ds18b20.h"
#include "pwm.h"
#include "dimmer.h"
#include "parameter.h"
#include "Params.h"
#include "JSNSensor.h"
#include "user_delay.h"
#include "lcd16x2.h"
#include "stepmotor.h"
#include "buzz.h"
#include "blinkled.h"
/*-----------------------------------------------------------------------------*/
//Pin identification address device
#define SW1_ADDR_PIN        GPIO_Pin_6
#define SW2_ADDR_PIN        GPIO_Pin_7
#define SW3_ADDR_PIN        GPIO_Pin_8
#define SW4_ADDR_PIN        GPIO_Pin_9
#define SW_ADDR_PORT        GPIO_PORTB

//INTERNAL VOID GetDataSensor(PVOID pData);
INTERNAL VOID InitRegister();
INTERNAL VOID DefineParamProc(PVOID pParam);
INTERNAL VOID OnDeviceRegisterProc(PVOID pEvent);
INTERNAL VOID ParamChangeProc(PVOID pParameter);
INTERNAL BYTE GetDeviceAddress();
VOID GetDataSensor(PVOID pData);
//INTERNAL VOID OnDeviceParamsProc(PVOID pConfig);
//INTERNAL VOID Test()
//{
//  
//StartShortTimer(1000, (SYSTEMCALLBACK)WriteUartIndirect, NULL);
// 
//}
VOID main()
{
    InitSystem();
    OpenUartPort(UART_PORT_2, UART_BAUD_RATE_115200);
    InitIO();
    
    InitParameter(DefineParamProc);
    InitDevice(GetDeviceAddress());
    InitRegister();
    InitBuzz();
    InitLed();
    //InitLedFast();
    InitADC();
    InitIOService(); 
    DS18B20_Init();
    InitDimmer();
    InitJns();
    InitPWM();
    
    RegisterDeviceCallback(DEVICE_REGISTER_EVENT, OnDeviceRegisterProc);
    RegisterParamCallback(PARAM_CHANGE_EVENT, ParamChangeProc);
	
    StartShortTimer(1000, GetDataSensor, NULL);
    //ActivateWatchdog();
    
    while (TRUE)
      
    
    {
        ProcessTimerEvents();
        ProcessUartEvents();    
        //ResetWatchdog();
    }
}
 
VOID GetDataSensor(PVOID pData)
{
      DS18B20DATA Ds18b20Data;
      DS18B20_ReadTemperature(&Ds18b20Data);
      StartShortTimer(1000, GetDataSensor, NULL);
}

INTERNAL VOID InitRegister()
{
    RELAY1 = 0;
    RELAY2 = 0;
    RELAY3 = 0;
    RELAY4 = 0;
    LIGHT1 = 0;
    LIGHT1_CURRENT = 0;
    LIGHT_SS1 = 0;
}
INTERNAL VOID DefineParamProc(PVOID pParam)
{
    for (BYTE nIndex = 0; nIndex < 10; nIndex++)
    {
        DEFINE_PARAM(nIndex, nIndex + 1, nIndex + 1);
    }
}

INTERNAL VOID ParamChangeProc(PVOID pParameter)
{
 	PPARAMCHANGEEVENT pEvent = (PPARAMCHANGEEVENT)pParameter;
 	switch (pEvent->nParam)
 	{
    default:
        break;
 	}
}

INTERNAL VOID OnDeviceRegisterProc(PVOID pEvent)
{
}

INTERNAL BYTE GetDeviceAddress()
{
    WORD nAddress = GetAllPins(SW_ADDR_PORT);
    
    nAddress >>= 6;
    nAddress &= 0x0F;
    return (BYTE)(nAddress + 2);
}
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, DWORD line)
{ 
    while (1) {
    }
}
#endif