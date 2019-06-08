#include<p18cxxx.h>	//Include the required library for the microcontroller.
char list[]= {6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6};	//Store the required data in RAM.
void main(void)
{
	unsigned char a=0;	//Initialise a variable.
	TRISC=0;		//Set PORTC as O/P port.
	while(1)		//Set an infinte loop to repeat the O/P.
	{
		for(a=0;a<13;a++)	//Use for loop to change the value of the variable from 00H-0CH.
		{
			PORTC=list[a];	// O/P the value at PORTC.
		}
	}
}