################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drv/core/src/core.c 

OBJS += \
./drv/core/src/core.o 

C_DEPS += \
./drv/core/src/core.d 


# Each subdirectory must supply rules for building sources it contributes
drv/core/src/%.o: ../drv/core/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw" -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/global" -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/drv/hdr" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

