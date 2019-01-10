/*
 * app.c
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#include<stdio.h>
#include <hw.h>
#include <motor_control.h>

#include "app_i.h"
#include "appErrorCodes_i.h"

void app_init()
{
    STATUS status = -1;

    hal_init_raspberryPi();
    status = hardware_init();
    if(OK != status)
        printf("Hardware init failed status %d\n", status);

    /*Setup motors*/
    motor1_setup();
    motor1_control_enable();

    motor2_setup();
    motor2_control_enable();
}

void handlePOSTRequest(POST_DATA *data)
{
    /*printf("Post Req %d %d\n", data->cmd, data->value);*/

    switch(data->cmd)
    {
        case forward:
            motor1_move_forward();
            motor2_move_forward();
            break;
        case reverse:
            motor1_move_reverse();
            motor2_move_reverse();
            break;
        case leftFwd:
            motor1_move_forward();
            motor2_stop();
            break;
        case rightFwd:
            motor2_move_forward();
            motor1_stop();
            break;
        case leftRev:
            motor1_move_reverse();
            motor2_stop();
            break;
        case rightRev:
            motor2_move_reverse();
            motor1_stop();
            break;
        case stop:
            motor1_stop();
            motor2_stop();
            break;
        case speed:
            motor1_speed(data->value);
            motor2_speed(data->value);
            break;
    }
}
