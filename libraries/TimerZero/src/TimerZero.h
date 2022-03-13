#ifndef TIMERZERO_H
#define TIMERZERO_H

#include <Arduino.h>

class TimerZero
{
  public:
    // methods
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
};

extern TimerZero Timer0;
#endif