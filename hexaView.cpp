#pragma once
#include <stdio.h>
//////////////////////////////////////////////////////////////////////////
// Product Date : 2009/09/18                                            //
// Author : (Last) Lee                                                  //
//          (First) Hyunbin                                             //
// comment : This function is printed hexa and ascii code               //
//           입력되는 버퍼의 내용을 hexa(16진수)와                      //
//           아스키 코드(ascii code)로 출력 시키는 함수                 //
// 인지값 - INPUT : 포인터의 방향을 표시, 즉 입력이란 의미              //
//		    const : 입력된 버퍼의 값은 함수 실행 도중에 변경되지 않음   //
//          u_char *buffer : unsigned char pointer 형 변수 buffer       //
// 반환값 - void                                                        //
//////////////////////////////////////////////////////////////////////////
void hexaView( const unsigned char *buffer, int size)
{
	int loop_temp = 0;
	int counter = 0;

	printf("=======================================================================\n");
	printf("Address 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D");
	printf(" 0E 0F 123456789ABCDEF\n");
	printf("=======================================================================\n");

	counter = 0;

	if (1200 < size)
		size = 1200;

	while (counter < size)
	{
		printf("0x%04X	", counter);
		loop_temp = 0;
		while (loop_temp < 16)
		{
			printf("%02X ", *buffer);
			++buffer;
			++loop_temp;
		}
		buffer = buffer - 16;
		loop_temp = 0;
		while (loop_temp < 16)
		{
			if (31 > *buffer || 127 <= *buffer)
			{
				putchar('.');
			}
			else
			{
				putchar(*buffer);

			}
			++buffer;
			++loop_temp;
		}
		counter = counter++;
		putchar('\n');
	}
	return;
}
