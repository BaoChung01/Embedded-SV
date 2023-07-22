// mo rong ngo ra dung ic 74hc595
// yeu cau phai tao file port.h chua cac ket noi phan cung nhu sau
//sbit IE74595_SHCP=P2^0;
//sbit IE74595_DS=P2^1;
//sbit IE74595_STCP=P2^2;
#ifndef _74595_H_
#define _74595_H_

void  IE74595_OUT (unsigned char *p,unsigned char n);

#endif