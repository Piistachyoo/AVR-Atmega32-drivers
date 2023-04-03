/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main3.c                      	            	     */
/* Date          : Feb 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/*
#include "../../MCAL/ATMEGA32/EXTI/EXTI_interface.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL
u8 flag = 0;

void main()
{
	DIO_vSetGroupDir(PORTA, OUTPUT);
	DIO_vSetPinDir(PORTD, PIN2, INPUT);
	DIO_vSetPinValue(PORTD, PIN2, HIGH);
	EXTI_vEnablePin(INT0_PIN);
	GIE_vEnableInterrupts();
	while(1)
	{

		DIO_vSetPinValue(PORTA, PIN0, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN0, LOW);
		DIO_vSetPinValue(PORTA, PIN1, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN1, LOW);
		DIO_vSetPinValue(PORTA, PIN2, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN2, LOW);
		DIO_vSetPinValue(PORTA, PIN3, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN3, LOW);
		DIO_vSetPinValue(PORTA, PIN4, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN4, LOW);
		DIO_vSetPinValue(PORTA, PIN5, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN5, LOW);
		DIO_vSetPinValue(PORTA, PIN6, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN6, LOW);
		DIO_vSetPinValue(PORTA, PIN7, HIGH);
		_delay_ms(150);
		if (flag==1)
		{
			flag=0;
			continue;
		}
		DIO_vSetPinValue(PORTA, PIN7, LOW);

		for(int i=0;i<7;i++)
		{
			DIO_vSetGroupValue(PORTA, 0x01);
			//shift right by every iteration
			//if i=6 reset
			//if flag = 1 reset
		}
	}
}

void __vector_1(void)	__attribute__((signal));
void __vector_1(void)
{
	DIO_vSetGroupValue(PORTA, 0xFF);
	_delay_ms(150);
	DIO_vSetGroupValue(PORTA, 0x00);
	_delay_ms(150);
	DIO_vSetGroupValue(PORTA, 0xFF);
	_delay_ms(150);
	DIO_vSetGroupValue(PORTA, 0x00);
	_delay_ms(150);
	DIO_vSetGroupValue(PORTA, 0xFF);
	_delay_ms(150);
	DIO_vSetGroupValue(PORTA, 0x00);
	_delay_ms(150);
	flag = 1;
}
*/
