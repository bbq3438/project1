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

	// 1. device 검색
	if ((pcap_findalldevs(&allDevice, errbuf)) == -1)
	{
		printf("장치를 검색하는데 오류가 발생했습니다\n");
		printf("관리자 권한으로 실행시켜 주세요.\n");
		return 0;
	}

	// 2. 검색된 device 목록 출력&선택
	printf("------------------------------------------------------------------\n");
	for (viewDevice = allDevice; viewDevice != NULL; viewDevice = viewDevice->next)
	{
		printf("[ %d ]번 device \n", i++);
		printf("device 정보 : %s\n", viewDevice->name);
		printf("device 설명 : %s\n\n", viewDevice->description);
	}
	printf("------------------------------------------------------------------\n");
	printf("Dvice를 선택해 주세요 : ");
	scanf("%d", &select);

	viewDevice = allDevice;

	for (i = 0; i < select; i++)
		viewDevice = viewDevice->next;


	// 3. device 열기
	selectDevice = pcap_open_live(viewDevice->name, 65536, 0, 1000, errbuf);
	pcap_freealldevs(allDevice);

	// 4. 정보 출력

	pcap_loop(selectDevice, 0, packet_handler, NULL);

	pcap_close(selectDevice);

	return 0;
}
