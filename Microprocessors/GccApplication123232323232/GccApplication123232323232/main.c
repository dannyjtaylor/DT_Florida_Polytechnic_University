/*
 * GccApplication123232323232.c
 *
 * Created: 10/27/2024 10:31:36 PM
 * Author : 18639
 */ 

#include <avr/io.h>


int main(void)
{
    DDRD = 0xFF;
    unsigned char positionArray[9] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b01111111};
    unsigned char value = 0x00;

    unsigned char position = 8;



    for(unsigned char i = 0; i<=7; i++) {
	    if((value & (1<<i)) != 0) {
		    position = i;
		    break;
	    }
    }


    PORTD = positionArray[position];


    
    while (1)
    {
    }

    return 0;
    
    
}

