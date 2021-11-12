/*==============================================================================
 * UART загрузчик для К1921ВК01T
 *
 * Функции работы с пакетами
 *------------------------------------------------------------------------------
 * НИИЭТ, Богдан Колбов <kolbov@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2019 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "boot_packet.h"

//-- Variables -----------------------------------------------------------------
volatile static struct
{
    uint8_t mem[PACKET_FIFO_BYTES];
    uint32_t wr_ptr;
    uint32_t rd_ptr;
    uint32_t full;
    uint32_t empty;
} packet_fifo;

//-- Private functions ---------------------------------------------------------
//Функция записи в fifo, вызываемая в обработчике прерывания UART_RX
static inline __attribute__((always_inline)) void packet_fifo_write(uint8_t data)
{
    if (!packet_fifo.full) {
        packet_fifo.mem[packet_fifo.wr_ptr] = data;
        packet_fifo.empty = 0;
        if (packet_fifo.wr_ptr == (PACKET_FIFO_BYTES - 1))
            packet_fifo.wr_ptr = 0;
        else
            packet_fifo.wr_ptr++;
    }

    if (packet_fifo.wr_ptr == packet_fifo.rd_ptr)
        packet_fifo.full = 1;
    else
        packet_fifo.full = 0;
}

//-- Functions -----------------------------------------------------------------
//Инициализация fifo
void packet_fifo_init()
{
    packet_fifo.wr_ptr = 0;
    packet_fifo.rd_ptr = 0;
    packet_fifo.full = 0;
    packet_fifo.empty = 1;
}

//Чтение байта из пакетного fifo
uint8_t packet_fifo_read()
{
    uint8_t data = 0;

    while (packet_fifo.empty) {
    };
    __disable_irq();
    data = packet_fifo.mem[packet_fifo.rd_ptr];
    if (packet_fifo.rd_ptr == (PACKET_FIFO_BYTES - 1))
        packet_fifo.rd_ptr = 0;
    else
        packet_fifo.rd_ptr++;

    if ((packet_fifo.wr_ptr == packet_fifo.rd_ptr) && !packet_fifo.full)
        packet_fifo.empty = 1;
    __enable_irq();
    return data;
}

//Побайтовый расчет CRC16
uint16_t crc_upd(uint16_t crc_in, uint8_t data)
{
    uint32_t crc = crc_in;
    uint32_t in = data | 0x100;

    do {
        crc <<= 1;
        in <<= 1;
        if (in & 0x100)
            ++crc;
        if (crc & 0x10000)
            crc ^= 0x1021;
    } while (!(in & 0x10000));

    return crc & 0xffffu;
}

//Поиск и прием пакетов
void packet_recieve(Packet_TypeDef* rx_packet)
{
    uint16_t rx_signature;
    uint8_t rx_cmd;
    uint8_t rx_cmd_inv;
    uint16_t rx_data_n;
    uint16_t pre_crc;

    //поиск сигнатуры
    rx_signature = 0x0000;
    while (rx_signature != PACKET_HOST_SIGN) {
        rx_signature = (rx_signature >> 8) | (uint16_t)(packet_fifo_read() << 8);
    }
    //считываем служебную инфмацию
    rx_cmd = packet_fifo_read();
    rx_cmd_inv = packet_fifo_read();
    rx_data_n = packet_fifo_read_u16();

    //проверяем корректность команды
    if ((rx_cmd ^ rx_cmd_inv) != 0xFF) {
        rx_packet->cmd_code = CMD_NONE;
        rx_packet->tmp_data8[0] = MSG_ERR_CMD;
    }
    //если все верно, то начинаем считать crc
    else {
        pre_crc = 0;
        pre_crc = crc_upd(pre_crc, rx_cmd);
        pre_crc = crc_upd(pre_crc, rx_cmd_inv);
        pre_crc = crc_upd_u16(pre_crc, rx_data_n);
        //передаем то что распарсили в ядро, crc досчитается и проверится уже там в обработчике конкретной команды
        rx_packet->cmd_code = rx_cmd;
        rx_packet->data_n = rx_data_n;
        rx_packet->crc = pre_crc;
    }
}

//Проверка статуса отправки текущего пакета
uint32_t packet_transmit_status_busy()
{
    return UARTx->FR_bit.BUSY | !UARTx->FR_bit.TXFE;
}

//Отправка исходящего пакета
void packet_transmit(Packet_TypeDef* tx_packet)
{
    uint16_t crc = 0;

    //ждем если есть передача
    while (packet_transmit_status_busy()) {
    };
    DBG_PRINT(0x20);
    DBG_PRINT(tx_packet->cmd_code);

    //грузим все сразу в uart fifo
    UARTx->DR = PACKET_DEVICE_SIGN & 0x00FF;
    UARTx->DR = (PACKET_DEVICE_SIGN & 0xFF00) >> 8;

    UARTx->DR = tx_packet->cmd_code;
    crc = crc_upd(crc, tx_packet->cmd_code);

    UARTx->DR = ~tx_packet->cmd_code;
    crc = crc_upd(crc, ~tx_packet->cmd_code);

    UARTx->DR = tx_packet->data_n & 0x00FF;
    UARTx->DR = (tx_packet->data_n & 0xFF00) >> 8;
    crc = crc_upd_u16(crc, tx_packet->data_n);

    for (uint16_t i = 0; i < tx_packet->data_n; i++) {
        while (!UARTx->RIS_bit.TXRIS || UARTx->FR_bit.TXFF) {
        };
        UARTx->DR = tx_packet->tmp_data8[i];
        UARTx->ICR = UART_ICR_TXIC_Msk;
        crc = crc_upd(crc, tx_packet->tmp_data8[i]);
    }

    UARTx->DR = crc & 0x00FF;
    UARTx->DR = (crc & 0xFF00) >> 8;
}

//Обертка для чтения 32-битных значений из пакетного fifo
uint32_t packet_fifo_read_u32()
{
    uint32_t data = 0;

    data = (uint32_t)(packet_fifo_read() << 0);
    data |= (uint32_t)(packet_fifo_read() << 8);
    data |= (uint32_t)(packet_fifo_read() << 16);
    data |= (uint32_t)(packet_fifo_read() << 24);

    return data;
}

//Обертка для чтения 16-битных значений из пакетного fifo
uint16_t packet_fifo_read_u16()
{
    uint16_t data = 0;

    data = (uint16_t)(packet_fifo_read() << 0);
    data |= (uint16_t)(packet_fifo_read() << 8);

    return data;
}

//Обертка для расчета CRC16 для 32-битных данных
uint16_t crc_upd_u32(uint16_t crc_in, uint32_t data)
{
    crc_in = crc_upd(crc_in, (uint8_t)((data & 0x000000FF) >> 0));
    crc_in = crc_upd(crc_in, (uint8_t)((data & 0x0000FF00) >> 8));
    crc_in = crc_upd(crc_in, (uint8_t)((data & 0x00FF0000) >> 16));
    crc_in = crc_upd(crc_in, (uint8_t)((data & 0xFF000000) >> 24));

    return crc_in;
}

//Обертка для расчета CRC16 для 16-битных данных
uint16_t crc_upd_u16(uint16_t crc_in, uint16_t data)
{
    crc_in = crc_upd(crc_in, (uint8_t)((data & 0x00FF) >> 0));
    crc_in = crc_upd(crc_in, (uint8_t)((data & 0xFF00) >> 8));

    return crc_in;
}

//-- Interrupt handlers --------------------------------------------------------
RAMFUNC void UARTx_RX_IRQHandler()
{
    UARTx->ICR = UART_ICR_RXIC_Msk;

    while (!UARTx->FR_bit.RXFE) { //вычитываем uart fifo полностью
        packet_fifo_write(UARTx->DR_bit.DATA);
    }
}
