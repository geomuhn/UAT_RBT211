
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */
#include <avr/interrupt.h>					/* Functions add interrupts */





int main(void)
{
	//Define any variables here
	uint8_t brightness;
	//uint16_t Max_pwm_value;
	
	
	// Decided what timers may be used for Blinking the LED or Dimming LED
	// HINT one of the 3 timers will be better for blinking the LED
	
	// Timer 0 Registers
	TCCR0A |= ;
	TCCR0B |= ;
	TIMSK0 |= ;	
	OCR0A |= ;
	OCR0B |= ;
	
	// Timer 1 Registers
	TCCR1A |= ;
	TCCR1B |= ;
	TIMSK1 |= ;
	OCR1A |= ;
	OCR1B |= ;
	
	// Timer 2 Registers
	TCCR2A |= ;
	TCCR2A |= ;
	TIMSK2 |= ;
	OCR2A |= ;
	OCR2A |= ;
	
	
	// Set up INPUT AND OUTPUT PINS or PULL UP/DOWN RESISTORS
	// REMEBER even PWM pins must be set as an output or they will not work.
	
	
	
	
	
	
	sei(); // Enables Interrupts

    /* Replace with your application code */
    while (1) 
    {

		
		for (uint8_t i = 0; i <255 ; i++ )
		{
		
			_delay_ms(10);
		}
		for (/* INSERT CONDITION */)
		{
			
			_delay_ms(10);
		}
		 
    }
	return(0);
}

ISR(/* INSERT TIMER INTERUPT TYPE */){
	
	// Turn on LED at half brightness
	
	
}