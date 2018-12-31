################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/app/app.c \
../src/app/httpUtil.c \
../src/app/requestHandler.c 

OBJS += \
./src/app/app.o \
./src/app/httpUtil.o \
./src/app/requestHandler.o 

C_DEPS += \
./src/app/app.d \
./src/app/httpUtil.d \
./src/app/requestHandler.d 


# Each subdirectory must supply rules for building sources it contributes
src/app/%.o: ../src/app/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I../src/include -I../src/hal/raspberryPi/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


