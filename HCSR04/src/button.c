/*
* Filename: button.c
* Content: handle button behavior 
*/
#include "button.h"

/* handle interrupt PB12 */
void EXTI15_10_IRQHandler(void)
{
	// Checks whether the interrupt is from EXTI12 or not
	if (EXTI_GetITStatus(EXTI_Line12))
	{
		BUTTON = !(BUTTON);
		// Clear pending bit
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

/*Initalization interrupt PB12*/
void EXTI15_10_Init(void)
{
	// Initalization struct
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	// Initialize PB12 as input with pull-up resistor
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	// Initialize PB12 to EXTI
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12);
	
	// Initialize EXTI line 12 for PB12
	EXTI_InitStruct.EXTI_Line = EXTI_Line12;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	// Initialize NVIC for EXTI15_10 IRQ channel
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

/*Initalization button*/
void Init_button(void){
    EXTI15_10_Init();
}

/* handle button */
void handle_button(void){
    EXTI15_10_IRQHandler();
}

