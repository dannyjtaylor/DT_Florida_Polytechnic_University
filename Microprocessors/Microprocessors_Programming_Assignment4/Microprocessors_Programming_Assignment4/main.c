//ACTIVITY 1

/*

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

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	//data direction, port B all input, port C all output, port D1 is output, then for activity 2, ports D2/D3 are input, port D4 is output
	DDRB = 0x00;
	DDRC = 0xFF;
	DDRD |= (1<<4 | 1<<1);
	DDRD &= ~((1<<3 | 1<<2));
	
	//timer 0 setup, CTC mode w/ 8 prescalar
	TCCR0A = 0x02;
	TCCR0B = 0x02;
	//set output compare
	OCR0A = 200-1;
	
	//interrupt masks
	EIMSK = 1<<INT0 | 1<<INT1;
	TIMSK0 = 1<<OCIE0A;
	
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

//timer compare interrupt
ISR(TIMER0_COMPA_vect) {
	//upon interrupt starting, toggle pin 1 on PORTD per rawa's instructions
	PORTD ^= 1<<1;
}
//external interrupt 0
ISR(INT0_vect) {
	//int0, low to high pulse, turn LED on
	PORTD |= (1<<4);
}

//external interrupt 1
ISR(INT1_vect) {
	//int 1, high to low pulse, turn LED off
	PORTD  &= ~(1<<4);
}
