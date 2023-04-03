/*
 * main.c
 *
 *  Created on: Jan 28, 2023
 *      Author: omarm
 */
/*
#include "../../HAL/LCD/LCD_interface.h"

void main(void)
{
	LCD_vInit();
	u8 Local_u8ASpecChar[8] =
	{
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000111,
			0b00001000,
			0b00010000,
			0b00000000
	}; //ر

	u8 Local_u8ASpecChar2[8] =
	{
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00011111,
			0b00001010,
			0b00000100,
			0b00000000
	}; //م

	u8 Local_u8ASpecChar3[8] =
	{
			0b00000000,
			0b00000000,
			0b00000111,
			0b00000100,
			0b00011111,
			0b00000000,
			0b00000000,
			0b00000000
	}; //ع

	u8 Local_u8ASpecChar4[8] =
	{
			0b00000000,
			0b00000000,
			0b00001100,
			0b00000010,
			0b00011111,
			0b00000000,
			0b00000000,
			0b00000000
	};//ح

	u8 Local_u8ASpecChar5[8] =
	{
			0b00000000,
			0b00000000,
			0b00000010,
			0b00000010,
			0b00001111,
			0b00000000,
			0b00000000,
			0b00000000
	};//د
	LCD_vStoreSpecChar(Local_u8ASpecChar, 0);  //ر
	LCD_vStoreSpecChar(Local_u8ASpecChar2, 1); //م
	LCD_vStoreSpecChar(Local_u8ASpecChar3, 2); //ع
	LCD_vStoreSpecChar(Local_u8ASpecChar4, 3); //ح
	LCD_vStoreSpecChar(Local_u8ASpecChar5, 4); //د
	LCD_vSendCmd(SET_CURSOR_LOCATION);
	LCD_vDisplayChar(4);
	LCD_vDisplayChar(1);
	LCD_vDisplayChar(3);
	LCD_vDisplayChar(1);
	LCD_vDisplayChar(32);
	LCD_vDisplayChar(0);
	LCD_vDisplayChar(1);
	LCD_vDisplayChar(2);
	//{ 0b00000000, 0b00000000, 0b00000111, 0b00000100, 0b00011111, 0b00000000, 0b00000000, 0b00000000 } //ع
	while(1)
	{

	}

}

*/
