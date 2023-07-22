#include <REGX52.H>
void delay_ms(unsigned int t)
{
	unsigned int x,y;
	for(x=1;x<t;x++){
		for (y=1;y<123;y++);
	}
}
void main(){
	P0=0xAA;
	while(1){
		P0=~P0;
		delay_ms(500);
	}
}