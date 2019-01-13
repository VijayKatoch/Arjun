################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/stack/hw.c \
../src/stack/motor_control.c \
../src/stack/turret_control.c 

OBJS += \
./src/stack/hw.o \
./src/stack/motor_control.o \
./src/stack/turret_control.o 

C_DEPS += \
./src/stack/hw.d \
./src/stack/motor_control.d \
./src/stack/turret_control.d 


# Each subdirectory must supply rules for building sources it contributes
src/stack/%.o: ../src/stack/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I../src/include -I../src/hal/raspberryPi/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


