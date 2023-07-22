#include "delay.h"
#include "main.h"

#if (FREQ_OSC ==12000000)
void delay_ms(unsigned int t)
		{
			unsigned int x,y;
			for (x=0 ;x<t;x++)
			{
				for (y=0;y<123;y++); //delay 1ms
				}}
#elif (FREQ_OSC ==11059200)
				void delay_ms(unsigned int t)
		{
			unsigned int x,y;
			for (x=0 ;x<t;x++)
			{
				for (y=0;y<113;y++); //delay 1ms
				}}
#elif (FREQ_OSC ==4000000)
				void delay_ms(unsigned int t)
		{
			unsigned int x,y;
			for (x=0 ;x<t;x++)
			{
				for (y=0;y<106;y++); //delay 1ms
				}}
		#else
				#error "khong co ham delay_ms nao tuong ung "
	#endif