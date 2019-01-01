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
        .pwmA.pwm_init      = bsp_init_pwm,

        .pwmA.pwm1_setup    = bsp_setup_pwm1,
        .pwmA.pwm1_write    = bsp_pwm1_write,

        .pwmA.pwm2_setup    = bsp_setup_pwm2,
        .pwmA.pwm2_write    = bsp_pwm2_write,

        .gpio.gpio_init = bsp_init_gpio,
        .gpio.gpio_set_output_pin = bsp_set_gpio_output_pin,
        .gpio.gpio_set_input_pin  = bsp_set_gpio_input_pin,
        .gpio.gpio_write  = bsp_gpio_write,

        .gpio.gpio_enable_motor1_direction_control = bsp_gpio_mtr1_dir_ctl_enable,
        .gpio.gpio_motor1_turn_forward = bsp_gpio_mtr1_turn_fwd,
        .gpio.gpio_motor1_turn_reverse = bsp_gpio_mtr1_turn_rev,

        .gpio.gpio_enable_motor2_direction_control = bsp_gpio_mtr2_dir_ctl_enable,
        .gpio.gpio_motor2_turn_forward = bsp_gpio_mtr2_turn_fwd,
        .gpio.gpio_motor2_turn_reverse = bsp_gpio_mtr2_turn_rev
    };

    motor_config(&config);
}
