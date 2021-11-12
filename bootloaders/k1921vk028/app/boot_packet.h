/*==============================================================================
 * UART загрузчик для К1921ВК028
 *
 * Прототипы функций работы с пакетами.
 * Перед использованием необходмо осуществить инициализацию
 * с помощью packet_init().
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

#ifndef BOOT_PACKET_H
#define BOOT_PACKET_H

//--- Includes -----------------------------------------------------------------
#include "boot_conf.h"

//--- Defines ------------------------------------------------------------------
// clang-format off
//Command write page flash options
#define CMD_WRITE_PAGE_OPT_MEMORY_POS   5
#define CMD_WRITE_PAGE_OPT_MEMORY_MSK   (1<<CMD_WRITE_PAGE_OPT_MEMORY_POS)
#define CMD_WRITE_PAGE_OPT_ERASE_POS    6
#define CMD_WRITE_PAGE_OPT_ERASE_MSK    (1<<CMD_WRITE_PAGE_OPT_ERASE_POS)
#define CMD_WRITE_PAGE_OPT_NVR_POS      7
#define CMD_WRITE_PAGE_OPT_NVR_MSK      (1<<CMD_WRITE_PAGE_OPT_NVR_POS)
#define CMD_READ_PAGE_OPT_NVR_POS       CMD_WRITE_PAGE_OPT_NVR_POS
#define CMD_READ_PAGE_OPT_NVR_MSK       CMD_WRITE_PAGE_OPT_NVR_MSK
#define CMD_READ_PAGE_OPT_MEMORY_POS    CMD_WRITE_PAGE_OPT_MEMORY_POS
#define CMD_READ_PAGE_OPT_MEMORY_MSK    CMD_WRITE_PAGE_OPT_MEMORY_MSK
// clang-format on

//--- Types --------------------------------------------------------------------
//Полный список команд загрузчика
typedef enum {
    //Get commands
    CMD_GET_INFO = 0x35,
    CMD_GET_CFGWORD = 0x3A,
    // Set commands
    CMD_SET_CFGWORD = 0x65,
    CMD_SET_BAUDRATE = 0x6A,
    // Write commands
    CMD_WRITE_PAGE = 0x9A,
    // Read commands
    CMD_READ_PAGE = 0xA5,
    // Erase commands
    CMD_ERASE_FULL = 0xC5,
    CMD_ERASE_PAGE = 0xCA,
    //Misc
    CMD_NONE = 0x00,
    CMD_EXIT = 0xF5,
    CMD_MSG = 0xFA,
} CmdCode_TypeDef;

//Сообщения для команды CMD_MSG
typedef enum {
    MSG_NONE,
    MSG_ERR_CMD,
    MSG_ERR_CRC,
    MSG_READY,
    MSG_OK,
    MSG_FAIL
} MsgCode_TypeDef;

//Структура пакета
typedef struct
{
    CmdCode_TypeDef cmd_code;
    uint16_t data_n;
    uint16_t crc;
    union { //дополнительные байты временной информации для внутренних целей
        uint8_t tmp_data8[PACKET_TMP_DATA_BYTES];
        uint16_t tmp_data16[PACKET_TMP_DATA_BYTES / 2];
        uint32_t tmp_data32[PACKET_TMP_DATA_BYTES / 4];
    };
} Packet_TypeDef;

//--- Function prototypes ------------------------------------------------------
RAMFUNC void packet_fifo_init();
RAMFUNC uint8_t packet_fifo_read();
RAMFUNC uint32_t packet_fifo_read_u32();
RAMFUNC uint16_t packet_fifo_read_u16();
RAMFUNC void packet_recieve(Packet_TypeDef* cmd);
RAMFUNC void packet_transmit(Packet_TypeDef* tx_packet);
RAMFUNC uint32_t packet_transmit_status_busy();
RAMFUNC uint16_t crc_upd(uint16_t crc_in, uint8_t data);
RAMFUNC uint16_t crc_upd_u32(uint16_t crc_in, uint32_t data);
RAMFUNC uint16_t crc_upd_u16(uint16_t crc_in, uint16_t data);

#endif //BOOT_PACKET_H
