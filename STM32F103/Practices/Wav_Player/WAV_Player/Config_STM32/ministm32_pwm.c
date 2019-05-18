
/*

PWM output on PB7 ->	 JP2-pin30(mainboard) = CN2-pin10(TFT board)  DF_CS

PB7 -> TIM4_CH2 (alternate function)

*/

#include "stm32f1xx_hal.h"
#include "ministm32_pwm.h"
#include "main.h"

/* Private variables ---------------------------------------------------------*/
extern TIM_HandleTypeDef htim4;
/* TIM4 clock enable */
  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  GPIO_InitTypeDef GPIO_InitStruct = {0};


void PWM_init(void)
{

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOB_CLK_ENABLE();
	
	/* GPIOB Configuration:TIM4 Channel 2 as alternate function push-pull */
	GPIO_InitStruct.Pin = TIM4_CH2;	 // PB7
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);
	//
	/* GPIOB Configuration:TIM4 Channel 3 as alternate function push-pull */
	GPIO_InitStruct.Pin = TIM4_CH3;	 // PB8
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);
	/* Time base configuration */
	/* PWM frequency = 72MHz / [Period * (Prescaler + 1)]  */
	  htim4.Instance = TIM4;
	  htim4.Init.Prescaler = 1-1;
	  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim4.Init.Period = 350-1;
	  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 128;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN TIM4_Init 2 */

	  /* USER CODE END TIM4_Init 2 */
	  HAL_TIM_MspPostInit(&htim4);

}

void set_pwm_duty(unsigned char duty)
{
	sConfigOC.Pulse = duty;
	  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	  {
	    Error_Handler();
	  }

}

void set_pwm_duty_3(unsigned char duty)
{
	sConfigOC.Pulse = duty;
	  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	  {
	    Error_Handler();
	  }

}

void pwm_output_enable(bool on)
{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};

	if(on){
		/* GPIOB Configuration:TIM4 Channel 2 as alternate function push-pull */
		GPIO_InitStruct.Pin = TIM4_CH2;	 // PB7
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);

		//
		/* GPIOB Configuration:TIM4 Channel 2 as alternate function push-pull */

		GPIO_InitStruct.Pin = TIM4_CH3;	 // PB7
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);
	}
	else{
		/* GPIOB7 as input */
		GPIO_InitStruct.Pin = TIM4_CH2;	 // PB7
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);

		//
				/* GPIOB7 as input */
		GPIO_InitStruct.Pin = TIM4_CH3;	 // PB8
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(SD_CS_GPIO_Port, &GPIO_InitStruct);

	}
}

