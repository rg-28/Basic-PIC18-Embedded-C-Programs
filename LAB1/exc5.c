#include<p18cxxx.h>	//Include the required library for the microcontroller.
void Delay10TCYX(unsigned int);	//Initialise the Delay function.
void main(void)
{
	unsigned int a=0,b=0xAA;	//Initialise one variable for loop and other for O/P.
	TRISB=0;		//Set PORTB as O/P port.
	PORTB=b;		//Initially send 0xAA to PORTB.
	
	for(a=0;a<20000;a++)	//Initialise a for loop to repeat the O/P 20,000 times.
	{
		PORTB=~b;		//Complement the value at PORTB.
		b=PORTB;		//Save the complemented value at PORTB in variable b.
		Delay10TCYX(500);	//Calling the Delay fuction.
	}
}
void Delay10TCYX(unsigned int itime)		//Delay Subroutine of 500ms for XTAL=20Mhz.
{
	unsigned int i,j;
	for(i=0;i<=itime;i++)
		for(j=0;j<276;j++);
}