/*
 * bsp.c
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#include <pwm.h>
#include <gpio.h>
#include "bsp.h"

/*
 *Hardware PWM configuration for Raspberry Pi 3 Model B Ver 1.2
 */

/*
 * PWM
 */

int bsp_init_pwm()
{
    int status = -1;

    status = init_pwm();
    return status;
}

void bsp_setup_pwm1()
{
    pwm_set_output_pin(PWM1_SET_PIN);
    pwm_set_clock(PWM1_SET_CLOCK);
    pwm_set_range(PWM1_SET_RANGE);
}

void bsp_pwm1_write(int dutyCycle)
{
    int value = dutyCycle * PWM1_DUTY_CYCLE_FACTOR;
    pwm_write(PWM1_SET_PIN, value);
}

void bsp_setup_pwm2()
{
    pwm_set_output_pin(PWM2_SET_PIN);
    pwm_set_clock(PWM2_SET_CLOCK);
    pwm_set_range(PWM2_SET_RANGE);
}

void bsp_pwm2_write(int dutyCycle)
{
    int value = dutyCycle * PWM2_DUTY_CYCLE_FACTOR;
    pwm_write(PWM2_SET_PIN, value);
}

/*
 * GPIO
 */

int bsp_init_gpio()
{
    int status = -1;

    status = init_gpio();
    if(0 > status) return status;

    return status;
}

void bsp_set_gpio_output_pin(int pin)
{
    gpio_set_output_pin(pin);
}

void bsp_set_gpio_input_pin(int pin)
{
    gpio_set_input_pin(pin);
}

void bsp_gpio_write(int pin, int value)
{
    gpio_write(pin, value);
}

void bsp_gpio_mtr1_dir_ctl_enable()
{
    gpio_set_output_pin(GPIO_MOTOR1_FWD_PIN);
    gpio_set_output_pin(GPIO_MOTOR1_REV_PIN);
}
void bsp_gpio_mtr1_turn_fwd()
{
    gpio_write(GPIO_MOTOR1_FWD_PIN, 1);
    gpio_write(GPIO_MOTOR1_REV_PIN, 0);
}

void bsp_gpio_mtr1_turn_rev()
{
    gpio_write(GPIO_MOTOR1_FWD_PIN, 0);
    gpio_write(GPIO_MOTOR1_REV_PIN, 1);
}

void bsp_gpio_mtr2_dir_ctl_enable()
{
    gpio_set_output_pin(GPIO_MOTOR2_FWD_PIN);
    gpio_set_output_pin(GPIO_MOTOR2_REV_PIN);
}
void bsp_gpio_mtr2_turn_fwd()
{
    gpio_write(GPIO_MOTOR2_FWD_PIN, 1);
    gpio_write(GPIO_MOTOR2_REV_PIN, 0);
}

void bsp_gpio_mtr2_turn_rev()
{
    gpio_write(GPIO_MOTOR2_FWD_PIN, 0);
    gpio_write(GPIO_MOTOR2_REV_PIN, 1);
}


