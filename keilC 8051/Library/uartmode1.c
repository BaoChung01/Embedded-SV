#include "main.h"
#include "..\library\uartmode1.h"

#if(FREQ_OSC!=11059200)
		#error "thu vien uart mode 1 chi ho tro tan so hoat dong laf 11059200"
#endif
void uart_init()
{
	SM0=0;
	SM1=1;// uart mode 1
	
	TMOD&=0x0F;	///0010 xxxx timer 1 hoat dong o che do 8 bit tu dong lap lai
	TMOD|=0x20;
	
	#if(BAUD_RATE==9600)
	TH1=0xFD;// toc do baud 9600
	#elif(BAUD_RATE==2400)
	TH1=0xF4;
	#elif(BAUD_RATE==1200)
	TH1=0xE8;
	#elif(BAUD_RATE==19200)
	TH1=0xFD;
	PCON|=0x80;
	#else
		#error "toc dau baud chi co the la 1 trong 4 so sau 19200, 9600, 2400,1200"
		#endif
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