#include "main.h"
#include <stdio.h>
void main()
{	
	unsigned char c,i;
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
	TI=1;
	i=255;
	do {
		i++;
		putchar(i);}
	while(i!=255);
	
	
	while(1)
		{
		c=_getkey();
		switch(c)
		{
			case '0':
			P2_0=!P2_0;
			break;
			case '1':
			P2_1=!P2_1;
			break;
		}
		}
}