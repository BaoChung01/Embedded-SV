#include "main.h"

void main()
{	
	T2CON=0x00;
	T2MOD=0x02;
	
	RCAP2H=0xF4;
	RCAP2L=0X48;
	
	TR2=1;
	while(1)
	{

	}
}