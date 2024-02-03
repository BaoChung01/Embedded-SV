/*
* Filename: common.h
* Content: library common the program
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#include "stm32f10x.h" 
#include <stdint.h>

#define RET_SUCCESS 0
#define RET_FAILED 1

#define LED_1_GPIO_PIN        GPIO_Pin_13
#define LED_2_GPIO_PIN        GPIO_Pin_14
#define UART_GPIO_PIN_TX    GPIO_Pin_10
#define UART_GPIO_PIN_RX    GPIO_Pin_11
#endif /* _COMMON_H_ */
