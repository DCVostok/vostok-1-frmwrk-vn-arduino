/*==============================================================================
 * UART загрузчик для К1921ВК035
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
 *                              2018 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "boot_flash.h"

//-- Private functions ---------------------------------------------------------
static RAMFUNC void flash_cmd(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data, FlashCmd_TypeDef cmd)
{
    __NOP();
    while (MFLASH->STAT_bit.BUSY) {
    };
    MFLASH->ADDR = addr;
    if (cmd == FLASH_WR) {
        MFLASH->DATA[0].DATA = data[0];
        MFLASH->DATA[1].DATA = data[1];
    }
    MFLASH->CMD = FLASH_MAGICKEY_CONST << MFLASH_CMD_KEY_Pos |
                  cmd | ftype << MFLASH_CMD_NVRON_Pos;
    if (cmd == FLASH_RD) {
        while (MFLASH->STAT_bit.BUSY) {
        };
        data[0] = MFLASH->DATA[0].DATA;
        data[1] = MFLASH->DATA[1].DATA;
    }
}

//-- Functions -----------------------------------------------------------------
void flash_read(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data)
{
    flash_cmd(addr, ftype, data, FLASH_RD);
}

void flash_write(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data)
{
    flash_cmd(addr, ftype, data, FLASH_WR);
    //~42.5us
}

void flash_erase_page(uint32_t addr, FlashType_TypeDef ftype)
{
    flash_cmd(addr, ftype, NULL, FLASH_ERSEC);
    //~4.570ms
}

void flash_erase_full()
{
    flash_cmd(0, FLASH_MAIN, NULL, FLASH_ERALL);
    //~35.071ms
}

void flash_disable_boot()
{
    MFLASH->BDIS = MFLASH_BDIS_BMDIS_Msk;
}
