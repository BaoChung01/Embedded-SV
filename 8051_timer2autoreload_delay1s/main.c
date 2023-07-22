#include "main.h"
void delaytimer2_1s()
{
	unsigned char i;
	TR2=1;
	for(i=0;i<20;i++)
	{	
		while (!TF2);
		TF2=0;
	}
	TR2=0;
}
void main()
{	// dat timer2 tu dong nap lai mode 16 bit
	T2CON=0x00;
	T2MOD=0x00;
	
	RCAP2H=0x3C;
	RCAP2L=0XB0;
	
	TH2=0X3C;
	TL2=0xB0;
	while(1)
	{
		P2=~P2;
		delaytimer2_1s();
	}
}