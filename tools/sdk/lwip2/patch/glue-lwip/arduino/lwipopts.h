// this file will be overwritten upon lwip2 rebuild
#ifndef __CUSTOM_EXTRA_DEFINES__
#define __CUSTOM_EXTRA_DEFINES__

#endif
#ifndef MYLWIPOPTS_H
#define MYLWIPOPTS_H

/* opt.h version lwip-2.1.3 for esp8266 */

/**
 * @file
 *
 * lwIP Options Configuration
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/*
 * NOTE: || defined __DOXYGEN__ is a workaround for doxygen bug -
 * without this, doxygen does not see the actual #define
 */

/*
 * Include user defined options first. Anything not defined in these files
 * will be set to standard values. Override anything you don't like!
 */
//#include "lwip/debug.h"      // done at end of this file
#include "gluedebug.h"

/**
 * @defgroup lwip_opts Options (lwipopts.h)
 * @ingroup lwip
 *
 * @defgroup lwip_opts_debug Debugging
 * @ingroup lwip_opts
 *
 * @defgroup lwip_opts_infrastructure Infrastructure
 * @ingroup lwip_opts
 *
 * @defgroup lwip_opts_callback Callback-style APIs
 * @ingroup lwip_opts
 *
 * @defgroup lwip_opts_threadsafe_apis Thread-safe APIs
 * @ingroup lwip_opts
 */

 /*
   ---------------------------------------------------
   -------------- CUSTOM CONFIGURATIONS --------------
   ---------------------------------------------------
*/
#undef NO_SYS
#define NO_SYS                          1 

#undef LWIP_FEATURES
#define LWIP_FEATURES                   1

#undef LWIP_RAW
#define LWIP_RAW                        1

#undef LWIP_IPV6
#define LWIP_IPV6                       0

/* ---------- memory options ---------- */
#undef MEM_LIBC_MALLOC
#define MEM_LIBC_MALLOC                 0 

#undef MEM_SANITY_CHECK
#define MEM_SANITY_CHECK                0

#undef MEM_OVERFLOW_CHECK
#define MEM_OVERFLOW_CHECK              0

#undef MEM_USE_POOLS
#define MEM_USE_POOLS                   1

#undef MEM_USE_POOLS_TRY_BIGGER_POOL
#define MEM_USE_POOLS_TRY_BIGGER_POOL   0

#undef MEMP_USE_CUSTOM_POOLS
#define MEMP_USE_CUSTOM_POOLS           1

// MEM_SIZE: the size of the heap memory. This is a statically allocated block.
#undef MEM_SIZE
#define MEM_SIZE                        (32*1024)

#undef MEM_ALIGNMENT
#define MEM_ALIGNMENT                   4

/* ---------- tcp options ---------- */
#undef TCP_MSS                         
#define TCP_MSS                         1460

#undef TCP_OVERSIZE                         
#define TCP_OVERSIZE                    TCP_MSS // TCP_MSS required for esp8266

// should be big enough to accept multiple packet buffers and not be blocked when there are multiple tcp writes.
#undef TCP_SND_BUF
#define TCP_SND_BUF                     (5*1024)

// TCP_WND have to be at least a couple of segments. It should be less than total pbup_pool_size
#undef TCP_WND
#define TCP_WND                         TCP_SND_BUF

#undef LWIP_WND_SCALE
#define LWIP_WND_SCALE                  0

#undef TCP_RCV_SCALE
#define TCP_RCV_SCALE                   0

// must be less than 256 
#undef TCP_SND_QUEUELEN
#define TCP_SND_QUEUELEN                3

#undef LWIP_DISABLE_TCP_SANITY_CHECKS
#define LWIP_DISABLE_TCP_SANITY_CHECKS  1

// do not send out of order packets
#undef TCP_QUEUE_OOSEQ
#define TCP_QUEUE_OOSEQ                 0

#undef LWIP_TCP_SACK_OUT
#define LWIP_TCP_SACK_OUT               0

/**
 * TCP_SNDLOWAT: TCP writable space (bytes). This must be less than
 * TCP_SND_BUF. It is the amount of space which must be available in the
 * TCP snd_buf for select to return writable (combined with TCP_SNDQUEUELOWAT).
 */
#undef TCP_SNDLOWAT
#define TCP_SNDLOWAT                    3072

/**
 * TCP_SNDQUEUELOWAT: TCP writable bufs (pbuf count). This must be less
 * than TCP_SND_QUEUELEN. If the number of pbufs queued on a pcb drops below
 * this number, select returns writable (combined with TCP_SNDLOWAT).
 */
#undef TCP_SNDQUEUELOWAT
#define TCP_SNDQUEUELOWAT               2

/**
 * TCP_WND_UPDATE_THRESHOLD: difference in window to trigger an
 * explicit window update
 */
#undef TCP_WND_UPDATE_THRESHOLD
#define TCP_WND_UPDATE_THRESHOLD        1536

/* ---------- udp options ---------- */
#undef LWIP_UDPLITE
#define LWIP_UDPLITE                    1

/* ---------- memp options ---------- */
// determines whether malloc memory is dynamically or statically allocated 
// (0 = static memory)
#undef MEMP_MEM_MALLOC
#define MEMP_MEM_MALLOC		            	0

#undef MEMP_SANITY_CHECK
#define MEMP_SANITY_CHECK               0 // MEMP_SANITY_CHECK=0 stabilizes time between two sent packets hence increasing overall throughput

#undef MEMP_OVERFLOW_CHECK
#define MEMP_OVERFLOW_CHECK             0

/* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
   sends a lot of data out of ROM (or other static memory), this
   should be set high (>1024). */
#undef MEMP_NUM_PBUF
#define MEMP_NUM_PBUF                   10 

/* MEMP_NUM_TCP_PCB: the number of simultaneously active TCP
   connections. */
#undef MEMP_NUM_TCP_PCB
#define MEMP_NUM_TCP_PCB                4

#undef MEMP_NUM_TCP_PCB_LISTEN
#define MEMP_NUM_TCP_PCB_LISTEN         2 

#undef MEMP_NUM_UDP_PCB
#define MEMP_NUM_UDP_PCB                6

#undef MEMP_NUM_RAW_PCB
#define MEMP_NUM_RAW_PCB                6

#undef MEMP_NUM_TCP_PCB_TIME_WAIT
#define MEMP_NUM_TCP_PCB_TIME_WAIT      2

/* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
   segments. (2 * TCP_SND_QUEUELEN) */
#undef MEMP_NUM_TCP_SEG
#define MEMP_NUM_TCP_SEG                12

#undef MEMP_NUM_SYS_TIMEOUT
#define MEMP_NUM_SYS_TIMEOUT            10

/* ---------- pbuf options ---------- */
// PBUF_POOL_SIZE is the total number of available pbufs. total pool zize equals (PBUF_POOL_SIZE * PBUF_POOL_BUFSIZE) bytes
#undef PBUF_POOL_SIZE
#define PBUF_POOL_SIZE                  0

// **packet buffers are approximately MTU size (1500) and therefore smaller packet buffers are just wasted.The code joins together smaller buffers to fit an mtu sized buffer i.e (3 x 500 byte = 1500). Therefore having a 500 byte bufsize gives better performance for smaller packets because each has its own buffer.
#undef PBUF_POOL_BUFSIZE
#define PBUF_POOL_BUFSIZE               LWIP_MEM_ALIGN_SIZE(1536)

/* ---------- netif options ---------- */
#undef LWIP_NETIF_TX_SINGLE_PBUF
#define LWIP_NETIF_TX_SINGLE_PBUF       1

/* ---------- ip options ---------- */
#undef IP_REASSEMBLY
#define IP_REASSEMBLY                   1

#undef IP_REASS_MAX_PBUFS
#define IP_REASS_MAX_PBUFS              4

#undef MEMP_NUM_REASSDATA
#define MEMP_NUM_REASSDATA              IP_REASS_MAX_PBUFS

#undef IP_FRAG
#define IP_FRAG                         1

/* ---------- arp options ---------- */
#undef ARP_QUEUEING
#define ARP_QUEUEING                    1

#undef ARP_QUEUE_LEN
#define ARP_QUEUE_LEN                   2

#undef MEMP_NUM_ARP_QUEUE
#define MEMP_NUM_ARP_QUEUE              6

/* ---------- Checksum options ---------- */
#define LWIP_CHECKSUM_CTRL_PER_NETIF      1
#define LWIP_CHECKSUM_ON_COPY             1
#define TCP_CHECKSUM_ON_COPY_SANITY_CHECK 0
#define LWIP_CHKSUM_ALGORITHM             3 // 2

#define CHECKSUM_GEN_IP                   1
#define CHECKSUM_GEN_UDP                  1
#define CHECKSUM_GEN_TCP                  1
#define CHECKSUM_GEN_ICMP                 1
#define CHECKSUM_GEN_ICMP6                1

#define CHECKSUM_CHECK_IP                 1
#define CHECKSUM_CHECK_UDP                1
#define CHECKSUM_CHECK_TCP                1
#define CHECKSUM_CHECK_ICMP               1
#define CHECKSUM_CHECK_ICMP6              1

/* ---------- Statistics options ---------- */

#define LWIP_STATS              1
#define LWIP_STATS_DISPLAY      1

#if LWIP_STATS
#define LINK_STATS              0
#define IP_STATS                0
#define ICMP_STATS              0
#define IGMP_STATS              0
#define IPFRAG_STATS            0
#define UDP_STATS               0
#define TCP_STATS               1
#define MEM_STATS               1
#define MEMP_STATS              1
#define PBUF_STATS              1
#define SYS_STATS               1
#define IP_NAPT_STATS           1
#endif /* LWIP_STATS */

/* ---------- Debug options ---------- */
#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_ALL
#define LWIP_DBG_TYPES_ON               LWIP_DBG_ON
#define LWIP_TESTMODE                   0

#define PBUF_DEBUG                      LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_OFF
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_OFF
#define TIMERS_DEBUG                    LWIP_DBG_OFF
#define TCP_DEBUG                       LWIP_DBG_OFF
#define TCP_INPUT_DEBUG                 LWIP_DBG_OFF
#define TCP_FR_DEBUG                    LWIP_DBG_OFF
#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
#define TCP_WND_DEBUG                   LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG                LWIP_DBG_OFF
#define TCP_RST_DEBUG                   LWIP_DBG_OFF
#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
#define UDP_DEBUG                       LWIP_DBG_OFF
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define AUTOIP_DEBUG                    LWIP_DBG_OFF
#define DNS_DEBUG                       LWIP_DBG_OFF
#define NAPT_DEBUG                      LWIP_DBG_OFF


 /*
   ------------------------------------
   -------------- NO SYS --------------
   ------------------------------------
*/
#define LWIP_TIMERS                     1
#define LWIP_TIMERS_CUSTOM              0
#define MEMCPY(dst,src,len)             memcpy(dst,src,len)
#define SMEMCPY(dst,src,len)            memcpy(dst,src,len)
#define MEMMOVE(dst,src,len)            memmove(dst,src,len)

/*
   ------------------------------------
   ----------- Core locking -----------
   ------------------------------------
*/
#define LWIP_MPU_COMPATIBLE             0
#define LWIP_TCPIP_CORE_LOCKING         0 // 1
#define LWIP_TCPIP_CORE_LOCKING_INPUT   0
#define SYS_LIGHTWEIGHT_PROT            1
#define LWIP_ASSERT_CORE_LOCKED()
#define LWIP_MARK_TCPIP_THREAD()

/*
   ------------------------------------
   ---------- Memory options ----------
   ------------------------------------
*/
#define MEMP_MEM_INIT                   0
#define LWIP_ALLOW_MEM_FREE_FROM_OTHER_CONTEXT 0

/*
   ------------------------------------------------
   ---------- Internal Memory Pool Sizes ----------
   ------------------------------------------------
*/
#define MEMP_NUM_ALTCP_PCB              MEMP_NUM_TCP_PCB
#define MEMP_NUM_FRAG_PBUF              0 // 15
#define MEMP_NUM_IGMP_GROUP             5
#define MEMP_NUM_NETBUF                 0 // 2
#define MEMP_NUM_NETCONN                0 // 4
#define MEMP_NUM_SELECT_CB              4
#define MEMP_NUM_TCPIP_MSG_API          4 // 8
#define MEMP_NUM_TCPIP_MSG_INPKT        4 // 8
#define MEMP_NUM_NETDB                  1
#define MEMP_NUM_LOCALHOSTLIST          0 // 1
#define MEMP_NUM_API_MSG                MEMP_NUM_TCPIP_MSG_API
#define MEMP_NUM_DNS_API_MSG            MEMP_NUM_TCPIP_MSG_API
#define MEMP_NUM_SOCKET_SETGETSOCKOPT_DATA MEMP_NUM_TCPIP_MSG_API
#define MEMP_NUM_NETIFAPI_MSG           MEMP_NUM_TCPIP_MSG_API

/*
   ---------------------------------
   ---------- ARP options ----------
   ---------------------------------
*/
#define LWIP_ARP                        1
#define ARP_TABLE_SIZE                  10
#define ARP_MAXAGE                      300
#define ETHARP_SUPPORT_VLAN             0
#define LWIP_ETHERNET                   LWIP_ARP
#define ETH_PAD_SIZE                    0
#define ETHARP_SUPPORT_STATIC_ENTRIES   0
#define ETHARP_TABLE_MATCH_NETIF        !LWIP_SINGLE_NETIF

/*
   --------------------------------
   ---------- IP options ----------
   --------------------------------
*/
#define LWIP_IPV4                       1
#define IP_FORWARD                      LWIP_FEATURES
#define IP_OPTIONS_ALLOWED              1
#define IP_REASS_MAXAGE                 15
#define IP_DEFAULT_TTL                  255
#define IP_SOF_BROADCAST                0
#define IP_SOF_BROADCAST_RECV           0
#define IP_FORWARD_ALLOW_TX_ON_RX_NETIF 0

/*
   ----------------------------------
   ---------- ICMP options ----------
   ----------------------------------
*/
#define LWIP_ICMP                       1
#define ICMP_TTL                        IP_DEFAULT_TTL
#define LWIP_BROADCAST_PING             0
#define LWIP_MULTICAST_PING             0

/*
   ---------------------------------
   ---------- RAW options ----------
   ---------------------------------
*/
#define RAW_TTL                         IP_DEFAULT_TTL

/*
   ----------------------------------
   ---------- DHCP options ----------
   ----------------------------------
*/
#define LWIP_DHCP                       1 // 0
#define DHCP_DOES_ARP_CHECK             0 // (LWIP_DHCP && LWIP_ARP)
#define LWIP_DHCP_BOOTP_FILE            0
#define LWIP_DHCP_GET_NTP_SRV           1 // 0
#define LWIP_DHCP_MAX_NTP_SERVERS       1
#define LWIP_DHCP_MAX_DNS_SERVERS       DNS_MAX_SERVERS

/*
   ------------------------------------
   ---------- AUTOIP options ----------
   ------------------------------------
*/
#define LWIP_AUTOIP                     LWIP_FEATURES // 0
#define LWIP_DHCP_AUTOIP_COOP           LWIP_FEATURES // 0
#define LWIP_DHCP_AUTOIP_COOP_TRIES     9

/*
   ----------------------------------
   ----- SNMP MIB2 support      -----
   ----------------------------------
*/
#define LWIP_MIB2_CALLBACKS             0

/*
   ----------------------------------
   -------- Multicast options -------
   ----------------------------------
*/
#define LWIP_MULTICAST_TX_OPTIONS       ((LWIP_IGMP || LWIP_IPV6_MLD) && (LWIP_UDP || LWIP_RAW))

/*
   ----------------------------------
   ---------- IGMP options ----------
   ----------------------------------
*/
#define LWIP_IGMP                       1

/*
   ----------------------------------
   ---------- DNS options -----------
   ----------------------------------
*/
#define LWIP_DNS                        1 // 0
#define DNS_TABLE_SIZE                  4
#define DNS_MAX_NAME_LENGTH             128 // 256
#define DNS_MAX_SERVERS                 2
#define DNS_MAX_RETRIES                 4
#define DNS_DOES_NAME_CHECK             0 // 1
#define LWIP_DNS_SECURE                 0 // (LWIP_DNS_SECURE_RAND_XID | LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING | LWIP_DNS_SECURE_RAND_SRC_PORT)
#define LWIP_DNS_SECURE_RAND_XID                1
#define LWIP_DNS_SECURE_NO_MULTIPLE_OUTSTANDING 2
#define LWIP_DNS_SECURE_RAND_SRC_PORT           4
#define DNS_LOCAL_HOSTLIST              0
#define DNS_LOCAL_HOSTLIST_IS_DYNAMIC   0
#define LWIP_DNS_SUPPORT_MDNS_QUERIES   1 // 0

/*
   ---------------------------------
   ---------- UDP options ----------
   ---------------------------------
*/
#define LWIP_UDP                        1
#define UDP_TTL                         IP_DEFAULT_TTL
#define LWIP_NETBUF_RECVINFO            0

/*
   ---------------------------------
   ---------- TCP options ----------
   ---------------------------------
*/
#define LWIP_TCP                        1
#define TCP_TTL                         IP_DEFAULT_TTL
#define TCP_MAXRTX                      12
#define TCP_SYNMAXRTX                   12
#define LWIP_TCP_MAX_SACK_NUM           2 // 4
#define TCP_CALCULATE_EFF_SEND_MSS      1
#define TCP_OOSEQ_MAX_BYTES             TCP_MSS // 0
#define TCP_OOSEQ_BYTES_LIMIT(pcb)      TCP_OOSEQ_MAX_BYTES
#define TCP_OOSEQ_MAX_PBUFS             1 // 0
#define TCP_OOSEQ_PBUFS_LIMIT(pcb)      TCP_OOSEQ_MAX_PBUFS
#define TCP_LISTEN_BACKLOG              LWIP_FEATURES // 0
#define TCP_DEFAULT_LISTEN_BACKLOG      0xff
#define LWIP_TCP_TIMESTAMPS             0

#if !defined(LWIP_EVENT_API) && !defined(LWIP_CALLBACK_API) || defined __DOXYGEN__
#define LWIP_EVENT_API                  0
#define LWIP_CALLBACK_API               1
#else
#ifndef LWIP_EVENT_API
#define LWIP_EVENT_API                  0
#endif
#ifndef LWIP_CALLBACK_API
#define LWIP_CALLBACK_API               0
#endif
#endif

#define LWIP_TCP_PCB_NUM_EXT_ARGS       0
#define LWIP_ALTCP                      0
#define LWIP_ALTCP_TLS                  0

/*
   ----------------------------------
   ---------- Pbuf options ----------
   ----------------------------------
*/
#if !defined PBUF_LINK_HLEN || defined __DOXYGEN__
#if defined LWIP_HOOK_VLAN_SET && !defined __DOXYGEN__
#define PBUF_LINK_HLEN                  (18 + ETH_PAD_SIZE)
#else /* LWIP_HOOK_VLAN_SET */
#define PBUF_LINK_HLEN                  (14 + ETH_PAD_SIZE)
#endif /* LWIP_HOOK_VLAN_SET */
#endif

#define PBUF_LINK_ENCAPSULATION_HLEN    36 // required for esp8266 (36 is EP_OFFSET from original esp implementation)
#define LWIP_PBUF_REF_T                 u8_t
#define LWIP_PBUF_CUSTOM_DATA

/*
   ------------------------------------------------
   ---------- Network Interfaces options ----------
   ------------------------------------------------
*/
#define LWIP_SINGLE_NETIF               0 // AP, STA, spi ethernet...
#define LWIP_NETIF_HOSTNAME             1 // 0
#define LWIP_NETIF_API                  0
#define LWIP_NETIF_STATUS_CALLBACK      1 // 0
#define LWIP_NETIF_EXT_STATUS_CALLBACK  0
#define LWIP_NETIF_LINK_CALLBACK        0
#define LWIP_NETIF_REMOVE_CALLBACK      0
#define LWIP_NETIF_HWADDRHINT           0

/*
   ------------------------------------
   ---------- LOOPIF options ----------
   ------------------------------------
*/
#define LWIP_HAVE_LOOPIF                (LWIP_NETIF_LOOPBACK && !LWIP_SINGLE_NETIF)
#define LWIP_LOOPIF_MULTICAST           0
#define LWIP_NETIF_LOOPBACK             0
#define LWIP_LOOPBACK_MAX_PBUFS         0
#define LWIP_NETIF_LOOPBACK_MULTITHREADING    (!NO_SYS)

/*
   ------------------------------------
   ---------- Thread options ----------
   ------------------------------------
*/
#define TCPIP_THREAD_NAME               "tcpip_thread"
#define TCPIP_THREAD_STACKSIZE          0
#define TCPIP_THREAD_PRIO               1
#define TCPIP_MBOX_SIZE                 0
#define LWIP_TCPIP_THREAD_ALIVE()
#define SLIPIF_THREAD_NAME              "slipif_loop"
#define SLIPIF_THREAD_STACKSIZE         0
#define SLIPIF_THREAD_PRIO              1
#define DEFAULT_THREAD_NAME             "lwIP"
#define DEFAULT_THREAD_STACKSIZE        0
#define DEFAULT_THREAD_PRIO             1
#define DEFAULT_RAW_RECVMBOX_SIZE       0
#define DEFAULT_UDP_RECVMBOX_SIZE       0
#define DEFAULT_TCP_RECVMBOX_SIZE       0
#define DEFAULT_ACCEPTMBOX_SIZE         0

/*
   ----------------------------------------------
   ---------- Sequential layer options ----------
   ----------------------------------------------
*/
#define LWIP_NETCONN                    0 // 1
#define LWIP_TCPIP_TIMEOUT              0
#define LWIP_NETCONN_SEM_PER_THREAD     0
#define LWIP_NETCONN_FULLDUPLEX         0

/*
   ------------------------------------
   ---------- Socket options ----------
   ------------------------------------
*/
#define LWIP_SOCKET                     0 // 1
#define LWIP_COMPAT_SOCKETS             1
#define LWIP_POSIX_SOCKETS_IO_NAMES     1
#define LWIP_SOCKET_OFFSET              0
#define LWIP_TCP_KEEPALIVE              1
#define LWIP_SO_SNDTIMEO                0
#define LWIP_SO_RCVTIMEO                0
#define LWIP_SO_SNDRCVTIMEO_NONSTANDARD 0
#define LWIP_SO_RCVBUF                  0
#define LWIP_SO_LINGER                  0
#define RECV_BUFSIZE_DEFAULT            INT_MAX
#define LWIP_TCP_CLOSE_TIMEOUT_MS_DEFAULT 10000
#define SO_REUSE                        1 // 0
#define SO_REUSE_RXTOALL                0
#define LWIP_FIONREAD_LINUXMODE         0
#define LWIP_SOCKET_SELECT              1
#define LWIP_SOCKET_POLL                1

/*
   ---------------------------------------
   ---------- IPv6 options ---------------
   ---------------------------------------
*/
#define IPV6_REASS_MAXAGE               60
#define LWIP_IPV6_SCOPES                (LWIP_IPV6 && !LWIP_SINGLE_NETIF)
#define LWIP_IPV6_SCOPES_DEBUG          0
#define LWIP_IPV6_NUM_ADDRESSES         4 // 3
#define LWIP_IPV6_FORWARD               0
#define LWIP_IPV6_FRAG                  0 // 1
#define LWIP_IPV6_REASS                 0 // LWIP_IPV6
#define LWIP_IPV6_SEND_ROUTER_SOLICIT   LWIP_IPV6
#define LWIP_IPV6_AUTOCONFIG            LWIP_IPV6
#define LWIP_IPV6_ADDRESS_LIFETIMES     LWIP_IPV6_AUTOCONFIG
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   1
#define LWIP_ICMP6                      LWIP_IPV6
#define LWIP_ICMP6_DATASIZE             0
#define LWIP_ICMP6_HL                   255
#define LWIP_IPV6_MLD                   LWIP_IPV6
#define MEMP_NUM_MLD6_GROUP             4
#define LWIP_ND6_QUEUEING               0 // LWIP_IPV6
#define MEMP_NUM_ND6_QUEUE              20
#define LWIP_ND6_NUM_NEIGHBORS          4 // 10
#define LWIP_ND6_NUM_DESTINATIONS       5 // 10
#define LWIP_ND6_NUM_PREFIXES           5
#define LWIP_ND6_NUM_ROUTERS            2 // 3
#define LWIP_ND6_MAX_MULTICAST_SOLICIT  3
#define LWIP_ND6_MAX_UNICAST_SOLICIT    3
#define LWIP_ND6_MAX_ANYCAST_DELAY_TIME 1000
#define LWIP_ND6_MAX_NEIGHBOR_ADVERTISEMENT  3
#define LWIP_ND6_REACHABLE_TIME         30000
#define LWIP_ND6_RETRANS_TIMER          1000
#define LWIP_ND6_DELAY_FIRST_PROBE_TIME 5000
#define LWIP_ND6_ALLOW_RA_UPDATES       1
#define LWIP_ND6_TCP_REACHABILITY_HINTS 1
#define LWIP_ND6_RDNSS_MAX_DNS_SERVERS  0
#define LWIP_IPV6_DHCP6                 1 // 0
#define LWIP_IPV6_DHCP6_STATEFUL        0
#define LWIP_IPV6_DHCP6_STATELESS       LWIP_IPV6_DHCP6
#define LWIP_DHCP6_GET_NTP_SRV          1
#define LWIP_DHCP6_MAX_NTP_SERVERS      1
#define LWIP_DHCP6_MAX_DNS_SERVERS      DNS_MAX_SERVERS

/*
   ---------------------------------------
   ---------- Hook options ---------------
   ---------------------------------------
*/

/*
   --------------------------------------------------
   ---------- Performance tracking options ----------
   --------------------------------------------------
*/
#define LWIP_PERF                       0

/*
   --------------------------------------------------
   ------------- End of original lwipopts -----------
   --------------------------------------------------
*/

#include "lwip/debug.h"
#include "arch/cc.h"
#include "lwip-git-hash.h"
#include <sys/time.h> // settimeofday() + struct timeval

#ifdef __cplusplus
extern "C" {
#endif

#define TCP_RANDOM_PORT 1

/*
   --------------------------------------------------
   ------------------ SNTP options ------------------
   --------------------------------------------------
*/

#define SNTP_SERVER_DNS 1                   // enable SNTP support DNS names through sntp_setservername / sntp_getservername
#define SNTP_SET_SYSTEM_TIME_US(t,us)	do { struct timeval tv = { t, us }; settimeofday(&tv, (struct timezone*)0xFeedC0de); } while (0)
#define SNTP_SUPPRESS_DELAY_CHECK 1
#define SNTP_UPDATE_DELAY_DEFAULT 3600000   // update delay defined by a default weak function
#define SNTP_UPDATE_DELAY sntp_update_delay_MS_rfc_not_less_than_15000()
uint32_t SNTP_UPDATE_DELAY;
#define SNTP_MAX_SERVERS                3
#define SNTP_STARTUP_DELAY 1                // enable startup delay
#define SNTP_STARTUP_DELAY_FUNC_DEFAULT 0   // to 0 by default via a default weak function
#define SNTP_STARTUP_DELAY_FUNC sntp_startup_delay_MS_rfc_not_less_than_60000()
uint32_t SNTP_STARTUP_DELAY_FUNC;

/*
   --------------------------------------------------
   ------------------- LOCAL FIXES ------------------
   --------------------------------------------------
*/

// allow to handle special packets (user redefinable)
struct pbuf;
struct netif;
#ifndef LWIP_ERR_T
#error LWIP_ERR_T definition should come from lwip1.4 from espressif
#endif
//#define LWIP_ERR_T s8
LWIP_ERR_T lwip_unhandled_packet (struct pbuf* pbuf, struct netif* netif);

// called when STA OR AP is set up or down
void netif_status_changed (struct netif*);

//----------------- Alloc functions ----------------
#define mem_clib_free(p)      vPortFree(p, NULL, -1)
#define mem_clib_malloc(s)   pvPortMalloc(s, NULL, -1)
#define mem_clib_calloc(n,s) pvPortZalloc(n*s, NULL, -1)

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MYLWIPOPTS_H */
