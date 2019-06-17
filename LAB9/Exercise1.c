#include<p18cxxx.h>		//Include the library of the required microcontroller
#define rs PORTDbits.RD7	//Define various variable names for different pins
#define rw PORTDbits.RD6
#define en PORTDbits.RD5
#define lcdport PORTB		//Define a variable name for PORTB
void lcd_ini(void);			//Initialise various required functions
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void interrupt(void);
void chk_isr(void);
void RX_ISR(void);
void MSDelay(unsigned int itime);
unsigned char data[]="Rajan's ID No.'\0'";	//Declare various arrays to store data in the RAM 
unsigned char card_id[12];
unsigned int i=0;

#pragma code My_Hiprio_Int=0x08		//High priority Interrupt location
void My_Hiprio_Int(void)
{
	_asm
	GOTO chk_isr
	_endasm
}
#pragma code

#pragma interrupt chk_isr		//Interrupt Service Routine
void chk_isr(void)
{
	RX_ISR();
}
void main(void)
{
	TRISB=0;					//Configure the LCD ports, serial port, Baud rate and interrupts
	TRISD=0;
	TRISCbits.TRISC7=1;
	RCSTA=0x90;
	SPBRG=0x20;
	RCSTAbits.CREN=1;
	RCSTAbits.SPEN=1;
	PIE1bits.RCIE=1;
	INTCONbits.PEIE=1;
	INTCONbits.GIE=1;

	lcd_ini();				//LCD initialisation
	
	while(data[i]!='\0')
	{
		lcddata(data[i]);		//To send characters one by one from the 'data' array
		i++;
	}
	while(1)
	{
		i=0;
		while(i<12);
		lcdcmd(0xC0);		//Position the cursor at the second line of the display
		i=0;
		while(i<12)
		{
			lcddata(card_id[i]);	//Display the 12 bytes received data on the LCD
			i++;
		}
	}
}

void RX_ISR()
{
	card_id[i]=RCREG;			//Store the received data byte by byte
	i++;
}

void lcd_ini()		//Configuring the LCD
{
	lcdcmd(0x38);
	lcdcmd(0x0E);
	lcdcmd(0x01);
	lcdcmd(0x06);
	lcdcmd(0x80);
}

void lcdcmd(unsigned char cmdout)
{
	lcdport=cmdout;				//Send command to lcdport
	rs=0;
	rw=0;
	en=1;
	MSDelay(15);
	en=0;
}

void lcddata(unsigned char dataout)
{
	lcdport=dataout;			//Send data to lcdport
	rs=1;
	rw=0;
	en=1;
	MSDelay(15);
	en=0;
}

void MSDelay(unsigned int itime)		//Delay needed to allow LCD to process commands and data
{
	unsigned int i,j;
	for(i=0;i<itime;i++)
	{
		for(j=0;j<135;j++);
	}
}
