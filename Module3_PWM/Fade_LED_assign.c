/*
This one WORKS! KEEP IT!
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define MAX_PWM 255
#define HALF_PWM 127
#define MIN_PWM 0
#define QUARTER_PWM 64  // 25% of max brightness

int main(void)
{
	// Set PD6 (OC0A) and PD5 (OC0B) as outputs
	DDRD |= (1 << PORTD6);
	DDRD |= (1 << PORTD5);

	// Set PB5 to low
	DDRB |= (1 << PORTB5);
	PORTB &= ~(1 << PORTB5);

	// Set Timer0 for Fast PWM mode and normal port operation, clear OC0A/OC0B on compare match
	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);

	// Set prescaler to 64 and start the timer
	TCCR0B = (1 << CS01) | (1 << CS00);

	while (1)
	{
		// Fade in PD6 to half brightness
		for (uint8_t i = MIN_PWM; i < HALF_PWM; i++)
		{
			OCR0A = i;  // Set the value for OC0A (PD6) PWM duty cycle
			_delay_ms(2);
		}

		// Fade out PD6
		for (uint8_t i = HALF_PWM; i > MIN_PWM; i--)
		{
			OCR0A = i;  // Set the value for OC0A (PD6) PWM duty cycle
			_delay_ms(2);
		}

		// Fade in PD5 to full brightness
		for (uint8_t i = MIN_PWM; i < MAX_PWM; i++)
		{
			OCR0B = i;  // Set the value for OC0B (PD5) PWM duty cycle
			_delay_ms(2);
		}

		// Fade out PD5
		for (uint8_t i = MAX_PWM; i > MIN_PWM; i--)
		{
			OCR0B = i;  // Set the value for OC0B (PD5) PWM duty cycle
			_delay_ms(2);
		}
	}

	return 0;
}
