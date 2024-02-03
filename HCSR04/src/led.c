/*
* Filename: LED.c
* Content: handle LED behavior source code
*/
#include "led.h"

// Function to turn on the LED
void LED_GPIO_INIT(void) {
    GPIO_InitTypeDef gpioInit;

    // Enable the clock for GPIOC
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Configure GPIO pin for the LED
    gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInit.GPIO_Pin = LED_1_GPIO_PIN | LED_2_GPIO_PIN;
    gpioInit.GPIO_Speed = GPIO_Speed_50MHz;

    // Initialize GPIOC with the specified configuration
    GPIO_Init(GPIOC, &gpioInit);
	
	GPIO_SetBits(GPIOC, LED_1_GPIO_PIN | LED_2_GPIO_PIN );
	
}

// Toggle the LED_1
void LED_PC13_TOGGLE(void){
    GPIO_WriteBit(GPIOC, LED_1_GPIO_PIN, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOC, LED_1_GPIO_PIN)));
}

// Toggle the LED_2
void LED_2_TOGGLE(void){
    GPIO_WriteBit(GPIOC, LED_2_GPIO_PIN, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOC, LED_2_GPIO_PIN)));
}
