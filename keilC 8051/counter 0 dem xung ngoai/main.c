#include "main.h"
#include "..\library\delay.h"
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void display(unsigned int n)
{
	unsigned char chuc_ngan,ngan,tram,chuc,dvi;
	chuc_ngan=n/10000;
	n%=10000;
	ngan=n/1000;
	n%=1000;
	tram=n/100;
	n%=100;
	chuc=n/10;
	dvi=n%10;
	
	P0=code7seg[chuc_ngan];
	P2_4=0;
	delay_ms(1);
	P2_4=1;
	
	P0=code7seg[ngan];
	P2_3=0;
	delay_ms(1);
	P2_3=1;
	
	P0=code7seg[tram];
	P2_2=0;
	delay_ms(1);
	P2_2=1;
	
	P0=code7seg[chuc];
	P2_1=0;
	delay_ms(1);
	P2_1=1;
	
	P0=code7seg[dvi];
	P2_0=0;
	delay_ms(1);
	P2_0=1;
}
void main()
{	
	unsigned char low,high;
	unsigned int number;
	TMOD &=0xF0;
	TMOD |=0x05;
	TR0=1;
	
	while(1)
	{
		do {
		high=TH0;
		low=TL0;
		}while(high!=TH0);
		number=high;
		number<<=8;
		number |=low;
		
		display(number);
	}
}