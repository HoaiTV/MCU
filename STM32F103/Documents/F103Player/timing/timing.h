#ifndef TIMING_H
#define TIMING_H

#include <stm32f1xx.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    uint32_t start_tick;
    uint32_t timeout;
} timeout_t;

extern volatile uint32_t g_TickCount;

void Timing_Init();
void Timing_SleepMs(uint32_t delay);

inline __attribute__((always_inline))
uint32_t Timing_GetTickCount()
{
    return g_TickCount;
}

inline __attribute__((always_inline))
void Timing_TimeoutInit(timeout_t *to_s, uint32_t timeout_ms)
{
    to_s->start_tick = g_TickCount;
    to_s->timeout = timeout_ms;
}

inline __attribute__((always_inline))
bool Timing_TimeoutExpired(timeout_t *to_s)
{
    return (g_TickCount - to_s->start_tick) > to_s->timeout;
}


#endif // TIMING_H
