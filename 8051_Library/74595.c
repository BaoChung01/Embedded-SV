// mo rong ngo ra dung ic 74hc595
// yeu cau phai tao file port.h chua cac ket noi phan cung nhu sau
//sbit IE74595_SHCP=P2^0;
//sbit IE74595_DS=P2^1;
//sbit IE74595_STCP=P2^2;
#include "main.h"
#include "74595.h"
#include "port.h"

void  IE74595_OUT (unsigned char *p,unsigned char n)
{
	unsigned char i,b,j;
	for (j=0;j<n;j++)
	{			b=*(p+n-j-1);
		for(i=0;i<8;i++)
		{
			IE74595_DS= b & (0X80>>i);//lay tung bit cua byte b gui ra DS, lay bit MSB truoc
			//tao xung du lieu
			IE74595_SHCP=0;
			IE74595_SHCP=1;
	}
}
					IE74595_STCP=0;
					IE74595_STCP=1;
}