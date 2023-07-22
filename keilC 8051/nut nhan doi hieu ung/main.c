#include "main.h"
#include "..\library\delay.h"
	sbit BTN=P1^0;
#define LED P2

bit keybreak=0;
unsigned char delayvakiemtranut()
	{
		unsigned char i;
		for(i=0;i<50;i++)
		{
			delay_ms(10);
			if(BTN==0)
			{ if(keybreak==0)
				{
					
					keybreak=1;
					return 1;
			}
			else { 
			keybreak=0; 
			}
		}
	}
		return 0;
}
	void main(){
		unsigned char i;
		
while(1){
		LED=0X00;
	for (i=0;i<20;i++){
			if(delayvakiemtranut())
			break;
		LED = ~ LED;
	}
	for(i=0;i<20;i++)
	{
			LED=0x55;
	if(delayvakiemtranut())
			break;
		LED = ~ LED;
	}
	LED=0x0F;
	for (i=0;i<20;i++){
if(delayvakiemtranut())
			break;
		LED = ~LED;
	}
}
}