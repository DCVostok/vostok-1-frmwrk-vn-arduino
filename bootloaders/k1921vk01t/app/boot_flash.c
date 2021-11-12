/*==============================================================================
 * UART загрузчик для К1921ВК01T
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
    FLASH_RD = USERFLASH_FMC_READ_Msk,
    FLASH_WR = USERFLASH_FMC_WRITE_Msk,
    FLASH_ERSEC = USERFLASH_FMC_PAGE_ERASE_Msk,
    FLASH_ERALL = USERFLASH_FMC_FULL_ERASE_Msk,
    FLASH_NVR_RD = USERFLASH_FMC_READ_IFB_Msk,
    FLASH_NVR_WR = USERFLASH_FMC_WRITE_IFB_Msk,
    FLASH_NVR_ERSEC = USERFLASH_FMC_PAGEERASE_IFB_Msk,
    FLASH_NVR_ERALL = 0
} FlashCmd_TypeDef;

//-- Private functions ---------------------------------------------------------
static volatile uint32_t bootflash_busy = 0;
static RAMFUNC void bootflash_cmd(uint32_t addr, uint32_t* data, FlashCmd_TypeDef cmd)
{
    while (bootflash_busy && (!NT_BOOTFLASH->FCIS)) {
    };
    bootflash_busy = 0;
    NT_BOOTFLASH->FCIC = 3;
    if (cmd == FLASH_RD) {
        if (addr >= BOOTFLASH_PAGE_SIZE_BYTES) {
            data[0] = *(volatile uint32_t*)(addr + 0x0);
            data[1] = *(volatile uint32_t*)(addr + 0x4);
            data[2] = *(volatile uint32_t*)(addr + 0x8);
            data[3] = *(volatile uint32_t*)(addr + 0xC);
        } else {
            data[0] = 0;
            data[1] = 0;
            data[2] = 0;
            data[3] = 0;
        }
    } else {
        NT_BOOTFLASH->FMA = addr;
        if (cmd == FLASH_WR) {
            NT_BOOTFLASH->FMD0 = data[0];
            NT_BOOTFLASH->FMD1 = data[1];
            NT_BOOTFLASH->FMD2 = data[2];
            NT_BOOTFLASH->FMD3 = data[3];
        }
        NT_BOOTFLASH->FMC = (FLASH_MAGICKEY_CONST << BOOTFLASH_FMC_MAGIC_KEY_Pos) | cmd;
        bootflash_busy = 1;
    }
}

static volatile uint32_t userflash_busy = 0;
static RAMFUNC void userflash_cmd(uint32_t addr, uint32_t* data, FlashCmd_TypeDef cmd)
{
    while (userflash_busy && (!NT_USERFLASH->FCIS)) {
    };
    userflash_busy = 0;
    NT_USERFLASH->FCIC = 3;

    NT_USERFLASH->FMA = addr;
    if ((cmd == FLASH_WR) || (cmd == FLASH_NVR_WR)) {
        NT_USERFLASH->FMD = data[0];
    }
    NT_USERFLASH->FMC = (FLASH_MAGICKEY_CONST << USERFLASH_FMC_MAGIC_KEY_Pos) | cmd;
    userflash_busy = 1;
    if ((cmd == FLASH_RD) || (cmd == FLASH_NVR_RD)) {
        while (!NT_USERFLASH->FCIS) {
        };
        data[0] = NT_USERFLASH->FMD;
    }
}

//-- Functions -----------------------------------------------------------------
void flash_read(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data)
{
    if (fmem == BOOTFLASH_MEM) {
        bootflash_cmd(addr, data, FLASH_RD);
    } else if (fmem == USERFLASH_MEM) {
        if (ftype == FLASH_MAIN) {
            userflash_cmd(addr, data, FLASH_RD);
        } else if (ftype == FLASH_NVR) {
            userflash_cmd(addr, data, FLASH_NVR_RD);
        }
    }
}

void flash_write(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data)
{
    if (fmem == BOOTFLASH_MEM) {
        bootflash_cmd(addr, data, FLASH_WR);
    } else if (fmem == USERFLASH_MEM) {
        if (ftype == FLASH_MAIN) {
            userflash_cmd(addr, data, FLASH_WR);
        } else if (ftype == FLASH_NVR) {
            userflash_cmd(addr, data, FLASH_NVR_WR);
        }
    }
}

void flash_erase_page(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype)
{
    if (fmem == BOOTFLASH_MEM) {
        bootflash_cmd(addr, NULL, FLASH_ERSEC);
    } else if (fmem == USERFLASH_MEM) {
        if (ftype == FLASH_MAIN) {
            userflash_cmd(addr, NULL, FLASH_ERSEC);
        } else if (ftype == FLASH_NVR) {
            userflash_cmd(addr, NULL, FLASH_NVR_ERSEC);
        }
    }
}

void flash_erase_full(FlashMemory_TypeDef fmem, FlashType_TypeDef ftype)
{
    if (fmem == BOOTFLASH_MEM) {
        bootflash_cmd(0, NULL, FLASH_ERALL);
    } else if (fmem == USERFLASH_MEM) {
        //FIXME: userflash full erase do nothing for now
        if (ftype == FLASH_MAIN) {
            userflash_cmd(0, NULL, FLASH_NVR_ERALL);
        } else if (ftype == FLASH_NVR) {
            userflash_cmd(0, NULL, FLASH_NVR_ERALL);
        }
    }
}
