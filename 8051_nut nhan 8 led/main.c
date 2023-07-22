#include "main.h"
#include "..\library\delay.h"
#define led P2
sbit on= P1^0;
sbit off= P1^1;

unsigned char  delay1svaquetphim(){
	unsigned char i;
	for (i=0;i<100;i++){
					delay_ms(10);
				if (off==0)
			{
				led=0;
				return 1;
			}
			}
			return 0;
		}
void main()
{
	led=0;
while(1){
	if(on==0)
	{
		while(1)
		{
				led=~led;
			if(delay1svaquetphim())
			{
					break;
 			}
		}
	}
				}
}
