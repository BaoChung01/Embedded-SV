#include "main.h"
#include"..\library\delay.h"
sbit BTN=P1^0;
sbit RL=P2^0;
void main(){
	RL=1;
while(1){
if(BTN==0){
		delay_ms(20);
	if(BTN==0)
	{	
		RL=!RL;
		while (BTN==0);
	}
}
}
}