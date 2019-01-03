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

    void    (* pwm1_setup)(void);
    void    (* pwm1_mode_setup)(void);
    void    (* pwm1_write)(int);

    void    (* pwm2_setup)(void);
    void    (* pwm2_mode_setup)(void);
    void    (* pwm2_write)(int);
}pwm_api_t;

typedef struct
{
    int     (* gpio_init)(void);
    void    (* gpio_set_output_pin)(int);
    void    (* gpio_set_input_pin)(int);
    void    (* gpio_write)(int, int);

    void    (* gpio_enable_motor1_direction_control)(void);
    void    (* gpio_motor1_turn_forward)(void);
    void    (* gpio_motor1_turn_reverse)(void);
    void    (* gpio_motor1_stop)(void);

    void    (* gpio_enable_motor2_direction_control)(void);
    void    (* gpio_motor2_turn_forward)(void);
    void    (* gpio_motor2_turn_reverse)(void);
    void    (* gpio_motor2_stop)(void);
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

void motor1_setup();
void motor1_control_enable();
void motor1_stop();
void motor1_move_forward();
void motor1_move_reverse();
void motor1_speed(int speed);

void motor2_setup();
void motor2_control_enable();
void motor2_stop();
void motor2_move_forward();
void motor2_move_reverse();
void motor2_speed(int speed);

#endif /* APP_MOTOR_CONTROL_H_ */
