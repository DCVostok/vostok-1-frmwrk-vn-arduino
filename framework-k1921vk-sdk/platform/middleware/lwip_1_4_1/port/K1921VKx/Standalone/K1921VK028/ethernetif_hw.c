/*==============================================================================
 * Низкоуровневый драйвер блока Ethernet К1921ВК01Т
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

//-- Includes ------------------------------------------------------------------
#include "ethernetif.h"

//-- Functions -----------------------------------------------------------------
void ETH_DMADscrChainInit(ETH_DMADSCR_TypeDef* DMADscrTbl, uint8_t* Buff, uint32_t BuffCnt)
{
    uint32_t i = 0;
    ETH_DMADSCR_TypeDef* DMADscr;

    for (i = 0; i < BuffCnt; i++) {
        // Get one descriptor
        DMADscr = DMADscrTbl + i;
        // Set pointer to Buf
        DMADscr->pkt_addr = (uint32_t*)(&Buff[i * ETH_MAX_PACKET_SIZE]);
        // Set EMPTY flag
        DMADscr->pkt_size = ETH_DMADscr_Empty;

        if (i < (BuffCnt - 1))
            DMADscr->nxt_dscr = DMADscrTbl + (i + 1);
        else
            DMADscr->nxt_dscr = DMADscrTbl;
    }
}

void ETH_DMATxDscrChainInit(ETH_DMADSCR_TypeDef* DMADscrTbl, uint8_t* Buff, uint32_t BuffCnt)
{
    ETH_DMADscrChainInit(DMADscrTbl, Buff, BuffCnt);
    ETH->DMATXDESCR = (uint32_t)DMADscrTbl;
}

void ETH_DMARxDscrChainInit(ETH_DMADSCR_TypeDef* DMADscrTbl, uint8_t* Buff, uint32_t BuffCnt)
{
    ETH_DMADscrChainInit(DMADscrTbl, Buff, BuffCnt);
    ETH->DMARXDESCR = (uint32_t)DMADscrTbl;
    // Enable DMA receiving
    ETH->DMARXCTRL_bit.RXENABLE = 1;
}

void ETH_MACAddrConfig(uint8_t* mac_addr)
{
    ETH->SA0 = (uint32_t)(*(mac_addr + 5) << 8) | (uint32_t)(*(mac_addr + 4));
    ETH->SA1 = (uint32_t)(*(mac_addr + 3) << 8) | (uint32_t)(*(mac_addr + 2));
    ETH->SA2 = (uint32_t)(*(mac_addr + 1) << 8) | (uint32_t)(*mac_addr);
}

void ETH_MACInit(void)
{
    ETH->MAC1_bit.SOFTRESET = 0;

    ETH->MAC1 |= (ETH_MAC1_RXENABLE_Msk |
                  ETH_MAC1_RXPAUSE_Msk |
                  ETH_MAC1_TXPAUSE_Msk);

    ETH->MAC2 |= (ETH_MAC2_CRCENABLE_Msk |
                  ETH_MAC2_PADENABLE_Msk);

    ETH->IPGT = 0x0015; // for full-duplex
    ETH->IPGR = 0x0C12; // recommended values

    ETH->DMAINTMASK |= (ETH_DMAINTMASK_TXPKTSENT_Msk |
                        ETH_DMAINTMASK_RXPKTREC_Msk |
                        ETH_DMAINTMASK_RXOVER_Msk);

    ETH->FIFOCFG = 0x1F00;

    NVIC_EnableIRQ(ETH_IRQn);
}

void ETH_DMARXSTATClear(uint32_t flags)
{
    ETH->DMARXSTAT |= flags;
}

void ETH_DMATXSTATClear(uint32_t flags)
{
    ETH->DMATXSTAT |= flags;
}

uint8_t ETH_IsDMATxEnabled(void)
{
    return (uint8_t)ETH->DMATXCTRL_bit.TXENABLE;
}

uint8_t ETH_IsDMARxEnabled(void)
{
    return (uint8_t)ETH->DMARXCTRL_bit.RXENABLE;
}

void ETH_DMATxEnable(void)
{
    ETH->DMATXCTRL_bit.TXENABLE = 1;
}

void ETH_DMARxEnable(void)
{
    ETH->DMARXCTRL_bit.RXENABLE = 1;
}

void ETH_DMADecrRxPktCnt(void)
{
    ETH->DMARXSTAT_bit.RXPKTREC = 1;
}

void ETH_DMADecrTxPktCnt(void)
{
    ETH->DMATXSTAT_bit.TXPKTSENT = 1;
}

ETH_MDIOStat_TypeDef ETH_MDIORead(uint8_t phy_addr, uint8_t phy_reg_addr, uint16_t* prd_var)
{
    // set all addresses thats need
    ETH->MADR_bit.PHYADDR = phy_addr;
    ETH->MADR_bit.REGADDR = phy_reg_addr;
    // set read command
    ETH->MCMD_bit.READ = 1;
    while (ETH->MIND_bit.BUSY) {
    };
    // check errors
    if (ETH->MIND_bit.NOTVALID)
        return ETH_MDIOStat_NotValid;
    if (ETH->MIND_bit.LINKFAIL)
        return ETH_MDIOStat_LinkFail;
    // disable read command
    ETH->MCMD_bit.READ = 0;
    // set read data
    *prd_var = ETH->MRDD;
    // return status
    return ETH_MDIOStat_OK;
}

ETH_MDIOStat_TypeDef ETH_MDIOWrite(uint8_t phy_addr, uint8_t phy_reg_addr, uint16_t write_data)
{
    //set all addresses thats need
    ETH->MADR_bit.PHYADDR = phy_addr;
    ETH->MADR_bit.REGADDR = phy_reg_addr;
    //set write data
    ETH->MWTD = (uint32_t)write_data;
    //
    while (ETH->MIND_bit.BUSY) {
    };
    //check errors
    if (ETH->MIND_bit.NOTVALID)
        return ETH_MDIOStat_NotValid;
    if (ETH->MIND_bit.LINKFAIL)
        return ETH_MDIOStat_LinkFail;
    return ETH_MDIOStat_OK;
}

void ETH_MDIOSpeedConfig(ETH_MDIOSpeed_TypeDef speed)
{
    ETH->MCFG_bit.CLKSEL = speed;
}

void ETH_Callback(void)
{
    if (ETH->DMAINT_bit.RXPKTREC) {
        LwIP_RxPacketHandle();
    }
    if (ETH->DMAINT_bit.RXOVER) {
        while (ETH->DMARXSTAT_bit.RXPKTREC) {
            LwIP_RxPacketHandle();
        }
        ETH_DMARXSTATClear(ETH_DMARXSTAT_RXOVERFLOW_Msk);
        ETH_DMARxEnable();
    }
    if (ETH->DMAINT_bit.BUSERRRX) {
        //FIXME: write bus error handler
        ETH_DMARXSTATClear(ETH_DMARXSTAT_BUSERROR_Msk);
    }
    if (ETH->DMAINT_bit.TXPKTSENT) {
        ETH_DMADecrTxPktCnt();
    }
}

void ETH_PHY_Callback(void)
{
    //TODO: write PHY ETHERNET IRQ handler here
}
