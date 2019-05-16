#include "Params.h"
#include "timer.h"
#include "pwm.h"
#include "dimmer.h"
#include "device.h"

//set dimmer time to 4s
#define DIMMER_TIME1        4
#define DIMMER_TIME2        4
#define DIMMER_TIME3        4

#define DIM_CHANNEL_COUNT   1

INTERNAL WORD g_arSetChannel[DIM_CHANNEL_COUNT] = { 0 };
INTERNAL WORD g_arCurrentChannel[DIM_CHANNEL_COUNT] = { 0 };

INTERNAL VOID ProcessDimmerChannel1(PVOID pParam);
//INTERNAL VOID ProcessDimmerChannel2(PVOID pParam);
//INTERNAL VOID ProcessDimmerChannel3(PVOID pParam);

VOID InitDimmer()
{
	ProcessDimmerChannel1(NULL);
	//ProcessDimmerChannel2(NULL);
	//ProcessDimmerChannel3(NULL);
}

VOID SetDimmerChannel(BYTE nDimChannel, BYTE nValue)
{
    if (nDimChannel < DIM_CHANNEL_COUNT)
    {
        g_arSetChannel[nDimChannel] = nValue;
        g_arSetChannel[nDimChannel] *= 10;
    }
}

INTERNAL VOID ProcessDimmerChannel1(PVOID pParam)
{
	if (g_arCurrentChannel[DIM_CHANNEL_1] < g_arSetChannel[DIM_CHANNEL_1])
	{
		g_arCurrentChannel[DIM_CHANNEL_1] += 1;
        SetDutyCycle(PWM_CHANNEL_1, g_arCurrentChannel[DIM_CHANNEL_1]);
	}
	else if (g_arCurrentChannel[DIM_CHANNEL_1] > g_arSetChannel[DIM_CHANNEL_1])
	{
		g_arCurrentChannel[DIM_CHANNEL_1] -= 1;
        SetDutyCycle(PWM_CHANNEL_1, g_arCurrentChannel[DIM_CHANNEL_1]);
	}
    else if ((g_arCurrentChannel[DIM_CHANNEL_1] / 10) != LIGHT1_CURRENT)
    {
        SetRegister(LIGHT1_CURRENT_REG, g_arCurrentChannel[DIM_CHANNEL_1] / 10);
    }
	
	if (((g_arCurrentChannel[DIM_CHANNEL_1] % 100) == 0) && ((g_arCurrentChannel[DIM_CHANNEL_1] / 10) != LIGHT1_CURRENT))
	{
		SetRegister(LIGHT1_CURRENT_REG, g_arCurrentChannel[DIM_CHANNEL_1] / 10);
	}
    
	StartShortTimer(DIMMER_TIME1, ProcessDimmerChannel1, NULL);
}

