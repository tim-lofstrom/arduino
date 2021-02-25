################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arduinolib/Ethernet/src/Dhcp.cpp \
../arduinolib/Ethernet/src/Dns.cpp \
../arduinolib/Ethernet/src/Ethernet.cpp \
../arduinolib/Ethernet/src/EthernetClient.cpp \
../arduinolib/Ethernet/src/EthernetServer.cpp \
../arduinolib/Ethernet/src/EthernetUdp.cpp 

OBJS += \
./arduinolib/Ethernet/src/Dhcp.o \
./arduinolib/Ethernet/src/Dns.o \
./arduinolib/Ethernet/src/Ethernet.o \
./arduinolib/Ethernet/src/EthernetClient.o \
./arduinolib/Ethernet/src/EthernetServer.o \
./arduinolib/Ethernet/src/EthernetUdp.o 

CPP_DEPS += \
./arduinolib/Ethernet/src/Dhcp.d \
./arduinolib/Ethernet/src/Dns.d \
./arduinolib/Ethernet/src/Ethernet.d \
./arduinolib/Ethernet/src/EthernetClient.d \
./arduinolib/Ethernet/src/EthernetServer.d \
./arduinolib/Ethernet/src/EthernetUdp.d 


# Each subdirectory must supply rules for building sources it contributes
arduinolib/Ethernet/src/%.o: ../arduinolib/Ethernet/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -x c++ -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\EEPROM\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\NetEEPROM\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\SPI\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\CmdArduino\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\arduinolib\Ethernet\src" -I"C:\Users\tilo\workspace_arduino\ArduinoCoreFiles\src" -I"C:\Users\tilo\workspace_arduino\IRIGWatchDog\lib" -DARDUINO=22 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


