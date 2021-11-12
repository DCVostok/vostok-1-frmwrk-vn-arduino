///*****************************************************************************
// * @file:    startup_K1921VK035.S
// * @author   NIIET
// * @version: V1.7
// * @date:    02.05.2018
// * @brief:   K1921VK035 startup file for IAR
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
// * FILE startup_K1921VK035.S
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
		DCD     MFLASH_IRQHandler ; MFLASH interrupt
		DCD     GPIOA_IRQHandler ; GPIO A interrupt
		DCD     GPIOB_IRQHandler ; GPIO B interrupt
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
		DCD     TMR0_IRQHandler ; Timer 0 interrupt
		DCD     TMR1_IRQHandler ; Timer 1 interrupt
		DCD     TMR2_IRQHandler ; Timer 2 interrupt
		DCD     TMR3_IRQHandler ; Timer 3 interrupt
		DCD     UART0_TD_IRQHandler ; UART0 Transmit Done interrupt
		DCD     UART0_RX_IRQHandler ; UART0 Recieve interrupt
		DCD     UART0_TX_IRQHandler ; UART0 Transmit interrupt
		DCD     UART0_E_RT_IRQHandler ; UART0 Error and Receive Timeout interrupt
		DCD     UART1_TD_IRQHandler ; UART1 Transmit Done interrupt
		DCD     UART1_RX_IRQHandler ; UART1 Recieve interrupt
		DCD     UART1_TX_IRQHandler ; UART1 Transmit interrupt
		DCD     UART1_E_RT_IRQHandler ; UART1 Error and Receive Timeout interrupt
		DCD     SPI_RO_RT_IRQHandler ; SPI RX FIFO overrun and Receive Timeout interrupt
		DCD     SPI_RX_IRQHandler ; SPI Receive interrupt
		DCD     SPI_TX_IRQHandler ; SPI Transmit interrupt
		DCD     I2C_IRQHandler ; I2C interrupt
		DCD     ECAP0_IRQHandler ; ECAP0 interrupt
		DCD     ECAP1_IRQHandler ; ECAP1 interrupt
		DCD     ECAP2_IRQHandler ; ECAP2 interrupt
		DCD     PWM0_IRQHandler ; PWM0 interrupt
		DCD     PWM0_HD_IRQHandler ; PWM0 HD interrupt
		DCD     PWM0_TZ_IRQHandler ; PWM0 TZ interrupt
		DCD     PWM1_IRQHandler ; PWM1 interrupt
		DCD     PWM1_HD_IRQHandler ; PWM1 HD interrupt
		DCD     PWM1_TZ_IRQHandler ; PWM1 TZ interrupt
		DCD     PWM2_IRQHandler ; PWM2 interrupt
		DCD     PWM2_HD_IRQHandler ; PWM2 HD interrupt
		DCD     PWM2_TZ_IRQHandler ; PWM2 TZ interrupt
		DCD     QEP_IRQHandler ; QEP interrupt
		DCD     ADC_SEQ0_IRQHandler ; ADC Sequencer 0 interrupt
		DCD     ADC_SEQ1_IRQHandler ; ADC Sequencer 1 interrupt
		DCD     ADC_DC_IRQHandler ; ADC Digital Comparator interrupt
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

	REPT 170
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

	PUBWEAK MFLASH_IRQHandler
MFLASH_IRQHandler
	B MFLASH_IRQHandler

	PUBWEAK GPIOA_IRQHandler
GPIOA_IRQHandler
	B GPIOA_IRQHandler

	PUBWEAK GPIOB_IRQHandler
GPIOB_IRQHandler
	B GPIOB_IRQHandler

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

	PUBWEAK UART0_TD_IRQHandler
UART0_TD_IRQHandler
	B UART0_TD_IRQHandler

	PUBWEAK UART0_RX_IRQHandler
UART0_RX_IRQHandler
	B UART0_RX_IRQHandler

	PUBWEAK UART0_TX_IRQHandler
UART0_TX_IRQHandler
	B UART0_TX_IRQHandler

	PUBWEAK UART0_E_RT_IRQHandler
UART0_E_RT_IRQHandler
	B UART0_E_RT_IRQHandler

	PUBWEAK UART1_TD_IRQHandler
UART1_TD_IRQHandler
	B UART1_TD_IRQHandler

	PUBWEAK UART1_RX_IRQHandler
UART1_RX_IRQHandler
	B UART1_RX_IRQHandler

	PUBWEAK UART1_TX_IRQHandler
UART1_TX_IRQHandler
	B UART1_TX_IRQHandler

	PUBWEAK UART1_E_RT_IRQHandler
UART1_E_RT_IRQHandler
	B UART1_E_RT_IRQHandler

	PUBWEAK SPI_RO_RT_IRQHandler
SPI_RO_RT_IRQHandler
	B SPI_RO_RT_IRQHandler

	PUBWEAK SPI_RX_IRQHandler
SPI_RX_IRQHandler
	B SPI_RX_IRQHandler

	PUBWEAK SPI_TX_IRQHandler
SPI_TX_IRQHandler
	B SPI_TX_IRQHandler

	PUBWEAK I2C_IRQHandler
I2C_IRQHandler
	B I2C_IRQHandler

	PUBWEAK ECAP0_IRQHandler
ECAP0_IRQHandler
	B ECAP0_IRQHandler

	PUBWEAK ECAP1_IRQHandler
ECAP1_IRQHandler
	B ECAP1_IRQHandler

	PUBWEAK ECAP2_IRQHandler
ECAP2_IRQHandler
	B ECAP2_IRQHandler

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

	PUBWEAK QEP_IRQHandler
QEP_IRQHandler
	B QEP_IRQHandler

	PUBWEAK ADC_SEQ0_IRQHandler
ADC_SEQ0_IRQHandler
	B ADC_SEQ0_IRQHandler

	PUBWEAK ADC_SEQ1_IRQHandler
ADC_SEQ1_IRQHandler
	B ADC_SEQ1_IRQHandler

	PUBWEAK ADC_DC_IRQHandler
ADC_DC_IRQHandler
	B ADC_DC_IRQHandler

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



	PUBWEAK Unknown_INTR
Unknown_INTR
	B       Unknown_INTR

	END
