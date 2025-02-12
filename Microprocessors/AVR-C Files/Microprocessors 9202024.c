/*
 * GccApplication1.c
 *
 * Created: 9/20/2024 1:08:56 PM
 * Author : 18639
 
 toggle port B every 1 second
 pinD 3 toggling
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = 0xFF;
	PORTB = 0x00;
	//DDRD = 0xFF;
	//DDRD |= (1 << 3);
	
	
    /*while (1) 
    {
		//PORTB ^= 0xFF;	
		//_delay_ms(1000);
		//PIND ^= (1 << 3);
		
		PORTD ^= (1 << 3);
		_delay_ms(1000);
	
		
    }*/
	
	//write an AVR c program to toggle all pins of pORT d 100,000 times
	DDRD = 0xFF;
	for(int i = 0; i<=100000;i++) {
		PORTD ^= 0xFF;
	}
	
	while(1);
	return 0;
}

