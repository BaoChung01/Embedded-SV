/*
* Filename: stm32f10x-HC-SR04.h
* Content: library handle the sensor HC-SR04
*/

#ifndef STM32F10X_HC_SR04_H_
#define STM32F10X_HC_SR04_H_

/*include library stm32f103c8t6*/
#include "stm32f10x.h"

/*define timer*/
#define US_TIMER					    TIM3

/*define port and pin for sensor*/
#define US_TRIG_PORT					GPIOB
#define US_TRIG_PIN						GPIO_Pin_0		//TIM Ch3 (trig output)

#define US_ECHO_PORT					GPIOA
#define US_ECHO_PIN						GPIO_Pin_6		//TIM Ch1 (echo input)
#define US_TIMER_TRIG_SOURCE		    TIM_TS_TI1FP1

/*
*   Initialization timer 
*/
static void initMeasureTimer(void);

/*
*   Initialization pin HCSR04
*/
static void initPins(void);

/**
 * Initialization of HCSR04's peripherals
 */
void InitHCSR04(void);

/**
 * Initialization clock HCSR04
 */
void EnableHCSR04PeriphClock(void);

/**
 * Measure distance and get value in mm. Lower than 0 means no echo signal: distance more than ~3m.
 */
int32_t HCSR04GetDistance(void);


#endif /* STM32F10X_HC_SR04_H_ */
