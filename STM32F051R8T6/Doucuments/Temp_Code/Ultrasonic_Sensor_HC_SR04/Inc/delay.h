/*
 * delay.h
 *
 *  Created on: Mar 23, 2019
 *      Author: hoai
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f0xx.h"

void SysTick_Init(void);
void TimeTick_Decrement(void);
void delay_nus(uint32_t n);
void delay_1ms(void);
void delay_nms(uint32_t n);


#endif /* DELAY_H_ */
