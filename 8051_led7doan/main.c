#include "main.h"
#include "..\library\delay.h"
sbit dendo=P0^0;
sbit denvang=P0^1;
sbit denxanh=P0^2;
#define ledchuc P2
#define leddonvi P3
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void main(){
signed char i;
while(1){
	dendo=0;
	denxanh=1;
	denvang=1;
  for(i=20;i>=0;i--)
	{
			ledchuc=code7seg[i/10];
			leddonvi=code7seg[i%10];
		delay_ms(1000);
	}
	dendo=1;
	denxanh=0;
	denvang=1;
  for(i=15;i>=0;i--)
	{
			ledchuc=code7seg[i/10];
			leddonvi=code7seg[i%10];
		delay_ms(1000);
	}
		dendo=1;
	denxanh=1;
	denvang=0;
  for(i=5;i>=0;i--)
	{
			ledchuc=code7seg[i/10];
			leddonvi=code7seg[i%10];
		delay_ms(1000);
	}
}
}