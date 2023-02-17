# Activation of debugging via JTAG/SWD
[![en](https://img.shields.io/badge/lang-en-red.svg)](Activate_JTAG.md)
[![ru](https://img.shields.io/badge/lang-ru-green.svg)](Activate_JTAG.ru.md)  
Initially, the factory bootloader was loaded into VOSTOK UNO-VN035 and the JTAG/SWD connector was deactivated. In order to activate the JTAG/SWD connector, you need to perform a service full erase of the MCU memory. 
## Service full erase of the MCU memory
1. Connect ST-LINK to JTAG/SWD connector: SWDIO>SWDIO, SWCLK>SWCLK, GND>GND.
2. Connect VOSTOK UNO-VN035 to power supply via Vin or USB.
3. Open Platform IO example project [Blink](https://github.com/DCVostok/vostok-1-frmwrk-vn-arduino/tree/main/examples/Platformio/Blink)
4. Upload firmware `Blink` to MCU via bootloader, to check that everything is configured correctly.
5. Switch the MCU to service mode:
   1. Hold down the `RESET` button.
   2. Without releasing the `RESET` button, press and hold the `USER` button.
   3. Release the `RESET` button, keep holding the `USER` button.


5. Send cmd `srv_erase` via `platformio > project tasks > Vostok_uno > Custom > service_full_erase` or via shell ```pio run -t service_full_erase```.
6. Release the `USER` button, press `RESET` button once.
7. In the configuration file `platfromio.ini` enable firmware download via JTAG/SWD. To do this, add the line: `upload_protocol = stlink`.
8. Upload firmware `Blink` via JTAG/SWD.

### Notes:
1. Send cmd `srv_erase` from p.6 you can also use the utility [openocd-k1921](https://github.com/DCVostok/openocd-k1921vk)
```
openocd -f interface/stlink-v2.cfg -f target/k1921vk035.cfg -c "transport select hla_swd; init; reset init; flash probe 0; k1921vk035 srv_erase; exit"
```
1. After performing the procedure [Service full erase of the MCU memory](#Service-full-erase-of-the-MCU-memory), the factory bootloader will be erased. But you can download and use an open-source loader from the repository [bootloader-k1921vk035](https://github.com/DCVostok/bootloader-k1921vk035).