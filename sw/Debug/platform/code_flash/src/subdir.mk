################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/code_flash/src/code_flash.c 

OBJS += \
./platform/code_flash/src/code_flash.o 

C_DEPS += \
./platform/code_flash/src/code_flash.d 


# Each subdirectory must supply rules for building sources it contributes
platform/code_flash/src/%.o: ../platform/code_flash/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/platform/hdr" -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/drv/hdr" -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/myLib/hdr" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


