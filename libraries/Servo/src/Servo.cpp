/*
  Copyright (c) 2013 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#if defined(MCU_K1921VK035) || defined(MCU_K1921VK01T)

#include <Arduino.h>
#include <Servo.h>
#include <k1921vk_sdk.h>

#define TICKS_IN_MICROSECOND (SystemCoreClock/1000000)

#define usToTicks(_us)    (TICKS_IN_MICROSECOND * _us)     // converts microseconds to tick
#define ticksToUs(_ticks) (( (unsigned)_ticks)/ TICKS_IN_MICROSECOND) // converts from ticks back to microseconds
#define REFRESH_INTERVAL_TICKS  usToTicks(REFRESH_INTERVAL)

#define TRIM_DURATION       30                               // compensation ticks to trim adjust for digitalWrite delays

static servo_t servos[MAX_SERVOS];                          // static array of servo structures
uint8_t ServoCount = 0;                                     // the total number of attached servos
static volatile int8_t CurTimerServo[_Nbr_timers ];             // counter for the servo being pulsed for each timer (or -1 if refresh interval)
static uint32_t CumulativeTicksSinceRefresh[_Nbr_timers ]; 


#define SERVO_INDEX_TO_TIMER_ID(_servo_nbr) ((timer_Sequence_t)(_servo_nbr / SERVOS_PER_TIMER)) // returns the timer controlling this servo

/************ static functions common to all instances ***********************/

//------------------------------------------------------------------------------
/// Interrupt handler for the TC0 channel 1.
//------------------------------------------------------------------------------
void Servo_Handler(timer_Sequence_t timer);

extern "C"{
  #if defined (_useTimer0)
  void SERVO_TIMER0_IRQHandler(void) {
      Servo_Handler(_timer0);
  }
  #endif
  #if defined (_useTimer1)
 __WEAK void SERVO_TIMER1_IRQHandler(void) {
      Servo_Handler(_timer1);
  }
  #endif
}
inline void ServoTimer_setCounter(timer_Sequence_t timer_id,uint32_t value){
#if defined (_useTimer0)
    if (timer_id == _timer0){
        SERVO_TIMER0->VALUE = value;
        
    }   
#endif
#if defined (_useTimer1)
    if (timer_id == _timer1){
      SERVO_TIMER1->VALUE = value;
    }
#endif
}
inline void ServoTimer_ClearIrq(timer_Sequence_t timer_id){
#if defined (_useTimer0)
    if (timer_id == _timer0){
      #ifdef MCU_K1921VK035
        SERVO_TIMER0->INTSTATUS_bit.INT = 1;
      #elif MCU_K1921VK01T  
        SERVO_TIMER0->INTSTATUS_INTCLEAR_bit.INT = 1;
      #endif
    }   
#endif
#if defined (_useTimer1)
    if (timer_id == _timer1){
      #ifdef MCU_K1921VK035
        SERVO_TIMER1->INTSTATUS_bit.INT = 1;
      #elif MCU_K1921VK01T  
        SERVO_TIMER1->INTSTATUS_INTCLEAR_bit.INT = 1;
      #endif
    }
#endif
}


void Servo_Handler(timer_Sequence_t timer_id)
{
  uint8_t CurServoIndex = timer_id*SERVOS_PER_TIMER+CurTimerServo[timer_id];
    if (CurTimerServo[timer_id] < 0) {
    // Restart from 1st servo
    CumulativeTicksSinceRefresh[timer_id] = 0;
  } else {
    if (CurServoIndex < ServoCount && servos[CurServoIndex].Pin.isActive) {
      digitalWrite(servos[CurServoIndex].Pin.nbr, LOW); // pulse this channel low if activated
    }
  }

  CurTimerServo[timer_id]++;    // increment to the next servo
  CurServoIndex++;
  if (CurServoIndex < ServoCount && CurTimerServo[timer_id] < SERVOS_PER_TIMER) {
    ServoTimer_setCounter(timer_id,servos[CurServoIndex].ticks);
    CumulativeTicksSinceRefresh[timer_id] += servos[CurServoIndex].ticks;
    if (servos[CurServoIndex].Pin.isActive) {
      // check if activated
      digitalWrite(servos[CurServoIndex].Pin.nbr, HIGH); // its an active channel so pulse it high
    }
  } else {
    // finished all channels so wait for the refresh period to expire before starting over
    if (CumulativeTicksSinceRefresh[timer_id] + 4 < REFRESH_INTERVAL_TICKS) {
      // allow a few ticks to ensure the next OCR1A not missed
      ServoTimer_setCounter(timer_id,REFRESH_INTERVAL_TICKS - CumulativeTicksSinceRefresh[timer_id]);
    } else {
      // generate update to restart immediately from the beginning with the 1st servo
      ServoTimer_setCounter(timer_id,50);
    }
    CurTimerServo[timer_id] = -1; // this will get incremented at the end of the refresh period to start again at the first channel
  }
  ServoTimer_ClearIrq(timer_id);
}


static void initISR(timer_Sequence_t timer_id)
{
#if defined (_useTimer0)
    if (timer_id == _timer0){
      NVIC_SetPriority(SERVO_TIMER0_IRQ, 0);
    #ifdef MCU_K1921VK035
      RCU_APBClkCmd(SERVO_TIMER0_RCU_CLK, ENABLE);
      RCU_APBRstCmd(SERVO_TIMER0_RCU_RST, ENABLE);
      TMR_SetLoad(SERVO_TIMER0,REFRESH_INTERVAL_TICKS);
      TMR_SetCounter(SERVO_TIMER0,usToTicks(1000));//first irq after 1ms
      TMR_ITCmd(SERVO_TIMER0, ENABLE);
      TMR_Cmd(SERVO_TIMER0, ENABLE);
    #elif MCU_K1921VK01T
      RCC_PeriphRstCmd(SERVO_TIMER0_RCC_PERIPH_RST, ENABLE);
      TIMER_SetReload(SERVO_TIMER0,REFRESH_INTERVAL_TICKS);
      TIMER_SetCounter(SERVO_TIMER0,usToTicks(1000));//first irq after 1ms
      TIMER_ITCmd(SERVO_TIMER0, ENABLE);
      TIMER_Cmd(SERVO_TIMER0, ENABLE);
    #endif
      NVIC_EnableIRQ(SERVO_TIMER0_IRQ);
    }
        
#endif
#if defined (_useTimer1)
    if (timer_id == _timer1){
      NVIC_SetPriority(SERVO_TIMER1_IRQ, 0);
    #ifdef MCU_K1921VK035
      RCU_APBClkCmd(SERVO_TIMER1_RCU_CLK, ENABLE);
      RCU_APBRstCmd(SERVO_TIMER1_RCU_RST, ENABLE);
      TMR_SetLoad(SERVO_TIMER1,usToTicks(200000));
      TMR_SetCounter(SERVO_TIMER1,usToTicks(1000));//first irq after 1ms
      TMR_ITCmd(SERVO_TIMER1, ENABLE);
      TMR_Cmd(SERVO_TIMER1, ENABLE);
    #elif MCU_K1921VK01T
      RCC_PeriphRstCmd(SERVO_TIMER1_RCC_PERIPH_RST, ENABLE);
      TIMER_SetReload(SERVO_TIMER1,usToTicks(20000));
      TIMER_SetCounter(SERVO_TIMER1,usToTicks(1000));//first irq after 1ms
      TIMER_ITCmd(SERVO_TIMER1, ENABLE);
      TIMER_Cmd(SERVO_TIMER1, ENABLE);
    #endif
      NVIC_EnableIRQ(SERVO_TIMER1_IRQ);
    }
#endif
}

static void finISR(timer_Sequence_t timer_id)
{
#if defined (_useTimer0)
    if (timer_id == _timer0){
      NVIC_DisableIRQ(SERVO_TIMER0_IRQ);
      NVIC_ClearPendingIRQ(SERVO_TIMER0_IRQ);
      #ifdef MCU_K1921VK035
        TMR_ITCmd(SERVO_TIMER0, DISABLE);
        TMR_Cmd(SERVO_TIMER0, DISABLE);
        TMR_SetCounter(SERVO_TIMER0,0);
      #elif MCU_K1921VK01T
        TIMER_ITCmd(SERVO_TIMER0, DISABLE);
        TIMER_Cmd(SERVO_TIMER0, DISABLE);
        TIMER_SetCounter(SERVO_TIMER0,0);
      #endif
    }
        
#endif
#if defined (_useTimer1)
    if (timer_id == _timer1){
      NVIC_DisableIRQ(SERVO_TIMER1_IRQ);
      NVIC_ClearPendingIRQ(SERVO_TIMER1_IRQ);
      #ifdef MCU_K1921VK035
        TMR_ITCmd(SERVO_TIMER1, DISABLE);
        TMR_Cmd(SERVO_TIMER1, DISABLE);
        TMR_SetCounter(SERVO_TIMER1,0);
      #elif MCU_K1921VK01T
        TIMER_ITCmd(SERVO_TIMER1, DISABLE);
        TIMER_Cmd(SERVO_TIMER1, DISABLE);
        TIMER_SetCounter(SERVO_TIMER1,0);
      #endif
    }
#endif
}


static boolean isTimerActive(timer_Sequence_t timer_id)
{
  // returns true if any servo is active on this timer
  uint8_t BeginServoIndex = timer_id*SERVOS_PER_TIMER;
  for(uint8_t i=0; i < SERVOS_PER_TIMER; ++i) {
    if(servos[BeginServoIndex+i].Pin.isActive == true)
      return true;
  }
  return false;
}

/****************** end of static functions ******************************/

Servo::Servo()
{
  if (ServoCount < MAX_SERVOS) {
    this->servoIndex = ServoCount++;                    // assign a servo index to this instance
    servos[this->servoIndex].ticks = 0;   // store default values
  } else {
    this->servoIndex = INVALID_SERVO;  // too many servos
  }
}

uint8_t Servo::attach(int pin)
{
  return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t Servo::attach(int pin, int min, int max)
{
  timer_Sequence_t timer_id;

  if (this->servoIndex < MAX_SERVOS) {
    pinMode(pin, OUTPUT);                                   // set servo pin to output
    servos[this->servoIndex].Pin.nbr = pin;
    this->min  = min > MIN_PULSE_WIDTH ? min : MIN_PULSE_WIDTH; 
    this->max  = min < MAX_PULSE_WIDTH ? max : MAX_PULSE_WIDTH; 
    // initialize the timer if it has not already been initialized
    timer_id = SERVO_INDEX_TO_TIMER_ID(servoIndex);
    if (isTimerActive(timer_id) == false) {
      initISR(timer_id);
    }
    if( servos[this->servoIndex].ticks < MIN_PULSE_WIDTH){
      writeMicroseconds(DEFAULT_PULSE_WIDTH);
    }
    servos[this->servoIndex].Pin.isActive = true;  // this must be set after the check for isTimerActive
  }
  return this->servoIndex;
}

void Servo::detach()
{
  timer_Sequence_t timer_id;

  servos[this->servoIndex].Pin.isActive = false;
  timer_id = SERVO_INDEX_TO_TIMER_ID(servoIndex);
  if(isTimerActive(timer_id) == false) {
    finISR(timer_id);
  }
}

void Servo::write(int value)
{
  // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
  if(value < MIN_PULSE_WIDTH){
    if (value < 0)
      value = 0;
    else if (value > 180)
      value = 180;

    value = map(value, 0, 180, this->min, this->max);
  }
  writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value)
{
  // calculate and store the values for the given channel
  byte channel = this->servoIndex;
  if( (channel < MAX_SERVOS) )   // ensure channel is valid
  {
    if (value < MIN_PULSE_WIDTH)          // ensure pulse width is valid
      value = MIN_PULSE_WIDTH;
    else if (value > MAX_PULSE_WIDTH)
      value = MAX_PULSE_WIDTH;

    value = usToTicks(value) - TRIM_DURATION;  // convert to ticks after compensating for interrupt overhead
    servos[channel].ticks = value;
  }
}

int Servo::read() // return the value as degrees
{
  return map(readMicroseconds()+1, this->min, this->max, 0, 180);
}

int Servo::readMicroseconds()
{
  unsigned int pulsewidth;
  if (this->servoIndex != INVALID_SERVO)
    pulsewidth = ticksToUs(servos[this->servoIndex].ticks + TRIM_DURATION);
  else
    pulsewidth  = 0;

  return pulsewidth;
}

bool Servo::attached()
{
  return servos[this->servoIndex].Pin.isActive;
}

#endif // ARDUINO_ARCH_SAM
