#include <REGX52.H>
void delay_ms(unsigned int t)
{ unsigned int x,y;
	for (x=0;x<t;x++){
	for(y=0;y<123;y++);
	}
}
void main(){
	unsigned char i;
	
		while(1)
		{ 
			P0=0x03;
			for ( i=0;i<4;i++)
			{
			delay_ms(300);
		P0<<=2;
	}
}}
		
	
	
