/*
 * gpio.h
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#ifndef HAL_RASPBERRYPI_DRIVERS_GPIO_GPIO_H_
#define HAL_RASPBERRYPI_DRIVERS_GPIO_GPIO_H_

int init_gpio();

void gpio_set_output_pin(int pin);

void gpio_set_input_pin(int pin);

void gpio_write(int pin, int value);

#endif /* HAL_RASPBERRYPI_DRIVERS_GPIO_GPIO_H_ */
