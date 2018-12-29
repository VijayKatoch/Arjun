/*
 * gpio.c
 *
 * WiringPi based userspace driver.
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#include <wiringPi.h>

int init_gpio()
{
    return wiringPiSetupGpio();     /* FixMe: Initialize WiringPi only Once */
}

void gpio_set_output_pin(int pin)
{
    return pinMode (pin, OUTPUT);
}

void gpio_set_input_pin(int pin)
{
    return pinMode (pin, INPUT);
}

void gpio_write(int pin, int value)
{
    return pwmWrite (pin, value);
}
