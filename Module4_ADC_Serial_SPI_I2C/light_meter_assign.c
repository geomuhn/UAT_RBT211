/*
 *
 * Created: 5/19/2023 5:22:23 PM
 * Author : George Muhn
 */ 


#ifndef F_CPU					// if F_CPU was not defined in Project -> Properties
#define F_CPU 16000000UL			// define it now as 16 GHz unsigned long
#endif

#include <avr/io.h>				// this is always included in AVR programs
#include "util/delay.h"



///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
	
	DDRD = ;				// set Port D pins for output
	DDRB = ; // Set the first two of pins of port D as output. This is because pins 0 and 1 have pull up resistors and not generally used as outputs.

	ADMUX = ;
	

	ADCSRA = ;
	

	ADCSRB = ;
	
	ADCSRA |= (1 << ADSC);		// start ADC
	
	while (1) {									// begin infinite loop
		PORTD = ADCH;							// assign contents of ADC high register to Port D pins
		PORTB = ADCH;

		//or
		//printWord(ADCH); // Will print the Decimal number

	}
	return(0);					// should never get here, this is to prevent a compiler warning
}



