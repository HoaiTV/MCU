#ifndef __HW_TIMER_H__
#define __HW_TIMER_H__

VOID HwTimer_Init();
VOID HwTimer_Delay(DWORD nuSecond);
WORD GetCounter();
VOID EnableHwTimer();
VOID DisableHwTimer();
#endif