/**
  ******************************************************************************
  * @file    menu.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    08-March-2016
  * @brief   This file includes the menu navigation driver for the STM32373C-EVAL demonstration.
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
#include "rc5_decode.h"
#include "rc5_encode.h"
#include "sirc_decode.h"
#include "sirc_encode.h"

/** @addtogroup IR_REMOTE
  * @{
  */

/** @defgroup MENU
  * @brief    This file includes the menu navigation driver for the EVAL boards
  *           demonstration.
  * @{
  */

/** @defgroup MENU_Private_Types
  * @{
  */
typedef void (* tMenuFunc)(void);
typedef struct sMenuItem * tMenuItem;
typedef struct sMenu * tMenu;

struct sMenuItem
{
  uint8_t* pszTitle;
  tMenuFunc pfMenuFunc;
  tMenuFunc pfUpDownMenuFunc;
  tMenu psSubMenu;
};

struct sMenu
{
  uint8_t* pszTitle;
  tMenuItem psItems;
  uint8_t nItems;
};

/**
  * @}
  */

/** @defgroup MENU_Private_Defines
  * @{
  */
#define MAX_MENU_LEVELS ((uint32_t)3)
#define countof(a) (sizeof(a) / sizeof(*(a)))

/**
  * @}
  */

/** @defgroup MENU_Private_Variables
  * @{
  */
uint8_t MenuItemIndex = 0;
uint8_t nMenuLevel = 0;
uint8_t ItemNumb[MAX_MENU_LEVELS];
tMenuItem psMenuItem;
tMenuItem psCurrentMenuItem;
tMenu psPrevMenu[MAX_MENU_LEVELS];
tMenu psCurrentMenu;

struct sMenuItem RFRECEIVERMenuItems[] =
  {
    {(uint8_t*)"        SIRC        ", Menu_SIRCDecode_Func, Menu_IdleFunc},
    {(uint8_t*)"        RC5         ", Menu_RC5Decode_Func, Menu_IdleFunc},
    {(uint8_t*)"       Return       ", Menu_ReturnFunc, Menu_IdleFunc}
  };

struct sMenu RFRECEIVERMenu =
  {
    (uint8_t*)"    IR Receiver    ", RFRECEIVERMenuItems, countof(RFRECEIVERMenuItems)
  };

struct sMenuItem RFTRANSMITTERMenuItems[] =
  {
    {(uint8_t*)"       SIRC       ", Menu_SIRC_Encode_Func, Menu_IdleFunc},
    {(uint8_t*)"       RC5        ", Menu_RC5_Encode_Func, Menu_IdleFunc},
    {(uint8_t*)"      Return      ", Menu_ReturnFunc, Menu_IdleFunc}
  };

struct sMenu RFTRANSMITTERMenu =
  {
    (uint8_t*)"  IR Transmitter   ", RFTRANSMITTERMenuItems, countof(RFTRANSMITTERMenuItems)
  };

struct sMenuItem ConnectivityDisplayMenuItems[] =
  {
    {(uint8_t*)"  IR Transmitter  ", Menu_IdleFunc, Menu_IdleFunc, &RFTRANSMITTERMenu},
    {(uint8_t*)"   IR Receiver    ", Menu_IdleFunc, Menu_IdleFunc, &RFRECEIVERMenu}
  };

struct sMenu ConnectivityDisplayMenu =
  {
    (uint8_t*)"   Infrared demo   ", ConnectivityDisplayMenuItems, countof(ConnectivityDisplayMenuItems)
  };

/**
  * @}
  */

/** @defgroup MENU_Exported_Functions
  * @{
  */

/**
  * @brief  Initializes the navigation menu.
  * @param  None
  * @retval None
  */
void Menu_Init(void)
{
  psCurrentMenu = &ConnectivityDisplayMenu;
  psPrevMenu[nMenuLevel] = psCurrentMenu;
  psMenuItem = ConnectivityDisplayMenuItems;
}

/**
  * @brief  Displays the current menu.
  * @param  None
  * @retval None
  */
void Menu_DisplayMenu(void)
{
  uint32_t Line = 0, index = 0;

  tMenuItem psMenuItem2;
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  /* Clear the LCD Screen */
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_DisplayStringAtLine(Line, (uint8_t*)psCurrentMenu->pszTitle);
  Line += 24;
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  while (!(index >= (psCurrentMenu->nItems)))
  {
    psMenuItem2 = &(psCurrentMenu->psItems[index]);
    BSP_LCD_DisplayStringAtLine(Line, (uint8_t*)psMenuItem2->pszTitle);
    index++;
    Line += 24;
  }
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  /* Get the current menu */
  psMenuItem = &(psCurrentMenu->psItems[MenuItemIndex]);
  BSP_LCD_DisplayStringAtLine(((MenuItemIndex + 1) * 24), (uint8_t*)psMenuItem->pszTitle);
}

/**
  * @brief  This function is executed when "SEL" push-button is pressed.
  * @param  None
  * @retval None
  */
void Menu_SelFunc(void)
{
  psCurrentMenuItem = psMenuItem;
  if (psMenuItem->psSubMenu != '\0')
  {
    /* Update the current Item by the sub-menu */
    MenuItemIndex = 0;
    psCurrentMenu = psMenuItem->psSubMenu;
    psMenuItem = &(psCurrentMenu->psItems)[MenuItemIndex];
    Menu_DisplayMenu();
    nMenuLevel++;
    psPrevMenu[nMenuLevel] = psCurrentMenu;
  }
  psCurrentMenuItem->pfMenuFunc();
}

/**
  * @brief  This function is executed when any of "UP" push-buttons is pressed.
  * @param  None
  * @retval None
  */
void Menu_UpFunc(void)
{
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  psMenuItem = &psCurrentMenu->psItems[MenuItemIndex];
  BSP_LCD_DisplayStringAtLine(((MenuItemIndex + 1) * 24), (uint8_t*)psMenuItem->pszTitle);
  if (MenuItemIndex > 0)
  {
    MenuItemIndex--;
  }
  else
  {
    MenuItemIndex = psCurrentMenu->nItems - 1;
  }
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  psMenuItem = &psCurrentMenu->psItems[MenuItemIndex];
  BSP_LCD_DisplayStringAtLine(((MenuItemIndex + 1) * 24), (uint8_t*)psMenuItem->pszTitle);
  ItemNumb[nMenuLevel] = MenuItemIndex;
}

/**
  * @brief  This function is executed when any of "Down" push-buttons is pressed.
  * @param  None
  * @retval None
  */
void Menu_DownFunc(void)
{
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  psMenuItem = &psCurrentMenu->psItems[MenuItemIndex];
  BSP_LCD_DisplayStringAtLine(((MenuItemIndex + 1) * 24), (uint8_t*)psMenuItem->pszTitle);

  /* Test on the MenuItemIndex value before incrementing it */
  if (MenuItemIndex >= ((psCurrentMenu->nItems) - 1))
  {
    MenuItemIndex = 0;
  }
  else
  {
    MenuItemIndex++;
  }
  /* Set the Back Color */
  BSP_LCD_SetBackColor(LCD_COLOR_GREEN);
  /* Set the Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  /* Get the current menu */
  psMenuItem = &(psCurrentMenu->psItems[MenuItemIndex]);
  BSP_LCD_DisplayStringAtLine(((MenuItemIndex + 1) * 24), (uint8_t*)psMenuItem->pszTitle);
  ItemNumb[nMenuLevel] = MenuItemIndex;
}

/**
  * @brief  This function is executed when the "RETURN" menu is selected.
  * @param  None
  * @retval None
  */
void Menu_ReturnFunc(void)
{
  psMenuItem->pfUpDownMenuFunc();
  if (nMenuLevel == 0)
  {
    nMenuLevel++;
  }
  psCurrentMenu = psPrevMenu[nMenuLevel-1];
  psMenuItem = &psCurrentMenu->psItems[0];
  ItemNumb[nMenuLevel] = 0;
  MenuItemIndex = 0;
  nMenuLevel--;
  Menu_DisplayMenu();
}

/**
  * @brief  Reads key from demo board.
  * @param  None
  * @retval Return RIGHT, LEFT, SEL, UP, DOWN, KEY or NOKEY
  */
MenuKeyStroke_t Menu_ReadKey(void)
{
  HAL_NVIC_DisableIRQ(LEFT_JOY_EXTI_IRQn);
  HAL_GPIO_EXTI_Callback(0);

  /* "right" key is pressed */
  if (DownStatus != RESET)
  {
    DownStatus = RESET;
    return DOWN;
  }
  if (RightStatus != RESET)
  {
    RightStatus = RESET;
    return RIGHT;
  }
  if (LeftStatus != RESET)
  {
    LeftStatus = RESET;
    return LEFT;
  }
  if (UpStatus != RESET)
  {
    UpStatus = RESET;
    return UP;
  }
  if (SelStatus != RESET)
  {
    SelStatus = RESET;
    return SEL;
  }
  if (KeyStatus != RESET)
  {
    KeyStatus = RESET;
    return KEY;
  }
  /* No key is pressed */
  else
  {
    return NOKEY;
  }
}

/**
  * @brief  Idle function.
  * @param  None
  * @retval None
  */
void Menu_IdleFunc(void)
{
  /* Nothing to execute: return */
  return;
}

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
