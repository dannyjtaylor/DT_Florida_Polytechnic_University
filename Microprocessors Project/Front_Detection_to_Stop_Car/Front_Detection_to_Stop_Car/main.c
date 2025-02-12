
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int getDistanceLeft() {
	//duration variable
	int durationLeft = 0;
	
	//send a 10탎 high pulse to the left ultrasonic trigger pin on pin D0
	PORTD |= (1 << 2);
	_delay_us(10);
	PORTD &= ~(1 << 2);

	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 7)));

	//measure how long echo pin stays HIGH
	while (PIND & (1 << 7)) {
		durationLeft++;
		_delay_us(1);
	}
	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return durationLeft / 58;
}


int getDistanceRight() {
	//duration variable
	int durationRight = 0;
	
	//send a 10탎 high pulse to the Right ultrasonic trigger pin on pin D0
	PORTB |= (1 << 1);
	_delay_us(10);
	PORTB &= ~(1 << 1);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 5)));

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 5)) {
		durationRight++;
		_delay_us(1);
	}
	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return durationRight / 58;
}


int getDistanceFront() {
	//duration variable
	int durationFront = 0;	
	//send 10 microsecond pulse to front sensor trigger
	PORTD |= (1 << 4);
	_delay_us(10);
	PORTD &= ~(1 << 4);
	
	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 0)));

	//while receiving pulse, count 
	while (PINC & (1 << 0)) {
		durationFront++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return durationFront / 58;
}

int main(void) {
	//initialization
	int front_distance = 0;
	int left_distance = 0;
	int right_distance = 0;
	
	//configure front sensor detection LED to port C pin 2
	DDRC |= 1<<2;
	//left sensor detection LED port B pin 0
	DDRB |= 1<<0;
	//right sensor detection LED port B pin 5
	DDRC |= 1<<1;
	
	//front ultrasonic sensor initialization
	//trigger pin: PORTD PIN0
	//echo pin: PORTD PIN1
	DDRD |= (1 << 4); //set trigger pin as output
	DDRC &= ~(1 << 0); //set echo pin as input
	
	//left ultrasonic sensor
	//trigger pin: PORT D PIN 2
	//echo pin: PORTD PIN 7
	DDRD |= (1 << 2); //set trigger pin as output
	DDRD &= ~(1 << 7); //set echo pin as input

	//right ultrasonic sensor
	//trigger pin: PORTB PIN1
	//echo pin: PORTB PIN2
	DDRB |= (1 << 1); //set trigger pin as output
	DDRC &= ~(1 << 5); //set echo pin as input

	//Front Right Wheel
	DDRB |= (1<<3);
	//Back Right Wheel
	DDRD |= (1<<3);
	//Front Left Wheel
	DDRD |= (1<<6);
	//Back Left Wheel
	DDRD |= (1<<5);

	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		front_distance = getDistanceFront();
		left_distance = getDistanceLeft();
		right_distance = getDistanceRight();
		
		// if statement to check if the front distance is X centimeters away or less
		if (front_distance > 0 && front_distance <= 5) {
			//then stop car and turn on front detection LED accordingly
			PORTD &= ~(1<<3);
			PORTD &= ~(1<<6);
			PORTD &= ~(1<<5);
			PORTB &= ~(1<<3);
			PORTC |= 1<<2;
		}
		else {
			//else, run like normal, and turn off front detection LED
			PORTD |= (1<<3);
			PORTD |= (1<<6);
			PORTD |= (1<<5);
			PORTB |= (1<<3);
			PORTC &= ~(1<<2);
		}
		
		
		// if statement to check if the left distance is X centimeters away or less
		if (left_distance > 0 && left_distance <= 5) {
			//turn on left detection LED accordingly
			PORTB |= 1<<0;
			}
		else {
			//else, run like normal, and turn off left detection LEDs
			PORTD |= (1<<3);
			PORTD |= (1<<6);
			PORTD |= (1<<5);
			PORTB |= (1<<3);
			PORTB &= ~(1<<0);
				}
				
				
		// if statement to check if the right distance is X centimeters away or less
		if (right_distance > 0 && right_distance <= 5) {
			//turn on right detection LED accordingly
			PORTC |= 1<<1;
				}
		
		else {
			//else, run like normal, and turn off right detection LED
			PORTD |= (1<<3);
			PORTD |= (1<<6);
			PORTD |= (1<<5);
			PORTB |= (1<<3);
			PORTC &= ~(1<<1);
		}
		
		_delay_us(10); //10탎 delay between readings
	}
	return 0;
}