#include "stm32f10x_usart.h"
#include "uart.h"
#include "io.h"
#include "Params.h"
#include "service_io.h"
#include "device.h"
#include "timer.h"
#include "pwm.h"
#include "dimmer.h"
#include "stepmotor.h"
#include "buzz.h"
#include "blinkled.h"


#define UART_BUFFER_SIZE	    255

#define SERIAL_START_BYTE	    0xAA
#define SERIAL_STOP_BYTE	    0x55
#define PAYLOAD_LENGTH(p) ((p)[1] == 0xFF ? (p)[2] + ((p)[3] << 8) : (p)[1])
#define PAYLOAD_OFFSET(p) ((p)[1] == 0xFF ? 4 : 2)
#define STOP_BYTE_INDEX(p) ((p)[1] == 0xFF ? (p)[2] + ((p)[3] << 8) + 4 : (p)[1] + 2)
#define PAYLOAD_TYPE(p) ((p)[1] == 0xFF ? LONG_BUFFER : SHORT_BUFFER)

#define UART_PORT           g_pUartDef[g_nUartPort]

#define STEPMOTOR                   0x01
#define RELAY_1                     0x03
#define RELAY_2                     0x11

#define RELAY_3                     0x12
#define BlinkLedSuccess             0x10
#define DIMMER_LED                  0x09




BYTE g_nUartPort = 0;
WORD nDataTran=0;


INTERNAL USART_TypeDef* g_pUartDef[MAX_UART_PORT] = { USART1, USART2, USART3 };

INTERNAL UARTBUFFER  g_stUartBuffer = { NULL };
INTERNAL UARTBUFFER_ m_stUartBuffer = { NULL };


INTERNAL SYSTEMCALLBACK fnUartCallBack[MAX_UART_EVENT] = { NULL };
INTERNAL BYTE g_nProcessIndex = 0;
INTERNAL BYTE g_nPackageIndex = 0;
INTERNAL BYTE g_nBufferIndex = 0;
INTERNAL BYTE g_pReceivePackage[UART_BUFFER_SIZE] = { 0x00 };
INTERNAL BYTE g_pReceiveBuffer[UART_BUFFER_SIZE] = { 0 };

INTERNAL VOID NVIC_UART_Configuration(BYTE nPort);
INTERNAL VOID RCC_UART_Configuration(BYTE nPort);
INTERNAL VOID GPIO_UART_Configuration(BYTE nPort);
VOID USART2_IRQHandler();


VOID OpenUartPort(BYTE nPort, DWORD nBaudrate)
{
	NVIC_UART_Configuration(nPort);
	RCC_UART_Configuration(nPort);
	GPIO_UART_Configuration(nPort);
    USART_InitTypeDef USART_InitStructure;

    USART_InitStructure.USART_BaudRate = nBaudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    
    if (nPort < MAX_UART_PORT)
    {
        g_nUartPort = nPort;
        USART_Init(UART_PORT, &USART_InitStructure);
        /* Enable USARTz Receive and Transmit interrupts */
        USART_ITConfig(UART_PORT, USART_IT_RXNE, ENABLE);
        USART_ITConfig(UART_PORT, USART_IT_TXE, DISABLE);
        /* Enable the USARTz */
        USART_Cmd(UART_PORT, ENABLE);
    }
}

VOID WriteUart(BYTE nPort, PVOID pData, BYTE nLen)
{
    for (BYTE nIndex = 0; nIndex < nLen; nIndex++)
    {
        USART_SendData(UART_PORT, *((PBYTE)pData + nIndex));
        while (USART_GetFlagStatus(UART_PORT, USART_FLAG_TXE) == RESET);
    }
}
VOID WriteUartTransmit(BYTE nPort, BYTE Command, BYTE Data)  
{
    m_stUartBuffer.nCommand_ = Command;
    m_stUartBuffer.nData_ = Data;
 
    USART_SendData(UART_PORT, SERIAL_START_BYTE);////////////////////Start byte
    while (USART_GetFlagStatus(UART_PORT, USART_FLAG_TXE) == RESET);
    
    USART_SendData(UART_PORT, m_stUartBuffer.nCommand_);/////////////command
    while (USART_GetFlagStatus(UART_PORT, USART_FLAG_TXE) == RESET);
        
    USART_SendData(UART_PORT,  m_stUartBuffer.nData_);///////////////Data
    while (USART_GetFlagStatus(UART_PORT, USART_FLAG_TXE) == RESET);
   
    USART_SendData(UART_PORT, SERIAL_STOP_BYTE);/////////////////////Stop Byte
    while (USART_GetFlagStatus(UART_PORT, USART_FLAG_TXE) == RESET);
}

VOID RegisterUartCallback(BYTE nEvent, SYSTEMCALLBACK fnCallback)
{
    if (nEvent < MAX_UART_EVENT)  
    {
        fnUartCallBack[nEvent] = fnCallback;
    }
}

WORD nI1=0;
WORD nI2=0;
WORD nI3=0;
WORD nData_=0;
BYTE nDimmer=0;
//0xAA,0x03,0x01,0x01,0x66,0x55
RESULT ProcessUartEvents()
{
    if (g_nProcessIndex != g_nBufferIndex)
    {
        g_pReceivePackage[g_nPackageIndex] = g_pReceiveBuffer[g_nProcessIndex];
        if (g_nPackageIndex == STOP_BYTE_INDEX(g_pReceivePackage))
        {
            if (g_pReceivePackage[g_nPackageIndex] == SERIAL_STOP_BYTE)
            {
                if (fnUartCallBack[UART_DATA_EVENT] != NULL)
                {
                    g_stUartBuffer.nTypeBuffer = PAYLOAD_TYPE(g_pReceivePackage);;
                    g_stUartBuffer.nLength = PAYLOAD_LENGTH(g_pReceivePackage) - 2;
                    g_stUartBuffer.nAddr = g_pReceivePackage[PAYLOAD_OFFSET(g_pReceivePackage)];
                    g_stUartBuffer.nCommand = g_pReceivePackage[PAYLOAD_OFFSET(g_pReceivePackage) + 1];
                    g_stUartBuffer.pData = &g_pReceivePackage[PAYLOAD_OFFSET(g_pReceivePackage) + 2];
                    
                    fnUartCallBack[UART_DATA_EVENT](&g_stUartBuffer);
                    BuzzSet(3);
                    switch (g_stUartBuffer.nCommand) {   
                              case STEPMOTOR:
                                   InitStepMotor();
                                   break;
                              case BlinkLedSuccess:
                                   LedSet(5);
                                   break;             
                              case RELAY_3:
                                      if(nI3%2) SetIOState(RELAY3_PORT, RELAY3_PIN,0);
                                      else SetIOState(RELAY3_PORT, RELAY3_PIN,1);
                                      nI3++;
                                      if(nI3>1000)    nI3=1;
                                      g_stUartBuffer.nCommand=0;
                                   break;
                              case RELAY_2:
                                      if(nI2%2) SetIOState(RELAY2_PORT, RELAY2_PIN,0);
                                      else SetIOState(RELAY2_PORT, RELAY2_PIN,1);
                                      nI2++;
                                      if(nI2>1000)  nI2=1;
                                      g_stUartBuffer.nCommand=0;
                                   break;
                                   
                              case RELAY_1:
                                      if(nI1%2) SetIOState(RELAY1_PORT, RELAY1_PIN,0);
                                      else SetIOState(RELAY1_PORT, RELAY1_PIN,1);
                                      //if (nI1%2) SetPin(RELAY1_PORT, 0, RELAY1_PIN);
                                      //else SetPin(RELAY1_PORT, RELAY1_PIN, 0);
                                      nI1++;
                                      if(nI1>1000)    nI1=1;
                                      g_stUartBuffer.nCommand=0;
                                   break;
             
                              case DIMMER_LED:
                                  nDimmer= (UINT)g_stUartBuffer.pData;
                                  if (nDimmer>=100) 
                                  {nDimmer =100;
                                  SetDutyCycle(PWM_CHANNEL_1,nDimmer );
                                  }
                                  else SetDutyCycle(PWM_CHANNEL_1,nDimmer );
                                   break;
                              default:
                                break;
                            }  
                }
            }
            g_nPackageIndex = 0;
        }
        else
          if (((g_nPackageIndex == 0) && (g_pReceiveBuffer[g_nProcessIndex] == SERIAL_START_BYTE)) || (g_nPackageIndex > 0))
        {
            g_nPackageIndex++;
            if (g_nPackageIndex >= UART_BUFFER_SIZE)
                g_nPackageIndex = 0;      
        }
        g_nProcessIndex++;
        if (g_nProcessIndex >= UART_BUFFER_SIZE)
            g_nProcessIndex = 0;
        return TRUE;
    }
    return FALSE;
}

VOID NVIC_UART_Configuration(BYTE nPort)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    /* Configure the NVIC Preemption Priority Bits */  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    /* Enable the USARTy Interrupt */
    if (nPort == UART_PORT_1)
    {
        NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    }
    else if (nPort == UART_PORT_2)
    {
        NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    }
	else if (nPort == UART_PORT_3)
	{
		NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	}
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

INTERNAL VOID RCC_UART_Configuration(BYTE nPort)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA |\
		RCC_APB2Periph_AFIO, ENABLE);
    if (nPort == UART_PORT_1)
    {
        /* Enable USART Clock */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    }
    else if (nPort == UART_PORT_2)
    {
        /* Enable USART Clock */
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    }
	else if (nPort == UART_PORT_3)
    {
        /* Enable USART Clock */
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    }
}

INTERNAL VOID GPIO_UART_Configuration(BYTE nPort)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	if (nPort == UART_PORT_1)
	{
		// RX
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//TX
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
	else if (nPort == UART_PORT_2)
	{
		// RX
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		//TX
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
	else if (nPort == UART_PORT_3)
	{
		// RX
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		//TX
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
}

VOID USART2_IRQHandler()
{
    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
		g_pReceiveBuffer[g_nBufferIndex] = USART_ReceiveData(USART2);
        g_nBufferIndex++;
        if (g_nBufferIndex >= UART_BUFFER_SIZE)
		{
            g_nBufferIndex = 0;
		}
    }
}

//VOID USART1_IRQHandler()
//{
//    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
//    {
//		g_pReceiveBuffer[g_nBufferIndex] = USART_ReceiveData(USART1);
//        g_nBufferIndex++;
//        if (g_nBufferIndex >= UART_BUFFER_SIZE)
//		{
//            g_nBufferIndex = 0;
//		}
//    }
//}
