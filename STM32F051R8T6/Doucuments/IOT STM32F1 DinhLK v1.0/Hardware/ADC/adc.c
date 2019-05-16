#include "stm32f10x_dma.h"
#include "stm32f10x_adc.h"
#include "timer.h"
#include "uart.h"
#include "adc.h"

#define ADC_CHANEL_NUMBER       3
#define ADC1_DR_ADD             ((DWORD)0x4001244C)
#define ADC_DELAY_US(a)     { WORD delay = (a) * 10; for (WORD index = 0; index < delay; index++) asm("NOP");}

BYTE g_ValueVotage = 0;
BYTE g_pH = 0;
BYTE g_Light = 0;
BYTE g_Offset = 3;
WORD g_arADC[ADC_CHANEL_NUMBER] = { 0 };
WORD g_arADC_0 = 0;
WORD g_arADC_1 = 0;
WORD g_arADC_2 = 0;
VOID InitADC()
{
	ADC_InitTypeDef ADC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
        GPIO_InitTypeDef GPIO_InitStructure;
        
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_AFIO, ENABLE);
	
	/* DMA channel1 configuration ----------------------------------------------*/
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_ADD;
	DMA_InitStructure.DMA_MemoryBaseAddr = (DWORD)g_arADC;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = ADC_CHANEL_NUMBER;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	
	/* Enable DMA1 channel1 */
	DMA_Cmd(DMA1_Channel1, ENABLE);
    
	/* ADC1 configuration ------------------------------------------------------*/
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = ADC_CHANEL_NUMBER;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	/* ADC1 regular channel15 configuration */ 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_239Cycles5);  
        ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 3, ADC_SampleTime_239Cycles5);  
	
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);                 /* Enable ADC1 */ 
	
	/* Enable ADC1 reset calibaration register */   
	ADC_ResetCalibration(ADC1);
	/* Check the end of ADC1 reset calibration register */
	while (ADC_GetResetCalibrationStatus(ADC1));
	
	/* Start ADC1 calibaration */
	ADC_StartCalibration(ADC1);
	/* Check the end of ADC1 calibration */
	while (ADC_GetCalibrationStatus(ADC1));                     
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);    /*  */
        StartLongTimer(3, ReadADCProcess, NULL);
}

WORD ReadADC(BYTE nChannel)
{
    if (nChannel <= 3)
    {
            return g_arADC[nChannel - 1];
    }
            
    else
        return 0;
}
VOID ReadADCProcess(PVOID pDATA)
{
  
            g_arADC_0 = ReadADC(1);
            g_arADC_1 = ReadADC(2);
            g_arADC_2 = ReadADC(3);
            g_ValueVotage = (BYTE)3.3*g_arADC_2/4096;
            g_pH = (BYTE)3.5*g_ValueVotage + g_Offset;
            g_Light = (BYTE)100*g_arADC_1/4096;
            WriteUartTransmit(UART_PORT_2,0x22,g_pH);
            //g_Light = 70;
            ADC_DELAY_US(3);
            WriteUartTransmit(UART_PORT_2,0x23,g_Light);
            StartLongTimer(3, ReadADCProcess, NULL);
}

