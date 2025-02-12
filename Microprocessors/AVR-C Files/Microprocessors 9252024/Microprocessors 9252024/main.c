/*
 * Microprocessors 9252024.c
 *
 * Created: 9/25/2024 1:12:02 PM
 * Author : 18639
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

//value received from port D
int main(void)
{
	DDRC &= ~(1<<3));
	DDRD = 0xFF;
	//unsigned char value = 0x55;	
	
    for(unsigned char i = 0; i<=7; i++) {
		if (PINC & (1<<3) != 0) { //USE PIN D SINCE ITS COMING INNNNN!! SINCE THATS THE INPUTS GOING INTO D, which is then sent to PORTC
			//
			// //or equals to only make bit 3 on PORTC 1, so its outputting 1
			PORTD |= (1<<i);
			}
		else {
			// //and equals the negation to make only bit 3 on PORTC 0, so its outputting 0. should use negation when doing AND=, maybe not always for AND
			PORTD &= ~(1<<i);
			
			//bringing in data, u check the input in the condition
		}
		
	}
    while (1) 
    {
    }
	
	return 0;
}

