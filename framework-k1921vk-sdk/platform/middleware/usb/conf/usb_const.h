/*==============================================================================
 * Файл констант USB
 *------------------------------------------------------------------------------
 * НИИЭТ, Дмитрий Сериков <lonie@niiet.ru>
 * НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_CONST_H
#define __USB_CONST_H

/* Exported defines ----------------------------------------------------------*/

#define USB_AUDIO_CLASS                             0x1
#define USB_CDC_CONTROL_CLASS                       0x2
#define USB_HID_CLASS                               0x3
#define USB_PHYSICAL_CLASS                          0x5
#define USB_IMAGE_CLASS                             0x6
#define USB_PRINTER_CLASS                           0x7
#define USB_MASS_STORAGE_CLASS                      0x8
#define USB_HUB_STORAGE_CLASS                       0x9
#define USB_CDC_DATA_CLASS                          0xa
#define USB_SMART_CARD_CLASS                        0xb
#define USB_CONTENT_SECURITY_CLASS                  0xd
#define USB_DIAGNOSTIC_DEVICE_CLASS                 0xdc
#define USB_WIRELESS_CONTROLLER_CLASS               0xe0
#define USB_APPLICATION_SPECIFIC_CLASS              0xfe
#define USB_VENDOR_SPECIFIC_CLASS                   0xff

#define USB_CONTROL_TRANSFER_TYPE                   0x0
#define USB_ISOC_TRANSFER_TYPE                      0x1
#define USB_BULK_TRANSFER_TYPE                      0x2
#define USB_INTERRUPT_TRANSFER_TYPE                 0x3

#define USB_GET_STATUS_REQUEST                      0
#define USB_CLEAR_FEATURE_REQUEST                   1
#define USB_SET_FEATURE_REQUEST                     3
#define USB_SET_ADDRESS_REQUEST                     5
#define USB_GET_DESCRIPTOR_REQUEST                  6
#define USB_SET_DESCRIPTOR_REQUEST                  7
#define USB_GET_CONFIGURATION_REQUEST               8
#define USB_SET_CONFIGURATION_REQUEST               9
#define USB_GET_INTERFACE_REQUEST                   10
#define USB_SET_INTERFACE_REQUEST                   11
#define USB_SYNCH_FRAME_REQUEST                     12

#define USB_DEV_DESCRIPTOR_TYPE                     1
#define USB_CONFIG_DESCRIPTOR_TYPE                  2
#define USB_STRING_DESCRIPTOR_TYPE                  3
#define USB_INTERFACE_DESCRIPTOR_TYPE               4
#define USB_ENDPOINT_DESCRIPTOR_TYPE                5

#define USB_DEVICE_DESCRIPTOR_TYPE_MASK             0x0100
#define USB_CONFIG_DESCRIPTOR_TYPE_MASK             0x0200
#define USB_STRING_DESCRIPTOR_TYPE_MASK             0x0300
#define USB_INTERFACE_DESCRIPTOR_TYPE_MASK          0x0400
#define USB_ENDPOINT_DESCRIPTOR_TYPE_MASK           0x0500
#define USB_OTG_DESCRIPTOR_TYPE_MASK                0x0900

#define USB_DESC_TYPE_DEVICE                        1
#define USB_DESC_TYPE_CONFIGURATION                 2
#define USB_DESC_TYPE_STRING                        3
#define USB_DESC_TYPE_INTERFACE                     4
#define USB_DESC_TYPE_ENDPOINT                      5
#define USB_DESC_TYPE_DEVICE_QUALIFIER              6
#define USB_DESC_TYPE_OTHER_SPEED_CONFIGURATION     7
#define USB_DESC_TYPE_OTG                           9

#define USBD_IDX_LANGID_STR                         0x00
#define USBD_IDX_MFC_STR                            0x01
#define USBD_IDX_PRODUCT_STR                        0x02
#define USBD_IDX_SERIAL_STR                         0x03
#define USBD_IDX_CONFIG_STR                         0x04
#define USBD_IDX_INTERFACE_STR                      0x05

#define USB_REQ_RECIPIENT_DEVICE    0x00
#define USB_REQ_RECIPIENT_INTERFACE 0x01
#define USB_REQ_RECIPIENT_ENDPOINT  0x02

#define USB_REQ_GET_STATUS        0x00
#define USB_REQ_CLEAR_FEATURE     0x01
#define USB_REQ_SET_FEATURE       0x03
#define USB_REQ_SET_ADDRESS       0x05
#define USB_REQ_GET_DESCRIPTOR    0x06
#define USB_REQ_SET_DESCRIPTOR    0x07
#define USB_REQ_GET_CONFIGURATION 0x08
#define USB_REQ_SET_CONFIGURATION 0x09
#define USB_REQ_GET_INTERFACE     0x0A
#define USB_REQ_SET_INTERFACE     0x0B
#define USB_REQ_SYNCH_FRAME       0x0C

#define USB_FEATURE_EP_HALT        0
#define USB_FEATURE_REMOTE_WAKEUP  1
#define USB_FEATURE_TEST_MODE      2

#define EP_IN 0x80
#define EP_OUT 0x00

#define EP_CONTROL 0x00
#define EP_ISO 0x01
#define EP_BULK 0x02
#define EP_INTERRUPT 0x03

#define EP_NOSYNC 0x00
#define EP_ASYNC  0x01
#define EP_ADAPT  0x02
#define EP_SYNC   0x03

#define EP_DATA     0x00
#define EP_FEEDBACK 0x01
#define EP_IMPLFBCK 0x02

#define USB_SELFPOWERED 0x40
#define USB_REMOTEWKUP  0x20

#endif /* __USB_CONST_H */
