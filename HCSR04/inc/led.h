/*
* Filename: LED.h
* Content: library handle the LED
*/
#ifndef _LED_H_
#define _LED_H_

#include "common.h"

// Initialize the GPIO for LED
void LED_GPIO_INIT(void);

// turn on the LED
void LED_TURN_ON(void);

// turn off the LED
void LED_TURN_OFF(void);

// toggle the LED
void LED_PC13_TOGGLE(void);
void LED_2_TOGGLE(void);

#endif /*_LED_H_*/
