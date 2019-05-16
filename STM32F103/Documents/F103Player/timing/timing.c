#include "timing.h"

volatile uint32_t g_TickCount;

void SysTick_Handler()
{
    g_TickCount++;
}

void Timing_Init()
{
    g_TickCount = 0;
    SysTick_Config(SystemCoreClock / 1000);
}

void Timing_SleepMs(uint32_t delay)
{
    uint32_t now = g_TickCount;

    while((g_TickCount - now) < delay);
}
