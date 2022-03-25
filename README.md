# framework-k1921vk-arduino
This repo adds the support of [NIIET k1921vk MCUs](https://niiet.ru/product-category/chips/microcont/risc-32-bit/) in Arduino IDE and [PlatformIO](http://platformio.org).

# Usage with VS_Code+PlatformIO

1. [Install VS_Code](https://code.visualstudio.com/)  
2. [Install VS_Code+PlatformIO](https://docs.platformio.org/en/latest/integration/ide/vscode.html#ide-vscode)  
3. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:  
Note: You can use PlatformIO project example [Blink](examples/Platformio/Blink)
4. Wait until PlatformIO prepare project, Platform IO automatically download all the necessary components.
Note: On Windows requires an installed git. Github authorization may be requested.
5. Click **PlatfromIO:Build** button.
## Example platformio.ini 
```ini
[env:Vostok_uno]
platform = k1921vk
board = vostok_uno_vn035
framework = arduino
upload_port = COM11
monitor_port = COM11
monitor_speed = 115200
platform_packages = framework-k1921vk-arduino @ https://github.com/DCVostok/vostok-1-frmwrk-vn-arduino#main
...
```
Or you can use GUI (Not working yet)
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
|TimerOne|Built-in timer interrupt library|+|TMR1 is used. See [TimerOne readme.md](libraries/TimerOne/readme.md)|
|TimerZero|Built-in timer interrupt library|+|TMR0 is used. See [TimerZero readme.md](libraries/TimerZero/readme.md)|
|Wire|Built-in arduino I2c library|+|I2c bus is not working on Vostok UNO VN035, if slave devices is using additional pull-up resistors.  Solution: Remove pull-up resistors from slave devices|
|[NewPing](https://bitbucket.org/teckel12/arduino-new-ping/src/master/)|Library for ultrasonic sensor|+|[See example](examples/Platformio/NewPing)|
|[SD Library](https://www.arduino.cc/en/Reference/SD)|The SD library allows for reading from and writing to SD cards|+|[See example](examples/Platformio/SD_card)|
