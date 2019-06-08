# Basic-PIC18-Embedded-C-Programs
These are some of the various excercises that I am working on to learn Embedded C using PIC18 Microcontroller.

**LAB1** includes the following programs:

**Excercise1**: This program outputs FFH to 00H in the form of binary at PORTB of PIC18.

**exc2**: This program outputs the hex codes of various ASCII characters already stored in the RAM at PORTB of the microcontroller.

**exc3**: This program outputs the hex codes of integers -6 to +6, which are already stored in the RAM at PORTB of the microcontroller.

**exc4**: This program toggles the output at PORTB 20,000 times.

**exc5**: This program toggles the output at PORTB 20,000 times with a delay 500 ms after every toggle.


**LAB2** includes the following programs:

**Excercise1**: This program toggles the output at pin 0 of PORTB with a delay generated using Timer0 of PIC18.

**exc5**: This program helps to toggle the output at pin RB0 if the onboard switch of PIC-P40 is in OFF position and othervise toggle the output at pin RB4 of PIC18 and also the delay used to create waves of different frequencies is generated using Timer.
 

**LAB3** includes the following programs:

**Excercise1**: This program helps to count the number of pulses sent to pin RA4 (with max value upto FFH) and then output the value of the counter at PORTB of PIC18.

**exc2**: This program helps to count the number of pulses sent to pin RA4 (with max value upto FFFFH) and then output the higher bytes of the counter at PORTD and lower bytes to PORTB of PIC18.


**LAB4** includes the following programs:

**Excercise1**: This program helps to light the onboard led of PIC18-P40 board for 500 ms while switch it off for 1000ms. Also the delays are created using timers.

**exc2**: This program helps to switch on\off the onboard led of PIC18-P40 board three times with a delay of 1000 ms and then generates a delay of 500 ms when the onboard switch is pressed odd number of times while the reverse pattern occurs with an external led connected to RB0 pin when the switch is pressed even number of times.


**LAB5** includes the following programs:

**Excercise1**: This program helps to send a pwm wave with different duty cycles at pin RC2 of PIC18 when the onboard switch of PIC18-P40 board is pressed various number of times succesively.


**LAB6** includes the following programs:

**Excercise1**: This program helps to light the 7-segment display connected to the PIC18 in a specific pattern in which different characters are displayed on the display after specific time delays.


**LAB7** includes the following programs:

**Excercise1**: This program helps to control a DC motor using PIC18 microcontroller. In this we control the DC motor using PWM wave generated using the CCP module of PIC18 in forward direction when the switch is pressed for first time along with a pattern dispalyed on leds and in reverse direction when the switch is pressed again along with another pattern displayed on leds.
