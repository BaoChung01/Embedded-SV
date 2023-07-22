#include "stm32f10x.h"    

void DelayMillis(void);
void DelayMs(unsigned long t);
char chat = 'C';
int main(void)
{
// Delays function
	SysTick->CTRL = 0;
	SysTick->LOAD= 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	//-----------Init UART ------------///
	// Enable the Alternate Function for PINs
		RCC->APB2ENR |= 1;
	// Enable UART2
		RCC->APB1ENR |=(1<<17);
	// Enable the related PINs
	RCC->APB2ENR |= (1<<2);	
	
	GPIOA->CRL &= ~((0xF)<<8); /// pin 2 output pushpull
	GPIOA->CRL  |=  3<<8;
	GPIOA->CRL  |=  2<<10;
	
	GPIOA->CRL &= ~((0xF)<<12);// pin 3 input pushpull
	GPIOA->CRL  |=  2<<14;
	
	// Setup the baude rate for 9600 bps
	USART2->BRR = 0xEA6; 
	// Enable Uart Transmit
	USART2->CR1 |= 1<<3;
	// Enable Uart Recive
	USART2->CR1 |= 1<<2;
	// Enable Uart
	USART2->CR1 |= 1<<13;

while(1)
	{
		// Recieve Char
		while(!(USART2->SR & (1<<5)));
		chat = USART2->DR;
		// Transmit Char
		//DelayMs(100);
		while(!(USART2->SR & (1<<6)));
		USART2->DR = chat;
	}
	
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
