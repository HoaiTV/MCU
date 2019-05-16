#include "timer.h"
#include "adc.h"
#include "io.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "ds18b20.h"
#include "uart.h"
#include "system.h"
#include "hw_timer.h"
#include "service_io.h"

#define JSN_ECHO              GPIO_Pin_6 // PA6
#define JSN_TRIGGER         GPIO_Pin_5 // PA5
#define JSN_PORT_ECHO         GPIO_PORTA
#define JSN_PORT_TRIGGER       GPIO_PORTA
#define JNS_DELAY_US(a)     { WORD delay = (a) * 10; for (WORD index = 0; index < delay; index++) asm("NOP");}
#define JNS_TIMEOUT         200
#define SOUND_SPEED 342122 // cm/s
INTERNAL WORD g_Distant = 0;
INTERNAL WORD g_LevelWater = 0;

DWORD g_Timer = 0;

VOID ReadJnsProcess(PVOID pDATA)
{     
      DWORD nTime =0;
      SetPin(JSN_PORT_TRIGGER, JSN_TRIGGER, 0); 
      JNS_DELAY_US(1000);
      SetPin(JSN_PORT_TRIGGER, 0, JSN_TRIGGER);
      
      nTime = GetTickCount();
      while (GetPin(JSN_PORT_ECHO, JSN_ECHO ) == 0)
      {
        if((GetTickCount()- nTime)>JNS_TIMEOUT)  break; 
      };
      EnableHwTimer();
      nTime = GetTickCount();
      while (GetPin(JSN_PORT_ECHO, JSN_ECHO ) != 0)
      {
        if((GetTickCount()- nTime)>JNS_TIMEOUT)  break; 
      }; 
      g_Timer = GetCounter();
      
      DisableHwTimer();
      g_Distant = g_Timer/58;
      g_LevelWater = 35 - g_Distant;
      if(g_Distant>10) SetPin(RELAY4_PORT, RELAY4_PIN, 0);//1
      else SetPin(RELAY4_PORT, 0, RELAY4_PIN);//0
      WriteUartTransmit(UART_PORT_2,0x21,g_LevelWater);
      StartLongTimer(2, ReadJnsProcess, NULL);
}

VOID InitJns()
{
      
      HwTimer_Init();
      SetDirPin(JSN_PORT_TRIGGER, 0, JSN_TRIGGER);// set up power for TDS sensor
      SetPin(JSN_PORT_TRIGGER, 0, JSN_TRIGGER); 
      StartShortTimer(100, ReadJnsProcess, NULL);
}



