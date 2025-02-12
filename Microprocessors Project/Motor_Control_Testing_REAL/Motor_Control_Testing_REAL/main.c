
#include <avr/io.h>
#define F_CPU 16000000UL
#define PWM_FREQUENCY 1000     
#define DUTY_CYCLE 0.5         
#include <util/delay.h>

int getDistance(int trigger, int echo) {
	//duration variable
	int duration = 0;
	//FRONT, TRIGGER = D7, ECHO = C0
	//LEFT, TRIGGER = D0, ECHO = D1
	//RIGHT, TRIGGER = D2, ECHO = D4
	
	//if statement to check if on front sensor or not
	if(trigger == 7 && echo == 0) {
		//send 10 microsecond pulse to trigger
		PORTD |= 1 << trigger;
		_delay_us(10);
		PORTD &= ~(1 << trigger);
		
		//wait for echo pin to receive the pulse
		while (!(PINC & (1 << echo)));

		//measure how long echo pin stays HIGH
		while (PINC & (1 << echo)) {
			duration++;
			_delay_us(1);
			}

		//calculate distance in cm: duration / 58 (for 1µs per round trip count at 340m/s (speed of sound) )
		return duration / 58;
	}
	
	else {
		//else, now we are using front and right, so strictly PORTD
		//send 10 microsecond pulse to trigger
		PORTD |= 1 << trigger;
		_delay_us(10);
		PORTD &= ~(1 << trigger);
				
		//wait for echo pin to receive the pulse
		while (!(PIND & (1 << echo)));

		//measure how long echo pin stays HIGH
		while (PIND & (1 << echo)) {
				duration++;
				_delay_us(1);
				}
		return duration / 58;
	}



/*
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
}*/


void motorPWMInit() {
		//FRONT LEFT WHEEL:
		//FRONT RIGHT WHEEL:
		//REAR LEFT WHEEL:
		//REAR RIGHT WHEEL:
		// Set PD3 (OC2B), PD5 (OC0B), PD6 (OC0A), and PB3 (OC2A) as outputs
		DDRD |= (1 << 3) | (1 << 5) | (1 << 6);
		DDRB |= (1 << 3);

		// Configure Timer 0 for Fast PWM on PD6 (OC0A) and PD5 (OC0B)
		TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1); // Fast PWM mode, and clear OC0A on compare match, set on BOTTOM, and clear OC0B on compare match, set on BOTTOM
		TCCR0B = (1 << CS01);                   // Prescaler: 8

		// Set the duty cycle for PD6 and PD5
		OCR0A = (uint8_t)(DUTY_CYCLE * 255);    // PD6 (OC0A)
		OCR0B = (uint8_t)(DUTY_CYCLE * 255);    // PD5 (OC0B)

		// Configure Timer 2 for Fast PWM on PB3 (OC2A) and PD3 (OC2B)
		TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << COM2A1) | (1 << COM2B1);  // Fast PWM mode, and clear OC2A on compare matc set on BOTTOM, and Clear OC2B on compare match, set on BOTTOM
		TCCR2B = (1 << CS21);                   // Prescaler: 8

		// Set the duty cycle for PB3 and PD3
		OCR2A = (uint8_t)(DUTY_CYCLE * 255);    // PB3 (OC2A)
		OCR2B = (uint8_t)(DUTY_CYCLE * 255);    // PD3 (OC2B)
		return;
	}
	
	void stopCar(float dutyCycle) {
		OSCRA = 
		
	}
	
	
	
	/*
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
	return;
}*/


int main(void) {
	//initialization
	//left, right, and front distances are the respective distances the ultrasonic sensor sees. initialize them to 0
	// detection LEDs are output
	//then initialize the left, right, and front ultrasonic sensors
	//then initialize the PWM settings for each wheel
	
	int left_distance = 0;
	int right_distance = 0;
	int front_distance = 0;
	
	//detection LED initialization
	//configure left sensor test LED to port C pin 0
	DDRC |= 1<<0;
	
	//configure right sensor test LED to port C pin 1
	DDRC |= 1<<1;
	
	//configure front sensor test to port C pin 2
	DDRC |= 1<<2;
	
	//front ultrasonic sensor initialization
	//trigger pin: PORTD PIN7
	//echo pin: PORTC PIN3
	DDRD |= (1 << 7); //set trigger pin as output
	DDRC &= ~(1 << 3); //set echo pin as input
	
	
	//left ultrasonic sensor initialization
	//trigger pin: PORTD PIN0
	//echo pin: PORTD PIN1
	DDRD |= (1 << 0); //set trigger pin as output
	DDRD &= ~(1 << 1); //set echo pin as input
	
	//right ultrasonic sensor initialization
	//trigger pin: PORTD PIN2
	//echo pin: PORTD PIN4
	DDRD |= (1 << 2); //set trigger pin as output
	DDRD &= ~(1 << 4); //set echo pin as input

	motorPWMInit();
	
	//initialize speed of wheels, set each to 50% duty
	//OCR0A = 128; //50% duty of FRONT LEFT WHEEL
	//OCR0B = 128; //50% duty of REAR LEFT WHEEL
	//OCR2A = 128; //50% duty of FRONT RIGHT WHEEL
	//OCR2B = 128; //50% duty of REAR RIGHT WHEEL
	
	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		left_distance = getDistance(0,1);
		right_distance = getDistance(2,4);
		front_distance = getDistance(7,0);
		
		// else if statement to check if the front distance is 5 centimeters away or less
		if (front_distance > 0 | right_distance > 0 | left_distance > 0) {
			if (front_distance <= 15) {
				//then go slower on both wheels by decreasing front left and right wheels by 10 clock cycles, and turn on detection LED
				//OCR0A -= 10;
				//OCR2A -= 10;
				PORTB |= 1<<0;
			}/*
		
		// if statement to check if the left distance is 5 centimeters away or less
		if (left_distance <= 15) {
			//then go slower on the right side, by decreasing the front right wheel by 10 clock cycles, and turn on detection LED
			//OCR2A -= 10;
			PORTC |= 1<<6;
		}
		
		//if statement to check if the right distance is 5 centimeters away or less
		if (right_distance <= 15) {
			//then go slower on the left side, by decreasing the front left wheel by 10 clock cycles, and turn on detection LED
			//OCR0A -= 10;
			PORTC |= 1<<7;
		}*/
		
		else {
			//else, resume wheels to 50% duty. assume normal road conditions
			//OCR0A = 128;
			//OCR2A = 128;
			
			PORTC &= ~(1<<6);
			PORTC &= ~(1<<7);
			PORTB &= ~(1<<0);
		}
		}
		_delay_us(10); //10µs delay between readings
	}

	return 0;
}
