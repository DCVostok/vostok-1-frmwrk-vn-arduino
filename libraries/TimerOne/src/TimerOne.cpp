#ifndef TIMERONE_cpp
#define TIMERONE_cpp

#include "TimerOne.h"

#define TIMERONE_TICKS_IN_MICROSECOND (SystemCoreClock/1000000)

#define TIMERONE_TIMER0      TMR0
#define TIMERONE_TIMER0_IRQ  TMR0_IRQn
#define TIMERONE_TIMER0_RCU_RST  RCU_APBRst_TMR0
#define TIMERONE_TIMER0_RCU_CLK  RCU_APBClk_TMR0
#define TIMERONE_TIMER0_IRQHandler TMR0_IRQHandler


#define TIMERONE_TIMER1      TMR1
#define TIMERONE_TIMER1_IRQ  TMR1_IRQn
#define TIMERONE_TIMER1_RCU_RST  RCU_APBRst_TMR1
#define TIMERONE_TIMER1_RCU_CLK  RCU_APBClk_TMR1
#define TIMERONE_TIMER1_IRQHandler TMR1_IRQHandler

TimerOne Timer0(TIMERONE_TIMER0);
TimerOne Timer1(TIMERONE_TIMER1);

extern "C"{
  void TIMERONE_TIMER0_IRQHandler(){
      Timer0.irqCallback();
      TIMERONE_TIMER0->INTSTATUS_bit.INT = 1;
  }
  void TIMERONE_TIMER1_IRQHandler(){
    Timer1.irqCallback();
    TIMERONE_TIMER1->INTSTATUS_bit.INT = 1;
  }
}
TimerOne::TimerOne(TMR_TypeDef* tmr_arg){
  this->tmr = tmr_arg;
}

void TimerOne::initialize(long microseconds)
{
    if (tmr == TIMERONE_TIMER0){
      NVIC_SetPriority(TIMERONE_TIMER0_IRQ, 0);
      RCU_APBClkCmd(TIMERONE_TIMER0_RCU_CLK, ENABLE);
      RCU_APBRstCmd(TIMERONE_TIMER0_RCU_RST, ENABLE);
      NVIC_EnableIRQ(TIMERONE_TIMER0_IRQ);
    }
    if (tmr == TIMERONE_TIMER1){
      NVIC_SetPriority(TIMERONE_TIMER1_IRQ, 1);
      RCU_APBClkCmd(TIMERONE_TIMER1_RCU_CLK, ENABLE);
      RCU_APBRstCmd(TIMERONE_TIMER1_RCU_RST, ENABLE);
      NVIC_EnableIRQ(TIMERONE_TIMER1_IRQ);
    }

    setPeriod(microseconds);
}


void TimerOne::setPeriod(long microseconds) // set period and restart timer
{
  TMR_SetLoad(tmr,microseconds*TIMERONE_TICKS_IN_MICROSECOND);
  start();
}



void TimerOne::attachInterrupt(void (*irq)(), long microseconds)
{
  if(microseconds > 0){
    setPeriod(microseconds);
  }
  irqCallback = irq;
  TMR_ITCmd(tmr, ENABLE);
}

void TimerOne::detachInterrupt()
{
  TMR_ITCmd(tmr, DISABLE);
}

void TimerOne::resume()				// resume timer with out change counter value
{ 
  TMR_Cmd(tmr, ENABLE);
}

void TimerOne::restart()		// Depricated - start from period value
{
  start();
}

void TimerOne::start()	// start from period value
{
  TMR_SetCounter(tmr,TMR_GetLoad(tmr));
  TMR_Cmd(tmr, ENABLE);
}

void TimerOne::stop()
{
  TMR_Cmd(tmr, DISABLE);
}

unsigned long TimerOne::read()//returns the value of the timer in microseconds
{
  return TMR_GetCounter(tmr) / TIMERONE_TICKS_IN_MICROSECOND;
}

#endif