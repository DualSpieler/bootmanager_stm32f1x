################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include platform/serial_interface/src/subdir.mk
-include platform/comm/src/subdir.mk
-include myLib/queue/src/subdir.mk
-include drv/uart/src/subdir.mk
-include drv/gpio/src/subdir.mk
-include drv/core/src/subdir.mk
-include drv/clock/src/subdir.mk
-include app/sys/src/subdir.mk
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
bootmanager.elf: $(OBJS) $(USER_OBJS) D:\CB\ Learning\Bootloader\git\bootmanager_stm32f1x\sw/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -T"D:/CB Learning/Bootloader/git/bootmanager_stm32f1x/sw/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "bootmanager.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
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
