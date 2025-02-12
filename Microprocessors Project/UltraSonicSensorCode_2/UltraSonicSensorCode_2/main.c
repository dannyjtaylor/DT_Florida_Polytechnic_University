#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int getDistance() {
	//duration variable
	int duration = 0;

	//send a 10µs high pulse to the trigger pin
	PORTD |= (1 << 2);
	_delay_us(10);
	PORTD &= ~(1 << 2);

	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 3)));

	//measure how long echo pin stays HIGH
	while (PIND & (1 << 3)) {
		duration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1µs per round trip count at 340m/s (speed of sound) )
	return duration / 58;
}

int main(void) {
	//trigger pin: PORTD2 PIN2
	//echo pin: PORTD PIN3
	//initialize to zero
	int distance = 0;
	
	//initialize ultrasonic sensor
	
	DDRD |= (1 << 2); //set trigger pin as output
	DDRD &= ~(1 << 3); //set echo pin as input
	//PORTD &= ~(1 << 2); //initially make trigger pin low
	
	DDRD |= (1 << 0); //set PORTD0 as output for LED
	PORTD &= ~(1 << 0); //initially make LED low

	while (1) {
		//get the distance from object to ultrasonic sensor
		distance = getDistance();
		//check if within sensor range (in centimeters)
		if (distance > 0 && distance <= 50) { 
			//if detected, turn on LED
			PORTD |= (1 << 0);
			//else, not detected, turn on LED
			} else {
			PORTD &= ~(1 << 0);
		}

		//_delay_ms(10); //delay between readings
	}
	
	return 0;
}