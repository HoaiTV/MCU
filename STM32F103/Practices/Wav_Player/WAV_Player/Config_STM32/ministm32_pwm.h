
#ifndef	__MINISTM32_PWM_H__
#define	__MINISTM32_PWM_H__
#include <stdbool.h>

#define TIM4_CH2 GPIO_PIN_7
#define TIM4_CH3 GPIO_PIN_8

void PWM_init(void);	// PB7
void set_pwm_duty(unsigned char duty);
void set_pwm_duty_3(unsigned char duty);

void pwm_output_enable(bool on);

#endif	// __MINISTM32_PWM_H__
