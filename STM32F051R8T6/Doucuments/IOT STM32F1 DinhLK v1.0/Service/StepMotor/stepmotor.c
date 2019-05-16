#include "timer.h"
#include "io.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "uart.h"
#include "system.h"
#include "stepmotor.h"

#define STEPMOTOR_EN          GPIO_Pin_11 // PB11
#define STEPMOTOR_DIR         GPIO_Pin_1 // PB1
#define STEPMOTOR_STEP        GPIO_Pin_10 // PB10

#define STEPMOTOR_PORT        GPIO_PORTB
#define STEP_DELAY_US(a)     { WORD delay = (a) * 10; for (WORD index = 0; index < delay; index++) asm("NOP");}
INTERNAL WORD g_Step =0;

VOID StepMotorControl(BYTE nDirect, WORD nStep);
VOID OneStepMotorControl(BYTE nDirect);

VOID InitStepMotor()
{
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA |\
		RCC_APB2Periph_AFIO, ENABLE);
      
      SetDirPin(STEPMOTOR_PORT, 0, STEPMOTOR_EN);
      SetDirPin(STEPMOTOR_PORT, 0, STEPMOTOR_DIR);
      SetDirPin(STEPMOTOR_PORT, 0, STEPMOTOR_STEP);
      //SetPin(STEPMOTOR_PORT, STEPMOTOR_EN, 0); //1
      //STEP_DELAY_US(1000);
      SetPin(STEPMOTOR_PORT, 0, STEPMOTOR_EN);//0
      //GPIO_SetBits(STEPMOTOR_PORT,STEPMOTOR_DIR);
      //GPIO_SetBits(STEPMOTOR_PORT,STEPMOTOR_STEP);
       StepMotorControl(1,5000);
}

VOID StepMotorControl(BYTE nDirect, WORD nStep)
{
    g_Step = nStep;
    OneStepMotorControl(nDirect);
}
VOID OneStepMotorControl(BYTE nDirect)
{
  if (nDirect) 
    {
      SetPin(STEPMOTOR_PORT, STEPMOTOR_DIR, 0); //0
      
    } 
  else 
    {
      SetPin(STEPMOTOR_PORT, 0, STEPMOTOR_DIR);//1
      //GPIO_ResetBits(STEPMOTOR_PORT,STEPMOTOR_DIR);
    } 
      
      SetPin(STEPMOTOR_PORT, STEPMOTOR_STEP, 0); //0
      STEP_DELAY_US(1000);
      SetPin(STEPMOTOR_PORT, 0, STEPMOTOR_STEP);//1
     
      
      if(g_Step > 0)
      {
        StartShortTimer(1, (SYSTEMCALLBACK)OneStepMotorControl, (PVOID)&nDirect);
        g_Step--;
      }
      else 
      {
        SetPin(STEPMOTOR_PORT, STEPMOTOR_EN, 0); //1
      }
}






