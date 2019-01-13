/*
 * turret_control.h
 *
 *  Created on: Jan 11, 2019
 *      Author: Vijay Katoch
 */

#ifndef STACK_TURRET_CONTROL_H_
#define STACK_TURRET_CONTROL_H_

typedef struct
{
    void     (* gpio_turret_dir_ctl_enable)(void);
    void     (* gpio_turret_mv_clockwise)(void);
    void     (* gpio_turret_mv_anticlockwise)(void);
}turret_api_t;

typedef struct
{
    turret_api_t   turret;
}turret_config_t;

/*
 * Turret configuration
 * turret configuration by a particular HAL implementation
 * These api's are used by HAL
 */

void turret_config(turret_config_t *cfg);

/*
 * App Turret Control Interface
 * Application should use these apis
 *
 */
void turret_dir_ctl_enable();
void turret_mv_clockwise();
void turret_mv_anticlockwise();

#endif /* STACK_TURRET_CONTROL_H_ */
