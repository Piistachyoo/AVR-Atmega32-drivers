/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : SSD_interface.h                                 	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"
#include "util/delay.h"

// This function is responsible for initializing SSD PORT
void SSD_vInit(u8 Copy_u8SSD_PORT);

// This function is responsible for showing a number
void SSD_vShowNumber(u8 Copy_u8SSD_PORT,u8 Copy_u8Number, u8 DOT_CHECK);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
