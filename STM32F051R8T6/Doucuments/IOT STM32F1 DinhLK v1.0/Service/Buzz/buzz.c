#include "timer.h"
#include "io.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "uart.h"
#include "system.h"
#include "buzz.h"

#define BUZZ_PIN               GPIO_Pin_12 // PB12
#define BUZZ_PORT              GPIO_PORTB
INTERNAL BYTE gNumber=0;
INTERNAL BYTE gFlag=1;

VOID BuzzOn();
VOID BuzzOff();
VOID BuzzProcess(PVOID pData);



VOID InitBuzz()
{
      SetDirPin(BUZZ_PORT, 0, BUZZ_PIN);
      BuzzSet(1);
}
VOID BuzzSet( BYTE nIndex)
{
  gNumber = 2*nIndex;
  BuzzProcess(NULL);
  
}

VOID BuzzProcess(PVOID pData)
{ 
  if(gFlag){
      BuzzOn();
      gFlag = 0;
           }
  else 
  {
    BuzzOff();
    gFlag = 1;
  }
  gNumber--;
  if(gNumber > 0)
  {
   StartShortTimer(200, BuzzProcess, NULL);
  }
  else 
  {
    BuzzOff();
    gFlag = 1;
  }
  
}
VOID BuzzOn()
{
      SetPin(BUZZ_PORT, BUZZ_PIN, 0);
 
}     
VOID BuzzOff()
{
 SetPin(BUZZ_PORT, 0, BUZZ_PIN);
}






