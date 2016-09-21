#pragma once
#include <stdio.h>
void hexaView(const unsigned char *buffer, int size)
{
	int loop_temp = 0;
	int counter = 0;

	int line = size / 16;
	int reminder = size % 16;

	printf("=======================================================================\n");
	printf("Address 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D");
	printf(" 0E 0F 123456789ABCDEF\n");
	printf("=======================================================================\n");

	counter = 0;

	while (counter < line)
	{
		printf("0x%04X	", counter);
		loop_temp = 0;

		if (counter != line - 1)
		{
			while (loop_temp < 16)
			{
				printf("%02X ", *buffer);
				++buffer;
				++loop_temp;
			}
		}
		else
		{
			while (loop_temp < reminder)
			{
				printf("%02X ", *buffer);
				++buffer;
				++loop_temp;
			}
			for (loop_temp = 0; loop_temp < 16 - reminder; loop_temp++)
				printf("   ");
		}
		

		buffer = buffer - 16;
		loop_temp = 0;

		if (counter != line - 1)
		{
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
		}
		else
		{
			while (loop_temp < reminder)
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
		}
						
		counter = counter++;
		putchar('\n');
	}

	return;
}
