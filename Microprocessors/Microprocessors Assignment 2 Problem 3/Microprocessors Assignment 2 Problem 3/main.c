/*
 * Microprocessors Assignment 2 Problem 3.c
 *
 * Created: 10/27/2024 9:59:50 PM
 * Author : 18639
 */ 

#include <avr/io.h>


int main(void)
{
	//clear pin 4 on PORTC, since its input
    DDRC &= ~(1<<4);
	//set pins 5 and 6 on port D since they're outputs
	DDRD |= ((1<<5) | (1<<6));
	
	
    while (1) 
    {
		if((PINC & (1<<4)) != 0) {
			PORTD |= (1<<5);
			PORTD &= ~(1<<6);
		} 
		else {
			PORTD |= (1<<6);
			PORTD &= ~(1<<5);
			}
    }
	return 0;
}

