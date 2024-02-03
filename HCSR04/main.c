/*
*   Filename: main.c
*   Content: Demo RTOS with 3 tasks
*/

#include "main.h"

/*initialize global variables*/
int32_t data_sensor = EMPTY;
int8_t BUTTON = OFF;

int main(void){
	/*Initialize GPIO for leds*/
    LED_GPIO_INIT();
    /*Initialize HCSR04*/
    InitHCSR04();
	/*Initialize button*/
	Init_button();
	/*initialize uart */
	Init_UART_3();
    /*create three tasks*/
    xTaskCreate(Receive_Data_Sensor, "Receive Data Sensor", configMINIMAL_STACK_SIZE,
				NULL, PRIORTY_2, NULL);
    xTaskCreate(ON_OFF_SEND_RECEIVE_DATA, "Button_ON_OFF", configMINIMAL_STACK_SIZE,
				NULL, PRIORTY_3, NULL);
    xTaskCreate(SEND_DATA_UART, "Send data UART", configMINIMAL_STACK_SIZE,
				NULL, PRIORTY_1, NULL);
    /*start FREERTOS scheduler*/
    vTaskStartScheduler();
}

/*Task to receive data sensor*/ 
static void Receive_Data_Sensor(void *pvParameters){
    while(TRUE) {
		if(BUTTON) {
			LED_PC13_TOGGLE();
			data_sensor  = HCSR04GetDistance();
			vTaskDelay(ONE_SECOND);	
		}
	}
}

/*Task to ON/OFF receive and send */
static void ON_OFF_SEND_RECEIVE_DATA(void *pvParameters){
    while(TRUE) {
		handle_button();
		vTaskDelay(100);		// Delay 100ms
    }
}

/*Task to send data uart*/
static void SEND_DATA_UART(void *pvParameters){
	while(TRUE){
		if (BUTTON) {
			send_data(data_sensor);
			vTaskDelay(ONE_SECOND);	
		}
	}
}

