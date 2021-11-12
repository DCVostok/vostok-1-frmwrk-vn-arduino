/**
******************************************************************************
* @file    K1921VK01T.h
* @author  Angioscan Electronics Application Team
* @version V1.3.4
* @date    01.04.2016
* @brief   This file contains all the Special Function Registers definitions
*          for the NIIET K1921VK01T microcontroller.
******************************************************************************
*
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, ANGIOSCAN ELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
*                 COPYRIGHT 2014 - 2016 Angioscan Electronics
*******************************************************************************
* FILE K1921VK01T.h
*/
/**
  * Patch log:
  *     - 14.02.2019 (SVD 2.1): return of GPIODSCTLx registers
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __K1921VK01T_H
#define __K1921VK01T_H

#define __I     volatile const                /*!< defines 'read only' permissions      */
#define __O     volatile                      /*!< defines 'write only' permissions     */
#define __IO    volatile                      /*!< defines 'read / write' permissions   */

/* Start of section using anonymous unions */
#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#endif

/* Configuration of the Cortex-M4F Processor and Core Peripherals */
#define __CM4F_REV             0x0100   /*!< Cortex-M4F Core Revision r0p1                */
#define __MPU_PRESENT             1     /*!< MPU present or not                           */
#define __NVIC_PRIO_BITS          3     /*!< Number of Bits used for Priority Levels      */
#define __Vendor_SysTickConfig    0     /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1     /*!< FPU present or not                           */

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                  K1921VK01T Interrupt Number Definition                    */
/******************************************************************************/

typedef enum IRQn
{
/*-- Cortex-M4F Processor Exceptions Numbers ---------------------------------*/
  NonMaskableInt_IRQn     = -14,      /*!<  2 Non Maskable Interrupt          */
  HardFault_IRQn          = -13,      /*!<  3 Hard Fault Interrupt            */
  SVCall_IRQn             = -5,       /*!< 11 SV Call Interrupt               */
  PendSV_IRQn             = -2,       /*!< 14 Pend SV Interrupt               */
  SysTick_IRQn            = -1,       /*!< 15 System Tick Timer Interrupt     */

/*-- K1921VK01T specific Interrupt Numbers -----------------------------------*/
  WWDG_IRQn                =  0,      /*!< WWDG interrupt                     */
  I2C0_IRQn                =  1,      /*!< I2C_0 interrupt                    */
  I2C1_IRQn                =  2,      /*!< I2C_1 interrupt                    */
  TIM0_IRQn                =  3,      /*!< TIMER0 interrupt                   */
  TIM1_IRQn                =  4,      /*!< TIMER1 interrupt                   */
  TIM2_IRQn                =  5,      /*!< TIMER2 interrupt                   */
  DMA_Stream0_IRQn         =  6,      /*!< DMA_Stream0 interrupt              */
  DMA_Stream1_IRQn         =  7,      /*!< DMA_Stream1 interrupt              */
  DMA_Stream2_IRQn         =  8,      /*!< DMA_Stream2 interrupt              */
  DMA_Stream3_IRQn         =  9,      /*!< DMA_Stream3 interrupt              */
  DMA_Stream4_IRQn         =  10,     /*!< DMA_Stream4 interrupt              */
  DMA_Stream5_IRQn         =  11,     /*!< DMA_Stream5 interrupt              */
  DMA_Stream6_IRQn         =  12,     /*!< DMA_Stream6 interrupt              */
  DMA_Stream7_IRQn         =  13,     /*!< DMA_Stream7 interrupt              */
  DMA_Stream8_IRQn         =  14,     /*!< DMA_Stream8 interrupt              */
  DMA_Stream9_IRQn         =  15,     /*!< DMA_Stream9 interrupt              */
  DMA_Stream10_IRQn        =  16,     /*!< DMA_Stream10 interrupt             */
  DMA_Stream11_IRQn        =  17,     /*!< DMA_Stream11 interrupt             */
  DMA_Stream12_IRQn        =  18,     /*!< DMA_Stream12 interrupt             */
  DMA_Stream13_IRQn        =  19,     /*!< DMA_Stream13 interrupt             */
  DMA_Stream14_IRQn        =  20,     /*!< DMA_Stream14 interrupt             */
  DMA_Stream15_IRQn        =  21,     /*!< DMA_Stream15 interrupt             */
  DMA_Stream16_IRQn        =  22,     /*!< DMA_Stream16 interrupt             */
  DMA_Stream17_IRQn        =  23,     /*!< DMA_Stream17 interrupt             */
  DMA_Stream18_IRQn        =  24,     /*!< DMA_Stream18 interrupt             */
  DMA_Stream19_IRQn        =  25,     /*!< DMA_Stream19 interrupt             */
  DMA_Stream20_IRQn        =  26,     /*!< DMA_Stream20 interrupt             */
  DMA_Stream21_IRQn        =  27,     /*!< DMA_Stream21 interrupt             */
  DMA_Stream22_IRQn        =  28,     /*!< DMA_Stream22 interrupt             */
  DMA_Stream23_IRQn        =  29,     /*!< DMA_Stream23 interrupt             */
  UART0_MX_IRQn            =  30,     /*!< UART 0 interrupt                   */
  UART0_RX_IRQn            =  31,     /*!< UART 0 interrupt                   */
  UART0_TX_IRQn            =  32,     /*!< UART 0 interrupt                   */
  UART0_RT_IRQn            =  33,     /*!< UART 0 interrupt                   */
  UART0_E_IRQn             =  34,     /*!< UART 0 interrupt                   */
  UART0_IRQn               =  35,     /*!< UART 0 interrupt                   */
  UART1_MX_IRQn            =  36,     /*!< UART 1 interrupt                   */
  UART1_RX_IRQn            =  37,     /*!< UART 1 interrupt                   */
  UART1_TX_IRQn            =  38,     /*!< UART 1 interrupt                   */
  UART1_RT_IRQn            =  39,     /*!< UART 1 interrupt                   */
  UART1_E_IRQn             =  40,     /*!< UART 1 interrupt                   */
  UART1_IRQn               =  41,     /*!< UART 1 interrupt                   */
  UART2_MX_IRQn            =  42,     /*!< UART 2 interrupt                   */
  UART2_RX_IRQn            =  43,     /*!< UART 2 interrupt                   */
  UART2_TX_IRQn            =  44,     /*!< UART 2 interrupt                   */
  UART2_RT_IRQn            =  45,     /*!< UART 2 interrupt                   */
  UART2_E_IRQn             =  46,     /*!< UART 2 interrupt                   */
  UART2_IRQn               =  47,     /*!< UART 2 interrupt                   */
  UART3_MX_IRQn            =  48,     /*!< UART 3 interrupt                   */
  UART3_RX_IRQn            =  49,     /*!< UART 3 interrupt                   */
  UART3_TX_IRQn            =  50,     /*!< UART 3 interrupt                   */
  UART3_RT_IRQn            =  51,     /*!< UART 3 interrupt                   */
  UART3_E_IRQn             =  52,     /*!< UART 3 interrupt                   */
  UART3_IRQn               =  53,     /*!< UART 3 interrupt                   */
  PWM0_IRQn                =  54,     /*!< PWM 0 general interrupt            */
  PWM0_HD_IRQn             =  55,     /*!< PWM HR 0 interrupt                 */
  PWM0_TZ_IRQn             =  56,     /*!< TZ PWM 0 interrupt                 */
  PWM1_IRQn                =  57,     /*!< PWM 1 general interrupt            */
  PWM1_HD_IRQn             =  58,     /*!< PWM HR 1 general interrupt         */
  PWM1_TZ_IRQn             =  59,     /*!< TZ PWM 1 interrupt                 */
  PWM2_IRQn                =  60,     /*!< PWM 2 general interrupt            */
  PWM2_HD_IRQn             =  61,     /*!< PWM HR 2 general interrupt         */
  PWM2_TZ_IRQn             =  62,     /*!< TZ PWM 2 interrupt                 */
  PWM3_IRQn                =  63,     /*!< PWM 3 general interrupt            */
  PWM3_HD_IRQn             =  64,     /*!< PWM HR 3 general interrupt         */
  PWM3_TZ_IRQn             =  65,     /*!< TZ PWM 3 interrupt                 */
  PWM4_IRQn                =  66,     /*!< PWM 4 general interrupt            */
  PWM4_HD_IRQn             =  67,     /*!< PWM HR 4 general interrupt         */
  PWM4_TZ_IRQn             =  68,     /*!< TZ PWM 4 interrupt                 */
  PWM5_IRQn                =  69,     /*!< PWM 5 general interrupt            */
  PWM5_HD_IRQn             =  70,     /*!< PWM HR 5 general interrupt         */
  PWM5_TZ_IRQn             =  71,     /*!< TZ PWM 5 interrupt                 */
  PWM6_IRQn                =  72,     /*!< PWM 6 general interrupt            */
  PWM6_HD_IRQn             =  73,     /*!< PWM HR 6 general interrupt         */
  PWM6_TZ_IRQn             =  74,     /*!< TZ PWM 6 interrupt                 */
  PWM7_IRQn                =  75,     /*!< PWM 7 general interrupt            */
  PWM7_HD_IRQn             =  76,     /*!< PWM HR 7 general interrupt         */
  PWM7_TZ_IRQn             =  77,     /*!< TZ PWM 7 interrupt                 */
  PWM8_IRQn                =  78,     /*!< PWM 8 general interrupt            */
  PWM8_HD_IRQn             =  79,     /*!< PWM HR 8 general interrupt         */
  PWM8_TZ_IRQn             =  80,     /*!< TZ PWM 8 interrupt                 */
  ADC_SEQ0_IRQn            =  81,     /*!< ADC_0 interrupt                    */
  ADC_SEQ1_IRQn            =  82,     /*!< ADC_1 interrupt                    */
  ADC_SEQ2_IRQn            =  83,     /*!< ADC_2 interrupt                    */
  ADC_SEQ3_IRQn            =  84,     /*!< ADC_3 interrupt                    */
  ADC_SEQ4_IRQn            =  85,     /*!< ADC_4 interrupt                    */
  ADC_SEQ5_IRQn            =  86,     /*!< ADC_5 interrupt                    */
  ADC_SEQ6_IRQn            =  87,     /*!< ADC_6 interrupt                    */
  ADC_SEQ7_IRQn            =  88,     /*!< ADC_7 interrupt                    */
  ADC_CompInt_IRQn         =  89,     /*!< ADC Comparator interrupt           */
  CAP0_IRQn                =  90,     /*!< CAP_0 interrupt                    */
  CAP1_IRQn                =  91,     /*!< CAP_1 interrupt                    */
  CAP2_IRQn                =  92,     /*!< CAP_2 interrupt                    */
  CAP3_IRQn                =  93,     /*!< CAP_3 interrupt                    */
  CAP4_IRQn                =  94,     /*!< CAP_4 interrupt                    */
  CAP5_IRQn                =  95,     /*!< CAP_5 interrupt                    */
  QEP0_IRQn                =  96,     /*!< QEP_0 interrupt                    */
  QEP1_IRQn                =  97,     /*!< QEP_1 interrupt                    */
  BootFlash_IRQn           =  98,     /*!< BootFlash interrupt                */
  CMP0_IRQn                =  99,     /*!< CMP 0 interrupt                    */
  CMP1_IRQn                =  100,    /*!< CMP 1 interrupt                    */
  CMP2_IRQn                =  101,    /*!< CMP 2 interrupt                    */
  SPI0_IRQn                =  102,    /*!< SPI_0 interrupt                    */
  SPI1_IRQn                =  103,    /*!< SPI_1 interrupt                    */
  SPI2_IRQn                =  104,    /*!< SPI_2 interrupt                    */
  SPI3_IRQn                =  105,    /*!< SPI_3 interrupt                    */
  UserFlash_IRQn           =  106,    /*!< UserFlash interrupt                */
  GPIOA_IRQn               =  107,    /*!< GPIO A interrupt                   */
  GPIOB_IRQn               =  108,    /*!< GPIO B interrupt                   */
  GPIOC_IRQn               =  109,    /*!< GPIO C interrupt                   */
  GPIOD_IRQn               =  110,    /*!< GPIO D interrupt                   */
  GPIOE_IRQn               =  111,    /*!< GPIO E interrupt                   */
  GPIOF_IRQn               =  112,    /*!< GPIO F interrupt                   */
  GPIOG_IRQn               =  113,    /*!< GPIO G interrupt                   */
  GPIOH_IRQn               =  114,    /*!< GPIO H interrupt                   */
  Ethernet_IRQn            =  115,    /*!< Ethernet interrupt                 */
  CAN0_IRQn                =  116,    /*!< CAN 0 interrupt                    */
  CAN1_IRQn                =  117,    /*!< CAN  1 interrupt                   */
  CAN2_IRQn                =  118,    /*!< CAN  2 interrupt                   */
  CAN3_IRQn                =  119,    /*!< CAN  3 interrupt                   */
  CAN4_IRQn                =  120,    /*!< CAN  4 interrupt                   */
  CAN5_IRQn                =  121,    /*!< CAN  5 interrupt                   */
  CAN6_IRQn                =  122,    /*!< CAN  6 interrupt                   */
  CAN7_IRQn                =  123,    /*!< CAN  7 interrupt                   */
  CAN8_IRQn                =  124,    /*!< CAN  8 interrupt                   */
  CAN9_IRQn                =  125,    /*!< CAN  9 interrupt                   */
  CAN10_IRQn               =  126,    /*!< CAN 10 interrupt                   */
  CAN11_IRQn               =  127,    /*!< CAN 11 interrupt                   */
  CAN12_IRQn               =  128,    /*!< CAN 12 interrupt                   */
  CAN13_IRQn               =  129,    /*!< CAN 13 interrupt                   */
  CAN14_IRQn               =  130,    /*!< CAN 14 interrupt                   */
  CAN15_IRQn               =  131,    /*!< CAN 15 interrupt                   */
  RTC_IRQn                 =  132,    /*!< RTC interrupt                      */
  USBOTG_IRQn              =  133,    /*!< USB OTG interrupt                  */
} IRQn_Type;

#include <core_cm4.h>                 /* Cortex-M# processor and core peripherals */

/******************************************************************************/
/*                         ADC controller registers                           */
/******************************************************************************/

/*-- ACTSS: Enable sequencer register --------------------------------*/

typedef struct {
  uint32_t ASEN0                                  :1;                   /*!< Enable sequencer 0 */
  uint32_t ASEN1                                  :1;                   /*!< Enable sequencer 1 */
  uint32_t ASEN2                                  :1;                   /*!< Enable sequencer 2 */
  uint32_t ASEN3                                  :1;                   /*!< Enable sequencer 3 */
  uint32_t ASEN4                                  :1;                   /*!< Enable sequencer 4 */
  uint32_t ASEN5                                  :1;                   /*!< Enable sequencer 5 */
  uint32_t ASEN6                                  :1;                   /*!< Enable sequencer 6 */
  uint32_t ASEN7                                  :1;                   /*!< Enable sequencer 7 */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _ADC_ACTSS_bits;

/* Bit field positions: */
#define ADC_ACTSS_ASEN0_Pos                                 0           /*!< Enable sequencer 0 */
#define ADC_ACTSS_ASEN1_Pos                                 1           /*!< Enable sequencer 1 */
#define ADC_ACTSS_ASEN2_Pos                                 2           /*!< Enable sequencer 2 */
#define ADC_ACTSS_ASEN3_Pos                                 3           /*!< Enable sequencer 3 */
#define ADC_ACTSS_ASEN4_Pos                                 4           /*!< Enable sequencer 4 */
#define ADC_ACTSS_ASEN5_Pos                                 5           /*!< Enable sequencer 5 */
#define ADC_ACTSS_ASEN6_Pos                                 6           /*!< Enable sequencer 6 */
#define ADC_ACTSS_ASEN7_Pos                                 7           /*!< Enable sequencer 7 */

/* Bit field masks: */
#define ADC_ACTSS_ASEN0_Msk                                 0x00000001  /*!< Enable sequencer 0 */
#define ADC_ACTSS_ASEN1_Msk                                 0x00000002  /*!< Enable sequencer 1 */
#define ADC_ACTSS_ASEN2_Msk                                 0x00000004  /*!< Enable sequencer 2 */
#define ADC_ACTSS_ASEN3_Msk                                 0x00000008  /*!< Enable sequencer 3 */
#define ADC_ACTSS_ASEN4_Msk                                 0x00000010  /*!< Enable sequencer 4 */
#define ADC_ACTSS_ASEN5_Msk                                 0x00000020  /*!< Enable sequencer 5 */
#define ADC_ACTSS_ASEN6_Msk                                 0x00000040  /*!< Enable sequencer 6 */
#define ADC_ACTSS_ASEN7_Msk                                 0x00000080  /*!< Enable sequencer 7 */

/*-- RIS: Raw interrupt status register ----------------------------------------*/

typedef struct {
  uint32_t INR0                                   :1;                   /*!< Sequencer 0 raw interrupt status */
  uint32_t INR1                                   :1;                   /*!< Sequencer 1 raw interrupt status */
  uint32_t INR2                                   :1;                   /*!< Sequencer 2 raw interrupt status */
  uint32_t INR3                                   :1;                   /*!< Sequencer 3 raw interrupt status */
  uint32_t INR4                                   :1;                   /*!< Sequencer 4 raw interrupt status */
  uint32_t INR5                                   :1;                   /*!< Sequencer 5 raw interrupt status */
  uint32_t INR6                                   :1;                   /*!< Sequencer 6 raw interrupt status */
  uint32_t INR7                                   :1;                   /*!< Sequencer 7 raw interrupt status */
  uint32_t INRDC0                                 :1;                   /*!< DCMP 0 raw interrupt status */
  uint32_t INRDC1                                 :1;                   /*!< DCMP 1 raw interrupt status */
  uint32_t INRDC2                                 :1;                   /*!< DCMP 2 raw interrupt status */
  uint32_t INRDC3                                 :1;                   /*!< DCMP 3 raw interrupt status */
  uint32_t INRDC4                                 :1;                   /*!< DCMP 4 raw interrupt status */
  uint32_t INRDC5                                 :1;                   /*!< DCMP 5 raw interrupt status */
  uint32_t INRDC6                                 :1;                   /*!< DCMP 6 raw interrupt status */
  uint32_t INRDC7                                 :1;                   /*!< DCMP 7 raw interrupt status */
  uint32_t INRDC8                                 :1;                   /*!< DCMP 8 raw interrupt status */
  uint32_t INRDC9                                 :1;                   /*!< DCMP 9 raw interrupt status */
  uint32_t INRDC10                                :1;                   /*!< DCMP 10 raw interrupt status */
  uint32_t INRDC11                                :1;                   /*!< DCMP 11 raw interrupt status */
  uint32_t INRDC12                                :1;                   /*!< DCMP 12 raw interrupt status */
  uint32_t INRDC13                                :1;                   /*!< DCMP 13 raw interrupt status */
  uint32_t INRDC14                                :1;                   /*!< DCMP 14 raw interrupt status */
  uint32_t INRDC15                                :1;                   /*!< DCMP 15 raw interrupt status */
  uint32_t INRDC16                                :1;                   /*!< DCMP 16 raw interrupt status */
  uint32_t INRDC17                                :1;                   /*!< DCMP 17 raw interrupt status */
  uint32_t INRDC18                                :1;                   /*!< DCMP 18 raw interrupt status */
  uint32_t INRDC19                                :1;                   /*!< DCMP 19 raw interrupt status */
  uint32_t INRDC20                                :1;                   /*!< DCMP 20 raw interrupt status */
  uint32_t INRDC21                                :1;                   /*!< DCMP 21 raw interrupt status */
  uint32_t INRDC22                                :1;                   /*!< DCMP 22 raw interrupt status */
  uint32_t INRDC23                                :1;                   /*!< DCMP 23 raw interrupt status */
} _ADC_RIS_bits;

/* Bit field positions: */
#define ADC_RIS_INR0_Pos                                    0           /*!< Sequencer 0 raw interrupt status */
#define ADC_RIS_INR1_Pos                                    1           /*!< Sequencer 1 raw interrupt status */
#define ADC_RIS_INR2_Pos                                    2           /*!< Sequencer 2 raw interrupt status */
#define ADC_RIS_INR3_Pos                                    3           /*!< Sequencer 3 raw interrupt status */
#define ADC_RIS_INR4_Pos                                    4           /*!< Sequencer 4 raw interrupt status */
#define ADC_RIS_INR5_Pos                                    5           /*!< Sequencer 5 raw interrupt status */
#define ADC_RIS_INR6_Pos                                    6           /*!< Sequencer 6 raw interrupt status */
#define ADC_RIS_INR7_Pos                                    7           /*!< Sequencer 7 raw interrupt status */
#define ADC_RIS_INRDC0_Pos                                  8           /*!< DCMP 0 raw interrupt status */
#define ADC_RIS_INRDC1_Pos                                  9           /*!< DCMP 1 raw interrupt status */
#define ADC_RIS_INRDC2_Pos                                  10          /*!< DCMP 2 raw interrupt status */
#define ADC_RIS_INRDC3_Pos                                  11          /*!< DCMP 3 raw interrupt status */
#define ADC_RIS_INRDC4_Pos                                  12          /*!< DCMP 4 raw interrupt status */
#define ADC_RIS_INRDC5_Pos                                  13          /*!< DCMP 5 raw interrupt status */
#define ADC_RIS_INRDC6_Pos                                  14          /*!< DCMP 6 raw interrupt status */
#define ADC_RIS_INRDC7_Pos                                  15          /*!< DCMP 7 raw interrupt status */
#define ADC_RIS_INRDC8_Pos                                  16          /*!< DCMP 8 raw interrupt status */
#define ADC_RIS_INRDC9_Pos                                  17          /*!< DCMP 9 raw interrupt status */
#define ADC_RIS_INRDC10_Pos                                 18          /*!< DCMP 10 raw interrupt status */
#define ADC_RIS_INRDC11_Pos                                 19          /*!< DCMP 11 raw interrupt status */
#define ADC_RIS_INRDC12_Pos                                 20          /*!< DCMP 12 raw interrupt status */
#define ADC_RIS_INRDC13_Pos                                 21          /*!< DCMP 13 raw interrupt status */
#define ADC_RIS_INRDC14_Pos                                 22          /*!< DCMP 14 raw interrupt status */
#define ADC_RIS_INRDC15_Pos                                 23          /*!< DCMP 15 raw interrupt status */
#define ADC_RIS_INRDC16_Pos                                 24          /*!< DCMP 16 raw interrupt status */
#define ADC_RIS_INRDC17_Pos                                 25          /*!< DCMP 17 raw interrupt status */
#define ADC_RIS_INRDC18_Pos                                 26          /*!< DCMP 18 raw interrupt status */
#define ADC_RIS_INRDC19_Pos                                 27          /*!< DCMP 19 raw interrupt status */
#define ADC_RIS_INRDC20_Pos                                 28          /*!< DCMP 20 raw interrupt status */
#define ADC_RIS_INRDC21_Pos                                 29          /*!< DCMP 21 raw interrupt status */
#define ADC_RIS_INRDC22_Pos                                 30          /*!< DCMP 22 raw interrupt status */
#define ADC_RIS_INRDC23_Pos                                 31          /*!< DCMP 23 raw interrupt status */

/* Bit field masks: */
#define ADC_RIS_INR0_Msk                                    0x00000001  /*!< Sequencer 0 raw interrupt status */
#define ADC_RIS_INR1_Msk                                    0x00000002  /*!< Sequencer 1 raw interrupt status */
#define ADC_RIS_INR2_Msk                                    0x00000004  /*!< Sequencer 2 raw interrupt status */
#define ADC_RIS_INR3_Msk                                    0x00000008  /*!< Sequencer 3 raw interrupt status */
#define ADC_RIS_INR4_Msk                                    0x00000010  /*!< Sequencer 4 raw interrupt status */
#define ADC_RIS_INR5_Msk                                    0x00000020  /*!< Sequencer 5 raw interrupt status */
#define ADC_RIS_INR6_Msk                                    0x00000040  /*!< Sequencer 6 raw interrupt status */
#define ADC_RIS_INR7_Msk                                    0x00000080  /*!< Sequencer 7 raw interrupt status */
#define ADC_RIS_INRDC0_Msk                                  0x00000100  /*!< DCMP 0 raw interrupt status */
#define ADC_RIS_INRDC1_Msk                                  0x00000200  /*!< DCMP 1 raw interrupt status */
#define ADC_RIS_INRDC2_Msk                                  0x00000400  /*!< DCMP 2 raw interrupt status */
#define ADC_RIS_INRDC3_Msk                                  0x00000800  /*!< DCMP 3 raw interrupt status */
#define ADC_RIS_INRDC4_Msk                                  0x00001000  /*!< DCMP 4 raw interrupt status */
#define ADC_RIS_INRDC5_Msk                                  0x00002000  /*!< DCMP 5 raw interrupt status */
#define ADC_RIS_INRDC6_Msk                                  0x00004000  /*!< DCMP 6 raw interrupt status */
#define ADC_RIS_INRDC7_Msk                                  0x00008000  /*!< DCMP 7 raw interrupt status */
#define ADC_RIS_INRDC8_Msk                                  0x00010000  /*!< DCMP 8 raw interrupt status */
#define ADC_RIS_INRDC9_Msk                                  0x00020000  /*!< DCMP 9 raw interrupt status */
#define ADC_RIS_INRDC10_Msk                                 0x00040000  /*!< DCMP 10 raw interrupt status */
#define ADC_RIS_INRDC11_Msk                                 0x00080000  /*!< DCMP 11 raw interrupt status */
#define ADC_RIS_INRDC12_Msk                                 0x00100000  /*!< DCMP 12 raw interrupt status */
#define ADC_RIS_INRDC13_Msk                                 0x00200000  /*!< DCMP 13 raw interrupt status */
#define ADC_RIS_INRDC14_Msk                                 0x00400000  /*!< DCMP 14 raw interrupt status */
#define ADC_RIS_INRDC15_Msk                                 0x00800000  /*!< DCMP 15 raw interrupt status */
#define ADC_RIS_INRDC16_Msk                                 0x01000000  /*!< DCMP 16 raw interrupt status */
#define ADC_RIS_INRDC17_Msk                                 0x02000000  /*!< DCMP 17 raw interrupt status */
#define ADC_RIS_INRDC18_Msk                                 0x04000000  /*!< DCMP 18 raw interrupt status */
#define ADC_RIS_INRDC19_Msk                                 0x08000000  /*!< DCMP 19 raw interrupt status */
#define ADC_RIS_INRDC20_Msk                                 0x10000000  /*!< DCMP 20 raw interrupt status */
#define ADC_RIS_INRDC21_Msk                                 0x20000000  /*!< DCMP 21 raw interrupt status */
#define ADC_RIS_INRDC22_Msk                                 0x40000000  /*!< DCMP 22 raw interrupt status */
#define ADC_RIS_INRDC23_Msk                                 0x80000000  /*!< DCMP 23 raw interrupt status */

/*-- IM: Interrupt mask register ---------------------------------------------*/

typedef struct {
  uint32_t MASK0                                  :1;                   /*!< Sequencer 0 interrupt mask */
  uint32_t MASK1                                  :1;                   /*!< Sequencer 1 interrupt mask */
  uint32_t MASK2                                  :1;                   /*!< Sequencer 2 interrupt mask */
  uint32_t MASK3                                  :1;                   /*!< Sequencer 3 interrupt mask */
  uint32_t MASK4                                  :1;                   /*!< Sequencer 4 interrupt mask */
  uint32_t MASK5                                  :1;                   /*!< Sequencer 5 interrupt mask */
  uint32_t MASK6                                  :1;                   /*!< Sequencer 6 interrupt mask */
  uint32_t MASK7                                  :1;                   /*!< Sequencer 7 interrupt mask */
  uint32_t MIDC0                                  :1;                   /*!< DCMP 0 interrupt mask */
  uint32_t MIDC1                                  :1;                   /*!< DCMP 1 interrupt mask */
  uint32_t MIDC2                                  :1;                   /*!< DCMP 2 interrupt mask */
  uint32_t MIDC3                                  :1;                   /*!< DCMP 3 interrupt mask */
  uint32_t MIDC4                                  :1;                   /*!< DCMP 4 interrupt mask */
  uint32_t MIDC5                                  :1;                   /*!< DCMP 5 interrupt mask */
  uint32_t MIDC6                                  :1;                   /*!< DCMP 6 interrupt mask */
  uint32_t MIDC7                                  :1;                   /*!< DCMP 7 interrupt mask */
  uint32_t MIDC8                                  :1;                   /*!< DCMP 8 interrupt mask */
  uint32_t MIDC9                                  :1;                   /*!< DCMP 9 interrupt mask */
  uint32_t MIDC10                                 :1;                   /*!< DCMP 10 interrupt mask */
  uint32_t MIDC11                                 :1;                   /*!< DCMP 11 interrupt mask */
  uint32_t MIDC12                                 :1;                   /*!< DCMP 12 interrupt mask */
  uint32_t MIDC13                                 :1;                   /*!< DCMP 13 interrupt mask */
  uint32_t MIDC14                                 :1;                   /*!< DCMP 14 interrupt mask */
  uint32_t MIDC15                                 :1;                   /*!< DCMP 15 interrupt mask */
  uint32_t MIDC16                                 :1;                   /*!< DCMP 16 interrupt mask */
  uint32_t MIDC17                                 :1;                   /*!< DCMP 17 interrupt mask */
  uint32_t MIDC18                                 :1;                   /*!< DCMP 18 interrupt mask */
  uint32_t MIDC19                                 :1;                   /*!< DCMP 19 interrupt mask */
  uint32_t MIDC20                                 :1;                   /*!< DCMP 20 interrupt mask */
  uint32_t MIDC21                                 :1;                   /*!< DCMP 21 interrupt mask */
  uint32_t MIDC22                                 :1;                   /*!< DCMP 22 interrupt mask */
  uint32_t MIDC23                                 :1;                   /*!< DCMP 23 interrupt mask */
} _ADC_IM_bits;

/* Bit field positions: */
#define ADC_IM_MASK0_Pos                                    0           /*!< Sequencer 0 interrupt mask */
#define ADC_IM_MASK1_Pos                                    1           /*!< Sequencer 1 interrupt mask */
#define ADC_IM_MASK2_Pos                                    2           /*!< Sequencer 2 interrupt mask */
#define ADC_IM_MASK3_Pos                                    3           /*!< Sequencer 3 interrupt mask */
#define ADC_IM_MASK4_Pos                                    4           /*!< Sequencer 4 interrupt mask */
#define ADC_IM_MASK5_Pos                                    5           /*!< Sequencer 5 interrupt mask */
#define ADC_IM_MASK6_Pos                                    6           /*!< Sequencer 6 interrupt mask */
#define ADC_IM_MASK7_Pos                                    7           /*!< Sequencer 7 interrupt mask */
#define ADC_IM_MIDC0_Pos                                    8           /*!< DCMP 0 interrupt mask*/
#define ADC_IM_MIDC1_Pos                                    9           /*!< DCMP 1 interrupt mask*/
#define ADC_IM_MIDC2_Pos                                    10          /*!< DCMP 2 interrupt mask*/
#define ADC_IM_MIDC3_Pos                                    11          /*!< DCMP 3 interrupt mask*/
#define ADC_IM_MIDC4_Pos                                    12          /*!< DCMP 4 interrupt mask*/
#define ADC_IM_MIDC5_Pos                                    13          /*!< DCMP 5 interrupt mask*/
#define ADC_IM_MIDC6_Pos                                    14          /*!< DCMP 6 interrupt mask*/
#define ADC_IM_MIDC7_Pos                                    15          /*!< DCMP 7 interrupt mask*/
#define ADC_IM_MIDC8_Pos                                    16          /*!< DCMP 8 interrupt mask*/
#define ADC_IM_MIDC9_Pos                                    17          /*!< DCMP 9 interrupt mask*/
#define ADC_IM_MIDC10_Pos                                   18          /*!< DCMP 10 interrupt mask */
#define ADC_IM_MIDC11_Pos                                   19          /*!< DCMP 11 interrupt mask */
#define ADC_IM_MIDC12_Pos                                   20          /*!< DCMP 12 interrupt mask */
#define ADC_IM_MIDC13_Pos                                   21          /*!< DCMP 13 interrupt mask */
#define ADC_IM_MIDC14_Pos                                   22          /*!< DCMP 14 interrupt mask */
#define ADC_IM_MIDC15_Pos                                   23          /*!< DCMP 15 interrupt mask */
#define ADC_IM_MIDC16_Pos                                   24          /*!< DCMP 16 interrupt mask */
#define ADC_IM_MIDC17_Pos                                   25          /*!< DCMP 17 interrupt mask */
#define ADC_IM_MIDC18_Pos                                   26          /*!< DCMP 18 interrupt mask */
#define ADC_IM_MIDC19_Pos                                   27          /*!< DCMP 19 interrupt mask */
#define ADC_IM_MIDC20_Pos                                   28          /*!< DCMP 20 interrupt mask */
#define ADC_IM_MIDC21_Pos                                   29          /*!< DCMP 21 interrupt mask */
#define ADC_IM_MIDC22_Pos                                   30          /*!< DCMP 22 interrupt mask */
#define ADC_IM_MIDC23_Pos                                   31          /*!< DCMP 23 interrupt mask */

/* Bit field masks: */
#define ADC_IM_MASK0_Msk                                    0x00000001  /*!< Sequencer 0 interrupt mask */
#define ADC_IM_MASK1_Msk                                    0x00000002  /*!< Sequencer 1 interrupt mask */
#define ADC_IM_MASK2_Msk                                    0x00000004  /*!< Sequencer 2 interrupt mask */
#define ADC_IM_MASK3_Msk                                    0x00000008  /*!< Sequencer 3 interrupt mask */
#define ADC_IM_MASK4_Msk                                    0x00000010  /*!< Sequencer 4 interrupt mask */
#define ADC_IM_MASK5_Msk                                    0x00000020  /*!< Sequencer 5 interrupt mask */
#define ADC_IM_MASK6_Msk                                    0x00000040  /*!< Sequencer 6 interrupt mask */
#define ADC_IM_MASK7_Msk                                    0x00000080  /*!< Sequencer 7 interrupt mask */
#define ADC_IM_MIDC0_Msk                                    0x00000100  /*!< DCMP 0 interrupt mask*/
#define ADC_IM_MIDC1_Msk                                    0x00000200  /*!< DCMP 1 interrupt mask*/
#define ADC_IM_MIDC2_Msk                                    0x00000400  /*!< DCMP 2 interrupt mask*/
#define ADC_IM_MIDC3_Msk                                    0x00000800  /*!< DCMP 3 interrupt mask*/
#define ADC_IM_MIDC4_Msk                                    0x00001000  /*!< DCMP 4 interrupt mask*/
#define ADC_IM_MIDC5_Msk                                    0x00002000  /*!< DCMP 5 interrupt mask*/
#define ADC_IM_MIDC6_Msk                                    0x00004000  /*!< DCMP 6 interrupt mask*/
#define ADC_IM_MIDC7_Msk                                    0x00008000  /*!< DCMP 7 interrupt mask*/
#define ADC_IM_MIDC8_Msk                                    0x00010000  /*!< DCMP 8 interrupt mask*/
#define ADC_IM_MIDC9_Msk                                    0x00020000  /*!< DCMP 9 interrupt mask*/
#define ADC_IM_MIDC10_Msk                                   0x00040000  /*!< DCMP 10 interrupt mask */
#define ADC_IM_MIDC11_Msk                                   0x00080000  /*!< DCMP 11 interrupt mask */
#define ADC_IM_MIDC12_Msk                                   0x00100000  /*!< DCMP 12 interrupt mask */
#define ADC_IM_MIDC13_Msk                                   0x00200000  /*!< DCMP 13 interrupt mask */
#define ADC_IM_MIDC14_Msk                                   0x00400000  /*!< DCMP 14 interrupt mask */
#define ADC_IM_MIDC15_Msk                                   0x00800000  /*!< DCMP 15 interrupt mask */
#define ADC_IM_MIDC16_Msk                                   0x01000000  /*!< DCMP 16 interrupt mask */
#define ADC_IM_MIDC17_Msk                                   0x02000000  /*!< DCMP 17 interrupt mask */
#define ADC_IM_MIDC18_Msk                                   0x04000000  /*!< DCMP 18 interrupt mask */
#define ADC_IM_MIDC19_Msk                                   0x08000000  /*!< DCMP 19 interrupt mask */
#define ADC_IM_MIDC20_Msk                                   0x10000000  /*!< DCMP 20 interrupt mask */
#define ADC_IM_MIDC21_Msk                                   0x20000000  /*!< DCMP 21 interrupt mask */
#define ADC_IM_MIDC22_Msk                                   0x40000000  /*!< DCMP 22 interrupt mask */
#define ADC_IM_MIDC23_Msk                                   0x80000000  /*!< DCMP 23 interrupt mask */

/*-- ISC: Interrupt status and clear register -------------------------------------------*/

typedef struct {
  uint32_t IN0                                    :1;                   /*!< Sequencer 0 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN1                                    :1;                   /*!< Sequencer 1 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN2                                    :1;                   /*!< Sequencer 2 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN3                                    :1;                   /*!< Sequencer 3 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN4                                    :1;                   /*!< Sequencer 4 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN5                                    :1;                   /*!< Sequencer 5 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN6                                    :1;                   /*!< Sequencer 6 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t IN7                                    :1;                   /*!< Sequencer 7 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN0                                  :1;                   /*!< DCMP 0 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN1                                  :1;                   /*!< DCMP 1 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN2                                  :1;                   /*!< DCMP 2 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN3                                  :1;                   /*!< DCMP 3 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN4                                  :1;                   /*!< DCMP 4 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN5                                  :1;                   /*!< DCMP 5 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN6                                  :1;                   /*!< DCMP 6 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN7                                  :1;                   /*!< DCMP 7 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN8                                  :1;                   /*!< DCMP 8 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN9                                  :1;                   /*!< DCMP 9 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN10                                 :1;                   /*!< DCMP 10 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN11                                 :1;                   /*!< DCMP 11 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN12                                 :1;                   /*!< DCMP 12 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN13                                 :1;                   /*!< DCMP 13 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN14                                 :1;                   /*!< DCMP 14 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN15                                 :1;                   /*!< DCMP 15 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN16                                 :1;                   /*!< DCMP 16 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN17                                 :1;                   /*!< DCMP 17 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN18                                 :1;                   /*!< DCMP 18 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN19                                 :1;                   /*!< DCMP 19 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN20                                 :1;                   /*!< DCMP 20 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN21                                 :1;                   /*!< DCMP 21 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN22                                 :1;                   /*!< DCMP 22 masked interrupt status / Write 1 to clear (also clear raw status) */
  uint32_t DCIN23                                 :1;                   /*!< DCMP 23 masked interrupt status / Write 1 to clear (also clear raw status) */
} _ADC_ISC_bits;

/* Bit field positions: */
#define ADC_ISC_IN0_Pos                                     0           /*!< Sequencer 0 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN1_Pos                                     1           /*!< Sequencer 1 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN2_Pos                                     2           /*!< Sequencer 2 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN3_Pos                                     3           /*!< Sequencer 3 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN4_Pos                                     4           /*!< Sequencer 4 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN5_Pos                                     5           /*!< Sequencer 5 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN6_Pos                                     6           /*!< Sequencer 6 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN7_Pos                                     7           /*!< Sequencer 7 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN0_Pos                                   8           /*!< DCMP 0 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN1_Pos                                   9           /*!< DCMP 1 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN2_Pos                                   10          /*!< DCMP 2 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN3_Pos                                   11          /*!< DCMP 3 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN4_Pos                                   12          /*!< DCMP 4 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN5_Pos                                   13          /*!< DCMP 5 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN6_Pos                                   14          /*!< DCMP 6 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN7_Pos                                   15          /*!< DCMP 7 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN8_Pos                                   16          /*!< DCMP 8 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN9_Pos                                   17          /*!< DCMP 9 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN10_Pos                                  18          /*!< DCMP 10 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN11_Pos                                  19          /*!< DCMP 11 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN12_Pos                                  20          /*!< DCMP 12 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN13_Pos                                  21          /*!< DCMP 13 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN14_Pos                                  22          /*!< DCMP 14 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN15_Pos                                  23          /*!< DCMP 15 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN16_Pos                                  24          /*!< DCMP 16 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN17_Pos                                  25          /*!< DCMP 17 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN18_Pos                                  26          /*!< DCMP 18 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN19_Pos                                  27          /*!< DCMP 19 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN20_Pos                                  28          /*!< DCMP 20 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN21_Pos                                  29          /*!< DCMP 21 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN22_Pos                                  30          /*!< DCMP 22 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN23_Pos                                  31          /*!< DCMP 23 masked interrupt status / Write 1 to clear (also clear raw status) */

/* Bit field masks: */
#define ADC_ISC_IN0_Msk                                     0x00000001  /*!< Sequencer 0 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN1_Msk                                     0x00000002  /*!< Sequencer 1 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN2_Msk                                     0x00000004  /*!< Sequencer 2 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN3_Msk                                     0x00000008  /*!< Sequencer 3 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN4_Msk                                     0x00000010  /*!< Sequencer 4 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN5_Msk                                     0x00000020  /*!< Sequencer 5 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN6_Msk                                     0x00000040  /*!< Sequencer 6 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_IN7_Msk                                     0x00000080  /*!< Sequencer 7 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN0_Msk                                   0x00000100  /*!< DCMP 0 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN1_Msk                                   0x00000200  /*!< DCMP 1 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN2_Msk                                   0x00000400  /*!< DCMP 2 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN3_Msk                                   0x00000800  /*!< DCMP 3 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN4_Msk                                   0x00001000  /*!< DCMP 4 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN5_Msk                                   0x00002000  /*!< DCMP 5 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN6_Msk                                   0x00004000  /*!< DCMP 6 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN7_Msk                                   0x00008000  /*!< DCMP 7 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN8_Msk                                   0x00010000  /*!< DCMP 8 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN9_Msk                                   0x00020000  /*!< DCMP 9 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN10_Msk                                  0x00040000  /*!< DCMP 10 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN11_Msk                                  0x00080000  /*!< DCMP 11 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN12_Msk                                  0x00100000  /*!< DCMP 12 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN13_Msk                                  0x00200000  /*!< DCMP 13 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN14_Msk                                  0x00400000  /*!< DCMP 14 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN15_Msk                                  0x00800000  /*!< DCMP 15 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN16_Msk                                  0x01000000  /*!< DCMP 16 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN17_Msk                                  0x02000000  /*!< DCMP 17 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN18_Msk                                  0x04000000  /*!< DCMP 18 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN19_Msk                                  0x08000000  /*!< DCMP 19 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN20_Msk                                  0x10000000  /*!< DCMP 20 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN21_Msk                                  0x20000000  /*!< DCMP 21 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN22_Msk                                  0x40000000  /*!< DCMP 22 masked interrupt status / Write 1 to clear (also clear raw status) */
#define ADC_ISC_DCIN23_Msk                                  0x80000000  /*!< DCMP 23 masked interrupt status / Write 1 to clear (also clear raw status) */

/*-- OSTAT: FIFO overflow status register -------------------------------------*/

typedef struct {
  uint32_t OV0                                    :1;                   /*!< Sequencer 0 FIFO overflow */
  uint32_t OV1                                    :1;                   /*!< Sequencer 1 FIFO overflow */
  uint32_t OV2                                    :1;                   /*!< Sequencer 2 FIFO overflow */
  uint32_t OV3                                    :1;                   /*!< Sequencer 3 FIFO overflow */
  uint32_t OV4                                    :1;                   /*!< Sequencer 4 FIFO overflow */
  uint32_t OV5                                    :1;                   /*!< Sequencer 5 FIFO overflow */
  uint32_t OV6                                    :1;                   /*!< Sequencer 6 FIFO overflow */
  uint32_t OV7                                    :1;                   /*!< Sequencer 7 FIFO overflow */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t DOV0                                   :1;                   /*!< Sequencer 0 FIFO DMA request overflow */
  uint32_t DOV1                                   :1;                   /*!< Sequencer 1 FIFO DMA request overflow */
  uint32_t DOV2                                   :1;                   /*!< Sequencer 2 FIFO DMA request overflow */
  uint32_t DOV3                                   :1;                   /*!< Sequencer 3 FIFO DMA request overflow */
  uint32_t DOV4                                   :1;                   /*!< Sequencer 4 FIFO DMA request overflow */
  uint32_t DOV5                                   :1;                   /*!< Sequencer 5 FIFO DMA request overflow */
  uint32_t DOV6                                   :1;                   /*!< Sequencer 6 FIFO DMA request overflow */
  uint32_t DOV7                                   :1;                   /*!< Sequencer 7 FIFO DMA request overflow */
  uint32_t Reserved1                              :8;                   /*!< Reserved */
} _ADC_OSTAT_bits;

/* Bit field positions: */
#define ADC_OSTAT_OV0_Pos                                   0           /*!< Sequencer 0 FIFO overflow */
#define ADC_OSTAT_OV1_Pos                                   1           /*!< Sequencer 1 FIFO overflow */
#define ADC_OSTAT_OV2_Pos                                   2           /*!< Sequencer 2 FIFO overflow */
#define ADC_OSTAT_OV3_Pos                                   3           /*!< Sequencer 3 FIFO overflow */
#define ADC_OSTAT_OV4_Pos                                   4           /*!< Sequencer 4 FIFO overflow */
#define ADC_OSTAT_OV5_Pos                                   5           /*!< Sequencer 5 FIFO overflow */
#define ADC_OSTAT_OV6_Pos                                   6           /*!< Sequencer 6 FIFO overflow */
#define ADC_OSTAT_OV7_Pos                                   7           /*!< Sequencer 7 FIFO overflow */
#define ADC_OSTAT_DOV0_Pos                                  16          /*!< Sequencer 0 FIFO DMA request overflow */
#define ADC_OSTAT_DOV1_Pos                                  17          /*!< Sequencer 1 FIFO DMA request overflow */
#define ADC_OSTAT_DOV2_Pos                                  18          /*!< Sequencer 2 FIFO DMA request overflow */
#define ADC_OSTAT_DOV3_Pos                                  19          /*!< Sequencer 3 FIFO DMA request overflow */
#define ADC_OSTAT_DOV4_Pos                                  20          /*!< Sequencer 4 FIFO DMA request overflow */
#define ADC_OSTAT_DOV5_Pos                                  21          /*!< Sequencer 5 FIFO DMA request overflow */
#define ADC_OSTAT_DOV6_Pos                                  22          /*!< Sequencer 6 FIFO DMA request overflow */
#define ADC_OSTAT_DOV7_Pos                                  23          /*!< Sequencer 7 FIFO DMA request overflow */

/* Bit field masks: */
#define ADC_OSTAT_OV0_Msk                                   0x00000001  /*!< Sequencer 0 FIFO overflow */
#define ADC_OSTAT_OV1_Msk                                   0x00000002  /*!< Sequencer 1 FIFO overflow */
#define ADC_OSTAT_OV2_Msk                                   0x00000004  /*!< Sequencer 2 FIFO overflow */
#define ADC_OSTAT_OV3_Msk                                   0x00000008  /*!< Sequencer 3 FIFO overflow */
#define ADC_OSTAT_OV4_Msk                                   0x00000010  /*!< Sequencer 4 FIFO overflow */
#define ADC_OSTAT_OV5_Msk                                   0x00000020  /*!< Sequencer 5 FIFO overflow */
#define ADC_OSTAT_OV6_Msk                                   0x00000040  /*!< Sequencer 6 FIFO overflow */
#define ADC_OSTAT_OV7_Msk                                   0x00000080  /*!< Sequencer 7 FIFO overflow */
#define ADC_OSTAT_DOV0_Msk                                  0x00010000  /*!< Sequencer 0 FIFO DMA request overflow */
#define ADC_OSTAT_DOV1_Msk                                  0x00020000  /*!< Sequencer 1 FIFO DMA request overflow */
#define ADC_OSTAT_DOV2_Msk                                  0x00040000  /*!< Sequencer 2 FIFO DMA request overflow */
#define ADC_OSTAT_DOV3_Msk                                  0x00080000  /*!< Sequencer 3 FIFO DMA request overflow */
#define ADC_OSTAT_DOV4_Msk                                  0x00100000  /*!< Sequencer 4 FIFO DMA request overflow */
#define ADC_OSTAT_DOV5_Msk                                  0x00200000  /*!< Sequencer 5 FIFO DMA request overflow */
#define ADC_OSTAT_DOV6_Msk                                  0x00400000  /*!< Sequencer 6 FIFO DMA request overflow */
#define ADC_OSTAT_DOV7_Msk                                  0x00800000  /*!< Sequencer 7 FIFO DMA request overflow */

/*-- EMUX: Sequencer start event selection register -----------------------*/

typedef struct {
  uint32_t EM0                                    :4;                   /*!< Select start event for sequencer 0 */
  uint32_t EM1                                    :4;                   /*!< Select start event for sequencer 1 */
  uint32_t EM2                                    :4;                   /*!< Select start event for sequencer 2 */
  uint32_t EM3                                    :4;                   /*!< Select start event for sequencer 3 */
  uint32_t EM4                                    :4;                   /*!< Select start event for sequencer 4 */
  uint32_t EM5                                    :4;                   /*!< Select start event for sequencer 5 */
  uint32_t EM6                                    :4;                   /*!< Select start event for sequencer 6 */
  uint32_t EM7                                    :4;                   /*!< Select start event for sequencer 7 */
} _ADC_EMUX_bits;

/* Bit field positions: */
#define ADC_EMUX_EM0_Pos                                    0           /*!< Select start event for sequencer 0 */
#define ADC_EMUX_EM1_Pos                                    4           /*!< Select start event for sequencer 1 */
#define ADC_EMUX_EM2_Pos                                    8           /*!< Select start event for sequencer 2 */
#define ADC_EMUX_EM3_Pos                                    12          /*!< Select start event for sequencer 3 */
#define ADC_EMUX_EM4_Pos                                    16          /*!< Select start event for sequencer 4 */
#define ADC_EMUX_EM5_Pos                                    20          /*!< Select start event for sequencer 5 */
#define ADC_EMUX_EM6_Pos                                    24          /*!< Select start event for sequencer 6 */
#define ADC_EMUX_EM7_Pos                                    28          /*!< Select start event for sequencer 7 */

/* Bit field masks: */
#define ADC_EMUX_EM0_Msk                                    0x0000000F  /*!< Select start event for sequencer 0 */
#define ADC_EMUX_EM1_Msk                                    0x000000F0  /*!< Select start event for sequencer 1 */
#define ADC_EMUX_EM2_Msk                                    0x00000F00  /*!< Select start event for sequencer 2 */
#define ADC_EMUX_EM3_Msk                                    0x0000F000  /*!< Select start event for sequencer 3 */
#define ADC_EMUX_EM4_Msk                                    0x000F0000  /*!< Select start event for sequencer 4 */
#define ADC_EMUX_EM5_Msk                                    0x00F00000  /*!< Select start event for sequencer 5 */
#define ADC_EMUX_EM6_Msk                                    0x0F000000  /*!< Select start event for sequencer 6 */
#define ADC_EMUX_EM7_Msk                                    0xF0000000  /*!< Select start event for sequencer 7 */

/*-- USTAT: FIFO underflow status register ----------------------------------------------*/

typedef struct {
  uint32_t UV0                                    :1;                   /*!< Sequencer 0 FIFO underflow */
  uint32_t UV1                                    :1;                   /*!< Sequencer 1 FIFO underflow */
  uint32_t UV2                                    :1;                   /*!< Sequencer 2 FIFO underflow */
  uint32_t UV3                                    :1;                   /*!< Sequencer 3 FIFO underflow */
  uint32_t UV4                                    :1;                   /*!< Sequencer 4 FIFO underflow */
  uint32_t UV5                                    :1;                   /*!< Sequencer 5 FIFO underflow */
  uint32_t UV6                                    :1;                   /*!< Sequencer 6 FIFO underflow */
  uint32_t UV7                                    :1;                   /*!< Sequencer 7 FIFO underflow */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _ADC_USTAT_bits;

/* Bit field positions: */
#define ADC_USTAT_UV0_Pos                                   0           /*!< Sequencer 0 FIFO underflow */
#define ADC_USTAT_UV1_Pos                                   1           /*!< Sequencer 1 FIFO underflow */
#define ADC_USTAT_UV2_Pos                                   2           /*!< Sequencer 2 FIFO underflow */
#define ADC_USTAT_UV3_Pos                                   3           /*!< Sequencer 3 FIFO underflow */
#define ADC_USTAT_UV4_Pos                                   4           /*!< Sequencer 4 FIFO underflow */
#define ADC_USTAT_UV5_Pos                                   5           /*!< Sequencer 5 FIFO underflow */
#define ADC_USTAT_UV6_Pos                                   6           /*!< Sequencer 6 FIFO underflow */
#define ADC_USTAT_UV7_Pos                                   7           /*!< Sequencer 7 FIFO underflow */

/* Bit field masks: */
#define ADC_USTAT_UV0_Msk                                   0x00000001  /*!< Sequencer 0 FIFO underflow */
#define ADC_USTAT_UV1_Msk                                   0x00000002  /*!< Sequencer 1 FIFO underflow */
#define ADC_USTAT_UV2_Msk                                   0x00000004  /*!< Sequencer 2 FIFO underflow */
#define ADC_USTAT_UV3_Msk                                   0x00000008  /*!< Sequencer 3 FIFO underflow */
#define ADC_USTAT_UV4_Msk                                   0x00000010  /*!< Sequencer 4 FIFO underflow */
#define ADC_USTAT_UV5_Msk                                   0x00000020  /*!< Sequencer 5 FIFO underflow */
#define ADC_USTAT_UV6_Msk                                   0x00000040  /*!< Sequencer 6 FIFO underflow */
#define ADC_USTAT_UV7_Msk                                   0x00000080  /*!< Sequencer 7 FIFO underflow */

/*-- SPC0: ADC0, ADC1 start delay register  -----------------------------------*/

typedef struct {
  uint32_t PHASE0                                 :12;                  /*!< ADC0 start delay (channel 0,1) */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t PHASE1                                 :12;                  /*!< ADC1 start delay (channel 2,3) */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_SPC0_bits;

/* Bit field positions: */
#define ADC_SPC0_PHASE0_Pos                                 0           /*!< ADC0 start delay (channel 0,1) */
#define ADC_SPC0_PHASE1_Pos                                 16          /*!< ADC1 start delay (channel 2,3) */

/* Bit field masks: */
#define ADC_SPC0_PHASE0_Msk                                 0x00000FFF  /*!< ADC0 start delay (channel 0,1) */
#define ADC_SPC0_PHASE1_Msk                                 0x0FFF0000  /*!< ADC1 start delay (channel 2,3) */

/*-- SPC1: ADC2, ADC3 start delay register -----------------------------------*/

typedef struct {
  uint32_t PHASE2                                 :12;                  /*!< ADC2 start delay (channel 4,5) */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t PHASE3                                 :12;                  /*!< ADC3 start delay (channel 6,7) */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_SPC1_bits;

/* Bit field positions: */
#define ADC_SPC1_PHASE2_Pos                                 0           /*!< ADC2 start delay (channel 4,5) */
#define ADC_SPC1_PHASE3_Pos                                 16          /*!< ADC3 start delay (channel 6,7) */

/* Bit field masks: */
#define ADC_SPC1_PHASE2_Msk                                 0x00000FFF  /*!< ADC2 start delay (channel 4,5) */
#define ADC_SPC1_PHASE3_Msk                                 0x0FFF0000  /*!< ADC3 start delay (channel 6,7) */

/*-- SPC2: ADC4, ADC5 start delay register -----------------------------------*/

typedef struct {
  uint32_t PHASE4                                 :12;                  /*!< ADC4 start delay (channel 8,9) */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t PHASE5                                 :12;                  /*!< ADC5 start delay (channel 10,11) */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_SPC2_bits;

/* Bit field positions: */
#define ADC_SPC2_PHASE4_Pos                                 0           /*!< ADC4 start delay (channel 8,9) */
#define ADC_SPC2_PHASE5_Pos                                 16          /*!< ADC5 start delay (channel 10,11) */

/* Bit field masks: */
#define ADC_SPC2_PHASE4_Msk                                 0x00000FFF  /*!< ADC4 start delay (channel 8,9) */
#define ADC_SPC2_PHASE5_Msk                                 0x0FFF0000  /*!< ADC5 start delay (channel 10,11) */

/*-- SPC3: ADC6, ADC7 start delay register -----------------------------------*/

typedef struct {
  uint32_t PHASE6                                 :12;                  /*!< ADC6 start delay (channel 12,13) */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t PHASE7                                 :12;                  /*!< ADC7 start delay (channel 14,15) */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_SPC3_bits;

/* Bit field positions: */
#define ADC_SPC3_PHASE6_Pos                                 0           /*!< ADC6 start delay (channel 12,13) */
#define ADC_SPC3_PHASE7_Pos                                 16          /*!< ADC7 start delay (channel 14,15) */

/* Bit field masks: */
#define ADC_SPC3_PHASE6_Msk                                 0x00000FFF  /*!< ADC6 start delay (channel 12,13) */
#define ADC_SPC3_PHASE7_Msk                                 0x0FFF0000  /*!< ADC7 start delay (channel 14,15) */

/*-- SPC4: ADC8, ADC9 start delay register -----------------------------------*/

typedef struct {
  uint32_t PHASE8                                 :12;                  /*!< ADC8 start delay (channel 16,17) */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t PHASE9                                 :12;                  /*!< ADC9 start delay (channel 18,19) */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_SPC4_bits;

/* Bit field positions: */
#define ADC_SPC4_PHASE8_Pos                                 0           /*!< ADC8 start delay (channel 16,17) */
#define ADC_SPC4_PHASE9_Pos                                 16          /*!< ADC9 start delay (channel 18,19) */

/* Bit field masks: */
#define ADC_SPC4_PHASE8_Msk                                 0x00000FFF  /*!< ADC8 start delay (channel 16,17) */
#define ADC_SPC4_PHASE9_Msk                                 0x0FFF0000  /*!< ADC9 start delay (channel 18,19) */

/*-- SPC5: ADC10, ADC11 start delay register ---------------------------------*/

typedef struct {
  uint32_t PHASE10                                :12;                  /*!< ADC10 start delay (channel 20,21) */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t PHASE11                                :12;                  /*!< ADC11 start delay (channel 22,23) */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_SPC5_bits;

/* Bit field positions: */
#define ADC_SPC5_PHASE10_Pos                                0           /*!< ADC10 start delay (channel 20,21) */
#define ADC_SPC5_PHASE11_Pos                                16          /*!< ADC11 start delay (channel 22,23) */

/* Bit field masks: */
#define ADC_SPC5_PHASE10_Msk                                0x00000FFF  /*!< ADC10 start delay (channel 20,21) */
#define ADC_SPC5_PHASE11_Msk                                0x0FFF0000  /*!< ADC11 start delay (channel 22,23) */

/*-- SAC: Average control (ADC0-7) register ------------------------------------------*/

typedef struct {
  uint32_t AVG0                                   :3;                   /*!< ADC0 average control */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t AVG1                                   :3;                   /*!< ADC1 average control */
  uint32_t Reserved1                              :1;                   /*!< Reserved */
  uint32_t AVG2                                   :3;                   /*!< ADC2 average control */
  uint32_t Reserved2                              :1;                   /*!< Reserved */
  uint32_t AVG3                                   :3;                   /*!< ADC3 average control */
  uint32_t Reserved3                              :1;                   /*!< Reserved */
  uint32_t AVG4                                   :3;                   /*!< ADC4 average control */
  uint32_t Reserved4                              :1;                   /*!< Reserved */
  uint32_t AVG5                                   :3;                   /*!< ADC5 average control */
  uint32_t Reserved5                              :1;                   /*!< Reserved */
  uint32_t AVG6                                   :3;                   /*!< ADC6 average control */
  uint32_t Reserved6                              :1;                   /*!< Reserved */
  uint32_t AVG7                                   :3;                   /*!< ADC7 average control */
  uint32_t Reserved7                              :1;                   /*!< Reserved */
} _ADC_SAC_bits;

/* Bit field positions: */
#define ADC_SAC_AVG0_Pos                                    0           /*!< ADC0 average control */
#define ADC_SAC_AVG1_Pos                                    4           /*!< ADC1 average control */
#define ADC_SAC_AVG2_Pos                                    8           /*!< ADC2 average control */
#define ADC_SAC_AVG3_Pos                                    12          /*!< ADC3 average control */
#define ADC_SAC_AVG4_Pos                                    16          /*!< ADC4 average control */
#define ADC_SAC_AVG5_Pos                                    20          /*!< ADC5 average control */
#define ADC_SAC_AVG6_Pos                                    24          /*!< ADC6 average control */
#define ADC_SAC_AVG7_Pos                                    28          /*!< ADC7 average control */

/* Bit field masks: */
#define ADC_SAC_AVG0_Msk                                    0x00000007  /*!< ADC0 average control */
#define ADC_SAC_AVG1_Msk                                    0x00000070  /*!< ADC1 average control */
#define ADC_SAC_AVG2_Msk                                    0x00000700  /*!< ADC2 average control */
#define ADC_SAC_AVG3_Msk                                    0x00007000  /*!< ADC3 average control */
#define ADC_SAC_AVG4_Msk                                    0x00070000  /*!< ADC4 average control */
#define ADC_SAC_AVG5_Msk                                    0x00700000  /*!< ADC5 average control */
#define ADC_SAC_AVG6_Msk                                    0x07000000  /*!< ADC6 average control */
#define ADC_SAC_AVG7_Msk                                    0x70000000  /*!< ADC7 average control */

/*-- RICNT: Interrupt counter reset control / Average control (ADC8-11) register ---------------------------------*/

typedef struct {
  uint32_t AVG8                                   :3;                   /*!< ADC8 average control */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t AVG9                                   :3;                   /*!< ADC9 average control */
  uint32_t Reserved1                              :1;                   /*!< Reserved */
  uint32_t AVG10                                  :3;                   /*!< ADC10 average control */
  uint32_t Reserved2                              :1;                   /*!< Reserved */
  uint32_t AVG11                                  :3;                   /*!< ADC11 average control */
  uint32_t Reserved3                              :1;                   /*!< Reserved */
  uint32_t RICNT0                                 :1;                   /*!< Disable interrupt counter reset on sequencer 0 start */
  uint32_t RICNT1                                 :1;                   /*!< Disable interrupt counter reset on sequencer 1 start */
  uint32_t RICNT2                                 :1;                   /*!< Disable interrupt counter reset on sequencer 2 start */
  uint32_t RICNT3                                 :1;                   /*!< Disable interrupt counter reset on sequencer 3 start */
  uint32_t RICNT4                                 :1;                   /*!< Disable interrupt counter reset on sequencer 4 start */
  uint32_t RICNT5                                 :1;                   /*!< Disable interrupt counter reset on sequencer 5 start */
  uint32_t RICNT6                                 :1;                   /*!< Disable interrupt counter reset on sequencer 6 start */
  uint32_t RICNT7                                 :1;                   /*!< Disable interrupt counter reset on sequencer 7 start */
  uint32_t Reserved4                              :8;                   /*!< Reserved */
} _ADC_RICNT_bits;

/* Bit field positions: */
#define ADC_RICNT_AVG8_Pos                                  0           /*!< ADC8 average control */
#define ADC_RICNT_AVG9_Pos                                  4           /*!< ADC9 average control */
#define ADC_RICNT_AVG10_Pos                                 8           /*!< ADC10 average control */
#define ADC_RICNT_AVG11_Pos                                 12          /*!< ADC11 average control */
#define ADC_RICNT_RICNT0_Pos                                16          /*!< Disable interrupt counter reset on sequencer 0 start */
#define ADC_RICNT_RICNT1_Pos                                17          /*!< Disable interrupt counter reset on sequencer 1 start */
#define ADC_RICNT_RICNT2_Pos                                18          /*!< Disable interrupt counter reset on sequencer 2 start */
#define ADC_RICNT_RICNT3_Pos                                19          /*!< Disable interrupt counter reset on sequencer 3 start */
#define ADC_RICNT_RICNT4_Pos                                20          /*!< Disable interrupt counter reset on sequencer 4 start */
#define ADC_RICNT_RICNT5_Pos                                21          /*!< Disable interrupt counter reset on sequencer 5 start */
#define ADC_RICNT_RICNT6_Pos                                22          /*!< Disable interrupt counter reset on sequencer 6 start */
#define ADC_RICNT_RICNT7_Pos                                23          /*!< Disable interrupt counter reset on sequencer 7 start */

/* Bit field masks: */
#define ADC_RICNT_AVG8_Msk                                  0x00000007  /*!< ADC8 average control */
#define ADC_RICNT_AVG9_Msk                                  0x00000070  /*!< ADC9 average control */
#define ADC_RICNT_AVG10_Msk                                 0x00000700  /*!< ADC10 average control */
#define ADC_RICNT_AVG11_Msk                                 0x00007000  /*!< ADC11 average control */
#define ADC_RICNT_RICNT0_Msk                                0x00010000  /*!< Disable interrupt counter reset on sequencer 0 start */
#define ADC_RICNT_RICNT1_Msk                                0x00020000  /*!< Disable interrupt counter reset on sequencer 1 start */
#define ADC_RICNT_RICNT2_Msk                                0x00040000  /*!< Disable interrupt counter reset on sequencer 2 start */
#define ADC_RICNT_RICNT3_Msk                                0x00080000  /*!< Disable interrupt counter reset on sequencer 3 start */
#define ADC_RICNT_RICNT4_Msk                                0x00100000  /*!< Disable interrupt counter reset on sequencer 4 start */
#define ADC_RICNT_RICNT5_Msk                                0x00200000  /*!< Disable interrupt counter reset on sequencer 5 start */
#define ADC_RICNT_RICNT6_Msk                                0x00400000  /*!< Disable interrupt counter reset on sequencer 6 start */
#define ADC_RICNT_RICNT7_Msk                                0x00800000  /*!< Disable interrupt counter reset on sequencer 7 start */

/*-- MUX: Sequencer ADC channels selection register ------------------------*/

typedef struct {
  uint32_t CH0                                    :1;                   /*!< Enable measure on channnel 0 (ADC0 A) */
  uint32_t CH1                                    :1;                   /*!< Enable measure on channnel 1 (ADC0 B) */
  uint32_t CH2                                    :1;                   /*!< Enable measure on channnel 2 (ADC1 A) */
  uint32_t CH3                                    :1;                   /*!< Enable measure on channnel 3 (ADC1 B) */
  uint32_t CH4                                    :1;                   /*!< Enable measure on channnel 4 (ADC2 A) */
  uint32_t CH5                                    :1;                   /*!< Enable measure on channnel 5 (ADC2 B) */
  uint32_t CH6                                    :1;                   /*!< Enable measure on channnel 6 (ADC3 A) */
  uint32_t CH7                                    :1;                   /*!< Enable measure on channnel 7 (ADC3 B) */
  uint32_t CH8                                    :1;                   /*!< Enable measure on channnel 8 (ADC4 A) */
  uint32_t CH9                                    :1;                   /*!< Enable measure on channnel 9 (ADC4 B) */
  uint32_t CH10                                   :1;                   /*!< Enable measure on channnel 10 (ADC5 A) */
  uint32_t CH11                                   :1;                   /*!< Enable measure on channnel 11 (ADC5 B) */
  uint32_t CH12                                   :1;                   /*!< Enable measure on channnel 12 (ADC6 A) */
  uint32_t CH13                                   :1;                   /*!< Enable measure on channnel 13 (ADC6 B) */
  uint32_t CH14                                   :1;                   /*!< Enable measure on channnel 14 (ADC7 A) */
  uint32_t CH15                                   :1;                   /*!< Enable measure on channnel 15 (ADC7 B) */
  uint32_t CH16                                   :1;                   /*!< Enable measure on channnel 16 (ADC8 A) */
  uint32_t CH17                                   :1;                   /*!< Enable measure on channnel 17 (ADC8 B) */
  uint32_t CH18                                   :1;                   /*!< Enable measure on channnel 18 (ADC9 A) */
  uint32_t CH19                                   :1;                   /*!< Enable measure on channnel 19 (ADC9 B) */
  uint32_t CH20                                   :1;                   /*!< Enable measure on channnel 20 (ADC10 A) */
  uint32_t CH21                                   :1;                   /*!< Enable measure on channnel 21 (ADC10 B) */
  uint32_t CH22                                   :1;                   /*!< Enable measure on channnel 22 (ADC11 A) */
  uint32_t CH23                                   :1;                   /*!< Enable measure on channnel 23 (ADC11 B) */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _ADC_MUX_bits;

/* Bit field positions: */
#define ADC_MUX_CH0_Pos                                     0           /*!< Enable measure on channnel 0 (ADC0 A) */
#define ADC_MUX_CH1_Pos                                     1           /*!< Enable measure on channnel 1 (ADC0 B) */
#define ADC_MUX_CH2_Pos                                     2           /*!< Enable measure on channnel 2 (ADC1 A) */
#define ADC_MUX_CH3_Pos                                     3           /*!< Enable measure on channnel 3 (ADC1 B) */
#define ADC_MUX_CH4_Pos                                     4           /*!< Enable measure on channnel 4 (ADC2 A) */
#define ADC_MUX_CH5_Pos                                     5           /*!< Enable measure on channnel 5 (ADC2 B) */
#define ADC_MUX_CH6_Pos                                     6           /*!< Enable measure on channnel 6 (ADC3 A) */
#define ADC_MUX_CH7_Pos                                     7           /*!< Enable measure on channnel 7 (ADC3 B) */
#define ADC_MUX_CH8_Pos                                     8           /*!< Enable measure on channnel 8 (ADC4 A) */
#define ADC_MUX_CH9_Pos                                     9           /*!< Enable measure on channnel 9 (ADC4 B) */
#define ADC_MUX_CH10_Pos                                    10          /*!< Enable measure on channnel 10 (ADC5 A) */
#define ADC_MUX_CH11_Pos                                    11          /*!< Enable measure on channnel 11 (ADC5 B) */
#define ADC_MUX_CH12_Pos                                    12          /*!< Enable measure on channnel 12 (ADC6 A) */
#define ADC_MUX_CH13_Pos                                    13          /*!< Enable measure on channnel 13 (ADC6 B) */
#define ADC_MUX_CH14_Pos                                    14          /*!< Enable measure on channnel 14 (ADC7 A) */
#define ADC_MUX_CH15_Pos                                    15          /*!< Enable measure on channnel 15 (ADC7 B) */
#define ADC_MUX_CH16_Pos                                    16          /*!< Enable measure on channnel 16 (ADC8 A) */
#define ADC_MUX_CH17_Pos                                    17          /*!< Enable measure on channnel 17 (ADC8 B) */
#define ADC_MUX_CH18_Pos                                    18          /*!< Enable measure on channnel 18 (ADC9 A) */
#define ADC_MUX_CH19_Pos                                    19          /*!< Enable measure on channnel 19 (ADC9 B) */
#define ADC_MUX_CH20_Pos                                    20          /*!< Enable measure on channnel 20 (ADC10 A) */
#define ADC_MUX_CH21_Pos                                    21          /*!< Enable measure on channnel 21 (ADC10 B) */
#define ADC_MUX_CH22_Pos                                    22          /*!< Enable measure on channnel 22 (ADC11 A) */
#define ADC_MUX_CH23_Pos                                    23          /*!< Enable measure on channnel 23 (ADC11 B) */

/* Bit field masks: */
#define ADC_MUX_CH0_Msk                                     0x00000001  /*!< Enable measure on channnel 0 (ADC0 A) */
#define ADC_MUX_CH1_Msk                                     0x00000002  /*!< Enable measure on channnel 1 (ADC0 B) */
#define ADC_MUX_CH2_Msk                                     0x00000004  /*!< Enable measure on channnel 2 (ADC1 A) */
#define ADC_MUX_CH3_Msk                                     0x00000008  /*!< Enable measure on channnel 3 (ADC1 B) */
#define ADC_MUX_CH4_Msk                                     0x00000010  /*!< Enable measure on channnel 4 (ADC2 A) */
#define ADC_MUX_CH5_Msk                                     0x00000020  /*!< Enable measure on channnel 5 (ADC2 B) */
#define ADC_MUX_CH6_Msk                                     0x00000040  /*!< Enable measure on channnel 6 (ADC3 A) */
#define ADC_MUX_CH7_Msk                                     0x00000080  /*!< Enable measure on channnel 7 (ADC3 B) */
#define ADC_MUX_CH8_Msk                                     0x00000100  /*!< Enable measure on channnel 8 (ADC4 A) */
#define ADC_MUX_CH9_Msk                                     0x00000200  /*!< Enable measure on channnel 9 (ADC4 B) */
#define ADC_MUX_CH10_Msk                                    0x00000400  /*!< Enable measure on channnel 10 (ADC5 A) */
#define ADC_MUX_CH11_Msk                                    0x00000800  /*!< Enable measure on channnel 11 (ADC5 B) */
#define ADC_MUX_CH12_Msk                                    0x00001000  /*!< Enable measure on channnel 12 (ADC6 A) */
#define ADC_MUX_CH13_Msk                                    0x00002000  /*!< Enable measure on channnel 13 (ADC6 B) */
#define ADC_MUX_CH14_Msk                                    0x00004000  /*!< Enable measure on channnel 14 (ADC7 A) */
#define ADC_MUX_CH15_Msk                                    0x00008000  /*!< Enable measure on channnel 15 (ADC7 B) */
#define ADC_MUX_CH16_Msk                                    0x00010000  /*!< Enable measure on channnel 16 (ADC8 A) */
#define ADC_MUX_CH17_Msk                                    0x00020000  /*!< Enable measure on channnel 17 (ADC8 B) */
#define ADC_MUX_CH18_Msk                                    0x00040000  /*!< Enable measure on channnel 18 (ADC9 A) */
#define ADC_MUX_CH19_Msk                                    0x00080000  /*!< Enable measure on channnel 19 (ADC9 B) */
#define ADC_MUX_CH20_Msk                                    0x00100000  /*!< Enable measure on channnel 20 (ADC10 A) */
#define ADC_MUX_CH21_Msk                                    0x00200000  /*!< Enable measure on channnel 21 (ADC10 B) */
#define ADC_MUX_CH22_Msk                                    0x00400000  /*!< Enable measure on channnel 22 (ADC11 A) */
#define ADC_MUX_CH23_Msk                                    0x00800000  /*!< Enable measure on channnel 23 (ADC11 B) */

/*-- CTL: Sequencer control register ---------------------------------------------------*/

typedef struct {
  uint32_t RCNT                                   :8;                   /*!< Number of ADC restarts by seqensor */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t ICNT                                   :8;                   /*!< Number of ADC restarts for interrupt generation */
  uint32_t WMARK                                  :3;                   /*!< FIFO load threshold for DMA request generation */
  uint32_t Reserved1                              :1;                   /*!< Reserved */
  uint32_t DMAEN                                  :1;                   /*!< Enable DMA use */
  uint32_t Reserved2                              :3;                   /*!< Reserved */
} _ADC_CTL_bits;

/* Bit field positions: */
#define ADC_CTL_RCNT_Pos                                    0           /*!< NNumber of ADC restarts by seqensor */
#define ADC_CTL_ICNT_Pos                                    16          /*!< Number of ADC restarts for interrupt generation */
#define ADC_CTL_WMARK_Pos                                   24          /*!< FIFO load threshold for DMA request generation */
#define ADC_CTL_DMAEN_Pos                                   28          /*!< Enable DMA use */

/* Bit field masks: */
#define ADC_CTL_RCNT_Msk                                    0x000000FF  /*!< Number of ADC restarts by seqensor */
#define ADC_CTL_ICNT_Msk                                    0x00FF0000  /*!< Number of ADC restarts for interrupt generation */
#define ADC_CTL_WMARK_Msk                                   0x07000000  /*!< FIFO load threshold for DMA request generation */
#define ADC_CTL_DMAEN_Msk                                   0x10000000  /*!< Enable DMA use */

/*-- FSTAT: Sequencer FIFO load status register -------------------------------------*/

typedef struct {
  uint32_t FLOAD                                  :6;                   /*!< Sequencer FIFO current load value */
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _ADC_FSTAT_bits;

/* Bit field positions: */
#define ADC_FSTAT_FLOAD_Pos                                 0           /*!< Sequencer FIFO current load value */

/* Bit field masks: */
#define ADC_FSTAT_FLOAD_Msk                                 0x0000003F  /*!< Sequencer FIFO current load value */

/*-- OP: Sequencer ADC restart counter register -----------------------------------------*/

typedef struct {
  uint32_t RCNT                                   :8;                   /*!< Current number of ADC restarts by seqensor */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t ICNT                                   :8;                   /*!< Current number of ADC restarts for interrupt generation */
  uint32_t Reserved1                              :8;                   /*!< Reserved */
} _ADC_OP_bits;

/* Bit field positions: */
#define ADC_OP_RCNT_Pos                                     0           /*!< Current number of ADC restarts by seqensor */
#define ADC_OP_ICNT_Pos                                     16          /*!< Current number of ADC restarts for interrupt generation */

/* Bit field masks: */
#define ADC_OP_RCNT_Msk                                     0x000000FF  /*!< Current number of ADC restarts by seqensor */
#define ADC_OP_ICNT_Msk                                     0x00FF0000  /*!< Current number of ADC restarts for interrupt generation */

/*-- DCP: Sequencer digital comparator selection register -----------------------------------*/

typedef struct {
  uint32_t CMP0                                   :1;                   /*!< Enable DCMP 0 */
  uint32_t CMP1                                   :1;                   /*!< Enable DCMP 1 */
  uint32_t CMP2                                   :1;                   /*!< Enable DCMP 2 */
  uint32_t CMP3                                   :1;                   /*!< Enable DCMP 3 */
  uint32_t CMP4                                   :1;                   /*!< Enable DCMP 4 */
  uint32_t CMP5                                   :1;                   /*!< Enable DCMP 5 */
  uint32_t CMP6                                   :1;                   /*!< Enable DCMP 6 */
  uint32_t CMP7                                   :1;                   /*!< Enable DCMP 7 */
  uint32_t CMP8                                   :1;                   /*!< Enable DCMP 8 */
  uint32_t CMP9                                   :1;                   /*!< Enable DCMP 9 */
  uint32_t CMP10                                  :1;                   /*!< Enable DCMP 10 */
  uint32_t CMP11                                  :1;                   /*!< Enable DCMP 11 */
  uint32_t CMP12                                  :1;                   /*!< Enable DCMP 12 */
  uint32_t CMP13                                  :1;                   /*!< Enable DCMP 13 */
  uint32_t CMP14                                  :1;                   /*!< Enable DCMP 14 */
  uint32_t CMP15                                  :1;                   /*!< Enable DCMP 15 */
  uint32_t CMP16                                  :1;                   /*!< Enable DCMP 16 */
  uint32_t CMP17                                  :1;                   /*!< Enable DCMP 17 */
  uint32_t CMP18                                  :1;                   /*!< Enable DCMP 18 */
  uint32_t CMP19                                  :1;                   /*!< Enable DCMP 19 */
  uint32_t CMP20                                  :1;                   /*!< Enable DCMP 20 */
  uint32_t CMP21                                  :1;                   /*!< Enable DCMP 21 */
  uint32_t CMP22                                  :1;                   /*!< Enable DCMP 22 */
  uint32_t CMP23                                  :1;                   /*!< Enable DCMP 23 */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _ADC_DCP_bits;

/* Bit field positions: */
#define ADC_DCP_CMP0_Pos                                    0           /*!< Enable DCMP 0 */
#define ADC_DCP_CMP1_Pos                                    1           /*!< Enable DCMP 1 */
#define ADC_DCP_CMP2_Pos                                    2           /*!< Enable DCMP 2 */
#define ADC_DCP_CMP3_Pos                                    3           /*!< Enable DCMP 3 */
#define ADC_DCP_CMP4_Pos                                    4           /*!< Enable DCMP 4 */
#define ADC_DCP_CMP5_Pos                                    5           /*!< Enable DCMP 5 */
#define ADC_DCP_CMP6_Pos                                    6           /*!< Enable DCMP 6 */
#define ADC_DCP_CMP7_Pos                                    7           /*!< Enable DCMP 7 */
#define ADC_DCP_CMP8_Pos                                    8           /*!< Enable DCMP 8 */
#define ADC_DCP_CMP9_Pos                                    9           /*!< Enable DCMP 9 */
#define ADC_DCP_CMP10_Pos                                   10          /*!< Enable DCMP 10 */
#define ADC_DCP_CMP11_Pos                                   11          /*!< Enable DCMP 11 */
#define ADC_DCP_CMP12_Pos                                   12          /*!< Enable DCMP 12 */
#define ADC_DCP_CMP13_Pos                                   13          /*!< Enable DCMP 13 */
#define ADC_DCP_CMP14_Pos                                   14          /*!< Enable DCMP 14 */
#define ADC_DCP_CMP15_Pos                                   15          /*!< Enable DCMP 15 */
#define ADC_DCP_CMP16_Pos                                   16          /*!< Enable DCMP 16 */
#define ADC_DCP_CMP17_Pos                                   17          /*!< Enable DCMP 17 */
#define ADC_DCP_CMP18_Pos                                   18          /*!< Enable DCMP 18 */
#define ADC_DCP_CMP19_Pos                                   19          /*!< Enable DCMP 19 */
#define ADC_DCP_CMP20_Pos                                   20          /*!< Enable DCMP 20 */
#define ADC_DCP_CMP21_Pos                                   21          /*!< Enable DCMP 21 */
#define ADC_DCP_CMP22_Pos                                   22          /*!< Enable DCMP 22 */
#define ADC_DCP_CMP23_Pos                                   23          /*!< Enable DCMP 23 */

/* Bit field masks: */
#define ADC_DCP_CMP0_Msk                                    0x00000001  /*!< Enable DCMP 0 */
#define ADC_DCP_CMP1_Msk                                    0x00000002  /*!< Enable DCMP 1 */
#define ADC_DCP_CMP2_Msk                                    0x00000004  /*!< Enable DCMP 2 */
#define ADC_DCP_CMP3_Msk                                    0x00000008  /*!< Enable DCMP 3 */
#define ADC_DCP_CMP4_Msk                                    0x00000010  /*!< Enable DCMP 4 */
#define ADC_DCP_CMP5_Msk                                    0x00000020  /*!< Enable DCMP 5 */
#define ADC_DCP_CMP6_Msk                                    0x00000040  /*!< Enable DCMP 6 */
#define ADC_DCP_CMP7_Msk                                    0x00000080  /*!< Enable DCMP 7 */
#define ADC_DCP_CMP8_Msk                                    0x00000100  /*!< Enable DCMP 8 */
#define ADC_DCP_CMP9_Msk                                    0x00000200  /*!< Enable DCMP 9 */
#define ADC_DCP_CMP10_Msk                                   0x00000400  /*!< Enable DCMP 10 */
#define ADC_DCP_CMP11_Msk                                   0x00000800  /*!< Enable DCMP 11 */
#define ADC_DCP_CMP12_Msk                                   0x00001000  /*!< Enable DCMP 12 */
#define ADC_DCP_CMP13_Msk                                   0x00002000  /*!< Enable DCMP 13 */
#define ADC_DCP_CMP14_Msk                                   0x00004000  /*!< Enable DCMP 14 */
#define ADC_DCP_CMP15_Msk                                   0x00008000  /*!< Enable DCMP 15 */
#define ADC_DCP_CMP16_Msk                                   0x00010000  /*!< Enable DCMP 16 */
#define ADC_DCP_CMP17_Msk                                   0x00020000  /*!< Enable DCMP 17 */
#define ADC_DCP_CMP18_Msk                                   0x00040000  /*!< Enable DCMP 18 */
#define ADC_DCP_CMP19_Msk                                   0x00080000  /*!< Enable DCMP 19 */
#define ADC_DCP_CMP20_Msk                                   0x00100000  /*!< Enable DCMP 20 */
#define ADC_DCP_CMP21_Msk                                   0x00200000  /*!< Enable DCMP 21 */
#define ADC_DCP_CMP22_Msk                                   0x00400000  /*!< Enable DCMP 22 */
#define ADC_DCP_CMP23_Msk                                   0x00800000  /*!< Enable DCMP 23 */

/*-- TMR: Sequencer ADC restart timer register -----------------------*/

typedef struct {
  uint32_t TMR                                    :24;                  /*!< Sequencer ADC restart timer value */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _ADC_TMR_bits;

/* Bit field positions: */
#define ADC_TMR_TMR_Pos                                     0           /*!< Sequencer ADC restart timer value */

/* Bit field masks: */
#define ADC_TMR_TMR_Msk                                     0x00FFFFFF  /*!< Sequencer ADC restart timer value */

/*-- FIFO: Sequencer FIFO register ----------------------------------*/

typedef struct {
  uint32_t DATA                                   :16;                  /*!< AD conversion value */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ADC_FIFO_bits;

/* Bit field positions: */
#define ADC_FIFO_DATA_Pos                                   0           /*!< AD conversion value */

/* Bit field masks: */
#define ADC_FIFO_DATA_Msk                                   0x0000FFFF  /*!< AD conversion value */

/*-- DCCTL: Digital comparator control register --------------------------------------*/

typedef struct {
  uint32_t CIM                                    :2;                   /*!< DCMP interrupt generation mode */
  uint32_t CIC                                    :2;                   /*!< DCMP interrupt generation compare conditions */
  uint32_t CIE                                    :1;                   /*!< Enable DCMP interrupt generation */
  uint32_t Reserved0                              :3;                   /*!< Reserved */
  uint32_t CTM                                    :2;                   /*!< DCMP output trigger mode */
  uint32_t CTC                                    :2;                   /*!< DCMP output trigger compare conditions */
  uint32_t CTE                                    :1;                   /*!< Enable DCMP output trigger */
  uint32_t Reserved1                              :3;                   /*!< Reserved */
  uint32_t CHNL                                   :5;                   /*!< ADC channel selection */
  uint32_t Reserved2                              :11;                  /*!< Reserved */
} _ADC_DCCTL_bits;

/* Bit field positions: */
#define ADC_DCCTL_CIM_Pos                                   0           /*!< DCMP interrupt generation mode */
#define ADC_DCCTL_CIC_Pos                                   2           /*!< DCMP interrupt generation compare conditions */
#define ADC_DCCTL_CIE_Pos                                   4           /*!< Enable DCMP interrupt generation */
#define ADC_DCCTL_CTM_Pos                                   8           /*!< DCMP output trigger mode */
#define ADC_DCCTL_CTC_Pos                                   10          /*!< DCMP output trigger compare conditions */
#define ADC_DCCTL_CTE_Pos                                   12          /*!< Enable DCMP output trigger */
#define ADC_DCCTL_CHNL_Pos                                  16          /*!< ADC channel selection */

/* Bit field masks: */
#define ADC_DCCTL_CIM_Msk                                   0x00000003  /*!< DCMP interrupt generation mode */
#define ADC_DCCTL_CIC_Msk                                   0x0000000C  /*!< DCMP interrupt generation compare conditions */
#define ADC_DCCTL_CIE_Msk                                   0x00000010  /*!< Enable DCMP interrupt generation */
#define ADC_DCCTL_CTM_Msk                                   0x00000300  /*!< DCMP output trigger mode */
#define ADC_DCCTL_CTC_Msk                                   0x00000C00  /*!< DCMP output trigger compare conditions */
#define ADC_DCCTL_CTE_Msk                                   0x00001000  /*!< Enable DCMP output trigger */
#define ADC_DCCTL_CHNL_Msk                                  0x001F0000  /*!< ADC channel selection */

/*-- DCCMP: Digital comparator range register ----------------------------------------*/

typedef struct {
  uint32_t COMP0                                  :12;                  /*!< Low threshold compare value */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t COMP1                                  :12;                  /*!< High threshold compare value */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _ADC_DCCMP_bits;

/* Bit field positions: */
#define ADC_DCCMP_COMP0_Pos                                 0           /*!< Low threshold compare value */
#define ADC_DCCMP_COMP1_Pos                                 16          /*!< High threshold compare value */

/* Bit field masks: */
#define ADC_DCCMP_COMP0_Msk                                 0x00000FFF  /*!< Low threshold compare value */
#define ADC_DCCMP_COMP1_Msk                                 0x0FFF0000  /*!< High threshold compare value */

/*-- DCVAL: Digital comparator measure value register ----------------------------------*/

typedef struct {
  uint32_t VAL                                    :12;                  /*!< Value of last compared AD conversion result */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _ADC_DCVAL_bits;

/* Bit field positions: */
#define ADC_DCVAL_VAL_Pos                                   0           /*!< Value of last compared AD conversion result */

/* Bit field masks: */
#define ADC_DCVAL_VAL_Msk                                   0x00000FFF  /*!< Value of last compared AD conversion result */

/*-- DCRTC: Digital comparator output trigger status register ----------------------------------*/

typedef struct {
  uint32_t DCTRIG0                                :1;                   /*!< DCMP 0 output trigger status */
  uint32_t DCTRIG1                                :1;                   /*!< DCMP 1 output trigger status */
  uint32_t DCTRIG2                                :1;                   /*!< DCMP 2 output trigger status */
  uint32_t DCTRIG3                                :1;                   /*!< DCMP 3 output trigger status */
  uint32_t DCTRIG4                                :1;                   /*!< DCMP 4 output trigger status */
  uint32_t DCTRIG5                                :1;                   /*!< DCMP 5 output trigger status */
  uint32_t DCTRIG6                                :1;                   /*!< DCMP 6 output trigger status */
  uint32_t DCTRIG7                                :1;                   /*!< DCMP 7 output trigger status */
  uint32_t DCTRIG8                                :1;                   /*!< DCMP 8 output trigger status */
  uint32_t DCTRIG9                                :1;                   /*!< DCMP 9 output trigger status */
  uint32_t DCTRIG10                               :1;                   /*!< DCMP 10 output trigger status */
  uint32_t DCTRIG11                               :1;                   /*!< DCMP 11 output trigger status */
  uint32_t DCTRIG12                               :1;                   /*!< DCMP 12 output trigger status */
  uint32_t DCTRIG13                               :1;                   /*!< DCMP 13 output trigger status */
  uint32_t DCTRIG14                               :1;                   /*!< DCMP 14 output trigger status */
  uint32_t DCTRIG15                               :1;                   /*!< DCMP 15 output trigger status */
  uint32_t DCTRIG16                               :1;                   /*!< DCMP 16 output trigger status */
  uint32_t DCTRIG17                               :1;                   /*!< DCMP 17 output trigger status */
  uint32_t DCTRIG18                               :1;                   /*!< DCMP 18 output trigger status */
  uint32_t DCTRIG19                               :1;                   /*!< DCMP 19 output trigger status */
  uint32_t DCTRIG20                               :1;                   /*!< DCMP 20 output trigger status */
  uint32_t DCTRIG21                               :1;                   /*!< DCMP 21 output trigger status */
  uint32_t DCTRIG22                               :1;                   /*!< DCMP 22 output trigger status */
  uint32_t DCTRIG23                               :1;                   /*!< DCMP 23 output trigger status */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _ADC_DCRTC_bits;

/* Bit field positions: */
#define ADC_DCRTC_DCTRIG0_Pos                               0           /*!< DCMP 0 output trigger status */
#define ADC_DCRTC_DCTRIG1_Pos                               1           /*!< DCMP 1 output trigger status */
#define ADC_DCRTC_DCTRIG2_Pos                               2           /*!< DCMP 2 output trigger status */
#define ADC_DCRTC_DCTRIG3_Pos                               3           /*!< DCMP 3 output trigger status */
#define ADC_DCRTC_DCTRIG4_Pos                               4           /*!< DCMP 4 output trigger status */
#define ADC_DCRTC_DCTRIG5_Pos                               5           /*!< DCMP 5 output trigger status */
#define ADC_DCRTC_DCTRIG6_Pos                               6           /*!< DCMP 6 output trigger status */
#define ADC_DCRTC_DCTRIG7_Pos                               7           /*!< DCMP 7 output trigger status */
#define ADC_DCRTC_DCTRIG8_Pos                               8           /*!< DCMP 8 output trigger status */
#define ADC_DCRTC_DCTRIG9_Pos                               9           /*!< DCMP 9 output trigger status */
#define ADC_DCRTC_DCTRIG10_Pos                              10          /*!< DCMP 10 output trigger status */
#define ADC_DCRTC_DCTRIG11_Pos                              11          /*!< DCMP 11 output trigger status */
#define ADC_DCRTC_DCTRIG12_Pos                              12          /*!< DCMP 12 output trigger status */
#define ADC_DCRTC_DCTRIG13_Pos                              13          /*!< DCMP 13 output trigger status */
#define ADC_DCRTC_DCTRIG14_Pos                              14          /*!< DCMP 14 output trigger status */
#define ADC_DCRTC_DCTRIG15_Pos                              15          /*!< DCMP 15 output trigger status */
#define ADC_DCRTC_DCTRIG16_Pos                              16          /*!< DCMP 16 output trigger status */
#define ADC_DCRTC_DCTRIG17_Pos                              17          /*!< DCMP 17 output trigger status */
#define ADC_DCRTC_DCTRIG18_Pos                              18          /*!< DCMP 18 output trigger status */
#define ADC_DCRTC_DCTRIG19_Pos                              19          /*!< DCMP 19 output trigger status */
#define ADC_DCRTC_DCTRIG20_Pos                              20          /*!< DCMP 20 output trigger status */
#define ADC_DCRTC_DCTRIG21_Pos                              21          /*!< DCMP 21 output trigger status */
#define ADC_DCRTC_DCTRIG22_Pos                              22          /*!< DCMP 22 output trigger status */
#define ADC_DCRTC_DCTRIG23_Pos                              23          /*!< DCMP 23 output trigger status */

/* Bit field masks: */
#define ADC_DCRTC_DCTRIG0_Msk                               0x00000001  /*!< DCMP 0 output trigger status */
#define ADC_DCRTC_DCTRIG1_Msk                               0x00000002  /*!< DCMP 1 output trigger status */
#define ADC_DCRTC_DCTRIG2_Msk                               0x00000004  /*!< DCMP 2 output trigger status */
#define ADC_DCRTC_DCTRIG3_Msk                               0x00000008  /*!< DCMP 3 output trigger status */
#define ADC_DCRTC_DCTRIG4_Msk                               0x00000010  /*!< DCMP 4 output trigger status */
#define ADC_DCRTC_DCTRIG5_Msk                               0x00000020  /*!< DCMP 5 output trigger status */
#define ADC_DCRTC_DCTRIG6_Msk                               0x00000040  /*!< DCMP 6 output trigger status */
#define ADC_DCRTC_DCTRIG7_Msk                               0x00000080  /*!< DCMP 7 output trigger status */
#define ADC_DCRTC_DCTRIG8_Msk                               0x00000100  /*!< DCMP 8 output trigger status */
#define ADC_DCRTC_DCTRIG9_Msk                               0x00000200  /*!< DCMP 9 output trigger status */
#define ADC_DCRTC_DCTRIG10_Msk                              0x00000400  /*!< DCMP 10 output trigger status */
#define ADC_DCRTC_DCTRIG11_Msk                              0x00000800  /*!< DCMP 11 output trigger status */
#define ADC_DCRTC_DCTRIG12_Msk                              0x00001000  /*!< DCMP 12 output trigger status */
#define ADC_DCRTC_DCTRIG13_Msk                              0x00002000  /*!< DCMP 13 output trigger status */
#define ADC_DCRTC_DCTRIG14_Msk                              0x00004000  /*!< DCMP 14 output trigger status */
#define ADC_DCRTC_DCTRIG15_Msk                              0x00008000  /*!< DCMP 15 output trigger status */
#define ADC_DCRTC_DCTRIG16_Msk                              0x00010000  /*!< DCMP 16 output trigger status */
#define ADC_DCRTC_DCTRIG17_Msk                              0x00020000  /*!< DCMP 17 output trigger status */
#define ADC_DCRTC_DCTRIG18_Msk                              0x00040000  /*!< DCMP 18 output trigger status */
#define ADC_DCRTC_DCTRIG19_Msk                              0x00080000  /*!< DCMP 19 output trigger status */
#define ADC_DCRTC_DCTRIG20_Msk                              0x00100000  /*!< DCMP 20 output trigger status */
#define ADC_DCRTC_DCTRIG21_Msk                              0x00200000  /*!< DCMP 21 output trigger status */
#define ADC_DCRTC_DCTRIG22_Msk                              0x00400000  /*!< DCMP 22 output trigger status */
#define ADC_DCRTC_DCTRIG23_Msk                              0x00800000  /*!< DCMP 23 output trigger status */

/*-- PP: ADC control register -----------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :16;                  /*!< Reserved */
  uint32_t OM                                     :8;                   /*!< ADC mode */
  uint32_t Reserved1                              :7;                   /*!< Reserved */
  uint32_t ENA                                    :1;                   /*!< Enable ADC */
} _ADC_PP_bits;

/* Bit field positions: */
#define ADC_PP_OM_Pos                                       16          /*!< ADC mode */
#define ADC_PP_ENA_Pos                                      31          /*!< Enable ADC */

/* Bit field masks: */
#define ADC_PP_OM_Msk                                       0x00FF0000  /*!< ADC mode */
#define ADC_PP_ENA_Msk                                      0x80000000  /*!< Enable ADC */

/*-- PSSI: Sequencer sync register ---------------------------------*/

typedef struct {
  uint32_t SS0                                    :1;                   /*!< Enable sequencer 0 software sync */
  uint32_t SS1                                    :1;                   /*!< Enable sequencer 1 software sync */
  uint32_t SS2                                    :1;                   /*!< Enable sequencer 2 software sync */
  uint32_t SS3                                    :1;                   /*!< Enable sequencer 3 software sync */
  uint32_t SS4                                    :1;                   /*!< Enable sequencer 4 software sync */
  uint32_t SS5                                    :1;                   /*!< Enable sequencer 5 software sync */
  uint32_t SS6                                    :1;                   /*!< Enable sequencer 6 software sync */
  uint32_t SS7                                    :1;                   /*!< Enable sequencer 7 software sync */
  uint32_t Reserved0                              :23;                  /*!< Reserved */
  uint32_t GSYNC                                  :1;                   /*!< Sync all sequencers */
} _ADC_PSSI_bits;

/* Bit field positions: */
#define ADC_PSSI_SS0_Pos                                    0           /*!< Enable sequencer 0 software sync */
#define ADC_PSSI_SS1_Pos                                    1           /*!< Enable sequencer 1 software sync */
#define ADC_PSSI_SS2_Pos                                    2           /*!< Enable sequencer 2 software sync */
#define ADC_PSSI_SS3_Pos                                    3           /*!< Enable sequencer 3 software sync */
#define ADC_PSSI_SS4_Pos                                    4           /*!< Enable sequencer 4 software sync */
#define ADC_PSSI_SS5_Pos                                    5           /*!< Enable sequencer 5 software sync */
#define ADC_PSSI_SS6_Pos                                    6           /*!< Enable sequencer 6 software sync */
#define ADC_PSSI_SS7_Pos                                    7           /*!< Enable sequencer 7 software sync */
#define ADC_PSSI_GSYNC_Pos                                  31          /*!< Sync all sequencers */

/* Bit field masks: */
#define ADC_PSSI_SS0_Msk                                    0x00000001  /*!< Enable sequencer 0 software sync */
#define ADC_PSSI_SS1_Msk                                    0x00000002  /*!< Enable sequencer 1 software sync */
#define ADC_PSSI_SS2_Msk                                    0x00000004  /*!< Enable sequencer 2 software sync */
#define ADC_PSSI_SS3_Msk                                    0x00000008  /*!< Enable sequencer 3 software sync */
#define ADC_PSSI_SS4_Msk                                    0x00000010  /*!< Enable sequencer 4 software sync */
#define ADC_PSSI_SS5_Msk                                    0x00000020  /*!< Enable sequencer 5 software sync */
#define ADC_PSSI_SS6_Msk                                    0x00000040  /*!< Enable sequencer 6 software sync */
#define ADC_PSSI_SS7_Msk                                    0x00000080  /*!< Enable sequencer 7 software sync */
#define ADC_PSSI_GSYNC_Msk                                  0x80000000  /*!< Sync all sequencers */

/*-- Register map for ADC peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Sequencer ADC channels selection register */
    __IO uint32_t MUX;                                                  /*!< MUX    : type used for word access */
    __IO _ADC_MUX_bits MUX_bit;                                         /*!< MUX_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer control register */
    __IO uint32_t CTL;                                                  /*!< CTL    : type used for word access */
    __IO _ADC_CTL_bits CTL_bit;                                         /*!< CTL_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< Sequencer FIFO load status register*/
    __I  uint32_t FSTAT;                                                /*!< FSTAT    : type used for word access */
    __I  _ADC_FSTAT_bits FSTAT_bit;                                     /*!< FSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer ADC restart counter register */
    __IO uint32_t OP;                                                   /*!< OP    : type used for word access */
    __IO _ADC_OP_bits OP_bit;                                           /*!< OP_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer digital comparator selection register */
    __IO uint32_t DCP;                                                  /*!< DCP    : type used for word access */
    __IO _ADC_DCP_bits DCP_bit;                                         /*!< DCP_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer ADC restart timer register */
    __IO uint32_t TMR;                                                  /*!< TMR    : type used for word access */
    __IO _ADC_TMR_bits TMR_bit;                                         /*!< TMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer FIFO register */
    __I  uint32_t FIFO;                                                 /*!< FIFO    : type used for word access */
    __I  _ADC_FIFO_bits FIFO_bit;                                       /*!< FIFO_bit: structure used for bit access */
  };
} NT_SEQ_TypeDef;

typedef struct {
  union {                                                               /*!< Enable sequencer register */
    __IO uint32_t ACTSS;                                                /*!< ACTSS    : type used for word access */
    __IO _ADC_ACTSS_bits ACTSS_bit;                                     /*!< ACTSS_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw interrupt status register */
    __I  uint32_t RIS;                                                  /*!< RIS    : type used for word access */
    __I  _ADC_RIS_bits RIS_bit;                                         /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t IM;                                                   /*!< IM    : type used for word access */
    __IO _ADC_IM_bits IM_bit;                                           /*!< IM_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status and clear register */
    __IO uint32_t ISC;                                                  /*!< ISC    : type used for word access */
    __IO _ADC_ISC_bits ISC_bit;                                         /*!< ISC_bit: structure used for bit access */
  };
  union {                                                               /*!< FIFO overflow status register */
    __IO uint32_t OSTAT;                                                /*!< OSTAT    : type used for word access */
    __IO _ADC_OSTAT_bits OSTAT_bit;                                     /*!< OSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer start event selection register */
    __IO uint32_t EMUX;                                                 /*!< EMUX    : type used for word access */
    __IO _ADC_EMUX_bits EMUX_bit;                                       /*!< EMUX_bit: structure used for bit access */
  };
  union {                                                               /*!< FIFO underflow status register */
    __IO uint32_t USTAT;                                                /*!< USTAT    : type used for word access */
    __IO _ADC_USTAT_bits USTAT_bit;                                     /*!< USTAT_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< ADC0, ADC1 start delay register */
    __IO uint32_t SPC0;                                                 /*!< SPC0    : type used for word access */
    __IO _ADC_SPC0_bits SPC0_bit;                                       /*!< SPC0_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC2, ADC3 start delay register */
    __IO uint32_t SPC1;                                                 /*!< SPC1    : type used for word access */
    __IO _ADC_SPC1_bits SPC1_bit;                                       /*!< SPC1_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC4, ADC5 start delay register */
    __IO uint32_t SPC2;                                                 /*!< SPC2    : type used for word access */
    __IO _ADC_SPC2_bits SPC2_bit;                                       /*!< SPC2_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC6, ADC7 start delay register */
    __IO uint32_t SPC3;                                                 /*!< SPC3    : type used for word access */
    __IO _ADC_SPC3_bits SPC3_bit;                                       /*!< SPC3_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC8, ADC9 start delay register */
    __IO uint32_t SPC4;                                                 /*!< SPC4    : type used for word access */
    __IO _ADC_SPC4_bits SPC4_bit;                                       /*!< SPC4_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC10, ADC11 start delay register */
    __IO uint32_t SPC5;                                                 /*!< SPC5    : type used for word access */
    __IO _ADC_SPC5_bits SPC5_bit;                                       /*!< SPC5_bit: structure used for bit access */
  };
  union {                                                               /*!< Average control (ADC0-7) register */
    __IO uint32_t SAC;                                                  /*!< SAC    : type used for word access */
    __IO _ADC_SAC_bits SAC_bit;                                         /*!< SAC_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt counter reset control / Average control (ADC8-11) register */
    __IO uint32_t RICNT;                                                /*!< RICNT    : type used for word access */
    __IO _ADC_RICNT_bits RICNT_bit;                                     /*!< RICNT_bit: structure used for bit access */
  };
  NT_SEQ_TypeDef SEQ[8];
  union {                                                               /*!< Digital comparator control register */
    __IO uint32_t DCCTL[24];                                            /*!< DCCTL    : type used for word access */
    __IO _ADC_DCCTL_bits DCCTL_bit[24];                                 /*!< DCCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital comparator range register */
    __IO uint32_t DCCMP[24];                                            /*!< DCCMP    : type used for word access */
    __IO _ADC_DCCMP_bits DCCMP_bit[24];                                 /*!< DCCMP_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital comparator measure value register */
    __I  uint32_t DCVAL[24];                                            /*!< DCVAL    : type used for word access */
    __I  _ADC_DCVAL_bits DCVAL_bit[24];                                 /*!< DCVAL_bit: structure used for bit access */
  };
  uint32_t Reserved1[35];                                               /*!< Reserved */
  union {                                                               /*!< Digital comparator output trigger status register */
    __O  uint32_t DCRTC;                                                /*!< DCRTC    : type used for word access */
    __O  _ADC_DCRTC_bits DCRTC_bit;                                     /*!< DCRTC_bit: structure used for bit access */
  };
  uint32_t Reserved2[4];                                                /*!< Reserved */
  union {                                                               /*!< ADC control register */
    __IO uint32_t PP[12];                                               /*!< PP    : type used for word access */
    __IO _ADC_PP_bits PP_bit[12];                                       /*!< PP_bit: structure used for bit access */
  };
  uint32_t Reserved3[50];                                               /*!< Reserved */
  union {                                                               /*!< Sequencer sync register */
    __IO uint32_t PSSI;                                                 /*!< PSSI    : type used for word access */
    __IO _ADC_PSSI_bits PSSI_bit;                                       /*!< PSSI_bit: structure used for bit access */
  };
} NT_ADC_TypeDef;

/******************************************************************************/
/*                         GPIO controller regisres                           */
/******************************************************************************/

/*-- DATA: Data input register -----------------------------------------------*/

typedef struct {
  uint32_t DATA                                   :16;                  /*!< Sampled at port */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_DATA_bits;

/* Bit field positions: */
#define GPIO_DATA_DATA_Pos                                  0           /*!< Sampled at port */

/* Bit field masks: */
#define GPIO_DATA_DATA_Msk                                  0x0000FFFF  /*!< Sampled at port */

/*-- DATAOUT: Data output register -------------------------------------------*/

typedef struct {
  uint32_t DATAOUT                                :16;                  /*!< Data output */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_DATAOUT_bits;

/* Bit field positions: */
#define GPIO_DATAOUT_DATAOUT_Pos                            0           /*!< Data output */

/* Bit field masks: */
#define GPIO_DATAOUT_DATAOUT_Msk                            0x0000FFFF  /*!< Data output */

/*-- OUTENSET: Output enable set register -------------------------------*/

typedef struct {
  uint32_t OUTENSET                               :16;                  /*!< Set the output enable */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_OUTENSET_bits;

/* Bit field positions: */
#define GPIO_OUTENSET_OUTENSET_Pos                          0           /*!< Set the output enable */

/* Bit field masks: */
#define GPIO_OUTENSET_OUTENSET_Msk                          0x0000FFFF  /*!< Set the output enable */

/*-- OUTENCLR: Output enable clear register ----------------------------------------*/

typedef struct {
  uint32_t OUTENCLR                               :16;                  /*!< Clear the output enable */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_OUTENCLR_bits;

/* Bit field positions: */
#define GPIO_OUTENCLR_OUTENCLR_Pos                          0           /*!< Clear the output enable */

/* Bit field masks: */
#define GPIO_OUTENCLR_OUTENCLR_Msk                          0x0000FFFF  /*!< Clear the output enable */

/*-- ALTFUNCSET: Alternative function set register ---------------------*/

typedef struct {
  uint32_t ALTFUNCSET                             :16;                  /*!< Set the alternative function enable */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_ALTFUNCSET_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCSET_ALTFUNCSET_Pos                      0           /*!< Set the alternative function enable */

/* Bit field masks: */
#define GPIO_ALTFUNCSET_ALTFUNCSET_Msk                      0x0000FFFF  /*!< Set the alternative function enable */

/*-- ALTFUNCCLR: Alternative function clear register --------------------*/

typedef struct {
  uint32_t ALTFUNCCLR                             :16;                  /*!< Clear the alternative function enable */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_ALTFUNCCLR_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCCLR_ALTFUNCCLR_Pos                      0           /*!< Clear the alternative function enable */

/* Bit field masks: */
#define GPIO_ALTFUNCCLR_ALTFUNCCLR_Msk                      0x0000FFFF  /*!< Clear the alternative function enable */

/*-- INTENSET: Interrupt enable set register ----------------------*/

typedef struct {
  uint32_t INTENSET                               :16;                  /*!< Set the interrupt enable */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTENSET_bits;

/* Bit field positions: */
#define GPIO_INTENSET_INTENSET_Pos                          0           /*!< Set the interrupt enable */

/* Bit field masks: */
#define GPIO_INTENSET_INTENSET_Msk                          0x0000FFFF  /*!< Set the interrupt enable */

/*-- INTENCLR: Interrupt enable clear register ---------------------*/

typedef struct {
  uint32_t INTENCLR                               :16;                  /*!< Clear the interrupt enable  */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTENCLR_bits;

/* Bit field positions: */
#define GPIO_INTENCLR_INTENCLR_Pos                          0           /*!< Clear the interrupt enable */

/* Bit field masks: */
#define GPIO_INTENCLR_INTENCLR_Msk                          0x0000FFFF  /*!< Clear the interrupt enable */

/*-- INTTYPESET: Interrupt type set register ----------------------------*/

typedef struct {
  uint32_t INTTYPESET                             :16;                  /*!< Set the interrupt type */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTTYPESET_bits;

/* Bit field positions: */
#define GPIO_INTTYPESET_INTTYPESET_Pos                      0           /*!< Set the interrupt type */

/* Bit field masks: */
#define GPIO_INTTYPESET_INTTYPESET_Msk                      0x0000FFFF  /*!< Set the interrupt type */

/*-- INTTYPECLR: Interrupt type clear register ----------------------------*/

typedef struct {
  uint32_t INTTYPECLR                             :16;                  /*!< Clear the interrupt type */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTTYPECLR_bits;

/* Bit field positions: */
#define GPIO_INTTYPECLR_INTTYPECLR_Pos                      0           /*!< Clear the interrupt type */

/* Bit field masks: */
#define GPIO_INTTYPECLR_INTTYPECLR_Msk                      0x0000FFFF  /*!< Clear the interrupt type */

/*-- INTPOLSET: Interrupt polarity set register ----------------------------*/

typedef struct {
  uint32_t INTPOLSET                              :16;                  /*!< Set the interrupt polarity */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTPOLSET_bits;

/* Bit field positions: */
#define GPIO_INTPOLSET_INTPOLSET_Pos                        0           /*!< Set the interrupt polarity */

/* Bit field masks: */
#define GPIO_INTPOLSET_INTPOLSET_Msk                        0x0000FFFF  /*!< Set the interrupt polarity */

/*-- INTPOLCLR: Interrupt polarity clear register ----------------------------*/

typedef struct {
  uint32_t INTPOLCLR                              :16;                  /*!< Clear the interrupt polarity */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTPOLCLR_bits;

/* Bit field positions: */
#define GPIO_INTPOLCLR_INTPOLCLR_Pos                        0           /*!< Clear the interrupt polarity */

/* Bit field masks: */
#define GPIO_INTPOLCLR_INTPOLCLR_Msk                        0x0000FFFF  /*!< Clear the interrupt polarity */

/*-- INTSTATUS: Interrupt status register */

typedef struct {
  uint32_t INTSTATUS                              :16;                  /*!< Interrupt status */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _GPIO_INTSTATUS_bits;

/* Bit field positions: */
#define GPIO_INTSTATUS_INTSTATUS_Pos                        0           /*!< Interrupt status */

/* Bit field masks: */
#define GPIO_INTSTATUS_INTSTATUS_Msk                        0x0000FFFF  /*!< Interrupt status */

/*-- MASKLOWBYTE: Lower byte masked access register -----------------------------*/

typedef struct {
  uint32_t MASKLB                                 :8;                   /*!< Data for lower byte masked access */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _GPIO_MASKLOWBYTE_bits;

/* Bit field positions: */
#define GPIO_MASKLOWBYTE_MASKLB_Pos                         0           /*!< Data for lower byte masked access */

/* Bit field masks: */
#define GPIO_MASKLOWBYTE_MASKLB_Msk                         0x000000FF  /*!< Data for lower byte masked access */

/*-- MASKHIGHBYTE: Higher byte masked access register ---------------------------*/

typedef struct {
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t MASKHB                                 :8;                   /*!< Data for higher byte masked access */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _GPIO_MASKHIGHBYTE_bits;

/* Bit field positions: */
#define GPIO_MASKHIGHBYTE_MASKHB_Pos                        8           /*!< Data for higher byte masked access */

/* Bit field masks: */
#define GPIO_MASKHIGHBYTE_MASKHB_Msk                        0x0000FF00  /*!< Data for higher byte masked access */

/*-- Register map for GPIO peripheral ----------------------------------------*/

typedef struct {
  union {                                                               /*!< Data input register */
    __IO uint32_t DATA;                                                 /*!< DATA    : type used for word access */
    __IO _GPIO_DATA_bits DATA_bit;                                      /*!< DATA_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output register */
    __IO uint32_t DATAOUT;                                              /*!< DATAOUT    : type used for word access */
    __IO _GPIO_DATAOUT_bits DATAOUT_bit;                                /*!< DATAOUT_bit: structure used for bit access */
  };
  uint32_t Reserved0[2];                                                /*!< Reserved */
  union {                                                               /*!< Output enable set register */
    __IO uint32_t OUTENSET;                                             /*!< OUTENSET    : type used for word access */
    __IO _GPIO_OUTENSET_bits OUTENSET_bit;                              /*!< OUTENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Output enable clear register */
    __IO uint32_t OUTENCLR;                                             /*!< OUTENCLR    : type used for word access */
    __IO _GPIO_OUTENCLR_bits OUTENCLR_bit;                              /*!< OUTENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function set register */
    __IO uint32_t ALTFUNCSET;                                           /*!< ALTFUNCSET    : type used for word access */
    __IO _GPIO_ALTFUNCSET_bits ALTFUNCSET_bit;                          /*!< ALTFUNCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function clear register */
    __IO uint32_t ALTFUNCCLR;                                           /*!< ALTFUNCCLR    : type used for word access */
    __IO _GPIO_ALTFUNCCLR_bits ALTFUNCCLR_bit;                          /*!< ALTFUNCCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt enable set register */
    __IO uint32_t INTENSET;                                             /*!< INTENSET    : type used for word access */
    __IO _GPIO_INTENSET_bits INTENSET_bit;                              /*!< INTENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt enable clear register */
    __IO uint32_t INTENCLR;                                             /*!< INTENCLR    : type used for word access */
    __IO _GPIO_INTENCLR_bits INTENCLR_bit;                              /*!< INTENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt type set register */
    __IO uint32_t INTTYPESET;                                           /*!< INTTYPESET    : type used for word access */
    __IO _GPIO_INTTYPESET_bits INTTYPESET_bit;                          /*!< INTTYPESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt type clear register*/
    __IO uint32_t INTTYPECLR;                                           /*!< INTTYPECLR    : type used for word access */
    __IO _GPIO_INTTYPECLR_bits INTTYPECLR_bit;                          /*!< INTTYPECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt polarity set register */
    __IO uint32_t INTPOLSET;                                            /*!< INTPOLSET    : type used for word access */
    __IO _GPIO_INTPOLSET_bits INTPOLSET_bit;                            /*!< INTPOLSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt polarity clear register */
    __IO uint32_t INTPOLCLR;                                            /*!< INTPOLCLR    : type used for word access */
    __IO _GPIO_INTPOLCLR_bits INTPOLCLR_bit;                            /*!< INTPOLCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status register */
    __IO uint32_t INTSTATUS;                                            /*!< INTSTATUS    : type used for word access */
    __IO _GPIO_INTSTATUS_bits INTSTATUS_bit;                            /*!< INTSTATUS_bit: structure used for bit access */
  };
  uint32_t Reserved1[241];                                              /*!< Reserved */
  union {                                                               /*!< Lower byte masked access register */
    __IO uint32_t MASKLOWBYTE[256];                                     /*!< MASKLOWBYTE    : type used for word access */
    __IO _GPIO_MASKLOWBYTE_bits MASKLOWBYTE_bit[256];                   /*!< MASKLOWBYTE_bit: structure used for bit access */
  };
  union {                                                               /*!< Higher byte masked access register */
    __IO uint32_t MASKHIGHBYTE[256];                                    /*!< MASKHIGHBYTE    : type used for word access */
    __IO _GPIO_MASKHIGHBYTE_bits MASKHIGHBYTE_bit[256];                 /*!< MASKHIGHBYTE_bit: structure used for bit access */
  };
} NT_GPIO_TypeDef;

/******************************************************************************/
/*                          Common block registers                            */
/******************************************************************************/

/*-- GPIODEN0: Port A,B digital enable register -------------------------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Port A digital output (GPIO or ALTFUNC) enable */
  uint32_t PORTB                                  :16;                  /*!< Port B digital output (GPIO or ALTFUNC) enable */
} _COMMON_REG_GPIODEN0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODEN0_PORTA_Pos                       0           /*!< Port A digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN0_PORTB_Pos                       16          /*!< Port B digital output (GPIO or ALTFUNC) enable */

/* Bit field masks: */
#define COMMON_REG_GPIODEN0_PORTA_Msk                       0x0000FFFF  /*!< Port A digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN0_PORTB_Msk                       0xFFFF0000  /*!< Port B digital output (GPIO or ALTFUNC) enable */

/*-- GPIODEN1: Port C,D digital enable register -------------------------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Port C digital output (GPIO or ALTFUNC) enable */
  uint32_t PORTD                                  :16;                  /*!< Port D digital output (GPIO or ALTFUNC) enable */
} _COMMON_REG_GPIODEN1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODEN1_PORTC_Pos                       0           /*!< Port C digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN1_PORTD_Pos                       16          /*!< Port D digital output (GPIO or ALTFUNC) enable */

/* Bit field masks: */
#define COMMON_REG_GPIODEN1_PORTC_Msk                       0x0000FFFF  /*!< Port C digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN1_PORTD_Msk                       0xFFFF0000  /*!< Port D digital output (GPIO or ALTFUNC) enable */

/*-- GPIODEN2: Port E,F digital enable register -------------------------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Port E digital output (GPIO or ALTFUNC) enable */
  uint32_t PORTF                                  :16;                  /*!< Port F digital output (GPIO or ALTFUNC) enable */
} _COMMON_REG_GPIODEN2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODEN2_PORTE_Pos                       0           /*!< Port E digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN2_PORTF_Pos                       16          /*!< Port F digital output (GPIO or ALTFUNC) enable */

/* Bit field masks: */
#define COMMON_REG_GPIODEN2_PORTE_Msk                       0x0000FFFF  /*!< Port E digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN2_PORTF_Msk                       0xFFFF0000  /*!< Port F digital output (GPIO or ALTFUNC) enable */

/*-- GPIODEN3: Port G,H digital enable register -------------------------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Port G digital output (GPIO or ALTFUNC) enable */
  uint32_t PORTH                                  :16;                  /*!< Port H digital output (GPIO or ALTFUNC) enable */
} _COMMON_REG_GPIODEN3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODEN3_PORTG_Pos                       0           /*!< Port G digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN3_PORTH_Pos                       16          /*!< Port H digital output (GPIO or ALTFUNC) enable */

/* Bit field masks: */
#define COMMON_REG_GPIODEN3_PORTG_Msk                       0x0000FFFF  /*!< Port G digital output (GPIO or ALTFUNC) enable */
#define COMMON_REG_GPIODEN3_PORTH_Msk                       0xFFFF0000  /*!< Port H digital output (GPIO or ALTFUNC) enable */

/*-- GPIOPCTLA: Port A alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin A0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin A1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin A2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin A3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin A4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin A5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin A6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin A7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin A8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin A9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin A10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin A11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin A12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin A13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin A14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin A15 alternative function selection */
} _COMMON_REG_GPIOPCTLA_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLA_PIN0_Pos                       0           /*!< Pin A0 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN1_Pos                       2           /*!< Pin A1 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN2_Pos                       4           /*!< Pin A2 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN3_Pos                       6           /*!< Pin A3 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN4_Pos                       8           /*!< Pin A4 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN5_Pos                       10          /*!< Pin A5 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN6_Pos                       12          /*!< Pin A6 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN7_Pos                       14          /*!< Pin A7 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN8_Pos                       16          /*!< Pin A8 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN9_Pos                       18          /*!< Pin A9 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN10_Pos                      20          /*!< Pin A10 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN11_Pos                      22          /*!< Pin A11 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN12_Pos                      24          /*!< Pin A12 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN13_Pos                      26          /*!< Pin A13 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN14_Pos                      28          /*!< Pin A14 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN15_Pos                      30          /*!< Pin A15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLA_PIN0_Msk                       0x00000003  /*!< Pin A0 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN1_Msk                       0x0000000C  /*!< Pin A1 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN2_Msk                       0x00000030  /*!< Pin A2 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN3_Msk                       0x000000C0  /*!< Pin A3 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN4_Msk                       0x00000300  /*!< Pin A4 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN5_Msk                       0x00000C00  /*!< Pin A5 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN6_Msk                       0x00003000  /*!< Pin A6 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN7_Msk                       0x0000C000  /*!< Pin A7 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN8_Msk                       0x00030000  /*!< Pin A8 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN9_Msk                       0x000C0000  /*!< Pin A9 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN10_Msk                      0x00300000  /*!< Pin A10 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN11_Msk                      0x00C00000  /*!< Pin A11 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN12_Msk                      0x03000000  /*!< Pin A12 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN13_Msk                      0x0C000000  /*!< Pin A13 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN14_Msk                      0x30000000  /*!< Pin A14 alternative function selection */
#define COMMON_REG_GPIOPCTLA_PIN15_Msk                      0xC0000000  /*!< Pin A15 alternative function selection */

/*-- GPIOPCTLB: Port B alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin B0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin B1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin B2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin B3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin B4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin B5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin B6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin B7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin B8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin B9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin B10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin B11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin B12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin B13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin B14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin B15 alternative function selection */
} _COMMON_REG_GPIOPCTLB_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLB_PIN0_Pos                       0           /*!< Pin B0 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN1_Pos                       2           /*!< Pin B1 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN2_Pos                       4           /*!< Pin B2 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN3_Pos                       6           /*!< Pin B3 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN4_Pos                       8           /*!< Pin B4 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN5_Pos                       10          /*!< Pin B5 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN6_Pos                       12          /*!< Pin B6 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN7_Pos                       14          /*!< Pin B7 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN8_Pos                       16          /*!< Pin B8 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN9_Pos                       18          /*!< Pin B9 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN10_Pos                      20          /*!< Pin B10 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN11_Pos                      22          /*!< Pin B11 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN12_Pos                      24          /*!< Pin B12 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN13_Pos                      26          /*!< Pin B13 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN14_Pos                      28          /*!< Pin B14 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN15_Pos                      30          /*!< Pin B15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLB_PIN0_Msk                       0x00000003  /*!< Pin B0 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN1_Msk                       0x0000000C  /*!< Pin B1 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN2_Msk                       0x00000030  /*!< Pin B2 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN3_Msk                       0x000000C0  /*!< Pin B3 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN4_Msk                       0x00000300  /*!< Pin B4 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN5_Msk                       0x00000C00  /*!< Pin B5 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN6_Msk                       0x00003000  /*!< Pin B6 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN7_Msk                       0x0000C000  /*!< Pin B7 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN8_Msk                       0x00030000  /*!< Pin B8 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN9_Msk                       0x000C0000  /*!< Pin B9 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN10_Msk                      0x00300000  /*!< Pin B10 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN11_Msk                      0x00C00000  /*!< Pin B11 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN12_Msk                      0x03000000  /*!< Pin B12 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN13_Msk                      0x0C000000  /*!< Pin B13 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN14_Msk                      0x30000000  /*!< Pin B14 alternative function selection */
#define COMMON_REG_GPIOPCTLB_PIN15_Msk                      0xC0000000  /*!< Pin B15 alternative function selection */

/*-- GPIOPCTLC: Port C alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin C0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin C1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin C2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin C3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin C4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin C5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin C6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin C7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin C8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin C9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin C10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin C11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin C12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin C13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin C14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin C15 alternative function selection */
} _COMMON_REG_GPIOPCTLC_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLC_PIN0_Pos                       0           /*!< Pin C0 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN1_Pos                       2           /*!< Pin C1 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN2_Pos                       4           /*!< Pin C2 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN3_Pos                       6           /*!< Pin C3 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN4_Pos                       8           /*!< Pin C4 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN5_Pos                       10          /*!< Pin C5 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN6_Pos                       12          /*!< Pin C6 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN7_Pos                       14          /*!< Pin C7 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN8_Pos                       16          /*!< Pin C8 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN9_Pos                       18          /*!< Pin C9 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN10_Pos                      20          /*!< Pin C10 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN11_Pos                      22          /*!< Pin C11 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN12_Pos                      24          /*!< Pin C12 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN13_Pos                      26          /*!< Pin C13 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN14_Pos                      28          /*!< Pin C14 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN15_Pos                      30          /*!< Pin C15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLC_PIN0_Msk                       0x00000003  /*!< Pin C0 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN1_Msk                       0x0000000C  /*!< Pin C1 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN2_Msk                       0x00000030  /*!< Pin C2 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN3_Msk                       0x000000C0  /*!< Pin C3 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN4_Msk                       0x00000300  /*!< Pin C4 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN5_Msk                       0x00000C00  /*!< Pin C5 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN6_Msk                       0x00003000  /*!< Pin C6 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN7_Msk                       0x0000C000  /*!< Pin C7 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN8_Msk                       0x00030000  /*!< Pin C8 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN9_Msk                       0x000C0000  /*!< Pin C9 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN10_Msk                      0x00300000  /*!< Pin C10 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN11_Msk                      0x00C00000  /*!< Pin C11 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN12_Msk                      0x03000000  /*!< Pin C12 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN13_Msk                      0x0C000000  /*!< Pin C13 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN14_Msk                      0x30000000  /*!< Pin C14 alternative function selection */
#define COMMON_REG_GPIOPCTLC_PIN15_Msk                      0xC0000000  /*!< Pin C15 alternative function selection */

/*-- GPIOPCTLD: Port D alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin D0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin D1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin D2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin D3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin D4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin D5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin D6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin D7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin D8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin D9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin D10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin D11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin D12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin D13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin D14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin D15 alternative function selection */
} _COMMON_REG_GPIOPCTLD_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLD_PIN0_Pos                       0           /*!< Pin D0 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN1_Pos                       2           /*!< Pin D1 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN2_Pos                       4           /*!< Pin D2 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN3_Pos                       6           /*!< Pin D3 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN4_Pos                       8           /*!< Pin D4 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN5_Pos                       10          /*!< Pin D5 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN6_Pos                       12          /*!< Pin D6 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN7_Pos                       14          /*!< Pin D7 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN8_Pos                       16          /*!< Pin D8 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN9_Pos                       18          /*!< Pin D9 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN10_Pos                      20          /*!< Pin D10 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN11_Pos                      22          /*!< Pin D11 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN12_Pos                      24          /*!< Pin D12 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN13_Pos                      26          /*!< Pin D13 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN14_Pos                      28          /*!< Pin D14 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN15_Pos                      30          /*!< Pin D15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLD_PIN0_Msk                       0x00000003  /*!< Pin D0 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN1_Msk                       0x0000000C  /*!< Pin D1 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN2_Msk                       0x00000030  /*!< Pin D2 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN3_Msk                       0x000000C0  /*!< Pin D3 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN4_Msk                       0x00000300  /*!< Pin D4 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN5_Msk                       0x00000C00  /*!< Pin D5 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN6_Msk                       0x00003000  /*!< Pin D6 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN7_Msk                       0x0000C000  /*!< Pin D7 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN8_Msk                       0x00030000  /*!< Pin D8 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN9_Msk                       0x000C0000  /*!< Pin D9 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN10_Msk                      0x00300000  /*!< Pin D10 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN11_Msk                      0x00C00000  /*!< Pin D11 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN12_Msk                      0x03000000  /*!< Pin D12 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN13_Msk                      0x0C000000  /*!< Pin D13 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN14_Msk                      0x30000000  /*!< Pin D14 alternative function selection */
#define COMMON_REG_GPIOPCTLD_PIN15_Msk                      0xC0000000  /*!< Pin D15 alternative function selection */

/*-- GPIOPCTLE: Port E alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin E0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin E1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin E2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin E3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin E4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin E5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin E6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin E7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin E8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin E9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin E10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin E11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin E12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin E13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin E14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin E15 alternative function selection */
} _COMMON_REG_GPIOPCTLE_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLE_PIN0_Pos                       0           /*!< Pin E0 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN1_Pos                       2           /*!< Pin E1 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN2_Pos                       4           /*!< Pin E2 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN3_Pos                       6           /*!< Pin E3 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN4_Pos                       8           /*!< Pin E4 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN5_Pos                       10          /*!< Pin E5 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN6_Pos                       12          /*!< Pin E6 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN7_Pos                       14          /*!< Pin E7 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN8_Pos                       16          /*!< Pin E8 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN9_Pos                       18          /*!< Pin E9 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN10_Pos                      20          /*!< Pin E10 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN11_Pos                      22          /*!< Pin E11 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN12_Pos                      24          /*!< Pin E12 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN13_Pos                      26          /*!< Pin E13 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN14_Pos                      28          /*!< Pin E14 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN15_Pos                      30          /*!< Pin E15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLE_PIN0_Msk                       0x00000003  /*!< Pin E0 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN1_Msk                       0x0000000C  /*!< Pin E1 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN2_Msk                       0x00000030  /*!< Pin E2 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN3_Msk                       0x000000C0  /*!< Pin E3 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN4_Msk                       0x00000300  /*!< Pin E4 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN5_Msk                       0x00000C00  /*!< Pin E5 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN6_Msk                       0x00003000  /*!< Pin E6 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN7_Msk                       0x0000C000  /*!< Pin E7 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN8_Msk                       0x00030000  /*!< Pin E8 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN9_Msk                       0x000C0000  /*!< Pin E9 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN10_Msk                      0x00300000  /*!< Pin E10 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN11_Msk                      0x00C00000  /*!< Pin E11 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN12_Msk                      0x03000000  /*!< Pin E12 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN13_Msk                      0x0C000000  /*!< Pin E13 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN14_Msk                      0x30000000  /*!< Pin E14 alternative function selection */
#define COMMON_REG_GPIOPCTLE_PIN15_Msk                      0xC0000000  /*!< Pin E15 alternative function selection */

/*-- GPIOPCTLF: Port F alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin F0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin F1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin F2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin F3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin F4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin F5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin F6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin F7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin F8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin F9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin F10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin F11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin F12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin F13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin F14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin F15 alternative function selection */
} _COMMON_REG_GPIOPCTLF_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLF_PIN0_Pos                       0           /*!< Pin F0 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN1_Pos                       2           /*!< Pin F1 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN2_Pos                       4           /*!< Pin F2 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN3_Pos                       6           /*!< Pin F3 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN4_Pos                       8           /*!< Pin F4 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN5_Pos                       10          /*!< Pin F5 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN6_Pos                       12          /*!< Pin F6 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN7_Pos                       14          /*!< Pin F7 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN8_Pos                       16          /*!< Pin F8 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN9_Pos                       18          /*!< Pin F9 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN10_Pos                      20          /*!< Pin F10 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN11_Pos                      22          /*!< Pin F11 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN12_Pos                      24          /*!< Pin F12 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN13_Pos                      26          /*!< Pin F13 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN14_Pos                      28          /*!< Pin F14 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN15_Pos                      30          /*!< Pin F15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLF_PIN0_Msk                       0x00000003  /*!< Pin F0 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN1_Msk                       0x0000000C  /*!< Pin F1 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN2_Msk                       0x00000030  /*!< Pin F2 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN3_Msk                       0x000000C0  /*!< Pin F3 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN4_Msk                       0x00000300  /*!< Pin F4 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN5_Msk                       0x00000C00  /*!< Pin F5 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN6_Msk                       0x00003000  /*!< Pin F6 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN7_Msk                       0x0000C000  /*!< Pin F7 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN8_Msk                       0x00030000  /*!< Pin F8 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN9_Msk                       0x000C0000  /*!< Pin F9 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN10_Msk                      0x00300000  /*!< Pin F10 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN11_Msk                      0x00C00000  /*!< Pin F11 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN12_Msk                      0x03000000  /*!< Pin F12 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN13_Msk                      0x0C000000  /*!< Pin F13 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN14_Msk                      0x30000000  /*!< Pin F14 alternative function selection */
#define COMMON_REG_GPIOPCTLF_PIN15_Msk                      0xC0000000  /*!< Pin F15 alternative function selection */

/*-- GPIOPCTLG: Port G alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin G0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin G1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin G2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin G3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin G4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin G5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin G6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin G7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin G8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin G9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin G10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin G11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin G12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin G13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin G14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin G15 alternative function selection */
} _COMMON_REG_GPIOPCTLG_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLG_PIN0_Pos                       0           /*!< Pin G0 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN1_Pos                       2           /*!< Pin G1 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN2_Pos                       4           /*!< Pin G2 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN3_Pos                       6           /*!< Pin G3 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN4_Pos                       8           /*!< Pin G4 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN5_Pos                       10          /*!< Pin G5 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN6_Pos                       12          /*!< Pin G6 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN7_Pos                       14          /*!< Pin G7 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN8_Pos                       16          /*!< Pin G8 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN9_Pos                       18          /*!< Pin G9 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN10_Pos                      20          /*!< Pin G10 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN11_Pos                      22          /*!< Pin G11 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN12_Pos                      24          /*!< Pin G12 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN13_Pos                      26          /*!< Pin G13 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN14_Pos                      28          /*!< Pin G14 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN15_Pos                      30          /*!< Pin G15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLG_PIN0_Msk                       0x00000003  /*!< Pin G0 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN1_Msk                       0x0000000C  /*!< Pin G1 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN2_Msk                       0x00000030  /*!< Pin G2 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN3_Msk                       0x000000C0  /*!< Pin G3 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN4_Msk                       0x00000300  /*!< Pin G4 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN5_Msk                       0x00000C00  /*!< Pin G5 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN6_Msk                       0x00003000  /*!< Pin G6 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN7_Msk                       0x0000C000  /*!< Pin G7 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN8_Msk                       0x00030000  /*!< Pin G8 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN9_Msk                       0x000C0000  /*!< Pin G9 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN10_Msk                      0x00300000  /*!< Pin G10 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN11_Msk                      0x00C00000  /*!< Pin G11 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN12_Msk                      0x03000000  /*!< Pin G12 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN13_Msk                      0x0C000000  /*!< Pin G13 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN14_Msk                      0x30000000  /*!< Pin G14 alternative function selection */
#define COMMON_REG_GPIOPCTLG_PIN15_Msk                      0xC0000000  /*!< Pin G15 alternative function selection */

/*-- GPIOPCTLH: Port H alternative function selection register ----------------------------*/

typedef struct {
  uint32_t PIN0                                   :2;                   /*!< Pin H0 alternative function selection */
  uint32_t PIN1                                   :2;                   /*!< Pin H1 alternative function selection */
  uint32_t PIN2                                   :2;                   /*!< Pin H2 alternative function selection */
  uint32_t PIN3                                   :2;                   /*!< Pin H3 alternative function selection */
  uint32_t PIN4                                   :2;                   /*!< Pin H4 alternative function selection */
  uint32_t PIN5                                   :2;                   /*!< Pin H5 alternative function selection */
  uint32_t PIN6                                   :2;                   /*!< Pin H6 alternative function selection */
  uint32_t PIN7                                   :2;                   /*!< Pin H7 alternative function selection */
  uint32_t PIN8                                   :2;                   /*!< Pin H8 alternative function selection */
  uint32_t PIN9                                   :2;                   /*!< Pin H9 alternative function selection */
  uint32_t PIN10                                  :2;                   /*!< Pin H10 alternative function selection */
  uint32_t PIN11                                  :2;                   /*!< Pin H11 alternative function selection */
  uint32_t PIN12                                  :2;                   /*!< Pin H12 alternative function selection */
  uint32_t PIN13                                  :2;                   /*!< Pin H13 alternative function selection */
  uint32_t PIN14                                  :2;                   /*!< Pin H14 alternative function selection */
  uint32_t PIN15                                  :2;                   /*!< Pin H15 alternative function selection */
} _COMMON_REG_GPIOPCTLH_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPCTLH_PIN0_Pos                       0           /*!< Pin H0 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN1_Pos                       2           /*!< Pin H1 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN2_Pos                       4           /*!< Pin H2 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN3_Pos                       6           /*!< Pin H3 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN4_Pos                       8           /*!< Pin H4 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN5_Pos                       10          /*!< Pin H5 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN6_Pos                       12          /*!< Pin H6 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN7_Pos                       14          /*!< Pin H7 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN8_Pos                       16          /*!< Pin H8 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN9_Pos                       18          /*!< Pin H9 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN10_Pos                      20          /*!< Pin H10 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN11_Pos                      22          /*!< Pin H11 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN12_Pos                      24          /*!< Pin H12 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN13_Pos                      26          /*!< Pin H13 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN14_Pos                      28          /*!< Pin H14 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN15_Pos                      30          /*!< Pin H15 alternative function selection */

/* Bit field masks: */
#define COMMON_REG_GPIOPCTLH_PIN0_Msk                       0x00000003  /*!< Pin H0 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN1_Msk                       0x0000000C  /*!< Pin H1 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN2_Msk                       0x00000030  /*!< Pin H2 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN3_Msk                       0x000000C0  /*!< Pin H3 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN4_Msk                       0x00000300  /*!< Pin H4 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN5_Msk                       0x00000C00  /*!< Pin H5 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN6_Msk                       0x00003000  /*!< Pin H6 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN7_Msk                       0x0000C000  /*!< Pin H7 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN8_Msk                       0x00030000  /*!< Pin H8 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN9_Msk                       0x000C0000  /*!< Pin H9 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN10_Msk                      0x00300000  /*!< Pin H10 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN11_Msk                      0x00C00000  /*!< Pin H11 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN12_Msk                      0x03000000  /*!< Pin H12 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN13_Msk                      0x0C000000  /*!< Pin H13 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN14_Msk                      0x30000000  /*!< Pin H14 alternative function selection */
#define COMMON_REG_GPIOPCTLH_PIN15_Msk                      0xC0000000  /*!< Pin H15 alternative function selection */

/*-- GPIOODCTL0: Port A,B open-drain enable register ---------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Port A open-drain enable */
  uint32_t PORTB                                  :16;                  /*!< Port B open-drain enable */
} _COMMON_REG_GPIOODCTL0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOODCTL0_PORTA_Pos                     0           /*!< Port A open-drain enable */
#define COMMON_REG_GPIOODCTL0_PORTB_Pos                     16          /*!< Port B open-drain enable */

/* Bit field masks: */
#define COMMON_REG_GPIOODCTL0_PORTA_Msk                     0x0000FFFF  /*!< Port A open-drain enable */
#define COMMON_REG_GPIOODCTL0_PORTB_Msk                     0xFFFF0000  /*!< Port B open-drain enable */

/*-- GPIOODCTL1: Port C,D open-drain enable register ---------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Port C open-drain enable */
  uint32_t PORTD                                  :16;                  /*!< Port D open-drain enable */
} _COMMON_REG_GPIOODCTL1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOODCTL1_PORTC_Pos                     0           /*!< Port C open-drain enable */
#define COMMON_REG_GPIOODCTL1_PORTD_Pos                     16          /*!< Port D open-drain enable */

/* Bit field masks: */
#define COMMON_REG_GPIOODCTL1_PORTC_Msk                     0x0000FFFF  /*!< Port C open-drain enable */
#define COMMON_REG_GPIOODCTL1_PORTD_Msk                     0xFFFF0000  /*!< Port D open-drain enable */

/*-- GPIOODCTL2: Port E,F open-drain enable register ---------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Port E open-drain enable */
  uint32_t PORTF                                  :16;                  /*!< Port F open-drain enable */
} _COMMON_REG_GPIOODCTL2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOODCTL2_PORTE_Pos                     0           /*!< Port E open-drain enable */
#define COMMON_REG_GPIOODCTL2_PORTF_Pos                     16          /*!< Port F open-drain enable */

/* Bit field masks: */
#define COMMON_REG_GPIOODCTL2_PORTE_Msk                     0x0000FFFF  /*!< Port E open-drain enable */
#define COMMON_REG_GPIOODCTL2_PORTF_Msk                     0xFFFF0000  /*!< Port F open-drain enable */

/*-- GPIOODCTL3: Port G,H open-drain enable register ---------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Port G open-drain enable */
  uint32_t PORTH                                  :16;                  /*!< Port H open-drain enable */
} _COMMON_REG_GPIOODCTL3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOODCTL3_PORTG_Pos                     0           /*!< Port G open-drain enable */
#define COMMON_REG_GPIOODCTL3_PORTH_Pos                     16          /*!< Port H open-drain enable */

/* Bit field masks: */
#define COMMON_REG_GPIOODCTL3_PORTG_Msk                     0x0000FFFF  /*!< Port G open-drain enable */
#define COMMON_REG_GPIOODCTL3_PORTH_Msk                     0xFFFF0000  /*!< Port H open-drain enable */

/*-- GPIODSCTL0: Port A,B strength control register ---------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Port A strength control */
  uint32_t PORTB                                  :16;                  /*!< Port B strength control */
} _COMMON_REG_GPIODSCTL0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODSCTL0_PORTA_Pos                    0           /*!< Port A strength control */
#define COMMON_REG_GPIODSCTL0_PORTB_Pos                    16          /*!< Port B strength control */

/* Bit field masks: */
#define COMMON_REG_GPIODSCTL0_PORTA_Msk                    0x0000FFFF  /*!< Port A strength control */
#define COMMON_REG_GPIODSCTL0_PORTB_Msk                    0xFFFF0000  /*!< Port B strength control */

/*-- GPIODSCTL1: Port C,D strength control register ---------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Port C strength control */
  uint32_t PORTD                                  :16;                  /*!< Port D strength control */
} _COMMON_REG_GPIODSCTL1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODSCTL1_PORTC_Pos                    0           /*!< Port C strength control */
#define COMMON_REG_GPIODSCTL1_PORTD_Pos                    16          /*!< Port D strength control */

/* Bit field masks: */
#define COMMON_REG_GPIODSCTL1_PORTC_Msk                    0x0000FFFF  /*!< Port C strength control */
#define COMMON_REG_GPIODSCTL1_PORTD_Msk                    0xFFFF0000  /*!< Port D strength control */

/*-- GPIODSCTL2: Port E,F strength control register ---------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Port E strength control */
  uint32_t PORTF                                  :16;                  /*!< Port F strength control */
} _COMMON_REG_GPIODSCTL2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODSCTL2_PORTE_Pos                    0           /*!< Port E strength control */
#define COMMON_REG_GPIODSCTL2_PORTF_Pos                    16          /*!< Port F strength control */

/* Bit field masks: */
#define COMMON_REG_GPIODSCTL2_PORTE_Msk                    0x0000FFFF  /*!< Port E strength control */
#define COMMON_REG_GPIODSCTL2_PORTF_Msk                    0xFFFF0000  /*!< Port F strength control */

/*-- GPIODSCTL3: Port G,H strength control register ---------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Port G strength control */
  uint32_t PORTH                                  :16;                  /*!< Port H strength control */
} _COMMON_REG_GPIODSCTL3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIODSCTL3_PORTG_Pos                    0           /*!< Port G strength control */
#define COMMON_REG_GPIODSCTL3_PORTH_Pos                    16          /*!< Port H strength control */

/* Bit field masks: */
#define COMMON_REG_GPIODSCTL3_PORTG_Msk                    0x0000FFFF  /*!< Port G strength control */
#define COMMON_REG_GPIODSCTL3_PORTH_Msk                    0xFFFF0000  /*!< Port H strength control */

/*-- GPIOPUCTL0: Port A,B pull-up enable register ---------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Port A pull-up enable */
  uint32_t PORTB                                  :16;                  /*!< Port B pull-up enable */
} _COMMON_REG_GPIOPUCTL0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPUCTL0_PORTA_Pos                     0           /*!< Port A pull-up enable */
#define COMMON_REG_GPIOPUCTL0_PORTB_Pos                     16          /*!< Port B pull-up enable */

/* Bit field masks: */
#define COMMON_REG_GPIOPUCTL0_PORTA_Msk                     0x0000FFFF  /*!< Port A pull-up enable */
#define COMMON_REG_GPIOPUCTL0_PORTB_Msk                     0xFFFF0000  /*!< Port B pull-up enable */

/*-- GPIOPUCTL1: Port C,D pull-up enable register ---------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Port C pull-up enable */
  uint32_t PORTD                                  :16;                  /*!< Port D pull-up enable */
} _COMMON_REG_GPIOPUCTL1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPUCTL1_PORTC_Pos                     0           /*!< Port C pull-up enable */
#define COMMON_REG_GPIOPUCTL1_PORTD_Pos                     16          /*!< Port D pull-up enable */

/* Bit field masks: */
#define COMMON_REG_GPIOPUCTL1_PORTC_Msk                     0x0000FFFF  /*!< Port C pull-up enable */
#define COMMON_REG_GPIOPUCTL1_PORTD_Msk                     0xFFFF0000  /*!< Port D pull-up enable */

/*-- GPIOPUCTL2: Port E,F pull-up enable register ---------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Port E pull-up enable */
  uint32_t PORTF                                  :16;                  /*!< Port F pull-up enable */
} _COMMON_REG_GPIOPUCTL2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPUCTL2_PORTE_Pos                     0           /*!< Port E pull-up enable */
#define COMMON_REG_GPIOPUCTL2_PORTF_Pos                     16          /*!< Port F pull-up enable */

/* Bit field masks: */
#define COMMON_REG_GPIOPUCTL2_PORTE_Msk                     0x0000FFFF  /*!< Port E pull-up enable */
#define COMMON_REG_GPIOPUCTL2_PORTF_Msk                     0xFFFF0000  /*!< Port F pull-up enable */

/*-- GPIOPUCTL3: Port G,H pull-up enable register ---------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Port G pull-up enable */
  uint32_t PORTH                                  :16;                  /*!< Port H pull-up enable */
} _COMMON_REG_GPIOPUCTL3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOPUCTL3_PORTG_Pos                     0           /*!< Port G pull-up enable */
#define COMMON_REG_GPIOPUCTL3_PORTH_Pos                     16          /*!< Port H pull-up enable */

/* Bit field masks: */
#define COMMON_REG_GPIOPUCTL3_PORTG_Msk                     0x0000FFFF  /*!< Port G pull-up enable */
#define COMMON_REG_GPIOPUCTL3_PORTH_Msk                     0xFFFF0000  /*!< Port H pull-up enable */

/*-- PLL_CTRL: PLL control register ---------------------------------*/

typedef struct {
  uint32_t REFSEL                                 :2;                   /*!< PLL reference clk selection */
  uint32_t Reserved0                              :6;                   /*!< Reserved */
  uint32_t PLL_DIV                                :8;                   /*!< External divider for PLL output */
  uint32_t Reserved1                              :15;                  /*!< Reserved */
  uint32_t PD                                     :1;                   /*!< PLL PowerDown mode enable */
} _COMMON_REG_PLL_CTRL_bits;

/* Bit field positions: */
#define COMMON_REG_PLL_CTRL_REFSEL_Pos                      0           /*!< PLL reference clk selection */
#define COMMON_REG_PLL_CTRL_PLL_DIV_Pos                     8           /*!< External divider for PLL output */
#define COMMON_REG_PLL_CTRL_PD_Pos                          31          /*!< PLL PowerDown mode enable */

/* Bit field masks: */
#define COMMON_REG_PLL_CTRL_REFSEL_Msk                      0x00000003  /*!< PLL reference clk selection */
#define COMMON_REG_PLL_CTRL_PLL_DIV_Msk                     0x0000FF00  /*!< External divider for PLL output */
#define COMMON_REG_PLL_CTRL_PD_Msk                          0x80000000  /*!< PLL PowerDown mode enable */

/*-- PLL_OD: PLL output divider register ---------------------------------------*/

typedef struct {
  uint32_t PLL_OD                                 :2;                   /*!< PLL output divider "NO" control */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _COMMON_REG_PLL_OD_bits;

/* Bit field positions: */
#define COMMON_REG_PLL_OD_PLL_OD_Pos                        0           /*!< PLL output divider "NO" control */

/* Bit field masks: */
#define COMMON_REG_PLL_OD_PLL_OD_Msk                        0x00000003  /*!< PLL output divider "NO" control */

/*-- PLL_NR: PLL reference divider register -------------------------------*/

typedef struct {
  uint32_t R_PLL                                  :5;                   /*!< PLL reference divider "NR = R_PLL+2" */
  uint32_t Reserved0                              :27;                  /*!< Reserved */
} _COMMON_REG_PLL_NR_bits;

/* Bit field positions: */
#define COMMON_REG_PLL_NR_R_PLL_Pos                         0           /*!< PLL reference divider "NR = R_PLL+2" */

/* Bit field masks: */
#define COMMON_REG_PLL_NR_R_PLL_Msk                         0x0000001F  /*!< PLL reference divider "NR = R_PLL+2" */

/*-- PLL_NF: PLL feedback divider register --------------------------------*/

typedef struct {
  uint32_t F_PLL                                  :9;                   /*!< PLL feedback divider "NF = F_PLL+2" */
  uint32_t Reserved0                              :23;                  /*!< Reserved */
} _COMMON_REG_PLL_NF_bits;

/* Bit field positions: */
#define COMMON_REG_PLL_NF_F_PLL_Pos                         0           /*!< PLL feedback divider "NF = F_PLL+2" */

/* Bit field masks: */
#define COMMON_REG_PLL_NF_F_PLL_Msk                         0x000001FF  /*!< PLL feedback divider "NF = F_PLL+2" */

/*-- EXT_MEM_CFG: External memory configuration register -------------------*/

typedef struct {
  uint32_t ReadWS                                 :3;                   /*!< Read wait state cycles value */
  uint32_t WriteWS                                :3;                   /*!< Write wait state cycles value */
  uint32_t RWWS                                   :3;                   /*!< Pause wait state cycles value */
  uint32_t CE_MASK                                :9;                   /*!< CE1, OE1 address mask */
  uint32_t Reserved0                              :13;                  /*!< Reserved */
  uint32_t BW                                     :1;                   /*!< External memory bus width (8/16bit) */
} _COMMON_REG_EXT_MEM_CFG_bits;

/* Bit field positions: */
#define COMMON_REG_EXT_MEM_CFG_ReadWS_Pos                   0           /*!< Read wait state cycles value */
#define COMMON_REG_EXT_MEM_CFG_WriteWS_Pos                  3           /*!< Write wait state cycles value */
#define COMMON_REG_EXT_MEM_CFG_RWWS_Pos                     6           /*!< Pause wait state cycles value */
#define COMMON_REG_EXT_MEM_CFG_CE_MASK_Pos                  9           /*!< CE1, OE1 address mask */
#define COMMON_REG_EXT_MEM_CFG_BW_Pos                       31          /*!< External memory bus width (8/16bit) */

/* Bit field masks: */
#define COMMON_REG_EXT_MEM_CFG_ReadWS_Msk                   0x00000007  /*!< Read wait state cycles value */
#define COMMON_REG_EXT_MEM_CFG_WriteWS_Msk                  0x00000038  /*!< Write wait state cycles value */
#define COMMON_REG_EXT_MEM_CFG_RWWS_Msk                     0x000001C0  /*!< Pause wait state cycles value */
#define COMMON_REG_EXT_MEM_CFG_CE_MASK_Msk                  0x0003FE00  /*!< CE1, OE1 address mask */
#define COMMON_REG_EXT_MEM_CFG_BW_Msk                       0x80000000  /*!< External memory bus width (8/16bit) */

/*-- ADC_CTRL0: ADC 0-3 clock control register ---------------------------------------*/

typedef struct {
  uint32_t CLKEN_ADC0                             :1;                   /*!< ADC0 clk enable */
  uint32_t DIVEN_ADC0                             :1;                   /*!< ADC0 clk divider enable */
  uint32_t DIV_ADC0                               :6;                   /*!< ADC0 clk divider value */
  uint32_t CLKEN_ADC1                             :1;                   /*!< ADC1 clk enable */
  uint32_t DIVEN_ADC1                             :1;                   /*!< ADC1 clk divider enable */
  uint32_t DIV_ADC1                               :6;                   /*!< ADC1 clk divider value */
  uint32_t CLKEN_ADC2                             :1;                   /*!< ADC2 clk enable */
  uint32_t DIVEN_ADC2                             :1;                   /*!< ADC2 clk divider enable */
  uint32_t DIV_ADC2                               :6;                   /*!< ADC2 clk divider value */
  uint32_t CLKEN_ADC3                             :1;                   /*!< ADC3 clk enable */
  uint32_t DIVEN_ADC3                             :1;                   /*!< ADC3 clk divider enable */
  uint32_t DIV_ADC3                               :6;                   /*!< ADC3 clk divider value */
} _COMMON_REG_ADC_CTRL0_bits;

/* Bit field positions: */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC0_Pos                 0           /*!< ADC0 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC0_Pos                 1           /*!< ADC0 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC0_Pos                   2           /*!< ADC0 clk divider value */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC1_Pos                 8           /*!< ADC1 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC1_Pos                 9           /*!< ADC1 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC1_Pos                   10          /*!< ADC1 clk divider value */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC2_Pos                 16          /*!< ADC2 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC2_Pos                 17          /*!< ADC2 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC2_Pos                   18          /*!< ADC2 clk divider value */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC3_Pos                 24          /*!< ADC3 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC3_Pos                 25          /*!< ADC3 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC3_Pos                   26          /*!< ADC3 clk divider value */

/* Bit field masks: */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC0_Msk                 0x00000001  /*!< ADC0 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC0_Msk                 0x00000002  /*!< ADC0 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC0_Msk                   0x000000FC  /*!< ADC0 clk divider value */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC1_Msk                 0x00000100  /*!< ADC1 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC1_Msk                 0x00000200  /*!< ADC1 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC1_Msk                   0x0000FC00  /*!< ADC1 clk divider value */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC2_Msk                 0x00010000  /*!< ADC2 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC2_Msk                 0x00020000  /*!< ADC2 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC2_Msk                   0x00FC0000  /*!< ADC2 clk divider value */
#define COMMON_REG_ADC_CTRL0_CLKEN_ADC3_Msk                 0x01000000  /*!< ADC3 clk enable */
#define COMMON_REG_ADC_CTRL0_DIVEN_ADC3_Msk                 0x02000000  /*!< ADC3 clk divider enable */
#define COMMON_REG_ADC_CTRL0_DIV_ADC3_Msk                   0xFC000000  /*!< ADC3 clk divider value */

/*-- ADC_CTRL1: ADC 4-7 clock control register ---------------------------------------*/

typedef struct {
  uint32_t CLKEN_ADC4                             :1;                   /*!< ADC4 clk enable */
  uint32_t DIVEN_ADC4                             :1;                   /*!< ADC4 clk divider enable */
  uint32_t DIV_ADC4                               :6;                   /*!< ADC4 clk divider value */
  uint32_t CLKEN_ADC5                             :1;                   /*!< ADC5 clk enable */
  uint32_t DIVEN_ADC5                             :1;                   /*!< ADC5 clk divider enable */
  uint32_t DIV_ADC5                               :6;                   /*!< ADC5 clk divider value */
  uint32_t CLKEN_ADC6                             :1;                   /*!< ADC6 clk enable */
  uint32_t DIVEN_ADC6                             :1;                   /*!< ADC6 clk divider enable */
  uint32_t DIV_ADC6                               :6;                   /*!< ADC6 clk divider value */
  uint32_t CLKEN_ADC7                             :1;                   /*!< ADC7 clk enable */
  uint32_t DIVEN_ADC7                             :1;                   /*!< ADC7 clk divider enable */
  uint32_t DIV_ADC7                               :6;                   /*!< ADC7 clk divider value */
} _COMMON_REG_ADC_CTRL1_bits;

/* Bit field positions: */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC4_Pos                 0           /*!< ADC4 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC4_Pos                 1           /*!< ADC4 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC4_Pos                   2           /*!< ADC4 clk divider value */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC5_Pos                 8           /*!< ADC5 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC5_Pos                 9           /*!< ADC5 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC5_Pos                   10          /*!< ADC5 clk divider value */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC6_Pos                 16          /*!< ADC6 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC6_Pos                 17          /*!< ADC6 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC6_Pos                   18          /*!< ADC6 clk divider value */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC7_Pos                 24          /*!< ADC7 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC7_Pos                 25          /*!< ADC7 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC7_Pos                   26          /*!< ADC7 clk divider value */

/* Bit field masks: */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC4_Msk                 0x00000001  /*!< ADC4 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC4_Msk                 0x00000002  /*!< ADC4 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC4_Msk                   0x000000FC  /*!< ADC4 clk divider value */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC5_Msk                 0x00000100  /*!< ADC5 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC5_Msk                 0x00000200  /*!< ADC5 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC5_Msk                   0x0000FC00  /*!< ADC5 clk divider value */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC6_Msk                 0x00010000  /*!< ADC6 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC6_Msk                 0x00020000  /*!< ADC6 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC6_Msk                   0x00FC0000  /*!< ADC6 clk divider value */
#define COMMON_REG_ADC_CTRL1_CLKEN_ADC7_Msk                 0x01000000  /*!< ADC7 clk enable */
#define COMMON_REG_ADC_CTRL1_DIVEN_ADC7_Msk                 0x02000000  /*!< ADC7 clk divider enable */
#define COMMON_REG_ADC_CTRL1_DIV_ADC7_Msk                   0xFC000000  /*!< ADC7 clk divider value */

/*-- PWM_SYNC: PWM prescalers sync register --------------------------------*/

typedef struct {
  uint32_t TBCLKSYNC                              :9;                   /*!< PWM prescalers enable */
  uint32_t Reserved0                              :23;                  /*!< Reserved */
} _COMMON_REG_PWM_SYNC_bits;

/* Bit field positions: */
#define COMMON_REG_PWM_SYNC_TBCLKSYNC_Pos                   0           /*!< PWM prescalers enable */

/* Bit field masks: */
#define COMMON_REG_PWM_SYNC_TBCLKSYNC_Msk                   0x000001FF  /*!< PWM prescalers enable */

/*-- PWM_CTRL: PWM sync control register -------------*/

typedef struct {
  uint32_t SYNCSELECT                             :2;                   /*!< PWM sync mode selection */
  uint32_t CAPSYNCSEL                             :1;                   /*!< CAP3 sync mode selection (from CAP2 or PWM0) */
  uint32_t SYNCREG                                :1;                   /*!< SYNCI pulse generation on PWM0 input */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _COMMON_REG_PWM_CTRL_bits;

/* Bit field positions: */
#define COMMON_REG_PWM_CTRL_SYNCSELECT_Pos                  0           /*!< PWM sync mode selection */
#define COMMON_REG_PWM_CTRL_CAPSYNCSEL_Pos                  2           /*!< CAP3 sync mode selection (from CAP2 or PWM0) */
#define COMMON_REG_PWM_CTRL_SYNCREG_Pos                     3           /*!< SYNCI pulse generation on PWM0 input */

/* Bit field masks: */
#define COMMON_REG_PWM_CTRL_SYNCSELECT_Msk                  0x00000003  /*!< PWM sync mode selection */
#define COMMON_REG_PWM_CTRL_CAPSYNCSEL_Msk                  0x00000004  /*!< CAP3 sync mode selection (from CAP2 or PWM0) */
#define COMMON_REG_PWM_CTRL_SYNCREG_Msk                     0x00000008  /*!< SYNCI pulse generation on PWM0 input */

/*-- SYS_CLK: System clock control register ----------------------------*/

typedef struct {
  uint32_t SEL_SRC                                :3;                   /*!< System clk source selection */
  uint32_t Reserved0                              :5;                   /*!< Reserved */
  uint32_t CURR_SRC                               :3;                   /*!< Current system clk source */
  uint32_t Reserved1                              :21;                  /*!< Reserved */
} _COMMON_REG_SYS_CLK_bits;

/* Bit field positions: */
#define COMMON_REG_SYS_CLK_SEL_SRC_Pos                      0           /*!< System clk source selection */
#define COMMON_REG_SYS_CLK_CURR_SRC_Pos                     8           /*!< Current system clk source */

/* Bit field masks: */
#define COMMON_REG_SYS_CLK_SEL_SRC_Msk                      0x00000007  /*!< System clk source selection */
#define COMMON_REG_SYS_CLK_CURR_SRC_Msk                     0x00000700  /*!< Current system clk source */

/*-- APB_CLK: Peripheral clock control register -----------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t QEPEN0                                 :1;                   /*!< QEP0 clk enable */
  uint32_t QEPEN1                                 :1;                   /*!< QEP1 clk enable */
  uint32_t Reserved1                              :6;                   /*!< Reserved */
  uint32_t CMPEN                                  :1;                   /*!< Analog comparator clk enable */
  uint32_t PWMEN0                                 :1;                   /*!< PWM0 clk enable */
  uint32_t PWMEN1                                 :1;                   /*!< PWM1 clk enable */
  uint32_t PWMEN2                                 :1;                   /*!< PWM2 clk enable */
  uint32_t PWMEN3                                 :1;                   /*!< PWM3 clk enable */
  uint32_t PWMEN4                                 :1;                   /*!< PWM4 clk enable */
  uint32_t PWMEN5                                 :1;                   /*!< PWM5 clk enable */
  uint32_t PWMEN6                                 :1;                   /*!< PWM6 clk enable */
  uint32_t PWMEN7                                 :1;                   /*!< PWM7 clk enable */
  uint32_t PWMEN8                                 :1;                   /*!< PWM8 clk enable */
  uint32_t WDEN                                   :1;                   /*!< WDT clk enable */
  uint32_t I2CEN0                                 :1;                   /*!< I2C0 clk enable */
  uint32_t I2CEN1                                 :1;                   /*!< I2C1 clk enable */
  uint32_t Reserved2                              :2;                   /*!< Reserved */
  uint32_t ADCEN                                  :1;                   /*!< ADC clk enable */
  uint32_t Reserved3                              :7;                   /*!< Reserved */
} _COMMON_REG_APB_CLK_bits;

/* Bit field positions: */
#define COMMON_REG_APB_CLK_QEPEN0_Pos                       1           /*!< QEP0 clk enable */
#define COMMON_REG_APB_CLK_QEPEN1_Pos                       2           /*!< QEP1 clk enable */
#define COMMON_REG_APB_CLK_CMPEN_Pos                        9           /*!< Analog comparator clk enable */
#define COMMON_REG_APB_CLK_PWMEN0_Pos                       10          /*!< PWM0 clk enable */
#define COMMON_REG_APB_CLK_PWMEN1_Pos                       11          /*!< PWM1 clk enable */
#define COMMON_REG_APB_CLK_PWMEN2_Pos                       12          /*!< PWM2 clk enable */
#define COMMON_REG_APB_CLK_PWMEN3_Pos                       13          /*!< PWM3 clk enable */
#define COMMON_REG_APB_CLK_PWMEN4_Pos                       14          /*!< PWM4 clk enable */
#define COMMON_REG_APB_CLK_PWMEN5_Pos                       15          /*!< PWM5 clk enable */
#define COMMON_REG_APB_CLK_PWMEN6_Pos                       16          /*!< PWM6 clk enable */
#define COMMON_REG_APB_CLK_PWMEN7_Pos                       17          /*!< PWM7 clk enable */
#define COMMON_REG_APB_CLK_PWMEN8_Pos                       18          /*!< PWM8 clk enable */
#define COMMON_REG_APB_CLK_WDEN_Pos                         19          /*!< WDT clk enable */
#define COMMON_REG_APB_CLK_I2CEN0_Pos                       20          /*!< I2C0 clk enable */
#define COMMON_REG_APB_CLK_I2CEN1_Pos                       21          /*!< I2C1 clk enable */
#define COMMON_REG_APB_CLK_ADCEN_Pos                        24          /*!< ADC clk enable */

/* Bit field masks: */
#define COMMON_REG_APB_CLK_QEPEN0_Msk                       0x00000002  /*!< QEP0 clk enable */
#define COMMON_REG_APB_CLK_QEPEN1_Msk                       0x00000004  /*!< QEP1 clk enable */
#define COMMON_REG_APB_CLK_CMPEN_Msk                        0x00000200  /*!< Analog comparator clk enable */
#define COMMON_REG_APB_CLK_PWMEN0_Msk                       0x00000400  /*!< PWM0 clk enable */
#define COMMON_REG_APB_CLK_PWMEN1_Msk                       0x00000800  /*!< PWM1 clk enable */
#define COMMON_REG_APB_CLK_PWMEN2_Msk                       0x00001000  /*!< PWM2 clk enable */
#define COMMON_REG_APB_CLK_PWMEN3_Msk                       0x00002000  /*!< PWM3 clk enable */
#define COMMON_REG_APB_CLK_PWMEN4_Msk                       0x00004000  /*!< PWM4 clk enable */
#define COMMON_REG_APB_CLK_PWMEN5_Msk                       0x00008000  /*!< PWM5 clk enable */
#define COMMON_REG_APB_CLK_PWMEN6_Msk                       0x00010000  /*!< PWM6 clk enable */
#define COMMON_REG_APB_CLK_PWMEN7_Msk                       0x00020000  /*!< PWM7 clk enable */
#define COMMON_REG_APB_CLK_PWMEN8_Msk                       0x00040000  /*!< PWM8 clk enable */
#define COMMON_REG_APB_CLK_WDEN_Msk                         0x00080000  /*!< WDT clk enable */
#define COMMON_REG_APB_CLK_I2CEN0_Msk                       0x00100000  /*!< I2C0 clk enable */
#define COMMON_REG_APB_CLK_I2CEN1_Msk                       0x00200000  /*!< I2C1 clk enable */
#define COMMON_REG_APB_CLK_ADCEN_Msk                        0x01000000  /*!< ADC clk enable */

/*-- UART_CLK: UART clock control register ---------------------------------*/

typedef struct {
  uint32_t CLKEN_UART0                            :1;                   /*!< UART0 clk enable */
  uint32_t DIVEN_UART0                            :1;                   /*!< UART0 clk divider enable */
  uint32_t DIV_UART0                              :6;                   /*!< UART0 clk divider value */
  uint32_t CLKEN_UART1                            :1;                   /*!< UART1 clk enable */
  uint32_t DIVEN_UART1                            :1;                   /*!< UART1 clk divider enable */
  uint32_t DIV_UART1                              :6;                   /*!< UART1 clk divider value */
  uint32_t CLKEN_UART2                            :1;                   /*!< UART2 clk enable */
  uint32_t DIVEN_UART2                            :1;                   /*!< UART2 clk divider enable */
  uint32_t DIV_UART2                              :6;                   /*!< UART2 clk divider value */
  uint32_t CLKEN_UART3                            :1;                   /*!< UART3 clk enable */
  uint32_t DIVEN_UART3                            :1;                   /*!< UART3 clk divider enable */
  uint32_t DIV_UART3                              :6;                   /*!< UART3 clk divider value */
} _COMMON_REG_UART_CLK_bits;

/* Bit field positions: */
#define COMMON_REG_UART_CLK_CLKEN_UART0_Pos                 0           /*!< UART0 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART0_Pos                 1           /*!< UART0 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART0_Pos                   2           /*!< UART0 clk divider value */
#define COMMON_REG_UART_CLK_CLKEN_UART1_Pos                 8           /*!< UART1 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART1_Pos                 9           /*!< UART1 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART1_Pos                   10          /*!< UART1 clk divider value */
#define COMMON_REG_UART_CLK_CLKEN_UART2_Pos                 16          /*!< UART2 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART2_Pos                 17          /*!< UART2 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART2_Pos                   18          /*!< UART2 clk divider value */
#define COMMON_REG_UART_CLK_CLKEN_UART3_Pos                 24          /*!< UART3 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART3_Pos                 25          /*!< UART3 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART3_Pos                   26          /*!< UART3 clk divider value */

/* Bit field masks: */
#define COMMON_REG_UART_CLK_CLKEN_UART0_Msk                 0x00000001  /*!< UART0 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART0_Msk                 0x00000002  /*!< UART0 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART0_Msk                   0x000000FC  /*!< UART0 clk divider value */
#define COMMON_REG_UART_CLK_CLKEN_UART1_Msk                 0x00000100  /*!< UART1 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART1_Msk                 0x00000200  /*!< UART1 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART1_Msk                   0x0000FC00  /*!< UART1 clk divider value */
#define COMMON_REG_UART_CLK_CLKEN_UART2_Msk                 0x00010000  /*!< UART2 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART2_Msk                 0x00020000  /*!< UART2 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART2_Msk                   0x00FC0000  /*!< UART2 clk divider value */
#define COMMON_REG_UART_CLK_CLKEN_UART3_Msk                 0x01000000  /*!< UART3 clk enable */
#define COMMON_REG_UART_CLK_DIVEN_UART3_Msk                 0x02000000  /*!< UART3 clk divider enable */
#define COMMON_REG_UART_CLK_DIV_UART3_Msk                   0xFC000000  /*!< UART3 clk divider value */

/*-- SPI_CLK: SPI clock control register -----------------------------------*/

typedef struct {
  uint32_t CLKEN_SPI0                             :1;                   /*!< SPI0 clk enable */
  uint32_t DIVEN_SPI0                             :1;                   /*!< SPI0 clk divider enable */
  uint32_t DIV_SPI0                               :6;                   /*!< SPI0 clk divider value */
  uint32_t CLKEN_SPI1                             :1;                   /*!< SPI1 clk enable */
  uint32_t DIVEN_SPI1                             :1;                   /*!< SPI1 clk divider enable */
  uint32_t DIV_SPI1                               :6;                   /*!< SPI1 clk divider value */
  uint32_t CLKEN_SPI2                             :1;                   /*!< SPI2 clk enable */
  uint32_t DIVEN_SPI2                             :1;                   /*!< SPI2 clk divider enable */
  uint32_t DIV_SPI2                               :6;                   /*!< SPI2 clk divider value */
  uint32_t CLKEN_SPI3                             :1;                   /*!< SPI3 clk enable */
  uint32_t DIVEN_SPI3                             :1;                   /*!< SPI3 clk divider enable */
  uint32_t DIV_SPI3                               :6;                   /*!< SPI3 clk divider value */
} _COMMON_REG_SPI_CLK_bits;

/* Bit field positions: */
#define COMMON_REG_SPI_CLK_CLKEN_SPI0_Pos                   0           /*!< SPI0 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI0_Pos                   1           /*!< SPI0 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI0_Pos                     2           /*!< SPI0 clk divider value */
#define COMMON_REG_SPI_CLK_CLKEN_SPI1_Pos                   8           /*!< SPI1 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI1_Pos                   9           /*!< SPI1 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI1_Pos                     10          /*!< SPI1 clk divider value */
#define COMMON_REG_SPI_CLK_CLKEN_SPI2_Pos                   16          /*!< SPI2 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI2_Pos                   17          /*!< SPI2 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI2_Pos                     18          /*!< SPI2 clk divider value */
#define COMMON_REG_SPI_CLK_CLKEN_SPI3_Pos                   24          /*!< SPI3 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI3_Pos                   25          /*!< SPI3 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI3_Pos                     26          /*!< SPI3 clk divider value */

/* Bit field masks: */
#define COMMON_REG_SPI_CLK_CLKEN_SPI0_Msk                   0x00000001  /*!< SPI0 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI0_Msk                   0x00000002  /*!< SPI0 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI0_Msk                     0x000000FC  /*!< SPI0 clk divider value */
#define COMMON_REG_SPI_CLK_CLKEN_SPI1_Msk                   0x00000100  /*!< SPI1 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI1_Msk                   0x00000200  /*!< SPI1 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI1_Msk                     0x0000FC00  /*!< SPI1 clk divider value */
#define COMMON_REG_SPI_CLK_CLKEN_SPI2_Msk                   0x00010000  /*!< SPI2 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI2_Msk                   0x00020000  /*!< SPI2 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI2_Msk                     0x00FC0000  /*!< SPI2 clk divider value */
#define COMMON_REG_SPI_CLK_CLKEN_SPI3_Msk                   0x01000000  /*!< SPI3 clk enable */
#define COMMON_REG_SPI_CLK_DIVEN_SPI3_Msk                   0x02000000  /*!< SPI3 clk divider enable */
#define COMMON_REG_SPI_CLK_DIV_SPI3_Msk                     0xFC000000  /*!< SPI3 clk divider value */

/*-- PER_RST0: Peripheral reset register 0 -----------------------------------*/

typedef struct {
  uint32_t WDRST                                  :1;                   /*!< Reset WatchDog */
  uint32_t I2CRST0                                :1;                   /*!< Reset I2C0 */
  uint32_t I2CRST1                                :1;                   /*!< Reset I2C1 */
  uint32_t USBPHYRST                              :1;                   /*!< Reset USB_PHY */
  uint32_t TIMERRST0                              :1;                   /*!< Reset TIMER0 */
  uint32_t TIMERRST1                              :1;                   /*!< Reset TIMER1 */
  uint32_t TIMERRST2                              :1;                   /*!< Reset TIMER2 */
  uint32_t UARTRST0                               :1;                   /*!< Reset UART0 */
  uint32_t UARTRST1                               :1;                   /*!< Reset UART1 */
  uint32_t UARTRST2                               :1;                   /*!< Reset UART2 */
  uint32_t UARTRST3                               :1;                   /*!< Reset UART3 */
  uint32_t SPIRST0                                :1;                   /*!< Reset SPI0 */
  uint32_t SPIRST1                                :1;                   /*!< Reset SPI1 */
  uint32_t SPIRST2                                :1;                   /*!< Reset SPI2 */
  uint32_t SPIRST3                                :1;                   /*!< Reset SPI3 */
  uint32_t ETHRST                                 :1;                   /*!< Reset Ethernet */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _COMMON_REG_PER_RST0_bits;

/* Bit field positions: */
#define COMMON_REG_PER_RST0_WDRST_Pos                       0           /*!< Reset WatchDog */
#define COMMON_REG_PER_RST0_I2CRST0_Pos                     1           /*!< Reset I2C0 */
#define COMMON_REG_PER_RST0_I2CRST1_Pos                     2           /*!< Reset I2C1 */
#define COMMON_REG_PER_RST0_USBPHYRST_Pos                   3           /*!< Reset USB_PHY */
#define COMMON_REG_PER_RST0_TIMERRST0_Pos                   4           /*!< Reset TIMER0 */
#define COMMON_REG_PER_RST0_TIMERRST1_Pos                   5           /*!< Reset TIMER1 */
#define COMMON_REG_PER_RST0_TIMERRST2_Pos                   6           /*!< Reset TIMER2 */
#define COMMON_REG_PER_RST0_UARTRST0_Pos                    7           /*!< Reset UART0 */
#define COMMON_REG_PER_RST0_UARTRST1_Pos                    8           /*!< Reset UART1 */
#define COMMON_REG_PER_RST0_UARTRST2_Pos                    9           /*!< Reset UART2 */
#define COMMON_REG_PER_RST0_UARTRST3_Pos                    10          /*!< Reset UART3 */
#define COMMON_REG_PER_RST0_SPIRST0_Pos                     11          /*!< Reset SPI0 */
#define COMMON_REG_PER_RST0_SPIRST1_Pos                     12          /*!< Reset SPI1 */
#define COMMON_REG_PER_RST0_SPIRST2_Pos                     13          /*!< Reset SPI2 */
#define COMMON_REG_PER_RST0_SPIRST3_Pos                     14          /*!< Reset SPI3 */
#define COMMON_REG_PER_RST0_ETHRST_Pos                      15          /*!< Reset Ethernet */

/* Bit field masks: */
#define COMMON_REG_PER_RST0_WDRST_Msk                       0x00000001  /*!< Reset WatchDog */
#define COMMON_REG_PER_RST0_I2CRST0_Msk                     0x00000002  /*!< Reset I2C0 */
#define COMMON_REG_PER_RST0_I2CRST1_Msk                     0x00000004  /*!< Reset I2C1 */
#define COMMON_REG_PER_RST0_USBPHYRST_Msk                   0x00000008  /*!< Reset USB_PHY */
#define COMMON_REG_PER_RST0_TIMERRST0_Msk                   0x00000010  /*!< Reset TIMER0 */
#define COMMON_REG_PER_RST0_TIMERRST1_Msk                   0x00000020  /*!< Reset TIMER1 */
#define COMMON_REG_PER_RST0_TIMERRST2_Msk                   0x00000040  /*!< Reset TIMER2 */
#define COMMON_REG_PER_RST0_UARTRST0_Msk                    0x00000080  /*!< Reset UART0 */
#define COMMON_REG_PER_RST0_UARTRST1_Msk                    0x00000100  /*!< Reset UART1 */
#define COMMON_REG_PER_RST0_UARTRST2_Msk                    0x00000200  /*!< Reset UART2 */
#define COMMON_REG_PER_RST0_UARTRST3_Msk                    0x00000400  /*!< Reset UART3 */
#define COMMON_REG_PER_RST0_SPIRST0_Msk                     0x00000800  /*!< Reset SPI0 */
#define COMMON_REG_PER_RST0_SPIRST1_Msk                     0x00001000  /*!< Reset SPI1 */
#define COMMON_REG_PER_RST0_SPIRST2_Msk                     0x00002000  /*!< Reset SPI2 */
#define COMMON_REG_PER_RST0_SPIRST3_Msk                     0x00004000  /*!< Reset SPI3 */
#define COMMON_REG_PER_RST0_ETHRST_Msk                      0x00008000  /*!< Reset Ethernet */

/*-- PER_RST1: Peripheral reset register 1 -----------------------------------*/

typedef struct {
  uint32_t QEPRST0                                :1;                   /*!< Reset QEPR0 */
  uint32_t QEPRST1                                :1;                   /*!< Reset QEPR0 */
  uint32_t PWMRST0                                :1;                   /*!< Reset module PWM0 */
  uint32_t PWMRST1                                :1;                   /*!< Reset module PWM1 */
  uint32_t PWMRST2                                :1;                   /*!< Reset module PWM2 */
  uint32_t PWMRST3                                :1;                   /*!< Reset module PWM3 */
  uint32_t PWMRST4                                :1;                   /*!< Reset module PWM4 */
  uint32_t PWMRST5                                :1;                   /*!< Reset module PWM5 */
  uint32_t PWMRST6                                :1;                   /*!< Reset module PWM6 */
  uint32_t PWMRST7                                :1;                   /*!< Reset module PWM7 */
  uint32_t PWMRST8                                :1;                   /*!< Reset module PWM8 */
  uint32_t CAPRST0                                :1;                   /*!< Reset module CAP0 */
  uint32_t CAPRST1                                :1;                   /*!< Reset module CAP1 */
  uint32_t CAPRST2                                :1;                   /*!< Reset module CAP2 */
  uint32_t CAPRST3                                :1;                   /*!< Reset module CAP3 */
  uint32_t CAPRST4                                :1;                   /*!< Reset module CAP4 */
  uint32_t CAPRST5                                :1;                   /*!< Reset module CAP5 */
  uint32_t ECMPRST                                :1;                   /*!< Reset of analog comparator */
  uint32_t Reserved0                              :14;                  /*!< Reserved */
} _COMMON_REG_PER_RST1_bits;

/* Bit field positions: */
#define COMMON_REG_PER_RST1_QEPRST0_Pos                     0           /*!< Reset QEPR0 */
#define COMMON_REG_PER_RST1_QEPRST1_Pos                     1           /*!< Reset QEPR0 */
#define COMMON_REG_PER_RST1_PWMRST0_Pos                     2           /*!< Reset module PWM0 */
#define COMMON_REG_PER_RST1_PWMRST1_Pos                     3           /*!< Reset module PWM1 */
#define COMMON_REG_PER_RST1_PWMRST2_Pos                     4           /*!< Reset module PWM2 */
#define COMMON_REG_PER_RST1_PWMRST3_Pos                     5           /*!< Reset module PWM3 */
#define COMMON_REG_PER_RST1_PWMRST4_Pos                     6           /*!< Reset module PWM4 */
#define COMMON_REG_PER_RST1_PWMRST5_Pos                     7           /*!< Reset module PWM5 */
#define COMMON_REG_PER_RST1_PWMRST6_Pos                     8           /*!< Reset module PWM6 */
#define COMMON_REG_PER_RST1_PWMRST7_Pos                     9           /*!< Reset module PWM7 */
#define COMMON_REG_PER_RST1_PWMRST8_Pos                     10          /*!< Reset module PWM8 */
#define COMMON_REG_PER_RST1_CAPRST0_Pos                     11          /*!< Reset module CAP0 */
#define COMMON_REG_PER_RST1_CAPRST1_Pos                     12          /*!< Reset module CAP1 */
#define COMMON_REG_PER_RST1_CAPRST2_Pos                     13          /*!< Reset module CAP2 */
#define COMMON_REG_PER_RST1_CAPRST3_Pos                     14          /*!< Reset module CAP3 */
#define COMMON_REG_PER_RST1_CAPRST4_Pos                     15          /*!< Reset module CAP4 */
#define COMMON_REG_PER_RST1_CAPRST5_Pos                     16          /*!< Reset module CAP5 */
#define COMMON_REG_PER_RST1_ECMPRST_Pos                     17          /*!< Reset of analog comparator */

/* Bit field masks: */
#define COMMON_REG_PER_RST1_QEPRST0_Msk                     0x00000001  /*!< Reset QEPR0 */
#define COMMON_REG_PER_RST1_QEPRST1_Msk                     0x00000002  /*!< Reset QEPR0 */
#define COMMON_REG_PER_RST1_PWMRST0_Msk                     0x00000004  /*!< Reset module PWM0 */
#define COMMON_REG_PER_RST1_PWMRST1_Msk                     0x00000008  /*!< Reset module PWM1 */
#define COMMON_REG_PER_RST1_PWMRST2_Msk                     0x00000010  /*!< Reset module PWM2 */
#define COMMON_REG_PER_RST1_PWMRST3_Msk                     0x00000020  /*!< Reset module PWM3 */
#define COMMON_REG_PER_RST1_PWMRST4_Msk                     0x00000040  /*!< Reset module PWM4 */
#define COMMON_REG_PER_RST1_PWMRST5_Msk                     0x00000080  /*!< Reset module PWM5 */
#define COMMON_REG_PER_RST1_PWMRST6_Msk                     0x00000100  /*!< Reset module PWM6 */
#define COMMON_REG_PER_RST1_PWMRST7_Msk                     0x00000200  /*!< Reset module PWM7 */
#define COMMON_REG_PER_RST1_PWMRST8_Msk                     0x00000400  /*!< Reset module PWM8 */
#define COMMON_REG_PER_RST1_CAPRST0_Msk                     0x00000800  /*!< Reset module CAP0 */
#define COMMON_REG_PER_RST1_CAPRST1_Msk                     0x00001000  /*!< Reset module CAP1 */
#define COMMON_REG_PER_RST1_CAPRST2_Msk                     0x00002000  /*!< Reset module CAP2 */
#define COMMON_REG_PER_RST1_CAPRST3_Msk                     0x00004000  /*!< Reset module CAP3 */
#define COMMON_REG_PER_RST1_CAPRST4_Msk                     0x00008000  /*!< Reset module CAP4 */
#define COMMON_REG_PER_RST1_CAPRST5_Msk                     0x00010000  /*!< Reset module CAP5 */
#define COMMON_REG_PER_RST1_ECMPRST_Msk                     0x00020000  /*!< Reset of analog comparator */

/*-- GPIOSE0: Control register resynchronization input ports A, B ------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port A */
  uint32_t PORTB                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port B */
} _COMMON_REG_GPIOSE0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOSE0_PORTA_Pos                        0           /*!< Enable resynchronization  of each input PIN for Port A */
#define COMMON_REG_GPIOSE0_PORTB_Pos                        16          /*!< Enable resynchronization  of each input PIN for Port B */

/* Bit field masks: */
#define COMMON_REG_GPIOSE0_PORTA_Msk                        0x0000FFFF  /*!< Enable resynchronization  of each input PIN for Port A */
#define COMMON_REG_GPIOSE0_PORTB_Msk                        0xFFFF0000  /*!< Enable resynchronization  of each input PIN for Port B */

/*-- GPIOSE1: Control register resynchronization input ports C, D ------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port C */
  uint32_t PORTD                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port D */
} _COMMON_REG_GPIOSE1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOSE1_PORTC_Pos                        0           /*!< Enable resynchronization  of each input PIN for Port C */
#define COMMON_REG_GPIOSE1_PORTD_Pos                        16          /*!< Enable resynchronization  of each input PIN for Port D */

/* Bit field masks: */
#define COMMON_REG_GPIOSE1_PORTC_Msk                        0x0000FFFF  /*!< Enable resynchronization  of each input PIN for Port C */
#define COMMON_REG_GPIOSE1_PORTD_Msk                        0xFFFF0000  /*!< Enable resynchronization  of each input PIN for Port D */

/*-- GPIOSE2: Control register resynchronization input ports E, F ------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port E */
  uint32_t PORTF                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port F */
} _COMMON_REG_GPIOSE2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOSE2_PORTE_Pos                        0           /*!< Enable resynchronization  of each input PIN for Port E */
#define COMMON_REG_GPIOSE2_PORTF_Pos                        16          /*!< Enable resynchronization  of each input PIN for Port F */

/* Bit field masks: */
#define COMMON_REG_GPIOSE2_PORTE_Msk                        0x0000FFFF  /*!< Enable resynchronization  of each input PIN for Port E */
#define COMMON_REG_GPIOSE2_PORTF_Msk                        0xFFFF0000  /*!< Enable resynchronization  of each input PIN for Port F */

/*-- GPIOSE3: Control register resynchronization input ports G, H ------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port G */
  uint32_t PORTH                                  :16;                  /*!< Enable resynchronization  of each input PIN for Port H */
} _COMMON_REG_GPIOSE3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOSE3_PORTG_Pos                        0           /*!< Enable resynchronization  of each input PIN for Port G */
#define COMMON_REG_GPIOSE3_PORTH_Pos                        16          /*!< Enable resynchronization  of each input PIN for Port H */

/* Bit field masks: */
#define COMMON_REG_GPIOSE3_PORTG_Msk                        0x0000FFFF  /*!< Enable resynchronization  of each input PIN for Port G */
#define COMMON_REG_GPIOSE3_PORTH_Msk                        0xFFFF0000  /*!< Enable resynchronization  of each input PIN for Port H */

/*-- GPIOQE0: Register filter settings input ports A, B ----------------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Enable filter  of each input PIN for Port A */
  uint32_t PORTB                                  :16;                  /*!< Enable filter  of each input PIN for Port B */
} _COMMON_REG_GPIOQE0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQE0_PORTA_Pos                        0           /*!< Enable filter  of each input PIN for Port A */
#define COMMON_REG_GPIOQE0_PORTB_Pos                        16          /*!< Enable filter  of each input PIN for Port B */

/* Bit field masks: */
#define COMMON_REG_GPIOQE0_PORTA_Msk                        0x0000FFFF  /*!< Enable filter  of each input PIN for Port A */
#define COMMON_REG_GPIOQE0_PORTB_Msk                        0xFFFF0000  /*!< Enable filter  of each input PIN for Port B */

/*-- GPIOQE1: Register filter settings input ports C, D ----------------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Enable filter  of each input PIN for Port C */
  uint32_t PORTD                                  :16;                  /*!< Enable filter  of each input PIN for Port D */
} _COMMON_REG_GPIOQE1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQE1_PORTC_Pos                        0           /*!< Enable filter  of each input PIN for Port C */
#define COMMON_REG_GPIOQE1_PORTD_Pos                        16          /*!< Enable filter  of each input PIN for Port D */

/* Bit field masks: */
#define COMMON_REG_GPIOQE1_PORTC_Msk                        0x0000FFFF  /*!< Enable filter  of each input PIN for Port C */
#define COMMON_REG_GPIOQE1_PORTD_Msk                        0xFFFF0000  /*!< Enable filter  of each input PIN for Port D */

/*-- GPIOQE2: Register filter settings input ports E, F ----------------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Enable filter  of each input PIN for Port E */
  uint32_t PORTF                                  :16;                  /*!< Enable filter  of each input PIN for Port F */
} _COMMON_REG_GPIOQE2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQE2_PORTE_Pos                        0           /*!< Enable filter  of each input PIN for Port E */
#define COMMON_REG_GPIOQE2_PORTF_Pos                        16          /*!< Enable filter  of each input PIN for Port F */

/* Bit field masks: */
#define COMMON_REG_GPIOQE2_PORTE_Msk                        0x0000FFFF  /*!< Enable filter  of each input PIN for Port E */
#define COMMON_REG_GPIOQE2_PORTF_Msk                        0xFFFF0000  /*!< Enable filter  of each input PIN for Port F */

/*-- GPIOQE3: Register filter settings input ports G, H ----------------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Enable filter  of each input PIN for Port G */
  uint32_t PORTH                                  :16;                  /*!< Enable filter  of each input PIN for Port H */
} _COMMON_REG_GPIOQE3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQE3_PORTG_Pos                        0           /*!< Enable filter  of each input PIN for Port G */
#define COMMON_REG_GPIOQE3_PORTH_Pos                        16          /*!< Enable filter  of each input PIN for Port H */

/* Bit field masks: */
#define COMMON_REG_GPIOQE3_PORTG_Msk                        0x0000FFFF  /*!< Enable filter  of each input PIN for Port G */
#define COMMON_REG_GPIOQE3_PORTH_Msk                        0xFFFF0000  /*!< Enable filter  of each input PIN for Port H */

/*-- GPIOQM0: Register filter settings input ports A, B ----------------------*/

typedef struct {
  uint32_t PORTA                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port B */
  uint32_t PORTB                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port A */
} _COMMON_REG_GPIOQM0_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQM0_PORTA_Pos                        0           /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port B */
#define COMMON_REG_GPIOQM0_PORTB_Pos                        16          /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port A */

/* Bit field masks: */
#define COMMON_REG_GPIOQM0_PORTA_Msk                        0x0000FFFF  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port B */
#define COMMON_REG_GPIOQM0_PORTB_Msk                        0xFFFF0000  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port A */

/*-- GPIOQM1: Register filter settings input ports C, D ----------------------*/

typedef struct {
  uint32_t PORTC                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port C */
  uint32_t PORTD                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port D */
} _COMMON_REG_GPIOQM1_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQM1_PORTC_Pos                        0           /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port C */
#define COMMON_REG_GPIOQM1_PORTD_Pos                        16          /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port D */

/* Bit field masks: */
#define COMMON_REG_GPIOQM1_PORTC_Msk                        0x0000FFFF  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port C */
#define COMMON_REG_GPIOQM1_PORTD_Msk                        0xFFFF0000  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port D */

/*-- GPIOQM2: Register filter settings input ports E, F ----------------------*/

typedef struct {
  uint32_t PORTE                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port E */
  uint32_t PORTF                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port F */
} _COMMON_REG_GPIOQM2_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQM2_PORTE_Pos                        0           /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port E */
#define COMMON_REG_GPIOQM2_PORTF_Pos                        16          /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port F */

/* Bit field masks: */
#define COMMON_REG_GPIOQM2_PORTE_Msk                        0x0000FFFF  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port E */
#define COMMON_REG_GPIOQM2_PORTF_Msk                        0xFFFF0000  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port F */

/*-- GPIOQM3: Register filter settings input ports G, H ----------------------*/

typedef struct {
  uint32_t PORTG                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port G */
  uint32_t PORTH                                  :16;                  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port H */
} _COMMON_REG_GPIOQM3_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQM3_PORTG_Pos                        0           /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port G */
#define COMMON_REG_GPIOQM3_PORTH_Pos                        16          /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port H */

/* Bit field masks: */
#define COMMON_REG_GPIOQM3_PORTG_Msk                        0x0000FFFF  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port G */
#define COMMON_REG_GPIOQM3_PORTH_Msk                        0xFFFF0000  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port H */

/*-- GPIOQPAD: Register filter settings input ports A, B, C, D ---------------*/

typedef struct {
  uint32_t SPRDA                                  :8;
  uint32_t SPRDB                                  :8;                   /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port B */
  uint32_t SPRDC                                  :8;
  uint32_t SPRDD                                  :8;                   /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port A */
} _COMMON_REG_GPIOQPAD_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQPAD_SPRDA_Pos                       0
#define COMMON_REG_GPIOQPAD_SPRDB_Pos                       8           /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port B */
#define COMMON_REG_GPIOQPAD_SPRDC_Pos                       16
#define COMMON_REG_GPIOQPAD_SPRDD_Pos                       24          /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port A */

/* Bit field masks: */
#define COMMON_REG_GPIOQPAD_SPRDA_Msk                       0x000000FF
#define COMMON_REG_GPIOQPAD_SPRDB_Msk                       0x0000FF00  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port B */
#define COMMON_REG_GPIOQPAD_SPRDC_Msk                       0x00FF0000
#define COMMON_REG_GPIOQPAD_SPRDD_Msk                       0xFF000000  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port A */

/*-- GPIOQPEH: Register filter settings input ports E, F, G, H ---------------*/

typedef struct {
  uint32_t SPRDE                                  :8;
  uint32_t SPRDF                                  :8;                   /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port C */
  uint32_t SPRDG                                  :8;
  uint32_t SPRDH                                  :8;                   /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port D */
} _COMMON_REG_GPIOQPEH_bits;

/* Bit field positions: */
#define COMMON_REG_GPIOQPEH_SPRDE_Pos                       0
#define COMMON_REG_GPIOQPEH_SPRDF_Pos                       8           /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port C */
#define COMMON_REG_GPIOQPEH_SPRDG_Pos                       16
#define COMMON_REG_GPIOQPEH_SPRDH_Pos                       24          /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port D */

/* Bit field masks: */
#define COMMON_REG_GPIOQPEH_SPRDE_Msk                       0x000000FF
#define COMMON_REG_GPIOQPEH_SPRDF_Msk                       0x0000FF00  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port C */
#define COMMON_REG_GPIOQPEH_SPRDG_Msk                       0x00FF0000
#define COMMON_REG_GPIOQPEH_SPRDH_Msk                       0xFF000000  /*!< Enable filtered of each PIN on 6 clk instead of 3 clk for Port D */

/*-- USB_CTRL: Customize the USB PHY -----------------------------------------*/

typedef struct {
  uint32_t FSEL                                   :1;                   /*!< Frequency selection reference signal USBPHY (0- 12MHz; 1- 24MHz) */
  uint32_t CLKSEL                                 :1;                   /*!< Select of reference source USBPHY */
  uint32_t CLKEN                                  :1;                   /*!< Enable clk signal USBPHY */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _COMMON_REG_USB_CTRL_bits;

/* Bit field positions: */
#define COMMON_REG_USB_CTRL_FSEL_Pos                        0           /*!< Frequency selection reference signal USBPHY (0- 12MHz; 1- 24MHz) */
#define COMMON_REG_USB_CTRL_CLKSEL_Pos                      1           /*!< Select of reference source USBPHY */
#define COMMON_REG_USB_CTRL_CLKEN_Pos                       2           /*!< Enable clk signal USBPHY */

/* Bit field masks: */
#define COMMON_REG_USB_CTRL_FSEL_Msk                        0x00000001  /*!< Frequency selection reference signal USBPHY (0- 12MHz; 1- 24MHz) */
#define COMMON_REG_USB_CTRL_CLKSEL_Msk                      0x00000002  /*!< Select of reference source USBPHY */
#define COMMON_REG_USB_CTRL_CLKEN_Msk                       0x00000004  /*!< Enable clk signal USBPHY */

/*-- UART_SPI_CLK_SEL: Select source clk UART and SSP register ---------------*/

typedef struct {
  uint32_t SEL_UART0                              :2;                   /*!< Select source clk UART0 */
  uint32_t SEL_UART1                              :2;                   /*!< Select source clk UART1 */
  uint32_t SEL_UART2                              :2;                   /*!< Select source clk UART2 */
  uint32_t SEL_UART3                              :2;                   /*!< Select source clk UART3 */
  uint32_t SEL_SPI0                               :2;                   /*!< Select source clk SPI0 */
  uint32_t SEL_SPI1                               :2;                   /*!< Select source clk SPI1 */
  uint32_t SEL_SPI2                               :2;                   /*!< Select source clk SPI2 */
  uint32_t SEL_SPI3                               :2;                   /*!< Select source clk SPI3 */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _COMMON_REG_UART_SPI_CLK_SEL_bits;

/* Bit field positions: */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART0_Pos           0           /*!< Select source clk UART0 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART1_Pos           2           /*!< Select source clk UART1 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART2_Pos           4           /*!< Select source clk UART2 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART3_Pos           6           /*!< Select source clk UART3 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI0_Pos            8           /*!< Select source clk SPI0 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI1_Pos            10          /*!< Select source clk SPI1 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI2_Pos            12          /*!< Select source clk SPI2 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI3_Pos            14          /*!< Select source clk SPI3 */

/* Bit field masks: */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART0_Msk           0x00000003  /*!< Select source clk UART0 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART1_Msk           0x0000000C  /*!< Select source clk UART1 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART2_Msk           0x00000030  /*!< Select source clk UART2 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_UART3_Msk           0x000000C0  /*!< Select source clk UART3 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI0_Msk            0x00000300  /*!< Select source clk SPI0 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI1_Msk            0x00000C00  /*!< Select source clk SPI1 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI2_Msk            0x00003000  /*!< Select source clk SPI2 */
#define COMMON_REG_UART_SPI_CLK_SEL_SEL_SPI3_Msk            0x0000C000  /*!< Select source clk SPI3 */

/*-- ADC_CTRL2: ADC control register 2 ---------------------------------------*/

typedef struct {
  uint32_t CLKEN_ADC8                             :1;                   /*!< Enable clk ADC8 */
  uint32_t DIVEN_ADC8                             :1;                   /*!< Enable divider clk ADC8 */
  uint32_t DIV_ADC8                               :6;                   /*!< Divider clk ADC8 */
  uint32_t CLKEN_ADC9                             :1;                   /*!< Enable clk ADC9 */
  uint32_t DIVEN_ADC9                             :1;                   /*!< Enable divider clk ADC9 */
  uint32_t DIV_ADC9                               :6;                   /*!< Divider clk ADC9 */
  uint32_t CLKEN_ADC10                            :1;                   /*!< Enable clk ADC10 */
  uint32_t DIVEN_ADC10                            :1;                   /*!< Enable divider clk ADC10 */
  uint32_t DIV_ADC10                              :6;                   /*!< Divider clk ADC10 */
  uint32_t CLKEN_ADC11                            :1;                   /*!< Enable clk ADC11 */
  uint32_t DIVEN_ADC11                            :1;                   /*!< Enable divider clk ADC11 */
  uint32_t DIV_ADC11                              :6;                   /*!< Divider clk ADC11 */
} _COMMON_REG_ADC_CTRL2_bits;

/* Bit field positions: */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC8_Pos                 0           /*!< Enable clk ADC8 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC8_Pos                 1           /*!< Enable divider clk ADC8 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC8_Pos                   2           /*!< Divider clk ADC8 */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC9_Pos                 8           /*!< Enable clk ADC9 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC9_Pos                 9           /*!< Enable divider clk ADC9 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC9_Pos                   10          /*!< Divider clk ADC9 */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC10_Pos                16          /*!< Enable clk ADC10 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC10_Pos                17          /*!< Enable divider clk ADC10 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC10_Pos                  18          /*!< Divider clk ADC10 */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC11_Pos                24          /*!< Enable clk ADC11 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC11_Pos                25          /*!< Enable divider clk ADC11 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC11_Pos                  26          /*!< Divider clk ADC11 */

/* Bit field masks: */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC8_Msk                 0x00000001  /*!< Enable clk ADC8 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC8_Msk                 0x00000002  /*!< Enable divider clk ADC8 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC8_Msk                   0x000000FC  /*!< Divider clk ADC8 */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC9_Msk                 0x00000100  /*!< Enable clk ADC9 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC9_Msk                 0x00000200  /*!< Enable divider clk ADC9 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC9_Msk                   0x0000FC00  /*!< Divider clk ADC9 */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC10_Msk                0x00010000  /*!< Enable clk ADC10 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC10_Msk                0x00020000  /*!< Enable divider clk ADC10 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC10_Msk                  0x00FC0000  /*!< Divider clk ADC10 */
#define COMMON_REG_ADC_CTRL2_CLKEN_ADC11_Msk                0x01000000  /*!< Enable clk ADC11 */
#define COMMON_REG_ADC_CTRL2_DIVEN_ADC11_Msk                0x02000000  /*!< Enable divider clk ADC11 */
#define COMMON_REG_ADC_CTRL2_DIV_ADC11_Msk                  0xFC000000  /*!< Divider clk ADC11 */

/*-- FLASH_FULL_ERASE: Full erase flash (user and boot) register -------------*/

typedef struct {
  uint32_t ERASE_FLASH                            :1;
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _COMMON_REG_FLASH_FULL_ERASE_bits;

/* Bit field positions: */
#define COMMON_REG_FLASH_FULL_ERASE_ERASE_FLASH_Pos         0

/* Bit field masks: */
#define COMMON_REG_FLASH_FULL_ERASE_ERASE_FLASH_Msk         0x00000001

/*-- Register map for COMMON_REG peripheral ----------------------------------*/

typedef struct {
  union {                                                               /*!< Port A,B digital enable register */
    __IO uint32_t GPIODEN0;                                             /*!< GPIODEN0    : type used for word access */
    __IO _COMMON_REG_GPIODEN0_bits GPIODEN0_bit;                        /*!< GPIODEN0_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODENA;                                           /*!< Port A digital enable register */
      __IO uint16_t GPIODENB;                                           /*!< Port B digital enable register */
    };
  };
  union {                                                               /*!< Port C,D digital enable register */
    __IO uint32_t GPIODEN1;                                             /*!< GPIODEN1    : type used for word access */
    __IO _COMMON_REG_GPIODEN1_bits GPIODEN1_bit;                        /*!< GPIODEN1_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODENC;                                           /*!< Port C digital enable register */
      __IO uint16_t GPIODEND;                                           /*!< Port D digital enable register */
    };
  };
  union {                                                               /*!< Port E,F digital enable register */
    __IO uint32_t GPIODEN2;                                             /*!< GPIODEN2    : type used for word access */
    __IO _COMMON_REG_GPIODEN2_bits GPIODEN2_bit;                        /*!< GPIODEN2_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODENE;                                           /*!< Port E digital enable register */
      __IO uint16_t GPIODENF;                                           /*!< Port F digital enable register */
    };
  };
  union {                                                               /*!< Port G,H digital enable register */
    __IO uint32_t GPIODEN3;                                             /*!< GPIODEN3    : type used for word access */
    __IO _COMMON_REG_GPIODEN3_bits GPIODEN3_bit;                        /*!< GPIODEN3_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODENG;                                           /*!< Port G digital enable register */
      __IO uint16_t GPIODENH;                                           /*!< Port H digital enable register */
    };
  };
  uint32_t Reserved0[2];                                                /*!< Reserved */
  union {                                                               /*!< Port A alternative function selection register */
    __IO uint32_t GPIOPCTLA;                                            /*!< GPIOPCTLA    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLA_bits GPIOPCTLA_bit;                      /*!< GPIOPCTLA_bit: structure used for bit access */
  };
  union {                                                               /*!< Port B alternative function selection register */
    __IO uint32_t GPIOPCTLB;                                            /*!< GPIOPCTLB    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLB_bits GPIOPCTLB_bit;                      /*!< GPIOPCTLB_bit: structure used for bit access */
  };
  union {                                                               /*!< Port C alternative function selection register */
    __IO uint32_t GPIOPCTLC;                                            /*!< GPIOPCTLC    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLC_bits GPIOPCTLC_bit;                      /*!< GPIOPCTLC_bit: structure used for bit access */
  };
  union {                                                               /*!< Port D alternative function selection register */
    __IO uint32_t GPIOPCTLD;                                            /*!< GPIOPCTLD    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLD_bits GPIOPCTLD_bit;                      /*!< GPIOPCTLD_bit: structure used for bit access */
  };
  union {                                                               /*!< Port E alternative function selection register */
    __IO uint32_t GPIOPCTLE;                                            /*!< GPIOPCTLE    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLE_bits GPIOPCTLE_bit;                      /*!< GPIOPCTLE_bit: structure used for bit access */
  };
  union {                                                               /*!< Port F alternative function selection register */
    __IO uint32_t GPIOPCTLF;                                            /*!< GPIOPCTLF    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLF_bits GPIOPCTLF_bit;                      /*!< GPIOPCTLF_bit: structure used for bit access */
  };
  union {                                                               /*!< Port G alternative function selection register */
    __IO uint32_t GPIOPCTLG;                                            /*!< GPIOPCTLG    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLG_bits GPIOPCTLG_bit;                      /*!< GPIOPCTLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Port H alternative function selection register */
    __IO uint32_t GPIOPCTLH;                                            /*!< GPIOPCTLH    : type used for word access */
    __IO _COMMON_REG_GPIOPCTLH_bits GPIOPCTLH_bit;                      /*!< GPIOPCTLH_bit: structure used for bit access */
  };
  uint32_t Reserved1[4];                                                /*!< Reserved */
  union {                                                               /*!< Port A,B open-drain enable register */
    __IO uint32_t GPIOODCTL0;                                           /*!< GPIOODCTL0    : type used for word access */
    __IO _COMMON_REG_GPIOODCTL0_bits GPIOODCTL0_bit;                    /*!< GPIOODCTL0_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOODCTLA;                                         /*!< Port A open-drain enable register */
      __IO uint16_t GPIOODCTLB;                                         /*!< Port B open-drain enable register */
    };
  };
  union {                                                               /*!< Port C,D open-drain enable register */
    __IO uint32_t GPIOODCTL1;                                           /*!< GPIOODCTL1    : type used for word access */
    __IO _COMMON_REG_GPIOODCTL1_bits GPIOODCTL1_bit;                    /*!< GPIOODCTL1_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOODCTLC;                                         /*!< Port C open-drain enable register */
      __IO uint16_t GPIOODCTLD;                                         /*!< Port D open-drain enable register */
    };
  };
  union {                                                               /*!< Port E,F open-drain enable register */
    __IO uint32_t GPIOODCTL2;                                           /*!< GPIOODCTL2    : type used for word access */
    __IO _COMMON_REG_GPIOODCTL2_bits GPIOODCTL2_bit;                    /*!< GPIOODCTL2_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOODCTLE;                                         /*!< Port E open-drain enable register */
      __IO uint16_t GPIOODCTLF;                                         /*!< Port F open-drain enable register */
    };
  };
  union {                                                               /*!< Port G,H open-drain enable register */
    __IO uint32_t GPIOODCTL3;                                           /*!< GPIOODCTL3    : type used for word access */
    __IO _COMMON_REG_GPIOODCTL3_bits GPIOODCTL3_bit;                    /*!< GPIOODCTL3_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOODCTLG;                                         /*!< Port G open-drain enable register */
      __IO uint16_t GPIOODCTLH;                                         /*!< Port H open-drain enable register */
    };
  };
  uint32_t Reserved2[2];                                                /*!< Reserved */
  union {                                                               /*!< Port A,B strength control register */
    __IO uint32_t GPIODSCTL0;                                           /*!< GPIODSCTL0    : type used for word access */
    __IO _COMMON_REG_GPIODSCTL0_bits GPIODSCTL0_bit;                    /*!< GPIODSCTL0_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODSCTLA;                                        /*!< Port A strength control register */
      __IO uint16_t GPIODSCTLB;                                        /*!< Port B strength control register */
    };
  };
  union {                                                               /*!< Port C,D strength control register */
    __IO uint32_t GPIODSCTL1;                                           /*!< GPIODSCTL1    : type used for word access */
    __IO _COMMON_REG_GPIODSCTL1_bits GPIODSCTL1_bit;                    /*!< GPIODSCTL1_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODSCTLC;                                        /*!< Port C strength control register */
      __IO uint16_t GPIODSCTLD;                                        /*!< Port D strength control register */
    };
  };
  union {                                                               /*!< Port E,F strength control register */
    __IO uint32_t GPIODSCTL2;                                           /*!< GPIODSCTL2    : type used for word access */
    __IO _COMMON_REG_GPIODSCTL2_bits GPIODSCTL2_bit;                    /*!< GPIODSCTL2_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODSCTLE;                                        /*!< Port E strength control register */
      __IO uint16_t GPIODSCTLF;                                        /*!< Port F strength control register */
    };
  };
  union {                                                               /*!< Port G,H strength control register */
    __IO uint32_t GPIODSCTL3;                                           /*!< GPIODSCTL3    : type used for word access */
    __IO _COMMON_REG_GPIODSCTL3_bits GPIODSCTL3_bit;                    /*!< GPIODSCTL3_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIODSCTLG;                                        /*!< Port G strength control register */
      __IO uint16_t GPIODSCTLH;                                        /*!< Port H strength control register */
    };
  };
  uint32_t Reserved3[2];                                                /*!< Reserved */                                               /*!< Reserved */
  union {                                                               /*!< Port A,B pull-up enable register */
    __IO uint32_t GPIOPUCTL0;                                           /*!< GPIOPUCTL0    : type used for word access */
    __IO _COMMON_REG_GPIOPUCTL0_bits GPIOPUCTL0_bit;                    /*!< GPIOPUCTL0_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOPUCTLA;                                         /*!< Port A pull-up enable register */
      __IO uint16_t GPIOPUCTLB;                                         /*!< Port B pull-up enable register */
    };
  };
  union {                                                               /*!< Port C,D pull-up enable register */
    __IO uint32_t GPIOPUCTL1;                                           /*!< GPIOPUCTL1    : type used for word access */
    __IO _COMMON_REG_GPIOPUCTL1_bits GPIOPUCTL1_bit;                    /*!< GPIOPUCTL1_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOPUCTLC;                                         /*!< Port C pull-up enable register */
      __IO uint16_t GPIOPUCTLD;                                         /*!< Port D pull-up enable register */
    };
  };
  union {                                                               /*!< Port E,F pull-up enable register*/
    __IO uint32_t GPIOPUCTL2;                                           /*!< GPIOPUCTL2    : type used for word access */
    __IO _COMMON_REG_GPIOPUCTL2_bits GPIOPUCTL2_bit;                    /*!< GPIOPUCTL2_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOPUCTLE;                                         /*!< Port E pull-up enable register */
      __IO uint16_t GPIOPUCTLF;                                         /*!< Port F pull-up enable register */
    };
  };
  union {                                                               /*!< Port G,H pull-up enable register */
    __IO uint32_t GPIOPUCTL3;                                           /*!< GPIOPUCTL3    : type used for word access */
    __IO _COMMON_REG_GPIOPUCTL3_bits GPIOPUCTL3_bit;                    /*!< GPIOPUCTL3_bit: structure used for bit access */
    struct {
      __IO uint16_t GPIOPUCTLG;                                         /*!< Port G pull-up enable register */
      __IO uint16_t GPIOPUCTLH;                                         /*!< Port H pull-up enable register */
    };
  };
  uint32_t Reserved4[3];                                                /*!< Reserved */
  union {                                                               /*!< PLL control register */
    __IO uint32_t PLL_CTRL;                                             /*!< PLL_CTRL    : type used for word access */
    __IO _COMMON_REG_PLL_CTRL_bits PLL_CTRL_bit;                        /*!< PLL_CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL output divider selection register */
    __IO uint32_t PLL_OD;                                               /*!< PLL_OD    : type used for word access */
    __IO _COMMON_REG_PLL_OD_bits PLL_OD_bit;                            /*!< PLL_OD_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL reference divider register */
    __IO uint32_t PLL_NR;                                               /*!< PLL_NR    : type used for word access */
    __IO _COMMON_REG_PLL_NR_bits PLL_NR_bit;                            /*!< PLL_NR_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL feedback divider register */
    __IO uint32_t PLL_NF;                                               /*!< PLL_NF    : type used for word access */
    __IO _COMMON_REG_PLL_NF_bits PLL_NF_bit;                            /*!< PLL_NF_bit: structure used for bit access */
  };
  union {                                                               /*!< External memory configuration register */
    __IO uint32_t EXT_MEM_CFG;                                          /*!< EXT_MEM_CFG    : type used for word access */
    __IO _COMMON_REG_EXT_MEM_CFG_bits EXT_MEM_CFG_bit;                  /*!< EXT_MEM_CFG_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC 0-3 clock control register */
    __IO uint32_t ADC_CTRL0;                                            /*!< ADC_CTRL0    : type used for word access */
    __IO _COMMON_REG_ADC_CTRL0_bits ADC_CTRL0_bit;                      /*!< ADC_CTRL0_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC 4-7 clock control register */
    __IO uint32_t ADC_CTRL1;                                            /*!< ADC_CTRL1    : type used for word access */
    __IO _COMMON_REG_ADC_CTRL1_bits ADC_CTRL1_bit;                      /*!< ADC_CTRL1_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM prescalers sync register */
    __IO uint32_t PWM_SYNC;                                             /*!< PWM_SYNC    : type used for word access */
    __IO _COMMON_REG_PWM_SYNC_bits PWM_SYNC_bit;                        /*!< PWM_SYNC_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM sync control register */
    __IO uint32_t PWM_CTRL;                                             /*!< PWM_CTRL    : type used for word access */
    __IO _COMMON_REG_PWM_CTRL_bits PWM_CTRL_bit;                        /*!< PWM_CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< System clock control register */
    __IO uint32_t SYS_CLK;                                              /*!< SYS_CLK    : type used for word access */
    __IO _COMMON_REG_SYS_CLK_bits SYS_CLK_bit;                          /*!< SYS_CLK_bit: structure used for bit access */
  };
  union {                                                               /*!< Peripheral clock control register */
    __IO uint32_t APB_CLK;                                              /*!< APB_CLK    : type used for word access */
    __IO _COMMON_REG_APB_CLK_bits APB_CLK_bit;                          /*!< APB_CLK_bit: structure used for bit access */
  };
  union {                                                               /*!< UART clock control register */
    __IO uint32_t UART_CLK;                                             /*!< UART_CLK    : type used for word access */
    __IO _COMMON_REG_UART_CLK_bits UART_CLK_bit;                        /*!< UART_CLK_bit: structure used for bit access */
  };
  union {                                                               /*!< SPI clock control register */
    __IO uint32_t SPI_CLK;                                              /*!< SPI_CLK    : type used for word access */
    __IO _COMMON_REG_SPI_CLK_bits SPI_CLK_bit;                          /*!< SPI_CLK_bit: structure used for bit access */
  };
  union {                                                               /*!< Peripheral reset register 0 */
    __IO uint32_t PER_RST0;                                             /*!< PER_RST0    : type used for word access */
    __IO _COMMON_REG_PER_RST0_bits PER_RST0_bit;                        /*!< PER_RST0_bit: structure used for bit access */
  };
  union {                                                               /*!< Peripheral reset register 1 */
    __IO uint32_t PER_RST1;                                             /*!< PER_RST1    : type used for word access */
    __IO _COMMON_REG_PER_RST1_bits PER_RST1_bit;                        /*!< PER_RST1_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register resynchronization input ports A, B */
    __IO uint32_t GPIOSE0;                                              /*!< GPIOSE0    : type used for word access */
    __IO _COMMON_REG_GPIOSE0_bits GPIOSE0_bit;                          /*!< GPIOSE0_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register resynchronization input ports C, D */
    __IO uint32_t GPIOSE1;                                              /*!< GPIOSE1    : type used for word access */
    __IO _COMMON_REG_GPIOSE1_bits GPIOSE1_bit;                          /*!< GPIOSE1_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register resynchronization input ports E, F */
    __IO uint32_t GPIOSE2;                                              /*!< GPIOSE2    : type used for word access */
    __IO _COMMON_REG_GPIOSE2_bits GPIOSE2_bit;                          /*!< GPIOSE2_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register resynchronization input ports G, H */
    __IO uint32_t GPIOSE3;                                              /*!< GPIOSE3    : type used for word access */
    __IO _COMMON_REG_GPIOSE3_bits GPIOSE3_bit;                          /*!< GPIOSE3_bit: structure used for bit access */
  };
  uint32_t Reserved5[4];                                                /*!< Reserved */
  union {                                                               /*!< Register filter settings input ports A, B */
    __IO uint32_t GPIOQE0;                                              /*!< GPIOQE0    : type used for word access */
    __IO _COMMON_REG_GPIOQE0_bits GPIOQE0_bit;                          /*!< GPIOQE0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports C, D */
    __IO uint32_t GPIOQE1;                                              /*!< GPIOQE1    : type used for word access */
    __IO _COMMON_REG_GPIOQE1_bits GPIOQE1_bit;                          /*!< GPIOQE1_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports E, F */
    __IO uint32_t GPIOQE2;                                              /*!< GPIOQE2    : type used for word access */
    __IO _COMMON_REG_GPIOQE2_bits GPIOQE2_bit;                          /*!< GPIOQE2_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports G, H */
    __IO uint32_t GPIOQE3;                                              /*!< GPIOQE3    : type used for word access */
    __IO _COMMON_REG_GPIOQE3_bits GPIOQE3_bit;                          /*!< GPIOQE3_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports A, B */
    __IO uint32_t GPIOQM0;                                              /*!< GPIOQM0    : type used for word access */
    __IO _COMMON_REG_GPIOQM0_bits GPIOQM0_bit;                          /*!< GPIOQM0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports C, D */
    __IO uint32_t GPIOQM1;                                              /*!< GPIOQM1    : type used for word access */
    __IO _COMMON_REG_GPIOQM1_bits GPIOQM1_bit;                          /*!< GPIOQM1_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports E, F */
    __IO uint32_t GPIOQM2;                                              /*!< GPIOQM2    : type used for word access */
    __IO _COMMON_REG_GPIOQM2_bits GPIOQM2_bit;                          /*!< GPIOQM2_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports G, H */
    __IO uint32_t GPIOQM3;                                              /*!< GPIOQM3    : type used for word access */
    __IO _COMMON_REG_GPIOQM3_bits GPIOQM3_bit;                          /*!< GPIOQM3_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports A, B, C, D */
    __IO uint32_t GPIOQPAD;                                             /*!< GPIOQPAD    : type used for word access */
    __IO _COMMON_REG_GPIOQPAD_bits GPIOQPAD_bit;                        /*!< GPIOQPAD_bit: structure used for bit access */
  };
  union {                                                               /*!< Register filter settings input ports E, F, G, H */
    __IO uint32_t GPIOQPEH;                                             /*!< GPIOQPEH    : type used for word access */
    __IO _COMMON_REG_GPIOQPEH_bits GPIOQPEH_bit;                        /*!< GPIOQPEH_bit: structure used for bit access */
  };
  uint32_t Reserved6[6];                                                /*!< Reserved */
  union {                                                               /*!< Customize the USB PHY */
    __IO uint32_t USB_CTRL;                                             /*!< USB_CTRL    : type used for word access */
    __IO _COMMON_REG_USB_CTRL_bits USB_CTRL_bit;                        /*!< USB_CTRL_bit: structure used for bit access */
  };
  uint32_t Reserved7;                                                   /*!< Reserved */
  union {                                                               /*!< Select source clk UART and SSP register */
    __IO uint32_t UART_SPI_CLK_SEL;                                     /*!< UART_SPI_CLK_SEL    : type used for word access */
    __IO _COMMON_REG_UART_SPI_CLK_SEL_bits UART_SPI_CLK_SEL_bit;        /*!< UART_SPI_CLK_SEL_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC control register 2 */
    __IO uint32_t ADC_CTRL2;                                            /*!< ADC_CTRL2    : type used for word access */
    __IO _COMMON_REG_ADC_CTRL2_bits ADC_CTRL2_bit;                      /*!< ADC_CTRL2_bit: structure used for bit access */
  };
  uint32_t Reserved8[9];                                                /*!< Reserved */
  union {                                                               /*!< Full erase flash (user and boot) register */
    __IO uint32_t FLASH_FULL_ERASE;                                     /*!< FLASH_FULL_ERASE    : type used for word access */
    __IO _COMMON_REG_FLASH_FULL_ERASE_bits FLASH_FULL_ERASE_bit;        /*!< FLASH_FULL_ERASE_bit: structure used for bit access */
  };
} NT_COMMON_REG_TypeDef;

/******************************************************************************/
/*                         CAN controller registers                           */
/******************************************************************************/

/*-- CLC: Frequency control register -----------------------------------------*/

typedef struct {
  uint32_t DISR                                   :1;                   /*!< OFF module CAN */
  uint32_t DISS                                   :1;                   /*!< State CAN */
  uint32_t SPEN                                   :1;                   /*!< Activate suspend mode for system debugging */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SBWE                                   :1;                   /*!< Enable write in FSOE and SPEN for system debugging */
  uint32_t FSOE                                   :1;                   /*!< activation quickly turn off the CAN for system debugging */
  uint32_t Reserved1                              :26;                  /*!< Reserved */
} _CAN_CLC_bits;

/* Bit field positions: */
#define CAN_CLC_DISR_Pos                                    0           /*!< OFF module CAN */
#define CAN_CLC_DISS_Pos                                    1           /*!< State CAN */
#define CAN_CLC_SPEN_Pos                                    2           /*!< Activate suspend mode for system debugging */
#define CAN_CLC_SBWE_Pos                                    4           /*!< Enable write in FSOE and SPEN for system debugging */
#define CAN_CLC_FSOE_Pos                                    5           /*!< activation quickly turn off the CAN for system debugging */

/* Bit field masks: */
#define CAN_CLC_DISR_Msk                                    0x00000001  /*!< OFF module CAN */
#define CAN_CLC_DISS_Msk                                    0x00000002  /*!< State CAN */
#define CAN_CLC_SPEN_Msk                                    0x00000004  /*!< Activate suspend mode for system debugging */
#define CAN_CLC_SBWE_Msk                                    0x00000010  /*!< Enable write in FSOE and SPEN for system debugging */
#define CAN_CLC_FSOE_Msk                                    0x00000020  /*!< activation quickly turn off the CAN for system debugging */

/*-- ID: Identity register ---------------------------------------------------*/

typedef struct {
  uint32_t MOD_REV                                :8;                   /*!< Number of modifications of the CAN */
  uint32_t MOD_TYPE                               :8;                   /*!< Digit capacity CAN */
  uint32_t MOD_NUMBER                             :16;                  /*!< Identification number CAN */
} _CAN_ID_bits;

/* Bit field positions: */
#define CAN_ID_MOD_REV_Pos                                  0           /*!< Number of modifications of the CAN */
#define CAN_ID_MOD_TYPE_Pos                                 8           /*!< Digit capacity CAN */
#define CAN_ID_MOD_NUMBER_Pos                               16          /*!< Identification number CAN */

/* Bit field masks: */
#define CAN_ID_MOD_REV_Msk                                  0x000000FF  /*!< Number of modifications of the CAN */
#define CAN_ID_MOD_TYPE_Msk                                 0x0000FF00  /*!< Digit capacity CAN */
#define CAN_ID_MOD_NUMBER_Msk                               0xFFFF0000  /*!< Identification number CAN */

/*-- FDR: Register divider ---------------------------------------------------*/

typedef struct {
  uint32_t STEP                                   :10;                  /*!< Step divider */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SM                                     :1;                   /*!< Select the transition mode Suspend */
  uint32_t SC                                     :2;                   /*!< Configuration of the frequency divider in mode Suspend */
  uint32_t DM                                     :2;                   /*!< Mode setting of the frequency divider */
  uint32_t RESULT                                 :10;                  /*!< Count frequency divider */
  uint32_t Reserved1                              :2;                   /*!< Reserved */
  uint32_t SUSACK                                 :1;                   /*!< Indicate mode Suspend */
  uint32_t SUSREQ                                 :1;                   /*!< Activate Suspend mode */
  uint32_t ENHW                                   :1;                   /*!< Control bit synchronization */
  uint32_t DISCLK                                 :1;                   /*!< Disable bit internal clock */
} _CAN_FDR_bits;

/* Bit field positions: */
#define CAN_FDR_STEP_Pos                                    0           /*!< Step divider */
#define CAN_FDR_SM_Pos                                      11          /*!< Select the transition mode Suspend */
#define CAN_FDR_SC_Pos                                      12          /*!< Configuration of the frequency divider in mode Suspend */
#define CAN_FDR_DM_Pos                                      14          /*!< Mode setting of the frequency divider */
#define CAN_FDR_RESULT_Pos                                  16          /*!< Count frequency divider */
#define CAN_FDR_SUSACK_Pos                                  28          /*!< Indicate mode Suspend */
#define CAN_FDR_SUSREQ_Pos                                  29          /*!< Activate Suspend mode */
#define CAN_FDR_ENHW_Pos                                    30          /*!< Control bit synchronization */
#define CAN_FDR_DISCLK_Pos                                  31          /*!< Disable bit internal clock */

/* Bit field masks: */
#define CAN_FDR_STEP_Msk                                    0x000003FF  /*!< Step divider */
#define CAN_FDR_SM_Msk                                      0x00000800  /*!< Select the transition mode Suspend */
#define CAN_FDR_SC_Msk                                      0x00003000  /*!< Configuration of the frequency divider in mode Suspend */
#define CAN_FDR_DM_Msk                                      0x0000C000  /*!< Mode setting of the frequency divider */
#define CAN_FDR_RESULT_Msk                                  0x03FF0000  /*!< Count frequency divider */
#define CAN_FDR_SUSACK_Msk                                  0x10000000  /*!< Indicate mode Suspend */
#define CAN_FDR_SUSREQ_Msk                                  0x20000000  /*!< Activate Suspend mode */
#define CAN_FDR_ENHW_Msk                                    0x40000000  /*!< Control bit synchronization */
#define CAN_FDR_DISCLK_Msk                                  0x80000000  /*!< Disable bit internal clock */

/*-- LIST: Register list -----------------------------------------------------*/

typedef struct {
  uint32_t BEGIN                                  :8;                   /*!< Number of the first message object */
  uint32_t END                                    :8;                   /*!< Number of the last message object */
  uint32_t SIZE                                   :8;                   /*!< List size */
  uint32_t EMPTY                                  :1;                   /*!< Indicate empty list */
  uint32_t Reserved0                              :7;                   /*!< Reserved */
} _CAN_LIST_bits;

/* Bit field positions: */
#define CAN_LIST_BEGIN_Pos                                  0           /*!< Number of the first message object */
#define CAN_LIST_END_Pos                                    8           /*!< Number of the last message object */
#define CAN_LIST_SIZE_Pos                                   16          /*!< List size */
#define CAN_LIST_EMPTY_Pos                                  24          /*!< Indicate empty list */

/* Bit field masks: */
#define CAN_LIST_BEGIN_Msk                                  0x000000FF  /*!< Number of the first message object */
#define CAN_LIST_END_Msk                                    0x0000FF00  /*!< Number of the last message object */
#define CAN_LIST_SIZE_Msk                                   0x00FF0000  /*!< List size */
#define CAN_LIST_EMPTY_Msk                                  0x01000000  /*!< Indicate empty list */

/*-- MSID: Register messages index -------------------------------------------*/

typedef struct {
  uint32_t INDEX                                  :8;                   /*!< Number field waiting bit */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _CAN_MSID_bits;

/* Bit field positions: */
#define CAN_MSID_INDEX_Pos                                  0           /*!< Number field waiting bit */

/* Bit field masks: */
#define CAN_MSID_INDEX_Msk                                  0x000000FF  /*!< Number field waiting bit */

/*-- PANCTR: Register command panel ------------------------------------------*/

typedef struct {
  uint32_t PANCMD                                 :8;                   /*!< Command panel */
  uint32_t BUSY                                   :1;                   /*!< Busy flag panels arguments (waiting to be written at the end of the command) */
  uint32_t RBUSY                                  :1;                   /*!< Busy flag panels arguments (running the command list, the result of which will be recorded in PANAR1 and PANAR2) */
  uint32_t Reserved0                              :6;                   /*!< Reserved */
  uint32_t PANAR1                                 :8;                   /*!< Panel argument 8 */
  uint32_t PANAR2                                 :8;                   /*!< Panel argument 9 */
} _CAN_PANCTR_bits;

/* Bit field positions: */
#define CAN_PANCTR_PANCMD_Pos                               0           /*!< Command panel */
#define CAN_PANCTR_BUSY_Pos                                 8           /*!< Busy flag panels arguments (waiting to be written at the end of the command) */
#define CAN_PANCTR_RBUSY_Pos                                9           /*!< Busy flag panels arguments (running the command list, the result of which will be recorded in PANAR1 and PANAR2) */
#define CAN_PANCTR_PANAR1_Pos                               16          /*!< Panel argument 8 */
#define CAN_PANCTR_PANAR2_Pos                               24          /*!< Panel argument 9 */

/* Bit field masks: */
#define CAN_PANCTR_PANCMD_Msk                               0x000000FF  /*!< Command panel */
#define CAN_PANCTR_BUSY_Msk                                 0x00000100  /*!< Busy flag panels arguments (waiting to be written at the end of the command) */
#define CAN_PANCTR_RBUSY_Msk                                0x00000200  /*!< Busy flag panels arguments (running the command list, the result of which will be recorded in PANAR1 and PANAR2) */
#define CAN_PANCTR_PANAR1_Msk                               0x00FF0000  /*!< Panel argument 8 */
#define CAN_PANCTR_PANAR2_Msk                               0xFF000000  /*!< Panel argument 9 */

/*-- MCR_REG -----------------------------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :12;                  /*!< Reserved */
  uint32_t MPSEL                                  :4;                   /*!< Field task position after waiting message bit transmit / receive messages */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _CAN_MCR_REG_bits;

/* Bit field positions: */
#define CAN_MCR_REG_MPSEL_Pos                               12          /*!< Field task position after waiting message bit transmit / receive messages */

/* Bit field masks: */
#define CAN_MCR_REG_MPSEL_Msk                               0x0000F000  /*!< Field task position after waiting message bit transmit / receive messages */

/*-- MITR: Interrupt register ------------------------------------------------*/

typedef struct {
  uint32_t IT                                     :16;                  /*!< Field  generate interrupt */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _CAN_MITR_bits;

/* Bit field positions: */
#define CAN_MITR_IT_Pos                                     0           /*!< Field  generate interrupt */

/* Bit field masks: */
#define CAN_MITR_IT_Msk                                     0x0000FFFF  /*!< Field  generate interrupt */

/*-- NCR: Register control node ----------------------------------------------*/

typedef struct {
  uint32_t INIT                                   :1;                   /*!< Node initialization */
  uint32_t TRIE                                   :1;                   /*!< Interrupt enable bit of the assembly at the end of the transmission / reception */
  uint32_t LECIE                                  :1;                   /*!< Interrupt enable bit of the assembly when it detects the last error code */
  uint32_t ALIE                                   :1;                   /*!< Enable interrupt ALERT from node */
  uint32_t CANDIS                                 :1;                   /*!< Off node */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CCE                                    :1;                   /*!< Permission node configuration changes */
  uint32_t CALM                                   :1;                   /*!< Activate the node analysis */
  uint32_t SUSEN                                  :1;                   /*!< Enable mode suspension of the node */
  uint32_t Reserved1                              :23;                  /*!< Reserved */
} _CAN_NCR_bits;

/* Bit field positions: */
#define CAN_NCR_INIT_Pos                                    0           /*!< Node initialization */
#define CAN_NCR_TRIE_Pos                                    1           /*!< Interrupt enable bit of the assembly at the end of the transmission / reception */
#define CAN_NCR_LECIE_Pos                                   2           /*!< Interrupt enable bit of the assembly when it detects the last error code */
#define CAN_NCR_ALIE_Pos                                    3           /*!< Enable interrupt ALERT from node */
#define CAN_NCR_CANDIS_Pos                                  4           /*!< Off node */
#define CAN_NCR_CCE_Pos                                     6           /*!< Permission node configuration changes */
#define CAN_NCR_CALM_Pos                                    7           /*!< Activate the node analysis */
#define CAN_NCR_SUSEN_Pos                                   8           /*!< Enable mode suspension of the node */

/* Bit field masks: */
#define CAN_NCR_INIT_Msk                                    0x00000001  /*!< Node initialization */
#define CAN_NCR_TRIE_Msk                                    0x00000002  /*!< Interrupt enable bit of the assembly at the end of the transmission / reception */
#define CAN_NCR_LECIE_Msk                                   0x00000004  /*!< Interrupt enable bit of the assembly when it detects the last error code */
#define CAN_NCR_ALIE_Msk                                    0x00000008  /*!< Enable interrupt ALERT from node */
#define CAN_NCR_CANDIS_Msk                                  0x00000010  /*!< Off node */
#define CAN_NCR_CCE_Msk                                     0x00000040  /*!< Permission node configuration changes */
#define CAN_NCR_CALM_Msk                                    0x00000080  /*!< Activate the node analysis */
#define CAN_NCR_SUSEN_Msk                                   0x00000100  /*!< Enable mode suspension of the node */

/*-- NSR: Register state node ------------------------------------------------*/

typedef struct {
  uint32_t LEC                                    :3;                   /*!< Last error code */
  uint32_t TXOK                                   :1;                   /*!< Flag successful message transmission */
  uint32_t RXOK                                   :1;                   /*!< Flag successful reception of messages */
  uint32_t ALERT                                  :1;                   /*!< Warning flag ALERT */
  uint32_t EWRN                                   :1;                   /*!< Flag critical errors */
  uint32_t BOFF                                   :1;                   /*!< Status flag 'is disconnected from the bus' */
  uint32_t LLE                                    :1;                   /*!< Error flag list */
  uint32_t LOE                                    :1;                   /*!< Error Flag Room list */
  uint32_t SUSACK                                 :1;                   /*!< Indicator cluster node suspend mode */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _CAN_NSR_bits;

/* Bit field positions: */
#define CAN_NSR_LEC_Pos                                     0           /*!< Last error code */
#define CAN_NSR_TXOK_Pos                                    3           /*!< Flag successful message transmission */
#define CAN_NSR_RXOK_Pos                                    4           /*!< Flag successful reception of messages */
#define CAN_NSR_ALERT_Pos                                   5           /*!< Warning flag ALERT */
#define CAN_NSR_EWRN_Pos                                    6           /*!< Flag critical errors */
#define CAN_NSR_BOFF_Pos                                    7           /*!< Status flag 'is disconnected from the bus' */
#define CAN_NSR_LLE_Pos                                     8           /*!< Error flag list */
#define CAN_NSR_LOE_Pos                                     9           /*!< Error Flag Room list */
#define CAN_NSR_SUSACK_Pos                                  10          /*!< Indicator cluster node suspend mode */

/* Bit field masks: */
#define CAN_NSR_LEC_Msk                                     0x00000007  /*!< Last error code */
#define CAN_NSR_TXOK_Msk                                    0x00000008  /*!< Flag successful message transmission */
#define CAN_NSR_RXOK_Msk                                    0x00000010  /*!< Flag successful reception of messages */
#define CAN_NSR_ALERT_Msk                                   0x00000020  /*!< Warning flag ALERT */
#define CAN_NSR_EWRN_Msk                                    0x00000040  /*!< Flag critical errors */
#define CAN_NSR_BOFF_Msk                                    0x00000080  /*!< Status flag 'is disconnected from the bus' */
#define CAN_NSR_LLE_Msk                                     0x00000100  /*!< Error flag list */
#define CAN_NSR_LOE_Msk                                     0x00000200  /*!< Error Flag Room list */
#define CAN_NSR_SUSACK_Msk                                  0x00000400  /*!< Indicator cluster node suspend mode */

/*-- NIPR: Interrupt pointer register node -----------------------------------*/

typedef struct {
  uint32_t ALINP                                  :4;
  uint32_t LECINP                                 :4;
  uint32_t TRINP                                  :4;
  uint32_t CFCINP                                 :4;
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _CAN_NIPR_bits;

/* Bit field positions: */
#define CAN_NIPR_ALINP_Pos                                  0
#define CAN_NIPR_LECINP_Pos                                 4
#define CAN_NIPR_TRINP_Pos                                  8
#define CAN_NIPR_CFCINP_Pos                                 12

/* Bit field masks: */
#define CAN_NIPR_ALINP_Msk                                  0x0000000F
#define CAN_NIPR_LECINP_Msk                                 0x000000F0
#define CAN_NIPR_TRINP_Msk                                  0x00000F00
#define CAN_NIPR_CFCINP_Msk                                 0x0000F000

/*-- NPCR: Port control register node ----------------------------------------*/

typedef struct {
  uint32_t RXSEL                                  :3;                   /*!< Selection field output of the microcontroller to receive messages */
  uint32_t Reserved0                              :5;                   /*!< Reserved */
  uint32_t LBM                                    :1;                   /*!< Enable mode Loop-Back */
  uint32_t Reserved1                              :23;                  /*!< Reserved */
} _CAN_NPCR_bits;

/* Bit field positions: */
#define CAN_NPCR_RXSEL_Pos                                  0           /*!< Selection field output of the microcontroller to receive messages */
#define CAN_NPCR_LBM_Pos                                    8           /*!< Enable mode Loop-Back */

/* Bit field masks: */
#define CAN_NPCR_RXSEL_Msk                                  0x00000007  /*!< Selection field output of the microcontroller to receive messages */
#define CAN_NPCR_LBM_Msk                                    0x00000100  /*!< Enable mode Loop-Back */

/*-- NBTR: Timing register bits  ---------------------------------------------*/

typedef struct {
  uint32_t BRP                                    :6;                   /*!< Prescaler rate */
  uint32_t SJW                                    :2;                   /*!< Transition width resynchronization */
  uint32_t TSEG1                                  :4;                   /*!< Parameter 1 */
  uint32_t TSEG2                                  :3;                   /*!< Parameter 2 */
  uint32_t DIV8                                   :1;                   /*!< Frequency divider by 8 */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _CAN_NBTR_bits;

/* Bit field positions: */
#define CAN_NBTR_BRP_Pos                                    0           /*!< Prescaler rate */
#define CAN_NBTR_SJW_Pos                                    6           /*!< Transition width resynchronization */
#define CAN_NBTR_TSEG1_Pos                                  8           /*!< Parameter 1 */
#define CAN_NBTR_TSEG2_Pos                                  12          /*!< Parameter 2 */
#define CAN_NBTR_DIV8_Pos                                   15          /*!< Frequency divider by 8 */

/* Bit field masks: */
#define CAN_NBTR_BRP_Msk                                    0x0000003F  /*!< Prescaler rate */
#define CAN_NBTR_SJW_Msk                                    0x000000C0  /*!< Transition width resynchronization */
#define CAN_NBTR_TSEG1_Msk                                  0x00000F00  /*!< Parameter 1 */
#define CAN_NBTR_TSEG2_Msk                                  0x00007000  /*!< Parameter 2 */
#define CAN_NBTR_DIV8_Msk                                   0x00008000  /*!< Frequency divider by 8 */

/*-- NECNT: Counter error register node --------------------------------------*/

typedef struct {
  uint32_t REC                                    :8;                   /*!< Receive Error Counter field messages */
  uint32_t TEC                                    :8;                   /*!< Counter field messaging error */
  uint32_t EWRNLVL                                :8;                   /*!< Error limit at which a flag is set in the register EWRN NSR */
  uint32_t LETD                                   :1;                   /*!< Flag last transmission errors */
  uint32_t LEINC                                  :1;                   /*!< Indicator increment at the last error */
  uint32_t Reserved0                              :6;                   /*!< Reserved */
} _CAN_NECNT_bits;

/* Bit field positions: */
#define CAN_NECNT_REC_Pos                                   0           /*!< Receive Error Counter field messages */
#define CAN_NECNT_TEC_Pos                                   8           /*!< Counter field messaging error */
#define CAN_NECNT_EWRNLVL_Pos                               16          /*!< Error limit at which a flag is set in the register EWRN NSR */
#define CAN_NECNT_LETD_Pos                                  24          /*!< Flag last transmission errors */
#define CAN_NECNT_LEINC_Pos                                 25          /*!< Indicator increment at the last error */

/* Bit field masks: */
#define CAN_NECNT_REC_Msk                                   0x000000FF  /*!< Receive Error Counter field messages */
#define CAN_NECNT_TEC_Msk                                   0x0000FF00  /*!< Counter field messaging error */
#define CAN_NECNT_EWRNLVL_Msk                               0x00FF0000  /*!< Error limit at which a flag is set in the register EWRN NSR */
#define CAN_NECNT_LETD_Msk                                  0x01000000  /*!< Flag last transmission errors */
#define CAN_NECNT_LEINC_Msk                                 0x02000000  /*!< Indicator increment at the last error */

/*-- NFCR: Register message counter node -------------------------------------*/

typedef struct {
  uint32_t CFC                                    :16;                  /*!< Field of the message counter */
  uint32_t CFSEL                                  :3;                   /*!< Field parameter setting mode selected message counter */
  uint32_t CFMOD                                  :2;                   /*!< Field task mode message counter */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CFCIE                                  :1;                   /*!< Interrupt enable bit of the message counter */
  uint32_t CFCOV                                  :1;                   /*!< Counter overflow flag messages */
  uint32_t Reserved1                              :8;                   /*!< Reserved */
} _CAN_NFCR_bits;

/* Bit field positions: */
#define CAN_NFCR_CFC_Pos                                    0           /*!< Field of the message counter */
#define CAN_NFCR_CFSEL_Pos                                  16          /*!< Field parameter setting mode selected message counter */
#define CAN_NFCR_CFMOD_Pos                                  19          /*!< Field task mode message counter */
#define CAN_NFCR_CFCIE_Pos                                  22          /*!< Interrupt enable bit of the message counter */
#define CAN_NFCR_CFCOV_Pos                                  23          /*!< Counter overflow flag messages */

/* Bit field masks: */
#define CAN_NFCR_CFC_Msk                                    0x0000FFFF  /*!< Field of the message counter */
#define CAN_NFCR_CFSEL_Msk                                  0x00070000  /*!< Field parameter setting mode selected message counter */
#define CAN_NFCR_CFMOD_Msk                                  0x00180000  /*!< Field task mode message counter */
#define CAN_NFCR_CFCIE_Msk                                  0x00400000  /*!< Interrupt enable bit of the message counter */
#define CAN_NFCR_CFCOV_Msk                                  0x00800000  /*!< Counter overflow flag messages */

/*-- MOFCR: Register control the operation of the message object  ------------*/

typedef struct {
  uint32_t MMC                                    :4;
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t GDFS                                   :1;
  uint32_t IDC                                    :1;
  uint32_t DLCC                                   :1;
  uint32_t DATC                                   :1;
  uint32_t Reserved1                              :4;                   /*!< Reserved */
  uint32_t RXIE                                   :1;                   /*!< Interrupt enable after taking the messages */
  uint32_t TXIE                                   :1;                   /*!< Interrupt enable at the end of the message */
  uint32_t OVIE                                   :1;                   /*!< Interrupt enable FIFO to fill the message object  */
  uint32_t Reserved2                              :1;                   /*!< Reserved */
  uint32_t FRREN                                  :1;                   /*!< Enable remote request */
  uint32_t RMM                                    :1;                   /*!< Enable remote monitoring of the communication object */
  uint32_t SDT                                    :1;                   /*!< Bit single of the message object  participation in shipment */
  uint32_t STT                                    :1;                   /*!< Bit single data transfer */
  uint32_t DLC                                    :4;                   /*!< Data length code */
  uint32_t Reserved3                              :4;                   /*!< Reserved */
} _CAN_MOFCR_bits;

/* Bit field positions: */
#define CAN_MOFCR_MMC_Pos                                   0
#define CAN_MOFCR_GDFS_Pos                                  8
#define CAN_MOFCR_IDC_Pos                                   9
#define CAN_MOFCR_DLCC_Pos                                  10
#define CAN_MOFCR_DATC_Pos                                  11
#define CAN_MOFCR_RXIE_Pos                                  16          /*!< Interrupt enable after taking the messages */
#define CAN_MOFCR_TXIE_Pos                                  17          /*!< Interrupt enable at the end of the message */
#define CAN_MOFCR_OVIE_Pos                                  18          /*!< Interrupt enable FIFO to fill the message object  */
#define CAN_MOFCR_FRREN_Pos                                 20          /*!< Enable remote request */
#define CAN_MOFCR_RMM_Pos                                   21          /*!< Enable remote monitoring of the communication object */
#define CAN_MOFCR_SDT_Pos                                   22          /*!< Bit single of the message object  participation in shipment */
#define CAN_MOFCR_STT_Pos                                   23          /*!< Bit single data transfer */
#define CAN_MOFCR_DLC_Pos                                   24          /*!< Data length code */

/* Bit field masks: */
#define CAN_MOFCR_MMC_Msk                                   0x0000000F
#define CAN_MOFCR_GDFS_Msk                                  0x00000100
#define CAN_MOFCR_IDC_Msk                                   0x00000200
#define CAN_MOFCR_DLCC_Msk                                  0x00000400
#define CAN_MOFCR_DATC_Msk                                  0x00000800
#define CAN_MOFCR_RXIE_Msk                                  0x00010000  /*!< Interrupt enable after taking the messages */
#define CAN_MOFCR_TXIE_Msk                                  0x00020000  /*!< Interrupt enable at the end of the message */
#define CAN_MOFCR_OVIE_Msk                                  0x00040000  /*!< Interrupt enable FIFO to fill the message object  */
#define CAN_MOFCR_FRREN_Msk                                 0x00100000  /*!< Enable remote request */
#define CAN_MOFCR_RMM_Msk                                   0x00200000  /*!< Enable remote monitoring of the communication object */
#define CAN_MOFCR_SDT_Msk                                   0x00400000  /*!< Bit single of the message object  participation in shipment */
#define CAN_MOFCR_STT_Msk                                   0x00800000  /*!< Bit single data transfer */
#define CAN_MOFCR_DLC_Msk                                   0x0F000000  /*!< Data length code */

/*-- MOFGPR: Pointer register FIFO / gateway message object  -----------------*/

typedef struct {
  uint32_t BOT                                    :8;                   /*!< FIFO pointer to the lower element */
  uint32_t TOP                                    :8;                   /*!< FIFO pointer to the top element */
  uint32_t CUR                                    :8;                   /*!< A pointer to the current object within the FIFO or gateway */
  uint32_t SEL                                    :8;                   /*!< Object pointer message */
} _CAN_MOFGPR_bits;

/* Bit field positions: */
#define CAN_MOFGPR_BOT_Pos                                  0           /*!< FIFO pointer to the lower element */
#define CAN_MOFGPR_TOP_Pos                                  8           /*!< FIFO pointer to the top element */
#define CAN_MOFGPR_CUR_Pos                                  16          /*!< A pointer to the current object within the FIFO or gateway */
#define CAN_MOFGPR_SEL_Pos                                  24          /*!< Object pointer message */

/* Bit field masks: */
#define CAN_MOFGPR_BOT_Msk                                  0x000000FF  /*!< FIFO pointer to the lower element */
#define CAN_MOFGPR_TOP_Msk                                  0x0000FF00  /*!< FIFO pointer to the top element */
#define CAN_MOFGPR_CUR_Msk                                  0x00FF0000  /*!< A pointer to the current object within the FIFO or gateway */
#define CAN_MOFGPR_SEL_Msk                                  0xFF000000  /*!< Object pointer message */

/*-- MOIPR: Pointer register interrupt message object  -----------------------*/

typedef struct {
  uint32_t RXINP                                  :4;                   /*!< Pointer interrupt line to interrupt after receiving */
  uint32_t TXINP                                  :4;                   /*!< Pointer interrupt line to interrupt after transfer */
  uint32_t MPN                                    :8;                   /*!< Number message waiting bit */
  uint32_t CFCVAL                                 :16;                  /*!< Number of frames */
} _CAN_MOIPR_bits;

/* Bit field positions: */
#define CAN_MOIPR_RXINP_Pos                                 0           /*!< Pointer interrupt line to interrupt after receiving */
#define CAN_MOIPR_TXINP_Pos                                 4           /*!< Pointer interrupt line to interrupt after transfer */
#define CAN_MOIPR_MPN_Pos                                   8           /*!< Number message waiting bit */
#define CAN_MOIPR_CFCVAL_Pos                                16          /*!< Number of frames */

/* Bit field masks: */
#define CAN_MOIPR_RXINP_Msk                                 0x0000000F  /*!< Pointer interrupt line to interrupt after receiving */
#define CAN_MOIPR_TXINP_Msk                                 0x000000F0  /*!< Pointer interrupt line to interrupt after transfer */
#define CAN_MOIPR_MPN_Msk                                   0x0000FF00  /*!< Number message waiting bit */
#define CAN_MOIPR_CFCVAL_Msk                                0xFFFF0000  /*!< Number of frames */

/*-- MOAMR: Mask register message object  ------------------------------------*/

typedef struct {
  uint32_t AM                                     :29;                  /*!< Mask ID */
  uint32_t MIDE                                   :1;                   /*!< Mask bit IDE message */
  uint32_t Reserved0                              :2;                   /*!< Reserved */
} _CAN_MOAMR_bits;

/* Bit field positions: */
#define CAN_MOAMR_AM_Pos                                    0           /*!< Mask ID */
#define CAN_MOAMR_MIDE_Pos                                  29          /*!< Mask bit IDE message */

/* Bit field masks: */
#define CAN_MOAMR_AM_Msk                                    0x1FFFFFFF  /*!< Mask ID */
#define CAN_MOAMR_MIDE_Msk                                  0x20000000  /*!< Mask bit IDE message */

/*-- MODATAL: Low data registers of the message object  ----------------------*/

typedef struct {
  uint32_t DB0                                    :8;                   /*!< Zero byte data */
  uint32_t DB1                                    :8;                   /*!< The first data byte */
  uint32_t DB2                                    :8;                   /*!< Second data byte */
  uint32_t DB3                                    :8;                   /*!< The third data byte */
} _CAN_MODATAL_bits;

/* Bit field positions: */
#define CAN_MODATAL_DB0_Pos                                 0           /*!< Zero byte data */
#define CAN_MODATAL_DB1_Pos                                 8           /*!< The first data byte */
#define CAN_MODATAL_DB2_Pos                                 16          /*!< Second data byte */
#define CAN_MODATAL_DB3_Pos                                 24          /*!< The third data byte */

/* Bit field masks: */
#define CAN_MODATAL_DB0_Msk                                 0x000000FF  /*!< Zero byte data */
#define CAN_MODATAL_DB1_Msk                                 0x0000FF00  /*!< The first data byte */
#define CAN_MODATAL_DB2_Msk                                 0x00FF0000  /*!< Second data byte */
#define CAN_MODATAL_DB3_Msk                                 0xFF000000  /*!< The third data byte */

/*-- MODATAH: High data registers of the message object  ---------------------*/

typedef struct {
  uint32_t DB4                                    :8;                   /*!< The fourth data byte */
  uint32_t DB5                                    :8;                   /*!< Fifth byte data */
  uint32_t DB6                                    :8;                   /*!< Sixth byte data */
  uint32_t DB7                                    :8;                   /*!< Seventh byte of data */
} _CAN_MODATAH_bits;

/* Bit field positions: */
#define CAN_MODATAH_DB4_Pos                                 0           /*!< The fourth data byte */
#define CAN_MODATAH_DB5_Pos                                 8           /*!< Fifth byte data */
#define CAN_MODATAH_DB6_Pos                                 16          /*!< Sixth byte data */
#define CAN_MODATAH_DB7_Pos                                 24          /*!< Seventh byte of data */

/* Bit field masks: */
#define CAN_MODATAH_DB4_Msk                                 0x000000FF  /*!< The fourth data byte */
#define CAN_MODATAH_DB5_Msk                                 0x0000FF00  /*!< Fifth byte data */
#define CAN_MODATAH_DB6_Msk                                 0x00FF0000  /*!< Sixth byte data */
#define CAN_MODATAH_DB7_Msk                                 0xFF000000  /*!< Seventh byte of data */

/*-- MOAR: Register arbitration message object  ------------------------------*/

typedef struct {
  uint32_t ID                                     :29;                  /*!< Object ID message  */
  uint32_t IDE                                    :1;                   /*!< Bit extension identifier of the message object  */
  uint32_t PRI                                    :2;                   /*!< Priority class */
} _CAN_MOAR_bits;

/* Bit field positions: */
#define CAN_MOAR_ID_Pos                                     0           /*!< Object ID message  */
#define CAN_MOAR_IDE_Pos                                    29          /*!< Bit extension identifier of the message object  */
#define CAN_MOAR_PRI_Pos                                    30          /*!< Priority class */

/* Bit field masks: */
#define CAN_MOAR_ID_Msk                                     0x1FFFFFFF  /*!< Object ID message  */
#define CAN_MOAR_IDE_Msk                                    0x20000000  /*!< Bit extension identifier of the message object  */
#define CAN_MOAR_PRI_Msk                                    0xC0000000  /*!< Priority class */

/*-- MOCTR: Control register Message object  ---------------------------------*/

typedef struct {
  uint32_t RESRXPND                               :1;                   /*!< Reset bit RXPND */
  uint32_t RESTXPND                               :1;                   /*!< Reset bit TXPND */
  uint32_t RESRXUPD                               :1;                   /*!< Reset bit RXUPD */
  uint32_t RESNEWDAT                              :1;                   /*!< Reset bit NEWDAT */
  uint32_t RESMSGLST                              :1;                   /*!< Reset bit MSGLST */
  uint32_t RESMSGVAL                              :1;                   /*!< Reset bit MSGVAL */
  uint32_t RESRTSEL                               :1;                   /*!< Reset bit RTSEL */
  uint32_t RESRXEN                                :1;                   /*!< Reset bit RXEN */
  uint32_t RESTXRQ                                :1;                   /*!< Reset bit TXRQ */
  uint32_t RESTXEN0                               :1;                   /*!< Reset bit TXEN0 */
  uint32_t RESTXEN1                               :1;                   /*!< Reset bit TXEN1 */
  uint32_t RESDIR                                 :1;                   /*!< Reset bit DIR */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t SETRXPND                               :1;                   /*!< Set bit RXPND */
  uint32_t SETTXPND                               :1;                   /*!< Set bit TXPND */
  uint32_t SETRXUPD                               :1;                   /*!< Set bit RXUPD */
  uint32_t SETNEWDAT                              :1;                   /*!< Set bit NEWDAT */
  uint32_t SETMSGLST                              :1;                   /*!< Set bit MSGLST */
  uint32_t SETMSGVAL                              :1;                   /*!< Set bit MSGVAL */
  uint32_t SETRTSEL                               :1;                   /*!< Set bit RTSEL */
  uint32_t SETRXEN                                :1;                   /*!< Set bit RXEN */
  uint32_t SETTXRQ                                :1;                   /*!< Set bit TXRQ */
  uint32_t SETTXEN0                               :1;                   /*!< Set bit TXEN0 */
  uint32_t SETTXEN1                               :1;                   /*!< Set bit TXEN1 */
  uint32_t SETDIR                                 :1;                   /*!< Set bit DIR */
  uint32_t Reserved1                              :4;                   /*!< Reserved */
} _CAN_MOCTR_bits;

/* Bit field positions: */
#define CAN_MOCTR_RESRXPND_Pos                              0           /*!< Reset bit RXPND */
#define CAN_MOCTR_RESTXPND_Pos                              1           /*!< Reset bit TXPND */
#define CAN_MOCTR_RESRXUPD_Pos                              2           /*!< Reset bit RXUPD */
#define CAN_MOCTR_RESNEWDAT_Pos                             3           /*!< Reset bit NEWDAT */
#define CAN_MOCTR_RESMSGLST_Pos                             4           /*!< Reset bit MSGLST */
#define CAN_MOCTR_RESMSGVAL_Pos                             5           /*!< Reset bit MSGVAL */
#define CAN_MOCTR_RESRTSEL_Pos                              6           /*!< Reset bit RTSEL */
#define CAN_MOCTR_RESRXEN_Pos                               7           /*!< Reset bit RXEN */
#define CAN_MOCTR_RESTXRQ_Pos                               8           /*!< Reset bit TXRQ */
#define CAN_MOCTR_RESTXEN0_Pos                              9           /*!< Reset bit TXEN0 */
#define CAN_MOCTR_RESTXEN1_Pos                              10          /*!< Reset bit TXEN1 */
#define CAN_MOCTR_RESDIR_Pos                                11          /*!< Reset bit DIR */
#define CAN_MOCTR_SETRXPND_Pos                              16          /*!< Set bit RXPND */
#define CAN_MOCTR_SETTXPND_Pos                              17          /*!< Set bit TXPND */
#define CAN_MOCTR_SETRXUPD_Pos                              18          /*!< Set bit RXUPD */
#define CAN_MOCTR_SETNEWDAT_Pos                             19          /*!< Set bit NEWDAT */
#define CAN_MOCTR_SETMSGLST_Pos                             20          /*!< Set bit MSGLST */
#define CAN_MOCTR_SETMSGVAL_Pos                             21          /*!< Set bit MSGVAL */
#define CAN_MOCTR_SETRTSEL_Pos                              22          /*!< Set bit RTSEL */
#define CAN_MOCTR_SETRXEN_Pos                               23          /*!< Set bit RXEN */
#define CAN_MOCTR_SETTXRQ_Pos                               24          /*!< Set bit TXRQ */
#define CAN_MOCTR_SETTXEN0_Pos                              25          /*!< Set bit TXEN0 */
#define CAN_MOCTR_SETTXEN1_Pos                              26          /*!< Set bit TXEN1 */
#define CAN_MOCTR_SETDIR_Pos                                27          /*!< Set bit DIR */

/* Bit field masks: */
#define CAN_MOCTR_RESRXPND_Msk                              0x00000001  /*!< Reset bit RXPND */
#define CAN_MOCTR_RESTXPND_Msk                              0x00000002  /*!< Reset bit TXPND */
#define CAN_MOCTR_RESRXUPD_Msk                              0x00000004  /*!< Reset bit RXUPD */
#define CAN_MOCTR_RESNEWDAT_Msk                             0x00000008  /*!< Reset bit NEWDAT */
#define CAN_MOCTR_RESMSGLST_Msk                             0x00000010  /*!< Reset bit MSGLST */
#define CAN_MOCTR_RESMSGVAL_Msk                             0x00000020  /*!< Reset bit MSGVAL */
#define CAN_MOCTR_RESRTSEL_Msk                              0x00000040  /*!< Reset bit RTSEL */
#define CAN_MOCTR_RESRXEN_Msk                               0x00000080  /*!< Reset bit RXEN */
#define CAN_MOCTR_RESTXRQ_Msk                               0x00000100  /*!< Reset bit TXRQ */
#define CAN_MOCTR_RESTXEN0_Msk                              0x00000200  /*!< Reset bit TXEN0 */
#define CAN_MOCTR_RESTXEN1_Msk                              0x00000400  /*!< Reset bit TXEN1 */
#define CAN_MOCTR_RESDIR_Msk                                0x00000800  /*!< Reset bit DIR */
#define CAN_MOCTR_SETRXPND_Msk                              0x00010000  /*!< Set bit RXPND */
#define CAN_MOCTR_SETTXPND_Msk                              0x00020000  /*!< Set bit TXPND */
#define CAN_MOCTR_SETRXUPD_Msk                              0x00040000  /*!< Set bit RXUPD */
#define CAN_MOCTR_SETNEWDAT_Msk                             0x00080000  /*!< Set bit NEWDAT */
#define CAN_MOCTR_SETMSGLST_Msk                             0x00100000  /*!< Set bit MSGLST */
#define CAN_MOCTR_SETMSGVAL_Msk                             0x00200000  /*!< Set bit MSGVAL */
#define CAN_MOCTR_SETRTSEL_Msk                              0x00400000  /*!< Set bit RTSEL */
#define CAN_MOCTR_SETRXEN_Msk                               0x00800000  /*!< Set bit RXEN */
#define CAN_MOCTR_SETTXRQ_Msk                               0x01000000  /*!< Set bit TXRQ */
#define CAN_MOCTR_SETTXEN0_Msk                              0x02000000  /*!< Set bit TXEN0 */
#define CAN_MOCTR_SETTXEN1_Msk                              0x04000000  /*!< Set bit TXEN1 */
#define CAN_MOCTR_SETDIR_Msk                                0x08000000  /*!< Set bit DIR */

/*-- MOSTAT: Status register of the message object  --------------------------*/

typedef struct {
  uint32_t RXPND                                  :1;                   /*!< Indicator deadline */
  uint32_t TXPND                                  :1;                   /*!< Indicator end of transmission */
  uint32_t RXUPD                                  :1;                   /*!< Indicator changes */
  uint32_t NEWDAT                                 :1;                   /*!< New data indicator */
  uint32_t MSGLST                                 :1;                   /*!< Bit message loss */
  uint32_t MSGVAL                                 :1;                   /*!< Activity bit of the message object  */
  uint32_t RTSEL                                  :1;                   /*!< The indication of transmission / reception */
  uint32_t RXEN                                   :1;                   /*!< Bits allow reception */
  uint32_t TXRQ                                   :1;                   /*!< Initiate transmission */
  uint32_t TXEN0                                  :1;                   /*!< Enable bit transmission frame */
  uint32_t TXEN1                                  :1;                   /*!< Enable bit transmission frame */
  uint32_t DIR                                    :1;                   /*!< Bit allocation */
  uint32_t LIST                                   :4;                   /*!< Number list  the message object  */
  uint32_t PPREV                                  :8;                   /*!< Pointer to the previous entry */
  uint32_t PNEXT                                  :8;                   /*!< Pointer to the next item in the list */
} _CAN_MOSTAT_bits;

/* Bit field positions: */
#define CAN_MOSTAT_RXPND_Pos                                0           /*!< Indicator deadline */
#define CAN_MOSTAT_TXPND_Pos                                1           /*!< Indicator end of transmission */
#define CAN_MOSTAT_RXUPD_Pos                                2           /*!< Indicator changes */
#define CAN_MOSTAT_NEWDAT_Pos                               3           /*!< New data indicator */
#define CAN_MOSTAT_MSGLST_Pos                               4           /*!< Bit message loss */
#define CAN_MOSTAT_MSGVAL_Pos                               5           /*!< Activity bit of the message object  */
#define CAN_MOSTAT_RTSEL_Pos                                6           /*!< The indication of transmission / reception */
#define CAN_MOSTAT_RXEN_Pos                                 7           /*!< Bits allow reception */
#define CAN_MOSTAT_TXRQ_Pos                                 8           /*!< Initiate transmission */
#define CAN_MOSTAT_TXEN0_Pos                                9           /*!< Enable bit transmission frame */
#define CAN_MOSTAT_TXEN1_Pos                                10          /*!< Enable bit transmission frame */
#define CAN_MOSTAT_DIR_Pos                                  11          /*!< Bit allocation */
#define CAN_MOSTAT_LIST_Pos                                 12          /*!< Number list  the message object  */
#define CAN_MOSTAT_PPREV_Pos                                16          /*!< Pointer to the previous entry */
#define CAN_MOSTAT_PNEXT_Pos                                24          /*!< Pointer to the next item in the list */

/* Bit field masks: */
#define CAN_MOSTAT_RXPND_Msk                                0x00000001  /*!< Indicator deadline */
#define CAN_MOSTAT_TXPND_Msk                                0x00000002  /*!< Indicator end of transmission */
#define CAN_MOSTAT_RXUPD_Msk                                0x00000004  /*!< Indicator changes */
#define CAN_MOSTAT_NEWDAT_Msk                               0x00000008  /*!< New data indicator */
#define CAN_MOSTAT_MSGLST_Msk                               0x00000010  /*!< Bit message loss */
#define CAN_MOSTAT_MSGVAL_Msk                               0x00000020  /*!< Activity bit of the message object  */
#define CAN_MOSTAT_RTSEL_Msk                                0x00000040  /*!< The indication of transmission / reception */
#define CAN_MOSTAT_RXEN_Msk                                 0x00000080  /*!< Bits allow reception */
#define CAN_MOSTAT_TXRQ_Msk                                 0x00000100  /*!< Initiate transmission */
#define CAN_MOSTAT_TXEN0_Msk                                0x00000200  /*!< Enable bit transmission frame */
#define CAN_MOSTAT_TXEN1_Msk                                0x00000400  /*!< Enable bit transmission frame */
#define CAN_MOSTAT_DIR_Msk                                  0x00000800  /*!< Bit allocation */
#define CAN_MOSTAT_LIST_Msk                                 0x0000F000  /*!< Number list  the message object  */
#define CAN_MOSTAT_PPREV_Msk                                0x00FF0000  /*!< Pointer to the previous entry */
#define CAN_MOSTAT_PNEXT_Msk                                0xFF000000  /*!< Pointer to the next item in the list */

/*-- Register map for CAN peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Register control node */
    __IO uint32_t NCR;                                                  /*!< NCR    : type used for word access */
    __IO _CAN_NCR_bits NCR_bit;                                         /*!< NCR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register state node */
    __IO uint32_t NSR;                                                  /*!< NSR    : type used for word access */
    __IO _CAN_NSR_bits NSR_bit;                                         /*!< NSR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt pointer register node */
    __IO uint32_t NIPR;                                                 /*!< NIPR    : type used for word access */
    __IO _CAN_NIPR_bits NIPR_bit;                                       /*!< NIPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Port control register node */
    __IO uint32_t NPCR;                                                 /*!< NPCR    : type used for word access */
    __IO _CAN_NPCR_bits NPCR_bit;                                       /*!< NPCR_bit: structure used for bit access */
  };
  union {                                                               /*!< Timing register bits  */
    __IO uint32_t NBTR;                                                 /*!< NBTR    : type used for word access */
    __IO _CAN_NBTR_bits NBTR_bit;                                       /*!< NBTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter error register node */
    __IO uint32_t NECNT;                                                /*!< NECNT    : type used for word access */
    __IO _CAN_NECNT_bits NECNT_bit;                                     /*!< NECNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Register message counter node */
    __IO uint32_t NFCR;                                                 /*!< NFCR    : type used for word access */
    __IO _CAN_NFCR_bits NFCR_bit;                                       /*!< NFCR_bit: structure used for bit access */
  };
  uint32_t Reserved0[57];                                               /*!< Reserved */
} NT_CAN_Node_TypeDef;

typedef struct {
  union {                                                               /*!< Register control the operation of the message object  */
    __IO uint32_t MOFCR;                                                /*!< MOFCR    : type used for word access */
    __IO _CAN_MOFCR_bits MOFCR_bit;                                     /*!< MOFCR_bit: structure used for bit access */
  };
  union {                                                               /*!< Pointer register FIFO / gateway message object  */
    __IO uint32_t MOFGPR;                                               /*!< MOFGPR    : type used for word access */
    __IO _CAN_MOFGPR_bits MOFGPR_bit;                                   /*!< MOFGPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Pointer register interrupt message object  */
    __IO uint32_t MOIPR;                                                /*!< MOIPR    : type used for word access */
    __IO _CAN_MOIPR_bits MOIPR_bit;                                     /*!< MOIPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Mask register message object  */
    __IO uint32_t MOAMR;                                                /*!< MOAMR    : type used for word access */
    __IO _CAN_MOAMR_bits MOAMR_bit;                                     /*!< MOAMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Low data registers of the message object  */
    __IO uint32_t MODATAL;                                              /*!< MODATAL    : type used for word access */
    __IO _CAN_MODATAL_bits MODATAL_bit;                                 /*!< MODATAL_bit: structure used for bit access */
  };
  union {                                                               /*!< High data registers of the message object  */
    __IO uint32_t MODATAH;                                              /*!< MODATAH    : type used for word access */
    __IO _CAN_MODATAH_bits MODATAH_bit;                                 /*!< MODATAH_bit: structure used for bit access */
  };
  union {                                                               /*!< Register arbitration message object  */
    __IO uint32_t MOAR;                                                 /*!< MOAR    : type used for word access */
    __IO _CAN_MOAR_bits MOAR_bit;                                       /*!< MOAR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register Message object  */
    __O  uint32_t MOCTR;                                                /*!< MOCTR    : type used for word access */
    __O  _CAN_MOCTR_bits MOCTR_bit;                                     /*!< MOCTR_bit: structure used for bit access */
                                                                        /*!< Status register of the message object  */
    __I  uint32_t MOSTAT;                                               /*!< MOSTAT    : type used for word access */
    __I  _CAN_MOSTAT_bits MOSTAT_bit;                                   /*!< MOSTAT_bit: structure used for bit access */
  };
} NT_CAN_Msg_TypeDef;

typedef struct {
  union {                                                               /*!< Frequency control register */
    __IO uint32_t CLC;                                                  /*!< CLC    : type used for word access */
    __IO _CAN_CLC_bits CLC_bit;                                         /*!< CLC_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< Identity register */
    __IO uint32_t ID;                                                   /*!< ID    : type used for word access */
    __IO _CAN_ID_bits ID_bit;                                           /*!< ID_bit: structure used for bit access */
  };
  union {                                                               /*!< Register divider */
    __IO uint32_t FDR;                                                  /*!< FDR    : type used for word access */
    __IO _CAN_FDR_bits FDR_bit;                                         /*!< FDR_bit: structure used for bit access */
  };
  uint32_t Reserved1[60];                                               /*!< Reserved */
  union {                                                               /*!< Register list */
    __I  uint32_t LIST[8];                                              /*!< LIST    : type used for word access */
    __I  _CAN_LIST_bits LIST_bit[8];                                    /*!< LIST_bit: structure used for bit access */
  };
  uint32_t Reserved2[8];                                                /*!< Reserved */
  __IO uint32_t MSPND[8];                                               /*!< Register waiting interrupts */
  uint32_t Reserved3[8];                                                /*!< Reserved */
  union {                                                               /*!< Register messages index */
    __I  uint32_t MSID[8];                                              /*!< MSID    : type used for word access */
    __I  _CAN_MSID_bits MSID_bit[8];                                    /*!< MSID_bit: structure used for bit access */
  };
  uint32_t Reserved4[8];                                                /*!< Reserved */
  __IO uint32_t MSIMASK;                                                /*!< Mask register message index */
  union {                                                               /*!< Register command panel */
    __IO uint32_t PANCTR;                                               /*!< PANCTR    : type used for word access */
    __IO _CAN_PANCTR_bits PANCTR_bit;                                   /*!< PANCTR_bit: structure used for bit access */
  };
  union {                                                               /*!<  */
    __IO uint32_t MCR_REG;                                              /*!< MCR_REG    : type used for word access */
    __IO _CAN_MCR_REG_bits MCR_REG_bit;                                 /*!< MCR_REG_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt register */
    __O  uint32_t MITR;                                                 /*!< MITR    : type used for word access */
    __O  _CAN_MITR_bits MITR_bit;                                       /*!< MITR_bit: structure used for bit access */
  };
  uint32_t Reserved5[12];                                               /*!< Reserved */
  NT_CAN_Node_TypeDef CAN_Node[2];
  uint32_t Reserved6[768];                                              /*!< Reserved */
  NT_CAN_Msg_TypeDef CAN_Msg[256];
} NT_CAN_TypeDef;

/******************************************************************************/
/*                      ETHERNET controller registers                         */
/******************************************************************************/

/*-- MAC1: MAC configuration register 1 --------------------------------------*/

typedef struct {
  uint32_t RXENABLE                               :1;                   /*!< Frame reception enable bit */
  uint32_t PASSALL                                :1;                   /*!< Bit control PASS */
  uint32_t RXPAUSE                                :1;                   /*!< Enable receiving a pause as part of Frame */
  uint32_t TXPAUSE                                :1;                   /*!< Enable transmission pauses Frame */
  uint32_t LOOPBACK                               :1;                   /*!< Bit activate reception of packets transmitted back through MACReceive-interface */
  uint32_t Reserved0                              :3;                   /*!< Reserved */
  uint32_t RESETTFUN                              :1;                   /*!< Reset bit logic devices packet */
  uint32_t RESETTMCS                              :1;                   /*!< Reset bit device MAC layer, responsible for managing addresses in information transmission Reset bit device MAC layer, responsible for managing addresses in information transmission */
  uint32_t RESETRFUN                              :1;                   /*!< Reset bit logic devices receive packets */
  uint32_t RESETRMCS                              :1;                   /*!< Reset bit device MAC layer, responsible for managing the filtering addresses of packets received */
  uint32_t Reserved1                              :2;                   /*!< Reserved */
  uint32_t SIMRESET                               :1;                   /*!< Reset bit random number generator transmitting device */
  uint32_t SOFTRESET                              :1;                   /*!< Reset bit block MAC Ethernet Controller */
  uint32_t Reserved2                              :16;                  /*!< Reserved */
} _ETHERNET_MAC1_bits;

/* Bit field positions: */
#define ETHERNET_MAC1_RXENABLE_Pos                          0           /*!< Frame reception enable bit */
#define ETHERNET_MAC1_PASSALL_Pos                           1           /*!< Bit control PASS */
#define ETHERNET_MAC1_RXPAUSE_Pos                           2           /*!< Enable receiving a pause as part of Frame */
#define ETHERNET_MAC1_TXPAUSE_Pos                           3           /*!< Enable transmission pauses Frame */
#define ETHERNET_MAC1_LOOPBACK_Pos                          4           /*!< Bit activate reception of packets transmitted back through MACReceive-interface */
#define ETHERNET_MAC1_RESETTFUN_Pos                         8           /*!< Reset bit logic devices packet */
#define ETHERNET_MAC1_RESETTMCS_Pos                         9           /*!< Reset bit device MAC layer, responsible for managing addresses in information transmission Reset bit device MAC layer, responsible for managing addresses in information transmission */
#define ETHERNET_MAC1_RESETRFUN_Pos                         10          /*!< Reset bit logic devices receive packets */
#define ETHERNET_MAC1_RESETRMCS_Pos                         11          /*!< Reset bit device MAC layer, responsible for managing the filtering addresses of packets received */
#define ETHERNET_MAC1_SIMRESET_Pos                          14          /*!< Reset bit random number generator transmitting device */
#define ETHERNET_MAC1_SOFTRESET_Pos                         15          /*!< Reset bit block MAC Ethernet Controller */

/* Bit field masks: */
#define ETHERNET_MAC1_RXENABLE_Msk                          0x00000001  /*!< Frame reception enable bit */
#define ETHERNET_MAC1_PASSALL_Msk                           0x00000002  /*!< Bit control PASS */
#define ETHERNET_MAC1_RXPAUSE_Msk                           0x00000004  /*!< Enable receiving a pause as part of Frame */
#define ETHERNET_MAC1_TXPAUSE_Msk                           0x00000008  /*!< Enable transmission pauses Frame */
#define ETHERNET_MAC1_LOOPBACK_Msk                          0x00000010  /*!< Bit activate reception of packets transmitted back through MACReceive-interface */
#define ETHERNET_MAC1_RESETTFUN_Msk                         0x00000100  /*!< Reset bit logic devices packet */
#define ETHERNET_MAC1_RESETTMCS_Msk                         0x00000200  /*!< Reset bit device MAC layer, responsible for managing addresses in information transmission Reset bit device MAC layer, responsible for managing addresses in information transmission */
#define ETHERNET_MAC1_RESETRFUN_Msk                         0x00000400  /*!< Reset bit logic devices receive packets */
#define ETHERNET_MAC1_RESETRMCS_Msk                         0x00000800  /*!< Reset bit device MAC layer, responsible for managing the filtering addresses of packets received */
#define ETHERNET_MAC1_SIMRESET_Msk                          0x00004000  /*!< Reset bit random number generator transmitting device */
#define ETHERNET_MAC1_SOFTRESET_Msk                         0x00008000  /*!< Reset bit block MAC Ethernet Controller */

/*-- MAC2: MAC configuration register 2 --------------------------------------*/

typedef struct {
  uint32_t FULLDUPLEX                             :1;                   /*!< Mode Select bit MAC-run operations */
  uint32_t LENGTHCHECK                            :1;                   /*!< Enable bit komparatsii length Frame */
  uint32_t HUGEFRAME                              :1;                   /*!< Enable Bit Frame reception and transmission of arbitrary length */
  uint32_t DALAYCRC                               :1;                   /*!< Enable bit adding a 4-byte CRC */
  uint32_t CRCENABLE                              :1;                   /*!< Enable bit CRC inserter */
  uint32_t PADENABLE                              :1;                   /*!< Bit resolution and functioning bits AUTOPAD VLANPAD */
  uint32_t VLANPAD                                :1;                   /*!< Enable bit short additions Frame */
  uint32_t AUTOPAD                                :1;                   /*!< Bit enable automatic determination of type Frame */
  uint32_t PUREPRE                                :1;                   /*!< Bit enable validation preamble */
  uint32_t LONGPRE                                :1;                   /*!< Select bit preamble length packets received */
  uint32_t Reserved0                              :2;                   /*!< Reserved */
  uint32_t NOBACKOFF                              :1;                   /*!< Bit parameter setting retransmission in conflict */
  uint32_t BP_NOBACKOFF                           :1;                   /*!< Enable bit retransmission in conflict */
  uint32_t EXCESSDEF                              :1;                   /*!< Mode Select bit packet processing */
  uint32_t Reserved1                              :17;                  /*!< Reserved */
} _ETHERNET_MAC2_bits;

/* Bit field positions: */
#define ETHERNET_MAC2_FULLDUPLEX_Pos                        0           /*!< Mode Select bit MAC-run operations */
#define ETHERNET_MAC2_LENGTHCHECK_Pos                       1           /*!< Enable bit komparatsii length Frame */
#define ETHERNET_MAC2_HUGEFRAME_Pos                         2           /*!< Enable Bit Frame reception and transmission of arbitrary length */
#define ETHERNET_MAC2_DALAYCRC_Pos                          3           /*!< Enable bit adding a 4-byte CRC */
#define ETHERNET_MAC2_CRCENABLE_Pos                         4           /*!< Enable bit CRC inserter */
#define ETHERNET_MAC2_PADENABLE_Pos                         5           /*!< Bit resolution and functioning bits AUTOPAD VLANPAD */
#define ETHERNET_MAC2_VLANPAD_Pos                           6           /*!< Enable bit short additions Frame */
#define ETHERNET_MAC2_AUTOPAD_Pos                           7           /*!< Bit enable automatic determination of type Frame */
#define ETHERNET_MAC2_PUREPRE_Pos                           8           /*!< Bit enable validation preamble */
#define ETHERNET_MAC2_LONGPRE_Pos                           9           /*!< Select bit preamble length packets received */
#define ETHERNET_MAC2_NOBACKOFF_Pos                         12          /*!< Bit parameter setting retransmission in conflict */
#define ETHERNET_MAC2_BP_NOBACKOFF_Pos                      13          /*!< Enable bit retransmission in conflict */
#define ETHERNET_MAC2_EXCESSDEF_Pos                         14          /*!< Mode Select bit packet processing */

/* Bit field masks: */
#define ETHERNET_MAC2_FULLDUPLEX_Msk                        0x00000001  /*!< Mode Select bit MAC-run operations */
#define ETHERNET_MAC2_LENGTHCHECK_Msk                       0x00000002  /*!< Enable bit komparatsii length Frame */
#define ETHERNET_MAC2_HUGEFRAME_Msk                         0x00000004  /*!< Enable Bit Frame reception and transmission of arbitrary length */
#define ETHERNET_MAC2_DALAYCRC_Msk                          0x00000008  /*!< Enable bit adding a 4-byte CRC */
#define ETHERNET_MAC2_CRCENABLE_Msk                         0x00000010  /*!< Enable bit CRC inserter */
#define ETHERNET_MAC2_PADENABLE_Msk                         0x00000020  /*!< Bit resolution and functioning bits AUTOPAD VLANPAD */
#define ETHERNET_MAC2_VLANPAD_Msk                           0x00000040  /*!< Enable bit short additions Frame */
#define ETHERNET_MAC2_AUTOPAD_Msk                           0x00000080  /*!< Bit enable automatic determination of type Frame */
#define ETHERNET_MAC2_PUREPRE_Msk                           0x00000100  /*!< Bit enable validation preamble */
#define ETHERNET_MAC2_LONGPRE_Msk                           0x00000200  /*!< Select bit preamble length packets received */
#define ETHERNET_MAC2_NOBACKOFF_Msk                         0x00001000  /*!< Bit parameter setting retransmission in conflict */
#define ETHERNET_MAC2_BP_NOBACKOFF_Msk                      0x00002000  /*!< Enable bit retransmission in conflict */
#define ETHERNET_MAC2_EXCESSDEF_Msk                         0x00004000  /*!< Mode Select bit packet processing */

/*-- IPGT: Register Back-to-Back Inter-Packet-Gap ----------------------------*/

typedef struct {
  uint32_t BTBIPG_TRANS                           :7;                   /*!< Field specifying the minimum time between the end of transmission of the last nibble packet before transmission of the next packet */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _ETHERNET_IPGT_bits;

/* Bit field positions: */
#define ETHERNET_IPGT_BTBIPG_TRANS_Pos                      0           /*!< Field specifying the minimum time between the end of transmission of the last nibble packet before transmission of the next packet */

/* Bit field masks: */
#define ETHERNET_IPGT_BTBIPG_TRANS_Msk                      0x0000007F  /*!< Field specifying the minimum time between the end of transmission of the last nibble packet before transmission of the next packet */

/*-- IPGR: Register Non-Back-to-Back Inter-Packet-Gap ------------------------*/

typedef struct {
  uint32_t NBTBIPG_TRANS_PART2                    :7;                   /*!< non-back-to-back Inter-Packet-Gap */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t NBTBIPG_TRANS_PART1                    :7;                   /*!< Option carrierSense */
  uint32_t Reserved1                              :17;                  /*!< Reserved */
} _ETHERNET_IPGR_bits;

/* Bit field positions: */
#define ETHERNET_IPGR_NBTBIPG_TRANS_PART2_Pos               0           /*!< non-back-to-back Inter-Packet-Gap */
#define ETHERNET_IPGR_NBTBIPG_TRANS_PART1_Pos               8           /*!< Option carrierSense */

/* Bit field masks: */
#define ETHERNET_IPGR_NBTBIPG_TRANS_PART2_Msk               0x0000007F  /*!< non-back-to-back Inter-Packet-Gap */
#define ETHERNET_IPGR_NBTBIPG_TRANS_PART1_Msk               0x00007F00  /*!< Option carrierSense */

/*-- CLRT: Register collision window -----------------------------------------*/

typedef struct {
  uint32_t RETRANS_MAX                            :4;
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t COLLISION_WINDOW                       :6;
  uint32_t Reserved1                              :18;                  /*!< Reserved */
} _ETHERNET_CLRT_bits;

/* Bit field positions: */
#define ETHERNET_CLRT_RETRANS_MAX_Pos                       0
#define ETHERNET_CLRT_COLLISION_WINDOW_Pos                  8

/* Bit field masks: */
#define ETHERNET_CLRT_RETRANS_MAX_Msk                       0x0000000F
#define ETHERNET_CLRT_COLLISION_WINDOW_Msk                  0x00003F00

/*-- MAXF: Register the upper limit size Frame -------------------------------*/

typedef struct {
  uint32_t MAXFRAME_LENGTH                        :16;                  /*!< Frame maximum length */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ETHERNET_MAXF_bits;

/* Bit field positions: */
#define ETHERNET_MAXF_MAXFRAME_LENGTH_Pos                   0           /*!< Frame maximum length */

/* Bit field masks: */
#define ETHERNET_MAXF_MAXFRAME_LENGTH_Msk                   0x0000FFFF  /*!< Frame maximum length */

/*-- SUPP: Register PHY-support interface ------------------------------------*/

typedef struct {
  uint32_t BITMODE                                :1;                   /*!< Activated mode 10BASE-T ENDEC */
  uint32_t ENBLJABBER                             :1;                   /*!< Enable bit of protection against incorrect data transmission mode 10T ENDEC */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t RESET10T                               :1;                   /*!< Reset bit module, which converts the MII nibble streams into a serial bit stream mode transceiver 10T */
  uint32_t LINKFAIL                               :1;                   /*!< Bit resolution modeling */
  uint32_t NOCIPHER                               :1;                   /*!< Select encryption */
  uint32_t FORCEQUIET                             :1;                   /*!< enable encryption */
  uint32_t RESET100X                              :1;                   /*!< Reset bit of the module that contains the logic of the encoder / decoder bit characters 4/5 bits */
  uint32_t SPEED                                  :1;                   /*!< Bits set the operating speed simplified MII */
  uint32_t Reserved1                              :2;                   /*!< Reserved */
  uint32_t RESETRMII                              :1;                   /*!< Reset bit simplified logic MII */
  uint32_t PHYMODE                                :1;                   /*!< Bit configuration consistent with MI SMII-connected devices */
  uint32_t Reserved2                              :2;                   /*!< Reserved */
  uint32_t RESETINT                               :1;                   /*!< Reset bit of the physical interface */
  uint32_t Reserved3                              :16;                  /*!< Reserved */
} _ETHERNET_SUPP_bits;

/* Bit field positions: */
#define ETHERNET_SUPP_BITMODE_Pos                           0           /*!< Activated mode 10BASE-T ENDEC */
#define ETHERNET_SUPP_ENBLJABBER_Pos                        1           /*!< Enable bit of protection against incorrect data transmission mode 10T ENDEC */
#define ETHERNET_SUPP_RESET10T_Pos                          3           /*!< Reset bit module, which converts the MII nibble streams into a serial bit stream mode transceiver 10T */
#define ETHERNET_SUPP_LINKFAIL_Pos                          4           /*!< Bit resolution modeling */
#define ETHERNET_SUPP_NOCIPHER_Pos                          5           /*!< Select encryption */
#define ETHERNET_SUPP_FORCEQUIET_Pos                        6           /*!< enable encryption */
#define ETHERNET_SUPP_RESET100X_Pos                         7           /*!< Reset bit of the module that contains the logic of the encoder / decoder bit characters 4/5 bits */
#define ETHERNET_SUPP_SPEED_Pos                             8           /*!< Bits set the operating speed simplified MII */
#define ETHERNET_SUPP_RESETRMII_Pos                         11          /*!< Reset bit simplified logic MII */
#define ETHERNET_SUPP_PHYMODE_Pos                           12          /*!< Bit configuration consistent with MI SMII-connected devices */
#define ETHERNET_SUPP_RESETINT_Pos                          15          /*!< Reset bit of the physical interface */

/* Bit field masks: */
#define ETHERNET_SUPP_BITMODE_Msk                           0x00000001  /*!< Activated mode 10BASE-T ENDEC */
#define ETHERNET_SUPP_ENBLJABBER_Msk                        0x00000002  /*!< Enable bit of protection against incorrect data transmission mode 10T ENDEC */
#define ETHERNET_SUPP_RESET10T_Msk                          0x00000008  /*!< Reset bit module, which converts the MII nibble streams into a serial bit stream mode transceiver 10T */
#define ETHERNET_SUPP_LINKFAIL_Msk                          0x00000010  /*!< Bit resolution modeling */
#define ETHERNET_SUPP_NOCIPHER_Msk                          0x00000020  /*!< Select encryption */
#define ETHERNET_SUPP_FORCEQUIET_Msk                        0x00000040  /*!< enable encryption */
#define ETHERNET_SUPP_RESET100X_Msk                         0x00000080  /*!< Reset bit of the module that contains the logic of the encoder / decoder bit characters 4/5 bits */
#define ETHERNET_SUPP_SPEED_Msk                             0x00000100  /*!< Bits set the operating speed simplified MII */
#define ETHERNET_SUPP_RESETRMII_Msk                         0x00000800  /*!< Reset bit simplified logic MII */
#define ETHERNET_SUPP_PHYMODE_Msk                           0x00001000  /*!< Bit configuration consistent with MI SMII-connected devices */
#define ETHERNET_SUPP_RESETINT_Msk                          0x00008000  /*!< Reset bit of the physical interface */

/*-- MCFG: Configuration control register MII --------------------------------*/

typedef struct {
  uint32_t SCANINC                                :1;                   /*!< Reading module addresses all MII PHY */
  uint32_t NOPRE                                  :1;                   /*!< Control bit preamble */
  uint32_t CLOCK_SELECT                           :3;                   /*!< Selection field frequency divider */
  uint32_t Reserved0                              :10;                  /*!< Reserved */
  uint32_t RESETMGMT                              :1;                   /*!< Reset bit MII management module */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _ETHERNET_MCFG_bits;

/* Bit field positions: */
#define ETHERNET_MCFG_SCANINC_Pos                           0           /*!< Reading module addresses all MII PHY */
#define ETHERNET_MCFG_NOPRE_Pos                             1           /*!< Control bit preamble */
#define ETHERNET_MCFG_CLOCK_SELECT_Pos                      2           /*!< Selection field frequency divider */
#define ETHERNET_MCFG_RESETMGMT_Pos                         15          /*!< Reset bit MII management module */

/* Bit field masks: */
#define ETHERNET_MCFG_SCANINC_Msk                           0x00000001  /*!< Reading module addresses all MII PHY */
#define ETHERNET_MCFG_NOPRE_Msk                             0x00000002  /*!< Control bit preamble */
#define ETHERNET_MCFG_CLOCK_SELECT_Msk                      0x0000001C  /*!< Selection field frequency divider */
#define ETHERNET_MCFG_RESETMGMT_Msk                         0x00008000  /*!< Reset bit MII management module */

/*-- MCMD: Command register MII ----------------------------------------------*/

typedef struct {
  uint32_t READ                                   :1;                   /*!< Single execution of read cycles */
  uint32_t SCAN                                   :1;                   /*!< Continuous performance of read cycles */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _ETHERNET_MCMD_bits;

/* Bit field positions: */
#define ETHERNET_MCMD_READ_Pos                              0           /*!< Single execution of read cycles */
#define ETHERNET_MCMD_SCAN_Pos                              1           /*!< Continuous performance of read cycles */

/* Bit field masks: */
#define ETHERNET_MCMD_READ_Msk                              0x00000001  /*!< Single execution of read cycles */
#define ETHERNET_MCMD_SCAN_Msk                              0x00000002  /*!< Continuous performance of read cycles */

/*-- MADR: MII address register ----------------------------------------------*/

typedef struct {
  uint32_t REG_ADDRESS                            :5;                   /*!< The 5-bit register address PHY-device */
  uint32_t Reserved0                              :3;                   /*!< Reserved */
  uint32_t PHY_ADDRESS                            :5;                   /*!< The 5-bit address PHY-device */
  uint32_t Reserved1                              :19;                  /*!< Reserved */
} _ETHERNET_MADR_bits;

/* Bit field positions: */
#define ETHERNET_MADR_REG_ADDRESS_Pos                       0           /*!< The 5-bit register address PHY-device */
#define ETHERNET_MADR_PHY_ADDRESS_Pos                       8           /*!< The 5-bit address PHY-device */

/* Bit field masks: */
#define ETHERNET_MADR_REG_ADDRESS_Msk                       0x0000001F  /*!< The 5-bit register address PHY-device */
#define ETHERNET_MADR_PHY_ADDRESS_Msk                       0x00001F00  /*!< The 5-bit address PHY-device */

/*-- MWTD: Register data written in MII --------------------------------------*/

typedef struct {
  uint32_t WRITE_DATA                             :16;                  /*!< Field data */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ETHERNET_MWTD_bits;

/* Bit field positions: */
#define ETHERNET_MWTD_WRITE_DATA_Pos                        0           /*!< Field data */

/* Bit field masks: */
#define ETHERNET_MWTD_WRITE_DATA_Msk                        0x0000FFFF  /*!< Field data */

/*-- MRDD: Register read data from MII ---------------------------------------*/

typedef struct {
  uint32_t READ_DATA                              :16;                  /*!< After reading the control module of the MII PHY-device */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ETHERNET_MRDD_bits;

/* Bit field positions: */
#define ETHERNET_MRDD_READ_DATA_Pos                         0           /*!< After reading the control module of the MII PHY-device */

/* Bit field masks: */
#define ETHERNET_MRDD_READ_DATA_Msk                         0x0000FFFF  /*!< After reading the control module of the MII PHY-device */

/*-- MIND: MII status register flags -----------------------------------------*/

typedef struct {
  uint32_t BUSY                                   :1;                   /*!< Flag continuing cycle of the read / write control MII */
  uint32_t SCAN                                   :1;                   /*!< Flag ongoing scan operation (continue reading cycles control MII) */
  uint32_t NOTVALID                               :1;                   /*!< Flag unfinished read cycle MII (inaccessibility of data to be read) */
  uint32_t LINKFAIL                               :1;                   /*!< Failure flag control MII (PHY device management) */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _ETHERNET_MIND_bits;

/* Bit field positions: */
#define ETHERNET_MIND_BUSY_Pos                              0           /*!< Flag continuing cycle of the read / write control MII */
#define ETHERNET_MIND_SCAN_Pos                              1           /*!< Flag ongoing scan operation (continue reading cycles control MII) */
#define ETHERNET_MIND_NOTVALID_Pos                          2           /*!< Flag unfinished read cycle MII (inaccessibility of data to be read) */
#define ETHERNET_MIND_LINKFAIL_Pos                          3           /*!< Failure flag control MII (PHY device management) */

/* Bit field masks: */
#define ETHERNET_MIND_BUSY_Msk                              0x00000001  /*!< Flag continuing cycle of the read / write control MII */
#define ETHERNET_MIND_SCAN_Msk                              0x00000002  /*!< Flag ongoing scan operation (continue reading cycles control MII) */
#define ETHERNET_MIND_NOTVALID_Msk                          0x00000004  /*!< Flag unfinished read cycle MII (inaccessibility of data to be read) */
#define ETHERNET_MIND_LINKFAIL_Msk                          0x00000008  /*!< Failure flag control MII (PHY device management) */

/*-- SMII: MII controller status register ------------------------------------*/

typedef struct {
  uint32_t SPEED                                  :1;                   /*!< Speed Indicator */
  uint32_t DUPLEX                                 :1;                   /*!< Mode indicator */
  uint32_t LINK                                   :1;                   /*!< Status Indicator LINK */
  uint32_t JABBER                                 :1;                   /*!< Flag of conditions Jabber */
  uint32_t CLASH                                  :1;                   /*!< Flag of the selected mode */
  uint32_t Reserved0                              :27;                  /*!< Reserved */
} _ETHERNET_SMII_bits;

/* Bit field positions: */
#define ETHERNET_SMII_SPEED_Pos                             0           /*!< Speed Indicator */
#define ETHERNET_SMII_DUPLEX_Pos                            1           /*!< Mode indicator */
#define ETHERNET_SMII_LINK_Pos                              2           /*!< Status Indicator LINK */
#define ETHERNET_SMII_JABBER_Pos                            3           /*!< Flag of conditions Jabber */
#define ETHERNET_SMII_CLASH_Pos                             4           /*!< Flag of the selected mode */

/* Bit field masks: */
#define ETHERNET_SMII_SPEED_Msk                             0x00000001  /*!< Speed Indicator */
#define ETHERNET_SMII_DUPLEX_Msk                            0x00000002  /*!< Mode indicator */
#define ETHERNET_SMII_LINK_Msk                              0x00000004  /*!< Status Indicator LINK */
#define ETHERNET_SMII_JABBER_Msk                            0x00000008  /*!< Flag of conditions Jabber */
#define ETHERNET_SMII_CLASH_Msk                             0x00000010  /*!< Flag of the selected mode */

/*-- FIFOCFG: MIIFIFO configurate register -----------------------------------*/

typedef struct {
  uint32_t RST                                    :5;                   /*!< Reset MIIFIFO */
  uint32_t Reserved0                              :3;                   /*!< Reserved */
  uint32_t ENREQ                                  :5;                   /*!< Enable request MIIFIFO */
  uint32_t Reserved1                              :3;                   /*!< Reserved */
  uint32_t ENRPLY                                 :5;                   /*!< Indicate enable MIIFIFO */
  uint32_t Reserved2                              :11;                  /*!< Reserved */
} _ETHERNET_FIFOCFG_bits;

/* Bit field positions: */
#define ETHERNET_FIFOCFG_RST_Pos                            0           /*!< Reset MIIFIFO */
#define ETHERNET_FIFOCFG_ENREQ_Pos                          8           /*!< Enable request MIIFIFO */
#define ETHERNET_FIFOCFG_ENRPLY_Pos                         16          /*!< Indicate enable MIIFIFO */

/* Bit field masks: */
#define ETHERNET_FIFOCFG_RST_Msk                            0x0000001F  /*!< Reset MIIFIFO */
#define ETHERNET_FIFOCFG_ENREQ_Msk                          0x00001F00  /*!< Enable request MIIFIFO */
#define ETHERNET_FIFOCFG_ENRPLY_Msk                         0x001F0000  /*!< Indicate enable MIIFIFO */

/*-- SA0: Station address register 0 -----------------------------------------*/

typedef struct {
  uint32_t STATION_ADDRESS_2B                     :8;                   /*!< 2nd octet of the station address */
  uint32_t STATION_ADDRESS_1B                     :8;                   /*!< 1st octet of the station address */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ETHERNET_SA0_bits;

/* Bit field positions: */
#define ETHERNET_SA0_STATION_ADDRESS_2B_Pos                 0           /*!< 2nd octet of the station address */
#define ETHERNET_SA0_STATION_ADDRESS_1B_Pos                 8           /*!< 1st octet of the station address */

/* Bit field masks: */
#define ETHERNET_SA0_STATION_ADDRESS_2B_Msk                 0x000000FF  /*!< 2nd octet of the station address */
#define ETHERNET_SA0_STATION_ADDRESS_1B_Msk                 0x0000FF00  /*!< 1st octet of the station address */

/*-- SA1: Station address register 1 -----------------------------------------*/

typedef struct {
  uint32_t STATION_ADDRESS_4B                     :8;                   /*!< 4th octet of the station address */
  uint32_t STATION_ADDRESS_3B                     :8;                   /*!< The third octet of the station address */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ETHERNET_SA1_bits;

/* Bit field positions: */
#define ETHERNET_SA1_STATION_ADDRESS_4B_Pos                 0           /*!< 4th octet of the station address */
#define ETHERNET_SA1_STATION_ADDRESS_3B_Pos                 8           /*!< The third octet of the station address */

/* Bit field masks: */
#define ETHERNET_SA1_STATION_ADDRESS_4B_Msk                 0x000000FF  /*!< 4th octet of the station address */
#define ETHERNET_SA1_STATION_ADDRESS_3B_Msk                 0x0000FF00  /*!< The third octet of the station address */

/*-- SA2: Station address register 2 -----------------------------------------*/

typedef struct {
  uint32_t STATION_ADDRESS_6B                     :8;                   /*!< 6th octet station */
  uint32_t STATION_ADDRESS_5B                     :8;                   /*!< 5th octet station */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _ETHERNET_SA2_bits;

/* Bit field positions: */
#define ETHERNET_SA2_STATION_ADDRESS_6B_Pos                 0           /*!< 6th octet station */
#define ETHERNET_SA2_STATION_ADDRESS_5B_Pos                 8           /*!< 5th octet station */

/* Bit field masks: */
#define ETHERNET_SA2_STATION_ADDRESS_6B_Msk                 0x000000FF  /*!< 6th octet station */
#define ETHERNET_SA2_STATION_ADDRESS_5B_Msk                 0x0000FF00  /*!< 5th octet station */

/*-- DMATxCtrl: Reception control register -----------------------------------*/

typedef struct {
  uint32_t TXENABLE                               :1;
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _ETHERNET_DMATxCtrl_bits;

/* Bit field positions: */
#define ETHERNET_DMATxCtrl_TXENABLE_Pos                     0

/* Bit field masks: */
#define ETHERNET_DMATxCtrl_TXENABLE_Msk                     0x00000001

/*-- DMATxDescriptor: Reception control register -----------------------------------*/

typedef struct {
  uint32_t DADDR                              :32;
} _ETHERNET_DMATxDescriptor_bits;

/* Bit field positions: */
#define ETHERNET_DMATxDescriptor_DADDR_Pos                     0

/* Bit field masks: */
#define ETHERNET_DMATxDescriptor_DADDR_Msk                     0xFFFFFFFF

/*-- DMATxStatus: Reception control register -----------------------------------*/

typedef struct {
  uint32_t TXPKTREC                              :1;
  uint32_t Reserved0                             :1;
  uint32_t TXOVERFLOW                            :1;
  uint32_t BUSERROR                              :1;
  uint32_t Reserved1                             :12;
  uint32_t TX_PKT_COUNT                          :8;
  uint32_t Reserved2                             :8;
} _ETHERNET_DMATxStatus_bits;

/* Bit field positions: */
#define ETHERNET_DMATxStatus_TXPKTREC_Pos                     0
#define ETHERNET_DMATxStatus_TXOVERFLOW_Pos                   2
#define ETHERNET_DMATxStatus_BUSERROR_Pos                     3
#define ETHERNET_DMATxStatus_TX_PKT_COUNT_Pos                 16

/* Bit field masks: */
#define ETHERNET_DMATxStatus_TXPKTREC_Msk                     0x00000001
#define ETHERNET_DMATxStatus_TXOVERFLOW_Msk                   0x00000002
#define ETHERNET_DMATxStatus_BUSERROR_Msk                     0x00000004
#define ETHERNET_DMATxStatus_TX_PKT_COUNT_Msk                 0x00FF0000

/*-- DMARxCtrl: Reception control register -----------------------------------*/

typedef struct {
  uint32_t RXENABLE                               :1;
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _ETHERNET_DMARxCtrl_bits;

/* Bit field positions: */
#define ETHERNET_DMARxCtrl_RXENABLE_Pos                     0

/* Bit field masks: */
#define ETHERNET_DMARxCtrl_RXENABLE_Msk                     0x00000001

/*-- DMARxDescriptor: Reception control register -----------------------------------*/

typedef struct {
  uint32_t DADDR                              :32;
} _ETHERNET_DMARxDescriptor_bits;

/* Bit field positions: */
#define ETHERNET_DMARxDescriptor_DADDR_Pos                     0

/* Bit field masks: */
#define ETHERNET_DMARxDescriptor_DADDR_Msk                     0xFFFFFFFF

/*-- DMARxStatus: Reception control register -----------------------------------*/

typedef struct {
  uint32_t RXPKTREC                              :1;
  uint32_t Reserved0                             :1;
  uint32_t RXOVERFLOW                            :1;
  uint32_t BUSERROR                              :1;
  uint32_t Reserved1                             :12;
  uint32_t RX_PKT_COUNT                          :8;
  uint32_t Reserved2                             :8;
} _ETHERNET_DMARxStatus_bits;

/* Bit field positions: */
#define ETHERNET_DMARxStatus_RXPKTREC_Pos                     0
#define ETHERNET_DMARxStatus_RXOVERFLOW_Pos                   2
#define ETHERNET_DMARxStatus_BUSERROR_Pos                     3
#define ETHERNET_DMARxStatus_RX_PKT_COUNT_Pos                 16

/* Bit field masks: */
#define ETHERNET_DMARxStatus_RXPKTREC_Msk                     0x00000001
#define ETHERNET_DMARxStatus_RXOVERFLOW_Msk                   0x00000002
#define ETHERNET_DMARxStatus_BUSERROR_Msk                     0x00000004
#define ETHERNET_DMARxStatus_RX_PKT_COUNT_Msk                 0x00FF0000

/*-- DMAINTMASK: Reception control register -----------------------------------*/

typedef struct {
  uint32_t TXPKTSENT                             :1;
  uint32_t TXUNDERRRUN                           :1;
  uint32_t Reserved0                             :1;
  uint32_t BUSERR_TX                             :1;
  uint32_t RXPKTREC                              :1;
  uint32_t Reserved1                             :1;
  uint32_t RXOVER                                :1;
  uint32_t BUSERR_RX                             :1;
  uint32_t Reserved2                             :24;
} _ETHERNET_DMAINTMASK_bits;

/* Bit field positions: */
#define ETHERNET_DMAINTMASK_TXPKTSENT_Pos                     0
#define ETHERNET_DMAINTMASK_TXUNDERRRUN_Pos                   1
#define ETHERNET_DMAINTMASK_BUSERR_TX_Pos                     3
#define ETHERNET_DMAINTMASK_RXPKTREC_Pos                      4
#define ETHERNET_DMAINTMASK_RXOVER_Pos                        6
#define ETHERNET_DMAINTMASK_BUSERR_RX_Pos                     7

/* Bit field masks: */
#define ETHERNET_DMAINTMASK_TXPKTSENT_Msk                     0x00000001
#define ETHERNET_DMAINTMASK_TXUNDERRRUN_Msk                   0x00000002
#define ETHERNET_DMAINTMASK_BUSERR_TX_Msk                     0x00000008
#define ETHERNET_DMAINTMASK_RXPKTREC_Msk                      0x00000010
#define ETHERNET_DMAINTMASK_RXOVER_Msk                        0x00000040
#define ETHERNET_DMAINTMASK_BUSERR_RX_Msk                     0x00000080

/*-- DMAINT: Reception control register -----------------------------------*/

typedef struct {
  uint32_t TXPKTSENT                             :1;
  uint32_t TXUNDERRRUN                           :1;
  uint32_t Reserved0                             :1;
  uint32_t BUSERR_TX                             :1;
  uint32_t RXPKTREC                              :1;
  uint32_t Reserved1                             :1;
  uint32_t RXOVER                                :1;
  uint32_t BUSERR_RX                             :1;
  uint32_t Reserved2                             :24;
} _ETHERNET_DMAINT_bits;

/* Bit field positions: */
#define ETHERNET_DMAINT_TXPKTSENT_Pos                     0
#define ETHERNET_DMAINT_TXUNDERRRUN_Pos                   1
#define ETHERNET_DMAINT_BUSERR_TX_Pos                     3
#define ETHERNET_DMAINT_RXPKTREC_Pos                      4
#define ETHERNET_DMAINT_RXOVER_Pos                        6
#define ETHERNET_DMAINT_BUSERR_RX_Pos                     7

/* Bit field masks: */
#define ETHERNET_DMAINT_TXPKTSENT_Msk                     0x00000001
#define ETHERNET_DMAINT_TXUNDERRRUN_Msk                   0x00000002
#define ETHERNET_DMAINT_BUSERR_TX_Msk                     0x00000008
#define ETHERNET_DMAINT_RXPKTREC_Msk                      0x00000010
#define ETHERNET_DMAINT_RXOVER_Msk                        0x00000040
#define ETHERNET_DMAINT_BUSERR_RX_Msk                     0x00000080

/*-- Register map for ETHERNET peripheral ------------------------------------*/

typedef struct {
  union {                                                               /*!< MAC configuration register 1 */
    __IO uint32_t MAC1;                                                 /*!< MAC1    : type used for word access */
    __IO _ETHERNET_MAC1_bits MAC1_bit;                                  /*!< MAC1_bit: structure used for bit access */
  };
  union {                                                               /*!< MAC configuration register 2 */
    __IO uint32_t MAC2;                                                 /*!< MAC2    : type used for word access */
    __IO _ETHERNET_MAC2_bits MAC2_bit;                                  /*!< MAC2_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Back-to-Back Inter-Packet-Gap */
    __IO uint32_t IPGT;                                                 /*!< IPGT    : type used for word access */
    __IO _ETHERNET_IPGT_bits IPGT_bit;                                  /*!< IPGT_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Non-Back-to-Back Inter-Packet-Gap */
    __IO uint32_t IPGR;                                                 /*!< IPGR    : type used for word access */
    __IO _ETHERNET_IPGR_bits IPGR_bit;                                  /*!< IPGR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register collision window */
    __IO uint32_t CLRT;                                                 /*!< CLRT    : type used for word access */
    __IO _ETHERNET_CLRT_bits CLRT_bit;                                  /*!< CLRT_bit: structure used for bit access */
  };
  union {                                                               /*!< Register the upper limit size Frame */
    __IO uint32_t MAXF;                                                 /*!< MAXF    : type used for word access */
    __IO _ETHERNET_MAXF_bits MAXF_bit;                                  /*!< MAXF_bit: structure used for bit access */
  };
  union {                                                               /*!< Register PHY-support interface */
    __IO uint32_t SUPP;                                                 /*!< SUPP    : type used for word access */
    __IO _ETHERNET_SUPP_bits SUPP_bit;                                  /*!< SUPP_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< Configuration control register MII */
    __IO uint32_t MCFG;                                                 /*!< MCFG    : type used for word access */
    __IO _ETHERNET_MCFG_bits MCFG_bit;                                  /*!< MCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Command register MII */
    __IO uint32_t MCMD;                                                 /*!< MCMD    : type used for word access */
    __IO _ETHERNET_MCMD_bits MCMD_bit;                                  /*!< MCMD_bit: structure used for bit access */
  };
  union {                                                               /*!< MII address register */
    __IO uint32_t MADR;                                                 /*!< MADR    : type used for word access */
    __IO _ETHERNET_MADR_bits MADR_bit;                                  /*!< MADR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register data written in MII */
    __O  uint32_t MWTD;                                                 /*!< MWTD    : type used for word access */
    __O  _ETHERNET_MWTD_bits MWTD_bit;                                  /*!< MWTD_bit: structure used for bit access */
  };
  union {                                                               /*!< Register read data from MII */
    __I  uint32_t MRDD;                                                 /*!< MRDD    : type used for word access */
    __I  _ETHERNET_MRDD_bits MRDD_bit;                                  /*!< MRDD_bit: structure used for bit access */
  };
  union {                                                               /*!< MII status register flags */
    __I  uint32_t MIND;                                                 /*!< MIND    : type used for word access */
    __I  _ETHERNET_MIND_bits MIND_bit;                                  /*!< MIND_bit: structure used for bit access */
  };
  union {                                                               /*!< MII controller status register */
    __I  uint32_t SMII;                                                 /*!< SMII    : type used for word access */
    __I  _ETHERNET_SMII_bits SMII_bit;                                  /*!< SMII_bit: structure used for bit access */
  };
  union {                                                               /*!< MIIFIFO configurate register */
    __IO uint32_t FIFOCFG;                                              /*!< FIFOCFG    : type used for word access */
    __IO _ETHERNET_FIFOCFG_bits FIFOCFG_bit;                            /*!< FIFOCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Station address register 0 */
    __IO uint32_t SA0;                                                  /*!< SA0    : type used for word access */
    __IO _ETHERNET_SA0_bits SA0_bit;                                    /*!< SA0_bit: structure used for bit access */
  };
  union {                                                               /*!< Station address register 1 */
    __IO uint32_t SA1;                                                  /*!< SA1    : type used for word access */
    __IO _ETHERNET_SA1_bits SA1_bit;                                    /*!< SA1_bit: structure used for bit access */
  };
  union {                                                               /*!< Station address register 2 */
    __IO uint32_t SA2;                                                  /*!< SA2    : type used for word access */
    __IO _ETHERNET_SA2_bits SA2_bit;                                    /*!< SA2_bit: structure used for bit access */
  };
  uint32_t Reserved1[77];                                               /*!< Reserved */
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMATxCtrl;                                            /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMATxCtrl_bits DMATxCtrl_bit;                        /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMATxDescriptor;                                      /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMATxDescriptor_bits DMATxDescriptor_bit;            /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMATxStatus;                                      /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMATxStatus_bits DMATxStatus_bit;            /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMARxCtrl;                                            /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMARxCtrl_bits DMARxCtrl_bit;                        /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMARxDescriptor;                                      /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMARxDescriptor_bits DMARxDescriptor_bit;            /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMARxStatus;                                      /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMARxStatus_bits DMARxStatus_bit;            /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMAINTMASK;                                      /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMAINTMASK_bits DMAINTMASK_bit;            /*!< DMATxCtrl_bit: structure used for bit access */
  };
  union {                                                               /*!< Reception control register */
    __IO uint32_t DMAINT;                                      /*!< DMATxCtrl    : type used for word access */
    __IO _ETHERNET_DMAINT_bits DMAINT_bit;            /*!< DMATxCtrl_bit: structure used for bit access */
  };
} NT_ETHERNET_TypeDef;

/******************************************************************************/
/*                      USB Host controller registers                         */
/******************************************************************************/

/*-- VERSION: Host controller USB version register ---------------------------*/

typedef struct {
  uint32_t VERSION                                :8;                   /*!< This addressable location holds the version No. of this implementation of the embedded host controller */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _USBHost_VERSION_bits;

/* Bit field positions: */
#define USBHost_VERSION_VERSION_Pos                         0           /*!< This addressable location holds the version No. of this implementation of the embedded host controller */

/* Bit field masks: */
#define USBHost_VERSION_VERSION_Msk                         0x000000FF  /*!< This addressable location holds the version No. of this implementation of the embedded host controller */

/*-- USBCMD_STS_INTR: HC Control register 1 ----------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t OUTSPACEINTEN                          :1;                   /*!< Hardware interrupt enable bit */
  uint32_t INDATAREADYINTEN                       :1;                   /*!< Enable interrupt InDataReady */
  uint32_t FRAMESOFINTEN                          :1;                   /*!< Enable interrupt Frame sof */
  uint32_t MICROFRAMEINTEN                        :1;                   /*!< Enable interrupt Microframe soa */
  uint32_t Reserved1                              :1;                   /*!< Reserved */
  uint32_t PORTCHANGINTEN                         :1;                   /*!< Enable interrupt Port change detect */
  uint32_t Reserved2                              :3;                   /*!< Reserved */
  uint32_t FRAMESOFINT                            :1;                   /*!< Interrupt flag Framesof */
  uint32_t MICROFRAMEINT                          :1;                   /*!< Interrupt flag Microframesof */
  uint32_t Reserved3                              :1;                   /*!< Reserved */
  uint32_t PORTCHANGINT                           :1;                   /*!< Indicate the any port has a change bit transmission from 0 to 1 */
  uint32_t Reserved4                              :1;                   /*!< Reserved */
  uint32_t HCHALTED                               :1;                   /*!< Indicator controller stop */
  uint32_t RUN_STOP                               :1;                   /*!< Perfoms data */
  uint32_t HOSTRESET                              :1;                   /*!< Initial state of USB-controller */
  uint32_t CONFIGFLAG                             :1;                   /*!< Configurate flag */
  uint32_t Reserved5                              :5;                   /*!< Reserved */
  uint32_t INT_SPACE                              :8;                   /*!< Control Interrupt intervals */
} _USBHost_USBCMD_STS_INTR_bits;

/* Bit field positions: */
#define USBHost_USBCMD_STS_INTR_OUTSPACEINTEN_Pos           1           /*!< Hardware interrupt enable bit */
#define USBHost_USBCMD_STS_INTR_INDATAREADYINTEN_Pos        2           /*!< Enable interrupt InDataReady */
#define USBHost_USBCMD_STS_INTR_FRAMESOFINTEN_Pos           3           /*!< Enable interrupt Frame sof */
#define USBHost_USBCMD_STS_INTR_MICROFRAMEINTEN_Pos         4           /*!< Enable interrupt Microframe soa */
#define USBHost_USBCMD_STS_INTR_PORTCHANGINTEN_Pos          6           /*!< Enable interrupt Port change detect */
#define USBHost_USBCMD_STS_INTR_FRAMESOFINT_Pos             10          /*!< Interrupt flag Framesof */
#define USBHost_USBCMD_STS_INTR_MICROFRAMEINT_Pos           11          /*!< Interrupt flag Microframesof */
#define USBHost_USBCMD_STS_INTR_PORTCHANGINT_Pos            13          /*!< Indicate the any port has a change bit transmission from 0 to 1 */
#define USBHost_USBCMD_STS_INTR_HCHALTED_Pos                15          /*!< Indicator controller stop */
#define USBHost_USBCMD_STS_INTR_RUN_STOP_Pos                16          /*!< Perfoms data */
#define USBHost_USBCMD_STS_INTR_HOSTRESET_Pos               17          /*!< Initial state of USB-controller */
#define USBHost_USBCMD_STS_INTR_CONFIGFLAG_Pos              18          /*!< Configurate flag */
#define USBHost_USBCMD_STS_INTR_INT_SPACE_Pos               24          /*!< Control Interrupt intervals */

/* Bit field masks: */
#define USBHost_USBCMD_STS_INTR_OUTSPACEINTEN_Msk           0x00000002  /*!< Hardware interrupt enable bit */
#define USBHost_USBCMD_STS_INTR_INDATAREADYINTEN_Msk        0x00000004  /*!< Enable interrupt InDataReady */
#define USBHost_USBCMD_STS_INTR_FRAMESOFINTEN_Msk           0x00000008  /*!< Enable interrupt Frame sof */
#define USBHost_USBCMD_STS_INTR_MICROFRAMEINTEN_Msk         0x00000010  /*!< Enable interrupt Microframe soa */
#define USBHost_USBCMD_STS_INTR_PORTCHANGINTEN_Msk          0x00000040  /*!< Enable interrupt Port change detect */
#define USBHost_USBCMD_STS_INTR_FRAMESOFINT_Msk             0x00000400  /*!< Interrupt flag Framesof */
#define USBHost_USBCMD_STS_INTR_MICROFRAMEINT_Msk           0x00000800  /*!< Interrupt flag Microframesof */
#define USBHost_USBCMD_STS_INTR_PORTCHANGINT_Msk            0x00002000  /*!< Indicate the any port has a change bit transmission from 0 to 1 */
#define USBHost_USBCMD_STS_INTR_HCHALTED_Msk                0x00008000  /*!< Indicator controller stop */
#define USBHost_USBCMD_STS_INTR_RUN_STOP_Msk                0x00010000  /*!< Perfoms data */
#define USBHost_USBCMD_STS_INTR_HOSTRESET_Msk               0x00020000  /*!< Initial state of USB-controller */
#define USBHost_USBCMD_STS_INTR_CONFIGFLAG_Msk              0x00040000  /*!< Configurate flag */
#define USBHost_USBCMD_STS_INTR_INT_SPACE_Msk               0xFF000000  /*!< Control Interrupt intervals */

/*-- FRAME_REG: Register version ---------------------------------------------*/

typedef struct {
  uint32_t FRAMEINDEX                             :14;                  /*!< Field of the countdown */
  uint32_t Reserved0                              :2;                   /*!< Reserved */
  uint32_t FRAMELENGTH                            :6;                   /*!< Micro frame length */
  uint32_t Reserved1                              :10;                  /*!< Reserved */
} _USBHost_FRAME_REG_bits;

/* Bit field positions: */
#define USBHost_FRAME_REG_FRAMEINDEX_Pos                    0           /*!< Field of the countdown */
#define USBHost_FRAME_REG_FRAMELENGTH_Pos                   16          /*!< Micro frame length */

/* Bit field masks: */
#define USBHost_FRAME_REG_FRAMEINDEX_Msk                    0x00003FFF  /*!< Field of the countdown */
#define USBHost_FRAME_REG_FRAMELENGTH_Msk                   0x003F0000  /*!< Micro frame length */

/*-- PORT_STS: HC Control register 2 -----------------------------------------*/

typedef struct {
  uint32_t PORTCONNECT                            :1;                   /*!< Indicator device connection */
  uint32_t PORTCONCHNG                            :1;                   /*!< Indicator status change bit PORTCONNECT */
  uint32_t PORTENABLE                             :1;                   /*!< Enable bit port */
  uint32_t PORTEN_DISCHNG                         :1;                   /*!< Indicator status change bit PORTENABLE */
  uint32_t PORTRESET                              :1;                   /*!< Setting bit starts the reset procedure in accordance with USB2.0 */
  uint32_t LINESTATE                              :2;                   /*!< Field reflect the current logic level signals D + and D- */
  uint32_t PORTOWNER0                             :1;                   /*!< Bit with bit PORTOWNER1 assignment of the port speed */
  uint32_t SUSPEND                                :1;                   /*!< Bit suspension of work */
  uint32_t FORCEPORTRESUME                        :1;                   /*!< Flag resume */
  uint32_t XCVRRESET                              :1;                   /*!< Reset bit transceiver */
  uint32_t XCVRRESLEVEL                           :1;                   /*!< Bit setting active level reset signal transceiver */
  uint32_t XCVRSUSPEND                            :1;
  uint32_t TESTJ                                  :1;                   /*!< keep in line condition HS J */
  uint32_t TESTK                                  :1;                   /*!< Enable keep in line condition HS K */
  uint32_t TESTSEO                                :1;                   /*!< Enable keep in line condition SEO */
  uint32_t TESTFORCEEN                            :1;                   /*!< Enable transmit packets looped */
  uint32_t TESTPKT                                :1;                   /*!< Bits select the standard USB */
  uint32_t PORTOWNER1                             :1;                   /*!< Indicator low-speed devices */
  uint32_t Reserved0                              :13;                  /*!< Reserved */
} _USBHost_PORT_STS_bits;

/* Bit field positions: */
#define USBHost_PORT_STS_PORTCONNECT_Pos                    0           /*!< Indicator device connection */
#define USBHost_PORT_STS_PORTCONCHNG_Pos                    1           /*!< Indicator status change bit PORTCONNECT */
#define USBHost_PORT_STS_PORTENABLE_Pos                     2           /*!< Enable bit port */
#define USBHost_PORT_STS_PORTEN_DISCHNG_Pos                 3           /*!< Indicator status change bit PORTENABLE */
#define USBHost_PORT_STS_PORTRESET_Pos                      4           /*!< Setting bit starts the reset procedure in accordance with USB2.0 */
#define USBHost_PORT_STS_LINESTATE_Pos                      5           /*!< Field reflect the current logic level signals D + and D- */
#define USBHost_PORT_STS_PORTOWNER0_Pos                     7           /*!< Bit with bit PORTOWNER1 assignment of the port speed */
#define USBHost_PORT_STS_SUSPEND_Pos                        8           /*!< Bit suspension of work */
#define USBHost_PORT_STS_FORCEPORTRESUME_Pos                9           /*!< Flag resume */
#define USBHost_PORT_STS_XCVRRESET_Pos                      10          /*!< Reset bit transceiver */
#define USBHost_PORT_STS_XCVRRESLEVEL_Pos                   11          /*!< Bit setting active level reset signal transceiver */
#define USBHost_PORT_STS_XCVRSUSPEND_Pos                    12
#define USBHost_PORT_STS_TESTJ_Pos                          13          /*!< keep in line condition HS J */
#define USBHost_PORT_STS_TESTK_Pos                          14          /*!< Enable keep in line condition HS K */
#define USBHost_PORT_STS_TESTSEO_Pos                        15          /*!< Enable keep in line condition SEO */
#define USBHost_PORT_STS_TESTFORCEEN_Pos                    16          /*!< Enable transmit packets looped */
#define USBHost_PORT_STS_TESTPKT_Pos                        17          /*!< Bits select the standard USB */
#define USBHost_PORT_STS_PORTOWNER1_Pos                     18          /*!< Indicator low-speed devices */

/* Bit field masks: */
#define USBHost_PORT_STS_PORTCONNECT_Msk                    0x00000001  /*!< Indicator device connection */
#define USBHost_PORT_STS_PORTCONCHNG_Msk                    0x00000002  /*!< Indicator status change bit PORTCONNECT */
#define USBHost_PORT_STS_PORTENABLE_Msk                     0x00000004  /*!< Enable bit port */
#define USBHost_PORT_STS_PORTEN_DISCHNG_Msk                 0x00000008  /*!< Indicator status change bit PORTENABLE */
#define USBHost_PORT_STS_PORTRESET_Msk                      0x00000010  /*!< Setting bit starts the reset procedure in accordance with USB2.0 */
#define USBHost_PORT_STS_LINESTATE_Msk                      0x00000060  /*!< Field reflect the current logic level signals D + and D- */
#define USBHost_PORT_STS_PORTOWNER0_Msk                     0x00000080  /*!< Bit with bit PORTOWNER1 assignment of the port speed */
#define USBHost_PORT_STS_SUSPEND_Msk                        0x00000100  /*!< Bit suspension of work */
#define USBHost_PORT_STS_FORCEPORTRESUME_Msk                0x00000200  /*!< Flag resume */
#define USBHost_PORT_STS_XCVRRESET_Msk                      0x00000400  /*!< Reset bit transceiver */
#define USBHost_PORT_STS_XCVRRESLEVEL_Msk                   0x00000800  /*!< Bit setting active level reset signal transceiver */
#define USBHost_PORT_STS_XCVRSUSPEND_Msk                    0x00001000
#define USBHost_PORT_STS_TESTJ_Msk                          0x00002000  /*!< keep in line condition HS J */
#define USBHost_PORT_STS_TESTK_Msk                          0x00004000  /*!< Enable keep in line condition HS K */
#define USBHost_PORT_STS_TESTSEO_Msk                        0x00008000  /*!< Enable keep in line condition SEO */
#define USBHost_PORT_STS_TESTFORCEEN_Msk                    0x00010000  /*!< Enable transmit packets looped */
#define USBHost_PORT_STS_TESTPKT_Msk                        0x00020000  /*!< Bits select the standard USB */
#define USBHost_PORT_STS_PORTOWNER1_Msk                     0x00040000  /*!< Indicator low-speed devices */

/*-- USB_PKT_FIELDS_A: Transmission Control register A -----------------------*/

typedef struct {
  uint32_t EP_ADDR                                :4;                   /*!< Buffer address field that has received a transfer */
  uint32_t PID                                    :2;                   /*!< Field of tags that should be sent to the downstream */
  uint32_t ENDPOINTTYPE                           :2;                   /*!< Buffer type */
  uint32_t DEV_ADDR                               :7;                   /*!< Address field that is accessed by the current operation */
  uint32_t IOC                                    :1;                   /*!< Bits specify the behavior of the host controller when transfer */
  uint32_t PORT_NUMBER                            :7;                   /*!< Field router port number to which the device is connected FS / LS */
  uint32_t DATATOGGLE                             :1;                   /*!< Identifier field data to be used in the current transmission */
  uint32_t HUB_ADDRESS                            :7;                   /*!< The address field of the router to which the transfer of the type faces 'Split' */
  uint32_t ENTRANSFER                             :1;                   /*!< Beginning of the current permission bits of data */
} _USBHost_USB_PKT_FIELDS_A_bits;

/* Bit field positions: */
#define USBHost_USB_PKT_FIELDS_A_EP_ADDR_Pos                0           /*!< Buffer address field that has received a transfer */
#define USBHost_USB_PKT_FIELDS_A_PID_Pos                    4           /*!< Field of tags that should be sent to the downstream */
#define USBHost_USB_PKT_FIELDS_A_ENDPOINTTYPE_Pos           6           /*!< Buffer type */
#define USBHost_USB_PKT_FIELDS_A_DEV_ADDR_Pos               8           /*!< Address field that is accessed by the current operation */
#define USBHost_USB_PKT_FIELDS_A_IOC_Pos                    15          /*!< Bits specify the behavior of the host controller when transfer */
#define USBHost_USB_PKT_FIELDS_A_PORT_NUMBER_Pos            16          /*!< Field router port number to which the device is connected FS / LS */
#define USBHost_USB_PKT_FIELDS_A_DATATOGGLE_Pos             23          /*!< Identifier field data to be used in the current transmission */
#define USBHost_USB_PKT_FIELDS_A_HUB_ADDRESS_Pos            24          /*!< The address field of the router to which the transfer of the type faces 'Split' */
#define USBHost_USB_PKT_FIELDS_A_ENTRANSFER_Pos             31          /*!< Beginning of the current permission bits of data */

/* Bit field masks: */
#define USBHost_USB_PKT_FIELDS_A_EP_ADDR_Msk                0x0000000F  /*!< Buffer address field that has received a transfer */
#define USBHost_USB_PKT_FIELDS_A_PID_Msk                    0x00000030  /*!< Field of tags that should be sent to the downstream */
#define USBHost_USB_PKT_FIELDS_A_ENDPOINTTYPE_Msk           0x000000C0  /*!< Buffer type */
#define USBHost_USB_PKT_FIELDS_A_DEV_ADDR_Msk               0x00007F00  /*!< Address field that is accessed by the current operation */
#define USBHost_USB_PKT_FIELDS_A_IOC_Msk                    0x00008000  /*!< Bits specify the behavior of the host controller when transfer */
#define USBHost_USB_PKT_FIELDS_A_PORT_NUMBER_Msk            0x007F0000  /*!< Field router port number to which the device is connected FS / LS */
#define USBHost_USB_PKT_FIELDS_A_DATATOGGLE_Msk             0x00800000  /*!< Identifier field data to be used in the current transmission */
#define USBHost_USB_PKT_FIELDS_A_HUB_ADDRESS_Msk            0x7F000000  /*!< The address field of the router to which the transfer of the type faces 'Split' */
#define USBHost_USB_PKT_FIELDS_A_ENTRANSFER_Msk             0x80000000  /*!< Beginning of the current permission bits of data */

/*-- USB_PKT_FIELDS_B: Transmission Control register B -----------------------*/

typedef struct {
  uint32_t MPS                                    :11;                  /*!< Maximum packet size in the downstream */
  uint32_t ABORTTRANSFER                          :1;                   /*!< Bit the current operation */
  uint32_t XFRLEVEL                               :1;
  uint32_t IGNORSHORTPKT                          :1;                   /*!< Enable bit ignore short packets */
  uint32_t EFIELD                                 :1;                   /*!< Bit transmission control */
  uint32_t SPEED                                  :1;                   /*!< Indicator the type of device connected to the router and port */
  uint32_t COMPLETESPLIT                          :1;                   /*!< Complete bit operations such as Split */
  uint32_t STARTSPLIT                             :1;                   /*!< Bit run operations such as Split */
  uint32_t Reserved0                              :2;                   /*!< Reserved */
  uint32_t MAX_ERR_CNT                            :4;                   /*!< Field the maximum number of consecutive transmission errors */
  uint32_t MAX_NAK_CNT                            :4;                   /*!< Maximum number of labels NAK, which is allowed to accept the host. */
  uint32_t SLAVEMODE                              :1;                   /*!< Enable slave mode */
  uint32_t Reserved1                              :2;                   /*!< Reserved */
  uint32_t OHCIENABLE                             :1;                   /*!< Demand indicator */
} _USBHost_USB_PKT_FIELDS_B_bits;

/* Bit field positions: */
#define USBHost_USB_PKT_FIELDS_B_MPS_Pos                    0           /*!< Maximum packet size in the downstream */
#define USBHost_USB_PKT_FIELDS_B_ABORTTRANSFER_Pos          11          /*!< Bit the current operation */
#define USBHost_USB_PKT_FIELDS_B_XFRLEVEL_Pos               12
#define USBHost_USB_PKT_FIELDS_B_IGNORSHORTPKT_Pos          13          /*!< Enable bit ignore short packets */
#define USBHost_USB_PKT_FIELDS_B_EFIELD_Pos                 14          /*!< Bit transmission control */
#define USBHost_USB_PKT_FIELDS_B_SPEED_Pos                  15          /*!< Indicator the type of device connected to the router and port */
#define USBHost_USB_PKT_FIELDS_B_COMPLETESPLIT_Pos          16          /*!< Complete bit operations such as Split */
#define USBHost_USB_PKT_FIELDS_B_STARTSPLIT_Pos             17          /*!< Bit run operations such as Split */
#define USBHost_USB_PKT_FIELDS_B_MAX_ERR_CNT_Pos            20          /*!< Field the maximum number of consecutive transmission errors */
#define USBHost_USB_PKT_FIELDS_B_MAX_NAK_CNT_Pos            24          /*!< Maximum number of labels NAK, which is allowed to accept the host. */
#define USBHost_USB_PKT_FIELDS_B_SLAVEMODE_Pos              28          /*!< Enable slave mode */
#define USBHost_USB_PKT_FIELDS_B_OHCIENABLE_Pos             31          /*!< Demand indicator */

/* Bit field masks: */
#define USBHost_USB_PKT_FIELDS_B_MPS_Msk                    0x000007FF  /*!< Maximum packet size in the downstream */
#define USBHost_USB_PKT_FIELDS_B_ABORTTRANSFER_Msk          0x00000800  /*!< Bit the current operation */
#define USBHost_USB_PKT_FIELDS_B_XFRLEVEL_Msk               0x00001000
#define USBHost_USB_PKT_FIELDS_B_IGNORSHORTPKT_Msk          0x00002000  /*!< Enable bit ignore short packets */
#define USBHost_USB_PKT_FIELDS_B_EFIELD_Msk                 0x00004000  /*!< Bit transmission control */
#define USBHost_USB_PKT_FIELDS_B_SPEED_Msk                  0x00008000  /*!< Indicator the type of device connected to the router and port */
#define USBHost_USB_PKT_FIELDS_B_COMPLETESPLIT_Msk          0x00010000  /*!< Complete bit operations such as Split */
#define USBHost_USB_PKT_FIELDS_B_STARTSPLIT_Msk             0x00020000  /*!< Bit run operations such as Split */
#define USBHost_USB_PKT_FIELDS_B_MAX_ERR_CNT_Msk            0x00F00000  /*!< Field the maximum number of consecutive transmission errors */
#define USBHost_USB_PKT_FIELDS_B_MAX_NAK_CNT_Msk            0x0F000000  /*!< Maximum number of labels NAK, which is allowed to accept the host. */
#define USBHost_USB_PKT_FIELDS_B_SLAVEMODE_Msk              0x10000000  /*!< Enable slave mode */
#define USBHost_USB_PKT_FIELDS_B_OHCIENABLE_Msk             0x80000000  /*!< Demand indicator */

/*-- TBT: Transmission data register -----------------------------------------*/

typedef struct {
  uint32_t TOTALBTRANS                            :20;                  /*!< Total Byte transfer */
  uint32_t Reserved0                              :12;                  /*!< Reserved */
} _USBHost_TBT_bits;

/* Bit field positions: */
#define USBHost_TBT_TOTALBTRANS_Pos                         0           /*!< Total Byte transfer */

/* Bit field masks: */
#define USBHost_TBT_TOTALBTRANS_Msk                         0x000FFFFF  /*!< Total Byte transfer */

/*-- USB_STATUS: XFR STATUS register -----------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t UNEXPPID                               :1;                   /*!< Receiving flag PID, different from the expected */
  uint32_t SHORTPKT                               :1;                   /*!< Flag receiving fewer bits than indicated in the register TOTAL_BYTES_TRANS TBT */
  uint32_t ERRPID                                 :1;                   /*!< Flag to receive a response to the label ERROR PID Complete Split */
  uint32_t OUTSPACEVAILABLE                       :1;                   /*!< Request flag outbound operation with an empty data buffer */
  uint32_t INDATAREADY                            :1;                   /*!< Flag successful completion of an inbound operation */
  uint32_t PIDERR                                 :1;                   /*!< Receiving flag incorrect PID */
  uint32_t CRCERR                                 :1;                   /*!< CRC error in receiving data */
  uint32_t TOGGLEERR                              :1;                   /*!< Receiving flag bit wrong DATATOGGLE */
  uint32_t TIMEOUT                                :1;                   /*!< Flag timeout response */
  uint32_t NYET                                   :1;                   /*!< Receiving flag tags NYET */
  uint32_t NAK                                    :1;                   /*!< Receiving flag tags NAK */
  uint32_t PAGECROSS                              :1;                   /*!< Flag requirements transmission pagecross */
  uint32_t PING                                   :1;                   /*!< Flag response */
  uint32_t XACTNERR                               :1;
  uint32_t BABBLE                                 :1;                   /*!< Flag of finding the system in state Packet Babble */
  uint32_t HALTED                                 :1;                   /*!< Flag of finding the system in state Stall or Packet Babble */
  uint32_t USBINT                                 :1;                   /*!< Flag of the last operation */
  uint32_t USBERRINT                              :1;                   /*!< Error flag that indicates that the last operation was completed due to an erroneous bus state */
  uint32_t Reserved1                              :6;                   /*!< Reserved */
} _USBHost_USB_STATUS_bits;

/* Bit field positions: */
#define USBHost_USB_STATUS_UNEXPPID_Pos                     8           /*!< Receiving flag PID, different from the expected */
#define USBHost_USB_STATUS_SHORTPKT_Pos                     9           /*!< Flag receiving fewer bits than indicated in the register TOTAL_BYTES_TRANS TBT */
#define USBHost_USB_STATUS_ERRPID_Pos                       10          /*!< Flag to receive a response to the label ERROR PID Complete Split */
#define USBHost_USB_STATUS_OUTSPACEVAILABLE_Pos             11          /*!< Request flag outbound operation with an empty data buffer */
#define USBHost_USB_STATUS_INDATAREADY_Pos                  12          /*!< Flag successful completion of an inbound operation */
#define USBHost_USB_STATUS_PIDERR_Pos                       13          /*!< Receiving flag incorrect PID */
#define USBHost_USB_STATUS_CRCERR_Pos                       14          /*!< CRC error in receiving data */
#define USBHost_USB_STATUS_TOGGLEERR_Pos                    15          /*!< Receiving flag bit wrong DATATOGGLE */
#define USBHost_USB_STATUS_TIMEOUT_Pos                      16          /*!< Flag timeout response */
#define USBHost_USB_STATUS_NYET_Pos                         17          /*!< Receiving flag tags NYET */
#define USBHost_USB_STATUS_NAK_Pos                          18          /*!< Receiving flag tags NAK */
#define USBHost_USB_STATUS_PAGECROSS_Pos                    19          /*!< Flag requirements transmission pagecross */
#define USBHost_USB_STATUS_PING_Pos                         20          /*!< Flag response */
#define USBHost_USB_STATUS_XACTNERR_Pos                     21
#define USBHost_USB_STATUS_BABBLE_Pos                       22          /*!< Flag of finding the system in state Packet Babble */
#define USBHost_USB_STATUS_HALTED_Pos                       23          /*!< Flag of finding the system in state Stall or Packet Babble */
#define USBHost_USB_STATUS_USBINT_Pos                       24          /*!< Flag of the last operation */
#define USBHost_USB_STATUS_USBERRINT_Pos                    25          /*!< Error flag that indicates that the last operation was completed due to an erroneous bus state */

/* Bit field masks: */
#define USBHost_USB_STATUS_UNEXPPID_Msk                     0x00000100  /*!< Receiving flag PID, different from the expected */
#define USBHost_USB_STATUS_SHORTPKT_Msk                     0x00000200  /*!< Flag receiving fewer bits than indicated in the register TOTAL_BYTES_TRANS TBT */
#define USBHost_USB_STATUS_ERRPID_Msk                       0x00000400  /*!< Flag to receive a response to the label ERROR PID Complete Split */
#define USBHost_USB_STATUS_OUTSPACEVAILABLE_Msk             0x00000800  /*!< Request flag outbound operation with an empty data buffer */
#define USBHost_USB_STATUS_INDATAREADY_Msk                  0x00001000  /*!< Flag successful completion of an inbound operation */
#define USBHost_USB_STATUS_PIDERR_Msk                       0x00002000  /*!< Receiving flag incorrect PID */
#define USBHost_USB_STATUS_CRCERR_Msk                       0x00004000  /*!< CRC error in receiving data */
#define USBHost_USB_STATUS_TOGGLEERR_Msk                    0x00008000  /*!< Receiving flag bit wrong DATATOGGLE */
#define USBHost_USB_STATUS_TIMEOUT_Msk                      0x00010000  /*!< Flag timeout response */
#define USBHost_USB_STATUS_NYET_Msk                         0x00020000  /*!< Receiving flag tags NYET */
#define USBHost_USB_STATUS_NAK_Msk                          0x00040000  /*!< Receiving flag tags NAK */
#define USBHost_USB_STATUS_PAGECROSS_Msk                    0x00080000  /*!< Flag requirements transmission pagecross */
#define USBHost_USB_STATUS_PING_Msk                         0x00100000  /*!< Flag response */
#define USBHost_USB_STATUS_XACTNERR_Msk                     0x00200000
#define USBHost_USB_STATUS_BABBLE_Msk                       0x00400000  /*!< Flag of finding the system in state Packet Babble */
#define USBHost_USB_STATUS_HALTED_Msk                       0x00800000  /*!< Flag of finding the system in state Stall or Packet Babble */
#define USBHost_USB_STATUS_USBINT_Msk                       0x01000000  /*!< Flag of the last operation */
#define USBHost_USB_STATUS_USBERRINT_Msk                    0x02000000  /*!< Error flag that indicates that the last operation was completed due to an erroneous bus state */

/*-- SLAVE_IN_COUNT: Register received data ----------------------------------*/

typedef struct {
  uint32_t BYTECOUNT                              :11;                  /*!< Indication of the number of bytes received from the device when prompted interruption 'Data ready' */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _USBHost_SLAVE_IN_COUNT_bits;

/* Bit field positions: */
#define USBHost_SLAVE_IN_COUNT_BYTECOUNT_Pos                0           /*!< Indication of the number of bytes received from the device when prompted interruption 'Data ready' */

/* Bit field masks: */
#define USBHost_SLAVE_IN_COUNT_BYTECOUNT_Msk                0x000007FF  /*!< Indication of the number of bytes received from the device when prompted interruption 'Data ready' */

/*-- Register map for USBHost peripheral -------------------------------------*/

typedef struct {
  union {                                                               /*!< Host controller USB version register */
    __I  uint32_t VERSION;                                              /*!< VERSION    : type used for word access */
    __I  _USBHost_VERSION_bits VERSION_bit;                             /*!< VERSION_bit: structure used for bit access */
  };
  union {                                                               /*!< HC Control register 1 */
    __IO uint32_t USBCMD_STS_INTR;                                      /*!< USBCMD_STS_INTR    : type used for word access */
    __IO _USBHost_USBCMD_STS_INTR_bits USBCMD_STS_INTR_bit;             /*!< USBCMD_STS_INTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register version */
    __IO uint32_t FRAME_REG;                                            /*!< FRAME_REG    : type used for word access */
    __IO _USBHost_FRAME_REG_bits FRAME_REG_bit;                         /*!< FRAME_REG_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< HC Control register 2 */
    __IO uint32_t PORT_STS;                                             /*!< PORT_STS    : type used for word access */
    __IO _USBHost_PORT_STS_bits PORT_STS_bit;                           /*!< PORT_STS_bit: structure used for bit access */
  };
  union {                                                               /*!< Transmission Control register A */
    __IO uint32_t USB_PKT_FIELDS_A;                                     /*!< USB_PKT_FIELDS_A    : type used for word access */
    __IO _USBHost_USB_PKT_FIELDS_A_bits USB_PKT_FIELDS_A_bit;           /*!< USB_PKT_FIELDS_A_bit: structure used for bit access */
  };
  union {                                                               /*!< Transmission Control register B */
    __IO uint32_t USB_PKT_FIELDS_B;                                     /*!< USB_PKT_FIELDS_B    : type used for word access */
    __IO _USBHost_USB_PKT_FIELDS_B_bits USB_PKT_FIELDS_B_bit;           /*!< USB_PKT_FIELDS_B_bit: structure used for bit access */
  };
  __IO uint32_t BUFF_START_ADDR;                                        /*!< Bufer start address register */
  union {                                                               /*!< Transmission data register */
    __IO uint32_t TBT;                                                  /*!< TBT    : type used for word access */
    __IO _USBHost_TBT_bits TBT_bit;                                     /*!< TBT_bit: structure used for bit access */
  };
  union {                                                               /*!< XFR STATUS register */
    __I  uint32_t USB_STATUS;                                           /*!< USB_STATUS    : type used for word access */
    __I  _USBHost_USB_STATUS_bits USB_STATUS_bit;                       /*!< USB_STATUS_bit: structure used for bit access */
  };
  uint32_t Reserved1;                                                   /*!< Reserved */
  __IO uint32_t Data_Buffer;                                            /*!< Data buffer register */
  union {                                                               /*!< Register received data */
    __I  uint32_t SLAVE_IN_COUNT;                                       /*!< SLAVE_IN_COUNT    : type used for word access */
    __I  _USBHost_SLAVE_IN_COUNT_bits SLAVE_IN_COUNT_bit;               /*!< SLAVE_IN_COUNT_bit: structure used for bit access */
  };
} NT_USBHost_TypeDef;

/******************************************************************************/
/*                     USB Device controller registers                        */
/******************************************************************************/

/*-- IRQ_STAT_L: Interrupt status register -----------------------------------*/

typedef struct {
  uint32_t USBBUSINT                              :1;                   /*!< Interrupt flag events on the USB bus */
  uint32_t CEP_INT                                :1;                   /*!< Interrupt flag Control EndPoint */
  uint32_t EP0_INT                                :1;                   /*!< Interrupt flags EndPoint 1 */
  uint32_t EP1_INT                                :1;                   /*!< Interrupt flags EndPoint 2 */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _USBDevice_IRQ_STAT_L_bits;

/* Bit field positions: */
#define USBDevice_IRQ_STAT_L_USBBUSINT_Pos                  0           /*!< Interrupt flag events on the USB bus */
#define USBDevice_IRQ_STAT_L_CEP_INT_Pos                    1           /*!< Interrupt flag Control EndPoint */
#define USBDevice_IRQ_STAT_L_EP0_INT_Pos                    2           /*!< Interrupt flags EndPoint 1 */
#define USBDevice_IRQ_STAT_L_EP1_INT_Pos                    3           /*!< Interrupt flags EndPoint 2 */

/* Bit field masks: */
#define USBDevice_IRQ_STAT_L_USBBUSINT_Msk                  0x00000001  /*!< Interrupt flag events on the USB bus */
#define USBDevice_IRQ_STAT_L_CEP_INT_Msk                    0x00000002  /*!< Interrupt flag Control EndPoint */
#define USBDevice_IRQ_STAT_L_EP0_INT_Msk                    0x00000004  /*!< Interrupt flags EndPoint 1 */
#define USBDevice_IRQ_STAT_L_EP1_INT_Msk                    0x00000008  /*!< Interrupt flags EndPoint 2 */

/*-- IRQ_ENB_L: Interrupt enable register ------------------------------------*/

typedef struct {
  uint32_t USBBUSINTEN                            :1;                   /*!< Enable interrupts from the events on the USB bus */
  uint32_t CEP_INTEN                              :1;                   /*!< Interrupt enable for Control EndPoint */
  uint32_t EP0_INTEN                              :1;                   /*!< Interrupt enable for EndPoint 1 */
  uint32_t EP1_INTEN                              :1;                   /*!< Interrupt enable for EndPoint 2 */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _USBDevice_IRQ_ENB_L_bits;

/* Bit field positions: */
#define USBDevice_IRQ_ENB_L_USBBUSINTEN_Pos                 0           /*!< Enable interrupts from the events on the USB bus */
#define USBDevice_IRQ_ENB_L_CEP_INTEN_Pos                   1           /*!< Interrupt enable for Control EndPoint */
#define USBDevice_IRQ_ENB_L_EP0_INTEN_Pos                   2           /*!< Interrupt enable for EndPoint 1 */
#define USBDevice_IRQ_ENB_L_EP1_INTEN_Pos                   3           /*!< Interrupt enable for EndPoint 2 */

/* Bit field masks: */
#define USBDevice_IRQ_ENB_L_USBBUSINTEN_Msk                 0x00000001  /*!< Enable interrupts from the events on the USB bus */
#define USBDevice_IRQ_ENB_L_CEP_INTEN_Msk                   0x00000002  /*!< Interrupt enable for Control EndPoint */
#define USBDevice_IRQ_ENB_L_EP0_INTEN_Msk                   0x00000004  /*!< Interrupt enable for EndPoint 1 */
#define USBDevice_IRQ_ENB_L_EP1_INTEN_Msk                   0x00000008  /*!< Interrupt enable for EndPoint 2 */

/*-- USB_IRQ_STAT: USB Interrupt status register -----------------------------*/

typedef struct {
  uint32_t SOF                                    :1;                   /*!< Flag SOF packet reception */
  uint32_t RESSTATUS                              :1;                   /*!< Completion flag reset the root port */
  uint32_t RESUME                                 :1;                   /*!< Flag reactivate the device */
  uint32_t SUSPENDREQ                             :1;                   /*!< SUSPEND mode request bit */
  uint32_t HIGHSPEEDSETTLE                        :1;                   /*!< Completion flag reset and switching devices in high-speed mode */
  uint32_t DMACMPLINT                             :1;                   /*!< Completion flag DMA data transfer */
  uint32_t CLKUNSTBLINT                           :1;                   /*!< Interrupt flag, signaling an unstable clock signal UTMI and to initialize the device controller registers */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _USBDevice_USB_IRQ_STAT_bits;

/* Bit field positions: */
#define USBDevice_USB_IRQ_STAT_SOF_Pos                      0           /*!< Flag SOF packet reception */
#define USBDevice_USB_IRQ_STAT_RESSTATUS_Pos                1           /*!< Completion flag reset the root port */
#define USBDevice_USB_IRQ_STAT_RESUME_Pos                   2           /*!< Flag reactivate the device */
#define USBDevice_USB_IRQ_STAT_SUSPENDREQ_Pos               3           /*!< SUSPEND mode request bit */
#define USBDevice_USB_IRQ_STAT_HIGHSPEEDSETTLE_Pos          4           /*!< Completion flag reset and switching devices in high-speed mode */
#define USBDevice_USB_IRQ_STAT_DMACMPLINT_Pos               5           /*!< Completion flag DMA data transfer */
#define USBDevice_USB_IRQ_STAT_CLKUNSTBLINT_Pos             6           /*!< Interrupt flag, signaling an unstable clock signal UTMI and to initialize the device controller registers */

/* Bit field masks: */
#define USBDevice_USB_IRQ_STAT_SOF_Msk                      0x00000001  /*!< Flag SOF packet reception */
#define USBDevice_USB_IRQ_STAT_RESSTATUS_Msk                0x00000002  /*!< Completion flag reset the root port */
#define USBDevice_USB_IRQ_STAT_RESUME_Msk                   0x00000004  /*!< Flag reactivate the device */
#define USBDevice_USB_IRQ_STAT_SUSPENDREQ_Msk               0x00000008  /*!< SUSPEND mode request bit */
#define USBDevice_USB_IRQ_STAT_HIGHSPEEDSETTLE_Msk          0x00000010  /*!< Completion flag reset and switching devices in high-speed mode */
#define USBDevice_USB_IRQ_STAT_DMACMPLINT_Msk               0x00000020  /*!< Completion flag DMA data transfer */
#define USBDevice_USB_IRQ_STAT_CLKUNSTBLINT_Msk             0x00000040  /*!< Interrupt flag, signaling an unstable clock signal UTMI and to initialize the device controller registers */

/*-- USB_IRQ_ENB: USB Interrupt enable register ------------------------------*/

typedef struct {
  uint32_t SOFINTEN                               :1;                   /*!< Enable SOF packet reception */
  uint32_t RESSTATUSINTEN                         :1;                   /*!< Enable completion reset the root port */
  uint32_t RESUMEINTEN                            :1;                   /*!< Enable reactivate the device */
  uint32_t SUSPENDINTEN                           :1;                   /*!< Enable SUSPEND mode request bit */
  uint32_t HISPEEDINTEN                           :1;                   /*!< Enable completion reset and switching devices in high-speed mode */
  uint32_t DMACMPLINTEN                           :1;                   /*!< Enable completion DMA data transfer */
  uint32_t CLKUNSTBLINTEN                         :1;                   /*!< Enable interrupt, signaling an unstable clock signal UTMI and to initialize the device controller registers */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _USBDevice_USB_IRQ_ENB_bits;

/* Bit field positions: */
#define USBDevice_USB_IRQ_ENB_SOFINTEN_Pos                  0           /*!< Enable SOF packet reception */
#define USBDevice_USB_IRQ_ENB_RESSTATUSINTEN_Pos            1           /*!< Enable completion reset the root port */
#define USBDevice_USB_IRQ_ENB_RESUMEINTEN_Pos               2           /*!< Enable reactivate the device */
#define USBDevice_USB_IRQ_ENB_SUSPENDINTEN_Pos              3           /*!< Enable SUSPEND mode request bit */
#define USBDevice_USB_IRQ_ENB_HISPEEDINTEN_Pos              4           /*!< Enable completion reset and switching devices in high-speed mode */
#define USBDevice_USB_IRQ_ENB_DMACMPLINTEN_Pos              5           /*!< Enable completion DMA data transfer */
#define USBDevice_USB_IRQ_ENB_CLKUNSTBLINTEN_Pos            6           /*!< Enable interrupt, signaling an unstable clock signal UTMI and to initialize the device controller registers */

/* Bit field masks: */
#define USBDevice_USB_IRQ_ENB_SOFINTEN_Msk                  0x00000001  /*!< Enable SOF packet reception */
#define USBDevice_USB_IRQ_ENB_RESSTATUSINTEN_Msk            0x00000002  /*!< Enable completion reset the root port */
#define USBDevice_USB_IRQ_ENB_RESUMEINTEN_Msk               0x00000004  /*!< Enable reactivate the device */
#define USBDevice_USB_IRQ_ENB_SUSPENDINTEN_Msk              0x00000008  /*!< Enable SUSPEND mode request bit */
#define USBDevice_USB_IRQ_ENB_HISPEEDINTEN_Msk              0x00000010  /*!< Enable completion reset and switching devices in high-speed mode */
#define USBDevice_USB_IRQ_ENB_DMACMPLINTEN_Msk              0x00000020  /*!< Enable completion DMA data transfer */
#define USBDevice_USB_IRQ_ENB_CLKUNSTBLINTEN_Msk            0x00000040  /*!< Enable interrupt, signaling an unstable clock signal UTMI and to initialize the device controller registers */

/*-- USB_OPER: USB Operations register ---------------------------------------*/

typedef struct {
  uint32_t GEN_RESUME                             :1;                   /*!< Bit start recovery work */
  uint32_t HIGHSPEED                              :1;                   /*!< Trigger bit protocol 'Chirp' */
  uint32_t CURRENTSPEED                           :1;                   /*!< Speed indication device controller 1-High speed; 0 - Full speed */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _USBDevice_USB_OPER_bits;

/* Bit field positions: */
#define USBDevice_USB_OPER_GEN_RESUME_Pos                   0           /*!< Bit start recovery work */
#define USBDevice_USB_OPER_HIGHSPEED_Pos                    1           /*!< Trigger bit protocol 'Chirp' */
#define USBDevice_USB_OPER_CURRENTSPEED_Pos                 2           /*!< Speed indication device controller 1-High speed; 0 - Full speed */

/* Bit field masks: */
#define USBDevice_USB_OPER_GEN_RESUME_Msk                   0x00000001  /*!< Bit start recovery work */
#define USBDevice_USB_OPER_HIGHSPEED_Msk                    0x00000002  /*!< Trigger bit protocol 'Chirp' */
#define USBDevice_USB_OPER_CURRENTSPEED_Msk                 0x00000004  /*!< Speed indication device controller 1-High speed; 0 - Full speed */

/*-- USB_FRAME_CNT: USB Frame counter register -------------------------------*/

typedef struct {
  uint32_t MICRO_FRAME_COUNTER                    :3;                   /*!< Number field current a chip */
  uint32_t FRAME_COUNTER                          :11;                  /*!< Field frame counter since last SOF packet */
  uint32_t Reserved0                              :18;                  /*!< Reserved */
} _USBDevice_USB_FRAME_CNT_bits;

/* Bit field positions: */
#define USBDevice_USB_FRAME_CNT_MICRO_FRAME_COUNTER_Pos     0           /*!< Number field current a chip */
#define USBDevice_USB_FRAME_CNT_FRAME_COUNTER_Pos           3           /*!< Field frame counter since last SOF packet */

/* Bit field masks: */
#define USBDevice_USB_FRAME_CNT_MICRO_FRAME_COUNTER_Msk     0x00000007  /*!< Number field current a chip */
#define USBDevice_USB_FRAME_CNT_FRAME_COUNTER_Msk           0x00003FF8  /*!< Field frame counter since last SOF packet */

/*-- USB_ADDR: USB Address register ------------------------------------------*/

typedef struct {
  uint32_t CURRENT_ADDR                           :6;                   /*!< Field of the current address of the device */
  uint32_t USBADDR                                :1;                   /*!< Field of the current address of the device */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _USBDevice_USB_ADDR_bits;

/* Bit field positions: */
#define USBDevice_USB_ADDR_CURRENT_ADDR_Pos                 0           /*!< Field of the current address of the device */
#define USBDevice_USB_ADDR_USBADDR_Pos                      6           /*!< Field of the current address of the device */

/* Bit field masks: */
#define USBDevice_USB_ADDR_CURRENT_ADDR_Msk                 0x0000003F  /*!< Field of the current address of the device */
#define USBDevice_USB_ADDR_USBADDR_Msk                      0x00000040  /*!< Field of the current address of the device */

/*-- CEP_DATA_BUF: Data buffer for transmission register of Control EndPoint -*/

typedef struct {
  uint32_t DATA_BUF                               :16;                  /*!< Data buffer for transmission */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_DATA_BUF_bits;

/* Bit field positions: */
#define USBDevice_CEP_DATA_BUF_DATA_BUF_Pos                 0           /*!< Data buffer for transmission */

/* Bit field masks: */
#define USBDevice_CEP_DATA_BUF_DATA_BUF_Msk                 0x0000FFFF  /*!< Data buffer for transmission */

/*-- CEP_CTRL_STAT: Control register and buffer status of Control EndPoint ---*/

typedef struct {
  uint32_t NAKCLEAR                               :1;                   /*!< Receiving flag tags SETIP */
  uint32_t STALL                                  :1;                   /*!< Enable sending 'Stall' */
  uint32_t ZEROLEN                                :1;                   /*!< Enable transmission zero length packet */
  uint32_t CEPFLUSH                               :1;                   /*!< Reset buffer */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _USBDevice_CEP_CTRL_STAT_bits;

/* Bit field positions: */
#define USBDevice_CEP_CTRL_STAT_NAKCLEAR_Pos                0           /*!< Receiving flag tags SETIP */
#define USBDevice_CEP_CTRL_STAT_STALL_Pos                   1           /*!< Enable sending 'Stall' */
#define USBDevice_CEP_CTRL_STAT_ZEROLEN_Pos                 2           /*!< Enable transmission zero length packet */
#define USBDevice_CEP_CTRL_STAT_CEPFLUSH_Pos                3           /*!< Reset buffer */

/* Bit field masks: */
#define USBDevice_CEP_CTRL_STAT_NAKCLEAR_Msk                0x00000001  /*!< Receiving flag tags SETIP */
#define USBDevice_CEP_CTRL_STAT_STALL_Msk                   0x00000002  /*!< Enable sending 'Stall' */
#define USBDevice_CEP_CTRL_STAT_ZEROLEN_Msk                 0x00000004  /*!< Enable transmission zero length packet */
#define USBDevice_CEP_CTRL_STAT_CEPFLUSH_Msk                0x00000008  /*!< Reset buffer */

/*-- CEP_IRQ_ENB: Interrupt Enable buffer register of Control EndPoint -------*/

typedef struct {
  uint32_t SETUPTOKENINT                          :1;                   /*!< Enable flag deadline tags SETUP from the host */
  uint32_t SETUPPKTINT                            :1;                   /*!< Enable flag deadline Setup package from the host */
  uint32_t OUTTOKENINT                            :1;                   /*!< Enable reception end flag tags OUT from the host */
  uint32_t INTOKENINT                             :1;                   /*!< Enable reception end flag tags IN from the host */
  uint32_t PINGTOKENINT                           :1;                   /*!< Enable reception end flag tags PING from host */
  uint32_t DATAPKTTRINT                           :1;                   /*!< Enable flag successful sending of the data packet in response to the label to obtain IN ACK confirming tags */
  uint32_t DATAPKTRECINT                          :1;                   /*!< Enable flag successful reception of the data packet following the label OUT, in response to which the mark has been sent ACK */
  uint32_t NAKSENTINT                             :1;                   /*!< Enable flag closure parcel labels NAK in response to mark IN or OUT */
  uint32_t STALLSENTINT                           :1;                   /*!< Enable flag closure parcel labels STALL in response to mark IN or OUT */
  uint32_t USBERRINT                              :1;                   /*!< Enable error flag during the operation */
  uint32_t STATCMPLNINT                           :1;                   /*!< Enable flag successful completion stage 'Status' operations on the USB bus */
  uint32_t BUFFFULLINT                            :1;                   /*!< Enable flag filling control buffer */
  uint32_t BUFFEMPTYINT                           :1;                   /*!< Enable flag emptying control buffer */
  uint32_t Reserved0                              :19;                  /*!< Reserved */
} _USBDevice_CEP_IRQ_ENB_bits;

/* Bit field positions: */
#define USBDevice_CEP_IRQ_ENB_SETUPTOKENINT_Pos             0           /*!< Enable flag deadline tags SETUP from the host */
#define USBDevice_CEP_IRQ_ENB_SETUPPKTINT_Pos               1           /*!< Enable flag deadline Setup package from the host */
#define USBDevice_CEP_IRQ_ENB_OUTTOKENINT_Pos               2           /*!< Enable reception end flag tags OUT from the host */
#define USBDevice_CEP_IRQ_ENB_INTOKENINT_Pos                3           /*!< Enable reception end flag tags IN from the host */
#define USBDevice_CEP_IRQ_ENB_PINGTOKENINT_Pos              4           /*!< Enable reception end flag tags PING from host */
#define USBDevice_CEP_IRQ_ENB_DATAPKTTRINT_Pos              5           /*!< Enable flag successful sending of the data packet in response to the label to obtain IN ACK confirming tags */
#define USBDevice_CEP_IRQ_ENB_DATAPKTRECINT_Pos             6           /*!< Enable flag successful reception of the data packet following the label OUT, in response to which the mark has been sent ACK */
#define USBDevice_CEP_IRQ_ENB_NAKSENTINT_Pos                7           /*!< Enable flag closure parcel labels NAK in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_ENB_STALLSENTINT_Pos              8           /*!< Enable flag closure parcel labels STALL in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_ENB_USBERRINT_Pos                 9           /*!< Enable error flag during the operation */
#define USBDevice_CEP_IRQ_ENB_STATCMPLNINT_Pos              10          /*!< Enable flag successful completion stage 'Status' operations on the USB bus */
#define USBDevice_CEP_IRQ_ENB_BUFFFULLINT_Pos               11          /*!< Enable flag filling control buffer */
#define USBDevice_CEP_IRQ_ENB_BUFFEMPTYINT_Pos              12          /*!< Enable flag emptying control buffer */

/* Bit field masks: */
#define USBDevice_CEP_IRQ_ENB_SETUPTOKENINT_Msk             0x00000001  /*!< Enable flag deadline tags SETUP from the host */
#define USBDevice_CEP_IRQ_ENB_SETUPPKTINT_Msk               0x00000002  /*!< Enable flag deadline Setup package from the host */
#define USBDevice_CEP_IRQ_ENB_OUTTOKENINT_Msk               0x00000004  /*!< Enable reception end flag tags OUT from the host */
#define USBDevice_CEP_IRQ_ENB_INTOKENINT_Msk                0x00000008  /*!< Enable reception end flag tags IN from the host */
#define USBDevice_CEP_IRQ_ENB_PINGTOKENINT_Msk              0x00000010  /*!< Enable reception end flag tags PING from host */
#define USBDevice_CEP_IRQ_ENB_DATAPKTTRINT_Msk              0x00000020  /*!< Enable flag successful sending of the data packet in response to the label to obtain IN ACK confirming tags */
#define USBDevice_CEP_IRQ_ENB_DATAPKTRECINT_Msk             0x00000040  /*!< Enable flag successful reception of the data packet following the label OUT, in response to which the mark has been sent ACK */
#define USBDevice_CEP_IRQ_ENB_NAKSENTINT_Msk                0x00000080  /*!< Enable flag closure parcel labels NAK in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_ENB_STALLSENTINT_Msk              0x00000100  /*!< Enable flag closure parcel labels STALL in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_ENB_USBERRINT_Msk                 0x00000200  /*!< Enable error flag during the operation */
#define USBDevice_CEP_IRQ_ENB_STATCMPLNINT_Msk              0x00000400  /*!< Enable flag successful completion stage 'Status' operations on the USB bus */
#define USBDevice_CEP_IRQ_ENB_BUFFFULLINT_Msk               0x00000800  /*!< Enable flag filling control buffer */
#define USBDevice_CEP_IRQ_ENB_BUFFEMPTYINT_Msk              0x00001000  /*!< Enable flag emptying control buffer */

/*-- CEP_IRQ_STAT: Buffer interrupt flag register of Control EndPoint --------*/

typedef struct {
  uint32_t SETUPTOKENINT                          :1;                   /*!< Flag deadline tags SETUP from the host */
  uint32_t SETUPPKTINT                            :1;                   /*!< Flag deadline Setup package from the host */
  uint32_t OUTTOKENINT                            :1;                   /*!< Reception end flag tags OUT from the host */
  uint32_t INTOKENINT                             :1;                   /*!< Reception end flag tags IN from the host */
  uint32_t PINGTOKENINT                           :1;                   /*!< Reception end flag tags PING from host */
  uint32_t DATAPKTTRINT                           :1;                   /*!< Flag successful sending of the data packet in response to the label to obtain IN ACK confirming tags */
  uint32_t DATAPKTRECINT                          :1;                   /*!< Flag successful reception of the data packet following the label OUT, in response to which the mark has been sent ACK */
  uint32_t NAKSENTINT                             :1;                   /*!< Flag closure parcel labels NAK in response to mark IN or OUT */
  uint32_t STALLSENTINT                           :1;                   /*!< Flag closure parcel labels STALL in response to mark IN or OUT */
  uint32_t USBERRINT                              :1;                   /*!< The error flag during the operation */
  uint32_t STATCMPLNINT                           :1;                   /*!< Flag successful completion stage 'Status' operations on the USB bus */
  uint32_t BUFFFULLINT                            :1;                   /*!< Flag filling control buffer */
  uint32_t BUFFEMPTYINT                           :1;                   /*!< Flag control buffer emptying */
  uint32_t Reserved0                              :19;                  /*!< Reserved */
} _USBDevice_CEP_IRQ_STAT_bits;

/* Bit field positions: */
#define USBDevice_CEP_IRQ_STAT_SETUPTOKENINT_Pos            0           /*!< Flag deadline tags SETUP from the host */
#define USBDevice_CEP_IRQ_STAT_SETUPPKTINT_Pos              1           /*!< Flag deadline Setup package from the host */
#define USBDevice_CEP_IRQ_STAT_OUTTOKENINT_Pos              2           /*!< Reception end flag tags OUT from the host */
#define USBDevice_CEP_IRQ_STAT_INTOKENINT_Pos               3           /*!< Reception end flag tags IN from the host */
#define USBDevice_CEP_IRQ_STAT_PINGTOKENINT_Pos             4           /*!< Reception end flag tags PING from host */
#define USBDevice_CEP_IRQ_STAT_DATAPKTTRINT_Pos             5           /*!< Flag successful sending of the data packet in response to the label to obtain IN ACK confirming tags */
#define USBDevice_CEP_IRQ_STAT_DATAPKTRECINT_Pos            6           /*!< Flag successful reception of the data packet following the label OUT, in response to which the mark has been sent ACK */
#define USBDevice_CEP_IRQ_STAT_NAKSENTINT_Pos               7           /*!< Flag closure parcel labels NAK in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_STAT_STALLSENTINT_Pos             8           /*!< Flag closure parcel labels STALL in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_STAT_USBERRINT_Pos                9           /*!< The error flag during the operation */
#define USBDevice_CEP_IRQ_STAT_STATCMPLNINT_Pos             10          /*!< Flag successful completion stage 'Status' operations on the USB bus */
#define USBDevice_CEP_IRQ_STAT_BUFFFULLINT_Pos              11          /*!< Flag filling control buffer */
#define USBDevice_CEP_IRQ_STAT_BUFFEMPTYINT_Pos             12          /*!< Flag control buffer emptying */

/* Bit field masks: */
#define USBDevice_CEP_IRQ_STAT_SETUPTOKENINT_Msk            0x00000001  /*!< Flag deadline tags SETUP from the host */
#define USBDevice_CEP_IRQ_STAT_SETUPPKTINT_Msk              0x00000002  /*!< Flag deadline Setup package from the host */
#define USBDevice_CEP_IRQ_STAT_OUTTOKENINT_Msk              0x00000004  /*!< Reception end flag tags OUT from the host */
#define USBDevice_CEP_IRQ_STAT_INTOKENINT_Msk               0x00000008  /*!< Reception end flag tags IN from the host */
#define USBDevice_CEP_IRQ_STAT_PINGTOKENINT_Msk             0x00000010  /*!< Reception end flag tags PING from host */
#define USBDevice_CEP_IRQ_STAT_DATAPKTTRINT_Msk             0x00000020  /*!< Flag successful sending of the data packet in response to the label to obtain IN ACK confirming tags */
#define USBDevice_CEP_IRQ_STAT_DATAPKTRECINT_Msk            0x00000040  /*!< Flag successful reception of the data packet following the label OUT, in response to which the mark has been sent ACK */
#define USBDevice_CEP_IRQ_STAT_NAKSENTINT_Msk               0x00000080  /*!< Flag closure parcel labels NAK in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_STAT_STALLSENTINT_Msk             0x00000100  /*!< Flag closure parcel labels STALL in response to mark IN or OUT */
#define USBDevice_CEP_IRQ_STAT_USBERRINT_Msk                0x00000200  /*!< The error flag during the operation */
#define USBDevice_CEP_IRQ_STAT_STATCMPLNINT_Msk             0x00000400  /*!< Flag successful completion stage 'Status' operations on the USB bus */
#define USBDevice_CEP_IRQ_STAT_BUFFFULLINT_Msk              0x00000800  /*!< Flag filling control buffer */
#define USBDevice_CEP_IRQ_STAT_BUFFEMPTYINT_Msk             0x00001000  /*!< Flag control buffer emptying */

/*-- CEP_IN_XFRCNT: In transfer data count register  of Control EndPoint -----*/

typedef struct {
  uint32_t DATACOUNT                              :16;                  /*!< The number of bytes to be sent in response to a label IN */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_IN_XFRCNT_bits;

/* Bit field positions: */
#define USBDevice_CEP_IN_XFRCNT_DATACOUNT_Pos               0           /*!< The number of bytes to be sent in response to a label IN */

/* Bit field masks: */
#define USBDevice_CEP_IN_XFRCNT_DATACOUNT_Msk               0x0000FFFF  /*!< The number of bytes to be sent in response to a label IN */

/*-- CEP_OUT_XFRCNT: Out-transfer data count register of Control EndPoint ----*/

typedef struct {
  uint32_t DATACOUNT                              :16;                  /*!< The number of bytes received of data */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_OUT_XFRCNT_bits;

/* Bit field positions: */
#define USBDevice_CEP_OUT_XFRCNT_DATACOUNT_Pos              0           /*!< The number of bytes received of data */

/* Bit field masks: */
#define USBDevice_CEP_OUT_XFRCNT_DATACOUNT_Msk              0x0000FFFF  /*!< The number of bytes received of data */

/*-- CEP_SETUP1_0: Register zero and first byte packet Setup  of Control EndPoint */

typedef struct {
  uint32_t SETUPPKT_0B                            :8;                   /*!< destination */
  uint32_t SETUPPKT_1B                            :8;                   /*!< The first byte of the packet Setup */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_SETUP1_0_bits;

/* Bit field positions: */
#define USBDevice_CEP_SETUP1_0_SETUPPKT_0B_Pos              0           /*!< destination */
#define USBDevice_CEP_SETUP1_0_SETUPPKT_1B_Pos              8           /*!< The first byte of the packet Setup */

/* Bit field masks: */
#define USBDevice_CEP_SETUP1_0_SETUPPKT_0B_Msk              0x000000FF  /*!< destination */
#define USBDevice_CEP_SETUP1_0_SETUPPKT_1B_Msk              0x0000FF00  /*!< The first byte of the packet Setup */

/*-- CEP_SETUP3_2: Register 2nd and 3rd bytes of the packet Setup  of Control EndPoint */

typedef struct {
  uint32_t SETUPPKT_2B                            :8;                   /*!< Low byte field wValue */
  uint32_t SETUPPKT_3B                            :8;                   /*!< High byte field wValue */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_SETUP3_2_bits;

/* Bit field positions: */
#define USBDevice_CEP_SETUP3_2_SETUPPKT_2B_Pos              0           /*!< Low byte field wValue */
#define USBDevice_CEP_SETUP3_2_SETUPPKT_3B_Pos              8           /*!< High byte field wValue */

/* Bit field masks: */
#define USBDevice_CEP_SETUP3_2_SETUPPKT_2B_Msk              0x000000FF  /*!< Low byte field wValue */
#define USBDevice_CEP_SETUP3_2_SETUPPKT_3B_Msk              0x0000FF00  /*!< High byte field wValue */

/*-- CEP_SETUP5_4: Register 4th and 5th bytes of the packet Setup  of Control EndPoint */

typedef struct {
  uint32_t SETUPPKT_4B                            :8;                   /*!< Low byte field windex */
  uint32_t SETUPPKT_5B                            :8;                   /*!< High byte field windex */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_SETUP5_4_bits;

/* Bit field positions: */
#define USBDevice_CEP_SETUP5_4_SETUPPKT_4B_Pos              0           /*!< Low byte field windex */
#define USBDevice_CEP_SETUP5_4_SETUPPKT_5B_Pos              8           /*!< High byte field windex */

/* Bit field masks: */
#define USBDevice_CEP_SETUP5_4_SETUPPKT_4B_Msk              0x000000FF  /*!< Low byte field windex */
#define USBDevice_CEP_SETUP5_4_SETUPPKT_5B_Msk              0x0000FF00  /*!< High byte field windex */

/*-- CEP_SETUP7_6: Register on the 6th and 7th byte packet Setup of Control EndPoint */

typedef struct {
  uint32_t SETUPPKT_6B                            :8;                   /*!< Low byte field wLength */
  uint32_t SETUPPKT_7B                            :8;                   /*!< High byte field wLength */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_SETUP7_6_bits;

/* Bit field positions: */
#define USBDevice_CEP_SETUP7_6_SETUPPKT_6B_Pos              0           /*!< Low byte field wLength */
#define USBDevice_CEP_SETUP7_6_SETUPPKT_7B_Pos              8           /*!< High byte field wLength */

/* Bit field masks: */
#define USBDevice_CEP_SETUP7_6_SETUPPKT_6B_Msk              0x000000FF  /*!< Low byte field wLength */
#define USBDevice_CEP_SETUP7_6_SETUPPKT_7B_Msk              0x0000FF00  /*!< High byte field wLength */

/*-- CEP_START_ADDR: Control EndPoint RAM start Addr register ----------------*/

typedef struct {
  uint32_t STARTADDR                              :16;                  /*!< Beginning of the address space */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_START_ADDR_bits;

/* Bit field positions: */
#define USBDevice_CEP_START_ADDR_STARTADDR_Pos              0           /*!< Beginning of the address space */

/* Bit field masks: */
#define USBDevice_CEP_START_ADDR_STARTADDR_Msk              0x0000FFFF  /*!< Beginning of the address space */

/*-- CEP_END_ADDR: Control EndPoint RAM end Addr register --------------------*/

typedef struct {
  uint32_t ENDADDR                                :16;                  /*!< The end of the address space */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_CEP_END_ADDR_bits;

/* Bit field positions: */
#define USBDevice_CEP_END_ADDR_ENDADDR_Pos                  0           /*!< The end of the address space */

/* Bit field masks: */
#define USBDevice_CEP_END_ADDR_ENDADDR_Msk                  0x0000FFFF  /*!< The end of the address space */

/*-- DMA_CTRL_STS: Register control DMA --------------------------------------*/

typedef struct {
  uint32_t DMA_EP_ADDR                            :4;                   /*!< Buffer address accessed by the DMA */
  uint32_t DMARW                                  :1;                   /*!< Type DMA operations 1-Read, 0-Write */
  uint32_t DMAEN                                  :1;                   /*!< Enable DMA */
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _USBDevice_DMA_CTRL_STS_bits;

/* Bit field positions: */
#define USBDevice_DMA_CTRL_STS_DMA_EP_ADDR_Pos              0           /*!< Buffer address accessed by the DMA */
#define USBDevice_DMA_CTRL_STS_DMARW_Pos                    4           /*!< Type DMA operations 1-Read, 0-Write */
#define USBDevice_DMA_CTRL_STS_DMAEN_Pos                    5           /*!< Enable DMA */

/* Bit field masks: */
#define USBDevice_DMA_CTRL_STS_DMA_EP_ADDR_Msk              0x0000000F  /*!< Buffer address accessed by the DMA */
#define USBDevice_DMA_CTRL_STS_DMARW_Msk                    0x00000010  /*!< Type DMA operations 1-Read, 0-Write */
#define USBDevice_DMA_CTRL_STS_DMAEN_Msk                    0x00000020  /*!< Enable DMA */

/*-- DMA_CNT: DMA Count byte Register ----------------------------------------*/

typedef struct {
  uint32_t DMA_CNT                                :16;                  /*!< The number of words transmitted by DMA */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_DMA_CNT_bits;

/* Bit field positions: */
#define USBDevice_DMA_CNT_DMA_CNT_Pos                       0           /*!< The number of words transmitted by DMA */

/* Bit field masks: */
#define USBDevice_DMA_CNT_DMA_CNT_Msk                       0x0000FFFF  /*!< The number of words transmitted by DMA */

/*-- DATA_BUF: EndPoint Data Register ----------------------------------------*/

typedef struct {
  uint32_t DATA                                   :16;                  /*!< Data exchange with the buffer */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_DATA_BUF_bits;

/* Bit field positions: */
#define USBDevice_DATA_BUF_DATA_Pos                         0           /*!< Data exchange with the buffer */

/* Bit field masks: */
#define USBDevice_DATA_BUF_DATA_Msk                         0x0000FFFF  /*!< Data exchange with the buffer */

/*-- IRQ_STAT: Interrupt flag register no control buffer ---------------------*/

typedef struct {
  uint32_t BUFFFULLINT                            :1;                   /*!< Flag buffer fill */
  uint32_t BUFFEMPTYINT                           :1;                   /*!< Buffer empty flag */
  uint32_t SHORTPKTTRINT                          :1;                   /*!< Flag size of the last packet */
  uint32_t DATAPKTTRINT                           :1;                   /*!< Flag to send a data packet from the buffer to the host */
  uint32_t DATAPKTRECINT                          :1;                   /*!< Flag successful reception of a data packet from a host */
  uint32_t OUTTOKENINT                            :1;                   /*!< Receiving flag tags OUT from the host */
  uint32_t INTOKENINT                             :1;                   /*!< Receiving flag tags IN from the host */
  uint32_t PINGTOKENINT                           :1;                   /*!< Receiving flag tags PING from the host */
  uint32_t NACKSENTINT                            :1;                   /*!< Flag unsent last packet */
  uint32_t STALLSENTINT                           :1;                   /*!< Flag Uncommitted last packet */
  uint32_t NYETSENTINT                            :1;                   /*!< Flag lack of free memory to receive the next data packet */
  uint32_t ERRSENTINT                             :1;                   /*!< Flag of any error during the operation */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _USBDevice_IRQ_STAT_bits;

/* Bit field positions: */
#define USBDevice_IRQ_STAT_BUFFFULLINT_Pos                  0           /*!< Flag buffer fill */
#define USBDevice_IRQ_STAT_BUFFEMPTYINT_Pos                 1           /*!< Buffer empty flag */
#define USBDevice_IRQ_STAT_SHORTPKTTRINT_Pos                2           /*!< Flag size of the last packet */
#define USBDevice_IRQ_STAT_DATAPKTTRINT_Pos                 3           /*!< Flag to send a data packet from the buffer to the host */
#define USBDevice_IRQ_STAT_DATAPKTRECINT_Pos                4           /*!< Flag successful reception of a data packet from a host */
#define USBDevice_IRQ_STAT_OUTTOKENINT_Pos                  5           /*!< Receiving flag tags OUT from the host */
#define USBDevice_IRQ_STAT_INTOKENINT_Pos                   6           /*!< Receiving flag tags IN from the host */
#define USBDevice_IRQ_STAT_PINGTOKENINT_Pos                 7           /*!< Receiving flag tags PING from the host */
#define USBDevice_IRQ_STAT_NACKSENTINT_Pos                  8           /*!< Flag unsent last packet */
#define USBDevice_IRQ_STAT_STALLSENTINT_Pos                 9           /*!< Flag Uncommitted last packet */
#define USBDevice_IRQ_STAT_NYETSENTINT_Pos                  10          /*!< Flag lack of free memory to receive the next data packet */
#define USBDevice_IRQ_STAT_ERRSENTINT_Pos                   11          /*!< Flag of any error during the operation */

/* Bit field masks: */
#define USBDevice_IRQ_STAT_BUFFFULLINT_Msk                  0x00000001  /*!< Flag buffer fill */
#define USBDevice_IRQ_STAT_BUFFEMPTYINT_Msk                 0x00000002  /*!< Buffer empty flag */
#define USBDevice_IRQ_STAT_SHORTPKTTRINT_Msk                0x00000004  /*!< Flag size of the last packet */
#define USBDevice_IRQ_STAT_DATAPKTTRINT_Msk                 0x00000008  /*!< Flag to send a data packet from the buffer to the host */
#define USBDevice_IRQ_STAT_DATAPKTRECINT_Msk                0x00000010  /*!< Flag successful reception of a data packet from a host */
#define USBDevice_IRQ_STAT_OUTTOKENINT_Msk                  0x00000020  /*!< Receiving flag tags OUT from the host */
#define USBDevice_IRQ_STAT_INTOKENINT_Msk                   0x00000040  /*!< Receiving flag tags IN from the host */
#define USBDevice_IRQ_STAT_PINGTOKENINT_Msk                 0x00000080  /*!< Receiving flag tags PING from the host */
#define USBDevice_IRQ_STAT_NACKSENTINT_Msk                  0x00000100  /*!< Flag unsent last packet */
#define USBDevice_IRQ_STAT_STALLSENTINT_Msk                 0x00000200  /*!< Flag Uncommitted last packet */
#define USBDevice_IRQ_STAT_NYETSENTINT_Msk                  0x00000400  /*!< Flag lack of free memory to receive the next data packet */
#define USBDevice_IRQ_STAT_ERRSENTINT_Msk                   0x00000800  /*!< Flag of any error during the operation */

/*-- IRQ_ENB: Enable register Interrupt no control buffer --------------------*/

typedef struct {
  uint32_t BUFFFULLINTEN                          :1;                   /*!< Enable flag buffer fill */
  uint32_t BUFFEMPTYINTEN                         :1;                   /*!< Enable buffer empty flag */
  uint32_t SHORTPKTTRINTEN                        :1;                   /*!< Enable flag size of the last packet */
  uint32_t DATAPKTTRINTEN                         :1;                   /*!< Enable flag to send a data packet from the buffer to the host */
  uint32_t DATAPKTRECINTEN                        :1;                   /*!< Enable flag successful reception of a data packet from a host */
  uint32_t OUTTOKENINTEN                          :1;                   /*!< Enable receiving flag tags OUT from the host */
  uint32_t INTOKENINTEN                           :1;                   /*!< Enable receiving flag tags IN from the host */
  uint32_t PINGTOKENINTEN                         :1;                   /*!< Enable  receiving flag tags PING from the host */
  uint32_t NACKSENTINTEN                          :1;                   /*!< Enable flag unsent last packet */
  uint32_t STALLSENTINTEN                         :1;                   /*!< Enable flag Uncommitted last packet */
  uint32_t NYETSENTINTEN                          :1;                   /*!< Enable flag lack of free memory to receive the next data packet */
  uint32_t ERRSENTINTEN                           :1;                   /*!< Enable flag of any error during the operation */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _USBDevice_IRQ_ENB_bits;

/* Bit field positions: */
#define USBDevice_IRQ_ENB_BUFFFULLINTEN_Pos                 0           /*!< Enable flag buffer fill */
#define USBDevice_IRQ_ENB_BUFFEMPTYINTEN_Pos                1           /*!< Enable buffer empty flag */
#define USBDevice_IRQ_ENB_SHORTPKTTRINTEN_Pos               2           /*!< Enable flag size of the last packet */
#define USBDevice_IRQ_ENB_DATAPKTTRINTEN_Pos                3           /*!< Enable flag to send a data packet from the buffer to the host */
#define USBDevice_IRQ_ENB_DATAPKTRECINTEN_Pos               4           /*!< Enable flag successful reception of a data packet from a host */
#define USBDevice_IRQ_ENB_OUTTOKENINTEN_Pos                 5           /*!< Enable receiving flag tags OUT from the host */
#define USBDevice_IRQ_ENB_INTOKENINTEN_Pos                  6           /*!< Enable receiving flag tags IN from the host */
#define USBDevice_IRQ_ENB_PINGTOKENINTEN_Pos                7           /*!< Enable  receiving flag tags PING from the host */
#define USBDevice_IRQ_ENB_NACKSENTINTEN_Pos                 8           /*!< Enable flag unsent last packet */
#define USBDevice_IRQ_ENB_STALLSENTINTEN_Pos                9           /*!< Enable flag Uncommitted last packet */
#define USBDevice_IRQ_ENB_NYETSENTINTEN_Pos                 10          /*!< Enable flag lack of free memory to receive the next data packet */
#define USBDevice_IRQ_ENB_ERRSENTINTEN_Pos                  11          /*!< Enable flag of any error during the operation */

/* Bit field masks: */
#define USBDevice_IRQ_ENB_BUFFFULLINTEN_Msk                 0x00000001  /*!< Enable flag buffer fill */
#define USBDevice_IRQ_ENB_BUFFEMPTYINTEN_Msk                0x00000002  /*!< Enable buffer empty flag */
#define USBDevice_IRQ_ENB_SHORTPKTTRINTEN_Msk               0x00000004  /*!< Enable flag size of the last packet */
#define USBDevice_IRQ_ENB_DATAPKTTRINTEN_Msk                0x00000008  /*!< Enable flag to send a data packet from the buffer to the host */
#define USBDevice_IRQ_ENB_DATAPKTRECINTEN_Msk               0x00000010  /*!< Enable flag successful reception of a data packet from a host */
#define USBDevice_IRQ_ENB_OUTTOKENINTEN_Msk                 0x00000020  /*!< Enable receiving flag tags OUT from the host */
#define USBDevice_IRQ_ENB_INTOKENINTEN_Msk                  0x00000040  /*!< Enable receiving flag tags IN from the host */
#define USBDevice_IRQ_ENB_PINGTOKENINTEN_Msk                0x00000080  /*!< Enable  receiving flag tags PING from the host */
#define USBDevice_IRQ_ENB_NACKSENTINTEN_Msk                 0x00000100  /*!< Enable flag unsent last packet */
#define USBDevice_IRQ_ENB_STALLSENTINTEN_Msk                0x00000200  /*!< Enable flag Uncommitted last packet */
#define USBDevice_IRQ_ENB_NYETSENTINTEN_Msk                 0x00000400  /*!< Enable flag lack of free memory to receive the next data packet */
#define USBDevice_IRQ_ENB_ERRSENTINTEN_Msk                  0x00000800  /*!< Enable flag of any error during the operation */

/*-- AVAIL_CNT: EndPoint Available count register ----------------------------*/

typedef struct {
  uint32_t BUFFBYTENUM                            :12;                  /*!< Number of bytes in the buffer */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _USBDevice_AVAIL_CNT_bits;

/* Bit field positions: */
#define USBDevice_AVAIL_CNT_BUFFBYTENUM_Pos                 0           /*!< Number of bytes in the buffer */

/* Bit field masks: */
#define USBDevice_AVAIL_CNT_BUFFBYTENUM_Msk                 0x00000FFF  /*!< Number of bytes in the buffer */

/*-- RSP_SC: EndPoint Response Set/Clear register ----------------------------*/

typedef struct {
  uint32_t BUFFFLUSH                              :1;                   /*!< Reset bit in the buffer and register EP_AVAIL_CNT */
  uint32_t MODE                                   :2;                   /*!< Field mode of operation of the buffer type ID */
  uint32_t ENDPOINTTOGGL                          :1;                   /*!< Control bit by bit DATATOGGLE */
  uint32_t ENDPOINTHALT                           :1;                   /*!< Select bit answer to any label from the host */
  uint32_t ZEROLENIN                              :1;                   /*!< Select bit answer to mark IN */
  uint32_t PKTEND                                 :1;                   /*!< Indicator number of bytes */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _USBDevice_RSP_SC_bits;

/* Bit field positions: */
#define USBDevice_RSP_SC_BUFFFLUSH_Pos                      0           /*!< Reset bit in the buffer and register EP_AVAIL_CNT */
#define USBDevice_RSP_SC_MODE_Pos                           1           /*!< Field mode of operation of the buffer type ID */
#define USBDevice_RSP_SC_ENDPOINTTOGGL_Pos                  3           /*!< Control bit by bit DATATOGGLE */
#define USBDevice_RSP_SC_ENDPOINTHALT_Pos                   4           /*!< Select bit answer to any label from the host */
#define USBDevice_RSP_SC_ZEROLENIN_Pos                      5           /*!< Select bit answer to mark IN */
#define USBDevice_RSP_SC_PKTEND_Pos                         6           /*!< Indicator number of bytes */

/* Bit field masks: */
#define USBDevice_RSP_SC_BUFFFLUSH_Msk                      0x00000001  /*!< Reset bit in the buffer and register EP_AVAIL_CNT */
#define USBDevice_RSP_SC_MODE_Msk                           0x00000006  /*!< Field mode of operation of the buffer type ID */
#define USBDevice_RSP_SC_ENDPOINTTOGGL_Msk                  0x00000008  /*!< Control bit by bit DATATOGGLE */
#define USBDevice_RSP_SC_ENDPOINTHALT_Msk                   0x00000010  /*!< Select bit answer to any label from the host */
#define USBDevice_RSP_SC_ZEROLENIN_Msk                      0x00000020  /*!< Select bit answer to mark IN */
#define USBDevice_RSP_SC_PKTEND_Msk                         0x00000040  /*!< Indicator number of bytes */

/*-- MPS: EndPoint maximum packet size register ------------------------------*/

typedef struct {
  uint32_t MAXPKTSIZE                             :16;                  /*!< Maximum packet size */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_MPS_bits;

/* Bit field positions: */
#define USBDevice_MPS_MAXPKTSIZE_Pos                        0           /*!< Maximum packet size */

/* Bit field masks: */
#define USBDevice_MPS_MAXPKTSIZE_Msk                        0x0000FFFF  /*!< Maximum packet size */

/*-- CNT: EndPoint Transfer count register -----------------------------------*/

typedef struct {
  uint32_t EP_TFR_CNT                             :8;                   /*!< Field number of bytes to send to the host mode Manual-Validate */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _USBDevice_CNT_bits;

/* Bit field positions: */
#define USBDevice_CNT_EP_TFR_CNT_Pos                        0           /*!< Field number of bytes to send to the host mode Manual-Validate */

/* Bit field masks: */
#define USBDevice_CNT_EP_TFR_CNT_Msk                        0x000000FF  /*!< Field number of bytes to send to the host mode Manual-Validate */

/*-- USB_EP_CFG: EndPoint configuration register -----------------------------*/

typedef struct {
  uint32_t EP_VALID                               :1;                   /*!< Resolution of buffer */
  uint32_t EP_TYPE                                :2;                   /*!< Buffer type */
  uint32_t EP_DIR                                 :1;                   /*!< Field of type (direction) buffer */
  uint32_t EP_NUM                                 :4;                   /*!< Number field buffer */
  uint32_t MULT                                   :2;                   /*!< Field number of operations performed in one micro frame */
  uint32_t Reserved0                              :22;                  /*!< Reserved */
} _USBDevice_USB_EP_CFG_bits;

/* Bit field positions: */
#define USBDevice_USB_EP_CFG_EP_VALID_Pos                   0           /*!< Resolution of buffer */
#define USBDevice_USB_EP_CFG_EP_TYPE_Pos                    1           /*!< Buffer type */
#define USBDevice_USB_EP_CFG_EP_DIR_Pos                     3           /*!< Field of type (direction) buffer */
#define USBDevice_USB_EP_CFG_EP_NUM_Pos                     4           /*!< Number field buffer */
#define USBDevice_USB_EP_CFG_MULT_Pos                       8           /*!< Field number of operations performed in one micro frame */

/* Bit field masks: */
#define USBDevice_USB_EP_CFG_EP_VALID_Msk                   0x00000001  /*!< Resolution of buffer */
#define USBDevice_USB_EP_CFG_EP_TYPE_Msk                    0x00000006  /*!< Buffer type */
#define USBDevice_USB_EP_CFG_EP_DIR_Msk                     0x00000008  /*!< Field of type (direction) buffer */
#define USBDevice_USB_EP_CFG_EP_NUM_Msk                     0x000000F0  /*!< Number field buffer */
#define USBDevice_USB_EP_CFG_MULT_Msk                       0x00000300  /*!< Field number of operations performed in one micro frame */

/*-- START_ADDR: EndPoint RAM start addres register --------------------------*/

typedef struct {
  uint32_t STARTADDR                              :16;                  /*!< Start address space allocated for the buffer */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_START_ADDR_bits;

/* Bit field positions: */
#define USBDevice_START_ADDR_STARTADDR_Pos                  0           /*!< Start address space allocated for the buffer */

/* Bit field masks: */
#define USBDevice_START_ADDR_STARTADDR_Msk                  0x0000FFFF  /*!< Start address space allocated for the buffer */

/*-- END_ADDR: EndPoint RAM end addres register ------------------------------*/

typedef struct {
  uint32_t ENDADDR                                :16;                  /*!< The end of address space allocated for the buffer */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USBDevice_END_ADDR_bits;

/* Bit field positions: */
#define USBDevice_END_ADDR_ENDADDR_Pos                      0           /*!< The end of address space allocated for the buffer */

/* Bit field masks: */
#define USBDevice_END_ADDR_ENDADDR_Msk                      0x0000FFFF  /*!< The end of address space allocated for the buffer */

/*-- Register map for USBDevice peripheral -----------------------------------*/

typedef struct {
  union {                                                               /*!< EndPoint Data Register */
    __IO uint32_t DATA_BUF;                                             /*!< DATA_BUF    : type used for word access */
    __IO _USBDevice_DATA_BUF_bits DATA_BUF_bit;                         /*!< DATA_BUF_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt flag register no control buffer */
    __IO uint32_t IRQ_STAT;                                             /*!< IRQ_STAT    : type used for word access */
    __IO _USBDevice_IRQ_STAT_bits IRQ_STAT_bit;                         /*!< IRQ_STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Enable register Interrupt no control buffer */
    __IO uint32_t IRQ_ENB;                                              /*!< IRQ_ENB    : type used for word access */
    __IO _USBDevice_IRQ_ENB_bits IRQ_ENB_bit;                           /*!< IRQ_ENB_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint Available count register */
    __I  uint32_t AVAIL_CNT;                                            /*!< AVAIL_CNT    : type used for word access */
    __I  _USBDevice_AVAIL_CNT_bits AVAIL_CNT_bit;                       /*!< AVAIL_CNT_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint Response Set/Clear register */
    __IO uint32_t RSP_SC;                                               /*!< RSP_SC    : type used for word access */
    __IO _USBDevice_RSP_SC_bits RSP_SC_bit;                             /*!< RSP_SC_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint maximum packet size register */
    __IO uint32_t MPS;                                                  /*!< MPS    : type used for word access */
    __IO _USBDevice_MPS_bits MPS_bit;                                   /*!< MPS_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint Transfer count register */
    __IO uint32_t CNT;                                                  /*!< CNT    : type used for word access */
    __IO _USBDevice_CNT_bits CNT_bit;                                   /*!< CNT_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint configuration register */
    __IO uint32_t USB_EP_CFG;                                           /*!< USB_EP_CFG    : type used for word access */
    __IO _USBDevice_USB_EP_CFG_bits USB_EP_CFG_bit;                     /*!< USB_EP_CFG_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint RAM start addres register */
    __IO uint32_t START_ADDR;                                           /*!< START_ADDR    : type used for word access */
    __IO _USBDevice_START_ADDR_bits START_ADDR_bit;                     /*!< START_ADDR_bit: structure used for bit access */
  };
  union {                                                               /*!< EndPoint RAM end addres register */
    __IO uint32_t END_ADDR;                                             /*!< END_ADDR    : type used for word access */
    __IO _USBDevice_END_ADDR_bits END_ADDR_bit;                         /*!< END_ADDR_bit: structure used for bit access */
  };
} NT_USB_EP_TypeDef;

typedef struct {
  union {                                                               /*!< Interrupt status register */
    __IO uint32_t IRQ_STAT_L;                                           /*!< IRQ_STAT_L    : type used for word access */
    __IO _USBDevice_IRQ_STAT_L_bits IRQ_STAT_L_bit;                     /*!< IRQ_STAT_L_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< Interrupt enable register */
    __IO uint32_t IRQ_ENB_L;                                            /*!< IRQ_ENB_L    : type used for word access */
    __IO _USBDevice_IRQ_ENB_L_bits IRQ_ENB_L_bit;                       /*!< IRQ_ENB_L_bit: structure used for bit access */
  };
  uint32_t Reserved1;                                                   /*!< Reserved */
  union {                                                               /*!< USB Interrupt status register */
    __IO uint32_t USB_IRQ_STAT;                                         /*!< USB_IRQ_STAT    : type used for word access */
    __IO _USBDevice_USB_IRQ_STAT_bits USB_IRQ_STAT_bit;                 /*!< USB_IRQ_STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< USB Interrupt enable register */
    __IO uint32_t USB_IRQ_ENB;                                          /*!< USB_IRQ_ENB    : type used for word access */
    __IO _USBDevice_USB_IRQ_ENB_bits USB_IRQ_ENB_bit;                   /*!< USB_IRQ_ENB_bit: structure used for bit access */
  };
  union {                                                               /*!< USB Operations register */
    __IO uint32_t USB_OPER;                                             /*!< USB_OPER    : type used for word access */
    __IO _USBDevice_USB_OPER_bits USB_OPER_bit;                         /*!< USB_OPER_bit: structure used for bit access */
  };
  union {                                                               /*!< USB Frame counter register */
    __I  uint32_t USB_FRAME_CNT;                                        /*!< USB_FRAME_CNT    : type used for word access */
    __I  _USBDevice_USB_FRAME_CNT_bits USB_FRAME_CNT_bit;               /*!< USB_FRAME_CNT_bit: structure used for bit access */
  };
  union {                                                               /*!< USB Address register */
    __IO uint32_t USB_ADDR;                                             /*!< USB_ADDR    : type used for word access */
    __IO _USBDevice_USB_ADDR_bits USB_ADDR_bit;                         /*!< USB_ADDR_bit: structure used for bit access */
  };
  uint32_t Reserved2;                                                   /*!< Reserved */
  union {                                                               /*!< Data buffer for transmission register of Control EndPoint */
    __IO uint32_t CEP_DATA_BUF;                                         /*!< CEP_DATA_BUF    : type used for word access */
    __IO _USBDevice_CEP_DATA_BUF_bits CEP_DATA_BUF_bit;                 /*!< CEP_DATA_BUF_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register and buffer status of Control EndPoint */
    __IO uint32_t CEP_CTRL_STAT;                                        /*!< CEP_CTRL_STAT    : type used for word access */
    __IO _USBDevice_CEP_CTRL_STAT_bits CEP_CTRL_STAT_bit;               /*!< CEP_CTRL_STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Enable buffer register of Control EndPoint */
    __IO uint32_t CEP_IRQ_ENB;                                          /*!< CEP_IRQ_ENB    : type used for word access */
    __IO _USBDevice_CEP_IRQ_ENB_bits CEP_IRQ_ENB_bit;                   /*!< CEP_IRQ_ENB_bit: structure used for bit access */
  };
  union {                                                               /*!< Buffer interrupt flag register of Control EndPoint */
    __IO uint32_t CEP_IRQ_STAT;                                         /*!< CEP_IRQ_STAT    : type used for word access */
    __IO _USBDevice_CEP_IRQ_STAT_bits CEP_IRQ_STAT_bit;                 /*!< CEP_IRQ_STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< In transfer data count register  of Control EndPoint */
    __IO uint32_t CEP_IN_XFRCNT;                                        /*!< CEP_IN_XFRCNT    : type used for word access */
    __IO _USBDevice_CEP_IN_XFRCNT_bits CEP_IN_XFRCNT_bit;               /*!< CEP_IN_XFRCNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Out-transfer data count register of Control EndPoint */
    __I  uint32_t CEP_OUT_XFRCNT;                                       /*!< CEP_OUT_XFRCNT    : type used for word access */
    __I  _USBDevice_CEP_OUT_XFRCNT_bits CEP_OUT_XFRCNT_bit;             /*!< CEP_OUT_XFRCNT_bit: structure used for bit access */
  };
  uint32_t Reserved3;                                                   /*!< Reserved */
  union {                                                               /*!< Register zero and first byte packet Setup  of Control EndPoint */
    __I  uint32_t CEP_SETUP1_0;                                         /*!< CEP_SETUP1_0    : type used for word access */
    __I  _USBDevice_CEP_SETUP1_0_bits CEP_SETUP1_0_bit;                 /*!< CEP_SETUP1_0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register 2nd and 3rd bytes of the packet Setup  of Control EndPoint */
    __I  uint32_t CEP_SETUP3_2;                                         /*!< CEP_SETUP3_2    : type used for word access */
    __I  _USBDevice_CEP_SETUP3_2_bits CEP_SETUP3_2_bit;                 /*!< CEP_SETUP3_2_bit: structure used for bit access */
  };
  union {                                                               /*!< Register 4th and 5th bytes of the packet Setup  of Control EndPoint */
    __I  uint32_t CEP_SETUP5_4;                                         /*!< CEP_SETUP5_4    : type used for word access */
    __I  _USBDevice_CEP_SETUP5_4_bits CEP_SETUP5_4_bit;                 /*!< CEP_SETUP5_4_bit: structure used for bit access */
  };
  union {                                                               /*!< Register on the 6th and 7th byte packet Setup of Control EndPoint */
    __I  uint32_t CEP_SETUP7_6;                                         /*!< CEP_SETUP7_6    : type used for word access */
    __I  _USBDevice_CEP_SETUP7_6_bits CEP_SETUP7_6_bit;                 /*!< CEP_SETUP7_6_bit: structure used for bit access */
  };
  union {                                                               /*!< Control EndPoint RAM start Addr register */
    __IO uint32_t CEP_START_ADDR;                                       /*!< CEP_START_ADDR    : type used for word access */
    __IO _USBDevice_CEP_START_ADDR_bits CEP_START_ADDR_bit;             /*!< CEP_START_ADDR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control EndPoint RAM end Addr register */
    __IO uint32_t CEP_END_ADDR;                                         /*!< CEP_END_ADDR    : type used for word access */
    __IO _USBDevice_CEP_END_ADDR_bits CEP_END_ADDR_bit;                 /*!< CEP_END_ADDR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register control DMA */
    __IO uint32_t DMA_CTRL_STS;                                         /*!< DMA_CTRL_STS    : type used for word access */
    __IO _USBDevice_DMA_CTRL_STS_bits DMA_CTRL_STS_bit;                 /*!< DMA_CTRL_STS_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Count byte Register */
    __IO uint32_t DMA_CNT;                                              /*!< DMA_CNT    : type used for word access */
    __IO _USBDevice_DMA_CNT_bits DMA_CNT_bit;                           /*!< DMA_CNT_bit: structure used for bit access */
  };
  NT_USB_EP_TypeDef USB_EP[2];
  uint32_t Reserved4[403];                                              /*!< Reserved */
  __IO uint32_t AHB_DMA_ADDR;                                           /*!< AHB addr register */
} NT_USBDevice_TypeDef;

/******************************************************************************/
/*                       USB OTG controller registers                         */
/******************************************************************************/

/*-- OTG_IRQ_STAT: USB OTG interrupt flag register ---------------------------*/

typedef struct {
  uint32_t VBUSERR                                :1;                   /*!< Enable interrupt a_clr_err */
  uint32_t SPRDETECTED                            :1;                   /*!< Enable interrupt srp_detected */
  uint32_t HANDOFF_INTR                           :1;                   /*!< Interrupt when the output state Id */
  uint32_t SPR_FAIL                               :1;                   /*!< Indication of lack of response from the host mode operation Device */
  uint32_t DEVICE                                 :1;                   /*!< Set when the kernel is running as a device controller */
  uint32_t HOST                                   :1;                   /*!< Set when the kernel is running as a host controller */
  uint32_t A_BUSREQ                               :1;                   /*!< Request A device control bus */
  uint32_t A_BUSDROP                              :1;                   /*!< Set when the device A, you must disconnect bus */
  uint32_t A_HNPEN                                :1;                   /*!< Resolution run HNP device A */
  uint32_t B_HNPEN                                :1;                   /*!< Resolution run HNP device A */
  uint32_t B_BUSREQ                               :1;                   /*!< Request bus control device B */
  uint32_t A_SUSPENDREQ                           :1;                   /*!< Request A suspension device */
  uint32_t A_DEVICE                               :1;                   /*!< Display device A connections */
  uint32_t B_DEVICE                               :1;                   /*!< Display device B connections */
  uint32_t SESSION_FAIL                           :1;                   /*!< Bit is device B, A when the device interrupts the signal Vbus. */
  uint32_t SUSPENDEN                              :1;                   /*!< Request */
  uint32_t A_DEVCHANGE                            :1;                   /*!< Bit is set when there is a change device A. At the same time, the appropriate interrupt enable bit. */
  uint32_t B_DEVCHANGE                            :1;                   /*!< Bit is set when you change the display B. Simultaneously, the appropriate interrupt enable bit */
  uint32_t DEVSYNC                                :1;                   /*!< When resynchronization device this bit is set and the corresponding interrupt enable bit */
  uint32_t HOSTSYNC                               :1;                   /*!< When resynchronization host this bit is set and the corresponding interrupt enable bit */
  uint32_t DISCON                                 :1;                   /*!< Bit is set when disconnected not in suspend mode */
  uint32_t Reserved0                              :11;                  /*!< Reserved */
} _USBOTG_OTG_IRQ_STAT_bits;

/* Bit field positions: */
#define USBOTG_OTG_IRQ_STAT_VBUSERR_Pos                     0           /*!< Enable interrupt a_clr_err */
#define USBOTG_OTG_IRQ_STAT_SPRDETECTED_Pos                 1           /*!< Enable interrupt srp_detected */
#define USBOTG_OTG_IRQ_STAT_HANDOFF_INTR_Pos                2           /*!< Interrupt when the output state Id */
#define USBOTG_OTG_IRQ_STAT_SPR_FAIL_Pos                    3           /*!< Indication of lack of response from the host mode operation Device */
#define USBOTG_OTG_IRQ_STAT_DEVICE_Pos                      4           /*!< Set when the kernel is running as a device controller */
#define USBOTG_OTG_IRQ_STAT_HOST_Pos                        5           /*!< Set when the kernel is running as a host controller */
#define USBOTG_OTG_IRQ_STAT_A_BUSREQ_Pos                    6           /*!< Request A device control bus */
#define USBOTG_OTG_IRQ_STAT_A_BUSDROP_Pos                   7           /*!< Set when the device A, you must disconnect bus */
#define USBOTG_OTG_IRQ_STAT_A_HNPEN_Pos                     8           /*!< Resolution run HNP device A */
#define USBOTG_OTG_IRQ_STAT_B_HNPEN_Pos                     9           /*!< Resolution run HNP device A */
#define USBOTG_OTG_IRQ_STAT_B_BUSREQ_Pos                    10          /*!< Request bus control device B */
#define USBOTG_OTG_IRQ_STAT_A_SUSPENDREQ_Pos                11          /*!< Request A suspension device */
#define USBOTG_OTG_IRQ_STAT_A_DEVICE_Pos                    12          /*!< Display device A connections */
#define USBOTG_OTG_IRQ_STAT_B_DEVICE_Pos                    13          /*!< Display device B connections */
#define USBOTG_OTG_IRQ_STAT_SESSION_FAIL_Pos                14          /*!< Bit is device B, A when the device interrupts the signal Vbus. */
#define USBOTG_OTG_IRQ_STAT_SUSPENDEN_Pos                   15          /*!< Request */
#define USBOTG_OTG_IRQ_STAT_A_DEVCHANGE_Pos                 16          /*!< Bit is set when there is a change device A. At the same time, the appropriate interrupt enable bit. */
#define USBOTG_OTG_IRQ_STAT_B_DEVCHANGE_Pos                 17          /*!< Bit is set when you change the display B. Simultaneously, the appropriate interrupt enable bit */
#define USBOTG_OTG_IRQ_STAT_DEVSYNC_Pos                     18          /*!< When resynchronization device this bit is set and the corresponding interrupt enable bit */
#define USBOTG_OTG_IRQ_STAT_HOSTSYNC_Pos                    19          /*!< When resynchronization host this bit is set and the corresponding interrupt enable bit */
#define USBOTG_OTG_IRQ_STAT_DISCON_Pos                      20          /*!< Bit is set when disconnected not in suspend mode */

/* Bit field masks: */
#define USBOTG_OTG_IRQ_STAT_VBUSERR_Msk                     0x00000001  /*!< Enable interrupt a_clr_err */
#define USBOTG_OTG_IRQ_STAT_SPRDETECTED_Msk                 0x00000002  /*!< Enable interrupt srp_detected */
#define USBOTG_OTG_IRQ_STAT_HANDOFF_INTR_Msk                0x00000004  /*!< Interrupt when the output state Id */
#define USBOTG_OTG_IRQ_STAT_SPR_FAIL_Msk                    0x00000008  /*!< Indication of lack of response from the host mode operation Device */
#define USBOTG_OTG_IRQ_STAT_DEVICE_Msk                      0x00000010  /*!< Set when the kernel is running as a device controller */
#define USBOTG_OTG_IRQ_STAT_HOST_Msk                        0x00000020  /*!< Set when the kernel is running as a host controller */
#define USBOTG_OTG_IRQ_STAT_A_BUSREQ_Msk                    0x00000040  /*!< Request A device control bus */
#define USBOTG_OTG_IRQ_STAT_A_BUSDROP_Msk                   0x00000080  /*!< Set when the device A, you must disconnect bus */
#define USBOTG_OTG_IRQ_STAT_A_HNPEN_Msk                     0x00000100  /*!< Resolution run HNP device A */
#define USBOTG_OTG_IRQ_STAT_B_HNPEN_Msk                     0x00000200  /*!< Resolution run HNP device A */
#define USBOTG_OTG_IRQ_STAT_B_BUSREQ_Msk                    0x00000400  /*!< Request bus control device B */
#define USBOTG_OTG_IRQ_STAT_A_SUSPENDREQ_Msk                0x00000800  /*!< Request A suspension device */
#define USBOTG_OTG_IRQ_STAT_A_DEVICE_Msk                    0x00001000  /*!< Display device A connections */
#define USBOTG_OTG_IRQ_STAT_B_DEVICE_Msk                    0x00002000  /*!< Display device B connections */
#define USBOTG_OTG_IRQ_STAT_SESSION_FAIL_Msk                0x00004000  /*!< Bit is device B, A when the device interrupts the signal Vbus. */
#define USBOTG_OTG_IRQ_STAT_SUSPENDEN_Msk                   0x00008000  /*!< Request */
#define USBOTG_OTG_IRQ_STAT_A_DEVCHANGE_Msk                 0x00010000  /*!< Bit is set when there is a change device A. At the same time, the appropriate interrupt enable bit. */
#define USBOTG_OTG_IRQ_STAT_B_DEVCHANGE_Msk                 0x00020000  /*!< Bit is set when you change the display B. Simultaneously, the appropriate interrupt enable bit */
#define USBOTG_OTG_IRQ_STAT_DEVSYNC_Msk                     0x00040000  /*!< When resynchronization device this bit is set and the corresponding interrupt enable bit */
#define USBOTG_OTG_IRQ_STAT_HOSTSYNC_Msk                    0x00080000  /*!< When resynchronization host this bit is set and the corresponding interrupt enable bit */
#define USBOTG_OTG_IRQ_STAT_DISCON_Msk                      0x00100000  /*!< Bit is set when disconnected not in suspend mode */

/*-- OTG_IRQ_EN: Interrupt Enable USB OTG register ---------------------------*/

typedef struct {
  uint32_t VBUSERREN                              :1;                   /*!< Enable interrupt VBUSERR */
  uint32_t SPRDETECTEDEN                          :1;                   /*!< Enable interrupt SPRDETECTED */
  uint32_t TRANSINTREN                            :1;                   /*!< Enable interrupt TRANSINTR */
  uint32_t SRPFAILEN                              :1;                   /*!< Enable interrupt SRPFAIL */
  uint32_t SESSIONFAILEN                          :1;                   /*!< Enable interrupt SESSIONFAIL */
  uint32_t A_DEVCHANGEEN                          :1;                   /*!< Enable interrupt A_DEVCHANGE */
  uint32_t B_DEVCHANGEEN                          :1;                   /*!< Enable interrupt B_DEVCHANGE */
  uint32_t DEVSYNCEN                              :1;                   /*!< Enable interrupt DEVSYNC */
  uint32_t HOSTSYNCEN                             :1;                   /*!< Enable interrupt HOSTSYNC (Resynchronization host) */
  uint32_t DISCONEN                               :1;                   /*!< Enable interrupt Disconnect */
  uint32_t Reserved0                              :22;                  /*!< Reserved */
} _USBOTG_OTG_IRQ_EN_bits;

/* Bit field positions: */
#define USBOTG_OTG_IRQ_EN_VBUSERREN_Pos                     0           /*!< Enable interrupt VBUSERR */
#define USBOTG_OTG_IRQ_EN_SPRDETECTEDEN_Pos                 1           /*!< Enable interrupt SPRDETECTED */
#define USBOTG_OTG_IRQ_EN_TRANSINTREN_Pos                   2           /*!< Enable interrupt TRANSINTR */
#define USBOTG_OTG_IRQ_EN_SRPFAILEN_Pos                     3           /*!< Enable interrupt SRPFAIL */
#define USBOTG_OTG_IRQ_EN_SESSIONFAILEN_Pos                 4           /*!< Enable interrupt SESSIONFAIL */
#define USBOTG_OTG_IRQ_EN_A_DEVCHANGEEN_Pos                 5           /*!< Enable interrupt A_DEVCHANGE */
#define USBOTG_OTG_IRQ_EN_B_DEVCHANGEEN_Pos                 6           /*!< Enable interrupt B_DEVCHANGE */
#define USBOTG_OTG_IRQ_EN_DEVSYNCEN_Pos                     7           /*!< Enable interrupt DEVSYNC */
#define USBOTG_OTG_IRQ_EN_HOSTSYNCEN_Pos                    8           /*!< Enable interrupt HOSTSYNC (Resynchronization host) */
#define USBOTG_OTG_IRQ_EN_DISCONEN_Pos                      9           /*!< Enable interrupt Disconnect */

/* Bit field masks: */
#define USBOTG_OTG_IRQ_EN_VBUSERREN_Msk                     0x00000001  /*!< Enable interrupt VBUSERR */
#define USBOTG_OTG_IRQ_EN_SPRDETECTEDEN_Msk                 0x00000002  /*!< Enable interrupt SPRDETECTED */
#define USBOTG_OTG_IRQ_EN_TRANSINTREN_Msk                   0x00000004  /*!< Enable interrupt TRANSINTR */
#define USBOTG_OTG_IRQ_EN_SRPFAILEN_Msk                     0x00000008  /*!< Enable interrupt SRPFAIL */
#define USBOTG_OTG_IRQ_EN_SESSIONFAILEN_Msk                 0x00000010  /*!< Enable interrupt SESSIONFAIL */
#define USBOTG_OTG_IRQ_EN_A_DEVCHANGEEN_Msk                 0x00000020  /*!< Enable interrupt A_DEVCHANGE */
#define USBOTG_OTG_IRQ_EN_B_DEVCHANGEEN_Msk                 0x00000040  /*!< Enable interrupt B_DEVCHANGE */
#define USBOTG_OTG_IRQ_EN_DEVSYNCEN_Msk                     0x00000080  /*!< Enable interrupt DEVSYNC */
#define USBOTG_OTG_IRQ_EN_HOSTSYNCEN_Msk                    0x00000100  /*!< Enable interrupt HOSTSYNC (Resynchronization host) */
#define USBOTG_OTG_IRQ_EN_DISCONEN_Msk                      0x00000200  /*!< Enable interrupt Disconnect */

/*-- Register map for USBOTG peripheral --------------------------------------*/

typedef struct {
  union {                                                               /*!< USB OTG interrupt flag register */
    __IO uint32_t OTG_IRQ_STAT;                                         /*!< OTG_IRQ_STAT    : type used for word access */
    __IO _USBOTG_OTG_IRQ_STAT_bits OTG_IRQ_STAT_bit;                    /*!< OTG_IRQ_STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Enable USB OTG register */
    __IO uint32_t OTG_IRQ_EN;                                           /*!< OTG_IRQ_EN    : type used for word access */
    __IO _USBOTG_OTG_IRQ_EN_bits OTG_IRQ_EN_bit;                        /*!< OTG_IRQ_EN_bit: structure used for bit access */
  };
} NT_USBOTG_TypeDef;

/******************************************************************************/
/*                      Watchdog controller registers                         */
/******************************************************************************/

/*-- CTRL: Watchdog Control Register -----------------------------------------*/

typedef struct {
  uint32_t INTEN                                  :1;                   /*!< Enable the interrupt event */
  uint32_t RESEN                                  :1;                   /*!< Enable watchdog reset output */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _WDT_CTRL_bits;

/* Bit field positions: */
#define WDT_CTRL_INTEN_Pos                                  0           /*!< Enable the interrupt event */
#define WDT_CTRL_RESEN_Pos                                  1           /*!< Enable watchdog reset output */

/* Bit field masks: */
#define WDT_CTRL_INTEN_Msk                                  0x00000001  /*!< Enable the interrupt event */
#define WDT_CTRL_RESEN_Msk                                  0x00000002  /*!< Enable watchdog reset output */

/*-- RIS: Watchdog Raw Interrupt Status Register -----------------------------*/

typedef struct {
  uint32_t RAWWDTINT                              :1;                   /*!< Raw interrupt status from the counter */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _WDT_RIS_bits;

/* Bit field positions: */
#define WDT_RIS_RAWWDTINT_Pos                               0           /*!< Raw interrupt status from the counter */

/* Bit field masks: */
#define WDT_RIS_RAWWDTINT_Msk                               0x00000001  /*!< Raw interrupt status from the counter */

/*-- MIS: Watchdog Interrupt Status Register ---------------------------------*/

typedef struct {
  uint32_t WDTINT                                 :1;                   /*!< Enabled interrupt status from the counter */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _WDT_MIS_bits;

/* Bit field positions: */
#define WDT_MIS_WDTINT_Pos                                  0           /*!< Enabled interrupt status from the counter */

/* Bit field masks: */
#define WDT_MIS_WDTINT_Msk                                  0x00000001  /*!< Enabled interrupt status from the counter */

/*-- LOCK: Watchdog Lock Register --------------------------------------------*/

typedef struct {
  uint32_t REG_WR_DIS                             :1;                   /*!< Disable write access to all registers */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _WDT_LOCK_bits;

/* Bit field positions: */
#define WDT_LOCK_REG_WR_DIS_Pos                             0           /*!< Disable write access to all registers */

/* Bit field masks: */
#define WDT_LOCK_REG_WR_DIS_Msk                             0x00000001  /*!< Disable write access to all registers */

/*-- Register map for WDT peripheral -----------------------------------------*/

typedef struct {
  __IO uint32_t LOAD;                                                   /*!< Watchdog Load Register */
  __I  uint32_t VALUE;                                                  /*!< Watchdog Value Register */
  union {                                                               /*!< Watchdog Control Register */
    __IO uint32_t CTRL;                                                 /*!< CTRL    : type used for word access */
    __IO _WDT_CTRL_bits CTRL_bit;                                       /*!< CTRL_bit: structure used for bit access */
  };
  __O  uint32_t INTCLR;                                                 /*!< Watchdog Clear Interrupt Register */
  union {                                                               /*!< Watchdog Raw Interrupt Status Register */
    __I  uint32_t RIS;                                                  /*!< RIS    : type used for word access */
    __I  _WDT_RIS_bits RIS_bit;                                         /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Interrupt Status Register */
    __I  uint32_t MIS;                                                  /*!< MIS    : type used for word access */
    __I  _WDT_MIS_bits MIS_bit;                                         /*!< MIS_bit: structure used for bit access */
  };
  uint32_t Reserved0[762];                                              /*!< Reserved */
  union {                                                               /*!< Watchdog Lock Register */
    __O  uint32_t LOCK;                                                 /*!< LOCK    : type used for word access */
    __O  _WDT_LOCK_bits LOCK_bit;                                       /*!< LOCK_bit: structure used for bit access */
  };
} NT_WDT_TypeDef;

/******************************************************************************/
/*                         I2C controller registers                           */
/******************************************************************************/

/*-- SDA: Data register ------------------------------------------------------*/

typedef struct {
  uint32_t DATA                                   :8;                   /*!< Data field */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _I2C_SDA_bits;

/* Bit field positions: */
#define I2C_SDA_DATA_Pos                                    0           /*!< Data field */

/* Bit field masks: */
#define I2C_SDA_DATA_Msk                                    0x000000FF  /*!< Data field */

/*-- ST: Status register -----------------------------------------------------*/

typedef struct {
  uint32_t MODE                                   :6;                   /*!< Status code */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t INT                                    :1;                   /*!< Interrupt flag */
  uint32_t Reserved1                              :24;                  /*!< Reserved */
} _I2C_ST_bits;

/* Bit field positions: */
#define I2C_ST_MODE_Pos                                     0           /*!< Status code */
#define I2C_ST_INT_Pos                                      7           /*!< Interrupt flag */

/* Bit field masks: */
#define I2C_ST_MODE_Msk                                     0x0000003F  /*!< Status code */
#define I2C_ST_INT_Msk                                      0x00000080  /*!< Interrupt flag */

/*-- CST: Status and control register ----------------------------------------*/

typedef struct {
  uint32_t BB                                     :1;                   /*!< Flag employment bus */
  uint32_t TOCDIV                                 :2;                   /*!< Coeff. div */
  uint32_t TOERR                                  :1;                   /*!< Flag error simple bus */
  uint32_t TSDA                                   :1;                   /*!< Bit test SDA */
  uint32_t TGSCL                                  :1;                   /*!< Bit switch SCL */
  uint32_t PECNEXT                                :1;                   /*!< Bit control transmit CRC */
  uint32_t PECFAULT                               :1;                   /*!< Error flag */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _I2C_CST_bits;

/* Bit field positions: */
#define I2C_CST_BB_Pos                                      0           /*!< Flag employment bus */
#define I2C_CST_TOCDIV_Pos                                  1           /*!< Coeff. div */
#define I2C_CST_TOERR_Pos                                   3           /*!< Flag error simple bus */
#define I2C_CST_TSDA_Pos                                    4           /*!< Bit test SDA */
#define I2C_CST_TGSCL_Pos                                   5           /*!< Bit switch SCL */
#define I2C_CST_PECNEXT_Pos                                 6           /*!< Bit control transmit CRC */
#define I2C_CST_PECFAULT_Pos                                7           /*!< Error flag */

/* Bit field masks: */
#define I2C_CST_BB_Msk                                      0x00000001  /*!< Flag employment bus */
#define I2C_CST_TOCDIV_Msk                                  0x00000006  /*!< Coeff. div */
#define I2C_CST_TOERR_Msk                                   0x00000008  /*!< Flag error simple bus */
#define I2C_CST_TSDA_Msk                                    0x00000010  /*!< Bit test SDA */
#define I2C_CST_TGSCL_Msk                                   0x00000020  /*!< Bit switch SCL */
#define I2C_CST_PECNEXT_Msk                                 0x00000040  /*!< Bit control transmit CRC */
#define I2C_CST_PECFAULT_Msk                                0x00000080  /*!< Error flag */

/*-- CTL0: Control register 0 ------------------------------------------------*/

typedef struct {
  uint32_t START                                  :1;                   /*!< Start bit */
  uint32_t STOP                                   :1;                   /*!< Stop bit */
  uint32_t INTEN                                  :1;                   /*!< Interrupt enable bit */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t ACK                                    :1;                   /*!< Acknowledgment bit reception */
  uint32_t GCMEN                                  :1;                   /*!< Control bit part a response to the general call address */
  uint32_t SMBARE                                 :1;                   /*!< Control bit part a response to the response address */
  uint32_t CLRST                                  :1;                   /*!< Bit reset flag interrupt */
  uint32_t Reserved1                              :24;                  /*!< Reserved */
} _I2C_CTL0_bits;

/* Bit field positions: */
#define I2C_CTL0_START_Pos                                  0           /*!< Start bit */
#define I2C_CTL0_STOP_Pos                                   1           /*!< Stop bit */
#define I2C_CTL0_INTEN_Pos                                  2           /*!< Interrupt enable bit */
#define I2C_CTL0_ACK_Pos                                    4           /*!< Acknowledgment bit reception */
#define I2C_CTL0_GCMEN_Pos                                  5           /*!< Control bit part a response to the general call address */
#define I2C_CTL0_SMBARE_Pos                                 6           /*!< Control bit part a response to the response address */
#define I2C_CTL0_CLRST_Pos                                  7           /*!< Bit reset flag interrupt */

/* Bit field masks: */
#define I2C_CTL0_START_Msk                                  0x00000001  /*!< Start bit */
#define I2C_CTL0_STOP_Msk                                   0x00000002  /*!< Stop bit */
#define I2C_CTL0_INTEN_Msk                                  0x00000004  /*!< Interrupt enable bit */
#define I2C_CTL0_ACK_Msk                                    0x00000010  /*!< Acknowledgment bit reception */
#define I2C_CTL0_GCMEN_Msk                                  0x00000020  /*!< Control bit part a response to the general call address */
#define I2C_CTL0_SMBARE_Msk                                 0x00000040  /*!< Control bit part a response to the response address */
#define I2C_CTL0_CLRST_Msk                                  0x00000080  /*!< Bit reset flag interrupt */

/*-- ADDR: Register own address ----------------------------------------------*/

typedef struct {
  uint32_t ADDR                                   :7;                   /*!< Own 7-bit address */
  uint32_t SAEN                                   :1;                   /*!< Enable bit address recognition */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _I2C_ADDR_bits;

/* Bit field positions: */
#define I2C_ADDR_ADDR_Pos                                   0           /*!< Own 7-bit address */
#define I2C_ADDR_SAEN_Pos                                   7           /*!< Enable bit address recognition */

/* Bit field masks: */
#define I2C_ADDR_ADDR_Msk                                   0x0000007F  /*!< Own 7-bit address */
#define I2C_ADDR_SAEN_Msk                                   0x00000080  /*!< Enable bit address recognition */

/*-- CTL1: Control register 1 ------------------------------------------------*/

typedef struct {
  uint32_t ENABLE                                 :1;                   /*!< Enable I2C */
  uint32_t SCLFRQ                                 :7;                   /*!< Field frequency selection signal at pin SCL in master mode */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _I2C_CTL1_bits;

/* Bit field positions: */
#define I2C_CTL1_ENABLE_Pos                                 0           /*!< Enable I2C */
#define I2C_CTL1_SCLFRQ_Pos                                 1           /*!< Field frequency selection signal at pin SCL in master mode */

/* Bit field masks: */
#define I2C_CTL1_ENABLE_Msk                                 0x00000001  /*!< Enable I2C */
#define I2C_CTL1_SCLFRQ_Msk                                 0x000000FE  /*!< Field frequency selection signal at pin SCL in master mode */

/*-- TOPR: Prescaler load register -------------------------------------------*/

typedef struct {
  uint32_t SMBTOPR                                :8;                   /*!< Prescaler reload value field */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _I2C_TOPR_bits;

/* Bit field positions: */
#define I2C_TOPR_SMBTOPR_Pos                                0           /*!< Prescaler reload value field */

/* Bit field masks: */
#define I2C_TOPR_SMBTOPR_Msk                                0x000000FF  /*!< Prescaler reload value field */

/*-- CTL2: Control register 2 ------------------------------------------------*/

typedef struct {
  uint32_t S10ADR                                 :3;                   /*!< Upper bits of 10-bit slave address */
  uint32_t S10EN                                  :1;                   /*!< Bit enabled 10-bit addressing slave */
  uint32_t HSDIV                                  :4;                   /*!< Field frequency selection signal at pin SCL in HS master mode */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _I2C_CTL2_bits;

/* Bit field positions: */
#define I2C_CTL2_S10ADR_Pos                                 0           /*!< Upper bits of 10-bit slave address */
#define I2C_CTL2_S10EN_Pos                                  3           /*!< Bit enabled 10-bit addressing slave */
#define I2C_CTL2_HSDIV_Pos                                  4           /*!< Field frequency selection signal at pin SCL in HS master mode */

/* Bit field masks: */
#define I2C_CTL2_S10ADR_Msk                                 0x00000007  /*!< Upper bits of 10-bit slave address */
#define I2C_CTL2_S10EN_Msk                                  0x00000008  /*!< Bit enabled 10-bit addressing slave */
#define I2C_CTL2_HSDIV_Msk                                  0x000000F0  /*!< Field frequency selection signal at pin SCL in HS master mode */

/*-- Register map for I2C peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Data register */
    __IO uint32_t SDA;                                                  /*!< SDA    : type used for word access */
    __IO _I2C_SDA_bits SDA_bit;                                         /*!< SDA_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __I  uint32_t ST;                                                   /*!< ST    : type used for word access */
    __I  _I2C_ST_bits ST_bit;                                           /*!< ST_bit: structure used for bit access */
  };
  union {                                                               /*!< Status and control register */
    __IO uint32_t CST;                                                  /*!< CST    : type used for word access */
    __IO _I2C_CST_bits CST_bit;                                         /*!< CST_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 0 */
    __IO uint32_t CTL0;                                                 /*!< CTL0    : type used for word access */
    __IO _I2C_CTL0_bits CTL0_bit;                                       /*!< CTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register own address */
    __IO uint32_t ADDR;                                                 /*!< ADDR    : type used for word access */
    __IO _I2C_ADDR_bits ADDR_bit;                                       /*!< ADDR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 1 */
    __IO uint32_t CTL1;                                                 /*!< CTL1    : type used for word access */
    __IO _I2C_CTL1_bits CTL1_bit;                                       /*!< CTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Prescaler load register */
    __IO uint32_t TOPR;                                                 /*!< TOPR    : type used for word access */
    __IO _I2C_TOPR_bits TOPR_bit;                                       /*!< TOPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 2 */
    __IO uint32_t CTL2;                                                 /*!< CTL2    : type used for word access */
    __IO _I2C_CTL2_bits CTL2_bit;                                       /*!< CTL2_bit: structure used for bit access */
  };
} NT_I2C_TypeDef;

/******************************************************************************/
/*                        Timer controller registers                          */
/******************************************************************************/

/*-- CTRL: Control Timer register --------------------------------------------*/

typedef struct {
  uint32_t ON                                     :1;                   /*!< Enable Timer */
  uint32_t EXTINPUT_EN                            :1;                   /*!< Enable extern */
  uint32_t EXTINPUT_CLK                           :1;                   /*!< Enable extern input clock */
  uint32_t INTEN                                  :1;                   /*!< Enable Timer interrupt */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _TIMER_CTRL_bits;

/* Bit field positions: */
#define TIMER_CTRL_ON_Pos                                   0           /*!< Enable Timer */
#define TIMER_CTRL_EXTINPUT_EN_Pos                          1           /*!< Enable extern */
#define TIMER_CTRL_EXTINPUT_CLK_Pos                         2           /*!< Enable extern input clock */
#define TIMER_CTRL_INTEN_Pos                                3           /*!< Enable Timer interrupt */

/* Bit field masks: */
#define TIMER_CTRL_ON_Msk                                   0x00000001  /*!< Enable Timer */
#define TIMER_CTRL_EXTINPUT_EN_Msk                          0x00000002  /*!< Enable extern */
#define TIMER_CTRL_EXTINPUT_CLK_Msk                         0x00000004  /*!< Enable extern input clock */
#define TIMER_CTRL_INTEN_Msk                                0x00000008  /*!< Enable Timer interrupt */

/*-- INTSTATUS_INTCLEAR ------------------------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< Timer interrupt flag */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _TIMER_INTSTATUS_INTCLEAR_bits;

/* Bit field positions: */
#define TIMER_INTSTATUS_INTCLEAR_INT_Pos                    0           /*!< Timer interrupt flag */

/* Bit field masks: */
#define TIMER_INTSTATUS_INTCLEAR_INT_Msk                    0x00000001  /*!< Timer interrupt flag */

/*-- Register map for TIMER peripheral ---------------------------------------*/

typedef struct {
  union {                                                               /*!< Control Timer register */
    __IO uint32_t CTRL;                                                 /*!< CTRL    : type used for word access */
    __IO _TIMER_CTRL_bits CTRL_bit;                                     /*!< CTRL_bit: structure used for bit access */
  };
  __IO uint32_t VALUE;                                                  /*!< Current value timer register */
  __IO uint32_t RELOAD;                                                 /*!< Reload value timer register */
  union {                                                               /*!<  */
    __IO uint32_t INTSTATUS_INTCLEAR;                                   /*!< INTSTATUS_INTCLEAR    : type used for word access */
    __IO _TIMER_INTSTATUS_INTCLEAR_bits INTSTATUS_INTCLEAR_bit;         /*!< INTSTATUS_INTCLEAR_bit: structure used for bit access */
  };
} NT_TIMER_TypeDef;

/******************************************************************************/
/*                         DMA controller registers                           */
/******************************************************************************/

/*-- STATUS: Status DMA register ---------------------------------------------*/

typedef struct {
  uint32_t MASTER_EN                              :1;                   /*!< Indicate enable DMA */
  uint32_t Reserved0                              :3;                   /*!< Reserved */
  uint32_t STATE                                  :4;                   /*!< State of DMA */
  uint32_t Reserved1                              :8;                   /*!< Reserved */
  uint32_t CHNLS                                  :5;                   /*!< Number channel DMA (write: N-1) */
  uint32_t Reserved2                              :11;                  /*!< Reserved */
} _DMA_STATUS_bits;

/* Bit field positions: */
#define DMA_STATUS_MASTER_EN_Pos                            0           /*!< Indicate enable DMA */
#define DMA_STATUS_STATE_Pos                                4           /*!< State of DMA */
#define DMA_STATUS_CHNLS_Pos                                16          /*!< Number channel DMA (write: N-1) */

/* Bit field masks: */
#define DMA_STATUS_MASTER_EN_Msk                            0x00000001  /*!< Indicate enable DMA */
#define DMA_STATUS_STATE_Msk                                0x000000F0  /*!< State of DMA */
#define DMA_STATUS_CHNLS_Msk                                0x001F0000  /*!< Number channel DMA (write: N-1) */

/*-- CFG: Configurate DMA register -------------------------------------------*/

typedef struct {
  uint32_t MASTER_EN                              :1;                   /*!< Enable DMA */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t CHNL_PROT_CTRL                         :3;                   /*!< Enable control HPROT.1 for access indication with buffering */
  uint32_t Reserved1                              :24;                  /*!< Reserved */
} _DMA_CFG_bits;

/* Bit field positions: */
#define DMA_CFG_MASTER_EN_Pos                               0           /*!< Enable DMA */
#define DMA_CFG_CHNL_PROT_CTRL_Pos                          5           /*!< Enable control HPROT.1 for access indication with buffering */

/* Bit field masks: */
#define DMA_CFG_MASTER_EN_Msk                               0x00000001  /*!< Enable DMA */
#define DMA_CFG_CHNL_PROT_CTRL_Msk                          0x000000E0  /*!< Enable control HPROT.1 for access indication with buffering */

/*-- CTRL_BASE_PTR: Base address register control data channels --------------*/

typedef struct {
  uint32_t Reserved0                              :10;                  /*!< Reserved */
  uint32_t CTRL_BASE_PTR                          :22;                  /*!< Pointer to base address of the primary structure of the control data */
} _DMA_CTRL_BASE_PTR_bits;

/* Bit field positions: */
#define DMA_CTRL_BASE_PTR_CTRL_BASE_PTR_Pos                 10          /*!< Pointer to base address of the primary structure of the control data */

/* Bit field masks: */
#define DMA_CTRL_BASE_PTR_CTRL_BASE_PTR_Msk                 0xFFFFFC00  /*!< Pointer to base address of the primary structure of the control data */

/*-- WAITONREQ_STATUS: DMA wait request status -------------------------------*/

typedef struct {
  uint32_t DMA_WAITREQ0                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ1                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ2                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ3                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ4                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ5                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ6                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ7                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ8                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ9                           :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ10                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ11                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ12                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ13                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ14                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ15                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ16                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ17                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ18                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ19                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ20                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ21                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ22                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t DMA_WAITREQ23                          :1;                   /*!< Returns the status of the DMA request signals */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_WAITONREQ_STATUS_bits;

/* Bit field positions: */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ0_Pos               0           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ1_Pos               1           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ2_Pos               2           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ3_Pos               3           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ4_Pos               4           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ5_Pos               5           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ6_Pos               6           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ7_Pos               7           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ8_Pos               8           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ9_Pos               9           /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ10_Pos              10          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ11_Pos              11          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ12_Pos              12          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ13_Pos              13          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ14_Pos              14          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ15_Pos              15          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ16_Pos              16          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ17_Pos              17          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ18_Pos              18          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ19_Pos              19          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ20_Pos              20          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ21_Pos              21          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ22_Pos              22          /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ23_Pos              23          /*!< Returns the status of the DMA request signals */

/* Bit field masks: */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ0_Msk               0x00000001  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ1_Msk               0x00000002  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ2_Msk               0x00000004  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ3_Msk               0x00000008  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ4_Msk               0x00000010  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ5_Msk               0x00000020  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ6_Msk               0x00000040  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ7_Msk               0x00000080  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ8_Msk               0x00000100  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ9_Msk               0x00000200  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ10_Msk              0x00000400  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ11_Msk              0x00000800  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ12_Msk              0x00001000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ13_Msk              0x00002000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ14_Msk              0x00004000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ15_Msk              0x00008000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ16_Msk              0x00010000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ17_Msk              0x00020000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ18_Msk              0x00040000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ19_Msk              0x00080000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ20_Msk              0x00100000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ21_Msk              0x00200000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ22_Msk              0x00400000  /*!< Returns the status of the DMA request signals */
#define DMA_WAITONREQ_STATUS_DMA_WAITREQ23_Msk              0x00800000  /*!< Returns the status of the DMA request signals */

/*-- CHNL_SW_REQUEST: Register software process request DMA channels ---------*/

typedef struct {
  uint32_t DMA_SWREQ0                             :1;                   /*!< Set software request on channel 0 */
  uint32_t DMA_SWREQ1                             :1;                   /*!< Set software request on channel 1 */
  uint32_t DMA_SWREQ2                             :1;                   /*!< Set software request on channel 2 */
  uint32_t DMA_SWREQ3                             :1;                   /*!< Set software request on channel 3 */
  uint32_t DMA_SWREQ4                             :1;                   /*!< Set software request on channel 4 */
  uint32_t DMA_SWREQ5                             :1;                   /*!< Set software request on channel 5 */
  uint32_t DMA_SWREQ6                             :1;                   /*!< Set software request on channel 6 */
  uint32_t DMA_SWREQ7                             :1;                   /*!< Set software request on channel 7 */
  uint32_t DMA_SWREQ8                             :1;                   /*!< Set software request on channel 8 */
  uint32_t DMA_SWREQ9                             :1;                   /*!< Set software request on channel 9 */
  uint32_t DMA_SWREQ10                            :1;                   /*!< Set software request on channel 10 */
  uint32_t DMA_SWREQ11                            :1;                   /*!< Set software request on channel 11 */
  uint32_t DMA_SWREQ12                            :1;                   /*!< Set software request on channel 12 */
  uint32_t DMA_SWREQ13                            :1;                   /*!< Set software request on channel 13 */
  uint32_t DMA_SWREQ14                            :1;                   /*!< Set software request on channel 14 */
  uint32_t DMA_SWREQ15                            :1;                   /*!< Set software request on channel 15 */
  uint32_t DMA_SWREQ16                            :1;                   /*!< Set software request on channel 16 */
  uint32_t DMA_SWREQ17                            :1;                   /*!< Set software request on channel 17 */
  uint32_t DMA_SWREQ18                            :1;                   /*!< Set software request on channel 18 */
  uint32_t DMA_SWREQ19                            :1;                   /*!< Set software request on channel 19 */
  uint32_t DMA_SWREQ20                            :1;                   /*!< Set software request on channel 20 */
  uint32_t DMA_SWREQ21                            :1;                   /*!< Set software request on channel 21 */
  uint32_t DMA_SWREQ22                            :1;                   /*!< Set software request on channel 22 */
  uint32_t DMA_SWREQ23                            :1;                   /*!< Set software request on channel 23 */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_SW_REQUEST_bits;

/* Bit field positions: */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ0_Pos                  0           /*!< Set software request on channel 0 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ1_Pos                  1           /*!< Set software request on channel 1 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ2_Pos                  2           /*!< Set software request on channel 2 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ3_Pos                  3           /*!< Set software request on channel 3 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ4_Pos                  4           /*!< Set software request on channel 4 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ5_Pos                  5           /*!< Set software request on channel 5 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ6_Pos                  6           /*!< Set software request on channel 6 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ7_Pos                  7           /*!< Set software request on channel 7 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ8_Pos                  8           /*!< Set software request on channel 8 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ9_Pos                  9           /*!< Set software request on channel 9 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ10_Pos                 10          /*!< Set software request on channel 10 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ11_Pos                 11          /*!< Set software request on channel 11 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ12_Pos                 12          /*!< Set software request on channel 12 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ13_Pos                 13          /*!< Set software request on channel 13 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ14_Pos                 14          /*!< Set software request on channel 14 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ15_Pos                 15          /*!< Set software request on channel 15 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ16_Pos                 16          /*!< Set software request on channel 16 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ17_Pos                 17          /*!< Set software request on channel 17 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ18_Pos                 18          /*!< Set software request on channel 18 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ19_Pos                 19          /*!< Set software request on channel 19 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ20_Pos                 20          /*!< Set software request on channel 20 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ21_Pos                 21          /*!< Set software request on channel 21 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ22_Pos                 22          /*!< Set software request on channel 22 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ23_Pos                 23          /*!< Set software request on channel 23 */

/* Bit field masks: */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ0_Msk                  0x00000001  /*!< Set software request on channel 0 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ1_Msk                  0x00000002  /*!< Set software request on channel 1 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ2_Msk                  0x00000004  /*!< Set software request on channel 2 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ3_Msk                  0x00000008  /*!< Set software request on channel 3 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ4_Msk                  0x00000010  /*!< Set software request on channel 4 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ5_Msk                  0x00000020  /*!< Set software request on channel 5 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ6_Msk                  0x00000040  /*!< Set software request on channel 6 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ7_Msk                  0x00000080  /*!< Set software request on channel 7 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ8_Msk                  0x00000100  /*!< Set software request on channel 8 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ9_Msk                  0x00000200  /*!< Set software request on channel 9 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ10_Msk                 0x00000400  /*!< Set software request on channel 10 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ11_Msk                 0x00000800  /*!< Set software request on channel 11 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ12_Msk                 0x00001000  /*!< Set software request on channel 12 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ13_Msk                 0x00002000  /*!< Set software request on channel 13 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ14_Msk                 0x00004000  /*!< Set software request on channel 14 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ15_Msk                 0x00008000  /*!< Set software request on channel 15 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ16_Msk                 0x00010000  /*!< Set software request on channel 16 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ17_Msk                 0x00020000  /*!< Set software request on channel 17 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ18_Msk                 0x00040000  /*!< Set software request on channel 18 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ19_Msk                 0x00080000  /*!< Set software request on channel 19 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ20_Msk                 0x00100000  /*!< Set software request on channel 20 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ21_Msk                 0x00200000  /*!< Set software request on channel 21 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ22_Msk                 0x00400000  /*!< Set software request on channel 22 */
#define DMA_CHNL_SW_REQUEST_DMA_SWREQ23_Msk                 0x00800000  /*!< Set software request on channel 23 */

/*-- CHNL_USEBURST_SET: Register Set Packet Exchange DMA channels ------------*/

typedef struct {
  uint32_t DMA_BURSTSET0                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET1                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET2                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET3                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET4                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET5                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET6                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET7                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET8                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET9                          :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET10                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET11                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET12                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET13                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET14                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET15                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET16                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET17                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET18                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET19                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET20                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET21                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET22                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t DMA_BURSTSET23                         :1;                   /*!< Returns the status of the DMA single request signals */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_USEBURST_SET_bits;

/* Bit field positions: */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET0_Pos             0           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET1_Pos             1           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET2_Pos             2           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET3_Pos             3           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET4_Pos             4           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET5_Pos             5           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET6_Pos             6           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET7_Pos             7           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET8_Pos             8           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET9_Pos             9           /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET10_Pos            10          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET11_Pos            11          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET12_Pos            12          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET13_Pos            13          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET14_Pos            14          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET15_Pos            15          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET16_Pos            16          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET17_Pos            17          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET18_Pos            18          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET19_Pos            19          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET20_Pos            20          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET21_Pos            21          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET22_Pos            22          /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET23_Pos            23          /*!< Returns the status of the DMA single request signals */

/* Bit field masks: */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET0_Msk             0x00000001  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET1_Msk             0x00000002  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET2_Msk             0x00000004  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET3_Msk             0x00000008  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET4_Msk             0x00000010  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET5_Msk             0x00000020  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET6_Msk             0x00000040  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET7_Msk             0x00000080  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET8_Msk             0x00000100  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET9_Msk             0x00000200  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET10_Msk            0x00000400  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET11_Msk            0x00000800  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET12_Msk            0x00001000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET13_Msk            0x00002000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET14_Msk            0x00004000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET15_Msk            0x00008000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET16_Msk            0x00010000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET17_Msk            0x00020000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET18_Msk            0x00040000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET19_Msk            0x00080000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET20_Msk            0x00100000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET21_Msk            0x00200000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET22_Msk            0x00400000  /*!< Returns the status of the DMA single request signals */
#define DMA_CHNL_USEBURST_SET_DMA_BURSTSET23_Msk            0x00800000  /*!< Returns the status of the DMA single request signals */

/*-- CHNL_USEBURST_CLR: Register Clear Packet Exchange DMA channels ----------*/

typedef struct {
  uint32_t DMA_BURSTCLR0                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR1                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR2                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR3                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR4                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR5                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR6                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR7                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR8                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR9                          :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR10                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR11                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR12                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR13                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR14                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR15                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR16                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR17                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR18                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR19                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR20                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR21                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR22                         :1;                   /*!< reserved */
  uint32_t DMA_BURSTCLR23                         :1;                   /*!< reserved */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_USEBURST_CLR_bits;

/* Bit field positions: */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR0_Pos             0           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR1_Pos             1           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR2_Pos             2           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR3_Pos             3           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR4_Pos             4           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR5_Pos             5           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR6_Pos             6           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR7_Pos             7           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR8_Pos             8           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR9_Pos             9           /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR10_Pos            10          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR11_Pos            11          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR12_Pos            12          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR13_Pos            13          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR14_Pos            14          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR15_Pos            15          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR16_Pos            16          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR17_Pos            17          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR18_Pos            18          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR19_Pos            19          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR20_Pos            20          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR21_Pos            21          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR22_Pos            22          /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR23_Pos            23          /*!< reserved */

/* Bit field masks: */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR0_Msk             0x00000001  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR1_Msk             0x00000002  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR2_Msk             0x00000004  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR3_Msk             0x00000008  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR4_Msk             0x00000010  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR5_Msk             0x00000020  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR6_Msk             0x00000040  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR7_Msk             0x00000080  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR8_Msk             0x00000100  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR9_Msk             0x00000200  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR10_Msk            0x00000400  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR11_Msk            0x00000800  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR12_Msk            0x00001000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR13_Msk            0x00002000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR14_Msk            0x00004000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR15_Msk            0x00008000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR16_Msk            0x00010000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR17_Msk            0x00020000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR18_Msk            0x00040000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR19_Msk            0x00080000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR20_Msk            0x00100000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR21_Msk            0x00200000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR22_Msk            0x00400000  /*!< reserved */
#define DMA_CHNL_USEBURST_CLR_DMA_BURSTCLR23_Msk            0x00800000  /*!< reserved */

/*-- CHNL_REQ_MASK_SET: DMA request mask set ---------------------------------*/

typedef struct {
  uint32_t DMA_REQMASKSET0                        :1;
  uint32_t DMA_REQMASKSET1                        :1;
  uint32_t DMA_REQMASKSET2                        :1;
  uint32_t DMA_REQMASKSET3                        :1;
  uint32_t DMA_REQMASKSET4                        :1;
  uint32_t DMA_REQMASKSET5                        :1;
  uint32_t DMA_REQMASKSET6                        :1;
  uint32_t DMA_REQMASKSET7                        :1;
  uint32_t DMA_REQMASKSET8                        :1;
  uint32_t DMA_REQMASKSET9                        :1;
  uint32_t DMA_REQMASKSET10                       :1;
  uint32_t DMA_REQMASKSET11                       :1;
  uint32_t DMA_REQMASKSET12                       :1;
  uint32_t DMA_REQMASKSET13                       :1;
  uint32_t DMA_REQMASKSET14                       :1;
  uint32_t DMA_REQMASKSET15                       :1;
  uint32_t DMA_REQMASKSET16                       :1;
  uint32_t DMA_REQMASKSET17                       :1;
  uint32_t DMA_REQMASKSET18                       :1;
  uint32_t DMA_REQMASKSET19                       :1;
  uint32_t DMA_REQMASKSET20                       :1;
  uint32_t DMA_REQMASKSET21                       :1;
  uint32_t DMA_REQMASKSET22                       :1;
  uint32_t DMA_REQMASKSET23                       :1;
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_REQ_MASK_SET_bits;

/* Bit field positions: */
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET0_Pos           0
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET1_Pos           1
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET2_Pos           2
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET3_Pos           3
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET4_Pos           4
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET5_Pos           5
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET6_Pos           6
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET7_Pos           7
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET8_Pos           8
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET9_Pos           9
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET10_Pos          10
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET11_Pos          11
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET12_Pos          12
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET13_Pos          13
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET14_Pos          14
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET15_Pos          15
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET16_Pos          16
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET17_Pos          17
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET18_Pos          18
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET19_Pos          19
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET20_Pos          20
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET21_Pos          21
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET22_Pos          22
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET23_Pos          23

/* Bit field masks: */
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET0_Msk           0x00000001
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET1_Msk           0x00000002
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET2_Msk           0x00000004
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET3_Msk           0x00000008
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET4_Msk           0x00000010
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET5_Msk           0x00000020
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET6_Msk           0x00000040
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET7_Msk           0x00000080
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET8_Msk           0x00000100
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET9_Msk           0x00000200
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET10_Msk          0x00000400
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET11_Msk          0x00000800
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET12_Msk          0x00001000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET13_Msk          0x00002000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET14_Msk          0x00004000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET15_Msk          0x00008000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET16_Msk          0x00010000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET17_Msk          0x00020000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET18_Msk          0x00040000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET19_Msk          0x00080000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET20_Msk          0x00100000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET21_Msk          0x00200000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET22_Msk          0x00400000
#define DMA_CHNL_REQ_MASK_SET_DMA_REQMASKSET23_Msk          0x00800000

/*-- CHNL_REQ_MASK_CLR: DMA request mask clear -------------------------------*/

typedef struct {
  uint32_t DMA_REQMASKCLR0                        :1;
  uint32_t DMA_REQMASKCLR1                        :1;
  uint32_t DMA_REQMASKCLR2                        :1;
  uint32_t DMA_REQMASKCLR3                        :1;
  uint32_t DMA_REQMASKCLR4                        :1;
  uint32_t DMA_REQMASKCLR5                        :1;
  uint32_t DMA_REQMASKCLR6                        :1;
  uint32_t DMA_REQMASKCLR7                        :1;
  uint32_t DMA_REQMASKCLR8                        :1;
  uint32_t DMA_REQMASKCLR9                        :1;
  uint32_t DMA_REQMASKCLR10                       :1;
  uint32_t DMA_REQMASKCLR11                       :1;
  uint32_t DMA_REQMASKCLR12                       :1;
  uint32_t DMA_REQMASKCLR13                       :1;
  uint32_t DMA_REQMASKCLR14                       :1;
  uint32_t DMA_REQMASKCLR15                       :1;
  uint32_t DMA_REQMASKCLR16                       :1;
  uint32_t DMA_REQMASKCLR17                       :1;
  uint32_t DMA_REQMASKCLR18                       :1;
  uint32_t DMA_REQMASKCLR19                       :1;
  uint32_t DMA_REQMASKCLR20                       :1;
  uint32_t DMA_REQMASKCLR21                       :1;
  uint32_t DMA_REQMASKCLR22                       :1;
  uint32_t DMA_REQMASKCLR23                       :1;
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_REQ_MASK_CLR_bits;

/* Bit field positions: */
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR0_Pos           0
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR1_Pos           1
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR2_Pos           2
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR3_Pos           3
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR4_Pos           4
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR5_Pos           5
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR6_Pos           6
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR7_Pos           7
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR8_Pos           8
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR9_Pos           9
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR10_Pos          10
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR11_Pos          11
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR12_Pos          12
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR13_Pos          13
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR14_Pos          14
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR15_Pos          15
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR16_Pos          16
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR17_Pos          17
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR18_Pos          18
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR19_Pos          19
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR20_Pos          20
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR21_Pos          21
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR22_Pos          22
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR23_Pos          23

/* Bit field masks: */
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR0_Msk           0x00000001
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR1_Msk           0x00000002
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR2_Msk           0x00000004
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR3_Msk           0x00000008
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR4_Msk           0x00000010
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR5_Msk           0x00000020
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR6_Msk           0x00000040
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR7_Msk           0x00000080
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR8_Msk           0x00000100
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR9_Msk           0x00000200
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR10_Msk          0x00000400
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR11_Msk          0x00000800
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR12_Msk          0x00001000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR13_Msk          0x00002000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR14_Msk          0x00004000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR15_Msk          0x00008000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR16_Msk          0x00010000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR17_Msk          0x00020000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR18_Msk          0x00040000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR19_Msk          0x00080000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR20_Msk          0x00100000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR21_Msk          0x00200000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR22_Msk          0x00400000
#define DMA_CHNL_REQ_MASK_CLR_DMA_REQMASKCLR23_Msk          0x00800000

/*-- CHNL_ENABLE_SET: DMA channel enabled set --------------------------------*/

typedef struct {
  uint32_t DMA_ENSET0                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET1                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET2                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET3                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET4                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET5                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET6                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET7                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET8                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET9                             :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET10                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET11                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET12                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET13                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET14                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET15                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET16                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET17                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET18                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET19                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET20                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET21                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET22                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t DMA_ENSET23                            :1;                   /*!< Returns the status of dma_active[ ] */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_ENABLE_SET_bits;

/* Bit field positions: */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET0_Pos                  0           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET1_Pos                  1           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET2_Pos                  2           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET3_Pos                  3           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET4_Pos                  4           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET5_Pos                  5           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET6_Pos                  6           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET7_Pos                  7           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET8_Pos                  8           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET9_Pos                  9           /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET10_Pos                 10          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET11_Pos                 11          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET12_Pos                 12          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET13_Pos                 13          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET14_Pos                 14          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET15_Pos                 15          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET16_Pos                 16          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET17_Pos                 17          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET18_Pos                 18          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET19_Pos                 19          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET20_Pos                 20          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET21_Pos                 21          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET22_Pos                 22          /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET23_Pos                 23          /*!< Returns the status of dma_active[ ] */

/* Bit field masks: */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET0_Msk                  0x00000001  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET1_Msk                  0x00000002  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET2_Msk                  0x00000004  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET3_Msk                  0x00000008  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET4_Msk                  0x00000010  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET5_Msk                  0x00000020  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET6_Msk                  0x00000040  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET7_Msk                  0x00000080  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET8_Msk                  0x00000100  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET9_Msk                  0x00000200  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET10_Msk                 0x00000400  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET11_Msk                 0x00000800  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET12_Msk                 0x00001000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET13_Msk                 0x00002000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET14_Msk                 0x00004000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET15_Msk                 0x00008000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET16_Msk                 0x00010000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET17_Msk                 0x00020000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET18_Msk                 0x00040000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET19_Msk                 0x00080000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET20_Msk                 0x00100000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET21_Msk                 0x00200000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET22_Msk                 0x00400000  /*!< Returns the status of dma_active[ ] */
#define DMA_CHNL_ENABLE_SET_DMA_ENSET23_Msk                 0x00800000  /*!< Returns the status of dma_active[ ] */

/*-- CHNL_ENABLE_CLR: DMA channel enabled clear ------------------------------*/

typedef struct {
  uint32_t DMA_ENCLR0                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR1                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR2                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR3                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR4                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR5                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR6                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR7                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR8                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR9                             :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR10                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR11                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR12                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR13                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR14                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR15                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR16                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR17                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR18                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR19                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR20                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR21                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR22                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t DMA_ENCLR23                            :1;                   /*!< Enables you to set the dma_active[ ] */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_ENABLE_CLR_bits;

/* Bit field positions: */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR0_Pos                  0           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR1_Pos                  1           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR2_Pos                  2           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR3_Pos                  3           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR4_Pos                  4           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR5_Pos                  5           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR6_Pos                  6           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR7_Pos                  7           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR8_Pos                  8           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR9_Pos                  9           /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR10_Pos                 10          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR11_Pos                 11          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR12_Pos                 12          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR13_Pos                 13          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR14_Pos                 14          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR15_Pos                 15          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR16_Pos                 16          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR17_Pos                 17          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR18_Pos                 18          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR19_Pos                 19          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR20_Pos                 20          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR21_Pos                 21          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR22_Pos                 22          /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR23_Pos                 23          /*!< Enables you to set the dma_active[ ] */

/* Bit field masks: */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR0_Msk                  0x00000001  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR1_Msk                  0x00000002  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR2_Msk                  0x00000004  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR3_Msk                  0x00000008  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR4_Msk                  0x00000010  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR5_Msk                  0x00000020  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR6_Msk                  0x00000040  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR7_Msk                  0x00000080  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR8_Msk                  0x00000100  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR9_Msk                  0x00000200  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR10_Msk                 0x00000400  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR11_Msk                 0x00000800  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR12_Msk                 0x00001000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR13_Msk                 0x00002000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR14_Msk                 0x00004000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR15_Msk                 0x00008000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR16_Msk                 0x00010000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR17_Msk                 0x00020000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR18_Msk                 0x00040000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR19_Msk                 0x00080000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR20_Msk                 0x00100000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR21_Msk                 0x00200000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR22_Msk                 0x00400000  /*!< Enables you to set the dma_active[ ] */
#define DMA_CHNL_ENABLE_CLR_DMA_ENCLR23_Msk                 0x00800000  /*!< Enables you to set the dma_active[ ] */

/*-- CHNL_PRI_ALT_SET: Register setting primary / alternate channel control data structure */

typedef struct {
  uint32_t DMA_ALTSET0                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET1                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET2                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET3                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET4                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET5                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET6                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET7                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET8                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET9                            :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET10                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET11                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET12                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET13                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET14                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET15                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET16                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET17                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET18                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET19                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET20                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET21                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET22                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t DMA_ALTSET23                           :1;                   /*!< Set primary / alternate channel control data structure */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_PRI_ALT_SET_bits;

/* Bit field positions: */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET0_Pos                0           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET1_Pos                1           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET2_Pos                2           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET3_Pos                3           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET4_Pos                4           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET5_Pos                5           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET6_Pos                6           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET7_Pos                7           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET8_Pos                8           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET9_Pos                9           /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET10_Pos               10          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET11_Pos               11          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET12_Pos               12          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET13_Pos               13          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET14_Pos               14          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET15_Pos               15          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET16_Pos               16          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET17_Pos               17          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET18_Pos               18          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET19_Pos               19          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET20_Pos               20          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET21_Pos               21          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET22_Pos               22          /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET23_Pos               23          /*!< Set primary / alternate channel control data structure */

/* Bit field masks: */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET0_Msk                0x00000001  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET1_Msk                0x00000002  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET2_Msk                0x00000004  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET3_Msk                0x00000008  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET4_Msk                0x00000010  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET5_Msk                0x00000020  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET6_Msk                0x00000040  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET7_Msk                0x00000080  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET8_Msk                0x00000100  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET9_Msk                0x00000200  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET10_Msk               0x00000400  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET11_Msk               0x00000800  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET12_Msk               0x00001000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET13_Msk               0x00002000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET14_Msk               0x00004000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET15_Msk               0x00008000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET16_Msk               0x00010000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET17_Msk               0x00020000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET18_Msk               0x00040000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET19_Msk               0x00080000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET20_Msk               0x00100000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET21_Msk               0x00200000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET22_Msk               0x00400000  /*!< Set primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_SET_DMA_ALTSET23_Msk               0x00800000  /*!< Set primary / alternate channel control data structure */

/*-- CHNL_PRI_ALT_CLR: Register clearing primary / alternate channel control data structure */

typedef struct {
  uint32_t DMA_ALTCLR0                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR1                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR2                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR3                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR4                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR5                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR6                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR7                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR8                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR9                            :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR10                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR11                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR12                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR13                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR14                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR15                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR16                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR17                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR18                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR19                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR20                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR21                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR22                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t DMA_ALTCLR23                           :1;                   /*!< Clear primary / alternate channel control data structure */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_PRI_ALT_CLR_bits;

/* Bit field positions: */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR0_Pos                0           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR1_Pos                1           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR2_Pos                2           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR3_Pos                3           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR4_Pos                4           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR5_Pos                5           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR6_Pos                6           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR7_Pos                7           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR8_Pos                8           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR9_Pos                9           /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR10_Pos               10          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR11_Pos               11          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR12_Pos               12          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR13_Pos               13          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR14_Pos               14          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR15_Pos               15          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR16_Pos               16          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR17_Pos               17          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR18_Pos               18          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR19_Pos               19          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR20_Pos               20          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR21_Pos               21          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR22_Pos               22          /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR23_Pos               23          /*!< Clear primary / alternate channel control data structure */

/* Bit field masks: */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR0_Msk                0x00000001  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR1_Msk                0x00000002  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR2_Msk                0x00000004  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR3_Msk                0x00000008  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR4_Msk                0x00000010  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR5_Msk                0x00000020  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR6_Msk                0x00000040  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR7_Msk                0x00000080  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR8_Msk                0x00000100  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR9_Msk                0x00000200  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR10_Msk               0x00000400  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR11_Msk               0x00000800  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR12_Msk               0x00001000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR13_Msk               0x00002000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR14_Msk               0x00004000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR15_Msk               0x00008000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR16_Msk               0x00010000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR17_Msk               0x00020000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR18_Msk               0x00040000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR19_Msk               0x00080000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR20_Msk               0x00100000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR21_Msk               0x00200000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR22_Msk               0x00400000  /*!< Clear primary / alternate channel control data structure */
#define DMA_CHNL_PRI_ALT_CLR_DMA_ALTCLR23_Msk               0x00800000  /*!< Clear primary / alternate channel control data structure */

/*-- CHNL_PRIORITY_SET: Register set the priority channel --------------------*/

typedef struct {
  uint32_t DMA_PRISET0                            :1;                   /*!< Set the priority channel0 */
  uint32_t DMA_PRISET1                            :1;                   /*!< Set the priority channel1 */
  uint32_t DMA_PRISET2                            :1;                   /*!< Set the priority channel2 */
  uint32_t DMA_PRISET3                            :1;                   /*!< Set the priority channel3 */
  uint32_t DMA_PRISET4                            :1;                   /*!< Set the priority channel4 */
  uint32_t DMA_PRISET5                            :1;                   /*!< Set the priority channel5 */
  uint32_t DMA_PRISET6                            :1;                   /*!< Set the priority channel6 */
  uint32_t DMA_PRISET7                            :1;                   /*!< Set the priority channel7 */
  uint32_t DMA_PRISET8                            :1;                   /*!< Set the priority channel8 */
  uint32_t DMA_PRISET9                            :1;                   /*!< Set the priority channel9 */
  uint32_t DMA_PRISET10                           :1;                   /*!< Set the priority channel10 */
  uint32_t DMA_PRISET11                           :1;                   /*!< Set the priority channel11 */
  uint32_t DMA_PRISET12                           :1;                   /*!< Set the priority channel12 */
  uint32_t DMA_PRISET13                           :1;                   /*!< Set the priority channel13 */
  uint32_t DMA_PRISET14                           :1;                   /*!< Set the priority channel14 */
  uint32_t DMA_PRISET15                           :1;                   /*!< Set the priority channel15 */
  uint32_t DMA_PRISET16                           :1;                   /*!< Set the priority channel16 */
  uint32_t DMA_PRISET17                           :1;                   /*!< Set the priority channel17 */
  uint32_t DMA_PRISET18                           :1;                   /*!< Set the priority channel18 */
  uint32_t DMA_PRISET19                           :1;                   /*!< Set the priority channel19 */
  uint32_t DMA_PRISET20                           :1;                   /*!< Set the priority channel20 */
  uint32_t DMA_PRISET21                           :1;                   /*!< Set the priority channel21 */
  uint32_t DMA_PRISET22                           :1;                   /*!< Set the priority channel22 */
  uint32_t DMA_PRISET23                           :1;                   /*!< Set the priority channel23 */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_PRIORITY_SET_bits;

/* Bit field positions: */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET0_Pos               0           /*!< Set the priority channel0 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET1_Pos               1           /*!< Set the priority channel1 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET2_Pos               2           /*!< Set the priority channel2 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET3_Pos               3           /*!< Set the priority channel3 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET4_Pos               4           /*!< Set the priority channel4 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET5_Pos               5           /*!< Set the priority channel5 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET6_Pos               6           /*!< Set the priority channel6 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET7_Pos               7           /*!< Set the priority channel7 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET8_Pos               8           /*!< Set the priority channel8 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET9_Pos               9           /*!< Set the priority channel9 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET10_Pos              10          /*!< Set the priority channel10 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET11_Pos              11          /*!< Set the priority channel11 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET12_Pos              12          /*!< Set the priority channel12 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET13_Pos              13          /*!< Set the priority channel13 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET14_Pos              14          /*!< Set the priority channel14 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET15_Pos              15          /*!< Set the priority channel15 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET16_Pos              16          /*!< Set the priority channel16 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET17_Pos              17          /*!< Set the priority channel17 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET18_Pos              18          /*!< Set the priority channel18 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET19_Pos              19          /*!< Set the priority channel19 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET20_Pos              20          /*!< Set the priority channel20 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET21_Pos              21          /*!< Set the priority channel21 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET22_Pos              22          /*!< Set the priority channel22 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET23_Pos              23          /*!< Set the priority channel23 */

/* Bit field masks: */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET0_Msk               0x00000001  /*!< Set the priority channel0 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET1_Msk               0x00000002  /*!< Set the priority channel1 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET2_Msk               0x00000004  /*!< Set the priority channel2 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET3_Msk               0x00000008  /*!< Set the priority channel3 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET4_Msk               0x00000010  /*!< Set the priority channel4 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET5_Msk               0x00000020  /*!< Set the priority channel5 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET6_Msk               0x00000040  /*!< Set the priority channel6 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET7_Msk               0x00000080  /*!< Set the priority channel7 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET8_Msk               0x00000100  /*!< Set the priority channel8 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET9_Msk               0x00000200  /*!< Set the priority channel9 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET10_Msk              0x00000400  /*!< Set the priority channel10 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET11_Msk              0x00000800  /*!< Set the priority channel11 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET12_Msk              0x00001000  /*!< Set the priority channel12 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET13_Msk              0x00002000  /*!< Set the priority channel13 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET14_Msk              0x00004000  /*!< Set the priority channel14 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET15_Msk              0x00008000  /*!< Set the priority channel15 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET16_Msk              0x00010000  /*!< Set the priority channel16 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET17_Msk              0x00020000  /*!< Set the priority channel17 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET18_Msk              0x00040000  /*!< Set the priority channel18 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET19_Msk              0x00080000  /*!< Set the priority channel19 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET20_Msk              0x00100000  /*!< Set the priority channel20 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET21_Msk              0x00200000  /*!< Set the priority channel21 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET22_Msk              0x00400000  /*!< Set the priority channel22 */
#define DMA_CHNL_PRIORITY_SET_DMA_PRISET23_Msk              0x00800000  /*!< Set the priority channel23 */

/*-- CHNL_PRIORITY_CLR: Register clear the priority channel ------------------*/

typedef struct {
  uint32_t DMA_PRICLR0                            :1;                   /*!< Clear the priority channel0 */
  uint32_t DMA_PRICLR1                            :1;                   /*!< Clear the priority channel1 */
  uint32_t DMA_PRICLR2                            :1;                   /*!< Clear the priority channel2 */
  uint32_t DMA_PRICLR3                            :1;                   /*!< Clear the priority channel3 */
  uint32_t DMA_PRICLR4                            :1;                   /*!< Clear the priority channel4 */
  uint32_t DMA_PRICLR5                            :1;                   /*!< Clear the priority channel5 */
  uint32_t DMA_PRICLR6                            :1;                   /*!< Clear the priority channel6 */
  uint32_t DMA_PRICLR7                            :1;                   /*!< Clear the priority channel7 */
  uint32_t DMA_PRICLR8                            :1;                   /*!< Clear the priority channel8 */
  uint32_t DMA_PRICLR9                            :1;                   /*!< Clear the priority channel9 */
  uint32_t DMA_PRICLR10                           :1;                   /*!< Clear the priority channel10 */
  uint32_t DMA_PRICLR11                           :1;                   /*!< Clear the priority channel11 */
  uint32_t DMA_PRICLR12                           :1;                   /*!< Clear the priority channel12 */
  uint32_t DMA_PRICLR13                           :1;                   /*!< Clear the priority channel13 */
  uint32_t DMA_PRICLR14                           :1;                   /*!< Clear the priority channel14 */
  uint32_t DMA_PRICLR15                           :1;                   /*!< Clear the priority channel15 */
  uint32_t DMA_PRICLR16                           :1;                   /*!< Clear the priority channel16 */
  uint32_t DMA_PRICLR17                           :1;                   /*!< Clear the priority channel17 */
  uint32_t DMA_PRICLR18                           :1;                   /*!< Clear the priority channel18 */
  uint32_t DMA_PRICLR19                           :1;                   /*!< Clear the priority channel19 */
  uint32_t DMA_PRICLR20                           :1;                   /*!< Clear the priority channel20 */
  uint32_t DMA_PRICLR21                           :1;                   /*!< Clear the priority channel21 */
  uint32_t DMA_PRICLR22                           :1;                   /*!< Clear the priority channel22 */
  uint32_t DMA_PRICLR23                           :1;                   /*!< Clear the priority channel23 */
  uint32_t Reserved0                              :8;                   /*!< Reserved */
} _DMA_CHNL_PRIORITY_CLR_bits;

/* Bit field positions: */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR0_Pos               0           /*!< Clear the priority channel0 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR1_Pos               1           /*!< Clear the priority channel1 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR2_Pos               2           /*!< Clear the priority channel2 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR3_Pos               3           /*!< Clear the priority channel3 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR4_Pos               4           /*!< Clear the priority channel4 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR5_Pos               5           /*!< Clear the priority channel5 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR6_Pos               6           /*!< Clear the priority channel6 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR7_Pos               7           /*!< Clear the priority channel7 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR8_Pos               8           /*!< Clear the priority channel8 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR9_Pos               9           /*!< Clear the priority channel9 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR10_Pos              10          /*!< Clear the priority channel10 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR11_Pos              11          /*!< Clear the priority channel11 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR12_Pos              12          /*!< Clear the priority channel12 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR13_Pos              13          /*!< Clear the priority channel13 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR14_Pos              14          /*!< Clear the priority channel14 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR15_Pos              15          /*!< Clear the priority channel15 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR16_Pos              16          /*!< Clear the priority channel16 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR17_Pos              17          /*!< Clear the priority channel17 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR18_Pos              18          /*!< Clear the priority channel18 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR19_Pos              19          /*!< Clear the priority channel19 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR20_Pos              20          /*!< Clear the priority channel20 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR21_Pos              21          /*!< Clear the priority channel21 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR22_Pos              22          /*!< Clear the priority channel22 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR23_Pos              23          /*!< Clear the priority channel23 */

/* Bit field masks: */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR0_Msk               0x00000001  /*!< Clear the priority channel0 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR1_Msk               0x00000002  /*!< Clear the priority channel1 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR2_Msk               0x00000004  /*!< Clear the priority channel2 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR3_Msk               0x00000008  /*!< Clear the priority channel3 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR4_Msk               0x00000010  /*!< Clear the priority channel4 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR5_Msk               0x00000020  /*!< Clear the priority channel5 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR6_Msk               0x00000040  /*!< Clear the priority channel6 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR7_Msk               0x00000080  /*!< Clear the priority channel7 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR8_Msk               0x00000100  /*!< Clear the priority channel8 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR9_Msk               0x00000200  /*!< Clear the priority channel9 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR10_Msk              0x00000400  /*!< Clear the priority channel10 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR11_Msk              0x00000800  /*!< Clear the priority channel11 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR12_Msk              0x00001000  /*!< Clear the priority channel12 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR13_Msk              0x00002000  /*!< Clear the priority channel13 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR14_Msk              0x00004000  /*!< Clear the priority channel14 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR15_Msk              0x00008000  /*!< Clear the priority channel15 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR16_Msk              0x00010000  /*!< Clear the priority channel16 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR17_Msk              0x00020000  /*!< Clear the priority channel17 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR18_Msk              0x00040000  /*!< Clear the priority channel18 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR19_Msk              0x00080000  /*!< Clear the priority channel19 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR20_Msk              0x00100000  /*!< Clear the priority channel20 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR21_Msk              0x00200000  /*!< Clear the priority channel21 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR22_Msk              0x00400000  /*!< Clear the priority channel22 */
#define DMA_CHNL_PRIORITY_CLR_DMA_PRICLR23_Msk              0x00800000  /*!< Clear the priority channel23 */

/*-- ERR_CLR: Flag error clear register --------------------------------------*/

typedef struct {
  uint32_t ERR_CLR                                :1;                   /*!< Indicate Error on bus AHB-Lite / Clear flag error */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _DMA_ERR_CLR_bits;

/* Bit field positions: */
#define DMA_ERR_CLR_ERR_CLR_Pos                             0           /*!< Indicate Error on bus AHB-Lite / Clear flag error */

/* Bit field masks: */
#define DMA_ERR_CLR_ERR_CLR_Msk                             0x00000001  /*!< Indicate Error on bus AHB-Lite / Clear flag error */

/*-- Register map for DMA peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Status DMA register */
    __I  uint32_t STATUS;                                               /*!< STATUS    : type used for word access */
    __I  _DMA_STATUS_bits STATUS_bit;                                   /*!< STATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< Configurate DMA register */
    __O  uint32_t CFG;                                                  /*!< CFG    : type used for word access */
    __O  _DMA_CFG_bits CFG_bit;                                         /*!< CFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Base address register control data channels */
    __IO uint32_t CTRL_BASE_PTR;                                        /*!< CTRL_BASE_PTR    : type used for word access */
    __IO _DMA_CTRL_BASE_PTR_bits CTRL_BASE_PTR_bit;                     /*!< CTRL_BASE_PTR_bit: structure used for bit access */
  };
  __I  uint32_t ALT_CTRL_BASE_PTR;                                      /*!< Alternate base address register control data channels */
  union {                                                               /*!< DMA wait request status */
    __I  uint32_t WAITONREQ_STATUS;                                     /*!< WAITONREQ_STATUS    : type used for word access */
    __I  _DMA_WAITONREQ_STATUS_bits WAITONREQ_STATUS_bit;               /*!< WAITONREQ_STATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< Register software process request DMA channels */
    __O  uint32_t CHNL_SW_REQUEST;                                      /*!< CHNL_SW_REQUEST    : type used for word access */
    __O  _DMA_CHNL_SW_REQUEST_bits CHNL_SW_REQUEST_bit;                 /*!< CHNL_SW_REQUEST_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Set Packet Exchange DMA channels */
    __IO uint32_t CHNL_USEBURST_SET;                                    /*!< CHNL_USEBURST_SET    : type used for word access */
    __IO _DMA_CHNL_USEBURST_SET_bits CHNL_USEBURST_SET_bit;             /*!< CHNL_USEBURST_SET_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Clear Packet Exchange DMA channels */
    __O  uint32_t CHNL_USEBURST_CLR;                                    /*!< CHNL_USEBURST_CLR    : type used for word access */
    __O  _DMA_CHNL_USEBURST_CLR_bits CHNL_USEBURST_CLR_bit;             /*!< CHNL_USEBURST_CLR_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request mask set */
    __IO uint32_t CHNL_REQ_MASK_SET;                                    /*!< CHNL_REQ_MASK_SET    : type used for word access */
    __IO _DMA_CHNL_REQ_MASK_SET_bits CHNL_REQ_MASK_SET_bit;             /*!< CHNL_REQ_MASK_SET_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request mask clear */
    __O  uint32_t CHNL_REQ_MASK_CLR;                                    /*!< CHNL_REQ_MASK_CLR    : type used for word access */
    __O  _DMA_CHNL_REQ_MASK_CLR_bits CHNL_REQ_MASK_CLR_bit;             /*!< CHNL_REQ_MASK_CLR_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA channel enabled set */
    __IO uint32_t CHNL_ENABLE_SET;                                      /*!< CHNL_ENABLE_SET    : type used for word access */
    __IO _DMA_CHNL_ENABLE_SET_bits CHNL_ENABLE_SET_bit;                 /*!< CHNL_ENABLE_SET_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA channel enabled clear */
    __O  uint32_t CHNL_ENABLE_CLR;                                      /*!< CHNL_ENABLE_CLR    : type used for word access */
    __O  _DMA_CHNL_ENABLE_CLR_bits CHNL_ENABLE_CLR_bit;                 /*!< CHNL_ENABLE_CLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register setting primary / alternate channel control data structure */
    __IO uint32_t CHNL_PRI_ALT_SET;                                     /*!< CHNL_PRI_ALT_SET    : type used for word access */
    __IO _DMA_CHNL_PRI_ALT_SET_bits CHNL_PRI_ALT_SET_bit;               /*!< CHNL_PRI_ALT_SET_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clearing primary / alternate channel control data structure */
    __O  uint32_t CHNL_PRI_ALT_CLR;                                     /*!< CHNL_PRI_ALT_CLR    : type used for word access */
    __O  _DMA_CHNL_PRI_ALT_CLR_bits CHNL_PRI_ALT_CLR_bit;               /*!< CHNL_PRI_ALT_CLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register set the priority channel */
    __IO uint32_t CHNL_PRIORITY_SET;                                    /*!< CHNL_PRIORITY_SET    : type used for word access */
    __IO _DMA_CHNL_PRIORITY_SET_bits CHNL_PRIORITY_SET_bit;             /*!< CHNL_PRIORITY_SET_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear the priority channel */
    __O  uint32_t CHNL_PRIORITY_CLR;                                    /*!< CHNL_PRIORITY_CLR    : type used for word access */
    __O  _DMA_CHNL_PRIORITY_CLR_bits CHNL_PRIORITY_CLR_bit;             /*!< CHNL_PRIORITY_CLR_bit: structure used for bit access */
  };
  uint32_t Reserved0[3];                                                /*!< Reserved */
  union {                                                               /*!< Flag error clear register */
    __IO uint32_t ERR_CLR;                                              /*!< ERR_CLR    : type used for word access */
    __IO _DMA_ERR_CLR_bits ERR_CLR_bit;                                 /*!< ERR_CLR_bit: structure used for bit access */
  };
} NT_DMA_TypeDef;

/******************************************************************************/
/*                        UART controller registers                           */
/******************************************************************************/

/*-- DR: Data Register -------------------------------------------------------*/

typedef struct {
  uint32_t DATA                                   :8;                   /*!< Received/Transmitted data character */
  uint32_t FE                                     :1;                   /*!< Framing error */
  uint32_t PE                                     :1;                   /*!< Parity error */
  uint32_t BE                                     :1;                   /*!< Break error */
  uint32_t OE                                     :1;                   /*!< Overrun error */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _UART_DR_bits;

/* Bit field positions: */
#define UART_DR_DATA_Pos                                    0           /*!< Received/Transmitted data character */
#define UART_DR_FE_Pos                                      8           /*!< Framing error */
#define UART_DR_PE_Pos                                      9           /*!< Parity error */
#define UART_DR_BE_Pos                                      10          /*!< Break error */
#define UART_DR_OE_Pos                                      11          /*!< Overrun error */

/* Bit field masks: */
#define UART_DR_DATA_Msk                                    0x000000FF  /*!< Received/Transmitted data character */
#define UART_DR_FE_Msk                                      0x00000100  /*!< Framing error */
#define UART_DR_PE_Msk                                      0x00000200  /*!< Parity error */
#define UART_DR_BE_Msk                                      0x00000400  /*!< Break error */
#define UART_DR_OE_Msk                                      0x00000800  /*!< Overrun error */

/*-- RSR_ECR: Receive Status Register/Error Clear Register -------------------*/

typedef struct {
  uint32_t FE                                     :1;                   /*!< Framing error */
  uint32_t PE                                     :1;                   /*!< Parity error */
  uint32_t BE                                     :1;                   /*!< Break error */
  uint32_t OE                                     :1;                   /*!< Overrun error */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _UART_RSR_ECR_bits;

/* Bit field positions: */
#define UART_RSR_ECR_FE_Pos                                 0           /*!< Framing error */
#define UART_RSR_ECR_PE_Pos                                 1           /*!< Parity error */
#define UART_RSR_ECR_BE_Pos                                 2           /*!< Break error */
#define UART_RSR_ECR_OE_Pos                                 3           /*!< Overrun error */

/* Bit field masks: */
#define UART_RSR_ECR_FE_Msk                                 0x00000001  /*!< Framing error */
#define UART_RSR_ECR_PE_Msk                                 0x00000002  /*!< Parity error */
#define UART_RSR_ECR_BE_Msk                                 0x00000004  /*!< Break error */
#define UART_RSR_ECR_OE_Msk                                 0x00000008  /*!< Overrun error */

/*-- FR: Flag Register -------------------------------------------------------*/

typedef struct {
  uint32_t CTS                                    :1;                   /*!< Clear to send */
  uint32_t DSR                                    :1;                   /*!< Data set ready */
  uint32_t DCD                                    :1;                   /*!< Data carrier detect */
  uint32_t BUSY                                   :1;                   /*!< UART busy */
  uint32_t RXFE                                   :1;                   /*!< Receive FIFO empty */
  uint32_t TXFF                                   :1;                   /*!< Transmit FIFO full */
  uint32_t RXFF                                   :1;                   /*!< Receive FIFO full */
  uint32_t TXFE                                   :1;                   /*!< Transmit FIFO empty */
  uint32_t RI                                     :1;                   /*!< Ring indicator */
  uint32_t Reserved0                              :23;                  /*!< Reserved */
} _UART_FR_bits;

/* Bit field positions: */
#define UART_FR_CTS_Pos                                     0           /*!< Clear to send */
#define UART_FR_DSR_Pos                                     1           /*!< Data set ready */
#define UART_FR_DCD_Pos                                     2           /*!< Data carrier detect */
#define UART_FR_BUSY_Pos                                    3           /*!< UART busy */
#define UART_FR_RXFE_Pos                                    4           /*!< Receive FIFO empty */
#define UART_FR_TXFF_Pos                                    5           /*!< Transmit FIFO full */
#define UART_FR_RXFF_Pos                                    6           /*!< Receive FIFO full */
#define UART_FR_TXFE_Pos                                    7           /*!< Transmit FIFO empty */
#define UART_FR_RI_Pos                                      8           /*!< Ring indicator */

/* Bit field masks: */
#define UART_FR_CTS_Msk                                     0x00000001  /*!< Clear to send */
#define UART_FR_DSR_Msk                                     0x00000002  /*!< Data set ready */
#define UART_FR_DCD_Msk                                     0x00000004  /*!< Data carrier detect */
#define UART_FR_BUSY_Msk                                    0x00000008  /*!< UART busy */
#define UART_FR_RXFE_Msk                                    0x00000010  /*!< Receive FIFO empty */
#define UART_FR_TXFF_Msk                                    0x00000020  /*!< Transmit FIFO full */
#define UART_FR_RXFF_Msk                                    0x00000040  /*!< Receive FIFO full */
#define UART_FR_TXFE_Msk                                    0x00000080  /*!< Transmit FIFO empty */
#define UART_FR_RI_Msk                                      0x00000100  /*!< Ring indicator */

/*-- IBRD: Integer Baud Rate Register ----------------------------------------*/

typedef struct {
  uint32_t BAUD_DIVINT                            :16;                  /*!< The integer baud rate divisor */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _UART_IBRD_bits;

/* Bit field positions: */
#define UART_IBRD_BAUD_DIVINT_Pos                           0           /*!< The integer baud rate divisor */

/* Bit field masks: */
#define UART_IBRD_BAUD_DIVINT_Msk                           0x0000FFFF  /*!< The integer baud rate divisor */

/*-- FBRD: Fractional Baud Rate Register -------------------------------------*/

typedef struct {
  uint32_t BAUD_DIVFRAC                           :6;                   /*!< The fractional baud rate divisor */
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _UART_FBRD_bits;

/* Bit field positions: */
#define UART_FBRD_BAUD_DIVFRAC_Pos                          0           /*!< The fractional baud rate divisor */

/* Bit field masks: */
#define UART_FBRD_BAUD_DIVFRAC_Msk                          0x0000003F  /*!< The fractional baud rate divisor */

/*-- LCR_H: Line Control Register --------------------------------------------*/

typedef struct {
  uint32_t BRK                                    :1;                   /*!< Send break */
  uint32_t PEN                                    :1;                   /*!< Parity enable */
  uint32_t EPS                                    :1;                   /*!< Even parity select */
  uint32_t STP2                                   :1;                   /*!< Two stop bits select */
  uint32_t FEN                                    :1;                   /*!< Enable FIFOs */
  uint32_t WLEN                                   :2;                   /*!< Word length */
  uint32_t SPS                                    :1;                   /*!< Stick parity select */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _UART_LCR_H_bits;

/* Bit field positions: */
#define UART_LCR_H_BRK_Pos                                  0           /*!< Send break */
#define UART_LCR_H_PEN_Pos                                  1           /*!< Parity enable */
#define UART_LCR_H_EPS_Pos                                  2           /*!< Even parity select */
#define UART_LCR_H_STP2_Pos                                 3           /*!< Two stop bits select */
#define UART_LCR_H_FEN_Pos                                  4           /*!< Enable FIFOs */
#define UART_LCR_H_WLEN_Pos                                 5           /*!< Word length */
#define UART_LCR_H_SPS_Pos                                  7           /*!< Stick parity select */

/* Bit field masks: */
#define UART_LCR_H_BRK_Msk                                  0x00000001  /*!< Send break */
#define UART_LCR_H_PEN_Msk                                  0x00000002  /*!< Parity enable */
#define UART_LCR_H_EPS_Msk                                  0x00000004  /*!< Even parity select */
#define UART_LCR_H_STP2_Msk                                 0x00000008  /*!< Two stop bits select */
#define UART_LCR_H_FEN_Msk                                  0x00000010  /*!< Enable FIFOs */
#define UART_LCR_H_WLEN_Msk                                 0x00000060  /*!< Word length */
#define UART_LCR_H_SPS_Msk                                  0x00000080  /*!< Stick parity select */

/*-- CR: Control Register ----------------------------------------------------*/

typedef struct {
  uint32_t UARTEN                                 :1;                   /*!< UART enable */
  uint32_t Reserved0                              :7;                   /*!< Reserved */
  uint32_t TXE                                    :1;                   /*!< Transmit enable */
  uint32_t RXE                                    :1;                   /*!< Receive enable */
  uint32_t DTR                                    :1;                   /*!< Data transmit ready */
  uint32_t RTS                                    :1;                   /*!< Request to send */
  uint32_t OUT1                                   :1;                   /*!< This bit is the complement of the UART Out1 (nUARTOut1) modem status output */
  uint32_t OUT2                                   :1;                   /*!< This bit is the complement of the UART Out2 (nUARTOut2) modem status output */
  uint32_t RTSEN                                  :1;                   /*!< RTS hardware flow control enable */
  uint32_t CTSEN                                  :1;                   /*!< CTS hardware flow control enable */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _UART_CR_bits;

/* Bit field positions: */
#define UART_CR_UARTEN_Pos                                  0           /*!< UART enable */
#define UART_CR_TXE_Pos                                     8           /*!< Transmit enable */
#define UART_CR_RXE_Pos                                     9           /*!< Receive enable */
#define UART_CR_DTR_Pos                                     10          /*!< Data transmit ready */
#define UART_CR_RTS_Pos                                     11          /*!< Request to send */
#define UART_CR_OUT1_Pos                                    12          /*!< This bit is the complement of the UART Out1 (nUARTOut1) modem status output */
#define UART_CR_OUT2_Pos                                    13          /*!< This bit is the complement of the UART Out2 (nUARTOut2) modem status output */
#define UART_CR_RTSEN_Pos                                   14          /*!< RTS hardware flow control enable */
#define UART_CR_CTSEN_Pos                                   15          /*!< CTS hardware flow control enable */

/* Bit field masks: */
#define UART_CR_UARTEN_Msk                                  0x00000001  /*!< UART enable */
#define UART_CR_TXE_Msk                                     0x00000100  /*!< Transmit enable */
#define UART_CR_RXE_Msk                                     0x00000200  /*!< Receive enable */
#define UART_CR_DTR_Msk                                     0x00000400  /*!< Data transmit ready */
#define UART_CR_RTS_Msk                                     0x00000800  /*!< Request to send */
#define UART_CR_OUT1_Msk                                    0x00001000  /*!< This bit is the complement of the UART Out1 (nUARTOut1) modem status output */
#define UART_CR_OUT2_Msk                                    0x00002000  /*!< This bit is the complement of the UART Out2 (nUARTOut2) modem status output */
#define UART_CR_RTSEN_Msk                                   0x00004000  /*!< RTS hardware flow control enable */
#define UART_CR_CTSEN_Msk                                   0x00008000  /*!< CTS hardware flow control enable */

/*-- IFLS: Interrupt FIFO Level Select Register ------------------------------*/

typedef struct {
  uint32_t TXIFLSEL                               :3;                   /*!< Transmit interrupt FIFO level select */
  uint32_t RXIFLSEL                               :3;                   /*!< Receive interrupt FIFO level select */
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _UART_IFLS_bits;

/* Bit field positions: */
#define UART_IFLS_TXIFLSEL_Pos                              0           /*!< Transmit interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_Pos                              3           /*!< Receive interrupt FIFO level select */

/* Bit field masks: */
#define UART_IFLS_TXIFLSEL_Msk                              0x00000007  /*!< Transmit interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_Msk                              0x00000038  /*!< Receive interrupt FIFO level select */

/*-- IMSC: Interrupt Mask Set/Clear Register ---------------------------------*/

typedef struct {
  uint32_t RIMIM                                  :1;                   /*!< nUARTRI modem interrupt mask */
  uint32_t CTSMIM                                 :1;                   /*!< nUARTCTS modem interrupt mask */
  uint32_t DCDMIM                                 :1;                   /*!< nUARTDCD modem interrupt mask */
  uint32_t DSRMIM                                 :1;                   /*!< nUARTDSR modem interrupt mask */
  uint32_t RXIM                                   :1;                   /*!< Receive interrupt mask */
  uint32_t TXIM                                   :1;                   /*!< Transmit interrupt mask */
  uint32_t RTIM                                   :1;                   /*!< Receive timeout interrupt mask */
  uint32_t FEIM                                   :1;                   /*!< Framing error interrupt mask */
  uint32_t PEIM                                   :1;                   /*!< Parity error interrupt mask */
  uint32_t BEIM                                   :1;                   /*!< Break error interrupt mask */
  uint32_t OEIM                                   :1;                   /*!< Overrun error interrupt mask */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _UART_IMSC_bits;

/* Bit field positions: */
#define UART_IMSC_RIMIM_Pos                                 0           /*!< nUARTRI modem interrupt mask */
#define UART_IMSC_CTSMIM_Pos                                1           /*!< nUARTCTS modem interrupt mask */
#define UART_IMSC_DCDMIM_Pos                                2           /*!< nUARTDCD modem interrupt mask */
#define UART_IMSC_DSRMIM_Pos                                3           /*!< nUARTDSR modem interrupt mask */
#define UART_IMSC_RXIM_Pos                                  4           /*!< Receive interrupt mask */
#define UART_IMSC_TXIM_Pos                                  5           /*!< Transmit interrupt mask */
#define UART_IMSC_RTIM_Pos                                  6           /*!< Receive timeout interrupt mask */
#define UART_IMSC_FEIM_Pos                                  7           /*!< Framing error interrupt mask */
#define UART_IMSC_PEIM_Pos                                  8           /*!< Parity error interrupt mask */
#define UART_IMSC_BEIM_Pos                                  9           /*!< Break error interrupt mask */
#define UART_IMSC_OEIM_Pos                                  10          /*!< Overrun error interrupt mask */

/* Bit field masks: */
#define UART_IMSC_RIMIM_Msk                                 0x00000001  /*!< nUARTRI modem interrupt mask */
#define UART_IMSC_CTSMIM_Msk                                0x00000002  /*!< nUARTCTS modem interrupt mask */
#define UART_IMSC_DCDMIM_Msk                                0x00000004  /*!< nUARTDCD modem interrupt mask */
#define UART_IMSC_DSRMIM_Msk                                0x00000008  /*!< nUARTDSR modem interrupt mask */
#define UART_IMSC_RXIM_Msk                                  0x00000010  /*!< Receive interrupt mask */
#define UART_IMSC_TXIM_Msk                                  0x00000020  /*!< Transmit interrupt mask */
#define UART_IMSC_RTIM_Msk                                  0x00000040  /*!< Receive timeout interrupt mask */
#define UART_IMSC_FEIM_Msk                                  0x00000080  /*!< Framing error interrupt mask */
#define UART_IMSC_PEIM_Msk                                  0x00000100  /*!< Parity error interrupt mask */
#define UART_IMSC_BEIM_Msk                                  0x00000200  /*!< Break error interrupt mask */
#define UART_IMSC_OEIM_Msk                                  0x00000400  /*!< Overrun error interrupt mask */

/*-- RIS: Raw Interrupt Status Register --------------------------------------*/

typedef struct {
  uint32_t RIRMIS                                 :1;                   /*!< nUARTRI modem interrupt status */
  uint32_t CTSRMIS                                :1;                   /*!< nUARTCTS modem interrupt status */
  uint32_t DCDRMIS                                :1;                   /*!< nUARTDCD modem interrupt status */
  uint32_t DSRRMIS                                :1;                   /*!< nUARTDSR modem interrupt status */
  uint32_t RXRIS                                  :1;                   /*!< Receive interrupt status */
  uint32_t TXRIS                                  :1;                   /*!< Transmit interrupt status */
  uint32_t RTRIS                                  :1;                   /*!< Receive timeout interrupt status */
  uint32_t FERIS                                  :1;                   /*!< Framing error interrupt status */
  uint32_t PERIS                                  :1;                   /*!< Parity error interrupt status */
  uint32_t BERIS                                  :1;                   /*!< Break error interrupt status */
  uint32_t OERIS                                  :1;                   /*!< Overrun error interrupt status */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _UART_RIS_bits;

/* Bit field positions: */
#define UART_RIS_RIRMIS_Pos                                 0           /*!< nUARTRI modem interrupt status */
#define UART_RIS_CTSRMIS_Pos                                1           /*!< nUARTCTS modem interrupt status */
#define UART_RIS_DCDRMIS_Pos                                2           /*!< nUARTDCD modem interrupt status */
#define UART_RIS_DSRRMIS_Pos                                3           /*!< nUARTDSR modem interrupt status */
#define UART_RIS_RXRIS_Pos                                  4           /*!< Receive interrupt status */
#define UART_RIS_TXRIS_Pos                                  5           /*!< Transmit interrupt status */
#define UART_RIS_RTRIS_Pos                                  6           /*!< Receive timeout interrupt status */
#define UART_RIS_FERIS_Pos                                  7           /*!< Framing error interrupt status */
#define UART_RIS_PERIS_Pos                                  8           /*!< Parity error interrupt status */
#define UART_RIS_BERIS_Pos                                  9           /*!< Break error interrupt status */
#define UART_RIS_OERIS_Pos                                  10          /*!< Overrun error interrupt status */

/* Bit field masks: */
#define UART_RIS_RIRMIS_Msk                                 0x00000001  /*!< nUARTRI modem interrupt status */
#define UART_RIS_CTSRMIS_Msk                                0x00000002  /*!< nUARTCTS modem interrupt status */
#define UART_RIS_DCDRMIS_Msk                                0x00000004  /*!< nUARTDCD modem interrupt status */
#define UART_RIS_DSRRMIS_Msk                                0x00000008  /*!< nUARTDSR modem interrupt status */
#define UART_RIS_RXRIS_Msk                                  0x00000010  /*!< Receive interrupt status */
#define UART_RIS_TXRIS_Msk                                  0x00000020  /*!< Transmit interrupt status */
#define UART_RIS_RTRIS_Msk                                  0x00000040  /*!< Receive timeout interrupt status */
#define UART_RIS_FERIS_Msk                                  0x00000080  /*!< Framing error interrupt status */
#define UART_RIS_PERIS_Msk                                  0x00000100  /*!< Parity error interrupt status */
#define UART_RIS_BERIS_Msk                                  0x00000200  /*!< Break error interrupt status */
#define UART_RIS_OERIS_Msk                                  0x00000400  /*!< Overrun error interrupt status */

/*-- MIS: Masked Interrupt Status Register -----------------------------------*/

typedef struct {
  uint32_t RIMMIS                                 :1;                   /*!< nUARTRI modem masked interrupt status */
  uint32_t CTSMMIS                                :1;                   /*!< nUARTCTS modem masked interrupt status */
  uint32_t DCDMMIS                                :1;                   /*!< nUARTDCD modem masked interrupt status */
  uint32_t DSRMMIS                                :1;                   /*!< nUARTDSR modem masked interrupt status */
  uint32_t RXMIS                                  :1;                   /*!< Receive masked interrupt status */
  uint32_t TXMIS                                  :1;                   /*!< Transmit masked interrupt status */
  uint32_t RTMIS                                  :1;                   /*!< Receive timeout masked interrupt status */
  uint32_t FEMIS                                  :1;                   /*!< Framing error masked interrupt status */
  uint32_t PEMIS                                  :1;                   /*!< Parity error masked interrupt status */
  uint32_t BEMIS                                  :1;                   /*!< Break error masked interrupt status */
  uint32_t OEMIS                                  :1;                   /*!< Overrun error masked interrupt status */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _UART_MIS_bits;

/* Bit field positions: */
#define UART_MIS_RIMMIS_Pos                                 0           /*!< nUARTRI modem masked interrupt status */
#define UART_MIS_CTSMMIS_Pos                                1           /*!< nUARTCTS modem masked interrupt status */
#define UART_MIS_DCDMMIS_Pos                                2           /*!< nUARTDCD modem masked interrupt status */
#define UART_MIS_DSRMMIS_Pos                                3           /*!< nUARTDSR modem masked interrupt status */
#define UART_MIS_RXMIS_Pos                                  4           /*!< Receive masked interrupt status */
#define UART_MIS_TXMIS_Pos                                  5           /*!< Transmit masked interrupt status */
#define UART_MIS_RTMIS_Pos                                  6           /*!< Receive timeout masked interrupt status */
#define UART_MIS_FEMIS_Pos                                  7           /*!< Framing error masked interrupt status */
#define UART_MIS_PEMIS_Pos                                  8           /*!< Parity error masked interrupt status */
#define UART_MIS_BEMIS_Pos                                  9           /*!< Break error masked interrupt status */
#define UART_MIS_OEMIS_Pos                                  10          /*!< Overrun error masked interrupt status */

/* Bit field masks: */
#define UART_MIS_RIMMIS_Msk                                 0x00000001  /*!< nUARTRI modem masked interrupt status */
#define UART_MIS_CTSMMIS_Msk                                0x00000002  /*!< nUARTCTS modem masked interrupt status */
#define UART_MIS_DCDMMIS_Msk                                0x00000004  /*!< nUARTDCD modem masked interrupt status */
#define UART_MIS_DSRMMIS_Msk                                0x00000008  /*!< nUARTDSR modem masked interrupt status */
#define UART_MIS_RXMIS_Msk                                  0x00000010  /*!< Receive masked interrupt status */
#define UART_MIS_TXMIS_Msk                                  0x00000020  /*!< Transmit masked interrupt status */
#define UART_MIS_RTMIS_Msk                                  0x00000040  /*!< Receive timeout masked interrupt status */
#define UART_MIS_FEMIS_Msk                                  0x00000080  /*!< Framing error masked interrupt status */
#define UART_MIS_PEMIS_Msk                                  0x00000100  /*!< Parity error masked interrupt status */
#define UART_MIS_BEMIS_Msk                                  0x00000200  /*!< Break error masked interrupt status */
#define UART_MIS_OEMIS_Msk                                  0x00000400  /*!< Overrun error masked interrupt status */

/*-- ICR: Interrupt Clear Register -------------------------------------------*/

typedef struct {
  uint32_t RIMIC                                  :1;                   /*!< nUARTRI modem interrupt clear */
  uint32_t CTSMIC                                 :1;                   /*!< nUARTCTS modem interrupt clear */
  uint32_t DCDMIC                                 :1;                   /*!< nUARTDCD modem interrupt clear */
  uint32_t DSRMIC                                 :1;                   /*!< nUARTDSR modem interrupt clear */
  uint32_t RXIC                                   :1;                   /*!< Receive interrupt clear */
  uint32_t TXIC                                   :1;                   /*!< Transmit interrupt clear */
  uint32_t RTIC                                   :1;                   /*!< Receive timeout interrupt clear */
  uint32_t FEIC                                   :1;                   /*!< Framing error interrupt clear */
  uint32_t PEIC                                   :1;                   /*!< Parity error interrupt clear */
  uint32_t BEIC                                   :1;                   /*!< Break error interrupt clear */
  uint32_t OEIC                                   :1;                   /*!< Overrun error interrupt clear */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _UART_ICR_bits;

/* Bit field positions: */
#define UART_ICR_RIMIC_Pos                                  0           /*!< nUARTRI modem interrupt clear */
#define UART_ICR_CTSMIC_Pos                                 1           /*!< nUARTCTS modem interrupt clear */
#define UART_ICR_DCDMIC_Pos                                 2           /*!< nUARTDCD modem interrupt clear */
#define UART_ICR_DSRMIC_Pos                                 3           /*!< nUARTDSR modem interrupt clear */
#define UART_ICR_RXIC_Pos                                   4           /*!< Receive interrupt clear */
#define UART_ICR_TXIC_Pos                                   5           /*!< Transmit interrupt clear */
#define UART_ICR_RTIC_Pos                                   6           /*!< Receive timeout interrupt clear */
#define UART_ICR_FEIC_Pos                                   7           /*!< Framing error interrupt clear */
#define UART_ICR_PEIC_Pos                                   8           /*!< Parity error interrupt clear */
#define UART_ICR_BEIC_Pos                                   9           /*!< Break error interrupt clear */
#define UART_ICR_OEIC_Pos                                   10          /*!< Overrun error interrupt clear */

/* Bit field masks: */
#define UART_ICR_RIMIC_Msk                                  0x00000001  /*!< nUARTRI modem interrupt clear */
#define UART_ICR_CTSMIC_Msk                                 0x00000002  /*!< nUARTCTS modem interrupt clear */
#define UART_ICR_DCDMIC_Msk                                 0x00000004  /*!< nUARTDCD modem interrupt clear */
#define UART_ICR_DSRMIC_Msk                                 0x00000008  /*!< nUARTDSR modem interrupt clear */
#define UART_ICR_RXIC_Msk                                   0x00000010  /*!< Receive interrupt clear */
#define UART_ICR_TXIC_Msk                                   0x00000020  /*!< Transmit interrupt clear */
#define UART_ICR_RTIC_Msk                                   0x00000040  /*!< Receive timeout interrupt clear */
#define UART_ICR_FEIC_Msk                                   0x00000080  /*!< Framing error interrupt clear */
#define UART_ICR_PEIC_Msk                                   0x00000100  /*!< Parity error interrupt clear */
#define UART_ICR_BEIC_Msk                                   0x00000200  /*!< Break error interrupt clear */
#define UART_ICR_OEIC_Msk                                   0x00000400  /*!< Overrun error interrupt clear */

/*-- DMACR: DMA Control Register ---------------------------------------------*/

typedef struct {
  uint32_t RXDMAE                                 :1;                   /*!< Receive DMA enable */
  uint32_t TXDMAE                                 :1;                   /*!< Transmit DMA enable */
  uint32_t DMAONERR                               :1;                   /*!< DMA on error */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _UART_DMACR_bits;

/* Bit field positions: */
#define UART_DMACR_RXDMAE_Pos                               0           /*!< Receive DMA enable */
#define UART_DMACR_TXDMAE_Pos                               1           /*!< Transmit DMA enable */
#define UART_DMACR_DMAONERR_Pos                             2           /*!< DMA on error */

/* Bit field masks: */
#define UART_DMACR_RXDMAE_Msk                               0x00000001  /*!< Receive DMA enable */
#define UART_DMACR_TXDMAE_Msk                               0x00000002  /*!< Transmit DMA enable */
#define UART_DMACR_DMAONERR_Msk                             0x00000004  /*!< DMA on error */

/*-- Register map for UART peripheral ----------------------------------------*/

typedef struct {
  union {                                                               /*!< Data Register */
    __IO uint32_t DR;                                                   /*!< DR    : type used for word access */
    __IO _UART_DR_bits DR_bit;                                          /*!< DR_bit: structure used for bit access */
  };
  union {                                                               /*!< Receive Status Register/Error Clear Register */
    __IO uint32_t RSR_ECR;                                              /*!< RSR_ECR    : type used for word access */
    __IO _UART_RSR_ECR_bits RSR_ECR_bit;                                /*!< RSR_ECR_bit: structure used for bit access */
  };
  uint32_t Reserved0[4];                                                /*!< Reserved */
  union {                                                               /*!< Flag Register */
    __I  uint32_t FR;                                                   /*!< FR    : type used for word access */
    __I  _UART_FR_bits FR_bit;                                          /*!< FR_bit: structure used for bit access */
  };
  uint32_t Reserved1[2];                                                /*!< Reserved */
  union {                                                               /*!< Integer Baud Rate Register */
    __IO uint32_t IBRD;                                                 /*!< IBRD    : type used for word access */
    __IO _UART_IBRD_bits IBRD_bit;                                      /*!< IBRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Fractional Baud Rate Register */
    __IO uint32_t FBRD;                                                 /*!< FBRD    : type used for word access */
    __IO _UART_FBRD_bits FBRD_bit;                                      /*!< FBRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Line Control Register */
    __IO uint32_t LCR_H;                                                /*!< LCR_H    : type used for word access */
    __IO _UART_LCR_H_bits LCR_H_bit;                                    /*!< LCR_H_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register */
    __IO uint32_t CR;                                                   /*!< CR    : type used for word access */
    __IO _UART_CR_bits CR_bit;                                          /*!< CR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt FIFO Level Select Register */
    __IO uint32_t IFLS;                                                 /*!< IFLS    : type used for word access */
    __IO _UART_IFLS_bits IFLS_bit;                                      /*!< IFLS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Mask Set/Clear Register */
    __IO uint32_t IMSC;                                                 /*!< IMSC    : type used for word access */
    __IO _UART_IMSC_bits IMSC_bit;                                      /*!< IMSC_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw Interrupt Status Register */
    __I  uint32_t RIS;                                                  /*!< RIS    : type used for word access */
    __I  _UART_RIS_bits RIS_bit;                                        /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Masked Interrupt Status Register */
    __I  uint32_t MIS;                                                  /*!< MIS    : type used for word access */
    __I  _UART_MIS_bits MIS_bit;                                        /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Clear Register */
    __O  uint32_t ICR;                                                  /*!< ICR    : type used for word access */
    __O  _UART_ICR_bits ICR_bit;                                        /*!< ICR_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Control Register */
    __IO uint32_t DMACR;                                                /*!< DMACR    : type used for word access */
    __IO _UART_DMACR_bits DMACR_bit;                                    /*!< DMACR_bit: structure used for bit access */
  };
} NT_UART_TypeDef;

/******************************************************************************/
/*                         PWM controller registers                           */
/******************************************************************************/

/*-- TBCTL: Timer Control Register -------------------------------------------*/

typedef struct {
  uint32_t CTRMODE                                :2;                   /*!< Counter operation */
  uint32_t PHSEN                                  :1;                   /*!< load timer counter */
  uint32_t PRDLD                                  :1;                   /*!< lazy loading mode register */
  uint32_t SYNCOSEL                               :2;                   /*!< source for output clock signal */
  uint32_t SWFSYNC                                :1;                   /*!< Software emulation clock */
  uint32_t HSPCLKDIV                              :3;                   /*!< Dividing value of systemclock */
  uint32_t CLKDIV                                 :3;                   /*!< Dividing systemclock */
  uint32_t PHSDIR                                 :1;                   /*!< The phase direction */
  uint32_t FREE_SOFT                              :2;                   /*!< Mode emulation software */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _PWM_TBCTL_bits;

/* Bit field positions: */
#define PWM_TBCTL_CTRMODE_Pos                               0           /*!< Counter operation */
#define PWM_TBCTL_PHSEN_Pos                                 2           /*!< load timer counter */
#define PWM_TBCTL_PRDLD_Pos                                 3           /*!< lazy loading mode register */
#define PWM_TBCTL_SYNCOSEL_Pos                              4           /*!< source for output clock signal */
#define PWM_TBCTL_SWFSYNC_Pos                               6           /*!< Software emulation clock */
#define PWM_TBCTL_HSPCLKDIV_Pos                             7           /*!< Dividing value of systemclock */
#define PWM_TBCTL_CLKDIV_Pos                                10          /*!< Dividing systemclock */
#define PWM_TBCTL_PHSDIR_Pos                                13          /*!< The phase direction */
#define PWM_TBCTL_FREE_SOFT_Pos                             14          /*!< Mode emulation software */

/* Bit field masks: */
#define PWM_TBCTL_CTRMODE_Msk                               0x00000003  /*!< Counter operation */
#define PWM_TBCTL_PHSEN_Msk                                 0x00000004  /*!< load timer counter */
#define PWM_TBCTL_PRDLD_Msk                                 0x00000008  /*!< lazy loading mode register */
#define PWM_TBCTL_SYNCOSEL_Msk                              0x00000030  /*!< source for output clock signal */
#define PWM_TBCTL_SWFSYNC_Msk                               0x00000040  /*!< Software emulation clock */
#define PWM_TBCTL_HSPCLKDIV_Msk                             0x00000380  /*!< Dividing value of systemclock */
#define PWM_TBCTL_CLKDIV_Msk                                0x00001C00  /*!< Dividing systemclock */
#define PWM_TBCTL_PHSDIR_Msk                                0x00002000  /*!< The phase direction */
#define PWM_TBCTL_FREE_SOFT_Msk                             0x0000C000  /*!< Mode emulation software */

/*-- TBSTS: Timer status register --------------------------------------------*/

typedef struct {
  uint32_t CTRDIR                                 :1;                   /*!< Current timer counting direction */
  uint32_t SYNCI                                  :1;                   /*!< Synchronization status */
  uint32_t CTRMAX                                 :1;                   /*!< Position of the peak value */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _PWM_TBSTS_bits;

/* Bit field positions: */
#define PWM_TBSTS_CTRDIR_Pos                                0           /*!< Current timer counting direction */
#define PWM_TBSTS_SYNCI_Pos                                 1           /*!< Synchronization status */
#define PWM_TBSTS_CTRMAX_Pos                                2           /*!< Position of the peak value */

/* Bit field masks: */
#define PWM_TBSTS_CTRDIR_Msk                                0x00000001  /*!< Current timer counting direction */
#define PWM_TBSTS_SYNCI_Msk                                 0x00000002  /*!< Synchronization status */
#define PWM_TBSTS_CTRMAX_Msk                                0x00000004  /*!< Position of the peak value */

/*-- TBPHS: register Phases --------------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t TBPHSHR                                :8;
  uint32_t TBPHS                                  :16;                  /*!< initial phase of the Timer */
} _PWM_TBPHS_bits;

/* Bit field positions: */
#define PWM_TBPHS_TBPHSHR_Pos                               8
#define PWM_TBPHS_TBPHS_Pos                                 16          /*!< initial phase of the Timer */

/* Bit field masks: */
#define PWM_TBPHS_TBPHSHR_Msk                               0x0000FF00
#define PWM_TBPHS_TBPHS_Msk                                 0xFFFF0000  /*!< initial phase of the Timer */

/*-- TBCTR: Register current value of timer ----------------------------------*/

typedef struct {
  uint32_t TBCTR                                  :16;                  /*!< the current value of the timer */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _PWM_TBCTR_bits;

/* Bit field positions: */
#define PWM_TBCTR_TBCTR_Pos                                 0           /*!< the current value of the timer */

/* Bit field masks: */
#define PWM_TBCTR_TBCTR_Msk                                 0x0000FFFF  /*!< the current value of the timer */

/*-- TBPRD: Register maximum Timer -------------------------------------------*/

typedef struct {
  uint32_t TBPRD                                  :16;                  /*!< the maximum count value of Timer */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _PWM_TBPRD_bits;

/* Bit field positions: */
#define PWM_TBPRD_TBPRD_Pos                                 0           /*!< the maximum count value of Timer */

/* Bit field masks: */
#define PWM_TBPRD_TBPRD_Msk                                 0x0000FFFF  /*!< the maximum count value of Timer */

/*-- CMPCTL ------------------------------------------------------------------*/

typedef struct {
  uint32_t LOADAMODE                              :2;                   /*!< load event of deferred values CMPA */
  uint32_t LOADBMODE                              :2;                   /*!< load event of deferred values CMPB */
  uint32_t SHDWAMODE                              :1;                   /*!< Write-permit mode */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SHDWBMODE                              :1;                   /*!< Write-permit mode */
  uint32_t Reserved1                              :1;                   /*!< Reserved */
  uint32_t SHDWAFULL                              :1;                   /*!< Status lazy loading in CMPA */
  uint32_t SHDWBFULL                              :1;                   /*!< Status lazy loading in CMPB */
  uint32_t Reserved2                              :22;                  /*!< Reserved */
} _PWM_CMPCTL_bits;

/* Bit field positions: */
#define PWM_CMPCTL_LOADAMODE_Pos                            0           /*!< load event of deferred values CMPA */
#define PWM_CMPCTL_LOADBMODE_Pos                            2           /*!< load event of deferred values CMPB */
#define PWM_CMPCTL_SHDWAMODE_Pos                            4           /*!< Write-permit mode */
#define PWM_CMPCTL_SHDWBMODE_Pos                            6           /*!< Write-permit mode */
#define PWM_CMPCTL_SHDWAFULL_Pos                            8           /*!< Status lazy loading in CMPA */
#define PWM_CMPCTL_SHDWBFULL_Pos                            9           /*!< Status lazy loading in CMPB */

/* Bit field masks: */
#define PWM_CMPCTL_LOADAMODE_Msk                            0x00000003  /*!< load event of deferred values CMPA */
#define PWM_CMPCTL_LOADBMODE_Msk                            0x0000000C  /*!< load event of deferred values CMPB */
#define PWM_CMPCTL_SHDWAMODE_Msk                            0x00000010  /*!< Write-permit mode */
#define PWM_CMPCTL_SHDWBMODE_Msk                            0x00000040  /*!< Write-permit mode */
#define PWM_CMPCTL_SHDWAFULL_Msk                            0x00000100  /*!< Status lazy loading in CMPA */
#define PWM_CMPCTL_SHDWBFULL_Msk                            0x00000200  /*!< Status lazy loading in CMPB */

/*-- CMPA: Register threshold A ----------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :8;                   /*!< Reserved */
  uint32_t CMPAHR                                 :8;                   /*!< A threshold register */
  uint32_t CMPA                                   :16;                  /*!< active value threshold A */
} _PWM_CMPA_bits;

/* Bit field positions: */
#define PWM_CMPA_CMPAHR_Pos                                 8           /*!< A threshold register */
#define PWM_CMPA_CMPA_Pos                                   16          /*!< active value threshold A */

/* Bit field masks: */
#define PWM_CMPA_CMPAHR_Msk                                 0x0000FF00  /*!< A threshold register */
#define PWM_CMPA_CMPA_Msk                                   0xFFFF0000  /*!< active value threshold A */

/*-- CMPB: Register threshold B ----------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :16;                  /*!< Reserved */
  uint32_t CMPB                                   :16;                  /*!< active value threshold B */
} _PWM_CMPB_bits;

/* Bit field positions: */
#define PWM_CMPB_CMPB_Pos                                   16          /*!< active value threshold B */

/* Bit field masks: */
#define PWM_CMPB_CMPB_Msk                                   0xFFFF0000  /*!< active value threshold B */

/*-- AQCTLA: Register handlers for output A ----------------------------------*/

typedef struct {
  uint32_t ZRO                                    :2;                   /*!< effect on the output signal event CTR = 0 */
  uint32_t PRD                                    :2;                   /*!< effect on the output signal event CTR = PRD */
  uint32_t CAU                                    :2;                   /*!< effect on the output signal event CTR = CMPA,count up */
  uint32_t CAD                                    :2;                   /*!< effect on the output signal event CTR = CMPA,count down */
  uint32_t CBU                                    :2;                   /*!< effect on the output signal event CTR = CMPB,count up */
  uint32_t CBD                                    :2;                   /*!< effect on the output signal event CTR = CMPB,count down */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _PWM_AQCTLA_bits;

/* Bit field positions: */
#define PWM_AQCTLA_ZRO_Pos                                  0           /*!< effect on the output signal event CTR = 0 */
#define PWM_AQCTLA_PRD_Pos                                  2           /*!< effect on the output signal event CTR = PRD */
#define PWM_AQCTLA_CAU_Pos                                  4           /*!< effect on the output signal event CTR = CMPA,count up */
#define PWM_AQCTLA_CAD_Pos                                  6           /*!< effect on the output signal event CTR = CMPA,count down */
#define PWM_AQCTLA_CBU_Pos                                  8           /*!< effect on the output signal event CTR = CMPB,count up */
#define PWM_AQCTLA_CBD_Pos                                  10          /*!< effect on the output signal event CTR = CMPB,count down */

/* Bit field masks: */
#define PWM_AQCTLA_ZRO_Msk                                  0x00000003  /*!< effect on the output signal event CTR = 0 */
#define PWM_AQCTLA_PRD_Msk                                  0x0000000C  /*!< effect on the output signal event CTR = PRD */
#define PWM_AQCTLA_CAU_Msk                                  0x00000030  /*!< effect on the output signal event CTR = CMPA,count up */
#define PWM_AQCTLA_CAD_Msk                                  0x000000C0  /*!< effect on the output signal event CTR = CMPA,count down */
#define PWM_AQCTLA_CBU_Msk                                  0x00000300  /*!< effect on the output signal event CTR = CMPB,count up */
#define PWM_AQCTLA_CBD_Msk                                  0x00000C00  /*!< effect on the output signal event CTR = CMPB,count down */

/*-- AQCTLB: Register handlers for output B ----------------------------------*/

typedef struct {
  uint32_t ZRO                                    :2;                   /*!< effect on the output signal event CTR = 0 */
  uint32_t PRD                                    :2;                   /*!< effect on the output signal event CTR = PRD */
  uint32_t CAU                                    :2;                   /*!< effect on the output signal event CTR = CMPA,count up */
  uint32_t CAD                                    :2;                   /*!< effect on the output signal event CTR = CMPA,count down */
  uint32_t CBU                                    :2;                   /*!< effect on the output signal event CTR = CMPB,count up */
  uint32_t CBD                                    :2;                   /*!< effect on the output signal event CTR = CMPB,count down */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _PWM_AQCTLB_bits;

/* Bit field positions: */
#define PWM_AQCTLB_ZRO_Pos                                  0           /*!< effect on the output signal event CTR = 0 */
#define PWM_AQCTLB_PRD_Pos                                  2           /*!< effect on the output signal event CTR = PRD */
#define PWM_AQCTLB_CAU_Pos                                  4           /*!< effect on the output signal event CTR = CMPA,count up */
#define PWM_AQCTLB_CAD_Pos                                  6           /*!< effect on the output signal event CTR = CMPA,count down */
#define PWM_AQCTLB_CBU_Pos                                  8           /*!< effect on the output signal event CTR = CMPB,count up */
#define PWM_AQCTLB_CBD_Pos                                  10          /*!< effect on the output signal event CTR = CMPB,count down */

/* Bit field masks: */
#define PWM_AQCTLB_ZRO_Msk                                  0x00000003  /*!< effect on the output signal event CTR = 0 */
#define PWM_AQCTLB_PRD_Msk                                  0x0000000C  /*!< effect on the output signal event CTR = PRD */
#define PWM_AQCTLB_CAU_Msk                                  0x00000030  /*!< effect on the output signal event CTR = CMPA,count up */
#define PWM_AQCTLB_CAD_Msk                                  0x000000C0  /*!< effect on the output signal event CTR = CMPA,count down */
#define PWM_AQCTLB_CBU_Msk                                  0x00000300  /*!< effect on the output signal event CTR = CMPB,count up */
#define PWM_AQCTLB_CBD_Msk                                  0x00000C00  /*!< effect on the output signal event CTR = CMPB,count down */

/*-- AQSFRC: Register handlers for a single program management ---------------*/

typedef struct {
  uint32_t ACTSFA                                 :2;                   /*!< Defines an action with the output at pin */
  uint32_t OTSFA                                  :1;                   /*!< Initialization single pulse */
  uint32_t ACTSFB                                 :2;                   /*!< Defines an action with the output at pin */
  uint32_t OTSFB                                  :1;                   /*!< Initialization single pulse */
  uint32_t RLDCSF                                 :2;                   /*!< Defines an action with the output at pin */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _PWM_AQSFRC_bits;

/* Bit field positions: */
#define PWM_AQSFRC_ACTSFA_Pos                               0           /*!< Defines an action with the output at pin */
#define PWM_AQSFRC_OTSFA_Pos                                2           /*!< Initialization single pulse */
#define PWM_AQSFRC_ACTSFB_Pos                               3           /*!< Defines an action with the output at pin */
#define PWM_AQSFRC_OTSFB_Pos                                5           /*!< Initialization single pulse */
#define PWM_AQSFRC_RLDCSF_Pos                               6           /*!< Defines an action with the output at pin */

/* Bit field masks: */
#define PWM_AQSFRC_ACTSFA_Msk                               0x00000003  /*!< Defines an action with the output at pin */
#define PWM_AQSFRC_OTSFA_Msk                                0x00000004  /*!< Initialization single pulse */
#define PWM_AQSFRC_ACTSFB_Msk                               0x00000018  /*!< Defines an action with the output at pin */
#define PWM_AQSFRC_OTSFB_Msk                                0x00000020  /*!< Initialization single pulse */
#define PWM_AQSFRC_RLDCSF_Msk                               0x000000C0  /*!< Defines an action with the output at pin */

/*-- AQCSFRC: Register handlers for the cyclic program Management ------------*/

typedef struct {
  uint32_t CSFA                                   :2;                   /*!< cyclical impact on output A */
  uint32_t CSFB                                   :2;                   /*!< cyclical impact on output B */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _PWM_AQCSFRC_bits;

/* Bit field positions: */
#define PWM_AQCSFRC_CSFA_Pos                                0           /*!< cyclical impact on output A */
#define PWM_AQCSFRC_CSFB_Pos                                2           /*!< cyclical impact on output B */

/* Bit field masks: */
#define PWM_AQCSFRC_CSFA_Msk                                0x00000003  /*!< cyclical impact on output A */
#define PWM_AQCSFRC_CSFB_Msk                                0x0000000C  /*!< cyclical impact on output B */

/*-- DBCTL: Generator Control Register PWM Dead Time -------------------------*/

typedef struct {
  uint32_t OUT_MODE                               :2;
  uint32_t POLSEL                                 :2;
  uint32_t IN_MODE                                :2;
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _PWM_DBCTL_bits;

/* Bit field positions: */
#define PWM_DBCTL_OUT_MODE_Pos                              0
#define PWM_DBCTL_POLSEL_Pos                                2
#define PWM_DBCTL_IN_MODE_Pos                               4

/* Bit field masks: */
#define PWM_DBCTL_OUT_MODE_Msk                              0x00000003
#define PWM_DBCTL_POLSEL_Msk                                0x0000000C
#define PWM_DBCTL_IN_MODE_Msk                               0x00000030

/*-- DBRED: Dead time control register ---------------------------------------*/

typedef struct {
  uint32_t DEL                                    :10;                  /*!< delay on the front */
  uint32_t Reserved0                              :22;                  /*!< Reserved */
} _PWM_DBRED_bits;

/* Bit field positions: */
#define PWM_DBRED_DEL_Pos                                   0           /*!< delay on the front */

/* Bit field masks: */
#define PWM_DBRED_DEL_Msk                                   0x000003FF  /*!< delay on the front */

/*-- DBFED: Dead time control register ---------------------------------------*/

typedef struct {
  uint32_t DEL                                    :10;                  /*!< delay on the falling edge */
  uint32_t Reserved0                              :22;                  /*!< Reserved */
} _PWM_DBFED_bits;

/* Bit field positions: */
#define PWM_DBFED_DEL_Pos                                   0           /*!< delay on the falling edge */

/* Bit field masks: */
#define PWM_DBFED_DEL_Msk                                   0x000003FF  /*!< delay on the falling edge */

/*-- TZSEL: Register the source of the accident ------------------------------*/

typedef struct {
  uint32_t CBC0                                   :1;
  uint32_t CBC1                                   :1;
  uint32_t CBC2                                   :1;
  uint32_t CBC3                                   :1;
  uint32_t CBC4                                   :1;
  uint32_t CBC5                                   :1;                   /*!< source signal with the output of the accident Tzx(cyclic mode) */
  uint32_t Reserved0                              :2;                   /*!< Reserved */
  uint32_t OSHT0                                  :1;
  uint32_t OSHT1                                  :1;
  uint32_t OSHT2                                  :1;
  uint32_t OSHT3                                  :1;
  uint32_t OSHT4                                  :1;
  uint32_t OSHT5                                  :1;                   /*!< source signal with the output of the accident Tzx(Single mode) */
  uint32_t Reserved1                              :18;                  /*!< Reserved */
} _PWM_TZSEL_bits;

/* Bit field positions: */
#define PWM_TZSEL_CBC0_Pos                                  0
#define PWM_TZSEL_CBC1_Pos                                  1
#define PWM_TZSEL_CBC2_Pos                                  2
#define PWM_TZSEL_CBC3_Pos                                  3
#define PWM_TZSEL_CBC4_Pos                                  4
#define PWM_TZSEL_CBC5_Pos                                  5           /*!< source signal with the output of the accident Tzx(cyclic mode) */
#define PWM_TZSEL_OSHT0_Pos                                 8
#define PWM_TZSEL_OSHT1_Pos                                 9
#define PWM_TZSEL_OSHT2_Pos                                 10
#define PWM_TZSEL_OSHT3_Pos                                 11
#define PWM_TZSEL_OSHT4_Pos                                 12
#define PWM_TZSEL_OSHT5_Pos                                 13          /*!< source signal with the output of the accident Tzx(Single mode) */

/* Bit field masks: */
#define PWM_TZSEL_CBC0_Msk                                  0x00000001
#define PWM_TZSEL_CBC1_Msk                                  0x00000002
#define PWM_TZSEL_CBC2_Msk                                  0x00000004
#define PWM_TZSEL_CBC3_Msk                                  0x00000008
#define PWM_TZSEL_CBC4_Msk                                  0x00000010
#define PWM_TZSEL_CBC5_Msk                                  0x00000020  /*!< source signal with the output of the accident Tzx(cyclic mode) */
#define PWM_TZSEL_OSHT0_Msk                                 0x00000100
#define PWM_TZSEL_OSHT1_Msk                                 0x00000200
#define PWM_TZSEL_OSHT2_Msk                                 0x00000400
#define PWM_TZSEL_OSHT3_Msk                                 0x00000800
#define PWM_TZSEL_OSHT4_Msk                                 0x00001000
#define PWM_TZSEL_OSHT5_Msk                                 0x00002000  /*!< source signal with the output of the accident Tzx(Single mode) */

/*-- TZCTL: Control Register detector alarm signal ---------------------------*/

typedef struct {
  uint32_t TZA                                    :2;                   /*!< behavior output A */
  uint32_t TZB                                    :2;                   /*!< behavior output B */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _PWM_TZCTL_bits;

/* Bit field positions: */
#define PWM_TZCTL_TZA_Pos                                   0           /*!< behavior output A */
#define PWM_TZCTL_TZB_Pos                                   2           /*!< behavior output B */

/* Bit field masks: */
#define PWM_TZCTL_TZA_Msk                                   0x00000003  /*!< behavior output A */
#define PWM_TZCTL_TZB_Msk                                   0x0000000C  /*!< behavior output B */

/*-- TZEINT: Interrupt mask register Signal Detection Alarms -----------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CBC                                    :1;                   /*!< Interrupt generation(cyclic mode) */
  uint32_t OST                                    :1;                   /*!< Interrupt generation(single mode) */
  uint32_t Reserved1                              :29;                  /*!< Reserved */
} _PWM_TZEINT_bits;

/* Bit field positions: */
#define PWM_TZEINT_CBC_Pos                                  1           /*!< Interrupt generation(cyclic mode) */
#define PWM_TZEINT_OST_Pos                                  2           /*!< Interrupt generation(single mode) */

/* Bit field masks: */
#define PWM_TZEINT_CBC_Msk                                  0x00000002  /*!< Interrupt generation(cyclic mode) */
#define PWM_TZEINT_OST_Msk                                  0x00000004  /*!< Interrupt generation(single mode) */

/*-- TZFLG: Flags register interrupt signal detector Accidents ---------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< Status of external interrupts NVIC */
  uint32_t CBC                                    :1;                   /*!< Interrupt status in a cyclic mode */
  uint32_t OST                                    :1;                   /*!< Interrupt status in one-shot mode */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _PWM_TZFLG_bits;

/* Bit field positions: */
#define PWM_TZFLG_INT_Pos                                   0           /*!< Status of external interrupts NVIC */
#define PWM_TZFLG_CBC_Pos                                   1           /*!< Interrupt status in a cyclic mode */
#define PWM_TZFLG_OST_Pos                                   2           /*!< Interrupt status in one-shot mode */

/* Bit field masks: */
#define PWM_TZFLG_INT_Msk                                   0x00000001  /*!< Status of external interrupts NVIC */
#define PWM_TZFLG_CBC_Msk                                   0x00000002  /*!< Interrupt status in a cyclic mode */
#define PWM_TZFLG_OST_Msk                                   0x00000004  /*!< Interrupt status in one-shot mode */

/*-- TZCLR: Register reset interrupt flag detector alarm signal --------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< Reset status of external interrupts NVIC */
  uint32_t CBC                                    :1;                   /*!< Reset Interrupt status in a cyclic mode */
  uint32_t OST                                    :1;                   /*!< Reset Interrupt status in one-shot mode */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _PWM_TZCLR_bits;

/* Bit field positions: */
#define PWM_TZCLR_INT_Pos                                   0           /*!< Reset status of external interrupts NVIC */
#define PWM_TZCLR_CBC_Pos                                   1           /*!< Reset Interrupt status in a cyclic mode */
#define PWM_TZCLR_OST_Pos                                   2           /*!< Reset Interrupt status in one-shot mode */

/* Bit field masks: */
#define PWM_TZCLR_INT_Msk                                   0x00000001  /*!< Reset status of external interrupts NVIC */
#define PWM_TZCLR_CBC_Msk                                   0x00000002  /*!< Reset Interrupt status in a cyclic mode */
#define PWM_TZCLR_OST_Msk                                   0x00000004  /*!< Reset Interrupt status in one-shot mode */

/*-- TZFRC: Register software emulation of faults ----------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CBC                                    :1;                   /*!< Signal generation(cyclic mode) */
  uint32_t OST                                    :1;                   /*!< Signal generation(single mode) */
  uint32_t Reserved1                              :29;                  /*!< Reserved */
} _PWM_TZFRC_bits;

/* Bit field positions: */
#define PWM_TZFRC_CBC_Pos                                   1           /*!< Signal generation(cyclic mode) */
#define PWM_TZFRC_OST_Pos                                   2           /*!< Signal generation(single mode) */

/* Bit field masks: */
#define PWM_TZFRC_CBC_Msk                                   0x00000002  /*!< Signal generation(cyclic mode) */
#define PWM_TZFRC_OST_Msk                                   0x00000004  /*!< Signal generation(single mode) */

/*-- ETSEL: A Source event trigger -------------------------------------------*/

typedef struct {
  uint32_t INTSEL                                 :3;                   /*!< external interrupt event */
  uint32_t INTEN                                  :1;                   /*!< Generation of external interrupt EPWMxINT */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t SOCASEL                                :3;                   /*!< Event impulse EPWMxSOCA */
  uint32_t SOCAEN                                 :1;                   /*!< generation of an external signal (EPWMxSOCA) */
  uint32_t SOCBSEL                                :3;                   /*!< Event impulse EPWMxSOCB */
  uint32_t SOCBEN                                 :1;                   /*!< generation of an external signal (EPWMxSOCB) */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _PWM_ETSEL_bits;

/* Bit field positions: */
#define PWM_ETSEL_INTSEL_Pos                                0           /*!< external interrupt event */
#define PWM_ETSEL_INTEN_Pos                                 3           /*!< Generation of external interrupt EPWMxINT */
#define PWM_ETSEL_SOCASEL_Pos                               8           /*!< Event impulse EPWMxSOCA */
#define PWM_ETSEL_SOCAEN_Pos                                11          /*!< generation of an external signal (EPWMxSOCA) */
#define PWM_ETSEL_SOCBSEL_Pos                               12          /*!< Event impulse EPWMxSOCB */
#define PWM_ETSEL_SOCBEN_Pos                                15          /*!< generation of an external signal (EPWMxSOCB) */

/* Bit field masks: */
#define PWM_ETSEL_INTSEL_Msk                                0x00000007  /*!< external interrupt event */
#define PWM_ETSEL_INTEN_Msk                                 0x00000008  /*!< Generation of external interrupt EPWMxINT */
#define PWM_ETSEL_SOCASEL_Msk                               0x00000700  /*!< Event impulse EPWMxSOCA */
#define PWM_ETSEL_SOCAEN_Msk                                0x00000800  /*!< generation of an external signal (EPWMxSOCA) */
#define PWM_ETSEL_SOCBSEL_Msk                               0x00007000  /*!< Event impulse EPWMxSOCB */
#define PWM_ETSEL_SOCBEN_Msk                                0x00008000  /*!< generation of an external signal (EPWMxSOCB) */

/*-- ETPS: Prescaler register the event trigger ------------------------------*/

typedef struct {
  uint32_t INTPRD                                 :2;                   /*!< number of events specified in a register ETSEL[INTSEL] */
  uint32_t INTCNT                                 :2;                   /*!< value of event counter interrupt */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t SOCAPRD                                :2;                   /*!< number of events specified in a register ETSEL[SOCASEL] */
  uint32_t SOCACNT                                :2;                   /*!< count of events forming EPWMxSOCA */
  uint32_t SOCBPRD                                :2;                   /*!< Number of events specified in ETSEL [SOCBSEL] */
  uint32_t SOCBCNT                                :2;                   /*!< count of events forming EPWMxSOCB */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _PWM_ETPS_bits;

/* Bit field positions: */
#define PWM_ETPS_INTPRD_Pos                                 0           /*!< number of events specified in a register ETSEL[INTSEL] */
#define PWM_ETPS_INTCNT_Pos                                 2           /*!< value of event counter interrupt */
#define PWM_ETPS_SOCAPRD_Pos                                8           /*!< number of events specified in a register ETSEL[SOCASEL] */
#define PWM_ETPS_SOCACNT_Pos                                10          /*!< count of events forming EPWMxSOCA */
#define PWM_ETPS_SOCPRD_Pos                                 12          /*!< Number of events specified in ETSEL [SOCBSEL] */
#define PWM_ETPS_SOCBCNT_Pos                                14          /*!< count of events forming EPWMxSOCB */

/* Bit field masks: */
#define PWM_ETPS_INTPRD_Msk                                 0x00000003  /*!< number of events specified in a register ETSEL[INTSEL] */
#define PWM_ETPS_INTCNT_Msk                                 0x0000000C  /*!< value of event counter interrupt */
#define PWM_ETPS_SOCAPRD_Msk                                0x00000300  /*!< number of events specified in a register ETSEL[SOCASEL] */
#define PWM_ETPS_SOCACNT_Msk                                0x00000C00  /*!< count of events forming EPWMxSOCA */
#define PWM_ETPS_SOCPRD_Msk                                 0x00003000  /*!< Number of events specified in ETSEL [SOCBSEL] */
#define PWM_ETPS_SOCBCNT_Msk                                0x0000C000  /*!< count of events forming EPWMxSOCB */

/*-- ETFLG: Register Flags event trigger -------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< Status of the external interrupt EPWMxINT */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SOCA                                   :1;                   /*!< Status of the external ADC EPWMxSOCA */
  uint32_t SOCB                                   :1;                   /*!< Status of the external ADC EPWMxSOCB */
  uint32_t Reserved1                              :28;                  /*!< Reserved */
} _PWM_ETFLG_bits;

/* Bit field positions: */
#define PWM_ETFLG_INT_Pos                                   0           /*!< Status of the external interrupt EPWMxINT */
#define PWM_ETFLG_SOCA_Pos                                  2           /*!< Status of the external ADC EPWMxSOCA */
#define PWM_ETFLG_SOCB_Pos                                  3           /*!< Status of the external ADC EPWMxSOCB */

/* Bit field masks: */
#define PWM_ETFLG_INT_Msk                                   0x00000001  /*!< Status of the external interrupt EPWMxINT */
#define PWM_ETFLG_SOCA_Msk                                  0x00000004  /*!< Status of the external ADC EPWMxSOCA */
#define PWM_ETFLG_SOCB_Msk                                  0x00000008  /*!< Status of the external ADC EPWMxSOCB */

/*-- ETCLR: Register reset flags trigger events ------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< reset the status of the external interrupt EPWMxINT */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SOCA                                   :1;                   /*!< reset the status of the external ADC EPWMxSOCA */
  uint32_t SOCB                                   :1;                   /*!< reset the status of the external ADC EPWMxSOCB */
  uint32_t Reserved1                              :28;                  /*!< Reserved */
} _PWM_ETCLR_bits;

/* Bit field positions: */
#define PWM_ETCLR_INT_Pos                                   0           /*!< reset the status of the external interrupt EPWMxINT */
#define PWM_ETCLR_SOCA_Pos                                  2           /*!< reset the status of the external ADC EPWMxSOCA */
#define PWM_ETCLR_SOCB_Pos                                  3           /*!< reset the status of the external ADC EPWMxSOCB */

/* Bit field masks: */
#define PWM_ETCLR_INT_Msk                                   0x00000001  /*!< reset the status of the external interrupt EPWMxINT */
#define PWM_ETCLR_SOCA_Msk                                  0x00000004  /*!< reset the status of the external ADC EPWMxSOCA */
#define PWM_ETCLR_SOCB_Msk                                  0x00000008  /*!< reset the status of the external ADC EPWMxSOCB */

/*-- ETFRC: Register software emulation events -------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< activation of an external interrupt EPWMxINT */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SOCA                                   :1;                   /*!< activation of the external ADC EPWMxSOCA */
  uint32_t SOCB                                   :1;                   /*!< activation of the external ADC EPWMxSOCB */
  uint32_t Reserved1                              :28;                  /*!< Reserved */
} _PWM_ETFRC_bits;

/* Bit field positions: */
#define PWM_ETFRC_INT_Pos                                   0           /*!< activation of an external interrupt EPWMxINT */
#define PWM_ETFRC_SOCA_Pos                                  2           /*!< activation of the external ADC EPWMxSOCA */
#define PWM_ETFRC_SOCB_Pos                                  3           /*!< activation of the external ADC EPWMxSOCB */

/* Bit field masks: */
#define PWM_ETFRC_INT_Msk                                   0x00000001  /*!< activation of an external interrupt EPWMxINT */
#define PWM_ETFRC_SOCA_Msk                                  0x00000004  /*!< activation of the external ADC EPWMxSOCA */
#define PWM_ETFRC_SOCB_Msk                                  0x00000008  /*!< activation of the external ADC EPWMxSOCB */

/*-- PCCTL: Control Register modulator ---------------------------------------*/

typedef struct {
  uint32_t CHPEN                                  :1;                   /*!< enables the Modulator */
  uint32_t OSHTWTH                                :4;                   /*!< a first pulse width */
  uint32_t SHRFREQ                                :3;                   /*!< frequency of the second and subsequent pulses */
  uint32_t CHPDUTY                                :3;                   /*!< duty cycle of the second and subsequent pulses */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _PWM_PCCTL_bits;

/* Bit field positions: */
#define PWM_PCCTL_CHPEN_Pos                                 0           /*!< enables the Modulator */
#define PWM_PCCTL_OSHTWTH_Pos                               1           /*!< a first pulse width */
#define PWM_PCCTL_SHRFREQ_Pos                               5           /*!< frequency of the second and subsequent pulses */
#define PWM_PCCTL_CHPDUTY_Pos                               8           /*!< duty cycle of the second and subsequent pulses */

/* Bit field masks: */
#define PWM_PCCTL_CHPEN_Msk                                 0x00000001  /*!< enables the Modulator */
#define PWM_PCCTL_OSHTWTH_Msk                               0x0000001E  /*!< a first pulse width */
#define PWM_PCCTL_SHRFREQ_Msk                               0x000000E0  /*!< frequency of the second and subsequent pulses */
#define PWM_PCCTL_CHPDUTY_Msk                               0x00000700  /*!< duty cycle of the second and subsequent pulses */

/*-- HRCNFG: Register Configuration Block PWM High Definition ----------------*/

typedef struct {
  uint32_t EDGMODE                                :2;                   /*!< value of rise and fall, turning control of the delay line */
  uint32_t CTLMODE                                :1;                   /*!< register specifies the delay */
  uint32_t HR_LOAD                                :1;                   /*!< load event of deferred value to the active register */
  uint32_t Reserved0                              :12;                  /*!< Reserved */
  uint32_t MEP_SCALEFACTOR                        :8;                   /*!< result of the correction circuit of the delay line */
  uint32_t Reserved1                              :8;                   /*!< Reserved */
} _PWM_HRCNFG_bits;

/* Bit field positions: */
#define PWM_HRCNFG_EDGMODE_Pos                              0           /*!< value of rise and fall, turning control of the delay line */
#define PWM_HRCNFG_CTLMODE_Pos                              2           /*!< register specifies the delay */
#define PWM_HRCNFG_HR_LOAD_Pos                              3           /*!< load event of deferred value to the active register */
#define PWM_HRCNFG_MEP_SCALEFACTOR_Pos                      16          /*!< result of the correction circuit of the delay line */

/* Bit field masks: */
#define PWM_HRCNFG_EDGMODE_Msk                              0x00000003  /*!< value of rise and fall, turning control of the delay line */
#define PWM_HRCNFG_CTLMODE_Msk                              0x00000004  /*!< register specifies the delay */
#define PWM_HRCNFG_HR_LOAD_Msk                              0x00000008  /*!< load event of deferred value to the active register */
#define PWM_HRCNFG_MEP_SCALEFACTOR_Msk                      0x00FF0000  /*!< result of the correction circuit of the delay line */

/*-- FWDTH: Register width filtering -----------------------------------------*/

typedef struct {
  uint32_t FWDTH                                  :8;                   /*!< Short pulse width of the filter */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _PWM_FWDTH_bits;

/* Bit field positions: */
#define PWM_FWDTH_FWDTH_Pos                                 0           /*!< Short pulse width of the filter */

/* Bit field masks: */
#define PWM_FWDTH_FWDTH_Msk                                 0x000000FF  /*!< Short pulse width of the filter */

/*-- HDSEL: Register source event retention ----------------------------------*/

typedef struct {
  uint32_t DCMP                                   :24;                  /*!< Mask of the ADC digital comparator */
  uint32_t ACMP                                   :3;                   /*!< Mask Analog Comparator */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CBC                                    :1;                   /*!< Enable source ACMP/DCMP in cycle mode */
  uint32_t Reserved1                              :2;                   /*!< Reserved */
  uint32_t OSHT                                   :1;                   /*!< Enable source ACMP/DCMP in one-shot mode */
} _PWM_HDSEL_bits;

/* Bit field positions: */
#define PWM_HDSEL_DCMP_Pos                                  0           /*!< Mask of the ADC digital comparator */
#define PWM_HDSEL_ACMP_Pos                                  24          /*!< Mask Analog Comparator */
#define PWM_HDSEL_CBC_Pos                                   28          /*!< Enable source ACMP/DCMP in cycle mode */
#define PWM_HDSEL_OSHT_Pos                                  31          /*!< Enable source ACMP/DCMP in one-shot mode */

/* Bit field masks: */
#define PWM_HDSEL_DCMP_Msk                                  0x00FFFFFF  /*!< Mask of the ADC digital comparator */
#define PWM_HDSEL_ACMP_Msk                                  0x07000000  /*!< Mask Analog Comparator */
#define PWM_HDSEL_CBC_Msk                                   0x10000000  /*!< Enable source ACMP/DCMP in cycle mode */
#define PWM_HDSEL_OSHT_Msk                                  0x80000000  /*!< Enable source ACMP/DCMP in one-shot mode */

/*-- HDCTL: Control Register detector hold events ----------------------------*/

typedef struct {
  uint32_t HDA                                    :2;                   /*!< Signal A behavior in case failure events */
  uint32_t HDB                                    :2;                   /*!< Signal B behavior in case failure events */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _PWM_HDCTL_bits;

/* Bit field positions: */
#define PWM_HDCTL_HDA_Pos                                   0           /*!< Signal A behavior in case failure events */
#define PWM_HDCTL_HDB_Pos                                   2           /*!< Signal B behavior in case failure events */

/* Bit field masks: */
#define PWM_HDCTL_HDA_Msk                                   0x00000003  /*!< Signal A behavior in case failure events */
#define PWM_HDCTL_HDB_Msk                                   0x0000000C  /*!< Signal B behavior in case failure events */

/*-- HDEINT: Register software activation threshold trigger ------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CBC                                    :1;                   /*!< Activation threshold trigger in cycle mode */
  uint32_t OST                                    :1;                   /*!< Activation threshold trigger in single mode */
  uint32_t Reserved1                              :29;                  /*!< Reserved */
} _PWM_HDEINT_bits;

/* Bit field positions: */
#define PWM_HDEINT_CBC_Pos                                  1           /*!< Activation threshold trigger in cycle mode */
#define PWM_HDEINT_OST_Pos                                  2           /*!< Activation threshold trigger in single mode */

/* Bit field masks: */
#define PWM_HDEINT_CBC_Msk                                  0x00000002  /*!< Activation threshold trigger in cycle mode */
#define PWM_HDEINT_OST_Msk                                  0x00000004  /*!< Activation threshold trigger in single mode */

/*-- HDFLG: Registrer HD flag interrupt --------------------------------------*/

typedef struct {
  uint32_t HDINT                                  :1;
  uint32_t CBC                                    :1;                   /*!< Activation threshold trigger in cycle mode */
  uint32_t OST                                    :1;                   /*!< Activation threshold trigger in single mode */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _PWM_HDFLG_bits;

/* Bit field positions: */
#define PWM_HDFLG_HDINT_Pos                                 0
#define PWM_HDFLG_CBC_Pos                                   1           /*!< Activation threshold trigger in cycle mode */
#define PWM_HDFLG_OST_Pos                                   2           /*!< Activation threshold trigger in single mode */

/* Bit field masks: */
#define PWM_HDFLG_HDINT_Msk                                 0x00000001
#define PWM_HDFLG_CBC_Msk                                   0x00000002  /*!< Activation threshold trigger in cycle mode */
#define PWM_HDFLG_OST_Msk                                   0x00000004  /*!< Activation threshold trigger in single mode */

/*-- HDCLR: Register clear HD flag -------------------------------------------*/

typedef struct {
  uint32_t HDINT                                  :1;                   /*!< Clear flag HDINT */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _PWM_HDCLR_bits;

/* Bit field positions: */
#define PWM_HDCLR_HDINT_Pos                                 0           /*!< Clear flag HDINT */

/* Bit field masks: */
#define PWM_HDCLR_HDINT_Msk                                 0x00000001  /*!< Clear flag HDINT */

/*-- HDFRC: Register software activation threshold trigger -------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CBC                                    :1;                   /*!< activation threshold trigger in cycle mode */
  uint32_t OST                                    :1;                   /*!< activation threshold trigger in single mode */
  uint32_t Reserved1                              :29;                  /*!< Reserved */
} _PWM_HDFRC_bits;

/* Bit field positions: */
#define PWM_HDFRC_CBC_Pos                                   1           /*!< activation threshold trigger in cycle mode */
#define PWM_HDFRC_OST_Pos                                   2           /*!< activation threshold trigger in single mode */

/* Bit field masks: */
#define PWM_HDFRC_CBC_Msk                                   0x00000002  /*!< activation threshold trigger in cycle mode */
#define PWM_HDFRC_OST_Msk                                   0x00000004  /*!< activation threshold trigger in single mode */

/*-- HDINTCLR: Register clear HD interrupt -----------------------------------*/

typedef struct {
  uint32_t HDINT                                  :1;                   /*!< Clear HD interrupt */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _PWM_HDINTCLR_bits;

/* Bit field positions: */
#define PWM_HDINTCLR_HDINT_Pos                              0           /*!< Clear HD interrupt */

/* Bit field masks: */
#define PWM_HDINTCLR_HDINT_Msk                              0x00000001  /*!< Clear HD interrupt */

/*-- TZINTCLR: Register clear TZ interrupt -----------------------------------*/

typedef struct {
  uint32_t TZINT                                  :1;                   /*!< Clear TZ interrupt */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _PWM_TZINTCLR_bits;

/* Bit field positions: */
#define PWM_TZINTCLR_TZINT_Pos                              0           /*!< Clear TZ interrupt */

/* Bit field masks: */
#define PWM_TZINTCLR_TZINT_Msk                              0x00000001  /*!< Clear TZ interrupt */

/*-- INTCLR: Register clear interrupt ----------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< Clear interrupt */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _PWM_INTCLR_bits;

/* Bit field positions: */
#define PWM_INTCLR_INT_Pos                                  0           /*!< Clear interrupt */

/* Bit field masks: */
#define PWM_INTCLR_INT_Msk                                  0x00000001  /*!< Clear interrupt */

/*-- Register map for PWM peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Timer Control Register */
    __IO uint32_t TBCTL;                                                /*!< TBCTL    : type used for word access */
    __IO _PWM_TBCTL_bits TBCTL_bit;                                     /*!< TBCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Timer status register */
    __IO  uint32_t TBSTS;                                               /*!< TBSTS    : type used for word access */
    __IO  _PWM_TBSTS_bits TBSTS_bit;                                    /*!< TBSTS_bit: structure used for bit access */
  };
  union {                                                               /*!< register Phases */
    __IO uint32_t TBPHS;                                                /*!< TBPHS    : type used for word access */
    __IO _PWM_TBPHS_bits TBPHS_bit;                                     /*!< TBPHS_bit: structure used for bit access */
  };
  union {                                                               /*!< Register current value of timer */
    __IO uint32_t TBCTR;                                                /*!< TBCTR    : type used for word access */
    __IO _PWM_TBCTR_bits TBCTR_bit;                                     /*!< TBCTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register maximum Timer */
    __IO uint32_t TBPRD;                                                /*!< TBPRD    : type used for word access */
    __IO _PWM_TBPRD_bits TBPRD_bit;                                     /*!< TBPRD_bit: structure used for bit access */
  };
  union {                                                               /*!<  */
    __IO uint32_t CMPCTL;                                               /*!< CMPCTL    : type used for word access */
    __IO _PWM_CMPCTL_bits CMPCTL_bit;                                   /*!< CMPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Register threshold A */
    __IO uint32_t CMPA;                                                 /*!< CMPA    : type used for word access */
    __IO _PWM_CMPA_bits CMPA_bit;                                       /*!< CMPA_bit: structure used for bit access */
  };
  union {                                                               /*!< Register threshold B */
    __IO uint32_t CMPB;                                                 /*!< CMPB    : type used for word access */
    __IO _PWM_CMPB_bits CMPB_bit;                                       /*!< CMPB_bit: structure used for bit access */
  };
  union {                                                               /*!< Register handlers for output A */
    __IO uint32_t AQCTLA;                                               /*!< AQCTLA    : type used for word access */
    __IO _PWM_AQCTLA_bits AQCTLA_bit;                                   /*!< AQCTLA_bit: structure used for bit access */
  };
  union {                                                               /*!< Register handlers for output B */
    __IO uint32_t AQCTLB;                                               /*!< AQCTLB    : type used for word access */
    __IO _PWM_AQCTLB_bits AQCTLB_bit;                                   /*!< AQCTLB_bit: structure used for bit access */
  };
  union {                                                               /*!< Register handlers for a single program management */
    __IO uint32_t AQSFRC;                                               /*!< AQSFRC    : type used for word access */
    __IO _PWM_AQSFRC_bits AQSFRC_bit;                                   /*!< AQSFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Register handlers for the cyclic program Management */
    __IO uint32_t AQCSFRC;                                              /*!< AQCSFRC    : type used for word access */
    __IO _PWM_AQCSFRC_bits AQCSFRC_bit;                                 /*!< AQCSFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Generator Control Register PWM Dead Time */
    __IO uint32_t DBCTL;                                                /*!< DBCTL    : type used for word access */
    __IO _PWM_DBCTL_bits DBCTL_bit;                                     /*!< DBCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead time control register */
    __IO uint32_t DBRED;                                                /*!< DBRED    : type used for word access */
    __IO _PWM_DBRED_bits DBRED_bit;                                     /*!< DBRED_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead time control register */
    __IO uint32_t DBFED;                                                /*!< DBFED    : type used for word access */
    __IO _PWM_DBFED_bits DBFED_bit;                                     /*!< DBFED_bit: structure used for bit access */
  };
  union {                                                               /*!< Register the source of the accident */
    __IO uint32_t TZSEL;                                                /*!< TZSEL    : type used for word access */
    __IO _PWM_TZSEL_bits TZSEL_bit;                                     /*!< TZSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register detector alarm signal */
    __IO uint32_t TZCTL;                                                /*!< TZCTL    : type used for word access */
    __IO _PWM_TZCTL_bits TZCTL_bit;                                     /*!< TZCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register Signal Detection Alarms */
    __IO uint32_t TZEINT;                                               /*!< TZEINT    : type used for word access */
    __IO _PWM_TZEINT_bits TZEINT_bit;                                   /*!< TZEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Flags register interrupt signal detector Accidents */
    __I  uint32_t TZFLG;                                                /*!< TZFLG    : type used for word access */
    __I  _PWM_TZFLG_bits TZFLG_bit;                                     /*!< TZFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register reset interrupt flag detector alarm signal */
    __IO uint32_t TZCLR;                                                /*!< TZCLR    : type used for word access */
    __IO _PWM_TZCLR_bits TZCLR_bit;                                     /*!< TZCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register software emulation of faults */
    __IO uint32_t TZFRC;                                                /*!< TZFRC    : type used for word access */
    __IO _PWM_TZFRC_bits TZFRC_bit;                                     /*!< TZFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< A Source event trigger */
    __IO uint32_t ETSEL;                                                /*!< ETSEL    : type used for word access */
    __IO _PWM_ETSEL_bits ETSEL_bit;                                     /*!< ETSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Prescaler register the event trigger */
    __IO uint32_t ETPS;                                                 /*!< ETPS    : type used for word access */
    __IO _PWM_ETPS_bits ETPS_bit;                                       /*!< ETPS_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Flags event trigger */
    __I  uint32_t ETFLG;                                                /*!< ETFLG    : type used for word access */
    __I  _PWM_ETFLG_bits ETFLG_bit;                                     /*!< ETFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register reset flags trigger events */
    __IO uint32_t ETCLR;                                                /*!< ETCLR    : type used for word access */
    __IO _PWM_ETCLR_bits ETCLR_bit;                                     /*!< ETCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register software emulation events */
    __IO  uint32_t ETFRC;                                                /*!< ETFRC    : type used for word access */
    __IO  _PWM_ETFRC_bits ETFRC_bit;                                     /*!< ETFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register modulator */
    __IO uint32_t PCCTL;                                                /*!< PCCTL    : type used for word access */
    __IO _PWM_PCCTL_bits PCCTL_bit;                                     /*!< PCCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Configuration Block PWM High Definition */
    __IO uint32_t HRCNFG;                                               /*!< HRCNFG    : type used for word access */
    __IO _PWM_HRCNFG_bits HRCNFG_bit;                                   /*!< HRCNFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register width filtering */
    __IO uint32_t FWDTH;                                                /*!< FWDTH    : type used for word access */
    __IO _PWM_FWDTH_bits FWDTH_bit;                                     /*!< FWDTH_bit: structure used for bit access */
  };
  uint32_t Reserved0[5];                                                /*!< Reserved */
  union {                                                               /*!< Register source event retention */
    __IO uint32_t HDSEL;                                                /*!< HDSEL    : type used for word access */
    __IO _PWM_HDSEL_bits HDSEL_bit;                                     /*!< HDSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register detector hold events */
    __IO uint32_t HDCTL;                                                /*!< HDCTL    : type used for word access */
    __IO _PWM_HDCTL_bits HDCTL_bit;                                     /*!< HDCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Register software activation threshold trigger */
    __IO uint32_t HDEINT;                                               /*!< HDEINT    : type used for word access */
    __IO _PWM_HDEINT_bits HDEINT_bit;                                   /*!< HDEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Registrer HD flag interrupt */
    __I  uint32_t HDFLG;                                                /*!< HDFLG    : type used for word access */
    __I  _PWM_HDFLG_bits HDFLG_bit;                                     /*!< HDFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear HD flag */
    __IO uint32_t HDCLR;                                                /*!< HDCLR    : type used for word access */
    __IO _PWM_HDCLR_bits HDCLR_bit;                                     /*!< HDCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register software activation threshold trigger */
    __IO uint32_t HDFRC;                                                /*!< HDFRC    : type used for word access */
    __IO _PWM_HDFRC_bits HDFRC_bit;                                     /*!< HDFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear HD interrupt */
    __O  uint32_t HDINTCLR;                                             /*!< HDINTCLR    : type used for word access */
    __O  _PWM_HDINTCLR_bits HDINTCLR_bit;                               /*!< HDINTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear TZ interrupt */
    __O  uint32_t TZINTCLR;                                             /*!< TZINTCLR    : type used for word access */
    __O  _PWM_TZINTCLR_bits TZINTCLR_bit;                               /*!< TZINTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear interrupt */
    __O  uint32_t INTCLR;                                               /*!< INTCLR    : type used for word access */
    __O  _PWM_INTCLR_bits INTCLR_bit;                                   /*!< INTCLR_bit: structure used for bit access */
  };
} NT_PWM_TypeDef;

/******************************************************************************/
/*                         CAP controller registers                           */
/******************************************************************************/

/*-- ECCTL0: Register capture control 0 --------------------------------------*/

typedef struct {
  uint32_t CAP0_POL                               :1;                   /*!< pos/negedge capture 0 */
  uint32_t CTR_RST0                               :1;                   /*!< reset later event 0 */
  uint32_t CAP1_POL                               :1;                   /*!< pos/negedge capture 1 */
  uint32_t CTR_RST1                               :1;                   /*!< reset later event 1 */
  uint32_t CAP2_POL                               :1;                   /*!< pos/negedge capture 2 */
  uint32_t CTR_RST2                               :1;                   /*!< reset later event 2 */
  uint32_t CAP3_POL                               :1;                   /*!< pos/negedge capture 3 */
  uint32_t CTR_RST3                               :1;                   /*!< reset later event 3 */
  uint32_t CAPLDEN                                :1;                   /*!< enable capture */
  uint32_t PRESCALE                               :5;                   /*!< Prescaler meaning */
  uint32_t FREE_SOFT                              :2;                   /*!< Emulation mode */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _CAP_ECCTL0_bits;

/* Bit field positions: */
#define CAP_ECCTL0_CAP0_POL_Pos                             0           /*!< pos/negedge capture 0 */
#define CAP_ECCTL0_CTR_RST0_Pos                             1           /*!< reset later event 0 */
#define CAP_ECCTL0_CAP1_POL_Pos                             2           /*!< pos/negedge capture 1 */
#define CAP_ECCTL0_CTR_RST1_Pos                             3           /*!< reset later event 1 */
#define CAP_ECCTL0_CAP2_POL_Pos                             4           /*!< pos/negedge capture 2 */
#define CAP_ECCTL0_CTR_RST2_Pos                             5           /*!< reset later event 2 */
#define CAP_ECCTL0_CAP3_POL_Pos                             6           /*!< pos/negedge capture 3 */
#define CAP_ECCTL0_CTR_RST3_Pos                             7           /*!< reset later event 3 */
#define CAP_ECCTL0_CAPLDEN_Pos                              8           /*!< enable capture */
#define CAP_ECCTL0_PRESCALE_Pos                             9           /*!< Prescaler meaning */
#define CAP_ECCTL0_FREE_SOFT_Pos                            14          /*!< Emulation mode */

/* Bit field masks: */
#define CAP_ECCTL0_CAP0_POL_Msk                             0x00000001  /*!< pos/negedge capture 0 */
#define CAP_ECCTL0_CTR_RST0_Msk                             0x00000002  /*!< reset later event 0 */
#define CAP_ECCTL0_CAP1_POL_Msk                             0x00000004  /*!< pos/negedge capture 1 */
#define CAP_ECCTL0_CTR_RST1_Msk                             0x00000008  /*!< reset later event 1 */
#define CAP_ECCTL0_CAP2_POL_Msk                             0x00000010  /*!< pos/negedge capture 2 */
#define CAP_ECCTL0_CTR_RST2_Msk                             0x00000020  /*!< reset later event 2 */
#define CAP_ECCTL0_CAP3_POL_Msk                             0x00000040  /*!< pos/negedge capture 3 */
#define CAP_ECCTL0_CTR_RST3_Msk                             0x00000080  /*!< reset later event 3 */
#define CAP_ECCTL0_CAPLDEN_Msk                              0x00000100  /*!< enable capture */
#define CAP_ECCTL0_PRESCALE_Msk                             0x00003E00  /*!< Prescaler meaning */
#define CAP_ECCTL0_FREE_SOFT_Msk                            0x0000C000  /*!< Emulation mode */

/*-- ECCTL1: Register capture control 1 --------------------------------------*/

typedef struct {
  uint32_t CONT_ONESHT                            :1;                   /*!< Capture mode */
  uint32_t STOP_WRAP                              :2;                   /*!< Stops campare */
  uint32_t REARM                                  :1;                   /*!< reset and enable controller, load reg capt */
  uint32_t TSCTRSTOP                              :1;                   /*!< enable Timer */
  uint32_t SYNCI_EN                               :1;                   /*!< sync outer impulse */
  uint32_t SYNCO_SEL                              :2;                   /*!< Synchronization signal */
  uint32_t SWSYNC                                 :1;                   /*!< Timers synchr */
  uint32_t CAP_APWM                               :1;                   /*!< Capture mode or APWM */
  uint32_t APWM_POL                               :1;                   /*!< High/low level APWM */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _CAP_ECCTL1_bits;

/* Bit field positions: */
#define CAP_ECCTL1_CONT_ONESHT_Pos                          0           /*!< Capture mode */
#define CAP_ECCTL1_STOP_WRAP_Pos                            1           /*!< Stops campare */
#define CAP_ECCTL1_REARM_Pos                                3           /*!< reset and enable controller, load reg capt */
#define CAP_ECCTL1_TSCTRSTOP_Pos                            4           /*!< enable Timer */
#define CAP_ECCTL1_SYNCI_EN_Pos                             5           /*!< sync outer impulse */
#define CAP_ECCTL1_SYNCO_SEL_Pos                            6           /*!< Synchronization signal */
#define CAP_ECCTL1_SWSYNC_Pos                               8           /*!< Timers synchr */
#define CAP_ECCTL1_CAP_APWM_Pos                             9           /*!< Capture mode or APWM */
#define CAP_ECCTL1_APWM_POL_Pos                             10          /*!< High/low level APWM */

/* Bit field masks: */
#define CAP_ECCTL1_CONT_ONESHT_Msk                          0x00000001  /*!< Capture mode */
#define CAP_ECCTL1_STOP_WRAP_Msk                            0x00000006  /*!< Stops campare */
#define CAP_ECCTL1_REARM_Msk                                0x00000008  /*!< reset and enable controller, load reg capt */
#define CAP_ECCTL1_TSCTRSTOP_Msk                            0x00000010  /*!< enable Timer */
#define CAP_ECCTL1_SYNCI_EN_Msk                             0x00000020  /*!< sync outer impulse */
#define CAP_ECCTL1_SYNCO_SEL_Msk                            0x000000C0  /*!< Synchronization signal */
#define CAP_ECCTL1_SWSYNC_Msk                               0x00000100  /*!< Timers synchr */
#define CAP_ECCTL1_CAP_APWM_Msk                             0x00000200  /*!< Capture mode or APWM */
#define CAP_ECCTL1_APWM_POL_Msk                             0x00000400  /*!< High/low level APWM */

/*-- ECEINT: Register interrupt mask -----------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CEVT0                                  :1;                   /*!< enable int CEVT0 */
  uint32_t CEVT1                                  :1;                   /*!< enable int CEVT1 */
  uint32_t CEVT2                                  :1;                   /*!< enable int CEVT2 */
  uint32_t CEVT3                                  :1;                   /*!< enable int CEVT3 */
  uint32_t CTR_OVF                                :1;                   /*!< enable int CTR_OVF */
  uint32_t CTR_PRD                                :1;                   /*!< enable int CTR=PRD */
  uint32_t CTR_CMP                                :1;                   /*!< enable int CTR=CMP */
  uint32_t Reserved1                              :24;                  /*!< Reserved */
} _CAP_ECEINT_bits;

/* Bit field positions: */
#define CAP_ECEINT_CEVT0_Pos                                1           /*!< enable int CEVT0 */
#define CAP_ECEINT_CEVT1_Pos                                2           /*!< enable int CEVT1 */
#define CAP_ECEINT_CEVT2_Pos                                3           /*!< enable int CEVT2 */
#define CAP_ECEINT_CEVT3_Pos                                4           /*!< enable int CEVT3 */
#define CAP_ECEINT_CTR_OVF_Pos                              5           /*!< enable int CTR_OVF */
#define CAP_ECEINT_CTR_PRD_Pos                              6           /*!< enable int CTR=PRD */
#define CAP_ECEINT_CTR_CMP_Pos                              7           /*!< enable int CTR=CMP */

/* Bit field masks: */
#define CAP_ECEINT_CEVT0_Msk                                0x00000002  /*!< enable int CEVT0 */
#define CAP_ECEINT_CEVT1_Msk                                0x00000004  /*!< enable int CEVT1 */
#define CAP_ECEINT_CEVT2_Msk                                0x00000008  /*!< enable int CEVT2 */
#define CAP_ECEINT_CEVT3_Msk                                0x00000010  /*!< enable int CEVT3 */
#define CAP_ECEINT_CTR_OVF_Msk                              0x00000020  /*!< enable int CTR_OVF */
#define CAP_ECEINT_CTR_PRD_Msk                              0x00000040  /*!< enable int CTR=PRD */
#define CAP_ECEINT_CTR_CMP_Msk                              0x00000080  /*!< enable int CTR=CMP */

/*-- ECFLG: Register interrupt status ----------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< indicate global interrupt */
  uint32_t CEVT0                                  :1;                   /*!< Hap interrupt CEVT0 */
  uint32_t CEVT1                                  :1;                   /*!< Hap interrupt CEVT1 */
  uint32_t CEVT2                                  :1;                   /*!< Hap interrupt CEVT2 */
  uint32_t CEVT3                                  :1;                   /*!< Hap interrupt CEVT3 */
  uint32_t CTR_OVF                                :1;                   /*!< Hap interrupt CTROVF */
  uint32_t CTR_PRD                                :1;                   /*!< Hap interrupt CTR=PRD */
  uint32_t CTR_CMP                                :1;                   /*!< Hap interrupt CTR=CMP */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _CAP_ECFLG_bits;

/* Bit field positions: */
#define CAP_ECFLG_INT_Pos                                   0           /*!< indicate global interrupt */
#define CAP_ECFLG_CEVT0_Pos                                 1           /*!< Hap interrupt CEVT0 */
#define CAP_ECFLG_CEVT1_Pos                                 2           /*!< Hap interrupt CEVT1 */
#define CAP_ECFLG_CEVT2_Pos                                 3           /*!< Hap interrupt CEVT2 */
#define CAP_ECFLG_CEVT3_Pos                                 4           /*!< Hap interrupt CEVT3 */
#define CAP_ECFLG_CTR_OVF_Pos                               5           /*!< Hap interrupt CTROVF */
#define CAP_ECFLG_CTR_PRD_Pos                               6           /*!< Hap interrupt CTR=PRD */
#define CAP_ECFLG_CTR_CMP_Pos                               7           /*!< Hap interrupt CTR=CMP */

/* Bit field masks: */
#define CAP_ECFLG_INT_Msk                                   0x00000001  /*!< indicate global interrupt */
#define CAP_ECFLG_CEVT0_Msk                                 0x00000002  /*!< Hap interrupt CEVT0 */
#define CAP_ECFLG_CEVT1_Msk                                 0x00000004  /*!< Hap interrupt CEVT1 */
#define CAP_ECFLG_CEVT2_Msk                                 0x00000008  /*!< Hap interrupt CEVT2 */
#define CAP_ECFLG_CEVT3_Msk                                 0x00000010  /*!< Hap interrupt CEVT3 */
#define CAP_ECFLG_CTR_OVF_Msk                               0x00000020  /*!< Hap interrupt CTROVF */
#define CAP_ECFLG_CTR_PRD_Msk                               0x00000040  /*!< Hap interrupt CTR=PRD */
#define CAP_ECFLG_CTR_CMP_Msk                               0x00000080  /*!< Hap interrupt CTR=CMP */

/*-- ECCLR: Register reset interrupt -----------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< reset global interrupt */
  uint32_t CEVT0                                  :1;                   /*!< reset intstatus */
  uint32_t CEVT1                                  :1;                   /*!< reset intstatus */
  uint32_t CEVT2                                  :1;                   /*!< reset intstatus */
  uint32_t CEVT3                                  :1;                   /*!< reset intstatus */
  uint32_t CTR_OVF                                :1;                   /*!< reset intstatus */
  uint32_t CTR_PRD                                :1;                   /*!< reset intstatus */
  uint32_t CTR_CMP                                :1;                   /*!< reset intstatus */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _CAP_ECCLR_bits;

/* Bit field positions: */
#define CAP_ECCLR_INT_Pos                                   0           /*!< reset global interrupt */
#define CAP_ECCLR_CEVT0_Pos                                 1           /*!< reset intstatus */
#define CAP_ECCLR_CEVT1_Pos                                 2           /*!< reset intstatus */
#define CAP_ECCLR_CEVT2_Pos                                 3           /*!< reset intstatus */
#define CAP_ECCLR_CEVT3_Pos                                 4           /*!< reset intstatus */
#define CAP_ECCLR_CTR_OVF_Pos                               5           /*!< reset intstatus */
#define CAP_ECCLR_CTR_PRD_Pos                               6           /*!< reset intstatus */
#define CAP_ECCLR_CTR_CMP_Pos                               7           /*!< reset intstatus */

/* Bit field masks: */
#define CAP_ECCLR_INT_Msk                                   0x00000001  /*!< reset global interrupt */
#define CAP_ECCLR_CEVT0_Msk                                 0x00000002  /*!< reset intstatus */
#define CAP_ECCLR_CEVT1_Msk                                 0x00000004  /*!< reset intstatus */
#define CAP_ECCLR_CEVT2_Msk                                 0x00000008  /*!< reset intstatus */
#define CAP_ECCLR_CEVT3_Msk                                 0x00000010  /*!< reset intstatus */
#define CAP_ECCLR_CTR_OVF_Msk                               0x00000020  /*!< reset intstatus */
#define CAP_ECCLR_CTR_PRD_Msk                               0x00000040  /*!< reset intstatus */
#define CAP_ECCLR_CTR_CMP_Msk                               0x00000080  /*!< reset intstatus */

/*-- ECFRC: Test register interrupt generation -------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t CEVT0                                  :1;                   /*!< gen test interrupt */
  uint32_t CEVT1                                  :1;                   /*!< gen test interrupt */
  uint32_t CEVT2                                  :1;                   /*!< gen test interrupt */
  uint32_t CEVT3                                  :1;                   /*!< gen test interrupt */
  uint32_t CTR_OVF                                :1;                   /*!< gen test interrupt */
  uint32_t CTR_PRD                                :1;                   /*!< gen test interrupt */
  uint32_t CTR_CMP                                :1;                   /*!< gen test interrupt */
  uint32_t Reserved1                              :24;                  /*!< Reserved */
} _CAP_ECFRC_bits;

/* Bit field positions: */
#define CAP_ECFRC_CEVT0_Pos                                 1           /*!< gen test interrupt */
#define CAP_ECFRC_CEVT1_Pos                                 2           /*!< gen test interrupt */
#define CAP_ECFRC_CEVT2_Pos                                 3           /*!< gen test interrupt */
#define CAP_ECFRC_CEVT3_Pos                                 4           /*!< gen test interrupt */
#define CAP_ECFRC_CTR_OVF_Pos                               5           /*!< gen test interrupt */
#define CAP_ECFRC_CTR_PRD_Pos                               6           /*!< gen test interrupt */
#define CAP_ECFRC_CTR_CMP_Pos                               7           /*!< gen test interrupt */

/* Bit field masks: */
#define CAP_ECFRC_CEVT0_Msk                                 0x00000002  /*!< gen test interrupt */
#define CAP_ECFRC_CEVT1_Msk                                 0x00000004  /*!< gen test interrupt */
#define CAP_ECFRC_CEVT2_Msk                                 0x00000008  /*!< gen test interrupt */
#define CAP_ECFRC_CEVT3_Msk                                 0x00000010  /*!< gen test interrupt */
#define CAP_ECFRC_CTR_OVF_Msk                               0x00000020  /*!< gen test interrupt */
#define CAP_ECFRC_CTR_PRD_Msk                               0x00000040  /*!< gen test interrupt */
#define CAP_ECFRC_CTR_CMP_Msk                               0x00000080  /*!< gen test interrupt */

/*-- PEINT: Active interrupt status register ---------------------------------*/

typedef struct {
  uint32_t PEINT                                  :1;                   /*!< active interrupt flag */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _CAP_PEINT_bits;

/* Bit field positions: */
#define CAP_PEINT_PEINT_Pos                                 0           /*!< active interrupt flag */

/* Bit field masks: */
#define CAP_PEINT_PEINT_Msk                                 0x00000001  /*!< active interrupt flag */

/*-- Register map for CAP peripheral -----------------------------------------*/

typedef struct {
  __IO uint32_t TSCTR;                                                  /*!< TIMER register */
  __IO uint32_t CTRPHS;                                                 /*!< Load Timer register */
  __IO uint32_t CAP0;                                                   /*!< Capture register 0 */
  __IO uint32_t CAP1;                                                   /*!< Capture register 1 */
  __IO uint32_t CAP2;                                                   /*!< Capture register 2 */
  __IO uint32_t CAP3;                                                   /*!< Capture register 3 */
  uint32_t Reserved0[4];                                                /*!< Reserved */
  union {                                                               /*!< Register capture control 0 */
    __IO uint32_t ECCTL0;                                               /*!< ECCTL0    : type used for word access */
    __IO _CAP_ECCTL0_bits ECCTL0_bit;                                   /*!< ECCTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register capture control 1 */
    __IO uint32_t ECCTL1;                                               /*!< ECCTL1    : type used for word access */
    __IO _CAP_ECCTL1_bits ECCTL1_bit;                                   /*!< ECCTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Register interrupt mask */
    __IO uint32_t ECEINT;                                               /*!< ECEINT    : type used for word access */
    __IO _CAP_ECEINT_bits ECEINT_bit;                                   /*!< ECEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Register interrupt status */
    __I  uint32_t ECFLG;                                                /*!< ECFLG    : type used for word access */
    __I  _CAP_ECFLG_bits ECFLG_bit;                                     /*!< ECFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register reset interrupt */
    __IO uint32_t ECCLR;                                                /*!< ECCLR    : type used for word access */
    __IO _CAP_ECCLR_bits ECCLR_bit;                                     /*!< ECCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Test register interrupt generation */
    __IO uint32_t ECFRC;                                                /*!< ECFRC    : type used for word access */
    __IO _CAP_ECFRC_bits ECFRC_bit;                                     /*!< ECFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Active interrupt status register */
    __IO uint32_t PEINT;                                                /*!< PEINT    : type used for word access */
    __IO _CAP_PEINT_bits PEINT_bit;                                     /*!< PEINT_bit: structure used for bit access */
  };
} NT_CAP_TypeDef;

/******************************************************************************/
/*                        eQEP controller registers                           */
/******************************************************************************/

/*-- QDECCTL: Input control register -----------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :5;                   /*!< Reserved */
  uint32_t QSP                                    :1;                   /*!< inversion QEPS */
  uint32_t QIP                                    :1;                   /*!< inv. QEPI */
  uint32_t QBP                                    :1;                   /*!< inv. QEPB */
  uint32_t QAP                                    :1;                   /*!< inv. QEPA */
  uint32_t IGATE                                  :1;                   /*!< strobing input signal */
  uint32_t SWAP                                   :1;                   /*!< trade places QEPA and QEPB */
  uint32_t XCR                                    :1;                   /*!< edge selector */
  uint32_t SPSEL                                  :1;                   /*!< index/strobe output */
  uint32_t SOEN                                   :1;                   /*!< enable PCSOUT */
  uint32_t QSRC                                   :2;                   /*!< Select mode */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _QEP_QDECCTL_bits;

/* Bit field positions: */
#define QEP_QDECCTL_QSP_Pos                                 5           /*!< inversion QEPS */
#define QEP_QDECCTL_QIP_Pos                                 6           /*!< inv. QEPI */
#define QEP_QDECCTL_QBP_Pos                                 7           /*!< inv. QEPB */
#define QEP_QDECCTL_QAP_Pos                                 8           /*!< inv. QEPA */
#define QEP_QDECCTL_IGATE_Pos                               9           /*!< strobing input signal */
#define QEP_QDECCTL_SWAP_Pos                                10          /*!< trade places QEPA and QEPB */
#define QEP_QDECCTL_XCR_Pos                                 11          /*!< edge selector */
#define QEP_QDECCTL_SPSEL_Pos                               12          /*!< index/strobe output */
#define QEP_QDECCTL_SOEN_Pos                                13          /*!< enable PCSOUT */
#define QEP_QDECCTL_QSRC_Pos                                14          /*!< Select mode */

/* Bit field masks: */
#define QEP_QDECCTL_QSP_Msk                                 0x00000020  /*!< inversion QEPS */
#define QEP_QDECCTL_QIP_Msk                                 0x00000040  /*!< inv. QEPI */
#define QEP_QDECCTL_QBP_Msk                                 0x00000080  /*!< inv. QEPB */
#define QEP_QDECCTL_QAP_Msk                                 0x00000100  /*!< inv. QEPA */
#define QEP_QDECCTL_IGATE_Msk                               0x00000200  /*!< strobing input signal */
#define QEP_QDECCTL_SWAP_Msk                                0x00000400  /*!< trade places QEPA and QEPB */
#define QEP_QDECCTL_XCR_Msk                                 0x00000800  /*!< edge selector */
#define QEP_QDECCTL_SPSEL_Msk                               0x00001000  /*!< index/strobe output */
#define QEP_QDECCTL_SOEN_Msk                                0x00002000  /*!< enable PCSOUT */
#define QEP_QDECCTL_QSRC_Msk                                0x0000C000  /*!< Select mode */

/*-- QEPCTL: Quadrature decoder control register -----------------------------*/

typedef struct {
  uint32_t WDE                                    :1;                   /*!< enable watchdog timer */
  uint32_t UTE                                    :1;                   /*!< enable time reading timer */
  uint32_t QCLM                                   :1;                   /*!< save countposition meaning */
  uint32_t QPEN                                   :1;                   /*!< reset meaning countposition */
  uint32_t IEL                                    :2;                   /*!< indexevent */
  uint32_t SEL                                    :1;                   /*!< sttobevent */
  uint32_t SWI                                    :1;                   /*!< enable positioncount */
  uint32_t IEI                                    :2;                   /*!< indexevent fot positioncount */
  uint32_t SEI                                    :2;                   /*!< strobevent for positioncount */
  uint32_t PCRM                                   :2;                   /*!< rate reset positioncount */
  uint32_t FREE_SOFT                              :2;                   /*!< count in halt */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _QEP_QEPCTL_bits;

/* Bit field positions: */
#define QEP_QEPCTL_WDE_Pos                                  0           /*!< enable watchdog timer */
#define QEP_QEPCTL_UTE_Pos                                  1           /*!< enable time reading timer */
#define QEP_QEPCTL_QCLM_Pos                                 2           /*!< save countposition meaning */
#define QEP_QEPCTL_QPEN_Pos                                 3           /*!< reset meaning countposition */
#define QEP_QEPCTL_IEL_Pos                                  4           /*!< indexevent */
#define QEP_QEPCTL_SEL_Pos                                  6           /*!< sttobevent */
#define QEP_QEPCTL_SWI_Pos                                  7           /*!< enable positioncount */
#define QEP_QEPCTL_IEI_Pos                                  8           /*!< indexevent fot positioncount */
#define QEP_QEPCTL_SEI_Pos                                  10          /*!< strobevent for positioncount */
#define QEP_QEPCTL_PCRM_Pos                                 12          /*!< rate reset positioncount */
#define QEP_QEPCTL_FREE_SOFT_Pos                            14          /*!< count in halt */

/* Bit field masks: */
#define QEP_QEPCTL_WDE_Msk                                  0x00000001  /*!< enable watchdog timer */
#define QEP_QEPCTL_UTE_Msk                                  0x00000002  /*!< enable time reading timer */
#define QEP_QEPCTL_QCLM_Msk                                 0x00000004  /*!< save countposition meaning */
#define QEP_QEPCTL_QPEN_Msk                                 0x00000008  /*!< reset meaning countposition */
#define QEP_QEPCTL_IEL_Msk                                  0x00000030  /*!< indexevent */
#define QEP_QEPCTL_SEL_Msk                                  0x00000040  /*!< sttobevent */
#define QEP_QEPCTL_SWI_Msk                                  0x00000080  /*!< enable positioncount */
#define QEP_QEPCTL_IEI_Msk                                  0x00000300  /*!< indexevent fot positioncount */
#define QEP_QEPCTL_SEI_Msk                                  0x00000C00  /*!< strobevent for positioncount */
#define QEP_QEPCTL_PCRM_Msk                                 0x00003000  /*!< rate reset positioncount */
#define QEP_QEPCTL_FREE_SOFT_Msk                            0x0000C000  /*!< count in halt */

/*-- QCAPCTL: Capture register -----------------------------------------------*/

typedef struct {
  uint32_t UPPS                                   :4;                   /*!< Entrance divisor */
  uint32_t CCPS                                   :3;                   /*!< System cycle */
  uint32_t SELEVENT                               :1;                   /*!< Reset timer */
  uint32_t Reserved0                              :7;                   /*!< Reserved */
  uint32_t CEN                                    :1;                   /*!< enable decoder */
  uint32_t Reserved1                              :16;                  /*!< Reserved */
} _QEP_QCAPCTL_bits;

/* Bit field positions: */
#define QEP_QCAPCTL_UPPS_Pos                                0           /*!< Entrance divisor */
#define QEP_QCAPCTL_CCPS_Pos                                4           /*!< System cycle */
#define QEP_QCAPCTL_SELEVENT_Pos                            7           /*!< Reset timer */
#define QEP_QCAPCTL_CEN_Pos                                 15          /*!< enable decoder */

/* Bit field masks: */
#define QEP_QCAPCTL_UPPS_Msk                                0x0000000F  /*!< Entrance divisor */
#define QEP_QCAPCTL_CCPS_Msk                                0x00000070  /*!< System cycle */
#define QEP_QCAPCTL_SELEVENT_Msk                            0x00000080  /*!< Reset timer */
#define QEP_QCAPCTL_CEN_Msk                                 0x00008000  /*!< enable decoder */

/*-- QPOSCTL: Register countposition control ---------------------------------*/

typedef struct {
  uint32_t PCSPW                                  :12;                  /*!< Impulse width */
  uint32_t PCE                                    :1;                   /*!< enable compare */
  uint32_t PCPOL                                  :1;                   /*!< polarity synchout */
  uint32_t PCLOAD                                 :1;                   /*!< Lazy write rate */
  uint32_t PCSHDW                                 :1;                   /*!< Lazy load */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _QEP_QPOSCTL_bits;

/* Bit field positions: */
#define QEP_QPOSCTL_PCSPW_Pos                               0           /*!< Impulse width */
#define QEP_QPOSCTL_PCE_Pos                                 12          /*!< enable compare */
#define QEP_QPOSCTL_PCPOL_Pos                               13          /*!< polarity synchout */
#define QEP_QPOSCTL_PCLOAD_Pos                              14          /*!< Lazy write rate */
#define QEP_QPOSCTL_PCSHDW_Pos                              15          /*!< Lazy load */

/* Bit field masks: */
#define QEP_QPOSCTL_PCSPW_Msk                               0x00000FFF  /*!< Impulse width */
#define QEP_QPOSCTL_PCE_Msk                                 0x00001000  /*!< enable compare */
#define QEP_QPOSCTL_PCPOL_Msk                               0x00002000  /*!< polarity synchout */
#define QEP_QPOSCTL_PCLOAD_Msk                              0x00004000  /*!< Lazy write rate */
#define QEP_QPOSCTL_PCSHDW_Msk                              0x00008000  /*!< Lazy load */

/*-- QEINT: Interrupt mask ---------------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t PCE                                    :1;                   /*!< enable countpos interrupt */
  uint32_t QPE                                    :1;                   /*!< errorphase interrupt */
  uint32_t QDC                                    :1;                   /*!< Change direction interrupt */
  uint32_t WTO                                    :1;                   /*!< Watchdog interrupt */
  uint32_t PCU                                    :1;                   /*!< interrupt countmin */
  uint32_t PCO                                    :1;                   /*!< interrupt countmax */
  uint32_t PCR                                    :1;                   /*!< ready compare int */
  uint32_t PCM                                    :1;                   /*!< enable compare int */
  uint32_t SEL                                    :1;                   /*!< Strobe int */
  uint32_t IEL                                    :1;                   /*!< Index int */
  uint32_t UTO                                    :1;                   /*!< outflow time int */
  uint32_t Reserved1                              :20;                  /*!< Reserved */
} _QEP_QEINT_bits;

/* Bit field positions: */
#define QEP_QEINT_PCE_Pos                                   1           /*!< enable countpos interrupt */
#define QEP_QEINT_QPE_Pos                                   2           /*!< errorphase interrupt */
#define QEP_QEINT_QDC_Pos                                   3           /*!< Change direction interrupt */
#define QEP_QEINT_WTO_Pos                                   4           /*!< Watchdog interrupt */
#define QEP_QEINT_PCU_Pos                                   5           /*!< interrupt countmin */
#define QEP_QEINT_PCO_Pos                                   6           /*!< interrupt countmax */
#define QEP_QEINT_PCR_Pos                                   7           /*!< ready compare int */
#define QEP_QEINT_PCM_Pos                                   8           /*!< enable compare int */
#define QEP_QEINT_SEL_Pos                                   9           /*!< Strobe int */
#define QEP_QEINT_IEL_Pos                                   10          /*!< Index int */
#define QEP_QEINT_UTO_Pos                                   11          /*!< outflow time int */

/* Bit field masks: */
#define QEP_QEINT_PCE_Msk                                   0x00000002  /*!< enable countpos interrupt */
#define QEP_QEINT_QPE_Msk                                   0x00000004  /*!< errorphase interrupt */
#define QEP_QEINT_QDC_Msk                                   0x00000008  /*!< Change direction interrupt */
#define QEP_QEINT_WTO_Msk                                   0x00000010  /*!< Watchdog interrupt */
#define QEP_QEINT_PCU_Msk                                   0x00000020  /*!< interrupt countmin */
#define QEP_QEINT_PCO_Msk                                   0x00000040  /*!< interrupt countmax */
#define QEP_QEINT_PCR_Msk                                   0x00000080  /*!< ready compare int */
#define QEP_QEINT_PCM_Msk                                   0x00000100  /*!< enable compare int */
#define QEP_QEINT_SEL_Msk                                   0x00000200  /*!< Strobe int */
#define QEP_QEINT_IEL_Msk                                   0x00000400  /*!< Index int */
#define QEP_QEINT_UTO_Msk                                   0x00000800  /*!< outflow time int */

/*-- QFLG: Flag interrupt ----------------------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< outint flag */
  uint32_t PCE                                    :1;                   /*!< enable countpos interrupt flag */
  uint32_t QPE                                    :1;                   /*!< errorphase interrupt flag */
  uint32_t QDC                                    :1;                   /*!< Change direction interrupt flag */
  uint32_t WTO                                    :1;                   /*!< Watchdog interrupt flag */
  uint32_t PCU                                    :1;                   /*!< interrupt countmin flag */
  uint32_t PCO                                    :1;                   /*!< interrupt countmax flag */
  uint32_t PCR                                    :1;                   /*!< ready compare int flag */
  uint32_t PCM                                    :1;                   /*!< enable compare int flag */
  uint32_t SEL                                    :1;                   /*!< Strobe int flag */
  uint32_t IEL                                    :1;                   /*!< Index int flag */
  uint32_t UTO                                    :1;                   /*!< outflow time int flag */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _QEP_QFLG_bits;

/* Bit field positions: */
#define QEP_QFLG_INT_Pos                                    0           /*!< outint flag */
#define QEP_QFLG_PCE_Pos                                    1           /*!< enable countpos interrupt flag */
#define QEP_QFLG_QPE_Pos                                    2           /*!< errorphase interrupt flag */
#define QEP_QFLG_QDC_Pos                                    3           /*!< Change direction interrupt flag */
#define QEP_QFLG_WTO_Pos                                    4           /*!< Watchdog interrupt flag */
#define QEP_QFLG_PCU_Pos                                    5           /*!< interrupt countmin flag */
#define QEP_QFLG_PCO_Pos                                    6           /*!< interrupt countmax flag */
#define QEP_QFLG_PCR_Pos                                    7           /*!< ready compare int flag */
#define QEP_QFLG_PCM_Pos                                    8           /*!< enable compare int flag */
#define QEP_QFLG_SEL_Pos                                    9           /*!< Strobe int flag */
#define QEP_QFLG_IEL_Pos                                    10          /*!< Index int flag */
#define QEP_QFLG_UTO_Pos                                    11          /*!< outflow time int flag */

/* Bit field masks: */
#define QEP_QFLG_INT_Msk                                    0x00000001  /*!< outint flag */
#define QEP_QFLG_PCE_Msk                                    0x00000002  /*!< enable countpos interrupt flag */
#define QEP_QFLG_QPE_Msk                                    0x00000004  /*!< errorphase interrupt flag */
#define QEP_QFLG_QDC_Msk                                    0x00000008  /*!< Change direction interrupt flag */
#define QEP_QFLG_WTO_Msk                                    0x00000010  /*!< Watchdog interrupt flag */
#define QEP_QFLG_PCU_Msk                                    0x00000020  /*!< interrupt countmin flag */
#define QEP_QFLG_PCO_Msk                                    0x00000040  /*!< interrupt countmax flag */
#define QEP_QFLG_PCR_Msk                                    0x00000080  /*!< ready compare int flag */
#define QEP_QFLG_PCM_Msk                                    0x00000100  /*!< enable compare int flag */
#define QEP_QFLG_SEL_Msk                                    0x00000200  /*!< Strobe int flag */
#define QEP_QFLG_IEL_Msk                                    0x00000400  /*!< Index int flag */
#define QEP_QFLG_UTO_Msk                                    0x00000800  /*!< outflow time int flag */

/*-- QCLR: Reset interrupt ---------------------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< reset flag */
  uint32_t PCE                                    :1;                   /*!< reset flag */
  uint32_t QPE                                    :1;                   /*!< reset flag */
  uint32_t QDC                                    :1;                   /*!< reset flag */
  uint32_t WTO                                    :1;                   /*!< reset flag */
  uint32_t PCU                                    :1;                   /*!< reset flag */
  uint32_t PCO                                    :1;                   /*!< reset flag */
  uint32_t PCR                                    :1;                   /*!< reset flag */
  uint32_t PCM                                    :1;                   /*!< reset flag */
  uint32_t SEL                                    :1;                   /*!< reset flag */
  uint32_t IEL                                    :1;                   /*!< reset flag */
  uint32_t UTO                                    :1;                   /*!< reset flag */
  uint32_t Reserved0                              :20;                  /*!< Reserved */
} _QEP_QCLR_bits;

/* Bit field positions: */
#define QEP_QCLR_INT_Pos                                    0           /*!< reset flag */
#define QEP_QCLR_PCE_Pos                                    1           /*!< reset flag */
#define QEP_QCLR_QPE_Pos                                    2           /*!< reset flag */
#define QEP_QCLR_QDC_Pos                                    3           /*!< reset flag */
#define QEP_QCLR_WTO_Pos                                    4           /*!< reset flag */
#define QEP_QCLR_PCU_Pos                                    5           /*!< reset flag */
#define QEP_QCLR_PCO_Pos                                    6           /*!< reset flag */
#define QEP_QCLR_PCR_Pos                                    7           /*!< reset flag */
#define QEP_QCLR_PCM_Pos                                    8           /*!< reset flag */
#define QEP_QCLR_SEL_Pos                                    9           /*!< reset flag */
#define QEP_QCLR_IEL_Pos                                    10          /*!< reset flag */
#define QEP_QCLR_UTO_Pos                                    11          /*!< reset flag */

/* Bit field masks: */
#define QEP_QCLR_INT_Msk                                    0x00000001  /*!< reset flag */
#define QEP_QCLR_PCE_Msk                                    0x00000002  /*!< reset flag */
#define QEP_QCLR_QPE_Msk                                    0x00000004  /*!< reset flag */
#define QEP_QCLR_QDC_Msk                                    0x00000008  /*!< reset flag */
#define QEP_QCLR_WTO_Msk                                    0x00000010  /*!< reset flag */
#define QEP_QCLR_PCU_Msk                                    0x00000020  /*!< reset flag */
#define QEP_QCLR_PCO_Msk                                    0x00000040  /*!< reset flag */
#define QEP_QCLR_PCR_Msk                                    0x00000080  /*!< reset flag */
#define QEP_QCLR_PCM_Msk                                    0x00000100  /*!< reset flag */
#define QEP_QCLR_SEL_Msk                                    0x00000200  /*!< reset flag */
#define QEP_QCLR_IEL_Msk                                    0x00000400  /*!< reset flag */
#define QEP_QCLR_UTO_Msk                                    0x00000800  /*!< reset flag */

/*-- QFRC: Emulation interrupt -----------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t PCE                                    :1;                   /*!< enable flag */
  uint32_t QPE                                    :1;                   /*!< enable flag */
  uint32_t QDC                                    :1;                   /*!< enable flag */
  uint32_t WTO                                    :1;                   /*!< enable flag */
  uint32_t PCU                                    :1;                   /*!< enable flag */
  uint32_t PCO                                    :1;                   /*!< enable flag */
  uint32_t PCR                                    :1;                   /*!< enable flag */
  uint32_t PCM                                    :1;                   /*!< enable flag */
  uint32_t SEL                                    :1;                   /*!< enable flag */
  uint32_t IEL                                    :1;                   /*!< enable flag */
  uint32_t UTO                                    :1;                   /*!< enable flag */
  uint32_t Reserved1                              :20;                  /*!< Reserved */
} _QEP_QFRC_bits;

/* Bit field positions: */
#define QEP_QFRC_PCE_Pos                                    1           /*!< enable flag */
#define QEP_QFRC_QPE_Pos                                    2           /*!< enable flag */
#define QEP_QFRC_QDC_Pos                                    3           /*!< enable flag */
#define QEP_QFRC_WTO_Pos                                    4           /*!< enable flag */
#define QEP_QFRC_PCU_Pos                                    5           /*!< enable flag */
#define QEP_QFRC_PCO_Pos                                    6           /*!< enable flag */
#define QEP_QFRC_PCR_Pos                                    7           /*!< enable flag */
#define QEP_QFRC_PCM_Pos                                    8           /*!< enable flag */
#define QEP_QFRC_SEL_Pos                                    9           /*!< enable flag */
#define QEP_QFRC_IEL_Pos                                    10          /*!< enable flag */
#define QEP_QFRC_UTO_Pos                                    11          /*!< enable flag */

/* Bit field masks: */
#define QEP_QFRC_PCE_Msk                                    0x00000002  /*!< enable flag */
#define QEP_QFRC_QPE_Msk                                    0x00000004  /*!< enable flag */
#define QEP_QFRC_QDC_Msk                                    0x00000008  /*!< enable flag */
#define QEP_QFRC_WTO_Msk                                    0x00000010  /*!< enable flag */
#define QEP_QFRC_PCU_Msk                                    0x00000020  /*!< enable flag */
#define QEP_QFRC_PCO_Msk                                    0x00000040  /*!< enable flag */
#define QEP_QFRC_PCR_Msk                                    0x00000080  /*!< enable flag */
#define QEP_QFRC_PCM_Msk                                    0x00000100  /*!< enable flag */
#define QEP_QFRC_SEL_Msk                                    0x00000200  /*!< enable flag */
#define QEP_QFRC_IEL_Msk                                    0x00000400  /*!< enable flag */
#define QEP_QFRC_UTO_Msk                                    0x00000800  /*!< enable flag */

/*-- QEPSTS: Status interrupt ------------------------------------------------*/

typedef struct {
  uint32_t PCEF                                   :1;                   /*!< error position flag */
  uint32_t FIMF                                   :1;                   /*!< receiving impulse */
  uint32_t CDEF                                   :1;                   /*!< change rotation */
  uint32_t COEF                                   :1;                   /*!< Flag Counter Overflow quadrature */
  uint32_t QDLF                                   :1;                   /*!< rotation of the rotor shaft */
  uint32_t QDF                                    :1;                   /*!< rotation of the rotor shaft */
  uint32_t FIDF                                   :1;                   /*!< rotation of the rotor shaft */
  uint32_t UPEVNT                                 :1;                   /*!< Flag timer time samples */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _QEP_QEPSTS_bits;

/* Bit field positions: */
#define QEP_QEPSTS_PCEF_Pos                                 0           /*!< error position flag */
#define QEP_QEPSTS_FIMF_Pos                                 1           /*!< receiving impulse */
#define QEP_QEPSTS_CDEF_Pos                                 2           /*!< change rotation */
#define QEP_QEPSTS_COEF_Pos                                 3           /*!< Flag Counter Overflow quadrature */
#define QEP_QEPSTS_QDLF_Pos                                 4           /*!< rotation of the rotor shaft */
#define QEP_QEPSTS_QDF_Pos                                  5           /*!< rotation of the rotor shaft */
#define QEP_QEPSTS_FIDF_Pos                                 6           /*!< rotation of the rotor shaft */
#define QEP_QEPSTS_UPEVNT_Pos                               7           /*!< Flag timer time samples */

/* Bit field masks: */
#define QEP_QEPSTS_PCEF_Msk                                 0x00000001  /*!< error position flag */
#define QEP_QEPSTS_FIMF_Msk                                 0x00000002  /*!< receiving impulse */
#define QEP_QEPSTS_CDEF_Msk                                 0x00000004  /*!< change rotation */
#define QEP_QEPSTS_COEF_Msk                                 0x00000008  /*!< Flag Counter Overflow quadrature */
#define QEP_QEPSTS_QDLF_Msk                                 0x00000010  /*!< rotation of the rotor shaft */
#define QEP_QEPSTS_QDF_Msk                                  0x00000020  /*!< rotation of the rotor shaft */
#define QEP_QEPSTS_FIDF_Msk                                 0x00000040  /*!< rotation of the rotor shaft */
#define QEP_QEPSTS_UPEVNT_Msk                               0x00000080  /*!< Flag timer time samples */

/*-- INTCLR: Clear interrupt register ----------------------------------------*/

typedef struct {
  uint32_t INT                                    :1;                   /*!< Active interrupt by read, write 1 to clear interrupt */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _QEP_INTCLR_bits;

/* Bit field positions: */
#define QEP_INTCLR_INT_Pos                                  0           /*!< Active interrupt by read, write 1 to clear interrupt */

/* Bit field masks: */
#define QEP_INTCLR_INT_Msk                                  0x00000001  /*!< Active interrupt by read, write 1 to clear interrupt */

/*-- Register map for QEP peripheral -----------------------------------------*/

typedef struct {
  __IO uint32_t QPOSCNT;                                                /*!< Position count register */
  __IO uint32_t QPOSINIT;                                               /*!< Shadow count register */
  __IO uint32_t QPOSMAX;                                                /*!< Period register */
  __IO uint32_t QPOSCMP;                                                /*!< Count compare position reg */
  __I  uint32_t QPOSILAT;                                               /*!< Register meaning count position */
  __I  uint32_t QPOSSLAT;                                               /*!< Strobe register */
  __I  uint32_t QPOSLAT;                                                /*!< Time event register */
  __IO uint32_t QUTMR;                                                  /*!< Time reading timer register */
  __IO uint32_t QUPRD;                                                  /*!< Period time reading timer register */
  __IO uint32_t QWDTMR;                                                 /*!< Watchdog timer register */
  __IO uint32_t QWDPRD;                                                 /*!< Period watchdog timer register */
  union {                                                               /*!< Input control register */
    __IO uint32_t QDECCTL;                                              /*!< QDECCTL    : type used for word access */
    __IO _QEP_QDECCTL_bits QDECCTL_bit;                                 /*!< QDECCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Quadrature decoder control register */
    __IO uint32_t QEPCTL;                                               /*!< QEPCTL    : type used for word access */
    __IO _QEP_QEPCTL_bits QEPCTL_bit;                                   /*!< QEPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture register */
    __IO uint32_t QCAPCTL;                                              /*!< QCAPCTL    : type used for word access */
    __IO _QEP_QCAPCTL_bits QCAPCTL_bit;                                 /*!< QCAPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Register countposition control */
    __IO uint32_t QPOSCTL;                                              /*!< QPOSCTL    : type used for word access */
    __IO _QEP_QPOSCTL_bits QPOSCTL_bit;                                 /*!< QPOSCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask */
    __IO uint32_t QEINT;                                                /*!< QEINT    : type used for word access */
    __IO _QEP_QEINT_bits QEINT_bit;                                     /*!< QEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Flag interrupt */
    __I  uint32_t QFLG;                                                 /*!< QFLG    : type used for word access */
    __I  _QEP_QFLG_bits QFLG_bit;                                       /*!< QFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Reset interrupt */
    __IO uint32_t QCLR;                                                 /*!< QCLR    : type used for word access */
    __IO _QEP_QCLR_bits QCLR_bit;                                       /*!< QCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Emulation interrupt */
    __IO uint32_t QFRC;                                                 /*!< QFRC    : type used for word access */
    __IO _QEP_QFRC_bits QFRC_bit;                                       /*!< QFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status interrupt */
    __IO uint32_t QEPSTS;                                               /*!< QEPSTS    : type used for word access */
    __IO _QEP_QEPSTS_bits QEPSTS_bit;                                   /*!< QEPSTS_bit: structure used for bit access */
  };
  __IO uint32_t QCTMR;                                                  /*!< Timer register */
  __IO uint32_t QCPRD;                                                  /*!< Period register */
  __I  uint32_t QCTMRLAT;                                               /*!< Register Storage Timer */
  __IO uint32_t QCPRDLAT;                                               /*!< Register Storage Period */
  uint32_t Reserved0[4];                                                /*!< Reserved */
  union {                                                               /*!< Clear interrupt register */
    __IO uint32_t INTCLR;                                               /*!< INTCLR    : type used for word access */
    __IO _QEP_INTCLR_bits INTCLR_bit;                                   /*!< INTCLR_bit: structure used for bit access */
  };
} NT_QEP_TypeDef;

/******************************************************************************/
/*                      BOOTFLASH controller registers                        */
/******************************************************************************/

/*-- FMA: Address bootflash register -----------------------------------------*/

typedef struct {
  uint32_t ADDR                                   :20;                  /*!< Address for commands write and page erase */
  uint32_t Reserved0                              :12;                  /*!< Reserved */
} _BOOTFLASH_FMA_bits;

/* Bit field positions: */
#define BOOTFLASH_FMA_ADDR_Pos                              0           /*!< Address for commands write and page erase */

/* Bit field masks: */
#define BOOTFLASH_FMA_ADDR_Msk                              0x000FFFFF  /*!< Address for commands write and page erase */

/*-- FMC: Command register ---------------------------------------------------*/

typedef struct {
  uint32_t WRITE                                  :1;                   /*!< Bit writing in main block */
  uint32_t PAGE_ERASE                             :1;                   /*!< Bit paged erase the main block */
  uint32_t FULL_ERASE                             :1;                   /*!< Bit erase main block */
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t WRITE_IFB                              :1;                   /*!< Bit writing on information block */
  uint32_t PAGEERASE_IFB                          :1;                   /*!< Bit erase page of information block */
  uint32_t Reserved1                              :10;                  /*!< Reserved */
  uint32_t MAGIC_KEY                              :16;                  /*!< Code run command. For activate command in MAGIC_KEY write 0xA442 */
} _BOOTFLASH_FMC_bits;

/* Bit field positions: */
#define BOOTFLASH_FMC_WRITE_Pos                             0           /*!< Bit writing in main block */
#define BOOTFLASH_FMC_PAGE_ERASE_Pos                        1           /*!< Bit paged erase the main block */
#define BOOTFLASH_FMC_FULL_ERASE_Pos                        2           /*!< Bit erase main block */
#define BOOTFLASH_FMC_WRITE_IFB_Pos                         4           /*!< Bit writing on information block */
#define BOOTFLASH_FMC_PAGEERASE_IFB_Pos                     5           /*!< Bit erase page of information block */
#define BOOTFLASH_FMC_MAGIC_KEY_Pos                         16          /*!< Code run command. For activate command in MAGIC_KEY write 0xA442 */

/* Bit field masks: */
#define BOOTFLASH_FMC_WRITE_Msk                             0x00000001  /*!< Bit writing in main block */
#define BOOTFLASH_FMC_PAGE_ERASE_Msk                        0x00000002  /*!< Bit paged erase the main block */
#define BOOTFLASH_FMC_FULL_ERASE_Msk                        0x00000004  /*!< Bit erase main block */
#define BOOTFLASH_FMC_WRITE_IFB_Msk                         0x00000010  /*!< Bit writing on information block */
#define BOOTFLASH_FMC_PAGEERASE_IFB_Msk                     0x00000020  /*!< Bit erase page of information block */
#define BOOTFLASH_FMC_MAGIC_KEY_Msk                         0xFFFF0000  /*!< Code run command. For activate command in MAGIC_KEY write 0xA442 */

/*-- FCIS: Status register ---------------------------------------------------*/

typedef struct {
  uint32_t OP_CMLT                                :1;                   /*!< Completion flag operation */
  uint32_t OP_ERROR                               :1;                   /*!< Flag write error, erase block write-protected or non-existent, or read from a non-existent block */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _BOOTFLASH_FCIS_bits;

/* Bit field positions: */
#define BOOTFLASH_FCIS_OP_CMLT_Pos                          0           /*!< Completion flag operation */
#define BOOTFLASH_FCIS_OP_ERROR_Pos                         1           /*!< Flag write error, erase block write-protected or non-existent, or read from a non-existent block */

/* Bit field masks: */
#define BOOTFLASH_FCIS_OP_CMLT_Msk                          0x00000001  /*!< Completion flag operation */
#define BOOTFLASH_FCIS_OP_ERROR_Msk                         0x00000002  /*!< Flag write error, erase block write-protected or non-existent, or read from a non-existent block */

/*-- FCIM: Interrupt mask register -------------------------------------------*/

typedef struct {
  uint32_t MASK_OPCMLT                            :1;                   /*!< Enables generation of an interrupt upon completion of a read or write, or erase */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _BOOTFLASH_FCIM_bits;

/* Bit field positions: */
#define BOOTFLASH_FCIM_MASK_OPCMLT_Pos                      0           /*!< Enables generation of an interrupt upon completion of a read or write, or erase */

/* Bit field masks: */
#define BOOTFLASH_FCIM_MASK_OPCMLT_Msk                      0x00000001  /*!< Enables generation of an interrupt upon completion of a read or write, or erase */

/*-- FCIC: Command register --------------------------------------------------*/

typedef struct {
  uint32_t CLR_OPCMLT                             :1;                   /*!< Clear flag operate complit */
  uint32_t CLR_OPERROR                            :1;                   /*!< Clear flag operate Error */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _BOOTFLASH_FCIC_bits;

/* Bit field positions: */
#define BOOTFLASH_FCIC_CLR_OPCMLT_Pos                       0           /*!< Clear flag operate complit */
#define BOOTFLASH_FCIC_CLR_OPERROR_Pos                      1           /*!< Clear flag operate Error */

/* Bit field masks: */
#define BOOTFLASH_FCIC_CLR_OPCMLT_Msk                       0x00000001  /*!< Clear flag operate complit */
#define BOOTFLASH_FCIC_CLR_OPERROR_Msk                      0x00000002  /*!< Clear flag operate Error */

/*-- Register map for BOOTFLASH peripheral -----------------------------------*/

typedef struct {
  union {                                                               /*!< Address bootflash register */
    __IO uint32_t FMA;                                                  /*!< FMA    : type used for word access */
    __IO _BOOTFLASH_FMA_bits FMA_bit;                                   /*!< FMA_bit: structure used for bit access */
  };
  __IO uint32_t FMD0;                                                   /*!< Data words bootable flash register 0 */
  union {                                                               /*!< Command register */
    __O  uint32_t FMC;                                                  /*!< FMC    : type used for word access */
    __O  _BOOTFLASH_FMC_bits FMC_bit;                                   /*!< FMC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __I  uint32_t FCIS;                                                 /*!< FCIS    : type used for word access */
    __I  _BOOTFLASH_FCIS_bits FCIS_bit;                                 /*!< FCIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t FCIM;                                                 /*!< FCIM    : type used for word access */
    __IO _BOOTFLASH_FCIM_bits FCIM_bit;                                 /*!< FCIM_bit: structure used for bit access */
  };
  union {                                                               /*!< Command register */
    __O  uint32_t FCIC;                                                 /*!< FCIC    : type used for word access */
    __O  _BOOTFLASH_FCIC_bits FCIC_bit;                                 /*!< FCIC_bit: structure used for bit access */
  };
  uint32_t Reserved0[14];                                               /*!< Reserved */
  __IO uint32_t FMD1;                                                   /*!< Data words bootable flash register 1 */
  __IO uint32_t FMD2;                                                   /*!< Data words bootable flash register 2 */
  __IO uint32_t FMD3;                                                   /*!< Data words bootable flash register 3 */
  uint32_t Reserved1[9];                                                /*!< Reserved */
  __IO uint32_t T_ACC;                                                  /*!< Register the delay of setting addresses to read data from the flash memory */
  __IO uint32_t T_NVS;                                                  /*!< Register signal delay lifting NVSTR after lifting signal PROG */
  __IO uint32_t T_NVH;                                                  /*!< Register sets the release delay signal NVSTR after releasing signal PROG */
  __IO uint32_t T_RCV;                                                  /*!< Register delay from releasing signal NVSTR to raise it to the next transaction */
  __IO uint32_t T_PGS;                                                  /*!< Register delay lifting signal YE after lifting signal NVSTR */
  __IO uint32_t T_PROG;                                                 /*!< Register YE signal duration in recording transactions */
  __IO uint32_t T_PGH;                                                  /*!< Register delay signal NVSTR after releasing signal YE */
  __IO uint32_t T_ERASE;                                                /*!< Register duration of the signal in transactions ERASE erasure */
  __IO uint32_t T_ME;                                                   /*!< Register specifies the duration of the signal in transactions ERASE erasure */
  __IO uint32_t T_NVH1;                                                 /*!< Register specifies the duration of the signal in transactions ERASE erasure */
} NT_BOOTFLASH_TypeDef;

/******************************************************************************/
/*                         CMP controller registers                           */
/******************************************************************************/

/*-- MIS: Masked interrupt status register -----------------------------------*/

typedef struct {
  uint32_t IN0                                    :1;                   /*!< reset interrupt status CMP0 */
  uint32_t IN1                                    :1;                   /*!< reset interrupt status CMP1 */
  uint32_t IN2                                    :1;                   /*!< reset interrupt status CMP2 */
  uint32_t Reserved0                              :13;                  /*!< Reserved */
  uint32_t INT0                                   :1;                   /*!< reset get interrupt CMP0 */
  uint32_t INT1                                   :1;                   /*!< reset get interrupt CMP1 */
  uint32_t INT2                                   :1;                   /*!< reset get interrupt CMP2 */
  uint32_t Reserved1                              :13;                  /*!< Reserved */
} _CMP_MIS_bits;

/* Bit field positions: */
#define CMP_MIS_IN0_Pos                                     0           /*!< reset interrupt status CMP0 */
#define CMP_MIS_IN1_Pos                                     1           /*!< reset interrupt status CMP1 */
#define CMP_MIS_IN2_Pos                                     2           /*!< reset interrupt status CMP2 */
#define CMP_MIS_INT0_Pos                                    16          /*!< reset get interrupt CMP0 */
#define CMP_MIS_INT1_Pos                                    17          /*!< reset get interrupt CMP1 */
#define CMP_MIS_INT2_Pos                                    18          /*!< reset get interrupt CMP2 */

/* Bit field masks: */
#define CMP_MIS_IN0_Msk                                     0x00000001  /*!< reset interrupt status CMP0 */
#define CMP_MIS_IN1_Msk                                     0x00000002  /*!< reset interrupt status CMP1 */
#define CMP_MIS_IN2_Msk                                     0x00000004  /*!< reset interrupt status CMP2 */
#define CMP_MIS_INT0_Msk                                    0x00010000  /*!< reset get interrupt CMP0 */
#define CMP_MIS_INT1_Msk                                    0x00020000  /*!< reset get interrupt CMP1 */
#define CMP_MIS_INT2_Msk                                    0x00040000  /*!< reset get interrupt CMP2 */

/*-- RIS: Interrupt Status Register ------------------------------------------*/

typedef struct {
  uint32_t IN0                                    :1;                   /*!< set interrupt status CMP0 */
  uint32_t IN1                                    :1;                   /*!< set interrupt status CMP1 */
  uint32_t IN2                                    :1;                   /*!< set interrupt status CMP2 */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _CMP_RIS_bits;

/* Bit field positions: */
#define CMP_RIS_IN0_Pos                                     0           /*!< set interrupt status CMP0 */
#define CMP_RIS_IN1_Pos                                     1           /*!< set interrupt status CMP1 */
#define CMP_RIS_IN2_Pos                                     2           /*!< set interrupt status CMP2 */

/* Bit field masks: */
#define CMP_RIS_IN0_Msk                                     0x00000001  /*!< set interrupt status CMP0 */
#define CMP_RIS_IN1_Msk                                     0x00000002  /*!< set interrupt status CMP1 */
#define CMP_RIS_IN2_Msk                                     0x00000004  /*!< set interrupt status CMP2 */

/*-- INTEN: Interrupt mask register ------------------------------------------*/

typedef struct {
  uint32_t IN0                                    :1;                   /*!< Mask interrupt CMP0 */
  uint32_t IN1                                    :1;                   /*!< Mask interrupt CMP1 */
  uint32_t IN2                                    :1;                   /*!< Mask interrupt CMP2 */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _CMP_INTEN_bits;

/* Bit field positions: */
#define CMP_INTEN_IN0_Pos                                   0           /*!< Mask interrupt CMP0 */
#define CMP_INTEN_IN1_Pos                                   1           /*!< Mask interrupt CMP1 */
#define CMP_INTEN_IN2_Pos                                   2           /*!< Mask interrupt CMP2 */

/* Bit field masks: */
#define CMP_INTEN_IN0_Msk                                   0x00000001  /*!< Mask interrupt CMP0 */
#define CMP_INTEN_IN1_Msk                                   0x00000002  /*!< Mask interrupt CMP1 */
#define CMP_INTEN_IN2_Msk                                   0x00000004  /*!< Mask interrupt CMP2 */

/*-- REFCTL0: Reference voltage control DAC0 register ------------------------*/

typedef struct {
  uint32_t VREF                                   :4;                   /*!< reference voltage */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t RNG                                    :1;                   /*!< range of the DAC */
  uint32_t EN                                     :1;                   /*!< power to the built-in DAC */
  uint32_t Reserved1                              :22;                  /*!< Reserved */
} _CMP_REFCTL0_bits;

/* Bit field positions: */
#define CMP_REFCTL0_VREF_Pos                                0           /*!< reference voltage */
#define CMP_REFCTL0_RNG_Pos                                 8           /*!< range of the DAC */
#define CMP_REFCTL0_EN_Pos                                  9           /*!< power to the built-in DAC */

/* Bit field masks: */
#define CMP_REFCTL0_VREF_Msk                                0x0000000F  /*!< reference voltage */
#define CMP_REFCTL0_RNG_Msk                                 0x00000100  /*!< range of the DAC */
#define CMP_REFCTL0_EN_Msk                                  0x00000200  /*!< power to the built-in DAC */

/*-- REFCTL1: Reference voltage control DAC1 register ------------------------*/

typedef struct {
  uint32_t VREF                                   :4;                   /*!< reference voltage */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t RNG                                    :1;                   /*!< range of the DAC */
  uint32_t EN                                     :1;                   /*!< power to the built-in DAC */
  uint32_t Reserved1                              :22;                  /*!< Reserved */
} _CMP_REFCTL1_bits;

/* Bit field positions: */
#define CMP_REFCTL1_VREF_Pos                                0           /*!< reference voltage */
#define CMP_REFCTL1_RNG_Pos                                 8           /*!< range of the DAC */
#define CMP_REFCTL1_EN_Pos                                  9           /*!< power to the built-in DAC */

/* Bit field masks: */
#define CMP_REFCTL1_VREF_Msk                                0x0000000F  /*!< reference voltage */
#define CMP_REFCTL1_RNG_Msk                                 0x00000100  /*!< range of the DAC */
#define CMP_REFCTL1_EN_Msk                                  0x00000200  /*!< power to the built-in DAC */

/*-- REFCTL2: Reference voltage control DAC2 register ------------------------*/

typedef struct {
  uint32_t VREF                                   :4;                   /*!< reference voltage */
  uint32_t Reserved0                              :4;                   /*!< Reserved */
  uint32_t RNG                                    :1;                   /*!< range of the DAC */
  uint32_t EN                                     :1;                   /*!< power to the built-in DAC */
  uint32_t Reserved1                              :22;                  /*!< Reserved */
} _CMP_REFCTL2_bits;

/* Bit field positions: */
#define CMP_REFCTL2_VREF_Pos                                0           /*!< reference voltage */
#define CMP_REFCTL2_RNG_Pos                                 8           /*!< range of the DAC */
#define CMP_REFCTL2_EN_Pos                                  9           /*!< power to the built-in DAC */

/* Bit field masks: */
#define CMP_REFCTL2_VREF_Msk                                0x0000000F  /*!< reference voltage */
#define CMP_REFCTL2_RNG_Msk                                 0x00000100  /*!< range of the DAC */
#define CMP_REFCTL2_EN_Msk                                  0x00000200  /*!< power to the built-in DAC */

/*-- STAT0: Status register CMP0 ---------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t OVAL                                   :1;                   /*!< output value of the comparator0 */
  uint32_t Reserved1                              :30;                  /*!< Reserved */
} _CMP_STAT0_bits;

/* Bit field positions: */
#define CMP_STAT0_OVAL_Pos                                  1           /*!< output value of the comparator0 */

/* Bit field masks: */
#define CMP_STAT0_OVAL_Msk                                  0x00000002  /*!< output value of the comparator0 */

/*-- CTL0: Control Register CMP0 ---------------------------------------------*/

typedef struct {
  uint32_t CEN                                    :1;                   /*!< enable compare 0 */
  uint32_t CINV                                   :1;                   /*!< polarity of output signal */
  uint32_t ISEN                                   :2;                   /*!< Event interrupt */
  uint32_t ISVAL                                  :1;                   /*!< interrupt on a low level */
  uint32_t TSEN                                   :2;                   /*!< ADC trigger event */
  uint32_t TSVAL                                  :1;                   /*!< ADC start at a low level */
  uint32_t ASRCP                                  :2;                   /*!< source to VIN + */
  uint32_t TOEN                                   :1;                   /*!< ADC start generating events */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _CMP_CTL0_bits;

/* Bit field positions: */
#define CMP_CTL0_CEN_Pos                                    0           /*!< enable compare 0 */
#define CMP_CTL0_CINV_Pos                                   1           /*!< polarity of output signal */
#define CMP_CTL0_ISEN_Pos                                   2           /*!< Event interrupt */
#define CMP_CTL0_ISVAL_Pos                                  4           /*!< interrupt on a low level */
#define CMP_CTL0_TSEN_Pos                                   5           /*!< ADC trigger event */
#define CMP_CTL0_TSVAL_Pos                                  7           /*!< ADC start at a low level */
#define CMP_CTL0_ASRCP_Pos                                  8           /*!< source to VIN + */
#define CMP_CTL0_TOEN_Pos                                   10          /*!< ADC start generating events */

/* Bit field masks: */
#define CMP_CTL0_CEN_Msk                                    0x00000001  /*!< enable compare 0 */
#define CMP_CTL0_CINV_Msk                                   0x00000002  /*!< polarity of output signal */
#define CMP_CTL0_ISEN_Msk                                   0x0000000C  /*!< Event interrupt */
#define CMP_CTL0_ISVAL_Msk                                  0x00000010  /*!< interrupt on a low level */
#define CMP_CTL0_TSEN_Msk                                   0x00000060  /*!< ADC trigger event */
#define CMP_CTL0_TSVAL_Msk                                  0x00000080  /*!< ADC start at a low level */
#define CMP_CTL0_ASRCP_Msk                                  0x00000300  /*!< source to VIN + */
#define CMP_CTL0_TOEN_Msk                                   0x00000400  /*!< ADC start generating events */

/*-- STAT1: Status register CMP1 ---------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t OVAL                                   :1;                   /*!< output value of the comparator1 */
  uint32_t Reserved1                              :30;                  /*!< Reserved */
} _CMP_STAT1_bits;

/* Bit field positions: */
#define CMP_STAT1_OVAL_Pos                                  1           /*!< output value of the comparator1 */

/* Bit field masks: */
#define CMP_STAT1_OVAL_Msk                                  0x00000002  /*!< output value of the comparator1 */

/*-- CTL1: Control Register CMP1 ---------------------------------------------*/

typedef struct {
  uint32_t CEN                                    :1;                   /*!< enable compare 1 */
  uint32_t CINV                                   :1;                   /*!< polarity of output signal */
  uint32_t ISEN                                   :2;                   /*!< Event interrupt */
  uint32_t ISVAL                                  :1;                   /*!< interrupt on a low level */
  uint32_t TSEN                                   :2;                   /*!< ADC trigger event */
  uint32_t TSVAL                                  :1;                   /*!< ADC start at a low level */
  uint32_t ASRCP                                  :2;                   /*!< source to VIN + */
  uint32_t TOEN                                   :1;                   /*!< ADC start generating events */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _CMP_CTL1_bits;

/* Bit field positions: */
#define CMP_CTL1_CEN_Pos                                    0           /*!< enable compare 1 */
#define CMP_CTL1_CINV_Pos                                   1           /*!< polarity of output signal */
#define CMP_CTL1_ISEN_Pos                                   2           /*!< Event interrupt */
#define CMP_CTL1_ISVAL_Pos                                  4           /*!< interrupt on a low level */
#define CMP_CTL1_TSEN_Pos                                   5           /*!< ADC trigger event */
#define CMP_CTL1_TSVAL_Pos                                  7           /*!< ADC start at a low level */
#define CMP_CTL1_ASRCP_Pos                                  8           /*!< source to VIN + */
#define CMP_CTL1_TOEN_Pos                                   10          /*!< ADC start generating events */

/* Bit field masks: */
#define CMP_CTL1_CEN_Msk                                    0x00000001  /*!< enable compare 1 */
#define CMP_CTL1_CINV_Msk                                   0x00000002  /*!< polarity of output signal */
#define CMP_CTL1_ISEN_Msk                                   0x0000000C  /*!< Event interrupt */
#define CMP_CTL1_ISVAL_Msk                                  0x00000010  /*!< interrupt on a low level */
#define CMP_CTL1_TSEN_Msk                                   0x00000060  /*!< ADC trigger event */
#define CMP_CTL1_TSVAL_Msk                                  0x00000080  /*!< ADC start at a low level */
#define CMP_CTL1_ASRCP_Msk                                  0x00000300  /*!< source to VIN + */
#define CMP_CTL1_TOEN_Msk                                   0x00000400  /*!< ADC start generating events */

/*-- STAT2: Status register CMP2 ---------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t OVAL                                   :1;                   /*!< output value of the comparator2 */
  uint32_t Reserved1                              :30;                  /*!< Reserved */
} _CMP_STAT2_bits;

/* Bit field positions: */
#define CMP_STAT2_OVAL_Pos                                  1           /*!< output value of the comparator2 */

/* Bit field masks: */
#define CMP_STAT2_OVAL_Msk                                  0x00000002  /*!< output value of the comparator2 */

/*-- CTL2: Control Register CMP2 ---------------------------------------------*/

typedef struct {
  uint32_t CEN                                    :1;                   /*!< enable compare 2 */
  uint32_t CINV                                   :1;                   /*!< polarity of output signal */
  uint32_t ISEN                                   :2;                   /*!< Event interrupt */
  uint32_t ISVAL                                  :1;                   /*!< interrupt on a low level */
  uint32_t TSEN                                   :2;                   /*!< ADC trigger event */
  uint32_t TSVAL                                  :1;                   /*!< ADC start at a low level */
  uint32_t ASRCP                                  :2;                   /*!< source to VIN + */
  uint32_t TOEN                                   :1;                   /*!< ADC start generating events */
  uint32_t Reserved0                              :21;                  /*!< Reserved */
} _CMP_CTL2_bits;

/* Bit field positions: */
#define CMP_CTL2_CEN_Pos                                    0           /*!< enable compare 2 */
#define CMP_CTL2_CINV_Pos                                   1           /*!< polarity of output signal */
#define CMP_CTL2_ISEN_Pos                                   2           /*!< Event interrupt */
#define CMP_CTL2_ISVAL_Pos                                  4           /*!< interrupt on a low level */
#define CMP_CTL2_TSEN_Pos                                   5           /*!< ADC trigger event */
#define CMP_CTL2_TSVAL_Pos                                  7           /*!< ADC start at a low level */
#define CMP_CTL2_ASRCP_Pos                                  8           /*!< source to VIN + */
#define CMP_CTL2_TOEN_Pos                                   10          /*!< ADC start generating events */

/* Bit field masks: */
#define CMP_CTL2_CEN_Msk                                    0x00000001  /*!< enable compare 2 */
#define CMP_CTL2_CINV_Msk                                   0x00000002  /*!< polarity of output signal */
#define CMP_CTL2_ISEN_Msk                                   0x0000000C  /*!< Event interrupt */
#define CMP_CTL2_ISVAL_Msk                                  0x00000010  /*!< interrupt on a low level */
#define CMP_CTL2_TSEN_Msk                                   0x00000060  /*!< ADC trigger event */
#define CMP_CTL2_TSVAL_Msk                                  0x00000080  /*!< ADC start at a low level */
#define CMP_CTL2_ASRCP_Msk                                  0x00000300  /*!< source to VIN + */
#define CMP_CTL2_TOEN_Msk                                   0x00000400  /*!< ADC start generating events */

/*-- POWER: Power analog circuits register -----------------------------------*/

typedef struct {
  uint32_t PWU                                    :1;                   /*!< Enable power analog circuits */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _CMP_POWER_bits;

/* Bit field positions: */
#define CMP_POWER_PWU_Pos                                   0           /*!< Enable power analog circuits */

/* Bit field masks: */
#define CMP_POWER_PWU_Msk                                   0x00000001  /*!< Enable power analog circuits */

/*-- Register map for CMP peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Masked interrupt status register */
    __IO uint32_t MIS;                                                  /*!< MIS    : type used for word access */
    __IO _CMP_MIS_bits MIS_bit;                                         /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Status Register */
    __I  uint32_t RIS;                                                  /*!< RIS    : type used for word access */
    __I  _CMP_RIS_bits RIS_bit;                                         /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t INTEN;                                                /*!< INTEN    : type used for word access */
    __IO _CMP_INTEN_bits INTEN_bit;                                     /*!< INTEN_bit: structure used for bit access */
  };
  union {                                                               /*!< Reference voltage control DAC0 register */
    __IO uint32_t REFCTL0;                                              /*!< REFCTL0    : type used for word access */
    __IO _CMP_REFCTL0_bits REFCTL0_bit;                                 /*!< REFCTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Reference voltage control DAC1 register */
    __IO uint32_t REFCTL1;                                              /*!< REFCTL1    : type used for word access */
    __IO _CMP_REFCTL1_bits REFCTL1_bit;                                 /*!< REFCTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Reference voltage control DAC2 register */
    __IO uint32_t REFCTL2;                                              /*!< REFCTL2    : type used for word access */
    __IO _CMP_REFCTL2_bits REFCTL2_bit;                                 /*!< REFCTL2_bit: structure used for bit access */
  };
  uint32_t Reserved0[2];                                                /*!< Reserved */
  union {                                                               /*!< Status register CMP0 */
    __I  uint32_t STAT0;                                                /*!< STAT0    : type used for word access */
    __I  _CMP_STAT0_bits STAT0_bit;                                     /*!< STAT0_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register CMP0 */
    __IO uint32_t CTL0;                                                 /*!< CTL0    : type used for word access */
    __IO _CMP_CTL0_bits CTL0_bit;                                       /*!< CTL0_bit: structure used for bit access */
  };
  uint32_t Reserved1[6];                                                /*!< Reserved */
  union {                                                               /*!< Status register CMP1 */
    __I  uint32_t STAT1;                                                /*!< STAT1    : type used for word access */
    __I  _CMP_STAT1_bits STAT1_bit;                                     /*!< STAT1_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register CMP1 */
    __IO uint32_t CTL1;                                                 /*!< CTL1    : type used for word access */
    __IO _CMP_CTL1_bits CTL1_bit;                                       /*!< CTL1_bit: structure used for bit access */
  };
  uint32_t Reserved2[6];                                                /*!< Reserved */
  union {                                                               /*!< Status register CMP2 */
    __I  uint32_t STAT2;                                                /*!< STAT2    : type used for word access */
    __I  _CMP_STAT2_bits STAT2_bit;                                     /*!< STAT2_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register CMP2 */
    __IO uint32_t CTL2;                                                 /*!< CTL2    : type used for word access */
    __IO _CMP_CTL2_bits CTL2_bit;                                       /*!< CTL2_bit: structure used for bit access */
  };
  uint32_t Reserved3[5];                                                /*!< Reserved */
  union {                                                               /*!< Power analog circuits register */
    __IO uint32_t POWER;                                                /*!< POWER    : type used for word access */
    __IO _CMP_POWER_bits POWER_bit;                                     /*!< POWER_bit: structure used for bit access */
  };
} NT_CMP_TypeDef;

/******************************************************************************/
/*                         SPI controller registers                           */
/******************************************************************************/

/*-- SPI_CR0: Control register 0 ---------------------------------------------*/

typedef struct {
  uint32_t DSS                                    :4;                   /*!< Size of data */
  uint32_t FRF                                    :2;                   /*!< Select protocol */
  uint32_t SPO                                    :1;                   /*!< Polarity SSPCLKOUT */
  uint32_t SPH                                    :1;                   /*!< Phase SSPCLKOUT */
  uint32_t SCR                                    :8;                   /*!< Value divider */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _SPI_SPI_CR0_bits;

/* Bit field positions: */
#define SPI_SPI_CR0_DSS_Pos                                 0           /*!< Size of data */
#define SPI_SPI_CR0_FRF_Pos                                 4           /*!< Select protocol */
#define SPI_SPI_CR0_SPO_Pos                                 6           /*!< Polarity SSPCLKOUT */
#define SPI_SPI_CR0_SPH_Pos                                 7           /*!< Phase SSPCLKOUT */
#define SPI_SPI_CR0_SCR_Pos                                 8           /*!< Value divider */

/* Bit field masks: */
#define SPI_SPI_CR0_DSS_Msk                                 0x0000000F  /*!< Size of data */
#define SPI_SPI_CR0_FRF_Msk                                 0x00000030  /*!< Select protocol */
#define SPI_SPI_CR0_SPO_Msk                                 0x00000040  /*!< Polarity SSPCLKOUT */
#define SPI_SPI_CR0_SPH_Msk                                 0x00000080  /*!< Phase SSPCLKOUT */
#define SPI_SPI_CR0_SCR_Msk                                 0x0000FF00  /*!< Value divider */

/*-- SPI_CR1: Control register 1 ---------------------------------------------*/

typedef struct {
  uint32_t Reserved0                              :1;                   /*!< Reserved */
  uint32_t SSE                                    :1;                   /*!< Enable transceiver */
  uint32_t MS                                     :1;                   /*!< Select mode */
  uint32_t SOD                                    :1;                   /*!< Disable bit data */
  uint32_t Reserved1                              :28;                  /*!< Reserved */
} _SPI_SPI_CR1_bits;

/* Bit field positions: */
#define SPI_SPI_CR1_SSE_Pos                                 1           /*!< Enable transceiver */
#define SPI_SPI_CR1_MS_Pos                                  2           /*!< Select mode */
#define SPI_SPI_CR1_SOD_Pos                                 3           /*!< Disable bit data */

/* Bit field masks: */
#define SPI_SPI_CR1_SSE_Msk                                 0x00000002  /*!< Enable transceiver */
#define SPI_SPI_CR1_MS_Msk                                  0x00000004  /*!< Select mode */
#define SPI_SPI_CR1_SOD_Msk                                 0x00000008  /*!< Disable bit data */

/*-- SPI_DR: Data register ---------------------------------------------------*/

typedef struct {
  uint32_t DATA                                   :16;
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _SPI_SPI_DR_bits;

/* Bit field positions: */
#define SPI_SPI_DR_DATA_Pos                                 0

/* Bit field masks: */
#define SPI_SPI_DR_DATA_Msk                                 0x0000FFFF

/*-- SPI_SR: State register --------------------------------------------------*/

typedef struct {
  uint32_t TFE                                    :1;                   /*!< FIFO buffer empty flag transmitter */
  uint32_t TNF                                    :1;                   /*!< Indicator the transmitter FIFO buffer is not full */
  uint32_t RNE                                    :1;                   /*!< Indicate not empty receive buffer */
  uint32_t RFF                                    :1;                   /*!< Indicate full receive buffer */
  uint32_t BSY                                    :1;                   /*!< Activity flag */
  uint32_t Reserved0                              :27;                  /*!< Reserved */
} _SPI_SPI_SR_bits;

/* Bit field positions: */
#define SPI_SPI_SR_TFE_Pos                                  0           /*!< FIFO buffer empty flag transmitter */
#define SPI_SPI_SR_TNF_Pos                                  1           /*!< Indicator the transmitter FIFO buffer is not full */
#define SPI_SPI_SR_RNE_Pos                                  2           /*!< Indicate not empty receive buffer */
#define SPI_SPI_SR_RFF_Pos                                  3           /*!< Indicate full receive buffer */
#define SPI_SPI_SR_BSY_Pos                                  4           /*!< Activity flag */

/* Bit field masks: */
#define SPI_SPI_SR_TFE_Msk                                  0x00000001  /*!< FIFO buffer empty flag transmitter */
#define SPI_SPI_SR_TNF_Msk                                  0x00000002  /*!< Indicator the transmitter FIFO buffer is not full */
#define SPI_SPI_SR_RNE_Msk                                  0x00000004  /*!< Indicate not empty receive buffer */
#define SPI_SPI_SR_RFF_Msk                                  0x00000008  /*!< Indicate full receive buffer */
#define SPI_SPI_SR_BSY_Msk                                  0x00000010  /*!< Activity flag */

/*-- SPI_CPSR: Clock division factor register --------------------------------*/

typedef struct {
  uint32_t CPSDVSR                                :8;                   /*!< Clock division factor. Bit0 always 0 */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _SPI_SPI_CPSR_bits;

/* Bit field positions: */
#define SPI_SPI_CPSR_CPSDVSR_Pos                            0           /*!< Clock division factor. Bit0 always 0 */

/* Bit field masks: */
#define SPI_SPI_CPSR_CPSDVSR_Msk                            0x000000FF  /*!< Clock division factor. Bit0 always 0 */

/*-- SPI_IMSC: Mask interrupt register ---------------------------------------*/

typedef struct {
  uint32_t RORIM                                  :1;                   /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
  uint32_t RTIM                                   :1;                   /*!< Interrupt mask bit SSPRTINTR timeout receiver */
  uint32_t RXIM                                   :1;                   /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
  uint32_t TXIM                                   :1;                   /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _SPI_SPI_IMSC_bits;

/* Bit field positions: */
#define SPI_SPI_IMSC_RORIM_Pos                              0           /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
#define SPI_SPI_IMSC_RTIM_Pos                               1           /*!< Interrupt mask bit SSPRTINTR timeout receiver */
#define SPI_SPI_IMSC_RXIM_Pos                               2           /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
#define SPI_SPI_IMSC_TXIM_Pos                               3           /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */

/* Bit field masks: */
#define SPI_SPI_IMSC_RORIM_Msk                              0x00000001  /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
#define SPI_SPI_IMSC_RTIM_Msk                               0x00000002  /*!< Interrupt mask bit SSPRTINTR timeout receiver */
#define SPI_SPI_IMSC_RXIM_Msk                               0x00000004  /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
#define SPI_SPI_IMSC_TXIM_Msk                               0x00000008  /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */

/*-- SPI_RIS: Status register interrupt without mask -------------------------*/

typedef struct {
  uint32_t RORRIS                                 :1;                   /*!< Interrupt status before masking SSPRORINTR */
  uint32_t RTRIS                                  :1;                   /*!< Interrupt status before masking SSPRTINTR */
  uint32_t RXRIS                                  :1;                   /*!< Interrupt status before masking SSPRXINTR */
  uint32_t TXRIS                                  :1;                   /*!< Interrupt status before masking SSPTXINTR */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _SPI_SPI_RIS_bits;

/* Bit field positions: */
#define SPI_SPI_RIS_RORRIS_Pos                              0           /*!< Interrupt status before masking SSPRORINTR */
#define SPI_SPI_RIS_RTRIS_Pos                               1           /*!< Interrupt status before masking SSPRTINTR */
#define SPI_SPI_RIS_RXRIS_Pos                               2           /*!< Interrupt status before masking SSPRXINTR */
#define SPI_SPI_RIS_TXRIS_Pos                               3           /*!< Interrupt status before masking SSPTXINTR */

/* Bit field masks: */
#define SPI_SPI_RIS_RORRIS_Msk                              0x00000001  /*!< Interrupt status before masking SSPRORINTR */
#define SPI_SPI_RIS_RTRIS_Msk                               0x00000002  /*!< Interrupt status before masking SSPRTINTR */
#define SPI_SPI_RIS_RXRIS_Msk                               0x00000004  /*!< Interrupt status before masking SSPRXINTR */
#define SPI_SPI_RIS_TXRIS_Msk                               0x00000008  /*!< Interrupt status before masking SSPTXINTR */

/*-- SPI_MIS: Status register interrupt masking account ----------------------*/

typedef struct {
  uint32_t RORRIS                                 :1;                   /*!< Masked interrupt status SSPRORINTR */
  uint32_t RTRIS                                  :1;                   /*!< Masked interrupt status SSPRTINTR */
  uint32_t RXRIS                                  :1;                   /*!< Masked interrupt status SSPRXINTR */
  uint32_t TXRIS                                  :1;                   /*!< Masked interrupt status SSPTXINTR */
  uint32_t Reserved0                              :28;                  /*!< Reserved */
} _SPI_SPI_MIS_bits;

/* Bit field positions: */
#define SPI_SPI_MIS_RORRIS_Pos                              0           /*!< Masked interrupt status SSPRORINTR */
#define SPI_SPI_MIS_RTRIS_Pos                               1           /*!< Masked interrupt status SSPRTINTR */
#define SPI_SPI_MIS_RXRIS_Pos                               2           /*!< Masked interrupt status SSPRXINTR */
#define SPI_SPI_MIS_TXRIS_Pos                               3           /*!< Masked interrupt status SSPTXINTR */

/* Bit field masks: */
#define SPI_SPI_MIS_RORRIS_Msk                              0x00000001  /*!< Masked interrupt status SSPRORINTR */
#define SPI_SPI_MIS_RTRIS_Msk                               0x00000002  /*!< Masked interrupt status SSPRTINTR */
#define SPI_SPI_MIS_RXRIS_Msk                               0x00000004  /*!< Masked interrupt status SSPRXINTR */
#define SPI_SPI_MIS_TXRIS_Msk                               0x00000008  /*!< Masked interrupt status SSPTXINTR */

/*-- SPI_ICR: Register reset interrupt ---------------------------------------*/

typedef struct {
  uint32_t RORIC                                  :1;                   /*!< Reset interrupt SSPRORINTR */
  uint32_t RTIC                                   :1;                   /*!< Reset interrupt SSPRTINTR */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _SPI_SPI_ICR_bits;

/* Bit field positions: */
#define SPI_SPI_ICR_RORIC_Pos                               0           /*!< Reset interrupt SSPRORINTR */
#define SPI_SPI_ICR_RTIC_Pos                                1           /*!< Reset interrupt SSPRTINTR */

/* Bit field masks: */
#define SPI_SPI_ICR_RORIC_Msk                               0x00000001  /*!< Reset interrupt SSPRORINTR */
#define SPI_SPI_ICR_RTIC_Msk                                0x00000002  /*!< Reset interrupt SSPRTINTR */

/*-- SPI_DMACR: Control register DMA -----------------------------------------*/

typedef struct {
  uint32_t RXDMAE                                 :1;                   /*!< DMA enable bit at reception */
  uint32_t TXDMAE                                 :1;                   /*!< DMA enable bit transmission */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _SPI_SPI_DMACR_bits;

/* Bit field positions: */
#define SPI_SPI_DMACR_RXDMAE_Pos                            0           /*!< DMA enable bit at reception */
#define SPI_SPI_DMACR_TXDMAE_Pos                            1           /*!< DMA enable bit transmission */

/* Bit field masks: */
#define SPI_SPI_DMACR_RXDMAE_Msk                            0x00000001  /*!< DMA enable bit at reception */
#define SPI_SPI_DMACR_TXDMAE_Msk                            0x00000002  /*!< DMA enable bit transmission */

/*-- Register map for SPI peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Control register 0 */
    __IO uint32_t SPI_CR0;                                              /*!< SPI_CR0    : type used for word access */
    __IO _SPI_SPI_CR0_bits SPI_CR0_bit;                                 /*!< SPI_CR0_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 1 */
    __IO uint32_t SPI_CR1;                                              /*!< SPI_CR1    : type used for word access */
    __IO _SPI_SPI_CR1_bits SPI_CR1_bit;                                 /*!< SPI_CR1_bit: structure used for bit access */
  };
  union {                                                               /*!< Data register */
    __IO uint32_t SPI_DR;                                               /*!< SPI_DR    : type used for word access */
    __IO _SPI_SPI_DR_bits SPI_DR_bit;                                   /*!< SPI_DR_bit: structure used for bit access */
  };
  union {                                                               /*!< State register */
    __I  uint32_t SPI_SR;                                               /*!< SPI_SR    : type used for word access */
    __I  _SPI_SPI_SR_bits SPI_SR_bit;                                   /*!< SPI_SR_bit: structure used for bit access */
  };
  union {                                                               /*!< Clock division factor register */
    __IO uint32_t SPI_CPSR;                                             /*!< SPI_CPSR    : type used for word access */
    __IO _SPI_SPI_CPSR_bits SPI_CPSR_bit;                               /*!< SPI_CPSR_bit: structure used for bit access */
  };
  union {                                                               /*!< Mask interrupt register */
    __IO uint32_t SPI_IMSC;                                             /*!< SPI_IMSC    : type used for word access */
    __IO _SPI_SPI_IMSC_bits SPI_IMSC_bit;                               /*!< SPI_IMSC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register interrupt without mask */
    __I  uint32_t SPI_RIS;                                              /*!< SPI_RIS    : type used for word access */
    __I  _SPI_SPI_RIS_bits SPI_RIS_bit;                                 /*!< SPI_RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register interrupt masking account */
    __I  uint32_t SPI_MIS;                                              /*!< SPI_MIS    : type used for word access */
    __I  _SPI_SPI_MIS_bits SPI_MIS_bit;                                 /*!< SPI_MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Register reset interrupt */
    __O  uint32_t SPI_ICR;                                              /*!< SPI_ICR    : type used for word access */
    __O  _SPI_SPI_ICR_bits SPI_ICR_bit;                                 /*!< SPI_ICR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register DMA */
    __IO uint32_t SPI_DMACR;                                            /*!< SPI_DMACR    : type used for word access */
    __IO _SPI_SPI_DMACR_bits SPI_DMACR_bit;                             /*!< SPI_DMACR_bit: structure used for bit access */
  };
} NT_SPI_TypeDef;

/******************************************************************************/
/*                      USERFLASH controller registers                        */
/******************************************************************************/

/*-- FMA: Address userflash register -----------------------------------------*/

typedef struct {
  uint32_t ADDR                                   :16;                  /*!< Address for commands write and page erase */
  uint32_t Reserved0                              :16;                  /*!< Reserved */
} _USERFLASH_FMA_bits;

/* Bit field positions: */
#define USERFLASH_FMA_ADDR_Pos                              0           /*!< Address for commands write and page erase */

/* Bit field masks: */
#define USERFLASH_FMA_ADDR_Msk                              0x0000FFFF  /*!< Address for commands write and page erase */

/*-- FMD: Data byte user flash register --------------------------------------*/

typedef struct {
  uint32_t DATA                                   :8;                   /*!< User flash data */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _USERFLASH_FMD_bits;

/* Bit field positions: */
#define USERFLASH_FMD_DATA_Pos                              0           /*!< User flash data */

/* Bit field masks: */
#define USERFLASH_FMD_DATA_Msk                              0x000000FF  /*!< User flash data */

/*-- FMC: Command register ---------------------------------------------------*/

typedef struct {
  uint32_t WRITE                                  :1;                   /*!< Bit writing in main block */
  uint32_t PAGE_ERASE                             :1;                   /*!< Bit paged erase the main block */
  uint32_t FULL_ERASE                             :1;                   /*!< Bit erase main block */
  uint32_t READ                                   :1;
  uint32_t WRITE_IFB                              :1;                   /*!< Bit writing on information block */
  uint32_t PAGEERASE_IFB                          :1;                   /*!< Bit erase page of information block */
  uint32_t READ_IFB                               :1;
  uint32_t Reserved0                              :9;                   /*!< Reserved */
  uint32_t MAGIC_KEY                              :16;                  /*!< Code run command. For activate command in MAGIC_KEY write 0xA442 */
} _USERFLASH_FMC_bits;

/* Bit field positions: */
#define USERFLASH_FMC_WRITE_Pos                             0           /*!< Bit writing in main block */
#define USERFLASH_FMC_PAGE_ERASE_Pos                        1           /*!< Bit paged erase the main block */
#define USERFLASH_FMC_FULL_ERASE_Pos                        2           /*!< Bit erase main block */
#define USERFLASH_FMC_READ_Pos                              3
#define USERFLASH_FMC_WRITE_IFB_Pos                         4           /*!< Bit writing on information block */
#define USERFLASH_FMC_PAGEERASE_IFB_Pos                     5           /*!< Bit erase page of information block */
#define USERFLASH_FMC_READ_IFB_Pos                          6
#define USERFLASH_FMC_MAGIC_KEY_Pos                         16          /*!< Code run command. For activate command in MAGIC_KEY write 0xA442 */

/* Bit field masks: */
#define USERFLASH_FMC_WRITE_Msk                             0x00000001  /*!< Bit writing in main block */
#define USERFLASH_FMC_PAGE_ERASE_Msk                        0x00000002  /*!< Bit paged erase the main block */
#define USERFLASH_FMC_FULL_ERASE_Msk                        0x00000004  /*!< Bit erase main block */
#define USERFLASH_FMC_READ_Msk                              0x00000008
#define USERFLASH_FMC_WRITE_IFB_Msk                         0x00000010  /*!< Bit writing on information block */
#define USERFLASH_FMC_PAGEERASE_IFB_Msk                     0x00000020  /*!< Bit erase page of information block */
#define USERFLASH_FMC_READ_IFB_Msk                          0x00000040
#define USERFLASH_FMC_MAGIC_KEY_Msk                         0xFFFF0000  /*!< Code run command. For activate command in MAGIC_KEY write 0xA442 */

/*-- FCIS: Status register ---------------------------------------------------*/

typedef struct {
  uint32_t OP_CMLT                                :1;                   /*!< Completion flag operation */
  uint32_t OP_ERROR                               :1;                   /*!< Flag write error, erase block write-protected or non-existent, or read from a non-existent block */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _USERFLASH_FCIS_bits;

/* Bit field positions: */
#define USERFLASH_FCIS_OP_CMLT_Pos                          0           /*!< Completion flag operation */
#define USERFLASH_FCIS_OP_ERROR_Pos                         1           /*!< Flag write error, erase block write-protected or non-existent, or read from a non-existent block */

/* Bit field masks: */
#define USERFLASH_FCIS_OP_CMLT_Msk                          0x00000001  /*!< Completion flag operation */
#define USERFLASH_FCIS_OP_ERROR_Msk                         0x00000002  /*!< Flag write error, erase block write-protected or non-existent, or read from a non-existent block */

/*-- FCIM: Interrupt mask register -------------------------------------------*/

typedef struct {
  uint32_t MASK_OPCMLT                            :1;                   /*!< Enables generation of an interrupt upon completion of a read or write, or erase */
  uint32_t Reserved0                              :31;                  /*!< Reserved */
} _USERFLASH_FCIM_bits;

/* Bit field positions: */
#define USERFLASH_FCIM_MASK_OPCMLT_Pos                      0           /*!< Enables generation of an interrupt upon completion of a read or write, or erase */

/* Bit field masks: */
#define USERFLASH_FCIM_MASK_OPCMLT_Msk                      0x00000001  /*!< Enables generation of an interrupt upon completion of a read or write, or erase */

/*-- FCIC: Clear status register ---------------------------------------------*/

typedef struct {
  uint32_t CLR_OPCMLT                             :1;                   /*!< Clear flag operate complit */
  uint32_t CLR_OPERROR                            :1;                   /*!< Clear flag operate Error */
  uint32_t Reserved0                              :30;                  /*!< Reserved */
} _USERFLASH_FCIC_bits;

/* Bit field positions: */
#define USERFLASH_FCIC_CLR_OPCMLT_Pos                       0           /*!< Clear flag operate complit */
#define USERFLASH_FCIC_CLR_OPERROR_Pos                      1           /*!< Clear flag operate Error */

/* Bit field masks: */
#define USERFLASH_FCIC_CLR_OPCMLT_Msk                       0x00000001  /*!< Clear flag operate complit */
#define USERFLASH_FCIC_CLR_OPERROR_Msk                      0x00000002  /*!< Clear flag operate Error */

/*-- Register map for USERFLASH peripheral -----------------------------------*/

typedef struct {
  union {                                                               /*!< Address userflash register */
    __IO uint32_t FMA;                                                  /*!< FMA    : type used for word access */
    __IO _USERFLASH_FMA_bits FMA_bit;                                   /*!< FMA_bit: structure used for bit access */
  };
  union {                                                               /*!< Data byte user flash register */
    __IO uint32_t FMD;                                                  /*!< FMD    : type used for word access */
    __IO _USERFLASH_FMD_bits FMD_bit;                                   /*!< FMD_bit: structure used for bit access */
  };
  union {                                                               /*!< Command register */
    __O  uint32_t FMC;                                                  /*!< FMC    : type used for word access */
    __O  _USERFLASH_FMC_bits FMC_bit;                                   /*!< FMC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __I  uint32_t FCIS;                                                 /*!< FCIS    : type used for word access */
    __I  _USERFLASH_FCIS_bits FCIS_bit;                                 /*!< FCIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t FCIM;                                                 /*!< FCIM    : type used for word access */
    __IO _USERFLASH_FCIM_bits FCIM_bit;                                 /*!< FCIM_bit: structure used for bit access */
  };
  union {                                                               /*!< Clear status register */
    __O  uint32_t FCIC;                                                 /*!< FCIC    : type used for word access */
    __O  _USERFLASH_FCIC_bits FCIC_bit;                                 /*!< FCIC_bit: structure used for bit access */
  };
  uint32_t Reserved0[26];                                               /*!< Reserved */
  __IO uint32_t T_ACC;                                                  /*!< Register the delay of setting addresses to read data from the flash memory */
  __IO uint32_t T_NVS;                                                  /*!< Register signal delay lifting NVSTR after lifting signal PROG */
  __IO uint32_t T_NVH;                                                  /*!< Register sets the release delay signal NVSTR after releasing signal PROG */
  __IO uint32_t T_RCV;                                                  /*!< Register delay from releasing signal NVSTR to raise it to the next transaction */
  __IO uint32_t T_PGS;                                                  /*!< Register delay lifting signal YE after lifting signal NVSTR */
  __IO uint32_t T_PROG;                                                 /*!< Register YE signal duration in recording transactions */
  __IO uint32_t T_PGH;                                                  /*!< Register delay signal NVSTR after releasing signal YE */
  __IO uint32_t T_ERASE;                                                /*!< Register duration of the signal in transactions ERASE erasure */
  __IO uint32_t T_ME;                                                   /*!< Register specifies the duration of the signal in transactions ERASE erasure */
  __IO uint32_t T_NVH1;                                                 /*!< Register specifies the duration of the signal in transactions ERASE erasure */
} NT_USERFLASH_TypeDef;

/******************************************************************************/
/*                         RTC controller registers                           */
/******************************************************************************/

/*-- PSECONDS: Part seconds register -----------------------------------------*/

typedef struct {
  uint32_t PART_SEC                               :10;                  /*!< Part seconds */
  uint32_t Reserved0                              :22;                  /*!< Reserved */
} _RTC_PSECONDS_bits;

/* Bit field positions: */
#define RTC_PSECONDS_PART_SEC_Pos                           0           /*!< Part seconds */

/* Bit field masks: */
#define RTC_PSECONDS_PART_SEC_Msk                           0x000003FF  /*!< Part seconds */

/*-- SECOND: Seconds register ------------------------------------------------*/

typedef struct {
  uint32_t SECOND                                 :7;                   /*!< Seconds in BCD format */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _RTC_SECOND_bits;

/* Bit field positions: */
#define RTC_SECOND_SECOND_Pos                               0           /*!< Seconds in BCD format */

/* Bit field masks: */
#define RTC_SECOND_SECOND_Msk                               0x0000007F  /*!< Seconds in BCD format */

/*-- MINUTE: Minute register -------------------------------------------------*/

typedef struct {
  uint32_t MINUTE                                 :7;                   /*!< Minutes in BCD format */
  uint32_t Reserved0                              :25;                  /*!< Reserved */
} _RTC_MINUTE_bits;

/* Bit field positions: */
#define RTC_MINUTE_MINUTE_Pos                               0           /*!< Minutes in BCD format */

/* Bit field masks: */
#define RTC_MINUTE_MINUTE_Msk                               0x0000007F  /*!< Minutes in BCD format */

/*-- HOUR: Hour register -----------------------------------------------------*/

typedef struct {
  uint32_t HOUR                                   :6;                   /*!< Hours in BCD format */
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _RTC_HOUR_bits;

/* Bit field positions: */
#define RTC_HOUR_HOUR_Pos                                   0           /*!< Hours in BCD format */

/* Bit field masks: */
#define RTC_HOUR_HOUR_Msk                                   0x0000003F  /*!< Hours in BCD format */

/*-- WDAY: Day of week register ----------------------------------------------*/

typedef struct {
  uint32_t DAYWEEK                                :3;                   /*!< Day of week in BCD format */
  uint32_t Reserved0                              :29;                  /*!< Reserved */
} _RTC_WDAY_bits;

/* Bit field positions: */
#define RTC_WDAY_DAYWEEK_Pos                                0           /*!< Day of week in BCD format */

/* Bit field masks: */
#define RTC_WDAY_DAYWEEK_Msk                                0x00000007  /*!< Day of week in BCD format */

/*-- DAY: Day register -------------------------------------------------------*/

typedef struct {
  uint32_t DAY                                    :6;                   /*!< Day in BCD format */
  uint32_t Reserved0                              :26;                  /*!< Reserved */
} _RTC_DAY_bits;

/* Bit field positions: */
#define RTC_DAY_DAY_Pos                                     0           /*!< Day in BCD format */

/* Bit field masks: */
#define RTC_DAY_DAY_Msk                                     0x0000003F  /*!< Day in BCD format */

/*-- MONTH: Month register ---------------------------------------------------*/

typedef struct {
  uint32_t MONTH                                  :5;                   /*!< Month in BCD format */
  uint32_t Reserved0                              :27;                  /*!< Reserved */
} _RTC_MONTH_bits;

/* Bit field positions: */
#define RTC_MONTH_MONTH_Pos                                 0           /*!< Month in BCD format */

/* Bit field masks: */
#define RTC_MONTH_MONTH_Msk                                 0x0000001F  /*!< Month in BCD format */

/*-- YEAR: Year register -----------------------------------------------------*/

typedef struct {
  uint32_t YEAR                                   :8;                   /*!< Year in BCD format */
  uint32_t Reserved0                              :24;                  /*!< Reserved */
} _RTC_YEAR_bits;

/* Bit field positions: */
#define RTC_YEAR_YEAR_Pos                                   0           /*!< Year in BCD format */

/* Bit field masks: */
#define RTC_YEAR_YEAR_Msk                                   0x000000FF  /*!< Year in BCD format */

/*-- SHDW: Register Update shadow registers RTC ------------------------------*/

typedef struct {
  uint32_t Reserved0                              :7;                   /*!< Reserved */
  uint32_t UPDTEN                                 :1;                   /*!< Enable update shadow registers RTC */
  uint32_t Reserved1                              :24;                  /*!< Reserved */
} _RTC_SHDW_bits;

/* Bit field positions: */
#define RTC_SHDW_UPDTEN_Pos                                 7           /*!< Enable update shadow registers RTC */

/* Bit field masks: */
#define RTC_SHDW_UPDTEN_Msk                                 0x00000080  /*!< Enable update shadow registers RTC */

/*-- TIME: General register Time ---------------------------------------------*/

typedef struct {
  uint32_t SPLIT_SEC                              :10;                  /*!< Split seconds */
  uint32_t SECOND                                 :7;                   /*!< Seconds */
  uint32_t MINUTE                                 :7;                   /*!< Minute */
  uint32_t HOUR                                   :6;                   /*!< Hour */
  uint32_t Reserved0                              :2;                   /*!< Reserved */
} _RTC_TIME_bits;

/* Bit field positions: */
#define RTC_TIME_SPLIT_SEC_Pos                              0           /*!< Split seconds */
#define RTC_TIME_SECOND_Pos                                 10          /*!< Seconds */
#define RTC_TIME_MINUTE_Pos                                 17          /*!< Minute */
#define RTC_TIME_HOUR_Pos                                   24          /*!< Hour */

/* Bit field masks: */
#define RTC_TIME_SPLIT_SEC_Msk                              0x000003FF  /*!< Split seconds */
#define RTC_TIME_SECOND_Msk                                 0x0001FC00  /*!< Seconds */
#define RTC_TIME_MINUTE_Msk                                 0x00FE0000  /*!< Minute */
#define RTC_TIME_HOUR_Msk                                   0x3F000000  /*!< Hour */

/*-- Register map for RTC peripheral -----------------------------------------*/

typedef struct {
  union {                                                               /*!< Part seconds register */
    __IO uint32_t PSECONDS;                                             /*!< PSECONDS    : type used for word access */
    __IO _RTC_PSECONDS_bits PSECONDS_bit;                               /*!< PSECONDS_bit: structure used for bit access */
  };
  union {                                                               /*!< Seconds register */
    __IO uint32_t SECOND;                                               /*!< SECOND    : type used for word access */
    __IO _RTC_SECOND_bits SECOND_bit;                                   /*!< SECOND_bit: structure used for bit access */
  };
  union {                                                               /*!< Minute register */
    __IO uint32_t MINUTE;                                               /*!< MINUTE    : type used for word access */
    __IO _RTC_MINUTE_bits MINUTE_bit;                                   /*!< MINUTE_bit: structure used for bit access */
  };
  uint32_t Reserved0;                                                   /*!< Reserved */
  union {                                                               /*!< Hour register */
    __IO uint32_t HOUR;                                                 /*!< HOUR    : type used for word access */
    __IO _RTC_HOUR_bits HOUR_bit;                                       /*!< HOUR_bit: structure used for bit access */
  };
  uint32_t Reserved1;                                                   /*!< Reserved */
  union {                                                               /*!< Day of week register */
    __IO uint32_t WDAY;                                                 /*!< WDAY    : type used for word access */
    __IO _RTC_WDAY_bits WDAY_bit;                                       /*!< WDAY_bit: structure used for bit access */
  };
  uint32_t Reserved2;                                                   /*!< Reserved */
  union {                                                               /*!< Day register */
    __IO uint32_t DAY;                                                  /*!< DAY    : type used for word access */
    __IO _RTC_DAY_bits DAY_bit;                                         /*!< DAY_bit: structure used for bit access */
  };
  union {                                                               /*!< Month register */
    __IO uint32_t MONTH;                                                /*!< MONTH    : type used for word access */
    __IO _RTC_MONTH_bits MONTH_bit;                                     /*!< MONTH_bit: structure used for bit access */
  };
  union {                                                               /*!< Year register */
    __IO uint32_t YEAR;                                                 /*!< YEAR    : type used for word access */
    __IO _RTC_YEAR_bits YEAR_bit;                                       /*!< YEAR_bit: structure used for bit access */
  };
  union {                                                               /*!< Register Update shadow registers RTC */
    __O  uint32_t SHDW;                                                 /*!< SHDW    : type used for word access */
    __O  _RTC_SHDW_bits SHDW_bit;                                       /*!< SHDW_bit: structure used for bit access */
  };
  union {                                                               /*!< General register Time */
    __I  uint32_t TIME;                                                 /*!< TIME    : type used for word access */
    __I  _RTC_TIME_bits TIME_bit;                                       /*!< TIME_bit: structure used for bit access */
  };
} NT_RTC_TypeDef;

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#endif

/******************************************************************************/
/*                          Peripheral memory map                             */
/******************************************************************************/

#define NT_ADC_BASE              (0x80000000UL)
#define NT_GPIOA_BASE            (0x80010000UL)
#define NT_GPIOB_BASE            (0x80011000UL)
#define NT_GPIOC_BASE            (0x80012000UL)
#define NT_GPIOD_BASE            (0x80013000UL)
#define NT_GPIOE_BASE            (0x80014000UL)
#define NT_GPIOF_BASE            (0x80015000UL)
#define NT_GPIOG_BASE            (0x80016000UL)
#define NT_GPIOH_BASE            (0x80017000UL)
#define NT_COMMON_REG_BASE       (0x80030000UL)
#define NT_CAN_BASE              (0x80070000UL)
#define NT_ETHERNET_BASE         (0x80080000UL)
#define NT_USBHost_BASE          (0x80090000UL)
#define NT_USBDevice_BASE        (0x80090000UL)
#define NT_USBOTG_BASE           (0x80090704UL)
#define NT_WDT_BASE              (0xA0000000UL)
#define NT_I2C0_BASE             (0xA0001000UL)
#define NT_I2C1_BASE             (0xA0002000UL)
#define NT_TIMER0_BASE           (0xA0003000UL)
#define NT_TIMER1_BASE           (0xA0004000UL)
#define NT_TIMER2_BASE           (0xA0005000UL)
#define NT_DMA_BASE              (0xA0006000UL)
#define NT_UART0_BASE            (0xA0007000UL)
#define NT_UART1_BASE            (0xA0008000UL)
#define NT_UART2_BASE            (0xA0009000UL)
#define NT_UART3_BASE            (0xA000A000UL)
#define NT_PWM0_BASE             (0xA000B000UL)
#define NT_PWM1_BASE             (0xA000C000UL)
#define NT_PWM2_BASE             (0xA000D000UL)
#define NT_PWM3_BASE             (0xA000E000UL)
#define NT_PWM4_BASE             (0xA000F000UL)
#define NT_PWM5_BASE             (0xA0010000UL)
#define NT_PWM6_BASE             (0xA0011000UL)
#define NT_PWM7_BASE             (0xA0012000UL)
#define NT_PWM8_BASE             (0xA0013000UL)
#define NT_CAP0_BASE             (0xA0014000UL)
#define NT_CAP1_BASE             (0xA0015000UL)
#define NT_CAP2_BASE             (0xA0016000UL)
#define NT_CAP3_BASE             (0xA0017000UL)
#define NT_CAP4_BASE             (0xA0018000UL)
#define NT_CAP5_BASE             (0xA0019000UL)
#define NT_QEP0_BASE             (0xA001A000UL)
#define NT_QEP1_BASE             (0xA001B000UL)
#define NT_BOOTFLASH_BASE        (0xA001C000UL)
#define NT_CMP_BASE              (0xA001D000UL)
#define NT_SPI0_BASE             (0xA001E000UL)
#define NT_SPI1_BASE             (0xA001F000UL)
#define NT_SPI2_BASE             (0xA0020000UL)
#define NT_SPI3_BASE             (0xA0021000UL)
#define NT_USERFLASH_BASE        (0xA0022000UL)
#define NT_RTC_BASE              (0xA0023000UL)

/******************************************************************************/
/*                          Peripheral declaration                            */
/******************************************************************************/

#define NT_ADC                   ((NT_ADC_TypeDef                       *) NT_ADC_BASE)
#define NT_GPIOA                 ((NT_GPIO_TypeDef                      *) NT_GPIOA_BASE)
#define NT_GPIOB                 ((NT_GPIO_TypeDef                      *) NT_GPIOB_BASE)
#define NT_GPIOC                 ((NT_GPIO_TypeDef                      *) NT_GPIOC_BASE)
#define NT_GPIOD                 ((NT_GPIO_TypeDef                      *) NT_GPIOD_BASE)
#define NT_GPIOE                 ((NT_GPIO_TypeDef                      *) NT_GPIOE_BASE)
#define NT_GPIOF                 ((NT_GPIO_TypeDef                      *) NT_GPIOF_BASE)
#define NT_GPIOG                 ((NT_GPIO_TypeDef                      *) NT_GPIOG_BASE)
#define NT_GPIOH                 ((NT_GPIO_TypeDef                      *) NT_GPIOH_BASE)
#define NT_COMMON_REG            ((NT_COMMON_REG_TypeDef                *) NT_COMMON_REG_BASE)
#define NT_CAN                   ((NT_CAN_TypeDef                       *) NT_CAN_BASE)
#define NT_ETHERNET              ((NT_ETHERNET_TypeDef                  *) NT_ETHERNET_BASE)
#define NT_USBHost               ((NT_USBHost_TypeDef                   *) NT_USBHost_BASE)
#define NT_USBDevice             ((NT_USBDevice_TypeDef                 *) NT_USBDevice_BASE)
#define NT_USBOTG                ((NT_USBOTG_TypeDef                    *) NT_USBOTG_BASE)
#define NT_WDT                   ((NT_WDT_TypeDef                       *) NT_WDT_BASE)
#define NT_I2C0                  ((NT_I2C_TypeDef                       *) NT_I2C0_BASE)
#define NT_I2C1                  ((NT_I2C_TypeDef                       *) NT_I2C1_BASE)
#define NT_TIMER0                ((NT_TIMER_TypeDef                     *) NT_TIMER0_BASE)
#define NT_TIMER1                ((NT_TIMER_TypeDef                     *) NT_TIMER1_BASE)
#define NT_TIMER2                ((NT_TIMER_TypeDef                     *) NT_TIMER2_BASE)
#define NT_DMA                   ((NT_DMA_TypeDef                       *) NT_DMA_BASE)
#define NT_UART0                 ((NT_UART_TypeDef                      *) NT_UART0_BASE)
#define NT_UART1                 ((NT_UART_TypeDef                      *) NT_UART1_BASE)
#define NT_UART2                 ((NT_UART_TypeDef                      *) NT_UART2_BASE)
#define NT_UART3                 ((NT_UART_TypeDef                      *) NT_UART3_BASE)
#define NT_PWM0                  ((NT_PWM_TypeDef                       *) NT_PWM0_BASE)
#define NT_PWM1                  ((NT_PWM_TypeDef                       *) NT_PWM1_BASE)
#define NT_PWM2                  ((NT_PWM_TypeDef                       *) NT_PWM2_BASE)
#define NT_PWM3                  ((NT_PWM_TypeDef                       *) NT_PWM3_BASE)
#define NT_PWM4                  ((NT_PWM_TypeDef                       *) NT_PWM4_BASE)
#define NT_PWM5                  ((NT_PWM_TypeDef                       *) NT_PWM5_BASE)
#define NT_PWM6                  ((NT_PWM_TypeDef                       *) NT_PWM6_BASE)
#define NT_PWM7                  ((NT_PWM_TypeDef                       *) NT_PWM7_BASE)
#define NT_PWM8                  ((NT_PWM_TypeDef                       *) NT_PWM8_BASE)
#define NT_CAP0                  ((NT_CAP_TypeDef                       *) NT_CAP0_BASE)
#define NT_CAP1                  ((NT_CAP_TypeDef                       *) NT_CAP1_BASE)
#define NT_CAP2                  ((NT_CAP_TypeDef                       *) NT_CAP2_BASE)
#define NT_CAP3                  ((NT_CAP_TypeDef                       *) NT_CAP3_BASE)
#define NT_CAP4                  ((NT_CAP_TypeDef                       *) NT_CAP4_BASE)
#define NT_CAP5                  ((NT_CAP_TypeDef                       *) NT_CAP5_BASE)
#define NT_QEP0                  ((NT_QEP_TypeDef                       *) NT_QEP0_BASE)
#define NT_QEP1                  ((NT_QEP_TypeDef                       *) NT_QEP1_BASE)
#define NT_BOOTFLASH             ((NT_BOOTFLASH_TypeDef                 *) NT_BOOTFLASH_BASE)
#define NT_CMP                   ((NT_CMP_TypeDef                       *) NT_CMP_BASE)
#define NT_SPI0                  ((NT_SPI_TypeDef                       *) NT_SPI0_BASE)
#define NT_SPI1                  ((NT_SPI_TypeDef                       *) NT_SPI1_BASE)
#define NT_SPI2                  ((NT_SPI_TypeDef                       *) NT_SPI2_BASE)
#define NT_SPI3                  ((NT_SPI_TypeDef                       *) NT_SPI3_BASE)
#define NT_USERFLASH             ((NT_USERFLASH_TypeDef                 *) NT_USERFLASH_BASE)
#define NT_RTC                   ((NT_RTC_TypeDef                       *) NT_RTC_BASE)

#ifdef __cplusplus
}
#endif

#endif /* __K1921VK01T_H */

/******************* (C) COPYRIGHT 2015 Angioscan Electronics ******************
*
* END OF FILE K1921VK01T.h */

