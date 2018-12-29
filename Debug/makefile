################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/motor_control/subdir.mk
-include src/hal/raspberryPi/drivers/pwm/subdir.mk
-include src/hal/raspberryPi/drivers/gpio/subdir.mk
-include src/hal/raspberryPi/bsp/subdir.mk
-include src/hal/raspberryPi/subdir.mk
-include src/app/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	$(MAKE) --no-print-directory pre-build
	$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: PiTank

# Tool invocations
PiTank: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "PiTank" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) PiTank
	-@echo ' '

pre-build:
	-cp "../src/hal/raspberryPi/bsp/bsp.h" "../src/hal/raspberryPi/include"; cp "../src/hal/raspberryPi/drivers/"*/*.h "../src/hal/raspberryPi/include"; cp "../src/motor_control/motor_control.h" "../src/include";
	-@echo ' '

.PHONY: all clean dependents main-build pre-build

-include ../makefile.targets
