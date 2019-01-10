################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal/raspberryPi/raspi_hal.c 

OBJS += \
./src/hal/raspberryPi/raspi_hal.o 

C_DEPS += \
./src/hal/raspberryPi/raspi_hal.d 


# Each subdirectory must supply rules for building sources it contributes
src/hal/raspberryPi/%.o: ../src/hal/raspberryPi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I../src/include -I../src/hal/raspberryPi/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


