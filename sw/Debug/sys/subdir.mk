################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sys/src.c 

OBJS += \
./sys/src.o 

C_DEPS += \
./sys/src.d 


# Each subdirectory must supply rules for building sources it contributes
sys/%.o: ../sys/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"C:/Users/MAHESH/Desktop/STM32_Project/Bootloader_V1/bootmanager_stm32f1x/sw" -I"C:/Users/MAHESH/Desktop/STM32_Project/Bootloader_V1/bootmanager_stm32f1x/sw/global" -I"C:/Users/MAHESH/Desktop/STM32_Project/Bootloader_V1/bootmanager_stm32f1x/sw/drv/hdr" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


