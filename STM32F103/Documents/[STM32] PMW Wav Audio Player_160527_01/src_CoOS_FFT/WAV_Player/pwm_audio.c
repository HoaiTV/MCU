
/****************************************************
Mini-STM32 PWM Audio

Mini-STM32 SD/MMC WAV Audio Player
yus	- http://projectproto.blogspot.com/
June 2010
*****************************************************/

#include "stm32f10x.h"
#include "CoOS.h"			 			/*!< CooCox RTOS header file.		  */
#include "pwm_audio.h"

#define WAV_BUFFER_MASK		(WAV_BUFFER_SIZE-1)

/*** private variables ***/
unsigned char WAV_BUFF[WAV_BUFFER_SIZE];
volatile unsigned int pWAVIN, pWAVOUT;

TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

/*** private functions ***/

void TIM2_init(void)
{
	unsigned long ulFrequency;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Enable timer2 clock */
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );

	/* Initialise data. */
	TIM_DeInit( TIM2 );
	TIM_TimeBaseStructInit( &TIM_TimeBaseStructure );

	/* Time base configuration for timer 2 - which generates the interrupts. */
	ulFrequency = 72000000 / 8000;	
	TIM_TimeBaseStructure.TIM_Period = ( unsigned int ) ( ulFrequency & 0xffffUL );
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit( TIM2, &TIM_TimeBaseStructure );
	TIM_ARRPreloadConfig( TIM2, ENABLE );

	/* Enable TIM2 interrupt. */
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//HIGHEST_PRIORITY;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init( &NVIC_InitStructure );	
	//TIM_ITConfig( TIM2, TIM_IT_Update, ENABLE );

	/* Finally, enable timer 2. */
	TIM_Cmd( TIM2, ENABLE );

}

void TIM2_IRQHandler(void)
{
	CoEnterISR();                 /* Tell CooCox that we are starting an ISR. */

	set_pwm_duty ( WAV_BUFF[pWAVOUT] );
	++pWAVOUT;
	pWAVOUT &= WAV_BUFFER_MASK;
	                    
	if(pWAVOUT == pWAVIN)		// if buffer is empty
    {
    	/* Disable the timer 2 interrupt */
		TIM_ITConfig( TIM2, TIM_IT_Update, DISABLE );
    }

	TIM_ClearITPendingBit( TIM2, TIM_IT_Update );

	CoExitISR();
}

/*** exported functions ***/
void pwm_audio_init(void)
{
	PWM_init();
	TIM2_init();
	
	pWAVIN = pWAVOUT = 0;	// reset buffer
}

void set_sampling_rate(unsigned long rate)
{
	TIM_TimeBaseStructure.TIM_Period = ( unsigned int ) ( 72000000 / rate );
	TIM_TimeBaseInit( TIM2, &TIM_TimeBaseStructure );
}

void wav_putc(unsigned char c)
{
	// wait until buffer has an empty slot.
	while (((pWAVIN+1) & WAV_BUFFER_MASK)==pWAVOUT);
	WAV_BUFF[pWAVIN] = c;
	pWAVIN = (pWAVIN + 1) & WAV_BUFFER_MASK;	// increment input WAV buffer pointer

	TIM_ITConfig( TIM2, TIM_IT_Update, ENABLE );
}
