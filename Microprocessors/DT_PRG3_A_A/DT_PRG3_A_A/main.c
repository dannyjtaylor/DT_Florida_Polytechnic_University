#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

//initialize ultrasonic sensor
void ultrasonic_init() {
	//set trigger pin as output for four ultrasonic sensors
	DDRD |= (1 << 0);
	//DDRD |= (1 << 4);
	//DDRD |= (1 << 2);
	//DDRB |= (1 << 4);
	
	//data direction to have LED turn on
	DDRD |= 1<<6;
	//echo pin as input for four sensors
	DDRD &= ~(1 << 1);
	//DDRD &= ~(1 << 7);
	//DDRD &= ~(1 << 3);
	//DDRB &= ~(1 << 5);
}

// Function to send ultrasonic pulse
void ultrasonic_trigger(int x) {
	// Send a 10us high pulse
	PORTD |= (1 << x);  // Set trigger high

	_delay_us(10);                 // delay 10 uS
	PORTD &= ~(1 << x); // reset trigger pin
}

/*

void ultrasonic_trigger2() {
	// Send a 10us high pulse
	PORTB |= (1 << 4);  // Set trigger high

	_delay_us(10);                 // delay 10 uS
	PORTB &= ~(1 << 4); // reset trigger pin
}*/

// Function to measure the returning echo pulse
uint16_t ultrasonic_measure_distance(int x) {
	uint16_t count = 0;
	
	// Wait for the echo pin to go high
	while(!(PIND & (1 << x)));

	// Measure the time for which the echo pin stays high
	while(PIND & (1 << x)) {
		count++;
		_delay_us(1);
	}
	return count;
}

uint16_t ultrasonic_measure_distance2() {
	uint16_t count = 0;
	
	// Wait for the echo pin to go high
	while(!(PINB & (1 << 5)));

	// Measure the time for which the echo pin stays high
	while(PINB & (1 << 5)) {
		count++;
		_delay_us(1);
	}
	return count;
}


void PWM_Init() {
	//set PWM mode and prescaler for Timer1
	TCCR1A |= (1 << WGM10); // Fast PWM, 8-bit
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10); //prescaler of 1024

	//set non-inverting mode for OC1A
	TCCR1A |= (1 << COM1A1) | (1<< COM1B1);
	TCCR1B |= (1 << COM2A1) | (1<< COM2B1);
	
	//enable COM0A1, COM0B1 for non-inverting mode, and fast PWM
	//TCCR0A = 0b10100011;
	TCCR0A = 0xA3;
	
	//enable prescaler of 1024
	TCCR0B = 0x05;
	//TCCR0B = 0b00000101;

	//set duty cycle (5%)
	OCR1A = 12; // 5% of 255 (top value for 8-bit PWM) OCR1A = 12
	OCR1B = 12; //modified for second motor OCR1B = 12
	OCR0A = 12;
	OCR0B = 12;
	
	// Set PWM pins as output
	DDRB |= (1 << 1); // Assuming you're using PWM channel A of Timer1 (OC1A) on pin PB1
	DDRB |= (1 << 2);
	DDRD |= (1 << 5);
	DDRD |= (1 << 6);
}


int main() {
	PWM_Init();
	_delay_ms(4000);
	OCR1A = 13;
	OCR1B = 13;
	OCR0A = 13;
	OCR0B = 13;
	ultrasonic_init();
	while (1) {
		//us SENSOR
		uint16_t distance;
		
		//ultrasonic_trigger(4); // Trigger the ultrasonic pulse
		//distance = ultrasonic_measure_distance(7); // Measure the distance
		//int cm2 = distance/58;
		
		ultrasonic_trigger(0); // Trigger the ultrasonic pulse
		distance = ultrasonic_measure_distance(1); // Measure the distance
		int cm1 = distance/58;
		
		//ultrasonic_trigger(2); // Trigger the ultrasonic pulse
		//distance = ultrasonic_measure_distance(3); // Measure the distance
		//int// cm3 = distance/58;

		//ultrasonic_trigger2(); // Trigger the ultrasonic pulse
		//distance = ultrasonic_measure_distance2(); // Measure the distance
		//int cm4 = distance/58;

		// END US SENSOR
		//OCR1A = (32/(cm4*0.75))+13;
		//OCR1B = (32/(cm3*0.75))+13;
		OCR0A = (32/(cm1*0.75)) + 13;
		//OCR0B = (32/(cm2*0.75))+13;
		
	}

	return 0;
}