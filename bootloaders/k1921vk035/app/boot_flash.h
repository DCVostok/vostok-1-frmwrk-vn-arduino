/*==============================================================================
 * UART загрузчик для К1921ВК035
 *
 * Прототипы функций работы с флеш-памятью
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

#ifndef BOOT_FLASH_H
#define BOOT_FLASH_H

//--- Includes -----------------------------------------------------------------
#include "boot_conf.h"

//--- Defines ------------------------------------------------------------------
// clang-format off
#define FLASH_MAGICKEY_CONST        0xC0DEUL
#define FLASH_PAGE_SIZE_BYTES       1024UL
#define FLASH_PAGE_SIZE_BYTES_LOG2  10UL
#define FLASH_PAGE_TOTAL            64UL
#define FLASH_TOTAL_BYTES           (FLASH_PAGE_SIZE_BYTES*FLASH_PAGE_TOTAL)
#define FLASH_NVR_PAGE_SIZE_BYTES   FLASH_PAGE_SIZE_BYTES
#define FLASH_NVR_PAGE_TOTAL        4UL
#define FLASH_NVR_TOTAL_BYTES       (FLASH_NVR_PAGE_SIZE_BYTES*FLASH_NVR_PAGE_TOTAL)
#define FLASH_NVR_CFGWORD_OFFSET    (3*FLASH_NVR_PAGE_SIZE_BYTES)

#define CFGWORD_FLASHWE_POS         3
#define CFGWORD_NVRWE_POS           2
#define CFGWORD_NVRRE_POS           6
#define CFGWORD_FLASHRE_POS         7
#define CFGWORD_FLASHWE_MSK         (1<<CFGWORD_FLASHWE_POS)
#define CFGWORD_NVRWE_MSK           (1<<CFGWORD_NVRWE_POS)
#define CFGWORD_NVRRE_MSK           (1<<CFGWORD_NVRRE_POS)
#define CFGWORD_FLASHRE_MSK         (1<<CFGWORD_FLASHRE_POS)
// clang-format on

//--- Types --------------------------------------------------------------------
typedef enum {
    FLASH_MAIN = 0,
    FLASH_NVR = 1
} FlashType_TypeDef;

typedef enum {
    FLASH_RD = MFLASH_CMD_RD_Msk,
    FLASH_WR = MFLASH_CMD_WR_Msk,
    FLASH_ERSEC = MFLASH_CMD_ERSEC_Msk,
    FLASH_ERALL = MFLASH_CMD_ERALL_Msk
} FlashCmd_TypeDef;

//--- Function prototypes ------------------------------------------------------
RAMFUNC void flash_read(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data);
RAMFUNC void flash_write(uint32_t addr, FlashType_TypeDef ftype, uint32_t* data);
RAMFUNC void flash_erase_page(uint32_t addr, FlashType_TypeDef ftype);
RAMFUNC void flash_erase_full();
RAMFUNC void flash_disable_boot();

#endif //BOOT_FLASH_H
