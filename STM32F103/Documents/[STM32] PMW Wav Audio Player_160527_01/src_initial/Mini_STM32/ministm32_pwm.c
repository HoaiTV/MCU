
/*

PWM output on PB7 ->	 JP2-pin30(mainboard) = CN2-pin10(TFT board)  DF_CS

PB7 -> TIM4_CH2 (alternate function)

*/

#include "stm32f10x.h"
#include "ministm32_pwm.h"

/* Private variables ---------------------------------------------------------*/
TIM_OCInitTypeDef  TIM_OCInitStructure;

void PWM_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	/* TIM4 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );
	
	/* GPIOB Configuration:TIM4 Channel 2 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	 // PB7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//
	/* GPIOB Configuration:TIM4 Channel 3 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	 // PB7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	/* Time base configuration */
	/* PWM frequency = 72MHz / [Period * (Prescaler + 1)]  */
	TIM_TimeBaseStructure.TIM_Period = 350;//256;//360;
 	TIM_TimeBaseStructure.TIM_Prescaler = 0;
 	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* PWM1 Mode configuration: Channel2 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 128;	//CCR2 Value;	 duty cycle =  CCR/Period
 	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
 	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	//
	/* PWM1 Mode configuration: Channel3 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 128;	//CCR2 Value;	 duty cycle =  CCR/Period
 	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	//
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	/* TIM4 enable counter */
	TIM_Cmd(TIM4, ENABLE);

}

void set_pwm_duty(unsigned char duty)
{
	TIM_OCInitStructure.TIM_Pulse = duty;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	//TIM_OC3Init(TIM4, &TIM_OCInitStructure);

}

void set_pwm_duty_3(unsigned char duty)
{
	TIM_OCInitStructure.TIM_Pulse = duty;
	//TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);

}

void pwm_output_enable(bool on)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	if(on){
		/* GPIOB Configuration:TIM4 Channel 2 as alternate function push-pull */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	 // PB7
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		//
		/* GPIOB Configuration:TIM4 Channel 2 as alternate function push-pull */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	 // PB7
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	else{
		/* GPIOB7 as input */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;	 // PB7
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		//
				/* GPIOB7 as input */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	 // PB7
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
}

