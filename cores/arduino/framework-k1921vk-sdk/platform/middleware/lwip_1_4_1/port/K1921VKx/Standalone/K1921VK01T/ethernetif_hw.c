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
    NT_ETHERNET->DMATxDescriptor = (uint32_t)DMADscrTbl;
}

void ETH_DMARxDscrChainInit(ETH_DMADSCR_TypeDef* DMADscrTbl, uint8_t* Buff, uint32_t BuffCnt)
{
    ETH_DMADscrChainInit(DMADscrTbl, Buff, BuffCnt);
    NT_ETHERNET->DMARxDescriptor = (uint32_t)DMADscrTbl;
    // Enable DMA receiving
    NT_ETHERNET->DMARxCtrl_bit.RXENABLE = 1;
}

void ETH_MACAddrConfig(uint8_t* mac_addr)
{
    NT_ETHERNET->SA0 = (uint32_t)(*(mac_addr + 5) << 8) | (uint32_t)(*(mac_addr + 4));
    NT_ETHERNET->SA1 = (uint32_t)(*(mac_addr + 3) << 8) | (uint32_t)(*(mac_addr + 2));
    NT_ETHERNET->SA2 = (uint32_t)(*(mac_addr + 1) << 8) | (uint32_t)(*mac_addr);
}

void ETH_MACInit(void)
{
    NT_ETHERNET->MAC1_bit.SOFTRESET = 0;

    NT_ETHERNET->MAC1 |= (ETHERNET_MAC1_RXENABLE_Msk |
                          ETHERNET_MAC1_RXPAUSE_Msk |
                          ETHERNET_MAC1_TXPAUSE_Msk);

    NT_ETHERNET->MAC2 |= (ETHERNET_MAC2_CRCENABLE_Msk |
                          ETHERNET_MAC2_PADENABLE_Msk);

    NT_ETHERNET->IPGT = 0x0015; // for full-duplex
    NT_ETHERNET->IPGR = 0x0C12; // recommended values

    NT_ETHERNET->DMAINTMASK |= (ETHERNET_DMAINTMASK_TXPKTSENT_Msk |
                                ETHERNET_DMAINTMASK_RXPKTREC_Msk |
                                ETHERNET_DMAINTMASK_RXOVER_Msk);

    NT_ETHERNET->FIFOCFG = 0x1F00;

    NVIC_EnableIRQ(Ethernet_IRQn);
}

void ETH_DMARxStatusClear(uint32_t flags)
{
    NT_ETHERNET->DMARxStatus |= flags;
}

void ETH_DMATxStatusClear(uint32_t flags)
{
    NT_ETHERNET->DMATxStatus |= flags;
}

uint8_t ETH_IsDMATxEnabled(void)
{
    return (uint8_t)NT_ETHERNET->DMATxCtrl_bit.TXENABLE;
}

uint8_t ETH_IsDMARxEnabled(void)
{
    return (uint8_t)NT_ETHERNET->DMARxCtrl_bit.RXENABLE;
}

void ETH_DMATxEnable(void)
{
    NT_ETHERNET->DMATxCtrl_bit.TXENABLE = 1;
}

void ETH_DMARxEnable(void)
{
    NT_ETHERNET->DMARxCtrl_bit.RXENABLE = 1;
}

void ETH_DMADecrRxPktCnt(void)
{
    NT_ETHERNET->DMARxStatus_bit.RXPKTREC = 1;
}

void ETH_DMADecrTxPktCnt(void)
{
    NT_ETHERNET->DMATxStatus_bit.TX_PKT_COUNT = 1;
}

ETH_MDIOStat_TypeDef ETH_MDIORead(uint8_t phy_addr, uint8_t phy_reg_addr, uint16_t* prd_var)
{
    // set all addresses thats need
    NT_ETHERNET->MADR_bit.PHY_ADDRESS = phy_addr;
    NT_ETHERNET->MADR_bit.REG_ADDRESS = phy_reg_addr;
    // set read command
    NT_ETHERNET->MCMD_bit.READ = 1;
    while (NT_ETHERNET->MIND_bit.BUSY) {
    };
    // check errors
    if (NT_ETHERNET->MIND_bit.NOTVALID)
        return ETH_MDIOStat_NotValid;
    if (NT_ETHERNET->MIND_bit.LINKFAIL)
        return ETH_MDIOStat_LinkFail;
    // disable read command
    NT_ETHERNET->MCMD_bit.READ = 0;
    // set read data
    *prd_var = NT_ETHERNET->MRDD;
    // return status
    return ETH_MDIOStat_OK;
}

ETH_MDIOStat_TypeDef ETH_MDIOWrite(uint8_t phy_addr, uint8_t phy_reg_addr, uint16_t write_data)
{
    //set all addresses thats need
    NT_ETHERNET->MADR_bit.PHY_ADDRESS = phy_addr;
    NT_ETHERNET->MADR_bit.REG_ADDRESS = phy_reg_addr;
    //set write data
    NT_ETHERNET->MWTD = (uint32_t)write_data;
    //
    while (NT_ETHERNET->MIND_bit.BUSY) {
    };
    //check errors
    if (NT_ETHERNET->MIND_bit.NOTVALID)
        return ETH_MDIOStat_NotValid;
    if (NT_ETHERNET->MIND_bit.LINKFAIL)
        return ETH_MDIOStat_LinkFail;
    return ETH_MDIOStat_OK;
}

void ETH_MDIOSpeedConfig(ETH_MDIOSpeed_TypeDef speed)
{
    NT_ETHERNET->MCFG_bit.CLOCK_SELECT = speed;
}

void ETH_Callback(void)
{
    if (NT_ETHERNET->DMAINT_bit.RXPKTREC) {
        LwIP_RxPacketHandle();
    }
    if (NT_ETHERNET->DMAINT_bit.RXOVER) {
        while (NT_ETHERNET->DMARxStatus_bit.RXPKTREC) {
            LwIP_RxPacketHandle();
        }
        ETH_DMARxStatusClear(ETHERNET_DMARxStatus_RXOVERFLOW_Msk);
        ETH_DMARxEnable();
    }
    if (NT_ETHERNET->DMAINT_bit.BUSERR_RX) {
        //FIXME: write bus error handler
        ETH_DMARxStatusClear(ETHERNET_DMARxStatus_BUSERROR_Msk);
    }
    if (NT_ETHERNET->DMAINT_bit.TXPKTSENT) {
        ETH_DMADecrTxPktCnt();
    }
}

void ETH_PHY_Callback(void)
{
    //TODO: write PHY ETHERNET IRQ handler here
}
