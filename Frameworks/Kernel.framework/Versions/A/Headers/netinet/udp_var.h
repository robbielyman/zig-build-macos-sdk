/*
 * Copyright (c) 2008-2024 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1982, 1986, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)udp_var.h	8.1 (Berkeley) 6/10/93
 */

#ifndef _NETINET_UDP_VAR_H_
#define _NETINET_UDP_VAR_H_

#include <sys/appleapiopts.h>
#include <sys/sysctl.h>
#include <netinet/ip_var.h>
#include <netinet/udp.h>

/*
 * UDP kernel structures and variables.
 */
struct  udpiphdr {
	struct  ipovly ui_i;            /* overlaid ip structure */
	struct  udphdr ui_u;            /* udp header */
};
#define ui_x1           ui_i.ih_x1
#define ui_pr           ui_i.ih_pr
#define ui_len          ui_i.ih_len
#define ui_src          ui_i.ih_src
#define ui_dst          ui_i.ih_dst
#define ui_sport        ui_u.uh_sport
#define ui_dport        ui_u.uh_dport
#define ui_ulen         ui_u.uh_ulen
#define ui_sum          ui_u.uh_sum
#define ui_next         ui_i.ih_next
#define ui_prev         ui_i.ih_prev

struct  udpstat {
	/* input statistics: */
	u_int32_t udps_ipackets;        /* total input packets */
	u_int32_t udps_hdrops;          /* packet shorter than header */
	u_int32_t udps_badsum;          /* checksum error */
	u_int32_t udps_badlen;          /* data length larger than packet */
	u_int32_t udps_noport;          /* no socket on port */
	u_int32_t udps_noportbcast;     /* of above, arrived as broadcast */
	u_int32_t udps_fullsock;        /* not delivered, input socket full */
	u_int32_t udpps_pcbcachemiss;   /* input packets missing pcb cache */
	u_int32_t udpps_pcbhashmiss;    /* input packets not for hashed pcb */
	/* output statistics: */
	u_int32_t udps_opackets;        /* total output packets */
	u_int32_t udps_fastout;         /* output packets on fast path */
	u_int32_t udps_nosum;           /* no checksum */
	u_int32_t udps_noportmcast;     /* of no socket on port, multicast */
	u_int32_t udps_filtermcast;     /* blocked by multicast filter */
	/* checksum statistics: */
	u_int32_t udps_rcv_swcsum;        /* udp swcksum (inbound), packets */
	u_int32_t udps_rcv_swcsum_bytes;  /* udp swcksum (inbound), bytes */
	u_int32_t udps_rcv6_swcsum;       /* udp6 swcksum (inbound), packets */
	u_int32_t udps_rcv6_swcsum_bytes; /* udp6 swcksum (inbound), bytes */
	u_int32_t udps_snd_swcsum;        /* udp swcksum (outbound), packets */
	u_int32_t udps_snd_swcsum_bytes;  /* udp swcksum (outbound), bytes */
	u_int32_t udps_snd6_swcsum;       /* udp6 swcksum (outbound), packets */
	u_int32_t udps_snd6_swcsum_bytes; /* udp6 swcksum (outbound), bytes */
};

/*
 * Names for UDP sysctl objects
 */
#define UDPCTL_CHECKSUM         1       /* checksum UDP packets */
#define UDPCTL_STATS            2       /* statistics (read-only) */
#define UDPCTL_MAXDGRAM         3       /* max datagram size */
#define UDPCTL_RECVSPACE        4       /* default receive buffer space */
#define UDPCTL_PCBLIST          5       /* list of PCBs for UDP sockets */
#define UDPCTL_MAXID            6

#endif /* _NETINET_UDP_VAR_H_ */
