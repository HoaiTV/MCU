#include <stm32f1xx.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "crc7.h"
#include "timing.h"
#include "sd_utils.h"

void RCC_Init()
{
    /* Turn on HSE and wait for HSE settling */
    SET_BIT(RCC->CR, RCC_CR_HSEON);
    while(READ_BIT(RCC->CR, RCC_CR_HSERDY) == 0);

    /* Set PLL Multiplier to 6x, Set PLL Clock Source to HSE, set APB1 Prescaller */
    WRITE_REG(RCC->CFGR, RCC_CFGR_PLLMULL9 | RCC_CFGR_PLLSRC | RCC_CFGR_PPRE1_DIV2);

    /*  Enable PLL and wait for PLL settling */
    SET_BIT(RCC->CR, RCC_CR_PLLON);
    while(READ_BIT(RCC->CR, RCC_CR_PLLRDY) == 0);

    /* Set Flash Latency, Enable Prefetcher and wait for Prefetcher settling */
    SET_BIT(FLASH->ACR, (0x02 << FLASH_ACR_LATENCY_Pos) | FLASH_ACR_PRFTBE);
    while(READ_BIT(FLASH->ACR, FLASH_ACR_PRFTBS) == 0);

    /* Select PLL as System Clock */
    SET_BIT(RCC->CFGR, RCC_CFGR_SW_PLL);

    /* Update SystemCoreClock variable */
    SystemCoreClockUpdate();
}

void TIM3_Init()
{
    /* Enable GPIOB Clock */
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);

    /* Configure TIM3 Pins */
    MODIFY_REG(GPIOB->CRL,
               (GPIO_CRL_CNF0_Msk | GPIO_CRL_MODE0_Msk) |   /* GPIOA_7: TIM3_CH3 */
               (GPIO_CRL_CNF1_Msk | GPIO_CRL_MODE1_Msk),    /* GPIOA_6: TIM3_CH4 */
               (0b1010 << GPIO_CRL_MODE0_Pos) |             /* GPIOA_5: TIM3_CH3 - Alternate function, low speed output */
               (0b1010 << GPIO_CRL_MODE1_Pos) );            /* GPIOA_4: TIM3_CH4 - Alternate function, low speed output */

    /* Enable TIM14 Clock */
    SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);

    /* Set Auto-reload preload mode */
    SET_BIT(TIM3->CR1, TIM_CR1_ARPE);

    /* Set Timer Period */
    WRITE_REG(TIM3->ARR, 2047);

    /* Set PWM Width */
    WRITE_REG(TIM3->CCR3, 1023);
    WRITE_REG(TIM3->CCR4, 1023);

    /* Configure PWM mode for channels 3 and 4 */
    WRITE_REG(TIM3->CCMR2, (0x06 << TIM_CCMR2_OC3M_Pos) | (0x06 << TIM_CCMR2_OC4M_Pos) | TIM_CCMR2_OC3PE | TIM_CCMR2_OC4PE);

    /* Enable Channel 3 and 4 */
    SET_BIT(TIM3->CCER, TIM_CCER_CC3E | TIM_CCER_CC4E);

    /* Enable output (MOE = 1) */
    SET_BIT(TIM3->BDTR, TIM_BDTR_MOE);

    /* Enable TIM3 Update Interrupts */
    SET_BIT(TIM3->DIER, TIM_DIER_UIE);
    NVIC_EnableIRQ(TIM3_IRQn);
}

#include "ff.h"

BYTE fat_workarea[_MAX_SS];
uint16_t wav_buffer[2][2048];
volatile uint8_t  act_buffer = 0;
volatile uint32_t buf_idx = 0;

void TIM3_IRQHandler()
{
    CLEAR_BIT(TIM3->SR, TIM_SR_UIF);

    int32_t val = wav_buffer[act_buffer][buf_idx];
    WRITE_REG(TIM3->CCR3, (val >> 5));

    buf_idx++;
    if(buf_idx == 2048)
    {
        buf_idx = 0;
        act_buffer ^= 0x01;
    }
}

uint8_t file_num = 0;
char *filenames[] = {
    "1.raw",
    "2.raw",
    "3.raw",
    "4.raw",
    "5.raw",
    "6.raw",
    "7.raw",
    NULL
};

int main(void)
{
    RCC_Init();
    SPI_Init();
    TIM3_Init();
    Timing_Init();

    FATFS fs;           /* File system object */
    FIL fil;            /* File object */
    UINT br;            /* Bytes written */
    FRESULT res;

    res = f_mount(&fs, "", 0);
    if(res) goto error;

    res = f_open(&fil, filenames[file_num++], FA_READ | FA_OPEN_EXISTING);
    if(filenames[file_num] == NULL) file_num = 0;
    if(res) goto error;

    res = f_read(&fil, wav_buffer[0], sizeof(wav_buffer[0]), &br);
    if(br != sizeof(wav_buffer[0])) goto error;
    if(res) goto error;

    res = f_read(&fil, wav_buffer[1], sizeof(wav_buffer[1]), &br);
    if(br != sizeof(wav_buffer[1])) goto error;
    if(res) goto error;

    /* Enable counter */
    SET_BIT(TIM3->CR1, TIM_CR1_CEN);

    uint32_t play_buf = 0;
    while(1)
    {
        while(play_buf == act_buffer);

        res = f_read(&fil, wav_buffer[play_buf], sizeof(wav_buffer[play_buf]), &br);
        if(res) goto error;

        if(br < sizeof(wav_buffer[play_buf])) {
            f_close(&fil);

            res = f_open(&fil, filenames[file_num++], FA_READ | FA_OPEN_EXISTING);
            if(filenames[file_num] == NULL) file_num = 0;
            if(res) goto error;

            res = f_read(&fil, &wav_buffer[play_buf][br >> 1], sizeof(wav_buffer[play_buf]) - br, &br);
            if(res) goto error;
        }

        play_buf = act_buffer;
    }

error:
    /* Disable counter */
    CLEAR_BIT(TIM3->CR1, TIM_CR1_CEN);

    f_close(&fil);
    f_mount(0, "", 0);

    while(1);
}
