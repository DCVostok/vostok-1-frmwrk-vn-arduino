/**
  *******************************************************************************
  * @file    niietcm4_irq.с
  *
  * @brief   Файл содержит реализацию всех функций для назначения обработчиков
  *          прерываний во время выполнения программы
  *
  * @author  Виктор Коробковский, vitkorob@gmail.com
  *
  *          НИИЭТ
  *             - Богдан Колбов (bkolbov), kolbov@niiet.ru
  *
  * @date    03.08.2016
  *
  *******************************************************************************
  * @attention
  *
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
  * <h2><center>&copy; 2016 ОАО "НИИЭТ"</center></h2>
  *******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "niietcm4_irq.h"

/** @addtogroup Misc
  * @{
  */

/** @defgroup IRQ
  * @brief Назначение обработчиков прерываний во время выполнения программы
  * @{
  */

/** @defgroup IRQ_Private Приватные данные
  * @{
  */

/** @defgroup IRQ_Private_Macros Приватные макросы
  * @{
  */

/**
  * @brief Проверка выравнивания RAM таблицы векторов
  */

#define IS_VECTORS_ALIGNED(VECTORS) (((uint32_t)VECTORS & 0x3ff) == 0)

/**
 * @}
 */

/** @defgroup IRQ_Private_Functions Приватные функции
  * @{
  */

#if defined (__ICCARM__)
    #pragma data_alignment=1024
    static __no_init void (*Vectors[IRQ_TOTAL])(void) @ "VTABLE";
#elif defined (__GNUC__)
    static __attribute__((section("vtable")))
    void (*Vectors[IRQ_TOTAL])(void) __attribute__((aligned(1024)));
#elif defined (__CC_ARM)
    static __attribute__((section("vtable")))
    void (*Vectors[IRQ_TOTAL])(void) __attribute__((aligned(1024)));
#elif defined (__CMCPPARM__)
    void (*Vectors[IRQ_TOTAL])(void);
    #pragma locate Vectors 0x20000000 noinit
#else
    #error "Нет реализации под данный компилятор"
#endif

/*
 * This is the default interrupt handler for all interrupts. It simply loops
 * forever so that the system state is preserved for observation by a
 * debugger. Since interrupts should be disabled before unregistering the
 * corresponding handler, this should never be called.
 */
static void IntDefaultHandler(void)
{
    while (1)
    {
        // Capture
    }
}

/**
  * @brief  Назначает функцию для обработки прерывания.
  * @attention При первом вызове копирует таблицу векторов прерываний в ОЗУ МК, затем
  *   делает замену обработчика прерывания. При последующих вызовах осуществляется
  * только замена обработчиков прерываний.
  * @param  IRQn Идентификатор перывания.
  * @param  pfnHandler Указатель на функцию.
  * @retval Нет
  */

void IRQ_HandlerInit(IRQn_Type IRQn, void (*pfnHandler)(void))
{
    assert_param(IS_IRQ_NUM(IRQn));
    assert_param(IS_VECTORS_ALIGNED(Vectors));

    /*
     * See if the RAM vector table has been initialized.
     */
    if (SCB->VTOR != (uint32_t)Vectors)
    {
        uint32_t *src = (uint32_t *)SCB->VTOR;
        uint32_t *dst = (uint32_t *)Vectors;
        uint32_t n = IRQ_TOTAL;

        /*
         * Copy the vector table from the beginning of FLASH
         * to the RAM vector table.
         */
        while (n--)
            *dst++ = *src++;

        /*
         * Point the NVIC at the RAM vector table.
         */
        SCB->VTOR = (uint32_t)Vectors;
    }

    /*
     * Save the interrupt handler.
     */
    Vectors[IRQ_NUM(IRQn)] = pfnHandler;
}

/**
  * @brief  Назначает функцию-заглушку (бесконечный цикл) для обработки прерывания.
  * @attention Перед вызовом этой функции соответствующее прерывание должно быть деактивировано,
  *   иначе это может привести к зависанию всей программы микроконтроллера.
  * @param  IRQn идентификатор перывания.
  * @retval Нет
  */

void IRQ_HandlerDeInit(IRQn_Type IRQn)
{
    assert_param(IS_IRQ_NUM(IRQn));

    /*
     * Reset the interrupt handler.
     */
    Vectors[IRQ_NUM(IRQn)] = IntDefaultHandler;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2016 NIIET *****END OF FILE****/
