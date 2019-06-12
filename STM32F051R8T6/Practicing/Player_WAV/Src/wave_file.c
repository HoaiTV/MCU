
/***************************************************
Mini-STM32 PWM Audio
yus	- http://projectproto.blogspot.com/
June 2010
WAVE PCM soundfile format
https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
Simple SD Audio Player with an 8-pin IC
http://elm-chan.org/works/sd8p/report.html
****************************************************/

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include "wave_file.h"
#include "ff.h"
#include "pwm_audio.h"

//
#define FCC(c1,c2,c3,c4)	(((DWORD)c4<<24)+((DWORD)c3<<16)+((WORD)c2<<8)+(BYTE)c1)	/* FourCC */
#define fmt_chunk	FCC('f','m','t',' ')
#define data_chunk	FCC('d','a','t','a')
#define LIST_chunk	FCC('L','I','S','T')
#define fact_chunk	FCC('f','a','c','t')
//
BYTE Buff[READ_BUFF_SIZE];
WORD NumChannels, BitsPerSample;
UINT rb;			/* Return value */
extern FATFS Fs;			/* File system object */

/*---------------------------------------------------------*/

static
DWORD load_header(FIL fil)	/* 0:Invalid format, 1:I/O error, >1:Number of samples */
{
		DWORD ChunkID, SamplingRate, sz, Length;
		char str[20];
		if (f_read(&fil,Buff, 12, &rb))
				return 1;	/* Load file header (12 bytes) */
		if (rb != 12 || LD_DWORD(Buff+8) != FCC('W','A','V','E')) 
				return 0;
		while(1) 
	  {
				f_read(&fil,Buff, 8, &rb);			/* Get Chunk ID and size */
				if (rb != 8) 
						return 0;
				ChunkID = LD_DWORD(&Buff[0]);
				sz = LD_DWORD(&Buff[4]);		/* Chunk size */	
				switch (ChunkID) 
				{	  /* FCC */
						case fmt_chunk:					/* 'fmt ' chunk */
								if (sz > 100 || sz < 16) 
										return 0;		/* Check chunk size */
								f_read(&fil,Buff, sz, &rb);					/* Get content */
								if (rb != sz) 
										return 0;
								if (Buff[0] != 1) 
										return 0;				/* Check coding type (PCM=1) */
								NumChannels = Buff[2];					/* Get channel flag */
								if (NumChannels != 1 && NumChannels != 2) 		/* Check channels (1/2) */
										return 0;
								if (NumChannels == 1) 	
										//LCD_Text(50, 85, "Mono", LCD_Yellow, LCD_Red);
									printf("Mono\n");
								else 
										if (NumChannels == 2) 	
												//LCD_Text(50, 85, "Stereo", LCD_Yellow, LCD_Red);
											printf("Stereo\n");
								BitsPerSample = Buff[14];		/* Resolution flag */
								if (BitsPerSample != 8 && BitsPerSample != 16)	/* Check resolution (8/16) */
										return 0;
								if (BitsPerSample == 8) 	
										//LCD_Text(110, 85, "8-bits", LCD_Yellow, LCD_Red);
									printf("8-Bits\n");
								else 
										if (BitsPerSample == 16) 	
												//LCD_Text(110, 85, "16-bits", LCD_Yellow, LCD_Red);	
											printf("16-Bits\n");
								SamplingRate = LD_DWORD(Buff + 4);
								set_sampling_rate(SamplingRate);			/* Sampling freq */
								sprintf(str, "%ldHz", SamplingRate);
								//LCD_Text(170, 85, str, LCD_Yellow, LCD_Red);
							//	USART_SendString(USART1, str);
								break;
						case data_chunk:				/* 'data' chunk (start to play) */
								Length = sz / (SamplingRate * NumChannels * (BitsPerSample >> 3));	// length in seconds
								sprintf(str, " %ld : %2ld min", (Length / 60), (Length % 60));
								//LCD_Text(100, 100, str, LCD_Yellow, LCD_Red);
								printf("%s", str);
								return sz;
						case LIST_chunk:				/* 'LIST' chunk (skip) */
						case fact_chunk:				/* 'fact' chunk (skip) */
								f_lseek(&fil, sz);
								break;
						default :								/* Unknown chunk (error) */
								return 0;
				}
		}
	//return 0;
}

UINT play_wave_file(const char *fn)
{
		DWORD sz, i;
		WORD amplitude;
		FIL fil;
		//FRESULT res;
		//if ((res = pf_open(fn)) == FR_OK) {
		if(f_open(&fil, fn, FA_OPEN_ALWAYS | FA_READ | FA_WRITE)== FR_OK)
		{
				//LCD_Text(70, 70, fn, LCD_Yellow, LCD_Red);
				sz = load_header(fil);			/* Load file header */
				if (sz < 256) 
						return (UINT)sz;
				enable_audio();
				if ((NumChannels == 2) && (BitsPerSample == 16))
				{
						do
						{
								f_read(&fil,Buff, READ_BUFF_SIZE, &rb);
								//for(i=0; i<(READ_BUFF_SIZE>>2); i++)	wav_putc(Buff[(i<<2)+1]);
								for (i = 0; i < (READ_BUFF_SIZE >> 2); i++)
							  {
										amplitude = Buff[(i << 2) + 1];
										// two's compliment ??
										if (amplitude&0x80)	
												amplitude = 0;//=128 - (amplitude&0x7F)>>1;
										//else	amplitude = 127 + (amplitude>>1);
										wav_putc(amplitude);
								}
						} 
						while(rb == READ_BUFF_SIZE);
				}
				else 
						if ((NumChannels == 1) && (BitsPerSample == 16))
						{
								do
								{
									f_read(&fil,Buff, READ_BUFF_SIZE, &rb);
										//for(i=0; i<(READ_BUFF_SIZE>>1); i++)	wav_putc(Buff[(i<<1)+1]);
										for (i = 0; i < (READ_BUFF_SIZE >> 1); i++)
									  {
												amplitude = Buff[(i << 1) + 1];
												// two's compliment ??
												if (amplitude & 0x80)	
												    amplitude = 0;//=128 - (amplitude&0x7F)>>1;
												//else	amplitude = 127 + (amplitude>>1);
												wav_putc(amplitude);
										}
								} 
								while (rb == READ_BUFF_SIZE);
		        }  
						else 
								if ((NumChannels == 2) && (BitsPerSample == 8))
								{
										do
										{
											f_read(&fil,Buff, READ_BUFF_SIZE, &rb);
												for (i = 0; i < (READ_BUFF_SIZE >> 1); i++)
                        {											
														wav_putc(Buff[i << 1]);
													  wav_putc_3(Buff[(i << 1) + 1]);
												}
										} 
										while (rb == READ_BUFF_SIZE);
								}
								else 
										if ((NumChannels == 1) && (BitsPerSample == 8) )
										{
												do
												{
													f_read(&fil,Buff, READ_BUFF_SIZE, &rb);
														for (i = 0; i < 256; i++)
                            {													
																wav_putc(Buff[i]);
															  wav_putc_3(Buff[i]);
														}
												} while(rb==READ_BUFF_SIZE);
										}
				disable_audio();
		}
		return 0;
}
