#include "stm32f10x.h"                  // Device header

void delay(int rep);

int main(void)
{
	RCC->APB2ENR |= (1<<2);		// Enable PORT A
	RCC->APB2ENR |= (1<<4);		// Enable PORT C
	GPIOA->CRL &= 0;					// reset the port A pin 0
	GPIOA->CRL  |=  1<<3;			//SET PORT A PIN 0 AS IN INPUT PUSH PULL
	
	GPIOC->CRH &= 0000<<19;
	GPIOC->CRH |=  11<<19;
	while(1)
	{
		if (GPIOA->IDR & 0x00000001)
		{
			for (int i=0;i<5;i++)
			{
		GPIOC->ODR |= 1<<13;
		delay(5);
		GPIOC->ODR &=~ (1<<13);
		delay(5);
			}
		}
		else
		{
		GPIOC->ODR |= 1<<13;
		}
	}
}

void delay(int rep)
{
	for(;rep>0;rep--)
	{
	int i;
	for (i=0; i<1000000;i++)
	{}
	}
}

	
