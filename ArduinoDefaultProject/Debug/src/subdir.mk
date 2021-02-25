################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp \
../src/main.cpp 

OBJS += \
./src/Test.o \
./src/main.o 

CPP_DEPS += \
./src/Test.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Users\tilo\workspace_arduino\ArduinoDefaultProject\src" -I"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\src" -I"C:\Users\tilo\workspace_arduino\ArduinoDefaultProject\arduinolib" -I"C:\Users\tilo\workspace_arduino\ArduinoDefaultProject\lib" -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


