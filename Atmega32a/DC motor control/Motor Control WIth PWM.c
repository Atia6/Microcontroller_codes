/*
 * 4 DC motor control using pwm
 *
 * Created: 6/11/2022 7:52:49 PM
 *  Author: USER
 */



#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRD = 0b00111111;
	DDRA = 0x00;
	DDRB = 0xFF;

	OCR1AH = 0x00;
	OCR1BH = 0x00;

	TCCR1A |=(1<<COM1A1) | (1<<COM1A0) | (1<<WGM10); // Inverting mode, phase correct,8-bit
	TCCR1B |= (1<<CS11) | (1<<CS10); //prescaler 64

		 while(1)
		 {
			 if((PINA & (1<<PA7)))

		 {
			 OCR1AL=255;
			 OCR1BL=255;
			 PORTB |= (1<<PB0);
			 PORTB &=~ (1<<PB1);
			 PORTB |= (1<<PB6);
			 PORTB &= ~(1<<PB7);

		 }

	else
	{
		OCR1AH = 0x00;
		OCR1AL = 0xBF;  //Duty cycle 75%


			 PORTB |= (1<<PB0);
			 PORTB |= (1<<PB1);
			 PORTB |= (1<<PB6);
			 PORTB |= (1<<PB7);


	}

}
	}
