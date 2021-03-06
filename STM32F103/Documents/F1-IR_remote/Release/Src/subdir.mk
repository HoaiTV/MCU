################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c \
../Src/usb_device.c \
../Src/usbd_conf.c \
../Src/usbd_desc.c 

CPP_SRCS += \
../Src/IR.cpp \
../Src/kbd.cpp \
../Src/main.cpp 

OBJS += \
./Src/IR.o \
./Src/kbd.o \
./Src/main.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o \
./Src/usb_device.o \
./Src/usbd_conf.o \
./Src/usbd_desc.o 

C_DEPS += \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d \
./Src/usb_device.d \
./Src/usbd_conf.d \
./Src/usbd_desc.d 

CPP_DEPS += \
./Src/IR.d \
./Src/kbd.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/STM32F1xx_HAL_Driver/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/CMSIS/Include" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/STM32F1xx_HAL_Driver/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Drivers/CMSIS/Include" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"E:/stm32/Tutorial_Prototypes/F1-IR_remote/Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


