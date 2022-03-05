/*==============================================================================
 * Драйвер сети Ethernet микроконтроллеров К1921ВКх, адаптированный
 * для использования с LwIP
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
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/opt.h"
#include "lwip/pbuf.h"
#include "netif/etharp.h"
#include "netif/ppp_oe.h"
#include <lwip/snmp.h>
#include <lwip/stats.h>

#define ETH_TXBUFCELLS 10
#define ETH_RXBUFCELLS 10

// Define those to better describe your network interface.
#define IFNAME0 'e'
#define IFNAME1 'n'

ETH_DMADSCR_TypeDef DMATxDscrTbl[ETH_TXBUFCELLS];
ETH_DMADSCR_TypeDef DMARxDscrTbl[ETH_RXBUFCELLS];
uint8_t TxBuff[ETH_TXBUFCELLS][ETH_MAX_PACKET_SIZE];
uint8_t RxBuff[ETH_RXBUFCELLS][ETH_MAX_PACKET_SIZE];
uint8_t mac_addr[6] = ETH_MAC_ADDR;

struct netif netif;

/**
 * Helper struct to hold private data used to operate your ethernet interface.
 * Keeping the ethernet address of the MAC in this struct is not necessary
 * as it is already kept in the struct netif.
 * But this is only an example, anyway...
 */
struct ethernetif {
    struct eth_addr* ethaddr;
    // Add whatever per-interface state that is needed here.
};

// Forward declarations
err_t ethernetif_input(struct netif* netif);

/**
 * In this function, the hardware should be initialized.
 * Called from ethernetif_init().
 *
 * @param netif the already initialized lwip network interface structure
 *        for this ethernetif
 */
static void
low_level_init(struct netif* netif)
{
    // set MAC hardware address length
    netif->hwaddr_len = ETHARP_HWADDR_LEN;
    // set MAC hardware address
    netif->hwaddr[0] = mac_addr[0];
    netif->hwaddr[1] = mac_addr[1];
    netif->hwaddr[2] = mac_addr[2];
    netif->hwaddr[3] = mac_addr[3];
    netif->hwaddr[4] = mac_addr[4];
    netif->hwaddr[5] = mac_addr[5];
    // maximum transfer unit
    netif->mtu = 1500;
    // device capabilities
    netif->flags |= NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;

    ETH_MACAddrConfig(&mac_addr[0]);

    ETH_DMATxDscrChainInit(DMATxDscrTbl, &TxBuff[0][0], ETH_TXBUFCELLS);
    ETH_DMARxDscrChainInit(DMARxDscrTbl, &RxBuff[0][0], ETH_RXBUFCELLS);

    ETH_MACInit();
    ETH_MDIOSpeedConfig(ETH_MDIOSpeed_Div28);
}

/**
 * This function should do the actual transmission of the packet. The packet is
 * contained in the pbuf that is passed to the function. This pbuf
 * might be chained.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
 * @return ERR_OK if the packet could be sent
 *         an err_t value if the packet couldn't be sent
 *
 * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
 *       strange results. You might consider waiting for space in the DMA queue
 *       to become availale since the stack doesn't retry to send a packet
 *       dropped because of memory failure (except for the TCP timers).
 */

static err_t
low_level_output(struct netif* netif, struct pbuf* p)
{
    //suppress unused var warning
    (void)netif;

    static uint32_t idx_wr_ptr = 0;
    //struct ethernetif *ethernetif = netif->state;
    struct pbuf* q;
    uint32_t l = 0;
    ETH_DMADSCR_TypeDef* DMADescr;
    uint8_t* buffer;
    //get descriptor
    DMADescr = &DMATxDscrTbl[idx_wr_ptr];

    // if descriptor is full, return ERR_MEM
    if ((DMADescr->pkt_size & ETH_DMADscr_Empty) == 0)
        return ERR_MEM;

    buffer = (uint8_t*)DMADescr->pkt_addr;

    for (q = p; q != NULL; q = q->next) {
        memcpy((u8_t*)&buffer[l], q->payload, q->len);
        l = l + q->len;
    }
    // set data length for DMA TX
    DMADescr->pkt_size = l;
    // incr wr pointer
    if (idx_wr_ptr >= (ETH_TXBUFCELLS - 1))
        idx_wr_ptr = 0;
    else
        idx_wr_ptr++;
    // check tx enable (if not, then launch!)
    if (ETH_IsDMATxEnabled() == 0)
        ETH_DMATxEnable();

    return ERR_OK;
}

/**
 * Should allocate a pbuf and transfer the bytes of the incoming
 * packet from the interface into the pbuf.
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return a pbuf filled with the received packet (including MAC header)
 *         NULL on memory error
 */
static struct pbuf*
low_level_input(struct netif* netif)
{
    //suppress unused var warning
    (void)netif;
    struct pbuf *p, *q;
    u16_t len;
    uint32_t l = 0;
    ETH_DMADSCR_TypeDef* DMADescr;
    static uint32_t idx_rd_ptr = 0;
    uint8_t* buffer;

    p = NULL;
    // set pointer to DMA descriptor and get data from them
    DMADescr = &DMARxDscrTbl[idx_rd_ptr];
    // if descriptor is empty, return NULL pointer
    if ((DMADescr->pkt_size & ETH_DMADscr_Empty) != 0)
        return p;
    //else read data from DMA
    len = DMADescr->pkt_size;
    buffer = (uint8_t*)DMADescr->pkt_addr;

    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);

    if (p != NULL) {
        for (q = p; q != NULL; q = q->next) {
            memcpy((uint8_t*)q->payload, (uint8_t*)&buffer[l], q->len);
            l = l + q->len;
        }
    }
    //free DMA RX Descriptor
    DMADescr->pkt_size = ETH_DMADscr_Empty;
    // Decrement packet count
    ETH_DMADecrRxPktCnt();
    //change idx_rd_ptr
    if (idx_rd_ptr >= (ETH_RXBUFCELLS - 1))
        idx_rd_ptr = 0;
    else
        idx_rd_ptr++;
    //check if RX DMA not enabled
    if (ETH_IsDMARxEnabled() == 0)
        ETH_DMARxEnable();

    return p;
}

/**
 * This function should be called when a packet is ready to be read
 * from the interface. It uses the function low_level_input() that
 * should handle the actual reception of bytes from the network
 * interface. Then the type of the received packet is determined and
 * the appropriate input function is called.
 *
 * @param netif the lwip network interface structure for this ethernetif
 */
err_t ethernetif_input(struct netif* netif)
{
    err_t err = ERR_OK;

    //struct ethernetif* ethernetif;
    //struct eth_hdr *ethhdr;
    struct pbuf* p;

    //ethernetif = netif->state;

    // move received packet into a new pbuf
    p = low_level_input(netif);
    // no packet could be read, silently ignore this
    if (p == NULL)
        return ERR_MEM;

    err = netif->input(p, netif);

    if (err != ERR_OK) {
        pbuf_free(p);
        p = NULL;
    }

    return err;
}

/**
 * Should be called at the beginning of the program to set up the
 * network interface. It calls the function low_level_init() to do the
 * actual setup of the hardware.
 *
 * This function should be passed as a parameter to netif_add().
 *
 * @param netif the lwip network interface structure for this ethernetif
 * @return ERR_OK if the loopif is initialized
 *         ERR_MEM if private data couldn't be allocated
 *         any other err_t on error
 */
err_t ethernetif_init(struct netif* netif)
{
    struct ethernetif* ethernetif;

    LWIP_ASSERT("netif != NULL", (netif != NULL));

    ethernetif = mem_malloc(sizeof(struct ethernetif));
    if (ethernetif == NULL) {
        LWIP_DEBUGF(NETIF_DEBUG, ("ethernetif_init: out of memory\n"));
        return ERR_MEM;
    }

#if LWIP_NETIF_HOSTNAME
    /* Initialize interface hostname */
    netif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

    /*
   * Initialize the snmp variables and counters inside the struct netif.
   * The last argument should be replaced with your link speed, in units
   * of bits per second.
   */
    NETIF_INIT_SNMP(netif, snmp_ifType_ethernet_csmacd, LINK_SPEED_OF_YOUR_NETIF_IN_BPS);

    netif->state = ethernetif;
    netif->name[0] = IFNAME0;
    netif->name[1] = IFNAME1;
    /* We directly use etharp_output() here to save a function call.
   * You can instead declare your own function an call etharp_output()
   * from it if you have to do some checks before sending (e.g. if link
   * is available...) */
    netif->output = etharp_output;
    netif->linkoutput = low_level_output;

    ethernetif->ethaddr = (struct eth_addr*)&(netif->hwaddr[0]);

    /* initialize the hardware */
    low_level_init(netif);

    return ERR_OK;
}

//TODO: need to implement sys_now to use NO_SYS_NO_TIMERS=0(lwipopts.h)
// Returns the current time in milliseconds when LWIP_TIMERS == 1 and NO_SYS == 1
//u32_t sys_now(void)
//{
//  return GetTick();
//}

void LwIP_RxPacketHandle(void)
{
    ethernetif_input(&netif);
}

void LwIP_Init(void)
{
    struct ip_addr ipaddr;
    struct ip_addr netmask;
    struct ip_addr gw;

    // Initializes the dynamic memory heap defined by MEM_SIZE
    mem_init();

    // Initializes the memory pools defined by MEMP_NUM_x
    memp_init();

    IP4_ADDR(&ipaddr, 192, 168, 5, 48);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&gw, 192, 168, 1, 1);

    netif_add(&netif,
              &ipaddr,
              &netmask,
              &gw,
              NULL,
              ethernetif_init,
              ethernet_input);

#if LWIP_DHCP
    /*  Creates a new DHCP client for this interface on the first call.
  Note: you must call dhcp_fine_tmr() and dhcp_coarse_tmr() at
  the predefined regular intervals after starting the client.
  You can peek in the netif->dhcp struct for the actual DHCP status.*/
    dhcp_start(&netif);
#endif
    netif_set_default(&netif);
    //  When the netif is fully configured this function must be called
    netif_set_up(&netif);
}
