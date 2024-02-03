/*
*   FIlename: UART_H
*   Content: library use the uart
*/
#ifndef _UART_H
#define _UART_H

#include <stdint.h>
#include "stm32f10x.h"

#define DELAYTIME_SENDINGDATA 0xFF
#define BAUDRATE_9600 9600

/*define status */
#define SUCCESS 1
#define FAILED   0
#define OK 	0

#define MAXIMUN_DATAFRAME 3

//Initializes UART3 for communication.
int UART3_Init(void);

// Initializes UART pin for communication
int UART_PIN_Init(void);

/*Initialize UART for communication*/
void Init_UART_3(void);

/*send sensor data*/
void send_data(int32_t data);

#endif /* _UART_H */
