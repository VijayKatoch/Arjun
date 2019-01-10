/*
 * motor_control.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include "motor_control.h"

motor_config_t motor_var;

/*
 * Motor configuration
 * motor configuration by a particular HAL implementation
 * motor_config() api is used by HAL
 */

void motor_config(motor_config_t *cfg)
{
    motor_var.pwmA = cfg->pwmA;
    motor_var.gpio = cfg->gpio;
}

/*
 * App Motor Control Interface
 * Application should use below apis
 *
 */

/*
 * Motor1
 */

void motor1_setup()
{
    motor_var.pwmA.pwm1_setup();
    motor_var.pwmA.pwm1_mode_setup();
}

void motor1_control_enable()
{
    motor_var.gpio.gpio_enable_motor1_direction_control();
}

void motor1_stop()
{
    motor_var.gpio.gpio_motor1_stop();
}

void motor1_move_forward()
{
    motor_var.gpio.gpio_motor1_turn_forward();
}

void motor1_move_reverse()
{
    motor_var.gpio.gpio_motor1_turn_reverse();
}

void motor1_speed(int speed)
{
    motor_var.pwmA.pwm1_write(speed);
}

/*
 * Motor2
 */

void motor2_setup()
{
    motor_var.pwmA.pwm2_setup();
    motor_var.pwmA.pwm2_mode_setup();
}

void motor2_control_enable()
{
    motor_var.gpio.gpio_enable_motor2_direction_control();
}

void motor2_stop()
{
    motor_var.gpio.gpio_motor2_stop();
}

void motor2_move_forward()
{
    motor_var.gpio.gpio_motor2_turn_forward();
}

void motor2_move_reverse()
{
    motor_var.gpio.gpio_motor2_turn_reverse();
}

void motor2_speed(int speed)
{
    motor_var.pwmA.pwm2_write(speed);
}


