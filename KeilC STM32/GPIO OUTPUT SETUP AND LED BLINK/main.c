#include "stm32f10x.h"                  // Device header

void delay(int rep);
int main(void)
{
	RCC->APB2ENR |= (1<<4);
	GPIOC->CRH &= 0000<<19;
	GPIOC->CRH |=  11<<19;
	while (1)
	{
		GPIOC->ODR |= 1<<13;
		delay(5);
		GPIOC->ODR &=~ (1<<13);
		delay(5);
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
