/*
Link http://soundfile.sapp.org/doc/WaveFormat/
Link https://en.wikipedia.org/wiki/WAV
*/
#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include <string.h>

#include "ministm32_lcd.h"

#include "pff.h"
#include "wave_file.h"
#include "pwm_audio.h"
#include "user_usart.h"

FATFS Fs;			/* File system object */
DIR Dir;			/* Directory object */
FILINFO Fno;		/* File information */

void delay(void);
int main(void)
{
	  char arString[100];
		USART_InitTypeDef USART_InitStructure;	
		GPIO_InitTypeDef GPIO_InitStructure;
		//Enable clock AFIO
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);	 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //TX	         
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //RX	          
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
	  //
	  //GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;           
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	  //
	  RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE);
		USART_InitStructure.USART_BaudRate = 115200;									//9600, 19200, 115200, ...
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;		// USART_WordLength_8b:8 bits, USART_WordLength_9b: 9bits
		USART_InitStructure.USART_StopBits = USART_StopBits_1;			// 1 stop, USART_StopBits_0_5;USART_StopBits_1_5;USART_StopBits_2
		USART_InitStructure.USART_Parity = USART_Parity_No;				// USART_Parity_Even; USART_Parity_Odd 
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //USART_HardwareFlowControl_RTS;USART_HardwareFlowControl_CTS;USART_HardwareFlowControl_RTS_CTS
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//
		USART_Init(USART1, &USART_InitStructure);											 //
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);  
		USART_Cmd(USART1, ENABLE);	
		//
		USART_SendString(USART1, "PMW Wav Player Example\n");
		GPIO_SetBits(GPIOB, GPIO_Pin_2);
		pwm_audio_init();
		LCD_Init();
		//LCD_Text(30, 30, "Mini-STM32 WAVE Audio Player", LCD_Yellow, LCD_Red);	
		GPIO_ResetBits(GPIOB, GPIO_Pin_2);
		while(1)
		{
				delay();
				if (pf_mount(&Fs) ) 
						continue;	/* Initialize FS */
				USART_SendString(USART1, "Mount Disk Is Ok\n");
				while(1)
				{
						if (pf_opendir(&Dir, "")) 
								break;				// open root directory
						USART_SendString(USART1, "Open Root Directory Is Ok\n");
						while (!pf_readdir(&Dir, &Fno) && Fno.fname[0]) 
						{
								if (strstr(Fno.fname, ".WAV") )
								{		
										GPIO_SetBits(GPIOB, GPIO_Pin_2);
									  USART_SendString(USART1, "Mini-STM32 WAVE Audio Player\n");
										//LCD_Clear(LCD_Red);
										//LCD_Text(30, 20, "Mini-STM32 WAVE Audio Player", LCD_Yellow, LCD_Red);
									  sprintf(arString, "Play With File name: %s \n", Fno.fname);
									  USART_SendString(USART1, arString);
									  GPIO_ResetBits(GPIOB, GPIO_Pin_2);
										play_wave_file(Fno.fname);
							      //GPIO_ResetBits(GPIOB, GPIO_Pin_2);
										//delay();
								}
						}
				}
		}
}

void delay(void)
{
		long i=0x7FFFFF;
		while(--i);
}
