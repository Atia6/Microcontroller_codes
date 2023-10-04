//3 servo motor control for 2dof manipulator and gripper

#ifndef F_CPU
#define F_CPU 1000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF; //Makes Port B output

	PORTB= 0x00; // initializing

	while(1)
	{


		int i;
		//PB3 motor1, base motor
		//PB4 motor 2, arm motor
		//PB6 motor 2, gripper motor
		while(i<200)
		{
			PORTB=(1<<PB4);
			_delay_us(1500);// Motor2 Rotate to go upward
			PORTB &= ~(1<<PB4) ;
			_delay_ms(18);
			_delay_us(700);
			i++;
		}
		i=0;
		while(i<200)
		{
			PORTB=(1<<PB3);
			_delay_us(1500);  //Rotate Motor1 to 0 position
			PORTB &= ~(1<<PB3) ;
			_delay_ms(18);
			_delay_us(500);
			i++;
		}
		i = 0;

		while(i<200)
		{
			PORTB=(1<<PB6);
			_delay_us(1600);  //Rotate motor3 to an angle to open gripper
			PORTB &= ~(1<<PB6) ;
			_delay_ms(18);
			_delay_us(100);
			i++;
		}

		i = 0;

		while(i<200)
		{
			PORTB=(1<<PB4);
			_delay_us(1700);
			PORTB &= ~(1<<PB4) ; //Rotate motor2 to the position of the object to grab the object
			_delay_ms(19);
			_delay_us(600);

			i++;
		}


		i=0;
		while(i<200)
		{
			PORTB=(1<<PB6);
			_delay_us(1600);   //close gripper to grab object
			PORTB &= ~(1<<PB6) ;
			_delay_ms(18);
			_delay_us(400);
			i++;
		}
		i = 0;

		while(i<200)
		{
			PORTB=(1<<PB4);
			_delay_us(1500);// Motor2 Rotate to go upward
			PORTB &= ~(1<<PB4) ;
			_delay_ms(18);
			_delay_us(700);
			i++;
		}

		i = 0;

		while(i<200)
		{
			PORTB=(1<<PB3);
			_delay_us(1600);  //motor1 moves in another place to place the object
			PORTB &= ~(1<<PB3) ;
			_delay_ms(19);
			_delay_us(200);

			i++;
		}
		i = 0;





	}
}
