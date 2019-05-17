#ifndef __MINISTM32_SPI_H__
#define	__MINISTM32_SPI_H__

/* SD Card Support */
#define GPIO_Pin_SD_SCK		GPIO_Pin_5
#define GPIO_Pin_SD_MISO	GPIO_Pin_6
#define GPIO_Pin_SD_MOSI	GPIO_Pin_7
#define GPIO_Pin_SD_CS		GPIO_Pin_6
#define GPIO_SD				  GPIOA
#define GPIO_SD_CS			GPIOB
#define SD_Select()			GPIO_ResetBits(GPIO_SD_CS, GPIO_Pin_SD_CS)    /* MMC CS = L */
#define SD_Deselect()		GPIO_SetBits(GPIO_SD_CS, GPIO_Pin_SD_CS)      /* MMC CS = H */

void SD_SPI_Config(void);
unsigned char SD_SPI_RW( unsigned char c );

#endif	// __MINISTM32_SPI_H__
