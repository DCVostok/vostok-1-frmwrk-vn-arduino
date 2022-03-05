Установка микроконтроллеров К1921ВКx в J-Link
=========

Архив в этой папке содержит файлы, необходимые для того чтобы прошивать через JLink ([J-Link Software and Documentation pack](https://www.segger.com/downloads/jlink#J-LinkSoftwareAndDocumentationPack)) микроконтроллеры:

* К1921ВК01Т
* К1921ВК035
* К1921ВК028

Для установки необходимо распаковать архив в корневой каталог J-Link (например, c:\Program Files\SEGGER\JLink_V632d).
Далее в коневом каталоге необходимо открыть файл JLinkDevices.xml и внести в него строки из файла JLinkDevices.patch из SDK:


```
<DataBase>
   !!! ВСТАВИТЬ СОДЕРЖИМОЕ JLinkDevices.patch СЮДА !!!

  <!--                   -->
  <!-- Altera -->
  <!--                   -->
  <Device>
    <ChipInfo Vendor="Altera" Name="CYCLONE V"  Core="JLINK_CORE_CORTEX_A9" JLinkScriptFile="Devices/Altera/Cyclone_V/Altera_Cyclone_V.JLinkScript"/>
  </Device>
  <!--                   -->
  <!-- AmbiqMicro -->
  <!--                   -->
  <Device>
...  
```