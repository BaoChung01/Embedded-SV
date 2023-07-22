//#define AC0804_DATA P2
//sbit ADC0804_CS=P3^0;
//sbit ADC0804_RD=P3^1;
//sbit ADC0804_WR=P3^2;
//sbit ADC0804_INTR=P3^3;

#include "main.h"
#include  "ADC0804.h"
#include "PORT.h"
unsigned char ADC0804_Read()
{	
	unsigned char kq;
		ADC0804_CS=0;

	ADC0804_WR=0;
	ADC0804_WR=1;
	
	while(ADC0804_INTR)
	ADC0804_RD=0;
	kq=ADC0804_DATA;
	ADC0804_RD=1;
	return kq;
	
}