/*
 * DT_PRG3_B_A.c
 *
 * Created: 11/7/2024 12:38:52 PM
 * Author : 18639
 
 The program should generate a square wave with a period of 20us on pin PORTB.3, assuming the XTAL=16MHz.
 For each method, you must examine the frequency using the oscilloscope and describe the results.
Part BA - Polling, Timer 2, CTC Mode
10 us for ON, 10 us for HIGH

FREQ = 1600000, N = (10*10^-6)*(16000000) = 160. OCR2A = n - 1 = 160 - 1 =159
 */ 

#include <avr/io.h>


int main(void)
{
	
	//Part A - Polling
		//Data Direction, set pin 3 on PORTB for output, and clear the bit on the port before timer starts
	DDRB |= 1<<3;
	//Start Clock
	//CTC Mode
	TCCR2A = 0x02;
	// No Prescaler
	TCCR2B = 0x01;
	  while (1)
	  {
		  
		  TCNT2 = 0;
		  OCR2A = 159; 
		  
		  //Monitor
		  while((TIFR2 & 1<<OCF2A) == 0) {}
			  
		  //Stop/Reset Clock
		  TIFR2 = 1<<OCF2A;
		  
		  //Instructions
		  PORTB ^= 1<<3;
    }
	return 0;
}

