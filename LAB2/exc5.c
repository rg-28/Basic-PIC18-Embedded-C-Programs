#include<p18cxxx.h> //Include the library for the required microcontroller.
void T0Delay(unsigned char); //Define a delay function.
#define mybit1 PORTBbits.RB0		//Define a variable name for pin RB0 of PORTB.
#define mybit2 PORTBbits.RB4		//Define a variable name for pin RB4 of PORTB.
#define SW PORTBbits.RB7			//Define a variable name for pin RB7 of PORTB.
void main(void)
{
	TRISBbits.TRISB0=0; //Set pin 7 of PORTB as O/P.
	TRISBbits.TRISB4=0;	//Set pin 4 of PORTB as O/P.
	TRISBbits.TRISB7=1;	//Set pin 7 of PORTB as I/P.
	while(1)		//Set an infine loop to repeat the square wave.
	{
		if(SW==0)	//Check the condition on Switch on pin 7 of PORTB.
		{
			mybit1^=1;	//Toggle pin RB0
			T0Delay(0);	//Call delay
		}
		else
		{
			mybit2^=1;	//Toggle pin RB4
			T0Delay(1);	//Call delay
		}
	}
}
void T0Delay(unsigned char c)		//Delay function
{
	T0CON=0x05;		//Timer1, 16-bit mode, highest prescaler
	if(c==0)	//Values for 2 kHz wave.
	{
		TMR0H=0xFB;
		TMR0L=0x1E;
	}
	else		//Values for 3 kHz wave.
	{
		TMR0H=0xFC;
		TMR0L=0xBF;
	}
	T0CONbits.TMR0ON=1;		//Turn ON T0
	while(INTCONbits.TMR0IF==0);		//Wait for TF0 to roll-over.
	T0CONbits.TMR0ON=0;		//Turn OFF T0
	INTCONbits.TMR0IF=0;	//Clear TF0
}