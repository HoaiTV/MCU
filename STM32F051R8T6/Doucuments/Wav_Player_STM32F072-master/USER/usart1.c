//------------------------------------------------------------------------
// $Id
// 
// Copyright (C), 2004-2010, Centerm Information Co.,Ltd,All Rights Reserved
//
// FileName: usart1_app.c 
//
// Author: wangpeng
//
// Version: 1.0
//
// Date: 2012-11-29
//
// Description: 
// 
// Function List: 
//
// History: already change PINA2;PINA3;
//--------------------------------------------------------------------------
//#include "global.h"
#include "main.h"
#include "wav.h"
#include "usart1.h"


void USART2_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    USART_InitTypeDef USART_InitStructure;    

    /* Enable GPIO clock */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

    /* Enable USART clock - USART2  */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    
    /* Connect PXx to USART2_Tx */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);

    /* Connect PXx to USART2_Rx */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);
    
    /* Configure USART2 Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Configure USART2 Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* USARTx configured as follow:
    - BaudRate = 115200 baud  
    - Word Length = 8 Bits
    - Stop Bit = 1 Stop Bit
    - Parity = No Parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
    */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART2, &USART_InitStructure);

    /* Enable the usart2 receive interrupt */
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

    /* Enable USART */
    USART_Cmd(USART2, ENABLE);
	
    /* Enable the USARTy Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    

}

void SerialPutChar(uint8_t c)
{ 
  USART_SendData(USART2 , c);
  
  while (USART_GetFlagStatus(USART2 , USART_FLAG_TXE) == RESET)
  {}
}

/**
  * @brief  Print a string on the HyperTerminal
  * @param  s: The string to be printed
  * @retval None
  */
void Serial_PutString(uint8_t *s)
{
	while (*s != '\0')
	{
		SerialPutChar(*s);
		s++;
	}
}


