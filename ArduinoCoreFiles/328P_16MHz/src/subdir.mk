################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/WInterrupts.c \
../src/hooks.c \
../src/wiring.c \
../src/wiring_analog.c \
../src/wiring_digital.c \
../src/wiring_pulse.c \
../src/wiring_shift.c 

CPP_SRCS += \
../src/CDC.cpp \
../src/HardwareSerial.cpp \
../src/HardwareSerial0.cpp \
../src/HardwareSerial1.cpp \
../src/HardwareSerial2.cpp \
../src/HardwareSerial3.cpp \
../src/IPAddress.cpp \
../src/PluggableUSB.cpp \
../src/Print.cpp \
../src/Stream.cpp \
../src/Tone.cpp \
../src/USBCore.cpp \
../src/WMath.cpp \
../src/WString.cpp \
../src/abi.cpp \
../src/main.cpp \
../src/new.cpp 

S_UPPER_SRCS += \
../src/wiring_pulse.S 

C_DEPS += \
./src/WInterrupts.d \
./src/hooks.d \
./src/wiring.d \
./src/wiring_analog.d \
./src/wiring_digital.d \
./src/wiring_pulse.d \
./src/wiring_shift.d 

OBJS += \
./src/CDC.o \
./src/HardwareSerial.o \
./src/HardwareSerial0.o \
./src/HardwareSerial1.o \
./src/HardwareSerial2.o \
./src/HardwareSerial3.o \
./src/IPAddress.o \
./src/PluggableUSB.o \
./src/Print.o \
./src/Stream.o \
./src/Tone.o \
./src/USBCore.o \
./src/WInterrupts.o \
./src/WMath.o \
./src/WString.o \
./src/abi.o \
./src/hooks.o \
./src/main.o \
./src/new.o \
./src/wiring.o \
./src/wiring_analog.o \
./src/wiring_digital.o \
./src/wiring_pulse.o \
./src/wiring_shift.o 

S_UPPER_DEPS += \
./src/wiring_pulse.d 

CPP_DEPS += \
./src/CDC.d \
./src/HardwareSerial.d \
./src/HardwareSerial0.d \
./src/HardwareSerial1.d \
./src/HardwareSerial2.d \
./src/HardwareSerial3.d \
./src/IPAddress.d \
./src/PluggableUSB.d \
./src/Print.d \
./src/Stream.d \
./src/Tone.d \
./src/USBCore.d \
./src/WMath.d \
./src/WString.d \
./src/abi.d \
./src/main.d \
./src/new.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\src" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\src" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -std=gnu99 -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g2 -gstabs -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


