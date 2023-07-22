#include "main.h"
#include "../library/delay.h"
#include "../library/74595.h"

void main()
{ unsigned char buffer[2],i;
	
		while(1)
		{		
				for(i=0;i<2;i++)
				buffer[i]=0;
				 IE74595_OUT(buffer,2);
				delay_ms(600);
			
			for(i=0;i<2;i++)
				buffer[i]=0xFF;
				 IE74595_OUT(buffer,2);
				delay_ms(600); 
		}	
}