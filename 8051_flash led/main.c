#include <REGX52.H>

sbit led= P0^0; // dat ten cho chan p0^0 la led
void delay_ms(unsigned int t)
{
	unsigned int x,y;
	for (x=0 ;x<t;x++)
	{
		for (y=0;y<123;y++); //delay 1ms
		}
	}
void main ()
{
	while (1)
	{
		led=!led; /// dao trang thai led
		delay_ms(500); /// là delay do
	}
}
		
