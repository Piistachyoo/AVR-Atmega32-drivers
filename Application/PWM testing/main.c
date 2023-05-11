/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                                  	     */
/* Date          : Feb 28, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
/*
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/ADC/ADC_interface.h"
#include "../../MCAL/ATMEGA32/TMR/TMR_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"
#include <util/delay.h>


void main()
{
	DIO_vSetPinDir(PORTD, PIN5, OUTPUT); //PORTD5 connected to LED
	DIO_vSetPinDir(PORTC, PIN7, OUTPUT); //PORTC7 connected to LED
	DIO_vSetPinValue(PORTC, PIN7, HIGH); //SET Reference LED to HIGH
	TMR_vSetICRTopValue(20000);
	TMR_vEnable(TMR1_CHNL); //Timer enable for PWM
	TMR_vSetOCRValue(1500);//0
	_delay_ms(2000);
	TMR_vSetOCRValue(2000);//90
	_delay_ms(2000);
	TMR_vSetOCRValue(2500);//90
	_delay_ms(2000);
	TMR_vSetOCRValue(3000);//90
	_delay_ms(2000);
	TMR_vSetOCRValue(2500);//90
	_delay_ms(2000);
	TMR_vSetOCRValue(2000);//90
	_delay_ms(2000);

	TMR_vSetOCRValue(1500);//180
	_delay_ms(2000);
	TMR_vSetOCRValue(1000);//270
	_delay_ms(2000);
	TMR_vSetOCRValue(500);//360
	_delay_ms(2000);
	TMR_vSetOCRValue(4000);//?
	_delay_ms(2000);

	while(1)
	{
		TMR_vSetOCRValue(2500);
		_delay_ms(1000);
		TMR_vSetOCRValue(500);
		_delay_ms(1000);
	}
}

*/
