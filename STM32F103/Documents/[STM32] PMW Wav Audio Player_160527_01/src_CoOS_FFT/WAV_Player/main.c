
/****************************************************

Mini-STM32 SD/MMC WAV Audio Player
yus	- http://projectproto.blogspot.com/
June 2010

Simple SD Audio Player with an 8-pin IC
http://elm-chan.org/works/sd8p/report.html

CooCox CoOS real-time multi-task OS specially for ARM Cortex M series
http://www.coocox.org/CoOS.htm

DSP (Fast Fourier Transform) libraries for ARM Cortex M3
http://www.embeddedsignals.com/ARM.htm

*****************************************************/

#include "main.h"

int main(void)
{
	LCD_Init();
	LED_Config();
	PushButton_Config();
	pwm_audio_init();

	LCD_Text(40, 50, "Mini-STM32 WAVE Audio Player", LCD_Yellow, LCD_Red);
	LCD_Text(60, 70, "powered by CooCox CoOS", LCD_Yellow, LCD_Red);
	LCD_Text(40, 100, "yus - projectproto.blogspot", LCD_Yellow, LCD_Red); 	

	CoInitOS ( );                            /*!< Initial CooCox CoOS          */

	/*do{
		spectrum_start_flg = CoCreateFlag(TRUE, 0);	  // autoreset, intial 0
	}while(	spectrum_start_flg == E_CREATE_FAIL);
	do{
		spectrum_ready_flg = CoCreateFlag(TRUE, 0);	  // autoreset, intial 0
	}while(	spectrum_start_flg == E_CREATE_FAIL); */

	spectrum_ready_flag = spectrum_start_flag = FALSE;

	/**		create tasks	**/
	CoCreateTask( play_wav , (void *)0 , PLAY_WAV_PRIORITY, &play_wav_Stk[TASK_STK_SIZE-1], TASK_STK_SIZE );
	CoCreateTask( spectrum_display , (void *)0 , SPECTRUM_DISPLAY_PRIORITY, &spectrum_display_Stk[TASK_STK_SIZE-1], TASK_STK_SIZE );
	CoCreateTask( led_blink , (void *)0 , LED_BLINK_PRIORITY, &led_blink_Stk[TASK_STK_SIZE-1], TASK_STK_SIZE );

	CoStartOS ( );                        /*!< Start multitask               */  	
	while(1);

}

void play_wav(void *pdata)
{
	xWAVFile file;
	WORD i, amplitude, cnt, offset;

	CoTickDelay (200);
	for (;;)
	{
		CoTickDelay (50);
		LCD_Text(40, 170, "insert SD card.", LCD_Cyan, LCD_Red);
		if (pf_mount(&Fs) ) continue;	/* Initialize FS */
		restart_flag = FALSE;LED3_Off();
		while(!restart_flag){
			if (pf_opendir(&Dir, "")) break;				// open root directory			
			while (!pf_readdir(&Dir, &Fno) && Fno.fname[0] && !restart_flag ) {
				if( strstr(Fno.fname, ".WAV") ){			// WAV file
					LCD_Clear(LCD_Red);
					LCD_Text(40, 5, "Mini-STM32 WAVE Audio Player", LCD_Cyan, LCD_Red);

					if (pf_open(Fno.fname) == FR_OK){

						if (Get_WAV_Header(&file) > 256){		// valid file size
							file.pcFileName = Fno.fname; 
							show_wav_info(&file);	// display WAVE file infos
							//CoTickDelay (100);
							set_sampling_rate(file.xSamplingRate);
							next_file_flag = FALSE;	LED3_Off();
							enable_audio();
							if(file.xBitsPerSample==8){
								offset = file.xNumChannels - 1;
								cnt =  READ_BUFF_SIZE>>offset;								
								do{
									pf_read(Buff, READ_BUFF_SIZE, &rb);
									for(i=0; i<cnt; i++){
										wav_putc(Buff[i<<offset]);
									}
									//if( CoWaitForSingleFlag(spectrum_ready_flg,0) == E_OK ){
										//CoSetFlag(spectrum_start_flg);
									//}
									if( spectrum_ready_flag ){
										spectrum_ready_flag = FALSE;
										for(i=0; i<128; i++){
											//FFT_input[i] = (int)(Buff[i<<offset])<<8;
											FFT_input[i] = ( (int)(Buff[i<<offset]<<7) ) - (0x80<<7);
										}
										spectrum_start_flag = TRUE;
									}
								}while( (rb==READ_BUFF_SIZE) && !next_file_flag && !restart_flag);
								
							}
							else if(file.xBitsPerSample==16){
								offset = file.xNumChannels - 0;
								cnt =  READ_BUFF_SIZE>>offset;
								do{
									pf_read(Buff, READ_BUFF_SIZE, &rb);
									for(i=0; i<cnt; i++){
										amplitude = Buff[(i<<offset)+1];
										// two's compliment ???
								#if 0		
										if(amplitude&0x80)	amplitude = 128 - (amplitude&0x7F)>>1;
										else	amplitude = 127 + (amplitude>>1);
								#else
										if(amplitude&0x80)	amplitude = 0;
								#endif
										wav_putc(amplitude);
									}
									if( spectrum_ready_flag ){
										spectrum_ready_flag = FALSE;
										for(i=0; i<128; i++){
											FFT_input[i] = (int)(Buff[(i<<offset)+1]<<8) + Buff[(i<<offset)+0];
										}
										spectrum_start_flag = TRUE;
									}
								}while( (rb==READ_BUFF_SIZE) && !next_file_flag && !restart_flag);
							}
							
							disable_audio();
						}//is valid file size

					}//open file

				}// is wav file

			}//open directory
		}
	}
}



void spectrum_display(void *pdata)
{
	int i;
	int amplitude;

	//clear output array
	for (i=0;i<FFT_N;i++)   FFT_output[i]=0;
	//CoSetFlag(spectrum_ready_flg);
	spectrum_ready_flag = TRUE;
	for (;;)
	{
		//while( CoWaitForSingleFlag(spectrum_start_flg,0) != E_OK );
		CoTickDelay (5);
		if( spectrum_start_flag ){
			spectrum_start_flag = FALSE;

			//create windowing function 0Q16  (0.5 =32768   0.99998 =65535)
			for (i=0;i<FFT_N/2;i++)   FFT_window[i]=0xffff;   //0.99998

			/* clear the previous spectrum display */
			LCD_WriteRegister(0x03,0x1018);
			//for(i=2; i<63; i++){
			for(i=5; i<59; i++){
				//amplitude = (FFT_output[i<<1]+16384)>>15;
				amplitude = (FFT_output[i<<1]+16384)>>18;
				if(amplitude>128) amplitude = 128;
				do{
					//LCD_SetCursor((i<<2)+i,200-amplitude);	// pos = i*5
					LCD_WriteRegister(0x0020,200-amplitude);
					LCD_WriteRegister(0x0021,0x13f-((i<<2)+i));
					Clr_Cs;
					LCD_WriteIndex(0x0022);
					Set_Rs;
					LCD_WriteData(LCD_DarkBlue);	Clr_nWr;Set_nWr;
					LCD_WriteData(LCD_DarkBlue);	Clr_nWr;Set_nWr;
					LCD_WriteData(LCD_DarkBlue);	Clr_nWr;Set_nWr;
					LCD_WriteData(LCD_DarkBlue);	Clr_nWr;Set_nWr;
					Set_Cs;
				}while(amplitude--);
				
			}			

			//clear output array
			for (i=0;i<FFT_N;i++)   FFT_output[i]=0;

			// create input signal (16 bit in 32 bit array, upper 16 bits are ignored)
			//for (i=0;i<FFT_N;i++)	FFT_input[i] = FFT_samples[i];

			Window16to32b_real( FFT_input, Hamming128_16b, FFT_N); // apply Hamming window to input signal

			//call FFT routine;
			FFT128Real_32b(FFT_output, FFT_input);

			// convert complex output to magnitude
			magnitude32_32bIn(&FFT_output[2], FFT_N/2-1);  //DC and Fs/2 bins are already real (can be negative!)

			//Format output for easier reading
			//for (i=0;i<=FFT_N;i+=2) FFT_output[i+1]=0; //zero imag part of original complex frequency
			//for (i=0;i<=FFT_N;i+=2) FFT_output[i]=((FFT_output[i]+16384)>>15); //2Q30 converted to 17Q15 and rounded
 
			//for(i=2; i<63; i++){
			for(i=5; i<59; i++){
				//amplitude = (FFT_output[i<<1]+16384)>>15;
				amplitude = (FFT_output[i<<1]+16384)>>18;
				if(amplitude>128) amplitude = 128;
				do{
					//LCD_SetCursor((i<<2)+i,200-amplitude);	// pos = i*5
					LCD_WriteRegister(0x0020,200-amplitude);
					LCD_WriteRegister(0x0021,0x13f-((i<<2)+i));
					Clr_Cs;
					LCD_WriteIndex(0x0022);
					Set_Rs;
					LCD_WriteData(LCD_White);	Clr_nWr;Set_nWr;
					LCD_WriteData(LCD_White);	Clr_nWr;Set_nWr;
					LCD_WriteData(LCD_White);	Clr_nWr;Set_nWr;
					LCD_WriteData(LCD_White);	Clr_nWr;Set_nWr;
					Set_Cs;
				}while(amplitude--);

				
			}
			//CoSetFlag(spectrum_ready_flg);
			spectrum_ready_flag = TRUE;
		}
	}
}

void led_blink(void *pdata)
{
	for (;;)
	{
		CoTickDelay (20);
		LED2_On();
		CoTickDelay (20);
		LED2_Off();
	}
}

void show_wav_info(xWAVFile * file)
{
	char str[20];
	DWORD Length;
	u16 x, y;

	LCD_ClearArea(40,30, 250,60, LCD_Red);
	//File name	
	LCD_Text(70, 30, file->pcFileName, LCD_Yellow, LCD_Red);
	// length in time
	Length = file->xSize / (file->xSamplingRate *file->xNumChannels * (file->xBitsPerSample>>3) );	// length in seconds
	if(Length>60)	sprintf(str, "%ld:%2ldmin", (Length/60), (Length%60));
	else	sprintf(str, "%ldsec", Length);	
	LCD_Text(180, 30, str, LCD_Yellow, LCD_Red);
	// number of channels
	if(file->xNumChannels == 1) 	LCD_Text(50, 45, "Mono", LCD_Yellow, LCD_Red);
	else if(file->xNumChannels == 2) 	LCD_Text(50, 45, "Stereo", LCD_Yellow, LCD_Red);
	// resolution
	sprintf(str, "%ld-bits", file->xBitsPerSample);
	LCD_Text(110, 45, str, LCD_Yellow, LCD_Red);
	// sampling rate	
	sprintf(str, "%ldHz", file->xSamplingRate);
	LCD_Text(180, 45, str, LCD_Yellow, LCD_Red);

	/* prepare "spectrum display" area */
	for(y=65; y<205; y++){
		for(x=20; x<300; x++)	LCD_SetPoint(x,y, LCD_DarkBlue);
	}
	for(x=19; x<300; x++){
		LCD_SetPoint(x,64, LCD_Gray);	LCD_SetPoint(x,63, LCD_Gray);
		LCD_SetPoint(x,205, LCD_Gray);	LCD_SetPoint(x,204, LCD_Gray);
	}
	for(y=65; y<205; y++){
		LCD_SetPoint(19,y, LCD_Gray);	LCD_SetPoint(18,y, LCD_Gray);
		LCD_SetPoint(300,y, LCD_Gray);	LCD_SetPoint(299,y, LCD_Gray);
	}

	LCD_Text(120, 220, "Spectrum", LCD_Cyan, LCD_Red);
	LCD_Text(20, 207, "0", LCD_Green, LCD_Red);
	//sprintf(str, "%ld", (file->xSamplingRate)>>2);
	sprintf(str, "%ldkHz ", (file->xSamplingRate)/4000);
	LCD_Text(135, 207, str, LCD_Green, LCD_Red);
	//sprintf(str, "%ld", (file->xSamplingRate)>>1);
	sprintf(str, "%ldkHz ", (file->xSamplingRate)/2000);
	LCD_Text(270, 207, str, LCD_Green, LCD_Red);
}
