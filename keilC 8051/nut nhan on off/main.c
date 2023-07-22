#include "main.h"
#include "..\library\delay.h"
sbit BTN=P1^0;
sbit led=P2^0;

void main(){
	led=0;
while(1){
	if (BTN==0)
	{ delay_ms(20); //chong doi phim
		if (BTN==0){
		led=!led;
	while(BTN==0);}
}
}
}