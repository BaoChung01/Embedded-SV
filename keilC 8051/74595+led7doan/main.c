#include "main.h"
#include "..\library\delay.h"
#include "..\library\74595.h"
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void main(){
	unsigned char i;
	unsigned char buffer[2];
while(1){
				for(i=0;i<=99;i++)
					{		
						buffer[0]=code7seg[i/10];
						buffer[1]=code7seg[i%10];
							IE74595_OUT(buffer,2);
							delay_ms(300);
					}
				}
}