#include "main.h"
#include "..\library\delay.h"
#include "..\library\ADC0804.h"
#include <stdio.h>
void main()
{	
	unsigned char adc_value;
	unsigned int t;
	char buff[16];
	while(1)
	{
			adc_value=ADC0804_Read();
			t=adc_value*100.0f/255 +0.5f;
			sprintf(buff,"nhiet do: %3d",t);
			delay_ms(200);
	}
}