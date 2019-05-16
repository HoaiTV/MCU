#ifndef __ADC_H__
#define __ADC_H__

#define ADC_CHANNEL_1           0x01
#define ADC_CHANNEL_2           0x02
#define ADC_CHANNEL_3           0x03
#define ADC_CHANNEL_4           0x04
#define ADC_CHANNEL_5           0x05
#define ADC_CHANNEL_6           0x06
#define ADC_CHANNEL_7           0x07
#define ADC_CHANNEL_8           0x08

#define ADC_MAX_CHANNEL ADC_CHANNEL_8


VOID InitADC();
WORD ReadADC(BYTE Channel);
VOID ReadADCProcess(PVOID pDATA);

#endif // __ADC_H__