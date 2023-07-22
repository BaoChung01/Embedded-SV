#include "main.h"
#include <stdio.h>
void main()
{
	unsigned char cmd;
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
	TI=1;
	while(1)
	{
		cmd=_getkey();
		
		P2=~cmd;
	}
}