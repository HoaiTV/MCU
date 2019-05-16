#ifndef __IO_H__
#define __IO_H__

#include "stm32f10x_gpio.h"

#define GPIO_PORTA      0
#define GPIO_PORTB      1
#define GPIO_PORTC      2
#define GPIO_PORTD      3


#define INPUT2  (GPIOC->IDR & GPIO_Pin_13)
#define INPUT3  (GPIOC->IDR & GPIO_Pin_14)
#define INPUT4  (GPIOC->IDR & GPIO_Pin_15)

#define GPIO_PORT_COUNT 4

VOID InitIO();
VOID SetDirPin(BYTE nPort, WORD wInputPin, WORD wOutputPin);
VOID SetPin(BYTE nPort, WORD wSetPin, WORD wClearPin);
BOOL GetPin(BYTE nPort, WORD nPin);
WORD GetAllPins(BYTE nPort);

#endif