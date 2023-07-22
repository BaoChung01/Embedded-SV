#include <REGX52.H>
void delay_ms (unsigned int t)
{
	unsigned int x,y;
	for (x=0;x<t;x++)
	{
		for(y=0;y<123;y++);
	}
}
	void main(){
		unsigned char i;
		while(1){
			for (i=1;i<5;i++){
				P0=0x00;
				delay_ms(500);
				P0=0xFF;
				delay_ms(500);}
			for (i=1;i<5;i++){
				P0=0x0F;
				delay_ms(500);
				P0=0xF0;
				delay_ms(500);}
			for (i=1;i<5;i++){
				P0=0x55;
				delay_ms(500);
				P0=0xAA;
				delay_ms(500);}
	}
}		