#pragma once
#include <stdio.h>
//////////////////////////////////////////////////////////////////////////
// Product Date : 2009/09/18                                            //
// Author : (Last) Lee                                                  //
//          (First) Hyunbin                                             //
// comment : This function is printed hexa and ascii code               //
//           �ԷµǴ� ������ ������ hexa(16����)��                      //
//           �ƽ�Ű �ڵ�(ascii code)�� ��� ��Ű�� �Լ�                 //
// ������ - INPUT : �������� ������ ǥ��, �� �Է��̶� �ǹ�              //
//		    const : �Էµ� ������ ���� �Լ� ���� ���߿� ������� ����   //
//          u_char *buffer : unsigned char pointer �� ���� buffer       //
// ��ȯ�� - void                                                        //
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
