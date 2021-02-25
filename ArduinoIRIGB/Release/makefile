################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lib/Net/subdir.mk
-include lib/IRIGB/subdir.mk
-include arduinolib/SPI/src/subdir.mk
-include arduinolib/NetEEPROM/src/subdir.mk
-include arduinolib/Ethernet/src/utility/subdir.mk
-include arduinolib/Ethernet/src/subdir.mk
-include Debug/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ArduinoIRIGB.lss \

FLASH_IMAGE += \
ArduinoIRIGB.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ArduinoIRIGB.elf secondary-outputs

# Tool invocations
ArduinoIRIGB.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,ArduinoIRIGB.map,--cref -mrelax -Wl,--gc-sections -L"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\328P_16MHz" -mmcu=atmega328p -o "ArduinoIRIGB.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ArduinoIRIGB.lss: ArduinoIRIGB.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ArduinoIRIGB.elf  >"ArduinoIRIGB.lss"
	@echo 'Finished building: $@'
	@echo ' '

ArduinoIRIGB.hex: ArduinoIRIGB.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ArduinoIRIGB.elf  "ArduinoIRIGB.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ArduinoIRIGB.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ArduinoIRIGB.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(PDE_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) ArduinoIRIGB.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
