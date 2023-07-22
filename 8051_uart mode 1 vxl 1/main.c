#include "main.h"
#include "..\library\uartmode1.h"
#include "..\library\delay.h"
void main()
{	
	uart_init();
	
	while(1)
	{
			if (P1_0==0)
			{
				delay_ms(20);
				uart_write(0x01);
				while(P1_0==0);
			}
			
			if (P1_1==0)
			{
				delay_ms(20);
				uart_write(0x00);
				while(P1_1==0);
			}
	}
}