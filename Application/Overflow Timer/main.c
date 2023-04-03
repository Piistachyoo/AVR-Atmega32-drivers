/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                                  	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
/*
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/TMR/TMR_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"

void main()
{
	DIO_vSetPinDir(PORTA, PIN7, OUTPUT);
	TMR_vEnable();
	GIE_vEnableInterrupts();
	while(1);
}

void __vector_5(void) __attribute__((signal)); //using TMR2_CHNL
void __vector_5(void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	TCNT2_REG = 256-238;
	if(Local_u8Counter == 123)
	{
		TOG_BIT(PORTA_REG, PIN7);
		Local_u8Counter = 0;
	}
}
*/
