 /*
 The program should generate a square wave with a period of 20us on pin PORTB.3, assuming the XTAL=16MHz.
 For each method, you must examine the frequency using the oscilloscope and describe the results.
 Part bB - Interrupt, Timer 2, CTC Mode
 
 10us for HIGH, 10us for LOW

 FREQ = 1600000, N = (10*10^-6)*(16000000) = 160. n=160 OCR2A = n-1 = 159
 */

 #include <avr/io.h>
 #include <avr/interrupt.h>


 int main(void) {
 
	//Part B - Interrupt
	//Data Direction, set pin 3 on PORTB for output, and clear the bit on the port before timer starts
	DDRB |= 1<<3;
		//Start Clock
		//CTC Mode
		TCCR2A = 0x02;
		//No Prescaler
		TCCR2B = 0x01;
		//Counter initiation
		TCNT2 = 0;
		OCR2A = 159;
		//Mask for Interrupt
		TIMSK2 = 1<<OCIE2A;
		//Enable Global Interrupt
		sei();
		while(1) {}
		 
 //Instructions with ISR
	
	return 0;
 }
	
	//interrupt service routine 
 ISR(TIMER2_COMPA_vect) {
	 PORTB ^= 1<<3;
	 }