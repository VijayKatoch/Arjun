/*
 * pwm.c
 *
 * WiringPi based userspace driver.
 *
 * pwmFrequency in Hz = 19.2e6 Hz / pwmClock / pwmRange
 * e.g 50 Hz = 19.2e6 Hz / 1920 / 200
 *
 * pwmWrite (18, 15);  // 1.5 ms
 *
 * pwmClock = 1920 => clock divisor
 * pwmRange = 200 => 0.1 ms per unit
 * 50Hz ---> 20ms per cycle. 20ms / 200 units = 0.1ms per unit
 * Duty cycle = (0.1 / 20) * 100 = 0.5%
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include <wiringPi.h>

#include "pwm.h"

int init_pwm()
{
    return wiringPiSetup();
}

void pwm_set_output_pin(int pin)
{
    return pinMode (pin, PWM_OUTPUT);
}

void pwm_set_tone_output_pin(int pin)
{
    return pinMode (pin, PWM_TONE_OUTPUT);
}

void pwm_set_clock(int divisor)
{
    return pwmSetClock(divisor);
}

void pwm_set_range(unsigned int range)
{
    return pwmSetRange (range);
}

void pwm_write(int pin, int value)
{
    return pwmWrite (pin, value);
}

