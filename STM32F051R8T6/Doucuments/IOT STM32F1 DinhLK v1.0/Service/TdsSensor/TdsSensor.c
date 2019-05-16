#include "TdsSensor.h"
#include "timer.h"
#include "adc.h"
#include "io.h"
#include "stm32f10x_gpio.h"
#include "ds18b20.h"
#include "uart.h"


#define TDS_CH1   GPIO_Pin_8
#define TDS_CH2   GPIO_Pin_9
#define TDS_CH1_N   GPIO_Pin_13
#define TDS_CH2_N   GPIO_Pin_14


#define TDS_PORT1       GPIO_PORTA
#define TDS_PORT2       GPIO_PORTB

#define TDS_DELAY_US(a)     { WORD delay = (a) * 10; for (WORD index = 0; index < delay; index++) asm("NOP");}
#define TDS_TIME_CYCLES 60 // 60s
#define TDS_SENSOR_CHANNEL1 1
#define TDS_SENSOR_CHANNEL2 2
#define NUMBER_CHANNEL_TDS 2
#define TDSNOISEVONTAGLE 380
#define TDSTHERDHOLDVALUE 3000

#define SIZE_BUFFER_TDS 6


INTERNAL DWORD g_arPPM[NUMBER_CHANNEL_TDS] = {0, 0};
INTERNAL WORD g_arVdropCH[NUMBER_CHANNEL_TDS] = {0, 0};
INTERNAL WORD g_arVdropCHN[NUMBER_CHANNEL_TDS] = {0, 0};
INTERNAL BYTE flag_tds_ch = TRUE;
/*******************************************************************************/

INTERNAL WORD g_TDSLookUpTable[SIZE_BUFFER_TDS]  = {382,482,667,1050,1435,3763};
INTERNAL WORD g_TDSRefLookUpTable[SIZE_BUFFER_TDS] = {73,153,300,718,1590,3400};

//INTERNAL WORD g_TDSLookUpTable[SIZE_BUFFER_TDS]  = {382,409,443,455,482,510,520,572,589,623,648,676,705,736,796,857,866,908,945,995,1038,1095,1195,1254,1299,1435,1508,1650,1835,1904,2057,2161,2300,2434,2557,2711,2950,3200,3356};
//INTERNAL WORD g_TDSRefLookUpTable[SIZE_BUFFER_TDS] = {73,88,108,126,153,170,182,215,235,285,310,340,382,405,474,518,574,611,653,718,874,838,1000,1060,1160,1590,1700,1860,2050,2178,2270,2420,2690,2790,2890,2980,3170,3430,3560};
/*******************************************************************************/


WORD AutoCalib(WORD nValue)
{
   BYTE nIndex = 0;
   if(nValue > g_TDSLookUpTable[SIZE_BUFFER_TDS - 1] )return nValue;
   else if ((nValue > g_TDSLookUpTable[0]))
   for (nIndex = 0; nIndex < SIZE_BUFFER_TDS; nIndex ++) 
   { 
     if(nValue  == g_TDSLookUpTable[nIndex])break;
     if(g_TDSLookUpTable[nIndex] < nValue && nValue < g_TDSLookUpTable[nIndex +1] ) break;
   }
   BYTE nValueDIv  = 10*g_TDSLookUpTable[nIndex]/g_TDSRefLookUpTable[nIndex];
   if(nValueDIv)return (10*nValue/nValueDIv);
   else return 0xFFFF;
}




VOID TDSStop()
{
      SetPin(TDS_PORT1, 0, TDS_CH1); 
      SetPin(TDS_PORT2, 0, TDS_CH1_N); 
      
      SetPin(TDS_PORT1, 0, TDS_CH2); 
      SetPin(TDS_PORT2, 0, TDS_CH2_N); 
      if(flag_tds_ch)flag_tds_ch = 0;
      else flag_tds_ch  = 1;
}


/********************************************************************************/

VOID TDSStart(BYTE nActive)
{
     if(nActive)
      {
        SetPin(TDS_PORT1, 0, TDS_CH1); 
        SetPin(TDS_PORT2, TDS_CH1_N, 1); 
        
        SetPin(TDS_PORT1, 0, TDS_CH2);
        SetPin(TDS_PORT2, TDS_CH2_N, 1); 
      }
      else {
        SetPin(TDS_PORT1, TDS_CH1, 1); 
        SetPin(TDS_PORT2, 0, TDS_CH1_N); 
        
        SetPin(TDS_PORT1, TDS_CH2, 1); 
        SetPin(TDS_PORT2, 0, TDS_CH2_N); 
      }
      
}

WORD SubValue(WORD nValue1, WORD nValue2)
{
    if(nValue1 > nValue2)return (nValue1 - nValue2);
    else return (nValue2 - nValue1);
}

INTERNAL  WORD nVdrop[2] = {0,0};


VOID TDSCallBack(PVOID pData)
{
  
      TDSStart(flag_tds_ch);
      TDS_DELAY_US(300);
      g_arVdropCHN[0] = ReadADC(1);
      g_arVdropCHN[1] = ReadADC(2);
      TDSStop();    
      WORD nAdvance;
      for (BYTE nIndex = 0; nIndex < NUMBER_CHANNEL_TDS -1 ; nIndex ++) 
      {
        nAdvance = SubValue(g_arVdropCHN[nIndex], g_arVdropCH[nIndex]);
        nVdrop[nIndex] = (g_arVdropCHN[nIndex] + g_arVdropCH[nIndex])/2;

        if(g_arVdropCHN[nIndex] > TDSTHERDHOLDVALUE)
        {
          g_arPPM[nIndex] = nVdrop[nIndex];
        }
        else if(g_arVdropCHN[nIndex] < TDSNOISEVONTAGLE)
        {
          g_arPPM[nIndex] = 0;
        }
        else 
          g_arPPM[nIndex] = AutoCalib(nVdrop[nIndex]);
      }
}


VOID ReadTdsSensor(PVOID pDATA)
{
  

      TDSStart(flag_tds_ch);
      TDS_DELAY_US(300);
      g_arVdropCH[0] = ReadADC(1);
      g_arVdropCH[1] = ReadADC(2);
      TDSStop();
      StartShortTimer(1, (SYSTEMCALLBACK)TDSCallBack, NULL);
      
}

/*******************************************************************************/
VOID TdsSensor_Process(PVOID pData)
{
      ReadTdsSensor(NULL);
      StartLongTimer(3, TdsSensor_Process, NULL);
}
/*******************************************************************************/

VOID InitTdsSensor()
{
      SetDirPin(TDS_PORT1, 0, TDS_CH1);// set up power for TDS sensor
      SetDirPin(TDS_PORT1, 0, TDS_CH2);// set up power for TDS sensor
      SetDirPin(TDS_PORT2, 0, TDS_CH1_N);// set up power for TDS sensor
      SetDirPin(TDS_PORT2, 0, TDS_CH2_N);// set up power for TDS sensor
      TDSStop(TRUE);
      StartShortTimer(3000, TdsSensor_Process, NULL);
}


/******************************************************************************/
DWORD GetTDSResult(BYTE nChannel, BYTE nEnable)
{
      if(nEnable)
      {
        StartLongTimer(2000, TdsSensor_Process, NULL);
      }
      else CancelTimer(TdsSensor_Process);
      return g_arPPM[nChannel]; 
}



