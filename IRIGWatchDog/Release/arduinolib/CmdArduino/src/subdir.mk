################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arduinolib/CmdArduino/src/Cmd.cpp 

OBJS += \
./arduinolib/CmdArduino/src/Cmd.o 

CPP_DEPS += \
./arduinolib/CmdArduino/src/Cmd.d 


# Each subdirectory must supply rules for building sources it contributes
arduinolib/CmdArduino/src/%.o: ../arduinolib/CmdArduino/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -x c++ -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\EEPROM\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\NetEEPROM\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\SPI\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\CmdArduino\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\Ethernet\src" -I"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\lib" -DARDUINO=22 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


