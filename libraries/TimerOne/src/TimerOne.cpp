#ifndef TIMERONE_cpp
#define TIMERONE_cpp

#include "TimerOne.h"

#define TIMERONE_TICKS_IN_MICROSECOND (SystemCoreClock / 1000000)

#define TIMERONE_TIMER1 TMR1
#define TIMERONE_TIMER1_IRQ TMR1_IRQn
#define TIMERONE_TIMER1_RCU_RST RCU_APBRst_TMR1
#define TIMERONE_TIMER1_RCU_CLK RCU_APBClk_TMR1
#define TIMERONE_TIMER1_IRQHandler TMR1_IRQHandler

TimerOne Timer1;

extern "C" {
void TIMERONE_TIMER1_IRQHandler() {
  Timer1.irqCallback();
  TIMERONE_TIMER1->INTSTATUS_bit.INT = 1;
}
}

void TimerOne::initialize(long microseconds) {
  NVIC_SetPriority(TIMERONE_TIMER1_IRQ, 4);
  RCU_APBClkCmd(TIMERONE_TIMER1_RCU_CLK, ENABLE);
  RCU_APBRstCmd(TIMERONE_TIMER1_RCU_RST, ENABLE);
  NVIC_EnableIRQ(TIMERONE_TIMER1_IRQ);
  setPeriod(microseconds);
}

void TimerOne::setPeriod(long microseconds) // set period and restart timer
{
  TMR_SetLoad(TIMERONE_TIMER1, microseconds * TIMERONE_TICKS_IN_MICROSECOND);
  start();
}

void TimerOne::attachInterrupt(void (*irq)(), long microseconds) {
  if (microseconds > 0) {
    setPeriod(microseconds);
  }
  irqCallback = irq;
  TMR_ITCmd(TIMERONE_TIMER1, ENABLE);
}

void TimerOne::detachInterrupt() { TMR_ITCmd(TIMERONE_TIMER1, DISABLE); }

void TimerOne::resume() // resume timer with out change counter value
{
  TMR_Cmd(TIMERONE_TIMER1, ENABLE);
}

void TimerOne::restart() // Depricated - start from period value
{
  start();
}

void TimerOne::start() // start from period value
{
  TMR_SetCounter(TIMERONE_TIMER1, TMR_GetLoad(TIMERONE_TIMER1));
  TMR_Cmd(TIMERONE_TIMER1, ENABLE);
}

void TimerOne::stop() { TMR_Cmd(TIMERONE_TIMER1, DISABLE); }

unsigned long TimerOne::read() // returns the value of the timer in microseconds
{
  return TMR_GetCounter(TIMERONE_TIMER1) / TIMERONE_TICKS_IN_MICROSECOND;
}

#endif