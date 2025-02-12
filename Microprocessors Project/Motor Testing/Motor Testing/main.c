
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void testLEDInit() {
	//configure left sensor test LED to port c pin 6
	DDRC |= 1<<6;
	
	//configure right sensor test LED to port c pin 7
	DDRC |= 1<<7;
	Q
	//configure front sensor test to port B pin 0
	DDRB |= 1<<0;
	
	return;
}

int getDistanceLeft() {
	//duration variable
	int duration = 0;
	
	//send a 10탎 high pulse to the left ultrasonic trigger pin
	PORTC |= (1 << 3);
	_delay_us(10);
	PORTC &= ~(1 << 3);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 2)));

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 2)) {
		duration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return duration / 58;
}

int getDistanceRight() {
	//duration variable
	int duration = 0;
	
	//send a 10탎 high pulse to the right ultrasonic trigger pin
	PORTC |= (1 << 0);
	_delay_us(10);
	PORTC &= ~(1 << 0);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 1)));

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 1)) {
		duration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return duration / 58;
}

int getDistanceFront() {
	//duration variable
	int duration = 0;
	
	//send a 10 탎 high pulse to the front ultrasonic trigger pin
	PORTC |= (1 << 4);
	_delay_us(10);
	PORTC &= ~(1 << 4);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 5)));

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 5)) {
		duration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return duration / 58;
}


void leftUltrasonicInit() {
	//trigger pin: PORTC PIN0
	//echo pin: PORTC PIN1
	DDRC |= (1 << 3); //set trigger pin as output
	DDRC &= ~(1 << 2); //set echo pin as input
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


void motorPWMInit() {
	//LEFT WHEELS (TIMER 0)
	//TCCR0A = 0x83; //sets timer 0 in fast PWM with non-inverting
	//TCCR0B = 0x01; //sets timer 0 in clk NO PRESCALER
	
	// Configure Timer 0 for Fast PWM mode with non-inverting output on OC0A
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

	// Set clock prescaler to 256
	TCCR0B = (1 << CS02); // CS02:1, CS01:0, CS00:0 -> Prescaler = 256
	
	//FRONT LEFT
	//set PORT D pin 6 for OC0A
	DDRD |= 1<<6;
	OCR0A = 0;
	
	//REAR LEFT
	//set PORT D pin 5 for OC0B
	DDRD |= 1<<5;
	OCR0B = 0;
	

	//RIGHT WHEELS (TIMER 2)
	//TCCR2A = 0x83; //sets timer 2 in fast PWM with non-inverting
	//TCCR2B = 0x01; //sets timer 2 in clk NO PRESCALER
	// Configure Timer 0 for Fast PWM mode with non-inverting output on OC0A
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);

	// Set clock prescaler to 256
	TCCR2B = (1 << CS22) | (1 << CS21); // CS02:1, CS01:0, CS00:0 -> Prescaler = 256
	
	
	//FRONT RIGHT
	//set PORTB pin 3 for OC2A
	DDRB |= 1<<3;
	OCR2A = 0;
	
	//REAR RIGHT
	//set PORT D pin 3 for OC2B
	DDRD |= 1<<3;
	OCR2B = 0;
	return;
}


int main(void) {
	//initialization, where the left, right, and front distances are the respective distances the ultrasonic sensor sees
	//then initialize the left, right, and front ultrasonic sensors
	//then initialize the PWM settings for each wheel 
	
	int left_distance = 0; 
	int right_distance = 0;
	int front_distance = 0;
	
	leftUltrasonicInit();
	rightUltrasonicInit();
	frontUltrasonicInit();
	motorPWMInit();
	
	//initialize speed of wheels, set each to 50% duty
	//OCR0A = 128; //50% duty of FRONT LEFT WHEEL
	//OCR0B = 128; //50% duty of REAR LEFT WHEEL
	//OCR2A = 128; //50% duty of FRONT RIGHT WHEEL
	//OCR2B = 128; //50% duty of REAR RIGHT WHEEL
	
	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		left_distance = getDistanceLeft();
		right_distance = getDistanceRight();
		front_distance = getDistanceFront();
		
		// else if statement to check if the front distance is 5 centimeters away or less
		if (front_distance > 0 && front_distance <= 15) {
			//then go slower on both wheels by decreasing front left and right wheels by 10 clock cycles
			//OCR0A -= 10;
			//OCR2A -= 10;
			PORTB |= 1<<0;
		}
			
		//else if statement to check if the left distance is 5 centimeters away or less
		else if (left_distance > 0 && left_distance <= 15) {
			//then go slower on the right side, by decreasing the front right wheel by 10 clock cycles
			//OCR2A -= 10; 
			PORTC |= 1<<6;
		}
		
		//else if statement to check if the right distance is 5 centimeters away or less
		else if (right_distance > 0 && right_distance <= 15) {
			//then go slower on the left side, by decreasing the front left wheel by 10 clock cycles
			//OCR0A -= 10; 
			PORTC |= 1<<7;
		}
		
		else {
			//else, resume wheels to 50% duty. assume normal road conditions
			//OCR0A = 128;
			//OCR2A = 128;
			
			PORTC &= ~(1<<6);
			PORTC &= ~(1<<7);
			PORTB &= ~(1<<0);
		}
		_delay_us(10); //10탎 delay between readings
	}
	
	/*	while (1)
		{
			PORTD3 = OCF0A;
		}*/

	return 0;
}
