#ifndef __PWM_H__
#define __PWM_H__

#define PWM_CHANNEL_1   0
#define PWM_CHANNEL_2   1
#define PWM_CHANNEL_3   2
#define PWM_CHANNEL_4   4

VOID InitPWM();
VOID SetDutyCycle(BYTE nChannel, WORD nDutyCycle);

#endif // _PWM_H__