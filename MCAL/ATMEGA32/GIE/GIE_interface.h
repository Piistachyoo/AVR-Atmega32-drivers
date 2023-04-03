/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : GIE_interface.h                                 	     */
/* Date          : Feb 18, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_GIE_GIE_INTERFACE_H_
#define MCAL_ATMEGA32_GIE_GIE_INTERFACE_H_

/********************* FILE INCLUDES *********************/
#include "GIE_config.h"
#include "GIE_private.h"
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"

/********************* FUNCTION PROTOTYPES *********************/

// This function is responsible for enabling GIE for interrupts
void GIE_vEnableInterrupts();

// This function is responsible for disabling GIE for interrupts
void GIE_vDisableInterrupts();

#endif /* MCAL_ATMEGA32_GIE_GIE_INTERFACE_H_ */
