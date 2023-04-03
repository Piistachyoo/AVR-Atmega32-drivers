/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                        		          	     */
/* Date          : Feb 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/


#include "../../MCAL/ATMEGA32/ADC/ADC_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"
#include "../../MCAL/ATMEGA32/TMR/TMR_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#define F_CPU 8000000UL
/*
void main()
{
	LCD_vInit(); //LCD working on 4BIT mode connected on PORTD
	ADC_vInit(); //ADC Initialization
	TMR_vEnable(TMR0_CHNL); //Timer enabled on CTC mode channel 0
	GIE_vEnableInterrupts();
	while(1);
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u8 Local_u8TimerCounter = 0;
	Local_u8TimerCounter++;
	u16 Local_u16DigitalValue;
	if(Local_u8TimerCounter == 125)
	{
		LCD_vSendCmd(CLEAR_COMMAND);
		Local_u16DigitalValue = ADC_u16Read(ADC_SINGLE_PIN7);
		Local_u16DigitalValue = 1024 - Local_u16DigitalValue;
		Local_u16DigitalValue = (Local_u16DigitalValue * 5) / 1024;
		LCD_vDisplayNumber(Local_u16DigitalValue);
		LCD_vDisplayChar('V');
		Local_u8TimerCounter = 0;
	}
}
*/
