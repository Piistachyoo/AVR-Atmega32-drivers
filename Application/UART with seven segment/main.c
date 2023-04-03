/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c              		                    	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
/*

#include "../../HAL/SSD/SSD_interface.h"
#include "../../MCAL/ATMEGA32/UART/UART_interface.h"

void main()
{
	u8 Data;
	SSD_vInit(PORTC);
	UART_vInit();
	while(1)
	{
		Data = UART_u8ReceiveData();
		if( (Data >= '0') && (Data <= '9') )
		{
			SSD_vShowNumber(PORTC, Data-48, NO_DOT);
		}
		UART_vTransmitData(Data);

	}
}
*/
