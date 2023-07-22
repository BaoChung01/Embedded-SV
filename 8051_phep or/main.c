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
			P0=0x00;
			for(i=0;i<9;i++){
				delay_ms(100);
				P0=P0<<1;
				P0|=1;
			}
			P0=0x00;
			for(i=0;i<9;i++){
			delay_ms(100);
			P0>>=1;
			P0|=0x80;
			}
	}
}		