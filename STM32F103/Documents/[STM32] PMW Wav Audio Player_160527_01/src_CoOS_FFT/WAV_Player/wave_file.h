#ifndef _WAVE_FILE
#define _WAVE_FILE

#include "integer.h"
#include "pff.h"

#define READ_BUFF_SIZE	512//1024

typedef struct
{
	char *pcFileName;
	DWORD xSamplingRate;
	DWORD xNumChannels;
	DWORD xBitsPerSample;
	DWORD xSize;
} xWAVFile;

DWORD Get_WAV_Header(xWAVFile * file);

extern FATFS Fs;			/* File system object */
extern DIR Dir;			/* Directory object */
extern FILINFO Fno;		/* File information */

extern BYTE Buff[READ_BUFF_SIZE];
extern WORD NumChannels, BitsPerSample;
extern WORD rb;			/* Return value */

#endif	// _WAVE_FILE
