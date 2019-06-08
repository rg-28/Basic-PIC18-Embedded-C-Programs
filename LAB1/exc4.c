#include<p18cxxx.h>	//Include the required library for the microcontroller.
void main(void)
{
	unsigned int a=0,b=0xAA;	//Initialise one variable for loop and other for O/P.
	TRISB=0;		//Set PORTB as O/P port.
	PORTB=b;		//Initially send 0xAA to PORTB.
	
	for(a=0;a<20000;a++)	//Initialise a for loop to repeat the O/P 20,000 times.
	{
		PORTB=~b;		//Complement the value at PORTB.
		b=PORTB;		//Save the complemented value at PORTB in variable b.
	}
}