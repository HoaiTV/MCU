#ifndef __MINISTM32_SPI_H__
#define	__MINISTM32_SPI_H__

/* SD Card Support */
#define GPIO_Pin_SD_SCK		GPIO_PIN_5
#define GPIO_Pin_SD_MISO	GPIO_PIN_6
#define GPIO_Pin_SD_MOSI	GPIO_PIN_7
#define GPIO_Pin_SD_CS		GPIO_PIN_6
#define GPIO_SD				GPIOA
#define GPIO_SD_CS			GPIOB
#define SD_Select()			HAL_GPIO_WritePin(GPIO_SD_CS, GPIO_Pin_SD_CS, GPIO_PIN_RESET);    /* MMC CS = L */
#define SD_Deselect()		HAL_GPIO_WritePin(GPIO_SD_CS, GPIO_Pin_SD_CS, GPIO_PIN_SET);      /* MMC CS = H */

#define SPI_TIMEOUT 1000
void SD_SPI_Config(void);
unsigned char SD_SPI_RW( unsigned char c );

#endif	// __MINISTM32_SPI_H__
