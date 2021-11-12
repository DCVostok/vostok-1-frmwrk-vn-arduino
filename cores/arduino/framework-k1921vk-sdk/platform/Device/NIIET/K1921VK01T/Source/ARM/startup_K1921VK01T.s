;******************** (C) COPYRIGHT 2018 NIIET ********************
;* File Name          : startup_K1921VK01T.s
;* Author             : NIIET 
;* Version            : V2.0
;* Date               : 17.08.2018
;* Description        : K1921VK01T vector table for MDK-ARM 
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

                EXPORT     WWDG_IRQHandler           [WEAK]
                EXPORT     I2C0_IRQHandler           [WEAK]
                EXPORT     I2C1_IRQHandler           [WEAK]
                EXPORT     TIM0_IRQHandler           [WEAK]
                EXPORT     TIM1_IRQHandler           [WEAK]
                EXPORT     TIM2_IRQHandler           [WEAK]
                EXPORT     DMA_Stream0_IRQHandler           [WEAK]
                EXPORT     DMA_Stream1_IRQHandler           [WEAK]
                EXPORT     DMA_Stream2_IRQHandler           [WEAK]
                EXPORT     DMA_Stream3_IRQHandler           [WEAK]
                EXPORT     DMA_Stream4_IRQHandler           [WEAK]
                EXPORT     DMA_Stream5_IRQHandler           [WEAK]
                EXPORT     DMA_Stream6_IRQHandler           [WEAK]
                EXPORT     DMA_Stream7_IRQHandler           [WEAK]
                EXPORT     DMA_Stream8_IRQHandler           [WEAK]
                EXPORT     DMA_Stream9_IRQHandler           [WEAK]
                EXPORT     DMA_Stream10_IRQHandler           [WEAK]
                EXPORT     DMA_Stream11_IRQHandler           [WEAK]
                EXPORT     DMA_Stream12_IRQHandler           [WEAK]
                EXPORT     DMA_Stream13_IRQHandler           [WEAK]
                EXPORT     DMA_Stream14_IRQHandler           [WEAK]
                EXPORT     DMA_Stream15_IRQHandler           [WEAK]
                EXPORT     DMA_Stream16_IRQHandler           [WEAK]
                EXPORT     DMA_Stream17_IRQHandler           [WEAK]
                EXPORT     DMA_Stream18_IRQHandler           [WEAK]
                EXPORT     DMA_Stream19_IRQHandler           [WEAK]
                EXPORT     DMA_Stream20_IRQHandler           [WEAK]
                EXPORT     DMA_Stream21_IRQHandler           [WEAK]
                EXPORT     DMA_Stream22_IRQHandler           [WEAK]
                EXPORT     DMA_Stream23_IRQHandler           [WEAK]
                EXPORT     UART0_MX_IRQHandler           [WEAK]
                EXPORT     UART0_RX_IRQHandler           [WEAK]
                EXPORT     UART0_TX_IRQHandler           [WEAK]
                EXPORT     UART0_RT_IRQHandler           [WEAK]
                EXPORT     UART0_E_IRQHandler           [WEAK]
                EXPORT     UART0_IRQHandler           [WEAK]
                EXPORT     UART1_MX_IRQHandler           [WEAK]
                EXPORT     UART1_RX_IRQHandler           [WEAK]
                EXPORT     UART1_TX_IRQHandler           [WEAK]
                EXPORT     UART1_RT_IRQHandler           [WEAK]
                EXPORT     UART1_E_IRQHandler           [WEAK]
                EXPORT     UART1_IRQHandler           [WEAK]
                EXPORT     UART2_MX_IRQHandler           [WEAK]
                EXPORT     UART2_RX_IRQHandler           [WEAK]
                EXPORT     UART2_TX_IRQHandler           [WEAK]
                EXPORT     UART2_RT_IRQHandler           [WEAK]
                EXPORT     UART2_E_IRQHandler           [WEAK]
                EXPORT     UART2_IRQHandler           [WEAK]
                EXPORT     UART3_MX_IRQHandler           [WEAK]
                EXPORT     UART3_RX_IRQHandler           [WEAK]
                EXPORT     UART3_TX_IRQHandler           [WEAK]
                EXPORT     UART3_RT_IRQHandler           [WEAK]
                EXPORT     UART3_E_IRQHandler           [WEAK]
                EXPORT     UART3_IRQHandler           [WEAK]
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
                EXPORT     ADC_SEQ0_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ1_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ2_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ3_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ4_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ5_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ6_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ7_IRQHandler           [WEAK]
                EXPORT     ADC_CompInt_IRQHandler           [WEAK]
                EXPORT     CAP0_IRQHandler           [WEAK]
                EXPORT     CAP1_IRQHandler           [WEAK]
                EXPORT     CAP2_IRQHandler           [WEAK]
                EXPORT     CAP3_IRQHandler           [WEAK]
                EXPORT     CAP4_IRQHandler           [WEAK]
                EXPORT     CAP5_IRQHandler           [WEAK]
                EXPORT     QEP0_IRQHandler           [WEAK]
                EXPORT     QEP1_IRQHandler           [WEAK]
                EXPORT     BootFlash_IRQHandler           [WEAK]
                EXPORT     CMP0_IRQHandler           [WEAK]
                EXPORT     CMP1_IRQHandler           [WEAK]
                EXPORT     CMP2_IRQHandler           [WEAK]
                EXPORT     SPI0_IRQHandler           [WEAK]
                EXPORT     SPI1_IRQHandler           [WEAK]
                EXPORT     SPI2_IRQHandler           [WEAK]
                EXPORT     SPI3_IRQHandler           [WEAK]
                EXPORT     UserFlash_IRQHandler           [WEAK]
                EXPORT     GPIOA_IRQHandler           [WEAK]
                EXPORT     GPIOB_IRQHandler           [WEAK]
                EXPORT     GPIOC_IRQHandler           [WEAK]
                EXPORT     GPIOD_IRQHandler           [WEAK]
                EXPORT     GPIOE_IRQHandler           [WEAK]
                EXPORT     GPIOF_IRQHandler           [WEAK]
                EXPORT     GPIOG_IRQHandler           [WEAK]
                EXPORT     GPIOH_IRQHandler           [WEAK]
                EXPORT     Ethernet_IRQHandler           [WEAK]
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
                EXPORT     RTC_IRQHandler           [WEAK]
                EXPORT     USBOTG_IRQHandler           [WEAK]



WWDG_IRQHandler         
I2C0_IRQHandler         
I2C1_IRQHandler         
TIM0_IRQHandler         
TIM1_IRQHandler         
TIM2_IRQHandler         
DMA_Stream0_IRQHandler         
DMA_Stream1_IRQHandler         
DMA_Stream2_IRQHandler         
DMA_Stream3_IRQHandler         
DMA_Stream4_IRQHandler         
DMA_Stream5_IRQHandler         
DMA_Stream6_IRQHandler         
DMA_Stream7_IRQHandler         
DMA_Stream8_IRQHandler         
DMA_Stream9_IRQHandler         
DMA_Stream10_IRQHandler         
DMA_Stream11_IRQHandler         
DMA_Stream12_IRQHandler         
DMA_Stream13_IRQHandler         
DMA_Stream14_IRQHandler         
DMA_Stream15_IRQHandler         
DMA_Stream16_IRQHandler         
DMA_Stream17_IRQHandler         
DMA_Stream18_IRQHandler         
DMA_Stream19_IRQHandler         
DMA_Stream20_IRQHandler         
DMA_Stream21_IRQHandler         
DMA_Stream22_IRQHandler         
DMA_Stream23_IRQHandler         
UART0_MX_IRQHandler         
UART0_RX_IRQHandler         
UART0_TX_IRQHandler         
UART0_RT_IRQHandler         
UART0_E_IRQHandler         
UART0_IRQHandler         
UART1_MX_IRQHandler         
UART1_RX_IRQHandler         
UART1_TX_IRQHandler         
UART1_RT_IRQHandler         
UART1_E_IRQHandler         
UART1_IRQHandler         
UART2_MX_IRQHandler         
UART2_RX_IRQHandler         
UART2_TX_IRQHandler         
UART2_RT_IRQHandler         
UART2_E_IRQHandler         
UART2_IRQHandler         
UART3_MX_IRQHandler         
UART3_RX_IRQHandler         
UART3_TX_IRQHandler         
UART3_RT_IRQHandler         
UART3_E_IRQHandler         
UART3_IRQHandler         
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
ADC_SEQ0_IRQHandler         
ADC_SEQ1_IRQHandler         
ADC_SEQ2_IRQHandler         
ADC_SEQ3_IRQHandler         
ADC_SEQ4_IRQHandler         
ADC_SEQ5_IRQHandler         
ADC_SEQ6_IRQHandler         
ADC_SEQ7_IRQHandler         
ADC_CompInt_IRQHandler         
CAP0_IRQHandler         
CAP1_IRQHandler         
CAP2_IRQHandler         
CAP3_IRQHandler         
CAP4_IRQHandler         
CAP5_IRQHandler         
QEP0_IRQHandler         
QEP1_IRQHandler         
BootFlash_IRQHandler         
CMP0_IRQHandler         
CMP1_IRQHandler         
CMP2_IRQHandler         
SPI0_IRQHandler         
SPI1_IRQHandler         
SPI2_IRQHandler         
SPI3_IRQHandler         
UserFlash_IRQHandler         
GPIOA_IRQHandler         
GPIOB_IRQHandler         
GPIOC_IRQHandler         
GPIOD_IRQHandler         
GPIOE_IRQHandler         
GPIOF_IRQHandler         
GPIOG_IRQHandler         
GPIOH_IRQHandler         
Ethernet_IRQHandler         
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
RTC_IRQHandler         
USBOTG_IRQHandler         



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
