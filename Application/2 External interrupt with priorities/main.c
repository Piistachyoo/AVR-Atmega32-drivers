/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                            		      	     */
/* Date          : Feb 20, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
/*
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/EXTI/EXTI_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

void main(void)
{
	DIO_vSetPinDir(PORTC, PIN7, OUTPUT);
	DIO_vSetPinValue(PORTC, PIN7, HIGH);
	DIO_vSetPinDir(PORTC, PIN6, OUTPUT);
	DIO_vSetPinDir(PORTC, PIN5, OUTPUT);
	DIO_vSetPinDir(PORTD, PIN2, INPUT);
	DIO_vSetPinValue(PORTD, PIN2, HIGH);
	DIO_vSetPinDir(PORTD, PIN3, INPUT);
	DIO_vSetPinValue(PORTD, PIN3, HIGH);
	EXTI_vEnablePin(INT0_PIN);
	EXTI_vEnablePin(INT1_PIN);
	GIE_vEnableInterrupts();
	while(1)
	{
		DIO_vSetPinValue(PORTC, PIN7, HIGH);
		_delay_ms(250);
		DIO_vSetPinValue(PORTC, PIN7, LOW);
		_delay_ms(250);
	}
}

void __vector_1 () __attribute__((signal));
void __vector_1 ()
{
	DIO_vSetPinValue(PORTC, PIN6, HIGH);
	_delay_ms(250);
	DIO_vSetPinValue(PORTC, PIN6, LOW);
	_delay_ms(250);
}
void __vector_2 () __attribute__((signal));
void __vector_2 ()
{
	DIO_vSetPinValue(PORTC, PIN5, HIGH);
	_delay_ms(250);
	DIO_vSetPinValue(PORTC, PIN5, LOW);
	_delay_ms(250);
}


*/
