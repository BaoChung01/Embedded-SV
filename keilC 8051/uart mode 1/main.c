#include "main.h"
#include "..\library\delay.h"
#include "..\library\uartmode1.h"
void uart_init()
{
	SM0=0;
	SM1=1;// uart mode 1
	TMOD=0x20;	///0010 xxxx timer 1 hoat dong o che do 8 bit tu dong lap lai
	TH1=0xFD;// toc do baud 9600
	TR1=1; //timer 1 bat dau chay;
	TI=1;		// san sang gui du lieu
	REN=1;	// cho phep nhan du lieu
}
void uart_write(char c)
{
		while(TI==0);
			TI=0;
			SBUF=c;
}
char uart_data_ready()
{
	return RI;
}
char uart_read()
{
	RI=0;
	return SBUF;
}
void uart_write_text(char *str)
{	
	unsigned char i=0;
	while(str[i]!=0)
	{
		uart_write(str[i]);
		i++;
	}
}
void main()
{
	char i;
	uart_init();
	// khoi tao uart o mode 1
	while(1)
	{
		uart_write_text("nhap vao ki tu in thuong :");
		while(uart_data_ready()==0);
		i=uart_read();
		i=i-32;
		uart_write_text("-->");
		uart_write(i);
		uart_write_text("\r\n");
		
	}
}