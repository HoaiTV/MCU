#include "sd_utils.h"
#include "crc7.h"
#include "timing.h"

#define SD_COMMAND_SIZE         6
#define SD_COMMAND_TIMEOUT_MS   1000
#define SD_DATA_TIMEOUT_MS      1000

static uint8_t SD_SendCmd(uint8_t cmd, uint32_t arg, uint32_t *data_p, bool touch_ss)
{
    uint8_t cmd_buf[SD_COMMAND_SIZE];
    uint8_t u8;
    timeout_t to;
    uint8_t *const data_8p = (uint8_t *)data_p;

    /* Set command timeout */
    Timing_TimeoutInit(&to, SD_COMMAND_TIMEOUT_MS);

    /* Build command in RAM buffer */
    cmd_buf[0] = (cmd & 0x3F) | 0x40;
    cmd_buf[1] = arg >> 24;
    cmd_buf[2] = arg >> 16;
    cmd_buf[3] = arg >> 8;
    cmd_buf[4] = arg;
    u8 = crc7(cmd_buf, SD_COMMAND_SIZE - 1);
    u8 = ((u8 & 0x7F) << 1) | 0x01;
    cmd_buf[5] = u8;

    /* Select SD Cart (if required) */
    if(touch_ss) SPI_SELECT();

    /* Transmit CMD Buffer */
    SPI_IO_TRx(cmd_buf[0]);
    SPI_IO_TRx(cmd_buf[1]);
    SPI_IO_TRx(cmd_buf[2]);
    SPI_IO_TRx(cmd_buf[3]);
    SPI_IO_TRx(cmd_buf[4]);
    u8 = SPI_IO_TRx(cmd_buf[5]);

    /* Wait for command response header */
    while((u8 == 0xFF) && !Timing_TimeoutExpired(&to)) u8 = SPI_IO_TRx(0xFF);
    if(u8 == 0xFF) goto error;

    /* Store response argument */
    if(data_p)
    {
        data_8p[3] = SPI_IO_TRx(0xFF);
        data_8p[2] = SPI_IO_TRx(0xFF);
        data_8p[1] = SPI_IO_TRx(0xFF);
        data_8p[0] = SPI_IO_TRx(0xFF);
    }

    /* Send dummy 0xFF */
    SPI_IO_TRx(0xFF);

error:
    /* Select SD Cart (if required) */
    if(touch_ss) SPI_DESELECT();
    return u8;
}

/************************************************************************************
 * Get Sector Number
 ***********************************************************************************/
static bool SD_GetSectorNum(sd_info_t *sd_info)
{
    uint8_t u8;
    uint8_t csd[16];
    uint32_t c_size;

    SPI_SELECT();

    /* Send SEND_CSD command */
    u8 = SD_SendCmd(9, 0x00000000, NULL, false);
    if(SD_IS_ERROR(u8)) goto error;

    if(!SD_MultiReadNext(csd, sizeof(csd))) goto error;

    /* Send dummy 0xFF */
    SPI_IO_TRx(0xFF);

    SPI_DESELECT();

    if((csd[0] & 0xC0) == 0x00)         /* CSD v1.0 */
    {
        /* Not supported by now */
        goto error;
    }
    else if((csd[0] & 0xC0) == 0x40)    /* CSD v2.0 */
    {
        c_size = ((uint32_t)(csd[7] & 0x3F) << 16) | ((uint32_t)csd[8] << 8) | ((uint32_t)csd[9]);
        sd_info->sector_cnt = (c_size + 1) * 1024;
    }
    else goto error;

    return true;

error:
    SPI_DESELECT();
    return false;
}

/************************************************************************************
 * Initialize SD
 ***********************************************************************************/
bool SD_Init(sd_info_t *sd_info)
{
    uint8_t  rx_data;
    uint32_t resp_arg;
    timeout_t to;

    /* Set init timeout to 1 seconf */
    Timing_TimeoutInit(&to, 1000);

    /* Throttle SPI Clock to 72MHz/256 ~=280kHz */
    MODIFY_REG(SPI1->CR1, SPI_CR1_BR_Msk, (0b111 << SPI_CR1_BR_Pos));

    /* Generate 80 dummy clocks with SD Card Deselected */
    SPI_DESELECT();
    for(size_t i = 0; i < 10; i++) SPI_IO_TRx(0xFF);

    SPI_SELECT();

    /* Repeat GO_IDLE_STATE up to 64 times */
    rx_data = 0xFF;
    do {
        rx_data = SD_SendCmd(0, 0x00000000, NULL, true);
    } while((rx_data != 0x01) && !Timing_TimeoutExpired(&to));

    /* No response, card damaged */
    if(Timing_TimeoutExpired(&to)) goto error;

    /* Switch to Hi Speed SPI Clock */
    MODIFY_REG(SPI1->CR1, SPI_CR1_BR_Msk, (0b01 << SPI_CR1_BR_Pos));

    /* Send SEND_IF_COND */
    rx_data = SD_SendCmd(8, 0x000001AA, &resp_arg, true);
    sd_info->sd_version = (SD_IS_ERROR(rx_data)) ? 1 : 2;

    /* SD Cards v2 should respond with the same argument */
    if((sd_info->sd_version == 2) && (resp_arg != 0x000001AA)) goto error;

    /* Initialization procedure: Repead ACMD41 in a loop up to 1024 times */
    rx_data = 0xFF;
    do {
        rx_data = SD_SendCmd(55, 0x00000000, NULL, true);
        if(SD_IS_ERROR(rx_data)) goto error;
        rx_data = SD_SendCmd(41, (sd_info->sd_version == 2) ? 0x40000000 : 0x00000000, NULL, true);
        if(SD_IS_ERROR(rx_data)) goto error;
    } while((rx_data == 0x01) && !Timing_TimeoutExpired(&to));

    if(Timing_TimeoutExpired(&to)) goto error;

    /* Retrieve addressing mode */
    rx_data = SD_SendCmd(58, 0x00000000, &resp_arg, true);
    if(SD_IS_ERROR(rx_data)) goto error;

    sd_info->is_sdhc = (resp_arg & 0x40000000);

    /* Force block size to 512 byte in case of byte adddressing or SD v1 */
    if(!sd_info->is_sdhc || (sd_info->sd_version == 1))
    {
        rx_data = SD_SendCmd(58, 0x00000200, NULL, true);
        if(SD_IS_ERROR(rx_data)) goto error;
    }

    sd_info->sector_size = 512;

    return SD_GetSectorNum(sd_info);

error:
    return false;
}

/************************************************************************************
 * Read Commands
 ***********************************************************************************/
bool SD_MultiReadStart(uint32_t sector, uint8_t *buffer, size_t size)
{
    uint8_t   u8;

    SPI_SELECT();

    /* Send READ_MULTIPLE_BLOCK command */
    u8 = SD_SendCmd(18, sector, NULL, false);
    if(SD_IS_ERROR(u8)) goto error;

    /* Read first block */
    if(!SD_MultiReadNext(buffer, size)) goto error;

    return true;

error:
    return false;
}

bool SD_MultiReadNext(uint8_t *buffer, size_t size)
{
    uint8_t   u8;
    timeout_t to;

    /* Setup timeout */
    Timing_TimeoutInit(&to, SD_DATA_TIMEOUT_MS);

    /* Wait for Data Token */
    u8 = 0xFF;
    while((u8 == 0xFF) && !Timing_TimeoutExpired(&to)) u8 = SPI_IO_TRx(0xFF);
    if(u8 != 0xFE) goto error;

    /* Read data from SD using DMA */
    SPI_DMA_Rx(buffer, size);

    /* Read CRC */
    SPI_IO_TRx(0xFF);
    SPI_IO_TRx(0xFF);

    return true;

error:
    return false;
}

#include <stdio.h>

bool SD_MultiReadStop()
{
    uint8_t   u8;
    timeout_t to;

    /* Send READ_MULTIPLE_BLOCK command, ignore result because RX data is still shifted in */
    SD_SendCmd(12, 0x00000000, NULL, false);

    /* Setup timeout */
    Timing_TimeoutInit(&to, SD_DATA_TIMEOUT_MS);

    /* Read garbage data byte */
    SPI_IO_TRx(0xFF);

    /* Wait while SD is busy */
    u8 = 0x00;
    while((u8 == 0x00) && !Timing_TimeoutExpired(&to)) u8 = SPI_IO_TRx(0xFF);
    if(u8 == 0x00) goto error;

    /* Dummy 0xFF byte */
    SPI_IO_TRx(0xFF);

    SPI_DESELECT();
    return true;

error:
    SPI_DESELECT();
    return false;
}

bool SD_ReadSector(uint32_t sector, uint8_t *buffer, size_t size)
{
    uint8_t   u8;

    SPI_SELECT();

    /* Send READ_SECTOR command */
    u8 = SD_SendCmd(17, sector, NULL, false);
    if(SD_IS_ERROR(u8)) goto error;

    if(!SD_MultiReadNext(buffer, size)) goto error;

    /* Send dummy 0xFF */
    SPI_IO_TRx(0xFF);

    SPI_DESELECT();
    return true;

error:
    SPI_DESELECT();
    return false;
}

/************************************************************************************
 * Write Commands
 ***********************************************************************************/
bool SD_MultiWriteStart(uint32_t sector, uint8_t *buffer, size_t size)
{
    uint8_t   u8;

    SPI_SELECT();

    /* Send WRITE_MULTIPLE_BLOCK command */
    u8 = SD_SendCmd(25, sector, NULL, false);
    if(SD_IS_ERROR(u8)) goto error;

    /* Dummy byte */
    SPI_IO_TRx(0xFF);

    /* Write first block */
    if(!SD_MultiWriteNext(buffer, size)) goto error;

    return true;

error:
    return false;
}

bool SD_MultiWriteNext(uint8_t *buffer, size_t size)
{
    uint8_t   u8;
    timeout_t to;

    /* Dummy FF */
    SPI_IO_TRx(0xFF);

    /* CMD25 Data Token */
    SPI_IO_TRx(0xFC);

    /* Write data to SD using DMA */
    SPI_DMA_Tx(buffer, size);

    /* Write CRC */
    SPI_IO_TRx(0xA5);
    SPI_IO_TRx(0x5A);

    /* Setup timeout */
    Timing_TimeoutInit(&to, SD_DATA_TIMEOUT_MS);

    /* Read Data Response */
    u8 = SPI_IO_TRx(0xFF);
    if((u8 & 0x1F) != 0x05) goto error;

    /* Wait while SD is Busy */
    u8 = 0x00;
    while((u8 == 0x00) && !Timing_TimeoutExpired(&to)) u8 = SPI_IO_TRx(0xFF);
    if(u8 == 0x00) goto error;

    /* Dummy FF */
    SPI_IO_TRx(0xFF);

    return true;

error:
    return false;
}

bool SD_MultiWriteStop()
{
    uint8_t   u8;
    timeout_t to;

    /* CMD25 STOP Data Token */
    SPI_IO_TRx(0xFD);

    /* Dummy FF */
    SPI_IO_TRx(0xFF);

    /* Setup timeout */
    Timing_TimeoutInit(&to, SD_DATA_TIMEOUT_MS);

    /* Wait while SD is Busy */
    u8 = 0x00;
    while((u8 == 0x00) && !Timing_TimeoutExpired(&to)) u8 = SPI_IO_TRx(0xFF);
    if(u8 == 0x00) goto error;

    /* Dummy FF */
    SPI_IO_TRx(0xFF);

    SPI_DESELECT();
    return true;

error:
    SPI_DESELECT();
    return false;
}
