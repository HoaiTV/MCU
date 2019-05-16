#include "system.h"
#include "io.h"
#include "dht21.h"

#define DHT21_PORT  GPIO_PORTA
#define DHT21_PIN   GPIO_Pin_12

#define DHT_DELAY_US(a)     { WORD delay = (a) * 10; for (WORD index = 0; index < delay; index++) asm("NOP");}
#define DHT_TIMEOUT(t)      ((GetTickCount() - (t)) < 50)

VOID DHT21_Init()
{
    SetDirPin(DHT21_PORT, DHT21_PIN, 0);
}

BOOL DHT21_GetData(PDHT21DATA pData)
{
    BYTE arBuffer[5] = { 0 };
    BYTE byChecksum;
    WORD nTick;
    
    SetDirPin(DHT21_PORT, 0, DHT21_PIN);
    SetPin(DHT21_PORT, 0 , DHT21_PIN);
    
    DHT_DELAY_US(250);
    
    SetPin(DHT21_PORT, DHT21_PIN, 0);
    SetDirPin(DHT21_PORT, DHT21_PIN, 0);
    DHT_DELAY_US(15);
    
    if (GetPin(DHT21_PORT, DHT21_PIN))
        return FALSE;
    
    nTick = GetTickCount();
    while ((!GetPin(DHT21_PORT, DHT21_PIN)) & DHT_TIMEOUT(nTick));
    
    DHT_DELAY_US(10);       
    
    if (!GetPin(DHT21_PORT, DHT21_PIN))
        return FALSE;
    
    nTick = GetTickCount();
    while (GetPin(DHT21_PORT, DHT21_PIN) & DHT_TIMEOUT(nTick));
    
    for (BYTE nIndex = 0; nIndex < 5; nIndex++)
    {
        for (BYTE nCount = 0; nCount < 8; nCount++)
        {             
            nTick = GetTickCount();
            while ((!GetPin(DHT21_PORT, DHT21_PIN)) & DHT_TIMEOUT(nTick));
            
            DHT_DELAY_US(10);
            
            if (GetPin(DHT21_PORT, DHT21_PIN))
            {
                arBuffer[nIndex] |= ( 1 << (7 - nCount));
                nTick = GetTickCount();
                while (GetPin(DHT21_PORT, DHT21_PIN) & DHT_TIMEOUT(nTick));
            }
        }
    }
    
    byChecksum = (arBuffer[0] + arBuffer[1] + arBuffer[2] + arBuffer[3]);
    if (byChecksum != arBuffer[4])
        return FALSE;   
    
    pData->nTemperature  = ((arBuffer[2] * 256 + arBuffer[3]) / 10);
    pData->nHumidity = ((arBuffer[0] * 256 + arBuffer[1]) / 10);
    
    SetPin(DHT21_PORT, DHT21_PIN, 0);
    
    return TRUE;
}