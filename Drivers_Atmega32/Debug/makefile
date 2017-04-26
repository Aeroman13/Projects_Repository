################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Drivers_Atmega32.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Drivers_Atmega32.elf secondary-outputs

# Tool invocations
Drivers_Atmega32.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Drivers_Atmega32.map -mmcu=atmega16 -o "Drivers_Atmega32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Drivers_Atmega32.lss: Drivers_Atmega32.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Drivers_Atmega32.elf  >"Drivers_Atmega32.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Drivers_Atmega32.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Drivers_Atmega32.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Drivers_Atmega32.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
