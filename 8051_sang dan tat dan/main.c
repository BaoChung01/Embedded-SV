
#include "main.h"
#include"..\library\delay.h"

#define led_port P2

void sangdantatdan()
{	unsigned char i;
	//sang dan
	led_port =0x00;
	for (i=0;i<8;i++){
		led_port = (led_port<<1)|0x01;
		delay_ms(200);
}// tat dan
	for (i=0;i<8;i++){
		led_port = led_port<<1;
		delay_ms(200);
	}
}
void choptatxenke(){
unsigned char i;
	for(i=0;i<10;i++){
	led_port =0x55;
		delay_ms(200);
		led_port=0xAA;
		delay_ms(200);
		
	}
}
void main(){
	
while(1){
	sangdantatdan();
	choptatxenke();

}}

