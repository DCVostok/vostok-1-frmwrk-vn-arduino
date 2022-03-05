#include "variant.h"

/*
 * Pins descriptions
 */
const PinDescription pins_description_map[]=
{

  { NT_GPIOC,  GPIO_Pin_3, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //  D0 / C3 / UART0 RX
  { NT_GPIOC,  GPIO_Pin_4, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //  D1 / C4 / UART0 TX
  { NT_GPIOG,  GPIO_Pin_14, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D2 / G14 / Int0
  { NT_GPIOG,  GPIO_Pin_13, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(9)}, //   D3 / G13 / PWM_4_B
  { NT_GPIOG,  GPIO_Pin_12, (PIN_ATTR_TIMER_IN), PIN_ADC_NONE, PIN_PWM_NONE}, //   D4 / G12 / TMR_0_IN
  { NT_GPIOG,  GPIO_Pin_11, (PIN_ATTR_TIMER_IN), PIN_ADC_NONE, PIN_PWM_NONE}, //   D5 / G11 / TMR_1_IN
  { NT_GPIOA,  GPIO_Pin_13, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(7)}, //   D6 / A13 / PWM_3_B
  { NT_GPIOA,  GPIO_Pin_12, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(5)}, //   D7 / A12 / PWM_2_B
  { NT_GPIOA,  GPIO_Pin_11, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(3)}, //   D8 / A11 / PWM_1_B
  { NT_GPIOA,  GPIO_Pin_10, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(1)}, //   D9 / A10 / PWM_0_B
  { NT_GPIOA,  GPIO_Pin_5, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(14)}, //   D10 / A5 / SPI_CS,PWM_7_A
  { NT_GPIOA,  GPIO_Pin_1, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(17)}, //   D11 / A1 / SPI_MOSI,PWM_8_B
  { NT_GPIOA,  GPIO_Pin_7, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(16)}, //   D12 / A7 / SPI_MISO,PWM_8_A
  { NT_GPIOA,  GPIO_Pin_6, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(15)}, //   D13 / A6 / SPI_SCK,PWM_7_B
  { NT_GPIOD,  GPIO_Pin_2, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D14 / D2 / UART3_TX
  { NT_GPIOD,  GPIO_Pin_1, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D15 / D1 / UART3_RX
  { NT_GPIOF,  GPIO_Pin_4, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(5)}, //   D16 / F4 / UART2_TX, PWM_2_B
  { NT_GPIOG,  GPIO_Pin_4, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(4)}, //   D17 / G4 / UART2_RX, PWM_2_A
  { NT_GPIOA,  GPIO_Pin_3, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(12)}, //   D18 / A3 / UART1_TX, PWM_6_A
  { NT_GPIOA,  GPIO_Pin_4, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_CH_NUM(13)}, //   D19 / A4 / UART1_RX, PWM_6_B
  { NT_GPIOD,  GPIO_Pin_10, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D20 / D10 / SDA1
  { NT_GPIOD,  GPIO_Pin_9, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   D21 / D9 /  SCL1


  //-- ANALOG

  { NT_GPIOE,  GPIO_Pin_2, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(0), PIN_PWM_NONE}, //   A0 / E2 / ADC_0 
  { NT_GPIOE,  GPIO_Pin_3, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(1), PIN_PWM_NONE}, //   A1 / E3 / ADC_1 
  { NT_GPIOE,  GPIO_Pin_4, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(2), PIN_PWM_NONE}, //   A2 / E4 / ADC_2 
  { NT_GPIOE,  GPIO_Pin_5, (PIN_ATTR_NEED_LS_CTRL), PIN_ADC_CH_NUM(3), PIN_PWM_NONE}, //   A3 / E5 / ADC_3 

  { NT_GPIOE,  GPIO_Pin_0, (PIN_ATTR_NEED_LS_CTRL),  PIN_ADC_CH_NUM(4), PIN_PWM_NONE}, //   A4 / E0 / I2C_SCL0,ADC_4 
  { NT_GPIOE,  GPIO_Pin_1, (PIN_ATTR_NEED_LS_CTRL),  PIN_ADC_CH_NUM(5), PIN_PWM_NONE}, //   A5 / E1 / I2C_SDA0,ADC_5 

  { NT_GPIOH,  GPIO_Pin_2, (PIN_ATTR_NONE), PIN_ADC_NONE, PIN_PWM_NONE}, //   USER_BTN / H2 / USER_BTN

  { NT_GPIOE,  GPIO_Pin_6, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_0 /  E6
  { NT_GPIOE,  GPIO_Pin_7, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_1 /  E7
  { NT_GPIOE,  GPIO_Pin_8, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_2 /  E8
  { NT_GPIOE,  GPIO_Pin_9, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_3 /  E9
  { NT_GPIOE,  GPIO_Pin_10, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_4 / E10
  { NT_GPIOE,  GPIO_Pin_11, (PIN_ATTR_LVL_SHIFTER_CTRL), PIN_ADC_NONE, PIN_PWM_NONE}, //   LS_5 / E11

} ;

const pin_size_t adc_ls_ctrl_map[] = 
{
    PIN_LS_0,
    PIN_LS_1,
    PIN_LS_2,
    PIN_LS_3,
    PIN_LS_4,
    PIN_LS_5
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
