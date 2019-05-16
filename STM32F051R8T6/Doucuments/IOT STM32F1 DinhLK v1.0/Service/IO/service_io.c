#include "io.h"
#include "service_io.h"
#include "lcd16x2.h"
VOID InitIOService()
{
    
    SetDirPin(RELAY2_PORT, 0, (RELAY2_PIN | RELAY3_PIN | RELAY1_PIN));
    SetDirPin(RELAY4_PORT, 0, RELAY4_PIN);
    
    SetDirPin(LCD_D4_PORT, 0, LCD_D4_PIN);
    SetDirPin(LCD_D5_PORT, 0, LCD_D5_PIN);
    SetDirPin(LCD_D6_PORT, 0, LCD_D6_PIN);
    SetDirPin(LCD_D7_PORT, 0, LCD_D7_PIN);
    SetDirPin(LCD_RS_PORT, 0, LCD_RS_PIN);
    SetDirPin(LCD_EN_PORT, 0, LCD_EN_PIN);
    
    SetPin(LCD_D4_PORT, 0, LCD_D4_PIN);
    SetPin(LCD_D5_PORT, 0, LCD_D5_PIN);
    SetPin(LCD_D6_PORT, 0, LCD_D6_PIN);
    SetPin(LCD_D7_PORT, 0, LCD_D7_PIN);
    SetPin(LCD_RS_PORT, 0, LCD_RS_PIN);
    SetPin(LCD_EN_PORT, 0, LCD_EN_PIN);
    
    SetPin(RELAY1_PORT, 0, RELAY1_PIN);
    SetPin(RELAY2_PORT, 0, (RELAY2_PIN | RELAY3_PIN | RELAY4_PIN));
    
    //Led power on status
    //SetPin(LED_RED_PORT, LED_RED_PIN, 0);
}

VOID SetIOState(BYTE nIOPort, WORD wIOPin, BOOL bState)
{
    if (bState)
        SetPin(nIOPort, wIOPin, 0);
    else
        SetPin(nIOPort, 0, wIOPin);
}


