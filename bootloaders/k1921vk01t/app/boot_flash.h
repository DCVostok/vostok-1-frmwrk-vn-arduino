/*==============================================================================
 * UART загрузчик для К1921ВК01T
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
// clang-format off
#define FLASH_MAGICKEY_CONST            0xA442UL
#define BOOTFLASH_PAGE_SIZE_BYTES       8192UL
#define BOOTFLASH_PAGE_SIZE_BYTES_LOG2  13UL
#define BOOTFLASH_PAGE_TOTAL            128UL
#define BOOTFLASH_TOTAL_BYTES           (BOOTFLASH_PAGE_SIZE_BYTES*BOOTFLASH_PAGE_TOTAL)
#define BOOTFLASH_NVR_PAGE_SIZE_BYTES   BOOTFLASH_PAGE_SIZE_BYTES
#define BOOTFLASH_NVR_PAGE_TOTAL        1UL
#define BOOTFLASH_NVR_TOTAL_BYTES       (FLASH_NVR_PAGE_SIZE_BYTES*FLASH_NVR_PAGE_TOTAL)

#define USERFLASH_PAGE_SIZE_BYTES       256UL
#define USERFLASH_PAGE_SIZE_BYTES_LOG2  8UL
#define USERFLASH_PAGE_TOTAL            256UL
#define USERFLASH_TOTAL_BYTES           (USERFLASH_PAGE_SIZE_BYTES*USERFLASH_PAGE_TOTAL)
#define USERFLASH_NVR_PAGE_SIZE_BYTES   USERFLASH_PAGE_SIZE_BYTES
#define USERFLASH_NVR_PAGE_TOTAL        2UL
#define USERFLASH_NVR_TOTAL_BYTES       (USERFLASH_NVR_PAGE_SIZE_BYTES*USERFLASH_NVR_PAGE_TOTAL)

#define CFGWORD_OFFSET              0x00UL
#define CFGWORD_SIZE                4UL
#define BFLOCK_OFFSET               0x40UL
#define BFLOCK_SIZE                 16UL
#define UFLOCK_OFFSET               0x80UL
#define UFLOCK_SIZE                 32UL

#define CFGWORD_BOOTFROMIFB_POS     0
#define CFGWORD_ENGPIO_POS          1
#define CFGWORD_EXTMEMSEL_POS       3
#define CFGWORD_PINNUM_POS          8
#define CFGWORD_PORTNUM_POS         12
#define CFGWORD_LOCKIFBLF_POS       16
#define CFGWORD_BFRE_POS            17
#define CFGWORD_BFIFBRE_POS         18
#define CFGWORD_LOCKIFBUF_POS       24
#define CFGWORD_UFRE_POS            25
#define CFGWORD_UFIFBRE_POS         26

#define CFGWORD_BOOTFROMIFB_MSK  (1 << CFGWORD_BOOTFROMIFB_POS)
#define CFGWORD_ENGPIO_MSK       (1 << CFGWORD_ENGPIO_POS     )
#define CFGWORD_EXTMEMSEL_MSK    (1 << CFGWORD_EXTMEMSEL_POS  )
#define CFGWORD_PINNUM_MSK       (1 << CFGWORD_PINNUM_POS     )
#define CFGWORD_PORTNUM_MSK      (1 << CFGWORD_PORTNUM_POS    )
#define CFGWORD_LOCKIFBLF_MSK    (1 << CFGWORD_LOCKIFBLF_POS  )
#define CFGWORD_BFRE_MSK         (1 << CFGWORD_BFRE_POS       )
#define CFGWORD_BFIFBRE_MSK      (1 << CFGWORD_BFIFBRE_POS    )
#define CFGWORD_LOCKIFBUF_MSK    (1 << CFGWORD_LOCKIFBUF_POS  )
#define CFGWORD_UFRE_MSK         (1 << CFGWORD_UFRE_POS       )
#define CFGWORD_UFIFBRE_MSK      (1 << CFGWORD_UFIFBRE_POS    )

// clang-format on

//--- Types --------------------------------------------------------------------
typedef enum {
    FLASH_MAIN = 0,
    FLASH_NVR = 1
} FlashType_TypeDef;

typedef enum {
    BOOTFLASH_MEM = 0,
    USERFLASH_MEM = 1
} FlashMemory_TypeDef;

//--- Function prototypes ------------------------------------------------------
RAMFUNC void flash_read(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data);
RAMFUNC void flash_write(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype, uint32_t* data);
RAMFUNC void flash_erase_page(uint32_t addr, FlashMemory_TypeDef fmem, FlashType_TypeDef ftype);
RAMFUNC void flash_erase_full(FlashMemory_TypeDef fmem, FlashType_TypeDef ftype);

#endif //BOOT_FLASH_H
