/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c               		                   	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/*

#include "../../MCAL/ATMEGA32/ADC/ADC_interface.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

void main(void)
{
	LCD_vInit();
	DIO_vSetPinDir(PORTA, PIN7, INPUT);
//	DIO_vSetPinValue(PORTA, PIN7, HIGH);
	ADC_vInit();
	u16 ADC_Reading, Temp_Value;
	while(1)
	{
		ADC_Reading = ADC_u16Read(ADC_SINGLE_PIN7);
//		ADC_Reading = 1023-ADC_Reading;
		Temp_Value = (ADC_Reading* (5000UL))/1023;
		LCD_vDisplayString("Temp: ");
		LCD_vDisplayNumber(Temp_Value/10);
		_delay_ms(500);
		LCD_vSendCmd(CLEAR_COMMAND);
	}
}

*/
