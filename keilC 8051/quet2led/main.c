#include "main.h"
#include "..\library\delay.h"
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
#define led P3
sbit led1=P2^0;
sbit led2=P2^1;
void main(){
while(1){
		led=code7seg[1];
	led1=0;
	delay_ms(1);
	led1=1;
	
	led=code7seg[2];
	led2=0;
	delay_ms(1);
	led2=1;
}
}