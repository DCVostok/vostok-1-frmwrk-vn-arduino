/*==============================================================================
 * Низкоуровневый драйвер блока Ethernet К1921ВК028
 *------------------------------------------------------------------------------
 * НИИЭТ, Дмитрий Сериков <lonie@niiet.ru>
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

#ifndef ETHERNETIF_HW_H
#define ETHERNETIF_HW_H

#ifdef __cplusplus
extern "C" {
#endif

//-- Includes ------------------------------------------------------------------
#include "K1921VK028.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//-- Defines -------------------------------------------------------------------
typedef struct ETH_DMADSCR_Struct {
    volatile uint32_t* pkt_addr; // Packet address
    volatile uint32_t pkt_size;  // Packet size and status
    struct ETH_DMADSCR_Struct* nxt_dscr;
} ETH_DMADSCR_TypeDef;

#define ETH_DMADscr_Empty ((uint32_t)0x80000000)

typedef enum {
    ETH_MDIOSpeed_Div4 = ETH_MCFG_CLKSEL_Div4,
    ETH_MDIOSpeed_Div6 = ETH_MCFG_CLKSEL_Div6,
    ETH_MDIOSpeed_Div8 = ETH_MCFG_CLKSEL_Div8,
    ETH_MDIOSpeed_Div10 = ETH_MCFG_CLKSEL_Div10,
    ETH_MDIOSpeed_Div14 = ETH_MCFG_CLKSEL_Div14,
    ETH_MDIOSpeed_Div20 = ETH_MCFG_CLKSEL_Div20,
    ETH_MDIOSpeed_Div28 = ETH_MCFG_CLKSEL_Div28
} ETH_MDIOSpeed_TypeDef;

typedef enum {
    ETH_MDIOStat_OK,
    ETH_MDIOStat_Busy,
    ETH_MDIOStat_NotValid,
    ETH_MDIOStat_LinkFail
} ETH_MDIOStat_TypeDef;

//-- Functions  ----------------------------------------------------------------
void ETH_DMATxDscrChainInit(ETH_DMADSCR_TypeDef* DMADscrTbl, uint8_t* Buff, uint32_t BuffCnt);
void ETH_DMARxDscrChainInit(ETH_DMADSCR_TypeDef* DMADscrTbl, uint8_t* Buff, uint32_t BuffCnt);
void ETH_MACAddrConfig(uint8_t* mac_addr);
void ETH_MACInit(void);
void ETH_Callback(void);
uint8_t ETH_IsDMATxEnabled(void);
uint8_t ETH_IsDMARxEnabled(void);
void ETH_DMATxEnable(void);
void ETH_DMARxEnable(void);
void ETH_DMADecrRxPktCnt(void);
void ETH_DMADecrTxPktCnt(void);
void ETH_DMARxStatusClear(uint32_t flags);
void ETH_DMATxStatusClear(uint32_t flags);

ETH_MDIOStat_TypeDef ETH_MDIORead(uint8_t phy_addr, uint8_t phy_reg_addr, uint16_t* prd_var);
ETH_MDIOStat_TypeDef ETH_MDIOWrite(uint8_t phy_addr, uint8_t reg_addr, uint16_t write_data);
void ETH_MDIOSpeedConfig(ETH_MDIOSpeed_TypeDef speed);

void ETH_PHY_Callback(void);

#ifdef __cplusplus
}
#endif

#endif //ETHERNETIF_HW_H
