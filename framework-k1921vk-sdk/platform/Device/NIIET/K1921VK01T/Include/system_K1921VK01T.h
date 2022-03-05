/*==============================================================================
 * Инициализация К1921ВК01Т
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

#ifndef SYSTEM_K1921VK01T_H
#define SYSTEM_K1921VK01T_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include <stdint.h>

//-- Defines -------------------------------------------------------------------
#define OSICLK_VAL 5000000
#ifndef OSECLK_VAL
#define OSECLK_VAL 0
#endif
#define PLL_STABLE_TIMEOUT 1000
#define SYSCLK_SWITCH_TIMEOUT 10000

//-- Variables -----------------------------------------------------------------
extern uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)

//-- Functions -----------------------------------------------------------------
// Initialize the System
extern void SystemInit(void);
// Updates the SystemCoreClock with current core Clock retrieved from registers
extern void SystemCoreClockUpdate(void);

#if defined (__CMCPPARM__)
void NMI_Handler(void);           /* NMI Handler */
void HardFault_Handler(void);     /* Hard Fault Handler */
void MemManage_Handler(void);     /* MPU Fault Handler */
void BusFault_Handler(void);      /* Bus Fault Handler */
void UsageFault_Handler(void);    /* Usage Fault Handler */
void SVC_Handler(void);           /* SVCall Handler */
void DebugMon_Handler(void);      /* Debug Monitor Handler */
void PendSV_Handler(void);        /* PendSV Handler */
void SysTick_Handler(void);       /* SysTick Handler */
/* External interrupts */
void WWDG_IRQHandler(void);
void I2C0_IRQHandler(void);
void I2C1_IRQHandler(void);
void TIM0_IRQHandler(void);
void TIM1_IRQHandler(void);
void TIM2_IRQHandler(void);
void DMA_Stream0_IRQHandler(void);
void DMA_Stream1_IRQHandler(void);
void DMA_Stream2_IRQHandler(void);
void DMA_Stream3_IRQHandler(void);
void DMA_Stream4_IRQHandler(void);
void DMA_Stream5_IRQHandler(void);
void DMA_Stream6_IRQHandler(void);
void DMA_Stream7_IRQHandler(void);
void DMA_Stream8_IRQHandler(void);
void DMA_Stream9_IRQHandler(void);
void DMA_Stream10_IRQHandler(void);
void DMA_Stream11_IRQHandler(void);
void DMA_Stream12_IRQHandler(void);
void DMA_Stream13_IRQHandler(void);
void DMA_Stream14_IRQHandler(void);
void DMA_Stream15_IRQHandler(void);
void DMA_Stream16_IRQHandler(void);
void DMA_Stream17_IRQHandler(void);
void DMA_Stream18_IRQHandler(void);
void DMA_Stream19_IRQHandler(void);
void DMA_Stream20_IRQHandler(void);
void DMA_Stream21_IRQHandler(void);
void DMA_Stream22_IRQHandler(void);
void DMA_Stream23_IRQHandler(void);
void UART0_MX_IRQHandler(void);
void UART0_RX_IRQHandler(void);
void UART0_TX_IRQHandler(void);
void UART0_RT_IRQHandler(void);
void UART0_E_IRQHandler(void);
void UART0_IRQHandler(void);
void UART1_MX_IRQHandler(void);
void UART1_RX_IRQHandler(void);
void UART1_TX_IRQHandler(void);
void UART1_RT_IRQHandler(void);
void UART1_E_IRQHandler(void);
void UART1_IRQHandler(void);
void UART2_MX_IRQHandler(void);
void UART2_RX_IRQHandler(void);
void UART2_TX_IRQHandler(void);
void UART2_RT_IRQHandler(void);
void UART2_E_IRQHandler(void);
void UART2_IRQHandler(void);
void UART3_MX_IRQHandler(void);
void UART3_RX_IRQHandler(void);
void UART3_TX_IRQHandler(void);
void UART3_RT_IRQHandler(void);
void UART3_E_IRQHandler(void);
void UART3_IRQHandler(void);
void PWM0_IRQHandler(void);
void PWM0_HD_IRQHandler(void);
void PWM0_TZ_IRQHandler(void);
void PWM1_IRQHandler(void);
void PWM1_HD_IRQHandler(void);
void PWM1_TZ_IRQHandler(void);
void PWM2_IRQHandler(void);
void PWM2_HD_IRQHandler(void);
void PWM2_TZ_IRQHandler(void);
void PWM3_IRQHandler(void);
void PWM3_HD_IRQHandler(void);
void PWM3_TZ_IRQHandler(void);
void PWM4_IRQHandler(void);
void PWM4_HD_IRQHandler(void);
void PWM4_TZ_IRQHandler(void);
void PWM5_IRQHandler(void);
void PWM5_HD_IRQHandler(void);
void PWM5_TZ_IRQHandler(void);
void PWM6_IRQHandler(void);
void PWM6_HD_IRQHandler(void);
void PWM6_TZ_IRQHandler(void);
void PWM7_IRQHandler(void);
void PWM7_HD_IRQHandler(void);
void PWM7_TZ_IRQHandler(void);
void PWM8_IRQHandler(void);
void PWM8_HD_IRQHandler(void);
void PWM8_TZ_IRQHandler(void);
void ADC_SEQ0_IRQHandler(void);
void ADC_SEQ1_IRQHandler(void);
void ADC_SEQ2_IRQHandler(void);
void ADC_SEQ3_IRQHandler(void);
void ADC_SEQ4_IRQHandler(void);
void ADC_SEQ5_IRQHandler(void);
void ADC_SEQ6_IRQHandler(void);
void ADC_SEQ7_IRQHandler(void);
void ADC_CompInt_IRQHandler(void);
void CAP0_IRQHandler(void);
void CAP1_IRQHandler(void);
void CAP2_IRQHandler(void);
void CAP3_IRQHandler(void);
void CAP4_IRQHandler(void);
void CAP5_IRQHandler(void);
void QEP0_IRQHandler(void);
void QEP1_IRQHandler(void);
void BootFlash_IRQHandler(void);
void CMP0_IRQHandler(void);
void CMP1_IRQHandler(void);
void CMP2_IRQHandler(void);
void SPI0_IRQHandler(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void SPI3_IRQHandler(void);
void UserFlash_IRQHandler(void);
void GPIOA_IRQHandler(void);
void GPIOB_IRQHandler(void);
void GPIOC_IRQHandler(void);
void GPIOD_IRQHandler(void);
void GPIOE_IRQHandler(void);
void GPIOF_IRQHandler(void);
void GPIOG_IRQHandler(void);
void GPIOH_IRQHandler(void);
void Ethernet_IRQHandler(void);
void CAN0_IRQHandler(void);
void CAN1_IRQHandler(void);
void CAN2_IRQHandler(void);
void CAN3_IRQHandler(void);
void CAN4_IRQHandler(void);
void CAN5_IRQHandler(void);
void CAN6_IRQHandler(void);
void CAN7_IRQHandler(void);
void CAN8_IRQHandler(void);
void CAN9_IRQHandler(void);
void CAN10_IRQHandler(void);
void CAN11_IRQHandler(void);
void CAN12_IRQHandler(void);
void CAN13_IRQHandler(void);
void CAN14_IRQHandler(void);
void CAN15_IRQHandler(void);
void RTC_IRQHandler(void);
void USBOTG_IRQHandler(void);
#endif

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_K1921VK01T_H
