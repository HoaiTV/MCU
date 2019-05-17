
/****************************************************

Mini-STM32 SD/MMC WAV Audio Player
yus	- http://projectproto.blogspot.com/
June 2010

*****************************************************/

/*---------------------------------- Inlcude ---------------------------------*/

#include "stm32f10x.h"
#include "CoOS.h"			 			/*!< CooCox RTOS header file.		  */
#include <string.h>
#include <stdio.h>


#include "ministm32_lcd.h"
#include "ministm32_led.h"
#include "ministm32_pb.h"
#include "pff.h"
#include "wave_file.h"
#include "pwm_audio.h"

#include "fft.h"

/*---------------------------------- Define  ---------------------------------*/
#define TASK_STK_SIZE			128	 		/*!< Define stack size.				  */

#define PLAY_WAV_PRIORITY 			3
#define SPECTRUM_DISPLAY_PRIORITY	2
#define LED_BLINK_PRIORITY			3

/*---------------------------------- Variable Define -------------------------*/  
OS_STK   play_wav_Stk[TASK_STK_SIZE];
OS_STK   spectrum_display_Stk[TASK_STK_SIZE];
OS_STK   led_blink_Stk[TASK_STK_SIZE];

OS_FlagID	spectrum_ready_flg, spectrum_start_flg;
volatile char spectrum_ready_flag, spectrum_start_flag;
volatile char next_file_flag, restart_flag;

void play_wav(void *pdata);
void spectrum_display(void *pdata);
void led_blink(void *pdata);

void show_wav_info(xWAVFile * file);


#define FFT_N 128
int FFT_input[FFT_N];				// input arrayv
int FFT_output[FFT_N+2];			// one extra element
unsigned short FFT_window[FFT_N/2];	//first half of symetrical window 0Q16 unsigned


