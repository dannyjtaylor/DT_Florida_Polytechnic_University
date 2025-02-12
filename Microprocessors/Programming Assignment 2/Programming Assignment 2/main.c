/*
 * Programming Assignment 2.c
 *
 * Created: 10/27/2024 11:56:00 AM
 * Author : 18639
 */ 

#include <avr/io.h>


int main(void)
{
	//data direction
    DDRD = 0xFF;
	//array to store numbers in binary so they can be displayed on seven segment
	// binary digit to 7 segment display will be DpGFEDCBA. 9th one will only turn decimal point on, indicating an error finding a 1 in the given 8-bit data item
	unsigned char positionArray[9] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b01111111};
	unsigned char value = 0xA4; //(means 10100100 in binary, output should be "2")
	//position variable to keep track of first HIGH, automatically set to 8 in case no high is found
	unsigned char position = 8;
	
	
	//for loop that serially goes through the test byte, monitors each bit and if HIGH is found, saves value of that position into position variable, and exits for loop
	for(unsigned char i = 0; i<=7; i++) {
		if((value & (1<<i)) != 0) {
			position = i;
			break;
		}
	}
	
	//sets PORTD to the corresponding position variable using the position array
	PORTD = positionArray[position]; 
	
	
	//while 1 for output
    while (1) 
    {
    }
	
	return 0;
}

