#include <stdbool.h>
#include <unistd.h>
#include "esp_log.h"
#include "bme/bme.h"
#include "bme/I2C.h"
#include "lcd/lcd.h"
#include "ProcessImage.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

struct ProcessImage pi={0};

void app_main(void)
{
  init_I2C();
  init_BME();
  init_LCD();

  while(1) {
    cyclic_BME(&pi.bme280);
    cyclic_LCD(&pi);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
