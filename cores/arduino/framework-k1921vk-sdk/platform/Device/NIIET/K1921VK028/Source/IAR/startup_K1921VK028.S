///*****************************************************************************
// * @file:    startup_K1921VK028.S
// * @author   NIIET
// * @version: V2.0
// * @date:    16.08.2018
// * @brief:   K1921VK028 startup file for IAR
// *****************************************************************************
// * <br><br>
// *
// * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
// * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
// * TIME. AS A RESULT, NIIET NOT BE HELD LIABLE FOR ANY DIRECT,
// * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
// * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
// * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
// *
// * <h2><center>&copy; COPYRIGHT 2018 NIIET </center></h2>
// *****************************************************************************
// * FILE startup_K1921VK028.S
// */

	NAME startup

	EXTERN __iar_program_start
	//EXTERN SystemInit
	PUBLIC __vector_table

	//Stack
	SECTION CSTACK:DATA:NOROOT(3)

	//Interrupt Table =====================
	SECTION .intvec:CODE:NOROOT(2)
	DATA
__vector_table
		DCD     sfe(CSTACK)
		DCD     Reset_Handler
	//Exceptions
		DCD     NMI_Handler
		DCD     HardFault_Handler
		DCD     MemManage_Handler
		DCD     BusFault_Handler
		DCD     UsageFault_Handler
		DCD     Unknown_Exception
		DCD     Unknown_Exception
		DCD     Unknown_Exception
		DCD     Unknown_Exception
		DCD     SVC_Handler
		DCD     DebugMon_Handler
		DCD     Unknown_Exception
		DCD     PendSV_Handler
		DCD     SysTick_Handler
	//Interrupts
		DCD     WDT_IRQHandler ; Watchdog timer interrupt
		DCD     RCU_IRQHandler ; Reset and clock unit interrupt
		DCD     RTC_IRQHandler ; RTC interrupt
		DCD     MFLASH_IRQHandler ; MFLASH interrupt
		DCD     BFLASH_IRQHandler ; BFLASH interrupt
		DCD     GPIOA_IRQHandler ; GPIO A interrupt
		DCD     GPIOB_IRQHandler ; GPIO B interrupt
		DCD     GPIOC_IRQHandler ; GPIO C interrupt
		DCD     GPIOD_IRQHandler ; GPIO D interrupt
		DCD     GPIOE_IRQHandler ; GPIO E interrupt
		DCD     GPIOF_IRQHandler ; GPIO F interrupt
		DCD     GPIOG_IRQHandler ; GPIO G interrupt
		DCD     GPIOH_IRQHandler ; GPIO H interrupt
		DCD     GPIOJ_IRQHandler ; GPIO J interrupt
		DCD     GPIOK_IRQHandler ; GPIO K interrupt
		DCD     GPIOL_IRQHandler ; GPIO L interrupt
		DCD     GPIOM_IRQHandler ; GPIO M interrupt
		DCD     DMA_CH0_IRQHandler ; DMA channel 0 interrupt
		DCD     DMA_CH1_IRQHandler ; DMA channel 1 interrupt
		DCD     DMA_CH2_IRQHandler ; DMA channel 2 interrupt
		DCD     DMA_CH3_IRQHandler ; DMA channel 3 interrupt
		DCD     DMA_CH4_IRQHandler ; DMA channel 4 interrupt
		DCD     DMA_CH5_IRQHandler ; DMA channel 5 interrupt
		DCD     DMA_CH6_IRQHandler ; DMA channel 6 interrupt
		DCD     DMA_CH7_IRQHandler ; DMA channel 7 interrupt
		DCD     DMA_CH8_IRQHandler ; DMA channel 8 interrupt
		DCD     DMA_CH9_IRQHandler ; DMA channel 9 interrupt
		DCD     DMA_CH10_IRQHandler ; DMA channel 10 interrupt
		DCD     DMA_CH11_IRQHandler ; DMA channel 11 interrupt
		DCD     DMA_CH12_IRQHandler ; DMA channel 12 interrupt
		DCD     DMA_CH13_IRQHandler ; DMA channel 13 interrupt
		DCD     DMA_CH14_IRQHandler ; DMA channel 14 interrupt
		DCD     DMA_CH15_IRQHandler ; DMA channel 15 interrupt
		DCD     DMA_CH16_IRQHandler ; DMA channel 16 interrupt
		DCD     DMA_CH17_IRQHandler ; DMA channel 17 interrupt
		DCD     DMA_CH18_IRQHandler ; DMA channel 18 interrupt
		DCD     DMA_CH19_IRQHandler ; DMA channel 19 interrupt
		DCD     DMA_CH20_IRQHandler ; DMA channel 20 interrupt
		DCD     DMA_CH21_IRQHandler ; DMA channel 21 interrupt
		DCD     DMA_CH22_IRQHandler ; DMA channel 22 interrupt
		DCD     DMA_CH23_IRQHandler ; DMA channel 23 interrupt
		DCD     DMA_CH24_IRQHandler ; DMA channel 24 interrupt
		DCD     DMA_CH25_IRQHandler ; DMA channel 25 interrupt
		DCD     DMA_CH26_IRQHandler ; DMA channel 26 interrupt
		DCD     DMA_CH27_IRQHandler ; DMA channel 27 interrupt
		DCD     DMA_CH28_IRQHandler ; DMA channel 28 interrupt
		DCD     DMA_CH29_IRQHandler ; DMA channel 29 interrupt
		DCD     DMA_CH30_IRQHandler ; DMA channel 30 interrupt
		DCD     DMA_CH31_IRQHandler ; DMA channel 31 interrupt
		DCD     TMR0_IRQHandler ; Timer 0 interrupt
		DCD     TMR1_IRQHandler ; Timer 1 interrupt
		DCD     TMR2_IRQHandler ; Timer 2 interrupt
		DCD     TMR3_IRQHandler ; Timer 3 interrupt
		DCD     ETMR0_IRQHandler ; Enhanced Timer 0 interrupt
		DCD     ETMR1_IRQHandler ; Enhanced Timer 1 interrupt
		DCD     ETMR2_IRQHandler ; Enhanced Timer 2 interrupt
		DCD     ETMR3_IRQHandler ; Enhanced Timer 3 interrupt
		DCD     UART0_TD_IRQHandler ; UART0 Transmit Done interrupt
		DCD     UART0_MX_IRQHandler ; UART0 Modem interrupt
		DCD     UART0_RX_IRQHandler ; UART0 Recieve interrupt
		DCD     UART0_TX_IRQHandler ; UART0 Transmit interrupt
		DCD     UART0_RT_IRQHandler ; UART0 Recieve interrupt
		DCD     UART0_E_IRQHandler ; UART0 Error interrupt
		DCD     UART0_IRQHandler ; UART0 interrupt
		DCD     UART1_TD_IRQHandler ; UART1 Transmit Done interrupt
		DCD     UART1_MX_IRQHandler ; UART1 Modem interrupt
		DCD     UART1_RX_IRQHandler ; UART1 Recieve interrupt
		DCD     UART1_TX_IRQHandler ; UART1 Transmit interrupt
		DCD     UART1_RT_IRQHandler ; UART1 Recieve interrupt
		DCD     UART1_E_IRQHandler ; UART1 Error interrupt
		DCD     UART1_IRQHandler ; UART1 interrupt
		DCD     UART2_TD_IRQHandler ; UART2 Transmit Done interrupt
		DCD     UART2_MX_IRQHandler ; UART2 Modem interrupt
		DCD     UART2_RX_IRQHandler ; UART2 Recieve interrupt
		DCD     UART2_TX_IRQHandler ; UART2 Transmit interrupt
		DCD     UART2_RT_IRQHandler ; UART2 Recieve interrupt
		DCD     UART2_E_IRQHandler ; UART2 Error interrupt
		DCD     UART2_IRQHandler ; UART2 interrupt
		DCD     UART3_TD_IRQHandler ; UART3 Transmit Done interrupt
		DCD     UART3_MX_IRQHandler ; UART3 Modem interrupt
		DCD     UART3_RX_IRQHandler ; UART3 Recieve interrupt
		DCD     UART3_TX_IRQHandler ; UART3 Transmit interrupt
		DCD     UART3_RT_IRQHandler ; UART3 Recieve interrupt
		DCD     UART3_E_IRQHandler ; UART3 Error interrupt
		DCD     UART3_IRQHandler ; UART3 interrupt
		DCD     TUART0_RX_IRQHandler ; Tiny UART0 Receive interrupt
		DCD     TUART0_TX_IRQHandler ; Tiny UART0 Transmit interrupt
		DCD     TUART0_RO_IRQHandler ; Tiny UART0 Receive Overrun interrupt
		DCD     TUART0_TO_IRQHandler ; Tiny UART0 Transmit Overrun interrupt
		DCD     TUART0_IRQHandler ; Tiny UART0 interrupt
		DCD     TUART1_RX_IRQHandler ; Tiny UART1 Receive interrupt
		DCD     TUART1_TX_IRQHandler ; Tiny UART1 Transmit interrupt
		DCD     TUART1_RO_IRQHandler ; Tiny UART1 Receive Overrun interrupt
		DCD     TUART1_TO_IRQHandler ; Tiny UART1 Transmit Overrun interrupt
		DCD     TUART1_IRQHandler ; Tiny UART1 interrupt
		DCD     SPI0_IRQHandler ; SPI0 interrupt
		DCD     SPI0_RX_IRQHandler ; SPI0 Receive interrupt
		DCD     SPI0_TX_IRQHandler ; SPI0 Transmit interrupt
		DCD     SPI0_RO_IRQHandler ; SPI0 Receive Overrun interrupt
		DCD     SPI0_RT_IRQHandler ; SPI0 Receive Timeout interrupt
		DCD     SPI1_IRQHandler ; SPI1 interrupt
		DCD     SPI1_RX_IRQHandler ; SPI1 Receive interrupt
		DCD     SPI1_TX_IRQHandler ; SPI1 Transmit interrupt
		DCD     SPI1_RO_IRQHandler ; SPI1 Receive Overrun interrupt
		DCD     SPI1_RT_IRQHandler ; SPI1 Receive Timeout interrupt
		DCD     SPI2_IRQHandler ; SPI2 interrupt
		DCD     SPI2_RX_IRQHandler ; SPI2 Receive interrupt
		DCD     SPI2_TX_IRQHandler ; SPI2 Transmit interrupt
		DCD     SPI2_RO_IRQHandler ; SPI2 Receive Overrun interrupt
		DCD     SPI2_RT_IRQHandler ; SPI2 Receive Timeout interrupt
		DCD     SPI3_IRQHandler ; SPI3 interrupt
		DCD     SPI3_RX_IRQHandler ; SPI3 Receive interrupt
		DCD     SPI3_TX_IRQHandler ; SPI3 Transmit interrupt
		DCD     SPI3_RO_IRQHandler ; SPI3 Receive Overrun interrupt
		DCD     SPI3_RT_IRQHandler ; SPI3 Receive Timeout interrupt
		DCD     I2C0_IRQHandler ; I2C0 interrupt
		DCD     I2C1_IRQHandler ; I2C1 interrupt
		DCD     SPWR0_IRQHandler ; SpaceWire0 interrupt
		DCD     SPWR1_IRQHandler ; SpaceWire1 interrupt
		DCD     MILSTD0_IRQHandler ; MIL-STD 1553 0 interrupt
		DCD     MILSTD1_IRQHandler ; MIL-STD 1553 1 interrupt
		DCD     ECAP0_IRQHandler ; Capture Unit 0 interrupt
		DCD     ECAP1_IRQHandler ; Capture Unit 1 interrupt
		DCD     ECAP2_IRQHandler ; Capture Unit 2 interrupt
		DCD     ECAP3_IRQHandler ; Capture Unit 3 interrupt
		DCD     ECAP4_IRQHandler ; Capture Unit 4 interrupt
		DCD     ECAP5_IRQHandler ; Capture Unit 5 interrupt
		DCD     PWM0_IRQHandler ; PWM0 interrupt
		DCD     PWM0_HD_IRQHandler ; PWM0 HD interrupt
		DCD     PWM0_TZ_IRQHandler ; PWM0 TZ interrupt
		DCD     PWM1_IRQHandler ; PWM1 interrupt
		DCD     PWM1_HD_IRQHandler ; PWM1 HD interrupt
		DCD     PWM1_TZ_IRQHandler ; PWM1 TZ interrupt
		DCD     PWM2_IRQHandler ; PWM2 interrupt
		DCD     PWM2_HD_IRQHandler ; PWM2 HD interrupt
		DCD     PWM2_TZ_IRQHandler ; PWM2 TZ interrupt
		DCD     PWM3_IRQHandler ; PWM3 interrupt
		DCD     PWM3_HD_IRQHandler ; PWM3 HD interrupt
		DCD     PWM3_TZ_IRQHandler ; PWM3 TZ interrupt
		DCD     PWM4_IRQHandler ; PWM4 interrupt
		DCD     PWM4_HD_IRQHandler ; PWM4 HD interrupt
		DCD     PWM4_TZ_IRQHandler ; PWM4 TZ interrupt
		DCD     PWM5_IRQHandler ; PWM5 interrupt
		DCD     PWM5_HD_IRQHandler ; PWM5 HD interrupt
		DCD     PWM5_TZ_IRQHandler ; PWM5 TZ interrupt
		DCD     PWM6_IRQHandler ; PWM6 interrupt
		DCD     PWM6_HD_IRQHandler ; PWM6 HD interrupt
		DCD     PWM6_TZ_IRQHandler ; PWM6 TZ interrupt
		DCD     PWM7_IRQHandler ; PWM7 interrupt
		DCD     PWM7_HD_IRQHandler ; PWM7 HD interrupt
		DCD     PWM7_TZ_IRQHandler ; PWM7 TZ interrupt
		DCD     PWM8_IRQHandler ; PWM8 interrupt
		DCD     PWM8_HD_IRQHandler ; PWM8 HD interrupt
		DCD     PWM8_TZ_IRQHandler ; PWM8 TZ interrupt
		DCD     PWM9_IRQHandler ; PWM9 interrupt
		DCD     PWM9_HD_IRQHandler ; PWM9 HD interrupt
		DCD     PWM9_TZ_IRQHandler ; PWM9 TZ interrupt
		DCD     QEP0_IRQHandler ; QEP0 interrupt
		DCD     QEP1_IRQHandler ; QEP1 interrupt
		DCD     QEP2_IRQHandler ; QEP2 interrupt
		DCD     QEP3_IRQHandler ; QEP3 interrupt
		DCD     ADC_SEQ0_IRQHandler ; ADC Sequencer 0 interrupt
		DCD     ADC_SEQ1_IRQHandler ; ADC Sequencer 1 interrupt
		DCD     ADC_SEQ2_IRQHandler ; ADC Sequencer 2 interrupt
		DCD     ADC_SEQ3_IRQHandler ; ADC Sequencer 3 interrupt
		DCD     ADC_SEQ4_IRQHandler ; ADC Sequencer 4 interrupt
		DCD     ADC_SEQ5_IRQHandler ; ADC Sequencer 5 interrupt
		DCD     ADC_SEQ6_IRQHandler ; ADC Sequencer 6 interrupt
		DCD     ADC_SEQ7_IRQHandler ; ADC Sequencer 7 interrupt
		DCD     ADC_DC_IRQHandler ; ADC Digital Comparator interrupt
		DCD     ETH_IRQHandler ; Ethernet interrupt
		DCD     CAN0_IRQHandler ; CAN0 interrupt
		DCD     CAN1_IRQHandler ; CAN1 interrupt
		DCD     CAN2_IRQHandler ; CAN2 interrupt
		DCD     CAN3_IRQHandler ; CAN3 interrupt
		DCD     CAN4_IRQHandler ; CAN4 interrupt
		DCD     CAN5_IRQHandler ; CAN5 interrupt
		DCD     CAN6_IRQHandler ; CAN6 interrupt
		DCD     CAN7_IRQHandler ; CAN7 interrupt
		DCD     CAN8_IRQHandler ; CAN8 interrupt
		DCD     CAN9_IRQHandler ; CAN9 interrupt
		DCD     CAN10_IRQHandler ; CAN10 interrupt
		DCD     CAN11_IRQHandler ; CAN11 interrupt
		DCD     CAN12_IRQHandler ; CAN12 interrupt
		DCD     CAN13_IRQHandler ; CAN13 interrupt
		DCD     CAN14_IRQHandler ; CAN14 interrupt
		DCD     CAN15_IRQHandler ; CAN15 interrupt
		DCD     FPU_IRQHandler ; FPU exception interrupt
		DCD     TMU_IRQHandler ; TMU interrupt
		DCD     LAU_IRQHandler ; LAU interrupt
		DCD     SDFM_IRQHandler ; SDFM interrupt
		DCD     OWI0_IRQHandler ; OWI0 interrupt
		DCD     OWI1_IRQHandler ; OWI1 interrupt

	REPT 47
		DCD     Unknown_INTR 
	ENDR

	//Handlers ==============================
	THUMB
 
//Entry Point

Reset_Handler
                LDR R0,=SystemInit
		BLX R0

                ;LDR             R0, =0x8009002C
                ;LDR             R0,[R0,#0]

		LDR R0,=__iar_program_start
		BX R0

//Exceptions Temp Handlers -----------------------------------

        PUBWEAK SystemInit
SystemInit
        BX  LR

	PUBWEAK NMI_Handler
NMI_Handler
	B NMI_Handler

	PUBWEAK HardFault_Handler
HardFault_Handler
	B HardFault_Handler

	PUBWEAK MemManage_Handler
MemManage_Handler
	B MemManage_Handler

	PUBWEAK BusFault_Handler
BusFault_Handler
	B BusFault_Handler

	PUBWEAK UsageFault_Handler
UsageFault_Handler
	B UsageFault_Handler

	PUBWEAK Unknown_Exception
Unknown_Exception
	B Unknown_Exception

	PUBWEAK SVC_Handler
SVC_Handler
	B SVC_Handler

	PUBWEAK DebugMon_Handler
DebugMon_Handler
	B DebugMon_Handler

	PUBWEAK PendSV_Handler
PendSV_Handler
	B PendSV_Handler

	PUBWEAK SysTick_Handler
SysTick_Handler
	B SysTick_Handler

//Interrupts Temp Handlers ----------------------------------
	PUBWEAK WDT_IRQHandler
WDT_IRQHandler
	B WDT_IRQHandler

	PUBWEAK RCU_IRQHandler
RCU_IRQHandler
	B RCU_IRQHandler

	PUBWEAK RTC_IRQHandler
RTC_IRQHandler
	B RTC_IRQHandler

	PUBWEAK MFLASH_IRQHandler
MFLASH_IRQHandler
	B MFLASH_IRQHandler

	PUBWEAK BFLASH_IRQHandler
BFLASH_IRQHandler
	B BFLASH_IRQHandler

	PUBWEAK GPIOA_IRQHandler
GPIOA_IRQHandler
	B GPIOA_IRQHandler

	PUBWEAK GPIOB_IRQHandler
GPIOB_IRQHandler
	B GPIOB_IRQHandler

	PUBWEAK GPIOC_IRQHandler
GPIOC_IRQHandler
	B GPIOC_IRQHandler

	PUBWEAK GPIOD_IRQHandler
GPIOD_IRQHandler
	B GPIOD_IRQHandler

	PUBWEAK GPIOE_IRQHandler
GPIOE_IRQHandler
	B GPIOE_IRQHandler

	PUBWEAK GPIOF_IRQHandler
GPIOF_IRQHandler
	B GPIOF_IRQHandler

	PUBWEAK GPIOG_IRQHandler
GPIOG_IRQHandler
	B GPIOG_IRQHandler

	PUBWEAK GPIOH_IRQHandler
GPIOH_IRQHandler
	B GPIOH_IRQHandler

	PUBWEAK GPIOJ_IRQHandler
GPIOJ_IRQHandler
	B GPIOJ_IRQHandler

	PUBWEAK GPIOK_IRQHandler
GPIOK_IRQHandler
	B GPIOK_IRQHandler

	PUBWEAK GPIOL_IRQHandler
GPIOL_IRQHandler
	B GPIOL_IRQHandler

	PUBWEAK GPIOM_IRQHandler
GPIOM_IRQHandler
	B GPIOM_IRQHandler

	PUBWEAK DMA_CH0_IRQHandler
DMA_CH0_IRQHandler
	B DMA_CH0_IRQHandler

	PUBWEAK DMA_CH1_IRQHandler
DMA_CH1_IRQHandler
	B DMA_CH1_IRQHandler

	PUBWEAK DMA_CH2_IRQHandler
DMA_CH2_IRQHandler
	B DMA_CH2_IRQHandler

	PUBWEAK DMA_CH3_IRQHandler
DMA_CH3_IRQHandler
	B DMA_CH3_IRQHandler

	PUBWEAK DMA_CH4_IRQHandler
DMA_CH4_IRQHandler
	B DMA_CH4_IRQHandler

	PUBWEAK DMA_CH5_IRQHandler
DMA_CH5_IRQHandler
	B DMA_CH5_IRQHandler

	PUBWEAK DMA_CH6_IRQHandler
DMA_CH6_IRQHandler
	B DMA_CH6_IRQHandler

	PUBWEAK DMA_CH7_IRQHandler
DMA_CH7_IRQHandler
	B DMA_CH7_IRQHandler

	PUBWEAK DMA_CH8_IRQHandler
DMA_CH8_IRQHandler
	B DMA_CH8_IRQHandler

	PUBWEAK DMA_CH9_IRQHandler
DMA_CH9_IRQHandler
	B DMA_CH9_IRQHandler

	PUBWEAK DMA_CH10_IRQHandler
DMA_CH10_IRQHandler
	B DMA_CH10_IRQHandler

	PUBWEAK DMA_CH11_IRQHandler
DMA_CH11_IRQHandler
	B DMA_CH11_IRQHandler

	PUBWEAK DMA_CH12_IRQHandler
DMA_CH12_IRQHandler
	B DMA_CH12_IRQHandler

	PUBWEAK DMA_CH13_IRQHandler
DMA_CH13_IRQHandler
	B DMA_CH13_IRQHandler

	PUBWEAK DMA_CH14_IRQHandler
DMA_CH14_IRQHandler
	B DMA_CH14_IRQHandler

	PUBWEAK DMA_CH15_IRQHandler
DMA_CH15_IRQHandler
	B DMA_CH15_IRQHandler

	PUBWEAK DMA_CH16_IRQHandler
DMA_CH16_IRQHandler
	B DMA_CH16_IRQHandler

	PUBWEAK DMA_CH17_IRQHandler
DMA_CH17_IRQHandler
	B DMA_CH17_IRQHandler

	PUBWEAK DMA_CH18_IRQHandler
DMA_CH18_IRQHandler
	B DMA_CH18_IRQHandler

	PUBWEAK DMA_CH19_IRQHandler
DMA_CH19_IRQHandler
	B DMA_CH19_IRQHandler

	PUBWEAK DMA_CH20_IRQHandler
DMA_CH20_IRQHandler
	B DMA_CH20_IRQHandler

	PUBWEAK DMA_CH21_IRQHandler
DMA_CH21_IRQHandler
	B DMA_CH21_IRQHandler

	PUBWEAK DMA_CH22_IRQHandler
DMA_CH22_IRQHandler
	B DMA_CH22_IRQHandler

	PUBWEAK DMA_CH23_IRQHandler
DMA_CH23_IRQHandler
	B DMA_CH23_IRQHandler

	PUBWEAK DMA_CH24_IRQHandler
DMA_CH24_IRQHandler
	B DMA_CH24_IRQHandler

	PUBWEAK DMA_CH25_IRQHandler
DMA_CH25_IRQHandler
	B DMA_CH25_IRQHandler

	PUBWEAK DMA_CH26_IRQHandler
DMA_CH26_IRQHandler
	B DMA_CH26_IRQHandler

	PUBWEAK DMA_CH27_IRQHandler
DMA_CH27_IRQHandler
	B DMA_CH27_IRQHandler

	PUBWEAK DMA_CH28_IRQHandler
DMA_CH28_IRQHandler
	B DMA_CH28_IRQHandler

	PUBWEAK DMA_CH29_IRQHandler
DMA_CH29_IRQHandler
	B DMA_CH29_IRQHandler

	PUBWEAK DMA_CH30_IRQHandler
DMA_CH30_IRQHandler
	B DMA_CH30_IRQHandler

	PUBWEAK DMA_CH31_IRQHandler
DMA_CH31_IRQHandler
	B DMA_CH31_IRQHandler

	PUBWEAK TMR0_IRQHandler
TMR0_IRQHandler
	B TMR0_IRQHandler

	PUBWEAK TMR1_IRQHandler
TMR1_IRQHandler
	B TMR1_IRQHandler

	PUBWEAK TMR2_IRQHandler
TMR2_IRQHandler
	B TMR2_IRQHandler

	PUBWEAK TMR3_IRQHandler
TMR3_IRQHandler
	B TMR3_IRQHandler

	PUBWEAK ETMR0_IRQHandler
ETMR0_IRQHandler
	B ETMR0_IRQHandler

	PUBWEAK ETMR1_IRQHandler
ETMR1_IRQHandler
	B ETMR1_IRQHandler

	PUBWEAK ETMR2_IRQHandler
ETMR2_IRQHandler
	B ETMR2_IRQHandler

	PUBWEAK ETMR3_IRQHandler
ETMR3_IRQHandler
	B ETMR3_IRQHandler

	PUBWEAK UART0_TD_IRQHandler
UART0_TD_IRQHandler
	B UART0_TD_IRQHandler

	PUBWEAK UART0_MX_IRQHandler
UART0_MX_IRQHandler
	B UART0_MX_IRQHandler

	PUBWEAK UART0_RX_IRQHandler
UART0_RX_IRQHandler
	B UART0_RX_IRQHandler

	PUBWEAK UART0_TX_IRQHandler
UART0_TX_IRQHandler
	B UART0_TX_IRQHandler

	PUBWEAK UART0_RT_IRQHandler
UART0_RT_IRQHandler
	B UART0_RT_IRQHandler

	PUBWEAK UART0_E_IRQHandler
UART0_E_IRQHandler
	B UART0_E_IRQHandler

	PUBWEAK UART0_IRQHandler
UART0_IRQHandler
	B UART0_IRQHandler

	PUBWEAK UART1_TD_IRQHandler
UART1_TD_IRQHandler
	B UART1_TD_IRQHandler

	PUBWEAK UART1_MX_IRQHandler
UART1_MX_IRQHandler
	B UART1_MX_IRQHandler

	PUBWEAK UART1_RX_IRQHandler
UART1_RX_IRQHandler
	B UART1_RX_IRQHandler

	PUBWEAK UART1_TX_IRQHandler
UART1_TX_IRQHandler
	B UART1_TX_IRQHandler

	PUBWEAK UART1_RT_IRQHandler
UART1_RT_IRQHandler
	B UART1_RT_IRQHandler

	PUBWEAK UART1_E_IRQHandler
UART1_E_IRQHandler
	B UART1_E_IRQHandler

	PUBWEAK UART1_IRQHandler
UART1_IRQHandler
	B UART1_IRQHandler

	PUBWEAK UART2_TD_IRQHandler
UART2_TD_IRQHandler
	B UART2_TD_IRQHandler

	PUBWEAK UART2_MX_IRQHandler
UART2_MX_IRQHandler
	B UART2_MX_IRQHandler

	PUBWEAK UART2_RX_IRQHandler
UART2_RX_IRQHandler
	B UART2_RX_IRQHandler

	PUBWEAK UART2_TX_IRQHandler
UART2_TX_IRQHandler
	B UART2_TX_IRQHandler

	PUBWEAK UART2_RT_IRQHandler
UART2_RT_IRQHandler
	B UART2_RT_IRQHandler

	PUBWEAK UART2_E_IRQHandler
UART2_E_IRQHandler
	B UART2_E_IRQHandler

	PUBWEAK UART2_IRQHandler
UART2_IRQHandler
	B UART2_IRQHandler

	PUBWEAK UART3_TD_IRQHandler
UART3_TD_IRQHandler
	B UART3_TD_IRQHandler

	PUBWEAK UART3_MX_IRQHandler
UART3_MX_IRQHandler
	B UART3_MX_IRQHandler

	PUBWEAK UART3_RX_IRQHandler
UART3_RX_IRQHandler
	B UART3_RX_IRQHandler

	PUBWEAK UART3_TX_IRQHandler
UART3_TX_IRQHandler
	B UART3_TX_IRQHandler

	PUBWEAK UART3_RT_IRQHandler
UART3_RT_IRQHandler
	B UART3_RT_IRQHandler

	PUBWEAK UART3_E_IRQHandler
UART3_E_IRQHandler
	B UART3_E_IRQHandler

	PUBWEAK UART3_IRQHandler
UART3_IRQHandler
	B UART3_IRQHandler

	PUBWEAK TUART0_RX_IRQHandler
TUART0_RX_IRQHandler
	B TUART0_RX_IRQHandler

	PUBWEAK TUART0_TX_IRQHandler
TUART0_TX_IRQHandler
	B TUART0_TX_IRQHandler

	PUBWEAK TUART0_RO_IRQHandler
TUART0_RO_IRQHandler
	B TUART0_RO_IRQHandler

	PUBWEAK TUART0_TO_IRQHandler
TUART0_TO_IRQHandler
	B TUART0_TO_IRQHandler

	PUBWEAK TUART0_IRQHandler
TUART0_IRQHandler
	B TUART0_IRQHandler

	PUBWEAK TUART1_RX_IRQHandler
TUART1_RX_IRQHandler
	B TUART1_RX_IRQHandler

	PUBWEAK TUART1_TX_IRQHandler
TUART1_TX_IRQHandler
	B TUART1_TX_IRQHandler

	PUBWEAK TUART1_RO_IRQHandler
TUART1_RO_IRQHandler
	B TUART1_RO_IRQHandler

	PUBWEAK TUART1_TO_IRQHandler
TUART1_TO_IRQHandler
	B TUART1_TO_IRQHandler

	PUBWEAK TUART1_IRQHandler
TUART1_IRQHandler
	B TUART1_IRQHandler

	PUBWEAK SPI0_IRQHandler
SPI0_IRQHandler
	B SPI0_IRQHandler

	PUBWEAK SPI0_RX_IRQHandler
SPI0_RX_IRQHandler
	B SPI0_RX_IRQHandler

	PUBWEAK SPI0_TX_IRQHandler
SPI0_TX_IRQHandler
	B SPI0_TX_IRQHandler

	PUBWEAK SPI0_RO_IRQHandler
SPI0_RO_IRQHandler
	B SPI0_RO_IRQHandler

	PUBWEAK SPI0_RT_IRQHandler
SPI0_RT_IRQHandler
	B SPI0_RT_IRQHandler

	PUBWEAK SPI1_IRQHandler
SPI1_IRQHandler
	B SPI1_IRQHandler

	PUBWEAK SPI1_RX_IRQHandler
SPI1_RX_IRQHandler
	B SPI1_RX_IRQHandler

	PUBWEAK SPI1_TX_IRQHandler
SPI1_TX_IRQHandler
	B SPI1_TX_IRQHandler

	PUBWEAK SPI1_RO_IRQHandler
SPI1_RO_IRQHandler
	B SPI1_RO_IRQHandler

	PUBWEAK SPI1_RT_IRQHandler
SPI1_RT_IRQHandler
	B SPI1_RT_IRQHandler

	PUBWEAK SPI2_IRQHandler
SPI2_IRQHandler
	B SPI2_IRQHandler

	PUBWEAK SPI2_RX_IRQHandler
SPI2_RX_IRQHandler
	B SPI2_RX_IRQHandler

	PUBWEAK SPI2_TX_IRQHandler
SPI2_TX_IRQHandler
	B SPI2_TX_IRQHandler

	PUBWEAK SPI2_RO_IRQHandler
SPI2_RO_IRQHandler
	B SPI2_RO_IRQHandler

	PUBWEAK SPI2_RT_IRQHandler
SPI2_RT_IRQHandler
	B SPI2_RT_IRQHandler

	PUBWEAK SPI3_IRQHandler
SPI3_IRQHandler
	B SPI3_IRQHandler

	PUBWEAK SPI3_RX_IRQHandler
SPI3_RX_IRQHandler
	B SPI3_RX_IRQHandler

	PUBWEAK SPI3_TX_IRQHandler
SPI3_TX_IRQHandler
	B SPI3_TX_IRQHandler

	PUBWEAK SPI3_RO_IRQHandler
SPI3_RO_IRQHandler
	B SPI3_RO_IRQHandler

	PUBWEAK SPI3_RT_IRQHandler
SPI3_RT_IRQHandler
	B SPI3_RT_IRQHandler

	PUBWEAK I2C0_IRQHandler
I2C0_IRQHandler
	B I2C0_IRQHandler

	PUBWEAK I2C1_IRQHandler
I2C1_IRQHandler
	B I2C1_IRQHandler

	PUBWEAK SPWR0_IRQHandler
SPWR0_IRQHandler
	B SPWR0_IRQHandler

	PUBWEAK SPWR1_IRQHandler
SPWR1_IRQHandler
	B SPWR1_IRQHandler

	PUBWEAK MILSTD0_IRQHandler
MILSTD0_IRQHandler
	B MILSTD0_IRQHandler

	PUBWEAK MILSTD1_IRQHandler
MILSTD1_IRQHandler
	B MILSTD1_IRQHandler

	PUBWEAK ECAP0_IRQHandler
ECAP0_IRQHandler
	B ECAP0_IRQHandler

	PUBWEAK ECAP1_IRQHandler
ECAP1_IRQHandler
	B ECAP1_IRQHandler

	PUBWEAK ECAP2_IRQHandler
ECAP2_IRQHandler
	B ECAP2_IRQHandler

	PUBWEAK ECAP3_IRQHandler
ECAP3_IRQHandler
	B ECAP3_IRQHandler

	PUBWEAK ECAP4_IRQHandler
ECAP4_IRQHandler
	B ECAP4_IRQHandler

	PUBWEAK ECAP5_IRQHandler
ECAP5_IRQHandler
	B ECAP5_IRQHandler

	PUBWEAK PWM0_IRQHandler
PWM0_IRQHandler
	B PWM0_IRQHandler

	PUBWEAK PWM0_HD_IRQHandler
PWM0_HD_IRQHandler
	B PWM0_HD_IRQHandler

	PUBWEAK PWM0_TZ_IRQHandler
PWM0_TZ_IRQHandler
	B PWM0_TZ_IRQHandler

	PUBWEAK PWM1_IRQHandler
PWM1_IRQHandler
	B PWM1_IRQHandler

	PUBWEAK PWM1_HD_IRQHandler
PWM1_HD_IRQHandler
	B PWM1_HD_IRQHandler

	PUBWEAK PWM1_TZ_IRQHandler
PWM1_TZ_IRQHandler
	B PWM1_TZ_IRQHandler

	PUBWEAK PWM2_IRQHandler
PWM2_IRQHandler
	B PWM2_IRQHandler

	PUBWEAK PWM2_HD_IRQHandler
PWM2_HD_IRQHandler
	B PWM2_HD_IRQHandler

	PUBWEAK PWM2_TZ_IRQHandler
PWM2_TZ_IRQHandler
	B PWM2_TZ_IRQHandler

	PUBWEAK PWM3_IRQHandler
PWM3_IRQHandler
	B PWM3_IRQHandler

	PUBWEAK PWM3_HD_IRQHandler
PWM3_HD_IRQHandler
	B PWM3_HD_IRQHandler

	PUBWEAK PWM3_TZ_IRQHandler
PWM3_TZ_IRQHandler
	B PWM3_TZ_IRQHandler

	PUBWEAK PWM4_IRQHandler
PWM4_IRQHandler
	B PWM4_IRQHandler

	PUBWEAK PWM4_HD_IRQHandler
PWM4_HD_IRQHandler
	B PWM4_HD_IRQHandler

	PUBWEAK PWM4_TZ_IRQHandler
PWM4_TZ_IRQHandler
	B PWM4_TZ_IRQHandler

	PUBWEAK PWM5_IRQHandler
PWM5_IRQHandler
	B PWM5_IRQHandler

	PUBWEAK PWM5_HD_IRQHandler
PWM5_HD_IRQHandler
	B PWM5_HD_IRQHandler

	PUBWEAK PWM5_TZ_IRQHandler
PWM5_TZ_IRQHandler
	B PWM5_TZ_IRQHandler

	PUBWEAK PWM6_IRQHandler
PWM6_IRQHandler
	B PWM6_IRQHandler

	PUBWEAK PWM6_HD_IRQHandler
PWM6_HD_IRQHandler
	B PWM6_HD_IRQHandler

	PUBWEAK PWM6_TZ_IRQHandler
PWM6_TZ_IRQHandler
	B PWM6_TZ_IRQHandler

	PUBWEAK PWM7_IRQHandler
PWM7_IRQHandler
	B PWM7_IRQHandler

	PUBWEAK PWM7_HD_IRQHandler
PWM7_HD_IRQHandler
	B PWM7_HD_IRQHandler

	PUBWEAK PWM7_TZ_IRQHandler
PWM7_TZ_IRQHandler
	B PWM7_TZ_IRQHandler

	PUBWEAK PWM8_IRQHandler
PWM8_IRQHandler
	B PWM8_IRQHandler

	PUBWEAK PWM8_HD_IRQHandler
PWM8_HD_IRQHandler
	B PWM8_HD_IRQHandler

	PUBWEAK PWM8_TZ_IRQHandler
PWM8_TZ_IRQHandler
	B PWM8_TZ_IRQHandler

	PUBWEAK PWM9_IRQHandler
PWM9_IRQHandler
	B PWM9_IRQHandler

	PUBWEAK PWM9_HD_IRQHandler
PWM9_HD_IRQHandler
	B PWM9_HD_IRQHandler

	PUBWEAK PWM9_TZ_IRQHandler
PWM9_TZ_IRQHandler
	B PWM9_TZ_IRQHandler

	PUBWEAK QEP0_IRQHandler
QEP0_IRQHandler
	B QEP0_IRQHandler

	PUBWEAK QEP1_IRQHandler
QEP1_IRQHandler
	B QEP1_IRQHandler

	PUBWEAK QEP2_IRQHandler
QEP2_IRQHandler
	B QEP2_IRQHandler

	PUBWEAK QEP3_IRQHandler
QEP3_IRQHandler
	B QEP3_IRQHandler

	PUBWEAK ADC_SEQ0_IRQHandler
ADC_SEQ0_IRQHandler
	B ADC_SEQ0_IRQHandler

	PUBWEAK ADC_SEQ1_IRQHandler
ADC_SEQ1_IRQHandler
	B ADC_SEQ1_IRQHandler

	PUBWEAK ADC_SEQ2_IRQHandler
ADC_SEQ2_IRQHandler
	B ADC_SEQ2_IRQHandler

	PUBWEAK ADC_SEQ3_IRQHandler
ADC_SEQ3_IRQHandler
	B ADC_SEQ3_IRQHandler

	PUBWEAK ADC_SEQ4_IRQHandler
ADC_SEQ4_IRQHandler
	B ADC_SEQ4_IRQHandler

	PUBWEAK ADC_SEQ5_IRQHandler
ADC_SEQ5_IRQHandler
	B ADC_SEQ5_IRQHandler

	PUBWEAK ADC_SEQ6_IRQHandler
ADC_SEQ6_IRQHandler
	B ADC_SEQ6_IRQHandler

	PUBWEAK ADC_SEQ7_IRQHandler
ADC_SEQ7_IRQHandler
	B ADC_SEQ7_IRQHandler

	PUBWEAK ADC_DC_IRQHandler
ADC_DC_IRQHandler
	B ADC_DC_IRQHandler

	PUBWEAK ETH_IRQHandler
ETH_IRQHandler
	B ETH_IRQHandler

	PUBWEAK CAN0_IRQHandler
CAN0_IRQHandler
	B CAN0_IRQHandler

	PUBWEAK CAN1_IRQHandler
CAN1_IRQHandler
	B CAN1_IRQHandler

	PUBWEAK CAN2_IRQHandler
CAN2_IRQHandler
	B CAN2_IRQHandler

	PUBWEAK CAN3_IRQHandler
CAN3_IRQHandler
	B CAN3_IRQHandler

	PUBWEAK CAN4_IRQHandler
CAN4_IRQHandler
	B CAN4_IRQHandler

	PUBWEAK CAN5_IRQHandler
CAN5_IRQHandler
	B CAN5_IRQHandler

	PUBWEAK CAN6_IRQHandler
CAN6_IRQHandler
	B CAN6_IRQHandler

	PUBWEAK CAN7_IRQHandler
CAN7_IRQHandler
	B CAN7_IRQHandler

	PUBWEAK CAN8_IRQHandler
CAN8_IRQHandler
	B CAN8_IRQHandler

	PUBWEAK CAN9_IRQHandler
CAN9_IRQHandler
	B CAN9_IRQHandler

	PUBWEAK CAN10_IRQHandler
CAN10_IRQHandler
	B CAN10_IRQHandler

	PUBWEAK CAN11_IRQHandler
CAN11_IRQHandler
	B CAN11_IRQHandler

	PUBWEAK CAN12_IRQHandler
CAN12_IRQHandler
	B CAN12_IRQHandler

	PUBWEAK CAN13_IRQHandler
CAN13_IRQHandler
	B CAN13_IRQHandler

	PUBWEAK CAN14_IRQHandler
CAN14_IRQHandler
	B CAN14_IRQHandler

	PUBWEAK CAN15_IRQHandler
CAN15_IRQHandler
	B CAN15_IRQHandler

	PUBWEAK FPU_IRQHandler
FPU_IRQHandler
	B FPU_IRQHandler

	PUBWEAK TMU_IRQHandler
TMU_IRQHandler
	B TMU_IRQHandler

	PUBWEAK LAU_IRQHandler
LAU_IRQHandler
	B LAU_IRQHandler

	PUBWEAK SDFM_IRQHandler
SDFM_IRQHandler
	B SDFM_IRQHandler

	PUBWEAK OWI0_IRQHandler
OWI0_IRQHandler
	B OWI0_IRQHandler

	PUBWEAK OWI1_IRQHandler
OWI1_IRQHandler
	B OWI1_IRQHandler



	PUBWEAK Unknown_INTR
Unknown_INTR
	B       Unknown_INTR

	END
