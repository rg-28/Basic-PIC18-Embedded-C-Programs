#include<p18cxxx.h>		//Include the library of the required microcontroller.
void main(void)
{
	TRISAbits.TRISA4=1;	//Set RA4 as I/P for T0CKI.
	TRISB=0;		//Set PORTB as O/P.
	TRISD=0;		//Set PORTD as O/P.
	T0CON=0x28;		//Counter0, 16-bit mode
	TMR0H=0;		//Set higher bytes count equal to 0.
	TMR0L=0;		//Set lower bytes count equal to 0.
	CMCON=0x07;
	
	while(1)		//Set an infinite loop to run the program forever.
	{
		do			//Set a do-while loop.
		{
			T0CONbits.TMR0ON=1;		//Turn ON T0
			PORTB=TMR0L;		//Send lower bytes to PORTB
			PORTD=TMR0H;		//Send higher bytes to PORTD
		}
		while(INTCONbits.TMR0IF==0);	//Wait for TF0 to roll over and count till FFFFH+1.
		T0CONbits.TMR0ON=0;			//Turn OFF T0
		INTCONbits.TMR0IF=0;		//Clear the overflow flag TF0
	}
}