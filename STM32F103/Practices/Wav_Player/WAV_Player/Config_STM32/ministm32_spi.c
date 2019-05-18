
#include "stm32f1xx_hal.h"
#include "ministm32_spi.h"
#include "diskio.h"
#include "main.h"


// Variable
extern SPI_HandleTypeDef hspi1;
void SD_SPI_Config(void)
{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//	SPI_InitTypeDef  SPI_InitStructure;

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* Configure SPI pins: SCK and MOSI with default alternate function (not remapped) push-pull */
	GPIO_InitStruct.Pin   = GPIO_Pin_SD_SCK | GPIO_Pin_SD_MOSI;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
	HAL_GPIO_Init(GPIO_SD, &GPIO_InitStruct);
	/* Configure MISO as Input with internal pull-up */
	GPIO_InitStruct.Pin   = GPIO_Pin_SD_MISO;
	GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
	HAL_GPIO_Init(GPIO_SD, &GPIO_InitStruct);

	/* Configure SD_CS pin */	
	//Da duoc config tai mani.c
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_SD_CS;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_Init(GPIO_SD_CS, &GPIO_InitStructure);

	/* touch-controller's CS (PA4), SD-Card's CS (PB6) and DataFlash CS (PB7) high = unselect */
	// disable touch-controller (DataFlash not available)
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	GPIO_SetBits(GPIOA, GPIO_Pin_4);

	/* Enable GPIO clock for SD_CS */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
//	/* Enable SPI1 Periph clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);

	/* SPI1 configuration */
//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
//	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
//	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
//	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
//	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
//	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
//	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8; // 72000kHz/256=281kHz < 400kHz
//	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
//	SPI_InitStructure.SPI_CRCPolynomial = 7;
//
//	SPI_Init(SPI1, &SPI_InitStructure);
//	SPI_CalculateCRC(SPI1, DISABLE);
//	SPI_Cmd(SPI1, ENABLE);
	  /* SPI1 parameter configuration*/
	  hspi1.Instance = SPI1;
	  hspi1.Init.Mode = SPI_MODE_MASTER;
	  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	  hspi1.Init.NSS = SPI_NSS_SOFT;
	  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	  hspi1.Init.CRCPolynomial = 10;
	  if (HAL_SPI_Init(&hspi1) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

unsigned char SD_SPI_RW( BYTE c )
{
	  uint8_t dummy, data;
	  dummy = 0xFF;
	  data = 0;
	/* Send byte through the SPI1 peripheral */
	//while (HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_Transmit(&hspi1, &c, 1, SPI_TIMEOUT);
	/* Wait to receive a byte */
//	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) { ; }
//	/* Return the byte read from the SPI bus */
//	return SPI_I2S_ReceiveData(SPI1);
	  while ((HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY));
	  HAL_SPI_TransmitReceive(&hspi1, &dummy, &data, 1, SPI_TIMEOUT);
	  return data;
}

