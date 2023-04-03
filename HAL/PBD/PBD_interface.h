/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : PBD_interface.h                                 	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_PBD_PBD_INTERFACE_H_
#define HAL_PBD_PBD_INTERFACE_H_

#include "PBD_config.h"
#include "PBD_private.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"

typedef struct{
	enu_button_modes	PBmode  :1;
	u8					PortName:2;
	u8 					PinNum  :3;
}PB_cfg;

// This function is responsible for initializing a push button
Std_ReturnType PBD_vInit(const PB_cfg *PB);

// This function is responsible for getting button state
Std_ReturnType PBD_vGetButtonState(const PB_cfg *PB, u8 *Copy_u8State);

#endif /* HAL_PBD_PBD_INTERFACE_H_ */
