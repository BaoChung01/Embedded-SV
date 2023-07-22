#include "stm32f10x.h"    

void DelayMillis(void);
void DelayMs(unsigned long t);
void UART_SEND (unsigned short uart, char str[]);
void UART_TX(unsigned short uart,char c);
char UART_RX(unsigned short uart);
void str_empty(char str[]);
void UART_ISR(unsigned short uart,unsigned short bridge, unsigned short * signal, unsigned short * counter, char str[]);

char USART_1_msg[250];
unsigned short USART_1_cnt = 0;
unsigned short USART_1_sig = 0;
unsigned short USART_1_bdg = 0;

char USART_2_msg[250];
unsigned short USART_2_cnt = 0;
unsigned short USART_2_sig = 0;
unsigned short USART_2_bdg = 0;

char USART_3_msg[250];
unsigned short USART_3_cnt = 0;
unsigned short USART_3_sig = 0;
unsigned short USART_3_bdg = 0;


char mess[30] = "welcome to the CEMer";
int main(void)
{
// Delays function
	SysTick->CTRL = 0;
	SysTick->LOAD= 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	//-----------Init UART ------------///
	__disable_irq();
	// Enable the Alternate Function for PINs
		RCC->APB2ENR |= 1;
	// Enable UART2
		RCC->APB1ENR |=(1<<17);
	// Enable the related PINs
	RCC->APB2ENR |= (1<<2);	
	
	GPIOA->CRL &= ~((0xF)<<8); /// pin 2 output pushpull   TX
	GPIOA->CRL  |=  3<<8;
	GPIOA->CRL  |=  2<<10;
	
	GPIOA->CRL &= ~((0xF)<<12);// pin 3 input pushpull    RX
	GPIOA->CRL  |=  2<<14;
	
	// Setup the baude rate for 9600 bps
	USART2->BRR = 0xEA6; 
	// Enable Uart Transmit
	USART2->CR1 |= 1<<3;
	// Enable Uart Recive
	USART2->CR1 |= 1<<2;
	// Enable Uart
	USART2->CR1 |= 1<<13;
	// Enable Interrupt 
	USART2->CR1 |= 1<<5;
	NVIC_EnableIRQ(USART1_IRQn);
	__enable_irq();
	
	
	//-----------Init UART3 ------------///
	__disable_irq();
	// Enable UART3
		RCC->APB1ENR |=(1<<18);
	// Enable the related PINs
	RCC->APB2ENR |= (1<<3);	
	
	GPIOB->CRH &= ~((0xF)<<8); /// pin 10 output pushpull TX
	GPIOB->CRH  |=  3<<8;
	GPIOB->CRH  |=  2<<10;
					
	GPIOB->CRH &= ~((0xF)<<12);// pin 11 input pushpull  RX
	GPIOB->CRH  |=  2<<14;
	
	// Setup the baude rate for 9600 bps
	USART3->BRR = 0xEA6; 
	// Enable Uart Transmit
	USART3->CR1 |= 1<<3;
	// Enable Uart Recive
	USART3->CR1 |= 1<<2;
	// Enable Uart
	USART3->CR1 |= 1<<13;
	
	USART3->CR1 |= 1<<5;
	NVIC_EnableIRQ(USART1_IRQn);
	__enable_irq();
	
	DelayMs(100);
	
	UART_SEND(2,"UART2 here");
	UART_SEND(3,"UART3 here");
	
while(1)
	{
		if(USART_2_sig == 1)
		{
			UART_SEND(3,USART_2_msg);
			USART_2_sig = 0;
			str_empty(USART_2_msg);
		}
		if(USART_3_sig == 1)
		{
			UART_SEND(2,USART_3_msg);
			USART_3_sig = 0;
			str_empty(USART_3_msg);
		}
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
void UART_TX(unsigned short uart,char c)
{
	if(uart == 1)
		{
			while(!(USART2->SR & (1<<6)));
			USART1->DR = c;
		}
	else if(uart == 2)
		{
			while(!(USART2->SR & (1<<6)));
			USART2->DR = c;
		}
		if(uart == 3)
		{
			while(!(USART2->SR & (1<<6)));
			USART3->DR = c;
		}
}
char UART_RX(unsigned short uart)
{
	char c;
	if(uart == 1)
		{
		while(!(USART1->SR & (1<<5)))
		c = USART1->DR;
		}                                 
	else if(uart == 2)
		{
		while(!(USART2->SR & (1<<5)));
		c = USART2->DR;
		}
		if(uart == 3)
		{
		while(!(USART3->SR &(1<<5)));
		c = USART3->DR;
		}
		return c;
}
void UART_SEND (unsigned short uart, char str[])
{
	int i=0;
	while(str[i] != '\0')
	{
		UART_TX(uart,str[i]);
		i++;
	}
}
void UART_ISR(unsigned short uart,unsigned short bridge, unsigned short * signal, unsigned short * counter, char str[])
{
	if(bridge == 0)
		{
			str[*counter] = UART_RX(uart);
			if(str[*counter] == '\n')
			{
				*counter = 0;
				*signal = 1;
			}
			else
			{
				*counter = *counter +1;

			}
		}
	else
	{
		UART_TX(bridge,UART_RX(uart));
	}
}
void str_empty(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
	
}
void USART2_IRQHandler()
{
	UART_ISR(2,3,&USART_2_sig, &USART_2_cnt, USART_2_msg);
}

void USART3_IRQHandler()
{
	UART_ISR(3,2,&USART_3_sig, &USART_3_cnt, USART_3_msg);
}

