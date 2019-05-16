#ifndef __TIMER_H__
#define __TIMER_H__

VOID ProcessTimerEvents();
VOID StartLongTimer(WORD nSeconds, SYSTEMCALLBACK fnCallback, PVOID pParameter);
VOID StartShortTimer(WORD nMillis, SYSTEMCALLBACK fnCallback, PVOID pParameter);
VOID CancelTimer(SYSTEMCALLBACK fnCallback);
BOOL IsRunning(SYSTEMCALLBACK fnCallback);
VOID Delay_ms(volatile DWORD nTime);
#endif //__TIMER_H__

