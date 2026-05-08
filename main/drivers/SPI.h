/*
 * SPI.h
 *
 *  Created on: 07.05.2026
 *      Author: nikol
 */

#ifndef MAIN_DRIVERS_SPI_H_
#define MAIN_DRIVERS_SPI_H_
#include <stdint.h>

#define SPI_MAX_TX_BUFFER_SIZE 4092 // https://docs.espressif.com/projects/esp-idf/en/v6.0.1/esp32c6/api-reference/peripherals/spi_master.html#_CPPv4N16spi_bus_config_t15max_transfer_szE

enum Device {
  LCD,
  BME
};

void init_SPI();
//void spi_send(uint8_t byte);
//void spi_transmit(uint8_t* buffer, int32_t bytes);
//uint8_t spi_write_read(uint8_t data);
//uint8_t* spi_trancive_burst(uint8_t address, uint8_t length);
//void spi_transmit_bme(uint8_t* buffer, int32_t bytes);

void spi_send(uint8_t* p_buffer, int32_t number_bytes, enum Device device);
uint8_t* spi_send_receive(const uint8_t* const p_buffer, int32_t number_bytes, enum Device device);


#endif /* MAIN_DRIVERS_SPI_H_ */
