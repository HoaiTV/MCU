#include "stm32f10x.h"
#include "io.h"
#include "ds18b20.h"
#include "uart.h"
#include "timer.h"

#define DELAY_2US()     { for (WORD index = 0; index < 21; index++) asm("NOP"); }

#define DELAY_US(a)     { WORD delay = (a) * 10; for (WORD index = 0; index < delay; index++) asm("NOP");}

#define DS18B20_PIN         GPIO_Pin_9
#define DS18B20_PORT        GPIO_PORTB

#define DQ_HIGH()   {SetPin(DS18B20_PORT, DS18B20_PIN, 0);}
#define DQ_LOW()    {SetPin(DS18B20_PORT, 0, DS18B20_PIN);}

INTERNAL BOOL OneWireReset();
INTERNAL BYTE ReadOneWireByte();
INTERNAL VOID WriteOneWireByte(BYTE byData);
BYTE Temperature = 0;

VOID DS18B20_Init()
{ 
    SetDirPin(DS18B20_PORT, 0, DS18B20_PIN);
    DQ_HIGH();
    WriteUartTransmit(UART_PORT_2,0x20,Temperature);
}

BOOL DS18B20_ReadTemperature(PDS18B20DATA pData)
{
    BYTE byLowTemp, byHighTemp;
    
    OneWireReset();
    
    WriteOneWireByte(0xCC);
    WriteOneWireByte(0x44);
    
    DELAY_US(104);
    
    OneWireReset();
    WriteOneWireByte(0xCC);
    WriteOneWireByte(0xBE);
    
    byLowTemp = ReadOneWireByte();
    byHighTemp = ReadOneWireByte();
    
    if (byLowTemp != 0xFF)
    {
        pData->nInteger = ((byLowTemp & 0xf0) >> 4) + ((byHighTemp & 0x07) << 4);
        pData->nDecimal = byLowTemp & 0x0F;
        Temperature = pData->nInteger;
        WriteUartTransmit(UART_PORT_2,0x20,Temperature);
        return TRUE;
    }
    return FALSE;
}

INTERNAL BOOL OneWireReset()
{
    DQ_LOW();
    DELAY_US(500);
    DQ_HIGH();
    DELAY_US(500);
    return TRUE;
}

INTERNAL BYTE ReadOneWireByte()
{    
    BYTE byValue = 0;
    for (BYTE nCount = 0; nCount < 8; nCount++)
    {
        byValue >>= 1;
        DQ_LOW();
        DELAY_2US();
        DQ_HIGH();
        DELAY_2US();
        if (GetPin(DS18B20_PORT, DS18B20_PIN))
        {
            byValue |= 0x80;
        }
        DELAY_US(50);
    }
    return (byValue);
}

INTERNAL VOID WriteOneWireByte(BYTE byData)
{
    for (BYTE nCount = 0; nCount < 8; nCount++)
    {
        DQ_LOW();
        DELAY_2US();
        if ((byData >> nCount) & 0x01)
        {
            DQ_HIGH();
        }
        DELAY_US(50);
        DQ_HIGH();
        DELAY_2US();
    }
}