/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : siren.h                                  	     	 */
/* Date          : Apr 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_SIREN_SIREN_H_
#define HAL_SIREN_SIREN_H_

/* Section : Includes */
#include "../../Services/BIT_MATH/BIT_MATH.h"
#include "../../Services/STD_TYPES/STD_TYPES.h"
#include "../../MCAL/ATMEGA32/PWM/PWM_interface.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"

/* Section : Macro Declarations */
#define SIREN_TIMER0		0
#define SIREN_TIMER1		1
#define SIREN_TIMER2		2
#define SIREN_TIMER		SIREN_TIMER0
#define F_CPU			8000000UL


/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	siren_off,
	siren_on
}enu_siren_state;

/* Section : Function Declarations */
void Siren_vInit();
void SIREN_vChangeSound(u16 Copy_u16Frequency);
void SIREN_vStop();

#endif /* HAL_SIREN_SIREN_H_ */
