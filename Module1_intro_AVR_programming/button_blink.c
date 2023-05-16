/*
 * Flasing_arduino.c
 *
 * Created: 5/16/2023 1:23:43 PM
 * Author : George Muhn
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>


int main(void)
{
	DDRB &= ~(1 << PB4); //Sets pin 12 as an input without disturbing other bits 11101111 -> 00100000
	
	PORTB |= (1 << PB4); // Sets internal pull up resistor.
	
	DDRB |= (1 << PB5); //Sets only pin 13 as an output = 00100000
	
	
    while (1) 
	{
	    if (!(PINB & (1 << PB4))){ //Checks to see if the pin 12 or PINB4 is LOW or Clear
		    PORTB |= (1 << PB5);
		        
		    } else if (PINB & (1 << PB4)){ //Checks to see if the pin 12 or PINB4 is HIGH or Set
		    PORTB &= ~(1 << PB5);
			
		        
			}else{
				//Leave empty
			}
    }
}

