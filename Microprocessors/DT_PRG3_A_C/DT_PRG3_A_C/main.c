 /*
 The program should generate a square wave with a period of 20us on pin PORTB.3, assuming the XTAL=16MHz.
 For each method, you must examine the frequency using the oscilloscope and describe the results.
 Part AC - Delay Function, Timer 0, Normal Mode
 
 10us for HIGH, 10us for LOW

 FREQ = 1600000, N = (10*10^-6)*(16000000) = 160. n=160 TCNT = 256 - n
 */
#define F_CPU 16000000UL
 #include <avr/io.h>
 #include <util/delay.h>


 int main(void) {
 
	//Part AC - Delay Function
	//Data Direction, set pin 3 on PORTB for output, and clear the bit on the port before timer starts
	DDRB |= 1<<3;
	//PORTB &= ~(1<<3);
 
 
	//while loop that uses delay function to delay 10 microseconds and then toggles
	while(1) {
		_delay_us(10);
		PORTB ^= (1<<3); 
	}
		
	return 0;
 }