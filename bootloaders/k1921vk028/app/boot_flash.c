/*==============================================================================
 * UART загрузчик для К1921ВК028
 *
 * Функции работы с флеш-памятью.
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
#include "boot_flash.h"

//-- Private types -------------------------------------------------------------
typedef enum {
    FLASH_RD = MFLASH_CMD_RD_Msk,
    FLASH_WR = MFLASH_CMD_WR_Msk,
    FLASH_ERSEC = MFLASH_CMD_ERSEC_Msk,
    FLASH_ERALL = MFLASH_CMD_ERSEC_Msk | MFLASH_CMD_ALLSEC_Msk,
} FlashCmd_TypeDef;

//-- Private functions ---------------------------------------------------------
static RAMFUNC void mflash_cmd(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data, FlashCmd_TypeDef cmd)
{
    while (MFLASH->STAT_bit.BUSY) {
    };
    MFLASH->ADDR = addr;
    if (cmd == FLASH_WR) {
        for (uint32_t i = 0; i < MEM_MFLASH_BUS_WIDTH_WORDS; i++) {
            MFLASH->DATA[i].DATA = data[i];
        }
    }
    MFLASH->CMD = (MFLASH_CMD_KEY_Access << MFLASH_CMD_KEY_Pos) |
                  cmd | (ftype << MFLASH_CMD_NVRON_Pos);
    MFLASH->CTRL |= MFLASH_CTRL_DFLUSH_Msk | MFLASH_CTRL_IFLUSH_Msk;
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    if (cmd == FLASH_RD) {
        while (MFLASH->STAT_bit.BUSY) {
        };
        for (uint32_t i = 0; i < MEM_MFLASH_BUS_WIDTH_WORDS; i++) {
            data[i] = MFLASH->DATA[i].DATA;
        }
    }
}

static RAMFUNC void bflash_cmd(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data, FlashCmd_TypeDef cmd)
{
    while (BFLASH->STAT_bit.BUSY) {
    };
    BFLASH->ADDR = addr;
    if (cmd == FLASH_WR) {
        for (uint32_t i = 0; i < MEM_BFLASH_BUS_WIDTH_WORDS; i++) {
            BFLASH->DATA[i].DATA = data[i];
        }
    }
    BFLASH->CMD = (BFLASH_CMD_KEY_Access << BFLASH_CMD_KEY_Pos) |
                  cmd | (ftype << BFLASH_CMD_NVRON_Pos);
    BFLASH->CTRL |= BFLASH_CTRL_CFLUSH_Msk;
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    if (cmd == FLASH_RD) {
        while (BFLASH->STAT_bit.BUSY) {
        };
        for (uint32_t i = 0; i < MEM_BFLASH_BUS_WIDTH_WORDS; i++) {
            data[i] = BFLASH->DATA[i].DATA;
        }
    }
}

//-- Functions -----------------------------------------------------------------
void flash_read(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data)
{
    if (fmem == MFLASH_MEM)
        mflash_cmd(addr, ftype, data, FLASH_RD);
    else
        bflash_cmd(addr, ftype, data, FLASH_RD);
}

void flash_write(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data)
{
    if (fmem == MFLASH_MEM)
        mflash_cmd(addr, ftype, data, FLASH_WR);
    else
        bflash_cmd(addr, ftype, data, FLASH_WR);
}

void flash_erase_page(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype)
{
    if (fmem == MFLASH_MEM)
        mflash_cmd(addr, ftype, NULL, FLASH_ERSEC);
    else
        bflash_cmd(addr, ftype, NULL, FLASH_ERSEC);
}

void flash_erase_full(FlashMemory_TypeDef fmem, FlashType_TypeDef ftype)
{
    if (fmem == MFLASH_MEM)
        mflash_cmd(0, ftype, NULL, FLASH_ERALL);
    else
        bflash_cmd(0, ftype, NULL, FLASH_ERALL);
}
