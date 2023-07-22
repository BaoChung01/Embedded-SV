#include "main.h"

void delay_ms_timer0(unsigned int t)
{
	do {
	TL0=0x18;
	TH0=0xFC;
	TR0=1;	// timer 0 bat dau dem

	while(!TF0);
	TR0=0; // timer0 ngung dem
	TF0=0;
	t--;
}while (t!=0);
}
void main()
{
		// chon mode cho T0
	TMOD &=0xF0; // xoa cac bit dieu khien thanh ghi tmod cua t0
	TMOD |=0x01; // chon mode 1 cho timer0
	while(1)
	{
		P2_0=~P2_0;
		delay_ms_timer0(1000);
	}
}