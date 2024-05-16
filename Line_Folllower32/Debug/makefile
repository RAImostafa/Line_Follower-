################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER_COUNTER_V1/subdir.mk
-include MCAL/DIO_V1/subdir.mk
-include HAL/IR_Sensor_Handler/subdir.mk
-include HAL/DC_Motors_Handler/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Line_Folllower32.lss \

FLASH_IMAGE += \
Line_Folllower32.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Line_Folllower32.elf secondary-outputs

# Tool invocations
Line_Folllower32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Line_Folllower32.map -mmcu=atmega32 -o "Line_Folllower32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Line_Folllower32.lss: Line_Folllower32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Line_Folllower32.elf  >"Line_Folllower32.lss"
	@echo 'Finished building: $@'
	@echo ' '

Line_Folllower32.hex: Line_Folllower32.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Line_Folllower32.elf  "Line_Folllower32.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Line_Folllower32.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Line_Folllower32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Line_Folllower32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
