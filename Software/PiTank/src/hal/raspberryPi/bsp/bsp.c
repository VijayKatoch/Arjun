/*
 * bsp.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include <pwm.h>

#include "bsp.h"

/*
 *Hardware PWM configuration for Raspberry Pi 3 Model B Ver 1.2
 */

int bsp_init_pwm1()
{
    int status = -1;

    status = init_pwm();
    if(0 > status) return status;

    pwm_set_output_pin(PWM1_SET_PIN);
    pwm_set_clock(PWM1_SET_CLOCK);
    pwm_set_range(PWM1_SET_RANGE);

    return status;
}

void bsp_pwm1_write(int dutyCycle)
{
    int value = dutyCycle * PWM1_DUTY_CYCLE_FACTOR;
    pwm_write(PWM1_SET_PIN, value);
}


