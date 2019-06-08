#include<p18cxxx.h>		//Include the library for the required microcontroller.
void Delay0(unsigned char);		//Initialise the Delay function
#define mybit0 PORTAbits.RA0		//Define a variable name
#define mybit1 PORTBbits.RB0
#define SW PORTEbits.RE2
unsigned int c=1, d=0, e=0;
void main(void)
{

	ADCON1=0x06;		//Sets RA0-RA5 & RE0-RE2 as Digital mode.
	TRISAbits.TRISA0=0;	//Sets RA0 as O/P pin
	TRISBbits.TRISB0=0;	//Sets RB0 as O/P pin
	TRISEbits.TRISE2=1;	//Sets RE2 as I/P pin
	mybit0=0;		//Initially set both the LEDs at OFF.
	mybit1=0;
	while(1)
{
	if(SW==1)		//Check the condition of the Switch
		c=+1;
	d=c%2;
	if(d==0)	//If the switch is pressed even number of times.
	{
		for(e=0;e<3;e++)	
		{
			mybit1=1;	//Set the LED HIGH.
			Delay0(0);	//Delay of 500ms
			mybit1=0;	//Set the LED as LOW.
			Delay0(0);	//Delay of 500ms
		}
		Delay0(1);		//Delay of 1000ms.
	}
	else	//If the switch is pressed odd number of times.
	{
		for(e=0;e<3;e++)
		{
			mybit0=1;	//Set the LED HIGH.
			Delay0(1);	//Delay of 1000ms
			mybit0=0;	//Set the LED as LOW.
			Delay0(1);	//Delay of 1000ms
		}
		Delay0(0);		//Delay of 500ms.
	}
}
}

void Delay0(unsigned char c)	//Delay function
{
	T0CON=0x06;		//Timer0, 16-bit mode with prescaler 1:128
	if(c==0)		//For delay of 500ms
	{
		TMR0H=0xB3;
		TMR0L=0x00;
	}
	else			//For delay of 1000ms
	{
		TMR0H=0x60;
		TMR0L=0x00;
	}
	T0CONbits.TMR0ON=1;		//Set T0 ON.
	while(INTCONbits.TMR0IF==0);	//Check the overflow flag
	T0CONbits.TMR0ON=0;		//Stop T0
	INTCONbits.TMR0IF=0;	//Clear the overflow flag
}