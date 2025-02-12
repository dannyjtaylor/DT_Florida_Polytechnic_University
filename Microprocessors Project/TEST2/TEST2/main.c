
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void detectionLEDInit() {
	//configure left sensor test LED to port c pin 0
	DDRC |= 1<<0;
	
	//configure right sensor test LED to port c pin 1
	DDRC |= 1<<1;
	
	//configure front sensor test to port B pin 2
	DDRC |= 1<<2;
	
	return;
}

void motorPWMInit() {
	//LEFT WHEELS (TIMER 0)
	//TCCR0A = 0x83; //sets timer 0 in fast PWM with non-inverting
	//TCCR0B = 0x01; //sets timer 0 in clk NO PRESCALER
	
	//set Timer 0 for Fast PWM mode with non-inverting output on OC0A
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

	//set timer0 clock prescaler to 256
	TCCR0B = (1 << CS02); 
	
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

	//set clock prescaler to 256
	TCCR2B = (1 << CS22) | (1 << CS21);
	
	
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


void leftUltrasonicInit() {
	//trigger pin: PORTD PIN0
	//echo pin: PORTD PIN1
	DDRD |= (1 << 0); //set trigger pin as output
	DDRD &= ~(1 << 1)/; //set echo pin as input
	return;
}


void rightUltrasonicInit() {
	//trigger pin: PORTD PIN7
	//echo pin: PORTD PIN4
	DDRD |= (1 << 2); //set trigger pin as output
	DDRD &= ~(1 << 4); //set echo pin as input
	return;
}


void frontUltrasonicInit() {
	//trigger pin: PORTD PIN7
	//echo pin: PORTC PIN3
	DDRD |= (1 << 7); //set trigger pin as output
	DDRC &= ~(1 << 3); //set echo pin as input
	return;
}


int getDistanceLeft() {
	//duration variable
	int durationLeft = 0;
	
	//send a 10탎 high pulse to the left ultrasonic trigger pin on pin D0
	PORTD |= (1 << 0);
	_delay_us(10);
	PORTD &= ~(1 << 0);

	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 1)));

	//measure how long echo pin stays HIGH
	while (PIND & (1 << 1)) {
		durationLeft++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return durationLeft / 58;
}

int getDistanceRight() {
	//duration variable
	int durationRight = 0;
	
	//send a 10탎 high pulse to the right ultrasonic trigger pin
	PORTD |= (1 << 2);
	_delay_us(10);
	PORTD &= ~(1 << 2);

	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 4)));

	//measure how long echo pin stays HIGH
	while (PIND & (1 << 4)) {
		durationRight++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return durationRight / 58;
}

int getDistanceFront() {
	//duration variable
	int durationFront = 0;
	
	//send a 10 탎 high pulse to the front ultrasonic trigger pin
	PORTD |= (1 << 7);
	_delay_us(10);
	PORTC &= ~(1 << 7);

	//wait for echo pin to receive the pulse
	while (!(PINC & (1 << 3)));

	//measure how long echo pin stays HIGH
	while (PINC & (1 << 3)) {
		durationFront++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return durationFront / 58;
}


int main(void) {
	//initialization, where the left, right, and front distances are the respective distances the ultrasonic sensor sees
	//then initialize the left, right, and front ultrasonic sensors
	//then initialize the PWM settings for each wheel 
	
	int left_distance = 0; 
	int right_distance = 0;
	int front_distance = 0;
	
	detectionLEDInit();
	leftUltrasonicInit();
	rightUltrasonicInit();
	frontUltrasonicInit();
	motorPWMInit();
	
	//initialize speed of wheels, set each to 50% duty
	OCR0A = 128; //50% duty of FRONT LEFT WHEEL
	OCR0B = 128; //50% duty of REAR LEFT WHEEL
	OCR2A = 128; //50% duty of FRONT RIGHT WHEEL
	OCR2B = 128; //50% duty of REAR RIGHT WHEEL
	
	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		left_distance = getDistanceLeft();
		right_distance = getDistanceRight();
		front_distance = getDistanceFront();
		
		// else if statement to check if the front distance is 5 centimeters away or less
		if (front_distance > 0 && front_distance <= 15) {
			//then go slower on all wheels by decreasing all wheels by 10 clock cycles
			OCR0A -= 1;
			OCR2A -= 1;
			OCR0B -= 1;
			OCR2B -= 1;
			//then, set PORTC PIN 2 to turn LED on
			PORTC |= 1<<2;
		}
			
		/* //else if statement to check if the left distance is 15 centimeters away or less
		else if (left_distance > 0 && left_distance <= 15) {
			//then go slower on the right side, by decreasing the front right wheel by 10 clock cycles
			OCR2A -= 1; 
			//then set PORTC PIN 0 to turn LED on
			PORTC |= 1<<0;
		}
		
		//else if statement to check if the right distance is 5 centimeters away or less
		else if (right_distance > 0 && right_distance <= 15) {
			//then go slower on the left side, by decreasing the front left wheel by 10 clock cycles
			OCR0A -= 10; 
			//then set PORTC PIN1 to turn LED on
			PORTC |= 1<<1;
		}*/
		
		else {
			//else, resume wheels to 50% duty. assume normal road conditions
			OCR0A = 128;
			OCR2A = 128;
			OCR0B = 128;
			OCR0A = 128;
			
			//and then ensure LEDs are turned off
			PORTC &= ~(1<<0);
			PORTC &= ~(1<<1);
			PORTC &= ~(1<<2);
		}
		_delay_us(10); //10탎 delay between readings
	}
	return 0;
}
