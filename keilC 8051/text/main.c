#include <REGX52.H>
#include "..\library\delay.h"
sbit led= P0^0; // dat ten cho chan p0^0 la led

	
void main ()
{
	while (1)
	{
		led=!led; /// dao trang thai led
		delay_ms(500); /// là delay do
	}
}
		