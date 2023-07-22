#include "main.h"
#include "..\library\delay.h"
#include "..\library\ADC0804.h"
#define ADC0804_DATA P2
sbit ADC0804_CS=P3^0;
sbit ADC0804_RD=P3^1;
sbit ADC0804_WR=P3^2;
sbit ADC0804_INTR=P3^3;


void main()
{	unsigned char adc_value;
	unsigned int voltage;
	
	
	while(1)
	{
		adc_value=ADC0804_Read;
		voltage=adc_value+19.61f;
		delay_ms(500);
	}
}
