/*
 * Microprocessors 1042024.c
 *
 * Created: 10/4/2024 1:00:34 PM
 * Author : 1863
 */ 

//#define F_CPU 16000000UL


#include <avr/io.h>
//#include <util/delay.h>


int main(void) {
	DDRD = 0xFF;
	while (1) {
		//sets pin 0, 1, 2, on D LOW to go to a, b, c on seven seg respectively since its common anode since its the 7 seg from the lab
		PORTD = 0b11111000;
		
	}
	
	return 0;
}



/*





int main(void)
{
	//Data direction just for Port D, Pin 3, and just for Port B, Pin 3
    DDRD |= 1<<4;
	DDRB |= 1<<3;
	//variable for age. value is typically within 0-255, so used unsigned char
	unsigned char x = 17;
    while (1) 
    {		
		
			//if x is greater than 18, set port D pin 4 (Green LED) HIGH, and set port B pin 3 LOW to turn off red LED in case it was on
			if(x>=18) {
				PORTD |= 1<<4;
				PORTB &= ~(1<<3);
			}
			
			//else, set port B pin 3 HIGH (Red), and port D pin 4 LOW to turn off green LED in case it was on
			else {
				PORTB |= 1<<3;
				PORTD &= ~(1<<4);
			}
			
			//not apart of assignment, was for video. this increments x after a 4 second delay, so x goes from 17 to 18, so the video shows both LEDs and logic working.
			_delay_ms(4000);
			x++;
	}
			
			
}*/
