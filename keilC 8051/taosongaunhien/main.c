#include <REGX52.H>
#define led P0
sbit BTN=P1^0;
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void main(){
	unsigned char dem=0;
	
while(1){
		while(BTN ==0)
		{dem++;}
		led=code7seg[dem%6+1];//dem%5 tao so ngau nhien tu 0-5 +1 thanh 1-6
}
}