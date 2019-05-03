/**
  ******************************************************************************
  * @file    main.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    08-March-2016
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup IR_REMOTE
  * @brief Infra-red remote control
  * @{
  */

/** @addtogroup Global
  * @brief  Main program initialization and body.
  * @{
  */

/** @defgroup Global_Public_Variables
  * @{
  */
TIM_HandleTypeDef    TimHandleHF;
TIM_HandleTypeDef    TimHandleLF;
TIM_HandleTypeDef    TimHandleLED;
TIM_HandleTypeDef    TimHandleDEC;

__IO FlagStatus DownStatus = RESET;
__IO FlagStatus UpStatus = RESET;
__IO FlagStatus SelStatus = RESET;
__IO FlagStatus LeftStatus = RESET;
__IO FlagStatus RightStatus = RESET;
__IO FlagStatus KeyStatus = RESET;

/**
  * @}
  */

/** @defgroup Global_Private_Variables
  * @{
  */
static __IO uint32_t TimingDelay = 0;
static __IO uint32_t LedShowStatus = 0;
static __IO uint8_t Index = 0;

/**
  * @}
  */

/** @defgroup Global_Private_Function_Prototypes
  * @{
  */
static void SystemClock_Config(void);
static void Demo_LED_Init(void);

/**
  * @}
  */

/** @defgroup Global_Private_Function
  * @{
  */
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
void main(void)
{
  /* STM32F3xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the system clock to have a system clock = 72 MHz */
  SystemClock_Config();

  /* Configure Joystick pins as input floating with EXTI */
  BSP_PB_Init(BUTTON_BACK, BUTTON_MODE_GPIO);
  BSP_JOY_Init(JOY_MODE_EXTI);

  /* Enable Leds toggling */
  Demo_LED_Init();
  Demo_LedShow(ENABLE);

  /* Set the LCD Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);

  /* Set the LCD Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

  /* Initialize the Menu */
  Menu_Init();
  Menu_DisplayMenu();

  /* The DOWNStatus, SELStatus or UPStatus will be set in interrupt
  callback when the joystick button(DOWN, SEL or UP) is pressed */
  while (1)
  {
    if (DownStatus != RESET)
    {
      /* Reset DownStatus value */
      DownStatus = RESET;
      /* Execute DOWN Function */
      Menu_DownFunc();
    }
    else if (SelStatus != RESET)
    {
      /* Reset SelStatus value */
      SelStatus = RESET;
      /* Execute SEL Function */
      Menu_SelFunc();
    }
    else if (UpStatus != RESET)
    {
      /* Reset UpStatus value */
      UpStatus = RESET;
      /* Execute UP Function */
      Menu_UpFunc();
    }
  }
}

#ifdef STM32F072xB
/**
  * @brief  System Clock Configuration for F0
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 48000000
  *            HCLK(Hz)                       = 48000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            PREDIV                         = 1
  *            PLLMUL                         = 6
  *            Flash Latency(WS)              = 1
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_OscInitTypeDef osc_init;
  RCC_ClkInitTypeDef clk_init;

  /* Enable HSE Oscillator and Activate PLL with HSE as source */
  osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  osc_init.HSEState = RCC_HSE_ON;
  osc_init.PLL.PLLState = RCC_PLL_ON;
  osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  osc_init.PLL.PREDIV = RCC_PREDIV_DIV1;
  osc_init.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&osc_init) != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 clocks dividers */
  clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
  clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&clk_init, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}
#else /* STM32F072xB */
/**
* @brief  System Clock Configuration for F3
*         The system Clock is configured as follow :
*            System Clock source            = PLL (HSE)
*            SYSCLK(Hz)                     = 72000000
*            HCLK(Hz)                       = 72000000
*            AHB Prescaler                  = 1
*            APB1 Prescaler                 = 2
*            APB2 Prescaler                 = 1
*            HSE Frequency(Hz)              = 8000000
*            HSE PREDIV                     = 1
*            PLLMUL                         = RCC_PLL_MUL9 (9)
*            Flash Latency(WS)              = 2
* @param  None
* @retval None
*/
static void SystemClock_Config(void)
{
  RCC_OscInitTypeDef osc_init;
  RCC_ClkInitTypeDef clk_init;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  osc_init.HSEState = RCC_HSE_ON;
  osc_init.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  osc_init.PLL.PLLState = RCC_PLL_ON;
  osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  osc_init.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&osc_init) != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
  clocks dividers */
  clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
  clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&clk_init, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}
#endif /* STM32F072xB */

/**
  * @brief  Configure the LEDs pins as output push-pull: LED1, LED2, LED3
  *         and LED4
  * @param  None
  * @retval None
  */
static void Demo_LED_Init(void)
{
  /* Configure LEDs GPIO: as output push-pull */
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);

  /* TIM2 clocks enable */
  __HAL_RCC_TIM2_CLK_ENABLE();

  TimHandleLED.Instance = TIM2;
  TimHandleLED.Init.Period = 7200;
  TimHandleLED.Init.Prescaler = 1000;
  TimHandleLED.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TimHandleLED.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_Base_Init(&TimHandleLED);

  HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/**
  * @brief  Enables or disables LED1, LED2, LED3 and LED4 toggling.
  * @param  NewState: FunctionalState ENABLE or DISABLE
  * @retval None
  */
void Demo_LedShow(FunctionalState NewState)
{
  /* Enable LEDs toggling */
  if (NewState == ENABLE)
  {
    LedShowStatus = 1;
    /* Enable the TIM Update Interrupt */
    HAL_TIM_Base_Start_IT(&TimHandleLED);

    /* TIM2 counter enable */
    __HAL_TIM_ENABLE(&TimHandleLED);
  }
  /* Disable LEDs toggling */
  else
  {
    LedShowStatus = 0;
    /* Disable the TIM Update Interrupt */
    HAL_TIM_Base_Stop_IT(&TimHandleLED);

    /* TIM2 counter disable */
    __HAL_TIM_ENABLE(&TimHandleLED);
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while (1)
  {}
}

/**
  * @}
  */

/** @defgroup Global_Exported_Functions
  * @{
  */

/**
  * @brief  Get the LedShowStatus value.
  * @param  None
  * @retval LedShowStatus Value.
  */
uint32_t Demo_Get_LedShowStatus(void)
{
  return LedShowStatus;
}

/**
  * @brief  Modify the LED state (blink).
  * @param  None
  * @retval None
  */
void Demo_LedShowCallback(void)
{
  /* If LedShowStatus is TRUE: enable LEDs toggling */
  if (Demo_Get_LedShowStatus() != 0)
  {
    switch (Index)
    {
        /* LD1 turned on, LD4 turned off */
      case 0:
      {
        BSP_LED_Off(LED1);
        BSP_LED_On(LED4);
        Index++;
        break;
      }
      /* LD2 turned on, LD1 turned off */
      case 1:
      {
        BSP_LED_Off(LED2);
        BSP_LED_On(LED1);
        Index++;
        break;
      }
      /* LD3 turned on, LD2 turned off */
      case 2:
      {
        BSP_LED_Off(LED3);
        BSP_LED_On(LED2);
        Index++;
        break;
      }
      /* LD4 turned on, LD3 turned off */
      case 3:
      {
        BSP_LED_Off(LED4);
        BSP_LED_On(LED3);
        Index++;
        break;
      }
      default:
        break;
    }
    /* Reset Index to replay LEDs switch on sequence  */
    if (Index == 4)
    {
      Index = 0;
    }
  }
}

/**
  * @brief  Keystroke callback function.
  * @param  GPIO_Pin: Activated GPIO pin
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  JOYState_TypeDef joykey = BSP_JOY_GetState();

  /* key press de-bounce */
  if (joykey != JOY_NONE)
  {
    while ( BSP_JOY_GetState() != JOY_NONE)
    {}
  }

  /* Setting global status */
  if ( joykey == JOY_SEL)
  {
    SelStatus = SET;
  }
  else if ( joykey == JOY_UP)
  {
    UpStatus = SET;
  }
  else if ( joykey == JOY_DOWN)
  {
    DownStatus = SET;
  }
  else if ( joykey == JOY_LEFT)
  {
    LeftStatus = SET;
  }
  else if ( joykey == JOY_RIGHT)
  {
    RightStatus = SET;
  }
  else if (BSP_PB_GetState(BUTTON_BACK) != GPIO_PIN_SET)
  {
    KeyStatus = SET;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @retval None
  */
void assert_failed(void)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {}
}

#endif /* USE_FULL_ASSERT */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
