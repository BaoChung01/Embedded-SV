#include "main.h"
#include "..\library\delay.h"
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
#define led P2
sbit led1=P3^0;
sbit led2=P3^1; 

void main(){
	unsigned char dem;
	unsigned char chuc,dvi;
	unsigned int i;
while(1){
		for (dem=0;dem<100;dem++)
	{
			chuc=dem/10;
			dvi=dem%10;
		
		for (i=0;i<500;i++){
		led=code7seg[chuc];
		led1=0;
		delay_ms(1);
		led1=1;
		
		led=code7seg[dvi];
		led2=0;
		delay_ms(1);
		led2=1;}
	}
}
}