#ifndef UARTMODE1_H_
#define UARTMODE1_H_

void uart_init(); // khoi tao uart mode 1
void uart_write(char c);// gui 1 ki tu ra uart
char uart_data_ready();
//kiem tra xem co nhan dc byte du lieu chua
// tra ve 1 da nhan duoc va nguoc lai
char uart_read();// doc byte nhan duoc tu uart
void uart_write_text(char *str);// gui 1 chuoi ra uart;

#endif