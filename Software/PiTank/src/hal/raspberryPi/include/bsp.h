/*
 * bsp.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#ifndef HAL_RASPBERRYPI_BSP_BSP_H_
#define HAL_RASPBERRYPI_BSP_BSP_H_


/* Hardware PWM configuration for Raspberry Pi 3 Model B Ver 1.2
 *
 *pwmFrequency in Hz = 19.2e6 Hz / pwmClock / pwmRange
 * e.g 50 Hz = 19.2e6 Hz / 1920 / 200
 *
 * pwmClock = 1920 => clock divisor
 * pwmRange = 200 => 0.1 ms per unit
 * 50Hz ---> 20ms per cycle. 20ms / 200 units = 0.1ms per unit
 * Duty cycle = (0.1 / 20) * 100 = 0.5% per unit
 *
 * e.g for 15 units, on time = 15 * 0.1 = 1.5 ms
 * Duty cycle = (1.5 / 20 ) * 100 = 7.5%
 * PWM_DUTY_CYCLE_FACTOR = 20 / 100 =  0.2
 *
 */

#define PWM1_SET_PIN                     18
#define PWM1_SET_CLOCK                   1920
#define PWM1_SET_RANGE                   200
#define PWM1_DUTY_CYCLE_FACTOR           0.2

int bsp_init_pwm1();

void bsp_pwm1_write(int dutyCycle);


#endif /* HAL_RASPBERRYPI_BSP_BSP_H_ */
