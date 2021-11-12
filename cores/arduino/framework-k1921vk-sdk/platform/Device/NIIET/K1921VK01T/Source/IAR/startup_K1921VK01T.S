///*****************************************************************************
// * @file:    startup_K1921VK01T.S
// * @author   NIIET
// * @version: V2.0
// * @date:    17.08.2018
// * @brief:   K1921VK01T startup file for IAR
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
// * FILE startup_K1921VK01T.S
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
		DCD     WWDG_IRQHandler ; WWDG interrupt
		DCD     I2C0_IRQHandler ; I2C_0 interrupt
		DCD     I2C1_IRQHandler ; I2C_1 interrupt
		DCD     TIM0_IRQHandler ; TIMER0 interrupt
		DCD     TIM1_IRQHandler ; TIMER1 interrupt
		DCD     TIM2_IRQHandler ; TIMER2 interrupt
		DCD     DMA_Stream0_IRQHandler ; DMA_Stream0 interrupt
		DCD     DMA_Stream1_IRQHandler ; DMA_Stream1 interrupt
		DCD     DMA_Stream2_IRQHandler ; DMA_Stream2 interrupt
		DCD     DMA_Stream3_IRQHandler ; DMA_Stream3 interrupt
		DCD     DMA_Stream4_IRQHandler ; DMA_Stream4 interrupt
		DCD     DMA_Stream5_IRQHandler ; DMA_Stream5 interrupt
		DCD     DMA_Stream6_IRQHandler ; DMA_Stream6 interrupt
		DCD     DMA_Stream7_IRQHandler ; DMA_Stream7 interrupt
		DCD     DMA_Stream8_IRQHandler ; DMA_Stream8 interrupt
		DCD     DMA_Stream9_IRQHandler ; DMA_Stream9 interrupt
		DCD     DMA_Stream10_IRQHandler ; DMA_Stream10 interrupt
		DCD     DMA_Stream11_IRQHandler ; DMA_Stream11 interrupt
		DCD     DMA_Stream12_IRQHandler ; DMA_Stream12 interrupt
		DCD     DMA_Stream13_IRQHandler ; DMA_Stream13 interrupt
		DCD     DMA_Stream14_IRQHandler ; DMA_Stream14 interrupt
		DCD     DMA_Stream15_IRQHandler ; DMA_Stream15 interrupt
		DCD     DMA_Stream16_IRQHandler ; DMA_Stream16 interrupt
		DCD     DMA_Stream17_IRQHandler ; DMA_Stream17 interrupt
		DCD     DMA_Stream18_IRQHandler ; DMA_Stream18 interrupt
		DCD     DMA_Stream19_IRQHandler ; DMA_Stream19 interrupt
		DCD     DMA_Stream20_IRQHandler ; DMA_Stream20 interrupt
		DCD     DMA_Stream21_IRQHandler ; DMA_Stream21 interrupt
		DCD     DMA_Stream22_IRQHandler ; DMA_Stream22 interrupt
		DCD     DMA_Stream23_IRQHandler ; DMA_Stream23 interrupt
		DCD     UART0_MX_IRQHandler ; UART 0 interrupt
		DCD     UART0_RX_IRQHandler ; UART 0 interrupt
		DCD     UART0_TX_IRQHandler ; UART 0 interrupt
		DCD     UART0_RT_IRQHandler ; UART 0 interrupt
		DCD     UART0_E_IRQHandler ; UART 0 interrupt
		DCD     UART0_IRQHandler ; UART 0 interrupt
		DCD     UART1_MX_IRQHandler ; UART 1 interrupt
		DCD     UART1_RX_IRQHandler ; UART 1 interrupt
		DCD     UART1_TX_IRQHandler ; UART 1 interrupt
		DCD     UART1_RT_IRQHandler ; UART 1 interrupt
		DCD     UART1_E_IRQHandler ; UART 1 interrupt
		DCD     UART1_IRQHandler ; UART 1 interrupt
		DCD     UART2_MX_IRQHandler ; UART 2 interrupt
		DCD     UART2_RX_IRQHandler ; UART 2 interrupt
		DCD     UART2_TX_IRQHandler ; UART 2 interrupt
		DCD     UART2_RT_IRQHandler ; UART 2 interrupt
		DCD     UART2_E_IRQHandler ; UART 2 interrupt
		DCD     UART2_IRQHandler ; UART 2 interrupt
		DCD     UART3_MX_IRQHandler ; UART 3 interrupt
		DCD     UART3_RX_IRQHandler ; UART 3 interrupt
		DCD     UART3_TX_IRQHandler ; UART 3 interrupt
		DCD     UART3_RT_IRQHandler ; UART 3 interrupt
		DCD     UART3_E_IRQHandler ; UART 3 interrupt
		DCD     UART3_IRQHandler ; UART 3 interrupt
		DCD     PWM0_IRQHandler ; PWM 0 general interrupt
		DCD     PWM0_HD_IRQHandler ; PWM HR 0 interrupt
		DCD     PWM0_TZ_IRQHandler ; TZ PWM 0 interrupt
		DCD     PWM1_IRQHandler ; PWM 1 general interrupt
		DCD     PWM1_HD_IRQHandler ; PWM HR 1 general interrupt
		DCD     PWM1_TZ_IRQHandler ; TZ PWM 1 interrupt
		DCD     PWM2_IRQHandler ; PWM 2 general interrupt
		DCD     PWM2_HD_IRQHandler ; PWM HR 2 general interrupt
		DCD     PWM2_TZ_IRQHandler ; TZ PWM 2 interrupt
		DCD     PWM3_IRQHandler ; PWM 3 general interrupt
		DCD     PWM3_HD_IRQHandler ; PWM HR 3 general interrupt
		DCD     PWM3_TZ_IRQHandler ; TZ PWM 3 interrupt
		DCD     PWM4_IRQHandler ; PWM 4 general interrupt
		DCD     PWM4_HD_IRQHandler ; PWM HR 4 general interrupt
		DCD     PWM4_TZ_IRQHandler ; TZ PWM 4 interrupt
		DCD     PWM5_IRQHandler ; PWM 5 general interrupt
		DCD     PWM5_HD_IRQHandler ; PWM HR 5 general interrupt
		DCD     PWM5_TZ_IRQHandler ; TZ PWM 5 interrupt
		DCD     PWM6_IRQHandler ; PWM 6 general interrupt
		DCD     PWM6_HD_IRQHandler ; PWM HR 6 general interrupt
		DCD     PWM6_TZ_IRQHandler ; TZ PWM 6 interrupt
		DCD     PWM7_IRQHandler ; PWM 7 general interrupt
		DCD     PWM7_HD_IRQHandler ; PWM HR 7 general interrupt
		DCD     PWM7_TZ_IRQHandler ; TZ PWM 7 interrupt
		DCD     PWM8_IRQHandler ; PWM 8 general interrupt
		DCD     PWM8_HD_IRQHandler ; PWM HR 8 general interrupt
		DCD     PWM8_TZ_IRQHandler ; TZ PWM 8 interrupt
		DCD     ADC_SEQ0_IRQHandler ; ADC_0 interrupt
		DCD     ADC_SEQ1_IRQHandler ; ADC_1 interrupt
		DCD     ADC_SEQ2_IRQHandler ; ADC_2 interrupt
		DCD     ADC_SEQ3_IRQHandler ; ADC_3 interrupt
		DCD     ADC_SEQ4_IRQHandler ; ADC_4 interrupt
		DCD     ADC_SEQ5_IRQHandler ; ADC_5 interrupt
		DCD     ADC_SEQ6_IRQHandler ; ADC_6 interrupt
		DCD     ADC_SEQ7_IRQHandler ; ADC_7 interrupt
		DCD     ADC_CompInt_IRQHandler ; ADC Comparator interrupt
		DCD     CAP0_IRQHandler ; CAP_0 interrupt
		DCD     CAP1_IRQHandler ; CAP_1 interrupt
		DCD     CAP2_IRQHandler ; CAP_2 interrupt
		DCD     CAP3_IRQHandler ; CAP_3 interrupt
		DCD     CAP4_IRQHandler ; CAP_4 interrupt
		DCD     CAP5_IRQHandler ; CAP_5 interrupt
		DCD     QEP0_IRQHandler ; QEP_0 interrupt
		DCD     QEP1_IRQHandler ; QEP_1 interrupt
		DCD     BootFlash_IRQHandler ; BootFlash interrupt
		DCD     CMP0_IRQHandler ; CMP 0 interrupt
		DCD     CMP1_IRQHandler ; CMP 1 interrupt
		DCD     CMP2_IRQHandler ; CMP 2 interrupt
		DCD     SPI0_IRQHandler ; SPI_0 interrupt
		DCD     SPI1_IRQHandler ; SPI_1 interrupt
		DCD     SPI2_IRQHandler ; SPI_2 interrupt
		DCD     SPI3_IRQHandler ; SPI_3 interrupt
		DCD     UserFlash_IRQHandler ; UserFlash interrupt
		DCD     GPIOA_IRQHandler ; GPIO À interrupt
		DCD     GPIOB_IRQHandler ; GPIO B interrupt
		DCD     GPIOC_IRQHandler ; GPIO C interrupt
		DCD     GPIOD_IRQHandler ; GPIO D interrupt
		DCD     GPIOE_IRQHandler ; GPIO E interrupt
		DCD     GPIOF_IRQHandler ; GPIO F interrupt
		DCD     GPIOG_IRQHandler ; GPIO G interrupt
		DCD     GPIOH_IRQHandler ; GPIO H interrupt
		DCD     Ethernet_IRQHandler ; Ethernet interrupt
		DCD     CAN0_IRQHandler ; CAN 0 interrupt
		DCD     CAN1_IRQHandler ; CAN  1 interrupt
		DCD     CAN2_IRQHandler ; CAN  2 interrupt
		DCD     CAN3_IRQHandler ; CAN  3 interrupt
		DCD     CAN4_IRQHandler ; CAN  4 interrupt
		DCD     CAN5_IRQHandler ; CAN  5 interrupt
		DCD     CAN6_IRQHandler ; CAN  6 interrupt
		DCD     CAN7_IRQHandler ; CAN  7 interrupt
		DCD     CAN8_IRQHandler ; CAN  8 interrupt
		DCD     CAN9_IRQHandler ; CAN  9 interrupt
		DCD     CAN10_IRQHandler ; CAN 10 interrupt
		DCD     CAN11_IRQHandler ; CAN 11 interrupt
		DCD     CAN12_IRQHandler ; CAN 12 interrupt
		DCD     CAN13_IRQHandler ; CAN 13 interrupt
		DCD     CAN14_IRQHandler ; CAN 14 interrupt
		DCD     CAN15_IRQHandler ; CAN 15 interrupt
		DCD     RTC_IRQHandler ; RTC interrupt
		DCD     USBOTG_IRQHandler ; USB OTG interrupt

	REPT 106
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
	PUBWEAK WWDG_IRQHandler
WWDG_IRQHandler
	B WWDG_IRQHandler

	PUBWEAK I2C0_IRQHandler
I2C0_IRQHandler
	B I2C0_IRQHandler

	PUBWEAK I2C1_IRQHandler
I2C1_IRQHandler
	B I2C1_IRQHandler

	PUBWEAK TIM0_IRQHandler
TIM0_IRQHandler
	B TIM0_IRQHandler

	PUBWEAK TIM1_IRQHandler
TIM1_IRQHandler
	B TIM1_IRQHandler

	PUBWEAK TIM2_IRQHandler
TIM2_IRQHandler
	B TIM2_IRQHandler

	PUBWEAK DMA_Stream0_IRQHandler
DMA_Stream0_IRQHandler
	B DMA_Stream0_IRQHandler

	PUBWEAK DMA_Stream1_IRQHandler
DMA_Stream1_IRQHandler
	B DMA_Stream1_IRQHandler

	PUBWEAK DMA_Stream2_IRQHandler
DMA_Stream2_IRQHandler
	B DMA_Stream2_IRQHandler

	PUBWEAK DMA_Stream3_IRQHandler
DMA_Stream3_IRQHandler
	B DMA_Stream3_IRQHandler

	PUBWEAK DMA_Stream4_IRQHandler
DMA_Stream4_IRQHandler
	B DMA_Stream4_IRQHandler

	PUBWEAK DMA_Stream5_IRQHandler
DMA_Stream5_IRQHandler
	B DMA_Stream5_IRQHandler

	PUBWEAK DMA_Stream6_IRQHandler
DMA_Stream6_IRQHandler
	B DMA_Stream6_IRQHandler

	PUBWEAK DMA_Stream7_IRQHandler
DMA_Stream7_IRQHandler
	B DMA_Stream7_IRQHandler

	PUBWEAK DMA_Stream8_IRQHandler
DMA_Stream8_IRQHandler
	B DMA_Stream8_IRQHandler

	PUBWEAK DMA_Stream9_IRQHandler
DMA_Stream9_IRQHandler
	B DMA_Stream9_IRQHandler

	PUBWEAK DMA_Stream10_IRQHandler
DMA_Stream10_IRQHandler
	B DMA_Stream10_IRQHandler

	PUBWEAK DMA_Stream11_IRQHandler
DMA_Stream11_IRQHandler
	B DMA_Stream11_IRQHandler

	PUBWEAK DMA_Stream12_IRQHandler
DMA_Stream12_IRQHandler
	B DMA_Stream12_IRQHandler

	PUBWEAK DMA_Stream13_IRQHandler
DMA_Stream13_IRQHandler
	B DMA_Stream13_IRQHandler

	PUBWEAK DMA_Stream14_IRQHandler
DMA_Stream14_IRQHandler
	B DMA_Stream14_IRQHandler

	PUBWEAK DMA_Stream15_IRQHandler
DMA_Stream15_IRQHandler
	B DMA_Stream15_IRQHandler

	PUBWEAK DMA_Stream16_IRQHandler
DMA_Stream16_IRQHandler
	B DMA_Stream16_IRQHandler

	PUBWEAK DMA_Stream17_IRQHandler
DMA_Stream17_IRQHandler
	B DMA_Stream17_IRQHandler

	PUBWEAK DMA_Stream18_IRQHandler
DMA_Stream18_IRQHandler
	B DMA_Stream18_IRQHandler

	PUBWEAK DMA_Stream19_IRQHandler
DMA_Stream19_IRQHandler
	B DMA_Stream19_IRQHandler

	PUBWEAK DMA_Stream20_IRQHandler
DMA_Stream20_IRQHandler
	B DMA_Stream20_IRQHandler

	PUBWEAK DMA_Stream21_IRQHandler
DMA_Stream21_IRQHandler
	B DMA_Stream21_IRQHandler

	PUBWEAK DMA_Stream22_IRQHandler
DMA_Stream22_IRQHandler
	B DMA_Stream22_IRQHandler

	PUBWEAK DMA_Stream23_IRQHandler
DMA_Stream23_IRQHandler
	B DMA_Stream23_IRQHandler

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

	PUBWEAK ADC_CompInt_IRQHandler
ADC_CompInt_IRQHandler
	B ADC_CompInt_IRQHandler

	PUBWEAK CAP0_IRQHandler
CAP0_IRQHandler
	B CAP0_IRQHandler

	PUBWEAK CAP1_IRQHandler
CAP1_IRQHandler
	B CAP1_IRQHandler

	PUBWEAK CAP2_IRQHandler
CAP2_IRQHandler
	B CAP2_IRQHandler

	PUBWEAK CAP3_IRQHandler
CAP3_IRQHandler
	B CAP3_IRQHandler

	PUBWEAK CAP4_IRQHandler
CAP4_IRQHandler
	B CAP4_IRQHandler

	PUBWEAK CAP5_IRQHandler
CAP5_IRQHandler
	B CAP5_IRQHandler

	PUBWEAK QEP0_IRQHandler
QEP0_IRQHandler
	B QEP0_IRQHandler

	PUBWEAK QEP1_IRQHandler
QEP1_IRQHandler
	B QEP1_IRQHandler

	PUBWEAK BootFlash_IRQHandler
BootFlash_IRQHandler
	B BootFlash_IRQHandler

	PUBWEAK CMP0_IRQHandler
CMP0_IRQHandler
	B CMP0_IRQHandler

	PUBWEAK CMP1_IRQHandler
CMP1_IRQHandler
	B CMP1_IRQHandler

	PUBWEAK CMP2_IRQHandler
CMP2_IRQHandler
	B CMP2_IRQHandler

	PUBWEAK SPI0_IRQHandler
SPI0_IRQHandler
	B SPI0_IRQHandler

	PUBWEAK SPI1_IRQHandler
SPI1_IRQHandler
	B SPI1_IRQHandler

	PUBWEAK SPI2_IRQHandler
SPI2_IRQHandler
	B SPI2_IRQHandler

	PUBWEAK SPI3_IRQHandler
SPI3_IRQHandler
	B SPI3_IRQHandler

	PUBWEAK UserFlash_IRQHandler
UserFlash_IRQHandler
	B UserFlash_IRQHandler

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

	PUBWEAK Ethernet_IRQHandler
Ethernet_IRQHandler
	B Ethernet_IRQHandler

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

	PUBWEAK RTC_IRQHandler
RTC_IRQHandler
	B RTC_IRQHandler

	PUBWEAK USBOTG_IRQHandler
USBOTG_IRQHandler
	B USBOTG_IRQHandler



	PUBWEAK Unknown_INTR
Unknown_INTR
	B       Unknown_INTR

	END
