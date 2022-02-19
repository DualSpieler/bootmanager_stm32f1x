################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include sys/subdir.mk
-include startup/subdir.mk
-include drv/core/src/subdir.mk
-include drv/clock/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: bootmanager.elf

# Tool invocations
bootmanager.elf: $(OBJS) $(USER_OBJS) C:\Users\MAHESH\Desktop\STM32_Project\Bootloader_V1\bootmanager_stm32f1x\sw/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T"C:/Users/MAHESH/Desktop/STM32_Project/Bootloader_V1/bootmanager_stm32f1x/sw/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "bootmanager.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "bootmanager.elf" "bootmanager.bin"
	arm-none-eabi-size "bootmanager.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
