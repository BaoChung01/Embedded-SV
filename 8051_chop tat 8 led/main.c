
#include "..\library\delay.h"
#include "main.h"
#define led_port P2
void main (){
	led_port = 0x55;
	while (1){
		led_port = ~led_port;
		delay_ms(500);
	}}