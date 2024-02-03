/*
*   Filename: main.h
*   Content: main soure include file
*/
#ifndef _MAIN_H_
#define _MAIN_H_

/* include the main device */
#include "stm32f10x.h"

/* include the library */
#include "common.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f10x_HC-SR04.h"
#include "button.h"
#include "uart.h"
#include "led.h"

/* define delay time */
#define ONE_SECOND  1000
#define TWO_SECONDS 2000
/* define logic loop */
#define TRUE 1
#define FALSE	0
#define EMPTY 0
/*define Priorty */
#define PRIORTY_MIN     0
#define PRIORTY_1			1
#define PRIORTY_2			2
#define PRIORTY_3			3

/* Task to Receive data sensor */
static void Receive_Data_Sensor(void *pvParameters);
/* Task to button on/off */
static void ON_OFF_SEND_RECEIVE_DATA(void *pvParameters);
/* Task to send data uart*/
static void SEND_DATA_UART(void *pvParameters);

#endif /* _MAIN_H_ */
