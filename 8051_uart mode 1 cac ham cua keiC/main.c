#include "main.h"
#include <stdio.h>
#include "..\library\uartmode1.h"
void main()
{	
	char c;
	uart_init();
	
	printf("pi=%.2f\r\n", 3.14f);
	while(1)
	{		
		uart_write_text ("nhap vao 1 ki tu: ");
			c=_getkey();
		putchar(c-32);
		putchar('\r');
		putchar('\n');
	}
}