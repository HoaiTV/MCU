#ifndef __DHT21_H__
#define __DHT21_H__

typedef struct tagDHT21DATA
{
    BYTE nTemperature;
    BYTE nHumidity;
} DHT21DATA, *PDHT21DATA;

VOID DHT21_Init();
BOOL DHT21_GetData(PDHT21DATA pData);

#endif