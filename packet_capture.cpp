#include <stdio.h>
#include "pcap.h"
#include "libnet-headers.h"
#include "packet_handler.h"

int main()
{
	pcap_if_t *allDevice;
	pcap_if_t *viewDevice;
	pcap_t *selectDevice;
	char errbuf[PCAP_ERRBUF_SIZE];
	int i=0;
	int select;

	// 1. device �˻�
	if ((pcap_findalldevs(&allDevice, errbuf)) == -1)
	{
		printf("��ġ�� �˻��ϴµ� ������ �߻��߽��ϴ�\n");
		printf("������ �������� ������� �ּ���.\n");
		return 0;
	}

	// 2. �˻��� device ��� ���&����
	printf("------------------------------------------------------------------\n");
	for (viewDevice = allDevice; viewDevice != NULL; viewDevice = viewDevice->next)
	{
		printf("[ %d ]�� device \n", i++);
		printf("device ���� : %s\n", viewDevice->name);
		printf("device ���� : %s\n\n", viewDevice->description);
	}
	printf("------------------------------------------------------------------\n");
	printf("Dvice�� ������ �ּ��� : ");
	scanf("%d", &select);

	viewDevice = allDevice;

	for (i = 0; i < select; i++)
		viewDevice = viewDevice->next;


	// 3. device ����
	selectDevice = pcap_open_live(viewDevice->name, 65536, 0, 1000, errbuf);
	pcap_freealldevs(allDevice);

	// 4. ���� ���

	pcap_loop(selectDevice, 0, packet_handler, NULL);

	pcap_close(selectDevice);

	return 0;
}
