/*
 *  hw.h
 *
 *  Created on: Jan 10, 2019
 *      Author: Vijay Katoch
 */

#ifndef STACK_HW_H_
#define STACK_HW_H_

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
 * App configuration
 *
 */

typedef struct
{
    int     (* pwm_init)(void);
    int     (* gpio_init)(void);
}hw_api_t;

typedef struct
{
    hw_api_t   hwA;
}hw_config_t;

/*
 * Hardware configuration
 * hw configuration by a particular HAL implementation
 * These api's are used by HAL
 */

void hw_config(hw_config_t *hw_cfg);

/*
 * App Interface
 * Application should use these apis to
 * initialize hardware
 *
 */

int hardware_init();

#endif /* STACK_HW_H_ */
