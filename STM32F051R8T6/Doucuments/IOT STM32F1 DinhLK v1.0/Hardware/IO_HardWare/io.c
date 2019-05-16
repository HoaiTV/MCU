#include "stm32f10x_rcc.h"
#include "io.h"

INTERNAL GPIO_TypeDef* g_stIOPort[GPIO_PORT_COUNT] = { GPIOA, GPIOB, GPIOC, GPIOC };


VOID InitIO()
{

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
}

VOID SetDirPin(BYTE nPort, WORD wInputPin, WORD wOutputPin)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    if (nPort < GPIO_PORT_COUNT)
    {
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        
        if (wOutputPin != 0)
        {
            GPIO_InitStructure.GPIO_Pin = wOutputPin;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
            GPIO_Init(g_stIOPort[nPort], &GPIO_InitStructure);
        }
        
        if (wInputPin != 0)
        {
            GPIO_InitStructure.GPIO_Pin = wInputPin;
            GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
            GPIO_Init(g_stIOPort[nPort], &GPIO_InitStructure);
        }
    }
}

VOID SetPin(BYTE nPort, WORD wSetPin, WORD wClearPin)
{
    if (nPort < GPIO_PORT_COUNT)
    {
        if (wSetPin) {
            GPIO_SetBits(g_stIOPort[nPort], wSetPin);
        }
        
        if (wClearPin) {
            GPIO_ResetBits(g_stIOPort[nPort], wClearPin);
        }
    }
}

BOOL GetPin(BYTE nPort, WORD nPin)
{
    WORD nReval = GetAllPins(nPort);
    return ((nReval & nPin) == nPin);
}

WORD GetAllPins(BYTE nPort)
{
    if (nPort < GPIO_PORT_COUNT)
    {
        return GPIO_ReadInputData(g_stIOPort[nPort]);
    }
    return 0;
}