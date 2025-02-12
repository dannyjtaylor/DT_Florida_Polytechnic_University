/*
 * Programming_Assignment_4.c
 *
 * Created: 11/21/2024 6:30:24 PM
 * Author : 18639
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


/* 
ACTIVITY 1: Write a program to get data from port B and send it to port C continuously while an interrupt will do the
following: One of the timers will toggle pin PB1 every 100 microseconds. (I realize the assignment says Pin B1, but she told us in class to use PD1 since PORTB is being used as input continuously.)


ACTIVITY 2: Add the following interrupt to Activity 1:
Assume a square wave is connected to an external interrupt, and any time a L-to-H pulse
comes in, a single LED connected to PB2 is turned on, and any time a H-to-L pulse comes in,
the LED is turned off.
The rate of "On" and "Off" is the same as the square wave frequency. (I realize this sounds like we should code in the square wave, but she told us to use the lab function generator for this affect)


Desired Delay = 100 microseconds, so Number of Clock Cycles = 100*10^-6 * 16000000 = 1600, can use TIMER1 in Normal Mode




//ACTIVITY 1

int main(void)
{
	//data direction
	DDRB = 0x00;
	DDRC = 0xFF;
	DDRD |= 1<<1;
	//timer setup, normal mode w/ no prescalar
	TCCR1A = 0x00;
	TCCR1B = 0x01;
	//set TCNT1 appropriately 
	TCNT1 = 63936;
	//interrupt setup, and enable global interrupt 
	TIMSK1 = 1<<TOIE1;
	sei();
	
	//wait here, send data
	while (1) {
		PORTC = PINB;
	}
	return 0;
}

ISR(TIMER1_OVF_vect) {
	//reset counter for the square wave
	TCNT1 = 63936;
	//upon interrupt starting, toggle pin 1 on PORTD per rawa's instructions
	PORTD ^= 1<<1;
	//don’t need to change TOV flag or reset clock w/ TCCR1B as the interrupt does it for you
}

*/

//ACTIVITY 2
int main(void)
{
	//data direction, port B all input, port C all output, port D1 is output, ports D2/D3 are input
	DDRB = 0x00;
	DDRC = 0xFF;
	DDRD |= 1001<<4;
	DDRD &= ~(11<<3);
	
	//timer 1 setup, normal mode w/ no prescalar
	TCCR1A = 0x00;
	TCCR1B = 0x01;
	//set TCNT1 appropriately
	TCNT1 = 63936;
	
	//interrupt masks
	EIMSK = (1<<INT0 | 1<<INT1); 
	TIMSK1 = 1<<TOIE1;
	
	//external interrupt setup (INT 0 is low to high, INT1 is high to low, EICRA = 0000 1110
	EICRA = 0x0E;
	
	//enable global interrupt
	sei();
	
	//for activity 2, turn LED off initially 
	PORTD &= ~(1<<4);
	//wait here, send data
	while (1) {
		PORTC = PINB;
	}
	return 0;
}
ISR(TIMER1_OVF_vect) {
	//reset counter for the square wave
	TCNT1 = 63936;
	//upon interrupt starting, toggle pin 1 on PORTD per rawa's instructions
	PORTD ^= 1<<1;
	//don’t need to change TOV flag or reset clock w/ TCCR1B as the interrupt does it for you
}
ISR(INT0_vect) {
	//int0, low to high pulse, turn LED on
		PORTD |= (1<<4);
}

ISR(INT1_vect) {
		//int 1, high to low pulse, turn LED off
		PORTD  &= ~(1<<4);
}

