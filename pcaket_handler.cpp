#include "packet_handler.h"
#include "pcap.h"
#include "libnet-headers.h"
#include "hexaView.h"

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *data)
{
	ETH_HDR *EH = (ETH_HDR *)data;
	IP4_HDR *IH = (IP4_HDR *)(data + sizeof(ETH_HDR));
	TCP_HDR *TH = (TCP_HDR *)(data + sizeof(ETH_HDR) + sizeof(IP4_HDR));
	short int type = ntohs(EH->ether_type);
	int protocol = IH->ip_p;
	int dataByte=0;

	const unsigned char *pkt_data = data + sizeof(ETH_HDR) + (IH->ip_hl * 4) + (TH->data_offset * 4);

	dataByte = (header->len - sizeof(ETH_HDR) - (IH->ip_hl * 4) - (TH->data_offset * 4));

	if ((protocol == TCPHEADER) && ((ntohs(TH->th_sport) == 80) || (ntohs(TH->th_sport) == 443) || (ntohs(TH->th_dport) == 80) || (ntohs(TH->th_dport) == 443)))
	{
		// source, destination mac address 轎溘
		printf("\nぬ韃 紫雜!\n");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛 Total   : %4dByte   弛\n", header->len);
		printf("弛 ETH_HDR : %4dByte   弛\n", sizeof(ETH_HDR));
		printf("弛 IP4_HDR : %4dByte   弛\n", (IH->ip_hl)*4);
		printf("弛 TCP_HDR : %4dByte   弛\n", TH->data_offset * 4);
		printf("弛 Payload : %4dByte   弛\n", dataByte);
		printf("戌成成成成成成成成成成成成成成成成成成成成成成戎\n");
		printf("忙扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛扛式式式式式式式式忖\n");
		printf("弛 Src MAC  : %02x-%02x-%02x-%02x-%02x-%02x 弛\n", EH->ether_shost[0], EH->ether_shost[1], EH->ether_shost[2], EH->ether_shost[3], EH->ether_shost[4], EH->ether_shost[5]);
		printf("弛 Dst MAC  : %02x-%02x-%02x-%02x-%02x-%02x 弛\n", EH->ether_dhost[0], EH->ether_dhost[1], EH->ether_dhost[2], EH->ether_dhost[3], EH->ether_dhost[4], EH->ether_dhost[5]);

		if (type == IPHEADER)
		{
			printf("弛			       弛\n");
			printf("弛 Src IP   : %3d.%3d.%3d.%3d   弛\n", IH->ip_src.S_un.S_un_b.s_b1, IH->ip_src.S_un.S_un_b.s_b2, IH->ip_src.S_un.S_un_b.s_b3, IH->ip_src.S_un.S_un_b.s_b4);
			printf("弛 Dst IP   : %3d.%3d.%3d.%3d   弛\n", IH->ip_dst.S_un.S_un_b.s_b1, IH->ip_dst.S_un.S_un_b.s_b2, IH->ip_dst.S_un.S_un_b.s_b3, IH->ip_dst.S_un.S_un_b.s_b4);
		}

		if (protocol == TCPHEADER)
		{
			printf("弛			       弛\n");
			printf("弛 Src PORT : %-4d	       弛\n", ntohs(TH->th_sport));
			printf("弛 Dst PORT : %-4d	       弛\n", ntohs(TH->th_dport));
		}

		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

		if (dataByte != 0)
		{
			if((dataByte / 16) == 0)
				hexaView(pkt_data, 1);
			else
				hexaView(pkt_data, dataByte/16);
		}
			
	}
}