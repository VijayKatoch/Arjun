/*
 * motor_control_hw.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include <bsp.h>
#include <hw.h>
#include <motor_control.h>
#include <turret_control.h>


void hal_init_raspberryPi()
{
    static hw_config_t hw_cfg =
    {
        .hwA.pwm_init                              = bsp_init_pwm,
        .hwA.gpio_init                             = bsp_init_gpio
    };

    static motor_config_t motor_cfg =
    {
        .pwmA.pwm1_setup                            = bsp_setup_pwm1,
        .pwmA.pwm1_mode_setup                       = bsp_set_pwm_mode_ms,
        .pwmA.pwm1_write                            = bsp_pwm1_write,

        .pwmA.pwm2_setup                            = bsp_setup_pwm2,
        .pwmA.pwm2_mode_setup                       = bsp_set_pwm_mode_ms,
        .pwmA.pwm2_write                            = bsp_pwm2_write,

        .gpio.gpio_set_output_pin                   = bsp_set_gpio_output_pin,
        .gpio.gpio_set_input_pin                    = bsp_set_gpio_input_pin,
        .gpio.gpio_write                            = bsp_gpio_write,

        .gpio.gpio_enable_motor1_direction_control  = bsp_gpio_mtr1_dir_ctl_enable,
        .gpio.gpio_motor1_turn_forward              = bsp_gpio_mtr1_turn_fwd,
        .gpio.gpio_motor1_turn_reverse              = bsp_gpio_mtr1_turn_rev,
        .gpio.gpio_motor1_stop                      = bsp_gpio_mtr1_stop,

        .gpio.gpio_enable_motor2_direction_control  = bsp_gpio_mtr2_dir_ctl_enable,
        .gpio.gpio_motor2_turn_forward              = bsp_gpio_mtr2_turn_fwd,
        .gpio.gpio_motor2_turn_reverse              = bsp_gpio_mtr2_turn_rev,
        .gpio.gpio_motor2_stop                      = bsp_gpio_mtr2_stop
    };

    static turret_config_t turret_cfg =
    {
        .turret.gpio_turret_dir_ctl_enable          = bsp_gpio_turret_dir_ctl_enable,
        .turret.gpio_turret_mv_clockwise            = bsp_gpio_turret_mv_clockwise,
        .turret.gpio_turret_mv_anticlockwise        = bsp_gpio_turret_mv_anticlockwise
    };

    hw_config(&hw_cfg);
    motor_config(&motor_cfg);
    turret_config(&turret_cfg);
}
