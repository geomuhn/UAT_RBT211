

//Always include the F_CPU to reduce errors
#ifndef F_CPU					// if F_CPU was not defined in Project -> Properties
#define F_CPU 16000000UL			// define it now as 16 MHz unsigned long
#endif

#include <avr/io.h>				// this is always included in AVR programs
#include <avr/interrupt.h>		//Required Libraries for interupt

// You may define your pins ports and DDR here 
// EXAMPLE
// #define LED0 PB0 // This will set variable LED0 as PB0

int main(void)
{
	//SET UP PINS INPUT, OUTPUTS AND PULL UP/DOWN RESISTORS HERE:
	
	
	
	//
	
	//Timer Set up HINT: NOT ALL TIMERS WILL BE USED AND MAY BE REMOVED, COMMENTED LEFT as 0
	
	//Provided Timer 0 8bit timer Registers
	TCCR0A = ; 
	TCCR0B = ;
	TIMSK0 = ;
	
	//Provided Timer 1 16bit timer registers

	TCCR1A = ;
	TCCR1B = ;
	TCCR1C = ;
	TIMSK1 = ;
	
	//Provided Timer 3 8bit timer register
	TCCR2A = ; 
	TCCR2B = ;
	TIMSK2 = ;
	
	
	// Register for Count for Timer 0
	OCR0A = ;
	
	// Register for Count for Timer 1
	OCR1A = ; 
	
	// Register for Count for Timer 2
	OCR2A = ;
	
	
	//External Interrupt Set up
	// Check which External interupt pin you want to use. 
	EICRA = ;  
	
	EIMSK = ;  
	
	
	
	sei();
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		// NO CODE SHOULD EXIST
		
    }
	
	return(0);	
}

// Timer Interrupt Code, What to do once the timer has reached its count or overflow

// Tassignment will require 2 interupt ISR() functions

	ISR(/*INSERT TYPE OF INTERUPT*/) {
		// INPUT CODE TO BLINK LED HINT: Look at the blink led assignment
	}

	
	
 	ISR(t/*INSERT TYPE OF INTERUPT*/){
 		if(/*INSERT CONDITION IF BUTTON IS PRESSED*/)){
 			// INPUT CODE TO TURN LED ON
 			
 			}else if (/*INSERT CONDITION IF BUTTON IS NOT PRESSED*/)){
 			// INPUT CODE TO TURN LED OFF
 			
 			}else { //do nothing
 			
 		}
 	}
	 
	/*TYPES OF INTERUPTS
	1. INT0_vect 
		Looks for interrupt flag on external interrupt pin 0
	2. INT1_vect 
		Looks for interrupt flag on external interrupt pin 1
	3. TIMER(0,1 or 2)_COMPA_vect
		Looks for timer comparison A count on selected timer 0,1, or 2
	4. TIMER(0,1 or 2)_COMPB_vect
		Looks for timer comparison B count on selected timer 0,1, or 2
	5. TIMER(0,1 or 2)_OVF_vect
		Looks for Overflow of timers 0 1 or 2
	
	*/
 
