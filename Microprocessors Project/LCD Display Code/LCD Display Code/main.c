/*
 * LCD Display Code.c
 *
 
 
 
 Use LCD just for display. we have perrial one. all pins should be connected to arduino. one pin is control (set read/write), 8 pins just for data
 has data register for each
 
 Sends ASCII value into data register (DDRAM), and then displays character on LCD. (for example, 50H, 50 in hex, is letter P)
 ex: writing 01H (1) into command register, it turns display off
 2 levels, command, and data. we have 20x2
 
 
 PINS: Left to Right
 D7 D6 D5 D4 d3 d2 d1 d0 E RW RS Vee Vcc (5V) Vss (5)
 Vss - 5V
 VCC - 5V
 Vee - Control constrat of LCD ,give voltage between 0V and 5V ( ground maybe?)
 D0 - D7 - /Looks like the screen tells us. Sends and recieves data
 RW - Read/Write - set LOW to write data to LCD, set HIGH to recieve data. Usually we only write, so keep it 0 (grounded)
 E - Enable - Activate pin when you want to send or receive data from LCD. To send data, make RW low, and supply data pins to D0-D7. Apply a high to low pulse to enable pin. so SET that pin, then CLEAR that pin. H TO LOW
 RS - Register Select - RS = 1, when you send data to LCD, data is located in DATA REGISTER. RS = 0, when you send data, data is in COMMAND register.
 this stuff happens for every character you send to it
 
 
 Initialization:
	For 5x7 matrix, 8 bit operation, 0x38, 0x0E, 0x01 to send to command register.
Sending commands to LCD
	Make pins PS and R/W = 0
	Put command number on data pins
	Send high-to-low pulse to E pin to enable internal latch of LCD. Then wait 100microseconds after each command.
Send data to LCD
	Make pins RS = 1
	Put data on data pins
	Send high to low pulse to E pin to enable internal latch of LCD. Wait 100micro seconds 
 * Created: 11/22/2024 1:06:54 PM
 * Author : 18639
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	//Display H, D0-D7
	
	DDRC |= 1<<5;
	DDRC &= ~(1<<4);
	
	PORTD = 0xFF;
	
	PORTC |= 1<<5;
	PORTC &= ~(1<<4);
	PORTD = 'H';
	//can use potentiometer to make it brighter/dimmer.  	
	//LCD initialization
	
	//enable pin high to low so it knows, include delay to wait.
	PORTC |= 1<<3;
	_delay_ms(1);
	PORTC &= ~(1<<3);
	
	
    while (1) 
    {
		
    }
	return 0;
}

