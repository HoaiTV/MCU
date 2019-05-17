/******************************************************************************** 
Copyright (C) 2008-2009,
Product
Module: 
Version: 1.0
Author: DUONG MANH TUNG
Created: 28-08-2015
Modified: 
    <Name> DUONG MANH TUNG
    <Date> 28/08/2015
    <Change>
Released: 
Description:
Note: <Note>
********************************************************************************/
/*-----------------------------------------------------------------------------*/
/* Header inclusions                                                           */
/*-----------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_usart.h"

/*-------------------------------------------------------------------------------
Function: 
Purpose: 
Parameters: None.
Return: None.
Comments: None.
Modified:
    <Modifie/ by> DUONG MANH TUNG
    <Date> 28/08/2015
    <Change>
-------------------------------------------------------------------------------*/
void USART1_Configuration(void)									
{

		USART_InitTypeDef USART_InitStructure;
		//Kich hoat Clock USART1
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE);
		//Chon BaudRate
		USART_InitStructure.USART_BaudRate = 115200;									//9600, 19200, 115200, ...
		//Chon do dai khung truyen
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;		// USART_WordLength_8b:8 bits, USART_WordLength_9b: 9bits
		//Chon stop bit
		USART_InitStructure.USART_StopBits = USART_StopBits_1;			// 1 stop, USART_StopBits_0_5;USART_StopBits_1_5;USART_StopBits_2
		//Chon Parity
		USART_InitStructure.USART_Parity = USART_Parity_No;				// USART_Parity_Even; USART_Parity_Odd 
		//Chon che do dieu khien
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //USART_HardwareFlowControl_RTS;USART_HardwareFlowControl_CTS;USART_HardwareFlowControl_RTS_CTS
		//Chon phuong thuc truyen nhan
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//
		//Cau hinh cac thong so vua lua chon
		USART_Init(USART1, &USART_InitStructure);											 //
		//Cau hinh ngat nhan du lieu
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);  
		//Cau hinh ngat truyen du lieu
		//USART_ITConfig(USART1, USART_IT_TXE, ENABLE);						//
		//
		//USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
		//
		//USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);
		//Kich hoat hoat dong cua USART
		USART_Cmd(USART1, ENABLE);	
}

/*-------------------------------------------------------------------------------
Function: 
Purpose: 
Parameters: None.
Return: None.
Comments: None.
Modified:
    <Modifie/ by> DUONG MANH TUNG
    <Date> 28/08/2015
    <Change>
-------------------------------------------------------------------------------*/
void USART2_Configuration(USART_TypeDef* USARTx)									
{
		USART_InitTypeDef USART_InitStructure;
		//Kich hoat Clock USART2
		RCC_APB2PeriphClockCmd( RCC_APB1Periph_USART2, ENABLE);
		USART_InitStructure.USART_BaudRate = 9600;						//9600, 19200, 115200
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;		// 8 bit, USART_WordLength_9b: 9bit
		USART_InitStructure.USART_StopBits = USART_StopBits_1;			// 1 stop, USART_StopBits_0_5;USART_StopBits_1_5;USART_StopBits_2
		USART_InitStructure.USART_Parity = USART_Parity_No;				// USART_Parity_Even; USART_Parity_Odd   
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //USART_HardwareFlowControl_RTS;USART_HardwareFlowControl_CTS;USART_HardwareFlowControl_RTS_CTS
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//
		/* Configure USARTx */
		USART_Init(USARTx, &USART_InitStructure);							//
		/* Enable USARTx Receive and Transmit interrupts */
		USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);       
		USART_ITConfig(USARTx, USART_IT_TXE, ENABLE);			
		/* Enable the USARTx */
		USART_Cmd(USARTx, ENABLE);	
}

/*-------------------------------------------------------------------------------
Function: 
Purpose: 
Parameters: None.
Return: None.
Comments: None.
Modified:
    <Modifie/ by> DUONG MANH TUNG
    <Date> 28/08/2015
    <Change>
-------------------------------------------------------------------------------*/
void USART_SendChar(USART_TypeDef* USARTx, u8 data)
{
		USART_SendData(USARTx,data);
}

/*-------------------------------------------------------------------------------
Function: 
Purpose: 
Parameters: None.
Return: None.
Comments: None.
Modified:
    <Modifie/ by> DUONG MANH TUNG
    <Date> 28/08/2015
    <Change>
-------------------------------------------------------------------------------*/
void USART_SendString(USART_TypeDef* USARTx, unsigned char* str)
{
    while (*str)
		{
				USART_SendData(USARTx,*str); 
				str++;
				while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
		}
}


