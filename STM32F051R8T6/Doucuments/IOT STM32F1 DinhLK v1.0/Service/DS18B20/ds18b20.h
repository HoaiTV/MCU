#ifndef __DS18B20_H__
#define __DS18B20_H__

typedef struct tagDS18B20DATA
{
    BYTE nInteger;
    BYTE nDecimal;
} DS18B20DATA, *PDS18B20DATA;

VOID DS18B20_Init();
BOOL DS18B20_ReadTemperature(PDS18B20DATA pData);
VOID ReadTemperatureProcess(PVOID pData);
#endif /*DS1820_H_*/
