/*==============================================================================
 * UART загрузчик для К1921ВК035
 *
 * Ядро загрузчика.
 * Обработка полученных комманд и формирование исходящих пакетов.
 *------------------------------------------------------------------------------
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
 *                              2018 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "boot_core.h"
#include "boot_flash.h"
#include "boot_packet.h"

//-- Private function prototypes -----------------------------------------------
static RAMFUNC void msg_cmd(Packet_TypeDef* packet);
static RAMFUNC void get_info_cmd(Packet_TypeDef* packet);
static RAMFUNC void get_cfgword_cmd(Packet_TypeDef* packet);
static RAMFUNC void set_cfgword_cmd(Packet_TypeDef* packet);
static RAMFUNC void read_page_cmd(Packet_TypeDef* packet);
static RAMFUNC void write_page_cmd(Packet_TypeDef* packet);
static RAMFUNC void erase_full_cmd(Packet_TypeDef* packet);
static RAMFUNC void erase_page_cmd(Packet_TypeDef* packet);
static RAMFUNC void exit_cmd(Packet_TypeDef* packet);

//-- Functions -----------------------------------------------------------------
void boot_init()
{
    uint32_t ticks_counted;
    uint32_t baud_i;
    uint32_t baud_f;

    DBG_PRINT(0x01);
    //Ждем стартового бита - 0
    while (UART_PORT->DATA & (1 << UART_PIN_RX_POS)) {
    };
    //включаем счетчик
    TMR->CTRL_bit.ON = 1;
    //Ждём начало группы из семи 1 (передаётся 0x7F)
    while (!(UART_PORT->DATA & (1 << UART_PIN_RX_POS))) {
    };
    ticks_counted = TMR->VALUE;
    //Ждём нуля
    while (UART_PORT->DATA & (1 << UART_PIN_RX_POS)) {
    };
    ticks_counted -= TMR->VALUE;
    TMR->CTRL_bit.ON = 0;
    //Вычисляем баудрейт
    baud_i = ticks_counted / (16 * 7);
    baud_f = (uint32_t)((ticks_counted / (16.0f * 7.0f) - baud_i) * 64 + 0.5f);
    //Ждем стопового бита - 1
    while (!(UART_PORT->DATA & (1 << UART_PIN_RX_POS))) {
    };
    //Включаем UART
    UART->IBRD = baud_i;
    UART->FBRD = baud_f;
    UART->LCRH = (1 << UART_LCRH_FEN_Pos) | (3 << UART_LCRH_WLEN_Pos);
    UART->CR = (1 << UART_CR_RXE_Pos) | (1 << UART_CR_TXE_Pos) | (1 << UART_CR_UARTEN_Pos);
    //передаем сигнатуру устройства с обменянными местами байтами
    UART->DR = (PACKET_DEVICE_SIGN & 0xFF00) >> 8;
    UART->DR = PACKET_DEVICE_SIGN & 0x00FF;
}

void boot_exit()
{
    flash_disable_boot();
    NVIC_SystemReset();
}

__attribute__((noreturn)) void boot_core()
{
    Packet_TypeDef packet;

    DBG_PRINT(0x02);
    //Инициализируем FIFO пакетов
    packet_fifo_init();
    //Передаём сообщение о готовности принимать команды
    packet.cmd_code = CMD_NONE;
    packet.tmp_data8[0] = MSG_READY;
    msg_cmd(&packet);

    while (1) {
        packet_recieve(&packet);
        DBG_PRINT(0x03);
        DBG_PRINT(packet.cmd_code);
        switch (packet.cmd_code) {
        // Get commands
        case CMD_GET_INFO:
            get_info_cmd(&packet);
            break;
        case CMD_GET_CFGWORD:
            get_cfgword_cmd(&packet);
            break;
        // Set commands
        case CMD_SET_CFGWORD:
            set_cfgword_cmd(&packet);
            break;
        // Write commands
        case CMD_WRITE_PAGE:
            write_page_cmd(&packet);
            break;
        // Read commands
        case CMD_READ_PAGE:
            read_page_cmd(&packet);
            break;
        // Erase commands
        case CMD_ERASE_FULL:
            erase_full_cmd(&packet);
            break;
        case CMD_ERASE_PAGE:
            erase_page_cmd(&packet);
            break;
        // Exit
        case CMD_EXIT:
            exit_cmd(&packet);
            break;
        case CMD_NONE:
            msg_cmd(&packet);
            break;
        default:
            break;
        }
    }
}

void msg_cmd(Packet_TypeDef* packet)
{
    if (packet->cmd_code == CMD_NONE)
        packet->data_n = 4;
    packet->tmp_data8[1] = packet->cmd_code;
    packet->tmp_data8[2] = PACKET_EMPTY_DATA;
    packet->tmp_data8[3] = PACKET_EMPTY_DATA;
    packet->cmd_code = CMD_MSG;

    packet_transmit(packet);
}

void get_info_cmd(Packet_TypeDef* packet)
{
    uint16_t rx_crc;

    rx_crc = packet_fifo_read_u16();

    if (packet->crc != rx_crc) {
        packet->tmp_data8[0] = MSG_ERR_CRC;
        packet->data_n = 4;
    } else {
        packet->tmp_data8[0] = MSG_OK;
        packet->tmp_data32[1] = SIU->CHIPID;
        packet->tmp_data32[2] = SCB->CPUID;
        packet->tmp_data32[3] = BOOT_VER;
        packet->data_n = 16;
    }

    msg_cmd(packet);
}

void get_cfgword_cmd(Packet_TypeDef* packet)
{
    uint16_t rx_crc;
    uint32_t data[2];

    rx_crc = packet_fifo_read_u16();

    if (packet->crc != rx_crc) {
        packet->tmp_data8[0] = MSG_ERR_CRC;
        packet->data_n = 4;
    } else {
        packet->tmp_data8[0] = MSG_OK;
        flash_read(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR, data);
        packet->tmp_data32[1] = data[0];
        packet->data_n = 8;
    }

    msg_cmd(packet);
}

void set_cfgword_cmd(Packet_TypeDef* packet)
{
    uint32_t cfgword;
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t page_arr[FLASH_NVR_PAGE_SIZE_BYTES / 8][2];
    uint32_t data[2];
    uint32_t modify_en;

    flash_read(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR, data);
    modify_en = (data[0] & CFGWORD_NVRWE_MSK) >> CFGWORD_NVRWE_POS;

    cfgword = packet_fifo_read_u32();
    calc_crc = crc_upd_u32(packet->crc, cfgword);

    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        //читаем всю страницу
        for (uint32_t i = 0; i < FLASH_NVR_PAGE_SIZE_BYTES / 8; i++) {
            flash_read(FLASH_NVR_CFGWORD_OFFSET + i * 8, FLASH_NVR, (uint32_t*)page_arr[i]);
        }
        //модифицируем конфигурацию, стираем и пишем обратно
        page_arr[0][0] = cfgword;
        flash_erase_page(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR);
        for (uint32_t i = 0; i < FLASH_NVR_PAGE_SIZE_BYTES / 8; i++) {
            if ((page_arr[i][0] != 0xFFFFFFFF) || (page_arr[i][1] != 0xFFFFFFFF))
                flash_write(FLASH_NVR_CFGWORD_OFFSET + i * 8, FLASH_NVR, (uint32_t*)page_arr[i]);
        }
        //контроль записанного
        packet->tmp_data8[0] = MSG_OK;
        for (uint32_t i = 0; i < FLASH_NVR_PAGE_SIZE_BYTES / 8; i++) {
            flash_read(FLASH_NVR_CFGWORD_OFFSET + i * 8, FLASH_NVR, data);
            if ((page_arr[i][0] != data[0]) || (page_arr[i][1] != data[1]))
                packet->tmp_data8[0] = MSG_FAIL;
        }
    }

    packet->tmp_data32[1] = cfgword;

    msg_cmd(packet);
}

void write_page_cmd(Packet_TypeDef* packet)
{
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t addr;
    uint32_t addr_i;
    uint32_t flash_type;
    uint32_t erase_option;
    uint32_t data[2];
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t modify_en;

    //читаем адрес, определяем необходимый тип флеш и номер страницы, затем стираем её если нужно
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш и можно ли её писать
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_read(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR, data);
    if (flash_type == FLASH_MAIN)
        modify_en = (data[0] & CFGWORD_FLASHWE_MSK) >> CFGWORD_FLASHWE_POS;
    else
        modify_en = (data[0] & CFGWORD_NVRWE_MSK) >> CFGWORD_NVRWE_POS;

    //надо ли стирать перед записью
    erase_option = (cfg & CMD_WRITE_PAGE_OPT_ERASE_MSK) >> CMD_WRITE_PAGE_OPT_ERASE_POS;

    //адрес
    addr = rx_data & ~(FLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;

    //защита от модификации бутлоадера
    modify_en &= !((flash_type == FLASH_NVR) && (addr < (FLASH_PAGE_SIZE_BYTES * 3)));

    if (erase_option && modify_en)
        flash_erase_page(addr, flash_type);
    calc_crc = crc_upd_u32(packet->crc, rx_data);

    //читаем по 8 байт данных и пишем всю страницу
    addr_i = addr;
    for (uint32_t i = 0; i < FLASH_PAGE_SIZE_BYTES / 8; i++) {
        data[0] = packet_fifo_read_u32();
        data[1] = packet_fifo_read_u32();
        if (modify_en)
            flash_write(addr_i, flash_type, data);
        calc_crc = crc_upd_u32(calc_crc, data[0]);
        calc_crc = crc_upd_u32(calc_crc, data[1]);
        addr_i += 8;
    }

    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else
        packet->tmp_data8[0] = MSG_OK;

    packet->tmp_data32[1] = rx_data;

    msg_cmd(packet);
}

void read_page_cmd(Packet_TypeDef* packet)
{
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t addr;
    uint32_t addr_i;
    uint32_t flash_type;
    uint32_t data[2];
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t read_en;


    flash_read(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR, data);

    //читаем адрес, определяем необходимый тип флеш и номер страницы
    rx_data = packet_fifo_read_u32();
    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);
    flash_type = (FlashType_TypeDef)((cfg & CMD_READ_PAGE_OPT_NVR_MSK) >> CMD_READ_PAGE_OPT_NVR_POS);
    //может ли хост читать флэш
    if (flash_type == FLASH_MAIN)
        read_en = (data[0] & CFGWORD_FLASHRE_MSK) >> CFGWORD_FLASHRE_POS;
    else //if (flash_type == FLASH_NVR)
        read_en = (data[0] & CFGWORD_NVRRE_MSK) >> CFGWORD_NVRRE_POS;
    //адрес
    addr = rx_data & ~(FLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
    //защита от чтения бутлоадера
    read_en &= !((flash_type == FLASH_NVR) && (addr < (FLASH_PAGE_SIZE_BYTES * 3)));

    calc_crc = crc_upd_u32(packet->crc, rx_data);
    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!read_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        addr_i = addr;
        for (uint32_t i = 0; i < FLASH_PAGE_SIZE_BYTES / 8; i++) {
            flash_read(addr_i, flash_type, data);
            packet->tmp_data32[2 + i * 2] = data[0];
            packet->tmp_data32[2 + i * 2 + 1] = data[1];
            addr_i += 8;
        }
        packet->tmp_data8[0] = MSG_OK;
        packet->data_n += FLASH_PAGE_SIZE_BYTES;
    }

    packet->tmp_data32[1] = rx_data;

    msg_cmd(packet);
}

void erase_full_cmd(Packet_TypeDef* packet)
{
    uint16_t rx_crc;
    uint32_t data[2];
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t flash_type;
    uint32_t modify_en;
    uint32_t addr;
    uint16_t calc_crc;

    //читаем адрес, определяем необходимый тип флеш и затем стираем её
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш и может ли хост её стирать
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_read(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR, data);
    if (flash_type == FLASH_MAIN)
        modify_en = (data[0] & CFGWORD_FLASHWE_MSK) >> CFGWORD_FLASHWE_POS;
    else
        modify_en = (data[0] & CFGWORD_NVRWE_MSK) >> CFGWORD_NVRWE_POS;

    //адрес
    addr = rx_data & ~(FLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;

    //защита от стирания бутлоадера
    modify_en &= !((flash_type == FLASH_NVR) && (addr < (FLASH_PAGE_SIZE_BYTES * 3)));
    calc_crc = crc_upd_u32(packet->crc, rx_data);

    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        flash_erase_full();
        packet->tmp_data8[0] = MSG_OK;
    }

    packet->tmp_data32[1] = rx_data;

    msg_cmd(packet);
}

void erase_page_cmd(Packet_TypeDef* packet)
{
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t addr;
    uint32_t flash_type;
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t data[2];
    uint32_t modify_en;

    //читаем адрес, определяем необходимый тип флеш и номер страницы, затем стираем её
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш и может ли хост её стирать
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_read(FLASH_NVR_CFGWORD_OFFSET, FLASH_NVR, data);
    if (flash_type == FLASH_MAIN)
        modify_en = (data[0] & CFGWORD_FLASHWE_MSK) >> CFGWORD_FLASHWE_POS;
    else
        modify_en = (data[0] & CFGWORD_NVRWE_MSK) >> CFGWORD_NVRWE_POS;

    //адрес
    addr = rx_data & ~(FLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;

    //защита от стирания бутлоадера
    modify_en &= !((flash_type == FLASH_NVR) && (addr < (FLASH_PAGE_SIZE_BYTES * 3)));

    calc_crc = crc_upd_u32(packet->crc, rx_data);
    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        flash_erase_page(addr, flash_type);
        packet->tmp_data8[0] = MSG_OK;
    }

    packet->tmp_data32[1] = rx_data;

    msg_cmd(packet);
}

void exit_cmd(Packet_TypeDef* packet)
{
    uint16_t rx_crc;
    uint16_t calc_crc;

    calc_crc = packet->crc;
    rx_crc = packet_fifo_read_u16();

    packet->data_n = 4;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else
        packet->tmp_data8[0] = MSG_OK;

    msg_cmd(packet);
    while (packet_transmit_status_busy()) {
    };

    boot_exit();
}
