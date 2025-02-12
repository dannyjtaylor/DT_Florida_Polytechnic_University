#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	//data direction, PORB and PORTD are outputs
	DDRD = 0xFF;
	DDRB = 0xFF;
	
	//Write 1 to the ADEN ADCSA register to enable ADC conversion, have prescaler of 64. ADCSA = 1000 1110;
	ADCSRA = 0x8E;
	
	// ADMUX = 0100 0010, meaning we’re using AVV for VREF and using Channel 2 with right-justified.
	ADMUX = 0x42;

	//enable global interrupt
	sei();
	//after initialization, while loop to start conversion, poll, do instruction when conversion finished, and repeat

	while(1) {
		//write 1 to ADSC in ADSCRA to start conversion
		ADCSRA |= ADSC;
	}
	return 0;
}


ISR (ADC_vect) {
		//don't need to reset flag since using interrupts
		//ADCSA |= (1<<ADIF);

		//display ADC low and ADC high on port D and B respectively
		PORTD = ADCL;
		PORTB = ADCH;
		
		//100 ms after conversion complete so no corruption
		_delay_ms(100);
}