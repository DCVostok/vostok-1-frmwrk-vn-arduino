# framework-k1921vk-arduino
This repo adds the support of [NIIET k1921vk MCUs](https://niiet.ru/product-category/chips/microcont/risc-32-bit/) in Arduino IDE and [PlatformIO](http://platformio.org).

# Usage with VS_Code+PlatformIO

1. [Install VS_Code](https://code.visualstudio.com/)  
2. [Install VS_Code+PlatformIO](https://docs.platformio.org/en/latest/integration/ide/vscode.html#ide-vscode)  
3. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:  
Note: Examples with platfromIO projects  you can find in [/examples/Platformio](https://github.com/kenny5660/framework-k1921vk-arduino/tree/master/examples/Platformio)
4. Click build button, Platform IO automatically download all the necessary components
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
Or you can use GUI
1. Open Platfrom IO menu in VS_Code
2. Create "New Project"
    * Name - Project name
    * Board - Vostok UNO-VN035
    * Framework - Arduino
3. Platform IO automatically download all the necessary components
4. Add upload option "upload_port = COM11" to [platformio.ini](http://docs.platformio.org/page/projectconf.html)

# Usage with ArduinoIDE

Coming soon!

# Tested arduino libs

|Library|Description|Result|Notes|
|---------|---------|------|-----|
|Servo|Built-in arduino Servo library|+|Any digital pin can be used. Max 16 servos|
|SPI|Built-in arduino SPI library|+|  |
|Wire|Built-in arduino I2c library|+|I2c bus is not working on Vostok UNO VN035, if slave devices is using additional pull-up resistors.  Solution: Remove pull-up resistors from slave devices|
|[NewPing](https://bitbucket.org/teckel12/arduino-new-ping/src/master/)|Library for ultrasonic sensor|+|[See example](https://github.com/kenny5660/framework-k1921vk-arduino/tree/master/examples/Platformio/NewPing)|
|[SD Library](https://www.arduino.cc/en/Reference/SD)|The SD library allows for reading from and writing to SD cards|+|[See example](https://github.com/kenny5660/framework-k1921vk-arduino/tree/master/examples/Platformio/SD_card)|
