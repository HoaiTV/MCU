/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "sd_utils.h"
#include <stdio.h>

#define OP_NONE    0
#define OP_READ    1
#define OP_WRITE   2

static struct
{
    sd_info_t sd_info;
    bool is_initialized;
    uint8_t  active_op;
    uint32_t next_sector;
} g_sd_status;


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
    (void)pdrv;
    return g_sd_status.is_initialized ? 0 : STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
    (void)pdrv;

    DSTATUS stat = STA_NOINIT;

    for(size_t i = 0; i < 16; i++)
    {
        if(SD_Init(&g_sd_status.sd_info))
        {
            g_sd_status.is_initialized = true;
            stat = 0;
            break;
        }
    }

    return stat;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
    (void)pdrv;
    if(!g_sd_status.is_initialized) return RES_NOTRDY;

    size_t sec_size = g_sd_status.sd_info.sector_size;

    DRESULT res = RES_ERROR;

    if(g_sd_status.active_op == OP_WRITE)
    {
        if(!SD_MultiWriteStop()) goto error;
        g_sd_status.active_op = OP_NONE;
    }

    if(g_sd_status.active_op == OP_READ)
    {
        if(g_sd_status.next_sector == sector)
        {
            g_sd_status.next_sector = sector + count;
            while(count--)
            {
                if(!SD_MultiReadNext(buff, sec_size)) goto error;
                buff += sec_size;
            }

            res = RES_OK;
        }
        else
        {
            if(!SD_MultiReadStop()) goto error;
            g_sd_status.active_op = OP_NONE;
        }
    }

    if(g_sd_status.active_op == OP_NONE)
    {
        if(!SD_MultiReadStart(sector, buff, sec_size)) goto error;
        g_sd_status.active_op = OP_READ;
        g_sd_status.next_sector = sector + count;

        count--;
        buff += sec_size;

        while(count--)
        {
            if(!SD_MultiReadNext(buff, sec_size)) goto error;
            buff += sec_size;
        }

        res = RES_OK;
    }

error:
    return res;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
    (void)pdrv;
    if(!g_sd_status.is_initialized) return RES_NOTRDY;

    size_t sec_size = g_sd_status.sd_info.sector_size;

    DRESULT res = RES_ERROR;

    if(g_sd_status.active_op == OP_READ)
    {
        if(!SD_MultiReadStop()) goto error;
        g_sd_status.active_op = OP_NONE;
    }

    if(g_sd_status.active_op == OP_WRITE)
    {
        if(g_sd_status.next_sector == sector)
        {
            g_sd_status.next_sector = sector + count;
            while(count--)
            {
                if(!SD_MultiWriteNext((uint8_t *)buff, sec_size)) goto error;
                buff += sec_size;
            }

            res = RES_OK;
        }
        else
        {
            if(!SD_MultiWriteStop()) goto error;
            g_sd_status.active_op = OP_NONE;
        }
    }

    if(g_sd_status.active_op == OP_NONE)
    {
        if(!SD_MultiWriteStart(sector, (uint8_t *)buff, sec_size)) goto error;
        g_sd_status.active_op = OP_WRITE;
        g_sd_status.next_sector = sector + count;

        count--;
        buff += sec_size;

        while(count--)
        {
            if(!SD_MultiWriteNext((uint8_t *)buff, sec_size)) goto error;
            buff += sec_size;
        }

        res = RES_OK;
    }

error:
    return res;
}



/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
    (void)pdrv;
    if(!g_sd_status.is_initialized) return RES_NOTRDY;

    DRESULT res = RES_ERROR;

    switch(cmd)
    {
    case CTRL_SYNC:
        if(g_sd_status.active_op == OP_READ)
        {
            if(!SD_MultiReadStop()) goto error;
            g_sd_status.active_op = OP_NONE;
        }
        else if(g_sd_status.active_op == OP_WRITE)
        {
            if(!SD_MultiWriteStop()) goto error;
            g_sd_status.active_op = OP_NONE;
        }

        res = RES_OK;
        break;

    case GET_SECTOR_COUNT:
        *(DWORD *)buff = g_sd_status.sd_info.sector_cnt;
        res = RES_OK;
        break;

    case GET_SECTOR_SIZE:
        *(WORD *)buff = g_sd_status.sd_info.sector_size;
        res = RES_OK;
        break;

    case GET_BLOCK_SIZE:
        *(DWORD *)buff = g_sd_status.sd_info.sector_size;
        res = RES_OK;
        break;

    case CTRL_TRIM:
        res = RES_OK;
        break;
    }

error:
    return res;
}

