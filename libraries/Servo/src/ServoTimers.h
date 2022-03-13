/*
 * Defines for 16 bit timers used with Servo library
 *
 * If _useTimerX is defined then TimerX is a 16 bit timer on the current board
 * timer16_Sequence_t enumerates the sequence that the timers should be allocated
 * _Nbr_16timers indicates how many 16 bit timers are available.
 */


#define _useTimer0
#define _useTimer1


#if defined (_useTimer0)
#ifdef MCU_K1921VK035
  #define SERVO_TIMER0      TMR3
  #define SERVO_TIMER0_IRQ  TMR3_IRQn
  #define SERVO_TIMER0_RCU_RST  RCU_APBRst_TMR3
  #define SERVO_TIMER0_RCU_CLK  RCU_APBClk_TMR3
  #define SERVO_TIMER0_IRQHandler TMR3_IRQHandler
#elif MCU_K1921VK01T
  #define SERVO_TIMER0      NT_TIMER1
  #define SERVO_TIMER0_IRQ  TIM1_IRQn
  #define SERVO_TIMER0_RCC_PERIPH_RST  RCC_PeriphRst_Timer1
  #define SERVO_TIMER0_IRQHandler TIM1_IRQHandler
#endif
#endif
#if defined (_useTimer1)
#ifdef MCU_K1921VK035
  #define SERVO_TIMER1      TMR0
  #define SERVO_TIMER1_IRQ  TMR0_IRQn
  #define SERVO_TIMER1_RCU_RST  RCU_APBRst_TMR0
  #define SERVO_TIMER1_RCU_CLK  RCU_APBClk_TMR0
  #define SERVO_TIMER1_IRQHandler TMR0_IRQHandler
#elif MCU_K1921VK01T
  #define SERVO_TIMER1      NT_TIMER0
  #define SERVO_TIMER1_IRQ  TIM0_IRQn
  #define SERVO_TIMER1_RCC_PERIPH_RST  RCC_PeriphRst_Timer0
  #define SERVO_TIMER1_IRQHandler TIM0_IRQHandler
#endif
#endif

typedef enum { _timer0, _timer1, _Nbr_timers } timer_Sequence_t ;
