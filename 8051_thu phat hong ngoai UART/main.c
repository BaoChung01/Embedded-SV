#include "main.h"
#include <stdio.h>
void main()
{	
	// KHOI tao timer2 phat xung 38kHz
	T2CON=0x00;
	T2MOD=0x02;
	
	RCAP2H=0xFF;
	RCAP2L=0xB1;
	TH2=0xFF;
	TL2=0xB1;
	TR2=1;
	
	//khoi tao uart mode 1 1200 baud
	SCON=0x50; // uart 8 bit toc do baud dat boi timer1
	TMOD=0x20; // timer 1 mode 2
	
	TH1=0xE8; // toc do baud 1200;
	TR1=1;		// timer 1 chay
	TI=1;		//san sang gui tin hieu
	
printf("HEllo \n");
	while(1)
	{

	}
}

