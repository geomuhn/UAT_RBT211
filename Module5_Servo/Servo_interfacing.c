/*
 * Servo_test.c
 *
 * Created: 5/23/2023 9:32:55 AM
 * Author : george muhn
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


//Datasheet 102
#define PULSE_MIN	999U
#define PULSE_MAX	4799U
#define PULSE_MID	2899U

#define TOP_VALUE 39999//50 HZ 39999



int main(void)
{

	
	//TIMSK1 |= (1 << TOIE1) | (1 << OCIE1A);
	ICR1 = TOP_VALUE;
	TCCR1A |= (1 << WGM11);
	TCCR1A |= (1 << COM1A1); // Sets OC1A as direct output PB1
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11); // Prescaler of 8
	
	DDRB |= (1 << PB1);
	DDRD |= (1 << PD6);
	
	OCR1A = PULSE_MIN;
	//PORTD &= ~(1 << PD6); // LED used for debugging
	
    /* Replace with your application code */
    while (1) 
    {
		for (uint16_t i = PULSE_MIN; i < PULSE_MAX; i = i + 20)
		{
			//PORTD |= (1 << PD6);
			OCR1A = i;
			_delay_ms(10);
			
		
		}
		
		for (uint16_t i = PULSE_MAX; i > PULSE_MIN; i = i - 20)
		{
			//PORTD &= ~(1 << PD6);
			OCR1A = i;
			_delay_ms(10);
			
		}
		
 		OCR1A = PULSE_MIN;
		_delay_ms(500);
		OCR1A = PULSE_MID;
		_delay_ms(500);
		OCR1A = PULSE_MAX;
		_delay_ms(500);
		OCR1A = PULSE_MID;
		_delay_ms(500);
    }
}

