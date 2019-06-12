#ifndef _PWM_AUDIO
#define _PWM_AUDIO

#include "ministm32_pwm.h"
#include <stdbool.h>
#define TRUE	1
#define FALSE	0
#define WAV_BUFFER_SIZE		256

void pwm_audio_init(void);
void set_sampling_rate(unsigned long rate);
void wav_putc(unsigned char c);
void wav_putc_3(unsigned char c);

#define enable_audio()		pwm_output_enable(TRUE)
#define disable_audio()		pwm_output_enable(FALSE)


#endif	// _PWM_AUDIO
