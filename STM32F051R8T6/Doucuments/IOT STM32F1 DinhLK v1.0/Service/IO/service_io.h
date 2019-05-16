#ifndef __RELAY_H__
#define __RELAY_H__

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define RELAY1_PIN          GPIO_Pin_15
#define RELAY1_PORT         GPIO_PORTB

#define RELAY2_PIN          GPIO_Pin_14
#define RELAY2_PORT         GPIO_PORTB

#define RELAY3_PIN          GPIO_Pin_13
#define RELAY3_PORT         GPIO_PORTB

#define RELAY4_PIN          GPIO_Pin_7
#define RELAY4_PORT         GPIO_PORTA
/* 
cau hinh cac chan LCD16x02 
D7 PA12
D6 PA11
D5 PA10
D4 PA9
RS PB3
EN PB0
LED_BLUE_PIN LCD_D4
LED_RED_PIN
LED_YELLOW_PIN LCD_D5
*/
#define LCD_D4_PIN        GPIO_Pin_9
#define LCD_D4_PORT       GPIO_PORTA

#define LED_RED_PIN         GPIO_Pin_11
#define LED_RED_PORT        GPIO_PORTB

#define LCD_D5_PIN      GPIO_Pin_10
#define LCD_D5_PORT     GPIO_PORTA

#define LCD_D6_PIN      GPIO_Pin_11
#define LCD_D6_PORT     GPIO_PORTA

#define LCD_D7_PIN      GPIO_Pin_12
#define LCD_D7_PORT     GPIO_PORTA

#define LCD_RS_PIN      GPIO_Pin_3
#define LCD_RS_PORT     GPIO_PORTB

#define LCD_EN_PIN      GPIO_Pin_0
#define LCD_EN_PORT     GPIO_PORTB

VOID InitIOService();
VOID SetIOState(BYTE nIOPort, WORD wIOPin, BOOL bState);
//VOID TogglePin(BYTE nIOPort, WORD wIOPin);//DinhLK

#endif /*DS1820_H_*/
