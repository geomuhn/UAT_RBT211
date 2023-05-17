/*
 * External_interrupts.c
 *
 * Created: 5/17/2023 8:06:03 AM
 * Author : george muhn
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL //Utilizes the 16Mhz clock onboard the arduino
#endif

#include <avr/io.h>
#include <util/delay.h>			// add this to use the delay function
#include <avr/interrupt.h>


int main(void)
{
	//Set inputs and outputs
	DDRD &= ~(1 << PD2); //Clear pin PD2 for input
	PORTD |= (1 << PD2); //Set the internal pull-up resistor
	DDRD |= (1 << PD7); //Set pin PD7 as output
	
	
	// SET UP LED FOR OUTPUT (You may use the onboard LED or an external one)
	
	//
	
	EIMSK = ; //Fill in the register
	
	EICRA = ; //Fill in the register
	
	sei();
	
    /* Replace with your application code */
    while (1) {
		
		//CREATE A BLINKING LED
		
    }
	return(0);
}
	
	ISR(INT0_vect){
		if(!(PIND & (1 << PD2))){
			
			PORTD |= (1<<PD7);
			
			
		}else if (PIND & (1 << PD2)){
			
			PORTD &= ~(1<<PD7);
			
			
		}else { //do nothing
			
		}
	}
	