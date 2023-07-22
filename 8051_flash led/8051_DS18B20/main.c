#include <REGX52.H>

#define DS18B20_SKIP_ROM    0xCC
#define DS18B20_CONVERT_T   0x44
#define DS18B20_READ_SCRATCH_PAD 0xBE 
sbit DS18B20_PIN=P1^0;
unsigned char code code7seg[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void T0_delay_us(unsigned int t)
{
	unsigned int load_value;
	load_value=65536-t;
	TH0=load_value>>8;
	TL0=load_value&0x00FF;
	TR0=1;
	while(!TF0);
	TR0=0;
	TF0=0;
}
// return 0 ok
// return 1 not ok
void Delay_ms(unsigned int t)
{
		unsigned int x,y;
	for(x=0;x<<t;x++)
	{
		for(y=0;y<=123;y++);
	}
}
unsigned char DS18B20_Reset()
{		
	unsigned char result;
		DS18B20_PIN=0;
		T0_delay_us(480);
	
		DS18B20_PIN=1;
		T0_delay_us(70);
	
		result=DS18B20_PIN;
		T0_delay_us(6);

	
	return result;
}
void DS18B20_Write1()
{
	DS18B20_PIN=0;
	T0_delay_us(6);
	DS18B20_PIN=1;
	T0_delay_us(64);
}
void DS18B20_Write0()
{
	DS18B20_PIN=0;
	T0_delay_us(60);
	DS18B20_PIN=1;
	T0_delay_us(10);
}
void DS18B20_Write_Bit(unsigned char b)
{
		if(b==1)
		{
				 DS18B20_Write1();
		}
		else
		{
				DS18B20_Write0();
		}
}
unsigned char DS18B20_Read_Bit()
{
			unsigned char result;
			
			DS18B20_PIN=0;
			T0_delay_us(6);
	
			DS18B20_PIN=1;
			T0_delay_us(9);
	
			result=DS18B20_PIN;
			T0_delay_us(55);
			
	return result;
}
void DS18B20_Write_Byte(unsigned char b)
{
		unsigned char i=8;
		
		while(i--)
		{
			DS18B20_Write_Bit(b&0x01);
			b>>=1;
		}
}
unsigned char DS18B20_Read_Byte()
{
	unsigned char i=8,result=0;
	while(i--)
	{
				result>>=1;
				result|=DS18B20_Read_Bit()<<7;
	}
	return result;
}
void main()
{	unsigned int temp;
	unsigned char int_part,decimal_part;
	unsigned char chuc,dvi;
	TMOD|=0x01; //TIMER 0 HOAT DONG O CHE DO 1
	while(1)
	{
		while(DS18B20_Reset());
		DS18B20_Write_Byte(DS18B20_SKIP_ROM);
		DS18B20_Write_Byte(DS18B20_CONVERT_T);
		Delay_ms(750);
		while(DS18B20_Reset());
		DS18B20_Write_Byte(DS18B20_SKIP_ROM);
		DS18B20_Write_Byte(DS18B20_READ_SCRATCH_PAD);
		
		temp=DS18B20_Read_Byte();
		temp=(DS18B20_Read_Byte()<<8)|temp;
		
		int_part=temp >> 4;
		chuc=int_part/10;
		dvi=int_part%10;
		
		decimal_part=temp&0x000F;
		decimal_part=(decimal_part*10)/16;
		
		P0=code7seg[chuc];
		P2=code7seg[dvi];
		P3=code7seg[decimal_part];
		
	}
}