#include "main.h"
#include "../library/delay.h"
sbit IE74595_SHCP=P2^0;
sbit IE74595_DS=P2^1;
sbit IE74595_STCP=P2^2;
void  IE74595_OUT_BYTE (unsigned char b)
{
	unsigned char i;
	for (i=0;i<8;i++)
	{
			IE74595_DS= b & (0X80>>i);//lay tung bit cua byte b gui ra DS, lay bit MSB truoc
			//tao xung du lieu
			IE74595_SHCP=0;
			IE74595_SHCP=1;
	}
					IE74595_STCP=0;
					IE74595_STCP=1;
}

void main()
{ unsigned char b,i;
		while(1)
		{		
				b=0;
				IE74595_OUT_BYTE(b);
				delay_ms(300);
				for(i=0;i<8;i++)
			{
					b=(b<<1)|0x01;
				IE74595_OUT_BYTE(b);
					delay_ms(300);
			}
		}	
}