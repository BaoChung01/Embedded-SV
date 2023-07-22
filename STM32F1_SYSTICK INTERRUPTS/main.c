#include "stm32f10x.h"                  // Device header

void SysTick_Handler(void);
int main(void)
{	
	RCC->APB2ENR |= (1<<2);		// Enable PORT A
	RCC->APB2ENR |= (1<<4);		// Enable PORT C
	GPIOA->CRL &= ~(0xF);				// reset the port A pin 0
	GPIOA->CRL  |=  2<<2;			//SET PORT A PIN 0 AS IN INPUT PUSH PULL
	
	GPIOA->CRH &=~(0xF<<16);
	GPIOA->CRH |=3<<16;
	
	GPIOC->CRH &= ~(0xF<<20);
	GPIOC->CRH |=  3<<20;
	
	__disable_irq();
	SysTick->CTRL  = 0;
	SysTick->LOAD = 72000000-1;
	SysTick->VAL = 0;
	SysTick->CTRL = 7;
	__enable_irq();
	
	while(1)
	{
	  if (GPIOA->IDR &= 1)
	  {
		GPIOA->ODR |= 1<<12;
	  }
	  else
	  {
		GPIOA->ODR &= ~(1<<12);
	  }
	}
}
void SysTick_Handler(void)
{
		GPIOC->ODR ^=1<<13;
}


	
