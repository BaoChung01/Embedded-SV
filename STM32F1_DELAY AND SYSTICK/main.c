#include "stm32f10x.h"                  // Device header
int signal =0;
void systick_init(void);
void DelayMillis(void);
void DelayMs(unsigned long t);

int main(void)
{	
	systick_init();
	RCC->APB2ENR |= (1<<2);		// Enable PORT A
	RCC->APB2ENR |= (1<<4);		// Enable PORT C
	GPIOA->CRL &= ~(0xF);				// reset the port A pin 0
	GPIOA->CRL  |=  2<<2;			//SET PORT A PIN 0 AS IN INPUT PUSH PULL
	
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
		DelayMs(1000);
		GPIOC->ODR &=~ (1<<13);
		DelayMs(1000);
		}
		else
		{
		GPIOC->ODR |= 1<<13;
		GPIOA->ODR &= ~(1<<12);
		}
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
void systick_init(void)
{
	SysTick->CTRL = 0;
	SysTick->LOAD= 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
}
void DelayMillis(void)
{
	SysTick->LOAD = 72000 -1;
	SysTick->VAL = 0;
	while(!(SysTick->CTRL & (1<<16)));
}
void DelayMs(unsigned long t)
{
	for(;t>0;t--)
	{
		DelayMillis();
	}
}


	
