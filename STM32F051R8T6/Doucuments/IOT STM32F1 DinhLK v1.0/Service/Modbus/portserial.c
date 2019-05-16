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
 * File: $Id: portserial.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbrtu.h"
#include "mbport.h"
#include "stm32f10x_usart.h"
#include "uart.h"
#include <intrinsics.h>
/* ----------------------- macro define ---------------------------------*/

/* ----------------------- static variables ---------------------------------*/
//static eMBParity  eCurrParity;
INTERNAL USART_TypeDef* g_stUSART_Use;

/* ----------------------- functions ---------------------------------*/
VOID USART2_IRQHandler();
UCHAR CalcParity( UCHAR ucData );

/* ----------------------- Start implementation -----------------------------*/
BOOL xMBPortSerialInit( UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{  
    NVIC_InitTypeDef NVIC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    /* Configure the NVIC Preemption Priority Bits */  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    /* Enable the USARTy Interrupt */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    
    switch (ucPORT)
    {
    case UART_PORT_1:
        {
            g_stUSART_Use = USART1;
            NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
            RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
            // RX
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
            GPIO_Init(GPIOA, &GPIO_InitStructure);
            //TX
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
            GPIO_Init(GPIOA, &GPIO_InitStructure);
        }
        break;
        
    case UART_PORT_2:
        {
            g_stUSART_Use = USART2;
            NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
            // RX
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
            GPIO_Init(GPIOA, &GPIO_InitStructure);
            //TX
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
            GPIO_Init(GPIOA, &GPIO_InitStructure);
        }
        break;
        
    case UART_PORT_3:
        {
            g_stUSART_Use = USART3;
            NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
            RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
            // RX
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
            GPIO_Init(GPIOB, &GPIO_InitStructure);
            //TX
            GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
            GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
            GPIO_Init(GPIOB, &GPIO_InitStructure);
        }
        break;
        
    default:
        break;
    }

    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    USART_InitStructure.USART_BaudRate = ulBaudRate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(g_stUSART_Use, &USART_InitStructure);
    /* Enable USARTz Receive and Transmit interrupts */
//    USART_ITConfig(g_stUSART_Use, USART_IT_RXNE, ENABLE);
//    USART_ITConfig(g_stUSART_Use, USART_IT_TXE, ENABLE);
    /* Enable the USARTz */
//    USART_Cmd(g_stUSART_Use, ENABLE);
    
    vMBPortSerialEnable( FALSE, FALSE );
    return TRUE;
}

void vMBPortClose( void )
{
    xMBPortSerialClose();
    vMBPortTimersDisable();
}

void xMBPortSerialClose( void )
{            
}

void vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{
    USART_Cmd(g_stUSART_Use, DISABLE);
    if (xRxEnable)
    {
        USART_ClearFlag(g_stUSART_Use, USART_FLAG_RXNE);
        USART_ITConfig(g_stUSART_Use, USART_IT_RXNE, ENABLE);
    }
    else
    {
        USART_ITConfig(g_stUSART_Use, USART_IT_RXNE, DISABLE);
    }
    
    if (xTxEnable)
    {
        USART_ClearFlag(g_stUSART_Use, USART_FLAG_TXE);
        USART_ITConfig(g_stUSART_Use, USART_IT_TXE, ENABLE);
    }
    else
    {
        USART_ITConfig(g_stUSART_Use, USART_IT_TXE, DISABLE);
    }
    USART_Cmd(g_stUSART_Use, ENABLE);
}

BOOL xMBPortSerialGetByte( CHAR * pucByte )
{
    *pucByte = (BYTE) USART_ReceiveData(g_stUSART_Use);
    return TRUE;
}

BOOL xMBPortSerialPutByte( CHAR ucByte )
{
    USART_SendData(g_stUSART_Use, ucByte);
    return TRUE;
}

VOID USART2_IRQHandler()
{
    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
        xMBRTUReceiveFSM();
    }
    
    if (USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
    {
        xMBRTUTransmitFSM();
    }
}
/******************************************************************************
 * Name:        CalcParity
 * Description: Calculates parity of ucData
 * Uses: 
 *     
 * Returns: Parity of ucData in bit 0 of returned UCHAR: 0 = even, 1 = odd
 *                
 * NOTE: For TX of 9 bit Even Parity, send the bit returned here in the 9th bit.
 *  For TX of 9 bit Odd Parity, send the complement of the returned bit in the 9th bit.
 *  For RX of 9 Bit Even Parity, parity is good if returned bit matches 9th RX bit.     
 *  For RX of 9 bit Odd Parity, parity is good if returned bit is complement of 9th RX bit.
 *****************************************************************************/
//UCHAR CalcParity( UCHAR ucData )
//{
//    asm
//    { 
//		movf   _ucData, W
//		;8-bit parity
//		;This routine will leave the parity of ucData in _ucData.0 
//		;while blenderizing most of the rest of _ucData
//		swapf   _ucData, W	;x =     abcdefgh  w =     efghabcd
//		xorwf   _ucData, F	;x =     abcdefgh  w =     efghabcd
//		rrcf    _ucData, W 	;x =     abcdefgh  w =     -abcdefg
//		xorwf   _ucData, F 	;x =     abcdefgh  w =     -abcdefg
//	
//		; at this point, the parity for half the bits
//		; (a, b, e, and f) is in bit 2 of X, and the
//		; parity for the other half (bits c, d, g, and h)
//		; is in bit 0 of X.
//	
//		btfsc   _ucData, 2 	; if the parity of (a,b,e,f) is 0,
//						; then the parity of (a,b,c,d,e,f,g,h)
//						; is equal to the parity of (c,d,g,h)...
//						; which is already in bit 0, so skip ahead.
//	
//	
//		incf    _ucData, F 	; otherwise, the parity of (a,b,e,f) is 1,
//						; so the parity of (a,b,c,d,e,f,g,h) is
//						; NOT equal to the parity of (c,d,g,h).
//						; invert bit 0.
//	
//		; at this point, bit 0 of _ucData contains the parity of
//		; (a,b,c,d,e,f,g,h).
//	}
//	return ucData & 0x01;
//}    