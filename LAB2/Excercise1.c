#include<p18cxxx.h> //Include the library for the required microcontroller.
void T0Delay(void); //Define a delay function.
#define mybit PORTBbits.RB0		//Define a variable name for pin RB0 of PORTB.
void main(void)
{
	TRISBbits.TRISB0=0; //Set pin 0 of PORTB as O/P.
	while(1)		//Set an infine loop to repeat the square wave.
	{
		mybit=1;	//Send high at RB0.
		T0Delay();	//Call delay
		mybit=0;	//Send low at RB0.
		T0Delay();	//Call Delay
	}
}
void T0Delay()		//Delay function
{
	T0CON=0x08;		//Timer0, 16-bit mode, no prescaler
	TMR0H=0xFF;		//load TH0
	TMR0L=0xFC;		//load TL0
	T0CONbits.TMR0ON=1;		//Turn ON T0
	while(INTCONbits.TMR0IF==0);		//Wait for TF0 to roll-over.
	T0CONbits.TMR0ON=0;		//Turn OFF T0
	INTCONbits.TMR0IF=0;	//Clear TF0
}
