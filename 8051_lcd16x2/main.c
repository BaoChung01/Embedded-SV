#include "main.h"
#include "..\library\delay.h"
// khai bao ket noi lcd
sbit LCD_RS=P2^0;
sbit LCD_EN=P2^1;

#define LCD_DATA P3

void Lcd_cmd(unsigned char cmd)
{
		 LCD_RS=0;
			LCD_DATA=cmd;
			LCD_EN=0;
			LCD_EN=1;
			if(cmd<0x02)
			{
				delay_ms(2);
			}
			else 
			{
				delay_ms(1);
			}
}
void Lcd_chr_cp(char c)
{
		 LCD_RS=1;
			LCD_DATA=c;
			LCD_EN=0;
			LCD_EN=1;
			delay_ms(1);
}
void Lcd_chr(unsigned char row, unsigned char col, char c)
{
		// di chuyen con tro den vi tri can thiet
		unsigned char cmd;
	cmd = (row==1?0x80:0xC0)+col -1;
	Lcd_cmd(cmd);
	// xuat ki tu
	Lcd_chr_cp(c);
}
void Lcd_out_cp(char *str)
{
		unsigned char i=0;
		while (str[i]!=0)
		{
			Lcd_chr_cp(str[i]);
			i++;
		}
}
void Lcd_Init()
{
		Lcd_cmd(0x30);
		delay_ms(5);
		Lcd_cmd(0x30);
		delay_ms(1);
		Lcd_cmd(0x30);
	
		Lcd_cmd(0x38);  // so dong hien thi la 2 f
		
		Lcd_cmd(0x01);// xoa man hinh
	
		Lcd_cmd(0x0C);//bat hien thi tat con tro
}
void Lcd_out(unsigned char row, unsigned char col, char *str)
{
	// di chuyen con tro den vi tri can thiet
		unsigned char cmd;
	cmd = (row==1?0x80:0xC0)+col -1;
	Lcd_cmd(cmd);
	
	Lcd_out_cp(str);
}
void main()
{
	delay_ms(100);
	Lcd_Init();
	Lcd_out(1,1,"hello i love you forevel");
	delay_ms(3000);
	Lcd_cmd(0x1C);// dich phai
	delay_ms(3000);
	Lcd_cmd(0x1C);// dich phai
	delay_ms(3000);
	Lcd_cmd(0x02);// tra lai vi tri ban dau	
	while(1)
	{
			
	}
}