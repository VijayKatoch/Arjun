/*
 * motor_control.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#ifndef APP_MOTOR_CONTROL_H_
#define APP_MOTOR_CONTROL_H_

typedef struct
{
    int (* pwm_init)(void);
    void(* pwm_write)(int);
}pwm_api_t;

typedef struct
{
    pwm_api_t pwmA;
}motor_config_t;

/*
 * Motor configuration
 * motor configuration by a particular HAL implementation
 * These api's are used by HAL
 */

void motor_config(motor_config_t *cfg);

/*
 * HAL Interface
 * The HAL interface is implemented by different HAL
 * Application uses these interfaces
 */

/*
 * Initialize HAL
 * Add hal_init() apis for different HAL here
 */

extern void hal_init_raspberryPi();


/*
 * App Motor Control Interface
 * Application should use these apis
 *
 */

int motor_init();

#endif /* APP_MOTOR_CONTROL_H_ */
