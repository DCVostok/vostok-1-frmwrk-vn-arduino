#ifndef TIMERONE_h
#define TIMERONE_h

#include <Arduino.h>

class TimerOne
{
  public:
    // methods
    TimerOne(TMR_TypeDef* tmr_arg);
    void initialize(long microseconds=1000000);
    void start();
    void stop();
    void restart();
	void resume();
	unsigned long read();
    void attachInterrupt(void (*irq)(), long microseconds=-1);
    void detachInterrupt();
    void setPeriod(long microseconds);
    void (*irqCallback)();
private:
    TMR_TypeDef* tmr;
};

extern TimerOne Timer0;
extern TimerOne Timer1;
#endif