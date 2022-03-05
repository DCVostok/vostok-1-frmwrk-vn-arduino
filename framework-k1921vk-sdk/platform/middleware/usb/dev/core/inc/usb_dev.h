/*==============================================================================
 * Заголовочный файл для работы с USB Device.
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
#ifndef __USB_DEV_H
#define __USB_DEV_H

/* Includes ------------------------------------------------------------------*/
#include "usb_conf.h"
#include "usb_dev_descr.h"

/* Exported defines ----------------------------------------------------------*/
#define USB_MAX_EP0_SIZE 64

#define CEP_IRQ_STAT_SETUP_TOKEN   (1<<0)
#define CEP_IRQ_STAT_SETUP_PACKET  (1<<1)
#define CEP_IRQ_STAT_OUT_TOKEN     (1<<2)
#define CEP_IRQ_STAT_IN_TOKEN      (1<<3)
#define CEP_IRQ_STAT_PING_TOKEN    (1<<4)
#define CEP_IRQ_STAT_DATA_PACK_TX  (1<<5)
#define CEP_IRQ_STAT_DATA_PACK_RX  (1<<6)
#define CEP_IRQ_STAT_NAK_SENT      (1<<7)
#define CEP_IRQ_STAT_STALL_SENT    (1<<8)
#define CEP_IRQ_STAT_USB_ERROR     (1<<9)
#define CEP_IRQ_STAT_STAT_COMP     (1<<10)
#define CEP_IRQ_STAT_BUFF_FULL     (1<<11)
#define CEP_IRQ_STAT_BUFF_EMPTY    (1<<12)

#define EP_IRQ_STAT_BUFF_FULL      (1<<0)
#define EP_IRQ_STAT_BUFF_EMPTY     (1<<1)
#define EP_IRQ_STAT_SHORT_PKT_TX   (1<<2)
#define EP_IRQ_STAT_DATA_PKT_TX    (1<<3)
#define EP_IRQ_STAT_DATA_PKT_RX    (1<<4)
#define EP_IRQ_STAT_OUT_TOKEN      (1<<5)
#define EP_IRQ_STAT_IN_TOKEN       (1<<6)
#define EP_IRQ_STAT_PING_TOKEN     (1<<7)
#define EP_IRQ_STAT_NAK_SENT       (1<<8)
#define EP_IRQ_STAT_STALL_SENT     (1<<9)
#define EP_IRQ_STAT_NYET_SENT      (1<<10)
#define EP_IRQ_STAT_ERR_SENT       (1<<11)

#define USBDMA_OP_READ_FROM_EP     (0<<4)
#define USBDMA_OP_WRITE_TO_EP      (1<<4)
#define USBDMA_OP_START            (1<<5)
#define USBDMA_OP_MASK_DONE        (1<<5)

/* Exported types ------------------------------------------------------------*/
typedef enum
{
    USBDev_Attached = 1,
    USBDev_Powered,
    USBDev_Default,
    USBDev_Addressed,
    USBDev_Configured,
    USBDev_Suspended
} USBDev_State_TypeDef;

typedef enum
{
    USBDev_Speed_Full,
    USBDev_Speed_High
} USBDev_Speed_TypeDef;

typedef enum
{
    USBDev_SetupStage_Wait = 0,
    USBDev_SetupStage_Data,
    USBDev_SetupStage_Status
} USBDev_SetupStage_TypeDef;

typedef __PACKED_STRUCT
{
    uint8_t   bmRequestType;
    uint8_t   bRequest;
    uint16_t  wValue;
    uint16_t  wIndex;
    uint16_t  wLength;

    uint8_t   *xfer_buff;
    uint32_t  xfer_len;
    uint32_t  xfer_count;
    uint8_t   set_addr_active_flag; //TODO
    USBDev_SetupStage_TypeDef stage;
} USBDev_Setup_TypeDef;

typedef __PACKED_STRUCT
{
    uint8_t       bLength;
    uint8_t       bDescriptorType;
    uint8_t       bmAttributes;
} OTG_DSCR_TYPE;

typedef __PACKED_STRUCT
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bscUSB[2];
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint8_t idVendor[2];
    uint8_t idProduct[2];
    uint8_t bcdDevice[2];
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
} DEVICE_DSCR_TYPE;

//Configuration descriptor
typedef __PACKED_STRUCT
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t wTotalLength[2];
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttibutes;
    uint8_t MaxPower;
} CONFIGURATION_DSCR_TYPE;

//Interface Descriptor
typedef __PACKED_STRUCT
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bInterfaceNumber;
    uint8_t bAlternateSetting;
    uint8_t bNumEndpoints;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint8_t iInterface;
} INTERFACE_DSCR_TYPE;

//Endpoint Descriptor
typedef __PACKED_STRUCT
{
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
} ENDPOINT_DSCR_TYPE;

typedef __PACKED_STRUCT
{
    uint8_t   epnum;
    uint8_t   is_in;
    uint8_t   is_stall;
    uint8_t   type;
    uint32_t  max_packet;

    uint8_t   *xfer_buff;
    uint32_t  xfer_len;
    uint32_t  xfer_count;

    uint8_t   out_nak_active; //for out eps only
}USBDev_EP_TypeDef;

typedef enum
{
    CEP_ACK = 0,
    CEP_NAK = 1,
    CEP_STALL = 2,
    CEP_ZEROLEN = 4
}CEP_RESPONSE;

typedef enum
{
    EP_FLUSH = 0,
    EP_CLRNAK = 0,
    EP_CLRTOGGLE = 3,
    EP_HALT = 4,
    EP_ZEROLEN = 5,
    EP_PKTEND = 6,
    EP_SETNAK = 7
}EP_RESPONSE;

typedef struct
{
    uint32_t (*Init)(uint8_t config_num);
    uint32_t (*DeInit)(uint8_t config_num);
    uint32_t (*DataOut)(USBDev_EP_TypeDef *ep);
    uint32_t (*DataIn)(USBDev_EP_TypeDef *ep);
    uint32_t (*Setup)(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET);
    uint32_t (*SOF)(void);
    uint32_t (*EP0_RxReady)(void);
    uint32_t (*EP0_TxSent)(void);
    uint8_t *(*GetConfigDscr)(USBDev_Speed_TypeDef dev_speed, uint32_t *len);
} USBDev_ClassCB_TypeDef;

/* Exported function prototypes ----------------------------------------------*/
uint32_t USBDev_Init(void);
uint32_t USBDev_DeInit(void);

uint32_t USBDev_Ep_Handler(uint32_t epnum); //обработчик прерывания конечных точек
uint32_t USBDev_SOF_Handler(void);          //обработчик SOF прерывания
uint32_t USBDev_ResetDone(void);            //обработчик прерывания по сбросу линии USB
uint32_t USBDev_Resume(void);               //обработчик прерывания по запросу Resume
uint32_t USBDev_Suspend(void);              //обработчик прерывания по запросу Suspend
uint32_t USBDev_Disconnected(void);         //обработчик прерывания по отключению устройства

uint32_t USBDev_EP0Activate(void);
uint32_t USBDev_CEPSendResponse(CEP_RESPONSE resp);
uint32_t USBDev_PutNextCEPPacket(void);
uint32_t USBDev_GetNextCEPPacket(void);
uint32_t USBDev_CEPSendData(uint8_t *pbuf, uint32_t len);
uint32_t USBDev_SetSetupStage(USBDev_SetupStage_TypeDef stage);

uint32_t USBDev_EP_Open(uint8_t  ep_addr, uint32_t ep_mps, uint8_t  ep_type);
uint32_t USBDev_EP_Close(uint8_t ep_addr);
uint32_t USBDev_EPActivate(USBDev_EP_TypeDef *ep);     //for eps 1...4
uint32_t USBDev_EPDeactivate(USBDev_EP_TypeDef *ep);   //for eps 1...4
uint32_t USBDev_EP_AvailCnt(uint8_t epnum);    //for eps 1...4
uint32_t USBDev_EPSetResponse(EP_RESPONSE resp, uint8_t epnum); //for eps 1...4
uint32_t USBDev_EPSendData(uint8_t *pbuf, uint32_t len, uint8_t epnum);

USBDev_State_TypeDef USBDev_ReadState(void);

uint32_t USBDev_WritePacket(uint8_t *src, uint32_t len, uint8_t epnum);
uint32_t USBDev_ReadPacket(uint8_t *dst, uint32_t len, uint8_t epnum);

uint32_t USBDev_EPPrepareRx(uint8_t *pbuf, uint32_t len, uint8_t epnum);
uint32_t USBDev_ClassCbInit(USBDev_ClassCB_TypeDef *cb);

#endif /* __USB_DEV_H */
