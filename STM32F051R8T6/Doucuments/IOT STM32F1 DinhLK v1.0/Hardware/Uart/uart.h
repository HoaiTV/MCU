#ifndef __UART_H__
#define __UART_H__

#define SHORT_BUFFER            0
#define LONG_BUFFER             1

typedef SYSTEMCALLBACK UARTCALLBACK;

#pragma pack(1)
typedef struct tagUARTBUFFER
{
    BYTE nTypeBuffer;
    WORD nLength;
    BYTE nAddr;
    BYTE nCommand;
    PVOID pData;
} UARTBUFFER, *PUARTBUFFER;

typedef struct tagUARTBUFFER_
{
    BYTE nCommand_;
    BYTE nData_;
} UARTBUFFER_;

typedef struct tagUARTCONFIG
{
	BYTE nPort;
	BYTE nBaudrate;
} UARTCONFIG, *PUARTCONFIG;

// Port Definition
#define UART_PORT_1             0
#define UART_PORT_2             1
#define UART_PORT_3             2

#define MAX_UART_PORT           3

// Baudrate Definition
#define UART_BAUD_RATE_9600     9600
#define UART_BAUD_RATE_38400    38400
#define UART_BAUD_RATE_57600    57600
#define UART_BAUD_RATE_115200   115200

// Uart events
#define	UART_DATA_EVENT			0
#define MAX_UART_EVENT          1

EXTERNAL BYTE g_nUartPort;

VOID OpenUartPort(BYTE nPort, DWORD nBaudrate);
VOID WriteUart(BYTE nPort, PVOID pData, BYTE nLength);
VOID WriteUartIndirect(BYTE nPort, PVOID pData);
VOID WriteUartTransmit(BYTE nPort, BYTE Command, BYTE Data);
VOID RegisterUartCallback(BYTE nEvent, SYSTEMCALLBACK fnCallback);
RESULT ProcessUartEvents();

#endif //__UART_H__