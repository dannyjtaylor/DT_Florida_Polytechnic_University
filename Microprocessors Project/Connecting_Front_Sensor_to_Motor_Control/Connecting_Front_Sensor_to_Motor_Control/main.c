
#include <avr/io.h>
#define F_CPU 16000000UL        
#include <util/delay.h>

int getDistance() {
	//duration variable
	int duration = 0;
	//FRONT, TRIGGER = D0, ECHO = C0
	
	//send 10 microsecond pulse to front sensor trigger
	PORTD |= (1 << 4);
	_delay_us(10);
	PORTD &= ~(1 << 4);
		
	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 7)));

	while (PIND & (1 << 7)) {
		duration++;
		_delay_us(1);
		}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return duration / 58;
	}
		
int main(void) {
	//initialization
	int front_distance = 0;
	
	//configure front sensor detection LED to port C pin 2
	DDRC |= 1<<2;
	
	//front ultrasonic sensor initialization
	//trigger pin: PORTD PIN0
	//echo pin: PORTD PIN1
	DDRD |= (1 << 4); //set trigger pin as output
	DDRD &= ~(1 << 7); //set echo pin as input

	DDRD |= (1<<3);
	DDRD |= (1<<6);
	DDRB |= (1<<2);
	DDRB |= (1<<3);

	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		front_distance = getDistance();
		
		// if statement to check if the front distance is 15 centimeters away or less
		if (front_distance > 0 && front_distance <= 3) {
			//then stop car
			//OCR2B = 0;
			//OCR2B = (uint8_t)DUTY_CYCLE * 255;
			//and turn on detection LED accordingly
			PORTD &= ~(1<<3);
			PORTD &= ~(1<<6);
			PORTB &= ~(1<<2);
			PORTB &= ~(1<<3);
			PORTC |= 1<<2;
		}
		
		else {
			//else, start car, turn off any LED detection
			//OCR2B = (uint8_t)DUTY_CYCLE * 255;
			PORTD |= (1<<3);
			PORTD |= (1<<6);
			PORTB |= (1<<2);
			PORTB |= (1<<3);
			
			PORTC &= ~(1<<2);
			}
		_delay_us(10); //10탎 delay between readings
	}
	return 0;
}

/*

#include <avr/io.h>
#define F_CPU 16000000UL
#define PWM_FREQUENCY 1000
#define DUTY_CYCLE 0.8
#include <util/delay.h>

int getDistance() {
	//duration variable
	int duration = 0;
	//FRONT, TRIGGER = D0, ECHO = C0
	
	//send 10 microsecond pulse to front sensor trigger
	PORTD |= (1 << 0);
	_delay_us(10);
	PORTD &= ~(1 << 0);
	
	//wait for echo pin to receive the pulse
	while (!(PIND & (1 << 1)));

	while (PIND & (1 << 1)) {
		duration++;
		_delay_us(1);
	}

	//calculate distance in cm: duration / 58 (for 1탎 per round trip count at 340m/s (speed of sound) )
	return duration / 58;
}

void motorPWMInit() {
	//set PD3 (OC2B), PD5 (OC0B), PD6 (OC0A), and PB3 (OC2A) as outputs
	DDRD |= (1 << 3);
	DDRD |= (1 << 5);
	DDRD |= (1 << 6);
	DDRB |= (1 << 3);

	//configure Timer 0 for Fast PWM on PD6 (OC0A) and PD5 (OC0B)
	//TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1); // Fast PWM mode, and clear OC0A on compare match, set on BOTTOM, and clear OC0B on compare match, set on BOTTOM
	//TCCR0B = (1 << CS01);	//use prescaler: 8

	//initalize speed of wheels to 0
	//OCR0A = 0;    // PD6 (OC0A)
	//OCR0B = 0;    // PD5 (OC0B)

	//Configure Timer 2 for Fast PWM on PB3 (OC2A) and PD3 (OC2B)
	//TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << COM2A1) | (1 << COM2B1);  // Fast PWM mode, and clear OC2A on compare matc set on BOTTOM, and Clear OC2B on compare match, set on BOTTOM
	//TCCR2B = (1 << CS21);	//use prescaler of 8

	// initialize speed of wheels to 0
	//	OCR2A = 0;    // PB3 (OC2A)
	//OCR2B = (uint8_t)DUTY_CYCLE * 255;
	//OCR2B = 0;    // PD3 (OC2B)
	return;
}

int main(void) {
	//initialization
	
	int front_distance = 0;
	
	//configure front sensor detection LED to port C pin 2
	DDRC |= 1<<2;
	
	//front ultrasonic sensor initialization
	//trigger pin: PORTD PIN7
	//echo pin: PORTC PIN3
	DDRD |= (1 << 0); //set trigger pin as output
	DDRD &= ~(1 << 1); //set echo pin as input

	//PWM initialization
	motorPWMInit();
	
	while (1) {
		//at each instance of while loop, find the current distance to any object from the 3 sensors
		front_distance = getDistance(7,0);
		
		// if statement to check if the front distance is 15 centimeters away or less
		if (front_distance > 0 && front_distance <= 3) {
			//then stop car
			//OCR2B = 0;
			//OCR2B = (uint8_t)DUTY_CYCLE * 255;
			//and turn on detection LED accordingly
			PORTD &= ~(1<<3);
			PORTD &= ~(1<<5);
			PORTD &= ~(1<<6);
			PORTB &= ~(1<<3);
			PORTC |= 1<<2;
		}
		
		else {
			//else, start car, turn off any LED detection
			//OCR2B = (uint8_t)DUTY_CYCLE * 255;
			PORTD |= (1<<3);
			PORTD |= (1<<5);
			PORTD |= (1<<6);
			PORTB |= (1<<3);
			
			PORTC &= ~(1<<2);
		}
		_delay_us(10); //10탎 delay between readings
	}
	return 0;
}*/
