/**
  ******************************************************************************
  * @file    stm32f303xc.h
  * @author  MCD Application Team
  * @version $VERSION$
  * @date    $DATE$
  * @brief   CMSIS STM32F303xC Devices Peripheral Access Layer Header File.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral�s registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup stm32f303xc
  * @{
  */

#ifndef __STM32F303xC_H
#define __STM32F303xC_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
 */
#define __CM4_REV                 0x0001U  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1U       /*!< STM32F303xC devices provide an MPU */
#define __NVIC_PRIO_BITS          4U       /*!< STM32F303xC devices use 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U       /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U       /*!< STM32F303xC devices provide an FPU */

/**
  * @}
  */
   
/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief STM32F303xC devices Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ****************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamp interrupts through the EXTI line 19          */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup interrupt through the EXTI line 20                     */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_TSC_IRQn              = 8,      /*!< EXTI Line2 Interrupt and Touch Sense Controller Interrupt         */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 Interrupt                                          */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 Interrupt                                          */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 Interrupt                                          */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 Interrupt                                          */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 Interrupt                                          */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 Interrupt                                          */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 Interrupt                                          */
  ADC1_2_IRQn                 = 18,     /*!< ADC1 & ADC2 Interrupts                                            */
  USB_HP_CAN_TX_IRQn          = 19,     /*!< USB Device High Priority or CAN TX Interrupts                     */
  USB_LP_CAN_RX0_IRQn         = 20,     /*!< USB Device Low Priority or CAN RX0 Interrupts                     */
  CAN_RX1_IRQn                = 21,     /*!< CAN RX1 Interrupt                                                 */
  CAN_SCE_IRQn                = 22,     /*!< CAN SCE Interrupt                                                 */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 Break and TIM15 Interrupts                                   */
  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 Update and TIM16 Interrupts                                  */
  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt & EXTI Line23 Interrupt (I2C1 wakeup)        */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt & EXTI Line24 Interrupt (I2C2 wakeup)        */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt & EXTI Line25 Interrupt (USART1 wakeup)   */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt & EXTI Line26 Interrupt (USART2 wakeup)   */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt & EXTI Line28 Interrupt (USART3 wakeup)   */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line 17 Interrupt                 */
  USBWakeUp_IRQn              = 42,     /*!< USB Wakeup Interrupt                                              */
  TIM8_BRK_IRQn               = 43,     /*!< TIM8 Break Interrupt                                              */
  TIM8_UP_IRQn                = 44,     /*!< TIM8 Update Interrupt                                             */
  TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 Trigger and Commutation Interrupt                            */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare Interrupt                                    */
  ADC3_IRQn                   = 47,     /*!< ADC3 global Interrupt                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52,     /*!< UART4 global Interrupt & EXTI Line34 Interrupt (UART4 wakeup)     */
  UART5_IRQn                  = 53,     /*!< UART5 global Interrupt & EXTI Line35 Interrupt (UART5 wakeup)     */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC underrun error Interrupt             */
  TIM7_IRQn                   = 55,     /*!< TIM7 global Interrupt                                             */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 Channel 1 global Interrupt                                   */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 Channel 2 global Interrupt                                   */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 Channel 3 global Interrupt                                   */
  DMA2_Channel4_IRQn          = 59,     /*!< DMA2 Channel 4 global Interrupt                                   */
  DMA2_Channel5_IRQn          = 60,     /*!< DMA2 Channel 5 global Interrupt                                   */
  ADC4_IRQn                   = 61,     /*!< ADC4  global Interrupt                                            */
  COMP1_2_3_IRQn              = 64,     /*!< COMP1, COMP2 and COMP3 global Interrupt via EXTI Line21, 22 and 29*/
  COMP4_5_6_IRQn              = 65,     /*!< COMP4, COMP5 and COMP6 global Interrupt via EXTI Line30, 31 and 32*/
  COMP7_IRQn                  = 66,     /*!< COMP7 global Interrupt via EXTI Line33                            */
  USB_HP_IRQn                 = 74,     /*!< USB High Priority global Interrupt                                */
  USB_LP_IRQn                 = 75,     /*!< USB Low Priority global Interrupt                                 */
  USBWakeUp_RMP_IRQn          = 76,     /*!< USB Wakeup Interrupt remap                                        */
  FPU_IRQn                    = 81,      /*!< Floating point Interrupt                                          */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm4.h"            /* Cortex-M4 processor and core peripherals */
#include "system_stm32f3xx.h"    /* STM32F3xx System Header */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t ISR;              /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
  __IO uint32_t IER;              /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
  __IO uint32_t CR;               /*!< ADC control register,                              Address offset: 0x08 */
  __IO uint32_t CFGR;             /*!< ADC Configuration register,                        Address offset: 0x0C */
  uint32_t      RESERVED0;        /*!< Reserved, 0x010                                                         */
  __IO uint32_t SMPR1;            /*!< ADC sample time register 1,                        Address offset: 0x14 */
  __IO uint32_t SMPR2;            /*!< ADC sample time register 2,                        Address offset: 0x18 */
  uint32_t      RESERVED1;        /*!< Reserved, 0x01C                                                         */
  __IO uint32_t TR1;              /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
  __IO uint32_t TR2;              /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
  __IO uint32_t TR3;              /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
  uint32_t      RESERVED2;        /*!< Reserved, 0x02C                                                         */
  __IO uint32_t SQR1;             /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
  __IO uint32_t SQR2;             /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
  __IO uint32_t SQR3;             /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
  __IO uint32_t SQR4;             /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
  __IO uint32_t DR;               /*!< ADC regular data register,                         Address offset: 0x40 */
  uint32_t      RESERVED3;        /*!< Reserved, 0x044                                                         */
  uint32_t      RESERVED4;        /*!< Reserved, 0x048                                                         */
  __IO uint32_t JSQR;             /*!< ADC injected sequence register,                    Address offset: 0x4C */
  uint32_t      RESERVED5[4];     /*!< Reserved, 0x050 - 0x05C                                                 */
  __IO uint32_t OFR1;             /*!< ADC offset register 1,                             Address offset: 0x60 */
  __IO uint32_t OFR2;             /*!< ADC offset register 2,                             Address offset: 0x64 */
  __IO uint32_t OFR3;             /*!< ADC offset register 3,                             Address offset: 0x68 */
  __IO uint32_t OFR4;             /*!< ADC offset register 4,                             Address offset: 0x6C */
  uint32_t      RESERVED6[4];     /*!< Reserved, 0x070 - 0x07C                                                 */
  __IO uint32_t JDR1;             /*!< ADC injected data register 1,                      Address offset: 0x80 */
  __IO uint32_t JDR2;             /*!< ADC injected data register 2,                      Address offset: 0x84 */
  __IO uint32_t JDR3;             /*!< ADC injected data register 3,                      Address offset: 0x88 */
  __IO uint32_t JDR4;             /*!< ADC injected data register 4,                      Address offset: 0x8C */
  uint32_t      RESERVED7[4];     /*!< Reserved, 0x090 - 0x09C                                                 */
  __IO uint32_t AWD2CR;           /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
  __IO uint32_t AWD3CR;           /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
  uint32_t      RESERVED8;        /*!< Reserved, 0x0A8                                                         */
  uint32_t      RESERVED9;        /*!< Reserved, 0x0AC                                                         */
  __IO uint32_t DIFSEL;           /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
  __IO uint32_t CALFACT;          /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;            /*!< ADC Common status register,                  Address offset: ADC1/3 base address + 0x300 */
  uint32_t      RESERVED;       /*!< Reserved, ADC1/3 base address + 0x304                                                    */
  __IO uint32_t CCR;            /*!< ADC common control register,                 Address offset: ADC1/3 base address + 0x308 */
  __IO uint32_t CDR;            /*!< ADC common regular data register for dual
                                     AND triple modes,                            Address offset: ADC1/3 base address + 0x30C */
} ADC_Common_TypeDef;

/**
  * @brief Controller Area Network TxMailBox
  */
typedef struct
{
  __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
  __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
  __IO uint32_t TDLR; /*!< CAN mailbox data low register */
  __IO uint32_t TDHR; /*!< CAN mailbox data high register */
} CAN_TxMailBox_TypeDef;

/**
  * @brief Controller Area Network FIFOMailBox
  */
typedef struct
{
  __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
  __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
  __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
  __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_TypeDef;

/**
  * @brief Controller Area Network FilterRegister
  */
typedef struct
{
  __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
  __IO uint32_t FR2; /*!< CAN Filter bank register 1 */
} CAN_FilterRegister_TypeDef;

/**
  * @brief Controller Area Network
  */
typedef struct
{
  __IO uint32_t              MCR;                 /*!< CAN master control register,         Address offset: 0x00          */
  __IO uint32_t              MSR;                 /*!< CAN master status register,          Address offset: 0x04          */
  __IO uint32_t              TSR;                 /*!< CAN transmit status register,        Address offset: 0x08          */
  __IO uint32_t              RF0R;                /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
  __IO uint32_t              RF1R;                /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
  __IO uint32_t              IER;                 /*!< CAN interrupt enable register,       Address offset: 0x14          */
  __IO uint32_t              ESR;                 /*!< CAN error status register,           Address offset: 0x18          */
  __IO uint32_t              BTR;                 /*!< CAN bit timing register,             Address offset: 0x1C          */
  uint32_t                   RESERVED0[88];       /*!< Reserved, 0x020 - 0x17F                                            */
  CAN_TxMailBox_TypeDef      sTxMailBox[3];       /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];     /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
  uint32_t                   RESERVED1[12];       /*!< Reserved, 0x1D0 - 0x1FF                                            */
  __IO uint32_t              FMR;                 /*!< CAN filter master register,          Address offset: 0x200         */
  __IO uint32_t              FM1R;                /*!< CAN filter mode register,            Address offset: 0x204         */
  uint32_t                   RESERVED2;           /*!< Reserved, 0x208                                                    */
  __IO uint32_t              FS1R;                /*!< CAN filter scale register,           Address offset: 0x20C         */
  uint32_t                   RESERVED3;           /*!< Reserved, 0x210                                                    */
  __IO uint32_t              FFA1R;               /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
  uint32_t                   RESERVED4;           /*!< Reserved, 0x218                                                    */
  __IO uint32_t              FA1R;                /*!< CAN filter activation register,      Address offset: 0x21C         */
  uint32_t                   RESERVED5[8];        /*!< Reserved, 0x220-0x23F                                              */
  CAN_FilterRegister_TypeDef sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_TypeDef;

/**
  * @brief Analog Comparators
  */

typedef struct
{
  __IO uint32_t CSR;    /*!< Comparator control Status register, Address offset: 0x00 */
} COMP_TypeDef;

/**
  * @brief CRC calculation unit
  */

typedef struct
{
  __IO uint32_t DR;          /*!< CRC Data register,                           Address offset: 0x00 */
  __IO uint8_t  IDR;         /*!< CRC Independent data register,               Address offset: 0x04 */
  uint8_t       RESERVED0;   /*!< Reserved,                                                    0x05 */
  uint16_t      RESERVED1;   /*!< Reserved,                                                    0x06 */
  __IO uint32_t CR;          /*!< CRC Control register,                        Address offset: 0x08 */
  uint32_t      RESERVED2;   /*!< Reserved,                                                    0x0C */
  __IO uint32_t INIT;        /*!< Initial CRC value register,                  Address offset: 0x10 */
  __IO uint32_t POL;         /*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
  * @brief Digital to Analog Converter
  */

typedef struct
{
  __IO uint32_t CR;       /*!< DAC control register,                                    Address offset: 0x00 */
  __IO uint32_t SWTRIGR;  /*!< DAC software trigger register,                           Address offset: 0x04 */
  __IO uint32_t DHR12R1;  /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
  __IO uint32_t DHR12L1;  /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
  __IO uint32_t DHR8R1;   /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
  __IO uint32_t DHR12R2;  /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
  __IO uint32_t DHR12L2;  /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
  __IO uint32_t DHR8R2;   /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
  __IO uint32_t DHR12RD;  /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
  __IO uint32_t DHR12LD;  /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
  __IO uint32_t DHR8RD;   /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
  __IO uint32_t DOR1;     /*!< DAC channel1 data output register,                       Address offset: 0x2C */
  __IO uint32_t DOR2;     /*!< DAC channel2 data output register,                       Address offset: 0x30 */
  __IO uint32_t SR;       /*!< DAC status register,                                     Address offset: 0x34 */
} DAC_TypeDef;

/**
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;  /*!< MCU device ID code,               Address offset: 0x00 */
  __IO uint32_t CR;      /*!< Debug MCU configuration register, Address offset: 0x04 */
  __IO uint32_t APB1FZ;  /*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
  __IO uint32_t APB2FZ;  /*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */
}DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t CCR;          /*!< DMA channel x configuration register                                           */
  __IO uint32_t CNDTR;        /*!< DMA channel x number of data register                                          */
  __IO uint32_t CPAR;         /*!< DMA channel x peripheral address register                                      */
  __IO uint32_t CMAR;         /*!< DMA channel x memory address register                                          */
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;          /*!< DMA interrupt status register,                            Address offset: 0x00 */
  __IO uint32_t IFCR;         /*!< DMA interrupt flag clear register,                        Address offset: 0x04 */
} DMA_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMR;          /*!<EXTI Interrupt mask register,                             Address offset: 0x00 */
  __IO uint32_t EMR;          /*!<EXTI Event mask register,                                 Address offset: 0x04 */
  __IO uint32_t RTSR;         /*!<EXTI Rising trigger selection register ,                  Address offset: 0x08 */
  __IO uint32_t FTSR;         /*!<EXTI Falling trigger selection register,                  Address offset: 0x0C */
  __IO uint32_t SWIER;        /*!<EXTI Software interrupt event register,                   Address offset: 0x10 */
  __IO uint32_t PR;           /*!<EXTI Pending register,                                    Address offset: 0x14 */
  uint32_t      RESERVED1;    /*!< Reserved, 0x18                                                                */
  uint32_t      RESERVED2;    /*!< Reserved, 0x1C                                                                */
  __IO uint32_t IMR2;         /*!< EXTI Interrupt mask register,                            Address offset: 0x20 */
  __IO uint32_t EMR2;         /*!< EXTI Event mask register,                                Address offset: 0x24 */
  __IO uint32_t RTSR2;        /*!< EXTI Rising trigger selection register,                  Address offset: 0x28 */
  __IO uint32_t FTSR2;        /*!< EXTI Falling trigger selection register,                 Address offset: 0x2C */
  __IO uint32_t SWIER2;       /*!< EXTI Software interrupt event register,                  Address offset: 0x30 */
  __IO uint32_t PR2;          /*!< EXTI Pending register,                                   Address offset: 0x34 */
}EXTI_TypeDef;

/**
  * @brief FLASH Registers
  */

typedef struct
{
  __IO uint32_t ACR;          /*!< FLASH access control register,              Address offset: 0x00 */
  __IO uint32_t KEYR;         /*!< FLASH key register,                         Address offset: 0x04 */
  __IO uint32_t OPTKEYR;      /*!< FLASH option key register,                  Address offset: 0x08 */
  __IO uint32_t SR;           /*!< FLASH status register,                      Address offset: 0x0C */
  __IO uint32_t CR;           /*!< FLASH control register,                     Address offset: 0x10 */
  __IO uint32_t AR;           /*!< FLASH address register,                     Address offset: 0x14 */
  uint32_t      RESERVED;     /*!< Reserved, 0x18                                                   */
  __IO uint32_t OBR;          /*!< FLASH Option byte register,                 Address offset: 0x1C */
  __IO uint32_t WRPR;         /*!< FLASH Write register,                       Address offset: 0x20 */

} FLASH_TypeDef;

/**
  * @brief Option Bytes Registers
  */
typedef struct
{
  __IO uint16_t RDP;          /*!<FLASH option byte Read protection,             Address offset: 0x00 */
  __IO uint16_t USER;         /*!<FLASH option byte user options,                Address offset: 0x02 */
  uint16_t RESERVED0;         /*!< Reserved,                                                     0x04 */
  uint16_t RESERVED1;         /*!< Reserved,                                                     0x06 */
  __IO uint16_t WRP0;         /*!<FLASH option byte write protection 0,          Address offset: 0x08 */
  __IO uint16_t WRP1;         /*!<FLASH option byte write protection 1,          Address offset: 0x0C */
  __IO uint16_t WRP2;         /*!<FLASH option byte write protection 2,          Address offset: 0x10 */
  __IO uint16_t WRP3;         /*!<FLASH option byte write protection 3,          Address offset: 0x12 */
} OB_TypeDef;

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t MODER;        /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;       /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;          /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;          /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset register,      Address offset: 0x1A */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];       /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  __IO uint32_t BRR;          /*!< GPIO bit reset register,               Address offset: 0x28 */
}GPIO_TypeDef;

/**
  * @brief Operational Amplifier (OPAMP)
  */

typedef struct
{
  __IO uint32_t CSR;        /*!< OPAMP control and status register,            Address offset: 0x00 */
} OPAMP_TypeDef;

/**
  * @brief System configuration controller
  */

typedef struct
{
  __IO uint32_t CFGR1;       /*!< SYSCFG configuration register 1,                      Address offset: 0x00 */
  __IO uint32_t RCR;        /*!< SYSCFG CCM SRAM protection register,               Address offset: 0x04 */
  __IO uint32_t EXTICR[4];   /*!< SYSCFG external interrupt configuration registers, Address offset: 0x14-0x08 */
  __IO uint32_t CFGR2;       /*!< SYSCFG configuration register 2,                      Address offset: 0x18 */
} SYSCFG_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CR1;      /*!< I2C Control register 1,            Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< I2C Control register 2,            Address offset: 0x04 */
  __IO uint32_t OAR1;     /*!< I2C Own address 1 register,        Address offset: 0x08 */
  __IO uint32_t OAR2;     /*!< I2C Own address 2 register,        Address offset: 0x0C */
  __IO uint32_t TIMINGR;  /*!< I2C Timing register,               Address offset: 0x10 */
  __IO uint32_t TIMEOUTR; /*!< I2C Timeout register,              Address offset: 0x14 */
  __IO uint32_t ISR;      /*!< I2C Interrupt and status register, Address offset: 0x18 */
  __IO uint32_t ICR;      /*!< I2C Interrupt clear register,      Address offset: 0x1C */
  __IO uint32_t PECR;     /*!< I2C PEC register,                  Address offset: 0x20 */
  __IO uint32_t RXDR;     /*!< I2C Receive data register,         Address offset: 0x24 */
  __IO uint32_t TXDR;     /*!< I2C Transmit data register,        Address offset: 0x28 */
}I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __IO uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
  __IO uint32_t WINR; /*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;

/**
  * @brief Power Control
  */

typedef struct
{
  __IO uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  __IO uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;

/**
  * @brief Reset and Clock Control
  */
typedef struct
{
  __IO uint32_t CR;         /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t CFGR;       /*!< RCC clock configuration register,                            Address offset: 0x04 */
  __IO uint32_t CIR;        /*!< RCC clock interrupt register,                                Address offset: 0x08 */
  __IO uint32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
  __IO uint32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
  __IO uint32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
  __IO uint32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
  __IO uint32_t BDCR;       /*!< RCC Backup domain control register,                          Address offset: 0x20 */
  __IO uint32_t CSR;        /*!< RCC clock control & status register,                         Address offset: 0x24 */
  __IO uint32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
  __IO uint32_t CFGR2;      /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
  __IO uint32_t CFGR3;      /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
} RCC_TypeDef;

/**
  * @brief Real-Time Clock
  */

typedef struct
{
  __IO uint32_t TR;         /*!< RTC time register,                                        Address offset: 0x00 */
  __IO uint32_t DR;         /*!< RTC date register,                                        Address offset: 0x04 */
  __IO uint32_t CR;         /*!< RTC control register,                                     Address offset: 0x08 */
  __IO uint32_t ISR;        /*!< RTC initialization and status register,                   Address offset: 0x0C */
  __IO uint32_t PRER;       /*!< RTC prescaler register,                                   Address offset: 0x10 */
  __IO uint32_t WUTR;       /*!< RTC wakeup timer register,                                Address offset: 0x14 */
  uint32_t RESERVED0;       /*!< Reserved, 0x18                                                                 */
  __IO uint32_t ALRMAR;     /*!< RTC alarm A register,                                     Address offset: 0x1C */
  __IO uint32_t ALRMBR;     /*!< RTC alarm B register,                                     Address offset: 0x20 */
  __IO uint32_t WPR;        /*!< RTC write protection register,                            Address offset: 0x24 */
  __IO uint32_t SSR;        /*!< RTC sub second register,                                  Address offset: 0x28 */
  __IO uint32_t SHIFTR;     /*!< RTC shift control register,                               Address offset: 0x2C */
  __IO uint32_t TSTR;       /*!< RTC time stamp time register,                             Address offset: 0x30 */
  __IO uint32_t TSDR;       /*!< RTC time stamp date register,                             Address offset: 0x34 */
  __IO uint32_t TSSSR;      /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
  __IO uint32_t CALR;       /*!< RTC calibration register,                                 Address offset: 0x3C */
  __IO uint32_t TAFCR;      /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
  __IO uint32_t ALRMASSR;   /*!< RTC alarm A sub second register,                          Address offset: 0x44 */
  __IO uint32_t ALRMBSSR;   /*!< RTC alarm B sub second register,                          Address offset: 0x48 */
  uint32_t RESERVED7;       /*!< Reserved, 0x4C                                                                 */
  __IO uint32_t BKP0R;      /*!< RTC backup register 0,                                    Address offset: 0x50 */
  __IO uint32_t BKP1R;      /*!< RTC backup register 1,                                    Address offset: 0x54 */
  __IO uint32_t BKP2R;      /*!< RTC backup register 2,                                    Address offset: 0x58 */
  __IO uint32_t BKP3R;      /*!< RTC backup register 3,                                    Address offset: 0x5C */
  __IO uint32_t BKP4R;      /*!< RTC backup register 4,                                    Address offset: 0x60 */
  __IO uint32_t BKP5R;      /*!< RTC backup register 5,                                    Address offset: 0x64 */
  __IO uint32_t BKP6R;      /*!< RTC backup register 6,                                    Address offset: 0x68 */
  __IO uint32_t BKP7R;      /*!< RTC backup register 7,                                    Address offset: 0x6C */
  __IO uint32_t BKP8R;      /*!< RTC backup register 8,                                    Address offset: 0x70 */
  __IO uint32_t BKP9R;      /*!< RTC backup register 9,                                    Address offset: 0x74 */
  __IO uint32_t BKP10R;     /*!< RTC backup register 10,                                   Address offset: 0x78 */
  __IO uint32_t BKP11R;     /*!< RTC backup register 11,                                   Address offset: 0x7C */
  __IO uint32_t BKP12R;     /*!< RTC backup register 12,                                   Address offset: 0x80 */
  __IO uint32_t BKP13R;     /*!< RTC backup register 13,                                   Address offset: 0x84 */
  __IO uint32_t BKP14R;     /*!< RTC backup register 14,                                   Address offset: 0x88 */
  __IO uint32_t BKP15R;     /*!< RTC backup register 15,                                   Address offset: 0x8C */
} RTC_TypeDef;


/**
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CR1;      /*!< SPI Control register 1,                              Address offset: 0x00 */
  __IO uint32_t CR2;      /*!< SPI Control register 2,                              Address offset: 0x04 */
  __IO uint32_t SR;       /*!< SPI Status register,                                 Address offset: 0x08 */
  __IO uint32_t DR;       /*!< SPI data register,                                   Address offset: 0x0C */
  __IO uint32_t CRCPR;    /*!< SPI CRC polynomial register,                         Address offset: 0x10 */
  __IO uint32_t RXCRCR;   /*!< SPI Rx CRC register,                                 Address offset: 0x14 */
  __IO uint32_t TXCRCR;   /*!< SPI Tx CRC register,                                 Address offset: 0x18 */
  __IO uint32_t I2SCFGR;  /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
  __IO uint32_t I2SPR;    /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */
} SPI_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                 Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  __IO uint32_t OR;          /*!< TIM option register,                 Address offset: 0x50 */
  __IO uint32_t CCMR3;       /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
  __IO uint32_t CCR5;        /*!< TIM capture/compare register5,       Address offset: 0x58 */
  __IO uint32_t CCR6;        /*!< TIM capture/compare register 4,      Address offset: 0x5C */
} TIM_TypeDef;

/**
  * @brief Touch Sensing Controller (TSC)
  */
typedef struct
{
  __IO uint32_t CR;            /*!< TSC control register,                                     Address offset: 0x00 */
  __IO uint32_t IER;           /*!< TSC interrupt enable register,                            Address offset: 0x04 */
  __IO uint32_t ICR;           /*!< TSC interrupt clear register,                             Address offset: 0x08 */
  __IO uint32_t ISR;           /*!< TSC interrupt status register,                            Address offset: 0x0C */
  __IO uint32_t IOHCR;         /*!< TSC I/O hysteresis control register,                      Address offset: 0x10 */
  uint32_t      RESERVED1;     /*!< Reserved,                                                 Address offset: 0x14 */
  __IO uint32_t IOASCR;        /*!< TSC I/O analog switch control register,                   Address offset: 0x18 */
  uint32_t      RESERVED2;     /*!< Reserved,                                                 Address offset: 0x1C */
  __IO uint32_t IOSCR;         /*!< TSC I/O sampling control register,                        Address offset: 0x20 */
  uint32_t      RESERVED3;     /*!< Reserved,                                                 Address offset: 0x24 */
  __IO uint32_t IOCCR;         /*!< TSC I/O channel control register,                         Address offset: 0x28 */
  uint32_t      RESERVED4;     /*!< Reserved,                                                 Address offset: 0x2C */
  __IO uint32_t IOGCSR;        /*!< TSC I/O group control status register,                    Address offset: 0x30 */
  __IO uint32_t IOGXCR[8];     /*!< TSC I/O group x counter register,                         Address offset: 0x34-50 */
} TSC_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */

typedef struct
{
  __IO uint32_t CR1;    /*!< USART Control register 1,                 Address offset: 0x00 */
  __IO uint32_t CR2;    /*!< USART Control register 2,                 Address offset: 0x04 */
  __IO uint32_t CR3;    /*!< USART Control register 3,                 Address offset: 0x08 */
  __IO uint32_t BRR;    /*!< USART Baud rate register,                 Address offset: 0x0C */
  __IO uint32_t GTPR;   /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
  __IO uint32_t RTOR;   /*!< USART Receiver Time Out register,         Address offset: 0x14 */
  __IO uint32_t RQR;    /*!< USART Request register,                   Address offset: 0x18 */
  __IO uint32_t ISR;    /*!< USART Interrupt and status register,      Address offset: 0x1C */
  __IO uint32_t ICR;    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
  __IO uint16_t RDR;    /*!< USART Receive Data register,              Address offset: 0x24 */
  uint16_t  RESERVED1;  /*!< Reserved, 0x26                                                 */
  __IO uint16_t TDR;    /*!< USART Transmit Data register,             Address offset: 0x28 */
  uint16_t  RESERVED2;  /*!< Reserved, 0x2A                                                 */
} USART_TypeDef;

/** 
  * @brief Universal Serial Bus Full Speed Device
  */
  
typedef struct
{
  __IO uint16_t EP0R;            /*!< USB Endpoint 0 register,                Address offset: 0x00 */ 
  __IO uint16_t RESERVED0;       /*!< Reserved */     
  __IO uint16_t EP1R;            /*!< USB Endpoint 1 register,                Address offset: 0x04 */
  __IO uint16_t RESERVED1;       /*!< Reserved */       
  __IO uint16_t EP2R;            /*!< USB Endpoint 2 register,                Address offset: 0x08 */
  __IO uint16_t RESERVED2;       /*!< Reserved */       
  __IO uint16_t EP3R;            /*!< USB Endpoint 3 register,                Address offset: 0x0C */ 
  __IO uint16_t RESERVED3;       /*!< Reserved */       
  __IO uint16_t EP4R;            /*!< USB Endpoint 4 register,                Address offset: 0x10 */
  __IO uint16_t RESERVED4;       /*!< Reserved */       
  __IO uint16_t EP5R;            /*!< USB Endpoint 5 register,                Address offset: 0x14 */
  __IO uint16_t RESERVED5;       /*!< Reserved */       
  __IO uint16_t EP6R;            /*!< USB Endpoint 6 register,                Address offset: 0x18 */
  __IO uint16_t RESERVED6;       /*!< Reserved */       
  __IO uint16_t EP7R;            /*!< USB Endpoint 7 register,                Address offset: 0x1C */
  __IO uint16_t RESERVED7[17];   /*!< Reserved */     
  __IO uint16_t CNTR;            /*!< Control register,                       Address offset: 0x40 */
  __IO uint16_t RESERVED8;       /*!< Reserved */       
  __IO uint16_t ISTR;            /*!< Interrupt status register,              Address offset: 0x44 */
  __IO uint16_t RESERVED9;       /*!< Reserved */       
  __IO uint16_t FNR;             /*!< Frame number register,                  Address offset: 0x48 */
  __IO uint16_t RESERVEDA;       /*!< Reserved */       
  __IO uint16_t DADDR;           /*!< Device address register,                Address offset: 0x4C */
  __IO uint16_t RESERVEDB;       /*!< Reserved */       
  __IO uint16_t BTABLE;          /*!< Buffer Table address register,          Address offset: 0x50 */
  __IO uint16_t RESERVEDC;       /*!< Reserved */
} USB_TypeDef;

/**
  * @brief Window WATCHDOG
  */
typedef struct
{
  __IO uint32_t CR;   /*!< WWDG Control register,       Address offset: 0x00 */
  __IO uint32_t CFR;  /*!< WWDG Configuration register, Address offset: 0x04 */
  __IO uint32_t SR;   /*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE            ((uint32_t)0x08000000U) /*!< FLASH base address in the alias region */
#define CCMDATARAM_BASE       ((uint32_t)0x10000000U) /*!< CCM(core coupled memory) data RAM base address in the alias region     */
#define SRAM_BASE             ((uint32_t)0x20000000U) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           ((uint32_t)0x40000000U) /*!< Peripheral base address in the alias region */
#define SRAM_BB_BASE          ((uint32_t)0x22000000U) /*!< SRAM base address in the bit-band region */
#define PERIPH_BB_BASE        ((uint32_t)0x42000000U) /*!< Peripheral base address in the bit-band region */


/*!< Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000U)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000U)
#define AHB3PERIPH_BASE       (PERIPH_BASE + 0x10000000U)

/*!< APB1 peripherals */
#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000U)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400U)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x00000800U)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x00001000U)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x00001400U)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800U)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00U)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000U)
#define I2S2ext_BASE          (APB1PERIPH_BASE + 0x00003400U)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x00003800U)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x00003C00U)
#define I2S3ext_BASE          (APB1PERIPH_BASE + 0x00004000U)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400U)
#define USART3_BASE           (APB1PERIPH_BASE + 0x00004800U)
#define UART4_BASE            (APB1PERIPH_BASE + 0x00004C00U)
#define UART5_BASE            (APB1PERIPH_BASE + 0x00005000U)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400U)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x00005800U)
#define USB_BASE              (APB1PERIPH_BASE + 0x00005C00U) /*!< USB_IP Peripheral Registers base address */
#define USB_PMAADDR           (APB1PERIPH_BASE + 0x00006000U) /*!< USB_IP Packet Memory Area base address */
#define CAN_BASE              (APB1PERIPH_BASE + 0x00006400U)
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000U)
#define DAC1_BASE             (APB1PERIPH_BASE + 0x00007400U)
#define DAC_BASE               DAC1_BASE

/*!< APB2 peripherals */
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00000000U)
#define COMP1_BASE            (APB2PERIPH_BASE + 0x0000001CU)
#define COMP2_BASE            (APB2PERIPH_BASE + 0x00000020U)
#define COMP3_BASE            (APB2PERIPH_BASE + 0x00000024U)
#define COMP4_BASE            (APB2PERIPH_BASE + 0x00000028U)
#define COMP5_BASE            (APB2PERIPH_BASE + 0x0000002CU)
#define COMP6_BASE            (APB2PERIPH_BASE + 0x00000030U)
#define COMP7_BASE            (APB2PERIPH_BASE + 0x00000034U)
#define COMP_BASE             COMP1_BASE
#define OPAMP1_BASE           (APB2PERIPH_BASE + 0x00000038U)
#define OPAMP2_BASE           (APB2PERIPH_BASE + 0x0000003CU)
#define OPAMP3_BASE           (APB2PERIPH_BASE + 0x00000040U)
#define OPAMP4_BASE           (APB2PERIPH_BASE + 0x00000044U)
#define OPAMP_BASE            OPAMP1_BASE
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400U)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00U)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000U)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x00003400U)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800U)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x00004000U)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x00004400U)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x00004800U)

/*!< AHB1 peripherals */
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x00000000U)
#define DMA1_Channel1_BASE    (AHB1PERIPH_BASE + 0x00000008U)
#define DMA1_Channel2_BASE    (AHB1PERIPH_BASE + 0x0000001CU)
#define DMA1_Channel3_BASE    (AHB1PERIPH_BASE + 0x00000030U)
#define DMA1_Channel4_BASE    (AHB1PERIPH_BASE + 0x00000044U)
#define DMA1_Channel5_BASE    (AHB1PERIPH_BASE + 0x00000058U)
#define DMA1_Channel6_BASE    (AHB1PERIPH_BASE + 0x0000006CU)
#define DMA1_Channel7_BASE    (AHB1PERIPH_BASE + 0x00000080U)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x00000400U)
#define DMA2_Channel1_BASE    (AHB1PERIPH_BASE + 0x00000408U)
#define DMA2_Channel2_BASE    (AHB1PERIPH_BASE + 0x0000041CU)
#define DMA2_Channel3_BASE    (AHB1PERIPH_BASE + 0x00000430U)
#define DMA2_Channel4_BASE    (AHB1PERIPH_BASE + 0x00000444U)
#define DMA2_Channel5_BASE    (AHB1PERIPH_BASE + 0x00000458U)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x00001000U)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x00002000U) /*!< Flash registers base address */
#define OB_BASE               ((uint32_t)0x1FFFF800U)         /*!< Flash Option Bytes base address */
#define FLASHSIZE_BASE        ((uint32_t)0x1FFFF7CCU)         /*!< FLASH Size register base address */
#define UID_BASE              ((uint32_t)0x1FFFF7ACU)         /*!< Unique device ID register base address */
#define CRC_BASE              (AHB1PERIPH_BASE + 0x00003000U)
#define TSC_BASE              (AHB1PERIPH_BASE + 0x00004000U)

/*!< AHB2 peripherals */
#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000U)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400U)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800U)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00U)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x00001000U)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400U)

/*!< AHB3 peripherals */
#define ADC1_BASE             (AHB3PERIPH_BASE + 0x00000000U)
#define ADC2_BASE             (AHB3PERIPH_BASE + 0x00000100U)
#define ADC1_2_COMMON_BASE    (AHB3PERIPH_BASE + 0x00000300U)
#define ADC3_BASE             (AHB3PERIPH_BASE + 0x00000400U)
#define ADC4_BASE             (AHB3PERIPH_BASE + 0x00000500U)
#define ADC3_4_COMMON_BASE    (AHB3PERIPH_BASE + 0x00000700U)

#define DBGMCU_BASE          ((uint32_t)0xE0042000U) /*!< Debug MCU registers base address */
/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */
#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define I2S2ext             ((SPI_TypeDef *) I2S2ext_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#define I2S3ext             ((SPI_TypeDef *) I2S3ext_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define UART4               ((USART_TypeDef *) UART4_BASE)
#define UART5               ((USART_TypeDef *) UART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define CAN                 ((CAN_TypeDef *) CAN_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE)
#define DAC1                ((DAC_TypeDef *) DAC1_BASE)
#define COMP                ((COMP_TypeDef *) COMP_BASE)
#define COMP1               ((COMP_TypeDef *) COMP1_BASE)
#define COMP2               ((COMP_TypeDef *) COMP2_BASE)
#define COMP3               ((COMP_TypeDef *) COMP3_BASE)
#define COMP4               ((COMP_TypeDef *) COMP4_BASE)
#define COMP5               ((COMP_TypeDef *) COMP5_BASE)
#define COMP6               ((COMP_TypeDef *) COMP6_BASE)
#define COMP7               ((COMP_TypeDef *) COMP7_BASE)
#define OPAMP1              ((OPAMP_TypeDef *) OPAMP1_BASE)
#define OPAMP               ((OPAMP_TypeDef *) OPAMP_BASE)
#define OPAMP2              ((OPAMP_TypeDef *) OPAMP2_BASE)
#define OPAMP3              ((OPAMP_TypeDef *) OPAMP3_BASE)
#define OPAMP4              ((OPAMP_TypeDef *) OPAMP4_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define TSC                 ((TSC_TypeDef *) TSC_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#define ADC4                ((ADC_TypeDef *) ADC4_BASE)
#define ADC12_COMMON        ((ADC_Common_TypeDef *) ADC1_2_COMMON_BASE)
#define ADC34_COMMON        ((ADC_Common_TypeDef *) ADC3_4_COMMON_BASE)
/* Legacy defines */
#define ADC1_2_COMMON       ADC12_COMMON
#define ADC3_4_COMMON       ADC34_COMMON
#define USB                 ((USB_TypeDef *) USB_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter SAR (ADC)               */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F3 family)
 */
#define ADC_MULTIMODE_SUPPORT                          /*!< ADC feature available only on specific devices: multimode available on devices with several ADC instances */

/********************  Bit definition for ADC_ISR register  ********************/
#define ADC_ISR_ADRDY           ((uint32_t)0x00000001U) /*!< ADC ready flag */
#define ADC_ISR_EOSMP           ((uint32_t)0x00000002U) /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC             ((uint32_t)0x00000004U) /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS             ((uint32_t)0x00000008U) /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR             ((uint32_t)0x00000010U) /*!< ADC group regular overrun flag */
#define ADC_ISR_JEOC            ((uint32_t)0x00000020U) /*!< ADC group injected end of unitary conversion flag */
#define ADC_ISR_JEOS            ((uint32_t)0x00000040U) /*!< ADC group injected end of sequence conversions flag */
#define ADC_ISR_AWD1            ((uint32_t)0x00000080U) /*!< ADC analog watchdog 1 flag */
#define ADC_ISR_AWD2            ((uint32_t)0x00000100U) /*!< ADC analog watchdog 2 flag */
#define ADC_ISR_AWD3            ((uint32_t)0x00000200U) /*!< ADC analog watchdog 3 flag */
#define ADC_ISR_JQOVF           ((uint32_t)0x00000400U) /*!< ADC group injected contexts queue overflow flag */

/* Legacy defines */
#define ADC_ISR_ADRD            (ADC_ISR_ADRDY)

/********************  Bit definition for ADC_IER register  ********************/
#define ADC_IER_ADRDYIE         ((uint32_t)0x00000001U) /*!< ADC ready interrupt */
#define ADC_IER_EOSMPIE         ((uint32_t)0x00000002U) /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE           ((uint32_t)0x00000004U) /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE           ((uint32_t)0x00000008U) /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE           ((uint32_t)0x00000010U) /*!< ADC group regular overrun interrupt */
#define ADC_IER_JEOCIE          ((uint32_t)0x00000020U) /*!< ADC group injected end of unitary conversion interrupt */
#define ADC_IER_JEOSIE          ((uint32_t)0x00000040U) /*!< ADC group injected end of sequence conversions interrupt */
#define ADC_IER_AWD1IE          ((uint32_t)0x00000080U) /*!< ADC analog watchdog 1 interrupt */
#define ADC_IER_AWD2IE          ((uint32_t)0x00000100U) /*!< ADC analog watchdog 2 interrupt */
#define ADC_IER_AWD3IE          ((uint32_t)0x00000200U) /*!< ADC analog watchdog 3 interrupt */
#define ADC_IER_JQOVFIE         ((uint32_t)0x00000400U) /*!< ADC group injected contexts queue overflow interrupt */

/* Legacy defines */
#define ADC_IER_RDY             (ADC_IER_ADRDYIE)
#define ADC_IER_EOSMP           (ADC_IER_EOSMPIE)
#define ADC_IER_EOC             (ADC_IER_EOCIE)
#define ADC_IER_EOS             (ADC_IER_EOSIE)
#define ADC_IER_OVR             (ADC_IER_OVRIE)
#define ADC_IER_JEOC            (ADC_IER_JEOCIE)
#define ADC_IER_JEOS            (ADC_IER_JEOSIE)
#define ADC_IER_AWD1            (ADC_IER_AWD1IE)
#define ADC_IER_AWD2            (ADC_IER_AWD2IE)
#define ADC_IER_AWD3            (ADC_IER_AWD3IE)
#define ADC_IER_JQOVF           (ADC_IER_JQOVFIE)

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN             ((uint32_t)0x00000001U) /*!< ADC enable */
#define ADC_CR_ADDIS            ((uint32_t)0x00000002U) /*!< ADC disable */
#define ADC_CR_ADSTART          ((uint32_t)0x00000004U) /*!< ADC group regular conversion start */
#define ADC_CR_JADSTART         ((uint32_t)0x00000008U) /*!< ADC group injected conversion start */
#define ADC_CR_ADSTP            ((uint32_t)0x00000010U) /*!< ADC group regular conversion stop */
#define ADC_CR_JADSTP           ((uint32_t)0x00000020U) /*!< ADC group injected conversion stop */
#define ADC_CR_ADVREGEN         ((uint32_t)0x30000000U) /*!< ADC voltage regulator enable */
#define ADC_CR_ADVREGEN_0       ((uint32_t)0x10000000U) /*!< ADC ADVREGEN bit 0 */
#define ADC_CR_ADVREGEN_1       ((uint32_t)0x20000000U) /*!< ADC ADVREGEN bit 1 */
#define ADC_CR_ADCALDIF         ((uint32_t)0x40000000U) /*!< ADC differential mode for calibration */
#define ADC_CR_ADCAL            ((uint32_t)0x80000000U) /*!< ADC calibration */

/********************  Bit definition for ADC_CFGR register  ******************/
#define ADC_CFGR_DMAEN          ((uint32_t)0x00000001U) /*!< ADC DMA enable */
#define ADC_CFGR_DMACFG         ((uint32_t)0x00000002U) /*!< ADC DMA configuration */

#define ADC_CFGR_RES            ((uint32_t)0x00000018U) /*!< ADC data resolution */
#define ADC_CFGR_RES_0          ((uint32_t)0x00000008U) /*!< bit 0 */
#define ADC_CFGR_RES_1          ((uint32_t)0x00000010U) /*!< bit 1 */

#define ADC_CFGR_ALIGN          ((uint32_t)0x00000020U) /*!< ADC data alignement */

#define ADC_CFGR_EXTSEL         ((uint32_t)0x000003C0U) /*!< ADC group regular external trigger source */
#define ADC_CFGR_EXTSEL_0       ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_CFGR_EXTSEL_1       ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_CFGR_EXTSEL_2       ((uint32_t)0x00000100U) /*!< bit 2 */
#define ADC_CFGR_EXTSEL_3       ((uint32_t)0x00000200U) /*!< bit 3 */

#define ADC_CFGR_EXTEN          ((uint32_t)0x00000C00U) /*!< ADC group regular external trigger polarity */
#define ADC_CFGR_EXTEN_0        ((uint32_t)0x00000400U) /*!< bit 0 */
#define ADC_CFGR_EXTEN_1        ((uint32_t)0x00000800U) /*!< bit 1 */

#define ADC_CFGR_OVRMOD         ((uint32_t)0x00001000U) /*!< ADC group regular overrun configuration */
#define ADC_CFGR_CONT           ((uint32_t)0x00002000U) /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR_AUTDLY         ((uint32_t)0x00004000U) /*!< ADC low power auto wait */

#define ADC_CFGR_DISCEN         ((uint32_t)0x00010000U) /*!< ADC group regular sequencer discontinuous mode */

#define ADC_CFGR_DISCNUM        ((uint32_t)0x000E0000U) /*!< ADC Discontinuous mode channel count */
#define ADC_CFGR_DISCNUM_0      ((uint32_t)0x00020000U) /*!< bit 0 */
#define ADC_CFGR_DISCNUM_1      ((uint32_t)0x00040000U) /*!< bit 1 */
#define ADC_CFGR_DISCNUM_2      ((uint32_t)0x00080000U) /*!< bit 2 */

#define ADC_CFGR_JDISCEN        ((uint32_t)0x00100000U) /*!< ADC Discontinuous mode on injected channels */
#define ADC_CFGR_JQM            ((uint32_t)0x00200000U) /*!< ADC group injected contexts queue mode */
#define ADC_CFGR_AWD1SGL        ((uint32_t)0x00400000U) /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CFGR_AWD1EN         ((uint32_t)0x00800000U) /*!< ADC analog watchdog 1 enable on scope ADC group regular */
#define ADC_CFGR_JAWD1EN        ((uint32_t)0x01000000U) /*!< ADC analog watchdog 1 enable on scope ADC group injected */
#define ADC_CFGR_JAUTO          ((uint32_t)0x02000000U) /*!< ADC group injected automatic trigger mode */

#define ADC_CFGR_AWD1CH         ((uint32_t)0x7C000000U) /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CFGR_AWD1CH_0       ((uint32_t)0x04000000U) /*!< bit 0 */
#define ADC_CFGR_AWD1CH_1       ((uint32_t)0x08000000U) /*!< bit 1  */
#define ADC_CFGR_AWD1CH_2       ((uint32_t)0x10000000U) /*!< bit 2  */
#define ADC_CFGR_AWD1CH_3       ((uint32_t)0x20000000U) /*!< bit 3  */
#define ADC_CFGR_AWD1CH_4       ((uint32_t)0x40000000U) /*!< bit 4  */

/* Legacy defines */
#define ADC_CFGR_AUTOFF         ((uint32_t)0x00008000U) /*!< ADC low power auto power off */

/********************  Bit definition for ADC_SMPR1 register  *****************/
#define ADC_SMPR1_SMP0          ((uint32_t)0x00000007U) /*!< ADC channel 0 sampling time selection  */
#define ADC_SMPR1_SMP0_0        ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_SMPR1_SMP0_1        ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_SMPR1_SMP0_2        ((uint32_t)0x00000004U) /*!< bit 2 */

#define ADC_SMPR1_SMP1          ((uint32_t)0x00000038U) /*!< ADC channel 1 sampling time selection  */
#define ADC_SMPR1_SMP1_0        ((uint32_t)0x00000008U) /*!< bit 0 */
#define ADC_SMPR1_SMP1_1        ((uint32_t)0x00000010U) /*!< bit 1 */
#define ADC_SMPR1_SMP1_2        ((uint32_t)0x00000020U) /*!< bit 2 */

#define ADC_SMPR1_SMP2          ((uint32_t)0x000001C0U) /*!< ADC channel 2 sampling time selection  */
#define ADC_SMPR1_SMP2_0        ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_SMPR1_SMP2_1        ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_SMPR1_SMP2_2        ((uint32_t)0x00000100U) /*!< bit 2 */

#define ADC_SMPR1_SMP3          ((uint32_t)0x00000E00U) /*!< ADC channel 3 sampling time selection  */
#define ADC_SMPR1_SMP3_0        ((uint32_t)0x00000200U) /*!< bit 0 */
#define ADC_SMPR1_SMP3_1        ((uint32_t)0x00000400U) /*!< bit 1 */
#define ADC_SMPR1_SMP3_2        ((uint32_t)0x00000800U) /*!< bit 2 */

#define ADC_SMPR1_SMP4          ((uint32_t)0x00007000U) /*!< ADC channel 4 sampling time selection  */
#define ADC_SMPR1_SMP4_0        ((uint32_t)0x00001000U) /*!< bit 0 */
#define ADC_SMPR1_SMP4_1        ((uint32_t)0x00002000U) /*!< bit 1 */
#define ADC_SMPR1_SMP4_2        ((uint32_t)0x00004000U) /*!< bit 2 */

#define ADC_SMPR1_SMP5          ((uint32_t)0x00038000U) /*!< ADC channel 5 sampling time selection  */
#define ADC_SMPR1_SMP5_0        ((uint32_t)0x00008000U) /*!< bit 0 */
#define ADC_SMPR1_SMP5_1        ((uint32_t)0x00010000U) /*!< bit 1 */
#define ADC_SMPR1_SMP5_2        ((uint32_t)0x00020000U) /*!< bit 2 */

#define ADC_SMPR1_SMP6          ((uint32_t)0x001C0000U) /*!< ADC channel 6 sampling time selection  */
#define ADC_SMPR1_SMP6_0        ((uint32_t)0x00040000U) /*!< bit 0 */
#define ADC_SMPR1_SMP6_1        ((uint32_t)0x00080000U) /*!< bit 1 */
#define ADC_SMPR1_SMP6_2        ((uint32_t)0x00100000U) /*!< bit 2 */

#define ADC_SMPR1_SMP7          ((uint32_t)0x00E00000U) /*!< ADC channel 7 sampling time selection  */
#define ADC_SMPR1_SMP7_0        ((uint32_t)0x00200000U) /*!< bit 0 */
#define ADC_SMPR1_SMP7_1        ((uint32_t)0x00400000U) /*!< bit 1 */
#define ADC_SMPR1_SMP7_2        ((uint32_t)0x00800000U) /*!< bit 2 */

#define ADC_SMPR1_SMP8          ((uint32_t)0x07000000U) /*!< ADC channel 8 sampling time selection  */
#define ADC_SMPR1_SMP8_0        ((uint32_t)0x01000000U) /*!< bit 0 */
#define ADC_SMPR1_SMP8_1        ((uint32_t)0x02000000U) /*!< bit 1 */
#define ADC_SMPR1_SMP8_2        ((uint32_t)0x04000000U) /*!< bit 2 */

#define ADC_SMPR1_SMP9          ((uint32_t)0x38000000U) /*!< ADC channel 9 sampling time selection  */
#define ADC_SMPR1_SMP9_0        ((uint32_t)0x08000000U) /*!< bit 0 */
#define ADC_SMPR1_SMP9_1        ((uint32_t)0x10000000U) /*!< bit 1 */
#define ADC_SMPR1_SMP9_2        ((uint32_t)0x20000000U) /*!< bit 2 */

/********************  Bit definition for ADC_SMPR2 register  *****************/
#define ADC_SMPR2_SMP10         ((uint32_t)0x00000007U) /*!< ADC channel 10 sampling time selection  */
#define ADC_SMPR2_SMP10_0       ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_SMPR2_SMP10_1       ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_SMPR2_SMP10_2       ((uint32_t)0x00000004U) /*!< bit 2 */

#define ADC_SMPR2_SMP11         ((uint32_t)0x00000038U) /*!< ADC channel 11 sampling time selection  */
#define ADC_SMPR2_SMP11_0       ((uint32_t)0x00000008U) /*!< bit 0 */
#define ADC_SMPR2_SMP11_1       ((uint32_t)0x00000010U) /*!< bit 1 */
#define ADC_SMPR2_SMP11_2       ((uint32_t)0x00000020U) /*!< bit 2 */

#define ADC_SMPR2_SMP12         ((uint32_t)0x000001C0U) /*!< ADC channel 12 sampling time selection  */
#define ADC_SMPR2_SMP12_0       ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_SMPR2_SMP12_1       ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_SMPR2_SMP12_2       ((uint32_t)0x00000100U) /*!< bit 2 */

#define ADC_SMPR2_SMP13         ((uint32_t)0x00000E00U) /*!< ADC channel 13 sampling time selection  */
#define ADC_SMPR2_SMP13_0       ((uint32_t)0x00000200U) /*!< bit 0 */
#define ADC_SMPR2_SMP13_1       ((uint32_t)0x00000400U) /*!< bit 1 */
#define ADC_SMPR2_SMP13_2       ((uint32_t)0x00000800U) /*!< bit 2 */

#define ADC_SMPR2_SMP14         ((uint32_t)0x00007000U) /*!< ADC channel 14 sampling time selection  */
#define ADC_SMPR2_SMP14_0       ((uint32_t)0x00001000U) /*!< bit 0 */
#define ADC_SMPR2_SMP14_1       ((uint32_t)0x00002000U) /*!< bit 1 */
#define ADC_SMPR2_SMP14_2       ((uint32_t)0x00004000U) /*!< bit 2 */

#define ADC_SMPR2_SMP15         ((uint32_t)0x00038000U) /*!< ADC channel 15 sampling time selection  */
#define ADC_SMPR2_SMP15_0       ((uint32_t)0x00008000U) /*!< bit 0 */
#define ADC_SMPR2_SMP15_1       ((uint32_t)0x00010000U) /*!< bit 1 */
#define ADC_SMPR2_SMP15_2       ((uint32_t)0x00020000U) /*!< bit 2 */

#define ADC_SMPR2_SMP16         ((uint32_t)0x001C0000U) /*!< ADC channel 16 sampling time selection  */
#define ADC_SMPR2_SMP16_0       ((uint32_t)0x00040000U) /*!< bit 0 */
#define ADC_SMPR2_SMP16_1       ((uint32_t)0x00080000U) /*!< bit 1 */
#define ADC_SMPR2_SMP16_2       ((uint32_t)0x00100000U) /*!< bit 2 */

#define ADC_SMPR2_SMP17         ((uint32_t)0x00E00000U) /*!< ADC channel 17 sampling time selection  */
#define ADC_SMPR2_SMP17_0       ((uint32_t)0x00200000U) /*!< bit 0 */
#define ADC_SMPR2_SMP17_1       ((uint32_t)0x00400000U) /*!< bit 1 */
#define ADC_SMPR2_SMP17_2       ((uint32_t)0x00800000U) /*!< bit 2 */

#define ADC_SMPR2_SMP18         ((uint32_t)0x07000000U) /*!< ADC channel 18 sampling time selection  */
#define ADC_SMPR2_SMP18_0       ((uint32_t)0x01000000U) /*!< bit 0 */
#define ADC_SMPR2_SMP18_1       ((uint32_t)0x02000000U) /*!< bit 1 */
#define ADC_SMPR2_SMP18_2       ((uint32_t)0x04000000U) /*!< bit 2 */

/********************  Bit definition for ADC_TR1 register  *******************/
#define ADC_TR1_LT1             ((uint32_t)0x00000FFFU) /*!< ADC analog watchdog 1 threshold low */
#define ADC_TR1_LT1_0           ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_TR1_LT1_1           ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_TR1_LT1_2           ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_TR1_LT1_3           ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_TR1_LT1_4           ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_TR1_LT1_5           ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_TR1_LT1_6           ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_TR1_LT1_7           ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_TR1_LT1_8           ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_TR1_LT1_9           ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_TR1_LT1_10          ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_TR1_LT1_11          ((uint32_t)0x00000800U) /*!< bit 11 */

#define ADC_TR1_HT1             ((uint32_t)0x0FFF0000U) /*!< ADC Analog watchdog 1 threshold high */
#define ADC_TR1_HT1_0           ((uint32_t)0x00010000U) /*!< bit 0 */
#define ADC_TR1_HT1_1           ((uint32_t)0x00020000U) /*!< bit 1 */
#define ADC_TR1_HT1_2           ((uint32_t)0x00040000U) /*!< bit 2 */
#define ADC_TR1_HT1_3           ((uint32_t)0x00080000U) /*!< bit 3 */
#define ADC_TR1_HT1_4           ((uint32_t)0x00100000U) /*!< bit 4 */
#define ADC_TR1_HT1_5           ((uint32_t)0x00200000U) /*!< bit 5 */
#define ADC_TR1_HT1_6           ((uint32_t)0x00400000U) /*!< bit 6 */
#define ADC_TR1_HT1_7           ((uint32_t)0x00800000U) /*!< bit 7 */
#define ADC_TR1_HT1_8           ((uint32_t)0x01000000U) /*!< bit 8 */
#define ADC_TR1_HT1_9           ((uint32_t)0x02000000U) /*!< bit 9 */
#define ADC_TR1_HT1_10          ((uint32_t)0x04000000U) /*!< bit 10 */
#define ADC_TR1_HT1_11          ((uint32_t)0x08000000U) /*!< bit 11 */

/********************  Bit definition for ADC_TR2 register  *******************/
#define ADC_TR2_LT2             ((uint32_t)0x000000FFU) /*!< ADC analog watchdog 2 threshold low */
#define ADC_TR2_LT2_0           ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_TR2_LT2_1           ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_TR2_LT2_2           ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_TR2_LT2_3           ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_TR2_LT2_4           ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_TR2_LT2_5           ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_TR2_LT2_6           ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_TR2_LT2_7           ((uint32_t)0x00000080U) /*!< bit 7 */

#define ADC_TR2_HT2             ((uint32_t)0x00FF0000U) /*!< ADC analog watchdog 2 threshold high */
#define ADC_TR2_HT2_0           ((uint32_t)0x00010000U) /*!< bit 0 */
#define ADC_TR2_HT2_1           ((uint32_t)0x00020000U) /*!< bit 1 */
#define ADC_TR2_HT2_2           ((uint32_t)0x00040000U) /*!< bit 2 */
#define ADC_TR2_HT2_3           ((uint32_t)0x00080000U) /*!< bit 3 */
#define ADC_TR2_HT2_4           ((uint32_t)0x00100000U) /*!< bit 4 */
#define ADC_TR2_HT2_5           ((uint32_t)0x00200000U) /*!< bit 5 */
#define ADC_TR2_HT2_6           ((uint32_t)0x00400000U) /*!< bit 6 */
#define ADC_TR2_HT2_7           ((uint32_t)0x00800000U) /*!< bit 7 */

/********************  Bit definition for ADC_TR3 register  *******************/
#define ADC_TR3_LT3             ((uint32_t)0x000000FFU) /*!< ADC analog watchdog 3 threshold low */
#define ADC_TR3_LT3_0           ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_TR3_LT3_1           ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_TR3_LT3_2           ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_TR3_LT3_3           ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_TR3_LT3_4           ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_TR3_LT3_5           ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_TR3_LT3_6           ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_TR3_LT3_7           ((uint32_t)0x00000080U) /*!< bit 7 */

#define ADC_TR3_HT3             ((uint32_t)0x00FF0000U) /*!< ADC analog watchdog 3 threshold high */
#define ADC_TR3_HT3_0           ((uint32_t)0x00010000U) /*!< bit 0 */
#define ADC_TR3_HT3_1           ((uint32_t)0x00020000U) /*!< bit 1 */
#define ADC_TR3_HT3_2           ((uint32_t)0x00040000U) /*!< bit 2 */
#define ADC_TR3_HT3_3           ((uint32_t)0x00080000U) /*!< bit 3 */
#define ADC_TR3_HT3_4           ((uint32_t)0x00100000U) /*!< bit 4 */
#define ADC_TR3_HT3_5           ((uint32_t)0x00200000U) /*!< bit 5 */
#define ADC_TR3_HT3_6           ((uint32_t)0x00400000U) /*!< bit 6 */
#define ADC_TR3_HT3_7           ((uint32_t)0x00800000U) /*!< bit 7 */

/********************  Bit definition for ADC_SQR1 register  ******************/
#define ADC_SQR1_L              ((uint32_t)0x0000000FU) /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_L_0            ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_SQR1_L_1            ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_SQR1_L_2            ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_SQR1_L_3            ((uint32_t)0x00000008U) /*!< bit 3 */

#define ADC_SQR1_SQ1            ((uint32_t)0x000007C0U) /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR1_SQ1_0          ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_SQR1_SQ1_1          ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_SQR1_SQ1_2          ((uint32_t)0x00000100U) /*!< bit 2 */
#define ADC_SQR1_SQ1_3          ((uint32_t)0x00000200U) /*!< bit 3 */
#define ADC_SQR1_SQ1_4          ((uint32_t)0x00000400U) /*!< bit 4 */

#define ADC_SQR1_SQ2            ((uint32_t)0x0001F000U) /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR1_SQ2_0          ((uint32_t)0x00001000U) /*!< bit 0 */
#define ADC_SQR1_SQ2_1          ((uint32_t)0x00002000U) /*!< bit 1 */
#define ADC_SQR1_SQ2_2          ((uint32_t)0x00004000U) /*!< bit 2 */
#define ADC_SQR1_SQ2_3          ((uint32_t)0x00008000U) /*!< bit 3 */
#define ADC_SQR1_SQ2_4          ((uint32_t)0x00010000U) /*!< bit 4 */

#define ADC_SQR1_SQ3            ((uint32_t)0x007C0000U) /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR1_SQ3_0          ((uint32_t)0x00040000U) /*!< bit 0 */
#define ADC_SQR1_SQ3_1          ((uint32_t)0x00080000U) /*!< bit 1 */
#define ADC_SQR1_SQ3_2          ((uint32_t)0x00100000U) /*!< bit 2 */
#define ADC_SQR1_SQ3_3          ((uint32_t)0x00200000U) /*!< bit 3 */
#define ADC_SQR1_SQ3_4          ((uint32_t)0x00400000U) /*!< bit 4 */

#define ADC_SQR1_SQ4            ((uint32_t)0x1F000000U) /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR1_SQ4_0          ((uint32_t)0x01000000U) /*!< bit 0 */
#define ADC_SQR1_SQ4_1          ((uint32_t)0x02000000U) /*!< bit 1 */
#define ADC_SQR1_SQ4_2          ((uint32_t)0x04000000U) /*!< bit 2 */
#define ADC_SQR1_SQ4_3          ((uint32_t)0x08000000U) /*!< bit 3 */
#define ADC_SQR1_SQ4_4          ((uint32_t)0x10000000U) /*!< bit 4 */

/********************  Bit definition for ADC_SQR2 register  ******************/
#define ADC_SQR2_SQ5            ((uint32_t)0x0000001FU) /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR2_SQ5_0          ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_SQR2_SQ5_1          ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_SQR2_SQ5_2          ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_SQR2_SQ5_3          ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_SQR2_SQ5_4          ((uint32_t)0x00000010U) /*!< bit 4 */

#define ADC_SQR2_SQ6            ((uint32_t)0x000007C0U) /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR2_SQ6_0          ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_SQR2_SQ6_1          ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_SQR2_SQ6_2          ((uint32_t)0x00000100U) /*!< bit 2 */
#define ADC_SQR2_SQ6_3          ((uint32_t)0x00000200U) /*!< bit 3 */
#define ADC_SQR2_SQ6_4          ((uint32_t)0x00000400U) /*!< bit 4 */

#define ADC_SQR2_SQ7            ((uint32_t)0x0001F000U) /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR2_SQ7_0          ((uint32_t)0x00001000U) /*!< bit 0 */
#define ADC_SQR2_SQ7_1          ((uint32_t)0x00002000U) /*!< bit 1 */
#define ADC_SQR2_SQ7_2          ((uint32_t)0x00004000U) /*!< bit 2 */
#define ADC_SQR2_SQ7_3          ((uint32_t)0x00008000U) /*!< bit 3 */
#define ADC_SQR2_SQ7_4          ((uint32_t)0x00010000U) /*!< bit 4 */

#define ADC_SQR2_SQ8            ((uint32_t)0x007C0000U) /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR2_SQ8_0          ((uint32_t)0x00040000U) /*!< bit 0 */
#define ADC_SQR2_SQ8_1          ((uint32_t)0x00080000U) /*!< bit 1 */
#define ADC_SQR2_SQ8_2          ((uint32_t)0x00100000U) /*!< bit 2 */
#define ADC_SQR2_SQ8_3          ((uint32_t)0x00200000U) /*!< bit 3 */
#define ADC_SQR2_SQ8_4          ((uint32_t)0x00400000U) /*!< bit 4 */

#define ADC_SQR2_SQ9            ((uint32_t)0x1F000000U) /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR2_SQ9_0          ((uint32_t)0x01000000U) /*!< bit 0 */
#define ADC_SQR2_SQ9_1          ((uint32_t)0x02000000U) /*!< bit 1 */
#define ADC_SQR2_SQ9_2          ((uint32_t)0x04000000U) /*!< bit 2 */
#define ADC_SQR2_SQ9_3          ((uint32_t)0x08000000U) /*!< bit 3 */
#define ADC_SQR2_SQ9_4          ((uint32_t)0x10000000U) /*!< bit 4 */

/********************  Bit definition for ADC_SQR3 register  ******************/
#define ADC_SQR3_SQ10           ((uint32_t)0x0000001FU) /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR3_SQ10_0         ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_SQR3_SQ10_1         ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_SQR3_SQ10_2         ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_SQR3_SQ10_3         ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_SQR3_SQ10_4         ((uint32_t)0x00000010U) /*!< bit 4 */

#define ADC_SQR3_SQ11           ((uint32_t)0x000007C0U) /*!< ADC group regular sequencer rank 11 */
#define ADC_SQR3_SQ11_0         ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_SQR3_SQ11_1         ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_SQR3_SQ11_2         ((uint32_t)0x00000100U) /*!< bit 2 */
#define ADC_SQR3_SQ11_3         ((uint32_t)0x00000200U) /*!< bit 3 */
#define ADC_SQR3_SQ11_4         ((uint32_t)0x00000400U) /*!< bit 4 */

#define ADC_SQR3_SQ12           ((uint32_t)0x0001F000U) /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR3_SQ12_0         ((uint32_t)0x00001000U) /*!< bit 0 */
#define ADC_SQR3_SQ12_1         ((uint32_t)0x00002000U) /*!< bit 1 */
#define ADC_SQR3_SQ12_2         ((uint32_t)0x00004000U) /*!< bit 2 */
#define ADC_SQR3_SQ12_3         ((uint32_t)0x00008000U) /*!< bit 3 */
#define ADC_SQR3_SQ12_4         ((uint32_t)0x00010000U) /*!< bit 4 */

#define ADC_SQR3_SQ13           ((uint32_t)0x007C0000U) /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR3_SQ13_0         ((uint32_t)0x00040000U) /*!< bit 0 */
#define ADC_SQR3_SQ13_1         ((uint32_t)0x00080000U) /*!< bit 1 */
#define ADC_SQR3_SQ13_2         ((uint32_t)0x00100000U) /*!< bit 2 */
#define ADC_SQR3_SQ13_3         ((uint32_t)0x00200000U) /*!< bit 3 */
#define ADC_SQR3_SQ13_4         ((uint32_t)0x00400000U) /*!< bit 4 */

#define ADC_SQR3_SQ14           ((uint32_t)0x1F000000U) /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR3_SQ14_0         ((uint32_t)0x01000000U) /*!< bit 0 */
#define ADC_SQR3_SQ14_1         ((uint32_t)0x02000000U) /*!< bit 1 */
#define ADC_SQR3_SQ14_2         ((uint32_t)0x04000000U) /*!< bit 2 */
#define ADC_SQR3_SQ14_3         ((uint32_t)0x08000000U) /*!< bit 3 */
#define ADC_SQR3_SQ14_4         ((uint32_t)0x10000000U) /*!< bit 4 */

/********************  Bit definition for ADC_SQR4 register  ******************/
#define ADC_SQR4_SQ15           ((uint32_t)0x0000001FU) /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR4_SQ15_0         ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_SQR4_SQ15_1         ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_SQR4_SQ15_2         ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_SQR4_SQ15_3         ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_SQR4_SQ15_4         ((uint32_t)0x00000010U) /*!<5 bit 4 */

#define ADC_SQR4_SQ16           ((uint32_t)0x000007C0U) /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR4_SQ16_0         ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_SQR4_SQ16_1         ((uint32_t)0x00000080U) /*!< bit 1 */
#define ADC_SQR4_SQ16_2         ((uint32_t)0x00000100U) /*!< bit 2 */
#define ADC_SQR4_SQ16_3         ((uint32_t)0x00000200U) /*!< bit 3 */
#define ADC_SQR4_SQ16_4         ((uint32_t)0x00000400U) /*!< bit 4 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_RDATA            ((uint32_t)0x0000FFFFU) /*!< ADC group regular conversion data */
#define ADC_DR_RDATA_0          ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_DR_RDATA_1          ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_DR_RDATA_2          ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_DR_RDATA_3          ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_DR_RDATA_4          ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_DR_RDATA_5          ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_DR_RDATA_6          ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_DR_RDATA_7          ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_DR_RDATA_8          ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_DR_RDATA_9          ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_DR_RDATA_10         ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_DR_RDATA_11         ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_DR_RDATA_12         ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_DR_RDATA_13         ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_DR_RDATA_14         ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_DR_RDATA_15         ((uint32_t)0x00008000U) /*!< bit 15 */

/********************  Bit definition for ADC_JSQR register  ******************/
#define ADC_JSQR_JL             ((uint32_t)0x00000003U) /*!< ADC group injected sequencer scan length */
#define ADC_JSQR_JL_0           ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_JSQR_JL_1           ((uint32_t)0x00000002U) /*!< bit 1 */

#define ADC_JSQR_JEXTSEL        ((uint32_t)0x0000003CU) /*!< ADC group injected external trigger source */
#define ADC_JSQR_JEXTSEL_0      ((uint32_t)0x00000004U) /*!< bit 0 */
#define ADC_JSQR_JEXTSEL_1      ((uint32_t)0x00000008U) /*!< bit 1 */
#define ADC_JSQR_JEXTSEL_2      ((uint32_t)0x00000010U) /*!< bit 2 */
#define ADC_JSQR_JEXTSEL_3      ((uint32_t)0x00000020U) /*!< bit 3 */

#define ADC_JSQR_JEXTEN         ((uint32_t)0x000000C0U) /*!< ADC group injected external trigger polarity */
#define ADC_JSQR_JEXTEN_0       ((uint32_t)0x00000040U) /*!< bit 0 */
#define ADC_JSQR_JEXTEN_1       ((uint32_t)0x00000080U) /*!< bit 1 */

#define ADC_JSQR_JSQ1           ((uint32_t)0x00001F00U) /*!< ADC group injected sequencer rank 1 */
#define ADC_JSQR_JSQ1_0         ((uint32_t)0x00000100U) /*!< bit 0 */
#define ADC_JSQR_JSQ1_1         ((uint32_t)0x00000200U) /*!< bit 1 */
#define ADC_JSQR_JSQ1_2         ((uint32_t)0x00000400U) /*!< bit 2 */
#define ADC_JSQR_JSQ1_3         ((uint32_t)0x00000800U) /*!< bit 3 */
#define ADC_JSQR_JSQ1_4         ((uint32_t)0x00001000U) /*!< bit 4 */

#define ADC_JSQR_JSQ2           ((uint32_t)0x0007C000U) /*!< ADC group injected sequencer rank 2 */
#define ADC_JSQR_JSQ2_0         ((uint32_t)0x00004000U) /*!< bit 0 */
#define ADC_JSQR_JSQ2_1         ((uint32_t)0x00008000U) /*!< bit 1 */
#define ADC_JSQR_JSQ2_2         ((uint32_t)0x00010000U) /*!< bit 2 */
#define ADC_JSQR_JSQ2_3         ((uint32_t)0x00020000U) /*!< bit 3 */
#define ADC_JSQR_JSQ2_4         ((uint32_t)0x00040000U) /*!< bit 4 */

#define ADC_JSQR_JSQ3           ((uint32_t)0x01F00000U) /*!< ADC group injected sequencer rank 3 */
#define ADC_JSQR_JSQ3_0         ((uint32_t)0x00100000U) /*!< bit 0 */
#define ADC_JSQR_JSQ3_1         ((uint32_t)0x00200000U) /*!< bit 1 */
#define ADC_JSQR_JSQ3_2         ((uint32_t)0x00400000U) /*!< bit 2 */
#define ADC_JSQR_JSQ3_3         ((uint32_t)0x00800000U) /*!< bit 3 */
#define ADC_JSQR_JSQ3_4         ((uint32_t)0x01000000U) /*!< bit 4 */

#define ADC_JSQR_JSQ4           ((uint32_t)0x7C000000U) /*!< ADC group injected sequencer rank 4 */
#define ADC_JSQR_JSQ4_0         ((uint32_t)0x04000000U) /*!< bit 0 */
#define ADC_JSQR_JSQ4_1         ((uint32_t)0x08000000U) /*!< bit 1 */
#define ADC_JSQR_JSQ4_2         ((uint32_t)0x10000000U) /*!< bit 2 */
#define ADC_JSQR_JSQ4_3         ((uint32_t)0x20000000U) /*!< bit 3 */
#define ADC_JSQR_JSQ4_4         ((uint32_t)0x40000000U) /*!< bit 4 */


/********************  Bit definition for ADC_OFR1 register  ******************/
#define ADC_OFR1_OFFSET1        ((uint32_t)0x00000FFFU) /*!< ADC offset number 1 offset level */
#define ADC_OFR1_OFFSET1_0      ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_OFR1_OFFSET1_1      ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_OFR1_OFFSET1_2      ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_OFR1_OFFSET1_3      ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_OFR1_OFFSET1_4      ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_OFR1_OFFSET1_5      ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_OFR1_OFFSET1_6      ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_OFR1_OFFSET1_7      ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_OFR1_OFFSET1_8      ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_OFR1_OFFSET1_9      ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_OFR1_OFFSET1_10     ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_OFR1_OFFSET1_11     ((uint32_t)0x00000800U) /*!< bit 11 */

#define ADC_OFR1_OFFSET1_CH     ((uint32_t)0x7C000000U) /*!< ADC offset number 1 channel selection */
#define ADC_OFR1_OFFSET1_CH_0   ((uint32_t)0x04000000U) /*!<  bit 0 */
#define ADC_OFR1_OFFSET1_CH_1   ((uint32_t)0x08000000U) /*!<  bit 1 */
#define ADC_OFR1_OFFSET1_CH_2   ((uint32_t)0x10000000U) /*!<  bit 2 */
#define ADC_OFR1_OFFSET1_CH_3   ((uint32_t)0x20000000U) /*!<  bit 3 */
#define ADC_OFR1_OFFSET1_CH_4   ((uint32_t)0x40000000U) /*!<  bit 4 */

#define ADC_OFR1_OFFSET1_EN     ((uint32_t)0x80000000U) /*!< ADC offset number 1 enable */

/********************  Bit definition for ADC_OFR2 register  ******************/
#define ADC_OFR2_OFFSET2        ((uint32_t)0x00000FFFU) /*!< ADC offset number 2 offset level */
#define ADC_OFR2_OFFSET2_0      ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_OFR2_OFFSET2_1      ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_OFR2_OFFSET2_2      ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_OFR2_OFFSET2_3      ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_OFR2_OFFSET2_4      ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_OFR2_OFFSET2_5      ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_OFR2_OFFSET2_6      ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_OFR2_OFFSET2_7      ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_OFR2_OFFSET2_8      ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_OFR2_OFFSET2_9      ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_OFR2_OFFSET2_10     ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_OFR2_OFFSET2_11     ((uint32_t)0x00000800U) /*!< bit 11 */

#define ADC_OFR2_OFFSET2_CH     ((uint32_t)0x7C000000U) /*!< ADC offset number 2 channel selection */
#define ADC_OFR2_OFFSET2_CH_0   ((uint32_t)0x04000000U) /*!< bit 0 */
#define ADC_OFR2_OFFSET2_CH_1   ((uint32_t)0x08000000U) /*!< bit 1 */
#define ADC_OFR2_OFFSET2_CH_2   ((uint32_t)0x10000000U) /*!< bit 2 */
#define ADC_OFR2_OFFSET2_CH_3   ((uint32_t)0x20000000U) /*!< bit 3 */
#define ADC_OFR2_OFFSET2_CH_4   ((uint32_t)0x40000000U) /*!< bit 4 */

#define ADC_OFR2_OFFSET2_EN     ((uint32_t)0x80000000U) /*!< ADC offset number 2 enable */

/********************  Bit definition for ADC_OFR3 register  ******************/
#define ADC_OFR3_OFFSET3        ((uint32_t)0x00000FFFU) /*!< ADC offset number 3 offset level */
#define ADC_OFR3_OFFSET3_0      ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_OFR3_OFFSET3_1      ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_OFR3_OFFSET3_2      ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_OFR3_OFFSET3_3      ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_OFR3_OFFSET3_4      ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_OFR3_OFFSET3_5      ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_OFR3_OFFSET3_6      ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_OFR3_OFFSET3_7      ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_OFR3_OFFSET3_8      ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_OFR3_OFFSET3_9      ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_OFR3_OFFSET3_10     ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_OFR3_OFFSET3_11     ((uint32_t)0x00000800U) /*!< bit 11 */

#define ADC_OFR3_OFFSET3_CH     ((uint32_t)0x7C000000U) /*!< ADC offset number 3 channel selection */
#define ADC_OFR3_OFFSET3_CH_0   ((uint32_t)0x04000000U) /*!< bit 0 */
#define ADC_OFR3_OFFSET3_CH_1   ((uint32_t)0x08000000U) /*!< bit 1 */
#define ADC_OFR3_OFFSET3_CH_2   ((uint32_t)0x10000000U) /*!< bit 2 */
#define ADC_OFR3_OFFSET3_CH_3   ((uint32_t)0x20000000U) /*!< bit 3 */
#define ADC_OFR3_OFFSET3_CH_4   ((uint32_t)0x40000000U) /*!< bit 4 */

#define ADC_OFR3_OFFSET3_EN     ((uint32_t)0x80000000U) /*!< ADC offset number 3 enable */

/********************  Bit definition for ADC_OFR4 register  ******************/
#define ADC_OFR4_OFFSET4        ((uint32_t)0x00000FFFU) /*!< ADC offset number 4 offset level */
#define ADC_OFR4_OFFSET4_0      ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_OFR4_OFFSET4_1      ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_OFR4_OFFSET4_2      ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_OFR4_OFFSET4_3      ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_OFR4_OFFSET4_4      ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_OFR4_OFFSET4_5      ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_OFR4_OFFSET4_6      ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_OFR4_OFFSET4_7      ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_OFR4_OFFSET4_8      ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_OFR4_OFFSET4_9      ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_OFR4_OFFSET4_10     ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_OFR4_OFFSET4_11     ((uint32_t)0x00000800U) /*!< bit 11 */

#define ADC_OFR4_OFFSET4_CH     ((uint32_t)0x7C000000U) /*!< ADC offset number 4 channel selection */
#define ADC_OFR4_OFFSET4_CH_0   ((uint32_t)0x04000000U) /*!< bit 0 */
#define ADC_OFR4_OFFSET4_CH_1   ((uint32_t)0x08000000U) /*!< bit 1 */
#define ADC_OFR4_OFFSET4_CH_2   ((uint32_t)0x10000000U) /*!< bit 2 */
#define ADC_OFR4_OFFSET4_CH_3   ((uint32_t)0x20000000U) /*!< bit 3 */
#define ADC_OFR4_OFFSET4_CH_4   ((uint32_t)0x40000000U) /*!< bit 4 */

#define ADC_OFR4_OFFSET4_EN     ((uint32_t)0x80000000U) /*!< ADC offset number 4 enable */

/********************  Bit definition for ADC_JDR1 register  ******************/
#define ADC_JDR1_JDATA          ((uint32_t)0x0000FFFFU) /*!< ADC group injected sequencer rank 1 conversion data */
#define ADC_JDR1_JDATA_0        ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_JDR1_JDATA_1        ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_JDR1_JDATA_2        ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_JDR1_JDATA_3        ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_JDR1_JDATA_4        ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_JDR1_JDATA_5        ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_JDR1_JDATA_6        ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_JDR1_JDATA_7        ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_JDR1_JDATA_8        ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_JDR1_JDATA_9        ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_JDR1_JDATA_10       ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_JDR1_JDATA_11       ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_JDR1_JDATA_12       ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_JDR1_JDATA_13       ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_JDR1_JDATA_14       ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_JDR1_JDATA_15       ((uint32_t)0x00008000U) /*!< bit 15 */

/********************  Bit definition for ADC_JDR2 register  ******************/
#define ADC_JDR2_JDATA          ((uint32_t)0x0000FFFFU) /*!< ADC group injected sequencer rank 2 conversion data */
#define ADC_JDR2_JDATA_0        ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_JDR2_JDATA_1        ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_JDR2_JDATA_2        ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_JDR2_JDATA_3        ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_JDR2_JDATA_4        ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_JDR2_JDATA_5        ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_JDR2_JDATA_6        ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_JDR2_JDATA_7        ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_JDR2_JDATA_8        ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_JDR2_JDATA_9        ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_JDR2_JDATA_10       ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_JDR2_JDATA_11       ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_JDR2_JDATA_12       ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_JDR2_JDATA_13       ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_JDR2_JDATA_14       ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_JDR2_JDATA_15       ((uint32_t)0x00008000U) /*!< bit 15 */

/********************  Bit definition for ADC_JDR3 register  ******************/
#define ADC_JDR3_JDATA          ((uint32_t)0x0000FFFFU) /*!< ADC group injected sequencer rank 3 conversion data */
#define ADC_JDR3_JDATA_0        ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_JDR3_JDATA_1        ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_JDR3_JDATA_2        ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_JDR3_JDATA_3        ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_JDR3_JDATA_4        ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_JDR3_JDATA_5        ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_JDR3_JDATA_6        ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_JDR3_JDATA_7        ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_JDR3_JDATA_8        ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_JDR3_JDATA_9        ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_JDR3_JDATA_10       ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_JDR3_JDATA_11       ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_JDR3_JDATA_12       ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_JDR3_JDATA_13       ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_JDR3_JDATA_14       ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_JDR3_JDATA_15       ((uint32_t)0x00008000U) /*!< bit 15 */

/********************  Bit definition for ADC_JDR4 register  ******************/
#define ADC_JDR4_JDATA          ((uint32_t)0x0000FFFFU) /*!< ADC group injected sequencer rank 4 conversion data */
#define ADC_JDR4_JDATA_0        ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_JDR4_JDATA_1        ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_JDR4_JDATA_2        ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_JDR4_JDATA_3        ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_JDR4_JDATA_4        ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_JDR4_JDATA_5        ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_JDR4_JDATA_6        ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_JDR4_JDATA_7        ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_JDR4_JDATA_8        ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_JDR4_JDATA_9        ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_JDR4_JDATA_10       ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_JDR4_JDATA_11       ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_JDR4_JDATA_12       ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_JDR4_JDATA_13       ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_JDR4_JDATA_14       ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_JDR4_JDATA_15       ((uint32_t)0x00008000U) /*!< bit 15 */

/********************  Bit definition for ADC_AWD2CR register  ****************/
#define ADC_AWD2CR_AWD2CH       ((uint32_t)0x0007FFFFU) /*!< ADC analog watchdog 2 monitored channel selection */
#define ADC_AWD2CR_AWD2CH_0     ((uint32_t)0x00000001U) /*!< ADC analog watchdog 2 monitoring channel 0 */
#define ADC_AWD2CR_AWD2CH_1     ((uint32_t)0x00000002U) /*!< ADC analog watchdog 2 monitoring channel 1 */
#define ADC_AWD2CR_AWD2CH_2     ((uint32_t)0x00000004U) /*!< ADC analog watchdog 2 monitoring channel 2 */
#define ADC_AWD2CR_AWD2CH_3     ((uint32_t)0x00000008U) /*!< ADC analog watchdog 2 monitoring channel 3 */
#define ADC_AWD2CR_AWD2CH_4     ((uint32_t)0x00000010U) /*!< ADC analog watchdog 2 monitoring channel 4 */
#define ADC_AWD2CR_AWD2CH_5     ((uint32_t)0x00000020U) /*!< ADC analog watchdog 2 monitoring channel 5 */
#define ADC_AWD2CR_AWD2CH_6     ((uint32_t)0x00000040U) /*!< ADC analog watchdog 2 monitoring channel 6 */
#define ADC_AWD2CR_AWD2CH_7     ((uint32_t)0x00000080U) /*!< ADC analog watchdog 2 monitoring channel 7 */
#define ADC_AWD2CR_AWD2CH_8     ((uint32_t)0x00000100U) /*!< ADC analog watchdog 2 monitoring channel 8 */
#define ADC_AWD2CR_AWD2CH_9     ((uint32_t)0x00000200U) /*!< ADC analog watchdog 2 monitoring channel 9 */
#define ADC_AWD2CR_AWD2CH_10    ((uint32_t)0x00000400U) /*!< ADC analog watchdog 2 monitoring channel 10 */
#define ADC_AWD2CR_AWD2CH_11    ((uint32_t)0x00000800U) /*!< ADC analog watchdog 2 monitoring channel 11 */
#define ADC_AWD2CR_AWD2CH_12    ((uint32_t)0x00001000U) /*!< ADC analog watchdog 2 monitoring channel 12 */
#define ADC_AWD2CR_AWD2CH_13    ((uint32_t)0x00002000U) /*!< ADC analog watchdog 2 monitoring channel 13 */
#define ADC_AWD2CR_AWD2CH_14    ((uint32_t)0x00004000U) /*!< ADC analog watchdog 2 monitoring channel 14 */
#define ADC_AWD2CR_AWD2CH_15    ((uint32_t)0x00008000U) /*!< ADC analog watchdog 2 monitoring channel 15 */
#define ADC_AWD2CR_AWD2CH_16    ((uint32_t)0x00010000U) /*!< ADC analog watchdog 2 monitoring channel 16 */
#define ADC_AWD2CR_AWD2CH_17    ((uint32_t)0x00020000U) /*!< ADC analog watchdog 2 monitoring channel 17 */
#define ADC_AWD2CR_AWD2CH_18    ((uint32_t)0x00040000U) /*!< ADC analog watchdog 2 monitoring channel 18 */

/********************  Bit definition for ADC_AWD3CR register  ****************/
#define ADC_AWD3CR_AWD3CH       ((uint32_t)0x0007FFFFU) /*!< ADC analog watchdog 3 monitored channel selection */
#define ADC_AWD3CR_AWD3CH_0     ((uint32_t)0x00000001U) /*!< ADC analog watchdog 3 monitoring channel 0 */
#define ADC_AWD3CR_AWD3CH_1     ((uint32_t)0x00000002U) /*!< ADC analog watchdog 3 monitoring channel 1 */
#define ADC_AWD3CR_AWD3CH_2     ((uint32_t)0x00000004U) /*!< ADC analog watchdog 3 monitoring channel 2 */
#define ADC_AWD3CR_AWD3CH_3     ((uint32_t)0x00000008U) /*!< ADC analog watchdog 3 monitoring channel 3 */
#define ADC_AWD3CR_AWD3CH_4     ((uint32_t)0x00000010U) /*!< ADC analog watchdog 3 monitoring channel 4 */
#define ADC_AWD3CR_AWD3CH_5     ((uint32_t)0x00000020U) /*!< ADC analog watchdog 3 monitoring channel 5 */
#define ADC_AWD3CR_AWD3CH_6     ((uint32_t)0x00000040U) /*!< ADC analog watchdog 3 monitoring channel 6 */
#define ADC_AWD3CR_AWD3CH_7     ((uint32_t)0x00000080U) /*!< ADC analog watchdog 3 monitoring channel 7 */
#define ADC_AWD3CR_AWD3CH_8     ((uint32_t)0x00000100U) /*!< ADC analog watchdog 3 monitoring channel 8 */
#define ADC_AWD3CR_AWD3CH_9     ((uint32_t)0x00000200U) /*!< ADC analog watchdog 3 monitoring channel 9 */
#define ADC_AWD3CR_AWD3CH_10    ((uint32_t)0x00000400U) /*!< ADC analog watchdog 3 monitoring channel 10 */
#define ADC_AWD3CR_AWD3CH_11    ((uint32_t)0x00000800U) /*!< ADC analog watchdog 3 monitoring channel 11 */
#define ADC_AWD3CR_AWD3CH_12    ((uint32_t)0x00001000U) /*!< ADC analog watchdog 3 monitoring channel 12 */
#define ADC_AWD3CR_AWD3CH_13    ((uint32_t)0x00002000U) /*!< ADC analog watchdog 3 monitoring channel 13 */
#define ADC_AWD3CR_AWD3CH_14    ((uint32_t)0x00004000U) /*!< ADC analog watchdog 3 monitoring channel 14 */
#define ADC_AWD3CR_AWD3CH_15    ((uint32_t)0x00008000U) /*!< ADC analog watchdog 3 monitoring channel 15 */
#define ADC_AWD3CR_AWD3CH_16    ((uint32_t)0x00010000U) /*!< ADC analog watchdog 3 monitoring channel 16 */
#define ADC_AWD3CR_AWD3CH_17    ((uint32_t)0x00020000U) /*!< ADC analog watchdog 3 monitoring channel 17 */
#define ADC_AWD3CR_AWD3CH_18    ((uint32_t)0x00040000U) /*!< ADC analog watchdog 3 monitoring channel 18 */

/********************  Bit definition for ADC_DIFSEL register  ****************/
#define ADC_DIFSEL_DIFSEL       ((uint32_t)0x0007FFFFU) /*!< ADC channel differential or single-ended mode */
#define ADC_DIFSEL_DIFSEL_0     ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_DIFSEL_DIFSEL_1     ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_DIFSEL_DIFSEL_2     ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_DIFSEL_DIFSEL_3     ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_DIFSEL_DIFSEL_4     ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_DIFSEL_DIFSEL_5     ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_DIFSEL_DIFSEL_6     ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_DIFSEL_DIFSEL_7     ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_DIFSEL_DIFSEL_8     ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_DIFSEL_DIFSEL_9     ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_DIFSEL_DIFSEL_10    ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_DIFSEL_DIFSEL_11    ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_DIFSEL_DIFSEL_12    ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_DIFSEL_DIFSEL_13    ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_DIFSEL_DIFSEL_14    ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_DIFSEL_DIFSEL_15    ((uint32_t)0x00008000U) /*!< bit 15 */
#define ADC_DIFSEL_DIFSEL_16    ((uint32_t)0x00010000U) /*!< bit 16 */
#define ADC_DIFSEL_DIFSEL_17    ((uint32_t)0x00020000U) /*!< bit 17 */
#define ADC_DIFSEL_DIFSEL_18    ((uint32_t)0x00040000U) /*!< bit 18 */

/********************  Bit definition for ADC_CALFACT register  ***************/
#define ADC_CALFACT_CALFACT_S   ((uint32_t)0x0000007FU) /*!< ADC calibration factor in single-ended mode */
#define ADC_CALFACT_CALFACT_S_0 ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_CALFACT_CALFACT_S_1 ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_CALFACT_CALFACT_S_2 ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_CALFACT_CALFACT_S_3 ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_CALFACT_CALFACT_S_4 ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_CALFACT_CALFACT_S_5 ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_CALFACT_CALFACT_S_6 ((uint32_t)0x00000040U) /*!< bit 6 */

#define ADC_CALFACT_CALFACT_D   ((uint32_t)0x007F0000U) /*!< ADC calibration factor in differential mode */
#define ADC_CALFACT_CALFACT_D_0 ((uint32_t)0x00010000U) /*!< bit 0 */
#define ADC_CALFACT_CALFACT_D_1 ((uint32_t)0x00020000U) /*!< bit 1 */
#define ADC_CALFACT_CALFACT_D_2 ((uint32_t)0x00040000U) /*!< bit 2 */
#define ADC_CALFACT_CALFACT_D_3 ((uint32_t)0x00080000U) /*!< bit 3 */
#define ADC_CALFACT_CALFACT_D_4 ((uint32_t)0x00100000U) /*!< bit 4 */
#define ADC_CALFACT_CALFACT_D_5 ((uint32_t)0x00200000U) /*!< bit 5 */
#define ADC_CALFACT_CALFACT_D_6 ((uint32_t)0x00400000U) /*!< bit 6 */

/*************************  ADC Common registers  *****************************/
/***************  Bit definition for ADC12_COMMON_CSR register  ***************/
#define ADC12_CSR_ADRDY_MST         ((uint32_t)0x00000001U) /*!< Master ADC ready */
#define ADC12_CSR_ADRDY_EOSMP_MST   ((uint32_t)0x00000002U) /*!< End of sampling phase flag of the master ADC */
#define ADC12_CSR_ADRDY_EOC_MST     ((uint32_t)0x00000004U) /*!< End of regular conversion of the master ADC */
#define ADC12_CSR_ADRDY_EOS_MST     ((uint32_t)0x00000008U) /*!< End of regular sequence flag of the master ADC */
#define ADC12_CSR_ADRDY_OVR_MST     ((uint32_t)0x00000010U) /*!< Overrun flag of the master ADC */
#define ADC12_CSR_ADRDY_JEOC_MST    ((uint32_t)0x00000020U) /*!< End of injected conversion of the master ADC */
#define ADC12_CSR_ADRDY_JEOS_MST    ((uint32_t)0x00000040U) /*!< End of injected sequence flag of the master ADC */
#define ADC12_CSR_AWD1_MST          ((uint32_t)0x00000080U) /*!< Analog watchdog 1 flag of the master ADC */
#define ADC12_CSR_AWD2_MST          ((uint32_t)0x00000100U) /*!< Analog watchdog 2 flag of the master ADC */
#define ADC12_CSR_AWD3_MST          ((uint32_t)0x00000200U) /*!< Analog watchdog 3 flag of the master ADC */
#define ADC12_CSR_JQOVF_MST         ((uint32_t)0x00000400U) /*!< Injected context queue overflow flag of the master ADC */
#define ADC12_CSR_ADRDY_SLV         ((uint32_t)0x00010000U) /*!< Slave ADC ready */
#define ADC12_CSR_ADRDY_EOSMP_SLV   ((uint32_t)0x00020000U) /*!< End of sampling phase flag of the slave ADC */
#define ADC12_CSR_ADRDY_EOC_SLV     ((uint32_t)0x00040000U) /*!< End of regular conversion of the slave ADC */
#define ADC12_CSR_ADRDY_EOS_SLV     ((uint32_t)0x00080000U) /*!< End of regular sequence flag of the slave ADC */
#define ADC12_CSR_ADRDY_OVR_SLV     ((uint32_t)0x00100000U) /*!< Overrun flag of the slave ADC */
#define ADC12_CSR_ADRDY_JEOC_SLV    ((uint32_t)0x00200000U) /*!< End of injected conversion of the slave ADC */
#define ADC12_CSR_ADRDY_JEOS_SLV    ((uint32_t)0x00400000U) /*!< End of injected sequence flag of the slave ADC */
#define ADC12_CSR_AWD1_SLV          ((uint32_t)0x00800000U) /*!< Analog watchdog 1 flag of the slave ADC */
#define ADC12_CSR_AWD2_SLV          ((uint32_t)0x01000000U) /*!< Analog watchdog 2 flag of the slave ADC */
#define ADC12_CSR_AWD3_SLV          ((uint32_t)0x02000000U) /*!< Analog watchdog 3 flag of the slave ADC */
#define ADC12_CSR_JQOVF_SLV         ((uint32_t)0x04000000U) /*!< Injected context queue overflow flag of the slave ADC */

/***************  Bit definition for ADC34_COMMON_CSR register  ***************/
#define ADC34_CSR_ADRDY_MST         ((uint32_t)0x00000001U) /*!< Master ADC ready */
#define ADC34_CSR_ADRDY_EOSMP_MST   ((uint32_t)0x00000002U) /*!< End of sampling phase flag of the master ADC */
#define ADC34_CSR_ADRDY_EOC_MST     ((uint32_t)0x00000004U) /*!< End of regular conversion of the master ADC */
#define ADC34_CSR_ADRDY_EOS_MST     ((uint32_t)0x00000008U) /*!< End of regular sequence flag of the master ADC */
#define ADC34_CSR_ADRDY_OVR_MST     ((uint32_t)0x00000010U) /*!< Overrun flag of the master ADC */
#define ADC34_CSR_ADRDY_JEOC_MST    ((uint32_t)0x00000020U) /*!< End of injected conversion of the master ADC */
#define ADC34_CSR_ADRDY_JEOS_MST    ((uint32_t)0x00000040U) /*!< End of injected sequence flag of the master ADC */
#define ADC34_CSR_AWD1_MST          ((uint32_t)0x00000080U) /*!< Analog watchdog 1 flag of the master ADC */
#define ADC34_CSR_AWD2_MST          ((uint32_t)0x00000100U) /*!< Analog watchdog 2 flag of the master ADC */
#define ADC34_CSR_AWD3_MST          ((uint32_t)0x00000200U) /*!< Analog watchdog 3 flag of the master ADC */
#define ADC34_CSR_JQOVF_MST         ((uint32_t)0x00000400U) /*!< Injected context queue overflow flag of the master ADC */
#define ADC34_CSR_ADRDY_SLV         ((uint32_t)0x00010000U) /*!< Slave ADC ready */
#define ADC34_CSR_ADRDY_EOSMP_SLV   ((uint32_t)0x00020000U) /*!< End of sampling phase flag of the slave ADC */
#define ADC34_CSR_ADRDY_EOC_SLV     ((uint32_t)0x00040000U) /*!< End of regular conversion of the slave ADC */
#define ADC34_CSR_ADRDY_EOS_SLV     ((uint32_t)0x00080000U) /*!< End of regular sequence flag of the slave ADC */
#define ADC12_CSR_ADRDY_OVR_SLV     ((uint32_t)0x00100000U) /*!< Overrun flag of the slave ADC */
#define ADC34_CSR_ADRDY_JEOC_SLV    ((uint32_t)0x00200000U) /*!< End of injected conversion of the slave ADC */
#define ADC34_CSR_ADRDY_JEOS_SLV    ((uint32_t)0x00400000U) /*!< End of injected sequence flag of the slave ADC */
#define ADC34_CSR_AWD1_SLV          ((uint32_t)0x00800000U) /*!< Analog watchdog 1 flag of the slave ADC */
#define ADC34_CSR_AWD2_SLV          ((uint32_t)0x01000000U) /*!< Analog watchdog 2 flag of the slave ADC */
#define ADC34_CSR_AWD3_SLV          ((uint32_t)0x02000000U) /*!< Analog watchdog 3 flag of the slave ADC */
#define ADC34_CSR_JQOVF_SLV         ((uint32_t)0x04000000U) /*!< Injected context queue overflow flag of the slave ADC */

/***************  Bit definition for ADC12_COMMON_CCR register  ***************/
#define ADC12_CCR_MULTI             ((uint32_t)0x0000001FU) /*!< Multi ADC mode selection */
#define ADC12_CCR_MULTI_0           ((uint32_t)0x00000001U) /*!< MULTI bit 0 */
#define ADC12_CCR_MULTI_1           ((uint32_t)0x00000002U) /*!< MULTI bit 1 */
#define ADC12_CCR_MULTI_2           ((uint32_t)0x00000004U) /*!< MULTI bit 2 */
#define ADC12_CCR_MULTI_3           ((uint32_t)0x00000008U) /*!< MULTI bit 3 */
#define ADC12_CCR_MULTI_4           ((uint32_t)0x00000010U) /*!< MULTI bit 4 */
#define ADC12_CCR_DELAY             ((uint32_t)0x00000F00U) /*!< Delay between 2 sampling phases */
#define ADC12_CCR_DELAY_0           ((uint32_t)0x00000100U) /*!< DELAY bit 0 */
#define ADC12_CCR_DELAY_1           ((uint32_t)0x00000200U) /*!< DELAY bit 1 */
#define ADC12_CCR_DELAY_2           ((uint32_t)0x00000400U) /*!< DELAY bit 2 */
#define ADC12_CCR_DELAY_3           ((uint32_t)0x00000800U) /*!< DELAY bit 3 */
#define ADC12_CCR_DMACFG            ((uint32_t)0x00002000U) /*!< DMA configuration for multi-ADC mode */
#define ADC12_CCR_MDMA              ((uint32_t)0x0000C000U) /*!< DMA mode for multi-ADC mode */
#define ADC12_CCR_MDMA_0            ((uint32_t)0x00004000U) /*!< MDMA bit 0 */
#define ADC12_CCR_MDMA_1            ((uint32_t)0x00008000U) /*!< MDMA bit 1 */
#define ADC12_CCR_CKMODE            ((uint32_t)0x00030000U) /*!< ADC clock mode */
#define ADC12_CCR_CKMODE_0          ((uint32_t)0x00010000U) /*!< CKMODE bit 0 */
#define ADC12_CCR_CKMODE_1          ((uint32_t)0x00020000U) /*!< CKMODE bit 1 */
#define ADC12_CCR_VREFEN            ((uint32_t)0x00400000U) /*!< VREFINT enable */
#define ADC12_CCR_TSEN              ((uint32_t)0x00800000U) /*!< Temperature sensor enable */
#define ADC12_CCR_VBATEN            ((uint32_t)0x01000000U) /*!< VBAT enable */

/***************  Bit definition for ADC34_COMMON_CCR register  ***************/
#define ADC34_CCR_MULTI             ((uint32_t)0x0000001FU) /*!< Multi ADC mode selection */
#define ADC34_CCR_MULTI_0           ((uint32_t)0x00000001U) /*!< MULTI bit 0 */
#define ADC34_CCR_MULTI_1           ((uint32_t)0x00000002U) /*!< MULTI bit 1 */
#define ADC34_CCR_MULTI_2           ((uint32_t)0x00000004U) /*!< MULTI bit 2 */
#define ADC34_CCR_MULTI_3           ((uint32_t)0x00000008U) /*!< MULTI bit 3 */
#define ADC34_CCR_MULTI_4           ((uint32_t)0x00000010U) /*!< MULTI bit 4 */

#define ADC34_CCR_DELAY             ((uint32_t)0x00000F00U) /*!< Delay between 2 sampling phases */
#define ADC34_CCR_DELAY_0           ((uint32_t)0x00000100U) /*!< DELAY bit 0 */
#define ADC34_CCR_DELAY_1           ((uint32_t)0x00000200U) /*!< DELAY bit 1 */
#define ADC34_CCR_DELAY_2           ((uint32_t)0x00000400U) /*!< DELAY bit 2 */
#define ADC34_CCR_DELAY_3           ((uint32_t)0x00000800U) /*!< DELAY bit 3 */

#define ADC34_CCR_DMACFG            ((uint32_t)0x00002000U) /*!< DMA configuration for multi-ADC mode */
#define ADC34_CCR_MDMA              ((uint32_t)0x0000C000U) /*!< DMA mode for multi-ADC mode */
#define ADC34_CCR_MDMA_0            ((uint32_t)0x00004000U) /*!< MDMA bit 0 */
#define ADC34_CCR_MDMA_1            ((uint32_t)0x00008000U) /*!< MDMA bit 1 */

#define ADC34_CCR_CKMODE            ((uint32_t)0x00030000U) /*!< ADC clock mode */
#define ADC34_CCR_CKMODE_0          ((uint32_t)0x00010000U) /*!< CKMODE bit 0 */
#define ADC34_CCR_CKMODE_1          ((uint32_t)0x00020000U) /*!< CKMODE bit 1 */

#define ADC34_CCR_VREFEN            ((uint32_t)0x00400000U) /*!< VREFINT enable */
#define ADC34_CCR_TSEN              ((uint32_t)0x00800000U) /*!< Temperature sensor enable */
#define ADC34_CCR_VBATEN            ((uint32_t)0x01000000U) /*!< VBAT enable */

/***************  Bit definition for ADC12_COMMON_CDR register  ***************/
#define ADC12_CDR_RDATA_MST         ((uint32_t)0x0000FFFFU) /*!< Regular Data of the master ADC */
#define ADC12_CDR_RDATA_MST_0       ((uint32_t)0x00000001U) /*!< RDATA_MST bit 0 */
#define ADC12_CDR_RDATA_MST_1       ((uint32_t)0x00000002U) /*!< RDATA_MST bit 1 */
#define ADC12_CDR_RDATA_MST_2       ((uint32_t)0x00000004U) /*!< RDATA_MST bit 2 */
#define ADC12_CDR_RDATA_MST_3       ((uint32_t)0x00000008U) /*!< RDATA_MST bit 3 */
#define ADC12_CDR_RDATA_MST_4       ((uint32_t)0x00000010U) /*!< RDATA_MST bit 4 */
#define ADC12_CDR_RDATA_MST_5       ((uint32_t)0x00000020U) /*!< RDATA_MST bit 5 */
#define ADC12_CDR_RDATA_MST_6       ((uint32_t)0x00000040U) /*!< RDATA_MST bit 6 */
#define ADC12_CDR_RDATA_MST_7       ((uint32_t)0x00000080U) /*!< RDATA_MST bit 7 */
#define ADC12_CDR_RDATA_MST_8       ((uint32_t)0x00000100U) /*!< RDATA_MST bit 8 */
#define ADC12_CDR_RDATA_MST_9       ((uint32_t)0x00000200U) /*!< RDATA_MST bit 9 */
#define ADC12_CDR_RDATA_MST_10      ((uint32_t)0x00000400U) /*!< RDATA_MST bit 10 */
#define ADC12_CDR_RDATA_MST_11      ((uint32_t)0x00000800U) /*!< RDATA_MST bit 11 */
#define ADC12_CDR_RDATA_MST_12      ((uint32_t)0x00001000U) /*!< RDATA_MST bit 12 */
#define ADC12_CDR_RDATA_MST_13      ((uint32_t)0x00002000U) /*!< RDATA_MST bit 13 */
#define ADC12_CDR_RDATA_MST_14      ((uint32_t)0x00004000U) /*!< RDATA_MST bit 14 */
#define ADC12_CDR_RDATA_MST_15      ((uint32_t)0x00008000U) /*!< RDATA_MST bit 15 */

#define ADC12_CDR_RDATA_SLV         ((uint32_t)0xFFFF0000U) /*!< Regular Data of the master ADC */
#define ADC12_CDR_RDATA_SLV_0       ((uint32_t)0x00010000U) /*!< RDATA_SLV bit 0 */
#define ADC12_CDR_RDATA_SLV_1       ((uint32_t)0x00020000U) /*!< RDATA_SLV bit 1 */
#define ADC12_CDR_RDATA_SLV_2       ((uint32_t)0x00040000U) /*!< RDATA_SLV bit 2 */
#define ADC12_CDR_RDATA_SLV_3       ((uint32_t)0x00080000U) /*!< RDATA_SLV bit 3 */
#define ADC12_CDR_RDATA_SLV_4       ((uint32_t)0x00100000U) /*!< RDATA_SLV bit 4 */
#define ADC12_CDR_RDATA_SLV_5       ((uint32_t)0x00200000U) /*!< RDATA_SLV bit 5 */
#define ADC12_CDR_RDATA_SLV_6       ((uint32_t)0x00400000U) /*!< RDATA_SLV bit 6 */
#define ADC12_CDR_RDATA_SLV_7       ((uint32_t)0x00800000U) /*!< RDATA_SLV bit 7 */
#define ADC12_CDR_RDATA_SLV_8       ((uint32_t)0x01000000U) /*!< RDATA_SLV bit 8 */
#define ADC12_CDR_RDATA_SLV_9       ((uint32_t)0x02000000U) /*!< RDATA_SLV bit 9 */
#define ADC12_CDR_RDATA_SLV_10      ((uint32_t)0x04000000U) /*!< RDATA_SLV bit 10 */
#define ADC12_CDR_RDATA_SLV_11      ((uint32_t)0x08000000U) /*!< RDATA_SLV bit 11 */
#define ADC12_CDR_RDATA_SLV_12      ((uint32_t)0x10000000U) /*!< RDATA_SLV bit 12 */
#define ADC12_CDR_RDATA_SLV_13      ((uint32_t)0x20000000U) /*!< RDATA_SLV bit 13 */
#define ADC12_CDR_RDATA_SLV_14      ((uint32_t)0x40000000U) /*!< RDATA_SLV bit 14 */
#define ADC12_CDR_RDATA_SLV_15      ((uint32_t)0x80000000U) /*!< RDATA_SLV bit 15 */

/***************  Bit definition for ADC34_COMMON_CDR register  ***************/
#define ADC34_CDR_RDATA_MST         ((uint32_t)0x0000FFFFU) /*!< Regular Data of the master ADC */
#define ADC34_CDR_RDATA_MST_0       ((uint32_t)0x00000001U) /*!< RDATA_MST bit 0 */
#define ADC34_CDR_RDATA_MST_1       ((uint32_t)0x00000002U) /*!< RDATA_MST bit 1 */
#define ADC34_CDR_RDATA_MST_2       ((uint32_t)0x00000004U) /*!< RDATA_MST bit 2 */
#define ADC34_CDR_RDATA_MST_3       ((uint32_t)0x00000008U) /*!< RDATA_MST bit 3 */
#define ADC34_CDR_RDATA_MST_4       ((uint32_t)0x00000010U) /*!< RDATA_MST bit 4 */
#define ADC34_CDR_RDATA_MST_5       ((uint32_t)0x00000020U) /*!< RDATA_MST bit 5 */
#define ADC34_CDR_RDATA_MST_6       ((uint32_t)0x00000040U) /*!< RDATA_MST bit 6 */
#define ADC34_CDR_RDATA_MST_7       ((uint32_t)0x00000080U) /*!< RDATA_MST bit 7 */
#define ADC34_CDR_RDATA_MST_8       ((uint32_t)0x00000100U) /*!< RDATA_MST bit 8 */
#define ADC34_CDR_RDATA_MST_9       ((uint32_t)0x00000200U) /*!< RDATA_MST bit 9 */
#define ADC34_CDR_RDATA_MST_10      ((uint32_t)0x00000400U) /*!< RDATA_MST bit 10 */
#define ADC34_CDR_RDATA_MST_11      ((uint32_t)0x00000800U) /*!< RDATA_MST bit 11 */
#define ADC34_CDR_RDATA_MST_12      ((uint32_t)0x00001000U) /*!< RDATA_MST bit 12 */
#define ADC34_CDR_RDATA_MST_13      ((uint32_t)0x00002000U) /*!< RDATA_MST bit 13 */
#define ADC34_CDR_RDATA_MST_14      ((uint32_t)0x00004000U) /*!< RDATA_MST bit 14 */
#define ADC34_CDR_RDATA_MST_15      ((uint32_t)0x00008000U) /*!< RDATA_MST bit 15 */

#define ADC34_CDR_RDATA_SLV         ((uint32_t)0xFFFF0000U) /*!< Regular Data of the master ADC */
#define ADC34_CDR_RDATA_SLV_0       ((uint32_t)0x00010000U) /*!< RDATA_SLV bit 0 */
#define ADC34_CDR_RDATA_SLV_1       ((uint32_t)0x00020000U) /*!< RDATA_SLV bit 1 */
#define ADC34_CDR_RDATA_SLV_2       ((uint32_t)0x00040000U) /*!< RDATA_SLV bit 2 */
#define ADC34_CDR_RDATA_SLV_3       ((uint32_t)0x00080000U) /*!< RDATA_SLV bit 3 */
#define ADC34_CDR_RDATA_SLV_4       ((uint32_t)0x00100000U) /*!< RDATA_SLV bit 4 */
#define ADC34_CDR_RDATA_SLV_5       ((uint32_t)0x00200000U) /*!< RDATA_SLV bit 5 */
#define ADC34_CDR_RDATA_SLV_6       ((uint32_t)0x00400000U) /*!< RDATA_SLV bit 6 */
#define ADC34_CDR_RDATA_SLV_7       ((uint32_t)0x00800000U) /*!< RDATA_SLV bit 7 */
#define ADC34_CDR_RDATA_SLV_8       ((uint32_t)0x01000000U) /*!< RDATA_SLV bit 8 */
#define ADC34_CDR_RDATA_SLV_9       ((uint32_t)0x02000000U) /*!< RDATA_SLV bit 9 */
#define ADC34_CDR_RDATA_SLV_10      ((uint32_t)0x04000000U) /*!< RDATA_SLV bit 10 */
#define ADC34_CDR_RDATA_SLV_11      ((uint32_t)0x08000000U) /*!< RDATA_SLV bit 11 */
#define ADC34_CDR_RDATA_SLV_12      ((uint32_t)0x10000000U) /*!< RDATA_SLV bit 12 */
#define ADC34_CDR_RDATA_SLV_13      ((uint32_t)0x20000000U) /*!< RDATA_SLV bit 13 */
#define ADC34_CDR_RDATA_SLV_14      ((uint32_t)0x40000000U) /*!< RDATA_SLV bit 14 */
#define ADC34_CDR_RDATA_SLV_15      ((uint32_t)0x80000000U) /*!< RDATA_SLV bit 15 */

/********************  Bit definition for ADC_CSR register  *******************/
#define ADC_CSR_ADRDY_MST       ((uint32_t)0x00000001U) /*!< ADC multimode master ready flag */
#define ADC_CSR_EOSMP_MST       ((uint32_t)0x00000002U) /*!< ADC multimode master group regular end of sampling flag */
#define ADC_CSR_EOC_MST         ((uint32_t)0x00000004U) /*!< ADC multimode master group regular end of unitary conversion flag */
#define ADC_CSR_EOS_MST         ((uint32_t)0x00000008U) /*!< ADC multimode master group regular end of sequence conversions flag */
#define ADC_CSR_OVR_MST         ((uint32_t)0x00000010U) /*!< ADC multimode master group regular overrun flag */
#define ADC_CSR_JEOC_MST        ((uint32_t)0x00000020U) /*!< ADC multimode master group injected end of unitary conversion flag */
#define ADC_CSR_JEOS_MST        ((uint32_t)0x00000040U) /*!< ADC multimode master group injected end of sequence conversions flag */
#define ADC_CSR_AWD1_MST        ((uint32_t)0x00000080U) /*!< ADC multimode master analog watchdog 1 flag */
#define ADC_CSR_AWD2_MST        ((uint32_t)0x00000100U) /*!< ADC multimode master analog watchdog 2 flag */
#define ADC_CSR_AWD3_MST        ((uint32_t)0x00000200U) /*!< ADC multimode master analog watchdog 3 flag */
#define ADC_CSR_JQOVF_MST       ((uint32_t)0x00000400U) /*!< ADC multimode master group injected contexts queue overflow flag */

#define ADC_CSR_ADRDY_SLV       ((uint32_t)0x00010000U) /*!< ADC multimode slave ready flag */
#define ADC_CSR_EOSMP_SLV       ((uint32_t)0x00020000U) /*!< ADC multimode slave group regular end of sampling flag */
#define ADC_CSR_EOC_SLV         ((uint32_t)0x00040000U) /*!< ADC multimode slave group regular end of unitary conversion flag */
#define ADC_CSR_EOS_SLV         ((uint32_t)0x00080000U) /*!< ADC multimode slave group regular end of sequence conversions flag */
#define ADC_CSR_OVR_SLV         ((uint32_t)0x00100000U) /*!< ADC multimode slave group regular overrun flag */
#define ADC_CSR_JEOC_SLV        ((uint32_t)0x00200000U) /*!< ADC multimode slave group injected end of unitary conversion flag */
#define ADC_CSR_JEOS_SLV        ((uint32_t)0x00400000U) /*!< ADC multimode slave group injected end of sequence conversions flag */
#define ADC_CSR_AWD1_SLV        ((uint32_t)0x00800000U) /*!< ADC multimode slave analog watchdog 1 flag */
#define ADC_CSR_AWD2_SLV        ((uint32_t)0x01000000U) /*!< ADC multimode slave analog watchdog 2 flag */
#define ADC_CSR_AWD3_SLV        ((uint32_t)0x02000000U) /*!< ADC multimode slave analog watchdog 3 flag */
#define ADC_CSR_JQOVF_SLV       ((uint32_t)0x04000000U) /*!< ADC multimode slave group injected contexts queue overflow flag */

/* Legacy defines */
#define ADC_CSR_ADRDY_EOSMP_MST   ADC_CSR_EOSMP_MST
#define ADC_CSR_ADRDY_EOC_MST     ADC_CSR_EOC_MST
#define ADC_CSR_ADRDY_EOS_MST     ADC_CSR_EOS_MST
#define ADC_CSR_ADRDY_OVR_MST     ADC_CSR_OVR_MST
#define ADC_CSR_ADRDY_JEOC_MST    ADC_CSR_JEOC_MST
#define ADC_CSR_ADRDY_JEOS_MST    ADC_CSR_JEOS_MST

#define ADC_CSR_ADRDY_EOSMP_SLV   ADC_CSR_EOSMP_SLV
#define ADC_CSR_ADRDY_EOC_SLV     ADC_CSR_EOC_SLV
#define ADC_CSR_ADRDY_EOS_SLV     ADC_CSR_EOS_SLV
#define ADC_CSR_ADRDY_OVR_SLV     ADC_CSR_OVR_SLV
#define ADC_CSR_ADRDY_JEOC_SLV    ADC_CSR_JEOC_SLV
#define ADC_CSR_ADRDY_JEOS_SLV    ADC_CSR_JEOS_SLV

/********************  Bit definition for ADC_CCR register  *******************/
#define ADC_CCR_DUAL            ((uint32_t)0x0000001FU) /*!< ADC multimode mode selection */
#define ADC_CCR_DUAL_0          ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_CCR_DUAL_1          ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_CCR_DUAL_2          ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_CCR_DUAL_3          ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_CCR_DUAL_4          ((uint32_t)0x00000010U) /*!< bit 4 */

#define ADC_CCR_DELAY           ((uint32_t)0x00000F00U) /*!< ADC multimode delay between 2 sampling phases */
#define ADC_CCR_DELAY_0         ((uint32_t)0x00000100U) /*!< bit 0 */
#define ADC_CCR_DELAY_1         ((uint32_t)0x00000200U) /*!< bit 1 */
#define ADC_CCR_DELAY_2         ((uint32_t)0x00000400U) /*!< bit 2 */
#define ADC_CCR_DELAY_3         ((uint32_t)0x00000800U) /*!< bit 3 */

#define ADC_CCR_DMACFG          ((uint32_t)0x00002000U) /*!< ADC multimode DMA transfer configuration */

#define ADC_CCR_MDMA            ((uint32_t)0x0000C000U) /*!< ADC multimode DMA transfer enable */
#define ADC_CCR_MDMA_0          ((uint32_t)0x00004000U) /*!< bit 0 */
#define ADC_CCR_MDMA_1          ((uint32_t)0x00008000U) /*!< bit 1 */

#define ADC_CCR_CKMODE          ((uint32_t)0x00030000U) /*!< ADC common clock source and prescaler (prescaler only for clock source synchronous) */
#define ADC_CCR_CKMODE_0        ((uint32_t)0x00010000U) /*!< bit 0 */
#define ADC_CCR_CKMODE_1        ((uint32_t)0x00020000U) /*!< bit 1 */

#define ADC_CCR_VREFEN          ((uint32_t)0x00400000U) /*!< ADC internal path to VrefInt enable */
#define ADC_CCR_TSEN            ((uint32_t)0x00800000U) /*!< ADC internal path to temperature sensor enable */
#define ADC_CCR_VBATEN          ((uint32_t)0x01000000U) /*!< ADC internal path to battery voltage enable */

/* Legacy defines */
#define ADC_CCR_MULTI           (ADC_CCR_DUAL)
#define ADC_CCR_MULTI_0         (ADC_CCR_DUAL_0)
#define ADC_CCR_MULTI_1         (ADC_CCR_DUAL_1)
#define ADC_CCR_MULTI_2         (ADC_CCR_DUAL_2)
#define ADC_CCR_MULTI_3         (ADC_CCR_DUAL_3)
#define ADC_CCR_MULTI_4         (ADC_CCR_DUAL_4)

/********************  Bit definition for ADC_CDR register  *******************/
#define ADC_CDR_RDATA_MST       ((uint32_t)0x0000FFFFU) /*!< ADC multimode master group regular conversion data */
#define ADC_CDR_RDATA_MST_0     ((uint32_t)0x00000001U) /*!< bit 0 */
#define ADC_CDR_RDATA_MST_1     ((uint32_t)0x00000002U) /*!< bit 1 */
#define ADC_CDR_RDATA_MST_2     ((uint32_t)0x00000004U) /*!< bit 2 */
#define ADC_CDR_RDATA_MST_3     ((uint32_t)0x00000008U) /*!< bit 3 */
#define ADC_CDR_RDATA_MST_4     ((uint32_t)0x00000010U) /*!< bit 4 */
#define ADC_CDR_RDATA_MST_5     ((uint32_t)0x00000020U) /*!< bit 5 */
#define ADC_CDR_RDATA_MST_6     ((uint32_t)0x00000040U) /*!< bit 6 */
#define ADC_CDR_RDATA_MST_7     ((uint32_t)0x00000080U) /*!< bit 7 */
#define ADC_CDR_RDATA_MST_8     ((uint32_t)0x00000100U) /*!< bit 8 */
#define ADC_CDR_RDATA_MST_9     ((uint32_t)0x00000200U) /*!< bit 9 */
#define ADC_CDR_RDATA_MST_10    ((uint32_t)0x00000400U) /*!< bit 10 */
#define ADC_CDR_RDATA_MST_11    ((uint32_t)0x00000800U) /*!< bit 11 */
#define ADC_CDR_RDATA_MST_12    ((uint32_t)0x00001000U) /*!< bit 12 */
#define ADC_CDR_RDATA_MST_13    ((uint32_t)0x00002000U) /*!< bit 13 */
#define ADC_CDR_RDATA_MST_14    ((uint32_t)0x00004000U) /*!< bit 14 */
#define ADC_CDR_RDATA_MST_15    ((uint32_t)0x00008000U) /*!< bit 15 */

#define ADC_CDR_RDATA_SLV       ((uint32_t)0xFFFF0000U) /*!< ADC multimode slave group regular conversion data */
#define ADC_CDR_RDATA_SLV_0     ((uint32_t)0x00010000U) /*!< bit 0 */
#define ADC_CDR_RDATA_SLV_1     ((uint32_t)0x00020000U) /*!< bit 1 */
#define ADC_CDR_RDATA_SLV_2     ((uint32_t)0x00040000U) /*!< bit 2 */
#define ADC_CDR_RDATA_SLV_3     ((uint32_t)0x00080000U) /*!< bit 3 */
#define ADC_CDR_RDATA_SLV_4     ((uint32_t)0x00100000U) /*!< bit 4 */
#define ADC_CDR_RDATA_SLV_5     ((uint32_t)0x00200000U) /*!< bit 5 */
#define ADC_CDR_RDATA_SLV_6     ((uint32_t)0x00400000U) /*!< bit 6 */
#define ADC_CDR_RDATA_SLV_7     ((uint32_t)0x00800000U) /*!< bit 7 */
#define ADC_CDR_RDATA_SLV_8     ((uint32_t)0x01000000U) /*!< bit 8 */
#define ADC_CDR_RDATA_SLV_9     ((uint32_t)0x02000000U) /*!< bit 9 */
#define ADC_CDR_RDATA_SLV_10    ((uint32_t)0x04000000U) /*!< bit 10 */
#define ADC_CDR_RDATA_SLV_11    ((uint32_t)0x08000000U) /*!< bit 11 */
#define ADC_CDR_RDATA_SLV_12    ((uint32_t)0x10000000U) /*!< bit 12 */
#define ADC_CDR_RDATA_SLV_13    ((uint32_t)0x20000000U) /*!< bit 13 */
#define ADC_CDR_RDATA_SLV_14    ((uint32_t)0x40000000U) /*!< bit 14 */
#define ADC_CDR_RDATA_SLV_15    ((uint32_t)0x80000000U) /*!< bit 15 */

/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/

/**********************  Bit definition for COMP1_CSR register  ***************/
#define COMP1_CSR_COMP1EN               ((uint32_t)0x00000001U) /*!< COMP1 enable */
#define COMP1_CSR_COMP1SW1              ((uint32_t)0x00000002U) /*!< COMP1 SW1 switch control */
#define COMP1_CSR_COMP1MODE             ((uint32_t)0x0000000CU) /*!< COMP1 power mode */
#define COMP1_CSR_COMP1MODE_0           ((uint32_t)0x00000004U) /*!< COMP1 power mode bit 0 */
#define COMP1_CSR_COMP1MODE_1           ((uint32_t)0x00000008U) /*!< COMP1 power mode bit 1 */
#define COMP1_CSR_COMP1INSEL            ((uint32_t)0x00000070U) /*!< COMP1 inverting input select */
#define COMP1_CSR_COMP1INSEL_0          ((uint32_t)0x00000010U) /*!< COMP1 inverting input select bit 0 */
#define COMP1_CSR_COMP1INSEL_1          ((uint32_t)0x00000020U) /*!< COMP1 inverting input select bit 1 */
#define COMP1_CSR_COMP1INSEL_2          ((uint32_t)0x00000040U) /*!< COMP1 inverting input select bit 2 */
#define COMP1_CSR_COMP1NONINSEL         ((uint32_t)0x00000080U) /*!< COMP1 non inverting input select */
#define COMP1_CSR_COMP1OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP1 output select */
#define COMP1_CSR_COMP1OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP1 output select bit 0 */
#define COMP1_CSR_COMP1OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP1 output select bit 1 */
#define COMP1_CSR_COMP1OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP1 output select bit 2 */
#define COMP1_CSR_COMP1OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP1 output select bit 3 */
#define COMP1_CSR_COMP1POL              ((uint32_t)0x00008000U) /*!< COMP1 output polarity */
#define COMP1_CSR_COMP1HYST             ((uint32_t)0x00030000U) /*!< COMP1 hysteresis */
#define COMP1_CSR_COMP1HYST_0           ((uint32_t)0x00010000U) /*!< COMP1 hysteresis bit 0 */
#define COMP1_CSR_COMP1HYST_1           ((uint32_t)0x00020000U) /*!< COMP1 hysteresis bit 1 */
#define COMP1_CSR_COMP1BLANKING         ((uint32_t)0x000C0000U) /*!< COMP1 blanking */
#define COMP1_CSR_COMP1BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP1 blanking bit 0 */
#define COMP1_CSR_COMP1BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP1 blanking bit 1 */
#define COMP1_CSR_COMP1BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP1 blanking bit 2 */
#define COMP1_CSR_COMP1OUT              ((uint32_t)0x40000000U) /*!< COMP1 output level */
#define COMP1_CSR_COMP1LOCK             ((uint32_t)0x80000000U) /*!< COMP1 lock */

/**********************  Bit definition for COMP2_CSR register  ***************/
#define COMP2_CSR_COMP2EN               ((uint32_t)0x00000001U) /*!< COMP2 enable */
#define COMP2_CSR_COMP2MODE             ((uint32_t)0x0000000CU) /*!< COMP2 power mode */
#define COMP2_CSR_COMP2MODE_0           ((uint32_t)0x00000004U) /*!< COMP2 power mode bit 0 */
#define COMP2_CSR_COMP2MODE_1           ((uint32_t)0x00000008U) /*!< COMP2 power mode bit 1 */
#define COMP2_CSR_COMP2INSEL            ((uint32_t)0x00400070U) /*!< COMP2 inverting input select */
#define COMP2_CSR_COMP2INSEL_0          ((uint32_t)0x00000010U) /*!< COMP2 inverting input select bit 0 */
#define COMP2_CSR_COMP2INSEL_1          ((uint32_t)0x00000020U) /*!< COMP2 inverting input select bit 1 */
#define COMP2_CSR_COMP2INSEL_2          ((uint32_t)0x00000040U) /*!< COMP2 inverting input select bit 2 */
#define COMP2_CSR_COMP2INSEL_3          ((uint32_t)0x00400000U) /*!< COMP2 inverting input select bit 3 */
#define COMP2_CSR_COMP2NONINSEL         ((uint32_t)0x00000080U) /*!< COMP2 non inverting input select */
#define COMP2_CSR_COMP2WNDWEN           ((uint32_t)0x00000200U) /*!< COMP2 window mode enable */
#define COMP2_CSR_COMP2OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP2 output select */
#define COMP2_CSR_COMP2OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP2 output select bit 0 */
#define COMP2_CSR_COMP2OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP2 output select bit 1 */
#define COMP2_CSR_COMP2OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP2 output select bit 2 */
#define COMP2_CSR_COMP2OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP2 output select bit 3 */
#define COMP2_CSR_COMP2POL              ((uint32_t)0x00008000U) /*!< COMP2 output polarity */
#define COMP2_CSR_COMP2HYST             ((uint32_t)0x00030000U) /*!< COMP2 hysteresis */
#define COMP2_CSR_COMP2HYST_0           ((uint32_t)0x00010000U) /*!< COMP2 hysteresis bit 0 */
#define COMP2_CSR_COMP2HYST_1           ((uint32_t)0x00020000U) /*!< COMP2 hysteresis bit 1 */
#define COMP2_CSR_COMP2BLANKING         ((uint32_t)0x000C0000U) /*!< COMP2 blanking */
#define COMP2_CSR_COMP2BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP2 blanking bit 0 */
#define COMP2_CSR_COMP2BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP2 blanking bit 1 */
#define COMP2_CSR_COMP2BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP2 blanking bit 2 */
#define COMP2_CSR_COMP2OUT              ((uint32_t)0x40000000U) /*!< COMP2 output level */
#define COMP2_CSR_COMP2LOCK             ((uint32_t)0x80000000U) /*!< COMP2 lock */

/**********************  Bit definition for COMP3_CSR register  ***************/
#define COMP3_CSR_COMP3EN               ((uint32_t)0x00000001U) /*!< COMP3 enable */
#define COMP3_CSR_COMP3MODE             ((uint32_t)0x0000000CU) /*!< COMP3 power mode */
#define COMP3_CSR_COMP3MODE_0           ((uint32_t)0x00000004U) /*!< COMP3 power mode bit 0 */
#define COMP3_CSR_COMP3MODE_1           ((uint32_t)0x00000008U) /*!< COMP3 power mode bit 1 */
#define COMP3_CSR_COMP3INSEL            ((uint32_t)0x00000070U) /*!< COMP3 inverting input select */
#define COMP3_CSR_COMP3INSEL_0          ((uint32_t)0x00000010U) /*!< COMP3 inverting input select bit 0 */
#define COMP3_CSR_COMP3INSEL_1          ((uint32_t)0x00000020U) /*!< COMP3 inverting input select bit 1 */
#define COMP3_CSR_COMP3INSEL_2          ((uint32_t)0x00000040U) /*!< COMP3 inverting input select bit 2 */
#define COMP3_CSR_COMP3NONINSEL         ((uint32_t)0x00000080U) /*!< COMP3 non inverting input select */
#define COMP3_CSR_COMP3OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP3 output select */
#define COMP3_CSR_COMP3OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP3 output select bit 0 */
#define COMP3_CSR_COMP3OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP3 output select bit 1 */
#define COMP3_CSR_COMP3OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP3 output select bit 2 */
#define COMP3_CSR_COMP3OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP3 output select bit 3 */
#define COMP3_CSR_COMP3POL              ((uint32_t)0x00008000U) /*!< COMP3 output polarity */
#define COMP3_CSR_COMP3HYST             ((uint32_t)0x00030000U) /*!< COMP3 hysteresis */
#define COMP3_CSR_COMP3HYST_0           ((uint32_t)0x00010000U) /*!< COMP3 hysteresis bit 0 */
#define COMP3_CSR_COMP3HYST_1           ((uint32_t)0x00020000U) /*!< COMP3 hysteresis bit 1 */
#define COMP3_CSR_COMP3BLANKING         ((uint32_t)0x000C0000U) /*!< COMP3 blanking */
#define COMP3_CSR_COMP3BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP3 blanking bit 0 */
#define COMP3_CSR_COMP3BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP3 blanking bit 1 */
#define COMP3_CSR_COMP3BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP3 blanking bit 2 */
#define COMP3_CSR_COMP3OUT              ((uint32_t)0x40000000U) /*!< COMP3 output level */
#define COMP3_CSR_COMP3LOCK             ((uint32_t)0x80000000U) /*!< COMP3 lock */

/**********************  Bit definition for COMP4_CSR register  ***************/
#define COMP4_CSR_COMP4EN               ((uint32_t)0x00000001U) /*!< COMP4 enable */
#define COMP4_CSR_COMP4MODE             ((uint32_t)0x0000000CU) /*!< COMP4 power mode */
#define COMP4_CSR_COMP4MODE_0           ((uint32_t)0x00000004U) /*!< COMP4 power mode bit 0 */
#define COMP4_CSR_COMP4MODE_1           ((uint32_t)0x00000008U) /*!< COMP4 power mode bit 1 */
#define COMP4_CSR_COMP4INSEL            ((uint32_t)0x00400070U) /*!< COMP4 inverting input select */
#define COMP4_CSR_COMP4INSEL_0          ((uint32_t)0x00000010U) /*!< COMP4 inverting input select bit 0 */
#define COMP4_CSR_COMP4INSEL_1          ((uint32_t)0x00000020U) /*!< COMP4 inverting input select bit 1 */
#define COMP4_CSR_COMP4INSEL_2          ((uint32_t)0x00000040U) /*!< COMP4 inverting input select bit 2 */
#define COMP4_CSR_COMP4INSEL_3          ((uint32_t)0x00400000U) /*!< COMP4 inverting input select bit 3 */
#define COMP4_CSR_COMP4NONINSEL         ((uint32_t)0x00000080U) /*!< COMP4 non inverting input select */
#define COMP4_CSR_COMP4WNDWEN           ((uint32_t)0x00000200U) /*!< COMP4 window mode enable */
#define COMP4_CSR_COMP4OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP4 output select */
#define COMP4_CSR_COMP4OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP4 output select bit 0 */
#define COMP4_CSR_COMP4OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP4 output select bit 1 */
#define COMP4_CSR_COMP4OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP4 output select bit 2 */
#define COMP4_CSR_COMP4OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP4 output select bit 3 */
#define COMP4_CSR_COMP4POL              ((uint32_t)0x00008000U) /*!< COMP4 output polarity */
#define COMP4_CSR_COMP4HYST             ((uint32_t)0x00030000U) /*!< COMP4 hysteresis */
#define COMP4_CSR_COMP4HYST_0           ((uint32_t)0x00010000U) /*!< COMP4 hysteresis bit 0 */
#define COMP4_CSR_COMP4HYST_1           ((uint32_t)0x00020000U) /*!< COMP4 hysteresis bit 1 */
#define COMP4_CSR_COMP4BLANKING         ((uint32_t)0x000C0000U) /*!< COMP4 blanking */
#define COMP4_CSR_COMP4BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP4 blanking bit 0 */
#define COMP4_CSR_COMP4BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP4 blanking bit 1 */
#define COMP4_CSR_COMP4BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP4 blanking bit 2 */
#define COMP4_CSR_COMP4OUT              ((uint32_t)0x40000000U) /*!< COMP4 output level */
#define COMP4_CSR_COMP4LOCK             ((uint32_t)0x80000000U) /*!< COMP4 lock */

/**********************  Bit definition for COMP5_CSR register  ***************/
#define COMP5_CSR_COMP5EN               ((uint32_t)0x00000001U) /*!< COMP5 enable */
#define COMP5_CSR_COMP5MODE             ((uint32_t)0x0000000CU) /*!< COMP5 power mode */
#define COMP5_CSR_COMP5MODE_0           ((uint32_t)0x00000004U) /*!< COMP5 power mode bit 0 */
#define COMP5_CSR_COMP5MODE_1           ((uint32_t)0x00000008U) /*!< COMP5 power mode bit 1 */
#define COMP5_CSR_COMP5INSEL            ((uint32_t)0x00000070U) /*!< COMP5 inverting input select */
#define COMP5_CSR_COMP5INSEL_0          ((uint32_t)0x00000010U) /*!< COMP5 inverting input select bit 0 */
#define COMP5_CSR_COMP5INSEL_1          ((uint32_t)0x00000020U) /*!< COMP5 inverting input select bit 1 */
#define COMP5_CSR_COMP5INSEL_2          ((uint32_t)0x00000040U) /*!< COMP5 inverting input select bit 2 */
#define COMP5_CSR_COMP5NONINSEL         ((uint32_t)0x00000080U) /*!< COMP5 non inverting input select */
#define COMP5_CSR_COMP5OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP5 output select */
#define COMP5_CSR_COMP5OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP5 output select bit 0 */
#define COMP5_CSR_COMP5OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP5 output select bit 1 */
#define COMP5_CSR_COMP5OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP5 output select bit 2 */
#define COMP5_CSR_COMP5OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP5 output select bit 3 */
#define COMP5_CSR_COMP5POL              ((uint32_t)0x00008000U) /*!< COMP5 output polarity */
#define COMP5_CSR_COMP5HYST             ((uint32_t)0x00030000U) /*!< COMP5 hysteresis */
#define COMP5_CSR_COMP5HYST_0           ((uint32_t)0x00010000U) /*!< COMP5 hysteresis bit 0 */
#define COMP5_CSR_COMP5HYST_1           ((uint32_t)0x00020000U) /*!< COMP5 hysteresis bit 1 */
#define COMP5_CSR_COMP5BLANKING         ((uint32_t)0x000C0000U) /*!< COMP5 blanking */
#define COMP5_CSR_COMP5BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP5 blanking bit 0 */
#define COMP5_CSR_COMP5BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP5 blanking bit 1 */
#define COMP5_CSR_COMP5BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP5 blanking bit 2 */
#define COMP5_CSR_COMP5OUT              ((uint32_t)0x40000000U) /*!< COMP5 output level */
#define COMP5_CSR_COMP5LOCK             ((uint32_t)0x80000000U) /*!< COMP5 lock */

/**********************  Bit definition for COMP6_CSR register  ***************/
#define COMP6_CSR_COMP6EN               ((uint32_t)0x00000001U) /*!< COMP6 enable */
#define COMP6_CSR_COMP6MODE             ((uint32_t)0x0000000CU) /*!< COMP6 power mode */
#define COMP6_CSR_COMP6MODE_0           ((uint32_t)0x00000004U) /*!< COMP6 power mode bit 0 */
#define COMP6_CSR_COMP6MODE_1           ((uint32_t)0x00000008U) /*!< COMP6 power mode bit 1 */
#define COMP6_CSR_COMP6INSEL            ((uint32_t)0x00400070U) /*!< COMP6 inverting input select */
#define COMP6_CSR_COMP6INSEL_0          ((uint32_t)0x00000010U) /*!< COMP6 inverting input select bit 0 */
#define COMP6_CSR_COMP6INSEL_1          ((uint32_t)0x00000020U) /*!< COMP6 inverting input select bit 1 */
#define COMP6_CSR_COMP6INSEL_2          ((uint32_t)0x00000040U) /*!< COMP6 inverting input select bit 2 */
#define COMP6_CSR_COMP6INSEL_3          ((uint32_t)0x00400000U) /*!< COMP6 inverting input select bit 3 */
#define COMP6_CSR_COMP6NONINSEL         ((uint32_t)0x00000080U) /*!< COMP6 non inverting input select */
#define COMP6_CSR_COMP6WNDWEN           ((uint32_t)0x00000200U) /*!< COMP6 window mode enable */
#define COMP6_CSR_COMP6OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP6 output select */
#define COMP6_CSR_COMP6OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP6 output select bit 0 */
#define COMP6_CSR_COMP6OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP6 output select bit 1 */
#define COMP6_CSR_COMP6OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP6 output select bit 2 */
#define COMP6_CSR_COMP6OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP6 output select bit 3 */
#define COMP6_CSR_COMP6POL              ((uint32_t)0x00008000U) /*!< COMP6 output polarity */
#define COMP6_CSR_COMP6HYST             ((uint32_t)0x00030000U) /*!< COMP6 hysteresis */
#define COMP6_CSR_COMP6HYST_0           ((uint32_t)0x00010000U) /*!< COMP6 hysteresis bit 0 */
#define COMP6_CSR_COMP6HYST_1           ((uint32_t)0x00020000U) /*!< COMP6 hysteresis bit 1 */
#define COMP6_CSR_COMP6BLANKING         ((uint32_t)0x000C0000U) /*!< COMP6 blanking */
#define COMP6_CSR_COMP6BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP6 blanking bit 0 */
#define COMP6_CSR_COMP6BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP6 blanking bit 1 */
#define COMP6_CSR_COMP6BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP6 blanking bit 2 */
#define COMP6_CSR_COMP6OUT              ((uint32_t)0x40000000U) /*!< COMP6 output level */
#define COMP6_CSR_COMP6LOCK             ((uint32_t)0x80000000U) /*!< COMP6 lock */

/**********************  Bit definition for COMP7_CSR register  ***************/
#define COMP7_CSR_COMP7EN               ((uint32_t)0x00000001U) /*!< COMP7 enable */
#define COMP7_CSR_COMP7MODE             ((uint32_t)0x0000000CU) /*!< COMP7 power mode */
#define COMP7_CSR_COMP7MODE_0           ((uint32_t)0x00000004U) /*!< COMP7 power mode bit 0 */
#define COMP7_CSR_COMP7MODE_1           ((uint32_t)0x00000008U) /*!< COMP7 power mode bit 1 */
#define COMP7_CSR_COMP7INSEL            ((uint32_t)0x00000070U) /*!< COMP7 inverting input select */
#define COMP7_CSR_COMP7INSEL_0          ((uint32_t)0x00000010U) /*!< COMP7 inverting input select bit 0 */
#define COMP7_CSR_COMP7INSEL_1          ((uint32_t)0x00000020U) /*!< COMP7 inverting input select bit 1 */
#define COMP7_CSR_COMP7INSEL_2          ((uint32_t)0x00000040U) /*!< COMP7 inverting input select bit 2 */
#define COMP7_CSR_COMP7NONINSEL         ((uint32_t)0x00000080U) /*!< COMP7 non inverting input select */
#define COMP7_CSR_COMP7OUTSEL           ((uint32_t)0x00003C00U) /*!< COMP7 output select */
#define COMP7_CSR_COMP7OUTSEL_0         ((uint32_t)0x00000400U) /*!< COMP7 output select bit 0 */
#define COMP7_CSR_COMP7OUTSEL_1         ((uint32_t)0x00000800U) /*!< COMP7 output select bit 1 */
#define COMP7_CSR_COMP7OUTSEL_2         ((uint32_t)0x00001000U) /*!< COMP7 output select bit 2 */
#define COMP7_CSR_COMP7OUTSEL_3         ((uint32_t)0x00002000U) /*!< COMP7 output select bit 3 */
#define COMP7_CSR_COMP7POL              ((uint32_t)0x00008000U) /*!< COMP7 output polarity */
#define COMP7_CSR_COMP7HYST             ((uint32_t)0x00030000U) /*!< COMP7 hysteresis */
#define COMP7_CSR_COMP7HYST_0           ((uint32_t)0x00010000U) /*!< COMP7 hysteresis bit 0 */
#define COMP7_CSR_COMP7HYST_1           ((uint32_t)0x00020000U) /*!< COMP7 hysteresis bit 1 */
#define COMP7_CSR_COMP7BLANKING         ((uint32_t)0x000C0000U) /*!< COMP7 blanking */
#define COMP7_CSR_COMP7BLANKING_0       ((uint32_t)0x00040000U) /*!< COMP7 blanking bit 0 */
#define COMP7_CSR_COMP7BLANKING_1       ((uint32_t)0x00080000U) /*!< COMP7 blanking bit 1 */
#define COMP7_CSR_COMP7BLANKING_2       ((uint32_t)0x00100000U) /*!< COMP7 blanking bit 2 */
#define COMP7_CSR_COMP7OUT              ((uint32_t)0x40000000U) /*!< COMP7 output level */
#define COMP7_CSR_COMP7LOCK             ((uint32_t)0x80000000U) /*!< COMP7 lock */

/**********************  Bit definition for COMP_CSR register  ****************/
#define COMP_CSR_COMPxEN               ((uint32_t)0x00000001U) /*!< COMPx enable */
#define COMP_CSR_COMP1SW1              ((uint32_t)0x00000002U) /*!< COMP1 SW1 switch control */
#define COMP_CSR_COMPxMODE             ((uint32_t)0x0000000CU) /*!< COMPx power mode */
#define COMP_CSR_COMPxMODE_0           ((uint32_t)0x00000004U) /*!< COMPx power mode bit 0 */
#define COMP_CSR_COMPxMODE_1           ((uint32_t)0x00000008U) /*!< COMPx power mode bit 1 */
#define COMP_CSR_COMPxINSEL            ((uint32_t)0x00400070U) /*!< COMPx inverting input select */
#define COMP_CSR_COMPxINSEL_0          ((uint32_t)0x00000010U) /*!< COMPx inverting input select bit 0 */
#define COMP_CSR_COMPxINSEL_1          ((uint32_t)0x00000020U) /*!< COMPx inverting input select bit 1 */
#define COMP_CSR_COMPxINSEL_2          ((uint32_t)0x00000040U) /*!< COMPx inverting input select bit 2 */
#define COMP_CSR_COMPxINSEL_3          ((uint32_t)0x00400000U) /*!< COMPx inverting input select bit 3 */
#define COMP_CSR_COMPxNONINSEL         ((uint32_t)0x00000080U) /*!< COMPx non inverting input select */
#define COMP_CSR_COMPxWNDWEN           ((uint32_t)0x00000200U) /*!< COMPx window mode enable */
#define COMP_CSR_COMPxOUTSEL           ((uint32_t)0x00003C00U) /*!< COMPx output select */
#define COMP_CSR_COMPxOUTSEL_0         ((uint32_t)0x00000400U) /*!< COMPx output select bit 0 */
#define COMP_CSR_COMPxOUTSEL_1         ((uint32_t)0x00000800U) /*!< COMPx output select bit 1 */
#define COMP_CSR_COMPxOUTSEL_2         ((uint32_t)0x00001000U) /*!< COMPx output select bit 2 */
#define COMP_CSR_COMPxOUTSEL_3         ((uint32_t)0x00002000U) /*!< COMPx output select bit 3 */
#define COMP_CSR_COMPxPOL              ((uint32_t)0x00008000U) /*!< COMPx output polarity */
#define COMP_CSR_COMPxHYST             ((uint32_t)0x00030000U) /*!< COMPx hysteresis */
#define COMP_CSR_COMPxHYST_0           ((uint32_t)0x00010000U) /*!< COMPx hysteresis bit 0 */
#define COMP_CSR_COMPxHYST_1           ((uint32_t)0x00020000U) /*!< COMPx hysteresis bit 1 */
#define COMP_CSR_COMPxBLANKING         ((uint32_t)0x000C0000U) /*!< COMPx blanking */
#define COMP_CSR_COMPxBLANKING_0       ((uint32_t)0x00040000U) /*!< COMPx blanking bit 0 */
#define COMP_CSR_COMPxBLANKING_1       ((uint32_t)0x00080000U) /*!< COMPx blanking bit 1 */
#define COMP_CSR_COMPxBLANKING_2       ((uint32_t)0x00100000U) /*!< COMPx blanking bit 2 */
#define COMP_CSR_COMPxOUT              ((uint32_t)0x40000000U) /*!< COMPx output level */
#define COMP_CSR_COMPxLOCK             ((uint32_t)0x80000000U) /*!< COMPx lock */

/******************************************************************************/
/*                                                                            */
/*                     Operational Amplifier (OPAMP)                          */
/*                                                                            */
/******************************************************************************/
/*********************  Bit definition for OPAMP1_CSR register  ***************/
#define OPAMP1_CSR_OPAMP1EN               ((uint32_t)0x00000001U) /*!< OPAMP1 enable */
#define OPAMP1_CSR_FORCEVP                ((uint32_t)0x00000002U) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP1_CSR_VPSEL                  ((uint32_t)0x0000000CU) /*!< Non inverting input selection */
#define OPAMP1_CSR_VPSEL_0                ((uint32_t)0x00000004U) /*!< Bit 0 */
#define OPAMP1_CSR_VPSEL_1                ((uint32_t)0x00000008U) /*!< Bit 1 */
#define OPAMP1_CSR_VMSEL                  ((uint32_t)0x00000060U) /*!< Inverting input selection */
#define OPAMP1_CSR_VMSEL_0                ((uint32_t)0x00000020U) /*!< Bit 0 */
#define OPAMP1_CSR_VMSEL_1                ((uint32_t)0x00000040U) /*!< Bit 1 */
#define OPAMP1_CSR_TCMEN                  ((uint32_t)0x00000080U) /*!< Timer-Controlled Mux mode enable */
#define OPAMP1_CSR_VMSSEL                 ((uint32_t)0x00000100U) /*!< Inverting input secondary selection */
#define OPAMP1_CSR_VPSSEL                 ((uint32_t)0x00000600U) /*!< Non inverting input secondary selection */
#define OPAMP1_CSR_VPSSEL_0               ((uint32_t)0x00000200U) /*!< Bit 0 */
#define OPAMP1_CSR_VPSSEL_1               ((uint32_t)0x00000400U) /*!< Bit 1 */
#define OPAMP1_CSR_CALON                  ((uint32_t)0x00000800U) /*!< Calibration mode enable */
#define OPAMP1_CSR_CALSEL                 ((uint32_t)0x00003000U) /*!< Calibration selection */
#define OPAMP1_CSR_CALSEL_0               ((uint32_t)0x00001000U) /*!< Bit 0 */
#define OPAMP1_CSR_CALSEL_1               ((uint32_t)0x00002000U) /*!< Bit 1 */
#define OPAMP1_CSR_PGGAIN                 ((uint32_t)0x0003C000U) /*!< Gain in PGA mode */
#define OPAMP1_CSR_PGGAIN_0               ((uint32_t)0x00004000U) /*!< Bit 0 */
#define OPAMP1_CSR_PGGAIN_1               ((uint32_t)0x00008000U) /*!< Bit 1 */
#define OPAMP1_CSR_PGGAIN_2               ((uint32_t)0x00010000U) /*!< Bit 2 */
#define OPAMP1_CSR_PGGAIN_3               ((uint32_t)0x00020000U) /*!< Bit 3 */
#define OPAMP1_CSR_USERTRIM               ((uint32_t)0x00040000U) /*!< User trimming enable */
#define OPAMP1_CSR_TRIMOFFSETP            ((uint32_t)0x00F80000U) /*!< Offset trimming value (PMOS) */
#define OPAMP1_CSR_TRIMOFFSETN            ((uint32_t)0x1F000000U) /*!< Offset trimming value (NMOS) */
#define OPAMP1_CSR_TSTREF                 ((uint32_t)0x20000000U) /*!< It enables the switch to put out the internal reference */
#define OPAMP1_CSR_OUTCAL                 ((uint32_t)0x40000000U) /*!< OPAMP ouput status flag */
#define OPAMP1_CSR_LOCK                   ((uint32_t)0x80000000U) /*!< OPAMP lock */

/*********************  Bit definition for OPAMP2_CSR register  ***************/
#define OPAMP2_CSR_OPAMP2EN               ((uint32_t)0x00000001U) /*!< OPAMP2 enable */
#define OPAMP2_CSR_FORCEVP                ((uint32_t)0x00000002U) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP2_CSR_VPSEL                  ((uint32_t)0x0000000CU) /*!< Non inverting input selection */
#define OPAMP2_CSR_VPSEL_0                ((uint32_t)0x00000004U) /*!< Bit 0 */
#define OPAMP2_CSR_VPSEL_1                ((uint32_t)0x00000008U) /*!< Bit 1 */
#define OPAMP2_CSR_VMSEL                  ((uint32_t)0x00000060U) /*!< Inverting input selection */
#define OPAMP2_CSR_VMSEL_0                ((uint32_t)0x00000020U) /*!< Bit 0 */
#define OPAMP2_CSR_VMSEL_1                ((uint32_t)0x00000040U) /*!< Bit 1 */
#define OPAMP2_CSR_TCMEN                  ((uint32_t)0x00000080U) /*!< Timer-Controlled Mux mode enable */
#define OPAMP2_CSR_VMSSEL                 ((uint32_t)0x00000100U) /*!< Inverting input secondary selection */
#define OPAMP2_CSR_VPSSEL                 ((uint32_t)0x00000600U) /*!< Non inverting input secondary selection */
#define OPAMP2_CSR_VPSSEL_0               ((uint32_t)0x00000200U) /*!< Bit 0 */
#define OPAMP2_CSR_VPSSEL_1               ((uint32_t)0x00000400U) /*!< Bit 1 */
#define OPAMP2_CSR_CALON                  ((uint32_t)0x00000800U) /*!< Calibration mode enable */
#define OPAMP2_CSR_CALSEL                 ((uint32_t)0x00003000U) /*!< Calibration selection */
#define OPAMP2_CSR_CALSEL_0               ((uint32_t)0x00001000U) /*!< Bit 0 */
#define OPAMP2_CSR_CALSEL_1               ((uint32_t)0x00002000U) /*!< Bit 1 */
#define OPAMP2_CSR_PGGAIN                 ((uint32_t)0x0003C000U) /*!< Gain in PGA mode */
#define OPAMP2_CSR_PGGAIN_0               ((uint32_t)0x00004000U) /*!< Bit 0 */
#define OPAMP2_CSR_PGGAIN_1               ((uint32_t)0x00008000U) /*!< Bit 1 */
#define OPAMP2_CSR_PGGAIN_2               ((uint32_t)0x00010000U) /*!< Bit 2 */
#define OPAMP2_CSR_PGGAIN_3               ((uint32_t)0x00020000U) /*!< Bit 3 */
#define OPAMP2_CSR_USERTRIM               ((uint32_t)0x00040000U) /*!< User trimming enable */
#define OPAMP2_CSR_TRIMOFFSETP            ((uint32_t)0x00F80000U) /*!< Offset trimming value (PMOS) */
#define OPAMP2_CSR_TRIMOFFSETN            ((uint32_t)0x1F000000U) /*!< Offset trimming value (NMOS) */
#define OPAMP2_CSR_TSTREF                 ((uint32_t)0x20000000U) /*!< It enables the switch to put out the internal reference */
#define OPAMP2_CSR_OUTCAL                 ((uint32_t)0x40000000U) /*!< OPAMP ouput status flag */
#define OPAMP2_CSR_LOCK                   ((uint32_t)0x80000000U) /*!< OPAMP lock */

/*********************  Bit definition for OPAMP3_CSR register  ***************/
#define OPAMP3_CSR_OPAMP3EN               ((uint32_t)0x00000001U) /*!< OPAMP3 enable */
#define OPAMP3_CSR_FORCEVP                ((uint32_t)0x00000002U) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP3_CSR_VPSEL                  ((uint32_t)0x0000000CU) /*!< Non inverting input selection */
#define OPAMP3_CSR_VPSEL_0                ((uint32_t)0x00000004U) /*!< Bit 0 */
#define OPAMP3_CSR_VPSEL_1                ((uint32_t)0x00000008U) /*!< Bit 1 */
#define OPAMP3_CSR_VMSEL                  ((uint32_t)0x00000060U) /*!< Inverting input selection */
#define OPAMP3_CSR_VMSEL_0                ((uint32_t)0x00000020U) /*!< Bit 0 */
#define OPAMP3_CSR_VMSEL_1                ((uint32_t)0x00000040U) /*!< Bit 1 */
#define OPAMP3_CSR_TCMEN                  ((uint32_t)0x00000080U) /*!< Timer-Controlled Mux mode enable */
#define OPAMP3_CSR_VMSSEL                 ((uint32_t)0x00000100U) /*!< Inverting input secondary selection */
#define OPAMP3_CSR_VPSSEL                 ((uint32_t)0x00000600U) /*!< Non inverting input secondary selection */
#define OPAMP3_CSR_VPSSEL_0               ((uint32_t)0x00000200U) /*!< Bit 0 */
#define OPAMP3_CSR_VPSSEL_1               ((uint32_t)0x00000400U) /*!< Bit 1 */
#define OPAMP3_CSR_CALON                  ((uint32_t)0x00000800U) /*!< Calibration mode enable */
#define OPAMP3_CSR_CALSEL                 ((uint32_t)0x00003000U) /*!< Calibration selection */
#define OPAMP3_CSR_CALSEL_0               ((uint32_t)0x00001000U) /*!< Bit 0 */
#define OPAMP3_CSR_CALSEL_1               ((uint32_t)0x00002000U) /*!< Bit 1 */
#define OPAMP3_CSR_PGGAIN                 ((uint32_t)0x0003C000U) /*!< Gain in PGA mode */
#define OPAMP3_CSR_PGGAIN_0               ((uint32_t)0x00004000U) /*!< Bit 0 */
#define OPAMP3_CSR_PGGAIN_1               ((uint32_t)0x00008000U) /*!< Bit 1 */
#define OPAMP3_CSR_PGGAIN_2               ((uint32_t)0x00010000U) /*!< Bit 2 */
#define OPAMP3_CSR_PGGAIN_3               ((uint32_t)0x00020000U) /*!< Bit 3 */
#define OPAMP3_CSR_USERTRIM               ((uint32_t)0x00040000U) /*!< User trimming enable */
#define OPAMP3_CSR_TRIMOFFSETP            ((uint32_t)0x00F80000U) /*!< Offset trimming value (PMOS) */
#define OPAMP3_CSR_TRIMOFFSETN            ((uint32_t)0x1F000000U) /*!< Offset trimming value (NMOS) */
#define OPAMP3_CSR_TSTREF                 ((uint32_t)0x20000000U) /*!< It enables the switch to put out the internal reference */
#define OPAMP3_CSR_OUTCAL                 ((uint32_t)0x40000000U) /*!< OPAMP ouput status flag */
#define OPAMP3_CSR_LOCK                   ((uint32_t)0x80000000U) /*!< OPAMP lock */

/*********************  Bit definition for OPAMP4_CSR register  ***************/
#define OPAMP4_CSR_OPAMP4EN               ((uint32_t)0x00000001U) /*!< OPAMP4 enable */
#define OPAMP4_CSR_FORCEVP                ((uint32_t)0x00000002U) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP4_CSR_VPSEL                  ((uint32_t)0x0000000CU) /*!< Non inverting input selection */
#define OPAMP4_CSR_VPSEL_0                ((uint32_t)0x00000004U) /*!< Bit 0 */
#define OPAMP4_CSR_VPSEL_1                ((uint32_t)0x00000008U) /*!< Bit 1 */
#define OPAMP4_CSR_VMSEL                  ((uint32_t)0x00000060U) /*!< Inverting input selection */
#define OPAMP4_CSR_VMSEL_0                ((uint32_t)0x00000020U) /*!< Bit 0 */
#define OPAMP4_CSR_VMSEL_1                ((uint32_t)0x00000040U) /*!< Bit 1 */
#define OPAMP4_CSR_TCMEN                  ((uint32_t)0x00000080U) /*!< Timer-Controlled Mux mode enable */
#define OPAMP4_CSR_VMSSEL                 ((uint32_t)0x00000100U) /*!< Inverting input secondary selection */
#define OPAMP4_CSR_VPSSEL                 ((uint32_t)0x00000600U) /*!< Non inverting input secondary selection */
#define OPAMP4_CSR_VPSSEL_0               ((uint32_t)0x00000200U) /*!< Bit 0 */
#define OPAMP4_CSR_VPSSEL_1               ((uint32_t)0x00000400U) /*!< Bit 1 */
#define OPAMP4_CSR_CALON                  ((uint32_t)0x00000800U) /*!< Calibration mode enable */
#define OPAMP4_CSR_CALSEL                 ((uint32_t)0x00003000U) /*!< Calibration selection */
#define OPAMP4_CSR_CALSEL_0               ((uint32_t)0x00001000U) /*!< Bit 0 */
#define OPAMP4_CSR_CALSEL_1               ((uint32_t)0x00002000U) /*!< Bit 1 */
#define OPAMP4_CSR_PGGAIN                 ((uint32_t)0x0003C000U) /*!< Gain in PGA mode */
#define OPAMP4_CSR_PGGAIN_0               ((uint32_t)0x00004000U) /*!< Bit 0 */
#define OPAMP4_CSR_PGGAIN_1               ((uint32_t)0x00008000U) /*!< Bit 1 */
#define OPAMP4_CSR_PGGAIN_2               ((uint32_t)0x00010000U) /*!< Bit 2 */
#define OPAMP4_CSR_PGGAIN_3               ((uint32_t)0x00020000U) /*!< Bit 3 */
#define OPAMP4_CSR_USERTRIM               ((uint32_t)0x00040000U) /*!< User trimming enable */
#define OPAMP4_CSR_TRIMOFFSETP            ((uint32_t)0x00F80000U) /*!< Offset trimming value (PMOS) */
#define OPAMP4_CSR_TRIMOFFSETN            ((uint32_t)0x1F000000U) /*!< Offset trimming value (NMOS) */
#define OPAMP4_CSR_TSTREF                 ((uint32_t)0x20000000U) /*!< It enables the switch to put out the internal reference */
#define OPAMP4_CSR_OUTCAL                 ((uint32_t)0x40000000U) /*!< OPAMP ouput status flag */
#define OPAMP4_CSR_LOCK                   ((uint32_t)0x80000000U) /*!< OPAMP lock */

/*********************  Bit definition for OPAMPx_CSR register  ***************/
#define OPAMP_CSR_OPAMPxEN               ((uint32_t)0x00000001U) /*!< OPAMP enable */
#define OPAMP_CSR_FORCEVP                ((uint32_t)0x00000002U) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP_CSR_VPSEL                  ((uint32_t)0x0000000CU) /*!< Non inverting input selection */
#define OPAMP_CSR_VPSEL_0                ((uint32_t)0x00000004U) /*!< Bit 0 */
#define OPAMP_CSR_VPSEL_1                ((uint32_t)0x00000008U) /*!< Bit 1 */
#define OPAMP_CSR_VMSEL                  ((uint32_t)0x00000060U) /*!< Inverting input selection */
#define OPAMP_CSR_VMSEL_0                ((uint32_t)0x00000020U) /*!< Bit 0 */
#define OPAMP_CSR_VMSEL_1                ((uint32_t)0x00000040U) /*!< Bit 1 */
#define OPAMP_CSR_TCMEN                  ((uint32_t)0x00000080U) /*!< Timer-Controlled Mux mode enable */
#define OPAMP_CSR_VMSSEL                 ((uint32_t)0x00000100U) /*!< Inverting input secondary selection */
#define OPAMP_CSR_VPSSEL                 ((uint32_t)0x00000600U) /*!< Non inverting input secondary selection */
#define OPAMP_CSR_VPSSEL_0               ((uint32_t)0x00000200U) /*!< Bit 0 */
#define OPAMP_CSR_VPSSEL_1               ((uint32_t)0x00000400U) /*!< Bit 1 */
#define OPAMP_CSR_CALON                  ((uint32_t)0x00000800U) /*!< Calibration mode enable */
#define OPAMP_CSR_CALSEL                 ((uint32_t)0x00003000U) /*!< Calibration selection */
#define OPAMP_CSR_CALSEL_0               ((uint32_t)0x00001000U) /*!< Bit 0 */
#define OPAMP_CSR_CALSEL_1               ((uint32_t)0x00002000U) /*!< Bit 1 */
#define OPAMP_CSR_PGGAIN                 ((uint32_t)0x0003C000U) /*!< Gain in PGA mode */
#define OPAMP_CSR_PGGAIN_0               ((uint32_t)0x00004000U) /*!< Bit 0 */
#define OPAMP_CSR_PGGAIN_1               ((uint32_t)0x00008000U) /*!< Bit 1 */
#define OPAMP_CSR_PGGAIN_2               ((uint32_t)0x00010000U) /*!< Bit 2 */
#define OPAMP_CSR_PGGAIN_3               ((uint32_t)0x00020000U) /*!< Bit 3 */
#define OPAMP_CSR_USERTRIM               ((uint32_t)0x00040000U) /*!< User trimming enable */
#define OPAMP_CSR_TRIMOFFSETP            ((uint32_t)0x00F80000U) /*!< Offset trimming value (PMOS) */
#define OPAMP_CSR_TRIMOFFSETN            ((uint32_t)0x1F000000U) /*!< Offset trimming value (NMOS) */
#define OPAMP_CSR_TSTREF                 ((uint32_t)0x20000000U) /*!< It enables the switch to put out the internal reference */
#define OPAMP_CSR_OUTCAL                 ((uint32_t)0x40000000U) /*!< OPAMP ouput status flag */
#define OPAMP_CSR_LOCK                   ((uint32_t)0x80000000U) /*!< OPAMP lock */

/******************************************************************************/
/*                                                                            */
/*                   Controller Area Network (CAN )                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CAN_MCR register  ********************/
#define  CAN_MCR_INRQ                        ((uint32_t)0x00000001U)        /*!<Initialization Request */
#define  CAN_MCR_SLEEP                       ((uint32_t)0x00000002U)        /*!<Sleep Mode Request */
#define  CAN_MCR_TXFP                        ((uint32_t)0x00000004U)        /*!<Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        ((uint32_t)0x00000008U)        /*!<Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        ((uint32_t)0x00000010U)        /*!<No Automatic Retransmission */
#define  CAN_MCR_AWUM                        ((uint32_t)0x00000020U)        /*!<Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        ((uint32_t)0x00000040U)        /*!<Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        ((uint32_t)0x00000080U)        /*!<Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       ((uint32_t)0x00008000U)        /*!<bxCAN software master reset */

/*******************  Bit definition for CAN_MSR register  ********************/
#define  CAN_MSR_INAK                        ((uint32_t)0x00000001U)        /*!<Initialization Acknowledge */
#define  CAN_MSR_SLAK                        ((uint32_t)0x00000002U)        /*!<Sleep Acknowledge */
#define  CAN_MSR_ERRI                        ((uint32_t)0x00000004U)        /*!<Error Interrupt */
#define  CAN_MSR_WKUI                        ((uint32_t)0x00000008U)        /*!<Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       ((uint32_t)0x00000010U)        /*!<Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         ((uint32_t)0x00000100U)        /*!<Transmit Mode */
#define  CAN_MSR_RXM                         ((uint32_t)0x00000200U)        /*!<Receive Mode */
#define  CAN_MSR_SAMP                        ((uint32_t)0x00000400U)        /*!<Last Sample Point */
#define  CAN_MSR_RX                          ((uint32_t)0x00000800U)        /*!<CAN Rx Signal */

/*******************  Bit definition for CAN_TSR register  ********************/
#define  CAN_TSR_RQCP0                       ((uint32_t)0x00000001U)        /*!<Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       ((uint32_t)0x00000002U)        /*!<Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       ((uint32_t)0x00000004U)        /*!<Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       ((uint32_t)0x00000008U)        /*!<Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       ((uint32_t)0x00000080U)        /*!<Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       ((uint32_t)0x00000100U)        /*!<Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       ((uint32_t)0x00000200U)        /*!<Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       ((uint32_t)0x00000400U)        /*!<Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       ((uint32_t)0x00000800U)        /*!<Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       ((uint32_t)0x00008000U)        /*!<Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       ((uint32_t)0x00010000U)        /*!<Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       ((uint32_t)0x00020000U)        /*!<Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       ((uint32_t)0x00040000U)        /*!<Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       ((uint32_t)0x00080000U)        /*!<Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       ((uint32_t)0x00800000U)        /*!<Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        ((uint32_t)0x03000000U)        /*!<Mailbox Code */

#define  CAN_TSR_TME                         ((uint32_t)0x1C000000U)        /*!<TME[2:0] bits */
#define  CAN_TSR_TME0                        ((uint32_t)0x04000000U)        /*!<Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        ((uint32_t)0x08000000U)        /*!<Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        ((uint32_t)0x10000000U)        /*!<Transmit Mailbox 2 Empty */

#define  CAN_TSR_LOW                         ((uint32_t)0xE0000000U)        /*!<LOW[2:0] bits */
#define  CAN_TSR_LOW0                        ((uint32_t)0x20000000U)        /*!<Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        ((uint32_t)0x40000000U)        /*!<Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        ((uint32_t)0x80000000U)        /*!<Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define  CAN_RF0R_FMP0                       ((uint32_t)0x00000003U)        /*!<FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      ((uint32_t)0x00000008U)        /*!<FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      ((uint32_t)0x00000010U)        /*!<FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      ((uint32_t)0x00000020U)        /*!<Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define  CAN_RF1R_FMP1                       ((uint32_t)0x00000003U)        /*!<FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      ((uint32_t)0x00000008U)        /*!<FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      ((uint32_t)0x00000010U)        /*!<FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      ((uint32_t)0x00000020U)        /*!<Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((uint32_t)0x00000001U)        /*!<Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      ((uint32_t)0x00000002U)        /*!<FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       ((uint32_t)0x00000004U)        /*!<FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      ((uint32_t)0x00000008U)        /*!<FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      ((uint32_t)0x00000010U)        /*!<FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       ((uint32_t)0x00000020U)        /*!<FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      ((uint32_t)0x00000040U)        /*!<FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       ((uint32_t)0x00000100U)        /*!<Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       ((uint32_t)0x00000200U)        /*!<Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       ((uint32_t)0x00000400U)        /*!<Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       ((uint32_t)0x00000800U)        /*!<Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       ((uint32_t)0x00008000U)        /*!<Error Interrupt Enable */
#define  CAN_IER_WKUIE                       ((uint32_t)0x00010000U)        /*!<Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       ((uint32_t)0x00020000U)        /*!<Sleep Interrupt Enable */

/********************  Bit definition for CAN_ESR register  *******************/
#define  CAN_ESR_EWGF                        ((uint32_t)0x00000001U)        /*!<Error Warning Flag */
#define  CAN_ESR_EPVF                        ((uint32_t)0x00000002U)        /*!<Error Passive Flag */
#define  CAN_ESR_BOFF                        ((uint32_t)0x00000004U)        /*!<Bus-Off Flag */

#define  CAN_ESR_LEC                         ((uint32_t)0x00000070U)        /*!<LEC[2:0] bits (Last Error Code) */
#define  CAN_ESR_LEC_0                       ((uint32_t)0x00000010U)        /*!<Bit 0 */
#define  CAN_ESR_LEC_1                       ((uint32_t)0x00000020U)        /*!<Bit 1 */
#define  CAN_ESR_LEC_2                       ((uint32_t)0x00000040U)        /*!<Bit 2 */

#define  CAN_ESR_TEC                         ((uint32_t)0x00FF0000U)        /*!<Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         ((uint32_t)0xFF000000U)        /*!<Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((uint32_t)0x000003FFU)        /*!<Baud Rate Prescaler */
#define  CAN_BTR_TS1                         ((uint32_t)0x000F0000U)        /*!<Time Segment 1 */
#define  CAN_BTR_TS1_0                       ((uint32_t)0x00010000U)        /*!<Time Segment 1 (Bit 0) */
#define  CAN_BTR_TS1_1                       ((uint32_t)0x00020000U)        /*!<Time Segment 1 (Bit 1) */
#define  CAN_BTR_TS1_2                       ((uint32_t)0x00040000U)        /*!<Time Segment 1 (Bit 2) */
#define  CAN_BTR_TS1_3                       ((uint32_t)0x00080000U)        /*!<Time Segment 1 (Bit 3) */
#define  CAN_BTR_TS2                         ((uint32_t)0x00700000U)        /*!<Time Segment 2 */
#define  CAN_BTR_TS2_0                       ((uint32_t)0x00100000U)        /*!<Time Segment 2 (Bit 0) */
#define  CAN_BTR_TS2_1                       ((uint32_t)0x00200000U)        /*!<Time Segment 2 (Bit 1) */
#define  CAN_BTR_TS2_2                       ((uint32_t)0x00400000U)        /*!<Time Segment 2 (Bit 2) */
#define  CAN_BTR_SJW                         ((uint32_t)0x03000000U)        /*!<Resynchronization Jump Width */
#define  CAN_BTR_SJW_0                       ((uint32_t)0x01000000U)        /*!<Resynchronization Jump Width (Bit 0) */
#define  CAN_BTR_SJW_1                       ((uint32_t)0x02000000U)        /*!<Resynchronization Jump Width (Bit 1) */
#define  CAN_BTR_LBKM                        ((uint32_t)0x40000000U)        /*!<Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        ((uint32_t)0x80000000U)        /*!<Silent Mode */

/*!<Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define  CAN_TI0R_TXRQ                       ((uint32_t)0x00000001U)        /*!<Transmit Mailbox Request */
#define  CAN_TI0R_RTR                        ((uint32_t)0x00000002U)        /*!<Remote Transmission Request */
#define  CAN_TI0R_IDE                        ((uint32_t)0x00000004U)        /*!<Identifier Extension */
#define  CAN_TI0R_EXID                       ((uint32_t)0x001FFFF8U)        /*!<Extended Identifier */
#define  CAN_TI0R_STID                       ((uint32_t)0xFFE00000U)        /*!<Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define  CAN_TDT0R_DLC                       ((uint32_t)0x0000000FU)        /*!<Data Length Code */
#define  CAN_TDT0R_TGT                       ((uint32_t)0x00000100U)        /*!<Transmit Global Time */
#define  CAN_TDT0R_TIME                      ((uint32_t)0xFFFF0000U)        /*!<Message Time Stamp */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define  CAN_TDL0R_DATA0                     ((uint32_t)0x000000FFU)        /*!<Data byte 0 */
#define  CAN_TDL0R_DATA1                     ((uint32_t)0x0000FF00U)        /*!<Data byte 1 */
#define  CAN_TDL0R_DATA2                     ((uint32_t)0x00FF0000U)        /*!<Data byte 2 */
#define  CAN_TDL0R_DATA3                     ((uint32_t)0xFF000000U)        /*!<Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define  CAN_TDH0R_DATA4                     ((uint32_t)0x000000FFU)        /*!<Data byte 4 */
#define  CAN_TDH0R_DATA5                     ((uint32_t)0x0000FF00U)        /*!<Data byte 5 */
#define  CAN_TDH0R_DATA6                     ((uint32_t)0x00FF0000U)        /*!<Data byte 6 */
#define  CAN_TDH0R_DATA7                     ((uint32_t)0xFF000000U)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define  CAN_TI1R_TXRQ                       ((uint32_t)0x00000001U)        /*!<Transmit Mailbox Request */
#define  CAN_TI1R_RTR                        ((uint32_t)0x00000002U)        /*!<Remote Transmission Request */
#define  CAN_TI1R_IDE                        ((uint32_t)0x00000004U)        /*!<Identifier Extension */
#define  CAN_TI1R_EXID                       ((uint32_t)0x001FFFF8U)        /*!<Extended Identifier */
#define  CAN_TI1R_STID                       ((uint32_t)0xFFE00000U)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define  CAN_TDT1R_DLC                       ((uint32_t)0x0000000FU)        /*!<Data Length Code */
#define  CAN_TDT1R_TGT                       ((uint32_t)0x00000100U)        /*!<Transmit Global Time */
#define  CAN_TDT1R_TIME                      ((uint32_t)0xFFFF0000U)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define  CAN_TDL1R_DATA0                     ((uint32_t)0x000000FFU)        /*!<Data byte 0 */
#define  CAN_TDL1R_DATA1                     ((uint32_t)0x0000FF00U)        /*!<Data byte 1 */
#define  CAN_TDL1R_DATA2                     ((uint32_t)0x00FF0000U)        /*!<Data byte 2 */
#define  CAN_TDL1R_DATA3                     ((uint32_t)0xFF000000U)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define  CAN_TDH1R_DATA4                     ((uint32_t)0x000000FFU)        /*!<Data byte 4 */
#define  CAN_TDH1R_DATA5                     ((uint32_t)0x0000FF00U)        /*!<Data byte 5 */
#define  CAN_TDH1R_DATA6                     ((uint32_t)0x00FF0000U)        /*!<Data byte 6 */
#define  CAN_TDH1R_DATA7                     ((uint32_t)0xFF000000U)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define  CAN_TI2R_TXRQ                       ((uint32_t)0x00000001U)        /*!<Transmit Mailbox Request */
#define  CAN_TI2R_RTR                        ((uint32_t)0x00000002U)        /*!<Remote Transmission Request */
#define  CAN_TI2R_IDE                        ((uint32_t)0x00000004U)        /*!<Identifier Extension */
#define  CAN_TI2R_EXID                       ((uint32_t)0x001FFFF8U)        /*!<Extended identifier */
#define  CAN_TI2R_STID                       ((uint32_t)0xFFE00000U)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/
#define  CAN_TDT2R_DLC                       ((uint32_t)0x0000000FU)        /*!<Data Length Code */
#define  CAN_TDT2R_TGT                       ((uint32_t)0x00000100U)        /*!<Transmit Global Time */
#define  CAN_TDT2R_TIME                      ((uint32_t)0xFFFF0000U)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define  CAN_TDL2R_DATA0                     ((uint32_t)0x000000FFU)        /*!<Data byte 0 */
#define  CAN_TDL2R_DATA1                     ((uint32_t)0x0000FF00U)        /*!<Data byte 1 */
#define  CAN_TDL2R_DATA2                     ((uint32_t)0x00FF0000U)        /*!<Data byte 2 */
#define  CAN_TDL2R_DATA3                     ((uint32_t)0xFF000000U)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define  CAN_TDH2R_DATA4                     ((uint32_t)0x000000FFU)        /*!<Data byte 4 */
#define  CAN_TDH2R_DATA5                     ((uint32_t)0x0000FF00U)        /*!<Data byte 5 */
#define  CAN_TDH2R_DATA6                     ((uint32_t)0x00FF0000U)        /*!<Data byte 6 */
#define  CAN_TDH2R_DATA7                     ((uint32_t)0xFF000000U)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define  CAN_RI0R_RTR                        ((uint32_t)0x00000002U)        /*!<Remote Transmission Request */
#define  CAN_RI0R_IDE                        ((uint32_t)0x00000004U)        /*!<Identifier Extension */
#define  CAN_RI0R_EXID                       ((uint32_t)0x001FFFF8U)        /*!<Extended Identifier */
#define  CAN_RI0R_STID                       ((uint32_t)0xFFE00000U)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define  CAN_RDT0R_DLC                       ((uint32_t)0x0000000FU)        /*!<Data Length Code */
#define  CAN_RDT0R_FMI                       ((uint32_t)0x0000FF00U)        /*!<Filter Match Index */
#define  CAN_RDT0R_TIME                      ((uint32_t)0xFFFF0000U)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define  CAN_RDL0R_DATA0                     ((uint32_t)0x000000FFU)        /*!<Data byte 0 */
#define  CAN_RDL0R_DATA1                     ((uint32_t)0x0000FF00U)        /*!<Data byte 1 */
#define  CAN_RDL0R_DATA2                     ((uint32_t)0x00FF0000U)        /*!<Data byte 2 */
#define  CAN_RDL0R_DATA3                     ((uint32_t)0xFF000000U)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define  CAN_RDH0R_DATA4                     ((uint32_t)0x000000FFU)        /*!<Data byte 4 */
#define  CAN_RDH0R_DATA5                     ((uint32_t)0x0000FF00U)        /*!<Data byte 5 */
#define  CAN_RDH0R_DATA6                     ((uint32_t)0x00FF0000U)        /*!<Data byte 6 */
#define  CAN_RDH0R_DATA7                     ((uint32_t)0xFF000000U)        /*!<Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define  CAN_RI1R_RTR                        ((uint32_t)0x00000002U)        /*!<Remote Transmission Request */
#define  CAN_RI1R_IDE                        ((uint32_t)0x00000004U)        /*!<Identifier Extension */
#define  CAN_RI1R_EXID                       ((uint32_t)0x001FFFF8U)        /*!<Extended identifier */
#define  CAN_RI1R_STID                       ((uint32_t)0xFFE00000U)        /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define  CAN_RDT1R_DLC                       ((uint32_t)0x0000000FU)        /*!<Data Length Code */
#define  CAN_RDT1R_FMI                       ((uint32_t)0x0000FF00U)        /*!<Filter Match Index */
#define  CAN_RDT1R_TIME                      ((uint32_t)0xFFFF0000U)        /*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define  CAN_RDL1R_DATA0                     ((uint32_t)0x000000FFU)        /*!<Data byte 0 */
#define  CAN_RDL1R_DATA1                     ((uint32_t)0x0000FF00U)        /*!<Data byte 1 */
#define  CAN_RDL1R_DATA2                     ((uint32_t)0x00FF0000U)        /*!<Data byte 2 */
#define  CAN_RDL1R_DATA3                     ((uint32_t)0xFF000000U)        /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define  CAN_RDH1R_DATA4                     ((uint32_t)0x000000FFU)        /*!<Data byte 4 */
#define  CAN_RDH1R_DATA5                     ((uint32_t)0x0000FF00U)        /*!<Data byte 5 */
#define  CAN_RDH1R_DATA6                     ((uint32_t)0x00FF0000U)        /*!<Data byte 6 */
#define  CAN_RDH1R_DATA7                     ((uint32_t)0xFF000000U)        /*!<Data byte 7 */

/*!<CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FINIT                       ((uint32_t)0x00000001U)        /*!<Filter Init Mode */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define  CAN_FM1R_FBM                        ((uint32_t)0x00003FFFU)        /*!<Filter Mode */
#define  CAN_FM1R_FBM0                       ((uint32_t)0x00000001U)        /*!<Filter Init Mode bit 0 */
#define  CAN_FM1R_FBM1                       ((uint32_t)0x00000002U)        /*!<Filter Init Mode bit 1 */
#define  CAN_FM1R_FBM2                       ((uint32_t)0x00000004U)        /*!<Filter Init Mode bit 2 */
#define  CAN_FM1R_FBM3                       ((uint32_t)0x00000008U)        /*!<Filter Init Mode bit 3 */
#define  CAN_FM1R_FBM4                       ((uint32_t)0x00000010U)        /*!<Filter Init Mode bit 4 */
#define  CAN_FM1R_FBM5                       ((uint32_t)0x00000020U)        /*!<Filter Init Mode bit 5 */
#define  CAN_FM1R_FBM6                       ((uint32_t)0x00000040U)        /*!<Filter Init Mode bit 6 */
#define  CAN_FM1R_FBM7                       ((uint32_t)0x00000080U)        /*!<Filter Init Mode bit 7 */
#define  CAN_FM1R_FBM8                       ((uint32_t)0x00000100U)        /*!<Filter Init Mode bit 8 */
#define  CAN_FM1R_FBM9                       ((uint32_t)0x00000200U)        /*!<Filter Init Mode bit 9 */
#define  CAN_FM1R_FBM10                      ((uint32_t)0x00000400U)        /*!<Filter Init Mode bit 10 */
#define  CAN_FM1R_FBM11                      ((uint32_t)0x00000800U)        /*!<Filter Init Mode bit 11 */
#define  CAN_FM1R_FBM12                      ((uint32_t)0x00001000U)        /*!<Filter Init Mode bit 12 */
#define  CAN_FM1R_FBM13                      ((uint32_t)0x00002000U)        /*!<Filter Init Mode bit 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define  CAN_FS1R_FSC                        ((uint32_t)0x00003FFFU)        /*!<Filter Scale Configuration */
#define  CAN_FS1R_FSC0                       ((uint32_t)0x00000001U)        /*!<Filter Scale Configuration bit 0 */
#define  CAN_FS1R_FSC1                       ((uint32_t)0x00000002U)        /*!<Filter Scale Configuration bit 1 */
#define  CAN_FS1R_FSC2                       ((uint32_t)0x00000004U)        /*!<Filter Scale Configuration bit 2 */
#define  CAN_FS1R_FSC3                       ((uint32_t)0x00000008U)        /*!<Filter Scale Configuration bit 3 */
#define  CAN_FS1R_FSC4                       ((uint32_t)0x00000010U)        /*!<Filter Scale Configuration bit 4 */
#define  CAN_FS1R_FSC5                       ((uint32_t)0x00000020U)        /*!<Filter Scale Configuration bit 5 */
#define  CAN_FS1R_FSC6                       ((uint32_t)0x00000040U)        /*!<Filter Scale Configuration bit 6 */
#define  CAN_FS1R_FSC7                       ((uint32_t)0x00000080U)        /*!<Filter Scale Configuration bit 7 */
#define  CAN_FS1R_FSC8                       ((uint32_t)0x00000100U)        /*!<Filter Scale Configuration bit 8 */
#define  CAN_FS1R_FSC9                       ((uint32_t)0x00000200U)        /*!<Filter Scale Configuration bit 9 */
#define  CAN_FS1R_FSC10                      ((uint32_t)0x00000400U)        /*!<Filter Scale Configuration bit 10 */
#define  CAN_FS1R_FSC11                      ((uint32_t)0x00000800U)        /*!<Filter Scale Configuration bit 11 */
#define  CAN_FS1R_FSC12                      ((uint32_t)0x00001000U)        /*!<Filter Scale Configuration bit 12 */
#define  CAN_FS1R_FSC13                      ((uint32_t)0x00002000U)        /*!<Filter Scale Configuration bit 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define  CAN_FFA1R_FFA                       ((uint32_t)0x00003FFFU)        /*!<Filter FIFO Assignment */
#define  CAN_FFA1R_FFA0                      ((uint32_t)0x00000001U)        /*!<Filter FIFO Assignment for Filter 0 */
#define  CAN_FFA1R_FFA1                      ((uint32_t)0x00000002U)        /*!<Filter FIFO Assignment for Filter 1 */
#define  CAN_FFA1R_FFA2                      ((uint32_t)0x00000004U)        /*!<Filter FIFO Assignment for Filter 2 */
#define  CAN_FFA1R_FFA3                      ((uint32_t)0x00000008U)        /*!<Filter FIFO Assignment for Filter 3 */
#define  CAN_FFA1R_FFA4                      ((uint32_t)0x00000010U)        /*!<Filter FIFO Assignment for Filter 4 */
#define  CAN_FFA1R_FFA5                      ((uint32_t)0x00000020U)        /*!<Filter FIFO Assignment for Filter 5 */
#define  CAN_FFA1R_FFA6                      ((uint32_t)0x00000040U)        /*!<Filter FIFO Assignment for Filter 6 */
#define  CAN_FFA1R_FFA7                      ((uint32_t)0x00000080U)        /*!<Filter FIFO Assignment for Filter 7 */
#define  CAN_FFA1R_FFA8                      ((uint32_t)0x00000100U)        /*!<Filter FIFO Assignment for Filter 8 */
#define  CAN_FFA1R_FFA9                      ((uint32_t)0x00000200U)        /*!<Filter FIFO Assignment for Filter 9 */
#define  CAN_FFA1R_FFA10                     ((uint32_t)0x00000400U)        /*!<Filter FIFO Assignment for Filter 10 */
#define  CAN_FFA1R_FFA11                     ((uint32_t)0x00000800U)        /*!<Filter FIFO Assignment for Filter 11 */
#define  CAN_FFA1R_FFA12                     ((uint32_t)0x00001000U)        /*!<Filter FIFO Assignment for Filter 12 */
#define  CAN_FFA1R_FFA13                     ((uint32_t)0x00002000U)        /*!<Filter FIFO Assignment for Filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define  CAN_FA1R_FACT                       ((uint32_t)0x00003FFFU)        /*!<Filter Active */
#define  CAN_FA1R_FACT0                      ((uint32_t)0x00000001U)        /*!<Filter 0 Active */
#define  CAN_FA1R_FACT1                      ((uint32_t)0x00000002U)        /*!<Filter 1 Active */
#define  CAN_FA1R_FACT2                      ((uint32_t)0x00000004U)        /*!<Filter 2 Active */
#define  CAN_FA1R_FACT3                      ((uint32_t)0x00000008U)        /*!<Filter 3 Active */
#define  CAN_FA1R_FACT4                      ((uint32_t)0x00000010U)        /*!<Filter 4 Active */
#define  CAN_FA1R_FACT5                      ((uint32_t)0x00000020U)        /*!<Filter 5 Active */
#define  CAN_FA1R_FACT6                      ((uint32_t)0x00000040U)        /*!<Filter 6 Active */
#define  CAN_FA1R_FACT7                      ((uint32_t)0x00000080U)        /*!<Filter 7 Active */
#define  CAN_FA1R_FACT8                      ((uint32_t)0x00000100U)        /*!<Filter 8 Active */
#define  CAN_FA1R_FACT9                      ((uint32_t)0x00000200U)        /*!<Filter 9 Active */
#define  CAN_FA1R_FACT10                     ((uint32_t)0x00000400U)        /*!<Filter 10 Active */
#define  CAN_FA1R_FACT11                     ((uint32_t)0x00000800U)        /*!<Filter 11 Active */
#define  CAN_FA1R_FACT12                     ((uint32_t)0x00001000U)        /*!<Filter 12 Active */
#define  CAN_FA1R_FACT13                     ((uint32_t)0x00002000U)        /*!<Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define  CAN_F0R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F0R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F0R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F0R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F0R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F0R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F0R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F0R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F0R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F0R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F0R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F0R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F0R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F0R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F0R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F0R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F0R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F0R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F0R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F0R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F0R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F0R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F0R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F0R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F0R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F0R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F0R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F0R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F0R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F0R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F0R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F0R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define  CAN_F1R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F1R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F1R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F1R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F1R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F1R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F1R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F1R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F1R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F1R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F1R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F1R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F1R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F1R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F1R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F1R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F1R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F1R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F1R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F1R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F1R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F1R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F1R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F1R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F1R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F1R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F1R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F1R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F1R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F1R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F1R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F1R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define  CAN_F2R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F2R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F2R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F2R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F2R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F2R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F2R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F2R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F2R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F2R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F2R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F2R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F2R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F2R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F2R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F2R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F2R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F2R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F2R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F2R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F2R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F2R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F2R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F2R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F2R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F2R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F2R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F2R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F2R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F2R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F2R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F2R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define  CAN_F3R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F3R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F3R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F3R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F3R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F3R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F3R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F3R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F3R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F3R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F3R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F3R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F3R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F3R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F3R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F3R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F3R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F3R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F3R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F3R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F3R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F3R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F3R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F3R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F3R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F3R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F3R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F3R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F3R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F3R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F3R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F3R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define  CAN_F4R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F4R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F4R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F4R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F4R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F4R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F4R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F4R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F4R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F4R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F4R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F4R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F4R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F4R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F4R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F4R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F4R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F4R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F4R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F4R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F4R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F4R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F4R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F4R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F4R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F4R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F4R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F4R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F4R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F4R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F4R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F4R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define  CAN_F5R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F5R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F5R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F5R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F5R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F5R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F5R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F5R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F5R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F5R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F5R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F5R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F5R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F5R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F5R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F5R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F5R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F5R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F5R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F5R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F5R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F5R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F5R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F5R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F5R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F5R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F5R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F5R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F5R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F5R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F5R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F5R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define  CAN_F6R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F6R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F6R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F6R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F6R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F6R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F6R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F6R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F6R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F6R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F6R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F6R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F6R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F6R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F6R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F6R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F6R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F6R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F6R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F6R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F6R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F6R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F6R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F6R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F6R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F6R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F6R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F6R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F6R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F6R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F6R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F6R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define  CAN_F7R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F7R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F7R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F7R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F7R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F7R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F7R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F7R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F7R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F7R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F7R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F7R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F7R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F7R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F7R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F7R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F7R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F7R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F7R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F7R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F7R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F7R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F7R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F7R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F7R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F7R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F7R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F7R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F7R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F7R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F7R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F7R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define  CAN_F8R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F8R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F8R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F8R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F8R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F8R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F8R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F8R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F8R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F8R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F8R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F8R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F8R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F8R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F8R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F8R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F8R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F8R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F8R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F8R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F8R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F8R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F8R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F8R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F8R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F8R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F8R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F8R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F8R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F8R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F8R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F8R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define  CAN_F9R1_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F9R1_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F9R1_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F9R1_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F9R1_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F9R1_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F9R1_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F9R1_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F9R1_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F9R1_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F9R1_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F9R1_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F9R1_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F9R1_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F9R1_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F9R1_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F9R1_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F9R1_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F9R1_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F9R1_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F9R1_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F9R1_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F9R1_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F9R1_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F9R1_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F9R1_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F9R1_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F9R1_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F9R1_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F9R1_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F9R1_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F9R1_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define  CAN_F10R1_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F10R1_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F10R1_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F10R1_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F10R1_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F10R1_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F10R1_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F10R1_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F10R1_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F10R1_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F10R1_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F10R1_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F10R1_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F10R1_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F10R1_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F10R1_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F10R1_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F10R1_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F10R1_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F10R1_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F10R1_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F10R1_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F10R1_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F10R1_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F10R1_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F10R1_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F10R1_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F10R1_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F10R1_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F10R1_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F10R1_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F10R1_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define  CAN_F11R1_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F11R1_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F11R1_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F11R1_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F11R1_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F11R1_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F11R1_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F11R1_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F11R1_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F11R1_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F11R1_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F11R1_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F11R1_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F11R1_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F11R1_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F11R1_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F11R1_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F11R1_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F11R1_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F11R1_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F11R1_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F11R1_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F11R1_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F11R1_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F11R1_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F11R1_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F11R1_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F11R1_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F11R1_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F11R1_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F11R1_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F11R1_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define  CAN_F12R1_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F12R1_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F12R1_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F12R1_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F12R1_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F12R1_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F12R1_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F12R1_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F12R1_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F12R1_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F12R1_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F12R1_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F12R1_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F12R1_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F12R1_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F12R1_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F12R1_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F12R1_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F12R1_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F12R1_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F12R1_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F12R1_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F12R1_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F12R1_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F12R1_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F12R1_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F12R1_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F12R1_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F12R1_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F12R1_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F12R1_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F12R1_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define  CAN_F13R1_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F13R1_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F13R1_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F13R1_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F13R1_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F13R1_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F13R1_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F13R1_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F13R1_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F13R1_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F13R1_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F13R1_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F13R1_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F13R1_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F13R1_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F13R1_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F13R1_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F13R1_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F13R1_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F13R1_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F13R1_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F13R1_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F13R1_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F13R1_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F13R1_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F13R1_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F13R1_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F13R1_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F13R1_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F13R1_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F13R1_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F13R1_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define  CAN_F0R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F0R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F0R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F0R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F0R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F0R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F0R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F0R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F0R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F0R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F0R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F0R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F0R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F0R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F0R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F0R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F0R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F0R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F0R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F0R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F0R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F0R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F0R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F0R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F0R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F0R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F0R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F0R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F0R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F0R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F0R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F0R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define  CAN_F1R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F1R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F1R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F1R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F1R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F1R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F1R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F1R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F1R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F1R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F1R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F1R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F1R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F1R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F1R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F1R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F1R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F1R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F1R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F1R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F1R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F1R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F1R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F1R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F1R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F1R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F1R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F1R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F1R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F1R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F1R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F1R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define  CAN_F2R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F2R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F2R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F2R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F2R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F2R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F2R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F2R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F2R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F2R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F2R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F2R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F2R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F2R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F2R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F2R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F2R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F2R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F2R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F2R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F2R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F2R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F2R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F2R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F2R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F2R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F2R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F2R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F2R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F2R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F2R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F2R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define  CAN_F3R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F3R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F3R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F3R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F3R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F3R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F3R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F3R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F3R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F3R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F3R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F3R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F3R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F3R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F3R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F3R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F3R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F3R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F3R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F3R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F3R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F3R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F3R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F3R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F3R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F3R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F3R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F3R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F3R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F3R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F3R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F3R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define  CAN_F4R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F4R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F4R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F4R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F4R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F4R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F4R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F4R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F4R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F4R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F4R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F4R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F4R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F4R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F4R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F4R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F4R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F4R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F4R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F4R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F4R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F4R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F4R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F4R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F4R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F4R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F4R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F4R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F4R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F4R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F4R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F4R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define  CAN_F5R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F5R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F5R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F5R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F5R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F5R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F5R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F5R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F5R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F5R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F5R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F5R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F5R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F5R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F5R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F5R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F5R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F5R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F5R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F5R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F5R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F5R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F5R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F5R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F5R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F5R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F5R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F5R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F5R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F5R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F5R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F5R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define  CAN_F6R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F6R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F6R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F6R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F6R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F6R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F6R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F6R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F6R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F6R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F6R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F6R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F6R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F6R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F6R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F6R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F6R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F6R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F6R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F6R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F6R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F6R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F6R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F6R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F6R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F6R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F6R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F6R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F6R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F6R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F6R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F6R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define  CAN_F7R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F7R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F7R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F7R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F7R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F7R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F7R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F7R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F7R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F7R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F7R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F7R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F7R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F7R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F7R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F7R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F7R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F7R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F7R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F7R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F7R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F7R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F7R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F7R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F7R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F7R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F7R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F7R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F7R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F7R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F7R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F7R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define  CAN_F8R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F8R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F8R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F8R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F8R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F8R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F8R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F8R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F8R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F8R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F8R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F8R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F8R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F8R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F8R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F8R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F8R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F8R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F8R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F8R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F8R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F8R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F8R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F8R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F8R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F8R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F8R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F8R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F8R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F8R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F8R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F8R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define  CAN_F9R2_FB0                        ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F9R2_FB1                        ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F9R2_FB2                        ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F9R2_FB3                        ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F9R2_FB4                        ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F9R2_FB5                        ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F9R2_FB6                        ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F9R2_FB7                        ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F9R2_FB8                        ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F9R2_FB9                        ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F9R2_FB10                       ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F9R2_FB11                       ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F9R2_FB12                       ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F9R2_FB13                       ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F9R2_FB14                       ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F9R2_FB15                       ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F9R2_FB16                       ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F9R2_FB17                       ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F9R2_FB18                       ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F9R2_FB19                       ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F9R2_FB20                       ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F9R2_FB21                       ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F9R2_FB22                       ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F9R2_FB23                       ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F9R2_FB24                       ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F9R2_FB25                       ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F9R2_FB26                       ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F9R2_FB27                       ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F9R2_FB28                       ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F9R2_FB29                       ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F9R2_FB30                       ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F9R2_FB31                       ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define  CAN_F10R2_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F10R2_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F10R2_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F10R2_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F10R2_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F10R2_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F10R2_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F10R2_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F10R2_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F10R2_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F10R2_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F10R2_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F10R2_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F10R2_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F10R2_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F10R2_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F10R2_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F10R2_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F10R2_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F10R2_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F10R2_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F10R2_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F10R2_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F10R2_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F10R2_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F10R2_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F10R2_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F10R2_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F10R2_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F10R2_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F10R2_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F10R2_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define  CAN_F11R2_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F11R2_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F11R2_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F11R2_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F11R2_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F11R2_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F11R2_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F11R2_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F11R2_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F11R2_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F11R2_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F11R2_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F11R2_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F11R2_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F11R2_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F11R2_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F11R2_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F11R2_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F11R2_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F11R2_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F11R2_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F11R2_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F11R2_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F11R2_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F11R2_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F11R2_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F11R2_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F11R2_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F11R2_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F11R2_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F11R2_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F11R2_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define  CAN_F12R2_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F12R2_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F12R2_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F12R2_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F12R2_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F12R2_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F12R2_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F12R2_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F12R2_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F12R2_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F12R2_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F12R2_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F12R2_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F12R2_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F12R2_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F12R2_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F12R2_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F12R2_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F12R2_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F12R2_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F12R2_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F12R2_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F12R2_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F12R2_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F12R2_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F12R2_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F12R2_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F12R2_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F12R2_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F12R2_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F12R2_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F12R2_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define  CAN_F13R2_FB0                       ((uint32_t)0x00000001U)        /*!<Filter bit 0 */
#define  CAN_F13R2_FB1                       ((uint32_t)0x00000002U)        /*!<Filter bit 1 */
#define  CAN_F13R2_FB2                       ((uint32_t)0x00000004U)        /*!<Filter bit 2 */
#define  CAN_F13R2_FB3                       ((uint32_t)0x00000008U)        /*!<Filter bit 3 */
#define  CAN_F13R2_FB4                       ((uint32_t)0x00000010U)        /*!<Filter bit 4 */
#define  CAN_F13R2_FB5                       ((uint32_t)0x00000020U)        /*!<Filter bit 5 */
#define  CAN_F13R2_FB6                       ((uint32_t)0x00000040U)        /*!<Filter bit 6 */
#define  CAN_F13R2_FB7                       ((uint32_t)0x00000080U)        /*!<Filter bit 7 */
#define  CAN_F13R2_FB8                       ((uint32_t)0x00000100U)        /*!<Filter bit 8 */
#define  CAN_F13R2_FB9                       ((uint32_t)0x00000200U)        /*!<Filter bit 9 */
#define  CAN_F13R2_FB10                      ((uint32_t)0x00000400U)        /*!<Filter bit 10 */
#define  CAN_F13R2_FB11                      ((uint32_t)0x00000800U)        /*!<Filter bit 11 */
#define  CAN_F13R2_FB12                      ((uint32_t)0x00001000U)        /*!<Filter bit 12 */
#define  CAN_F13R2_FB13                      ((uint32_t)0x00002000U)        /*!<Filter bit 13 */
#define  CAN_F13R2_FB14                      ((uint32_t)0x00004000U)        /*!<Filter bit 14 */
#define  CAN_F13R2_FB15                      ((uint32_t)0x00008000U)        /*!<Filter bit 15 */
#define  CAN_F13R2_FB16                      ((uint32_t)0x00010000U)        /*!<Filter bit 16 */
#define  CAN_F13R2_FB17                      ((uint32_t)0x00020000U)        /*!<Filter bit 17 */
#define  CAN_F13R2_FB18                      ((uint32_t)0x00040000U)        /*!<Filter bit 18 */
#define  CAN_F13R2_FB19                      ((uint32_t)0x00080000U)        /*!<Filter bit 19 */
#define  CAN_F13R2_FB20                      ((uint32_t)0x00100000U)        /*!<Filter bit 20 */
#define  CAN_F13R2_FB21                      ((uint32_t)0x00200000U)        /*!<Filter bit 21 */
#define  CAN_F13R2_FB22                      ((uint32_t)0x00400000U)        /*!<Filter bit 22 */
#define  CAN_F13R2_FB23                      ((uint32_t)0x00800000U)        /*!<Filter bit 23 */
#define  CAN_F13R2_FB24                      ((uint32_t)0x01000000U)        /*!<Filter bit 24 */
#define  CAN_F13R2_FB25                      ((uint32_t)0x02000000U)        /*!<Filter bit 25 */
#define  CAN_F13R2_FB26                      ((uint32_t)0x04000000U)        /*!<Filter bit 26 */
#define  CAN_F13R2_FB27                      ((uint32_t)0x08000000U)        /*!<Filter bit 27 */
#define  CAN_F13R2_FB28                      ((uint32_t)0x10000000U)        /*!<Filter bit 28 */
#define  CAN_F13R2_FB29                      ((uint32_t)0x20000000U)        /*!<Filter bit 29 */
#define  CAN_F13R2_FB30                      ((uint32_t)0x40000000U)        /*!<Filter bit 30 */
#define  CAN_F13R2_FB31                      ((uint32_t)0x80000000U)        /*!<Filter bit 31 */

/******************************************************************************/
/*                                                                            */
/*                     CRC calculation unit (CRC)                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define  CRC_DR_DR                           ((uint32_t)0xFFFFFFFFU) /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define  CRC_IDR_IDR                         ((uint8_t)0xFFU)       /*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define  CRC_CR_RESET                        ((uint32_t)0x00000001U) /*!< RESET the CRC computation unit bit */
#define  CRC_CR_POLYSIZE                     ((uint32_t)0x00000018U) /*!< Polynomial size bits */
#define  CRC_CR_POLYSIZE_0                   ((uint32_t)0x00000008U) /*!< Polynomial size bit 0 */
#define  CRC_CR_POLYSIZE_1                   ((uint32_t)0x00000010U) /*!< Polynomial size bit 1 */
#define  CRC_CR_REV_IN                       ((uint32_t)0x00000060U) /*!< REV_IN Reverse Input Data bits */
#define  CRC_CR_REV_IN_0                     ((uint32_t)0x00000020U) /*!< Bit 0 */
#define  CRC_CR_REV_IN_1                     ((uint32_t)0x00000040U) /*!< Bit 1 */
#define  CRC_CR_REV_OUT                      ((uint32_t)0x00000080U) /*!< REV_OUT Reverse Output Data bits */

/*******************  Bit definition for CRC_INIT register  *******************/
#define  CRC_INIT_INIT                       ((uint32_t)0xFFFFFFFFU) /*!< Initial CRC value bits */

/*******************  Bit definition for CRC_POL register  ********************/
#define  CRC_POL_POL                         ((uint32_t)0xFFFFFFFFU) /*!< Coefficients of the polynomial */

/******************************************************************************/
/*                                                                            */
/*                 Digital to Analog Converter (DAC)                          */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F3 family)
 */
#define DAC_CHANNEL2_SUPPORT                           /*!< DAC feature available only on specific devices: DAC channel 2 available (may not be available on all DAC instances DACx) */


/********************  Bit definition for DAC_CR register  ********************/
#define  DAC_CR_EN1                          ((uint32_t)0x00000001U)        /*!< DAC channel1 enable */
#define  DAC_CR_BOFF1                        ((uint32_t)0x00000002U)        /*!< DAC channel1 output buffer disable */
#define  DAC_CR_TEN1                         ((uint32_t)0x00000004U)        /*!< DAC channel1 Trigger enable */

#define  DAC_CR_TSEL1                        ((uint32_t)0x00000038U)        /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define  DAC_CR_TSEL1_0                      ((uint32_t)0x00000008U)        /*!< Bit 0 */
#define  DAC_CR_TSEL1_1                      ((uint32_t)0x00000010U)        /*!< Bit 1 */
#define  DAC_CR_TSEL1_2                      ((uint32_t)0x00000020U)        /*!< Bit 2 */

#define  DAC_CR_WAVE1                        ((uint32_t)0x000000C0U)        /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE1_0                      ((uint32_t)0x00000040U)        /*!< Bit 0 */
#define  DAC_CR_WAVE1_1                      ((uint32_t)0x00000080U)        /*!< Bit 1 */

#define  DAC_CR_MAMP1                        ((uint32_t)0x00000F00U)        /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define  DAC_CR_MAMP1_0                      ((uint32_t)0x00000100U)        /*!< Bit 0 */
#define  DAC_CR_MAMP1_1                      ((uint32_t)0x00000200U)        /*!< Bit 1 */
#define  DAC_CR_MAMP1_2                      ((uint32_t)0x00000400U)        /*!< Bit 2 */
#define  DAC_CR_MAMP1_3                      ((uint32_t)0x00000800U)        /*!< Bit 3 */

#define  DAC_CR_DMAEN1                       ((uint32_t)0x00001000U)        /*!< DAC channel1 DMA enable */
#define  DAC_CR_DMAUDRIE1                    ((uint32_t)0x00002000U)        /*!< DAC channel1 DMA underrun IT enable */ 
#define  DAC_CR_EN2                          ((uint32_t)0x00010000U)        /*!< DAC channel2 enable */
#define  DAC_CR_BOFF2                        ((uint32_t)0x00020000U)        /*!< DAC channel2 output buffer disable */
#define  DAC_CR_TEN2                         ((uint32_t)0x00040000U)        /*!< DAC channel2 Trigger enable */

#define  DAC_CR_TSEL2                        ((uint32_t)0x00380000U)        /*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define  DAC_CR_TSEL2_0                      ((uint32_t)0x00080000U)        /*!< Bit 0 */
#define  DAC_CR_TSEL2_1                      ((uint32_t)0x00100000U)        /*!< Bit 1 */
#define  DAC_CR_TSEL2_2                      ((uint32_t)0x00200000U)        /*!< Bit 2 */

#define  DAC_CR_WAVE2                        ((uint32_t)0x00C00000U)        /*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE2_0                      ((uint32_t)0x00400000U)        /*!< Bit 0 */
#define  DAC_CR_WAVE2_1                      ((uint32_t)0x00800000U)        /*!< Bit 1 */

#define  DAC_CR_MAMP2                        ((uint32_t)0x0F000000U)        /*!< MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define  DAC_CR_MAMP2_0                      ((uint32_t)0x01000000U)        /*!< Bit 0 */
#define  DAC_CR_MAMP2_1                      ((uint32_t)0x02000000U)        /*!< Bit 1 */
#define  DAC_CR_MAMP2_2                      ((uint32_t)0x04000000U)        /*!< Bit 2 */
#define  DAC_CR_MAMP2_3                      ((uint32_t)0x08000000U)        /*!< Bit 3 */

#define  DAC_CR_DMAEN2                       ((uint32_t)0x10000000U)        /*!< DAC channel2 DMA enabled */
#define  DAC_CR_DMAUDRIE2                    ((uint32_t)0x20000000U)        /*!< DAC channel2 DMA underrun IT enable */ 

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define  DAC_SWTRIGR_SWTRIG1                 ((uint32_t)0x00000001U)        /*!< DAC channel1 software trigger */
#define  DAC_SWTRIGR_SWTRIG2                 ((uint32_t)0x00000002U)        /*!< DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define  DAC_DHR12R1_DACC1DHR                ((uint32_t)0x00000FFFU)        /*!< DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define  DAC_DHR12L1_DACC1DHR                ((uint32_t)0x0000FFF0U)        /*!< DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define  DAC_DHR8R1_DACC1DHR                 ((uint32_t)0x000000FFU)        /*!< DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define  DAC_DHR12R2_DACC2DHR                ((uint32_t)0x00000FFFU)        /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define  DAC_DHR12L2_DACC2DHR                ((uint32_t)0x0000FFF0U)        /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define  DAC_DHR8R2_DACC2DHR                 ((uint32_t)0x000000FFU)        /*!< DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define  DAC_DHR12RD_DACC1DHR                ((uint32_t)0x00000FFFU)        /*!< DAC channel1 12-bit Right aligned data */
#define  DAC_DHR12RD_DACC2DHR                ((uint32_t)0x0FFF0000U)        /*!< DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define  DAC_DHR12LD_DACC1DHR                ((uint32_t)0x0000FFF0U)        /*!< DAC channel1 12-bit Left aligned data */
#define  DAC_DHR12LD_DACC2DHR                ((uint32_t)0xFFF00000U)        /*!< DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define  DAC_DHR8RD_DACC1DHR                 ((uint32_t)0x000000FFU)        /*!< DAC channel1 8-bit Right aligned data */
#define  DAC_DHR8RD_DACC2DHR                 ((uint32_t)0x0000FF00U)        /*!< DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define  DAC_DOR1_DACC1DOR                   ((uint32_t)0x00000FFFU)        /*!< DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define  DAC_DOR2_DACC2DOR                   ((uint32_t)0x00000FFFU)        /*!< DAC channel2 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define  DAC_SR_DMAUDR1                      ((uint32_t)0x00002000U)        /*!< DAC channel1 DMA underrun flag */
#define  DAC_SR_DMAUDR2                      ((uint32_t)0x20000000U)        /*!< DAC channel2 DMA underrun flag */

/******************************************************************************/
/*                                                                            */
/*                                 Debug MCU (DBGMCU)                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define  DBGMCU_IDCODE_DEV_ID                ((uint32_t)0x00000FFFU)
#define  DBGMCU_IDCODE_REV_ID                ((uint32_t)0xFFFF0000U)

/********************  Bit definition for DBGMCU_CR register  *****************/
#define  DBGMCU_CR_DBG_SLEEP                 ((uint32_t)0x00000001U)
#define  DBGMCU_CR_DBG_STOP                  ((uint32_t)0x00000002U)
#define  DBGMCU_CR_DBG_STANDBY               ((uint32_t)0x00000004U)
#define  DBGMCU_CR_TRACE_IOEN                ((uint32_t)0x00000020U)

#define  DBGMCU_CR_TRACE_MODE                ((uint32_t)0x000000C0U)
#define  DBGMCU_CR_TRACE_MODE_0              ((uint32_t)0x00000040U)/*!<Bit 0 */
#define  DBGMCU_CR_TRACE_MODE_1              ((uint32_t)0x00000080U)/*!<Bit 1 */

/********************  Bit definition for DBGMCU_APB1_FZ register  ************/
#define  DBGMCU_APB1_FZ_DBG_TIM2_STOP        ((uint32_t)0x00000001U)
#define  DBGMCU_APB1_FZ_DBG_TIM3_STOP        ((uint32_t)0x00000002U)
#define  DBGMCU_APB1_FZ_DBG_TIM4_STOP        ((uint32_t)0x00000004U)
#define  DBGMCU_APB1_FZ_DBG_TIM6_STOP        ((uint32_t)0x00000010U)
#define  DBGMCU_APB1_FZ_DBG_TIM7_STOP        ((uint32_t)0x00000020U)
#define  DBGMCU_APB1_FZ_DBG_RTC_STOP         ((uint32_t)0x00000400U)
#define  DBGMCU_APB1_FZ_DBG_WWDG_STOP        ((uint32_t)0x00000800U)
#define  DBGMCU_APB1_FZ_DBG_IWDG_STOP        ((uint32_t)0x00001000U)
#define  DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT   ((uint32_t)0x00200000U)
#define  DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT   ((uint32_t)0x00400000U)
#define  DBGMCU_APB1_FZ_DBG_CAN_STOP         ((uint32_t)0x02000000U)

/********************  Bit definition for DBGMCU_APB2_FZ register  ************/
#define  DBGMCU_APB2_FZ_DBG_TIM1_STOP        ((uint32_t)0x00000001U)
#define  DBGMCU_APB2_FZ_DBG_TIM8_STOP        ((uint32_t)0x00000002U)
#define  DBGMCU_APB2_FZ_DBG_TIM15_STOP       ((uint32_t)0x00000004U)
#define  DBGMCU_APB2_FZ_DBG_TIM16_STOP       ((uint32_t)0x00000008U)
#define  DBGMCU_APB2_FZ_DBG_TIM17_STOP       ((uint32_t)0x00000010U)

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller (DMA)                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for DMA_ISR register  ********************/
#define  DMA_ISR_GIF1                        ((uint32_t)0x00000001U)        /*!< Channel 1 Global interrupt flag */
#define  DMA_ISR_TCIF1                       ((uint32_t)0x00000002U)        /*!< Channel 1 Transfer Complete flag */
#define  DMA_ISR_HTIF1                       ((uint32_t)0x00000004U)        /*!< Channel 1 Half Transfer flag */
#define  DMA_ISR_TEIF1                       ((uint32_t)0x00000008U)        /*!< Channel 1 Transfer Error flag */
#define  DMA_ISR_GIF2                        ((uint32_t)0x00000010U)        /*!< Channel 2 Global interrupt flag */
#define  DMA_ISR_TCIF2                       ((uint32_t)0x00000020U)        /*!< Channel 2 Transfer Complete flag */
#define  DMA_ISR_HTIF2                       ((uint32_t)0x00000040U)        /*!< Channel 2 Half Transfer flag */
#define  DMA_ISR_TEIF2                       ((uint32_t)0x00000080U)        /*!< Channel 2 Transfer Error flag */
#define  DMA_ISR_GIF3                        ((uint32_t)0x00000100U)        /*!< Channel 3 Global interrupt flag */
#define  DMA_ISR_TCIF3                       ((uint32_t)0x00000200U)        /*!< Channel 3 Transfer Complete flag */
#define  DMA_ISR_HTIF3                       ((uint32_t)0x00000400U)        /*!< Channel 3 Half Transfer flag */
#define  DMA_ISR_TEIF3                       ((uint32_t)0x00000800U)        /*!< Channel 3 Transfer Error flag */
#define  DMA_ISR_GIF4                        ((uint32_t)0x00001000U)        /*!< Channel 4 Global interrupt flag */
#define  DMA_ISR_TCIF4                       ((uint32_t)0x00002000U)        /*!< Channel 4 Transfer Complete flag */
#define  DMA_ISR_HTIF4                       ((uint32_t)0x00004000U)        /*!< Channel 4 Half Transfer flag */
#define  DMA_ISR_TEIF4                       ((uint32_t)0x00008000U)        /*!< Channel 4 Transfer Error flag */
#define  DMA_ISR_GIF5                        ((uint32_t)0x00010000U)        /*!< Channel 5 Global interrupt flag */
#define  DMA_ISR_TCIF5                       ((uint32_t)0x00020000U)        /*!< Channel 5 Transfer Complete flag */
#define  DMA_ISR_HTIF5                       ((uint32_t)0x00040000U)        /*!< Channel 5 Half Transfer flag */
#define  DMA_ISR_TEIF5                       ((uint32_t)0x00080000U)        /*!< Channel 5 Transfer Error flag */
#define  DMA_ISR_GIF6                        ((uint32_t)0x00100000U)        /*!< Channel 6 Global interrupt flag */
#define  DMA_ISR_TCIF6                       ((uint32_t)0x00200000U)        /*!< Channel 6 Transfer Complete flag */
#define  DMA_ISR_HTIF6                       ((uint32_t)0x00400000U)        /*!< Channel 6 Half Transfer flag */
#define  DMA_ISR_TEIF6                       ((uint32_t)0x00800000U)        /*!< Channel 6 Transfer Error flag */
#define  DMA_ISR_GIF7                        ((uint32_t)0x01000000U)        /*!< Channel 7 Global interrupt flag */
#define  DMA_ISR_TCIF7                       ((uint32_t)0x02000000U)        /*!< Channel 7 Transfer Complete flag */
#define  DMA_ISR_HTIF7                       ((uint32_t)0x04000000U)        /*!< Channel 7 Half Transfer flag */
#define  DMA_ISR_TEIF7                       ((uint32_t)0x08000000U)        /*!< Channel 7 Transfer Error flag */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define  DMA_IFCR_CGIF1                      ((uint32_t)0x00000001U)        /*!< Channel 1 Global interrupt clear */
#define  DMA_IFCR_CTCIF1                     ((uint32_t)0x00000002U)        /*!< Channel 1 Transfer Complete clear */
#define  DMA_IFCR_CHTIF1                     ((uint32_t)0x00000004U)        /*!< Channel 1 Half Transfer clear */
#define  DMA_IFCR_CTEIF1                     ((uint32_t)0x00000008U)        /*!< Channel 1 Transfer Error clear */
#define  DMA_IFCR_CGIF2                      ((uint32_t)0x00000010U)        /*!< Channel 2 Global interrupt clear */
#define  DMA_IFCR_CTCIF2                     ((uint32_t)0x00000020U)        /*!< Channel 2 Transfer Complete clear */
#define  DMA_IFCR_CHTIF2                     ((uint32_t)0x00000040U)        /*!< Channel 2 Half Transfer clear */
#define  DMA_IFCR_CTEIF2                     ((uint32_t)0x00000080U)        /*!< Channel 2 Transfer Error clear */
#define  DMA_IFCR_CGIF3                      ((uint32_t)0x00000100U)        /*!< Channel 3 Global interrupt clear */
#define  DMA_IFCR_CTCIF3                     ((uint32_t)0x00000200U)        /*!< Channel 3 Transfer Complete clear */
#define  DMA_IFCR_CHTIF3                     ((uint32_t)0x00000400U)        /*!< Channel 3 Half Transfer clear */
#define  DMA_IFCR_CTEIF3                     ((uint32_t)0x00000800U)        /*!< Channel 3 Transfer Error clear */
#define  DMA_IFCR_CGIF4                      ((uint32_t)0x00001000U)        /*!< Channel 4 Global interrupt clear */
#define  DMA_IFCR_CTCIF4                     ((uint32_t)0x00002000U)        /*!< Channel 4 Transfer Complete clear */
#define  DMA_IFCR_CHTIF4                     ((uint32_t)0x00004000U)        /*!< Channel 4 Half Transfer clear */
#define  DMA_IFCR_CTEIF4                     ((uint32_t)0x00008000U)        /*!< Channel 4 Transfer Error clear */
#define  DMA_IFCR_CGIF5                      ((uint32_t)0x00010000U)        /*!< Channel 5 Global interrupt clear */
#define  DMA_IFCR_CTCIF5                     ((uint32_t)0x00020000U)        /*!< Channel 5 Transfer Complete clear */
#define  DMA_IFCR_CHTIF5                     ((uint32_t)0x00040000U)        /*!< Channel 5 Half Transfer clear */
#define  DMA_IFCR_CTEIF5                     ((uint32_t)0x00080000U)        /*!< Channel 5 Transfer Error clear */
#define  DMA_IFCR_CGIF6                      ((uint32_t)0x00100000U)        /*!< Channel 6 Global interrupt clear */
#define  DMA_IFCR_CTCIF6                     ((uint32_t)0x00200000U)        /*!< Channel 6 Transfer Complete clear */
#define  DMA_IFCR_CHTIF6                     ((uint32_t)0x00400000U)        /*!< Channel 6 Half Transfer clear */
#define  DMA_IFCR_CTEIF6                     ((uint32_t)0x00800000U)        /*!< Channel 6 Transfer Error clear */
#define  DMA_IFCR_CGIF7                      ((uint32_t)0x01000000U)        /*!< Channel 7 Global interrupt clear */
#define  DMA_IFCR_CTCIF7                     ((uint32_t)0x02000000U)        /*!< Channel 7 Transfer Complete clear */
#define  DMA_IFCR_CHTIF7                     ((uint32_t)0x04000000U)        /*!< Channel 7 Half Transfer clear */
#define  DMA_IFCR_CTEIF7                     ((uint32_t)0x08000000U)        /*!< Channel 7 Transfer Error clear */

/*******************  Bit definition for DMA_CCR register  ********************/
#define  DMA_CCR_EN                          ((uint32_t)0x00000001U)        /*!< Channel enable                      */
#define  DMA_CCR_TCIE                        ((uint32_t)0x00000002U)        /*!< Transfer complete interrupt enable  */
#define  DMA_CCR_HTIE                        ((uint32_t)0x00000004U)        /*!< Half Transfer interrupt enable      */
#define  DMA_CCR_TEIE                        ((uint32_t)0x00000008U)        /*!< Transfer error interrupt enable     */
#define  DMA_CCR_DIR                         ((uint32_t)0x00000010U)        /*!< Data transfer direction             */
#define  DMA_CCR_CIRC                        ((uint32_t)0x00000020U)        /*!< Circular mode                       */
#define  DMA_CCR_PINC                        ((uint32_t)0x00000040U)        /*!< Peripheral increment mode           */
#define  DMA_CCR_MINC                        ((uint32_t)0x00000080U)        /*!< Memory increment mode               */

#define  DMA_CCR_PSIZE                       ((uint32_t)0x00000300U)        /*!< PSIZE[1:0] bits (Peripheral size)   */
#define  DMA_CCR_PSIZE_0                     ((uint32_t)0x00000100U)        /*!< Bit 0                               */
#define  DMA_CCR_PSIZE_1                     ((uint32_t)0x00000200U)        /*!< Bit 1                               */

#define  DMA_CCR_MSIZE                       ((uint32_t)0x00000C00U)        /*!< MSIZE[1:0] bits (Memory size)       */
#define  DMA_CCR_MSIZE_0                     ((uint32_t)0x00000400U)        /*!< Bit 0                               */
#define  DMA_CCR_MSIZE_1                     ((uint32_t)0x00000800U)        /*!< Bit 1                               */

#define  DMA_CCR_PL                          ((uint32_t)0x00003000U)        /*!< PL[1:0] bits(Channel Priority level)*/
#define  DMA_CCR_PL_0                        ((uint32_t)0x00001000U)        /*!< Bit 0                               */
#define  DMA_CCR_PL_1                        ((uint32_t)0x00002000U)        /*!< Bit 1                               */

#define  DMA_CCR_MEM2MEM                     ((uint32_t)0x00004000U)        /*!< Memory to memory mode               */

/******************  Bit definition for DMA_CNDTR register  *******************/
#define  DMA_CNDTR_NDT                       ((uint32_t)0x0000FFFFU)        /*!< Number of data to Transfer          */

/******************  Bit definition for DMA_CPAR register  ********************/
#define  DMA_CPAR_PA                         ((uint32_t)0xFFFFFFFFU)        /*!< Peripheral Address                  */

/******************  Bit definition for DMA_CMAR register  ********************/
#define  DMA_CMAR_MA                         ((uint32_t)0xFFFFFFFFU)        /*!< Memory Address                      */

/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller (EXTI)              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EXTI_IMR register  *******************/
#define  EXTI_IMR_MR0                        ((uint32_t)0x00000001U)        /*!< Interrupt Mask on line 0 */
#define  EXTI_IMR_MR1                        ((uint32_t)0x00000002U)        /*!< Interrupt Mask on line 1 */
#define  EXTI_IMR_MR2                        ((uint32_t)0x00000004U)        /*!< Interrupt Mask on line 2 */
#define  EXTI_IMR_MR3                        ((uint32_t)0x00000008U)        /*!< Interrupt Mask on line 3 */
#define  EXTI_IMR_MR4                        ((uint32_t)0x00000010U)        /*!< Interrupt Mask on line 4 */
#define  EXTI_IMR_MR5                        ((uint32_t)0x00000020U)        /*!< Interrupt Mask on line 5 */
#define  EXTI_IMR_MR6                        ((uint32_t)0x00000040U)        /*!< Interrupt Mask on line 6 */
#define  EXTI_IMR_MR7                        ((uint32_t)0x00000080U)        /*!< Interrupt Mask on line 7 */
#define  EXTI_IMR_MR8                        ((uint32_t)0x00000100U)        /*!< Interrupt Mask on line 8 */
#define  EXTI_IMR_MR9                        ((uint32_t)0x00000200U)        /*!< Interrupt Mask on line 9 */
#define  EXTI_IMR_MR10                       ((uint32_t)0x00000400U)        /*!< Interrupt Mask on line 10 */
#define  EXTI_IMR_MR11                       ((uint32_t)0x00000800U)        /*!< Interrupt Mask on line 11 */
#define  EXTI_IMR_MR12                       ((uint32_t)0x00001000U)        /*!< Interrupt Mask on line 12 */
#define  EXTI_IMR_MR13                       ((uint32_t)0x00002000U)        /*!< Interrupt Mask on line 13 */
#define  EXTI_IMR_MR14                       ((uint32_t)0x00004000U)        /*!< Interrupt Mask on line 14 */
#define  EXTI_IMR_MR15                       ((uint32_t)0x00008000U)        /*!< Interrupt Mask on line 15 */
#define  EXTI_IMR_MR16                       ((uint32_t)0x00010000U)        /*!< Interrupt Mask on line 16 */
#define  EXTI_IMR_MR17                       ((uint32_t)0x00020000U)        /*!< Interrupt Mask on line 17 */
#define  EXTI_IMR_MR18                       ((uint32_t)0x00040000U)        /*!< Interrupt Mask on line 18 */
#define  EXTI_IMR_MR19                       ((uint32_t)0x00080000U)        /*!< Interrupt Mask on line 19 */
#define  EXTI_IMR_MR20                       ((uint32_t)0x00100000U)        /*!< Interrupt Mask on line 20 */
#define  EXTI_IMR_MR21                       ((uint32_t)0x00200000U)        /*!< Interrupt Mask on line 21 */
#define  EXTI_IMR_MR22                       ((uint32_t)0x00400000U)        /*!< Interrupt Mask on line 22 */
#define  EXTI_IMR_MR23                       ((uint32_t)0x00800000U)        /*!< Interrupt Mask on line 23 */
#define  EXTI_IMR_MR24                       ((uint32_t)0x01000000U)        /*!< Interrupt Mask on line 24 */
#define  EXTI_IMR_MR25                       ((uint32_t)0x02000000U)        /*!< Interrupt Mask on line 25 */
#define  EXTI_IMR_MR26                       ((uint32_t)0x04000000U)        /*!< Interrupt Mask on line 26 */
#define  EXTI_IMR_MR27                       ((uint32_t)0x08000000U)        /*!< Interrupt Mask on line 27 */
#define  EXTI_IMR_MR28                       ((uint32_t)0x10000000U)        /*!< Interrupt Mask on line 28 */
#define  EXTI_IMR_MR29                       ((uint32_t)0x20000000U)        /*!< Interrupt Mask on line 29 */
#define  EXTI_IMR_MR30                       ((uint32_t)0x40000000U)        /*!< Interrupt Mask on line 30 */
#define  EXTI_IMR_MR31                       ((uint32_t)0x80000000U)        /*!< Interrupt Mask on line 31 */

/* References Defines */
#define  EXTI_IMR_IM0 EXTI_IMR_MR0
#define  EXTI_IMR_IM1 EXTI_IMR_MR1
#define  EXTI_IMR_IM2 EXTI_IMR_MR2
#define  EXTI_IMR_IM3 EXTI_IMR_MR3
#define  EXTI_IMR_IM4 EXTI_IMR_MR4
#define  EXTI_IMR_IM5 EXTI_IMR_MR5
#define  EXTI_IMR_IM6 EXTI_IMR_MR6
#define  EXTI_IMR_IM7 EXTI_IMR_MR7
#define  EXTI_IMR_IM8 EXTI_IMR_MR8
#define  EXTI_IMR_IM9 EXTI_IMR_MR9
#define  EXTI_IMR_IM10 EXTI_IMR_MR10
#define  EXTI_IMR_IM11 EXTI_IMR_MR11
#define  EXTI_IMR_IM12 EXTI_IMR_MR12
#define  EXTI_IMR_IM13 EXTI_IMR_MR13
#define  EXTI_IMR_IM14 EXTI_IMR_MR14
#define  EXTI_IMR_IM15 EXTI_IMR_MR15
#define  EXTI_IMR_IM16 EXTI_IMR_MR16
#define  EXTI_IMR_IM17 EXTI_IMR_MR17
#define  EXTI_IMR_IM18 EXTI_IMR_MR18
#define  EXTI_IMR_IM19 EXTI_IMR_MR19
#define  EXTI_IMR_IM20 EXTI_IMR_MR20
#define  EXTI_IMR_IM21 EXTI_IMR_MR21
#define  EXTI_IMR_IM22 EXTI_IMR_MR22
#define  EXTI_IMR_IM23 EXTI_IMR_MR23
#define  EXTI_IMR_IM24 EXTI_IMR_MR24
#define  EXTI_IMR_IM25 EXTI_IMR_MR25
#define  EXTI_IMR_IM26 EXTI_IMR_MR26
#define  EXTI_IMR_IM27 EXTI_IMR_MR27
#define  EXTI_IMR_IM28 EXTI_IMR_MR28
#define  EXTI_IMR_IM29 EXTI_IMR_MR29
#define  EXTI_IMR_IM30 EXTI_IMR_MR30
#define  EXTI_IMR_IM31 EXTI_IMR_MR31

#define  EXTI_IMR_IM   ((uint32_t)0xFFFFFFFF)          /*!< Interrupt Mask All */

/*******************  Bit definition for EXTI_EMR register  *******************/
#define  EXTI_EMR_MR0                        ((uint32_t)0x00000001U)        /*!< Event Mask on line 0 */
#define  EXTI_EMR_MR1                        ((uint32_t)0x00000002U)        /*!< Event Mask on line 1 */
#define  EXTI_EMR_MR2                        ((uint32_t)0x00000004U)        /*!< Event Mask on line 2 */
#define  EXTI_EMR_MR3                        ((uint32_t)0x00000008U)        /*!< Event Mask on line 3 */
#define  EXTI_EMR_MR4                        ((uint32_t)0x00000010U)        /*!< Event Mask on line 4 */
#define  EXTI_EMR_MR5                        ((uint32_t)0x00000020U)        /*!< Event Mask on line 5 */
#define  EXTI_EMR_MR6                        ((uint32_t)0x00000040U)        /*!< Event Mask on line 6 */
#define  EXTI_EMR_MR7                        ((uint32_t)0x00000080U)        /*!< Event Mask on line 7 */
#define  EXTI_EMR_MR8                        ((uint32_t)0x00000100U)        /*!< Event Mask on line 8 */
#define  EXTI_EMR_MR9                        ((uint32_t)0x00000200U)        /*!< Event Mask on line 9 */
#define  EXTI_EMR_MR10                       ((uint32_t)0x00000400U)        /*!< Event Mask on line 10 */
#define  EXTI_EMR_MR11                       ((uint32_t)0x00000800U)        /*!< Event Mask on line 11 */
#define  EXTI_EMR_MR12                       ((uint32_t)0x00001000U)        /*!< Event Mask on line 12 */
#define  EXTI_EMR_MR13                       ((uint32_t)0x00002000U)        /*!< Event Mask on line 13 */
#define  EXTI_EMR_MR14                       ((uint32_t)0x00004000U)        /*!< Event Mask on line 14 */
#define  EXTI_EMR_MR15                       ((uint32_t)0x00008000U)        /*!< Event Mask on line 15 */
#define  EXTI_EMR_MR16                       ((uint32_t)0x00010000U)        /*!< Event Mask on line 16 */
#define  EXTI_EMR_MR17                       ((uint32_t)0x00020000U)        /*!< Event Mask on line 17 */
#define  EXTI_EMR_MR18                       ((uint32_t)0x00040000U)        /*!< Event Mask on line 18 */
#define  EXTI_EMR_MR19                       ((uint32_t)0x00080000U)        /*!< Event Mask on line 19 */
#define  EXTI_EMR_MR20                       ((uint32_t)0x00100000U)        /*!< Event Mask on line 20 */
#define  EXTI_EMR_MR21                       ((uint32_t)0x00200000U)        /*!< Event Mask on line 21 */
#define  EXTI_EMR_MR22                       ((uint32_t)0x00400000U)        /*!< Event Mask on line 22 */
#define  EXTI_EMR_MR23                       ((uint32_t)0x00800000U)        /*!< Event Mask on line 23 */
#define  EXTI_EMR_MR24                       ((uint32_t)0x01000000U)        /*!< Event Mask on line 24 */
#define  EXTI_EMR_MR25                       ((uint32_t)0x02000000U)        /*!< Event Mask on line 25 */
#define  EXTI_EMR_MR26                       ((uint32_t)0x04000000U)        /*!< Event Mask on line 26 */
#define  EXTI_EMR_MR27                       ((uint32_t)0x08000000U)        /*!< Event Mask on line 27 */
#define  EXTI_EMR_MR28                       ((uint32_t)0x10000000U)        /*!< Event Mask on line 28 */
#define  EXTI_EMR_MR29                       ((uint32_t)0x20000000U)        /*!< Event Mask on line 29 */
#define  EXTI_EMR_MR30                       ((uint32_t)0x40000000U)        /*!< Event Mask on line 30 */
#define  EXTI_EMR_MR31                       ((uint32_t)0x80000000U)        /*!< Event Mask on line 31 */

/* References Defines */
#define  EXTI_EMR_EM0 EXTI_EMR_MR0
#define  EXTI_EMR_EM1 EXTI_EMR_MR1
#define  EXTI_EMR_EM2 EXTI_EMR_MR2
#define  EXTI_EMR_EM3 EXTI_EMR_MR3
#define  EXTI_EMR_EM4 EXTI_EMR_MR4
#define  EXTI_EMR_EM5 EXTI_EMR_MR5
#define  EXTI_EMR_EM6 EXTI_EMR_MR6
#define  EXTI_EMR_EM7 EXTI_EMR_MR7
#define  EXTI_EMR_EM8 EXTI_EMR_MR8
#define  EXTI_EMR_EM9 EXTI_EMR_MR9
#define  EXTI_EMR_EM10 EXTI_EMR_MR10
#define  EXTI_EMR_EM11 EXTI_EMR_MR11
#define  EXTI_EMR_EM12 EXTI_EMR_MR12
#define  EXTI_EMR_EM13 EXTI_EMR_MR13
#define  EXTI_EMR_EM14 EXTI_EMR_MR14
#define  EXTI_EMR_EM15 EXTI_EMR_MR15
#define  EXTI_EMR_EM16 EXTI_EMR_MR16
#define  EXTI_EMR_EM17 EXTI_EMR_MR17
#define  EXTI_EMR_EM18 EXTI_EMR_MR18
#define  EXTI_EMR_EM19 EXTI_EMR_MR19
#define  EXTI_EMR_EM20 EXTI_EMR_MR20
#define  EXTI_EMR_EM21 EXTI_EMR_MR21
#define  EXTI_EMR_EM22 EXTI_EMR_MR22
#define  EXTI_EMR_EM23 EXTI_EMR_MR23
#define  EXTI_EMR_EM24 EXTI_EMR_MR24
#define  EXTI_EMR_EM25 EXTI_EMR_MR25
#define  EXTI_EMR_EM26 EXTI_EMR_MR26
#define  EXTI_EMR_EM27 EXTI_EMR_MR27
#define  EXTI_EMR_EM28 EXTI_EMR_MR28
#define  EXTI_EMR_EM29 EXTI_EMR_MR29
#define  EXTI_EMR_EM30 EXTI_EMR_MR30
#define  EXTI_EMR_EM31 EXTI_EMR_MR31

/******************  Bit definition for EXTI_RTSR register  *******************/
#define  EXTI_RTSR_TR0                       ((uint32_t)0x00000001U)        /*!< Rising trigger event configuration bit of line 0 */
#define  EXTI_RTSR_TR1                       ((uint32_t)0x00000002U)        /*!< Rising trigger event configuration bit of line 1 */
#define  EXTI_RTSR_TR2                       ((uint32_t)0x00000004U)        /*!< Rising trigger event configuration bit of line 2 */
#define  EXTI_RTSR_TR3                       ((uint32_t)0x00000008U)        /*!< Rising trigger event configuration bit of line 3 */
#define  EXTI_RTSR_TR4                       ((uint32_t)0x00000010U)        /*!< Rising trigger event configuration bit of line 4 */
#define  EXTI_RTSR_TR5                       ((uint32_t)0x00000020U)        /*!< Rising trigger event configuration bit of line 5 */
#define  EXTI_RTSR_TR6                       ((uint32_t)0x00000040U)        /*!< Rising trigger event configuration bit of line 6 */
#define  EXTI_RTSR_TR7                       ((uint32_t)0x00000080U)        /*!< Rising trigger event configuration bit of line 7 */
#define  EXTI_RTSR_TR8                       ((uint32_t)0x00000100U)        /*!< Rising trigger event configuration bit of line 8 */
#define  EXTI_RTSR_TR9                       ((uint32_t)0x00000200U)        /*!< Rising trigger event configuration bit of line 9 */
#define  EXTI_RTSR_TR10                      ((uint32_t)0x00000400U)        /*!< Rising trigger event configuration bit of line 10 */
#define  EXTI_RTSR_TR11                      ((uint32_t)0x00000800U)        /*!< Rising trigger event configuration bit of line 11 */
#define  EXTI_RTSR_TR12                      ((uint32_t)0x00001000U)        /*!< Rising trigger event configuration bit of line 12 */
#define  EXTI_RTSR_TR13                      ((uint32_t)0x00002000U)        /*!< Rising trigger event configuration bit of line 13 */
#define  EXTI_RTSR_TR14                      ((uint32_t)0x00004000U)        /*!< Rising trigger event configuration bit of line 14 */
#define  EXTI_RTSR_TR15                      ((uint32_t)0x00008000U)        /*!< Rising trigger event configuration bit of line 15 */
#define  EXTI_RTSR_TR16                      ((uint32_t)0x00010000U)        /*!< Rising trigger event configuration bit of line 16 */
#define  EXTI_RTSR_TR17                      ((uint32_t)0x00020000U)        /*!< Rising trigger event configuration bit of line 17 */
#define  EXTI_RTSR_TR18                      ((uint32_t)0x00040000U)        /*!< Rising trigger event configuration bit of line 18 */
#define  EXTI_RTSR_TR19                      ((uint32_t)0x00080000U)        /*!< Rising trigger event configuration bit of line 19 */
#define  EXTI_RTSR_TR20                      ((uint32_t)0x00100000U)        /*!< Rising trigger event configuration bit of line 20 */
#define  EXTI_RTSR_TR21                      ((uint32_t)0x00200000U)        /*!< Rising trigger event configuration bit of line 21 */
#define  EXTI_RTSR_TR22                      ((uint32_t)0x00400000U)        /*!< Rising trigger event configuration bit of line 22 */
#define  EXTI_RTSR_TR29                      ((uint32_t)0x20000000U)        /*!< Rising trigger event configuration bit of line 29 */
#define  EXTI_RTSR_TR30                      ((uint32_t)0x40000000U)        /*!< Rising trigger event configuration bit of line 30 */
#define  EXTI_RTSR_TR31                      ((uint32_t)0x80000000U)        /*!< Rising trigger event configuration bit of line 31 */

/* References Defines */
#define EXTI_RTSR_RT0 EXTI_RTSR_TR0
#define EXTI_RTSR_RT1 EXTI_RTSR_TR1
#define EXTI_RTSR_RT2 EXTI_RTSR_TR2
#define EXTI_RTSR_RT3 EXTI_RTSR_TR3
#define EXTI_RTSR_RT4 EXTI_RTSR_TR4
#define EXTI_RTSR_RT5 EXTI_RTSR_TR5
#define EXTI_RTSR_RT6 EXTI_RTSR_TR6
#define EXTI_RTSR_RT7 EXTI_RTSR_TR7
#define EXTI_RTSR_RT8 EXTI_RTSR_TR8
#define EXTI_RTSR_RT9 EXTI_RTSR_TR9
#define EXTI_RTSR_RT10 EXTI_RTSR_TR10
#define EXTI_RTSR_RT11 EXTI_RTSR_TR11
#define EXTI_RTSR_RT12 EXTI_RTSR_TR12
#define EXTI_RTSR_RT13 EXTI_RTSR_TR13
#define EXTI_RTSR_RT14 EXTI_RTSR_TR14
#define EXTI_RTSR_RT15 EXTI_RTSR_TR15
#define EXTI_RTSR_RT16 EXTI_RTSR_TR16
#define EXTI_RTSR_RT17 EXTI_RTSR_TR17
#define EXTI_RTSR_RT18 EXTI_RTSR_TR18
#define EXTI_RTSR_RT19 EXTI_RTSR_TR19
#define EXTI_RTSR_RT20 EXTI_RTSR_TR20
#define EXTI_RTSR_RT21 EXTI_RTSR_TR21
#define EXTI_RTSR_RT22 EXTI_RTSR_TR22
#define EXTI_RTSR_RT29 EXTI_RTSR_TR29
#define EXTI_RTSR_RT30 EXTI_RTSR_TR30
#define EXTI_RTSR_RT31 EXTI_RTSR_TR31

/******************  Bit definition for EXTI_FTSR register  *******************/
#define  EXTI_FTSR_TR0                       ((uint32_t)0x00000001U)        /*!< Falling trigger event configuration bit of line 0 */
#define  EXTI_FTSR_TR1                       ((uint32_t)0x00000002U)        /*!< Falling trigger event configuration bit of line 1 */
#define  EXTI_FTSR_TR2                       ((uint32_t)0x00000004U)        /*!< Falling trigger event configuration bit of line 2 */
#define  EXTI_FTSR_TR3                       ((uint32_t)0x00000008U)        /*!< Falling trigger event configuration bit of line 3 */
#define  EXTI_FTSR_TR4                       ((uint32_t)0x00000010U)        /*!< Falling trigger event configuration bit of line 4 */
#define  EXTI_FTSR_TR5                       ((uint32_t)0x00000020U)        /*!< Falling trigger event configuration bit of line 5 */
#define  EXTI_FTSR_TR6                       ((uint32_t)0x00000040U)        /*!< Falling trigger event configuration bit of line 6 */
#define  EXTI_FTSR_TR7                       ((uint32_t)0x00000080U)        /*!< Falling trigger event configuration bit of line 7 */
#define  EXTI_FTSR_TR8                       ((uint32_t)0x00000100U)        /*!< Falling trigger event configuration bit of line 8 */
#define  EXTI_FTSR_TR9                       ((uint32_t)0x00000200U)        /*!< Falling trigger event configuration bit of line 9 */
#define  EXTI_FTSR_TR10                      ((uint32_t)0x00000400U)        /*!< Falling trigger event configuration bit of line 10 */
#define  EXTI_FTSR_TR11                      ((uint32_t)0x00000800U)        /*!< Falling trigger event configuration bit of line 11 */
#define  EXTI_FTSR_TR12                      ((uint32_t)0x00001000U)        /*!< Falling trigger event configuration bit of line 12 */
#define  EXTI_FTSR_TR13                      ((uint32_t)0x00002000U)        /*!< Falling trigger event configuration bit of line 13 */
#define  EXTI_FTSR_TR14                      ((uint32_t)0x00004000U)        /*!< Falling trigger event configuration bit of line 14 */
#define  EXTI_FTSR_TR15                      ((uint32_t)0x00008000U)        /*!< Falling trigger event configuration bit of line 15 */
#define  EXTI_FTSR_TR16                      ((uint32_t)0x00010000U)        /*!< Falling trigger event configuration bit of line 16 */
#define  EXTI_FTSR_TR17                      ((uint32_t)0x00020000U)        /*!< Falling trigger event configuration bit of line 17 */
#define  EXTI_FTSR_TR18                      ((uint32_t)0x00040000U)        /*!< Falling trigger event configuration bit of line 18 */
#define  EXTI_FTSR_TR19                      ((uint32_t)0x00080000U)        /*!< Falling trigger event configuration bit of line 19 */
#define  EXTI_FTSR_TR20                      ((uint32_t)0x00100000U)        /*!< Falling trigger event configuration bit of line 20 */
#define  EXTI_FTSR_TR21                      ((uint32_t)0x00200000U)        /*!< Falling trigger event configuration bit of line 21 */
#define  EXTI_FTSR_TR22                      ((uint32_t)0x00400000U)        /*!< Falling trigger event configuration bit of line 22 */
#define  EXTI_FTSR_TR29                      ((uint32_t)0x20000000U)        /*!< Falling trigger event configuration bit of line 29 */
#define  EXTI_FTSR_TR30                      ((uint32_t)0x40000000U)        /*!< Falling trigger event configuration bit of line 30 */
#define  EXTI_FTSR_TR31                      ((uint32_t)0x80000000U)        /*!< Falling trigger event configuration bit of line 31 */

/* References Defines */
#define EXTI_FTSR_FT0 EXTI_FTSR_TR0
#define EXTI_FTSR_FT1 EXTI_FTSR_TR1
#define EXTI_FTSR_FT2 EXTI_FTSR_TR2
#define EXTI_FTSR_FT3 EXTI_FTSR_TR3
#define EXTI_FTSR_FT4 EXTI_FTSR_TR4
#define EXTI_FTSR_FT5 EXTI_FTSR_TR5
#define EXTI_FTSR_FT6 EXTI_FTSR_TR6
#define EXTI_FTSR_FT7 EXTI_FTSR_TR7
#define EXTI_FTSR_FT8 EXTI_FTSR_TR8
#define EXTI_FTSR_FT9 EXTI_FTSR_TR9
#define EXTI_FTSR_FT10 EXTI_FTSR_TR10
#define EXTI_FTSR_FT11 EXTI_FTSR_TR11
#define EXTI_FTSR_FT12 EXTI_FTSR_TR12
#define EXTI_FTSR_FT13 EXTI_FTSR_TR13
#define EXTI_FTSR_FT14 EXTI_FTSR_TR14
#define EXTI_FTSR_FT15 EXTI_FTSR_TR15
#define EXTI_FTSR_FT16 EXTI_FTSR_TR16
#define EXTI_FTSR_FT17 EXTI_FTSR_TR17
#define  EXTI_FTSR_FT18 EXTI_FTSR_TR18
#define  EXTI_FTSR_FT19 EXTI_FTSR_TR19
#define  EXTI_FTSR_FT20 EXTI_FTSR_TR20
#define  EXTI_FTSR_FT21 EXTI_FTSR_TR21
#define  EXTI_FTSR_FT22 EXTI_FTSR_TR22
#define  EXTI_FTSR_FT29 EXTI_FTSR_TR29
#define  EXTI_FTSR_FT30 EXTI_FTSR_TR30
#define  EXTI_FTSR_FT31 EXTI_FTSR_TR31

/******************  Bit definition for EXTI_SWIER register  ******************/
#define  EXTI_SWIER_SWIER0                   ((uint32_t)0x00000001U)        /*!< Software Interrupt on line 0 */
#define  EXTI_SWIER_SWIER1                   ((uint32_t)0x00000002U)        /*!< Software Interrupt on line 1 */
#define  EXTI_SWIER_SWIER2                   ((uint32_t)0x00000004U)        /*!< Software Interrupt on line 2 */
#define  EXTI_SWIER_SWIER3                   ((uint32_t)0x00000008U)        /*!< Software Interrupt on line 3 */
#define  EXTI_SWIER_SWIER4                   ((uint32_t)0x00000010U)        /*!< Software Interrupt on line 4 */
#define  EXTI_SWIER_SWIER5                   ((uint32_t)0x00000020U)        /*!< Software Interrupt on line 5 */
#define  EXTI_SWIER_SWIER6                   ((uint32_t)0x00000040U)        /*!< Software Interrupt on line 6 */
#define  EXTI_SWIER_SWIER7                   ((uint32_t)0x00000080U)        /*!< Software Interrupt on line 7 */
#define  EXTI_SWIER_SWIER8                   ((uint32_t)0x00000100U)        /*!< Software Interrupt on line 8 */
#define  EXTI_SWIER_SWIER9                   ((uint32_t)0x00000200U)        /*!< Software Interrupt on line 9 */
#define  EXTI_SWIER_SWIER10                  ((uint32_t)0x00000400U)        /*!< Software Interrupt on line 10 */
#define  EXTI_SWIER_SWIER11                  ((uint32_t)0x00000800U)        /*!< Software Interrupt on line 11 */
#define  EXTI_SWIER_SWIER12                  ((uint32_t)0x00001000U)        /*!< Software Interrupt on line 12 */
#define  EXTI_SWIER_SWIER13                  ((uint32_t)0x00002000U)        /*!< Software Interrupt on line 13 */
#define  EXTI_SWIER_SWIER14                  ((uint32_t)0x00004000U)        /*!< Software Interrupt on line 14 */
#define  EXTI_SWIER_SWIER15                  ((uint32_t)0x00008000U)        /*!< Software Interrupt on line 15 */
#define  EXTI_SWIER_SWIER16                  ((uint32_t)0x00010000U)        /*!< Software Interrupt on line 16 */
#define  EXTI_SWIER_SWIER17                  ((uint32_t)0x00020000U)        /*!< Software Interrupt on line 17 */
#define  EXTI_SWIER_SWIER18                  ((uint32_t)0x00040000U)        /*!< Software Interrupt on line 18 */
#define  EXTI_SWIER_SWIER19                  ((uint32_t)0x00080000U)        /*!< Software Interrupt on line 19 */
#define  EXTI_SWIER_SWIER20                  ((uint32_t)0x00100000U)        /*!< Software Interrupt on line 20 */
#define  EXTI_SWIER_SWIER21                  ((uint32_t)0x00200000U)        /*!< Software Interrupt on line 21 */
#define  EXTI_SWIER_SWIER22                  ((uint32_t)0x00400000U)        /*!< Software Interrupt on line 22 */
#define  EXTI_SWIER_SWIER29                  ((uint32_t)0x20000000U)        /*!< Software Interrupt on line 29 */
#define  EXTI_SWIER_SWIER30                  ((uint32_t)0x40000000U)        /*!< Software Interrupt on line 30 */
#define  EXTI_SWIER_SWIER31                  ((uint32_t)0x80000000U)        /*!< Software Interrupt on line 31 */

/* References Defines */
#define EXTI_SWIER_SWI0 EXTI_SWIER_SWIER0
#define EXTI_SWIER_SWI1 EXTI_SWIER_SWIER1
#define EXTI_SWIER_SWI2 EXTI_SWIER_SWIER2
#define EXTI_SWIER_SWI3 EXTI_SWIER_SWIER3
#define EXTI_SWIER_SWI4 EXTI_SWIER_SWIER4
#define EXTI_SWIER_SWI5 EXTI_SWIER_SWIER5
#define EXTI_SWIER_SWI6 EXTI_SWIER_SWIER6
#define EXTI_SWIER_SWI7 EXTI_SWIER_SWIER7
#define EXTI_SWIER_SWI8 EXTI_SWIER_SWIER8
#define EXTI_SWIER_SWI9 EXTI_SWIER_SWIER9
#define EXTI_SWIER_SWI10 EXTI_SWIER_SWIER10
#define EXTI_SWIER_SWI11 EXTI_SWIER_SWIER11
#define EXTI_SWIER_SWI12 EXTI_SWIER_SWIER12
#define EXTI_SWIER_SWI13 EXTI_SWIER_SWIER13
#define EXTI_SWIER_SWI14 EXTI_SWIER_SWIER14
#define EXTI_SWIER_SWI15 EXTI_SWIER_SWIER15
#define EXTI_SWIER_SWI16 EXTI_SWIER_SWIER16
#define EXTI_SWIER_SWI17 EXTI_SWIER_SWIER17
#define  EXTI_SWIER_SWI18 EXTI_SWIER_SWIER18
#define  EXTI_SWIER_SWI19 EXTI_SWIER_SWIER19
#define  EXTI_SWIER_SWI20 EXTI_SWIER_SWIER20
#define  EXTI_SWIER_SWI21 EXTI_SWIER_SWIER21
#define  EXTI_SWIER_SWI22 EXTI_SWIER_SWIER22
#define  EXTI_SWIER_SWI29 EXTI_SWIER_SWIER29
#define  EXTI_SWIER_SWI30 EXTI_SWIER_SWIER30
#define  EXTI_SWIER_SWI31 EXTI_SWIER_SWIER31

/*******************  Bit definition for EXTI_PR register  ********************/
#define  EXTI_PR_PR0                         ((uint32_t)0x00000001U)        /*!< Pending bit for line 0 */
#define  EXTI_PR_PR1                         ((uint32_t)0x00000002U)        /*!< Pending bit for line 1 */
#define  EXTI_PR_PR2                         ((uint32_t)0x00000004U)        /*!< Pending bit for line 2 */
#define  EXTI_PR_PR3                         ((uint32_t)0x00000008U)        /*!< Pending bit for line 3 */
#define  EXTI_PR_PR4                         ((uint32_t)0x00000010U)        /*!< Pending bit for line 4 */
#define  EXTI_PR_PR5                         ((uint32_t)0x00000020U)        /*!< Pending bit for line 5 */
#define  EXTI_PR_PR6                         ((uint32_t)0x00000040U)        /*!< Pending bit for line 6 */
#define  EXTI_PR_PR7                         ((uint32_t)0x00000080U)        /*!< Pending bit for line 7 */
#define  EXTI_PR_PR8                         ((uint32_t)0x00000100U)        /*!< Pending bit for line 8 */
#define  EXTI_PR_PR9                         ((uint32_t)0x00000200U)        /*!< Pending bit for line 9 */
#define  EXTI_PR_PR10                        ((uint32_t)0x00000400U)        /*!< Pending bit for line 10 */
#define  EXTI_PR_PR11                        ((uint32_t)0x00000800U)        /*!< Pending bit for line 11 */
#define  EXTI_PR_PR12                        ((uint32_t)0x00001000U)        /*!< Pending bit for line 12 */
#define  EXTI_PR_PR13                        ((uint32_t)0x00002000U)        /*!< Pending bit for line 13 */
#define  EXTI_PR_PR14                        ((uint32_t)0x00004000U)        /*!< Pending bit for line 14 */
#define  EXTI_PR_PR15                        ((uint32_t)0x00008000U)        /*!< Pending bit for line 15 */
#define  EXTI_PR_PR16                        ((uint32_t)0x00010000U)        /*!< Pending bit for line 16 */
#define  EXTI_PR_PR17                        ((uint32_t)0x00020000U)        /*!< Pending bit for line 17 */
#define  EXTI_PR_PR18                        ((uint32_t)0x00040000U)        /*!< Pending bit for line 18 */
#define  EXTI_PR_PR19                        ((uint32_t)0x00080000U)        /*!< Pending bit for line 19 */
#define  EXTI_PR_PR20                        ((uint32_t)0x00100000U)        /*!< Pending bit for line 20 */
#define  EXTI_PR_PR21                        ((uint32_t)0x00200000U)        /*!< Pending bit for line 21 */
#define  EXTI_PR_PR22                        ((uint32_t)0x00400000U)        /*!< Pending bit for line 22 */
#define  EXTI_PR_PR29                        ((uint32_t)0x20000000U)        /*!< Pending bit for line 29 */
#define  EXTI_PR_PR30                        ((uint32_t)0x40000000U)        /*!< Pending bit for line 30 */
#define  EXTI_PR_PR31                        ((uint32_t)0x80000000U)        /*!< Pending bit for line 31 */

/* References Defines */
#define EXTI_PR_PIF0 EXTI_PR_PR0
#define EXTI_PR_PIF1 EXTI_PR_PR1
#define EXTI_PR_PIF2 EXTI_PR_PR2
#define EXTI_PR_PIF3 EXTI_PR_PR3
#define EXTI_PR_PIF4 EXTI_PR_PR4
#define EXTI_PR_PIF5 EXTI_PR_PR5
#define EXTI_PR_PIF6 EXTI_PR_PR6
#define EXTI_PR_PIF7 EXTI_PR_PR7
#define EXTI_PR_PIF8 EXTI_PR_PR8
#define EXTI_PR_PIF9 EXTI_PR_PR9
#define EXTI_PR_PIF10 EXTI_PR_PR10
#define EXTI_PR_PIF11 EXTI_PR_PR11
#define EXTI_PR_PIF12 EXTI_PR_PR12
#define EXTI_PR_PIF13 EXTI_PR_PR13
#define EXTI_PR_PIF14 EXTI_PR_PR14
#define EXTI_PR_PIF15 EXTI_PR_PR15
#define EXTI_PR_PIF16 EXTI_PR_PR16
#define EXTI_PR_PIF17 EXTI_PR_PR17
#define  EXTI_PR_PIF18 EXTI_PR_PR18
#define  EXTI_PR_PIF19 EXTI_PR_PR19
#define  EXTI_PR_PIF20 EXTI_PR_PR20
#define  EXTI_PR_PIF21 EXTI_PR_PR21
#define  EXTI_PR_PIF22 EXTI_PR_PR22
#define  EXTI_PR_PIF29 EXTI_PR_PR29
#define  EXTI_PR_PIF30 EXTI_PR_PR30
#define  EXTI_PR_PIF31 EXTI_PR_PR31

#define EXTI_32_63_SUPPORT /* EXTI support more than 32 lines */

/*******************  Bit definition for EXTI_IMR2 register  ******************/
#define  EXTI_IMR2_MR32                      ((uint32_t)0x00000001U)        /*!< Interrupt Mask on line 32 */
#define  EXTI_IMR2_MR33                      ((uint32_t)0x00000002U)        /*!< Interrupt Mask on line 33 */
#define  EXTI_IMR2_MR34                      ((uint32_t)0x00000004U)        /*!< Interrupt Mask on line 34 */
#define  EXTI_IMR2_MR35                      ((uint32_t)0x00000008U)        /*!< Interrupt Mask on line 35 */

/* References Defines */
#define  EXTI_IMR2_IM32 EXTI_IMR2_MR32
#define  EXTI_IMR2_IM33 EXTI_IMR2_MR33
#define  EXTI_IMR2_IM34 EXTI_IMR2_MR34
#define  EXTI_IMR2_IM35 EXTI_IMR2_MR35

#define  EXTI_IMR2_IM   ((uint32_t)0x0000000FU)

/*******************  Bit definition for EXTI_EMR2 ****************************/
#define  EXTI_EMR2_MR32                      ((uint32_t)0x00000001U)        /*!< Event Mask on line 32 */
#define  EXTI_EMR2_MR33                      ((uint32_t)0x00000002U)        /*!< Event Mask on line 33 */
#define  EXTI_EMR2_MR34                      ((uint32_t)0x00000004U)        /*!< Event Mask on line 34 */
#define  EXTI_EMR2_MR35                      ((uint32_t)0x00000008U)        /*!< Event Mask on line 34 */

/* References Defines */
#define  EXTI_EMR2_EM32 EXTI_EMR2_MR32
#define  EXTI_EMR2_EM33 EXTI_EMR2_MR33
#define  EXTI_EMR2_EM34 EXTI_EMR2_MR34
#define  EXTI_EMR2_EM35 EXTI_EMR2_MR35

/******************  Bit definition for EXTI_RTSR2 register ********************/
#define  EXTI_RTSR2_TR32                     ((uint32_t)0x00000001U)         /*!< Rising trigger event configuration bit of line 32 */
#define  EXTI_RTSR2_TR33                     ((uint32_t)0x00000002U)         /*!< Rising trigger event configuration bit of line 33 */

/* References Defines */
#define  EXTI_RTSR2_RT32 EXTI_RTSR2_TR32
#define  EXTI_RTSR2_RT33 EXTI_RTSR2_TR33

/******************  Bit definition for EXTI_FTSR2 register  ******************/
#define  EXTI_FTSR2_TR32                     ((uint32_t)0x00000001U)        /*!< Falling trigger event configuration bit of line 32 */
#define  EXTI_FTSR2_TR33                     ((uint32_t)0x00000002U)        /*!< Falling trigger event configuration bit of line 33 */

/* References Defines */
#define  EXTI_FTSR2_FT32 EXTI_FTSR2_TR32
#define  EXTI_FTSR2_FT33 EXTI_FTSR2_TR33

/******************  Bit definition for EXTI_SWIER2 register  *****************/
#define  EXTI_SWIER2_SWIER32                 ((uint32_t)0x00000001U)        /*!< Software Interrupt on line 32 */
#define  EXTI_SWIER2_SWIER33                 ((uint32_t)0x00000002U)        /*!< Software Interrupt on line 33 */

/* References Defines */
#define  EXTI_SWIER2_SWI32 EXTI_SWIER2_SWIER32
#define  EXTI_SWIER2_SWI33 EXTI_SWIER2_SWIER33

/*******************  Bit definition for EXTI_PR2 register  *******************/
#define  EXTI_PR2_PR32                       ((uint32_t)0x00000001U)        /*!< Pending bit for line 32 */
#define  EXTI_PR2_PR33                       ((uint32_t)0x00000002U)        /*!< Pending bit for line 33 */

/* References Defines */
#define  EXTI_PR2_PIF32 EXTI_PR2_PR32
#define  EXTI_PR2_PIF33 EXTI_PR2_PR33

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for FLASH_ACR register  ******************/
#define  FLASH_ACR_LATENCY                   ((uint32_t)0x00000007U)        /*!< LATENCY[2:0] bits (Latency) */
#define  FLASH_ACR_LATENCY_0                 ((uint32_t)0x00000001U)        /*!< Bit 0 */
#define  FLASH_ACR_LATENCY_1                 ((uint32_t)0x00000002U)        /*!< Bit 1 */
#define  FLASH_ACR_LATENCY_2                 ((uint32_t)0x00000004U)        /*!< Bit 2 */

#define  FLASH_ACR_HLFCYA                    ((uint32_t)0x00000008U)        /*!< Flash Half Cycle Access Enable */
#define  FLASH_ACR_PRFTBE                    ((uint32_t)0x00000010U)        /*!< Prefetch Buffer Enable */
#define  FLASH_ACR_PRFTBS                    ((uint32_t)0x00000020U)        /*!< Prefetch Buffer Status */

/******************  Bit definition for FLASH_KEYR register  ******************/
#define  FLASH_KEYR_FKEYR                    ((uint32_t)0xFFFFFFFFU)        /*!< FPEC Key */

#define  RDP_KEY                             ((uint32_t)0x000000A5U)        /*!< RDP Key */
#define  FLASH_KEY1                          ((uint32_t)0x45670123U)        /*!< FPEC Key1 */
#define  FLASH_KEY2                          ((uint32_t)0xCDEF89ABU)        /*!< FPEC Key2 */

/*****************  Bit definition for FLASH_OPTKEYR register  ****************/
#define  FLASH_OPTKEYR_OPTKEYR               ((uint32_t)0xFFFFFFFFU)        /*!< Option Byte Key */

#define  FLASH_OPTKEY1                       FLASH_KEY1                    /*!< Option Byte Key1 */
#define  FLASH_OPTKEY2                       FLASH_KEY2                    /*!< Option Byte Key2 */

/******************  Bit definition for FLASH_SR register  *******************/
#define  FLASH_SR_BSY                        ((uint32_t)0x00000001U)        /*!< Busy */
#define  FLASH_SR_PGERR                      ((uint32_t)0x00000004U)        /*!< Programming Error */
#define  FLASH_SR_WRPERR                     ((uint32_t)0x00000010U)        /*!< Write Protection Error */
#define  FLASH_SR_EOP                        ((uint32_t)0x00000020U)        /*!< End of operation */

/*******************  Bit definition for FLASH_CR register  *******************/
#define  FLASH_CR_PG                         ((uint32_t)0x00000001U)        /*!< Programming */
#define  FLASH_CR_PER                        ((uint32_t)0x00000002U)        /*!< Page Erase */
#define  FLASH_CR_MER                        ((uint32_t)0x00000004U)        /*!< Mass Erase */
#define  FLASH_CR_OPTPG                      ((uint32_t)0x00000010U)        /*!< Option Byte Programming */
#define  FLASH_CR_OPTER                      ((uint32_t)0x00000020U)        /*!< Option Byte Erase */
#define  FLASH_CR_STRT                       ((uint32_t)0x00000040U)        /*!< Start */
#define  FLASH_CR_LOCK                       ((uint32_t)0x00000080U)        /*!< Lock */
#define  FLASH_CR_OPTWRE                     ((uint32_t)0x00000200U)        /*!< Option Bytes Write Enable */
#define  FLASH_CR_ERRIE                      ((uint32_t)0x00000400U)        /*!< Error Interrupt Enable */
#define  FLASH_CR_EOPIE                      ((uint32_t)0x00001000U)        /*!< End of operation interrupt enable */
#define  FLASH_CR_OBL_LAUNCH                 ((uint32_t)0x00002000U)        /*!< OptionBytes Loader Launch */

/*******************  Bit definition for FLASH_AR register  *******************/
#define  FLASH_AR_FAR                        ((uint32_t)0xFFFFFFFFU)        /*!< Flash Address */

/******************  Bit definition for FLASH_OBR register  *******************/
#define  FLASH_OBR_OPTERR                    ((uint32_t)0x00000001U)        /*!< Option Byte Error */
#define  FLASH_OBR_RDPRT                     ((uint32_t)0x00000006U)        /*!< Read protection */
#define  FLASH_OBR_RDPRT_1                   ((uint32_t)0x00000002U)        /*!< Read protection Level 1 */
#define  FLASH_OBR_RDPRT_2                   ((uint32_t)0x00000006U)        /*!< Read protection Level 2 */

#define  FLASH_OBR_USER                      ((uint32_t)0x00007700U)        /*!< User Option Bytes */
#define  FLASH_OBR_IWDG_SW                   ((uint32_t)0x00000100U)        /*!< IWDG SW */
#define  FLASH_OBR_nRST_STOP                 ((uint32_t)0x00000200U)        /*!< nRST_STOP */
#define  FLASH_OBR_nRST_STDBY                ((uint32_t)0x00000400U)        /*!< nRST_STDBY */
#define  FLASH_OBR_nBOOT1                    ((uint32_t)0x00001000U)        /*!< nBOOT1 */
#define  FLASH_OBR_VDDA_MONITOR              ((uint32_t)0x00002000U)        /*!< VDDA_MONITOR */
#define  FLASH_OBR_SRAM_PE                   ((uint32_t)0x00004000U)        /*!< SRAM_PE */
#define  FLASH_OBR_DATA0                     ((uint32_t)0x00FF0000U) /*!< Data0 */
#define  FLASH_OBR_DATA1                     ((uint32_t)0xFF000000U) /*!< Data1 */

/* Legacy defines */
#define FLASH_OBR_WDG_SW FLASH_OBR_IWDG_SW

/******************  Bit definition for FLASH_WRPR register  ******************/
#define  FLASH_WRPR_WRP                        ((uint32_t)0xFFFFFFFFU)      /*!< Write Protect */

/*----------------------------------------------------------------------------*/

/******************  Bit definition for OB_RDP register  **********************/
#define  OB_RDP_RDP                          ((uint32_t)0x000000FFU)        /*!< Read protection option byte */
#define  OB_RDP_nRDP                         ((uint32_t)0x0000FF00U)        /*!< Read protection complemented option byte */

/******************  Bit definition for OB_USER register  *********************/
#define  OB_USER_USER                        ((uint32_t)0x00FF0000U)        /*!< User option byte */
#define  OB_USER_nUSER                       ((uint32_t)0xFF000000U)        /*!< User complemented option byte */

/******************  Bit definition for FLASH_WRP0 register  ******************/
#define  OB_WRP0_WRP0                        ((uint32_t)0x000000FFU)        /*!< Flash memory write protection option bytes */
#define  OB_WRP0_nWRP0                       ((uint32_t)0x0000FF00U)        /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for FLASH_WRP1 register  ******************/
#define  OB_WRP1_WRP1                        ((uint32_t)0x00FF0000U)        /*!< Flash memory write protection option bytes */
#define  OB_WRP1_nWRP1                       ((uint32_t)0xFF000000U)        /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for FLASH_WRP2 register  ******************/
#define  OB_WRP2_WRP2                        ((uint32_t)0x000000FFU)        /*!< Flash memory write protection option bytes */
#define  OB_WRP2_nWRP2                       ((uint32_t)0x0000FF00U)        /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for FLASH_WRP3 register  ******************/
#define  OB_WRP3_WRP3                        ((uint32_t)0x00FF0000U)        /*!< Flash memory write protection option bytes */
#define  OB_WRP3_nWRP3                       ((uint32_t)0xFF000000U)        /*!< Flash memory write protection complemented option bytes */

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O (GPIO)                      */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0          ((uint32_t)0x00000003U)
#define GPIO_MODER_MODER0_0        ((uint32_t)0x00000001U)
#define GPIO_MODER_MODER0_1        ((uint32_t)0x00000002U)
#define GPIO_MODER_MODER1          ((uint32_t)0x0000000CU)
#define GPIO_MODER_MODER1_0        ((uint32_t)0x00000004U)
#define GPIO_MODER_MODER1_1        ((uint32_t)0x00000008U)
#define GPIO_MODER_MODER2          ((uint32_t)0x00000030U)
#define GPIO_MODER_MODER2_0        ((uint32_t)0x00000010U)
#define GPIO_MODER_MODER2_1        ((uint32_t)0x00000020U)
#define GPIO_MODER_MODER3          ((uint32_t)0x000000C0U)
#define GPIO_MODER_MODER3_0        ((uint32_t)0x00000040U)
#define GPIO_MODER_MODER3_1        ((uint32_t)0x00000080U)
#define GPIO_MODER_MODER4          ((uint32_t)0x00000300U)
#define GPIO_MODER_MODER4_0        ((uint32_t)0x00000100U)
#define GPIO_MODER_MODER4_1        ((uint32_t)0x00000200U)
#define GPIO_MODER_MODER5          ((uint32_t)0x00000C00U)
#define GPIO_MODER_MODER5_0        ((uint32_t)0x00000400U)
#define GPIO_MODER_MODER5_1        ((uint32_t)0x00000800U)
#define GPIO_MODER_MODER6          ((uint32_t)0x00003000U)
#define GPIO_MODER_MODER6_0        ((uint32_t)0x00001000U)
#define GPIO_MODER_MODER6_1        ((uint32_t)0x00002000U)
#define GPIO_MODER_MODER7          ((uint32_t)0x0000C000U)
#define GPIO_MODER_MODER7_0        ((uint32_t)0x00004000U)
#define GPIO_MODER_MODER7_1        ((uint32_t)0x00008000U)
#define GPIO_MODER_MODER8          ((uint32_t)0x00030000U)
#define GPIO_MODER_MODER8_0        ((uint32_t)0x00010000U)
#define GPIO_MODER_MODER8_1        ((uint32_t)0x00020000U)
#define GPIO_MODER_MODER9          ((uint32_t)0x000C0000U)
#define GPIO_MODER_MODER9_0        ((uint32_t)0x00040000U)
#define GPIO_MODER_MODER9_1        ((uint32_t)0x00080000U)
#define GPIO_MODER_MODER10         ((uint32_t)0x00300000U)
#define GPIO_MODER_MODER10_0       ((uint32_t)0x00100000U)
#define GPIO_MODER_MODER10_1       ((uint32_t)0x00200000U)
#define GPIO_MODER_MODER11         ((uint32_t)0x00C00000U)
#define GPIO_MODER_MODER11_0       ((uint32_t)0x00400000U)
#define GPIO_MODER_MODER11_1       ((uint32_t)0x00800000U)
#define GPIO_MODER_MODER12         ((uint32_t)0x03000000U)
#define GPIO_MODER_MODER12_0       ((uint32_t)0x01000000U)
#define GPIO_MODER_MODER12_1       ((uint32_t)0x02000000U)
#define GPIO_MODER_MODER13         ((uint32_t)0x0C000000U)
#define GPIO_MODER_MODER13_0       ((uint32_t)0x04000000U)
#define GPIO_MODER_MODER13_1       ((uint32_t)0x08000000U)
#define GPIO_MODER_MODER14         ((uint32_t)0x30000000U)
#define GPIO_MODER_MODER14_0       ((uint32_t)0x10000000U)
#define GPIO_MODER_MODER14_1       ((uint32_t)0x20000000U)
#define GPIO_MODER_MODER15         ((uint32_t)0xC0000000U)
#define GPIO_MODER_MODER15_0       ((uint32_t)0x40000000U)
#define GPIO_MODER_MODER15_1       ((uint32_t)0x80000000U)

/******************  Bit definition for GPIO_OTYPER register  *****************/
#define GPIO_OTYPER_OT_0           ((uint32_t)0x00000001U)
#define GPIO_OTYPER_OT_1           ((uint32_t)0x00000002U)
#define GPIO_OTYPER_OT_2           ((uint32_t)0x00000004U)
#define GPIO_OTYPER_OT_3           ((uint32_t)0x00000008U)
#define GPIO_OTYPER_OT_4           ((uint32_t)0x00000010U)
#define GPIO_OTYPER_OT_5           ((uint32_t)0x00000020U)
#define GPIO_OTYPER_OT_6           ((uint32_t)0x00000040U)
#define GPIO_OTYPER_OT_7           ((uint32_t)0x00000080U)
#define GPIO_OTYPER_OT_8           ((uint32_t)0x00000100U)
#define GPIO_OTYPER_OT_9           ((uint32_t)0x00000200U)
#define GPIO_OTYPER_OT_10          ((uint32_t)0x00000400U)
#define GPIO_OTYPER_OT_11          ((uint32_t)0x00000800U)
#define GPIO_OTYPER_OT_12          ((uint32_t)0x00001000U)
#define GPIO_OTYPER_OT_13          ((uint32_t)0x00002000U)
#define GPIO_OTYPER_OT_14          ((uint32_t)0x00004000U)
#define GPIO_OTYPER_OT_15          ((uint32_t)0x00008000U)

/****************  Bit definition for GPIO_OSPEEDR register  ******************/
#define GPIO_OSPEEDER_OSPEEDR0     ((uint32_t)0x00000003U)
#define GPIO_OSPEEDER_OSPEEDR0_0   ((uint32_t)0x00000001U)
#define GPIO_OSPEEDER_OSPEEDR0_1   ((uint32_t)0x00000002U)
#define GPIO_OSPEEDER_OSPEEDR1     ((uint32_t)0x0000000CU)
#define GPIO_OSPEEDER_OSPEEDR1_0   ((uint32_t)0x00000004U)
#define GPIO_OSPEEDER_OSPEEDR1_1   ((uint32_t)0x00000008U)
#define GPIO_OSPEEDER_OSPEEDR2     ((uint32_t)0x00000030U)
#define GPIO_OSPEEDER_OSPEEDR2_0   ((uint32_t)0x00000010U)
#define GPIO_OSPEEDER_OSPEEDR2_1   ((uint32_t)0x00000020U)
#define GPIO_OSPEEDER_OSPEEDR3     ((uint32_t)0x000000C0U)
#define GPIO_OSPEEDER_OSPEEDR3_0   ((uint32_t)0x00000040U)
#define GPIO_OSPEEDER_OSPEEDR3_1   ((uint32_t)0x00000080U)
#define GPIO_OSPEEDER_OSPEEDR4     ((uint32_t)0x00000300U)
#define GPIO_OSPEEDER_OSPEEDR4_0   ((uint32_t)0x00000100U)
#define GPIO_OSPEEDER_OSPEEDR4_1   ((uint32_t)0x00000200U)
#define GPIO_OSPEEDER_OSPEEDR5     ((uint32_t)0x00000C00U)
#define GPIO_OSPEEDER_OSPEEDR5_0   ((uint32_t)0x00000400U)
#define GPIO_OSPEEDER_OSPEEDR5_1   ((uint32_t)0x00000800U)
#define GPIO_OSPEEDER_OSPEEDR6     ((uint32_t)0x00003000U)
#define GPIO_OSPEEDER_OSPEEDR6_0   ((uint32_t)0x00001000U)
#define GPIO_OSPEEDER_OSPEEDR6_1   ((uint32_t)0x00002000U)
#define GPIO_OSPEEDER_OSPEEDR7     ((uint32_t)0x0000C000U)
#define GPIO_OSPEEDER_OSPEEDR7_0   ((uint32_t)0x00004000U)
#define GPIO_OSPEEDER_OSPEEDR7_1   ((uint32_t)0x00008000U)
#define GPIO_OSPEEDER_OSPEEDR8     ((uint32_t)0x00030000U)
#define GPIO_OSPEEDER_OSPEEDR8_0   ((uint32_t)0x00010000U)
#define GPIO_OSPEEDER_OSPEEDR8_1   ((uint32_t)0x00020000U)
#define GPIO_OSPEEDER_OSPEEDR9     ((uint32_t)0x000C0000U)
#define GPIO_OSPEEDER_OSPEEDR9_0   ((uint32_t)0x00040000U)
#define GPIO_OSPEEDER_OSPEEDR9_1   ((uint32_t)0x00080000U)
#define GPIO_OSPEEDER_OSPEEDR10    ((uint32_t)0x00300000U)
#define GPIO_OSPEEDER_OSPEEDR10_0  ((uint32_t)0x00100000U)
#define GPIO_OSPEEDER_OSPEEDR10_1  ((uint32_t)0x00200000U)
#define GPIO_OSPEEDER_OSPEEDR11    ((uint32_t)0x00C00000U)
#define GPIO_OSPEEDER_OSPEEDR11_0  ((uint32_t)0x00400000U)
#define GPIO_OSPEEDER_OSPEEDR11_1  ((uint32_t)0x00800000U)
#define GPIO_OSPEEDER_OSPEEDR12    ((uint32_t)0x03000000U)
#define GPIO_OSPEEDER_OSPEEDR12_0  ((uint32_t)0x01000000U)
#define GPIO_OSPEEDER_OSPEEDR12_1  ((uint32_t)0x02000000U)
#define GPIO_OSPEEDER_OSPEEDR13    ((uint32_t)0x0C000000U)
#define GPIO_OSPEEDER_OSPEEDR13_0  ((uint32_t)0x04000000U)
#define GPIO_OSPEEDER_OSPEEDR13_1  ((uint32_t)0x08000000U)
#define GPIO_OSPEEDER_OSPEEDR14    ((uint32_t)0x30000000U)
#define GPIO_OSPEEDER_OSPEEDR14_0  ((uint32_t)0x10000000U)
#define GPIO_OSPEEDER_OSPEEDR14_1  ((uint32_t)0x20000000U)
#define GPIO_OSPEEDER_OSPEEDR15    ((uint32_t)0xC0000000U)
#define GPIO_OSPEEDER_OSPEEDR15_0  ((uint32_t)0x40000000U)
#define GPIO_OSPEEDER_OSPEEDR15_1  ((uint32_t)0x80000000U)

/*******************  Bit definition for GPIO_PUPDR register ******************/
#define GPIO_PUPDR_PUPDR0          ((uint32_t)0x00000003U)
#define GPIO_PUPDR_PUPDR0_0        ((uint32_t)0x00000001U)
#define GPIO_PUPDR_PUPDR0_1        ((uint32_t)0x00000002U)
#define GPIO_PUPDR_PUPDR1          ((uint32_t)0x0000000CU)
#define GPIO_PUPDR_PUPDR1_0        ((uint32_t)0x00000004U)
#define GPIO_PUPDR_PUPDR1_1        ((uint32_t)0x00000008U)
#define GPIO_PUPDR_PUPDR2          ((uint32_t)0x00000030U)
#define GPIO_PUPDR_PUPDR2_0        ((uint32_t)0x00000010U)
#define GPIO_PUPDR_PUPDR2_1        ((uint32_t)0x00000020U)
#define GPIO_PUPDR_PUPDR3          ((uint32_t)0x000000C0U)
#define GPIO_PUPDR_PUPDR3_0        ((uint32_t)0x00000040U)
#define GPIO_PUPDR_PUPDR3_1        ((uint32_t)0x00000080U)
#define GPIO_PUPDR_PUPDR4          ((uint32_t)0x00000300U)
#define GPIO_PUPDR_PUPDR4_0        ((uint32_t)0x00000100U)
#define GPIO_PUPDR_PUPDR4_1        ((uint32_t)0x00000200U)
#define GPIO_PUPDR_PUPDR5          ((uint32_t)0x00000C00U)
#define GPIO_PUPDR_PUPDR5_0        ((uint32_t)0x00000400U)
#define GPIO_PUPDR_PUPDR5_1        ((uint32_t)0x00000800U)
#define GPIO_PUPDR_PUPDR6          ((uint32_t)0x00003000U)
#define GPIO_PUPDR_PUPDR6_0        ((uint32_t)0x00001000U)
#define GPIO_PUPDR_PUPDR6_1        ((uint32_t)0x00002000U)
#define GPIO_PUPDR_PUPDR7          ((uint32_t)0x0000C000U)
#define GPIO_PUPDR_PUPDR7_0        ((uint32_t)0x00004000U)
#define GPIO_PUPDR_PUPDR7_1        ((uint32_t)0x00008000U)
#define GPIO_PUPDR_PUPDR8          ((uint32_t)0x00030000U)
#define GPIO_PUPDR_PUPDR8_0        ((uint32_t)0x00010000U)
#define GPIO_PUPDR_PUPDR8_1        ((uint32_t)0x00020000U)
#define GPIO_PUPDR_PUPDR9          ((uint32_t)0x000C0000U)
#define GPIO_PUPDR_PUPDR9_0        ((uint32_t)0x00040000U)
#define GPIO_PUPDR_PUPDR9_1        ((uint32_t)0x00080000U)
#define GPIO_PUPDR_PUPDR10         ((uint32_t)0x00300000U)
#define GPIO_PUPDR_PUPDR10_0       ((uint32_t)0x00100000U)
#define GPIO_PUPDR_PUPDR10_1       ((uint32_t)0x00200000U)
#define GPIO_PUPDR_PUPDR11         ((uint32_t)0x00C00000U)
#define GPIO_PUPDR_PUPDR11_0       ((uint32_t)0x00400000U)
#define GPIO_PUPDR_PUPDR11_1       ((uint32_t)0x00800000U)
#define GPIO_PUPDR_PUPDR12         ((uint32_t)0x03000000U)
#define GPIO_PUPDR_PUPDR12_0       ((uint32_t)0x01000000U)
#define GPIO_PUPDR_PUPDR12_1       ((uint32_t)0x02000000U)
#define GPIO_PUPDR_PUPDR13         ((uint32_t)0x0C000000U)
#define GPIO_PUPDR_PUPDR13_0       ((uint32_t)0x04000000U)
#define GPIO_PUPDR_PUPDR13_1       ((uint32_t)0x08000000U)
#define GPIO_PUPDR_PUPDR14         ((uint32_t)0x30000000U)
#define GPIO_PUPDR_PUPDR14_0       ((uint32_t)0x10000000U)
#define GPIO_PUPDR_PUPDR14_1       ((uint32_t)0x20000000U)
#define GPIO_PUPDR_PUPDR15         ((uint32_t)0xC0000000U)
#define GPIO_PUPDR_PUPDR15_0       ((uint32_t)0x40000000U)
#define GPIO_PUPDR_PUPDR15_1       ((uint32_t)0x80000000U)

/*******************  Bit definition for GPIO_IDR register  *******************/
#define GPIO_IDR_0                 ((uint32_t)0x00000001U)
#define GPIO_IDR_1                 ((uint32_t)0x00000002U)
#define GPIO_IDR_2                 ((uint32_t)0x00000004U)
#define GPIO_IDR_3                 ((uint32_t)0x00000008U)
#define GPIO_IDR_4                 ((uint32_t)0x00000010U)
#define GPIO_IDR_5                 ((uint32_t)0x00000020U)
#define GPIO_IDR_6                 ((uint32_t)0x00000040U)
#define GPIO_IDR_7                 ((uint32_t)0x00000080U)
#define GPIO_IDR_8                 ((uint32_t)0x00000100U)
#define GPIO_IDR_9                 ((uint32_t)0x00000200U)
#define GPIO_IDR_10                ((uint32_t)0x00000400U)
#define GPIO_IDR_11                ((uint32_t)0x00000800U)
#define GPIO_IDR_12                ((uint32_t)0x00001000U)
#define GPIO_IDR_13                ((uint32_t)0x00002000U)
#define GPIO_IDR_14                ((uint32_t)0x00004000U)
#define GPIO_IDR_15                ((uint32_t)0x00008000U)

/******************  Bit definition for GPIO_ODR register  ********************/
#define GPIO_ODR_0                 ((uint32_t)0x00000001U)
#define GPIO_ODR_1                 ((uint32_t)0x00000002U)
#define GPIO_ODR_2                 ((uint32_t)0x00000004U)
#define GPIO_ODR_3                 ((uint32_t)0x00000008U)
#define GPIO_ODR_4                 ((uint32_t)0x00000010U)
#define GPIO_ODR_5                 ((uint32_t)0x00000020U)
#define GPIO_ODR_6                 ((uint32_t)0x00000040U)
#define GPIO_ODR_7                 ((uint32_t)0x00000080U)
#define GPIO_ODR_8                 ((uint32_t)0x00000100U)
#define GPIO_ODR_9                 ((uint32_t)0x00000200U)
#define GPIO_ODR_10                ((uint32_t)0x00000400U)
#define GPIO_ODR_11                ((uint32_t)0x00000800U)
#define GPIO_ODR_12                ((uint32_t)0x00001000U)
#define GPIO_ODR_13                ((uint32_t)0x00002000U)
#define GPIO_ODR_14                ((uint32_t)0x00004000U)
#define GPIO_ODR_15                ((uint32_t)0x00008000U)

/****************** Bit definition for GPIO_BSRR register  ********************/
#define GPIO_BSRR_BS_0             ((uint32_t)0x00000001U)
#define GPIO_BSRR_BS_1             ((uint32_t)0x00000002U)
#define GPIO_BSRR_BS_2             ((uint32_t)0x00000004U)
#define GPIO_BSRR_BS_3             ((uint32_t)0x00000008U)
#define GPIO_BSRR_BS_4             ((uint32_t)0x00000010U)
#define GPIO_BSRR_BS_5             ((uint32_t)0x00000020U)
#define GPIO_BSRR_BS_6             ((uint32_t)0x00000040U)
#define GPIO_BSRR_BS_7             ((uint32_t)0x00000080U)
#define GPIO_BSRR_BS_8             ((uint32_t)0x00000100U)
#define GPIO_BSRR_BS_9             ((uint32_t)0x00000200U)
#define GPIO_BSRR_BS_10            ((uint32_t)0x00000400U)
#define GPIO_BSRR_BS_11            ((uint32_t)0x00000800U)
#define GPIO_BSRR_BS_12            ((uint32_t)0x00001000U)
#define GPIO_BSRR_BS_13            ((uint32_t)0x00002000U)
#define GPIO_BSRR_BS_14            ((uint32_t)0x00004000U)
#define GPIO_BSRR_BS_15            ((uint32_t)0x00008000U)
#define GPIO_BSRR_BR_0             ((uint32_t)0x00010000U)
#define GPIO_BSRR_BR_1             ((uint32_t)0x00020000U)
#define GPIO_BSRR_BR_2             ((uint32_t)0x00040000U)
#define GPIO_BSRR_BR_3             ((uint32_t)0x00080000U)
#define GPIO_BSRR_BR_4             ((uint32_t)0x00100000U)
#define GPIO_BSRR_BR_5             ((uint32_t)0x00200000U)
#define GPIO_BSRR_BR_6             ((uint32_t)0x00400000U)
#define GPIO_BSRR_BR_7             ((uint32_t)0x00800000U)
#define GPIO_BSRR_BR_8             ((uint32_t)0x01000000U)
#define GPIO_BSRR_BR_9             ((uint32_t)0x02000000U)
#define GPIO_BSRR_BR_10            ((uint32_t)0x04000000U)
#define GPIO_BSRR_BR_11            ((uint32_t)0x08000000U)
#define GPIO_BSRR_BR_12            ((uint32_t)0x10000000U)
#define GPIO_BSRR_BR_13            ((uint32_t)0x20000000U)
#define GPIO_BSRR_BR_14            ((uint32_t)0x40000000U)
#define GPIO_BSRR_BR_15            ((uint32_t)0x80000000U)

/****************** Bit definition for GPIO_LCKR register  ********************/
#define GPIO_LCKR_LCK0             ((uint32_t)0x00000001U)
#define GPIO_LCKR_LCK1             ((uint32_t)0x00000002U)
#define GPIO_LCKR_LCK2             ((uint32_t)0x00000004U)
#define GPIO_LCKR_LCK3             ((uint32_t)0x00000008U)
#define GPIO_LCKR_LCK4             ((uint32_t)0x00000010U)
#define GPIO_LCKR_LCK5             ((uint32_t)0x00000020U)
#define GPIO_LCKR_LCK6             ((uint32_t)0x00000040U)
#define GPIO_LCKR_LCK7             ((uint32_t)0x00000080U)
#define GPIO_LCKR_LCK8             ((uint32_t)0x00000100U)
#define GPIO_LCKR_LCK9             ((uint32_t)0x00000200U)
#define GPIO_LCKR_LCK10            ((uint32_t)0x00000400U)
#define GPIO_LCKR_LCK11            ((uint32_t)0x00000800U)
#define GPIO_LCKR_LCK12            ((uint32_t)0x00001000U)
#define GPIO_LCKR_LCK13            ((uint32_t)0x00002000U)
#define GPIO_LCKR_LCK14            ((uint32_t)0x00004000U)
#define GPIO_LCKR_LCK15            ((uint32_t)0x00008000U)
#define GPIO_LCKR_LCKK             ((uint32_t)0x00010000U)

/****************** Bit definition for GPIO_AFRL register  ********************/
#define GPIO_AFRL_AFRL0            ((uint32_t)0x0000000FU)
#define GPIO_AFRL_AFRL1            ((uint32_t)0x000000F0U)
#define GPIO_AFRL_AFRL2            ((uint32_t)0x00000F00U)
#define GPIO_AFRL_AFRL3            ((uint32_t)0x0000F000U)
#define GPIO_AFRL_AFRL4            ((uint32_t)0x000F0000U)
#define GPIO_AFRL_AFRL5            ((uint32_t)0x00F00000U)
#define GPIO_AFRL_AFRL6            ((uint32_t)0x0F000000U)
#define GPIO_AFRL_AFRL7            ((uint32_t)0xF0000000U)

/****************** Bit definition for GPIO_AFRH register  ********************/
#define GPIO_AFRH_AFRH0            ((uint32_t)0x0000000FU)
#define GPIO_AFRH_AFRH1            ((uint32_t)0x000000F0U)
#define GPIO_AFRH_AFRH2            ((uint32_t)0x00000F00U)
#define GPIO_AFRH_AFRH3            ((uint32_t)0x0000F000U)
#define GPIO_AFRH_AFRH4            ((uint32_t)0x000F0000U)
#define GPIO_AFRH_AFRH5            ((uint32_t)0x00F00000U)
#define GPIO_AFRH_AFRH6            ((uint32_t)0x0F000000U)
#define GPIO_AFRH_AFRH7            ((uint32_t)0xF0000000U)

/****************** Bit definition for GPIO_BRR register  *********************/
#define GPIO_BRR_BR_0              ((uint32_t)0x00000001U)
#define GPIO_BRR_BR_1              ((uint32_t)0x00000002U)
#define GPIO_BRR_BR_2              ((uint32_t)0x00000004U)
#define GPIO_BRR_BR_3              ((uint32_t)0x00000008U)
#define GPIO_BRR_BR_4              ((uint32_t)0x00000010U)
#define GPIO_BRR_BR_5              ((uint32_t)0x00000020U)
#define GPIO_BRR_BR_6              ((uint32_t)0x00000040U)
#define GPIO_BRR_BR_7              ((uint32_t)0x00000080U)
#define GPIO_BRR_BR_8              ((uint32_t)0x00000100U)
#define GPIO_BRR_BR_9              ((uint32_t)0x00000200U)
#define GPIO_BRR_BR_10             ((uint32_t)0x00000400U)
#define GPIO_BRR_BR_11             ((uint32_t)0x00000800U)
#define GPIO_BRR_BR_12             ((uint32_t)0x00001000U)
#define GPIO_BRR_BR_13             ((uint32_t)0x00002000U)
#define GPIO_BRR_BR_14             ((uint32_t)0x00004000U)
#define GPIO_BRR_BR_15             ((uint32_t)0x00008000U)

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface (I2C)              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  *******************/
#define  I2C_CR1_PE                          ((uint32_t)0x00000001U)        /*!< Peripheral enable */
#define  I2C_CR1_TXIE                        ((uint32_t)0x00000002U)        /*!< TX interrupt enable */
#define  I2C_CR1_RXIE                        ((uint32_t)0x00000004U)        /*!< RX interrupt enable */
#define  I2C_CR1_ADDRIE                      ((uint32_t)0x00000008U)        /*!< Address match interrupt enable */
#define  I2C_CR1_NACKIE                      ((uint32_t)0x00000010U)        /*!< NACK received interrupt enable */
#define  I2C_CR1_STOPIE                      ((uint32_t)0x00000020U)        /*!< STOP detection interrupt enable */
#define  I2C_CR1_TCIE                        ((uint32_t)0x00000040U)        /*!< Transfer complete interrupt enable */
#define  I2C_CR1_ERRIE                       ((uint32_t)0x00000080U)        /*!< Errors interrupt enable */
#define  I2C_CR1_DNF                         ((uint32_t)0x00000F00U)        /*!< Digital noise filter */
#define  I2C_CR1_ANFOFF                      ((uint32_t)0x00001000U)        /*!< Analog noise filter OFF */
#define  I2C_CR1_SWRST                       ((uint32_t)0x00002000U)        /*!< Software reset */
#define  I2C_CR1_TXDMAEN                     ((uint32_t)0x00004000U)        /*!< DMA transmission requests enable */
#define  I2C_CR1_RXDMAEN                     ((uint32_t)0x00008000U)        /*!< DMA reception requests enable */
#define  I2C_CR1_SBC                         ((uint32_t)0x00010000U)        /*!< Slave byte control */
#define  I2C_CR1_NOSTRETCH                   ((uint32_t)0x00020000U)        /*!< Clock stretching disable */
#define  I2C_CR1_WUPEN                       ((uint32_t)0x00040000U)        /*!< Wakeup from STOP enable */
#define  I2C_CR1_GCEN                        ((uint32_t)0x00080000U)        /*!< General call enable */
#define  I2C_CR1_SMBHEN                      ((uint32_t)0x00100000U)        /*!< SMBus host address enable */
#define  I2C_CR1_SMBDEN                      ((uint32_t)0x00200000U)        /*!< SMBus device default address enable */
#define  I2C_CR1_ALERTEN                     ((uint32_t)0x00400000U)        /*!< SMBus alert enable */
#define  I2C_CR1_PECEN                       ((uint32_t)0x00800000U)        /*!< PEC enable */

/* Legacy defines */
#define I2C_CR1_DFN I2C_CR1_DNF

/******************  Bit definition for I2C_CR2 register  ********************/
#define  I2C_CR2_SADD                        ((uint32_t)0x000003FFU)        /*!< Slave address (master mode) */
#define  I2C_CR2_RD_WRN                      ((uint32_t)0x00000400U)        /*!< Transfer direction (master mode) */
#define  I2C_CR2_ADD10                       ((uint32_t)0x00000800U)        /*!< 10-bit addressing mode (master mode) */
#define  I2C_CR2_HEAD10R                     ((uint32_t)0x00001000U)        /*!< 10-bit address header only read direction (master mode) */
#define  I2C_CR2_START                       ((uint32_t)0x00002000U)        /*!< START generation */
#define  I2C_CR2_STOP                        ((uint32_t)0x00004000U)        /*!< STOP generation (master mode) */
#define  I2C_CR2_NACK                        ((uint32_t)0x00008000U)        /*!< NACK generation (slave mode) */
#define  I2C_CR2_NBYTES                      ((uint32_t)0x00FF0000U)        /*!< Number of bytes */
#define  I2C_CR2_RELOAD                      ((uint32_t)0x01000000U)        /*!< NBYTES reload mode */
#define  I2C_CR2_AUTOEND                     ((uint32_t)0x02000000U)        /*!< Automatic end mode (master mode) */
#define  I2C_CR2_PECBYTE                     ((uint32_t)0x04000000U)        /*!< Packet error checking byte */

/*******************  Bit definition for I2C_OAR1 register  ******************/
#define  I2C_OAR1_OA1                        ((uint32_t)0x000003FFU)        /*!< Interface own address 1 */
#define  I2C_OAR1_OA1MODE                    ((uint32_t)0x00000400U)        /*!< Own address 1 10-bit mode */
#define  I2C_OAR1_OA1EN                      ((uint32_t)0x00008000U)        /*!< Own address 1 enable */

/*******************  Bit definition for I2C_OAR2 register  *******************/
#define  I2C_OAR2_OA2                        ((uint32_t)0x000000FEU)        /*!< Interface own address 2                        */
#define  I2C_OAR2_OA2MSK                     ((uint32_t)0x00000700U)        /*!< Own address 2 masks                            */
#define  I2C_OAR2_OA2NOMASK                  ((uint32_t)0x00000000U)        /*!< No mask                                        */
#define  I2C_OAR2_OA2MASK01                  ((uint32_t)0x00000100U)        /*!< OA2[1] is masked, Only OA2[7:2] are compared   */
#define  I2C_OAR2_OA2MASK02                  ((uint32_t)0x00000200U)        /*!< OA2[2:1] is masked, Only OA2[7:3] are compared */
#define  I2C_OAR2_OA2MASK03                  ((uint32_t)0x00000300U)        /*!< OA2[3:1] is masked, Only OA2[7:4] are compared */
#define  I2C_OAR2_OA2MASK04                  ((uint32_t)0x00000400U)        /*!< OA2[4:1] is masked, Only OA2[7:5] are compared */
#define  I2C_OAR2_OA2MASK05                  ((uint32_t)0x00000500U)        /*!< OA2[5:1] is masked, Only OA2[7:6] are compared */
#define  I2C_OAR2_OA2MASK06                  ((uint32_t)0x00000600U)        /*!< OA2[6:1] is masked, Only OA2[7] are compared   */
#define  I2C_OAR2_OA2MASK07                  ((uint32_t)0x00000700U)        /*!< OA2[7:1] is masked, No comparison is done      */
#define  I2C_OAR2_OA2EN                      ((uint32_t)0x00008000U)        /*!< Own address 2 enable                           */

/*******************  Bit definition for I2C_TIMINGR register *****************/
#define  I2C_TIMINGR_SCLL                    ((uint32_t)0x000000FFU)        /*!< SCL low period (master mode) */
#define  I2C_TIMINGR_SCLH                    ((uint32_t)0x0000FF00U)        /*!< SCL high period (master mode) */
#define  I2C_TIMINGR_SDADEL                  ((uint32_t)0x000F0000U)        /*!< Data hold time */
#define  I2C_TIMINGR_SCLDEL                  ((uint32_t)0x00F00000U)        /*!< Data setup time */
#define  I2C_TIMINGR_PRESC                   ((uint32_t)0xF0000000U)        /*!< Timings prescaler */

/******************* Bit definition for I2C_TIMEOUTR register *****************/
#define  I2C_TIMEOUTR_TIMEOUTA               ((uint32_t)0x00000FFFU)        /*!< Bus timeout A */
#define  I2C_TIMEOUTR_TIDLE                  ((uint32_t)0x00001000U)        /*!< Idle clock timeout detection */
#define  I2C_TIMEOUTR_TIMOUTEN               ((uint32_t)0x00008000U)        /*!< Clock timeout enable */
#define  I2C_TIMEOUTR_TIMEOUTB               ((uint32_t)0x0FFF0000U)        /*!< Bus timeout B*/
#define  I2C_TIMEOUTR_TEXTEN                 ((uint32_t)0x80000000U)        /*!< Extended clock timeout enable */

/******************  Bit definition for I2C_ISR register  *********************/
#define  I2C_ISR_TXE                         ((uint32_t)0x00000001U)        /*!< Transmit data register empty */
#define  I2C_ISR_TXIS                        ((uint32_t)0x00000002U)        /*!< Transmit interrupt status */
#define  I2C_ISR_RXNE                        ((uint32_t)0x00000004U)        /*!< Receive data register not empty */
#define  I2C_ISR_ADDR                        ((uint32_t)0x00000008U)        /*!< Address matched (slave mode)*/
#define  I2C_ISR_NACKF                       ((uint32_t)0x00000010U)        /*!< NACK received flag */
#define  I2C_ISR_STOPF                       ((uint32_t)0x00000020U)        /*!< STOP detection flag */
#define  I2C_ISR_TC                          ((uint32_t)0x00000040U)        /*!< Transfer complete (master mode) */
#define  I2C_ISR_TCR                         ((uint32_t)0x00000080U)        /*!< Transfer complete reload */
#define  I2C_ISR_BERR                        ((uint32_t)0x00000100U)        /*!< Bus error */
#define  I2C_ISR_ARLO                        ((uint32_t)0x00000200U)        /*!< Arbitration lost */
#define  I2C_ISR_OVR                         ((uint32_t)0x00000400U)        /*!< Overrun/Underrun */
#define  I2C_ISR_PECERR                      ((uint32_t)0x00000800U)        /*!< PEC error in reception */
#define  I2C_ISR_TIMEOUT                     ((uint32_t)0x00001000U)        /*!< Timeout or Tlow detection flag */
#define  I2C_ISR_ALERT                       ((uint32_t)0x00002000U)        /*!< SMBus alert */
#define  I2C_ISR_BUSY                        ((uint32_t)0x00008000U)        /*!< Bus busy */
#define  I2C_ISR_DIR                         ((uint32_t)0x00010000U)        /*!< Transfer direction (slave mode) */
#define  I2C_ISR_ADDCODE                     ((uint32_t)0x00FE0000U)        /*!< Address match code (slave mode) */

/******************  Bit definition for I2C_ICR register  *********************/
#define  I2C_ICR_ADDRCF                      ((uint32_t)0x00000008U)        /*!< Address matched clear flag */
#define  I2C_ICR_NACKCF                      ((uint32_t)0x00000010U)        /*!< NACK clear flag */
#define  I2C_ICR_STOPCF                      ((uint32_t)0x00000020U)        /*!< STOP detection clear flag */
#define  I2C_ICR_BERRCF                      ((uint32_t)0x00000100U)        /*!< Bus error clear flag */
#define  I2C_ICR_ARLOCF                      ((uint32_t)0x00000200U)        /*!< Arbitration lost clear flag */
#define  I2C_ICR_OVRCF                       ((uint32_t)0x00000400U)        /*!< Overrun/Underrun clear flag */
#define  I2C_ICR_PECCF                       ((uint32_t)0x00000800U)        /*!< PAC error clear flag */
#define  I2C_ICR_TIMOUTCF                    ((uint32_t)0x00001000U)        /*!< Timeout clear flag */
#define  I2C_ICR_ALERTCF                     ((uint32_t)0x00002000U)        /*!< Alert clear flag */

/******************  Bit definition for I2C_PECR register  ********************/
#define  I2C_PECR_PEC                        ((uint32_t)0x000000FFU)        /*!< PEC register */

/******************  Bit definition for I2C_RXDR register  *********************/
#define  I2C_RXDR_RXDATA                     ((uint32_t)0x000000FFU)        /*!< 8-bit receive data */

/******************  Bit definition for I2C_TXDR register  *********************/
#define  I2C_TXDR_TXDATA                     ((uint32_t)0x000000FFU)        /*!< 8-bit transmit data */


/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG (IWDG)                      */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define  IWDG_KR_KEY                         ((uint32_t)0x0000FFFFU)        /*!< Key value (write only, read 0000h) */

/*******************  Bit definition for IWDG_PR register  ********************/
#define  IWDG_PR_PR                          ((uint32_t)0x00000007U)        /*!< PR[2:0] (Prescaler divider) */
#define  IWDG_PR_PR_0                        ((uint32_t)0x00000001U)        /*!< Bit 0 */
#define  IWDG_PR_PR_1                        ((uint32_t)0x00000002U)        /*!< Bit 1 */
#define  IWDG_PR_PR_2                        ((uint32_t)0x00000004U)        /*!< Bit 2 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define  IWDG_RLR_RL                         ((uint32_t)0x00000FFFU)        /*!< Watchdog counter reload value */

/*******************  Bit definition for IWDG_SR register  ********************/
#define  IWDG_SR_PVU                         ((uint32_t)0x00000001U)        /*!< Watchdog prescaler value update */
#define  IWDG_SR_RVU                         ((uint32_t)0x00000002U)        /*!< Watchdog counter reload value update */
#define  IWDG_SR_WVU                         ((uint32_t)0x00000004U)        /*!< Watchdog counter window value update */

/*******************  Bit definition for IWDG_KR register  ********************/
#define  IWDG_WINR_WIN                       ((uint32_t)0x00000FFFU)        /*!< Watchdog counter window value */

/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
#define PWR_PVD_SUPPORT                       /*!< PWR feature available only on specific devices: Power Voltage Detection feature */
/********************  Bit definition for PWR_CR register  ********************/
#define  PWR_CR_LPDS                         ((uint32_t)0x00000001U)     /*!< Low-power Deepsleep */
#define  PWR_CR_PDDS                         ((uint32_t)0x00000002U)     /*!< Power Down Deepsleep */
#define  PWR_CR_CWUF                         ((uint32_t)0x00000004U)     /*!< Clear Wakeup Flag */
#define  PWR_CR_CSBF                         ((uint32_t)0x00000008U)     /*!< Clear Standby Flag */
#define  PWR_CR_PVDE                         ((uint32_t)0x00000010U)     /*!< Power Voltage Detector Enable */

#define  PWR_CR_PLS                          ((uint32_t)0x000000E0U)     /*!< PLS[2:0] bits (PVD Level Selection) */
#define  PWR_CR_PLS_0                        ((uint32_t)0x00000020U)     /*!< Bit 0 */
#define  PWR_CR_PLS_1                        ((uint32_t)0x00000040U)     /*!< Bit 1 */
#define  PWR_CR_PLS_2                        ((uint32_t)0x00000080U)     /*!< Bit 2 */

/*!< PVD level configuration */
#define  PWR_CR_PLS_LEV0                     ((uint32_t)0x00000000U)     /*!< PVD level 0 */
#define  PWR_CR_PLS_LEV1                     ((uint32_t)0x00000020U)     /*!< PVD level 1 */
#define  PWR_CR_PLS_LEV2                     ((uint32_t)0x00000040U)     /*!< PVD level 2 */
#define  PWR_CR_PLS_LEV3                     ((uint32_t)0x00000060U)     /*!< PVD level 3 */
#define  PWR_CR_PLS_LEV4                     ((uint32_t)0x00000080U)     /*!< PVD level 4 */
#define  PWR_CR_PLS_LEV5                     ((uint32_t)0x000000A0U)     /*!< PVD level 5 */
#define  PWR_CR_PLS_LEV6                     ((uint32_t)0x000000C0U)     /*!< PVD level 6 */
#define  PWR_CR_PLS_LEV7                     ((uint32_t)0x000000E0U)     /*!< PVD level 7 */

#define  PWR_CR_DBP                          ((uint32_t)0x00000100U)     /*!< Disable Backup Domain write protection */

/*******************  Bit definition for PWR_CSR register  ********************/
#define  PWR_CSR_WUF                         ((uint32_t)0x00000001U)     /*!< Wakeup Flag */
#define  PWR_CSR_SBF                         ((uint32_t)0x00000002U)     /*!< Standby Flag */
#define  PWR_CSR_PVDO                        ((uint32_t)0x00000004U)     /*!< PVD Output */
#define  PWR_CSR_VREFINTRDYF                 ((uint32_t)0x00000008U)     /*!< Internal voltage reference (VREFINT) ready flag */

#define  PWR_CSR_EWUP1                       ((uint32_t)0x00000100U)     /*!< Enable WKUP pin 1 */
#define  PWR_CSR_EWUP2                       ((uint32_t)0x00000200U)     /*!< Enable WKUP pin 2 */
#define  PWR_CSR_EWUP3                       ((uint32_t)0x00000400U)     /*!< Enable WKUP pin 3 */

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define  RCC_CR_HSION                        ((uint32_t)0x00000001U)
#define  RCC_CR_HSIRDY                       ((uint32_t)0x00000002U)

#define  RCC_CR_HSITRIM                      ((uint32_t)0x000000F8U)
#define  RCC_CR_HSITRIM_0                    ((uint32_t)0x00000008U)/*!<Bit 0 */
#define  RCC_CR_HSITRIM_1                    ((uint32_t)0x00000010U)/*!<Bit 1 */
#define  RCC_CR_HSITRIM_2                    ((uint32_t)0x00000020U)/*!<Bit 2 */
#define  RCC_CR_HSITRIM_3                    ((uint32_t)0x00000040U)/*!<Bit 3 */
#define  RCC_CR_HSITRIM_4                    ((uint32_t)0x00000080U)/*!<Bit 4 */

#define  RCC_CR_HSICAL                       ((uint32_t)0x0000FF00U)
#define  RCC_CR_HSICAL_0                     ((uint32_t)0x00000100U)/*!<Bit 0 */
#define  RCC_CR_HSICAL_1                     ((uint32_t)0x00000200U)/*!<Bit 1 */
#define  RCC_CR_HSICAL_2                     ((uint32_t)0x00000400U)/*!<Bit 2 */
#define  RCC_CR_HSICAL_3                     ((uint32_t)0x00000800U)/*!<Bit 3 */
#define  RCC_CR_HSICAL_4                     ((uint32_t)0x00001000U)/*!<Bit 4 */
#define  RCC_CR_HSICAL_5                     ((uint32_t)0x00002000U)/*!<Bit 5 */
#define  RCC_CR_HSICAL_6                     ((uint32_t)0x00004000U)/*!<Bit 6 */
#define  RCC_CR_HSICAL_7                     ((uint32_t)0x00008000U)/*!<Bit 7 */

#define  RCC_CR_HSEON                        ((uint32_t)0x00010000U)
#define  RCC_CR_HSERDY                       ((uint32_t)0x00020000U)
#define  RCC_CR_HSEBYP                       ((uint32_t)0x00040000U)
#define  RCC_CR_CSSON                        ((uint32_t)0x00080000U)
#define  RCC_CR_PLLON                        ((uint32_t)0x01000000U)
#define  RCC_CR_PLLRDY                       ((uint32_t)0x02000000U)

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define  RCC_CFGR_SW                         ((uint32_t)0x00000003U)        /*!< SW[1:0] bits (System clock Switch) */
#define  RCC_CFGR_SW_0                       ((uint32_t)0x00000001U)        /*!< Bit 0 */
#define  RCC_CFGR_SW_1                       ((uint32_t)0x00000002U)        /*!< Bit 1 */

#define  RCC_CFGR_SW_HSI                     ((uint32_t)0x00000000U)        /*!< HSI selected as system clock */
#define  RCC_CFGR_SW_HSE                     ((uint32_t)0x00000001U)        /*!< HSE selected as system clock */
#define  RCC_CFGR_SW_PLL                     ((uint32_t)0x00000002U)        /*!< PLL selected as system clock */

/*!< SWS configuration */
#define  RCC_CFGR_SWS                        ((uint32_t)0x0000000CU)        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define  RCC_CFGR_SWS_0                      ((uint32_t)0x00000004U)        /*!< Bit 0 */
#define  RCC_CFGR_SWS_1                      ((uint32_t)0x00000008U)        /*!< Bit 1 */

#define  RCC_CFGR_SWS_HSI                    ((uint32_t)0x00000000U)        /*!< HSI oscillator used as system clock */
#define  RCC_CFGR_SWS_HSE                    ((uint32_t)0x00000004U)        /*!< HSE oscillator used as system clock */
#define  RCC_CFGR_SWS_PLL                    ((uint32_t)0x00000008U)        /*!< PLL used as system clock */

/*!< HPRE configuration */
#define  RCC_CFGR_HPRE                       ((uint32_t)0x000000F0U)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define  RCC_CFGR_HPRE_0                     ((uint32_t)0x00000010U)        /*!< Bit 0 */
#define  RCC_CFGR_HPRE_1                     ((uint32_t)0x00000020U)        /*!< Bit 1 */
#define  RCC_CFGR_HPRE_2                     ((uint32_t)0x00000040U)        /*!< Bit 2 */
#define  RCC_CFGR_HPRE_3                     ((uint32_t)0x00000080U)        /*!< Bit 3 */

#define  RCC_CFGR_HPRE_DIV1                  ((uint32_t)0x00000000U)        /*!< SYSCLK not divided */
#define  RCC_CFGR_HPRE_DIV2                  ((uint32_t)0x00000080U)        /*!< SYSCLK divided by 2 */
#define  RCC_CFGR_HPRE_DIV4                  ((uint32_t)0x00000090U)        /*!< SYSCLK divided by 4 */
#define  RCC_CFGR_HPRE_DIV8                  ((uint32_t)0x000000A0U)        /*!< SYSCLK divided by 8 */
#define  RCC_CFGR_HPRE_DIV16                 ((uint32_t)0x000000B0U)        /*!< SYSCLK divided by 16 */
#define  RCC_CFGR_HPRE_DIV64                 ((uint32_t)0x000000C0U)        /*!< SYSCLK divided by 64 */
#define  RCC_CFGR_HPRE_DIV128                ((uint32_t)0x000000D0U)        /*!< SYSCLK divided by 128 */
#define  RCC_CFGR_HPRE_DIV256                ((uint32_t)0x000000E0U)        /*!< SYSCLK divided by 256 */
#define  RCC_CFGR_HPRE_DIV512                ((uint32_t)0x000000F0U)        /*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define  RCC_CFGR_PPRE1                      ((uint32_t)0x00000700U)        /*!< PRE1[2:0] bits (APB1 prescaler) */
#define  RCC_CFGR_PPRE1_0                    ((uint32_t)0x00000100U)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE1_1                    ((uint32_t)0x00000200U)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE1_2                    ((uint32_t)0x00000400U)        /*!< Bit 2 */

#define  RCC_CFGR_PPRE1_DIV1                 ((uint32_t)0x00000000U)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE1_DIV2                 ((uint32_t)0x00000400U)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE1_DIV4                 ((uint32_t)0x00000500U)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE1_DIV8                 ((uint32_t)0x00000600U)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE1_DIV16                ((uint32_t)0x00000700U)        /*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define  RCC_CFGR_PPRE2                      ((uint32_t)0x00003800U)        /*!< PRE2[2:0] bits (APB2 prescaler) */
#define  RCC_CFGR_PPRE2_0                    ((uint32_t)0x00000800U)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE2_1                    ((uint32_t)0x00001000U)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE2_2                    ((uint32_t)0x00002000U)        /*!< Bit 2 */

#define  RCC_CFGR_PPRE2_DIV1                 ((uint32_t)0x00000000U)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE2_DIV2                 ((uint32_t)0x00002000U)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE2_DIV4                 ((uint32_t)0x00002800U)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE2_DIV8                 ((uint32_t)0x00003000U)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE2_DIV16                ((uint32_t)0x00003800U)        /*!< HCLK divided by 16 */

#define  RCC_CFGR_PLLSRC                     ((uint32_t)0x00010000U)        /*!< PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSI_DIV2            ((uint32_t)0x00000000U)        /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSE_PREDIV          ((uint32_t)0x00010000U)        /*!< HSE/PREDIV clock selected as PLL entry clock source */

#define  RCC_CFGR_PLLXTPRE                   ((uint32_t)0x00020000U)        /*!< HSE divider for PLL entry */
#define  RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV1   ((uint32_t)0x00000000U)        /*!< HSE/PREDIV clock not divided for PLL entry */
#define  RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV2   ((uint32_t)0x00020000U)        /*!< HSE/PREDIV clock divided by 2 for PLL entry */

/*!< PLLMUL configuration */
#define  RCC_CFGR_PLLMUL                     ((uint32_t)0x003C0000U)        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define  RCC_CFGR_PLLMUL_0                   ((uint32_t)0x00040000U)        /*!< Bit 0 */
#define  RCC_CFGR_PLLMUL_1                   ((uint32_t)0x00080000U)        /*!< Bit 1 */
#define  RCC_CFGR_PLLMUL_2                   ((uint32_t)0x00100000U)        /*!< Bit 2 */
#define  RCC_CFGR_PLLMUL_3                   ((uint32_t)0x00200000U)        /*!< Bit 3 */

#define  RCC_CFGR_PLLMUL2                    ((uint32_t)0x00000000U)        /*!< PLL input clock*2 */
#define  RCC_CFGR_PLLMUL3                    ((uint32_t)0x00040000U)        /*!< PLL input clock*3 */
#define  RCC_CFGR_PLLMUL4                    ((uint32_t)0x00080000U)        /*!< PLL input clock*4 */
#define  RCC_CFGR_PLLMUL5                    ((uint32_t)0x000C0000U)        /*!< PLL input clock*5 */
#define  RCC_CFGR_PLLMUL6                    ((uint32_t)0x00100000U)        /*!< PLL input clock*6 */
#define  RCC_CFGR_PLLMUL7                    ((uint32_t)0x00140000U)        /*!< PLL input clock*7 */
#define  RCC_CFGR_PLLMUL8                    ((uint32_t)0x00180000U)        /*!< PLL input clock*8 */
#define  RCC_CFGR_PLLMUL9                    ((uint32_t)0x001C0000U)        /*!< PLL input clock*9 */
#define  RCC_CFGR_PLLMUL10                   ((uint32_t)0x00200000U)        /*!< PLL input clock10 */
#define  RCC_CFGR_PLLMUL11                   ((uint32_t)0x00240000U)        /*!< PLL input clock*11 */
#define  RCC_CFGR_PLLMUL12                   ((uint32_t)0x00280000U)        /*!< PLL input clock*12 */
#define  RCC_CFGR_PLLMUL13                   ((uint32_t)0x002C0000U)        /*!< PLL input clock*13 */
#define  RCC_CFGR_PLLMUL14                   ((uint32_t)0x00300000U)        /*!< PLL input clock*14 */
#define  RCC_CFGR_PLLMUL15                   ((uint32_t)0x00340000U)        /*!< PLL input clock*15 */
#define  RCC_CFGR_PLLMUL16                   ((uint32_t)0x00380000U)        /*!< PLL input clock*16 */

/*!< USB configuration */
#define  RCC_CFGR_USBPRE                     ((uint32_t)0x00400000U)        /*!< USB prescaler */

#define  RCC_CFGR_USBPRE_DIV1_5              ((uint32_t)0x00000000U)        /*!< USB prescaler is PLL clock divided by 1.5 */
#define  RCC_CFGR_USBPRE_DIV1                ((uint32_t)0x00400000U)        /*!< USB prescaler is PLL clock divided by 1 */

/*!< I2S configuration */
#define  RCC_CFGR_I2SSRC                     ((uint32_t)0x00800000U)        /*!< I2S external clock source selection */

#define  RCC_CFGR_I2SSRC_SYSCLK              ((uint32_t)0x00000000U)        /*!< System clock selected as I2S clock source */
#define  RCC_CFGR_I2SSRC_EXT                 ((uint32_t)0x00800000U)        /*!< External clock selected as I2S clock source */

/*!< MCO configuration */
#define  RCC_CFGR_MCO                        ((uint32_t)0x07000000U)        /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define  RCC_CFGR_MCO_0                      ((uint32_t)0x01000000U)        /*!< Bit 0 */
#define  RCC_CFGR_MCO_1                      ((uint32_t)0x02000000U)        /*!< Bit 1 */
#define  RCC_CFGR_MCO_2                      ((uint32_t)0x04000000U)        /*!< Bit 2 */

#define  RCC_CFGR_MCO_NOCLOCK                ((uint32_t)0x00000000U)        /*!< No clock */
#define  RCC_CFGR_MCO_LSI                    ((uint32_t)0x02000000U)        /*!< LSI clock selected as MCO source */
#define  RCC_CFGR_MCO_LSE                    ((uint32_t)0x03000000U)        /*!< LSE clock selected as MCO source */
#define  RCC_CFGR_MCO_SYSCLK                 ((uint32_t)0x04000000U)        /*!< System clock selected as MCO source */
#define  RCC_CFGR_MCO_HSI                    ((uint32_t)0x05000000U)        /*!< HSI clock selected as MCO source */
#define  RCC_CFGR_MCO_HSE                    ((uint32_t)0x06000000U)        /*!< HSE clock selected as MCO source  */
#define  RCC_CFGR_MCO_PLL                    ((uint32_t)0x07000000U)        /*!< PLL clock divided by 2 selected as MCO source */

#define  RCC_CFGR_MCOF                       ((uint32_t)0x10000000U)        /*!< Microcontroller Clock Output Flag */
/* Reference defines */
#define RCC_CFGR_MCOSEL                      RCC_CFGR_MCO
#define RCC_CFGR_MCOSEL_0                    RCC_CFGR_MCO_0
#define RCC_CFGR_MCOSEL_1                    RCC_CFGR_MCO_1
#define RCC_CFGR_MCOSEL_2                    RCC_CFGR_MCO_2
#define RCC_CFGR_MCOSEL_NOCLOCK              RCC_CFGR_MCO_NOCLOCK
#define RCC_CFGR_MCOSEL_LSI                  RCC_CFGR_MCO_LSI
#define RCC_CFGR_MCOSEL_LSE                  RCC_CFGR_MCO_LSE
#define RCC_CFGR_MCOSEL_SYSCLK               RCC_CFGR_MCO_SYSCLK
#define RCC_CFGR_MCOSEL_HSI                  RCC_CFGR_MCO_HSI
#define RCC_CFGR_MCOSEL_HSE                  RCC_CFGR_MCO_HSE
#define RCC_CFGR_MCOSEL_PLL_DIV2             RCC_CFGR_MCO_PLL

/*********************  Bit definition for RCC_CIR register  ********************/
#define  RCC_CIR_LSIRDYF                     ((uint32_t)0x00000001U)        /*!< LSI Ready Interrupt flag */
#define  RCC_CIR_LSERDYF                     ((uint32_t)0x00000002U)        /*!< LSE Ready Interrupt flag */
#define  RCC_CIR_HSIRDYF                     ((uint32_t)0x00000004U)        /*!< HSI Ready Interrupt flag */
#define  RCC_CIR_HSERDYF                     ((uint32_t)0x00000008U)        /*!< HSE Ready Interrupt flag */
#define  RCC_CIR_PLLRDYF                     ((uint32_t)0x00000010U)        /*!< PLL Ready Interrupt flag */
#define  RCC_CIR_CSSF                        ((uint32_t)0x00000080U)        /*!< Clock Security System Interrupt flag */
#define  RCC_CIR_LSIRDYIE                    ((uint32_t)0x00000100U)        /*!< LSI Ready Interrupt Enable */
#define  RCC_CIR_LSERDYIE                    ((uint32_t)0x00000200U)        /*!< LSE Ready Interrupt Enable */
#define  RCC_CIR_HSIRDYIE                    ((uint32_t)0x00000400U)        /*!< HSI Ready Interrupt Enable */
#define  RCC_CIR_HSERDYIE                    ((uint32_t)0x00000800U)        /*!< HSE Ready Interrupt Enable */
#define  RCC_CIR_PLLRDYIE                    ((uint32_t)0x00001000U)        /*!< PLL Ready Interrupt Enable */
#define  RCC_CIR_LSIRDYC                     ((uint32_t)0x00010000U)        /*!< LSI Ready Interrupt Clear */
#define  RCC_CIR_LSERDYC                     ((uint32_t)0x00020000U)        /*!< LSE Ready Interrupt Clear */
#define  RCC_CIR_HSIRDYC                     ((uint32_t)0x00040000U)        /*!< HSI Ready Interrupt Clear */
#define  RCC_CIR_HSERDYC                     ((uint32_t)0x00080000U)        /*!< HSE Ready Interrupt Clear */
#define  RCC_CIR_PLLRDYC                     ((uint32_t)0x00100000U)        /*!< PLL Ready Interrupt Clear */
#define  RCC_CIR_CSSC                        ((uint32_t)0x00800000U)        /*!< Clock Security System Interrupt Clear */

/******************  Bit definition for RCC_APB2RSTR register  *****************/
#define  RCC_APB2RSTR_SYSCFGRST              ((uint32_t)0x00000001U)        /*!< SYSCFG reset */
#define  RCC_APB2RSTR_TIM1RST                ((uint32_t)0x00000800U)        /*!< TIM1 reset */
#define  RCC_APB2RSTR_SPI1RST                ((uint32_t)0x00001000U)        /*!< SPI1 reset */
#define  RCC_APB2RSTR_TIM8RST                ((uint32_t)0x00002000U)        /*!< TIM8 reset */
#define  RCC_APB2RSTR_USART1RST              ((uint32_t)0x00004000U)        /*!< USART1 reset */
#define  RCC_APB2RSTR_TIM15RST               ((uint32_t)0x00010000U)        /*!< TIM15 reset */
#define  RCC_APB2RSTR_TIM16RST               ((uint32_t)0x00020000U)        /*!< TIM16 reset */
#define  RCC_APB2RSTR_TIM17RST               ((uint32_t)0x00040000U)        /*!< TIM17 reset */

/******************  Bit definition for RCC_APB1RSTR register  ******************/
#define  RCC_APB1RSTR_TIM2RST                ((uint32_t)0x00000001U)        /*!< Timer 2 reset */
#define  RCC_APB1RSTR_TIM3RST                ((uint32_t)0x00000002U)        /*!< Timer 3 reset */
#define  RCC_APB1RSTR_TIM4RST                ((uint32_t)0x00000004U)        /*!< Timer 4 reset */
#define  RCC_APB1RSTR_TIM6RST                ((uint32_t)0x00000010U)        /*!< Timer 6 reset */
#define  RCC_APB1RSTR_TIM7RST                ((uint32_t)0x00000020U)        /*!< Timer 7 reset */
#define  RCC_APB1RSTR_WWDGRST                ((uint32_t)0x00000800U)        /*!< Window Watchdog reset */
#define  RCC_APB1RSTR_SPI2RST                ((uint32_t)0x00004000U)        /*!< SPI2 reset */
#define  RCC_APB1RSTR_SPI3RST                ((uint32_t)0x00008000U)        /*!< SPI3 reset */
#define  RCC_APB1RSTR_USART2RST              ((uint32_t)0x00020000U)        /*!< USART 2 reset */
#define  RCC_APB1RSTR_USART3RST              ((uint32_t)0x00040000U)        /*!< USART 3 reset */
#define  RCC_APB1RSTR_UART4RST               ((uint32_t)0x00080000U)        /*!< UART 4 reset */
#define  RCC_APB1RSTR_UART5RST               ((uint32_t)0x00100000U)        /*!< UART 5 reset */
#define  RCC_APB1RSTR_I2C1RST                ((uint32_t)0x00200000U)        /*!< I2C 1 reset */
#define  RCC_APB1RSTR_I2C2RST                ((uint32_t)0x00400000U)        /*!< I2C 2 reset */
#define  RCC_APB1RSTR_USBRST                 ((uint32_t)0x00800000U)        /*!< USB reset */
#define  RCC_APB1RSTR_CANRST                 ((uint32_t)0x02000000U)        /*!< CAN reset */
#define  RCC_APB1RSTR_PWRRST                 ((uint32_t)0x10000000U)        /*!< PWR reset */
#define  RCC_APB1RSTR_DAC1RST                ((uint32_t)0x20000000U)        /*!< DAC 1 reset */

/******************  Bit definition for RCC_AHBENR register  ******************/
#define  RCC_AHBENR_DMA1EN                   ((uint32_t)0x00000001U)        /*!< DMA1 clock enable */
#define  RCC_AHBENR_DMA2EN                   ((uint32_t)0x00000002U)        /*!< DMA2 clock enable */
#define  RCC_AHBENR_SRAMEN                   ((uint32_t)0x00000004U)        /*!< SRAM interface clock enable */
#define  RCC_AHBENR_FLITFEN                  ((uint32_t)0x00000010U)        /*!< FLITF clock enable */
#define  RCC_AHBENR_CRCEN                    ((uint32_t)0x00000040U)        /*!< CRC clock enable */
#define  RCC_AHBENR_GPIOAEN                  ((uint32_t)0x00020000U)        /*!< GPIOA clock enable */
#define  RCC_AHBENR_GPIOBEN                  ((uint32_t)0x00040000U)        /*!< GPIOB clock enable */
#define  RCC_AHBENR_GPIOCEN                  ((uint32_t)0x00080000U)        /*!< GPIOC clock enable */
#define  RCC_AHBENR_GPIODEN                  ((uint32_t)0x00100000U)        /*!< GPIOD clock enable */
#define  RCC_AHBENR_GPIOEEN                  ((uint32_t)0x00200000U)        /*!< GPIOE clock enable */
#define  RCC_AHBENR_GPIOFEN                  ((uint32_t)0x00400000U)        /*!< GPIOF clock enable */
#define  RCC_AHBENR_TSCEN                     ((uint32_t)0x01000000U)       /*!< TS clock enable */
#define  RCC_AHBENR_ADC12EN                  ((uint32_t)0x10000000U)        /*!< ADC1/ ADC2 clock enable */
#define  RCC_AHBENR_ADC34EN                  ((uint32_t)0x20000000U)        /*!< ADC3/ ADC4 clock enable */

/*****************  Bit definition for RCC_APB2ENR register  ******************/
#define  RCC_APB2ENR_SYSCFGEN                ((uint32_t)0x00000001U)        /*!< SYSCFG clock enable */
#define  RCC_APB2ENR_TIM1EN                  ((uint32_t)0x00000800U)        /*!< TIM1 clock enable */
#define  RCC_APB2ENR_SPI1EN                  ((uint32_t)0x00001000U)        /*!< SPI1 clock enable */
#define  RCC_APB2ENR_TIM8EN                  ((uint32_t)0x00002000U)        /*!< TIM8 clock enable */
#define  RCC_APB2ENR_USART1EN                ((uint32_t)0x00004000U)        /*!< USART1 clock enable */
#define  RCC_APB2ENR_TIM15EN                 ((uint32_t)0x00010000U)        /*!< TIM15 clock enable */
#define  RCC_APB2ENR_TIM16EN                 ((uint32_t)0x00020000U)        /*!< TIM16 clock enable */
#define  RCC_APB2ENR_TIM17EN                 ((uint32_t)0x00040000U)        /*!< TIM17 clock enable */

/******************  Bit definition for RCC_APB1ENR register  ******************/
#define  RCC_APB1ENR_TIM2EN                  ((uint32_t)0x00000001U)        /*!< Timer 2 clock enable */
#define  RCC_APB1ENR_TIM3EN                  ((uint32_t)0x00000002U)        /*!< Timer 3 clock enable */
#define  RCC_APB1ENR_TIM4EN                  ((uint32_t)0x00000004U)        /*!< Timer 4 clock enable */
#define  RCC_APB1ENR_TIM6EN                  ((uint32_t)0x00000010U)        /*!< Timer 6 clock enable */
#define  RCC_APB1ENR_TIM7EN                  ((uint32_t)0x00000020U)        /*!< Timer 7 clock enable */
#define  RCC_APB1ENR_WWDGEN                  ((uint32_t)0x00000800U)        /*!< Window Watchdog clock enable */
#define  RCC_APB1ENR_SPI2EN                  ((uint32_t)0x00004000U)        /*!< SPI2 clock enable */
#define  RCC_APB1ENR_SPI3EN                  ((uint32_t)0x00008000U)        /*!< SPI3 clock enable */
#define  RCC_APB1ENR_USART2EN                ((uint32_t)0x00020000U)        /*!< USART 2 clock enable */
#define  RCC_APB1ENR_USART3EN                ((uint32_t)0x00040000U)        /*!< USART 3 clock enable */
#define  RCC_APB1ENR_UART4EN                 ((uint32_t)0x00080000U)        /*!< UART 4 clock enable */
#define  RCC_APB1ENR_UART5EN                 ((uint32_t)0x00100000U)        /*!< UART 5 clock enable */
#define  RCC_APB1ENR_I2C1EN                  ((uint32_t)0x00200000U)        /*!< I2C 1 clock enable */
#define  RCC_APB1ENR_I2C2EN                  ((uint32_t)0x00400000U)        /*!< I2C 2 clock enable */
#define  RCC_APB1ENR_USBEN                   ((uint32_t)0x00800000U)        /*!< USB clock enable */
#define  RCC_APB1ENR_CANEN                   ((uint32_t)0x02000000U)        /*!< CAN clock enable */
#define  RCC_APB1ENR_PWREN                   ((uint32_t)0x10000000U)        /*!< PWR clock enable */
#define  RCC_APB1ENR_DAC1EN                  ((uint32_t)0x20000000U)        /*!< DAC 1 clock enable */

/********************  Bit definition for RCC_BDCR register  ******************/
#define  RCC_BDCR_LSE                        ((uint32_t)0x00000007U)        /*!< External Low Speed oscillator [2:0] bits */
#define  RCC_BDCR_LSEON                      ((uint32_t)0x00000001U)        /*!< External Low Speed oscillator enable */
#define  RCC_BDCR_LSERDY                     ((uint32_t)0x00000002U)        /*!< External Low Speed oscillator Ready */
#define  RCC_BDCR_LSEBYP                     ((uint32_t)0x00000004U)        /*!< External Low Speed oscillator Bypass */

#define  RCC_BDCR_LSEDRV                     ((uint32_t)0x00000018U)        /*!< LSEDRV[1:0] bits (LSE Osc. drive capability) */
#define  RCC_BDCR_LSEDRV_0                   ((uint32_t)0x00000008U)        /*!< Bit 0 */
#define  RCC_BDCR_LSEDRV_1                   ((uint32_t)0x00000010U)        /*!< Bit 1 */

#define  RCC_BDCR_RTCSEL                     ((uint32_t)0x00000300U)        /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define  RCC_BDCR_RTCSEL_0                   ((uint32_t)0x00000100U)        /*!< Bit 0 */
#define  RCC_BDCR_RTCSEL_1                   ((uint32_t)0x00000200U)        /*!< Bit 1 */

/*!< RTC configuration */
#define  RCC_BDCR_RTCSEL_NOCLOCK             ((uint32_t)0x00000000U)        /*!< No clock */
#define  RCC_BDCR_RTCSEL_LSE                 ((uint32_t)0x00000100U)        /*!< LSE oscillator clock used as RTC clock */
#define  RCC_BDCR_RTCSEL_LSI                 ((uint32_t)0x00000200U)        /*!< LSI oscillator clock used as RTC clock */
#define  RCC_BDCR_RTCSEL_HSE                 ((uint32_t)0x00000300U)        /*!< HSE oscillator clock divided by 32 used as RTC clock */

#define  RCC_BDCR_RTCEN                      ((uint32_t)0x00008000U)        /*!< RTC clock enable */
#define  RCC_BDCR_BDRST                      ((uint32_t)0x00010000U)        /*!< Backup domain software reset  */

/********************  Bit definition for RCC_CSR register  *******************/
#define  RCC_CSR_LSION                       ((uint32_t)0x00000001U)        /*!< Internal Low Speed oscillator enable */
#define  RCC_CSR_LSIRDY                      ((uint32_t)0x00000002U)        /*!< Internal Low Speed oscillator Ready */
#define  RCC_CSR_V18PWRRSTF                  ((uint32_t)0x00800000U)        /*!< V1.8 power domain reset flag */
#define  RCC_CSR_RMVF                        ((uint32_t)0x01000000U)        /*!< Remove reset flag */
#define  RCC_CSR_OBLRSTF                     ((uint32_t)0x02000000U)        /*!< OBL reset flag */
#define  RCC_CSR_PINRSTF                     ((uint32_t)0x04000000U)        /*!< PIN reset flag */
#define  RCC_CSR_PORRSTF                     ((uint32_t)0x08000000U)        /*!< POR/PDR reset flag */
#define  RCC_CSR_SFTRSTF                     ((uint32_t)0x10000000U)        /*!< Software Reset flag */
#define  RCC_CSR_IWDGRSTF                    ((uint32_t)0x20000000U)        /*!< Independent Watchdog reset flag */
#define  RCC_CSR_WWDGRSTF                    ((uint32_t)0x40000000U)        /*!< Window watchdog reset flag */
#define  RCC_CSR_LPWRRSTF                    ((uint32_t)0x80000000U)        /*!< Low-Power reset flag */

/* Legacy defines */
#define  RCC_CSR_VREGRSTF                    RCC_CSR_V18PWRRSTF

/*******************  Bit definition for RCC_AHBRSTR register  ****************/
#define  RCC_AHBRSTR_GPIOARST                ((uint32_t)0x00020000U)         /*!< GPIOA reset */
#define  RCC_AHBRSTR_GPIOBRST                ((uint32_t)0x00040000U)         /*!< GPIOB reset */
#define  RCC_AHBRSTR_GPIOCRST                ((uint32_t)0x00080000U)         /*!< GPIOC reset */
#define  RCC_AHBRSTR_GPIODRST                ((uint32_t)0x00100000U)         /*!< GPIOD reset */
#define  RCC_AHBRSTR_GPIOERST                ((uint32_t)0x00200000U)         /*!< GPIOE reset */
#define  RCC_AHBRSTR_GPIOFRST                ((uint32_t)0x00400000U)         /*!< GPIOF reset */
#define  RCC_AHBRSTR_TSCRST                  ((uint32_t)0x01000000U)         /*!< TSC reset */
#define  RCC_AHBRSTR_ADC12RST                ((uint32_t)0x10000000U)         /*!< ADC1 & ADC2 reset */
#define  RCC_AHBRSTR_ADC34RST                ((uint32_t)0x20000000U)         /*!< ADC3 & ADC4 reset */

/*******************  Bit definition for RCC_CFGR2 register  ******************/
/*!< PREDIV configuration */
#define  RCC_CFGR2_PREDIV                    ((uint32_t)0x0000000FU)        /*!< PREDIV[3:0] bits */
#define  RCC_CFGR2_PREDIV_0                  ((uint32_t)0x00000001U)        /*!< Bit 0 */
#define  RCC_CFGR2_PREDIV_1                  ((uint32_t)0x00000002U)        /*!< Bit 1 */
#define  RCC_CFGR2_PREDIV_2                  ((uint32_t)0x00000004U)        /*!< Bit 2 */
#define  RCC_CFGR2_PREDIV_3                  ((uint32_t)0x00000008U)        /*!< Bit 3 */

#define  RCC_CFGR2_PREDIV_DIV1               ((uint32_t)0x00000000U)        /*!< PREDIV input clock not divided */
#define  RCC_CFGR2_PREDIV_DIV2               ((uint32_t)0x00000001U)        /*!< PREDIV input clock divided by 2 */
#define  RCC_CFGR2_PREDIV_DIV3               ((uint32_t)0x00000002U)        /*!< PREDIV input clock divided by 3 */
#define  RCC_CFGR2_PREDIV_DIV4               ((uint32_t)0x00000003U)        /*!< PREDIV input clock divided by 4 */
#define  RCC_CFGR2_PREDIV_DIV5               ((uint32_t)0x00000004U)        /*!< PREDIV input clock divided by 5 */
#define  RCC_CFGR2_PREDIV_DIV6               ((uint32_t)0x00000005U)        /*!< PREDIV input clock divided by 6 */
#define  RCC_CFGR2_PREDIV_DIV7               ((uint32_t)0x00000006U)        /*!< PREDIV input clock divided by 7 */
#define  RCC_CFGR2_PREDIV_DIV8               ((uint32_t)0x00000007U)        /*!< PREDIV input clock divided by 8 */
#define  RCC_CFGR2_PREDIV_DIV9               ((uint32_t)0x00000008U)        /*!< PREDIV input clock divided by 9 */
#define  RCC_CFGR2_PREDIV_DIV10              ((uint32_t)0x00000009U)        /*!< PREDIV input clock divided by 10 */
#define  RCC_CFGR2_PREDIV_DIV11              ((uint32_t)0x0000000AU)        /*!< PREDIV input clock divided by 11 */
#define  RCC_CFGR2_PREDIV_DIV12              ((uint32_t)0x0000000BU)        /*!< PREDIV input clock divided by 12 */
#define  RCC_CFGR2_PREDIV_DIV13              ((uint32_t)0x0000000CU)        /*!< PREDIV input clock divided by 13 */
#define  RCC_CFGR2_PREDIV_DIV14              ((uint32_t)0x0000000DU)        /*!< PREDIV input clock divided by 14 */
#define  RCC_CFGR2_PREDIV_DIV15              ((uint32_t)0x0000000EU)        /*!< PREDIV input clock divided by 15 */
#define  RCC_CFGR2_PREDIV_DIV16              ((uint32_t)0x0000000FU)        /*!< PREDIV input clock divided by 16 */

/*!< ADCPRE12 configuration */
#define  RCC_CFGR2_ADCPRE12                  ((uint32_t)0x000001F0U)        /*!< ADCPRE12[8:4] bits */
#define  RCC_CFGR2_ADCPRE12_0                ((uint32_t)0x00000010U)        /*!< Bit 0 */
#define  RCC_CFGR2_ADCPRE12_1                ((uint32_t)0x00000020U)        /*!< Bit 1 */
#define  RCC_CFGR2_ADCPRE12_2                ((uint32_t)0x00000040U)        /*!< Bit 2 */
#define  RCC_CFGR2_ADCPRE12_3                ((uint32_t)0x00000080U)        /*!< Bit 3 */
#define  RCC_CFGR2_ADCPRE12_4                ((uint32_t)0x00000100U)        /*!< Bit 4 */

#define  RCC_CFGR2_ADCPRE12_NO               ((uint32_t)0x00000000U)        /*!< ADC12 clock disabled, ADC12 can use AHB clock */
#define  RCC_CFGR2_ADCPRE12_DIV1             ((uint32_t)0x00000100U)        /*!< ADC12 PLL clock divided by 1 */
#define  RCC_CFGR2_ADCPRE12_DIV2             ((uint32_t)0x00000110U)        /*!< ADC12 PLL clock divided by 2 */
#define  RCC_CFGR2_ADCPRE12_DIV4             ((uint32_t)0x00000120U)        /*!< ADC12 PLL clock divided by 4 */
#define  RCC_CFGR2_ADCPRE12_DIV6             ((uint32_t)0x00000130U)        /*!< ADC12 PLL clock divided by 6 */
#define  RCC_CFGR2_ADCPRE12_DIV8             ((uint32_t)0x00000140U)        /*!< ADC12 PLL clock divided by 8 */
#define  RCC_CFGR2_ADCPRE12_DIV10            ((uint32_t)0x00000150U)        /*!< ADC12 PLL clock divided by 10 */
#define  RCC_CFGR2_ADCPRE12_DIV12            ((uint32_t)0x00000160U)        /*!< ADC12 PLL clock divided by 12 */
#define  RCC_CFGR2_ADCPRE12_DIV16            ((uint32_t)0x00000170U)        /*!< ADC12 PLL clock divided by 16 */
#define  RCC_CFGR2_ADCPRE12_DIV32            ((uint32_t)0x00000180U)        /*!< ADC12 PLL clock divided by 32 */
#define  RCC_CFGR2_ADCPRE12_DIV64            ((uint32_t)0x00000190U)        /*!< ADC12 PLL clock divided by 64 */
#define  RCC_CFGR2_ADCPRE12_DIV128           ((uint32_t)0x000001A0U)        /*!< ADC12 PLL clock divided by 128 */
#define  RCC_CFGR2_ADCPRE12_DIV256           ((uint32_t)0x000001B0U)        /*!< ADC12 PLL clock divided by 256 */

/*!< ADCPRE34 configuration */
#define  RCC_CFGR2_ADCPRE34                  ((uint32_t)0x00003E00U)        /*!< ADCPRE34[13:5] bits */
#define  RCC_CFGR2_ADCPRE34_0                ((uint32_t)0x00000200U)        /*!< Bit 0 */
#define  RCC_CFGR2_ADCPRE34_1                ((uint32_t)0x00000400U)        /*!< Bit 1 */
#define  RCC_CFGR2_ADCPRE34_2                ((uint32_t)0x00000800U)        /*!< Bit 2 */
#define  RCC_CFGR2_ADCPRE34_3                ((uint32_t)0x00001000U)        /*!< Bit 3 */
#define  RCC_CFGR2_ADCPRE34_4                ((uint32_t)0x00002000U)        /*!< Bit 4 */

#define  RCC_CFGR2_ADCPRE34_NO               ((uint32_t)0x00000000U)        /*!< ADC34 clock disabled, ADC34 can use AHB clock */
#define  RCC_CFGR2_ADCPRE34_DIV1             ((uint32_t)0x00002000U)        /*!< ADC34 PLL clock divided by 1 */
#define  RCC_CFGR2_ADCPRE34_DIV2             ((uint32_t)0x00002200U)        /*!< ADC34 PLL clock divided by 2 */
#define  RCC_CFGR2_ADCPRE34_DIV4             ((uint32_t)0x00002400U)        /*!< ADC34 PLL clock divided by 4 */
#define  RCC_CFGR2_ADCPRE34_DIV6             ((uint32_t)0x00002600U)        /*!< ADC34 PLL clock divided by 6 */
#define  RCC_CFGR2_ADCPRE34_DIV8             ((uint32_t)0x00002800U)        /*!< ADC34 PLL clock divided by 8 */
#define  RCC_CFGR2_ADCPRE34_DIV10            ((uint32_t)0x00002A00U)        /*!< ADC34 PLL clock divided by 10 */
#define  RCC_CFGR2_ADCPRE34_DIV12            ((uint32_t)0x00002C00U)        /*!< ADC34 PLL clock divided by 12 */
#define  RCC_CFGR2_ADCPRE34_DIV16            ((uint32_t)0x00002E00U)        /*!< ADC34 PLL clock divided by 16 */
#define  RCC_CFGR2_ADCPRE34_DIV32            ((uint32_t)0x00003000U)        /*!< ADC34 PLL clock divided by 32 */
#define  RCC_CFGR2_ADCPRE34_DIV64            ((uint32_t)0x00003200U)        /*!< ADC34 PLL clock divided by 64 */
#define  RCC_CFGR2_ADCPRE34_DIV128           ((uint32_t)0x00003400U)        /*!< ADC34 PLL clock divided by 128 */
#define  RCC_CFGR2_ADCPRE34_DIV256           ((uint32_t)0x00003600U)        /*!< ADC34 PLL clock divided by 256 */

/*******************  Bit definition for RCC_CFGR3 register  ******************/
#define  RCC_CFGR3_USART1SW                  ((uint32_t)0x00000003U)        /*!< USART1SW[1:0] bits */
#define  RCC_CFGR3_USART1SW_0                ((uint32_t)0x00000001U)        /*!< Bit 0 */
#define  RCC_CFGR3_USART1SW_1                ((uint32_t)0x00000002U)        /*!< Bit 1 */

#define  RCC_CFGR3_USART1SW_PCLK2            ((uint32_t)0x00000000U)        /*!< PCLK2 clock used as USART1 clock source */
#define  RCC_CFGR3_USART1SW_SYSCLK           ((uint32_t)0x00000001U)        /*!< System clock selected as USART1 clock source */
#define  RCC_CFGR3_USART1SW_LSE              ((uint32_t)0x00000002U)        /*!< LSE oscillator clock used as USART1 clock source */
#define  RCC_CFGR3_USART1SW_HSI              ((uint32_t)0x00000003U)        /*!< HSI oscillator clock used as USART1 clock source */
/* Legacy defines */
#define  RCC_CFGR3_USART1SW_PCLK             RCC_CFGR3_USART1SW_PCLK2

#define  RCC_CFGR3_I2CSW                     ((uint32_t)0x00000030U)        /*!< I2CSW bits */
#define  RCC_CFGR3_I2C1SW                    ((uint32_t)0x00000010U)        /*!< I2C1SW bits */
#define  RCC_CFGR3_I2C2SW                    ((uint32_t)0x00000020U)        /*!< I2C2SW bits */

#define  RCC_CFGR3_I2C1SW_HSI                ((uint32_t)0x00000000U)        /*!< HSI oscillator clock used as I2C1 clock source */
#define  RCC_CFGR3_I2C1SW_SYSCLK             ((uint32_t)0x00000010U)        /*!< System clock selected as I2C1 clock source */
#define  RCC_CFGR3_I2C2SW_HSI                ((uint32_t)0x00000000U)        /*!< HSI oscillator clock used as I2C2 clock source */
#define  RCC_CFGR3_I2C2SW_SYSCLK             ((uint32_t)0x00000020U)        /*!< System clock selected as I2C2 clock source */
#define  RCC_CFGR3_TIMSW                     ((uint32_t)0x00000300U)        /*!< TIMSW bits */
#define  RCC_CFGR3_TIM1SW                    ((uint32_t)0x00000100U)        /*!< TIM1SW bits */
#define  RCC_CFGR3_TIM8SW                    ((uint32_t)0x00000200U)        /*!< TIM8SW bits */
#define  RCC_CFGR3_TIM1SW_PCLK2              ((uint32_t)0x00000000U)        /*!< PCLK2 used as TIM1 clock source */
#define  RCC_CFGR3_TIM1SW_PLL                ((uint32_t)0x00000100U)        /*!< PLL clock used as TIM1 clock source */
#define  RCC_CFGR3_TIM8SW_PCLK2              ((uint32_t)0x00000000U)        /*!< PCLK2 used as TIM8 clock source */
#define  RCC_CFGR3_TIM8SW_PLL                ((uint32_t)0x00000200U)        /*!< PLL clock used as TIM8 clock source */

#define  RCC_CFGR3_USART2SW                  ((uint32_t)0x00030000U)        /*!< USART2SW[1:0] bits */
#define  RCC_CFGR3_USART2SW_0                ((uint32_t)0x00010000U)        /*!< Bit 0 */
#define  RCC_CFGR3_USART2SW_1                ((uint32_t)0x00020000U)        /*!< Bit 1 */

#define  RCC_CFGR3_USART2SW_PCLK             ((uint32_t)0x00000000U)        /*!< PCLK1 clock used as USART2 clock source */
#define  RCC_CFGR3_USART2SW_SYSCLK           ((uint32_t)0x00010000U)        /*!< System clock selected as USART2 clock source */
#define  RCC_CFGR3_USART2SW_LSE              ((uint32_t)0x00020000U)        /*!< LSE oscillator clock used as USART2 clock source */
#define  RCC_CFGR3_USART2SW_HSI              ((uint32_t)0x00030000U)        /*!< HSI oscillator clock used as USART2 clock source */

#define  RCC_CFGR3_USART3SW                  ((uint32_t)0x000C0000U)        /*!< USART3SW[1:0] bits */
#define  RCC_CFGR3_USART3SW_0                ((uint32_t)0x00040000U)        /*!< Bit 0 */
#define  RCC_CFGR3_USART3SW_1                ((uint32_t)0x00080000U)        /*!< Bit 1 */

#define  RCC_CFGR3_USART3SW_PCLK             ((uint32_t)0x00000000U)        /*!< PCLK1 clock used as USART3 clock source */
#define  RCC_CFGR3_USART3SW_SYSCLK           ((uint32_t)0x00040000U)        /*!< System clock selected as USART3 clock source */
#define  RCC_CFGR3_USART3SW_LSE              ((uint32_t)0x00080000U)        /*!< LSE oscillator clock used as USART3 clock source */
#define  RCC_CFGR3_USART3SW_HSI              ((uint32_t)0x000C0000U)        /*!< HSI oscillator clock used as USART3 clock source */

#define  RCC_CFGR3_UART4SW                   ((uint32_t)0x00300000U)        /*!< UART4SW[1:0] bits */
#define  RCC_CFGR3_UART4SW_0                 ((uint32_t)0x00100000U)        /*!< Bit 0 */
#define  RCC_CFGR3_UART4SW_1                 ((uint32_t)0x00200000U)        /*!< Bit 1 */

#define  RCC_CFGR3_UART4SW_PCLK              ((uint32_t)0x00000000U)        /*!< PCLK1 clock used as UART4 clock source */
#define  RCC_CFGR3_UART4SW_SYSCLK            ((uint32_t)0x00100000U)        /*!< System clock selected as UART4 clock source */
#define  RCC_CFGR3_UART4SW_LSE               ((uint32_t)0x00200000U)        /*!< LSE oscillator clock used as UART4 clock source */
#define  RCC_CFGR3_UART4SW_HSI               ((uint32_t)0x00300000U)        /*!< HSI oscillator clock used as UART4 clock source */

#define  RCC_CFGR3_UART5SW                   ((uint32_t)0x00C00000U)        /*!< UART5SW[1:0] bits */
#define  RCC_CFGR3_UART5SW_0                 ((uint32_t)0x00400000U)        /*!< Bit 0 */
#define  RCC_CFGR3_UART5SW_1                 ((uint32_t)0x00800000U)        /*!< Bit 1 */

#define  RCC_CFGR3_UART5SW_PCLK              ((uint32_t)0x00000000U)        /*!< PCLK1 clock used as UART5 clock source */
#define  RCC_CFGR3_UART5SW_SYSCLK            ((uint32_t)0x00400000U)        /*!< System clock selected as UART5 clock source */
#define  RCC_CFGR3_UART5SW_LSE               ((uint32_t)0x00800000U)        /*!< LSE oscillator clock used as UART5 clock source */
#define  RCC_CFGR3_UART5SW_HSI               ((uint32_t)0x00C00000U)        /*!< HSI oscillator clock used as UART5 clock source */

/* Legacy defines */
#define  RCC_CFGR3_TIM1SW_HCLK                RCC_CFGR3_TIM1SW_PCLK2
#define  RCC_CFGR3_TIM8SW_HCLK                RCC_CFGR3_TIM8SW_PCLK2

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/*
* @brief Specific device feature definitions  (not present on all devices in the STM32F3 family)
*/
#define RTC_TAMPER1_SUPPORT  /*!< TAMPER 1 feature support */
#define RTC_TAMPER2_SUPPORT  /*!< TAMPER 2 feature support */
#define RTC_TAMPER3_SUPPORT  /*!< TAMPER 3 feature support */
#define RTC_BACKUP_SUPPORT   /*!< BACKUP register feature support */
#define RTC_WAKEUP_SUPPORT   /*!< WAKEUP feature support */

/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM                            ((uint32_t)0x00400000U)
#define RTC_TR_HT                            ((uint32_t)0x00300000U)
#define RTC_TR_HT_0                          ((uint32_t)0x00100000U)
#define RTC_TR_HT_1                          ((uint32_t)0x00200000U)
#define RTC_TR_HU                            ((uint32_t)0x000F0000U)
#define RTC_TR_HU_0                          ((uint32_t)0x00010000U)
#define RTC_TR_HU_1                          ((uint32_t)0x00020000U)
#define RTC_TR_HU_2                          ((uint32_t)0x00040000U)
#define RTC_TR_HU_3                          ((uint32_t)0x00080000U)
#define RTC_TR_MNT                           ((uint32_t)0x00007000U)
#define RTC_TR_MNT_0                         ((uint32_t)0x00001000U)
#define RTC_TR_MNT_1                         ((uint32_t)0x00002000U)
#define RTC_TR_MNT_2                         ((uint32_t)0x00004000U)
#define RTC_TR_MNU                           ((uint32_t)0x00000F00U)
#define RTC_TR_MNU_0                         ((uint32_t)0x00000100U)
#define RTC_TR_MNU_1                         ((uint32_t)0x00000200U)
#define RTC_TR_MNU_2                         ((uint32_t)0x00000400U)
#define RTC_TR_MNU_3                         ((uint32_t)0x00000800U)
#define RTC_TR_ST                            ((uint32_t)0x00000070U)
#define RTC_TR_ST_0                          ((uint32_t)0x00000010U)
#define RTC_TR_ST_1                          ((uint32_t)0x00000020U)
#define RTC_TR_ST_2                          ((uint32_t)0x00000040U)
#define RTC_TR_SU                            ((uint32_t)0x0000000FU)
#define RTC_TR_SU_0                          ((uint32_t)0x00000001U)
#define RTC_TR_SU_1                          ((uint32_t)0x00000002U)
#define RTC_TR_SU_2                          ((uint32_t)0x00000004U)
#define RTC_TR_SU_3                          ((uint32_t)0x00000008U)

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT                            ((uint32_t)0x00F00000U)
#define RTC_DR_YT_0                          ((uint32_t)0x00100000U)
#define RTC_DR_YT_1                          ((uint32_t)0x00200000U)
#define RTC_DR_YT_2                          ((uint32_t)0x00400000U)
#define RTC_DR_YT_3                          ((uint32_t)0x00800000U)
#define RTC_DR_YU                            ((uint32_t)0x000F0000U)
#define RTC_DR_YU_0                          ((uint32_t)0x00010000U)
#define RTC_DR_YU_1                          ((uint32_t)0x00020000U)
#define RTC_DR_YU_2                          ((uint32_t)0x00040000U)
#define RTC_DR_YU_3                          ((uint32_t)0x00080000U)
#define RTC_DR_WDU                           ((uint32_t)0x0000E000U)
#define RTC_DR_WDU_0                         ((uint32_t)0x00002000U)
#define RTC_DR_WDU_1                         ((uint32_t)0x00004000U)
#define RTC_DR_WDU_2                         ((uint32_t)0x00008000U)
#define RTC_DR_MT                            ((uint32_t)0x00001000U)
#define RTC_DR_MU                            ((uint32_t)0x00000F00U)
#define RTC_DR_MU_0                          ((uint32_t)0x00000100U)
#define RTC_DR_MU_1                          ((uint32_t)0x00000200U)
#define RTC_DR_MU_2                          ((uint32_t)0x00000400U)
#define RTC_DR_MU_3                          ((uint32_t)0x00000800U)
#define RTC_DR_DT                            ((uint32_t)0x00000030U)
#define RTC_DR_DT_0                          ((uint32_t)0x00000010U)
#define RTC_DR_DT_1                          ((uint32_t)0x00000020U)
#define RTC_DR_DU                            ((uint32_t)0x0000000FU)
#define RTC_DR_DU_0                          ((uint32_t)0x00000001U)
#define RTC_DR_DU_1                          ((uint32_t)0x00000002U)
#define RTC_DR_DU_2                          ((uint32_t)0x00000004U)
#define RTC_DR_DU_3                          ((uint32_t)0x00000008U)

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_COE                           ((uint32_t)0x00800000U)
#define RTC_CR_OSEL                          ((uint32_t)0x00600000U)
#define RTC_CR_OSEL_0                        ((uint32_t)0x00200000U)
#define RTC_CR_OSEL_1                        ((uint32_t)0x00400000U)
#define RTC_CR_POL                           ((uint32_t)0x00100000U)
#define RTC_CR_COSEL                         ((uint32_t)0x00080000U)
#define RTC_CR_BCK                           ((uint32_t)0x00040000U)
#define RTC_CR_SUB1H                         ((uint32_t)0x00020000U)
#define RTC_CR_ADD1H                         ((uint32_t)0x00010000U)
#define RTC_CR_TSIE                          ((uint32_t)0x00008000U)
#define RTC_CR_WUTIE                         ((uint32_t)0x00004000U)
#define RTC_CR_ALRBIE                        ((uint32_t)0x00002000U)
#define RTC_CR_ALRAIE                        ((uint32_t)0x00001000U)
#define RTC_CR_TSE                           ((uint32_t)0x00000800U)
#define RTC_CR_WUTE                          ((uint32_t)0x00000400U)
#define RTC_CR_ALRBE                         ((uint32_t)0x00000200U)
#define RTC_CR_ALRAE                         ((uint32_t)0x00000100U)
#define RTC_CR_FMT                           ((uint32_t)0x00000040U)
#define RTC_CR_BYPSHAD                       ((uint32_t)0x00000020U)
#define RTC_CR_REFCKON                       ((uint32_t)0x00000010U)
#define RTC_CR_TSEDGE                        ((uint32_t)0x00000008U)
#define RTC_CR_WUCKSEL                       ((uint32_t)0x00000007U)
#define RTC_CR_WUCKSEL_0                     ((uint32_t)0x00000001U)
#define RTC_CR_WUCKSEL_1                     ((uint32_t)0x00000002U)
#define RTC_CR_WUCKSEL_2                     ((uint32_t)0x00000004U)

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_RECALPF                      ((uint32_t)0x00010000U)
#define RTC_ISR_TAMP3F                       ((uint32_t)0x00008000U)
#define RTC_ISR_TAMP2F                       ((uint32_t)0x00004000U)
#define RTC_ISR_TAMP1F                       ((uint32_t)0x00002000U)
#define RTC_ISR_TSOVF                        ((uint32_t)0x00001000U)
#define RTC_ISR_TSF                          ((uint32_t)0x00000800U)
#define RTC_ISR_WUTF                         ((uint32_t)0x00000400U)
#define RTC_ISR_ALRBF                        ((uint32_t)0x00000200U)
#define RTC_ISR_ALRAF                        ((uint32_t)0x00000100U)
#define RTC_ISR_INIT                         ((uint32_t)0x00000080U)
#define RTC_ISR_INITF                        ((uint32_t)0x00000040U)
#define RTC_ISR_RSF                          ((uint32_t)0x00000020U)
#define RTC_ISR_INITS                        ((uint32_t)0x00000010U)
#define RTC_ISR_SHPF                         ((uint32_t)0x00000008U)
#define RTC_ISR_WUTWF                        ((uint32_t)0x00000004U)
#define RTC_ISR_ALRBWF                       ((uint32_t)0x00000002U)
#define RTC_ISR_ALRAWF                       ((uint32_t)0x00000001U)

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A                    ((uint32_t)0x007F0000U)
#define RTC_PRER_PREDIV_S                    ((uint32_t)0x00007FFFU)

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT                         ((uint32_t)0x0000FFFFU)

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4                      ((uint32_t)0x80000000U)
#define RTC_ALRMAR_WDSEL                     ((uint32_t)0x40000000U)
#define RTC_ALRMAR_DT                        ((uint32_t)0x30000000U)
#define RTC_ALRMAR_DT_0                      ((uint32_t)0x10000000U)
#define RTC_ALRMAR_DT_1                      ((uint32_t)0x20000000U)
#define RTC_ALRMAR_DU                        ((uint32_t)0x0F000000U)
#define RTC_ALRMAR_DU_0                      ((uint32_t)0x01000000U)
#define RTC_ALRMAR_DU_1                      ((uint32_t)0x02000000U)
#define RTC_ALRMAR_DU_2                      ((uint32_t)0x04000000U)
#define RTC_ALRMAR_DU_3                      ((uint32_t)0x08000000U)
#define RTC_ALRMAR_MSK3                      ((uint32_t)0x00800000U)
#define RTC_ALRMAR_PM                        ((uint32_t)0x00400000U)
#define RTC_ALRMAR_HT                        ((uint32_t)0x00300000U)
#define RTC_ALRMAR_HT_0                      ((uint32_t)0x00100000U)
#define RTC_ALRMAR_HT_1                      ((uint32_t)0x00200000U)
#define RTC_ALRMAR_HU                        ((uint32_t)0x000F0000U)
#define RTC_ALRMAR_HU_0                      ((uint32_t)0x00010000U)
#define RTC_ALRMAR_HU_1                      ((uint32_t)0x00020000U)
#define RTC_ALRMAR_HU_2                      ((uint32_t)0x00040000U)
#define RTC_ALRMAR_HU_3                      ((uint32_t)0x00080000U)
#define RTC_ALRMAR_MSK2                      ((uint32_t)0x00008000U)
#define RTC_ALRMAR_MNT                       ((uint32_t)0x00007000U)
#define RTC_ALRMAR_MNT_0                     ((uint32_t)0x00001000U)
#define RTC_ALRMAR_MNT_1                     ((uint32_t)0x00002000U)
#define RTC_ALRMAR_MNT_2                     ((uint32_t)0x00004000U)
#define RTC_ALRMAR_MNU                       ((uint32_t)0x00000F00U)
#define RTC_ALRMAR_MNU_0                     ((uint32_t)0x00000100U)
#define RTC_ALRMAR_MNU_1                     ((uint32_t)0x00000200U)
#define RTC_ALRMAR_MNU_2                     ((uint32_t)0x00000400U)
#define RTC_ALRMAR_MNU_3                     ((uint32_t)0x00000800U)
#define RTC_ALRMAR_MSK1                      ((uint32_t)0x00000080U)
#define RTC_ALRMAR_ST                        ((uint32_t)0x00000070U)
#define RTC_ALRMAR_ST_0                      ((uint32_t)0x00000010U)
#define RTC_ALRMAR_ST_1                      ((uint32_t)0x00000020U)
#define RTC_ALRMAR_ST_2                      ((uint32_t)0x00000040U)
#define RTC_ALRMAR_SU                        ((uint32_t)0x0000000FU)
#define RTC_ALRMAR_SU_0                      ((uint32_t)0x00000001U)
#define RTC_ALRMAR_SU_1                      ((uint32_t)0x00000002U)
#define RTC_ALRMAR_SU_2                      ((uint32_t)0x00000004U)
#define RTC_ALRMAR_SU_3                      ((uint32_t)0x00000008U)

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4                      ((uint32_t)0x80000000U)
#define RTC_ALRMBR_WDSEL                     ((uint32_t)0x40000000U)
#define RTC_ALRMBR_DT                        ((uint32_t)0x30000000U)
#define RTC_ALRMBR_DT_0                      ((uint32_t)0x10000000U)
#define RTC_ALRMBR_DT_1                      ((uint32_t)0x20000000U)
#define RTC_ALRMBR_DU                        ((uint32_t)0x0F000000U)
#define RTC_ALRMBR_DU_0                      ((uint32_t)0x01000000U)
#define RTC_ALRMBR_DU_1                      ((uint32_t)0x02000000U)
#define RTC_ALRMBR_DU_2                      ((uint32_t)0x04000000U)
#define RTC_ALRMBR_DU_3                      ((uint32_t)0x08000000U)
#define RTC_ALRMBR_MSK3                      ((uint32_t)0x00800000U)
#define RTC_ALRMBR_PM                        ((uint32_t)0x00400000U)
#define RTC_ALRMBR_HT                        ((uint32_t)0x00300000U)
#define RTC_ALRMBR_HT_0                      ((uint32_t)0x00100000U)
#define RTC_ALRMBR_HT_1                      ((uint32_t)0x00200000U)
#define RTC_ALRMBR_HU                        ((uint32_t)0x000F0000U)
#define RTC_ALRMBR_HU_0                      ((uint32_t)0x00010000U)
#define RTC_ALRMBR_HU_1                      ((uint32_t)0x00020000U)
#define RTC_ALRMBR_HU_2                      ((uint32_t)0x00040000U)
#define RTC_ALRMBR_HU_3                      ((uint32_t)0x00080000U)
#define RTC_ALRMBR_MSK2                      ((uint32_t)0x00008000U)
#define RTC_ALRMBR_MNT                       ((uint32_t)0x00007000U)
#define RTC_ALRMBR_MNT_0                     ((uint32_t)0x00001000U)
#define RTC_ALRMBR_MNT_1                     ((uint32_t)0x00002000U)
#define RTC_ALRMBR_MNT_2                     ((uint32_t)0x00004000U)
#define RTC_ALRMBR_MNU                       ((uint32_t)0x00000F00U)
#define RTC_ALRMBR_MNU_0                     ((uint32_t)0x00000100U)
#define RTC_ALRMBR_MNU_1                     ((uint32_t)0x00000200U)
#define RTC_ALRMBR_MNU_2                     ((uint32_t)0x00000400U)
#define RTC_ALRMBR_MNU_3                     ((uint32_t)0x00000800U)
#define RTC_ALRMBR_MSK1                      ((uint32_t)0x00000080U)
#define RTC_ALRMBR_ST                        ((uint32_t)0x00000070U)
#define RTC_ALRMBR_ST_0                      ((uint32_t)0x00000010U)
#define RTC_ALRMBR_ST_1                      ((uint32_t)0x00000020U)
#define RTC_ALRMBR_ST_2                      ((uint32_t)0x00000040U)
#define RTC_ALRMBR_SU                        ((uint32_t)0x0000000FU)
#define RTC_ALRMBR_SU_0                      ((uint32_t)0x00000001U)
#define RTC_ALRMBR_SU_1                      ((uint32_t)0x00000002U)
#define RTC_ALRMBR_SU_2                      ((uint32_t)0x00000004U)
#define RTC_ALRMBR_SU_3                      ((uint32_t)0x00000008U)

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY                          ((uint32_t)0x000000FFU)

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS                           ((uint32_t)0x0000FFFFU)

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS                     ((uint32_t)0x00007FFFU)
#define RTC_SHIFTR_ADD1S                     ((uint32_t)0x80000000U)

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM                          ((uint32_t)0x00400000U)
#define RTC_TSTR_HT                          ((uint32_t)0x00300000U)
#define RTC_TSTR_HT_0                        ((uint32_t)0x00100000U)
#define RTC_TSTR_HT_1                        ((uint32_t)0x00200000U)
#define RTC_TSTR_HU                          ((uint32_t)0x000F0000U)
#define RTC_TSTR_HU_0                        ((uint32_t)0x00010000U)
#define RTC_TSTR_HU_1                        ((uint32_t)0x00020000U)
#define RTC_TSTR_HU_2                        ((uint32_t)0x00040000U)
#define RTC_TSTR_HU_3                        ((uint32_t)0x00080000U)
#define RTC_TSTR_MNT                         ((uint32_t)0x00007000U)
#define RTC_TSTR_MNT_0                       ((uint32_t)0x00001000U)
#define RTC_TSTR_MNT_1                       ((uint32_t)0x00002000U)
#define RTC_TSTR_MNT_2                       ((uint32_t)0x00004000U)
#define RTC_TSTR_MNU                         ((uint32_t)0x00000F00U)
#define RTC_TSTR_MNU_0                       ((uint32_t)0x00000100U)
#define RTC_TSTR_MNU_1                       ((uint32_t)0x00000200U)
#define RTC_TSTR_MNU_2                       ((uint32_t)0x00000400U)
#define RTC_TSTR_MNU_3                       ((uint32_t)0x00000800U)
#define RTC_TSTR_ST                          ((uint32_t)0x00000070U)
#define RTC_TSTR_ST_0                        ((uint32_t)0x00000010U)
#define RTC_TSTR_ST_1                        ((uint32_t)0x00000020U)
#define RTC_TSTR_ST_2                        ((uint32_t)0x00000040U)
#define RTC_TSTR_SU                          ((uint32_t)0x0000000FU)
#define RTC_TSTR_SU_0                        ((uint32_t)0x00000001U)
#define RTC_TSTR_SU_1                        ((uint32_t)0x00000002U)
#define RTC_TSTR_SU_2                        ((uint32_t)0x00000004U)
#define RTC_TSTR_SU_3                        ((uint32_t)0x00000008U)

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU                         ((uint32_t)0x0000E000U)
#define RTC_TSDR_WDU_0                       ((uint32_t)0x00002000U)
#define RTC_TSDR_WDU_1                       ((uint32_t)0x00004000U)
#define RTC_TSDR_WDU_2                       ((uint32_t)0x00008000U)
#define RTC_TSDR_MT                          ((uint32_t)0x00001000U)
#define RTC_TSDR_MU                          ((uint32_t)0x00000F00U)
#define RTC_TSDR_MU_0                        ((uint32_t)0x00000100U)
#define RTC_TSDR_MU_1                        ((uint32_t)0x00000200U)
#define RTC_TSDR_MU_2                        ((uint32_t)0x00000400U)
#define RTC_TSDR_MU_3                        ((uint32_t)0x00000800U)
#define RTC_TSDR_DT                          ((uint32_t)0x00000030U)
#define RTC_TSDR_DT_0                        ((uint32_t)0x00000010U)
#define RTC_TSDR_DT_1                        ((uint32_t)0x00000020U)
#define RTC_TSDR_DU                          ((uint32_t)0x0000000FU)
#define RTC_TSDR_DU_0                        ((uint32_t)0x00000001U)
#define RTC_TSDR_DU_1                        ((uint32_t)0x00000002U)
#define RTC_TSDR_DU_2                        ((uint32_t)0x00000004U)
#define RTC_TSDR_DU_3                        ((uint32_t)0x00000008U)

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS                         ((uint32_t)0x0000FFFFU)

/********************  Bits definition for RTC_CAL register  *****************/
#define RTC_CALR_CALP                        ((uint32_t)0x00008000U)
#define RTC_CALR_CALW8                       ((uint32_t)0x00004000U)
#define RTC_CALR_CALW16                      ((uint32_t)0x00002000U)
#define RTC_CALR_CALM                        ((uint32_t)0x000001FFU)
#define RTC_CALR_CALM_0                      ((uint32_t)0x00000001U)
#define RTC_CALR_CALM_1                      ((uint32_t)0x00000002U)
#define RTC_CALR_CALM_2                      ((uint32_t)0x00000004U)
#define RTC_CALR_CALM_3                      ((uint32_t)0x00000008U)
#define RTC_CALR_CALM_4                      ((uint32_t)0x00000010U)
#define RTC_CALR_CALM_5                      ((uint32_t)0x00000020U)
#define RTC_CALR_CALM_6                      ((uint32_t)0x00000040U)
#define RTC_CALR_CALM_7                      ((uint32_t)0x00000080U)
#define RTC_CALR_CALM_8                      ((uint32_t)0x00000100U)

/********************  Bits definition for RTC_TAFCR register  ****************/
#define RTC_TAFCR_PC15MODE                   ((uint32_t)0x00800000U)
#define RTC_TAFCR_PC15VALUE                  ((uint32_t)0x00400000U)
#define RTC_TAFCR_PC14MODE                   ((uint32_t)0x00200000U)
#define RTC_TAFCR_PC14VALUE                  ((uint32_t)0x00100000U)
#define RTC_TAFCR_PC13MODE                   ((uint32_t)0x00080000U)
#define RTC_TAFCR_PC13VALUE                  ((uint32_t)0x00040000U)
#define RTC_TAFCR_TAMPPUDIS                  ((uint32_t)0x00008000U)
#define RTC_TAFCR_TAMPPRCH                   ((uint32_t)0x00006000U)
#define RTC_TAFCR_TAMPPRCH_0                 ((uint32_t)0x00002000U)
#define RTC_TAFCR_TAMPPRCH_1                 ((uint32_t)0x00004000U)
#define RTC_TAFCR_TAMPFLT                    ((uint32_t)0x00001800U)
#define RTC_TAFCR_TAMPFLT_0                  ((uint32_t)0x00000800U)
#define RTC_TAFCR_TAMPFLT_1                  ((uint32_t)0x00001000U)
#define RTC_TAFCR_TAMPFREQ                   ((uint32_t)0x00000700U)
#define RTC_TAFCR_TAMPFREQ_0                 ((uint32_t)0x00000100U)
#define RTC_TAFCR_TAMPFREQ_1                 ((uint32_t)0x00000200U)
#define RTC_TAFCR_TAMPFREQ_2                 ((uint32_t)0x00000400U)
#define RTC_TAFCR_TAMPTS                     ((uint32_t)0x00000080U)
#define RTC_TAFCR_TAMP3TRG                   ((uint32_t)0x00000040U)
#define RTC_TAFCR_TAMP3E                     ((uint32_t)0x00000020U)
#define RTC_TAFCR_TAMP2TRG                   ((uint32_t)0x00000010U)
#define RTC_TAFCR_TAMP2E                     ((uint32_t)0x00000008U)
#define RTC_TAFCR_TAMPIE                     ((uint32_t)0x00000004U)
#define RTC_TAFCR_TAMP1TRG                   ((uint32_t)0x00000002U)
#define RTC_TAFCR_TAMP1E                     ((uint32_t)0x00000001U)

/* Reference defines */
#define RTC_TAFCR_ALARMOUTTYPE               RTC_TAFCR_PC13VALUE

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS                  ((uint32_t)0x0F000000U)
#define RTC_ALRMASSR_MASKSS_0                ((uint32_t)0x01000000U)
#define RTC_ALRMASSR_MASKSS_1                ((uint32_t)0x02000000U)
#define RTC_ALRMASSR_MASKSS_2                ((uint32_t)0x04000000U)
#define RTC_ALRMASSR_MASKSS_3                ((uint32_t)0x08000000U)
#define RTC_ALRMASSR_SS                      ((uint32_t)0x00007FFFU)

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS                  ((uint32_t)0x0F000000U)
#define RTC_ALRMBSSR_MASKSS_0                ((uint32_t)0x01000000U)
#define RTC_ALRMBSSR_MASKSS_1                ((uint32_t)0x02000000U)
#define RTC_ALRMBSSR_MASKSS_2                ((uint32_t)0x04000000U)
#define RTC_ALRMBSSR_MASKSS_3                ((uint32_t)0x08000000U)
#define RTC_ALRMBSSR_SS                      ((uint32_t)0x00007FFFU)

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R                            ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R                           ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R                           ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R                           ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R                           ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R                           ((uint32_t)0xFFFFFFFFU)

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R                           ((uint32_t)0xFFFFFFFFU)

/******************** Number of backup registers ******************************/
#define RTC_BKP_NUMBER                       16

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface (SPI)                   */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F3 family)
 */
#define SPI_I2S_SUPPORT                       /*!< I2S support */
#define SPI_I2S_FULLDUPLEX_SUPPORT            /*!< I2S Full-Duplex support */

/*******************  Bit definition for SPI_CR1 register  ********************/
#define  SPI_CR1_CPHA                        ((uint32_t)0x00000001U)        /*!< Clock Phase */
#define  SPI_CR1_CPOL                        ((uint32_t)0x00000002U)        /*!< Clock Polarity */
#define  SPI_CR1_MSTR                        ((uint32_t)0x00000004U)        /*!< Master Selection */
#define  SPI_CR1_BR                          ((uint32_t)0x00000038U)        /*!< BR[2:0] bits (Baud Rate Control) */
#define  SPI_CR1_BR_0                        ((uint32_t)0x00000008U)        /*!< Bit 0 */
#define  SPI_CR1_BR_1                        ((uint32_t)0x00000010U)        /*!< Bit 1 */
#define  SPI_CR1_BR_2                        ((uint32_t)0x00000020U)        /*!< Bit 2 */
#define  SPI_CR1_SPE                         ((uint32_t)0x00000040U)        /*!< SPI Enable */
#define  SPI_CR1_LSBFIRST                    ((uint32_t)0x00000080U)        /*!< Frame Format */
#define  SPI_CR1_SSI                         ((uint32_t)0x00000100U)        /*!< Internal slave select */
#define  SPI_CR1_SSM                         ((uint32_t)0x00000200U)        /*!< Software slave management */
#define  SPI_CR1_RXONLY                      ((uint32_t)0x00000400U)        /*!< Receive only */
#define  SPI_CR1_CRCL                        ((uint32_t)0x00000800U)        /*!< CRC Length */
#define  SPI_CR1_CRCNEXT                     ((uint32_t)0x00001000U)        /*!< Transmit CRC next */
#define  SPI_CR1_CRCEN                       ((uint32_t)0x00002000U)        /*!< Hardware CRC calculation enable */
#define  SPI_CR1_BIDIOE                      ((uint32_t)0x00004000U)        /*!< Output enable in bidirectional mode */
#define  SPI_CR1_BIDIMODE                    ((uint32_t)0x00008000U)        /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define  SPI_CR2_RXDMAEN                     ((uint32_t)0x00000001U)        /*!< Rx Buffer DMA Enable */
#define  SPI_CR2_TXDMAEN                     ((uint32_t)0x00000002U)        /*!< Tx Buffer DMA Enable */
#define  SPI_CR2_SSOE                        ((uint32_t)0x00000004U)        /*!< SS Output Enable */
#define  SPI_CR2_NSSP                        ((uint32_t)0x00000008U)        /*!< NSS pulse management Enable */
#define  SPI_CR2_FRF                         ((uint32_t)0x00000010U)        /*!< Frame Format Enable */
#define  SPI_CR2_ERRIE                       ((uint32_t)0x00000020U)        /*!< Error Interrupt Enable */
#define  SPI_CR2_RXNEIE                      ((uint32_t)0x00000040U)        /*!< RX buffer Not Empty Interrupt Enable */
#define  SPI_CR2_TXEIE                       ((uint32_t)0x00000080U)        /*!< Tx buffer Empty Interrupt Enable */
#define  SPI_CR2_DS                          ((uint32_t)0x00000F00U)        /*!< DS[3:0] Data Size */
#define  SPI_CR2_DS_0                        ((uint32_t)0x00000100U)        /*!< Bit 0 */
#define  SPI_CR2_DS_1                        ((uint32_t)0x00000200U)        /*!< Bit 1 */
#define  SPI_CR2_DS_2                        ((uint32_t)0x00000400U)        /*!< Bit 2 */
#define  SPI_CR2_DS_3                        ((uint32_t)0x00000800U)        /*!< Bit 3 */
#define  SPI_CR2_FRXTH                       ((uint32_t)0x00001000U)        /*!< FIFO reception Threshold */
#define  SPI_CR2_LDMARX                      ((uint32_t)0x00002000U)        /*!< Last DMA transfer for reception */
#define  SPI_CR2_LDMATX                      ((uint32_t)0x00004000U)        /*!< Last DMA transfer for transmission */

/********************  Bit definition for SPI_SR register  ********************/
#define  SPI_SR_RXNE                         ((uint32_t)0x00000001U)        /*!< Receive buffer Not Empty */
#define  SPI_SR_TXE                          ((uint32_t)0x00000002U)        /*!< Transmit buffer Empty */
#define  SPI_SR_CHSIDE                       ((uint32_t)0x00000004U)        /*!< Channel side */
#define  SPI_SR_UDR                          ((uint32_t)0x00000008U)        /*!< Underrun flag */
#define  SPI_SR_CRCERR                       ((uint32_t)0x00000010U)        /*!< CRC Error flag */
#define  SPI_SR_MODF                         ((uint32_t)0x00000020U)        /*!< Mode fault */
#define  SPI_SR_OVR                          ((uint32_t)0x00000040U)        /*!< Overrun flag */
#define  SPI_SR_BSY                          ((uint32_t)0x00000080U)        /*!< Busy flag */
#define  SPI_SR_FRE                          ((uint32_t)0x00000100U)        /*!< TI frame format error */
#define  SPI_SR_FRLVL                        ((uint32_t)0x00000600U)        /*!< FIFO Reception Level */
#define  SPI_SR_FRLVL_0                      ((uint32_t)0x00000200U)        /*!< Bit 0 */
#define  SPI_SR_FRLVL_1                      ((uint32_t)0x00000400U)        /*!< Bit 1 */
#define  SPI_SR_FTLVL                        ((uint32_t)0x00001800U)        /*!< FIFO Transmission Level */
#define  SPI_SR_FTLVL_0                      ((uint32_t)0x00000800U)        /*!< Bit 0 */
#define  SPI_SR_FTLVL_1                      ((uint32_t)0x00001000U)        /*!< Bit 1 */

/********************  Bit definition for SPI_DR register  ********************/
#define  SPI_DR_DR                           ((uint32_t)0x0000FFFFU)        /*!< Data Register */

/*******************  Bit definition for SPI_CRCPR register  ******************/
#define  SPI_CRCPR_CRCPOLY                   ((uint32_t)0x0000FFFFU)        /*!< CRC polynomial register */

/******************  Bit definition for SPI_RXCRCR register  ******************/
#define  SPI_RXCRCR_RXCRC                    ((uint32_t)0x0000FFFFU)        /*!< Rx CRC Register */

/******************  Bit definition for SPI_TXCRCR register  ******************/
#define  SPI_TXCRCR_TXCRC                    ((uint32_t)0x0000FFFFU)        /*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define  SPI_I2SCFGR_CHLEN                   ((uint32_t)0x00000001U)        /*!<Channel length (number of bits per audio channel) */
#define  SPI_I2SCFGR_DATLEN                  ((uint32_t)0x00000006U)        /*!<DATLEN[1:0] bits (Data length to be transferred) */
#define  SPI_I2SCFGR_DATLEN_0                ((uint32_t)0x00000002U)        /*!<Bit 0 */
#define  SPI_I2SCFGR_DATLEN_1                ((uint32_t)0x00000004U)        /*!<Bit 1 */
#define  SPI_I2SCFGR_CKPOL                   ((uint32_t)0x00000008U)        /*!<steady state clock polarity */
#define  SPI_I2SCFGR_I2SSTD                  ((uint32_t)0x00000030U)        /*!<I2SSTD[1:0] bits (I2S standard selection) */
#define  SPI_I2SCFGR_I2SSTD_0                ((uint32_t)0x00000010U)        /*!<Bit 0 */
#define  SPI_I2SCFGR_I2SSTD_1                ((uint32_t)0x00000020U)        /*!<Bit 1 */
#define  SPI_I2SCFGR_PCMSYNC                 ((uint32_t)0x00000080U)        /*!<PCM frame synchronization */
#define  SPI_I2SCFGR_I2SCFG                  ((uint32_t)0x00000300U)        /*!<I2SCFG[1:0] bits (I2S configuration mode) */
#define  SPI_I2SCFGR_I2SCFG_0                ((uint32_t)0x00000100U)        /*!<Bit 0 */
#define  SPI_I2SCFGR_I2SCFG_1                ((uint32_t)0x00000200U)        /*!<Bit 1 */
#define  SPI_I2SCFGR_I2SE                    ((uint32_t)0x00000400U)        /*!<I2S Enable */
#define  SPI_I2SCFGR_I2SMOD                  ((uint32_t)0x00000800U)        /*!<I2S mode selection */

/******************  Bit definition for SPI_I2SPR register  *******************/
#define  SPI_I2SPR_I2SDIV                    ((uint32_t)0x000000FFU)        /*!<I2S Linear prescaler */
#define  SPI_I2SPR_ODD                       ((uint32_t)0x00000100U)        /*!<Odd factor for the prescaler */
#define  SPI_I2SPR_MCKOE                     ((uint32_t)0x00000200U)        /*!<Master Clock Output Enable */

/******************************************************************************/
/*                                                                            */
/*                        System Configuration(SYSCFG)                        */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SYSCFG_CFGR1 register  ****************/
#define SYSCFG_CFGR1_MEM_MODE               ((uint32_t)0x00000003U) /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0             ((uint32_t)0x00000001U) /*!< Bit 0 */
#define SYSCFG_CFGR1_MEM_MODE_1             ((uint32_t)0x00000002U) /*!< Bit 1 */
#define SYSCFG_CFGR1_USB_IT_RMP             ((uint32_t)0x00000020U) /*!< USB interrupt remap */
#define SYSCFG_CFGR1_TIM1_ITR3_RMP          ((uint32_t)0x00000040U) /*!< Timer 1 ITR3 selection */
#define SYSCFG_CFGR1_DAC1_TRIG1_RMP         ((uint32_t)0x00000080U) /*!< DAC1 Trigger1 remap */
#define SYSCFG_CFGR1_DMA_RMP                ((uint32_t)0x00007900U) /*!< DMA remap mask */
#define SYSCFG_CFGR1_ADC24_DMA_RMP          ((uint32_t)0x00000100U) /*!< ADC2 and ADC4 DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP          ((uint32_t)0x00000800U) /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP          ((uint32_t)0x00001000U) /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP    ((uint32_t)0x00002000U) /*!< Timer 6 / DAC1 Ch1 DMA remap */
#define SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP    ((uint32_t)0x00004000U) /*!< Timer 7 / DAC1 Ch2 DMA remap */
#define SYSCFG_CFGR1_I2C_PB6_FMP            ((uint32_t)0x00010000U) /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_PB7_FMP            ((uint32_t)0x00020000U) /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_PB8_FMP            ((uint32_t)0x00040000U) /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_PB9_FMP            ((uint32_t)0x00080000U) /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C1_FMP               ((uint32_t)0x00100000U) /*!< I2C1 Fast mode plus */
#define SYSCFG_CFGR1_I2C2_FMP               ((uint32_t)0x00200000U) /*!< I2C2 Fast mode plus */
#define SYSCFG_CFGR1_ENCODER_MODE           ((uint32_t)0x00C00000U) /*!< Encoder Mode */
#define SYSCFG_CFGR1_ENCODER_MODE_0         ((uint32_t)0x00400000U) /*!< Encoder Mode bit 0 */
#define SYSCFG_CFGR1_ENCODER_MODE_1         ((uint32_t)0x00800000U) /*!< Encoder Mode bit 1 */
#define SYSCFG_CFGR1_ENCODER_MODE_TIM2      ((uint32_t)0x00400000U) /*!< TIM2 IC1 and TIM2 IC2 are connected to TIM15 IC1 and TIM15 IC2 respectively */
#define SYSCFG_CFGR1_ENCODER_MODE_TIM3      ((uint32_t)0x00800000U) /*!< TIM3 IC1 and TIM3 IC2 are connected to TIM15 IC1 and TIM15 IC2 respectively */
#define SYSCFG_CFGR1_ENCODER_MODE_TIM4      ((uint32_t)0x00C00000U) /*!< TIM4 IC1 and TIM4 IC2 are connected to TIM15 IC1 and TIM15 IC2 respectively */
#define SYSCFG_CFGR1_FPU_IE                 ((uint32_t)0xFC000000U) /*!< Floating Point Unit Interrupt Enable */
#define SYSCFG_CFGR1_FPU_IE_0               ((uint32_t)0x04000000U) /*!< Floating Point Unit Interrupt Enable 0 */
#define SYSCFG_CFGR1_FPU_IE_1               ((uint32_t)0x08000000U) /*!< Floating Point Unit Interrupt Enable 1 */
#define SYSCFG_CFGR1_FPU_IE_2               ((uint32_t)0x10000000U) /*!< Floating Point Unit Interrupt Enable 2 */
#define SYSCFG_CFGR1_FPU_IE_3               ((uint32_t)0x20000000U) /*!< Floating Point Unit Interrupt Enable 3 */
#define SYSCFG_CFGR1_FPU_IE_4               ((uint32_t)0x40000000U) /*!< Floating Point Unit Interrupt Enable 4 */
#define SYSCFG_CFGR1_FPU_IE_5               ((uint32_t)0x80000000U) /*!< Floating Point Unit Interrupt Enable 5 */

/*****************  Bit definition for SYSCFG_RCR register  *******************/
#define SYSCFG_RCR_PAGE0          ((uint32_t)0x00000001U) /*!< ICODE SRAM Write protection page 0 */
#define SYSCFG_RCR_PAGE1          ((uint32_t)0x00000002U) /*!< ICODE SRAM Write protection page 1 */
#define SYSCFG_RCR_PAGE2          ((uint32_t)0x00000004U) /*!< ICODE SRAM Write protection page 2 */
#define SYSCFG_RCR_PAGE3          ((uint32_t)0x00000008U) /*!< ICODE SRAM Write protection page 3 */
#define SYSCFG_RCR_PAGE4          ((uint32_t)0x00000010U) /*!< ICODE SRAM Write protection page 4 */
#define SYSCFG_RCR_PAGE5          ((uint32_t)0x00000020U) /*!< ICODE SRAM Write protection page 5 */
#define SYSCFG_RCR_PAGE6          ((uint32_t)0x00000040U) /*!< ICODE SRAM Write protection page 6 */
#define SYSCFG_RCR_PAGE7          ((uint32_t)0x00000080U) /*!< ICODE SRAM Write protection page 7 */

/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0            ((uint32_t)0x0000000FU) /*!< EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1            ((uint32_t)0x000000F0U) /*!< EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2            ((uint32_t)0x00000F00U) /*!< EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3            ((uint32_t)0x0000F000U) /*!< EXTI 3 configuration */

/*!<*
  * @brief  EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA         ((uint32_t)0x00000000U) /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB         ((uint32_t)0x00000001U) /*!< PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC         ((uint32_t)0x00000002U) /*!< PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD         ((uint32_t)0x00000003U) /*!< PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE         ((uint32_t)0x00000004U) /*!< PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF         ((uint32_t)0x00000005U) /*!< PF[0] pin */

/*!<*
  * @brief  EXTI1 configuration
  */
#define SYSCFG_EXTICR1_EXTI1_PA         ((uint32_t)0x00000000U) /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         ((uint32_t)0x00000010U) /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         ((uint32_t)0x00000020U) /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         ((uint32_t)0x00000030U) /*!< PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE         ((uint32_t)0x00000040U) /*!< PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF         ((uint32_t)0x00000050U) /*!< PF[1] pin */

/*!<*
  * @brief  EXTI2 configuration
  */
#define SYSCFG_EXTICR1_EXTI2_PA         ((uint32_t)0x00000000U) /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         ((uint32_t)0x00000100U) /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         ((uint32_t)0x00000200U) /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         ((uint32_t)0x00000300U) /*!< PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE         ((uint32_t)0x00000400U) /*!< PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF         ((uint32_t)0x00000500U) /*!< PF[2] pin */

/*!<*
  * @brief  EXTI3 configuration
  */
#define SYSCFG_EXTICR1_EXTI3_PA         ((uint32_t)0x00000000U) /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         ((uint32_t)0x00001000U) /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         ((uint32_t)0x00002000U) /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         ((uint32_t)0x00003000U) /*!< PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE         ((uint32_t)0x00004000U) /*!< PE[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  ***************/
#define SYSCFG_EXTICR2_EXTI4            ((uint32_t)0x0000000FU) /*!< EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5            ((uint32_t)0x000000F0U) /*!< EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6            ((uint32_t)0x00000F00U) /*!< EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7            ((uint32_t)0x0000F000U) /*!< EXTI 7 configuration */

/*!<*
  * @brief  EXTI4 configuration
  */
#define SYSCFG_EXTICR2_EXTI4_PA         ((uint32_t)0x00000000U) /*!< PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB         ((uint32_t)0x00000001U) /*!< PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC         ((uint32_t)0x00000002U) /*!< PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD         ((uint32_t)0x00000003U) /*!< PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE         ((uint32_t)0x00000004U) /*!< PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF         ((uint32_t)0x00000005U) /*!< PF[4] pin */

/*!<*
  * @brief  EXTI5 configuration
  */
#define SYSCFG_EXTICR2_EXTI5_PA         ((uint32_t)0x00000000U) /*!< PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB         ((uint32_t)0x00000010U) /*!< PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC         ((uint32_t)0x00000020U) /*!< PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD         ((uint32_t)0x00000030U) /*!< PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE         ((uint32_t)0x00000040U) /*!< PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF         ((uint32_t)0x00000050U) /*!< PF[5] pin */

/*!<*
  * @brief  EXTI6 configuration
  */
#define SYSCFG_EXTICR2_EXTI6_PA         ((uint32_t)0x00000000U) /*!< PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB         ((uint32_t)0x00000100U) /*!< PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC         ((uint32_t)0x00000200U) /*!< PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD         ((uint32_t)0x00000300U) /*!< PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE         ((uint32_t)0x00000400U) /*!< PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF         ((uint32_t)0x00000500U) /*!< PF[6] pin */

/*!<*
  * @brief  EXTI7 configuration
  */
#define SYSCFG_EXTICR2_EXTI7_PA         ((uint32_t)0x00000000U) /*!< PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB         ((uint32_t)0x00001000U) /*!< PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC         ((uint32_t)0x00002000U) /*!< PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD         ((uint32_t)0x00003000U) /*!< PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE         ((uint32_t)0x00004000U) /*!< PE[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  ***************/
#define SYSCFG_EXTICR3_EXTI8            ((uint32_t)0x0000000FU) /*!< EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9            ((uint32_t)0x000000F0U) /*!< EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10           ((uint32_t)0x00000F00U) /*!< EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11           ((uint32_t)0x0000F000U) /*!< EXTI 11 configuration */

/*!<*
  * @brief  EXTI8 configuration
  */
#define SYSCFG_EXTICR3_EXTI8_PA         ((uint32_t)0x00000000U) /*!< PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB         ((uint32_t)0x00000001U) /*!< PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC         ((uint32_t)0x00000002U) /*!< PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD         ((uint32_t)0x00000003U) /*!< PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE         ((uint32_t)0x00000004U) /*!< PE[8] pin */

/*!<*
  * @brief  EXTI9 configuration
  */
#define SYSCFG_EXTICR3_EXTI9_PA         ((uint32_t)0x00000000U) /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         ((uint32_t)0x00000010U) /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         ((uint32_t)0x00000020U) /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         ((uint32_t)0x00000030U) /*!< PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE         ((uint32_t)0x00000040U) /*!< PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF         ((uint32_t)0x00000050U) /*!< PF[9] pin */

/*!<*
  * @brief  EXTI10 configuration
  */
#define SYSCFG_EXTICR3_EXTI10_PA        ((uint32_t)0x00000000U) /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        ((uint32_t)0x00000100U) /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        ((uint32_t)0x00000200U) /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        ((uint32_t)0x00000300U) /*!< PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE        ((uint32_t)0x00000400U) /*!< PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF        ((uint32_t)0x00000500U) /*!< PF[10] pin */

/*!<*
  * @brief  EXTI11 configuration
  */
#define SYSCFG_EXTICR3_EXTI11_PA        ((uint32_t)0x00000000U) /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        ((uint32_t)0x00001000U) /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        ((uint32_t)0x00002000U) /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        ((uint32_t)0x00003000U) /*!< PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE        ((uint32_t)0x00004000U) /*!< PE[11] pin */

/*****************  Bit definition for SYSCFG_EXTICR4 register  *****************/
#define SYSCFG_EXTICR4_EXTI12           ((uint32_t)0x0000000FU) /*!< EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13           ((uint32_t)0x000000F0U) /*!< EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14           ((uint32_t)0x00000F00U) /*!< EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15           ((uint32_t)0x0000F000U) /*!< EXTI 15 configuration */

/*!<*
  * @brief  EXTI12 configuration
  */
#define SYSCFG_EXTICR4_EXTI12_PA        ((uint32_t)0x00000000U) /*!< PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB        ((uint32_t)0x00000001U) /*!< PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC        ((uint32_t)0x00000002U) /*!< PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD        ((uint32_t)0x00000003U) /*!< PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE        ((uint32_t)0x00000004U) /*!< PE[12] pin */

/*!<*
  * @brief  EXTI13 configuration
  */
#define SYSCFG_EXTICR4_EXTI13_PA        ((uint32_t)0x00000000U) /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB        ((uint32_t)0x00000010U) /*!< PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC        ((uint32_t)0x00000020U) /*!< PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD        ((uint32_t)0x00000030U) /*!< PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE        ((uint32_t)0x00000040U) /*!< PE[13] pin */

/*!<*
  * @brief  EXTI14 configuration
  */
#define SYSCFG_EXTICR4_EXTI14_PA        ((uint32_t)0x00000000U) /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB        ((uint32_t)0x00000100U) /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC        ((uint32_t)0x00000200U) /*!< PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD        ((uint32_t)0x00000300U) /*!< PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE        ((uint32_t)0x00000400U) /*!< PE[14] pin */

/*!<*
  * @brief  EXTI15 configuration
  */
#define SYSCFG_EXTICR4_EXTI15_PA        ((uint32_t)0x00000000U) /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB        ((uint32_t)0x00001000U) /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC        ((uint32_t)0x00002000U) /*!< PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD        ((uint32_t)0x00003000U) /*!< PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE        ((uint32_t)0x00004000U) /*!< PE[15] pin */

/*****************  Bit definition for SYSCFG_CFGR2 register  ****************/
#define SYSCFG_CFGR2_LOCKUP_LOCK               ((uint32_t)0x00000001U) /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM4 with Break Input of TIMx */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK          ((uint32_t)0x00000002U) /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMx */
#define SYSCFG_CFGR2_PVD_LOCK                  ((uint32_t)0x00000004U) /*!< Enables and locks the PVD connection with TIMx Break Input, as well as the PVDE and PLS[2:0] in the PWR_CR register */
#define SYSCFG_CFGR2_BYP_ADDR_PAR              ((uint32_t)0x00000010U) /*!< Disables the adddress parity check on RAM */
#define SYSCFG_CFGR2_SRAM_PE                   ((uint32_t)0x00000100U) /*!< SRAM Parity error flag */

/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define  TIM_CR1_CEN                         ((uint32_t)0x00000001U)            /*!<Counter enable */
#define  TIM_CR1_UDIS                        ((uint32_t)0x00000002U)            /*!<Update disable */
#define  TIM_CR1_URS                         ((uint32_t)0x00000004U)            /*!<Update request source */
#define  TIM_CR1_OPM                         ((uint32_t)0x00000008U)            /*!<One pulse mode */
#define  TIM_CR1_DIR                         ((uint32_t)0x00000010U)            /*!<Direction */

#define  TIM_CR1_CMS                         ((uint32_t)0x00000060U)            /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       ((uint32_t)0x00000020U)            /*!<Bit 0 */
#define  TIM_CR1_CMS_1                       ((uint32_t)0x00000040U)            /*!<Bit 1 */

#define  TIM_CR1_ARPE                        ((uint32_t)0x00000080U)            /*!<Auto-reload preload enable */

#define  TIM_CR1_CKD                         ((uint32_t)0x00000300U)            /*!<CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       ((uint32_t)0x00000100U)            /*!<Bit 0 */
#define  TIM_CR1_CKD_1                       ((uint32_t)0x00000200U)            /*!<Bit 1 */

#define  TIM_CR1_UIFREMAP                    ((uint32_t)0x00000800U)            /*!<Update interrupt flag remap */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define  TIM_CR2_CCPC                        ((uint32_t)0x00000001U)            /*!<Capture/Compare Preloaded Control */
#define  TIM_CR2_CCUS                        ((uint32_t)0x00000004U)            /*!<Capture/Compare Control Update Selection */
#define  TIM_CR2_CCDS                        ((uint32_t)0x00000008U)            /*!<Capture/Compare DMA Selection */

#define  TIM_CR2_MMS                         ((uint32_t)0x00000070U)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS_0                       ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_CR2_MMS_1                       ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_CR2_MMS_2                       ((uint32_t)0x00000040U)            /*!<Bit 2 */

#define  TIM_CR2_TI1S                        ((uint32_t)0x00000080U)            /*!<TI1 Selection */
#define  TIM_CR2_OIS1                        ((uint32_t)0x00000100U)            /*!<Output Idle state 1 (OC1 output) */
#define  TIM_CR2_OIS1N                       ((uint32_t)0x00000200U)            /*!<Output Idle state 1 (OC1N output) */
#define  TIM_CR2_OIS2                        ((uint32_t)0x00000400U)            /*!<Output Idle state 2 (OC2 output) */
#define  TIM_CR2_OIS2N                       ((uint32_t)0x00000800U)            /*!<Output Idle state 2 (OC2N output) */
#define  TIM_CR2_OIS3                        ((uint32_t)0x00001000U)            /*!<Output Idle state 3 (OC3 output) */
#define  TIM_CR2_OIS3N                       ((uint32_t)0x00002000U)            /*!<Output Idle state 3 (OC3N output) */
#define  TIM_CR2_OIS4                        ((uint32_t)0x00004000U)            /*!<Output Idle state 4 (OC4 output) */
#define  TIM_CR2_OIS5                        ((uint32_t)0x00010000U)            /*!<Output Idle state 4 (OC4 output) */
#define  TIM_CR2_OIS6                        ((uint32_t)0x00040000U)            /*!<Output Idle state 4 (OC4 output) */

#define  TIM_CR2_MMS2                        ((uint32_t)0x00F00000U)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS2_0                      ((uint32_t)0x00100000U)            /*!<Bit 0 */
#define  TIM_CR2_MMS2_1                      ((uint32_t)0x00200000U)            /*!<Bit 1 */
#define  TIM_CR2_MMS2_2                      ((uint32_t)0x00400000U)            /*!<Bit 2 */
#define  TIM_CR2_MMS2_3                      ((uint32_t)0x00800000U)            /*!<Bit 2 */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define  TIM_SMCR_SMS                        ((uint32_t)0x00010007U)            /*!<SMS[2:0] bits (Slave mode selection) */
#define  TIM_SMCR_SMS_0                      ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define  TIM_SMCR_SMS_1                      ((uint32_t)0x00000002U)            /*!<Bit 1 */
#define  TIM_SMCR_SMS_2                      ((uint32_t)0x00000004U)            /*!<Bit 2 */
#define  TIM_SMCR_SMS_3                      ((uint32_t)0x00010000U)            /*!<Bit 3 */

#define  TIM_SMCR_OCCS                       ((uint32_t)0x00000008U)            /*!< OCREF clear selection */

#define  TIM_SMCR_TS                         ((uint32_t)0x00000070U)            /*!<TS[2:0] bits (Trigger selection) */
#define  TIM_SMCR_TS_0                       ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_SMCR_TS_1                       ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_SMCR_TS_2                       ((uint32_t)0x00000040U)            /*!<Bit 2 */

#define  TIM_SMCR_MSM                        ((uint32_t)0x00000080U)            /*!<Master/slave mode */

#define  TIM_SMCR_ETF                        ((uint32_t)0x00000F00U)            /*!<ETF[3:0] bits (External trigger filter) */
#define  TIM_SMCR_ETF_0                      ((uint32_t)0x00000100U)            /*!<Bit 0 */
#define  TIM_SMCR_ETF_1                      ((uint32_t)0x00000200U)            /*!<Bit 1 */
#define  TIM_SMCR_ETF_2                      ((uint32_t)0x00000400U)            /*!<Bit 2 */
#define  TIM_SMCR_ETF_3                      ((uint32_t)0x00000800U)            /*!<Bit 3 */

#define  TIM_SMCR_ETPS                       ((uint32_t)0x00003000U)            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define  TIM_SMCR_ETPS_0                     ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TIM_SMCR_ETPS_1                     ((uint32_t)0x00002000U)            /*!<Bit 1 */

#define  TIM_SMCR_ECE                        ((uint32_t)0x00004000U)            /*!<External clock enable */
#define  TIM_SMCR_ETP                        ((uint32_t)0x00008000U)            /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define  TIM_DIER_UIE                        ((uint32_t)0x00000001U)            /*!<Update interrupt enable */
#define  TIM_DIER_CC1IE                      ((uint32_t)0x00000002U)            /*!<Capture/Compare 1 interrupt enable */
#define  TIM_DIER_CC2IE                      ((uint32_t)0x00000004U)            /*!<Capture/Compare 2 interrupt enable */
#define  TIM_DIER_CC3IE                      ((uint32_t)0x00000008U)            /*!<Capture/Compare 3 interrupt enable */
#define  TIM_DIER_CC4IE                      ((uint32_t)0x00000010U)            /*!<Capture/Compare 4 interrupt enable */
#define  TIM_DIER_COMIE                      ((uint32_t)0x00000020U)            /*!<COM interrupt enable */
#define  TIM_DIER_TIE                        ((uint32_t)0x00000040U)            /*!<Trigger interrupt enable */
#define  TIM_DIER_BIE                        ((uint32_t)0x00000080U)            /*!<Break interrupt enable */
#define  TIM_DIER_UDE                        ((uint32_t)0x00000100U)            /*!<Update DMA request enable */
#define  TIM_DIER_CC1DE                      ((uint32_t)0x00000200U)            /*!<Capture/Compare 1 DMA request enable */
#define  TIM_DIER_CC2DE                      ((uint32_t)0x00000400U)            /*!<Capture/Compare 2 DMA request enable */
#define  TIM_DIER_CC3DE                      ((uint32_t)0x00000800U)            /*!<Capture/Compare 3 DMA request enable */
#define  TIM_DIER_CC4DE                      ((uint32_t)0x00001000U)            /*!<Capture/Compare 4 DMA request enable */
#define  TIM_DIER_COMDE                      ((uint32_t)0x00002000U)            /*!<COM DMA request enable */
#define  TIM_DIER_TDE                        ((uint32_t)0x00004000U)            /*!<Trigger DMA request enable */

/********************  Bit definition for TIM_SR register  ********************/
#define  TIM_SR_UIF                          ((uint32_t)0x00000001U)            /*!<Update interrupt Flag */
#define  TIM_SR_CC1IF                        ((uint32_t)0x00000002U)            /*!<Capture/Compare 1 interrupt Flag */
#define  TIM_SR_CC2IF                        ((uint32_t)0x00000004U)            /*!<Capture/Compare 2 interrupt Flag */
#define  TIM_SR_CC3IF                        ((uint32_t)0x00000008U)            /*!<Capture/Compare 3 interrupt Flag */
#define  TIM_SR_CC4IF                        ((uint32_t)0x00000010U)            /*!<Capture/Compare 4 interrupt Flag */
#define  TIM_SR_COMIF                        ((uint32_t)0x00000020U)            /*!<COM interrupt Flag */
#define  TIM_SR_TIF                          ((uint32_t)0x00000040U)            /*!<Trigger interrupt Flag */
#define  TIM_SR_BIF                          ((uint32_t)0x00000080U)            /*!<Break interrupt Flag */
#define  TIM_SR_B2IF                         ((uint32_t)0x00000100U)            /*!<Break2 interrupt Flag */
#define  TIM_SR_CC1OF                        ((uint32_t)0x00000200U)            /*!<Capture/Compare 1 Overcapture Flag */
#define  TIM_SR_CC2OF                        ((uint32_t)0x00000400U)            /*!<Capture/Compare 2 Overcapture Flag */
#define  TIM_SR_CC3OF                        ((uint32_t)0x00000800U)            /*!<Capture/Compare 3 Overcapture Flag */
#define  TIM_SR_CC4OF                        ((uint32_t)0x00001000U)            /*!<Capture/Compare 4 Overcapture Flag */
#define  TIM_SR_CC5IF                        ((uint32_t)0x00010000U)            /*!<Capture/Compare 5 interrupt Flag */
#define  TIM_SR_CC6IF                        ((uint32_t)0x00020000U)            /*!<Capture/Compare 6 interrupt Flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define  TIM_EGR_UG                          ((uint32_t)0x00000001U)               /*!<Update Generation */
#define  TIM_EGR_CC1G                        ((uint32_t)0x00000002U)               /*!<Capture/Compare 1 Generation */
#define  TIM_EGR_CC2G                        ((uint32_t)0x00000004U)               /*!<Capture/Compare 2 Generation */
#define  TIM_EGR_CC3G                        ((uint32_t)0x00000008U)               /*!<Capture/Compare 3 Generation */
#define  TIM_EGR_CC4G                        ((uint32_t)0x00000010U)               /*!<Capture/Compare 4 Generation */
#define  TIM_EGR_COMG                        ((uint32_t)0x00000020U)               /*!<Capture/Compare Control Update Generation */
#define  TIM_EGR_TG                          ((uint32_t)0x00000040U)               /*!<Trigger Generation */
#define  TIM_EGR_BG                          ((uint32_t)0x00000080U)               /*!<Break Generation */
#define  TIM_EGR_B2G                         ((uint32_t)0x00000100U)               /*!<Break Generation */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define  TIM_CCMR1_CC1S                      ((uint32_t)0x00000003U)            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define  TIM_CCMR1_CC1S_1                    ((uint32_t)0x00000002U)            /*!<Bit 1 */

#define  TIM_CCMR1_OC1FE                     ((uint32_t)0x00000004U)            /*!<Output Compare 1 Fast enable */
#define  TIM_CCMR1_OC1PE                     ((uint32_t)0x00000008U)            /*!<Output Compare 1 Preload enable */

#define  TIM_CCMR1_OC1M                      ((uint32_t)0x00010070U)            /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define  TIM_CCMR1_OC1M_0                    ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_CCMR1_OC1M_1                    ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_CCMR1_OC1M_2                    ((uint32_t)0x00000040U)            /*!<Bit 2 */
#define  TIM_CCMR1_OC1M_3                    ((uint32_t)0x00010000U)            /*!<Bit 3 */

#define  TIM_CCMR1_OC1CE                     ((uint32_t)0x00000080U)            /*!<Output Compare 1Clear Enable */

#define  TIM_CCMR1_CC2S                      ((uint32_t)0x00000300U)            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    ((uint32_t)0x00000100U)            /*!<Bit 0 */
#define  TIM_CCMR1_CC2S_1                    ((uint32_t)0x00000200U)            /*!<Bit 1 */

#define  TIM_CCMR1_OC2FE                     ((uint32_t)0x00000400U)            /*!<Output Compare 2 Fast enable */
#define  TIM_CCMR1_OC2PE                     ((uint32_t)0x00000800U)            /*!<Output Compare 2 Preload enable */

#define  TIM_CCMR1_OC2M                      ((uint32_t)0x01007000U)            /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define  TIM_CCMR1_OC2M_0                    ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TIM_CCMR1_OC2M_1                    ((uint32_t)0x00002000U)            /*!<Bit 1 */
#define  TIM_CCMR1_OC2M_2                    ((uint32_t)0x00004000U)            /*!<Bit 2 */
#define  TIM_CCMR1_OC2M_3                    ((uint32_t)0x01000000U)            /*!<Bit 3 */

#define  TIM_CCMR1_OC2CE                     ((uint32_t)0x00008000U)            /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR1_IC1PSC                    ((uint32_t)0x0000000CU)            /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define  TIM_CCMR1_IC1PSC_0                  ((uint32_t)0x00000004U)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1PSC_1                  ((uint32_t)0x00000008U)            /*!<Bit 1 */

#define  TIM_CCMR1_IC1F                      ((uint32_t)0x000000F0U)            /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define  TIM_CCMR1_IC1F_0                    ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1F_1                    ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_CCMR1_IC1F_2                    ((uint32_t)0x00000040U)            /*!<Bit 2 */
#define  TIM_CCMR1_IC1F_3                    ((uint32_t)0x00000080U)            /*!<Bit 3 */

#define  TIM_CCMR1_IC2PSC                    ((uint32_t)0x00000C00U)            /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define  TIM_CCMR1_IC2PSC_0                  ((uint32_t)0x00000400U)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2PSC_1                  ((uint32_t)0x00000800U)            /*!<Bit 1 */

#define  TIM_CCMR1_IC2F                      ((uint32_t)0x0000F000U)            /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define  TIM_CCMR1_IC2F_0                    ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2F_1                    ((uint32_t)0x00002000U)            /*!<Bit 1 */
#define  TIM_CCMR1_IC2F_2                    ((uint32_t)0x00004000U)            /*!<Bit 2 */
#define  TIM_CCMR1_IC2F_3                    ((uint32_t)0x00008000U)            /*!<Bit 3 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define  TIM_CCMR2_CC3S                      ((uint32_t)0x00000003U)            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define  TIM_CCMR2_CC3S_0                    ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define  TIM_CCMR2_CC3S_1                    ((uint32_t)0x00000002U)            /*!<Bit 1 */

#define  TIM_CCMR2_OC3FE                     ((uint32_t)0x00000004U)            /*!<Output Compare 3 Fast enable */
#define  TIM_CCMR2_OC3PE                     ((uint32_t)0x00000008U)            /*!<Output Compare 3 Preload enable */

#define  TIM_CCMR2_OC3M                      ((uint32_t)0x00010070U)            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M_0                    ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_CCMR2_OC3M_1                    ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_CCMR2_OC3M_2                    ((uint32_t)0x00000040U)            /*!<Bit 2 */
#define  TIM_CCMR2_OC3M_3                    ((uint32_t)0x00010000U)            /*!<Bit 3 */

#define  TIM_CCMR2_OC3CE                     ((uint32_t)0x00000080U)            /*!<Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      ((uint32_t)0x00000300U)            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    ((uint32_t)0x00000100U)            /*!<Bit 0 */
#define  TIM_CCMR2_CC4S_1                    ((uint32_t)0x00000200U)            /*!<Bit 1 */

#define  TIM_CCMR2_OC4FE                     ((uint32_t)0x00000400U)            /*!<Output Compare 4 Fast enable */
#define  TIM_CCMR2_OC4PE                     ((uint32_t)0x00000800U)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      ((uint32_t)0x01007000U)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M_0                    ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TIM_CCMR2_OC4M_1                    ((uint32_t)0x00002000U)            /*!<Bit 1 */
#define  TIM_CCMR2_OC4M_2                    ((uint32_t)0x00004000U)            /*!<Bit 2 */
#define  TIM_CCMR2_OC4M_3                    ((uint32_t)0x01000000U)            /*!<Bit 3 */

#define  TIM_CCMR2_OC4CE                     ((uint32_t)0x00008000U)            /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR2_IC3PSC                    ((uint32_t)0x0000000CU)            /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define  TIM_CCMR2_IC3PSC_0                  ((uint32_t)0x00000004U)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3PSC_1                  ((uint32_t)0x00000008U)            /*!<Bit 1 */

#define  TIM_CCMR2_IC3F                      ((uint32_t)0x000000F0U)            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define  TIM_CCMR2_IC3F_0                    ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3F_1                    ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_CCMR2_IC3F_2                    ((uint32_t)0x00000040U)            /*!<Bit 2 */
#define  TIM_CCMR2_IC3F_3                    ((uint32_t)0x00000080U)            /*!<Bit 3 */

#define  TIM_CCMR2_IC4PSC                    ((uint32_t)0x00000C00U)            /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define  TIM_CCMR2_IC4PSC_0                  ((uint32_t)0x00000400U)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4PSC_1                  ((uint32_t)0x00000800U)            /*!<Bit 1 */

#define  TIM_CCMR2_IC4F                      ((uint32_t)0x0000F000U)            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define  TIM_CCMR2_IC4F_0                    ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4F_1                    ((uint32_t)0x00002000U)            /*!<Bit 1 */
#define  TIM_CCMR2_IC4F_2                    ((uint32_t)0x00004000U)            /*!<Bit 2 */
#define  TIM_CCMR2_IC4F_3                    ((uint32_t)0x00008000U)            /*!<Bit 3 */

/*******************  Bit definition for TIM_CCER register  *******************/
#define  TIM_CCER_CC1E                       ((uint32_t)0x00000001U)            /*!<Capture/Compare 1 output enable */
#define  TIM_CCER_CC1P                       ((uint32_t)0x00000002U)            /*!<Capture/Compare 1 output Polarity */
#define  TIM_CCER_CC1NE                      ((uint32_t)0x00000004U)            /*!<Capture/Compare 1 Complementary output enable */
#define  TIM_CCER_CC1NP                      ((uint32_t)0x00000008U)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       ((uint32_t)0x00000010U)            /*!<Capture/Compare 2 output enable */
#define  TIM_CCER_CC2P                       ((uint32_t)0x00000020U)            /*!<Capture/Compare 2 output Polarity */
#define  TIM_CCER_CC2NE                      ((uint32_t)0x00000040U)            /*!<Capture/Compare 2 Complementary output enable */
#define  TIM_CCER_CC2NP                      ((uint32_t)0x00000080U)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       ((uint32_t)0x00000100U)            /*!<Capture/Compare 3 output enable */
#define  TIM_CCER_CC3P                       ((uint32_t)0x00000200U)            /*!<Capture/Compare 3 output Polarity */
#define  TIM_CCER_CC3NE                      ((uint32_t)0x00000400U)            /*!<Capture/Compare 3 Complementary output enable */
#define  TIM_CCER_CC3NP                      ((uint32_t)0x00000800U)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       ((uint32_t)0x00001000U)            /*!<Capture/Compare 4 output enable */
#define  TIM_CCER_CC4P                       ((uint32_t)0x00002000U)            /*!<Capture/Compare 4 output Polarity */
#define  TIM_CCER_CC4NP                      ((uint32_t)0x00008000U)            /*!<Capture/Compare 4 Complementary output Polarity */
#define  TIM_CCER_CC5E                       ((uint32_t)0x00010000U)            /*!<Capture/Compare 5 output enable */
#define  TIM_CCER_CC5P                       ((uint32_t)0x00020000U)            /*!<Capture/Compare 5 output Polarity */
#define  TIM_CCER_CC6E                       ((uint32_t)0x00100000U)            /*!<Capture/Compare 6 output enable */
#define  TIM_CCER_CC6P                       ((uint32_t)0x00200000U)            /*!<Capture/Compare 6 output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define  TIM_CNT_CNT                         ((uint32_t)0xFFFFFFFFU)            /*!<Counter Value */
#define  TIM_CNT_UIFCPY                      ((uint32_t)0x80000000U)            /*!<Update interrupt flag copy */

/*******************  Bit definition for TIM_PSC register  ********************/
#define  TIM_PSC_PSC                         ((uint32_t)0x0000FFFFU)            /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  ********************/
#define  TIM_ARR_ARR                         ((uint32_t)0xFFFFFFFFU)            /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define  TIM_RCR_REP                         ((uint32_t)0x0000FFFFU)            /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define  TIM_CCR1_CCR1                       ((uint32_t)0x0000FFFFU)            /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define  TIM_CCR2_CCR2                       ((uint32_t)0x0000FFFFU)            /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define  TIM_CCR3_CCR3                       ((uint32_t)0x0000FFFFU)            /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define  TIM_CCR4_CCR4                       ((uint32_t)0x0000FFFFU)            /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIM_CCR5 register  *******************/
#define  TIM_CCR5_CCR5                       ((uint32_t)0xFFFFFFFFU)        /*!<Capture/Compare 5 Value */
#define  TIM_CCR5_GC5C1                      ((uint32_t)0x20000000U)        /*!<Group Channel 5 and Channel 1 */
#define  TIM_CCR5_GC5C2                      ((uint32_t)0x40000000U)        /*!<Group Channel 5 and Channel 2 */
#define  TIM_CCR5_GC5C3                      ((uint32_t)0x80000000U)        /*!<Group Channel 5 and Channel 3 */

/*******************  Bit definition for TIM_CCR6 register  *******************/
#define  TIM_CCR6_CCR6                       ((uint32_t)0x0000FFFFU)            /*!<Capture/Compare 6 Value */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define  TIM_BDTR_DTG                        ((uint32_t)0x000000FFU)            /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define  TIM_BDTR_DTG_0                      ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define  TIM_BDTR_DTG_1                      ((uint32_t)0x00000002U)            /*!<Bit 1 */
#define  TIM_BDTR_DTG_2                      ((uint32_t)0x00000004U)            /*!<Bit 2 */
#define  TIM_BDTR_DTG_3                      ((uint32_t)0x00000008U)            /*!<Bit 3 */
#define  TIM_BDTR_DTG_4                      ((uint32_t)0x00000010U)            /*!<Bit 4 */
#define  TIM_BDTR_DTG_5                      ((uint32_t)0x00000020U)            /*!<Bit 5 */
#define  TIM_BDTR_DTG_6                      ((uint32_t)0x00000040U)            /*!<Bit 6 */
#define  TIM_BDTR_DTG_7                      ((uint32_t)0x00000080U)            /*!<Bit 7 */

#define  TIM_BDTR_LOCK                       ((uint32_t)0x00000300U)            /*!<LOCK[1:0] bits (Lock Configuration) */
#define  TIM_BDTR_LOCK_0                     ((uint32_t)0x00000100U)            /*!<Bit 0 */
#define  TIM_BDTR_LOCK_1                     ((uint32_t)0x00000200U)            /*!<Bit 1 */

#define  TIM_BDTR_OSSI                       ((uint32_t)0x00000400U)            /*!<Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       ((uint32_t)0x00000800U)            /*!<Off-State Selection for Run mode */
#define  TIM_BDTR_BKE                        ((uint32_t)0x00001000U)            /*!<Break enable for Break1 */
#define  TIM_BDTR_BKP                        ((uint32_t)0x00002000U)            /*!<Break Polarity for Break1 */
#define  TIM_BDTR_AOE                        ((uint32_t)0x00004000U)            /*!<Automatic Output enable */
#define  TIM_BDTR_MOE                        ((uint32_t)0x00008000U)            /*!<Main Output enable */

#define  TIM_BDTR_BKF                        ((uint32_t)0x000F0000U)            /*!<Break Filter for Break1 */
#define  TIM_BDTR_BK2F                       ((uint32_t)0x00F00000U)            /*!<Break Filter for Break2 */

#define  TIM_BDTR_BK2E                       ((uint32_t)0x01000000U)            /*!<Break enable for Break2 */
#define  TIM_BDTR_BK2P                       ((uint32_t)0x02000000U)            /*!<Break Polarity for Break2 */

/*******************  Bit definition for TIM_DCR register  ********************/
#define  TIM_DCR_DBA                         ((uint32_t)0x0000001FU)            /*!<DBA[4:0] bits (DMA Base Address) */
#define  TIM_DCR_DBA_0                       ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define  TIM_DCR_DBA_1                       ((uint32_t)0x00000002U)            /*!<Bit 1 */
#define  TIM_DCR_DBA_2                       ((uint32_t)0x00000004U)            /*!<Bit 2 */
#define  TIM_DCR_DBA_3                       ((uint32_t)0x00000008U)            /*!<Bit 3 */
#define  TIM_DCR_DBA_4                       ((uint32_t)0x00000010U)            /*!<Bit 4 */

#define  TIM_DCR_DBL                         ((uint32_t)0x00001F00U)            /*!<DBL[4:0] bits (DMA Burst Length) */
#define  TIM_DCR_DBL_0                       ((uint32_t)0x00000100U)            /*!<Bit 0 */
#define  TIM_DCR_DBL_1                       ((uint32_t)0x00000200U)            /*!<Bit 1 */
#define  TIM_DCR_DBL_2                       ((uint32_t)0x00000400U)            /*!<Bit 2 */
#define  TIM_DCR_DBL_3                       ((uint32_t)0x00000800U)            /*!<Bit 3 */
#define  TIM_DCR_DBL_4                       ((uint32_t)0x00001000U)            /*!<Bit 4 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define  TIM_DMAR_DMAB                       ((uint32_t)0x0000FFFFU)            /*!<DMA register for burst accesses */

/*******************  Bit definition for TIM16_OR register  *********************/
#define TIM16_OR_TI1_RMP                     ((uint32_t)0x00000003U)            /*!<TI1_RMP[1:0] bits (TIM16 Input 1 remap) */
#define TIM16_OR_TI1_RMP_0                   ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define TIM16_OR_TI1_RMP_1                   ((uint32_t)0x00000002U)            /*!<Bit 1 */

/*******************  Bit definition for TIM1_OR register  *********************/
#define TIM1_OR_ETR_RMP                      ((uint32_t)0x0000000FU)            /*!<ETR_RMP[3:0] bits (TIM1 ETR remap) */
#define TIM1_OR_ETR_RMP_0                    ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define TIM1_OR_ETR_RMP_1                    ((uint32_t)0x00000002U)            /*!<Bit 1 */
#define TIM1_OR_ETR_RMP_2                    ((uint32_t)0x00000004U)            /*!<Bit 2 */
#define TIM1_OR_ETR_RMP_3                    ((uint32_t)0x00000008U)            /*!<Bit 3 */

/*******************  Bit definition for TIM8_OR register  *********************/
#define TIM8_OR_ETR_RMP                      ((uint32_t)0x0000000FU)            /*!<ETR_RMP[3:0] bits (TIM8 ETR remap) */
#define TIM8_OR_ETR_RMP_0                    ((uint32_t)0x00000001U)            /*!<Bit 0 */
#define TIM8_OR_ETR_RMP_1                    ((uint32_t)0x00000002U)            /*!<Bit 1 */
#define TIM8_OR_ETR_RMP_2                    ((uint32_t)0x00000004U)            /*!<Bit 2 */
#define TIM8_OR_ETR_RMP_3                    ((uint32_t)0x00000008U)            /*!<Bit 3 */

/******************  Bit definition for TIM_CCMR3 register  *******************/
#define  TIM_CCMR3_OC5FE                     ((uint32_t)0x00000004U)            /*!<Output Compare 5 Fast enable */
#define  TIM_CCMR3_OC5PE                     ((uint32_t)0x00000008U)            /*!<Output Compare 5 Preload enable */

#define  TIM_CCMR3_OC5M                      ((uint32_t)0x00010070U)            /*!<OC5M[2:0] bits (Output Compare 5 Mode) */
#define  TIM_CCMR3_OC5M_0                    ((uint32_t)0x00000010U)            /*!<Bit 0 */
#define  TIM_CCMR3_OC5M_1                    ((uint32_t)0x00000020U)            /*!<Bit 1 */
#define  TIM_CCMR3_OC5M_2                    ((uint32_t)0x00000040U)            /*!<Bit 2 */
#define  TIM_CCMR3_OC5M_3                    ((uint32_t)0x00010000U)            /*!<Bit 3 */

#define  TIM_CCMR3_OC5CE                     ((uint32_t)0x00000080U)            /*!<Output Compare 5 Clear Enable */

#define  TIM_CCMR3_OC6FE                     ((uint32_t)0x00000400U)            /*!<Output Compare 6 Fast enable */
#define  TIM_CCMR3_OC6PE                     ((uint32_t)0x00000800U)            /*!<Output Compare 6 Preload enable */

#define  TIM_CCMR3_OC6M                      ((uint32_t)0x01007000U)            /*!<OC6M[2:0] bits (Output Compare 6 Mode) */
#define  TIM_CCMR3_OC6M_0                    ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TIM_CCMR3_OC6M_1                    ((uint32_t)0x00002000U)            /*!<Bit 1 */
#define  TIM_CCMR3_OC6M_2                    ((uint32_t)0x00004000U)            /*!<Bit 2 */
#define  TIM_CCMR3_OC6M_3                    ((uint32_t)0x01000000U)            /*!<Bit 3 */

#define  TIM_CCMR3_OC6CE                     ((uint32_t)0x00008000U)            /*!<Output Compare 6 Clear Enable */

/******************************************************************************/
/*                                                                            */
/*                          Touch Sensing Controller (TSC)                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TSC_CR register  *********************/
#define  TSC_CR_TSCE                         ((uint32_t)0x00000001U)            /*!<Touch sensing controller enable */
#define  TSC_CR_START                        ((uint32_t)0x00000002U)            /*!<Start acquisition */
#define  TSC_CR_AM                           ((uint32_t)0x00000004U)            /*!<Acquisition mode */
#define  TSC_CR_SYNCPOL                      ((uint32_t)0x00000008U)            /*!<Synchronization pin polarity */
#define  TSC_CR_IODEF                        ((uint32_t)0x00000010U)            /*!<IO default mode */

#define  TSC_CR_MCV                          ((uint32_t)0x000000E0U)            /*!<MCV[2:0] bits (Max Count Value) */
#define  TSC_CR_MCV_0                        ((uint32_t)0x00000020U)            /*!<Bit 0 */
#define  TSC_CR_MCV_1                        ((uint32_t)0x00000040U)            /*!<Bit 1 */
#define  TSC_CR_MCV_2                        ((uint32_t)0x00000080U)            /*!<Bit 2 */

#define  TSC_CR_PGPSC                        ((uint32_t)0x00007000U)            /*!<PGPSC[2:0] bits (Pulse Generator Prescaler) */
#define  TSC_CR_PGPSC_0                      ((uint32_t)0x00001000U)            /*!<Bit 0 */
#define  TSC_CR_PGPSC_1                      ((uint32_t)0x00002000U)            /*!<Bit 1 */
#define  TSC_CR_PGPSC_2                      ((uint32_t)0x00004000U)            /*!<Bit 2 */

#define  TSC_CR_SSPSC                        ((uint32_t)0x00008000U)            /*!<Spread Spectrum Prescaler */
#define  TSC_CR_SSE                          ((uint32_t)0x00010000U)            /*!<Spread Spectrum Enable */

#define  TSC_CR_SSD                          ((uint32_t)0x00FE0000U)            /*!<SSD[6:0] bits (Spread Spectrum Deviation) */
#define  TSC_CR_SSD_0                        ((uint32_t)0x00020000U)            /*!<Bit 0 */
#define  TSC_CR_SSD_1                        ((uint32_t)0x00040000U)            /*!<Bit 1 */
#define  TSC_CR_SSD_2                        ((uint32_t)0x00080000U)            /*!<Bit 2 */
#define  TSC_CR_SSD_3                        ((uint32_t)0x00100000U)            /*!<Bit 3 */
#define  TSC_CR_SSD_4                        ((uint32_t)0x00200000U)            /*!<Bit 4 */
#define  TSC_CR_SSD_5                        ((uint32_t)0x00400000U)            /*!<Bit 5 */
#define  TSC_CR_SSD_6                        ((uint32_t)0x00800000U)            /*!<Bit 6 */

#define  TSC_CR_CTPL                         ((uint32_t)0x0F000000U)            /*!<CTPL[3:0] bits (Charge Transfer pulse low) */
#define  TSC_CR_CTPL_0                       ((uint32_t)0x01000000U)            /*!<Bit 0 */
#define  TSC_CR_CTPL_1                       ((uint32_t)0x02000000U)            /*!<Bit 1 */
#define  TSC_CR_CTPL_2                       ((uint32_t)0x04000000U)            /*!<Bit 2 */
#define  TSC_CR_CTPL_3                       ((uint32_t)0x08000000U)            /*!<Bit 3 */

#define  TSC_CR_CTPH                         ((uint32_t)0xF0000000U)            /*!<CTPH[3:0] bits (Charge Transfer pulse high) */
#define  TSC_CR_CTPH_0                       ((uint32_t)0x10000000U)            /*!<Bit 0 */
#define  TSC_CR_CTPH_1                       ((uint32_t)0x20000000U)            /*!<Bit 1 */
#define  TSC_CR_CTPH_2                       ((uint32_t)0x40000000U)            /*!<Bit 2 */
#define  TSC_CR_CTPH_3                       ((uint32_t)0x80000000U)            /*!<Bit 3 */

/*******************  Bit definition for TSC_IER register  ********************/
#define  TSC_IER_EOAIE                       ((uint32_t)0x00000001U)            /*!<End of acquisition interrupt enable */
#define  TSC_IER_MCEIE                       ((uint32_t)0x00000002U)            /*!<Max count error interrupt enable */

/*******************  Bit definition for TSC_ICR register  ********************/
#define  TSC_ICR_EOAIC                       ((uint32_t)0x00000001U)            /*!<End of acquisition interrupt clear */
#define  TSC_ICR_MCEIC                       ((uint32_t)0x00000002U)            /*!<Max count error interrupt clear */

/*******************  Bit definition for TSC_ISR register  ********************/
#define  TSC_ISR_EOAF                        ((uint32_t)0x00000001U)            /*!<End of acquisition flag */
#define  TSC_ISR_MCEF                        ((uint32_t)0x00000002U)            /*!<Max count error flag */

/*******************  Bit definition for TSC_IOHCR register  ******************/
#define  TSC_IOHCR_G1_IO1                    ((uint32_t)0x00000001U)            /*!<GROUP1_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G1_IO2                    ((uint32_t)0x00000002U)            /*!<GROUP1_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G1_IO3                    ((uint32_t)0x00000004U)            /*!<GROUP1_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G1_IO4                    ((uint32_t)0x00000008U)            /*!<GROUP1_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G2_IO1                    ((uint32_t)0x00000010U)            /*!<GROUP2_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G2_IO2                    ((uint32_t)0x00000020U)            /*!<GROUP2_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G2_IO3                    ((uint32_t)0x00000040U)            /*!<GROUP2_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G2_IO4                    ((uint32_t)0x00000080U)            /*!<GROUP2_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G3_IO1                    ((uint32_t)0x00000100U)            /*!<GROUP3_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G3_IO2                    ((uint32_t)0x00000200U)            /*!<GROUP3_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G3_IO3                    ((uint32_t)0x00000400U)            /*!<GROUP3_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G3_IO4                    ((uint32_t)0x00000800U)            /*!<GROUP3_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G4_IO1                    ((uint32_t)0x00001000U)            /*!<GROUP4_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G4_IO2                    ((uint32_t)0x00002000U)            /*!<GROUP4_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G4_IO3                    ((uint32_t)0x00004000U)            /*!<GROUP4_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G4_IO4                    ((uint32_t)0x00008000U)            /*!<GROUP4_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G5_IO1                    ((uint32_t)0x00010000U)            /*!<GROUP5_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G5_IO2                    ((uint32_t)0x00020000U)            /*!<GROUP5_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G5_IO3                    ((uint32_t)0x00040000U)            /*!<GROUP5_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G5_IO4                    ((uint32_t)0x00080000U)            /*!<GROUP5_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G6_IO1                    ((uint32_t)0x00100000U)            /*!<GROUP6_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G6_IO2                    ((uint32_t)0x00200000U)            /*!<GROUP6_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G6_IO3                    ((uint32_t)0x00400000U)            /*!<GROUP6_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G6_IO4                    ((uint32_t)0x00800000U)            /*!<GROUP6_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G7_IO1                    ((uint32_t)0x01000000U)            /*!<GROUP7_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G7_IO2                    ((uint32_t)0x02000000U)            /*!<GROUP7_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G7_IO3                    ((uint32_t)0x04000000U)            /*!<GROUP7_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G7_IO4                    ((uint32_t)0x08000000U)            /*!<GROUP7_IO4 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G8_IO1                    ((uint32_t)0x10000000U)            /*!<GROUP8_IO1 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G8_IO2                    ((uint32_t)0x20000000U)            /*!<GROUP8_IO2 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G8_IO3                    ((uint32_t)0x40000000U)            /*!<GROUP8_IO3 schmitt trigger hysteresis mode */
#define  TSC_IOHCR_G8_IO4                    ((uint32_t)0x80000000U)            /*!<GROUP8_IO4 schmitt trigger hysteresis mode */

/*******************  Bit definition for TSC_IOASCR register  *****************/
#define  TSC_IOASCR_G1_IO1                   ((uint32_t)0x00000001U)            /*!<GROUP1_IO1 analog switch enable */
#define  TSC_IOASCR_G1_IO2                   ((uint32_t)0x00000002U)            /*!<GROUP1_IO2 analog switch enable */
#define  TSC_IOASCR_G1_IO3                   ((uint32_t)0x00000004U)            /*!<GROUP1_IO3 analog switch enable */
#define  TSC_IOASCR_G1_IO4                   ((uint32_t)0x00000008U)            /*!<GROUP1_IO4 analog switch enable */
#define  TSC_IOASCR_G2_IO1                   ((uint32_t)0x00000010U)            /*!<GROUP2_IO1 analog switch enable */
#define  TSC_IOASCR_G2_IO2                   ((uint32_t)0x00000020U)            /*!<GROUP2_IO2 analog switch enable */
#define  TSC_IOASCR_G2_IO3                   ((uint32_t)0x00000040U)            /*!<GROUP2_IO3 analog switch enable */
#define  TSC_IOASCR_G2_IO4                   ((uint32_t)0x00000080U)            /*!<GROUP2_IO4 analog switch enable */
#define  TSC_IOASCR_G3_IO1                   ((uint32_t)0x00000100U)            /*!<GROUP3_IO1 analog switch enable */
#define  TSC_IOASCR_G3_IO2                   ((uint32_t)0x00000200U)            /*!<GROUP3_IO2 analog switch enable */
#define  TSC_IOASCR_G3_IO3                   ((uint32_t)0x00000400U)            /*!<GROUP3_IO3 analog switch enable */
#define  TSC_IOASCR_G3_IO4                   ((uint32_t)0x00000800U)            /*!<GROUP3_IO4 analog switch enable */
#define  TSC_IOASCR_G4_IO1                   ((uint32_t)0x00001000U)            /*!<GROUP4_IO1 analog switch enable */
#define  TSC_IOASCR_G4_IO2                   ((uint32_t)0x00002000U)            /*!<GROUP4_IO2 analog switch enable */
#define  TSC_IOASCR_G4_IO3                   ((uint32_t)0x00004000U)            /*!<GROUP4_IO3 analog switch enable */
#define  TSC_IOASCR_G4_IO4                   ((uint32_t)0x00008000U)            /*!<GROUP4_IO4 analog switch enable */
#define  TSC_IOASCR_G5_IO1                   ((uint32_t)0x00010000U)            /*!<GROUP5_IO1 analog switch enable */
#define  TSC_IOASCR_G5_IO2                   ((uint32_t)0x00020000U)            /*!<GROUP5_IO2 analog switch enable */
#define  TSC_IOASCR_G5_IO3                   ((uint32_t)0x00040000U)            /*!<GROUP5_IO3 analog switch enable */
#define  TSC_IOASCR_G5_IO4                   ((uint32_t)0x00080000U)            /*!<GROUP5_IO4 analog switch enable */
#define  TSC_IOASCR_G6_IO1                   ((uint32_t)0x00100000U)            /*!<GROUP6_IO1 analog switch enable */
#define  TSC_IOASCR_G6_IO2                   ((uint32_t)0x00200000U)            /*!<GROUP6_IO2 analog switch enable */
#define  TSC_IOASCR_G6_IO3                   ((uint32_t)0x00400000U)            /*!<GROUP6_IO3 analog switch enable */
#define  TSC_IOASCR_G6_IO4                   ((uint32_t)0x00800000U)            /*!<GROUP6_IO4 analog switch enable */
#define  TSC_IOASCR_G7_IO1                   ((uint32_t)0x01000000U)            /*!<GROUP7_IO1 analog switch enable */
#define  TSC_IOASCR_G7_IO2                   ((uint32_t)0x02000000U)            /*!<GROUP7_IO2 analog switch enable */
#define  TSC_IOASCR_G7_IO3                   ((uint32_t)0x04000000U)            /*!<GROUP7_IO3 analog switch enable */
#define  TSC_IOASCR_G7_IO4                   ((uint32_t)0x08000000U)            /*!<GROUP7_IO4 analog switch enable */
#define  TSC_IOASCR_G8_IO1                   ((uint32_t)0x10000000U)            /*!<GROUP8_IO1 analog switch enable */
#define  TSC_IOASCR_G8_IO2                   ((uint32_t)0x20000000U)            /*!<GROUP8_IO2 analog switch enable */
#define  TSC_IOASCR_G8_IO3                   ((uint32_t)0x40000000U)            /*!<GROUP8_IO3 analog switch enable */
#define  TSC_IOASCR_G8_IO4                   ((uint32_t)0x80000000U)            /*!<GROUP8_IO4 analog switch enable */

/*******************  Bit definition for TSC_IOSCR register  ******************/
#define  TSC_IOSCR_G1_IO1                    ((uint32_t)0x00000001U)            /*!<GROUP1_IO1 sampling mode */
#define  TSC_IOSCR_G1_IO2                    ((uint32_t)0x00000002U)            /*!<GROUP1_IO2 sampling mode */
#define  TSC_IOSCR_G1_IO3                    ((uint32_t)0x00000004U)            /*!<GROUP1_IO3 sampling mode */
#define  TSC_IOSCR_G1_IO4                    ((uint32_t)0x00000008U)            /*!<GROUP1_IO4 sampling mode */
#define  TSC_IOSCR_G2_IO1                    ((uint32_t)0x00000010U)            /*!<GROUP2_IO1 sampling mode */
#define  TSC_IOSCR_G2_IO2                    ((uint32_t)0x00000020U)            /*!<GROUP2_IO2 sampling mode */
#define  TSC_IOSCR_G2_IO3                    ((uint32_t)0x00000040U)            /*!<GROUP2_IO3 sampling mode */
#define  TSC_IOSCR_G2_IO4                    ((uint32_t)0x00000080U)            /*!<GROUP2_IO4 sampling mode */
#define  TSC_IOSCR_G3_IO1                    ((uint32_t)0x00000100U)            /*!<GROUP3_IO1 sampling mode */
#define  TSC_IOSCR_G3_IO2                    ((uint32_t)0x00000200U)            /*!<GROUP3_IO2 sampling mode */
#define  TSC_IOSCR_G3_IO3                    ((uint32_t)0x00000400U)            /*!<GROUP3_IO3 sampling mode */
#define  TSC_IOSCR_G3_IO4                    ((uint32_t)0x00000800U)            /*!<GROUP3_IO4 sampling mode */
#define  TSC_IOSCR_G4_IO1                    ((uint32_t)0x00001000U)            /*!<GROUP4_IO1 sampling mode */
#define  TSC_IOSCR_G4_IO2                    ((uint32_t)0x00002000U)            /*!<GROUP4_IO2 sampling mode */
#define  TSC_IOSCR_G4_IO3                    ((uint32_t)0x00004000U)            /*!<GROUP4_IO3 sampling mode */
#define  TSC_IOSCR_G4_IO4                    ((uint32_t)0x00008000U)            /*!<GROUP4_IO4 sampling mode */
#define  TSC_IOSCR_G5_IO1                    ((uint32_t)0x00010000U)            /*!<GROUP5_IO1 sampling mode */
#define  TSC_IOSCR_G5_IO2                    ((uint32_t)0x00020000U)            /*!<GROUP5_IO2 sampling mode */
#define  TSC_IOSCR_G5_IO3                    ((uint32_t)0x00040000U)            /*!<GROUP5_IO3 sampling mode */
#define  TSC_IOSCR_G5_IO4                    ((uint32_t)0x00080000U)            /*!<GROUP5_IO4 sampling mode */
#define  TSC_IOSCR_G6_IO1                    ((uint32_t)0x00100000U)            /*!<GROUP6_IO1 sampling mode */
#define  TSC_IOSCR_G6_IO2                    ((uint32_t)0x00200000U)            /*!<GROUP6_IO2 sampling mode */
#define  TSC_IOSCR_G6_IO3                    ((uint32_t)0x00400000U)            /*!<GROUP6_IO3 sampling mode */
#define  TSC_IOSCR_G6_IO4                    ((uint32_t)0x00800000U)            /*!<GROUP6_IO4 sampling mode */
#define  TSC_IOSCR_G7_IO1                    ((uint32_t)0x01000000U)            /*!<GROUP7_IO1 sampling mode */
#define  TSC_IOSCR_G7_IO2                    ((uint32_t)0x02000000U)            /*!<GROUP7_IO2 sampling mode */
#define  TSC_IOSCR_G7_IO3                    ((uint32_t)0x04000000U)            /*!<GROUP7_IO3 sampling mode */
#define  TSC_IOSCR_G7_IO4                    ((uint32_t)0x08000000U)            /*!<GROUP7_IO4 sampling mode */
#define  TSC_IOSCR_G8_IO1                    ((uint32_t)0x10000000U)            /*!<GROUP8_IO1 sampling mode */
#define  TSC_IOSCR_G8_IO2                    ((uint32_t)0x20000000U)            /*!<GROUP8_IO2 sampling mode */
#define  TSC_IOSCR_G8_IO3                    ((uint32_t)0x40000000U)            /*!<GROUP8_IO3 sampling mode */
#define  TSC_IOSCR_G8_IO4                    ((uint32_t)0x80000000U)            /*!<GROUP8_IO4 sampling mode */

/*******************  Bit definition for TSC_IOCCR register  ******************/
#define  TSC_IOCCR_G1_IO1                    ((uint32_t)0x00000001U)            /*!<GROUP1_IO1 channel mode */
#define  TSC_IOCCR_G1_IO2                    ((uint32_t)0x00000002U)            /*!<GROUP1_IO2 channel mode */
#define  TSC_IOCCR_G1_IO3                    ((uint32_t)0x00000004U)            /*!<GROUP1_IO3 channel mode */
#define  TSC_IOCCR_G1_IO4                    ((uint32_t)0x00000008U)            /*!<GROUP1_IO4 channel mode */
#define  TSC_IOCCR_G2_IO1                    ((uint32_t)0x00000010U)            /*!<GROUP2_IO1 channel mode */
#define  TSC_IOCCR_G2_IO2                    ((uint32_t)0x00000020U)            /*!<GROUP2_IO2 channel mode */
#define  TSC_IOCCR_G2_IO3                    ((uint32_t)0x00000040U)            /*!<GROUP2_IO3 channel mode */
#define  TSC_IOCCR_G2_IO4                    ((uint32_t)0x00000080U)            /*!<GROUP2_IO4 channel mode */
#define  TSC_IOCCR_G3_IO1                    ((uint32_t)0x00000100U)            /*!<GROUP3_IO1 channel mode */
#define  TSC_IOCCR_G3_IO2                    ((uint32_t)0x00000200U)            /*!<GROUP3_IO2 channel mode */
#define  TSC_IOCCR_G3_IO3                    ((uint32_t)0x00000400U)            /*!<GROUP3_IO3 channel mode */
#define  TSC_IOCCR_G3_IO4                    ((uint32_t)0x00000800U)            /*!<GROUP3_IO4 channel mode */
#define  TSC_IOCCR_G4_IO1                    ((uint32_t)0x00001000U)            /*!<GROUP4_IO1 channel mode */
#define  TSC_IOCCR_G4_IO2                    ((uint32_t)0x00002000U)            /*!<GROUP4_IO2 channel mode */
#define  TSC_IOCCR_G4_IO3                    ((uint32_t)0x00004000U)            /*!<GROUP4_IO3 channel mode */
#define  TSC_IOCCR_G4_IO4                    ((uint32_t)0x00008000U)            /*!<GROUP4_IO4 channel mode */
#define  TSC_IOCCR_G5_IO1                    ((uint32_t)0x00010000U)            /*!<GROUP5_IO1 channel mode */
#define  TSC_IOCCR_G5_IO2                    ((uint32_t)0x00020000U)            /*!<GROUP5_IO2 channel mode */
#define  TSC_IOCCR_G5_IO3                    ((uint32_t)0x00040000U)            /*!<GROUP5_IO3 channel mode */
#define  TSC_IOCCR_G5_IO4                    ((uint32_t)0x00080000U)            /*!<GROUP5_IO4 channel mode */
#define  TSC_IOCCR_G6_IO1                    ((uint32_t)0x00100000U)            /*!<GROUP6_IO1 channel mode */
#define  TSC_IOCCR_G6_IO2                    ((uint32_t)0x00200000U)            /*!<GROUP6_IO2 channel mode */
#define  TSC_IOCCR_G6_IO3                    ((uint32_t)0x00400000U)            /*!<GROUP6_IO3 channel mode */
#define  TSC_IOCCR_G6_IO4                    ((uint32_t)0x00800000U)            /*!<GROUP6_IO4 channel mode */
#define  TSC_IOCCR_G7_IO1                    ((uint32_t)0x01000000U)            /*!<GROUP7_IO1 channel mode */
#define  TSC_IOCCR_G7_IO2                    ((uint32_t)0x02000000U)            /*!<GROUP7_IO2 channel mode */
#define  TSC_IOCCR_G7_IO3                    ((uint32_t)0x04000000U)            /*!<GROUP7_IO3 channel mode */
#define  TSC_IOCCR_G7_IO4                    ((uint32_t)0x08000000U)            /*!<GROUP7_IO4 channel mode */
#define  TSC_IOCCR_G8_IO1                    ((uint32_t)0x10000000U)            /*!<GROUP8_IO1 channel mode */
#define  TSC_IOCCR_G8_IO2                    ((uint32_t)0x20000000U)            /*!<GROUP8_IO2 channel mode */
#define  TSC_IOCCR_G8_IO3                    ((uint32_t)0x40000000U)            /*!<GROUP8_IO3 channel mode */
#define  TSC_IOCCR_G8_IO4                    ((uint32_t)0x80000000U)            /*!<GROUP8_IO4 channel mode */

/*******************  Bit definition for TSC_IOGCSR register  *****************/
#define  TSC_IOGCSR_G1E                      ((uint32_t)0x00000001U)            /*!<Analog IO GROUP1 enable */
#define  TSC_IOGCSR_G2E                      ((uint32_t)0x00000002U)            /*!<Analog IO GROUP2 enable */
#define  TSC_IOGCSR_G3E                      ((uint32_t)0x00000004U)            /*!<Analog IO GROUP3 enable */
#define  TSC_IOGCSR_G4E                      ((uint32_t)0x00000008U)            /*!<Analog IO GROUP4 enable */
#define  TSC_IOGCSR_G5E                      ((uint32_t)0x00000010U)            /*!<Analog IO GROUP5 enable */
#define  TSC_IOGCSR_G6E                      ((uint32_t)0x00000020U)            /*!<Analog IO GROUP6 enable */
#define  TSC_IOGCSR_G7E                      ((uint32_t)0x00000040U)            /*!<Analog IO GROUP7 enable */
#define  TSC_IOGCSR_G8E                      ((uint32_t)0x00000080U)            /*!<Analog IO GROUP8 enable */
#define  TSC_IOGCSR_G1S                      ((uint32_t)0x00010000U)            /*!<Analog IO GROUP1 status */
#define  TSC_IOGCSR_G2S                      ((uint32_t)0x00020000U)            /*!<Analog IO GROUP2 status */
#define  TSC_IOGCSR_G3S                      ((uint32_t)0x00040000U)            /*!<Analog IO GROUP3 status */
#define  TSC_IOGCSR_G4S                      ((uint32_t)0x00080000U)            /*!<Analog IO GROUP4 status */
#define  TSC_IOGCSR_G5S                      ((uint32_t)0x00100000U)            /*!<Analog IO GROUP5 status */
#define  TSC_IOGCSR_G6S                      ((uint32_t)0x00200000U)            /*!<Analog IO GROUP6 status */
#define  TSC_IOGCSR_G7S                      ((uint32_t)0x00400000U)            /*!<Analog IO GROUP7 status */
#define  TSC_IOGCSR_G8S                      ((uint32_t)0x00800000U)            /*!<Analog IO GROUP8 status */

/*******************  Bit definition for TSC_IOGXCR register  *****************/
#define  TSC_IOGXCR_CNT                      ((uint32_t)0x00003FFFU)            /*!<CNT[13:0] bits (Counter value) */

/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for USART_CR1 register  *******************/
#define  USART_CR1_UE                        ((uint32_t)0x00000001U)            /*!< USART Enable */
#define  USART_CR1_UESM                      ((uint32_t)0x00000002U)            /*!< USART Enable in STOP Mode */
#define  USART_CR1_RE                        ((uint32_t)0x00000004U)            /*!< Receiver Enable */
#define  USART_CR1_TE                        ((uint32_t)0x00000008U)            /*!< Transmitter Enable */
#define  USART_CR1_IDLEIE                    ((uint32_t)0x00000010U)            /*!< IDLE Interrupt Enable */
#define  USART_CR1_RXNEIE                    ((uint32_t)0x00000020U)            /*!< RXNE Interrupt Enable */
#define  USART_CR1_TCIE                      ((uint32_t)0x00000040U)            /*!< Transmission Complete Interrupt Enable */
#define  USART_CR1_TXEIE                     ((uint32_t)0x00000080U)            /*!< TXE Interrupt Enable */
#define  USART_CR1_PEIE                      ((uint32_t)0x00000100U)            /*!< PE Interrupt Enable */
#define  USART_CR1_PS                        ((uint32_t)0x00000200U)            /*!< Parity Selection */
#define  USART_CR1_PCE                       ((uint32_t)0x00000400U)            /*!< Parity Control Enable */
#define  USART_CR1_WAKE                      ((uint32_t)0x00000800U)            /*!< Receiver Wakeup method */
#define  USART_CR1_M                         ((uint32_t)0x00001000U)            /*!< Word length */
#define  USART_CR1_M0                        ((uint32_t)0x00001000U)            /*!< SmartCard Word length */
#define  USART_CR1_MME                       ((uint32_t)0x00002000U)            /*!< Mute Mode Enable */
#define  USART_CR1_CMIE                      ((uint32_t)0x00004000U)            /*!< Character match interrupt enable */
#define  USART_CR1_OVER8                     ((uint32_t)0x00008000U)            /*!< Oversampling by 8-bit or 16-bit mode */
#define  USART_CR1_DEDT                      ((uint32_t)0x001F0000U)            /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define  USART_CR1_DEDT_0                    ((uint32_t)0x00010000U)            /*!< Bit 0 */
#define  USART_CR1_DEDT_1                    ((uint32_t)0x00020000U)            /*!< Bit 1 */
#define  USART_CR1_DEDT_2                    ((uint32_t)0x00040000U)            /*!< Bit 2 */
#define  USART_CR1_DEDT_3                    ((uint32_t)0x00080000U)            /*!< Bit 3 */
#define  USART_CR1_DEDT_4                    ((uint32_t)0x00100000U)            /*!< Bit 4 */
#define  USART_CR1_DEAT                      ((uint32_t)0x03E00000U)            /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define  USART_CR1_DEAT_0                    ((uint32_t)0x00200000U)            /*!< Bit 0 */
#define  USART_CR1_DEAT_1                    ((uint32_t)0x00400000U)            /*!< Bit 1 */
#define  USART_CR1_DEAT_2                    ((uint32_t)0x00800000U)            /*!< Bit 2 */
#define  USART_CR1_DEAT_3                    ((uint32_t)0x01000000U)            /*!< Bit 3 */
#define  USART_CR1_DEAT_4                    ((uint32_t)0x02000000U)            /*!< Bit 4 */
#define  USART_CR1_RTOIE                     ((uint32_t)0x04000000U)            /*!< Receive Time Out interrupt enable */
#define  USART_CR1_EOBIE                     ((uint32_t)0x08000000U)            /*!< End of Block interrupt enable */

/******************  Bit definition for USART_CR2 register  *******************/
#define  USART_CR2_ADDM7                     ((uint32_t)0x00000010U)            /*!< 7-bit or 4-bit Address Detection */
#define  USART_CR2_LBDL                      ((uint32_t)0x00000020U)            /*!< LIN Break Detection Length */
#define  USART_CR2_LBDIE                     ((uint32_t)0x00000040U)            /*!< LIN Break Detection Interrupt Enable */
#define  USART_CR2_LBCL                      ((uint32_t)0x00000100U)            /*!< Last Bit Clock pulse */
#define  USART_CR2_CPHA                      ((uint32_t)0x00000200U)            /*!< Clock Phase */
#define  USART_CR2_CPOL                      ((uint32_t)0x00000400U)            /*!< Clock Polarity */
#define  USART_CR2_CLKEN                     ((uint32_t)0x00000800U)            /*!< Clock Enable */
#define  USART_CR2_STOP                      ((uint32_t)0x00003000U)            /*!< STOP[1:0] bits (STOP bits) */
#define  USART_CR2_STOP_0                    ((uint32_t)0x00001000U)            /*!< Bit 0 */
#define  USART_CR2_STOP_1                    ((uint32_t)0x00002000U)            /*!< Bit 1 */
#define  USART_CR2_LINEN                     ((uint32_t)0x00004000U)            /*!< LIN mode enable */
#define  USART_CR2_SWAP                      ((uint32_t)0x00008000U)            /*!< SWAP TX/RX pins */
#define  USART_CR2_RXINV                     ((uint32_t)0x00010000U)            /*!< RX pin active level inversion */
#define  USART_CR2_TXINV                     ((uint32_t)0x00020000U)            /*!< TX pin active level inversion */
#define  USART_CR2_DATAINV                   ((uint32_t)0x00040000U)            /*!< Binary data inversion */
#define  USART_CR2_MSBFIRST                  ((uint32_t)0x00080000U)            /*!< Most Significant Bit First */
#define  USART_CR2_ABREN                     ((uint32_t)0x00100000U)            /*!< Auto Baud-Rate Enable*/
#define  USART_CR2_ABRMODE                   ((uint32_t)0x00600000U)            /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define  USART_CR2_ABRMODE_0                 ((uint32_t)0x00200000U)            /*!< Bit 0 */
#define  USART_CR2_ABRMODE_1                 ((uint32_t)0x00400000U)            /*!< Bit 1 */
#define  USART_CR2_RTOEN                     ((uint32_t)0x00800000U)            /*!< Receiver Time-Out enable */
#define  USART_CR2_ADD                       ((uint32_t)0xFF000000U)            /*!< Address of the USART node */

/******************  Bit definition for USART_CR3 register  *******************/
#define  USART_CR3_EIE                       ((uint32_t)0x00000001U)            /*!< Error Interrupt Enable */
#define  USART_CR3_IREN                      ((uint32_t)0x00000002U)            /*!< IrDA mode Enable */
#define  USART_CR3_IRLP                      ((uint32_t)0x00000004U)            /*!< IrDA Low-Power */
#define  USART_CR3_HDSEL                     ((uint32_t)0x00000008U)            /*!< Half-Duplex Selection */
#define  USART_CR3_NACK                      ((uint32_t)0x00000010U)            /*!< SmartCard NACK enable */
#define  USART_CR3_SCEN                      ((uint32_t)0x00000020U)            /*!< SmartCard mode enable */
#define  USART_CR3_DMAR                      ((uint32_t)0x00000040U)            /*!< DMA Enable Receiver */
#define  USART_CR3_DMAT                      ((uint32_t)0x00000080U)            /*!< DMA Enable Transmitter */
#define  USART_CR3_RTSE                      ((uint32_t)0x00000100U)            /*!< RTS Enable */
#define  USART_CR3_CTSE                      ((uint32_t)0x00000200U)            /*!< CTS Enable */
#define  USART_CR3_CTSIE                     ((uint32_t)0x00000400U)            /*!< CTS Interrupt Enable */
#define  USART_CR3_ONEBIT                    ((uint32_t)0x00000800U)            /*!< One sample bit method enable */
#define  USART_CR3_OVRDIS                    ((uint32_t)0x00001000U)            /*!< Overrun Disable */
#define  USART_CR3_DDRE                      ((uint32_t)0x00002000U)            /*!< DMA Disable on Reception Error */
#define  USART_CR3_DEM                       ((uint32_t)0x00004000U)            /*!< Driver Enable Mode */
#define  USART_CR3_DEP                       ((uint32_t)0x00008000U)            /*!< Driver Enable Polarity Selection */
#define  USART_CR3_SCARCNT                   ((uint32_t)0x000E0000U)            /*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define  USART_CR3_SCARCNT_0                 ((uint32_t)0x00020000U)            /*!< Bit 0 */
#define  USART_CR3_SCARCNT_1                 ((uint32_t)0x00040000U)            /*!< Bit 1 */
#define  USART_CR3_SCARCNT_2                 ((uint32_t)0x00080000U)            /*!< Bit 2 */
#define  USART_CR3_WUS                       ((uint32_t)0x00300000U)            /*!< WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
#define  USART_CR3_WUS_0                     ((uint32_t)0x00100000U)            /*!< Bit 0 */
#define  USART_CR3_WUS_1                     ((uint32_t)0x00200000U)            /*!< Bit 1 */
#define  USART_CR3_WUFIE                     ((uint32_t)0x00400000U)            /*!< Wake Up Interrupt Enable */

/******************  Bit definition for USART_BRR register  *******************/
#define  USART_BRR_DIV_FRACTION              ((uint32_t)0x0000000FU)            /*!< Fraction of USARTDIV */
#define  USART_BRR_DIV_MANTISSA              ((uint32_t)0x0000FFF0U)            /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_GTPR register  ******************/
#define  USART_GTPR_PSC                      ((uint32_t)0x000000FFU)            /*!< PSC[7:0] bits (Prescaler value) */
#define  USART_GTPR_GT                       ((uint32_t)0x0000FF00U)            /*!< GT[7:0] bits (Guard time value) */


/*******************  Bit definition for USART_RTOR register  *****************/
#define  USART_RTOR_RTO                      ((uint32_t)0x00FFFFFFU)            /*!< Receiver Time Out Value */
#define  USART_RTOR_BLEN                     ((uint32_t)0xFF000000U)            /*!< Block Length */

/*******************  Bit definition for USART_RQR register  ******************/
#define  USART_RQR_ABRRQ                     ((uint32_t)0x00000001U)            /*!< Auto-Baud Rate Request */
#define  USART_RQR_SBKRQ                     ((uint32_t)0x00000002U)            /*!< Send Break Request */
#define  USART_RQR_MMRQ                      ((uint32_t)0x00000004U)            /*!< Mute Mode Request */
#define  USART_RQR_RXFRQ                     ((uint32_t)0x00000008U)            /*!< Receive Data flush Request */
#define  USART_RQR_TXFRQ                     ((uint32_t)0x00000010U)            /*!< Transmit data flush Request */

/*******************  Bit definition for USART_ISR register  ******************/
#define  USART_ISR_PE                        ((uint32_t)0x00000001U)            /*!< Parity Error */
#define  USART_ISR_FE                        ((uint32_t)0x00000002U)            /*!< Framing Error */
#define  USART_ISR_NE                        ((uint32_t)0x00000004U)            /*!< Noise detected Flag */
#define  USART_ISR_ORE                       ((uint32_t)0x00000008U)            /*!< OverRun Error */
#define  USART_ISR_IDLE                      ((uint32_t)0x00000010U)            /*!< IDLE line detected */
#define  USART_ISR_RXNE                      ((uint32_t)0x00000020U)            /*!< Read Data Register Not Empty */
#define  USART_ISR_TC                        ((uint32_t)0x00000040U)            /*!< Transmission Complete */
#define  USART_ISR_TXE                       ((uint32_t)0x00000080U)            /*!< Transmit Data Register Empty */
#define  USART_ISR_LBDF                      ((uint32_t)0x00000100U)            /*!< LIN Break Detection Flag */
#define  USART_ISR_CTSIF                     ((uint32_t)0x00000200U)            /*!< CTS interrupt flag */
#define  USART_ISR_CTS                       ((uint32_t)0x00000400U)            /*!< CTS flag */
#define  USART_ISR_RTOF                      ((uint32_t)0x00000800U)            /*!< Receiver Time Out */
#define  USART_ISR_EOBF                      ((uint32_t)0x00001000U)            /*!< End Of Block Flag */
#define  USART_ISR_ABRE                      ((uint32_t)0x00004000U)            /*!< Auto-Baud Rate Error */
#define  USART_ISR_ABRF                      ((uint32_t)0x00008000U)            /*!< Auto-Baud Rate Flag */
#define  USART_ISR_BUSY                      ((uint32_t)0x00010000U)            /*!< Busy Flag */
#define  USART_ISR_CMF                       ((uint32_t)0x00020000U)            /*!< Character Match Flag */
#define  USART_ISR_SBKF                      ((uint32_t)0x00040000U)            /*!< Send Break Flag */
#define  USART_ISR_RWU                       ((uint32_t)0x00080000U)            /*!< Receive Wake Up from mute mode Flag */
#define  USART_ISR_WUF                       ((uint32_t)0x00100000U)            /*!< Wake Up from stop mode Flag */
#define  USART_ISR_TEACK                     ((uint32_t)0x00200000U)            /*!< Transmit Enable Acknowledge Flag */
#define  USART_ISR_REACK                     ((uint32_t)0x00400000U)            /*!< Receive Enable Acknowledge Flag */

/*******************  Bit definition for USART_ICR register  ******************/
#define  USART_ICR_PECF                      ((uint32_t)0x00000001U)            /*!< Parity Error Clear Flag */
#define  USART_ICR_FECF                      ((uint32_t)0x00000002U)            /*!< Framing Error Clear Flag */
#define  USART_ICR_NCF                       ((uint32_t)0x00000004U)            /*!< Noise detected Clear Flag */
#define  USART_ICR_ORECF                     ((uint32_t)0x00000008U)            /*!< OverRun Error Clear Flag */
#define  USART_ICR_IDLECF                    ((uint32_t)0x00000010U)            /*!< IDLE line detected Clear Flag */
#define  USART_ICR_TCCF                      ((uint32_t)0x00000040U)            /*!< Transmission Complete Clear Flag */
#define  USART_ICR_LBDCF                     ((uint32_t)0x00000100U)            /*!< LIN Break Detection Clear Flag */
#define  USART_ICR_CTSCF                     ((uint32_t)0x00000200U)            /*!< CTS Interrupt Clear Flag */
#define  USART_ICR_RTOCF                     ((uint32_t)0x00000800U)            /*!< Receiver Time Out Clear Flag */
#define  USART_ICR_EOBCF                     ((uint32_t)0x00001000U)            /*!< End Of Block Clear Flag */
#define  USART_ICR_CMCF                      ((uint32_t)0x00020000U)            /*!< Character Match Clear Flag */
#define  USART_ICR_WUCF                      ((uint32_t)0x00100000U)            /*!< Wake Up from stop mode Clear Flag */

/*******************  Bit definition for USART_RDR register  ******************/
#define  USART_RDR_RDR                       ((uint32_t)0x000001FFU)            /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define  USART_TDR_TDR                       ((uint32_t)0x000001FFU)            /*!< TDR[8:0] bits (Transmit Data value) */

/******************************************************************************/
/*                                                                            */
/*                         USB Device General registers                       */
/*                                                                            */
/******************************************************************************/
#define USB_CNTR                             (USB_BASE + 0x40U)             /*!< Control register */
#define USB_ISTR                             (USB_BASE + 0x44U)             /*!< Interrupt status register */
#define USB_FNR                              (USB_BASE + 0x48U)             /*!< Frame number register */
#define USB_DADDR                            (USB_BASE + 0x4CU)             /*!< Device address register */
#define USB_BTABLE                           (USB_BASE + 0x50U)             /*!< Buffer Table address register */

/****************************  ISTR interrupt events  *************************/
#define USB_ISTR_CTR                         ((uint16_t)0x8000U)             /*!< Correct TRansfer (clear-only bit) */
#define USB_ISTR_PMAOVR                      ((uint16_t)0x4000U)             /*!< DMA OVeR/underrun (clear-only bit) */
#define USB_ISTR_ERR                         ((uint16_t)0x2000U)             /*!< ERRor (clear-only bit) */
#define USB_ISTR_WKUP                        ((uint16_t)0x1000U)             /*!< WaKe UP (clear-only bit) */
#define USB_ISTR_SUSP                        ((uint16_t)0x0800U)             /*!< SUSPend (clear-only bit) */
#define USB_ISTR_RESET                       ((uint16_t)0x0400U)             /*!< RESET (clear-only bit) */
#define USB_ISTR_SOF                         ((uint16_t)0x0200U)             /*!< Start Of Frame (clear-only bit) */
#define USB_ISTR_ESOF                        ((uint16_t)0x0100U)             /*!< Expected Start Of Frame (clear-only bit) */
#define USB_ISTR_DIR                         ((uint16_t)0x0010U)             /*!< DIRection of transaction (read-only bit)  */
#define USB_ISTR_EP_ID                       ((uint16_t)0x000FU)             /*!< EndPoint IDentifier (read-only bit)  */

/* Legacy defines */
#define USB_ISTR_PMAOVRM USB_ISTR_PMAOVR

#define USB_CLR_CTR                          (~USB_ISTR_CTR)             /*!< clear Correct TRansfer bit */
#define USB_CLR_PMAOVR                       (~USB_ISTR_PMAOVR)          /*!< clear DMA OVeR/underrun bit*/
#define USB_CLR_ERR                          (~USB_ISTR_ERR)             /*!< clear ERRor bit */
#define USB_CLR_WKUP                         (~USB_ISTR_WKUP)            /*!< clear WaKe UP bit */
#define USB_CLR_SUSP                         (~USB_ISTR_SUSP)            /*!< clear SUSPend bit */
#define USB_CLR_RESET                        (~USB_ISTR_RESET)           /*!< clear RESET bit */
#define USB_CLR_SOF                          (~USB_ISTR_SOF)             /*!< clear Start Of Frame bit */
#define USB_CLR_ESOF                         (~USB_ISTR_ESOF)            /*!< clear Expected Start Of Frame bit */

/* Legacy defines */
#define USB_CLR_PMAOVRM USB_CLR_PMAOVR

/*************************  CNTR control register bits definitions  ***********/
#define USB_CNTR_CTRM                        ((uint16_t)0x8000U)             /*!< Correct TRansfer Mask */
#define USB_CNTR_PMAOVR                      ((uint16_t)0x4000U)             /*!< DMA OVeR/underrun Mask */
#define USB_CNTR_ERRM                        ((uint16_t)0x2000U)             /*!< ERRor Mask */
#define USB_CNTR_WKUPM                       ((uint16_t)0x1000U)             /*!< WaKe UP Mask */
#define USB_CNTR_SUSPM                       ((uint16_t)0x0800U)             /*!< SUSPend Mask */
#define USB_CNTR_RESETM                      ((uint16_t)0x0400U)             /*!< RESET Mask   */
#define USB_CNTR_SOFM                        ((uint16_t)0x0200U)             /*!< Start Of Frame Mask */
#define USB_CNTR_ESOFM                       ((uint16_t)0x0100U)             /*!< Expected Start Of Frame Mask */
#define USB_CNTR_RESUME                      ((uint16_t)0x0010U)             /*!< RESUME request */
#define USB_CNTR_FSUSP                       ((uint16_t)0x0008U)             /*!< Force SUSPend */
#define USB_CNTR_LPMODE                      ((uint16_t)0x0004U)             /*!< Low-power MODE */
#define USB_CNTR_PDWN                        ((uint16_t)0x0002U)             /*!< Power DoWN */
#define USB_CNTR_FRES                        ((uint16_t)0x0001U)             /*!< Force USB RESet */

/* Legacy defines */
#define USB_CNTR_PMAOVRM USB_CNTR_PMAOVR
#define USB_CNTR_LP_MODE USB_CNTR_LPMODE

/********************  FNR Frame Number Register bit definitions   ************/
#define USB_FNR_RXDP                         ((uint16_t)0x8000U)             /*!< status of D+ data line */
#define USB_FNR_RXDM                         ((uint16_t)0x4000U)             /*!< status of D- data line */
#define USB_FNR_LCK                          ((uint16_t)0x2000U)             /*!< LoCKed */
#define USB_FNR_LSOF                         ((uint16_t)0x1800U)             /*!< Lost SOF */
#define USB_FNR_FN                           ((uint16_t)0x07FFU)             /*!< Frame Number */

/********************  DADDR Device ADDRess bit definitions    ****************/
#define USB_DADDR_EF                         ((uint8_t)0x80U)                /*!< USB device address Enable Function */
#define USB_DADDR_ADD                        ((uint8_t)0x7FU)                /*!< USB device address */

/******************************  Endpoint register    *************************/
#define USB_EP0R                             USB_BASE                    /*!< endpoint 0 register address */
#define USB_EP1R                             (USB_BASE + 0x04U)           /*!< endpoint 1 register address */
#define USB_EP2R                             (USB_BASE + 0x08U)           /*!< endpoint 2 register address */
#define USB_EP3R                             (USB_BASE + 0x0CU)           /*!< endpoint 3 register address */
#define USB_EP4R                             (USB_BASE + 0x10U)           /*!< endpoint 4 register address */
#define USB_EP5R                             (USB_BASE + 0x14U)           /*!< endpoint 5 register address */
#define USB_EP6R                             (USB_BASE + 0x18U)           /*!< endpoint 6 register address */
#define USB_EP7R                             (USB_BASE + 0x1CU)           /*!< endpoint 7 register address */
/* bit positions */ 
#define USB_EP_CTR_RX                        ((uint16_t)0x8000U)             /*!<  EndPoint Correct TRansfer RX */
#define USB_EP_DTOG_RX                       ((uint16_t)0x4000U)             /*!<  EndPoint Data TOGGLE RX */
#define USB_EPRX_STAT                        ((uint16_t)0x3000U)             /*!<  EndPoint RX STATus bit field */
#define USB_EP_SETUP                         ((uint16_t)0x0800U)             /*!<  EndPoint SETUP */
#define USB_EP_T_FIELD                       ((uint16_t)0x0600U)             /*!<  EndPoint TYPE */
#define USB_EP_KIND                          ((uint16_t)0x0100U)             /*!<  EndPoint KIND */
#define USB_EP_CTR_TX                        ((uint16_t)0x0080U)             /*!<  EndPoint Correct TRansfer TX */
#define USB_EP_DTOG_TX                       ((uint16_t)0x0040U)             /*!<  EndPoint Data TOGGLE TX */
#define USB_EPTX_STAT                        ((uint16_t)0x0030U)             /*!<  EndPoint TX STATus bit field */
#define USB_EPADDR_FIELD                     ((uint16_t)0x000FU)             /*!<  EndPoint ADDRess FIELD */

/* EndPoint REGister MASK (no toggle fields) */
#define USB_EPREG_MASK     (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)
                                                                               /*!< EP_TYPE[1:0] EndPoint TYPE */
#define USB_EP_TYPE_MASK                     ((uint16_t)0x0600U)             /*!< EndPoint TYPE Mask */
#define USB_EP_BULK                          ((uint16_t)0x0000U)             /*!< EndPoint BULK */
#define USB_EP_CONTROL                       ((uint16_t)0x0200U)             /*!< EndPoint CONTROL */
#define USB_EP_ISOCHRONOUS                   ((uint16_t)0x0400U)             /*!< EndPoint ISOCHRONOUS */
#define USB_EP_INTERRUPT                     ((uint16_t)0x0600U)             /*!< EndPoint INTERRUPT */
#define USB_EP_T_MASK      (~USB_EP_T_FIELD & USB_EPREG_MASK)
                                                                 
#define USB_EPKIND_MASK    (~USB_EP_KIND & USB_EPREG_MASK)            /*!< EP_KIND EndPoint KIND */
                                                                               /*!< STAT_TX[1:0] STATus for TX transfer */
#define USB_EP_TX_DIS                        ((uint16_t)0x0000U)             /*!< EndPoint TX DISabled */
#define USB_EP_TX_STALL                      ((uint16_t)0x0010U)             /*!< EndPoint TX STALLed */
#define USB_EP_TX_NAK                        ((uint16_t)0x0020U)             /*!< EndPoint TX NAKed */
#define USB_EP_TX_VALID                      ((uint16_t)0x0030U)             /*!< EndPoint TX VALID */
#define USB_EPTX_DTOG1                       ((uint16_t)0x0010U)             /*!< EndPoint TX Data TOGgle bit1 */
#define USB_EPTX_DTOG2                       ((uint16_t)0x0020U)             /*!< EndPoint TX Data TOGgle bit2 */
#define USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)
                                                                               /*!< STAT_RX[1:0] STATus for RX transfer */
#define USB_EP_RX_DIS                        ((uint16_t)0x0000U)             /*!< EndPoint RX DISabled */
#define USB_EP_RX_STALL                      ((uint16_t)0x1000U)             /*!< EndPoint RX STALLed */
#define USB_EP_RX_NAK                        ((uint16_t)0x2000U)             /*!< EndPoint RX NAKed */
#define USB_EP_RX_VALID                      ((uint16_t)0x3000U)             /*!< EndPoint RX VALID */
#define USB_EPRX_DTOG1                       ((uint16_t)0x1000U)             /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOG2                       ((uint16_t)0x2000U)             /*!< EndPoint RX Data TOGgle bit1 */
#define USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define  WWDG_CR_T                           ((uint32_t)0x0000007FU)               /*!< T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  WWDG_CR_T_0                         ((uint32_t)0x00000001U)               /*!< Bit 0 */
#define  WWDG_CR_T_1                         ((uint32_t)0x00000002U)               /*!< Bit 1 */
#define  WWDG_CR_T_2                         ((uint32_t)0x00000004U)               /*!< Bit 2 */
#define  WWDG_CR_T_3                         ((uint32_t)0x00000008U)               /*!< Bit 3 */
#define  WWDG_CR_T_4                         ((uint32_t)0x00000010U)               /*!< Bit 4 */
#define  WWDG_CR_T_5                         ((uint32_t)0x00000020U)               /*!< Bit 5 */
#define  WWDG_CR_T_6                         ((uint32_t)0x00000040U)               /*!< Bit 6 */

/* Legacy defines */
#define  WWDG_CR_T0 WWDG_CR_T_0
#define  WWDG_CR_T1 WWDG_CR_T_1
#define  WWDG_CR_T2 WWDG_CR_T_2
#define  WWDG_CR_T3 WWDG_CR_T_3
#define  WWDG_CR_T4 WWDG_CR_T_4
#define  WWDG_CR_T5 WWDG_CR_T_5
#define  WWDG_CR_T6 WWDG_CR_T_6

#define  WWDG_CR_WDGA                        ((uint32_t)0x00000080U)        /*!<Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define  WWDG_CFR_W                          ((uint32_t)0x0000007FU)               /*!< W[6:0] bits (7-bit window value) */
#define  WWDG_CFR_W_0                        ((uint32_t)0x00000001U)               /*!< Bit 0 */
#define  WWDG_CFR_W_1                        ((uint32_t)0x00000002U)               /*!< Bit 1 */
#define  WWDG_CFR_W_2                        ((uint32_t)0x00000004U)               /*!< Bit 2 */
#define  WWDG_CFR_W_3                        ((uint32_t)0x00000008U)               /*!< Bit 3 */
#define  WWDG_CFR_W_4                        ((uint32_t)0x00000010U)               /*!< Bit 4 */
#define  WWDG_CFR_W_5                        ((uint32_t)0x00000020U)               /*!< Bit 5 */
#define  WWDG_CFR_W_6                        ((uint32_t)0x00000040U)               /*!< Bit 6 */

/* Legacy defines */
#define  WWDG_CFR_W0 WWDG_CFR_W_0
#define  WWDG_CFR_W1 WWDG_CFR_W_1
#define  WWDG_CFR_W2 WWDG_CFR_W_2
#define  WWDG_CFR_W3 WWDG_CFR_W_3
#define  WWDG_CFR_W4 WWDG_CFR_W_4
#define  WWDG_CFR_W5 WWDG_CFR_W_5
#define  WWDG_CFR_W6 WWDG_CFR_W_6

#define  WWDG_CFR_WDGTB                      ((uint32_t)0x00000180U)               /*!< WDGTB[1:0] bits (Timer Base) */
#define  WWDG_CFR_WDGTB_0                    ((uint32_t)0x00000080U)               /*!< Bit 0 */
#define  WWDG_CFR_WDGTB_1                    ((uint32_t)0x00000100U)               /*!< Bit 1 */

/* Legacy defines */
#define  WWDG_CFR_WDGTB0 WWDG_CFR_WDGTB_0
#define  WWDG_CFR_WDGTB1 WWDG_CFR_WDGTB_1

#define  WWDG_CFR_EWI                        ((uint32_t)0x00000200U)        /*!<Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define  WWDG_SR_EWIF                        ((uint32_t)0x00000001U)        /*!<Early Wakeup Interrupt Flag */

/**
  * @}
  */

 /**
  * @}
  */

/** @addtogroup Exported_macros
  * @{
  */

/****************************** ADC Instances *********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                       ((INSTANCE) == ADC2) || \
                                       ((INSTANCE) == ADC3) || \
                                       ((INSTANCE) == ADC4))

#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE) (((INSTANCE) == ADC1) || \
                                                    ((INSTANCE) == ADC3))

#define IS_ADC_COMMON_INSTANCE(INSTANCE) (((INSTANCE) == ADC12_COMMON) || \
                                          ((INSTANCE) == ADC34_COMMON))

/****************************** CAN Instances *********************************/
#define IS_CAN_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CAN)

/****************************** COMP Instances ********************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP1) || \
                                        ((INSTANCE) == COMP2) || \
                                        ((INSTANCE) == COMP3) || \
                                        ((INSTANCE) == COMP4) || \
                                        ((INSTANCE) == COMP5) || \
                                        ((INSTANCE) == COMP6) || \
                                        ((INSTANCE) == COMP7))

/******************** COMP Instances with switch on DAC1 Channel1 output ******/
#define IS_COMP_DAC1SWITCH_INSTANCE(INSTANCE) ((INSTANCE) == COMP1)

/******************** COMP Instances with window mode capability **************/
#define IS_COMP_WINDOWMODE_INSTANCE(INSTANCE) (((INSTANCE) == COMP2) || \
                                               ((INSTANCE) == COMP4) || \
                                               ((INSTANCE) == COMP6))

/****************************** CRC Instances *********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/****************************** DAC Instances *********************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DAC1)

#define IS_DAC_CHANNEL_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == DAC1) &&                   \
     (((CHANNEL) == DAC_CHANNEL_1) ||          \
      ((CHANNEL) == DAC_CHANNEL_2))))

/****************************** DMA Instances *********************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7) || \
                                       ((INSTANCE) == DMA2_Channel1) || \
                                       ((INSTANCE) == DMA2_Channel2) || \
                                       ((INSTANCE) == DMA2_Channel3) || \
                                       ((INSTANCE) == DMA2_Channel4) || \
                                       ((INSTANCE) == DMA2_Channel5))

/****************************** GPIO Instances ********************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == GPIOA) || \
                                         ((INSTANCE) == GPIOB) || \
                                         ((INSTANCE) == GPIOC) || \
                                         ((INSTANCE) == GPIOD) || \
                                         ((INSTANCE) == GPIOE) || \
                                         ((INSTANCE) == GPIOF))

#define IS_GPIO_AF_INSTANCE(INSTANCE)   (((INSTANCE) == GPIOA) || \
                                         ((INSTANCE) == GPIOB) || \
                                         ((INSTANCE) == GPIOC) || \
                                         ((INSTANCE) == GPIOD) || \
                                         ((INSTANCE) == GPIOE) || \
                                         ((INSTANCE) == GPIOF))

#define IS_GPIO_LOCK_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                         ((INSTANCE) == GPIOB) || \
                                         ((INSTANCE) == GPIOD))

/****************************** I2C Instances *********************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                       ((INSTANCE) == I2C2))

/****************** I2C Instances : wakeup capability from stop modes *********/
#define IS_I2C_WAKEUP_FROMSTOP_INSTANCE(INSTANCE) IS_I2C_ALL_INSTANCE(INSTANCE)

/****************************** I2S Instances *********************************/
#define IS_I2S_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))
#define IS_I2S_EXT_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2S2ext) || \
                                           ((INSTANCE) == I2S3ext))

/****************************** OPAMP Instances *******************************/
#define IS_OPAMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == OPAMP1) || \
                                         ((INSTANCE) == OPAMP2) || \
                                         ((INSTANCE) == OPAMP3) || \
                                         ((INSTANCE) == OPAMP4))

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/****************************** SMBUS Instances *******************************/
#define IS_SMBUS_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C1) || \
                                         ((INSTANCE) == I2C2))

/****************************** SPI Instances *********************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2) || \
                                       ((INSTANCE) == SPI3))

/******************* TIM Instances : All supported instances ******************/
#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/******************* TIM Instances : at least 1 capture/compare channel *******/
#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/****************** TIM Instances : at least 2 capture/compare channels *******/
#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : at least 3 capture/compare channels *******/
#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : at least 4 capture/compare channels *******/
#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : at least 5 capture/compare channels *******/
#define IS_TIM_CC5_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : at least 6 capture/compare channels *******/
#define IS_TIM_CC6_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))
    
/************************** TIM Instances : Advanced-control timers ***********/

/****************** TIM Instances : supporting clock selection ****************/
#define IS_TIM_CLOCK_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting external clock mode 1 for ETRF input */
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting external clock mode 2 **********/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting external clock mode 1 for TIX inputs*/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting internal trigger inputs(ITRX) *******/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting Hall interface *****************/
#define IS_TIM_HALL_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))     
   
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))      
   
/**************** TIM Instances : external trigger input available ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1)  || \
                                            ((INSTANCE) == TIM2)  || \
                                            ((INSTANCE) == TIM3)  || \
                                            ((INSTANCE) == TIM4)  || \
                                            ((INSTANCE) == TIM8))    

/****************** TIM Instances : supporting input XOR function *************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting master mode ********************/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM8)   || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting slave mode *********************/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)   || \
   ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting synchronization ****************/
#define IS_TIM_SYNCHRO_INSTANCE(INSTANCE)\
    (((INSTANCE) == TIM1)    || \
     ((INSTANCE) == TIM2)    || \
     ((INSTANCE) == TIM3)    || \
     ((INSTANCE) == TIM4)    || \
     ((INSTANCE) == TIM6)    || \
     ((INSTANCE) == TIM7)    || \
     ((INSTANCE) == TIM8)    || \
     ((INSTANCE) == TIM15))

/****************** TIM Instances : supporting 32 bits counter ****************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE)\
    ((INSTANCE) == TIM2)

/****************** TIM Instances : supporting DMA burst **********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE)\
    (((INSTANCE) == TIM1)    || \
     ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
     ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
     ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
      (((INSTANCE) == TIM1)    || \
       ((INSTANCE) == TIM8)    || \
       ((INSTANCE) == TIM15)   || \
       ((INSTANCE) == TIM16)   || \
       ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting input/output channel(s) ********/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4) ||          \
      ((CHANNEL) == TIM_CHANNEL_5) ||          \
      ((CHANNEL) == TIM_CHANNEL_6)))           \
    ||                                         \
    (((INSTANCE) == TIM2) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM3) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM4) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM8) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4) ||          \
      ((CHANNEL) == TIM_CHANNEL_5) ||          \
      ((CHANNEL) == TIM_CHANNEL_6)))           \
    ||                                         \
    (((INSTANCE) == TIM15) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TIM16) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM17) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1))))

/****************** TIM Instances : supporting complementary output(s) ********/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                         \
    (((INSTANCE) == TIM8) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                          \
    (((INSTANCE) == TIM15) &&                   \
      ((CHANNEL) == TIM_CHANNEL_1))             \
    ||                                          \
    (((INSTANCE) == TIM16) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1))              \
    ||                                          \
    (((INSTANCE) == TIM17) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1)))

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting 2 break inputs *****************/
#define IS_TIM_BKIN2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting ADC triggering through TRGO2 ***/
#define IS_TIM_TRGO2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

/****************** TIM Instances : supporting DMA generation on Update events*/
#define IS_TIM_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM7)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting DMA generation on Capture/Compare events */
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM2)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM4)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

/****************** TIM Instances : supporting remapping capability ***********/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8)   || \
   ((INSTANCE) == TIM16))

/****************** TIM Instances : supporting combined 3-phase PWM mode ******/
#define IS_TIM_COMBINED3PHASEPWM_INSTANCE(INSTANCE) \
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM8))

/****************************** TSC Instances *********************************/
#define IS_TSC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == TSC)

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2) || \
                                     ((INSTANCE) == USART3))

/****************** USART Instances : Auto Baud Rate detection ****************/
#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                            ((INSTANCE) == USART2) || \
                                                            ((INSTANCE) == USART3))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                      ((INSTANCE) == USART2) || \
                                      ((INSTANCE) == USART3) || \
                                      ((INSTANCE) == UART4)  || \
                                      ((INSTANCE) == UART5))
                                      
/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                 ((INSTANCE) == USART2) || \
                                                 ((INSTANCE) == USART3) || \
                                                 ((INSTANCE) == UART4)  || \
                                                 ((INSTANCE) == UART5))                                       
                                      
/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                          ((INSTANCE) == USART2) || \
                                          ((INSTANCE) == USART3) || \
                                          ((INSTANCE) == UART4)  || \
                                          ((INSTANCE) == UART5))
                                          
/******************** UART Instances : Wake-up from Stop mode **********************/
#define IS_UART_WAKEUP_FROMSTOP_INSTANCE(INSTANCE)   (((INSTANCE) == USART1) || \
                                                      ((INSTANCE) == USART2) || \
                                                      ((INSTANCE) == USART3) || \
                                                      ((INSTANCE) == UART4)  || \
                                                      ((INSTANCE) == UART5))

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2) || \
                                           ((INSTANCE) == USART3))

/****************** UART Instances : Auto Baud Rate detection *****************/
#define IS_UART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                           ((INSTANCE) == USART2) || \
                                                           ((INSTANCE) == USART3))

/****************** UART Instances : Driver Enable ****************************/
#define IS_UART_DRIVER_ENABLE_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                                  ((INSTANCE) == USART2) || \
                                                  ((INSTANCE) == USART3))

/********************* UART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2) || \
                                         ((INSTANCE) == USART3))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2) || \
                                    ((INSTANCE) == USART3) || \
                                    ((INSTANCE) == UART4)  || \
                                    ((INSTANCE) == UART5))

/******************** UART Instances : Support of continuous communication using DMA ****/
#define IS_UART_DMA_INSTANCE(INSTANCE) (1)

/****************************** USB Instances *********************************/
#define IS_USB_ALL_INSTANCE(INSTANCE) ((INSTANCE) == USB)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDG)

/**
  * @}
  */


/******************************************************************************/
/*  For a painless codes migration between the STM32F3xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */ 
/*  product lines within the same STM32F3 Family                              */
/******************************************************************************/

/* Aliases for __IRQn */
#define ADC1_IRQn       ADC1_2_IRQn
#define SDADC1_IRQn     ADC4_IRQn
#define COMP1_2_IRQn    COMP1_2_3_IRQn
#define COMP2_IRQn      COMP1_2_3_IRQn
#define COMP_IRQn       COMP1_2_3_IRQn
#define COMP4_6_IRQn    COMP4_5_6_IRQn
#define TIM15_IRQn      TIM1_BRK_TIM15_IRQn
#define TIM18_DAC2_IRQn TIM1_CC_IRQn
#define TIM17_IRQn      TIM1_TRG_COM_TIM17_IRQn
#define TIM16_IRQn      TIM1_UP_TIM16_IRQn
#define TIM6_DAC1_IRQn  TIM6_DAC_IRQn
#define TIM7_DAC2_IRQn  TIM7_IRQn
#define TIM12_IRQn      TIM8_BRK_IRQn
#define TIM14_IRQn      TIM8_TRG_COM_IRQn
#define TIM13_IRQn      TIM8_UP_IRQn
#define CEC_IRQn        USBWakeUp_IRQn
#define USBWakeUp_IRQn  USBWakeUp_RMP_IRQn
#define CAN_TX_IRQn     USB_HP_CAN_TX_IRQn
#define CAN_RX0_IRQn    USB_LP_CAN_RX0_IRQn


/* Aliases for __IRQHandler */
#define ADC1_IRQHandler       ADC1_2_IRQHandler
#define SDADC1_IRQHandler     ADC4_IRQHandler
#define COMP1_2_IRQHandler    COMP1_2_3_IRQHandler
#define COMP2_IRQHandler      COMP1_2_3_IRQHandler
#define COMP_IRQHandler       COMP1_2_3_IRQHandler
#define COMP4_6_IRQHandler    COMP4_5_6_IRQHandler
#define TIM15_IRQHandler      TIM1_BRK_TIM15_IRQHandler
#define TIM18_DAC2_IRQHandler TIM1_CC_IRQHandler
#define TIM17_IRQHandler      TIM1_TRG_COM_TIM17_IRQHandler
#define TIM16_IRQHandler      TIM1_UP_TIM16_IRQHandler
#define TIM6_DAC1_IRQHandler  TIM6_DAC_IRQHandler
#define TIM7_DAC2_IRQHandler  TIM7_IRQHandler
#define TIM12_IRQHandler      TIM8_BRK_IRQHandler
#define TIM14_IRQHandler      TIM8_TRG_COM_IRQHandler
#define TIM13_IRQHandler      TIM8_UP_IRQHandler
#define CEC_IRQHandler        USBWakeUp_IRQHandler
#define USBWakeUp_IRQHandler  USBWakeUp_RMP_IRQHandler
#define CAN_TX_IRQHandler     USB_HP_CAN_TX_IRQHandler
#define CAN_RX0_IRQHandler    USB_LP_CAN_RX0_IRQHandler


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32F303xC_H */

/**
  * @}
  */

  /**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
