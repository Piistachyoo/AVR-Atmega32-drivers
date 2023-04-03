/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TMR_interface.h                                 	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_TMR_TMR_INTERFACE_H_
#define MCAL_ATMEGA32_TMR_TMR_INTERFACE_H_

/****************** FILE INCLUDES ******************/
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"
#include "TMR_private.h"
#include "TMR_config.h"

/****************** CONFIGURATION FOR TIMER ******************/
#define MODE_SELECTION			NORMAL_MODE
#define MODE_SELECTION_16BIT	CTC_OCR1A_MODE
#define TIMER_INTERRUPT			CTC_IE_ENABLE
#define OCR0_VALUE				250
#define OCR1_VALUE				0
#define OCR2_VALUE				0
#define PRE_LOAD0_VALUE			24
#define PRE_LOAD1_VALUE			0
#define PRE_LOAD2_VALUE			0
#define INVERT_OR_NOT			NON_INVERTING_MODE // NONE if no mode


/****************** FUNCTIONS PROTOTYPES ******************/

// This function is responsible for enabling timer
void TMR_vEnable(u8 Copy_u8SelectedChannel);

// This function is responsible for disabling timer
void TMR_vDisable(u8 Copy_u8SelectedChannel);

void TMR_vStartTimer1(enu_prescale_modes prescale);

// This function is responsible for setting the ICR top value
void TMR_vSetICRTopValue(u16 Copy_u16TopValue);

// This function is responsible for setting the OCR top value
void TMR_vSetOCRValue(u16 Copy_u16OCRValue);

// This function starts the timer
void TMR_vStartTimer0(enu_prescale_modes prescale);


#endif /* MCAL_ATMEGA32_TMR_TMR_INTERFACE_H_ */
