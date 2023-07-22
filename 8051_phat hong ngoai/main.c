#include "main.h"
#include "..\library\delay.h"

void guibit(bit b)
{
	if (b)
	{
		TR2=1;
		delay_ms(1);
		TR2=0;
		P1_0=1;
		delay_ms(3);
	}
	else 
	{
		TR2=1;
		delay_ms(3);
		TR2=0;
		P1_0=1;
		delay_ms(31);
	}
}
void guibyte(unsigned char b)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		guibit(b&0x80);
		b<<=1;
	}
		
}

void main()
{	
	unsigned char cnt=0;
	T2CON=0X00;
	T2MOD=0X02;
	
	RCAP2H=0XFF;
	RCAP2L=0XB1;
	TH2=0XFF;
	TL2=0XB1;
	
	while(1)
	{
			guibyte(cnt);
		cnt++;
		delay_ms(200);
	}
}