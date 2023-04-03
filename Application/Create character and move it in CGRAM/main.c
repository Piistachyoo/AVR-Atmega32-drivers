/*
#include "../../HAL/LCD/LCD_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main()
{
	u8 LOCAL_u8SpecialChar[8] =
	{
			0b00000100,
			0b00001010,
			0b00000100,
			0b00000100,
			0b00011111,
			0b00000100,
			0b00001010,
			0b00010001
	};
	LCD_vInit();
	LCD_vStoreSpecChar(LOCAL_u8SpecialChar, 0);
	LCD_vSendCmd(SET_CURSOR_LOCATION);
	u8 LOCAL_u8HorizontalPosition = 0;
	u8 LOCAL_u8VerticalPosition = 0;
	while (1)
	{
		LCD_vSendCmd(CLEAR_COMMAND);
		LCD_vGoToRowCol(ROW_ONE, 0);
		LCD_vDisplayChar(0);
		_delay_ms(250);
		while(LOCAL_u8HorizontalPosition<16)
		{
			//LCD_vSendCmd(CLEAR_COMMAND);
			LCD_vShiftDisplay(RIGHT, 1);
			LOCAL_u8HorizontalPosition++;
			_delay_ms(200);
		}
		LCD_vSendCmd(CLEAR_COMMAND);
		LCD_vGoToRowCol(ROW_TWO, 15);
		LCD_vDisplayChar(0);
		_delay_ms(250);
		while(LOCAL_u8HorizontalPosition>0)
		{
			LCD_vShiftDisplay(LEFT, 1);
			LOCAL_u8HorizontalPosition--;
			_delay_ms(200);
		}
	}
	return 0;
}
*/
