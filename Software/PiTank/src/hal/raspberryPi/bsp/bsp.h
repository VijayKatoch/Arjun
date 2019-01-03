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

#define PWM1_SET_PIN                    1           /*BCM 18*/  /* PWM1 Channel 1*/
#define PWM1_SET_CLOCK                  1920
#define PWM1_SET_RANGE                  200
#define PWM1_DUTY_CYCLE_FACTOR          2

#define PWM2_SET_PIN                    24           /*BCM 19*/ /* PWM0 Channel 0*/
#define PWM2_SET_CLOCK                  1920
#define PWM2_SET_RANGE                  200
#define PWM2_DUTY_CYCLE_FACTOR          2

#define GPIO_MOTOR1_FWD_PIN             4           /*BCM 23*/
#define GPIO_MOTOR1_REV_PIN             5           /*BCM 24*/

#define GPIO_MOTOR2_FWD_PIN             12          /*BCM 10*/
#define GPIO_MOTOR2_REV_PIN             13          /*BCM 9*/


/* PWM configuration
 *
 * Raspberry Pi PWM clock has a base frequency of 19.2 MHz.
 * This frequency, divided by the argument to pwmSetClock(),
 * and is the frequency at which the PWM counter is incremented.
 *
 * Valid range of PwmClock is 2 to 4095,
 * The valid range for pwmSetRange() is up to 4096
 *
 * pwmFrequency in Hz = 19.2e6 Hz / pwmClock / pwmRange
 * e.g 50 Hz = 19.2e6 Hz / 1920 / 200
 *
 * pwm Frequency with max clock and range values
 * e.g. 19.2e6 Hz / 4095 / 4096 = 1.14 Hz
 *
 * pwmClock = 1920 => clock divisor
 * pwmRange = 200 => 0.1 ms per unit
 * 50Hz ---> 20ms per cycle. 20ms / 200 units = 0.1ms per unit
 *
 * e.g for 15 units, ON time = 15 * 0.1 = 1.5 ms
 * Duty cycle = (1.5 / 20 ) * 100 = 7.5%
 * 100 units  =>  ON time = 100 * 0.1 ms = 10 ms = 50%
 *
 * Therefore PWM_DUTY_CYCLE_FACTOR = 2, to achieve 100%
 *
 * On bash shell test with
 *
 *  gpio mode 1 pwm
    gpio pwm-ms
    gpio pwmc 1920
    gpio pwmr 200

    gpio pwm 1 15   // => 1.5 ms
    gpio pwm 1 20   // => 2.0 ms
    gpio pwm 1 10   // => 1.0 ms
 *
 */

int     bsp_init_pwm();
void    bsp_set_pwm_mode_ms();
void    bsp_set_pwm_mode_balanced();

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
void    bsp_gpio_mtr1_stop();

void    bsp_gpio_mtr2_dir_ctl_enable();
void    bsp_gpio_mtr2_turn_fwd();
void    bsp_gpio_mtr2_turn_rev();
void    bsp_gpio_mtr2_stop();

#endif /* HAL_RASPBERRYPI_BSP_BSP_H_ */
