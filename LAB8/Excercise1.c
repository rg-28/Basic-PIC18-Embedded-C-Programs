#include<p18cxxx.h>		//Inlcude the library required for the microcontroller
#define RS PORTDbits.RD7	//Define variable names for different pins required
#define RW PORTDbits.RD6
#define EN PORTDbits.RD5
#define SW PORTEbits.RE2
void command_wrt(unsigned int);	//Initialise various required functions
void data_wrt(unsigned int);
void Delayms(void);
void Delays(void);
unsigned int c=0,d=0,e=0;	//Declare some int variables
unsigned int lcdset[]={0x38,0x0E,0x01,0x06,0x80};	//Declare various arrays to display the data on the screen
unsigned char display1[]="Time in Seconds";
unsigned char display2[]="Seconds";
void main(void)
{
	ADCON1=0x06;	//Sets RE0-RE2 as digital pins
	TRISB=0;		//Sets PORTB as O/P port
	TRISD=0;		//Sets PORTD as O/P port
	TRISEbits.TRISE2=1;		//Sets RE2 as I/P pin
	for(e=0;e<5;e++)	//Sets a for loop to send some commands to the LCD
	{
		command_wrt(e);
		Delayms();
	}
	for(e=0;e<15;e++)	//Sets a for loop to display the data in the first line of LCD
	{
		data_wrt(e);
		Delayms();
	}
	command_wrt(0xC5);	//Sets cursor at 6th positon in 2nd line of LCD
	Delayms();
	for(e=0;e<7;e++)	//Displays the required data in second line of LCD
	{
		data_wrt(e);
		Delayms();
	}
	command_wrt(0xC3);	//Sets cursor at 4th positon in 2nd line of LCD
	Delayms();
	while(1)		//Sets an inifinite loop to run the program forever
	{
		if(SW==1 && d==0)	//Checks the status of switch and d
		{
			d=1;
continue1:	Delays();
			if(SW==0)		//Checks the status of switch after 1s delay
			{
				data_wrt(c);	//Displays the time on LCD and increment it
				Delayms();
				c=c+1;
			}
			else if(SW==1)
			{
				c=0;			//Resets the time and display it on LCD
				data_wrt(c);
				Delayms();
			}
		}
		else if(SW==1 && d==1)
		{
continue2:	data_wrt(c);		//Stops the time and display it continuously on LCD
			d=0;
		}
		if(c==60);		//It resets the time when it reaches 60s
			c=0;
		if(SW==0 && d==1)	//Continuously increments the time until the switch is pressed again
			goto continue1;
		else if(SW==0 && d==0)	//Continuously displays the same time until the switch is pressed again
			goto continue2;
	}
}
void command_wrt(unsigned int cmd)	//Command write function
{
	PORTB=cmd;		// O/P the cmd to PORTB
	RS=0;			//Clear the register select pin
	RW=0;			//Clear the read/write pin
	EN=1;			//Set the enable pin
	Delayms();
	EN=0;			//Clear the enable pin
}
void data_wrt(unsigned int data)	//Data write function
{
	PORTB=data;		// O/P the data to PORTB
	RS=1;			//Set the register select pin
	RW=0;			//Clear the read/write pin
	EN=1;			//Set the enable pin
	Delayms();
	EN=0;			//Clear the enable pin
}
void Delays()		//Delay function for 1000ms
{
	T0CON=0x06;		//Timer0, 16-bit mode with no prescaler
	TMR0H=0x60;
	TMR0L=0x00;
	T0CONbits.TMR0ON=1;		//Set TMR0 ON.
	while(INTCONbits.TMR0IF==0);	//Check the overflow flag
	T0CONbits.TMR0ON=0;		//Stop TMR0
	INTCONbits.TMR0IF=0;	//Clear the overflow flag
}
void Delayms()		//Delay function for 1ms
{
	T0CON=0x08;		//Timer0, 16-bit mode with no prescaler
	TMR0H=0x13;
	TMR0L=0x88;
	T0CONbits.TMR0ON=1;		//Set TMR0 ON.
	while(INTCONbits.TMR0IF==0);	//Check the overflow flag
	T0CONbits.TMR0ON=0;		//Stop TMR0
	INTCONbits.TMR0IF=0;	//Clear the overflow flag
}
