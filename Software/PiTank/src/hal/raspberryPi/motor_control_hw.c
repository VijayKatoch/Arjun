/*
 * motor_control_hw.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include <motor_control.h>
#include <bsp.h>


void hal_init_raspberryPi()
{
    static motor_config_t config =
    {
            .pwmA.pwm_init = bsp_init_pwm1,
            .pwmA.pwm_write = bsp_pwm1_write
    };

    motor_config(&config);
}
