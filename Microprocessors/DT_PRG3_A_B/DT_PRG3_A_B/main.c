/*
 The program should generate a square wave with a period of 20us on pin PORTB.3, assuming the XTAL=16MHz.
 For each method, you must examine the frequency using the oscilloscope and describe the results.
 Part AB - Interrupt, Timer 0, Normal Mode
 
 10us for HIGH, 10us for LOW

 FREQ = 1600000, N = (10*10^-6)*(16000000) = 160. n=160 TCNT = 256 - n
 */

 #include <avr/io.h>
 #include <avr/interrupt.h>


 int main(void) {
 
	//Part AB - Interrupt
	//Data Direction, set pin 3 on PORTB for output, and clear the bit on the port before timer starts
	DDRB |= 1<<3;
	//PORTB &= ~(1<<3);
 
	//Start Clock
	//Normal Mode
	TCCR0A = 0x00;
	//No Prescaler
	TCCR0B = 0x01;
	//Counter initiation
	TCNT0 = 96;
	sei();
	//Mask for Interrupt
	TIMSK0 = 1<<TOIE0;
		
	//while loop to keep output going
	while(1) {}
		
	return 0;
 }
	
	//interrupt service routine
 ISR(TIMER0_OVF_vect) {
	 //reload TCNT to reset it
	 TCNT0 = 96;
	 //instruction
	 PORTB ^= 1<<3;
	 }
