/*
 * hw.c
 *
 *  Created on: Jan 10, 2019
 *      Author: Vijay Katoch
 */

#include "hw.h"

hw_config_t hw_var;

void hw_config(hw_config_t *hw_cfg)
{
    hw_var.hwA = hw_cfg->hwA;
}

int hardware_init()
{
    int status = -1;

    status = hw_var.hwA.pwm_init();
    if(0 > status) return status;

    status = hw_var.hwA.gpio_init();
    if(0 > status) return status;

    return status;
}
