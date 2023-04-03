/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c             		                     	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/*
#include "../../MCAL/ATMEGA32/TMR/TMR_interface.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"


void main()
{
	TMR_vEnable();
	GIE_vEnableInterrupts();
	DIO_vSetPinDir(PORTA, PIN7, OUTPUT);
	while(1)
	{

	}
}

void __vector_10(void) __attribute__((signal)); //using timer 0 channel

void __vector_10(void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter == 125)
	{
		TOG_BIT(PORTA_REG, PIN7);
		Local_u8Counter = 0;
	}
}
*/
