#include "main.h"
#include "../library/delay.h"
#define led P2
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
sbit ledg1=P3^0;
sbit ledg2=P3^1;
sbit ledp1=P3^2;
sbit ledp2=P3^3;
sbit leds1=P3^4;
sbit leds2=P3^5;
void main(){
	unsigned char gio,phut,giay;
	unsigned char chuc,dvi;
	unsigned char i;
	gio=phut=giay=0;
while(1){ 
	for (i=0;i<166;i++)
	{
	chuc=gio/10;
	dvi=gio%10;
	led=code7seg[chuc];
	ledg1=0;
	delay_ms(1);
	ledg1=1;
	
	led=code7seg[dvi];
	ledg2=0;
	delay_ms(1);
	ledg2=1;
	
	chuc=phut/10;
	dvi=phut%10;
	led=code7seg[chuc];
	ledp1=0;
	delay_ms(1);
	ledp1=1;
	
		led=code7seg[dvi];
	ledp2=0;
	delay_ms(1);
	ledp2=1;
	
	chuc=giay/10;
	dvi=giay%10;
	led=code7seg[chuc];
	leds1=0;
	delay_ms(1);
	leds1=1;
	
	led=code7seg[dvi];
	leds2=0;
	delay_ms(1);
	leds2=1;
}
	giay++;
if(giay==60)
	{
	giay=0;
	phut++;
			if(phut==60)
				{phut=0;
				gio++;
				if(gio==24)
					{		
						gio=0;
					}
		
				}				}
				
	
	
}
}