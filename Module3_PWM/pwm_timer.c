/*
 * PWM_timer.c
 *
 * Created: 5/18/2023 10:06:26 AM
 * Author : george muhn
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include "USART.h"



int main(void)
{
	uint8_t brightness;
	uint16_t Max_pwm_value;
	// Timer 0 A,B
	
	TCCR0A = 0b00000000;
	TCCR0B = 0b00000000;
	// Timer 1 A,B
	TCCR1A |= (1 << WGM10);                      /* Fast PWM mode, 8-bit */
	TCCR1B |= (1 << WGM12);                       /* Fast PWM mode, pt.2 */
	TCCR1B |= (1 << CS10);
	//TCCR1B |= (1 << CS11);
	TCCR1B |= (1 << CS12);                 /* PWM Freq = F_CPU/8/256 */
	TCCR1A |= (1 << COM1A1);                      /* PWM output on OCR1A */
	TCCR1A |= (1 << COM1B1);                      /* PWM output on OCR1B */
	 // Timer 2 8 Bit timer
	TCCR2A |= (1 << WGM20);                             /* Fast PWM mode */
	TCCR2A |= (1 << WGM21);                       /* Fast PWM mode, pt.2 */
	//TCCR2B |= (1 << CS21); 
	TCCR2B |= (1 << CS20); 
	//TCCR2B |= (1 << CS21);                     /* PWM Freq = F_CPU/8/256 */
	TCCR2A |= (1 << COM2A1);                      /* PWM output on OCR2A */
	
	DDRB |= (1 << PB2);
	DDRB |= (1 << PB1);
	DDRB |= (1 << PB3);

    /* Replace with your application code */
    while (1) 
    {
		Max_pwm_value = 255;
		
		//OCR2A = 255;
		//OCR1A = 255;
		
		for (uint8_t i = 0; i <Max_pwm_value ; i++ )
		{
			brightness = i;
			//OCR2A = brightness;
			OCR1B = brightness;
			//OCR1A = brightness;
			_delay_ms(10);
		}
		for (uint8_t i = Max_pwm_value; i > 0 ; i-- )
		{
			brightness = i;
			//OCR2A = brightness;
			OCR1B = brightness;
			//OCR1A = brightness;
			_delay_ms(10);
		}
		 
    }
	return(0);
}

