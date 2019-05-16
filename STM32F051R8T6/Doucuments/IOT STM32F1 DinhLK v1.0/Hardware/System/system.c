
/********************************************************************************/
/*-----------------------------------------------------------------------------*/
/* Header inclusions */
/*-----------------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "uart.h"
#include <time.h>
#include <stdlib.h>
#include "system.h"
/*-----------------------------------------------------------------------------*/
/* Local Constant definitions */
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/* Local Macro definitions */
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/* Local Data type definitions */
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
/* Global variables */
/*-----------------------------------------------------------------------------*/
INTERNAL WORD g_wTickCount = 0;
INTERNAL WORD g_wSecondCount = 0;
INTERNAL WORD g_wTemp = 0;
/*-----------------------------------------------------------------------------*/
/* Function prototypes */
/*-----------------------------------------------------------------------------*/
VOID SysTick_Handler();
/*-----------------------------------------------------------------------------*/
/* Function implementations */
/*-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------- 
Function:  InitSystem()
Purpose: 
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID InitSystem()
{
    if (SysTick_Config(SystemCoreClock / 1000))
    { 
        /* Capture error */ 
        while (TRUE);
    }
}
/*------------------------------------------------------------------------------- 
Function:  GetTickCount()
Purpose: 
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
WORD GetTickCount()
{
    return g_wTickCount;
}
/*------------------------------------------------------------------------------- 
Function:  GetSecondCount()
Purpose:
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
WORD GetSecondCount()
{
    return g_wSecondCount;
}
/*------------------------------------------------------------------------------- 
Function:  Random(WORD nRange)
Purpose: Random number from 0 to nRange
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
WORD Random(WORD nRange)
{
    srand(time(NULL));
    return (rand() % nRange);
}
/*------------------------------------------------------------------------------- 
Function:  ByteRandom()
Purpose: Random number from 0x00 to 0xFF
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
BYTE ByteRandom()
{
    return Random(0xFF);
}
/*------------------------------------------------------------------------------- 
Function:  VOID Reboot()
Purpose: Restart the device
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID Reboot()
{
    NVIC_DisableIRQ(USART2_IRQn);
    NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x00);
    
    DWORD VEC_RESET_ADDR = *(__IO uint32_t*)(PROGRAM_START_ADDRESS + 4);
    SYSTEMCALLBACK RebootFunc = (SYSTEMCALLBACK)VEC_RESET_ADDR;
    RebootFunc(NULL);
}
/*------------------------------------------------------------------------------- 
Function:  CopyMemory(PBYTE pDest, PBYTE pSource, WORD nSize)
Purpose: 
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID CopyMemory(PBYTE pDest, PBYTE pSource, WORD nSize)
{
	while (nSize)
	{
		*pDest = *pSource;
		pDest++;
		pSource++;
		nSize--;
	}
}
/*------------------------------------------------------------------------------- 
Function:  CopyInvert(PBYTE pDest, PBYTE pSource, BYTE nSize)
Purpose:
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID CopyInvert(PBYTE pDest, PBYTE pSource, BYTE nSize)
{
	pSource += nSize - 1;
	while (nSize)
	{
		*pDest = *pSource;
		pDest++;
		pSource--;
		nSize--;
	}	
}
/*------------------------------------------------------------------------------- 
Function:  ZeroMemory(PBYTE pDest, BYTE nSize)
Purpose:
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID ZeroMemory(PBYTE pDest, BYTE nSize)
{
	while (nSize)
	{
		*pDest = 0;
		pDest++;
		nSize--;
	}
}
/*------------------------------------------------------------------------------- 
Function: ActivateWatchdog()
Purpose: 
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID ActivateWatchdog()
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(IWDG_Prescaler_64);
    IWDG_SetReload(0x0FFF);
    IWDG_ReloadCounter();
    IWDG_Enable();
}
/*------------------------------------------------------------------------------- 
Function:  ResetWatchdog()
Purpose:
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID ResetWatchdog()
{
    IWDG_ReloadCounter();
}
/*------------------------------------------------------------------------------- 
Function:  SetDefaultCacheMode()
Purpose:
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID SetDefaultCacheMode()
{
    
}
/*------------------------------------------------------------------------------- 
Function:  SetPrefetchCacheMode()
Purpose:
Parameters: None
Return: None
Comments:  None
Modified: 
<Modified by> 
<Date> 
<Change> 
--------------------------------------------------------------------------------*/
VOID SetPrefetchCacheMode()
{
    
}
/*******************************************************************************
Function:VOID SysTick_Handler(VOID);
Purpose: SysTick_Handler
Parameters: None
Return: None
Comments: None
Modified: 
  <Modified by> 
  <Date> 
  <Change> 
--------------------------------------------------------------------------------*/ 
VOID SysTick_Handler()
{
    g_wTickCount++;
	g_wTemp++;
	if (g_wTemp == 1000)
	{
		g_wSecondCount++;
		g_wTemp = 0;
	}
}