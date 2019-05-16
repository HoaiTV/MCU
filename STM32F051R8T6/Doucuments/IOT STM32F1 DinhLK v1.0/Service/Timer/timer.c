#include "system.h"
#include "timer.h"

#define TIMER_TYPE_SHORT	    0
#define TIMER_TYPE_LONG		    1
#define MAX_TIMER_COUNT		    64

#define TIMER_EXPIRED(timer) ((((timer).nType == TIMER_TYPE_SHORT) && ((WORD)(GetTickCount() - (timer).nStart) >= (timer).nTime)) \
	|| (((timer).nType == TIMER_TYPE_LONG) && ((WORD)(GetSecondCount() - (timer).nStart) >= (timer).nTime)))

typedef struct tagTIMER
{
	BYTE nType;
	WORD nStart;
	WORD nTime;
	SYSTEMCALLBACK fnCallback;
	PVOID pParameter;
} TIMER, *PTIMER;

INTERNAL TIMER g_pTimers[MAX_TIMER_COUNT] = { NULL };
 
VOID ProcessTimerEvents()
{
	INTERNAL SYSTEMCALLBACK fnCallback;
	INTERNAL PVOID pParameter;
	
	for (BYTE nIndex = 0; nIndex < MAX_TIMER_COUNT; nIndex++)
	{
		if ((g_pTimers[nIndex].fnCallback != NULL) && TIMER_EXPIRED(g_pTimers[nIndex]))
		{
			fnCallback = g_pTimers[nIndex].fnCallback;
			pParameter = g_pTimers[nIndex].pParameter;
			g_pTimers[nIndex].fnCallback = NULL;
			fnCallback(pParameter);
		}
	}
}

VOID StartLongTimer(WORD nSeconds, SYSTEMCALLBACK fnCallback, PVOID pParameter)
{
	for (BYTE nIndex = 0; nIndex < MAX_TIMER_COUNT; nIndex++)
	{
		if ((g_pTimers[nIndex].fnCallback == NULL) || (g_pTimers[nIndex].fnCallback == fnCallback))
		{
			g_pTimers[nIndex].nType = TIMER_TYPE_LONG;
			g_pTimers[nIndex].nStart = GetSecondCount();
			g_pTimers[nIndex].nTime = nSeconds;
			g_pTimers[nIndex].fnCallback = fnCallback;
			g_pTimers[nIndex].pParameter = pParameter;						
			for (nIndex = nIndex + 1; nIndex < MAX_TIMER_COUNT; nIndex++)
			{
				if (g_pTimers[nIndex].fnCallback == fnCallback)
				{
					g_pTimers[nIndex].fnCallback = NULL;
				}
			}
			return;
		}
	}
	// No timer available, critical error, must reboot to recover
	Reboot(NULL);	
}

VOID StartShortTimer(WORD nMillis, SYSTEMCALLBACK fnCallback, PVOID pParameter)
{
	for (BYTE nIndex = 0; nIndex < MAX_TIMER_COUNT; nIndex++)
	{
		if ((g_pTimers[nIndex].fnCallback == NULL) || (g_pTimers[nIndex].fnCallback == fnCallback))
		{
			g_pTimers[nIndex].nType = TIMER_TYPE_SHORT;
			g_pTimers[nIndex].nStart = GetTickCount();
			g_pTimers[nIndex].nTime = nMillis;
			g_pTimers[nIndex].fnCallback = fnCallback;
			g_pTimers[nIndex].pParameter = pParameter;
			for (nIndex = nIndex + 1; nIndex < MAX_TIMER_COUNT; nIndex++)
			{
				if (g_pTimers[nIndex].fnCallback == fnCallback)
				{
					g_pTimers[nIndex].fnCallback = NULL;
				}
			}
			return;
		}
	}
	// No timer available, critical error, must reboot to recover
	Reboot(NULL);	
}

VOID CancelTimer(SYSTEMCALLBACK fnCallback)
{
	for (BYTE nIndex = 0; nIndex < MAX_TIMER_COUNT; nIndex++)
	{
		if (g_pTimers[nIndex].fnCallback == fnCallback)
		{
			g_pTimers[nIndex].fnCallback = NULL;
			break;
		}
	}
}

BOOL IsRunning(SYSTEMCALLBACK fnCallback)
{
	for (BYTE nIndex = 0; nIndex < MAX_TIMER_COUNT; nIndex++)
	{
		if (g_pTimers[nIndex].fnCallback == fnCallback)
		{
			return TRUE;
		}
	}
	return FALSE;
}

VOID Delay_ms(volatile DWORD nTime)
{
	DWORD nTickStart = 0;
	nTickStart = GetTickCount();
	while ((GetTickCount() - nTickStart) < nTime);
}