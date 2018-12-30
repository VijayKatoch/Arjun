################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/motor_control/motor_control.c 

OBJS += \
./src/motor_control/motor_control.o 

C_DEPS += \
./src/motor_control/motor_control.d 


# Each subdirectory must supply rules for building sources it contributes
src/motor_control/%.o: ../src/motor_control/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I../src/include -I../src/hal/raspberryPi/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


