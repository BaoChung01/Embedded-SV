#include "main.h"
#include "../library/delay.h"
#include "../library/keypad4x4.h"
#include "port.h"
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

	void main()
{		unsigned char key,tmp;
		while(1)
		{
				key=keypress();
			if(key!=0)
			{
						tmp=key;
			}
			
			LED=code7seg[tmp/10];
			led1=0;
			delay_ms(1);
			led1=1;
			
			LED=code7seg[tmp%10];
			led2=0;
			delay_ms(1);
			led2=1;
		}
}