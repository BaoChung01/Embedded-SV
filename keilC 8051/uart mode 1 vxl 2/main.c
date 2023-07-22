#include "main.h"
#include "..\library\uartmode1.h"
void main()
{	
	P1_0=0;
	uart_init();
	while(1)
	{
		if(uart_data_ready())
		{
				if(uart_read()==0x01)
				{
						P1_0=1;
				}
				else 
				{
						P1_0=0;
				}
		}
	}
}