/**
  ******************************************************************************
  * Ten Tep      :        lcd16x2.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Khai bao cac ham dieu khien LCD 16x2.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho LCD vao file main.h
  *					 Vi Du:
#define     LCD_RS     PORTD_0     
#define     LCD_RW     PORTD_1     
#define     LCD_EN     PORTD_2          
#define     LCD_D4     PORTD_4          
#define     LCD_D5     PORTD_5          
#define     LCD_D6     PORTD_6         
#define     LCD_D7     PORTD_7                             
  ******************************************************************************
**/
#ifndef __LCD_16X2_H
#define __LCD_16X2_H
#include "stm32f10x_adc.h" 
/* #include "stm32f10x_bkp.h" */
/* #include "stm32f10x_can.h" */
/* #include "stm32f10x_crc.h" */
/* #include "stm32f10x_dac.h" */
/* #include "stm32f10x_dbgmcu.h" */
#include "stm32f10x_dma.h"
//#include "stm32f10x_exti.h"
#include "stm32f10x_flash.h"
/* #include "stm32f10x_fsmc.h" */
#include "stm32f10x_gpio.h"
//#include "stm32f10x_i2c.h"
#include "stm32f10x_iwdg.h"
//#include "stm32f10x_pwr.h"
#include "stm32f10x_rcc.h"
//#include "stm32f10x_rtc.h"
/* #include "stm32f10x_sdio.h" */
//#include "stm32f10x_spi.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_usart.h"
/*#include "stm32f10x_wwdg.h" */
#include "misc.h" /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */
/*******************************************************************************
Noi Dung    :   Gui tin hieu Enable den LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD_Enable(void);
 /*******************************************************************************
Noi Dung    :   Gui 4 bit du lieu den LCD.
Tham Bien   :   Data: 4 bit thap cua Data chua 4 bit du lieu can gui.
Tra Ve      :   Khong.
********************************************************************************/

 void LCD_Send4Bit( BYTE  Data );
 /*******************************************************************************
Noi Dung    :   Gui 1 byte du lieu den LCD.
Tham Bien   :   command: byte du lieu can gui.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD_SendCommand (BYTE  command );
 /*******************************************************************************
Noi Dung    :   Khoi tao LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD_Init ( void );
 /*******************************************************************************
Noi Dung    :   Thiet lap vi tri con tro LCD.
Tham Bien   :   x: vi tri cot cua con tro. x = 0 - 15.
                y: vi tri hang cua con tro. y= 0,1.
Tra Ve      :   Khong.
********************************************************************************/
void LCD_Gotoxy(BYTE  x, BYTE  y);
 /*******************************************************************************
Noi Dung    :   Xoa noi dung hien thi tren LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void LCD_Clear(void);
 /*******************************************************************************
Noi Dung    :   Viet 1 ki tu len LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD_PutChar ( BYTE  Data );
 /*******************************************************************************
Noi Dung    :   Viet 1 chuoi ki tu len LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void LCD_Puts (BYTE *s);
#endif
/******************************KET THUC FILE******************************/



