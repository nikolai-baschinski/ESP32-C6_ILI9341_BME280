BME280 data (temperature, air pressure and humidity) displayed on the Waveshare ILI9341 LCD by ESP32-C6-DevKitC-1 using Espressif IDE.

![BME280 and 2.4" LCD](/doc/Setup.jpg)

BME280, 2.4" LCD and the ESP32-C6-DevKitC-1

Connections (https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32c6/esp32-c6-devkitc-1/user_guide.html#getting-started)


| LCD Pin | ESP32-C6 GPIO | Function     |
| ------- | --------------| ------------ |
| VCC     | 3.3V          | Versorgung   |
| GND     | GND           | Masse        |
| DIN     | GPIO7         | MOSI         |
| CLK     | GPIO6         | SCLK         |
| CS      | GPIO10        | Chip Select  |
| DC      | GPIO2         | Data/Command |
| RST     | GPIO3         | Reset        |
| BL      | 3.3V          | Backlight    |



| BME280   | Port       | Function     |
|----------|------------|--------------|
| VCC      | 3,3V       | Vcc          |
| GND      | GND        | GND          |
| SCL      | GPIO4      | Clock        |
| SDA      | GPIO5      | Data         |
| ADDR     | not conn.  |              |
| CS       | 3,3V       | Vcc          |


Hardware
BME280: https://seengreat.com/product/207/bme280-environmental-sensor?srsltid=AfmBOorvlymsT9w0Ea-JBnftBbgADYcXMKpadnPHUyHl7X1wOO5TTgUa

LCD: https://www.waveshare.com/wiki/2.4inch_LCD_Module?srsltid=AfmBOoqtv3bq-mZfPtsi2BxiewwQnIkomXrloIzpVwGw_HnrOcmvQZar

ESP32-C6-DevKitC-1: https://www.reichelt.de/de/de/shop/produkt/entwicklungsboard_esp32-c6-wroom-1_u-380385



# **How to start**
1. git clone https://github.com/nikolai-baschinski/ESP32-C6_ILI9341_BME280.git
2. Open Espressif IDE
3. Open the project by File->Open Projects by File System.
4. Choose just the top most project
5. Select "Launch Mode" (e.g. Debug), "Launch Configuration" (e.g. ESP32-C6_ILI9341_BME280) and the target esp32c6.
6. Choose idf version 6.0 by Espressif->ESP-IDF Manager
7. Build
8. Launch

![](/doc/Import.png)


![](/doc/Launch.png)