#include "stm32f10x.h"                  // Device header
int signal =1;
void delay(int rep);

int main(void)
{
	RCC->APB2ENR |= (1<<2);		// Enable PORT A
	RCC->APB2ENR |= (1<<4);		// Enable PORT C
	GPIOA->CRL &= ~(1<<3);					// reset the port A pin 0
	GPIOA->CRL  |=  1<<3;			//SET PORT A PIN 0 AS IN INPUT PUSH PULL
	
	GPIOA->CRH &=~(0xF<<16);
	GPIOA->CRH |=3<<16;
	
	GPIOC->CRH &= ~(0xF<<20);
	GPIOC->CRH |=  3<<20;
	
	__disable_irq();
	AFIO->EXTICR[0] = 0x00;
	EXTI->IMR |=1;
	EXTI->RTSR |= 1;
	NVIC_EnableIRQ(EXTI0_IRQn);
	__enable_irq();
	
	while(1)
	{
		if (signal)
		{
		GPIOA->ODR |= 1<<12;
		GPIOC->ODR |= 1<<13;
		delay(5);
		GPIOC->ODR &=~ (1<<13);
		delay(5);
		}
		else
		{
		GPIOC->ODR |= 1<<13;
		GPIOA->ODR &= ~(1<<12);
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

void EXTI0_IRQHandler()
{
	EXTI->PR |= 1;
	if (signal)
	{
		signal = 0;
	}
	else
	{
	signal = 1;
	}
}

	
