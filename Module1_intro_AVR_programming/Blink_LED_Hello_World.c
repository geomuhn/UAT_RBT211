/*
 * Blink_LED_Hello_World.c
 *
 * Created: 5/16/2023 3:49:52 PM
 * Author : geomu
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= (1<<PB5); //Sets only pin 13 as an output = 00100000
	/* Replace with your application code */
	while (1) {
		PORTB |= (1 << PB5);
		_delay_ms(500);
		PORTB &= ~(1 << PB5);
		_delay_ms(500);
	}
}


