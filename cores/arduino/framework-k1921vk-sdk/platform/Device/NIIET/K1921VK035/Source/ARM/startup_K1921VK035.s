;******************** (C) COPYRIGHT 2018 NIIET ********************
;* File Name          : startup_K1921VK035.s
;* Author             : NIIET 
;* Version            : V1.7
;* Date               : 02.05.2018
;* Description        : K1921VK035 vector table for MDK-ARM 
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
                EXPORT     MFLASH_IRQHandler           [WEAK]
                EXPORT     GPIOA_IRQHandler           [WEAK]
                EXPORT     GPIOB_IRQHandler           [WEAK]
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
                EXPORT     TMR0_IRQHandler           [WEAK]
                EXPORT     TMR1_IRQHandler           [WEAK]
                EXPORT     TMR2_IRQHandler           [WEAK]
                EXPORT     TMR3_IRQHandler           [WEAK]
                EXPORT     UART0_TD_IRQHandler           [WEAK]
                EXPORT     UART0_RX_IRQHandler           [WEAK]
                EXPORT     UART0_TX_IRQHandler           [WEAK]
                EXPORT     UART0_E_RT_IRQHandler           [WEAK]
                EXPORT     UART1_TD_IRQHandler           [WEAK]
                EXPORT     UART1_RX_IRQHandler           [WEAK]
                EXPORT     UART1_TX_IRQHandler           [WEAK]
                EXPORT     UART1_E_RT_IRQHandler           [WEAK]
                EXPORT     SPI_RO_RT_IRQHandler           [WEAK]
                EXPORT     SPI_RX_IRQHandler           [WEAK]
                EXPORT     SPI_TX_IRQHandler           [WEAK]
                EXPORT     I2C_IRQHandler           [WEAK]
                EXPORT     ECAP0_IRQHandler           [WEAK]
                EXPORT     ECAP1_IRQHandler           [WEAK]
                EXPORT     ECAP2_IRQHandler           [WEAK]
                EXPORT     PWM0_IRQHandler           [WEAK]
                EXPORT     PWM0_HD_IRQHandler           [WEAK]
                EXPORT     PWM0_TZ_IRQHandler           [WEAK]
                EXPORT     PWM1_IRQHandler           [WEAK]
                EXPORT     PWM1_HD_IRQHandler           [WEAK]
                EXPORT     PWM1_TZ_IRQHandler           [WEAK]
                EXPORT     PWM2_IRQHandler           [WEAK]
                EXPORT     PWM2_HD_IRQHandler           [WEAK]
                EXPORT     PWM2_TZ_IRQHandler           [WEAK]
                EXPORT     QEP_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ0_IRQHandler           [WEAK]
                EXPORT     ADC_SEQ1_IRQHandler           [WEAK]
                EXPORT     ADC_DC_IRQHandler           [WEAK]
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



WDT_IRQHandler         
RCU_IRQHandler         
MFLASH_IRQHandler         
GPIOA_IRQHandler         
GPIOB_IRQHandler         
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
TMR0_IRQHandler         
TMR1_IRQHandler         
TMR2_IRQHandler         
TMR3_IRQHandler         
UART0_TD_IRQHandler         
UART0_RX_IRQHandler         
UART0_TX_IRQHandler         
UART0_E_RT_IRQHandler         
UART1_TD_IRQHandler         
UART1_RX_IRQHandler         
UART1_TX_IRQHandler         
UART1_E_RT_IRQHandler         
SPI_RO_RT_IRQHandler         
SPI_RX_IRQHandler         
SPI_TX_IRQHandler         
I2C_IRQHandler         
ECAP0_IRQHandler         
ECAP1_IRQHandler         
ECAP2_IRQHandler         
PWM0_IRQHandler         
PWM0_HD_IRQHandler         
PWM0_TZ_IRQHandler         
PWM1_IRQHandler         
PWM1_HD_IRQHandler         
PWM1_TZ_IRQHandler         
PWM2_IRQHandler         
PWM2_HD_IRQHandler         
PWM2_TZ_IRQHandler         
QEP_IRQHandler         
ADC_SEQ0_IRQHandler         
ADC_SEQ1_IRQHandler         
ADC_DC_IRQHandler         
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
