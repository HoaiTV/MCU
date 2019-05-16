#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include <stm32f1xx.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#define SPI_SELECT()    do { while(READ_BIT(GPIOA->IDR, GPIO_IDR_IDR5)); WRITE_REG(GPIOA->BSRR, GPIO_BSRR_BR4); } while(0)
#define SPI_DESELECT()  do { while(READ_BIT(GPIOA->IDR, GPIO_IDR_IDR5)); WRITE_REG(GPIOA->BSRR, GPIO_BSRR_BS4); } while(0)

void SPI_Init();
void SPI_DMA_Operation(void *tx_buffer, bool tx_inc, void *rx_buffer, bool rx_inc, size_t buf_size);
void SPI_DMA_Tx(void *tx_buf_p, size_t buf_size);
void SPI_DMA_Rx(void *rx_buf_p, size_t buf_size);
void SPI_DMA_TRx(void *tx_buf_p, void *rx_buf_p, size_t buf_size);

#pragma GCC optimize("Os")
static inline __attribute__((always_inline))
uint8_t SPI_IO_TRx(uint8_t tx_byte)
{
//    while(READ_BIT(SPI1->SR, SPI_SR_TXE) == 0);
    *(__IO uint8_t *)&SPI1->DR = tx_byte;

    while(READ_BIT(SPI1->SR, SPI_SR_RXNE) == 0);
    return *(__IO uint8_t *)&SPI1->DR;
}

#endif // SPI_DRIVER_H
