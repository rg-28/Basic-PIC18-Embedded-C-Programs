#include<p18cxxx.h> //Include the library for the required microcontroller.
void T0Delay(unsigned char); //Define a delay function.
#define mybit1 PORTBbits.RB0		//Define a variable name for pin RC7 of PORTC.
#define mybit2 PORTBbits.RB4
#define SW PORTBbits.RB7
void main(void)
{
	TRISBbits.TRISB0=0; //Set pin 7 of PORTC as O/P.
	TRISBbits.TRISB4=0;
	TRISBbits.TRISB7=1;
	while(1)		//Set an infine loop to repeat the square wave.
	{
		if(SW==0)
		{
			mybit1^=1;
			T0Delay(0);
		}
		else
		{
			mybit2^=1;
			T0Delay(1);
		}
	}
}
void T1Delay(unsigned char c)		//Delay function
{
	T0CON=0x05;		//Timer1, 16-bit mode, highest prescaler
	if(c==0)
	{
		TMR0H=0xFB;
		TMR0L=0x1E;
	}
	if(c==1)
	{
		TMR0H=0xFC;
		TMR0L=0xBF;
	}
	T0CONbits.TMR0ON=1;		//Turn ON T1
	while(INTCONbits.TMR0IF==0);		//Wait for TF1 to roll-over.
	T0CONbits.TMR0ON=0;		//Turn OFF T1
	INTCONbits.TMR0IF=0;	//Clear TF1
}