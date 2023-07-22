#include "main.h"
#include "..\library\delay.h"
void uart_mode0_write (unsigned char b)
{
	SBUF=b;
	while (TI==0);
	TI=0;
	
	P3_2=0;
	P3_2=1;
}
void main()
{		
	unsigned char i;
	SM0=SM1=0;
	while(1)
		{		for(i=0;i<3;i++)
			{
			uart_mode0_write(0x55);
			delay_ms(500);
			uart_mode0_write(0xAA);
			delay_ms(500);
			}
	}
}