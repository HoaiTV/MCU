/*
* FreeModbus Libary: BARE Port
* Copyright (C) 2006 Christian Walter <wolti@sil.at>
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*
* File: $Id: porttimer.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
*/

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "mbrtu.h"
#include "stm32f10x_tim.h"

/* ----------------------- static functions ---------------------------------*/
VOID TIM2_IRQHandler();
SHORT wTimerVal;

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBPortTimersInit( USHORT usTim1Timerout50us )
{      
    WORD nPrescaler;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  
    NVIC_InitTypeDef NVIC_InitStructure; 
    
    nPrescaler = SystemCoreClock / 20000; //50 us
    wTimerVal = usTim1Timerout50us;
    /*  --------------------------------------------------------------- */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    /* Time base configuration */
    TIM_TimeBaseStructure.TIM_Period = wTimerVal - 1;
    TIM_TimeBaseStructure.TIM_Prescaler = nPrescaler - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    
    /* Enable the TIM2 Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
    NVIC_Init(&NVIC_InitStructure); 
    
    TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
    TIM_Cmd(TIM2, DISABLE);
    return TRUE;
}
/*------------------------------------------------------------------------------- 
Function: TIM2_IRQHandler
Purpose: TIM2_IRQHandler
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
void vMBPortTimerClose( void )
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
/*------------------------------------------------------------------------------- 
Function: vMBPortTimersEnable
Purpose: vMBPortTimersEnable
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
void vMBPortTimersEnable( SHORT wTimerLoad )
{
    TIM_SetAutoreload(TIM2, wTimerLoad);
    TIM_SetCounter(TIM2, 0);
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}
/*------------------------------------------------------------------------------- 
Function: vMBPortTimersDisable
Purpose: vMBPortTimersDisable
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
void vMBPortTimersDisable( void )
{
    TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
    TIM_Cmd(TIM2, DISABLE);
}
/*------------------------------------------------------------------------------- 
Function: TIM2_IRQHandler
Purpose: TIM2_IRQHandler
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID TIM2_IRQHandler()
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        xMBRTUTimerT35Expired();
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
