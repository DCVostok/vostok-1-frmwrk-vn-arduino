/*****************************************************************************
 * @file:    startup_K1921VK035.S
 * @author   NIIET
 * @version: V1.7
 * @date:    02.05.2018
 * @brief:   K1921VK035 startup file for GCC
 *****************************************************************************
 * <br><br>
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, NIIET NOT BE HELD LIABLE FOR ANY DIRECT,
 * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2018 NIIET </center></h2>
 *****************************************************************************
 * FILE startup_K1921VK035.S
 */

	.syntax	unified
	.arch	armv7e-m

	.section .stack
	.align	3
#ifdef __STACK_SIZE
	.equ	Stack_Size, __STACK_SIZE
#else
	.equ	Stack_Size, 0xc00
#endif
	.globl	__StackTop
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

	.section .heap
	.align	3
#ifdef __HEAP_SIZE
	.equ	Heap_Size, __HEAP_SIZE
#else
	.equ	Heap_Size, 0
#endif
	.globl	__HeapBase
	.globl	__HeapLimit
__HeapBase:
	.if	Heap_Size
	.space	Heap_Size
	.endif
	.size	__HeapBase, . - __HeapBase
__HeapLimit:
	.size	__HeapLimit, . - __HeapLimit

	.section .isr_vector
	.align	2
	.globl	__isr_vector
__isr_vector:
	.long	__StackTop            /* Top of Stack */
	.long	Reset_Handler         /* Reset Handler */
	.long	NMI_Handler           /* NMI Handler */
	.long	HardFault_Handler     /* Hard Fault Handler */
	.long	MemManage_Handler     /* MPU Fault Handler */
	.long	BusFault_Handler      /* Bus Fault Handler */
	.long	UsageFault_Handler    /* Usage Fault Handler */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	SVC_Handler           /* SVCall Handler */
	.long	DebugMon_Handler      /* Debug Monitor Handler */
	.long	0                     /* Reserved */
	.long	PendSV_Handler        /* PendSV Handler */
	.long	SysTick_Handler       /* SysTick Handler */

    /* External interrupts */
        .long   WDT_IRQHandler
        .long   RCU_IRQHandler
        .long   MFLASH_IRQHandler
        .long   GPIOA_IRQHandler
        .long   GPIOB_IRQHandler
        .long   DMA_CH0_IRQHandler
        .long   DMA_CH1_IRQHandler
        .long   DMA_CH2_IRQHandler
        .long   DMA_CH3_IRQHandler
        .long   DMA_CH4_IRQHandler
        .long   DMA_CH5_IRQHandler
        .long   DMA_CH6_IRQHandler
        .long   DMA_CH7_IRQHandler
        .long   DMA_CH8_IRQHandler
        .long   DMA_CH9_IRQHandler
        .long   DMA_CH10_IRQHandler
        .long   DMA_CH11_IRQHandler
        .long   DMA_CH12_IRQHandler
        .long   DMA_CH13_IRQHandler
        .long   DMA_CH14_IRQHandler
        .long   DMA_CH15_IRQHandler
        .long   TMR0_IRQHandler
        .long   TMR1_IRQHandler
        .long   TMR2_IRQHandler
        .long   TMR3_IRQHandler
        .long   UART0_TD_IRQHandler
        .long   UART0_RX_IRQHandler
        .long   UART0_TX_IRQHandler
        .long   UART0_E_RT_IRQHandler
        .long   UART1_TD_IRQHandler
        .long   UART1_RX_IRQHandler
        .long   UART1_TX_IRQHandler
        .long   UART1_E_RT_IRQHandler
        .long   SPI_RO_RT_IRQHandler
        .long   SPI_RX_IRQHandler
        .long   SPI_TX_IRQHandler
        .long   I2C_IRQHandler
        .long   ECAP0_IRQHandler
        .long   ECAP1_IRQHandler
        .long   ECAP2_IRQHandler
        .long   PWM0_IRQHandler
        .long   PWM0_HD_IRQHandler
        .long   PWM0_TZ_IRQHandler
        .long   PWM1_IRQHandler
        .long   PWM1_HD_IRQHandler
        .long   PWM1_TZ_IRQHandler
        .long   PWM2_IRQHandler
        .long   PWM2_HD_IRQHandler
        .long   PWM2_TZ_IRQHandler
        .long   QEP_IRQHandler
        .long   ADC_SEQ0_IRQHandler
        .long   ADC_SEQ1_IRQHandler
        .long   ADC_DC_IRQHandler
        .long   CAN0_IRQHandler
        .long   CAN1_IRQHandler
        .long   CAN2_IRQHandler
        .long   CAN3_IRQHandler
        .long   CAN4_IRQHandler
        .long   CAN5_IRQHandler
        .long   CAN6_IRQHandler
        .long   CAN7_IRQHandler
        .long   CAN8_IRQHandler
        .long   CAN9_IRQHandler
        .long   CAN10_IRQHandler
        .long   CAN11_IRQHandler
        .long   CAN12_IRQHandler
        .long   CAN13_IRQHandler
        .long   CAN14_IRQHandler
        .long   CAN15_IRQHandler
        .long   FPU_IRQHandler


	.size	__isr_vector, . - __isr_vector

	.text
	.thumb
	.thumb_func
	.align	2
	.globl	Reset_Handler
	.type	Reset_Handler, %function
Reset_Handler:
/*  Firstly it copies data from read only memory to RAM. 
 *  Multiple sections scheme:
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of triplets, each of which specify:
 *    offset 0: LMA of start of a section to copy from
 *    offset 4: VMA of start of a section to copy to
 *    offset 8: size of the section to copy. Must be multiply of 4
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
    ldr r4, =__copy_table_start__
    ldr r5, =__copy_table_end__

.L_loop0:
    cmp r4, r5
    bge .L_loop0_done
    ldr r1, [r4]
    ldr r2, [r4, #4]
    ldr r3, [r4, #8]

.L_loop0_0:
    subs    r3, #4
    ittt    ge
    ldrge   r0, [r1, r3]
    strge   r0, [r2, r3]
    bge .L_loop0_0

    adds    r4, #12
    b   .L_loop0

.L_loop0_done:

/*  This part of work usually is done in C library startup code. Otherwise,
 *  define this macro to enable it in this startup.
 *
 *  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of tuples specifying:
 *    offset 0: Start of a BSS section
 *    offset 4: Size of this BSS section. Must be multiply of 4
 */
    ldr r3, =__zero_table_start__
    ldr r4, =__zero_table_end__

.L_loop2:
    cmp r3, r4
    bge .L_loop2_done
    ldr r1, [r3]
    ldr r2, [r3, #4]
    movs    r0, 0

.L_loop2_0:
    subs    r2, #4
    itt ge
    strge   r0, [r1, r2]
    bge .L_loop2_0

    adds    r3, #8
    b   .L_loop2
.L_loop2_done:

#ifndef __NO_SYSTEM_INIT
    bl  SystemInit
#endif

#ifndef __START
#define __START _start
#endif
    bl  __START

	.pool
	.size	Reset_Handler, . - Reset_Handler

	.align	1
	.thumb_func
	.weak	Default_Handler
	.type	Default_Handler, %function
Default_Handler:
	b	.
	.size	Default_Handler, . - Default_Handler

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
	.macro	def_irq_handler	handler_name
	.weak	\handler_name
	.set	\handler_name, Default_Handler
	.endm

	def_irq_handler	NMI_Handler
	def_irq_handler	HardFault_Handler
	def_irq_handler	MemManage_Handler
	def_irq_handler	BusFault_Handler
	def_irq_handler	UsageFault_Handler
	def_irq_handler	SVC_Handler
	def_irq_handler	DebugMon_Handler
	def_irq_handler	PendSV_Handler
	def_irq_handler	SysTick_Handler

    /* External Interrupt Handlers */
        def_irq_handler WDT_IRQHandler
        def_irq_handler RCU_IRQHandler
        def_irq_handler MFLASH_IRQHandler
        def_irq_handler GPIOA_IRQHandler
        def_irq_handler GPIOB_IRQHandler
        def_irq_handler DMA_CH0_IRQHandler
        def_irq_handler DMA_CH1_IRQHandler
        def_irq_handler DMA_CH2_IRQHandler
        def_irq_handler DMA_CH3_IRQHandler
        def_irq_handler DMA_CH4_IRQHandler
        def_irq_handler DMA_CH5_IRQHandler
        def_irq_handler DMA_CH6_IRQHandler
        def_irq_handler DMA_CH7_IRQHandler
        def_irq_handler DMA_CH8_IRQHandler
        def_irq_handler DMA_CH9_IRQHandler
        def_irq_handler DMA_CH10_IRQHandler
        def_irq_handler DMA_CH11_IRQHandler
        def_irq_handler DMA_CH12_IRQHandler
        def_irq_handler DMA_CH13_IRQHandler
        def_irq_handler DMA_CH14_IRQHandler
        def_irq_handler DMA_CH15_IRQHandler
        def_irq_handler TMR0_IRQHandler
        def_irq_handler TMR1_IRQHandler
        def_irq_handler TMR2_IRQHandler
        def_irq_handler TMR3_IRQHandler
        def_irq_handler UART0_TD_IRQHandler
        def_irq_handler UART0_RX_IRQHandler
        def_irq_handler UART0_TX_IRQHandler
        def_irq_handler UART0_E_RT_IRQHandler
        def_irq_handler UART1_TD_IRQHandler
        def_irq_handler UART1_RX_IRQHandler
        def_irq_handler UART1_TX_IRQHandler
        def_irq_handler UART1_E_RT_IRQHandler
        def_irq_handler SPI_RO_RT_IRQHandler
        def_irq_handler SPI_RX_IRQHandler
        def_irq_handler SPI_TX_IRQHandler
        def_irq_handler I2C_IRQHandler
        def_irq_handler ECAP0_IRQHandler
        def_irq_handler ECAP1_IRQHandler
        def_irq_handler ECAP2_IRQHandler
        def_irq_handler PWM0_IRQHandler
        def_irq_handler PWM0_HD_IRQHandler
        def_irq_handler PWM0_TZ_IRQHandler
        def_irq_handler PWM1_IRQHandler
        def_irq_handler PWM1_HD_IRQHandler
        def_irq_handler PWM1_TZ_IRQHandler
        def_irq_handler PWM2_IRQHandler
        def_irq_handler PWM2_HD_IRQHandler
        def_irq_handler PWM2_TZ_IRQHandler
        def_irq_handler QEP_IRQHandler
        def_irq_handler ADC_SEQ0_IRQHandler
        def_irq_handler ADC_SEQ1_IRQHandler
        def_irq_handler ADC_DC_IRQHandler
        def_irq_handler CAN0_IRQHandler
        def_irq_handler CAN1_IRQHandler
        def_irq_handler CAN2_IRQHandler
        def_irq_handler CAN3_IRQHandler
        def_irq_handler CAN4_IRQHandler
        def_irq_handler CAN5_IRQHandler
        def_irq_handler CAN6_IRQHandler
        def_irq_handler CAN7_IRQHandler
        def_irq_handler CAN8_IRQHandler
        def_irq_handler CAN9_IRQHandler
        def_irq_handler CAN10_IRQHandler
        def_irq_handler CAN11_IRQHandler
        def_irq_handler CAN12_IRQHandler
        def_irq_handler CAN13_IRQHandler
        def_irq_handler CAN14_IRQHandler
        def_irq_handler CAN15_IRQHandler
        def_irq_handler FPU_IRQHandler


	.end
