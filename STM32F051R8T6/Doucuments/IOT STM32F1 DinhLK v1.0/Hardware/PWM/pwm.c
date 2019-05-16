#include "stm32f10x_tim.h"
#include "stm32f10x.h"
#include "device.h"
#include "parameter.h"
#include "pwm.h"

INTERNAL TIM_TimeBaseInitTypeDef  g_stTIMTimeBaseStructure;
INTERNAL TIM_OCInitTypeDef  g_stTIMOCInitStructure;

INTERNAL VOID GPIOPWMConfiguration();

VOID InitPWM()
{
    GPIOPWMConfiguration();
    INTERNAL TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_AFIO, ENABLE);
    
	/* TIM1 Configuration ---------------------------------------------------
	TIMxCLK = 24 MHz, Prescaler = 5, TIMx counter clock = 4.8 MHz
	TIMx frequency = TIMxCLK/(TIMx_Period + 1) = 10 000 Hz
	----------------------------------------------------------------------- */
    g_stTIMTimeBaseStructure.TIM_Prescaler = 2 - 1;
    g_stTIMTimeBaseStructure.TIM_ClockDivision = 0;
    g_stTIMTimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    g_stTIMTimeBaseStructure.TIM_Period = 480 - 1;
    g_stTIMTimeBaseStructure.TIM_ClockDivision = 0;
    g_stTIMTimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1, &g_stTIMTimeBaseStructure);
	
    g_stTIMOCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ok
    g_stTIMOCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    g_stTIMOCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    g_stTIMOCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    g_stTIMOCInitStructure.TIM_OutputNState = TIM_OCNIdleState_Reset;

    
    g_stTIMOCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    
    g_stTIMOCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Set;
    g_stTIMOCInitStructure.TIM_Pulse = 0;

    TIM_OC1Init(TIM1, &g_stTIMOCInitStructure);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
    
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Disable; //The Off-State selection used in Run mode.
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSIState_Disable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
    TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;// Break input
    TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High; //
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable; // TIM Automatic Output feature is enabled
    TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);
    
    TIM_ARRPreloadConfig(TIM1, ENABLE);
    TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE); 
    SetDutyCycle(PWM_CHANNEL_1, 700); //50%
}
// InPut %
VOID SetDutyCycle(BYTE nChannel, WORD nDutyCycle)
{
    WORD nPWM_CCR;
    nPWM_CCR =  nDutyCycle*480/100;
    
	switch (nChannel)
	{
	case PWM_CHANNEL_1:
		TIM1->CCR1 = nPWM_CCR;
		break;
        
	case PWM_CHANNEL_2:
		TIM1->CCR2 = nPWM_CCR;
		break;
        case PWM_CHANNEL_3:
        TIM1->CCR3 = nPWM_CCR;
        break;
        
        case PWM_CHANNEL_4:
        TIM1->CCR4 = nPWM_CCR;
        break;
        
    default:
        break;
	}
}

INTERNAL VOID GPIOPWMConfiguration()
{
      GPIO_InitTypeDef GPIO_InitStructure;
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
      GPIO_Init(GPIOA, &GPIO_InitStructure);
      
}