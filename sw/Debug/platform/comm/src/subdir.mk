################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/comm/src/comm.c 

OBJS += \
./platform/comm/src/comm.o 

C_DEPS += \
./platform/comm/src/comm.d 


# Each subdirectory must supply rules for building sources it contributes
platform/comm/src/%.o: ../platform/comm/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/platform/hdr" -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/drv/hdr" -I"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/myLib/hdr" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


