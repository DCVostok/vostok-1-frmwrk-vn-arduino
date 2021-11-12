/*==============================================================================
 * UART загрузчик для К1921ВК028
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
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

#ifndef BOOT_FLASH_H
#define BOOT_FLASH_H

//--- Includes -----------------------------------------------------------------
#include "boot_conf.h"

//--- Defines ------------------------------------------------------------------
#define CFGWORD_PAGE (3 * MEM_BFLASH_NVR_PAGE_SIZE)

#define CFGWORD1_MFLASHRE_Pos 12
#define CFGWORD1_MNVRRE_Pos 13
#define CFGWORD1_BFLASHRE_Pos 14
#define CFGWORD1_BNVRRE_Pos 15
#define CFGWORD1_MFLASHRE_Msk (1 << CFGWORD1_MFLASHRE_Pos)
#define CFGWORD1_MNVRRE_Msk (1 << CFGWORD1_MNVRRE_Pos)
#define CFGWORD1_BFLASHRE_Msk (1 << CFGWORD1_BFLASHRE_Pos)
#define CFGWORD1_BNVRRE_Msk (1 << CFGWORD1_BNVRRE_Pos)

//--- Types --------------------------------------------------------------------
typedef enum {
    FLASH_MAIN = 0,
    FLASH_NVR = 1
} FlashType_TypeDef;

typedef enum {
    MFLASH_MEM = 0,
    BFLASH_MEM = 1
} FlashMemory_TypeDef;

//--- Function prototypes ------------------------------------------------------
RAMFUNC void flash_read(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data);
RAMFUNC void flash_write(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data);
RAMFUNC void flash_erase_page(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype);
RAMFUNC void flash_erase_full(FlashMemory_TypeDef fmem, FlashType_TypeDef ftype);

#endif //BOOT_FLASH_H
