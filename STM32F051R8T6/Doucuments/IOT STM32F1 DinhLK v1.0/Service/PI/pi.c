
#include "adc.h"
#include "pwm.h"
#include "timer.h"
#include "pi.h"
/*-----------------------------------------------------*/

#define NUMBER_LED_CHANNEL 4
#define SAMPLE_TIME_CIRCUIRT_CONTROL 1   // realtime
#define SAMPLE_TIME_LIGHT_CONTROL 10  // 1ms
#define SAMPLE_TIME_ADC 1

#define LEDMAXVALUE 1000
#define KPLED 1
#define LEDTHERHOLD 100
#define LEDMINVALUE 0

#define KPCIRCUIRT 1
#define CIRCUITMAX 1000

#define CIRCUIRTMAXPERVALUE 90 //%
#define CIRCUIRTMINPERVALUE 0 //%

typedef struct tagPIDControl
{
    WORD nSetPoint;
    WORD nFeedBack;
    WORD nControl;
    WORD nError;
    BYTE nFlag; // dau if (nFlag true nError > 0)
   // BYTE nKp;
    //BYTE nKI;
} PIDCONTROL, *PPIDCONTROL;



VOID InitPIControl();
long CaculatorSetPoint( WORD nSetPoint, WORD nValueFeedBack, WORD nKp);
long ThresholdBlocking(long nValue, long nMaxValue, long nMinValue);

INTERNAL VOID PILightProcess(PVOID pData);
INTERNAL VOID ConverADC(PVOID pData);

VOID InitPIControl()
{
  StartShortTimer(SAMPLE_TIME_ADC, ConverADC, NULL);//2ms
  //StartShortTimer(SAMPLE_TIME_LIGHT_CONTROL, PILightProcess, NULL);//2ms
  //StartShortTimer(SAMPLE_TIME_CIRCUIRT_CONTROL, PCircuitProcess, NULL);//1ms
}
INTERNAL PIDCONTROL g_Circuit[NUMBER_LED_CHANNEL] = {0};
INTERNAL PIDCONTROL g_LightSensor[NUMBER_LED_CHANNEL] = {0};
INTERNAL long g_DutyCyclesSetPoint[NUMBER_LED_CHANNEL] = {0,0,0};

long ThresholdBlocking(long nValue, long nMaxValue, long nMinValue)
{
      if(nValue > nMaxValue)(nValue = nMaxValue);
      else if(nValue < nMinValue)return (nValue = nMinValue);
      return nValue;
      
}

VOID ConverADC(PVOID pData)
{
  /*
      for (BYTE nIndex = LED_CHANNEL_1; nIndex < LED_CHANNEL_4; nIndex++ )
      {
        g_LightSensor[nIndex - LED_CHANNEL_1].nFeedBack = 100*ReadADC(nIndex)/LEDMAXVALUE;
        
      }
      for (BYTE nIndex = CIRCUIT_CHANNEL_5; nIndex < CIRCUIT_CHANNEL_8; nIndex++ )
      {
        g_Circuit[nIndex -CIRCUIT_CHANNEL_5].nFeedBack = 100*ReadADC(nIndex + 1)/CIRCUITMAX;
      }
  */
     for (BYTE nIndex = LED_CHANNEL_1; nIndex < LED_CHANNEL_4; nIndex++ )
      {
        gtest[nIndex - LED_CHANNEL_1] = ReadADC(nIndex);
        
      }
      StartShortTimer(SAMPLE_TIME_ADC, ConverADC, NULL);//1ms
  
}

long CaculatorSetPoint( WORD nSetPoint, WORD nValueFeedBack, WORD nKp)
{
      long nError = nSetPoint - nValueFeedBack;
      return (nError*nKp);
}

VOID PCircuitProcess(PVOID pData)
{
            
      for (BYTE nIndex = 0; nIndex < NUMBER_LED_CHANNEL; nIndex++ )
      {
        g_Circuit[nIndex].nSetPoint = g_LightSensor[nIndex].nControl;
        g_Circuit[nIndex].nControl   = CaculatorSetPoint(g_Circuit[nIndex].nSetPoint, g_Circuit[nIndex].nFeedBack, KPCIRCUIRT);
        g_DutyCyclesSetPoint[nIndex] = ThresholdBlocking(g_Circuit[nIndex].nControl,CIRCUIRTMAXPERVALUE, -CIRCUIRTMAXPERVALUE );//%
        SetDutyCycle(nIndex, g_DutyCyclesSetPoint[nIndex]);
      }
      StartShortTimer(SAMPLE_TIME_CIRCUIRT_CONTROL, PCircuitProcess, NULL);//1ms
}

VOID PILightProcess(PVOID pData)
{
      
      for (BYTE nIndex = 0; nIndex < NUMBER_LED_CHANNEL; nIndex++ )
      {
        g_LightSensor[nIndex].nControl = CaculatorSetPoint(g_LightSensor[nIndex].nSetPoint, g_LightSensor[nIndex].nFeedBack, KPLED);
        g_LightSensor[nIndex].nControl = ThresholdBlocking(g_LightSensor[nIndex].nControl, LEDTHERHOLD, -LEDTHERHOLD );//%
      }
      StartShortTimer(SAMPLE_TIME_LIGHT_CONTROL, PILightProcess, NULL);//10ms
      
}

    