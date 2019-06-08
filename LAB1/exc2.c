#include<p18cxxx.h>	//Include the required library for the microcontroller.
char list[]= "ABCDE12345";	//Store the required data in RAM.
void main(void)
{
	unsigned char a=0;	//Initialise a variable.
	TRISB=0;		//Set PORTB as O/P port.
	while(1)		//Set an infinte loop to repeat the O/P.
	{
		for(a=0;a<10;a++)	//Use for loop to change the value of the variable from 00H-09H.
		{
			PORTB=list[a];	// O/P the value at PORTB.
		}
	}
}