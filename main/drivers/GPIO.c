#include "GPIO.h"

void init_GPIO()
{
  gpio_config_t io_conf = {
    .mode = GPIO_MODE_OUTPUT,
    .pin_bit_mask = (1ULL << LCD_RST) | (1ULL << LCD_DC)
  };
  gpio_config(&io_conf);

  gpio_set_level(LCD_RST, 1);
  gpio_set_level(LCD_DC, 1);
}