/*
 * main.c
 *
 *  Created on: Feb 11, 2023
 *      Author: omarm
 */
/*
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main()
{
	DIO_vSetPinDir(PORTD, PIN0, INPUT);
	DIO_vSetPinValue(PORTD, PIN0, HIGH);
	DIO_vSetPinDir(PORTD, PIN1, OUTPUT);

	while(1)
	{
		if(DIO_u8ReadPinValue(PORTD, PIN0)==0)
		{
			DIO_vSetPinValue(PORTD, PIN1, HIGH);
		}
		else
		{
			DIO_vSetPinValue(PORTD, PIN1, LOW);
		}
	}
	return 0;
}
*/
