#include "main.h"

void main()
{	T2CON=0X00;
	T2MOD=0X02;
	
	RCAP2H=0XFF;
	RCAP2L=0XB1;
	TH2=0XFF;
	TL2=0XB1;
	
	TR2=1;
	while(1)
	{

	}
}