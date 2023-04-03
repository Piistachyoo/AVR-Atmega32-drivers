/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                                  	     */
/* Date          : Feb 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/*
#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/ATMEGA32/ADC/ADC_interface.h"
#include "../../MCAL/ATMEGA32/TMR/TMR_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

void main()
{
	DIO_vSetPinDir(PORTA, PIN7, INPUT); //ADC CONNECTED TO POTENTIOMETER
	DIO_vSetPinDir(PORTC, PIN0, OUTPUT); //FOR LED
	ADC_vInit();
	LCD_vInit();
	GIE_vEnableInterrupts();

	while(1)
	{
		LCD_vDisplayNumber(ADC_u16Read(ADC_SINGLE_PIN7));
		_delay_ms(2000);
		LCD_vSendCmd(CLEAR_COMMAND);
	}
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{

		DIO_vSetPinValue(PORTC, PIN0, HIGH);
	_delay_ms(100);
		DIO_vSetPinValue(PORTC, PIN0, LOW);
		SET_BIT(ADCSRA_REG, ADIF_PIN);
}
*/
