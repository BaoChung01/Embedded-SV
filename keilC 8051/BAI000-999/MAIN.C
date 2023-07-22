#include "main.h"
#include "..\library\delay.h"
void main(){
	unsigned int dem=0;
	unsigned char chuc,tram,dvi;
	unsigned char tam;
while(1){
dvi=dem%10;
	chuc=(dem%100)/10;
	tram=dem/100;
	
		tam=chuc<<4;
	tam |= dvi;
	P2=tam;
	P3=tram;
	
	delay_ms(10);
	dem++;
	dem%=1000;
	
}
}