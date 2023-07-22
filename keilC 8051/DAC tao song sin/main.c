#include "main.h"
#include "..\library\delay.h"
unsigned char code DACValue[]={127, 166, 202, 230, 248, 254, 248, 230, 202, 166, 127, 88, 52, 24, 6, 0 , 6, 24, 52, 88};
void main()
{	
	unsigned char i;
	while(1)
	{
		for (i=0;i<20;i++)
		{
			P2=DACValue[i];
			delay_ms(1);
		}
			
	}
}