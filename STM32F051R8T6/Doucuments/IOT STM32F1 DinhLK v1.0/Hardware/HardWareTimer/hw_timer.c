#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "hw_timer.h"

INTERNAL volatile BOOL g_nInterruptFlag = FALSE;

VOID TIM2_IRQHandler(VOID);

VOID HwTimer_Init()
{
    TIM_TimeBaseInitTypeDef g_stTIMTimeBaseStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    g_stTIMTimeBaseStructure.TIM_Period = 0xFFFF;
    g_stTIMTimeBaseStructure.TIM_Prescaler = SystemCoreClock / 1000000 - 1; // Moi xung la 10us
    g_stTIMTimeBaseStructure.TIM_ClockDivision = 0;
    g_stTIMTimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    g_stTIMTimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &g_stTIMTimeBaseStructure);
    
    DisableHwTimer();
}

VOID TIM2_IRQHandler()
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        DisableHwTimer();
    }
}

VOID EnableHwTimer()
{
    NVIC_InitTypeDef NVIC_InitStructure;    
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
    NVIC_Init(&NVIC_InitStructure);    
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    TIM_SetCounter(TIM2,0);
    TIM_Cmd(TIM2, ENABLE);
    
}

VOID DisableHwTimer()
{
    NVIC_InitTypeDef NVIC_InitStructure;    
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;    
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
    TIM_Cmd(TIM2, DISABLE);
}


WORD GetCounter()
{
  
  return TIM_GetCounter(TIM2);
}