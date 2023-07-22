#include "main.h"

void main()
{	
	T2CON=0x08;
	T2MOD=0x00;
	
	RCAP2H=0X3C;
	RCAP2L=0XB0;
	
	P2=0x00;

	ET2=1; // CHO PHEP NGAT TIMER2
	EA=1;		//CHO PHEP NGAT TOAN CUC
	while(1)
	{

	}
}
void timer2_overflow(void) interrupt 5
{
	if (EXF2)
	{	
		TR2=1;
		EXF2=0;
	}
	else 
	{	
		TR2=0;
		P2++;
		TF2=0;
	}
}