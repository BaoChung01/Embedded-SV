#include "main.h"

void main()
{	unsigned char b;
	SM0=SM1=0;
	REN=1;
	P1_0=0;
	while(1)
	{
			P3_2=0;
			P3_2=1;
		
			RI=0;
			while(RI==0);
			b=SBUF;
		
			if((b&0x02)==0)
			{
					P1_0=1;
			}			
			if((b&0x01)==0)
			{
					P1_0=0;
			}							
	}
}