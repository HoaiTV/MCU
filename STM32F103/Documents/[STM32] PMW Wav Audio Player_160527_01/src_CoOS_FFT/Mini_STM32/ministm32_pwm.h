
#ifndef	__MINISTM32_PWM_H__
#define	__MINISTM32_PWM_H__

void PWM_init(void);	// PB7
void set_pwm_duty(unsigned char duty);

void pwm_output_enable(char on);

#endif	// __MINISTM32_PWM_H__
