#ifndef TIMERZERO_cpp
#define TIMERZERO_cpp

#include "TimerZero.h"

#define TIMERZERO_TICKS_IN_MICROSECOND (SystemCoreClock/1000000)

#define TIMERZERO_TIMER0      TMR0
#define TIMERZERO_TIMER0_IRQ  TMR0_IRQn
#define TIMERZERO_TIMER0_RCU_RST  RCU_APBRst_TMR0
#define TIMERZERO_TIMER0_RCU_CLK  RCU_APBClk_TMR0
#define TIMERZERO_TIMER0_IRQHandler TMR0_IRQHandler

TimerZero Timer0;


extern "C"{
  void TIMERZERO_TIMER0_IRQHandler(){
      Timer0.irqCallback();
      TIMERZERO_TIMER0->INTSTATUS_bit.INT = 1;
  }
}


void TimerZero::initialize(long microseconds)
{
      NVIC_SetPriority(TIMERZERO_TIMER0_IRQ, 0);
      RCU_APBClkCmd(TIMERZERO_TIMER0_RCU_CLK, ENABLE);
      RCU_APBRstCmd(TIMERZERO_TIMER0_RCU_RST, ENABLE);
      NVIC_EnableIRQ(TIMERZERO_TIMER0_IRQ);
    setPeriod(microseconds);
}


void TimerZero::setPeriod(long microseconds) // set period and restart timer
{
  TMR_SetLoad(TIMERZERO_TIMER0,microseconds*TIMERZERO_TICKS_IN_MICROSECOND);
  start();
}



void TimerZero::attachInterrupt(void (*irq)(), long microseconds)
{
  if(microseconds > 0){
    setPeriod(microseconds);
  }
  irqCallback = irq;
  TMR_ITCmd(TIMERZERO_TIMER0, ENABLE);
}

void TimerZero::detachInterrupt()
{
  TMR_ITCmd(TIMERZERO_TIMER0, DISABLE);
}

void TimerZero::resume()				// resume timer with out change counter value
{ 
  TMR_Cmd(TIMERZERO_TIMER0, ENABLE);
}

void TimerZero::restart()		// Depricated - start from period value
{
  start();
}

void TimerZero::start()	// start from period value
{
  TMR_SetCounter(TIMERZERO_TIMER0,TMR_GetLoad(TIMERZERO_TIMER0));
  TMR_Cmd(TIMERZERO_TIMER0, ENABLE);
}

void TimerZero::stop()
{
  TMR_Cmd(TIMERZERO_TIMER0, DISABLE);
}

unsigned long TimerZero::read()//returns the value of the timer in microseconds
{
  return TMR_GetCounter(TIMERZERO_TIMER0) / TIMERZERO_TICKS_IN_MICROSECOND;
}

#endif