/*
 * app.c
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#include <motor_control.h>

void app_init()
{
    int status = -1;

    hal_init_raspberryPi();
    status = motor_init();
}
