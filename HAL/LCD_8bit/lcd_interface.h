/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : lcd_interface.h                                  	     */
/* Date          : Mar 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_



/* Section : Includes */
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include <util/delay.h>
#include "../../Services/BIT_MATH/BIT_MATH.h"
#include "../../Services/STD_TYPES/STD_TYPES.h"
#include "../LCD_8bit/lcd_config.h"
#include "../LCD_8bit/lcd_private.h"

/* Section : Macro Declarations */
#define ROW1	0
#define ROW2	1

#define ROW1_Address	0x80 // Set DDRAM address command + row 1 address
#define ROW2_Address	0xC0// Set DDRAM address command + row 2 address

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

typedef struct{
	u8 LCD_DataPort		:2;
	u8 LCD_CtrlPort		:2;
	u8 LCD_RS_PIN		:3;
	u8 LCD_RW_PIN		:3;
	u8 LCD_EN_PIN		:3;
}LCD_8bit_cfg;


/* Section : Function Declarations */
void LCD_8bit_vInit(const LCD_8bit_cfg *PTR_LCD);

void LCD_8bit_vSendCmd(const LCD_8bit_cfg *PTR_LCD, u8 Copy_u8Cmd);

void LCD_8bit_vSendChar(const LCD_8bit_cfg *PTR_LCD, u8 Copy_u8Char);

void LCD_8bit_vSendString(const LCD_8bit_cfg *PTR_LCD, u8 *Copy_u8String);

void LCD_8bit_vSendString_pos(const LCD_8bit_cfg *PTR_LCD, u8 *Copy_u8String, u8 row, u8 column);

void LCD_8bit_vSendNumber(const LCD_8bit_cfg *PTR_LCD, u16 Copy_u16Number);

void LCD_8bit_SetCursorPosition(const LCD_8bit_cfg *PTR_LCD, u8 column, u8 row);

#endif /* LCD_LCD_INTERFACE_H_ */
