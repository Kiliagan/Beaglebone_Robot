################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AStar.cpp \
../src/BeagleBoneCode.cpp \
../src/CentralHub.cpp \
../src/Client.cpp \
../src/DataKeeper.cpp \
../src/MotorManager.cpp \
../src/RoamingBot.cpp \
../src/SensorManager.cpp \
../src/Server.cpp 

OBJS += \
./src/AStar.o \
./src/BeagleBoneCode.o \
./src/CentralHub.o \
./src/Client.o \
./src/DataKeeper.o \
./src/MotorManager.o \
./src/RoamingBot.o \
./src/SensorManager.o \
./src/Server.o 

CPP_DEPS += \
./src/AStar.d \
./src/BeagleBoneCode.d \
./src/CentralHub.d \
./src/Client.d \
./src/DataKeeper.d \
./src/MotorManager.d \
./src/RoamingBot.d \
./src/SensorManager.d \
./src/Server.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


