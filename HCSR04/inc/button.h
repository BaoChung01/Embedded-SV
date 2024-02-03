/*
*   Filename: button.h
*   Content: library handle button
*/
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "stm32f10x.h"

/*define status button */
#define ON 	    1
#define OFF 	0

/*initialize variables*/
extern int8_t BUTTON;

/* handle interrupt PB12 */
void EXTI15_10_IRQHandler(void);

/*Initalization interrupt PB12*/
void EXTI15_10_Init(void);

/* handle button */
void Init_button(void);

/*Initalization button*/
void handle_button(void);

#endif /*_BUTTON_H_*/
