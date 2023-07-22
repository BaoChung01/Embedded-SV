#include "main.h"
#include "..\library\delay.h"
void main()
{
	while(1)
	{		unsigned char i,b;
			while (P3_2);
			b=0;
			for(i=0;i<8;i++)
		{
			b<<=1;
			delay_ms(2);
			if(P3_2)
			{
				b|=0x01;
			}
			else 
			{
				while(P3_2==0);
			}
			if(i!=7) while(P3_2);
		}
		P2=b;
	}
}