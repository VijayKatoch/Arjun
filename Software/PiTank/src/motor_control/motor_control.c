/*
 * motor_control.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include "motor_control.h"

motor_config_t motor_var;

void motor_config(motor_config_t *cfg)
{
    motor_var.pwmA = cfg->pwmA;
    motor_var.gpio = cfg->gpio;
}

int motor_init()
{
    int status = -1;

    status = motor_var.pwmA.pwm_init();
    if(0 > status) return status;

    status = motor_var.gpio.gpio_init();
    if(0 > status) return status;

    return status;
}

void motor_control_enable()
{
    motor_var.gpio.gpio_enable_motor_direction_control();
}

void motor_stop()
{
    motor_var.pwmA.pwm_write(0);
}

void motor_move_forward()
{
    motor_var.gpio.gpio_motor_turn_forward();
}

void motor_move_reverse()
{
    motor_var.gpio.gpio_motor_turn_reverse();
}

void motor_speed(int speed)
{
    motor_var.pwmA.pwm_write(speed);
}


