#include "main.h"
#include "..\library\delay.h"
unsigned char cnt=10,i;
void main()
{	// cau hinh timer 0 hoat dong muc 1
	TMOD&=0xF0;
	TMOD|=0x01;
	
	TH0=0x3C;
	TL0=0xB0;
	
	ET0=1; // cho phep ngat timer0
	EA=1; // cho phep ngat toan cuc
	TR0=1; // chp phep timer 0 chay
	
	while(1)
	{
			P1=0x00;
		delay_ms(100);
		for(i=0;i<8;i++)
		{
			P1<<=1;
			P1|=0x01;
			delay_ms(100);
		}
	}
}

void timeroverflow(void) interrupt 1
{	
	// nap lai gia tri cho 2 thanh ghi TH0 va TL0
	TH0=0x3C;
	TL0=0xB0;
	cnt--;
	if(cnt==0)
	{
		cnt=10;
		P2=~P2;
	}
}