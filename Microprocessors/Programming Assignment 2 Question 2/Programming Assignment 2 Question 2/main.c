/*
 * Programming Assignment 2 Question 2.c
 *
 * Created: 10/27/2024 9:20:53 PM
 * Author : 18639
 */ 

#include <avr/io.h>


int main(void)
{
	
	//data direction, pin 6 on D is an input, pin 4 on D is an output
    DDRD &= ~(1<<6);
	DDRD |= (1<<4);
	
    while (1) 
    {
		//use PIND to read into write into arduino, monitor pin6 on PIND
		if ((PIND & (1<<6)) != 0) {
			//if HIGH detected, set pin 4 on port D
			PORTD = 1<<4;
		}
		else {
			//else, clear pin 4 on PORTD
			PORTD &= ~(1<<4);
		}
	
	}
	return 0;
}

