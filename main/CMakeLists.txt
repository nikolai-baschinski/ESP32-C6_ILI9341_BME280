# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS main.c bme/bme.c bme/I2C.c lcd/GUI_Paint.c lcd/lcd.c Fonts/font8.c Fonts/font12.c Fonts/font16.c Fonts/font20.c Fonts/font24.c      # list the source files of this component
    INCLUDE_DIRS bme lcd Fonts     # optional, add here public include directories
    PRIV_INCLUDE_DIRS   # optional, add here private include directories
    REQUIRES esp_driver_i2c esp_driver_gpio esp_driver_spi    # optional, list the public requirements (component names)
    PRIV_REQUIRES       # optional, list the private requirements
)
