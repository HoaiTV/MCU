#ifndef SD_UTILS_H
#define SD_UTILS_H

#include <stm32f1xx.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "spi_driver.h"

#define SD_IS_ERROR(r) ((r) & 0x7E)

typedef struct
{
    bool     is_sdhc;
    uint8_t  sd_version;
    uint32_t sector_cnt;
    uint32_t sector_size;
} sd_info_t;

bool SD_Init(sd_info_t *sd_info);

bool SD_MultiReadStart(uint32_t sector, uint8_t *buffer, size_t size);
bool SD_MultiReadNext(uint8_t *buffer, size_t size);
bool SD_MultiReadStop();
bool SD_ReadSector(uint32_t sector, uint8_t *buffer, size_t size);

bool SD_MultiWriteStart(uint32_t sector, uint8_t *buffer, size_t size);
bool SD_MultiWriteNext(uint8_t *buffer, size_t size);
bool SD_MultiWriteStop();

#endif // SD_UTILS_H
