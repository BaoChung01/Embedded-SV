#include "systick_time.h"
#include "lcd_1602_drive.h"

/*
I2C2
PB10 -> SCL
PB11 -> SDA

I2C1
PB6 -> SCL
PB7 -> SDA
*/

// update init for 4 bit data transfer 

int main(void)
{
		systick_init();// initialize the delay function (Must initialize)
		lcd_i2c_init(2);
		lcd_i2c_msg(2,1, 1,"Welcome to the");
		lcd_i2c_msg(2,2, 2,"Embedded  SV");
	while(1) 
	{


	}
	
}

