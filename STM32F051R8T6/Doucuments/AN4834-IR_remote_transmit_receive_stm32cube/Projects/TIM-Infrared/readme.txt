/**
  @page TIM_Infrared  Description of the TIM_Infrared example
  
  @verbatim
  ******************** (C) COPYRIGHT 2015 STMicroelectronics *******************
  * @file    TIM_Infrared/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    08-March-2016
  * @brief   Description of the TIM_Infrared example.
  ******************************************************************************
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
  @endverbatim

@par Firmware Description

This projects provides a reference implementation of an infra-red transmitter and receiver using the 
IRTIM feature available on selected STM32 microcontrollers.

This project is configured for STM32F373VC and STM32F303VC devices using STM32CubeF3 HAL and running
on STM32373C-EVAL or STM32303C-EVAL board from STMicroelectronics. 

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Directory contents 

  - TIM-Infrared/Src/main.c                 Main program
  - TIM-Infrared/Src/menu.c                 Menu navigation implementation
  - TIM-Infrared/Src/ir_common.c            Functions shared for both IR protocols.
  - TIM-Infrared/Src/rc5_decode.c           RC5 receiver implementation
  - TIM-Infrared/Src/sirc_decode.c          SIRC receiver implementation
  - TIM-Infrared/Src/rc5_encode.c           RC5 transmitter implementation
  - TIM-Infrared/Src/sirc_encode.c          SIRC transmitter implementation
  - TIM-Infrared/Src/system_stm32f3xx.c     STM32F3xx system clock configuration file
  - TIM-Infrared/Src/stm32f3xx_it.c         Interrupt handlers 
  - TIM-Infrared/Src/stm32f3xx_hal_msp.c    HAL MSP module
  - TIM-Infrared/Src/system_stm32f0xx.c     STM32F0xx system clock configuration file
  - TIM-Infrared/Src/stm32f0xx_it.c         Interrupt handlers 
  - TIM-Infrared/Src/stm32f0xx_hal_msp.c    HAL MSP module
  - TIM-Infrared/Inc/main.h                 Main program header file  
  - TIM-Infrared/Inc/menu.h                 Menu navigation header file  
  - TIM-Infrared/Inc/stm32f3xx_hal_conf.h   HAL Configuration file
  - TIM-Infrared/Inc/stm32f3xx_it.h         Interrupt handlers header file
  - TIM-Infrared/Inc/stm32f0xx_hal_conf.h   HAL Configuration file
  - TIM-Infrared/Inc/stm32f0xx_it.h         Interrupt handlers header file
  - TIM-Infrared/Inc/ir_common.h            Shared definitions
  - TIM-Infrared/Inc/rc5_decode.h           RC5 receiver header file
  - TIM-Infrared/Inc/sirc_decode.h          SIRC receiver header file
  - TIM-Infrared/Inc/rc5_encode.h           RC5 transmitter header file
  - TIM-Infrared/Inc/sirc_encode.h          SIRC transmitter header file
        
@par Hardware and Software environment  

  - This example runs on STM32F373VC, STM32F303VC and STM32F072VB devices.
    
  - This example has been tested with STMicroelectronics STM32373C-EVAL RevB, STM32303C-EVAL RevC and 
    STM32072B-EVAL boards and can be easily tailored to any other supported device and development
	board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain.
 - Rebuild all files and load your image into target memory.
 - Run the example.
 - Use the joystick to navigate the menu and select the options.
 - Best way to demonstrate the functionality is by using two EVAL boards, communicating with each other.

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
