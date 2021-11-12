/*==============================================================================
 * Файл с исходным кодом для работы с USB Device.
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

/* Includes ------------------------------------------------------------------*/
#include "usb_dev.h"

/* Private types -------------------------------------------------------------*/
typedef struct
{
    USBDev_State_TypeDef state;
    USBDev_Speed_TypeDef speed;
    uint8_t address;
    uint8_t config;
    uint32_t tmp_config_buf_start_address;

    USBDev_Setup_TypeDef USB_SETUP_PACKET;
    USBDev_EP_TypeDef in_ep[5];
    USBDev_EP_TypeDef out_ep[5];

    USBDev_ClassCB_TypeDef *class_cb;

}USBDev_TypeDef;

/* Private variables ---------------------------------------------------------*/
uint8_t ep0_buf[64];

USBDev_TypeDef USBDevice;

DEVICE_DSCR_TYPE device_dscr =
{
    sizeof(DEVICE_DSCR_TYPE),
    USB_DESC_TYPE_DEVICE,
    {
        LOBYTE(USB_BCD),
        HIBYTE(USB_BCD)
    },
    0x02,//USB_DEVICE_CLASS,//(CDC)
    0x00,//USB_DEVICE_SUBCLASS,
    0x00,//USB_DEVICE_PROTOCOL,
    USB_DEVICE_MAX_EP0_SIZE,
    {
        LOBYTE(USB_DEVICE_VENDOR_ID),
        HIBYTE(USB_DEVICE_VENDOR_ID)
    },
    {
        LOBYTE(USB_DEVICE_PRODUCT_ID),
        HIBYTE(USB_DEVICE_PRODUCT_ID)
    },
    {
        LOBYTE(USB_BCD_DEVICE),
        HIBYTE(USB_BCD_DEVICE)
    },
    USB_DEVICE_IDX_MFC_STR,
    USB_DEVICE_IDX_PRODUCT_STR,
    USB_DEVICE_IDX_SERIAL_STR,
    USB_DEVICE_CFG_MAX_NUM
};


/* Private functions prototypes ----------------------------------------------*/
uint32_t USBDev_EPIntEnable(uint8_t epnum);    //for eps 0...4
uint32_t USBDev_EPIntDisable(uint8_t epnum);   //for eps 0...4
uint32_t USBDev_DMAOpStart(uint8_t *pbuf, uint32_t len, uint8_t epnum, uint32_t op);
uint32_t USBDev_SetAddress(uint8_t address);

uint32_t USBDev_ParseSetupPacket(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET);
uint32_t USBD_Setup_Stage(void);
uint32_t USBD_StdDevReq(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET);
uint32_t USBD_StdItfReq(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET);
uint32_t USBD_GetDescriptorReq(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET);
uint32_t USBD_SetAddressReq(void);
uint32_t USBD_SetConfigReq(void);
uint32_t USBD_SetCfg(uint8_t config_num);
uint32_t USBD_ClrCfg(uint8_t config_num);

uint32_t get_string_to_unicode(char *desc, uint8_t *unicode);

uint32_t USBDev_GetEPIntStatus(uint8_t epnum); //for eps 0...4
uint32_t USBDev_ClearEPIntBit(uint8_t epnum, uint32_t ep_bit); //for eps 0...4
uint32_t USBDev_IsEPTypeIN(uint8_t epnum);     //for eps 0...4
uint32_t USBDev_SetOpSpeed(USBDev_Speed_TypeDef speed);


/* Private functions ---------------------------------------------------------*/
uint32_t USBDev_ParseSetupPacket(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET)
{
    pUSB_SETUP_PACKET->bmRequestType = (NT_USBDevice->CEP_SETUP1_0 & 0xff);
    pUSB_SETUP_PACKET->bRequest      = ((NT_USBDevice->CEP_SETUP1_0 >> 8) & 0xff);
    pUSB_SETUP_PACKET->wValue        = NT_USBDevice->CEP_SETUP3_2;
    pUSB_SETUP_PACKET->wIndex        = NT_USBDevice->CEP_SETUP5_4;
    pUSB_SETUP_PACKET->wLength       = NT_USBDevice->CEP_SETUP7_6;

    return 0;
}

uint32_t USBDev_Ep_Handler(uint32_t epnum)
{
    USBDev_EP_TypeDef *ep;
    //uint32_t len;
    //если управляющая точка
    if(epnum == 0)
    {
        //если преывание по приему setup пакета
        if(USBDev_GetEPIntStatus(epnum) & CEP_IRQ_STAT_SETUP_PACKET)
        {
            if(USBDevice.USB_SETUP_PACKET.stage == USBDev_SetupStage_Wait)
            {
                //сбросим бит прерывания
                USBDev_ClearEPIntBit(epnum, CEP_IRQ_STAT_SETUP_PACKET);
                //парсим пакет setup
                USBDev_ParseSetupPacket(&USBDevice.USB_SETUP_PACKET);
                //обрабатываем пакет
                USBD_Setup_Stage();
            }
        }

        if(USBDev_GetEPIntStatus(epnum) & CEP_IRQ_STAT_DATA_PACK_TX) //data transmitted
        {
            if(USBDevice.USB_SETUP_PACKET.stage == USBDev_SetupStage_Data)
            {
                //сбросим бит прерывания
                USBDev_ClearEPIntBit(epnum, CEP_IRQ_STAT_DATA_PACK_TX);

                if(USBDevice.USB_SETUP_PACKET.xfer_count >= USBDevice.USB_SETUP_PACKET.xfer_len)
                {
                    //USBDev_Class_EP0_TxSent();
                    USBDevice.class_cb->EP0_TxSent();
                    //send status
                    USBDev_CEPSendResponse(CEP_ACK);
                    USBDev_SetSetupStage(USBDev_SetupStage_Status);
                }
                else
                    USBDev_PutNextCEPPacket();
            }
        }

        if(USBDev_GetEPIntStatus(epnum) & CEP_IRQ_STAT_DATA_PACK_RX) //data received
        {
            if(USBDevice.USB_SETUP_PACKET.stage == USBDev_SetupStage_Data)
            {
                //сбросим бит прерывания
                USBDev_ClearEPIntBit(epnum, CEP_IRQ_STAT_DATA_PACK_RX);

                USBDev_GetNextCEPPacket();

                if(USBDevice.USB_SETUP_PACKET.xfer_count >= USBDevice.USB_SETUP_PACKET.xfer_len)
                {
                    USBDevice.class_cb->EP0_RxReady();
                    //send zerolen packet
                    USBDev_CEPSendResponse(CEP_ZEROLEN);
                    USBDev_SetSetupStage(USBDev_SetupStage_Status);
                }
            }
        }

        if(USBDev_GetEPIntStatus(epnum) & CEP_IRQ_STAT_USB_ERROR)
        {
            //сбросим бит прерывания
            USBDev_ClearEPIntBit(epnum, CEP_IRQ_STAT_USB_ERROR);
            // TODO
        }

        if(USBDev_GetEPIntStatus(epnum) & CEP_IRQ_STAT_STAT_COMP) //status completion
        {
            if(USBDevice.USB_SETUP_PACKET.stage == USBDev_SetupStage_Status)
            {
                //сбросим бит прерывания
                USBDev_ClearEPIntBit(epnum, CEP_IRQ_STAT_STAT_COMP);

                if(USBDevice.USB_SETUP_PACKET.set_addr_active_flag)
                {
                    //записываем новый адрес, выданный нам
                    USBDev_SetAddress(USBDevice.address);
                    USBDevice.USB_SETUP_PACKET.set_addr_active_flag = 0;
                }
                // разрешаем прием следующего setup пакета
                //USBDev_CEPSendResponse(CEP_ACK);
                USBDev_SetSetupStage(USBDev_SetupStage_Wait);
            }
        }
    }
    else //endpoints 1...4
    {
        //если точка IN
        if(USBDev_IsEPTypeIN(epnum) != 0)
        {
            ep = &USBDevice.in_ep[epnum];
            //обрабатываем прерывания
            if(USBDev_GetEPIntStatus(epnum) & EP_IRQ_STAT_DATA_PKT_TX) // прерывание по передаче пакета хосту
            {
                //сбрасываем прерывание
                USBDev_ClearEPIntBit(epnum, EP_IRQ_STAT_DATA_PKT_TX);
                //TODO
                USBDevice.class_cb->DataIn(ep);
            }
        }
        else //тогда точка OUT
        {
            ep = &USBDevice.out_ep[epnum];
            //обрабаываем прерывания
            if(USBDev_GetEPIntStatus(epnum) & EP_IRQ_STAT_DATA_PKT_RX) // прерывание по приему пакета от хоста
            {
                //ставим NAK на точку
                USBDev_EPSetResponse(EP_SETNAK,epnum);
                //отдаем данные на обработку уровня выше
                USBDevice.class_cb->DataOut(ep);
                //если данных в точке больше нет, то сбрасываем прерывание
                if(USBDev_EP_AvailCnt(epnum) == 0)
                {
                    USBDev_ClearEPIntBit(epnum, EP_IRQ_STAT_DATA_PKT_RX);
                    USBDev_EPSetResponse(EP_CLRNAK,epnum);
                }
            }
        }
    }

    return 0;
}

uint32_t USBDev_SOF_Handler(void)
{
    USBDevice.class_cb->SOF();
    return 0;
}

uint32_t USBDev_ResetDone(void)
{
    //настраиваем контрольную точку для приема управляющих посылок
    USBDev_EP0Activate();
    //переводим usb device в состояние DEFAULT
    USBDevice.state = USBDev_Default;
    USBDev_SetSetupStage(USBDev_SetupStage_Wait);
    USBDevice.USB_SETUP_PACKET.set_addr_active_flag = 0;
    return 0;
}

uint32_t USBDev_Resume(void)
{
    //выполняем пользовательский обработчик перехода в рабочее состояние
    //FUNC()

    //usbdev_state = USBDEV_CONFIGURED;

    return 0;
}

uint32_t USBDev_Suspend(void)
{
    //usbdev_state = USBDEV_SUSPENDED;

    //выполняем пользовательский обработчик перехода в SUSPEND
    //FUNC()

    return 0;
}

uint32_t USBDev_Disconnected(void)
{
    //выполняем обработку пользовательской части при отключении устройства от хоста
    //DEV_DISCONNECT();

    //выполняем деинициализацию устройства
    USBDevice.class_cb->DeInit(0/*confignum*/);

    return 0;
}

/*void set_usbdev_state(USBDEV_STATE state)
{
  USBDevice.state = state;
}*/

uint32_t USBD_Setup_Stage (void)
{
    //смотрим тип запроса
    switch(USBDevice.USB_SETUP_PACKET.bmRequestType & 0x60)
    {
    case 0x00: //STANDART REQUEST
        switch(USBDevice.USB_SETUP_PACKET.bmRequestType & 0x1f)
        {
        case USB_REQ_RECIPIENT_DEVICE:
            USBD_StdDevReq(&USBDevice.USB_SETUP_PACKET);
            break;
        case USB_REQ_RECIPIENT_INTERFACE:
            USBD_StdItfReq(&USBDevice.USB_SETUP_PACKET);
            break;
        case USB_REQ_RECIPIENT_ENDPOINT:
            USBDev_CEPSendResponse(CEP_STALL);
            break;
        default:
            USBDev_CEPSendResponse(CEP_STALL);
            break;
        }
        break;
    case 0x20: //CLASS SPECIFIC REQUEST
    case 0x40: //VENDOR SPECIFIC REQUEST
        USBDevice.class_cb->Setup(&USBDevice.USB_SETUP_PACKET);
        break;
    default:
        USBDev_CEPSendResponse(CEP_STALL);
        break;
    }

    return 0;
}

uint32_t USBDev_CEPSendResponse(CEP_RESPONSE resp)
{
    NT_USBDevice->CEP_CTRL_STAT = resp;
    return 0;
}

uint32_t USBDev_SetSetupStage(USBDev_SetupStage_TypeDef stage)
{
    USBDevice.USB_SETUP_PACKET.stage = stage;
    return 0;
}

uint32_t USBDev_EP0Activate(void)
{
    //настраиваем область USB RAM памяти для контрольной точки
    NT_USBDevice->CEP_START_ADDR = 0x00;
    NT_USBDevice->CEP_END_ADDR = NT_USBDevice->CEP_START_ADDR + USB_MAX_EP0_SIZE - 1;

    if(USBDevice.state == USBDev_Powered)
    {
        //настраиваем необходимые прерывания
        NT_USBDevice->CEP_IRQ_ENB |= (1<<1)|  // setup packet int (прерывание по приему setup пакета)
                (1<<5)|  // data packet transmitted
                (1<<6)|  // data packet received
                (1<<9)|  // USB error int (прерывание по ошибке передачи)
                (1<<10); // Status completion int (прерывание по завершению цикла управляющего трансфера)

        //разрешаем прерывание на контрольную точку
        NT_USBDevice->IRQ_ENB_L |= (1<<1);
    }
    else
    {
        //присваиваем адрес по-умолчанию
        NT_USBDevice->USB_ADDR = 0;
    }

    return 0;
}

uint32_t USBD_StdDevReq(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET)
{
    switch(pUSB_SETUP_PACKET->bRequest)
    {
    case USB_REQ_GET_DESCRIPTOR:
        USBD_GetDescriptorReq(pUSB_SETUP_PACKET);
        break;
    case USB_REQ_SET_ADDRESS:
        USBD_SetAddressReq();
        break;
    case USB_REQ_SET_CONFIGURATION:
        USBD_SetConfigReq();
        break;
    case USB_REQ_GET_CONFIGURATION:
    case USB_REQ_GET_STATUS:
    case USB_REQ_SET_FEATURE:
    case USB_REQ_CLEAR_FEATURE:
    default:
        USBDev_CEPSendResponse(CEP_STALL);
        break;
    }

    return 0;
}

uint32_t USBD_StdItfReq(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET)
{
    switch(USBDevice.state)
    {
    case USBDev_Configured:
        if(pUSB_SETUP_PACKET->wIndex <= USB_DEVICE_ITFACE_MAX_NUM)
        {
            USBDevice.class_cb->Setup(&USBDevice.USB_SETUP_PACKET);
        }
        else
            USBDev_CEPSendResponse(CEP_STALL);
        break;

    default:
        USBDev_CEPSendResponse(CEP_STALL);
        break;
    }

    return 0;
}

uint32_t USBD_GetDescriptorReq(USBDev_Setup_TypeDef *pUSB_SETUP_PACKET)
{
    uint32_t len = 0;
    uint8_t *pbuf = NULL;
    uint8_t local_buffer[256];

    switch((uint8_t)(pUSB_SETUP_PACKET->wValue >> 8))
    {
    case USB_DESC_TYPE_DEVICE:
        if(USBDevice.state == USBDev_Powered)
            len = 8;
        else
            len = sizeof(device_dscr);
        pbuf = (uint8_t*)&device_dscr;
        break;
    case USB_DESC_TYPE_CONFIGURATION:
        if(USBDevice.speed == USBDev_Speed_Full)
            pbuf = USBDevice.class_cb->GetConfigDscr(USBDevice.speed, &len);
        else
            pbuf = USBDevice.class_cb->GetConfigDscr(USBDevice.speed, &len);
        break;
    case USB_DESC_TYPE_STRING:

        pbuf = &local_buffer[0];

        switch((uint8_t)(pUSB_SETUP_PACKET->wValue & 0xff))
        {
        case USBD_IDX_LANGID_STR:
            /*nbytes = MIN(4,pUSB_SETUP_PACKET->wLength);*/
            local_buffer[0] = 4;
            local_buffer[1] = USB_DESC_TYPE_STRING;
            local_buffer[2] = LOBYTE(USB_DEVICE_LANGID_STR);
            local_buffer[3] = HIBYTE(USB_DEVICE_LANGID_STR);

            len = MIN(4,pUSB_SETUP_PACKET->wLength);
            break;

        case USBD_IDX_MFC_STR:
            len = MIN(get_string_to_unicode(USB_DEVICE_MFC_STR,local_buffer),pUSB_SETUP_PACKET->wLength);
            break;

        case USBD_IDX_PRODUCT_STR:
            len = MIN(get_string_to_unicode(USB_DEVICE_PRODUCT_STR,local_buffer),pUSB_SETUP_PACKET->wLength);
            break;

        case USBD_IDX_SERIAL_STR:
            len = MIN(get_string_to_unicode(USB_DEVICE_SERIAL_STR,local_buffer),pUSB_SETUP_PACKET->wLength);
            break;

        case USBD_IDX_CONFIG_STR:
            len = MIN(get_string_to_unicode(USB_DEVICE_CONFIG_STR,local_buffer),pUSB_SETUP_PACKET->wLength);
            break;

        case USBD_IDX_INTERFACE_STR:
            len = MIN(get_string_to_unicode(USB_DEVICE_INTERFACE_STR,local_buffer),pUSB_SETUP_PACKET->wLength);
            break;

        default:
            USBDev_CEPSendResponse(CEP_STALL);
            break;
        }
        break;

    case USB_DESC_TYPE_DEVICE_QUALIFIER:
        USBDev_CEPSendResponse(CEP_STALL);
        break;

    default:
        USBDev_CEPSendResponse(CEP_STALL);
        break;
    }

    if((len != 0) && ((uint16_t)(pUSB_SETUP_PACKET->wLength) != 0)) {
        USBDev_EPSendData(pbuf, MIN(len,pUSB_SETUP_PACKET->wLength),0);
        USBDev_SetSetupStage(USBDev_SetupStage_Data);
    }

    return 0;
}

uint32_t get_strlen(char *str)
{
    char *pstr = str;
    uint32_t i=0;

    while((*pstr++) != 0) {i++;}
    return i;
}

uint32_t get_string_to_unicode(char *desc, uint8_t *unicode)
{
    uint8_t i=0;
    unicode[i++] = get_strlen(desc)*2+2;
    unicode[i++] = USB_DESC_TYPE_STRING;

    while (*desc != 0)
    {
        unicode[i++] = *desc++;
        unicode[i++] = 0x00;
    }
    return unicode[0];
}

uint32_t USBDev_CEPSendData(uint8_t *pbuf, uint32_t len)
{
    if(len == 0)
    {
        USBDev_CEPSendResponse(CEP_ZEROLEN);
        return 0;
    }

    USBDevice.USB_SETUP_PACKET.xfer_buff = pbuf;
    USBDevice.USB_SETUP_PACKET.xfer_count = 0;
    USBDevice.USB_SETUP_PACKET.xfer_len = len;

    USBDev_PutNextCEPPacket();

    return 0;
}

uint32_t USBDev_PutNextCEPPacket(void)
{
    uint32_t data_size;

    if((USBDevice.USB_SETUP_PACKET.xfer_len - USBDevice.USB_SETUP_PACKET.xfer_count) > USB_MAX_EP0_SIZE)
        data_size = USB_MAX_EP0_SIZE;
    else
        data_size = USBDevice.USB_SETUP_PACKET.xfer_len - USBDevice.USB_SETUP_PACKET.xfer_count;

    if(data_size == 0)
        USBDev_CEPSendResponse(CEP_ZEROLEN);
    else
    {
        USBDev_DMAOpStart((uint8_t*)(USBDevice.USB_SETUP_PACKET.xfer_buff + USBDevice.USB_SETUP_PACKET.xfer_count),
                          data_size, 0, USBDMA_OP_WRITE_TO_EP | USBDMA_OP_START);

        NT_USBDevice->CEP_IN_XFRCNT = data_size;

        USBDevice.USB_SETUP_PACKET.xfer_count += data_size;
    }

    return 0;
}

uint32_t USBDev_GetNextCEPPacket(void)
{
    uint32_t data_size;

    //получаем количество пришедших данных
    data_size = NT_USBDevice->CEP_OUT_XFRCNT;
    //получаем точку и инфу о ней
    if(data_size > 0)
    {
        USBDev_DMAOpStart((uint8_t*)(USBDevice.USB_SETUP_PACKET.xfer_buff + USBDevice.USB_SETUP_PACKET.xfer_count),
                          data_size,
                          0,
                          USBDMA_OP_READ_FROM_EP | USBDMA_OP_START);
        USBDevice.USB_SETUP_PACKET.xfer_count += data_size;
    }

    return 0;
}

uint32_t USBD_SetAddressReq(void)
{
    if((USBDevice.USB_SETUP_PACKET.wIndex == 0) && (USBDevice.USB_SETUP_PACKET.wLength == 0))
    {
        if(USBDevice.state == USBDev_Configured)
            USBDev_CEPSendResponse(CEP_STALL);
        else
        {
            USBDevice.USB_SETUP_PACKET.set_addr_active_flag = 1;
            USBDevice.address = (uint8_t)(USBDevice.USB_SETUP_PACKET.wValue) & 0x7F;
            USBDev_SetSetupStage(USBDev_SetupStage_Status);
            // нулевой пакет подтверждения
            USBDev_CEPSendResponse(CEP_ZEROLEN);

            if(USBDevice.address != 0) USBDevice.state = USBDev_Addressed;
            else                       USBDevice.state = USBDev_Default;
        }
    }
    else
        USBDev_CEPSendResponse(CEP_STALL);

    return 0;
}

uint32_t USBD_SetConfigReq(void)
{
    if(USBDevice.USB_SETUP_PACKET.wValue > USB_DEVICE_CFG_MAX_NUM)
    {
        USBDev_CEPSendResponse(CEP_STALL);
    }
    else
    {
        switch(USBDevice.state)
        {
        case USBDev_Addressed:
            if(USBDevice.USB_SETUP_PACKET.wValue) //если номер полученной конфигурации больше нулевой
            {
                USBDevice.config = USBDevice.USB_SETUP_PACKET.wValue;

                USBD_SetCfg(USBDevice.config);
                USBDevice.state  = USBDev_Configured;
            }

            USBDev_CEPSendResponse(CEP_ZEROLEN);
            USBDev_SetSetupStage(USBDev_SetupStage_Status);

            break;
        case USBDev_Configured:
            //если полученная конфигурация равна нулю - деконфигурируем
            if(USBDevice.USB_SETUP_PACKET.wValue == 0)
            {
                USBDevice.config = USBDevice.USB_SETUP_PACKET.wValue;
                USBDevice.state  = USBDev_Addressed;

                USBD_ClrCfg(USBDevice.config);
            }
            //если заданная конфигурация отличается от запрашиваемой, то реконфигурируем
            else if (USBDevice.config != USBDevice.USB_SETUP_PACKET.wValue)
            {
                USBD_ClrCfg(USBDevice.config);

                USBDevice.config = USBDevice.USB_SETUP_PACKET.wValue;

                USBD_SetCfg(USBDevice.config);

                USBDev_CEPSendResponse(CEP_ZEROLEN);
            }
            //else //иначе стоит та же самая конфигурация

            USBDev_CEPSendResponse(CEP_ZEROLEN);
            USBDev_SetSetupStage(USBDev_SetupStage_Status);
            break;
        default:
            USBDev_CEPSendResponse(CEP_STALL);
            break;
        }
    }

    return 0;
}

uint32_t USBD_SetCfg(uint8_t config_num)
{
    //tmp_config_buf_start_address = NT_USBDevice->CEP_END_ADDR + 1;

    USBDevice.class_cb->Init(config_num);

    return 0;
}

uint32_t USBD_ClrCfg(uint8_t config_num)
{
    USBDevice.tmp_config_buf_start_address = USB_DEVICE_MAX_EP0_SIZE;

    USBDevice.class_cb->DeInit(config_num);

    return 0;
}

// открытие точек 0..4
uint32_t USBDev_EP_Open(uint8_t  ep_addr,
                        uint32_t ep_mps,
                        uint8_t  ep_type)
{
    uint8_t epnum = ep_addr & 0x0F;
    USBDev_EP_TypeDef *ep;

    if((ep_addr & 0x80) == 0x80)
        ep = &USBDevice.in_ep[epnum];
    else
        ep = &USBDevice.out_ep[epnum];
    //настраиваем необходимые параметры
    ep->epnum      = epnum;
    ep->is_in      = (ep_addr & 0x80) != 0;
    ep->max_packet = ep_mps;

    if((ep_addr & 0x80) == 0) //if EP OUT
        ep->out_nak_active = 1;

    switch(ep_type) //ep type
    {
    case 0: ep->type = 0; break; //control
    case 1: ep->type = 3; break; //iso
    case 2: ep->type = 1; break; //bulk
    case 3: ep->type = 2; break; //int
    }

    if(epnum != 0)
        USBDev_EPActivate(ep);

    return 0;
}
//закрытие точек 1..4
uint32_t USBDev_EP_Close(uint8_t ep_addr)
{
    USBDev_EP_TypeDef *ep;

    if((ep_addr & 0x7F) == 0)
        return 1;

    if((ep_addr & 0x80) == 0x80)
        ep = &USBDevice.in_ep [(ep_addr-1) & 0x0F];
    else
        ep = &USBDevice.out_ep[(ep_addr-1) & 0x0F];

    USBDev_EPDeactivate(ep);

    return 0;
}

uint32_t USBDev_EPActivate(USBDev_EP_TypeDef *ep)
{
    //смотрим, активна ли точка уже
    if((NT_USBDevice->USB_EP[ep->epnum - 1].USB_EP_CFG & 0x0001) == 0)
    {
        //и если не активна, то настраиваем ее

        //задаем максимальный размер пакета
        NT_USBDevice->USB_EP[ep->epnum - 1].MPS    = ep->max_packet;
        //конфигурируем точку
        NT_USBDevice->USB_EP[ep->epnum - 1].USB_EP_CFG =  (ep->epnum  << 4) // номер конечной точки
                |(ep->is_in  << 3) // направление передачи
                |(ep->type   << 1) // тип конечной точки
                | 1;               // активируем точку
        //настраиваем адресное пространство буфера
        NT_USBDevice->USB_EP[ep->epnum - 1].START_ADDR = USBDevice.tmp_config_buf_start_address;
        USBDevice.tmp_config_buf_start_address =
                NT_USBDevice->USB_EP[ep->epnum - 1].START_ADDR + (NT_USBDevice->USB_EP[ep->epnum - 1].MPS >> 1) + 1;
        NT_USBDevice->USB_EP[ep->epnum - 1].END_ADDR   = USBDevice.tmp_config_buf_start_address - 1;

        //сбрасываем буфер конечной точки
        NT_USBDevice->USB_EP[ep->epnum - 1].RSP_SC = 1;

        //настраиваем прерывания по типу точки
        if(ep->is_in)
        {
            NT_USBDevice->USB_EP[ep->epnum - 1].IRQ_ENB =  (1<<3)  //data packet transmitted int
                    //|(1<<6) //in token int
                    //|(1<<10) //NYET SENT
                    ;
            NT_USBDevice->USB_EP[ep->epnum - 1].RSP_SC  = (0<<1);  //autovalidate mode
        }
        else
        {
            NT_USBDevice->USB_EP[ep->epnum - 1].RSP_SC = (1<<7); // set NAK for OUT ep

            NT_USBDevice->USB_EP[ep->epnum - 1].IRQ_ENB = (1<<4); //data packet receive int
        }

        //включаем прерывание на конечную точку
        USBDev_EPIntEnable(ep->epnum);
    }

    return 0;
}
uint32_t USBDev_EPDeactivate(USBDev_EP_TypeDef *ep)
{
    NT_USBDevice->USB_EP[ep->epnum - 1].USB_EP_CFG = 0; //disable ep
    USBDev_EPIntDisable(ep->epnum);                 //disable irq

    return 0;
}

uint32_t USBDev_Init(void)
{
    //переводим usb device в состояние powered
    USBDevice.state   = USBDev_Powered;
    USBDevice.speed   = USBDev_Speed_Full;
    USBDevice.address = 0;
    USBDevice.config  = 0;
    USBDevice.tmp_config_buf_start_address = USB_DEVICE_MAX_EP0_SIZE;
    //настраиваем прерывания на usb device
    NT_USBDevice->USB_IRQ_ENB = (1<<0)| //SOF int
            (1<<1)| //reset int
            (1<<2)| //resume int
            (1<<3);//| //suspend req int
    //(1<<4)| //HS settle int
    //(1<<5); //DMA complete int
    //включаем прерывание на usb device
    NT_USBDevice->IRQ_ENB_L |= (1<<0); //usb interrupt enable

    USBDev_SetOpSpeed(USBDev_Speed_Full);

    return 0;
}

uint32_t USBDev_ClearEPIntBit(uint8_t epnum, uint32_t ep_bit)
{
    if(epnum == 0) //control EP
        NT_USBDevice->CEP_IRQ_STAT = ep_bit;
    else
        NT_USBDevice->USB_EP[epnum - 1].IRQ_STAT = ep_bit;

    return 0;
}

uint32_t USBDev_GetEPIntStatus(uint8_t epnum)
{
    if(epnum == 0)
        return NT_USBDevice->CEP_IRQ_STAT;
    else
        return NT_USBDevice->USB_EP[epnum - 1].IRQ_STAT;
}

uint32_t USBDev_IsEPTypeIN(uint8_t epnum)
{
    if(epnum == 0)
        return 1;
    else
        return NT_USBDevice->USB_EP[epnum - 1].USB_EP_CFG & (1<<3);
}

uint32_t USBDev_SetAddress(uint8_t address)
{
    NT_USBDevice->USB_ADDR = address;
    return 0;
}

uint32_t USBDev_EPIntEnable(uint8_t epnum)
{
    uint32_t mask = (1 << (epnum + 1));

    NT_USBDevice->IRQ_ENB_L |= mask;

    return 0;
}

uint32_t USBDev_EPIntDisable(uint8_t epnum)
{
    uint32_t mask = (1 << (epnum + 1));

    NT_USBDevice->IRQ_ENB_L &= ~mask;

    return 0;
}

uint32_t USBDev_SetOpSpeed(USBDev_Speed_TypeDef speed)
{
    if(speed == USBDev_Speed_Full)
        NT_USBDevice->USB_OPER &= ~(1<<1); //full speed
    else
        NT_USBDevice->USB_OPER |= (1<<1);  //high speed

    return 0;
}

__ALIGNED(4) uint8_t dma_tmpbuf[1024]; // for max ISOC HIGHSPEED transaction

uint32_t USBDev_DMAOpStart(uint8_t *pbuf, uint32_t len, uint8_t epnum, uint32_t op)
{
    uint32_t wr_to_ep = USBDMA_OP_WRITE_TO_EP & op;

    if(len > 1024)
        return 1; //avoid buffer overflow

    if(wr_to_ep != 0)
        memcpy(dma_tmpbuf,pbuf,len);

    NT_USBDevice->AHB_DMA_ADDR  = (uint32_t)&dma_tmpbuf[0];
    NT_USBDevice->DMA_CNT       = len;
    NT_USBDevice->DMA_CTRL_STS  = op|epnum;

    //ждем окончания работы DMA
    while(NT_USBDevice->DMA_CTRL_STS & USBDMA_OP_MASK_DONE){};

    if(wr_to_ep == 0)
        memcpy(pbuf,&dma_tmpbuf[0],len);

    return 0;
}

/////////////////////////

uint32_t USBDev_WritePacket(uint8_t *src, uint32_t len, uint8_t epnum)
{
    USBDev_EP_TypeDef *ep;
    uint8_t epnum_mask = epnum & 0x0F;

    ep = &USBDevice.in_ep[epnum_mask];

    if(len > ep->max_packet)
        return 1;

    if(len > 0)
    {
        USBDev_DMAOpStart(src, len, epnum_mask, USBDMA_OP_WRITE_TO_EP | USBDMA_OP_START);
        //отправляем пакет
        if(len < ep->max_packet)
            USBDev_EPSetResponse(EP_PKTEND, epnum_mask);
    }

    return 0;
}

uint32_t USBDev_ReadPacket(uint8_t *dst, uint32_t len, uint8_t epnum)
{
    USBDev_EP_TypeDef *ep;
    uint8_t epnum_mask = epnum & 0x0F;

    ep = &USBDevice.out_ep[epnum_mask];

    if(len > ep->max_packet)
        return 1;

    if(len > 0)
        USBDev_DMAOpStart(dst, len, epnum_mask, USBDMA_OP_READ_FROM_EP | USBDMA_OP_START);

    return 0;
}

/////////////////////////
//возвращает количество байт в буфере конечной точки
uint32_t USBDev_EP_AvailCnt(uint8_t epnum)
{
    if(epnum > 0)
        return NT_USBDevice->USB_EP[epnum - 1].AVAIL_CNT;
    else
        return 0;
}

USBDev_State_TypeDef USBDev_ReadState(void)
{
    return USBDevice.state;
}

uint32_t USBDev_EPSetResponse(EP_RESPONSE resp, uint8_t epnum)
{
    if(epnum == 0)
        return 1;
    if(resp == EP_CLRNAK)
        NT_USBDevice->USB_EP[(epnum & 0x0F) - 1].RSP_SC = 0;
    else
        NT_USBDevice->USB_EP[(epnum & 0x0F) - 1].RSP_SC = (1<<resp);

    return 0;
}


uint32_t USBDev_EPSendData(uint8_t *pbuf, uint32_t len, uint8_t epnum)
{
    if(USBDev_IsEPTypeIN(epnum) == 0)
        return 1; //error! ep is not IN-endpoint

    if(epnum == 0) //if CEP
    {
        if(len == 0)
        {
            USBDev_CEPSendResponse(CEP_ZEROLEN);
            return 0;
        }

        USBDevice.USB_SETUP_PACKET.xfer_buff = pbuf;
        USBDevice.USB_SETUP_PACKET.xfer_count = 0;
        USBDevice.USB_SETUP_PACKET.xfer_len = len;

        USBDev_PutNextCEPPacket();
    }
    else //if ep 1...4
    {
        if(len == 0) //send zerolen packet
        {
            USBDev_EPSetResponse(EP_ZEROLEN,epnum);
            return 0;
        }
        //else len != 0
        USBDevice.in_ep[epnum - 1].xfer_buff  = pbuf;
        USBDevice.in_ep[epnum - 1].xfer_count = 0;
        USBDevice.in_ep[epnum - 1].xfer_len   = len;

        // TODO!!!
        // USBDev_PutNextEPPacket(epnum);
    }

    return 0;
}

uint32_t USBDev_EPPrepareRx(uint8_t *pbuf, uint32_t len, uint8_t epnum)
{
    USBDevice.out_ep[epnum].xfer_buff = pbuf;
    USBDevice.out_ep[epnum].xfer_len = len;
    USBDevice.out_ep[epnum].xfer_count = 0;
    USBDevice.out_ep[epnum].out_nak_active = 0;

    if(epnum != 0)
        //отключаем автоответ NAK от точки
        USBDev_EPSetResponse(EP_CLRNAK, epnum);
    else
        USBDev_SetSetupStage(USBDev_SetupStage_Data);

    return 0;
}

uint32_t USBDev_ClassCbInit(USBDev_ClassCB_TypeDef *cb)
{
    USBDevice.class_cb = cb;
    return 0;
}


