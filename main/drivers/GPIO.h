#include "driver/gpio.h"

#ifndef MAIN_DRIVERS_GPIO_H_
#define MAIN_DRIVERS_GPIO_H_

#define LCD_RST  GPIO_NUM_3
#define LCD_DC   GPIO_NUM_2

void init_GPIO();

#endif /* MAIN_DRIVERS_GPIO_H_ */
