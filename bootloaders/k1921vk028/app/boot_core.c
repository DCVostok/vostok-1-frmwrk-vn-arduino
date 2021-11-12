/*==============================================================================
 * UART загрузчик для К1921ВК028
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
 *                              2019 АО "НИИЭТ"
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
static RAMFUNC uint32_t is_modify_en(FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type);
static RAMFUNC uint32_t is_read_en(FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type);

//-- Functions -----------------------------------------------------------------
void boot_init()
{
    uint32_t ticks_counted;
    uint32_t baud_i;
    uint32_t baud_f;

    DBG_PRINT(0x01);
    //Ждем стартового бита - 0
    while (UARTx_RX_PIN_STATE) {
    };
    //включаем счетчик
    TMR->CTRL_bit.ON = 1;
    //Ждём начало группы из семи 1 (передаётся 0x7F)
    while (!(UARTx_RX_PIN_STATE)) {
    };
    ticks_counted = TMR->VALUE;
    //Ждём нуля
    while (UARTx_RX_PIN_STATE) {
    };
    ticks_counted -= TMR->VALUE;
    TMR->CTRL_bit.ON = 0;
    //Вычисляем баудрейт
    baud_i = ticks_counted / (16 * 7);
    baud_f = (uint32_t)((ticks_counted / (16.0f * 7.0f) - baud_i) * 64 + 0.5f);
    //Ждем стопового бита - 1
    while (!(UARTx_RX_PIN_STATE)) {
    };
    //Включаем UART
    UARTx->IBRD = baud_i;
    UARTx->FBRD = baud_f;
    UARTx->LCRH = (1 << UART_LCRH_FEN_Pos) | (3 << UART_LCRH_WLEN_Pos);
    UARTx->CR = (1 << UART_CR_RXE_Pos) | (1 << UART_CR_TXE_Pos) | (1 << UART_CR_UARTEN_Pos);
    //передаем сигнатуру устройства с обменянными местами байтами
    UARTx->DR = (PACKET_DEVICE_SIGN & 0xFF00) >> 8;
    UARTx->DR = PACKET_DEVICE_SIGN & 0x00FF;
}

void boot_exit()
{
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
        switch (packet.cmd_code) {
        // Get commands
        case CMD_GET_INFO:
            DBG_PRINT(packet.cmd_code);
            get_info_cmd(&packet);
            break;
        case CMD_GET_CFGWORD:
            DBG_PRINT(packet.cmd_code);
            get_cfgword_cmd(&packet);
            break;
        // Set commands
        case CMD_SET_CFGWORD:
            DBG_PRINT(packet.cmd_code);
            set_cfgword_cmd(&packet);
            break;
        // Write commands
        case CMD_WRITE_PAGE:
            DBG_PRINT(packet.cmd_code);
            write_page_cmd(&packet);
            break;
        // Read commands
        case CMD_READ_PAGE:
            DBG_PRINT(packet.cmd_code);
            read_page_cmd(&packet);
            break;
        // Erase commands
        case CMD_ERASE_FULL:
            DBG_PRINT(packet.cmd_code);
            erase_full_cmd(&packet);
            break;
        case CMD_ERASE_PAGE:
            DBG_PRINT(packet.cmd_code);
            erase_page_cmd(&packet);
            break;
        // Exit
        case CMD_EXIT:
            DBG_PRINT(packet.cmd_code);
            exit_cmd(&packet);
            break;
        case CMD_NONE:
            DBG_PRINT(packet.cmd_code);
            msg_cmd(&packet);
            break;
        default:
            break;
        }
    }
}

uint32_t is_modify_en(FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type)
{
    uint32_t data[4];
    uint32_t modify_en = 0;

    flash_read(CFGWORD_PAGE + CFGWORD0_BASE, BFLASH_MEM, FLASH_NVR, data);
    if (flash_type == FLASH_NVR) {
        if (flash_mem == MFLASH_MEM)
            modify_en = (data[1] & CFGWORD1_MNVRWE_Msk) >> CFGWORD1_MNVRWE_Pos;
        else
            modify_en = (data[1] & CFGWORD1_BNVRWE_Msk) >> CFGWORD1_BNVRWE_Pos;
    } else {
        if (flash_mem == MFLASH_MEM)
            modify_en = (data[1] & CFGWORD1_MFLASHWE_Msk) >> CFGWORD1_MFLASHWE_Pos;
        else
            modify_en = (data[1] & CFGWORD1_BFLASHWE_Msk) >> CFGWORD1_BFLASHWE_Pos;
    }

    return modify_en;
}

uint32_t is_read_en(FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type)
{
    uint32_t data[4];
    uint32_t read_en = 0;

    flash_read(CFGWORD_PAGE + CFGWORD0_BASE, BFLASH_MEM, FLASH_NVR, data);
    if (flash_type == FLASH_NVR) {
        if (flash_mem == MFLASH_MEM)
            read_en = (data[1] & CFGWORD1_MNVRRE_Msk) >> CFGWORD1_MNVRRE_Pos;
        else
            read_en = (data[1] & CFGWORD1_BNVRRE_Msk) >> CFGWORD1_BNVRRE_Pos;
    } else {
        if (flash_mem == MFLASH_MEM)
            read_en = (data[1] & CFGWORD1_MFLASHRE_Msk) >> CFGWORD1_MFLASHRE_Pos;
        else
            read_en = (data[1] & CFGWORD1_BFLASHRE_Msk) >> CFGWORD1_BFLASHRE_Pos;
    }

    return read_en;
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
    uint32_t data[4];

    rx_crc = packet_fifo_read_u16();

    if (packet->crc != rx_crc) {
        packet->tmp_data8[0] = MSG_ERR_CRC;
        packet->data_n = 4;
    } else {
        packet->tmp_data8[0] = MSG_OK;
        flash_read(CFGWORD_PAGE + CFGWORD0_BASE, BFLASH_MEM, FLASH_NVR, data);
        packet->tmp_data32[1] = data[0];
        packet->tmp_data32[2] = data[1];
        packet->data_n = 12;
    }

    msg_cmd(packet);
}

void set_cfgword_cmd(Packet_TypeDef* packet)
{
    uint32_t cfgword[2];
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t page_arr[MEM_BFLASH_NVR_PAGE_SIZE / 16][4];
    uint32_t data[4];
    uint32_t modify_en;

    modify_en = is_modify_en(BFLASH_MEM, FLASH_NVR);

    cfgword[0] = packet_fifo_read_u32();
    calc_crc = crc_upd_u32(packet->crc, cfgword[0]);
    cfgword[1] = packet_fifo_read_u32();
    calc_crc = crc_upd_u32(calc_crc, cfgword[1]);

    rx_crc = packet_fifo_read_u16();

    packet->data_n = 12;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        //читаем всю страницу
        for (uint32_t i = 0; i < MEM_BFLASH_NVR_PAGE_SIZE / 16; i++) {
            flash_read(CFGWORD_PAGE + i * 16, BFLASH_MEM, FLASH_NVR, (uint32_t*)page_arr[i]);
        }
        //модифицируем конфигурацию, стираем и пишем обратно
        page_arr[CFGWORD0_BASE/16][0] = cfgword[0];
        page_arr[CFGWORD0_BASE/16][1] = cfgword[1];
        flash_erase_page(CFGWORD_PAGE, BFLASH_MEM, FLASH_NVR);
        for (uint32_t i = 0; i < MEM_BFLASH_NVR_PAGE_SIZE / 16; i++) {
            if ((page_arr[i][0] != 0xFFFFFFFF) || (page_arr[i][1] != 0xFFFFFFFF) ||
                (page_arr[i][2] != 0xFFFFFFFF) || (page_arr[i][3] != 0xFFFFFFFF))
                flash_write(CFGWORD_PAGE + i * 16, BFLASH_MEM, FLASH_NVR, (uint32_t*)page_arr[i]);
        }
        //контроль записанного
        packet->tmp_data8[0] = MSG_OK;
        for (uint32_t i = 0; i < MEM_BFLASH_NVR_PAGE_SIZE / 16; i++) {
            flash_read(CFGWORD_PAGE + i * 16, BFLASH_MEM, FLASH_NVR, data);
            if ((page_arr[i][0] != data[0]) || (page_arr[i][1] != data[1]) ||
                (page_arr[i][2] != data[2]) || (page_arr[i][3] != data[3]))
                packet->tmp_data8[0] = MSG_FAIL;
        }
    }

    packet->tmp_data32[1] = cfgword[0];
    packet->tmp_data32[2] = cfgword[1];

    msg_cmd(packet);
}

void write_page_cmd(Packet_TypeDef* packet)
{
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t addr;
    uint32_t addr_i;
    uint32_t flash_type;
    uint32_t flash_mem;
    uint32_t erase_option;
    uint32_t data[16];
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t modify_en;
    uint32_t flash_words;
    uint32_t flash_page_size;

    //читаем адрес, определяем необходимый тип флеш и номер страницы, затем стираем её если нужно
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BFLASH_MEM) {
        addr = rx_data & ~(MEM_BFLASH_PAGE_SIZE - 1) & 0x00FFFFFF;
    } else {
        addr = rx_data & ~(MEM_MFLASH_PAGE_SIZE - 1) & 0x00FFFFFF;
    }

    //можно ли изменять страницу
    modify_en = is_modify_en(flash_mem, flash_type);

    //надо ли стирать перед записью
    erase_option = (cfg & CMD_WRITE_PAGE_OPT_ERASE_MSK) >> CMD_WRITE_PAGE_OPT_ERASE_POS;

    //защита от модификации бутлоадера
    modify_en &= !((flash_mem == BFLASH_MEM) && (flash_type == FLASH_MAIN) && (addr < 2 * MEM_BFLASH_PAGE_SIZE));

    if (erase_option && modify_en)
        flash_erase_page(addr, flash_mem, flash_type);
    calc_crc = crc_upd_u32(packet->crc, rx_data);

    addr_i = addr;

    if (flash_mem == BFLASH_MEM) {
        flash_words = MEM_BFLASH_BUS_WIDTH_WORDS;
        flash_page_size = MEM_BFLASH_PAGE_SIZE;
    } else {
        flash_words = MEM_MFLASH_BUS_WIDTH_WORDS;
        flash_page_size = MEM_MFLASH_PAGE_SIZE;
    }

    for (uint32_t i = 0; i < flash_page_size / (flash_words * 4); i++) {
        for (uint32_t d = 0; d < flash_words; d++) {
            data[d] = packet_fifo_read_u32();
        }
        if (modify_en)
            flash_write(addr_i, flash_mem, flash_type, data);
        for (uint32_t d = 0; d < flash_words; d++) {
            calc_crc = crc_upd_u32(calc_crc, data[d]);
        }
        addr_i += flash_words * 4;
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
    uint32_t flash_mem;
    uint32_t data[16];
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t read_en;
    uint32_t flash_words;
    uint32_t flash_page_size;

    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BFLASH_MEM) {
        addr = rx_data & ~(MEM_BFLASH_PAGE_SIZE - 1) & 0x00FFFFFF;
    } else {
        addr = rx_data & ~(MEM_MFLASH_PAGE_SIZE - 1) & 0x00FFFFFF;
    }

    //может ли хост читать флэш
    read_en = is_read_en(flash_mem, flash_type);

    //защита от чтения бутлоадера
    read_en &= !((flash_mem == BFLASH_MEM) && (flash_type == FLASH_MAIN) && (addr < 2 * MEM_BFLASH_PAGE_SIZE));

    calc_crc = crc_upd_u32(packet->crc, rx_data);
    rx_crc = packet_fifo_read_u16();

    packet->tmp_data32[1] = rx_data;
    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!read_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        addr_i = addr;
        if (flash_mem == BFLASH_MEM) {
            flash_words = MEM_BFLASH_BUS_WIDTH_WORDS;
            flash_page_size = MEM_BFLASH_PAGE_SIZE;
        } else {
            flash_words = MEM_MFLASH_BUS_WIDTH_WORDS;
            flash_page_size = MEM_MFLASH_PAGE_SIZE;
        }
        for (uint32_t i = 0; i < flash_page_size / (flash_words * 4); i++) {
            flash_read(addr_i, flash_mem, flash_type, data);
            for (uint32_t d = 0; d < flash_words; d++) {
                packet->tmp_data32[2 + i * flash_words + d] = data[d];
            }
            addr_i += flash_words * 4;
        }
        packet->data_n += flash_page_size;
        packet->tmp_data8[0] = MSG_OK;
    }

    msg_cmd(packet);
}

void erase_full_cmd(Packet_TypeDef* packet)
{
    uint16_t rx_crc;
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t flash_type;
    uint32_t flash_mem;
    uint32_t modify_en;
    uint16_t calc_crc;

    //читаем адрес, определяем необходимый тип флеш и затем стираем её
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //можно ли изменять страницу
    modify_en = is_modify_en(flash_mem, flash_type);

    //защита от модификации бутлоадера
    modify_en &= !((flash_mem == BFLASH_MEM) && (flash_type == FLASH_MAIN));

    calc_crc = crc_upd_u32(packet->crc, rx_data);
    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        flash_erase_full(flash_mem, flash_type);
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
    uint32_t flash_mem;
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t modify_en;

    //читаем адрес, определяем необходимый тип флеш и номер страницы, затем стираем её
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BFLASH_MEM) {
        addr = rx_data & ~(MEM_BFLASH_PAGE_SIZE - 1) & 0x00FFFFFF;
    } else {
        addr = rx_data & ~(MEM_MFLASH_PAGE_SIZE - 1) & 0x00FFFFFF;
    }

    //можно ли изменять страницу
    modify_en = is_modify_en(flash_mem, flash_type);

    //защита от модификации бутлоадера
    modify_en &= !((flash_mem == BFLASH_MEM) && (flash_type == FLASH_MAIN) && (addr < 2 * MEM_BFLASH_PAGE_SIZE));

    calc_crc = crc_upd_u32(packet->crc, rx_data);
    rx_crc = packet_fifo_read_u16();

    packet->data_n = 8;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        flash_erase_page(addr, flash_mem, flash_type);
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
