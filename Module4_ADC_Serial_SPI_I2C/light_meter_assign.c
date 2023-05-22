/*
 *
 * Created: 5/19/2023 5:22:23 PM
 * Author : George Muhn
 */ 


#ifndef F_CPU					// if F_CPU was not defined in Project -> Properties
#define F_CPU 1000000UL			// define it now as 1 GHz unsigned long
#endif

#include <avr/io.h>				// this is always included in AVR programs
#include "util/delay.h"

#include "USART.h" // This file requires the USART.c and USART.h files to run

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
	
	DDRD = 0xFF;				// set Port D pins for output
	DDRB = 0b00000011; // Set the first two of pins of port D as output. This is because pins 0 and 1 have pull up resistors and not generally used as outputs.
	
	initUSART();
	printString("USART Initiated\r\n");  
    /*
	ADMUX - ADC Multiplexer Selection Register
	
	bit          7           6          5         4        3         2          1          0
	name       REFS1       REFS0      ADLAR       -       MUX3      MUX2       MUX1       MUX0
	set to       0           1          1         0        0         1          0          1
	
	REFS1 = 0    use AVCC for reference voltage
	REFS0 = 1
	
	ADLAR = 1    left justify ADC result in ADCH/ADCL
	
	bit 4 = 0
	
	MUX3 = 0     use PC0/ADC0 
	MUX2 = 0
	MUX1 = 0
	MUX0 = 0
	*/
	ADMUX = 0b01100000;
	
	/*
	ADCSRA - ADC Control and Status Register A
	
	bit          7           6            5          4          3            2           1           0
	name        ADEN        ADSC        ADATE       ADIF       ADIE        ADPS2       ADPS1       ADPS0
	set to       1           0            1          0          0            0           1           1
	
	ADEN = 1     enable ADC
	ADSC = 0     don't start ADC yet
	ADATE = 1    enable ADC auto trigger (i.e. use free running mode)
	ADIF = 0     don't set ADC interrupt flag
	ADIE = 0     don't set ADC interrupt enable
	
	ADPS2 = 1
	ADPS1 = 0    0 MHz clock / 16 = 1Mhz ADC clock
	ADPS0 = 0
	*/
	ADCSRA = 0b10100100;
	
	/*
	ADCSRB - ADC Control and Status Register B
	
	bit         7           6           5           4           3         2           1           0
	name        -          ACME         -           -           -       ADTS2       ADTS1       ADTS0
	set to      0           0           0           0           0         0           0           0
	
	bit 7 = 0
	ACME = 0     don't enable analog comparator multiplexer
	bit 5 = 0
	bit 4 = 0
	bit 3 = 0
	ADTS2 = 0
	ADTS1 = 0    free running mode
	ADTS0 = 0
	*/
	ADCSRB = 0b00000000;
	
	ADCSRA |= (1 << ADSC);		// start ADC
	
	while (1) {									// begin infinite loop
		PORTD = ADCH;							// assign contents of ADC high register to Port D pins
		PORTB = ADCH;
		printBinaryByte(ADCH); // Will print the binary number
		//or
		//printWord(ADCH); // Will print the Decimal number

	}
	return(0);					// should never get here, this is to prevent a compiler warning
}



