/**
  ******************************************************************************
  * @file    main.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    08-March-2016
  * @brief   Header for main.c module
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/** @addtogroup Global
  * @{
  */
/* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32072B_EVAL
#include "stm32f0xx.h"
#include "stm32f0xx_hal.h"
#include "stm32072b_eval.h"
#include "stm32072b_eval_lcd.h"
#endif /*  USE_STM32072B_EVAL */
#ifdef USE_STM32373C_EVAL
#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"
#include "stm32373c_eval.h"
#include "stm32373c_eval_lcd.h"
#endif /* USE_STM32373C_EVAL */
#ifdef USE_STM32303C_EVAL
#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"
#include "stm32303c_eval.h"
#include "stm32303c_eval_lcd.h"
#endif /* USE_STM32303C_EVAL */
#include "menu.h"
#include "ir_common.h"

/** @addtogroup Global_Public_Defines
  * @{
  */
#ifdef USE_STM32072B_EVAL
#define BUTTON_BACK BUTTON_TAMPER
#else /*USE_STM32072B_EVAL*/
#define BUTTON_BACK BUTTON_KEY
#endif /*USE_STM32072B_EVAL*/

/**
  * @}
  */

/** @addtogroup Global_Exported_Functions
  * @{
  */
void Demo_LedShow(FunctionalState NewState);
uint32_t Demo_Get_LedShowStatus(void);
void Demo_LedShowCallback(void);
void Error_Handler(void);

/**
  * @}
  */

/** @addtogroup Global_Public_Variables
  * @{
  */
extern TIM_HandleTypeDef    TimHandleHF;
extern TIM_HandleTypeDef    TimHandleLF;
extern TIM_HandleTypeDef    TimHandleLED;
extern TIM_HandleTypeDef    TimHandleDEC;

extern __IO FlagStatus DownStatus;
extern __IO FlagStatus UpStatus;
extern __IO FlagStatus SelStatus;
extern __IO FlagStatus LeftStatus;
extern __IO FlagStatus RightStatus;
extern __IO FlagStatus KeyStatus;
/**
  * @}
  */

/**
  * @}
  */
#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
