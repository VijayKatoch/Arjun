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
    int     (* pwm_init)(void);
    void    (* pwm_write)(int);
}pwm_api_t;

typedef struct
{
    int     (* gpio_init)(void);
    void    (* gpio_set_output_pin)(int);
    void    (* gpio_set_input_pin)(int);
    void    (* gpio_write)(int, int);

    void    (* gpio_enable_motor_direction_control)(void);
    void    (* gpio_motor_turn_forward)(void);
    void    (* gpio_motor_turn_reverse)(void);
}gpio_api_t;

typedef struct
{
    pwm_api_t   pwmA;
    gpio_api_t  gpio;
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

void motor_control_enable();

void motor_stop();

void motor_move_forward();

void motor_move_reverse();

void motor_speed(int speed);


#endif /* APP_MOTOR_CONTROL_H_ */
