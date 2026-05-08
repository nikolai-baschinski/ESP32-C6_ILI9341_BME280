#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_log.h"
#include "SPI.h"

 // LCD SPI handle global
spi_device_handle_t lcd_spi;
spi_device_handle_t bme_spi;

#define SIZE_RECEIVE_BUFFER 9
uint8_t receive_buffer[SIZE_RECEIVE_BUFFER];

 void init_SPI()
 {
  esp_err_t rv;

  // 1. config the bus
  spi_bus_config_t spi_bus_cfg = {
    .mosi_io_num = GPIO_NUM_7,
    .miso_io_num = GPIO_NUM_4,
    .sclk_io_num = GPIO_NUM_6,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = SPI_MAX_TX_BUFFER_SIZE
  };

  rv = spi_bus_initialize(SPI2_HOST, &spi_bus_cfg, SPI_DMA_CH_AUTO);
  if (rv == ESP_OK) {
    ESP_LOGI("", "SPI bus initialization successfully");
  } else {
    ESP_LOGE("", "SPI bus initialization failed with %d", rv);
    while(1);
  }

  // 2. config the LCD device
  spi_device_interface_config_t devcfg_lcd = {
    .clock_speed_hz = 4 * 1000 * 1000,
    .mode = 0,
    .spics_io_num = GPIO_NUM_10, // CS Pin
    .queue_size = 1,
    .flags = 0,
    .command_bits = 0,
    .address_bits = 0,
    .dummy_bits = 0
  };
  rv = spi_bus_add_device(SPI2_HOST, &devcfg_lcd, &lcd_spi);
  if (rv == ESP_OK) {
    ESP_LOGI("", "SPI added device LCD successfully");
  } else {
    ESP_LOGE("", "SPI adding device LCD failed with %d", rv);
    while(1);
  }
  
  // 3. config the BME device
  spi_device_interface_config_t devcfg_bme = {
    .clock_speed_hz = 2 * 1000 * 1000,
    .mode = 0,
    .spics_io_num = GPIO_NUM_5, // CS Pin
    .queue_size = 1,
    .flags = 0,
    .command_bits = 0,
    .address_bits = 0,
    .dummy_bits = 0
  };
  rv = spi_bus_add_device(SPI2_HOST, &devcfg_bme, &bme_spi);
  if (rv == ESP_OK) {
    ESP_LOGI("", "SPI added device BME successfully");
  } else {
    ESP_LOGE("", "SPI adding device BME failed with %d", rv);
    while(1);
  }
}

void spi_send(uint8_t* p_buffer, int32_t number_bytes, enum Device device)
{
  spi_transaction_t t = {
    .length = number_bytes * 8,
    .tx_buffer = p_buffer,
    .rx_buffer = NULL
  };
  
  switch (device) {

    case LCD:
      spi_device_transmit(lcd_spi, &t);
      break;
    case BME:
      spi_device_transmit(bme_spi, &t);
    break;
    default:
      ESP_LOGE("", "Unknown SPI device");
      while(1);
      break;
  }
}

uint8_t* spi_send_receive(const uint8_t* const p_buffer, int32_t number_bytes, enum Device device)
{
  spi_transaction_t t = {
    .length = number_bytes * 8,
    .tx_buffer = p_buffer,
    .rx_buffer = receive_buffer
  };

  switch (device) {

    case LCD:
      spi_device_transmit(lcd_spi, &t);
      break;
    case BME:
      spi_device_transmit(bme_spi, &t);
    break;
    default:
      ESP_LOGE("", "Unknown SPI device");
      while(1);
      break;
  }
  
  return receive_buffer;
}