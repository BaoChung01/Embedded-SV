#include "main.h"
#include "..\library\delay.h"
#define UP  0
#define DOWN 1
sbit PWM_PIN=P2^0;

unsigned int T, Ton, Toff;
unsigned char Ton_h_reload, Ton_l_reload, Toff_h_reload, Toff_l_reload;

// ck (us)
void PWM_Init(unsigned int ck)
{
	PWM_PIN=1;
	
	TMOD&=0xF0; // xoa di cac bit chon mode cua timer0
	TMOD|=0x01;  // timer0 hoat dong o mode 1
	
	ET0=1;			/// cho phep ngat timer0
	EA=1;				// cho phep ngat toan cuc
	
	T=ck;
	Ton=T/2; 		// duty cylce 50%
	Toff=T-Ton;
	
	Ton_h_reload=(65536-Ton)>>8;
	Ton_l_reload=(65536-Ton)&0x00FF;
	
	Toff_h_reload=(65536-Toff)>>8;
	Toff_l_reload=(65536-Ton)&0x00FF;
	
	TH0=Ton_h_reload;
	TL0=Toff_h_reload;
	
}

void PWM_Start()
{
	TR0=1;		//timer 0 bat dau dem
	
}
void PWM_Stop()
{
		TR0=0;		// timer 0 ngung dem
}
void PWM_Set_Duty(unsigned char duty)
{	
	if(duty==0)
	{
				PWM_PIN=0;
				ET0=0;
	}
	else if(duty==100)
	{
			PWM_PIN=1;
				ET0=0;
	}

	else
	{
	Ton=((unsigned long)T)*duty/100;
	Toff=T-Ton;
	
	Ton_h_reload=(65536-Ton)>>8;
	Ton_l_reload=(65536-Ton)&0x00FF;
	
	Toff_h_reload=(65536-Toff)>>8;
	Toff_l_reload=(65536-Ton)&0x00FF;
	
	ET0=1;
	}
}
void main()
{	
	unsigned char dir=UP, duty=UP;
	PWM_Init(1000); // chu ki T=1000us=1ms
	PWM_Set_Duty(0);
	
	PWM_Start();
	while(1)
	{		
		delay_ms(100);
			if (dir==UP)
			{
				duty=duty+2;
				if(duty==100)
				{
					dir=DOWN;
				}
			}
		else
		{
			duty-=2;
			if(duty==0)
			{
				dir=UP;
			}
		}
		PWM_Set_Duty(duty);
	}	
}

void Timer0_Overflow() interrupt 1
{
	PWM_PIN=!PWM_PIN;
	if (PWM_PIN==0)
	{
		TH0=Toff_h_reload;
		TL0=Toff_l_reload;
	}
	else 
	{
		TH0=Ton_h_reload;
		TL0=Ton_l_reload;
	}
}