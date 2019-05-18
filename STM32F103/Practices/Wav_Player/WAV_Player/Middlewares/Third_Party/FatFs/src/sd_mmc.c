/*-----------------------------------------------------------------------*/
/* PFF - Low level disk control module			        (C)ChaN, 2009    */
/*-----------------------------------------------------------------------*/

#include "stm32f1xx_hal.h"
#include "ministm32_spi.h"
#include "diskio.h"

#define	init_spi()	SD_SPI_Config()
#define	xmit_spi(c)	SD_SPI_RW(c)
#define	rcv_spi()	SD_SPI_RW(0xFF)
#define	SELECT()	SD_Select()
#define	DESELECT()	SD_Deselect()

#define _WRITE_FUNC	0

/* Definitions for MMC/SDC command */
#define CMD0	(0x40+0)	/* GO_IDLE_STATE */
#define CMD1	(0x40+1)	/* SEND_OP_COND (MMC) */
#define	ACMD41	(0xC0+41)	/* SEND_OP_COND (SDC) */
#define CMD8	(0x40+8)	/* SEND_IF_COND */
#define CMD12	(0x40+12)	/* STOP_TRANSMISSION */
#define CMD16	(0x40+16)	/* SET_BLOCKLEN */
#define CMD17	(0x40+17)	/* READ_SINGLE_BLOCK */
#define CMD24	(0x40+24)	/* WRITE_BLOCK */
#define CMD55	(0x40+55)	/* APP_CMD */
#define CMD58	(0x40+58)	/* READ_OCR */

/*--------------------------------------------------------------------------

   Module Private Functions

---------------------------------------------------------------------------*/

BYTE CardType;


/*-----------------------------------------------------------------------*/
/* Deselect the card and release SPI bus                                 */
/*-----------------------------------------------------------------------*/

static
void release_spi (void)
{
	DESELECT();
	rcv_spi();
}

/*-----------------------------------------------------------------------*/
/* Wait for card ready                                                   */
/*-----------------------------------------------------------------------*/

static
BYTE wait_ready (void)
{
	BYTE res;
	DWORD timeout = 0x7FFF;
	
	do
		res = rcv_spi();
	while ((res != 0xFF) && (--timeout));
	
	return res;
}

/*-----------------------------------------------------------------------*/
/* Send a command packet to MMC                                          */
/*-----------------------------------------------------------------------*/

static
BYTE send_cmd (
	BYTE cmd,		/* Command byte */
	DWORD arg		/* Argument */
)
{
	BYTE n, res;

	/* Select the card and wait for ready */
	DESELECT();
	SELECT();

	if (wait_ready() != 0xFF) {
		return 0xFF;
	}
	
	if (cmd & 0x80) {	/* ACMD<n> is the command sequence of CMD55-CMD<n> */
		cmd &= 0x7F;
#if 0		// PICC18 Compiler error! (recursive function)
		res = send_cmd(CMD55, 0);
#else			
		/* Send command packet */
		xmit_spi(cmd);						/* Start + Command index */
		xmit_spi((BYTE)(arg >> 24));		/* Argument[31..24] */
		xmit_spi((BYTE)(arg >> 16));		/* Argument[23..16] */
		xmit_spi((BYTE)(arg >> 8));			/* Argument[15..8] */
		xmit_spi((BYTE)arg);				/* Argument[7..0] */
		n = 0x01;							/* Dummy CRC + Stop */
		if (cmd == CMD0) n = 0x95;			/* Valid CRC for CMD0(0) */
		if (cmd == CMD8) n = 0x87;			/* Valid CRC for CMD8(0x1AA) */
		xmit_spi(n);
	
		/* Receive command response */
		if (cmd == CMD12) rcv_spi();		/* Skip a stuff byte when stop reading */
	
		n = 10;								/* Wait for a valid response in timeout of 10 attempts */
		do
			res = rcv_spi();
		while ((res & 0x80) && --n);
#endif
		if (res > 1) return res;
	}
		

	/* Send command packet */
	xmit_spi(cmd);						/* Start + Command index */
	xmit_spi((BYTE)(arg >> 24));		/* Argument[31..24] */
	xmit_spi((BYTE)(arg >> 16));		/* Argument[23..16] */
	xmit_spi((BYTE)(arg >> 8));			/* Argument[15..8] */
	xmit_spi((BYTE)arg);				/* Argument[7..0] */
	n = 0x01;							/* Dummy CRC + Stop */
	if (cmd == CMD0) n = 0x95;			/* Valid CRC for CMD0(0) */
	if (cmd == CMD8) n = 0x87;			/* Valid CRC for CMD8(0x1AA) */
	xmit_spi(n);

	/* Receive command response */
	if (cmd == CMD12) rcv_spi();		/* Skip a stuff byte when stop reading */

	n = 10;								/* Wait for a valid response in timeout of 10 attempts */
	do
		res = rcv_spi();
	while ((res & 0x80) && --n);

	return res;			/* Return with the response value */
}



/*--------------------------------------------------------------------------

   Public Functions

---------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
/* Write partial sector                                                  */
/*-----------------------------------------------------------------------*/
#if _WRITE_FUNC

DRESULT disk_writep (
	const BYTE *buff,	/* Pointer to the bytes to be written (NULL:Initiate/Finalize sector write) */
	DWORD sa			/* Number of bytes to send, Sector number (LBA) or zero */
)
{
	DRESULT res;
	WORD bc;
	static WORD wc;


	res = RES_ERROR;

	if (buff) {		/* Send data bytes */
		bc = (WORD)sa;
		while (bc && wc) {		/* Send data bytes to the card */
			xmit_spi(*buff++);
			wc--; bc--;
		}
		res = RES_OK;
	} else {
		if (sa) {	/* Initiate sector write process */
			if (!(CardType & CT_BLOCK)) sa *= 512;	/* Convert to byte address if needed */
			if (send_cmd(CMD24, sa) == 0) {			/* WRITE_SINGLE_BLOCK */
				xmit_spi(0xFF); xmit_spi(0xFE);		/* Data block header */
				wc = 512;							/* Set byte counter */
				res = RES_OK;
			}
		} else {	/* Finalize sector write process */
			bc = wc + 2;
			while (bc--) xmit_spi(0);	/* Fill left bytes and CRC with zeros */
			if ((rcv_spi() & 0x1F) == 0x05) {	/* Receive data resp and wait for end of write process in timeout of 300ms */
				for (bc = 65000; rcv_spi() != 0xFF && bc; bc--) ;	/* Wait ready */
				if (bc) res = RES_OK;
			}
			release_spi();
		}
	}

	return res;
}
#endif



