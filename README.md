
# Vostok k1921vk arduino
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/dcvostok/tool/vostok-1-frmwrk-vn-arduino.svg)](https://registry.platformio.org/tools/dcvostok/vostok-1-frmwrk-vn-arduino)
[![en](https://img.shields.io/badge/lang-en-red.svg)](README.md)
[![ru](https://img.shields.io/badge/lang-ru-green.svg)](README.ru.md)  


This repo adds the support of [NIIET k1921vk MCUs](https://niiet.ru/product-category/chips/microcont/risc-32-bit/) in Arduino IDE and [PlatformIO](http://platformio.org).

# Documentation
*  User guide [VOSTOK_UNO-VN035.pdf](doc/VOSTOK_UNO-VN035.pdf)
*  Circuit [VOSTOK_UNO-VN035_circuit.pdf](doc/VOSTOK_UNO-VN035_circuit.pdf)
*  [Activation of debugging via JTAG/SWD](doc/Activate_JTAG.md)

# Usage with ArduinoIDE
1. Install [arduino IDE](https://www.arduino.cc/en/software)
2. Open `File > Preferences`
3. Add this link in the "Additional Boards Managers URLs" field:
```
https://raw.githubusercontent.com/DCVostok/vostok-arduinoide-board-manager/main/package_vostok_index.json
```
4. Open `Tools > Board > Board Manager`
5. Choose Type: `Contributed`
6. Click `install` on `k1921vk MCU based boards`
# Usage with VS Code+PlatformIO
1. [Install VS Code](https://code.visualstudio.com/)  
2. [Install VS Code+PlatformIO](https://docs.platformio.org/en/latest/integration/ide/vscode.html#ide-vscode)
## GUI

1. Open Platform IO menu in VS Code
2. Create "New Project"
    * Name - Project name
    * Board - Vostok UNO-VN035
    * Framework - Arduino
3. Platform IO automatically download all the necessary components
4. Add upload option `upload_port = COM5` to [platformio.ini](http://docs.platformio.org/page/projectconf.html)
## Manual

1. Create PlatformIO project and configure [platformio.ini](http://docs.platformio.org/page/projectconf.html) file according to the example below.  
Note: You can use PlatformIO project example [Blink](examples/Platformio/Blink)

2. Wait until PlatformIO prepare project, Platform IO automatically download all the necessary components.

3. Click **PlatformIO:Build** button.  
Note 1: Russian or other unicode characters in the path to the project or platform io core may cause problems.  
## Example platformio.ini 
```ini
[env:Vostok_uno]
platform = k1921vk
board = vostok_uno_vn035
framework = arduino
upload_port = COM11
monitor_port = COM11
monitor_speed = 115200
...
```

## Example platformio.ini with last version from github
Note: On Windows requires an installed git. Github authorization may be requested.  
```ini
[env:Vostok_uno]
platform = k1921vk
board = vostok_uno_vn035
framework = arduino
upload_port = COM11
monitor_port = COM11
monitor_speed = 115200
platform_packages = vostok-1-frmwrk-vn-arduino @ https://github.com/DCVostok/vostok-1-frmwrk-vn-arduino#main
...
```

# Additional functions in arduino core
## analogReadResolution
Set resolution for ADC and `analogRead` function. Default resolution is 10 bit (0-1023). Max resolution is 12 bit (0 - 4095).  
`res` - resolution in bits.

```
void analogReadResolution(int res)
```

## analogWriteResolution
Set resolution for PWM and `analogWrite` function. Default resolution is 8 bit (0-255). Max resolution is 10 bit (0 - 1023).  
`res` - resolution in bits.

```
void analogWriteResolution(int res)
```

## analogWriteFrequency
Set frequency of PWM for `analogWrite` function. Default freq is E_ANALOG_WRITE_FREQ_1K_Hz (1000 Hz).  
`freq` - frequency from enum eAnalogWriteFreq

```
typedef enum { // CLKDIV|HSPCLKDIV
  E_ANALOG_WRITE_FREQ_54_Hz  , // real freq 54 Hz
  E_ANALOG_WRITE_FREQ_508_Hz , // real freq 508 Hz
  E_ANALOG_WRITE_FREQ_1K_Hz  , // real freq 1017 Hz
  E_ANALOG_WRITE_FREQ_97K_Hz , // real freq 97656 Hz
  E_ANALOG_WRITE_FREQ_49K_Hz , // real freq 48828 Hz
  E_ANALOG_WRITE_FREQ_24K_Hz , // real freq 24414 Hz
  E_ANALOG_WRITE_FREQ_12K_Hz , // real freq 12207 Hz
  E_ANALOG_WRITE_FREQ_6K_Hz  , // real freq 6103 Hz
  E_ANALOG_WRITE_FREQ_3K_Hz  , // real freq 3051 Hz
  E_ANALOG_WRITE_FREQ_10K_Hz , // real freq 9765 Hz
  E_ANALOG_WRITE_FREQ_8K_Hz  , // real freq 8138 Hz
  E_ANALOG_WRITE_FREQ_7K_Hz  , // real freq 6975 Hz
} eAnalogWriteFreq;
```

```
void analogWriteFrequency(eAnalogWriteFreq freq)
```

# Tested arduino libs

|Library|Description|Result|Notes|
|---------|---------|------|-----|
|Servo|Built-in arduino `Servo` library|+|Any digital pin can be used. Max 16 servos|
|SPI|Built-in arduino `SPI` library|+|  |
|TimerOne|Built-in `TMR1` interrupt library|+|TMR1 is used. See [TimerOne readme.md](libraries/TimerOne/readme.md)|
|TimerZero|Built-in `TMR0` interrupt library|+|TMR0 is used. See [TimerZero readme.md](libraries/TimerZero/readme.md)|
|Wire|Built-in arduino `I2c` library|+||
|[NewPing](https://bitbucket.org/teckel12/arduino-new-ping/src/master/)|Library for ultrasonic sensor|v1.9.4|[See example](examples/Platformio/NewPing)|
|[SD Library](https://www.arduino.cc/en/Reference/SD)|The SD library allows for reading from and writing to `SD` cards|v1.2.4|[See example](examples/Platformio/SD_card)|
|[MPU6050](https://github.com/electroniccats/mpu6050)|`MPU-6050` 6-axis accelerometer/gyroscope Arduino Library.|v0.5.0|  |
|[Adafruit_ADXL343](https://github.com/adafruit/Adafruit_ADXL343)|This driver is for the [Adafruit ADXL343 Breakout](http://www.adafruit.com/products/), and is based on [Adafruit's Unified Sensor Library](https://github.com/adafruit/Adafruit_Sensor).|v1.6.2|  |
|[BME280](https://github.com/finitespace/BME280)|Provides an Arduino library for reading and interpreting Bosch BME280 data over `I2C`, `SPI` or `Sw SPI`.|v3.0.0|  |
|[LCD_I2C](https://github.com/blackhack/LCD_I2C)|This is fast Arduino library for LCD `HD44780` and its clones. It works in 4-bit mode via `I²C` bus with 8-bit `PCF8574/PCF8574A` I/O expander.|v2.3.0|  |


# Pinout Vostok UNO-VN035
![Pinout Vostok UNO-VN035](doc/Pinout_VostokUnoVN035.png)
