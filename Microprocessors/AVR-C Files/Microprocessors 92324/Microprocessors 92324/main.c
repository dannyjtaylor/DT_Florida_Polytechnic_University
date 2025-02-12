/*
 * Microprocessors 92324.c
 *
 * Created: 9/23/2024 1:13:28 PM
 * Author : 18639
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	//convert 2 binary digit values to the equivalent decimal value. binary values are connected to pins 2 and 3 on port C. and the decimal value is on port D.
	
	DDRC &= ~(11 << 2);
	DDRD = 0xFF;
	unsigned char dec = 0;
	if (PINC & (1<<2) != 0) {
		dec += 1;
	}
	
	else if (PINC & (1<<3) != 0) {
		
		dec+=2;
	}
	
	
	
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	//only make input bit #4, not the entire byte. and it with 0 to make it 0, so you ANDEQ with NOT (00010000), AND all other with 1 to keep them the same
	DDRC &= ~(1<<4);
	DDRB = 0xFF;
	//monitor bit 4 of port C, if high send 0xAA to port B. (sending meaning display it on port B, so B is an output. since ur sendinging it, C is the input 
	
	while(1) {
		if ((PINC & (1 << 4)) != 0) {
			PORTB = 0xAA;
		}
	}
		return 0;
	}
	
	/*
	
	
	
	
	
    DDRD = 0xFF;
	PORTD = 0xFF;
	
	for(long int i = 0; i < 100000; i++) {
		PORTD ^= 0xFF;
		//PORT D ~=(PORTD)
		_delay_ms(100)
	}
	
	should do a nested loop to use a smaller data type to save memory. 
		for(int i = 0; i<1000; i++) {
			for(unsigned char i; i<100;i++) {
				PORTD ^= 0xFF;
				_delay_ms(1000);
			}
		}
	
    while (1) 
		}
    }
	return 0;
}*/