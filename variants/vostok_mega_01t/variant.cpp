#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription pins_description_map[]=
{

  { NT_GPIOB,  GPIO_Pin_11, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //  D0 / B11 / UART0 RX
  { NT_GPIOB,  GPIO_Pin_10, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //  D1 / B10 / UART0 TX
  { NT_GPIOB,  GPIO_Pin_9, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D2 / B9 / UART1 RX
  { NT_GPIOA,  GPIO_Pin_11, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(3)}, //   D3 / A11 / PWM_1_B
  { NT_GPIOA,  GPIO_Pin_14, (PIN_ATTR_TIMER_IN), PIN_ADC_NONE, PIN_PWM_NONE}, //   D4 / A14 / TMR_0_IN
  { NT_GPIOA,  GPIO_Pin_15, (PIN_ATTR_TIMER_IN), PIN_ADC_NONE, PIN_PWM_NONE}, //   D5 / A15 / TMR_1_IN
  { NT_GPIOA,  GPIO_Pin_13, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(5)}, //   D6 / A13 / PWM_1_B
  { NT_GPIOB,  GPIO_Pin_8, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D7 / B8 / UART1 TX
  { NT_GPIOA,  GPIO_Pin_4, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D8 / A4 / ECAP0_IO
  { NT_GPIOA,  GPIO_Pin_8, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(0)}, //   D9 / A8 / PWM_0_A
  { NT_GPIOB,  GPIO_Pin_4, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D10 / B4 / SPI_CS
  { NT_GPIOB,  GPIO_Pin_7, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D11 / B7 / SPI_MOSI
  { NT_GPIOB,  GPIO_Pin_6, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D12 / B6 / SPI_MISO
  { NT_GPIOB,  GPIO_Pin_5, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D13 / B5 / SPI_SCK

  { NT_GPIOB,  GPIO_Pin_0, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(0), PIN_PWM_NONE}, //   A0 / B0 / ADC_0
  { NT_GPIOB,  GPIO_Pin_1, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(1), PIN_PWM_NONE}, //   A1 / B1 / ADC_1
  { NT_GPIOB,  GPIO_Pin_2, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(2), PIN_PWM_NONE}, //   A2 / B2 / ADC_2
  { NT_GPIOB,  GPIO_Pin_3, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(3), PIN_PWM_NONE}, //   A3 / B3 / ADC_3

  { NT_GPIOA,  GPIO_Pin_0, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   A4 / A0 / I2C_SCL
  { NT_GPIOA,  GPIO_Pin_1, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   A5 / A1 / I2C_SDA

  { NT_GPIOA,  GPIO_Pin_6, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   USER_BTN / A6 / USER_BTN

  { NT_GPIOB,  GPIO_Pin_12, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_0 / B12 
  { NT_GPIOB,  GPIO_Pin_13, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_1 / B13 
  { NT_GPIOB,  GPIO_Pin_14, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_2 / B14 
  { NT_GPIOB,  GPIO_Pin_15, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_3 / B15 


} ;

const pin_size_t adc_ls_ctrl_map[] = 
{
    PIN_LS_0,
    PIN_LS_1,
    PIN_LS_2,
    PIN_LS_3
};


arduino::UartSerial Serial(NT_UART0,PIN_UART_TX0,PIN_UART_RX0);
void UART0_RX_IRQHandler(){
    Serial.IrqHandlerRx();
}
void UART0_TX_IRQHandler(){
    Serial.IrqHandlerTx();
}
void UART0_RT_IRQHandler(){
    Serial.IrqHandlerRxTimeout();
}
arduino::UartSerial Serial1(NT_UART1,PIN_UART_TX1,PIN_UART_RX1);
void UART1_RX_IRQHandler(){
    Serial1.IrqHandlerRx();
}
void UART1_TX_IRQHandler(){
    Serial1.IrqHandlerTx();
}
void UART1_RT_IRQHandler(){
    Serial1.IrqHandlerRxTimeout();
}
arduino::UartSerial Serial2(NT_UART2,PIN_UART_TX2,PIN_UART_RX2);
void UART2_RX_IRQHandler(){
    Serial2.IrqHandlerRx();
}
void UART2_TX_IRQHandler(){
    Serial2.IrqHandlerTx();
}
void UART2_RT_IRQHandler(){
    Serial2.IrqHandlerRxTimeout();
}
arduino::UartSerial Serial3(NT_UART3,PIN_UART_TX3,PIN_UART_RX3);
void UART3_RX_IRQHandler(){
    Serial3.IrqHandlerRx();
}
void UART3_TX_IRQHandler(){
    Serial3.IrqHandlerTx();
}
void UART3_RT_IRQHandler(){
    Serial3.IrqHandlerRxTimeout();
}
