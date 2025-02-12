#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Define constants
#define PWM_FREQUENCY 700
#define DUTY_CYCLE 0.98
#define SLOW_DUTY_CYCLE 0.0

// Function declarations
void pwmInit(void);
int getDistance(uint8_t trigger_port, uint8_t trigger_pin, uint8_t echo_port, uint8_t echo_pin);
void setMotors(float duty_cycle);

int main(void) {
	// Initialization
	pwmInit();
	int front_distance = 0;
	int left_distance = 0;
	int right_distance = 0;
	uint8_t motor_running = 1;  // 1 = running, 0 = stopped

	// LED configuration (outputs)
	DDRC |= (1 << PC3) | (1 << PC4) | (1 << PC5);  // Front, Left, Right LEDs

	// Ultrasonic sensor configuration
	DDRD |= (1 << PD4) | (1 << PD2);  // Front and Left trigger as outputs
	DDRB |= (1 << PB0);               // Right trigger as output
	DDRC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2)); // Front, Left, Right echo as inputs

	while (1) {
		// Measure distances
		front_distance = getDistance(PORTD, PD4, PINC, PC0);
		left_distance = getDistance(PORTD, PD2, PINC, PC1);
		right_distance = getDistance(PORTB, PB0, PINC, PC2);

		// Front obstacle handling
		if (front_distance > 0 && front_distance <= 30) {
			if (motor_running) {
				motor_running = 0;
				setMotors(SLOW_DUTY_CYCLE);  // Stop motors
				PORTC |= (1 << PC3);        // Front LED on
			}
			} else {
			if (!motor_running) {
				motor_running = 1;
				setMotors(DUTY_CYCLE);  // Start motors
				PORTC &= ~(1 << PC3);  // Front LED off
			}
		}

		// Left obstacle handling
		if (left_distance > 0 && left_distance <= 10) {
			PORTC |= (1 << PC4);  //left LED on
			}
			else {
			PORTC &= ~(1 << PC4); // Left LED off
		}

		// Right obstacle handling
		if (right_distance > 0 && right_distance <= 10) {
			PORTC |= (1 << PC5);  // Right LED on
			} else {
			PORTC &= ~(1 << PC5); // Right LED off
		}

		_delay_us(10);  // Short delay between loops
	}

	return 0;
}

// PWM initialization
void pwmInit(void) {
	// Set PWM pins as outputs
	DDRD |= (1 << PD3) | (1 << PD5) | (1 << PD6);
	DDRB |= (1 << PB3);

	// Timer 0: Fast PWM, non-inverting, prescaler = 8
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1);
	TCCR0B = (1 << CS01);

	// Timer 2: Fast PWM, non-inverting, prescaler = 8
	TCCR2A = (1 << WGM20) | (1 << WGM21) | (1 << COM2A1) | (1 << COM2B1);
	TCCR2B = (1 << CS21);

	// Set initial duty cycle
	setMotors(DUTY_CYCLE);
}

// Set duty cycle for all motors
void setMotors(float duty_cycle) {
	OCR0A = (uint8_t)(duty_cycle * 255);
	OCR0B = (uint8_t)(duty_cycle * 255);
	OCR2A = (uint8_t)(duty_cycle * 255);
	OCR2B = (uint8_t)(duty_cycle * 255);
}

// Ultrasonic distance measurement function
int getDistance(uint8_t trigger_port, uint8_t trigger_pin, uint8_t echo_port, uint8_t echo_pin) {
	int duration = 0;

	// Send 10 µs pulse to the trigger pin
	if (trigger_port == PORTD) PORTD |= (1 << trigger_pin);
	if (trigger_port == PORTB) PORTB |= (1 << trigger_pin);
	_delay_us(10);
	if (trigger_port == PORTD) PORTD &= ~(1 << trigger_pin);
	if (trigger_port == PORTB) PORTB &= ~(1 << trigger_pin);

	// Wait for echo to start
	int timeout = 30000;
	while (!(echo_port & (1 << echo_pin)) && --timeout);
	if (timeout == 0) return -1;  // Timeout occurred

	// Measure echo duration
	timeout = 30000;
	while (echo_port & (1 << echo_pin) && --timeout) {
		duration++;
		_delay_us(1);
	}
	if (timeout == 0) return -1;  // Timeout occurred

	return duration / 58;  // Convert duration to distance in cm
}
