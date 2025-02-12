#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


void testLEDInit() {
	//configure left sensor test LED to port D pin 2
	DDRD |= 1<<2;
	
	//configure right sensor test LED to port c pin 7
	DDRB |= 1<<1;
	
	//configure front sensor test LED to port B pin 0
	DDRB |= 1<<0;
	return;
}

void leftUltrasonicInit() {
	//trigger pin: PORTC PIN0
	//echo pin: PORTC PIN1
	DDRD |= (1 << 0); //set trigger pin as output
	DDRD &= ~(1 << 1); //set echo pin as input
	return;
}


void rightUltrasonicInit() {
	//trigger pin: PORTC PIN2
	//echo pin: PORTC PIN3
	DDRC |= (1 << 0); //set trigger pin as output
	DDRC &= ~(1 << 1); //set echo pin as input
	return;
}


void frontUltrasonicInit() {
	//trigger pin: PORTC PIN4
	//echo pin: PORTC PIN5
	DDRC |= (1 << 4); //set trigger pin as output
	DDRC &= ~(1 << 5); //set echo pin as input
	return;
}

int getDistanceLeft() {
	//duration variable
	int leftDuration = 0;
	
	//send a 10탎 high pulse to the left ultrasonic trigger pin
	PORTD |= (1 << 0);
	_delay_us(10);
	PORTD &= ~(1 << 0);

	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 1))) {}

	//measure how long echo pin stays HIGH
	while (PIND & (1 << 1)) {
		leftDuration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return leftDuration / 58;
}
/*
int getDistanceRight() {
	//duration variable
	int rightDuration = 0;
	
	//send a 10탎 high pulse to the right ultrasonic trigger pin
	PORTC |= (1 << 0);
	_delay_us(10);
	PORTC &= ~(1 << 0);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 1))) {}

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 1)) {
		rightDuration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return rightDuration / 58;
}

int getDistanceFront() {
	//duration variable
	int frontDuration = 0;
	
	//send a 10 탎 high pulse to the front ultrasonic trigger pin
	PORTC |= (1 << 4);
	_delay_us(10);
	PORTC &= ~(1 << 4);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 5))) {}

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 5)) {
		frontDuration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return frontDuration / 58;
}*/


int main(void) {	
	int left_distance = 0;
	//int right_distance = 0;
	//int front_distance = 0;
	
	testLEDInit();
	leftUltrasonicInit();
	while(1) {
		left_distance = getDistanceLeft();
		if (left_distance > 0 && left_distance <= 15) {
			//then go slower on the right side, by decreasing the front right wheel by 10 clock cycles
			//OCR2A -= 10;
			PORTD |= 1<<2;
				}
				else {
					PORTD &= ~(1<<2);
				}
	}
	
	//rightUltrasonicInit();
	//frontUltrasonicInit();
	
	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		left_distance = getDistanceLeft();
		//right_distance = getDistanceRight();
		//front_distance = getDistanceFront();
		
		// else if statement to check if the front distance is 5 centimeters away or less
		/*if (front_distance > 0 && front_distance <= 15) {
			//then go slower on both wheels by decreasing front left and right wheels by 10 clock cycles
			//OCR0A -= 10;
			//OCR2A -= 10;
			PORTB |= 1<<0;
		}*/
		
		//else if statement to check if the left distance is 5 centimeters away or less
		else if (left_distance > 0 && left_distance <= 15) {
			//then go slower on the right side, by decreasing the front right wheel by 10 clock cycles
			//OCR2A -= 10;
			PORTC |= 1<<6;
		}
		
		//else if statement to check if the right distance is 5 centimeters away or less
		/*else if (right_distance > 0 && right_distance <= 15) {
			//then go slower on the left side, by decreasing the front left wheel by 10 clock cycles
			//OCR0A -= 10;
			PORTC |= 1<<7;
		}*/
		
		else {
			//else turn LEDs off
			
			//PORTC &= ~(1<<6);
			PORTC &= ~(1<<7);
			PORTB &= ~(1<<0);
		}
		_delay_us(10); //10탎 delay between readings
	}
	return 0;
}