#include "main.h"
#include "..\library\delay.h"
void main()
{	
	P2=0;
	while(1)
	{
		do{
			P2++;
			delay_ms(8);
		}
		while
	(P2!=255);
		
		do{
			P2--;
			delay_ms(8);
		}while (P2!=0);
		
		
	}
}