#include "main.h"
#include "..\library\delay.h"
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
sbit le1=P2^0;
sbit le2=P2^1;

void main()
{  unsigned char i;
		le1=le2=0;
while(1)
	{
			for(i=0;i<100;i++)
		{
			P0=code7seg[i/10];
			le1=1;
			le1=0;
			
			P0=code7seg[i%10];
			le2=1;
			le2=0;
			
			delay_ms(300);
		}
	}	
}