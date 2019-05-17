
/***************************************************

RIFF WAVE file format

Mini-STM32 SD/MMC WAV Audio Player
yus	- http://projectproto.blogspot.com/
June 2010

WAVE PCM soundfile format
https://ccrma.stanford.edu/courses/422/projects/WaveFormat/

Simple SD Audio Player with an 8-pin IC
http://elm-chan.org/works/sd8p/report.html

****************************************************/

#include "stm32f10x.h"
#include <stdio.h>

#include "wave_file.h"
#include "pwm_audio.h"

#define FCC(c1,c2,c3,c4)	(((DWORD)c4<<24)+((DWORD)c3<<16)+((WORD)c2<<8)+(BYTE)c1)	/* FourCC */
#define fmt_chunk	FCC('f','m','t',' ')
#define data_chunk	FCC('d','a','t','a')
#define LIST_chunk	FCC('L','I','S','T')
#define fact_chunk	FCC('f','a','c','t')

FATFS Fs;			/* File system object */
DIR Dir;			/* Directory object */
FILINFO Fno;		/* File information */

BYTE Buff[READ_BUFF_SIZE];
WORD NumChannels, BitsPerSample;
WORD rb;			/* Return value */

/*---------------------------------------------------------*/ 

DWORD Get_WAV_Header(xWAVFile * file)		/* 0:Invalid format, 1:I/O error, >1:Number of samples */
{
	DWORD ChunkID, SamplingRate, sz;
	
	if (pf_read(Buff, 12, &rb)) return 1;	/* Load file header (12 bytes) */
	if (rb != 12 || LD_DWORD(Buff+8) != FCC('W','A','V','E')) return 0;

	while(1) {
		pf_read(Buff, 8, &rb);			/* Get Chunk ID and size */
		if (rb != 8) return 0;
		ChunkID = LD_DWORD(&Buff[0]);
		sz = LD_DWORD(&Buff[4]);		/* Chunk size */	

		switch (ChunkID) {	/* FCC */
			case fmt_chunk:					/* 'fmt ' chunk */
				if (sz > 100 || sz < 16) return 0;		/* Check chunk size */
				pf_read(Buff, sz, &rb);					/* Get content */
				if (rb != sz) return 0;
				if (Buff[0] != 1) return 0;				/* Check coding type (PCM=1) */

				NumChannels = Buff[2];					/* Get channel flag */
				if (NumChannels != 1 && NumChannels != 2) 		/* Check channels (1/2) */
					return 0;
				file->xNumChannels = NumChannels;				

				BitsPerSample = Buff[14];		/* Resolution flag */
				if (BitsPerSample != 8 && BitsPerSample != 16)	/* Check resolution (8/16) */
					return 0;
				file->xBitsPerSample = BitsPerSample;

				SamplingRate = LD_DWORD(Buff+4);			/* Sampling freq */
				file->xSamplingRate = SamplingRate;

				break;
	
			case data_chunk:				/* 'data' chunk (start to play) */
				file->xSize = sz;
				return sz;
	
			case LIST_chunk:				/* 'LIST' chunk (skip) */

			case fact_chunk:				/* 'fact' chunk (skip) */
				pf_lseek(Fs.fptr + sz);
				break;
	
			default :								/* Unknown chunk (error) */
				return 0;
		}
	}

}

