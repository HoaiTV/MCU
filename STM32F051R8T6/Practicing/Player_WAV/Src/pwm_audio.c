
/****************************************************
Mini-STM32 PWM Audio

Mini-STM32 SD/MMC WAV Audio Player
yus	- http://projectproto.blogspot.com/
May 2010

*****************************************************/
#include "stm32f1xx_hal.h"
#include "pwm_audio.h"
#include "main.h"
#define WAV_BUFFER_MASK		(WAV_BUFFER_SIZE-1)
/*** private variables ***/
//For Pmw channel2
unsigned char WAV_BUFF[WAV_BUFFER_SIZE];
volatile unsigned int pWAVIN, pWAVOUT;
//For Pmw channel3
unsigned char WAV_BUFF_3[WAV_BUFFER_SIZE];
volatile unsigned int pWAVIN_3, pWAVOUT_3;

extern TIM_HandleTypeDef htim2;
extern uint32_t SystemCoreClock;

/*** private functions ***/
/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 1-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

void TIM2_IRQHandler(void)
{
	  //GPIO_SetBits(GPIOB, GPIO_Pin_2);
	  set_pwm_duty(WAV_BUFF[pWAVOUT]);
	  set_pwm_duty_3(WAV_BUFF_3[pWAVOUT_3]);
	  ++pWAVOUT;
	  ++pWAVOUT_3;
	  pWAVOUT &= WAV_BUFFER_MASK;
      pWAVOUT_3 &= WAV_BUFFER_MASK;
		if (pWAVOUT == pWAVIN)		
		{
				HAL_TIM_Base_Stop_IT(&htim2);
		}
		if (pWAVOUT_3 == pWAVIN_3)		// if buffer is empty
		{
				HAL_TIM_Base_Stop_IT(&htim2);
		}
		__HAL_TIM_CLEAR_IT(&htim2,TIM_IT_UPDATE);
}

void pwm_audio_init(void)
{
		PWM_init();
		MX_TIM2_Init();
		pWAVIN = pWAVOUT = 0;	
	    pWAVIN_3 = pWAVOUT_3 = 0;
}

void set_sampling_rate(unsigned long rate)
{
		htim2.Init.Period = (unsigned int)(SystemCoreClock / rate);
		  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
		  {
		    Error_Handler();
		  }
}

void wav_putc(unsigned char c)
{
		// wait until buffer has an empty slot.
		while (((pWAVIN+1) & WAV_BUFFER_MASK) == pWAVOUT);
		WAV_BUFF[pWAVIN] = c;
		pWAVIN = (pWAVIN + 1) & WAV_BUFFER_MASK;	// increment input WAV buffer pointer
		//TIM_ITConfig( TIM2, TIM_IT_Update, ENABLE );
}

void wav_putc_3(unsigned char c)
{
		// wait until buffer has an empty slot.
		//while (((pWAVIN_3 + 1) & WAV_BUFFER_MASK) == pWAVOUT_3);
		WAV_BUFF_3[pWAVIN_3] = c;
		pWAVIN_3 = (pWAVIN_3 + 1) & WAV_BUFFER_MASK;	// increment input WAV buffer pointer
		HAL_TIM_Base_Start_IT(&htim2);
}
