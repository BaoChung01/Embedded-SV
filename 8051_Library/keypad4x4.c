#include "keypad4x4.h"
#include "main.h"
#include "port.h"
unsigned char keypress()
{ 
	unsigned char key=0;
	COL1=0;
	if(ROW1==0)key=1;
	if(ROW2==0)key=2;
	if(ROW3==0)key=3;
	if(ROW4==0)key=4;
	COL1=1;
	
	COL2=0;
	if(ROW1==0)key=5;
	if(ROW2==0)key=6;
	if(ROW3==0)key=7;
	if(ROW4==0)key=8;
	COL2=1;
	
	
	COL3=0;
	if(ROW1==0)key=9;
	if(ROW2==0)key=10;
	if(ROW3==0)key=11;
	if(ROW4==0)key=12;
	COL3=1;
	
	COL4=0;
	if(ROW1==0)key=13;
	if(ROW2==0)key=14;
	if(ROW3==0)key=15;
	if(ROW4==0)key=16;
	COL4=1;
	
	return key;
	
	
}