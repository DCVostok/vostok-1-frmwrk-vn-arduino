;******************** (C) COPYRIGHT 2018 NIIET ********************
;* File Name          : startup_K1921VK028.s
;* Author             : NIIET 
;* Version            : V2.0
;* Date               : 16.08.2018
;* Description        : K1921VK028 vector table for MDK-ARM 
;*                      toolchain.  
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Configure the clock system
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM4 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>   
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, NIIET SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler
                DCD     NMI_Handler                ; NMI Handler
                DCD     HardFault_Handler          ; Hard Fault Handler
                DCD     MemManage_Handler          ; MPU Fault Handler
                DCD     BusFault_Handler           ; Bus Fault Handler
                DCD     UsageFault_Handler         ; Usage Fault Handler
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     0                          ; Reserved
                DCD     SVC_Handler                ; SVCall Handler
                DCD     DebugMon_Handler           ; Debug Monitor Handler
                DCD     0                          ; Reserved
                DCD     PendSV_Handler             ; PendSV Handler
                DCD     SysTick_Handler            ; SysTick Handler

                ; External Interrupts
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

__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
     IMPORT  __main
     IMPORT  SystemInit
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT     WDT_IRQHandler           [WEAK]
                EXPORT     RCU_IRQHandler           [WEAK]
                EXPORT     RTC_IRQHandler           [WEAK]
                EXPORT     MFLASH_IRQHandler           [WEAK]
                EXPORT     BFLASH_IRQHandler           [WEAK]
                EXPORT     GPIOA_IRQHandler           [WEAK]
                EXPORT     GPIOB_IRQHandler           [WEAK]
                EXPORT     GPIOC_IRQHandler           [WEAK]
                EXPORT     GPIOD_IRQHandler           [WEAK]
                EXPORT     GPIOE_IRQHandler           [WEAK]
                EXPORT     GPIOF_IRQHandler           [WEAK]
                EXPORT     GPIOG_IRQHandler           [WEAK]
                EXPORT     GPIOH_IRQHandler           [WEAK]
                EXPORT     GPIOJ_IRQHandler           [WEAK]
                EXPORT     GPIOK_IRQHandler           [WEAK]
                EXPORT     GPIOL_IRQHandler           [WEAK]
                EXPORT     GPIOM_IRQHandler           [WEAK]
                EXPORT     DMA_CH0_IRQHandler           [WEAK]
                EXPORT     DMA_CH1_IRQHandler           [WEAK]
                EXPORT     DMA_CH2_IRQHandler           [WEAK]
                EXPORT     DMA_CH3_IRQHandler           [WEAK]
                EXPORT     DMA_CH4_IRQHandler           [WEAK]
                EXPORT     DMA_CH5_IRQHandler           [WEAK]
                EXPORT     DMA_CH6_IRQHandler           [WEAK]
                EXPORT     DMA_CH7_IRQHandler           [WEAK]
                EXPORT     DMA_CH8_IRQHandler           [WEAK]
                EXPORT     DMA_CH9_IRQHandler           [WEAK]
                EXPORT     DMA_CH10_IRQHandler           [WEAK]
                EXPORT     DMA_CH11_IRQHandler           [WEAK]
                EXPORT     DMA_CH12_IRQHandler           [WEAK]
                EXPORT     DMA_CH13_IRQHandler           [WEAK]
                EXPORT     DMA_CH14_IRQHandler           [WEAK]
                EXPORT     DMA_CH15_IRQHandler           [WEAK]
                EXPORT     DMA_CH16_IRQHandler           [WEAK]
                EXPORT     DMA_CH17_IRQHandler           [WEAK]
                EXPORT     DMA_CH18_IRQHandler           [WEAK]
                EXPORT     DMA_CH19_IRQHandler           [WEAK]
                EXPORT     DMA_CH20_IRQHandler           [WEAK]
                EXPORT     DMA_CH21_IRQHandler           [WEAK]
                EXPORT     DMA_CH22_IRQHandler           [WEAK]
                EXPORT     DMA_CH23_IRQHandler           [WEAK]
                EXPORT     DMA_CH24_IRQHandler           [WEAK]
                EXPORT     DMA_CH25_IRQHandler           [WEAK]
                EXPORT     DMA_CH26_IRQHandler           [WEAK]
                EXPORT     DMA_CH27_IRQHandler           [WEAK]
                EXPORT     DMA_CH28_IRQHandler           [WEAK]
                EXPORT     DMA_CH29_IRQHandler           [WEAK]
                EXPORT     DMA_CH30_IRQHandler           [WEAK]
                EXPORT     DMA_CH31_IRQHandler           [WEAK]
                EXPORT     TMR0_IRQHandler           [WEAK]
                EXPORT     TMR1_IRQHandler           [WEAK]
                EXPORT     TMR2_IRQHandler           [WEAK]
                EXPORT     TMR3_IRQHandler           [WEAK]
                EXPORT     ETMR0_IRQHandler           [WEAK]
                EXPORT     ETMR1_IRQHandler           [WEAK]
                EXPORT     ETMR2_IRQHandler           [WEAK]
                EXPORT     ETMR3_IRQHandler           [WEAK]
                EXPORT     UART0_TD_IRQHandler           [WEAK]
                EXPORT     UART0_MX_IRQHandler           [WEAK]
                EXPORT     UART0_RX_IRQHandler           [WEAK]
                EXPORT     UART0_TX_IRQHandler           [WEAK]
                EXPORT     UART0_RT_IRQHandler           [WEAK]
                EXPORT     UART0_E_IRQHandler           [WEAK]
                EXPORT     UART0_IRQHandler           [WEAK]
                EXPORT     UART1_TD_IRQHandler           [WEAK]
                EXPORT     UART1_MX_IRQHandler           [WEAK]
                EXPORT     UART1_RX_IRQHandler           [WEAK]
                EXPORT     UART1_TX_IRQHandler           [WEAK]
                EXPORT     UART1_RT_IRQHandler           [WEAK]
                EXPORT     UART1_E_IRQHandler           [WEAK]
                EXPORT     UART1_IRQHandler           [WEAK]
                EXPORT     UART2_TD_IRQHandler           [WEAK]
                EXPORT     UART2_MX_IRQHandler           [WEAK]
                EXPORT     UART2_RX_IRQHandler           [WEAK]
                EXPORT     UART2_TX_IRQHandler           [WEAK]
                EXPORT     UART2_RT_IRQHandler           [WEAK]
                EXPORT     UART2_E_IRQHandler           [WEAK]
                EXPORT     UART2_IRQHandler           [WEAK]
                EXPORT     UART3_TD_IRQHandler           [WEAK]
                EXPORT     UART3_MX_IRQHandler           [WEAK]
                EXPORT     UART3_RX_IRQHandler           [WEAK]
                EXPORT     UART3_TX_IRQHandler           [WEAK]
                EXPORT     UART3_RT_IRQHandler           [WEAK]
                EXPORT     UART3_E_IRQHandler           [WEAK]
                EXPORT     UART3_IRQHandler           [WEAK]
                EXPORT     TUART0_RX_IRQHandler           [WEAK]
                EXPORT     TUART0_TX_IRQHandler           [WEAK]
                EXPORT     TUART0_RO_IRQHandler           [WEAK]
                EXPORT     TUART0_TO_IRQHandler           [WEAK]
                EXPORT     TUART0_IRQHandler           [WEAK]
                EXPORT     TUART1_RX_IRQHandler           [WEAK]
                EXPORT     TUART1_TX_IRQHandler           [WEAK]
                EXPORT     TUART1_RO_IRQHandler           [WEAK]
                EXPORT     TUART1_TO_IRQHandler           [WEAK]
                EXPORT     TUART1_IRQHandler           [WEAK]
                EXPORT     SPI0_IRQHandler           [WEAK]
                EXPORT     SPI0_RX_IRQHandler           [WEAK]
                EXPORT     SPI0_TX_IRQHandler           [WEAK]
                EXPORT     SPI0_RO_IRQHandler           [WEAK]
                EXPORT     SPI0_RT_IRQHandler           [WEAK]
                EXPORT     SPI1_IRQHandler           [WEAK]
                EXPORT     SPI1_RX_IRQHandler           [WEAK]
                EXPORT     SPI1_TX_IRQHandler           [WEAK]
                EXPORT     SPI1_RO_IRQHandler           [WEAK]
                EXPORT     SPI1_RT_IRQHandler           [WEAK]
                EXPORT     SPI2_IRQHandler           [WEAK]
                EXPORT     SPI2_RX_IRQHandler           [WEAK]
                EXPORT     SPI2_TX_IRQHandler           [WEAK]
                EXPORT     SPI2_RO_IRQHandler           [WEAK]
                EXPORT     SPI2_RT_IRQHandler           [WEAK]
                EXPORT     SPI3_IRQHandler           [WEAK]
                EXPORT     SPI3_RX_IRQHandler           [WEAK]
                EXPORT     SPI3_TX_IRQHandler           [WEAK]
                EXPORT     SPI3_RO_IRQHandler           [WEAK]
                EXPORT     SPI3_RT_IRQHandler           [WEAK]
                EXPORT     I2C0_IRQHandler           [WEAK]
                EXPORT     I2C1_IRQHandler           [WEAK]
                EXPORT     SPWR0_IRQHandler           [WEAK]
                EXPORT     SPWR1_IRQHandler           [WEAK]
                EXPORT     MILSTD0_IRQHandler           [WEAK]
                EXPORT     MILSTD1_IRQHandler           [WEAK]
                EXPORT     ECAP0_IRQHandler           [WEAK]
                EXPORT     ECAP1_IRQHandler           [WEAK]
                EXPORT     ECAP2_IRQHandler           [WEAK]
                EXPORT     ECAP3_IRQHandler           [WEAK]
                EXPORT     ECAP4_IRQHandler           [WEAK]
                EXPORT     ECAP5_IRQHandler           [WEAK]
                EXPORT     PWM0_IRQHandler           [WEAK]
                EXPORT     PWM0_HD_IRQHandler           [WEAK]
                EXPORT     PWM0_TZ_IRQHandler           [WEAK]
                EXPORT     PWM1_IRQHandler           [WEAK]
                EXPORT     PWM1_HD_IRQHandler           [WEAK]
                EXPORT     PWM1_TZ_IRQHandler           [WEAK]
                EXPORT     PWM2_IRQHandler           [WEAK]
                EXPORT     PWM2_HD_IRQHandler           [WEAK]
                EXPORT     PWM2_TZ_IRQHandler           [WEAK]
                EXPORT     PWM3_IRQHandler           [WEAK]
                EXPORT     PWM3_HD_IRQHandler           [WEAK]
                EXPORT     PWM3_TZ_IRQHandler           [WEAK]
                EXPORT     PWM4_IRQHandler           [WEAK]
                EXPORT     PWM4_HD_IRQHandler           [WEAK]
                EXPORT     PWM4_TZ_IRQHandler           [WEAK]
                EXPORT     PWM5_IRQHandler           [WEAK]
                EXPORT     PWM5_HD_IRQHandler           [WEAK]
                EXPORT     PWM5_TZ_IRQHandler           [WEAK]
                EXPORT     PWM6_IRQHandler           [WEAK]
                EXPORT     PWM6_HD_IRQHandler           [WEAK]
                EXPORT     PWM6_TZ_IRQHandler           [WEAK]
                EXPORT     PWM7_IRQHandler           [WEAK]
                EXPORT     PWM7_HD_IRQHandler           [WEAK]
                EXPORT     PWM7_TZ_IRQHandler           [WEAK]
                EXPORT     PWM8_IRQHandler           [WEAK]
                EXPORT     PWM8_HD_IRQHandler           [WEAK]
                EXPORT     PWM8_TZ_IRQHandler           [WEAK]
                EXPORT     PWM9_IRQHandler           [WEAK]
                EXPORT     PWM9_HD_IRQHandler           [WEAK]
                EXPORT     PWM9_TZ_IRQHandler           [WEAK]
                EXPORT     QEP0_IRQHandler           [WEAK]
                EXPORT     QEP1_IRQHandler           [WEAK]
                EXPORT     QEP2_IRQHandler           [WEAK]
                EXPORT     QEP3_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ0_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ1_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ2_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ3_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ4_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ5_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ6_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ7_IRQHandler           [WEAK]
                EXPORT     ADC_DC_IRQHandler           [WEAK]
                EXPORT     ETH_IRQHandler           [WEAK]
                EXPORT     CAN0_IRQHandler           [WEAK]
                EXPORT     CAN1_IRQHandler           [WEAK]
                EXPORT     CAN2_IRQHandler           [WEAK]
                EXPORT     CAN3_IRQHandler           [WEAK]
                EXPORT     CAN4_IRQHandler           [WEAK]
                EXPORT     CAN5_IRQHandler           [WEAK]
                EXPORT     CAN6_IRQHandler           [WEAK]
                EXPORT     CAN7_IRQHandler           [WEAK]
                EXPORT     CAN8_IRQHandler           [WEAK]
                EXPORT     CAN9_IRQHandler           [WEAK]
                EXPORT     CAN10_IRQHandler           [WEAK]
                EXPORT     CAN11_IRQHandler           [WEAK]
                EXPORT     CAN12_IRQHandler           [WEAK]
                EXPORT     CAN13_IRQHandler           [WEAK]
                EXPORT     CAN14_IRQHandler           [WEAK]
                EXPORT     CAN15_IRQHandler           [WEAK]
                EXPORT     FPU_IRQHandler           [WEAK]
                EXPORT     TMU_IRQHandler           [WEAK]
                EXPORT     LAU_IRQHandler           [WEAK]
                EXPORT     SDFM_IRQHandler           [WEAK]
                EXPORT     OWI0_IRQHandler           [WEAK]
                EXPORT     OWI1_IRQHandler           [WEAK]



WDT_IRQHandler         
RCU_IRQHandler         
RTC_IRQHandler         
MFLASH_IRQHandler         
BFLASH_IRQHandler         
GPIOA_IRQHandler         
GPIOB_IRQHandler         
GPIOC_IRQHandler         
GPIOD_IRQHandler         
GPIOE_IRQHandler         
GPIOF_IRQHandler         
GPIOG_IRQHandler         
GPIOH_IRQHandler         
GPIOJ_IRQHandler         
GPIOK_IRQHandler         
GPIOL_IRQHandler         
GPIOM_IRQHandler         
DMA_CH0_IRQHandler         
DMA_CH1_IRQHandler         
DMA_CH2_IRQHandler         
DMA_CH3_IRQHandler         
DMA_CH4_IRQHandler         
DMA_CH5_IRQHandler         
DMA_CH6_IRQHandler         
DMA_CH7_IRQHandler         
DMA_CH8_IRQHandler         
DMA_CH9_IRQHandler         
DMA_CH10_IRQHandler         
DMA_CH11_IRQHandler         
DMA_CH12_IRQHandler         
DMA_CH13_IRQHandler         
DMA_CH14_IRQHandler         
DMA_CH15_IRQHandler         
DMA_CH16_IRQHandler         
DMA_CH17_IRQHandler         
DMA_CH18_IRQHandler         
DMA_CH19_IRQHandler         
DMA_CH20_IRQHandler         
DMA_CH21_IRQHandler         
DMA_CH22_IRQHandler         
DMA_CH23_IRQHandler         
DMA_CH24_IRQHandler         
DMA_CH25_IRQHandler         
DMA_CH26_IRQHandler         
DMA_CH27_IRQHandler         
DMA_CH28_IRQHandler         
DMA_CH29_IRQHandler         
DMA_CH30_IRQHandler         
DMA_CH31_IRQHandler         
TMR0_IRQHandler         
TMR1_IRQHandler         
TMR2_IRQHandler         
TMR3_IRQHandler         
ETMR0_IRQHandler         
ETMR1_IRQHandler         
ETMR2_IRQHandler         
ETMR3_IRQHandler         
UART0_TD_IRQHandler         
UART0_MX_IRQHandler         
UART0_RX_IRQHandler         
UART0_TX_IRQHandler         
UART0_RT_IRQHandler         
UART0_E_IRQHandler         
UART0_IRQHandler         
UART1_TD_IRQHandler         
UART1_MX_IRQHandler         
UART1_RX_IRQHandler         
UART1_TX_IRQHandler         
UART1_RT_IRQHandler         
UART1_E_IRQHandler         
UART1_IRQHandler         
UART2_TD_IRQHandler         
UART2_MX_IRQHandler         
UART2_RX_IRQHandler         
UART2_TX_IRQHandler         
UART2_RT_IRQHandler         
UART2_E_IRQHandler         
UART2_IRQHandler         
UART3_TD_IRQHandler         
UART3_MX_IRQHandler         
UART3_RX_IRQHandler         
UART3_TX_IRQHandler         
UART3_RT_IRQHandler         
UART3_E_IRQHandler         
UART3_IRQHandler         
TUART0_RX_IRQHandler         
TUART0_TX_IRQHandler         
TUART0_RO_IRQHandler         
TUART0_TO_IRQHandler         
TUART0_IRQHandler         
TUART1_RX_IRQHandler         
TUART1_TX_IRQHandler         
TUART1_RO_IRQHandler         
TUART1_TO_IRQHandler         
TUART1_IRQHandler         
SPI0_IRQHandler         
SPI0_RX_IRQHandler         
SPI0_TX_IRQHandler         
SPI0_RO_IRQHandler         
SPI0_RT_IRQHandler         
SPI1_IRQHandler         
SPI1_RX_IRQHandler         
SPI1_TX_IRQHandler         
SPI1_RO_IRQHandler         
SPI1_RT_IRQHandler         
SPI2_IRQHandler         
SPI2_RX_IRQHandler         
SPI2_TX_IRQHandler         
SPI2_RO_IRQHandler         
SPI2_RT_IRQHandler         
SPI3_IRQHandler         
SPI3_RX_IRQHandler         
SPI3_TX_IRQHandler         
SPI3_RO_IRQHandler         
SPI3_RT_IRQHandler         
I2C0_IRQHandler         
I2C1_IRQHandler         
SPWR0_IRQHandler         
SPWR1_IRQHandler         
MILSTD0_IRQHandler         
MILSTD1_IRQHandler         
ECAP0_IRQHandler         
ECAP1_IRQHandler         
ECAP2_IRQHandler         
ECAP3_IRQHandler         
ECAP4_IRQHandler         
ECAP5_IRQHandler         
PWM0_IRQHandler         
PWM0_HD_IRQHandler         
PWM0_TZ_IRQHandler         
PWM1_IRQHandler         
PWM1_HD_IRQHandler         
PWM1_TZ_IRQHandler         
PWM2_IRQHandler         
PWM2_HD_IRQHandler         
PWM2_TZ_IRQHandler         
PWM3_IRQHandler         
PWM3_HD_IRQHandler         
PWM3_TZ_IRQHandler         
PWM4_IRQHandler         
PWM4_HD_IRQHandler         
PWM4_TZ_IRQHandler         
PWM5_IRQHandler         
PWM5_HD_IRQHandler         
PWM5_TZ_IRQHandler         
PWM6_IRQHandler         
PWM6_HD_IRQHandler         
PWM6_TZ_IRQHandler         
PWM7_IRQHandler         
PWM7_HD_IRQHandler         
PWM7_TZ_IRQHandler         
PWM8_IRQHandler         
PWM8_HD_IRQHandler         
PWM8_TZ_IRQHandler         
PWM9_IRQHandler         
PWM9_HD_IRQHandler         
PWM9_TZ_IRQHandler         
QEP0_IRQHandler         
QEP1_IRQHandler         
QEP2_IRQHandler         
QEP3_IRQHandler         
ADC_SEQ0_IRQHandler         
ADC_SEQ1_IRQHandler         
ADC_SEQ2_IRQHandler         
ADC_SEQ3_IRQHandler         
ADC_SEQ4_IRQHandler         
ADC_SEQ5_IRQHandler         
ADC_SEQ6_IRQHandler         
ADC_SEQ7_IRQHandler         
ADC_DC_IRQHandler         
ETH_IRQHandler         
CAN0_IRQHandler         
CAN1_IRQHandler         
CAN2_IRQHandler         
CAN3_IRQHandler         
CAN4_IRQHandler         
CAN5_IRQHandler         
CAN6_IRQHandler         
CAN7_IRQHandler         
CAN8_IRQHandler         
CAN9_IRQHandler         
CAN10_IRQHandler         
CAN11_IRQHandler         
CAN12_IRQHandler         
CAN13_IRQHandler         
CAN14_IRQHandler         
CAN15_IRQHandler         
FPU_IRQHandler         
TMU_IRQHandler         
LAU_IRQHandler         
SDFM_IRQHandler         
OWI0_IRQHandler         
OWI1_IRQHandler         



                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB           
                
                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit
                
                 ELSE
                
                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap
                 
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;******************* (C) COPYRIGHT 2018 NIIET *****END OF FILE*****
