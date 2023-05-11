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
#include "../GIE/GIE_interface.h"

/****************** HELPER FUNCTIONS ******************/
#define CLEAR_ICU_FLAG()		TIFR_REG = (1<<ICF1_PIN)
#define ICU_Rising_Edge()		SET_BIT(TCCR1B_REG, ICES1)
#define ICU_Falling_Edge()		CLR_BIT(TCCR1B_REG, ICES1)

/****************** CONFIGURATION FOR TIMER ******************/


typedef struct{
	enu_TimerChannel    TMR_TimerChannel;
	enu_prescale_modes  TMR_Prescale;
	enu_TimerToggleMode TMR_ToggleMode;
	enu_TimerOCMode		TMR_OCMode;
}TMR_cfg_t;

/****************** FUNCTIONS PROTOTYPES ******************/

// This function is responsible for enabling timer
void TMR_vInit(const TMR_cfg_t *TMR);

// This function is responsible for disabling timer
void TMR_vStop(const TMR_cfg_t *TMR);

// This function is responsible for setting the ICR top value
void TMR_vSetICRValue(const TMR_cfg_t *TMR, u16 Copy_u16ICRValue);

// This function is responsible for setting the OCR top value
void TMR_vSetOCRValue(const TMR_cfg_t *TMR, u16 Copy_u16OCRValue);

// This function starts the timer
void TMR_vStartTimer(const TMR_cfg_t *TMR);


#endif /* MCAL_ATMEGA32_TMR_TMR_INTERFACE_H_ */
