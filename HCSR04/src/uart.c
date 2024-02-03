/*
* Filename: uart.c
* Content: handle send data using uart 
*/
#include "uart.h"

/* Initialize UART3 for communication*/ 
int UART3_Init(void) {
    USART_InitTypeDef uart_config;

    // Enable clock for UART3 peripheral
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

    // Configure UART3
    uart_config.USART_BaudRate = BAUDRATE_9600;
    uart_config.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart_config.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    uart_config.USART_Parity = USART_Parity_No;
    uart_config.USART_StopBits = USART_StopBits_1;
    uart_config.USART_WordLength = USART_WordLength_8b;

    USART_Init(USART3, &uart_config);

    // Enable UART3
    USART_Cmd(USART3, ENABLE);
	
	return SUCCESS;
}

/*Initialize UART pin*/
int UART_PIN_Init(void) {
    GPIO_InitTypeDef gpio_init;

    // Enable clock for GPIOB peripheral
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // Configure PB10 (TX pin) as alternate function push-pull
    gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio_init.GPIO_Pin = GPIO_Pin_10;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpio_init);

    // Configure PB11 (RX pin) as input floating
    gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    gpio_init.GPIO_Pin = GPIO_Pin_11;
    gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpio_init);
	
	return SUCCESS;
}

/*Initialize UART for communication*/
void Init_UART_3(void){
    UART3_Init();
    UART_PIN_Init();
}

/*Send sensor data*/
void send_data(int32_t data){
	if((USART3->SR & (USART_FLAG_FE | USART_FLAG_PE | USART_FLAG_ORE)) == OK) {
		while (!(USART_GetFlagStatus(USART3, USART_FLAG_TXE)));
			USART_SendData(USART3,(uint16_t)data);
    }
}
