#include "timer.h"
#include "io.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "uart.h"
#include "system.h"
#include "blinkled.h"

#define LED_PIN               GPIO_Pin_5 // PB5
#define LED_PORT              GPIO_PORTB

INTERNAL BYTE gFlag = 1;
INTERNAL BYTE gFlag1 = 1;
//INTERNAL BYTE nIndex = 0;
INTERNAL BYTE gNumber=0;
INTERNAL BYTE gNumber1=0;
VOID LedOn();
VOID LedOff();
VOID LedProcess(PVOID pData);
VOID LedProcessFast(PVOID pData);


VOID InitLed()
{
      SetDirPin(LED_PORT, 0, LED_PIN);
      LedSet(3);
}
VOID InitLedFast()
{
      SetDirPin(LED_PORT, 0, LED_PIN);
      LedSetFast(3);
}
VOID LedSet( BYTE nIndex)
          {
          gNumber=2*nIndex;
          LedProcess(NULL);
          }
VOID LedSetFast( BYTE nIndex1)
          {
          gNumber1=2*nIndex1;
          LedProcessFast(NULL);
          }

VOID LedProcess(PVOID pData)
{ 
          if(gFlag){
              LedOn();
              gFlag = 0;
                   }
          else 
          {
            LedOff();
            gFlag = 1;
          }
           gNumber--;
          if(gNumber > 0)
          {
           StartLongTimer(1, LedProcess, NULL);
          }
  
}
VOID LedProcessFast(PVOID pData)
{ 
          if(gFlag1){
              LedOn();
              gFlag1 = 0;
                   }
          else 
          {
            LedOff();
            gFlag1 = 1;
          }
           gNumber1--;
          if(gNumber1 > 0)
          {
           StartShortTimer(500, LedProcessFast, NULL);
          }
  
}
VOID LedOn()
{
      SetPin(LED_PORT, LED_PIN, 0);
}     
VOID LedOff()
{
      SetPin(LED_PORT, 0, LED_PIN);
}






