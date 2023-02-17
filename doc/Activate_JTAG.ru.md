# Активация отладки через JTAG/SWD разьем
[![en](https://img.shields.io/badge/lang-en-red.svg)](Activate_JTAG.md)
[![ru](https://img.shields.io/badge/lang-ru-green.svg)](Activate_JTAG.ru.md)  
Изначально в VOSTOK UNO-VN035 загружен заводской bootloader и JTAG/SWD разьем деактивирован.
Для того чтобы активировать JTAG/SWD разьем нужно выполнить полное сервисное стирание памяти МК. 
## Полное сервисное стирание памяти МК
1. Подключить ST-LINK к сервисному разьему JTAG/SWD: SWDIO>SWDIO, SWCLK>SWCLK, GND>GND.
2. Подключить плату VOSTOK UNO-VN035 к источнику питания через Vin или USB.
3. Открыть в Platform IO пример проекта [Blink](https://github.com/DCVostok/vostok-1-frmwrk-vn-arduino/tree/main/examples/Platformio/Blink)
4. Загрузить прошивку `Blink` в МК через загрузчик, чтобы проверить, что все сконфигурировано верно.
5. Перевести МК в сервесный режим:
   1. Зажать кнопку `RESET`
   2. Не отпуская кнопку `RESET` нажать и удерживать кнопку `USER`
   3. Отпустить кнопку `RESET`, продолжать удерживать кнопку `USER`.


5. Отправить команду `srv_erase` с помощью  `platformio > project tasks > Vostok_uno > Custom > service_full_erase`. Или в консоли ```pio run -t service_full_erase```.
6. Отпустить кнопку `USER`, однократно нажать `RESET`.
7. В файле конфигурации `platfromio.ini` включить загрузку прошивки через JTAG/SWD. Для этого нужно добавить строчку: `upload_protocol = stlink`.
8. Загрузить прошивку `Blink` в МК уже через JTAG/SWD.

### Примечания:
1. Отправить команду `srv_erase` из п.6 также можно с помощью утилиты [openocd-k1921](https://github.com/DCVostok/openocd-k1921vk)
```
openocd -f interface/stlink-v2.cfg -f target/k1921vk035.cfg -c "transport select hla_swd; init; reset init; flash probe 0; k1921vk035 srv_erase; exit"
```
2. После выполнения процедуры "Полное сервисное стирание памяти МК" заводской загрузчик будет стерт. Но можно загрузить и использовать открытый загрузчик из репозитория [bootloader-k1921vk035](https://github.com/DCVostok/bootloader-k1921vk035).