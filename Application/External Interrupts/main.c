/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main2.c                		                  	     */
/* Date          : Feb 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/*
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/EXTI/EXTI_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"

void __vector_1 (void) __attribute__((signal));
void __vector_1(void)
{
	DIO_vSetPinValue(PORTD, PIN0, LOW);
}

void main()
{
	// Set pin 0 in PortD (LED) as output
	DIO_vSetPinDir(PORTD, PIN0, OUTPUT);

	// Set pin 2 in PORTD (Push button) as input
	DIO_vSetPinDir(PORTD, PIN2, INPUT);

	// Activate pull-up resistor for pin2 PORTD
	DIO_vSetPinValue(PORTD, PIN2, HIGH);

	// initialize external interrupt 0
	EXTI_vEnablePin(INT0_PIN);

	// Enable interrupts in MCU (GIE)
	GIE_vEnableInterrupts();

	while(1)
	{
		DIO_vSetPinValue(PORTD, PIN0, HIGH);
	}
}
*/