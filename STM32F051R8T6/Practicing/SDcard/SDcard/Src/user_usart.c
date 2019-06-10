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
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_uart.h"
#include "main.h"

extern UART_HandleTypeDef huart1;

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

	  huart1.Instance = USART1;
	  huart1.Init.BaudRate = 115200;
	  huart1.Init.WordLength = UART_WORDLENGTH_8B;
	  huart1.Init.StopBits = UART_STOPBITS_1;
	  huart1.Init.Parity = UART_PARITY_NONE;
	  huart1.Init.Mode = UART_MODE_TX_RX;
	  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	  if (HAL_UART_Init(&huart1) != HAL_OK)
	  {
		  _Error_Handler(__FILE__, __LINE__);
	  }
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
int __io_putchar(int ch)
{
 uint8_t c[1];
 c[0] = ch & 0x00FF;
 HAL_UART_Transmit(&huart1, &*c, 1, 10);
 return ch;
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
int _write(int file,char *ptr, int len)
{
 int DataIdx;
 for(DataIdx= 0; DataIdx< len; DataIdx++)
 {
 __io_putchar(*ptr++);
 }
return len;
}


