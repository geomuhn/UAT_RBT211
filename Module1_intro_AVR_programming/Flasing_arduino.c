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
	DDRB |= (1<<PB5); //Sets only pin 13 as an output = 00100000
    /* Replace with your application code */
    while (1) {
		PORTB |= (1<<PB5);
    }
}

