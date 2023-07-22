#include "main.h"
#include "..\library\delay.h"
sbit SPI_SCLK =P2^0;
sbit SPI_MOSI =P2^1;
sbit SPI_MISO =P2^2;
sbit SPI_CS =P2^3;

void Soft_SPI_Init();
void Soft_SPI_Write(unsigned char b);
unsigned char Soft_SPI_Read(void);
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b);
unsigned char EEPROM_25LCxxx_Read(unsigned int add);
unsigned char EEPROM_25LCxxx_WIP();

void main()
{	
	unsigned char i;
	Soft_SPI_Init();
	for(i=0;i<100;i++)
	{
	EEPROM_25LCxxx_Write(i,i);
	}
	while(1)
	{	
		for(i=0;i<100;i++)
		{
		P1=EEPROM_25LCxxx_Read(i);
		delay_ms(500);
	  }
		}
}
// ghi 1 byte b sang EEPROM tai dia chi add
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b)
{
	SPI_CS=0;
	Soft_SPI_Write(0x06); // gui lenh wren
	SPI_CS=1;
	
	SPI_CS=0;
	Soft_SPI_Write(0x02);		// gui lenh write
	Soft_SPI_Write(add>>8); // gui 8 bit cao cua dia chi
	Soft_SPI_Write(add & 0x00FF);	//gui 8 bit thap cua dia chi
	Soft_SPI_Write(b);
	SPI_CS=1;
	while(EEPROM_25LCxxx_WIP());
}
unsigned char EEPROM_25LCxxx_Read(unsigned int add)
{
	unsigned char b;
	
	SPI_CS=0;
	Soft_SPI_Write(0x03); // gui lenh doc
	Soft_SPI_Write(add>>8); // gui 8 bit cao cua dia chi
	Soft_SPI_Write(add & 0x00FF);	//gui 8 bit thap cua dia chi
	b=Soft_SPI_Read();
	SPI_CS=1;
	
	return b;
}
unsigned char EEPROM_25LCxxx_WIP()
{
	unsigned char result;
	SPI_CS=0;
	Soft_SPI_Write(0x05); // gui lenh doc thanh ghi trang thai
	result=Soft_SPI_Read();
	SPI_CS=1;
	return result&0x01;
}
void Soft_SPI_Init()
{
	SPI_CS=1;
	SPI_SCLK=0;
	SPI_MISO=1;
}
unsigned char Soft_SPI_Read(void)
{
	unsigned char i,b;
	for(i=0;i<8;i++)
	{
		b<<=1;
		SPI_SCLK=1;
		if(SPI_MISO)
			b|=0x01;
			SPI_SCLK=0;
	
	}
	return b;
}
void Soft_SPI_Write(unsigned char b)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if((b&0x80)==0x80)
			SPI_MOSI=1;
		else
			SPI_MOSI=0;
		SPI_SCLK=1;
		b<<=1;
		SPI_SCLK=0;
	}
}