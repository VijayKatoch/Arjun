/*
 * turret_control.c
 *
 *  Created on: Jan 11, 2019
 *      Author: Vijay Katoch
 */

#include "turret_control.h"

turret_config_t turret_var;

/*
 * Turret configuration
 * turret configuration by a particular HAL implementation
 * turret_config() api is used by HAL
 */

void turret_config(turret_config_t *cfg)
{
    turret_var.turret = cfg->turret;
}

/*
 * App Turret Control Interface
 * Application should use below apis
 *
 */

void turret_dir_ctl_enable()
{
    turret_var.turret.gpio_turret_dir_ctl_enable();
}

void turret_mv_clockwise()
{
    turret_var.turret.gpio_turret_mv_clockwise();
}

void turret_mv_anticlockwise()
{
    turret_var.turret.gpio_turret_mv_anticlockwise();
}
