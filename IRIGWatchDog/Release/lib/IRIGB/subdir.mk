################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/IRIGB/IRIGB.cpp 

OBJS += \
./lib/IRIGB/IRIGB.o 

CPP_DEPS += \
./lib/IRIGB/IRIGB.d 


# Each subdirectory must supply rules for building sources it contributes
lib/IRIGB/%.o: ../lib/IRIGB/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -x c++ -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\EEPROM\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\NetEEPROM\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\SPI\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\CmdArduino\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\Ethernet\src" -I"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\lib" -DARDUINO=22 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


