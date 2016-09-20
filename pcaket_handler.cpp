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
		// source, destination mac address ���
		printf("\n��Ŷ ����!\n");
		printf("������������������������������������������������\n");
		printf("�� Total   : %4dByte   ��\n", header->len);
		printf("�� ETH_HDR : %4dByte   ��\n", sizeof(ETH_HDR));
		printf("�� IP4_HDR : %4dByte   ��\n", (IH->ip_hl)*4);
		printf("�� TCP_HDR : %4dByte   ��\n", TH->data_offset * 4);
		printf("�� Payload : %4dByte   ��\n", dataByte);
		printf("������������������������������������������������\n");
		printf("����������������������������������������������������������������\n");
		printf("�� Src MAC  : %02x-%02x-%02x-%02x-%02x-%02x ��\n", EH->ether_shost[0], EH->ether_shost[1], EH->ether_shost[2], EH->ether_shost[3], EH->ether_shost[4], EH->ether_shost[5]);
		printf("�� Dst MAC  : %02x-%02x-%02x-%02x-%02x-%02x ��\n", EH->ether_dhost[0], EH->ether_dhost[1], EH->ether_dhost[2], EH->ether_dhost[3], EH->ether_dhost[4], EH->ether_dhost[5]);

		if (type == IPHEADER)
		{
			printf("��			       ��\n");
			printf("�� Src IP   : %3d.%3d.%3d.%3d   ��\n", IH->ip_src.S_un.S_un_b.s_b1, IH->ip_src.S_un.S_un_b.s_b2, IH->ip_src.S_un.S_un_b.s_b3, IH->ip_src.S_un.S_un_b.s_b4);
			printf("�� Dst IP   : %3d.%3d.%3d.%3d   ��\n", IH->ip_dst.S_un.S_un_b.s_b1, IH->ip_dst.S_un.S_un_b.s_b2, IH->ip_dst.S_un.S_un_b.s_b3, IH->ip_dst.S_un.S_un_b.s_b4);
		}

		if (protocol == TCPHEADER)
		{
			printf("��			       ��\n");
			printf("�� Src PORT : %-4d	       ��\n", ntohs(TH->th_sport));
			printf("�� Dst PORT : %-4d	       ��\n", ntohs(TH->th_dport));
		}

		printf("����������������������������������������������������������������\n");

		if (dataByte != 0)
		{
			if((dataByte / 16) == 0)
				hexaView(pkt_data, 1);
			else
				hexaView(pkt_data, dataByte/16);
		}
			
	}
}