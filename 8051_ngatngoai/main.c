#include "main.h"
#include "port.h"
#include "..\library\delay.h"
void main()
{	IT1=1;
	EX1=1;	
	EA=1;
	
	led0=led1=led2=led3=0;
	while(1)
	{
			PCON |=0x01;
	}
}
void EX1_ISR(void) interrupt 2
{
		delay_ms(20);
	if(!BTN0)
	{
		led0=!led0;
		while(!BTN0);
	}
	if(!BTN1)
	{
		led1=!led1;
		while(!BTN1);
	}
	if(!BTN2)
	{
		led2=!led2;
		while(!BTN2);
	}
	if(!BTN3)
	{
		led3=!led3;
		while(!BTN3);
	}
}