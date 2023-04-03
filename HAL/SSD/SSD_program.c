/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : SSD_program.c                                  	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "SSD_interface.h"

//	Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, DOT
u8 SS_NumbersHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};


// This function is responsible for initializing SSD PORT
void SSD_vInit(u8 Copy_u8SSD_PORT){

	// Set SS port as OUTPUT
	DIO_vSetGroupDir(Copy_u8SSD_PORT, OUTPUT);

	// Welcome animation

	DIO_vSetGroupValue(Copy_u8SSD_PORT, 0xFF);
	_delay_ms(250);
	DIO_vSetGroupValue(Copy_u8SSD_PORT, 0x00);
	_delay_ms(250);
	DIO_vSetGroupValue(Copy_u8SSD_PORT, 0xFF);
	_delay_ms(250);
	DIO_vSetGroupValue(Copy_u8SSD_PORT, 0x00);
	_delay_ms(250);

}

// This function is responsible for showing a number
void SSD_vShowNumber(u8 Copy_u8SSD_PORT, u8 Copy_u8Number, u8 DOT_CHECK){

	 u8 Printed_Number;

	// If use dot, set the pin
	if(DOT_CHECK == USE_DOT) { Printed_Number = SS_NumbersHex[Copy_u8Number] | 0x80; }
	else { Printed_Number = SS_NumbersHex[Copy_u8Number]; }



	DIO_vSetGroupValue(Copy_u8SSD_PORT, Printed_Number);

	/*
	switch(Copy_u8Number)
	{
	case 0: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[0]); break;
	case 1: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[1]); break;
	case 2: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[2]);	break;
	case 3: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[3]);	break;
	case 4: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[4]);	break;
	case 5: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[5]);	break;
	case 6: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[6]);	break;
	case 7: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[7]);	break;
	case 8: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[8]);	break;
	case 9: DIO_vSetGroupValue(SSD_PORT, SS_NumbersHex[9]);	break;
	default: 	Do Nothing  break;
	}
	*/
}
