/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c												 */
/* Date          : Feb 25, 2023	                                         */
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
	DIO_vSetPinDir(PORTA, PIN7, INPUT); // connected to LDR
	DIO_vSetPinValue(PORTA, PIN7, HIGH); // pull up for LDR
	DIO_vSetPinDir(PORTA, PIN2, INPUT); // connected to potentiometer
	DIO_vSetPinDir(PORTA, PIN0, OUTPUT); // connected to LED
	ADC_vInit();
	LCD_vInit();
	u16 ADC_Value;
	u16 Voltage;
	while(1)
	{
		// Potentiometer

		// Read data from potentiometer
		ADC_Value = ADC_u16Read(ADC_SINGLE_PIN2);
		// Convert digital value to original analog value
		ADC_Value = 1023-ADC_Value;
		Voltage = (ADC_Value * 5) / 1023;
		// Display value on LCD
		LCD_vDisplayString("Volt: ");
		LCD_vDisplayNumber(Voltage);

		// LDR Sensor

		// Read data from LDR sensor
		ADC_Value = ADC_u16Read(ADC_SINGLE_PIN7);
		// Display data on LCD
		LCD_vGoToRowCol(ROW_TWO, 0);
		if((ADC_Value <= 300) && (ADC_Value >= 0))
		{
			LCD_vDisplayString("Bright Light!");
		}
		else if((ADC_Value > 300) && (ADC_Value <= 600))
		{
			LCD_vDisplayString("Light is normal!");
		}
		else if((ADC_Value > 600) && (ADC_Value <= 1023))
		{
			LCD_vDisplayString("Low Light!");
		}
		else
		{
			LCD_vDisplayString("Error in LDR Sensor!");
		}

		// Flash LED then delay
		DIO_vSetPinValue(PORTA, PIN0, HIGH);
		_delay_ms(50);
		DIO_vSetPinValue(PORTA, PIN0, LOW);
		_delay_ms(4000);

		// Clear Display
		LCD_vSendCmd(0x01);
	}
}
*/
