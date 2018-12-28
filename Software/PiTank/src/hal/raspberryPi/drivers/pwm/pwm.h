/*
 * pwm.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#ifndef HAL_RASPBERRYPI_DRIVERS_PWM_PWM_H_
#define HAL_RASPBERRYPI_DRIVERS_PWM_PWM_H_

int init_pwm();

void pwm_set_output_pin(int pin);

void pwm_set_tone_output_pin(int pin);

void pwm_set_clock(int divisor);

void pwm_set_range(unsigned int range);

void pwm_write(int pin, int value);

#endif /* HAL_RASPBERRYPI_DRIVERS_PWM_PWM_H_ */
