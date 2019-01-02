/*
 * bsp.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Vijay Katoch
 */

#ifndef HAL_RASPBERRYPI_BSP_BSP_H_
#define HAL_RASPBERRYPI_BSP_BSP_H_

/*
 *  Hardware configuration for Raspberry Pi 3 Model B Ver 1.2
 *
 */

#define PWM1_SET_PIN                    1           /*BCM 18*/
#define PWM1_SET_CLOCK                  1920
#define PWM1_SET_RANGE                  200
#define PWM1_DUTY_CYCLE_FACTOR          0.2

#define PWM2_SET_PIN                    0           /*BCM 17*/
#define PWM2_SET_CLOCK                  1920
#define PWM2_SET_RANGE                  200
#define PWM2_DUTY_CYCLE_FACTOR          0.2

#define GPIO_MOTOR1_FWD_PIN             4           /*BCM 23*/
#define GPIO_MOTOR1_REV_PIN             5           /*BCM 24*/

#define GPIO_MOTOR2_FWD_PIN             12          /*BCM 10*/
#define GPIO_MOTOR2_REV_PIN             13          /*BCM 9*/


/* PWM configuration
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

int     bsp_init_pwm();

void    bsp_setup_pwm1();
void    bsp_pwm1_write(int dutyCycle);

void    bsp_setup_pwm2();
void    bsp_pwm2_write(int dutyCycle);

/*
 * GPIO configuration
 */

int     bsp_init_gpio();
void    bsp_set_gpio_output_pin(int pin);
void    bsp_set_gpio_input_pin(int pin);
void    bsp_gpio_write(int pin, int value);

void    bsp_gpio_mtr1_dir_ctl_enable();
void    bsp_gpio_mtr1_turn_fwd();
void    bsp_gpio_mtr1_turn_rev();

void    bsp_gpio_mtr2_dir_ctl_enable();
void    bsp_gpio_mtr2_turn_fwd();
void    bsp_gpio_mtr2_turn_rev();

#endif /* HAL_RASPBERRYPI_BSP_BSP_H_ */
