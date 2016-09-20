#pragma once
#include "pcap.h"

#define IPHEADER 0x0800
#define TCPHEADER 0x06

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *data);