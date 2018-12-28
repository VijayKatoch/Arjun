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
}

int motor_init()
{
    int status = -1;

    status = motor_var.pwmA.pwm_init();
    if(0 > status) return status;


    return status;
}


