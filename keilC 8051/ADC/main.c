#include "main.h"
#include "..\library\delay.h"

unsigned char ADC_Read();

void main()
{	unsigned char adc_value;
	unsigned int voltage;
	
	
	while(1)
	{
		adc_value=ADC_Read();
		voltage=adc_value*1.953125f;
		// 0.00-5.00 V
		//0-500v
	}
}
unsigned char ADC_Read()
{
		P2=255;
	while(P3_0)
	{
		P2--;
		if(P2==0) break;
	}
	return P2;
}