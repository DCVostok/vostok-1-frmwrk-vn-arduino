/*==============================================================================
 * UART загрузчик для К1921ВК01T
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
static RAMFUNC uint32_t is_page_modify_en(uint32_t page_num, FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type);
static RAMFUNC uint32_t is_page_read_en(uint32_t page_num, FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type);

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
    while (!UARTx_RX_PIN_STATE) {
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
    while (!UARTx_RX_PIN_STATE) {
    };
    //Включаем UART
    UARTx->IBRD = baud_i;
    UARTx->FBRD = baud_f;
    UARTx->LCR_H = (1 << UART_LCR_H_FEN_Pos) | (3 << UART_LCR_H_WLEN_Pos);
    UARTx->CR = (1 << UART_CR_RXE_Pos) | (1 << UART_CR_TXE_Pos) | (1 << UART_CR_UARTEN_Pos);
    //передаем сигнатуру устройства с обменянными местами байтами
    UARTx->DR = (PACKET_DEVICE_SIGN & 0xFF00) >> 8;
    UARTx->DR = PACKET_DEVICE_SIGN & 0x00FF;
}

void boot_exit()
{
    typedef void (*p_func)(void);
    p_func user_app;

    DBG_PRINT(0x05);
    // отключаем прерывания
    __disable_irq();
    NVIC->ICER[0] = 0xFFFFFFFF;
    NVIC->ICER[1] = 0xFFFFFFFF;
    NVIC->ICER[2] = 0xFFFFFFFF;
    NVIC->ICER[3] = 0xFFFFFFFF;
    NVIC->ICER[4] = 0xFFFFFFFF;
    __DSB();
    __ISB();

    //сбрасываем порты
    NT_COMMON_REG->GPIODEN0 = 0x00020062;
    NT_COMMON_REG->GPIODEN1 = 0x08000000;
    NT_COMMON_REG->GPIODEN2 = 0x00000400;
    NT_COMMON_REG->GPIODEN2 = 0x00000000;
    NT_COMMON_REG->GPIOPCTLA = 0x0;
    NT_GPIOA->ALTFUNCCLR = 0xFFFFFFFF;
    NT_GPIOA->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOA->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLB = 0x0;
    NT_GPIOB->ALTFUNCCLR = 0xFFFFFFF8;
    NT_GPIOB->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOB->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLC = 0x0;
    NT_GPIOC->ALTFUNCCLR = 0xFFFFFFFF;
    NT_GPIOC->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOC->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLD = 0x0;
    NT_GPIOD->ALTFUNCCLR = 0xFFFFF7FF;
    NT_GPIOD->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOD->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLE = 0x0;
    NT_GPIOE->ALTFUNCCLR = 0xFFFFFBFC;
    NT_GPIOE->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOE->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLF = 0x0;
    NT_GPIOF->ALTFUNCCLR = 0xFFFFFFFF;
    NT_GPIOF->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOF->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLG = 0x0;
    NT_GPIOG->ALTFUNCCLR = 0xFFFFFFFF;
    NT_GPIOG->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOG->DATAOUT = 0x0;
    NT_COMMON_REG->GPIOPCTLH = 0x0;
    NT_GPIOH->ALTFUNCCLR = 0xFFFFFFFF;
    NT_GPIOH->OUTENCLR = 0xFFFFFFFF;
    NT_GPIOH->DATAOUT = 0x0;

    //сбрасываем периферию
    NT_COMMON_REG->PER_RST0 = 0;
    NT_COMMON_REG->UART_CLK = 0;

    //переходим на тактирование от RC
    NT_COMMON_REG->SYS_CLK = 0;
    uint32_t timeout_counter = SYSCLK_SWITCH_TIMEOUT;
    while (timeout_counter) {
        timeout_counter--;
    }
    NT_COMMON_REG->PLL_NF = 0;
    NT_COMMON_REG->PLL_NR = 0;
    NT_COMMON_REG->PLL_OD = 0;
    NT_COMMON_REG->PLL_CTRL = 0;

    SysTick->LOAD = 0;
    SysTick->VAL = 0;
    SysTick->CTRL = 0;

    user_app = (void (*)(void))(*((uint32_t*)((0x00002000 + 4))));
    SCB->VTOR = 0x00002000;
    __enable_irq();
    __set_MSP(*(volatile uint32_t*)(0x00002000));
    user_app();
    while (1) {
    };
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

uint32_t is_page_modify_en(uint32_t page_num, FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type)
{
    uint32_t data;
    uint32_t temp;
    uint32_t bflock[BFLOCK_SIZE / 4];
    uint32_t uflock[UFLOCK_SIZE / 4];
    uint32_t modify_en = 0;

    if (flash_type == FLASH_NVR) {
        for (uint32_t i = 0; i < CFGWORD_SIZE; i++) {
            flash_read(CFGWORD_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
            *((uint8_t*)(&temp) + i) = (uint8_t)data;
        }
        if (flash_mem == BOOTFLASH_MEM)
            modify_en = (temp & CFGWORD_LOCKIFBLF_MSK) >> CFGWORD_LOCKIFBLF_POS;
        else
            modify_en = (temp & CFGWORD_LOCKIFBUF_MSK) >> CFGWORD_LOCKIFBUF_POS;
    } else {
        if (flash_mem == BOOTFLASH_MEM) {
            for (uint32_t i = 0; i < BFLOCK_SIZE; i++) {
                flash_read(BFLOCK_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
                *((uint8_t*)(bflock) + i) = (uint8_t)data;
            }
            modify_en = (bflock[page_num / 32] & (1 << (page_num % 32))) ? 1 : 0;
        } else {
            for (uint32_t i = 0; i < UFLOCK_SIZE; i++) {
                flash_read(UFLOCK_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
                *((uint8_t*)(uflock) + i) = (uint8_t)data;
            }
            modify_en = (uflock[page_num / 32] & (1 << (page_num % 32))) ? 1 : 0;
        }
    }

    return modify_en;
}

uint32_t is_page_read_en(uint32_t page_num, FlashMemory_TypeDef flash_mem, FlashType_TypeDef flash_type)
{
    uint32_t data;
    uint32_t temp;
    uint32_t read_en = 0;

    (void)page_num;

    for (uint32_t i = 0; i < CFGWORD_SIZE; i++) {
        flash_read(CFGWORD_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
        *((uint8_t*)(&temp) + i) = (uint8_t)data;
    }

    if (flash_type == FLASH_NVR) {
        if (flash_mem == BOOTFLASH_MEM)
            read_en = (temp & CFGWORD_BFIFBRE_MSK) >> CFGWORD_BFIFBRE_POS;
        else
            read_en = (temp & CFGWORD_UFIFBRE_MSK) >> CFGWORD_UFIFBRE_POS;
    } else {
        if (flash_mem == BOOTFLASH_MEM)
            read_en = (temp & CFGWORD_BFRE_MSK) >> CFGWORD_BFRE_POS;
        else
            read_en = (temp & CFGWORD_UFRE_MSK) >> CFGWORD_UFRE_POS;
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
        packet->tmp_data32[1] = 0x00000000;
        packet->tmp_data32[2] = SCB->CPUID;
        packet->tmp_data32[3] = BOOT_VER;
        packet->data_n = 16;
    }

    msg_cmd(packet);
}

void get_cfgword_cmd(Packet_TypeDef* packet)
{
    uint16_t rx_crc;
    uint32_t data;

    rx_crc = packet_fifo_read_u16();

    if (packet->crc != rx_crc) {
        packet->tmp_data8[0] = MSG_ERR_CRC;
        packet->data_n = 4;
    } else {
        packet->tmp_data8[0] = MSG_OK;
        packet->data_n = 4;
        for (uint32_t i = 0; i < CFGWORD_SIZE; i++) {
            flash_read(CFGWORD_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
            packet->tmp_data8[packet->data_n] = (uint8_t)data;
            packet->data_n++;
        }
        for (uint32_t i = 0; i < BFLOCK_SIZE; i++) {
            flash_read(BFLOCK_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
            packet->tmp_data8[packet->data_n] = (uint8_t)data;
            packet->data_n++;
        }
        for (uint32_t i = 0; i < UFLOCK_SIZE; i++) {
            flash_read(UFLOCK_OFFSET + i, USERFLASH_MEM, FLASH_NVR, &data);
            packet->tmp_data8[packet->data_n] = (uint8_t)data;
            packet->data_n++;
        }
    }

    msg_cmd(packet);
}

void set_cfgword_cmd(Packet_TypeDef* packet)
{
    uint32_t cfgword;
    uint32_t bflock[BFLOCK_SIZE / 4];
    uint32_t uflock[UFLOCK_SIZE / 4];
    uint16_t rx_crc;
    uint16_t calc_crc;
    union {
        uint8_t data8[USERFLASH_NVR_PAGE_SIZE_BYTES];
        uint32_t data32[USERFLASH_NVR_PAGE_SIZE_BYTES / 4];
    } page_arr;
    uint32_t data;
    uint32_t modify_en;

    modify_en = is_page_modify_en(0, USERFLASH_MEM, FLASH_NVR);

    cfgword = packet_fifo_read_u32();
    calc_crc = crc_upd_u32(packet->crc, cfgword);
    for (uint32_t i = 0; i < BFLOCK_SIZE / 4; i++) {
        bflock[i] = packet_fifo_read_u32();
        calc_crc = crc_upd_u32(calc_crc, bflock[i]);
    }
    for (uint32_t i = 0; i < UFLOCK_SIZE / 4; i++) {
        uflock[i] = packet_fifo_read_u32();
        calc_crc = crc_upd_u32(calc_crc, uflock[i]);
    }

    rx_crc = packet_fifo_read_u16();

    packet->data_n = 4;
    if (calc_crc != rx_crc)
        packet->tmp_data8[0] = MSG_ERR_CRC;
    else if (!modify_en)
        packet->tmp_data8[0] = MSG_FAIL;
    else {
        //читаем всю страницу
        for (uint32_t i = 0; i < USERFLASH_NVR_PAGE_SIZE_BYTES; i++) {
            flash_read(i, USERFLASH_MEM, FLASH_NVR, &data);
            page_arr.data8[i] = (uint8_t)data;
        }
        //модифицируем конфигурацию, стираем и пишем обратно
        page_arr.data32[CFGWORD_OFFSET / 4] = cfgword;
        for (uint32_t i = 0; i < BFLOCK_SIZE / 4; i++) {
            page_arr.data32[(BFLOCK_OFFSET / 4) + i] = bflock[i];
        }
        for (uint32_t i = 0; i < UFLOCK_SIZE / 4; i++) {
            page_arr.data32[(UFLOCK_OFFSET / 4) + i] = uflock[i];
        }
        flash_erase_page(CFGWORD_OFFSET, USERFLASH_MEM, FLASH_NVR);
        for (uint32_t i = 0; i < USERFLASH_NVR_PAGE_SIZE_BYTES; i++) {
            if (page_arr.data8[i] != 0xFF) {
                data = page_arr.data8[i];
                flash_write(i, USERFLASH_MEM, FLASH_NVR, &data);
            }
        }
        //контроль записанного
        packet->tmp_data8[0] = MSG_OK;
        for (uint32_t i = 0; i < USERFLASH_NVR_PAGE_SIZE_BYTES; i++) {
            flash_read(i, USERFLASH_MEM, FLASH_NVR, &data);
            if (page_arr.data8[i] != (uint8_t)data)
                packet->tmp_data8[0] = MSG_FAIL;
            break;
        }
    }

    packet->tmp_data32[packet->data_n / 4] = cfgword;
    packet->data_n += 4;
    for (uint32_t i = 0; i < BFLOCK_SIZE / 4; i++) {
        packet->tmp_data32[(packet->data_n / 4) + i] = bflock[i];
        packet->data_n += 4;
    }
    for (uint32_t i = 0; i < UFLOCK_SIZE / 4; i++) {
        packet->tmp_data32[(packet->data_n / 4) + i] = uflock[i];
        packet->data_n += 4;
    }

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
    uint32_t data[4];
    uint32_t temp;
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t modify_en;
    uint32_t page_num;

    //читаем адрес, определяем необходимый тип флеш и номер страницы, затем стираем её если нужно
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BOOTFLASH_MEM) {
        addr = rx_data & ~(BOOTFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / BOOTFLASH_PAGE_SIZE_BYTES;
    } else {
        addr = rx_data & ~(USERFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / USERFLASH_PAGE_SIZE_BYTES;
    }

    //можно ли изменять страницу
    modify_en = is_page_modify_en(page_num, flash_mem, flash_type);

    //надо ли стирать перед записью
    erase_option = (cfg & CMD_WRITE_PAGE_OPT_ERASE_MSK) >> CMD_WRITE_PAGE_OPT_ERASE_POS;

    //защита от модификации бутлоадера
    modify_en &= !((flash_mem == BOOTFLASH_MEM) && (flash_type == FLASH_NVR));

    if (erase_option && modify_en)
        flash_erase_page(addr, flash_mem, flash_type);
    calc_crc = crc_upd_u32(packet->crc, rx_data);

    addr_i = addr;
    if (flash_mem == BOOTFLASH_MEM) {
        //читаем по 16 байт данных и пишем всю страницу
        for (uint32_t i = 0; i < BOOTFLASH_PAGE_SIZE_BYTES / 16; i++) {
            data[0] = packet_fifo_read_u32();
            data[1] = packet_fifo_read_u32();
            data[2] = packet_fifo_read_u32();
            data[3] = packet_fifo_read_u32();
            if (modify_en)
                flash_write(addr_i, flash_mem, flash_type, data);
            calc_crc = crc_upd_u32(calc_crc, data[0]);
            calc_crc = crc_upd_u32(calc_crc, data[1]);
            calc_crc = crc_upd_u32(calc_crc, data[2]);
            calc_crc = crc_upd_u32(calc_crc, data[3]);
            addr_i += 16;
        }
    } else {
        //читаем по 4 байта данных и пишем всю страницу
        for (uint32_t i = 0; i < USERFLASH_PAGE_SIZE_BYTES / 4; i++) {
            data[0] = packet_fifo_read_u32();
            if (modify_en) {
                for (uint32_t b = 0; b < 4; b++) {
                    temp = *((uint8_t*)(&data) + b);
                    flash_write(addr_i, flash_mem, flash_type, &temp);
                    addr_i++;
                }
            }
            calc_crc = crc_upd_u32(calc_crc, data[0]);
        }
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
    uint32_t data[4];
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t read_en;
    uint32_t page_num;

    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BOOTFLASH_MEM) {
        addr = rx_data & ~(BOOTFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / BOOTFLASH_PAGE_SIZE_BYTES;
    } else {
        addr = rx_data & ~(USERFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / USERFLASH_PAGE_SIZE_BYTES;
    }

    //может ли хост читать флэш
    read_en = is_page_read_en(page_num, flash_mem, flash_type);

    //защита от чтения бутлоадера
    read_en &= !((flash_mem == BOOTFLASH_MEM) && (flash_type == FLASH_NVR));

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
        if (flash_mem == BOOTFLASH_MEM) {
            for (uint32_t i = 0; i < BOOTFLASH_PAGE_SIZE_BYTES / 16; i++) {
                flash_read(addr_i, flash_mem, flash_type, data);
                packet->tmp_data32[2 + i * 4] = data[0];
                packet->tmp_data32[2 + i * 4 + 1] = data[1];
                packet->tmp_data32[2 + i * 4 + 2] = data[2];
                packet->tmp_data32[2 + i * 4 + 3] = data[3];
                addr_i += 16;
            }
            packet->data_n += BOOTFLASH_PAGE_SIZE_BYTES;
        } else {
            for (uint32_t i = 0; i < USERFLASH_PAGE_SIZE_BYTES; i++) {
                flash_read(addr_i, flash_mem, flash_type, data);
                packet->tmp_data8[8 + i] = (uint8_t)data[0];
                addr_i += 1;
            }
            packet->data_n += USERFLASH_PAGE_SIZE_BYTES;
        }
        packet->tmp_data8[0] = MSG_OK;
    }

    msg_cmd(packet);
}

void erase_full_cmd(Packet_TypeDef* packet)
{
    uint32_t rx_data;
    uint8_t cfg;
    uint32_t addr;
    uint32_t flash_type;
    uint32_t flash_mem;
    uint16_t rx_crc;
    uint16_t calc_crc;
    uint32_t modify_en;
    uint32_t page_num;

    //читаем адрес, определяем необходимый тип флеш и затем стираем её
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BOOTFLASH_MEM) {
        addr = rx_data & ~(BOOTFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / BOOTFLASH_PAGE_SIZE_BYTES;
    } else {
        addr = rx_data & ~(USERFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / USERFLASH_PAGE_SIZE_BYTES;
    }

    //можно ли изменять страницу
    modify_en = is_page_modify_en(page_num, flash_mem, flash_type);

    //защита от модификации бутлоадера
    modify_en &= !((flash_mem == BOOTFLASH_MEM) && (flash_type == FLASH_NVR));

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
    uint32_t page_num;

    //читаем адрес, определяем необходимый тип флеш и номер страницы, затем стираем её
    rx_data = packet_fifo_read_u32();

    //конфигурация
    cfg = (uint8_t)(rx_data >> 24);

    //определяем тип флэш
    flash_type = (FlashType_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_NVR_MSK) >> CMD_WRITE_PAGE_OPT_NVR_POS);
    flash_mem = (FlashMemory_TypeDef)((cfg & CMD_WRITE_PAGE_OPT_MEMORY_MSK) >> CMD_WRITE_PAGE_OPT_MEMORY_POS);

    //адрес
    if (flash_mem == BOOTFLASH_MEM) {
        addr = rx_data & ~(BOOTFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / BOOTFLASH_PAGE_SIZE_BYTES;
    } else {
        addr = rx_data & ~(USERFLASH_PAGE_SIZE_BYTES - 1) & 0x00FFFFFF;
        page_num = addr / USERFLASH_PAGE_SIZE_BYTES;
    }

    //можно ли изменять страницу
    modify_en = is_page_modify_en(page_num, flash_mem, flash_type);

    //защита от модификации бутлоадера
    modify_en &= !((flash_mem == BOOTFLASH_MEM) && (flash_type == FLASH_NVR));

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
