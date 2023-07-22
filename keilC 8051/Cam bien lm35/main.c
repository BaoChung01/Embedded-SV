#include "main.h"
#include "..\library\delay.h"
#include "..\library\ADC0804.h"
void main()
{	unsigned char adc_value,t;
	
	while(1)
	{
			adc_value=ADC0804_Read();
			t=adc_value*1.961f+0.5;
			delay_ms(500);
	}
}