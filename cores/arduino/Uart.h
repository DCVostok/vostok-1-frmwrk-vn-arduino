#ifndef UART_H
#define UART_H

#include "wiring_private.h"
#include "api/RingBuffer.h"
#include "api/HardwareSerial.h"
#include "api/Print.h"


#include <cstddef>

#define SERIAL_BUFFER_SIZE  64
namespace arduino{
    class UartSerial : public HardwareSerial
    {
      public:
        UartSerial(UART_TypeDef* nt_uart, int pin_tx, int pin_rx);
        void begin(unsigned long baudRate);
        void begin(unsigned long baudrate, uint16_t config);
        void end();
        int available();
        int availableForWrite();
        int peek();
        int read();
        void flush();
        size_t write(const uint8_t data);
        using Print::write; // pull in write(str) and write(buf, size) from Print
        operator bool() { return true; }
        void IrqHandlerRx();
        void IrqHandlerRxTimeout();
        void IrqHandlerTx();
        

      private:
        static const int _c_irq_priority = 2;
        void init_gpio_nvic_rcc();
        UART_TypeDef* _nt_uart;
        RingBuffer _rxBuffer;
        //RingBuffer _txBuffer;
        int _pin_tx;
        int _pin_rx;
        //volatile bool tx_in_progress;
    };
}
#endif