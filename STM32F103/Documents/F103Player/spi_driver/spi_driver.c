#include "spi_driver.h"

void SPI_Init()
{
    /* Turn on SPI and GPIOA clock */
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN);

    /* Configure SPI Pins */
    MODIFY_REG(GPIOA->CRL,
               (GPIO_CRL_CNF7_Msk | GPIO_CRL_MODE7_Msk) |   /* GPIOA_7: MOSI */
               (GPIO_CRL_CNF6_Msk | GPIO_CRL_MODE6_Msk) |   /* GPIOA_6: MISO */
               (GPIO_CRL_CNF5_Msk | GPIO_CRL_MODE5_Msk) |   /* GPIOA_5: SCLK */
               (GPIO_CRL_CNF4_Msk | GPIO_CRL_MODE4_Msk) ,   /* GPIOA_4: NSS  */
               (0b1011 << GPIO_CRL_MODE7_Pos) |             /* GPIOA_7: MOSI - Alternate function, high speed output    */
               (0b1000 << GPIO_CRL_MODE6_Pos) |             /* GPIOA_6: MISO - Input mode, PullUp/PillDown              */
               (0b1011 << GPIO_CRL_MODE5_Pos) |             /* GPIOA_5: SCLK - Alternate function, high speed output    */
               (0b0011 << GPIO_CRL_MODE4_Pos) );            /* GPIOA_4: NSS  - Generap Purpose High Speed Output        */

    /* GPIOA_6: MISO - Enable PullUp */
    SET_BIT(GPIOA->ODR, GPIO_ODR_ODR6_Msk);

    /* Set Clock Prescaller to 4, Enable Master Mode, Enable SW SS Management, Set SW SS to High */
    SET_BIT(SPI1->CR1, (0x01 << SPI_CR1_BR_Pos) | SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI);

    /* Enable the SPI1 */
    SET_BIT(SPI1->CR1, SPI_CR1_SPE);

    /* Turn on DMA1 clock */
    SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);

    /* DMA: Configure Periph Addresses */
    WRITE_REG(DMA1_Channel3->CPAR, (uint32_t)&SPI1->DR);
    WRITE_REG(DMA1_Channel2->CPAR, (uint32_t)&SPI1->DR);

    /* Enable SPI TX and RX DMA */
    SET_BIT(SPI1->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
}

void SPI_DMA_Operation(void *tx_buffer, bool tx_inc, void *rx_buffer, bool rx_inc, size_t buf_size)
{
    /* Enable Memory Increment, Direction Mem->Per */
    WRITE_REG(DMA1_Channel3->CCR, (tx_inc ? DMA_CCR_MINC : 0) | DMA_CCR_DIR);
    WRITE_REG(DMA1_Channel2->CCR, (rx_inc ? DMA_CCR_MINC : 0));

    /* Configure transaction size */
    WRITE_REG(DMA1_Channel3->CNDTR, buf_size);
    WRITE_REG(DMA1_Channel2->CNDTR, buf_size);

    /* Configure Mem address */
    WRITE_REG(DMA1_Channel3->CMAR, (uint32_t)tx_buffer);
    WRITE_REG(DMA1_Channel2->CMAR, (uint32_t)rx_buffer);

    /* Enable DMA Channel */
    __disable_irq();
    SET_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
    SET_BIT(DMA1_Channel2->CCR, DMA_CCR_EN);
    __enable_irq();

    /* Wait for RX DMA Complete flag */
    while(READ_BIT(DMA1->ISR, DMA_ISR_TCIF2) == 0);
    while(READ_BIT(DMA1->ISR, DMA_ISR_TCIF3) == 0);

    /* Clear RX DMA Complete flag */
    SET_BIT(DMA1->IFCR, DMA_IFCR_CTCIF2);
    SET_BIT(DMA1->IFCR, DMA_IFCR_CTCIF3);

    /* Disable DMA Chanels */
    CLEAR_BIT(DMA1_Channel3->CCR, DMA_CCR_EN);
    CLEAR_BIT(DMA1_Channel2->CCR, DMA_CCR_EN);
}

void SPI_DMA_Tx(void *tx_buf_p, size_t buf_size)
{
    uint8_t dummy;
    SPI_DMA_Operation(tx_buf_p, true, &dummy, false, buf_size);
}

void SPI_DMA_Rx(void *rx_buf_p, size_t buf_size)
{
    uint8_t tx_data = 0xFF;
    SPI_DMA_Operation(&tx_data, false, rx_buf_p, true, buf_size);
}


