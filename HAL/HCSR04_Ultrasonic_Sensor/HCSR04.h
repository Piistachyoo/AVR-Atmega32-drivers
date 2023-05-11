/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : HCSR04.h                                    	     */
/* Date          : May 11, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_HCSR04_ULTRASONIC_SENSOR_HCSR04_H_
#define HAL_HCSR04_ULTRASONIC_SENSOR_HCSR04_H_

/* Section : Includes */
#include "../../MCAL/ATMEGA32/GIE/GIE_interface.h"
#include "../../MCAL/ATMEGA32/TMR/TMR_interface.h"
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
#include "../../Services/STD_TYPES/STD_TYPES.h"
#include "../../Services/BIT_MATH/BIT_MATH.h"
#include <util/delay.h>

/* Section : Macro Declarations */
#define TRIG_PORT		PORTD
#define TRIG_PIN		PIN0
#define ECHO_PORT		PORTD
#define ECHO_PIN		PIN6

#define ICU_PORT		PORTD
#define ICU_PIN			PIN6

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Function Declarations */
void HCSR04_vInit();
void HCSR04_vGet_Reading(f64 *Copy_f64Sensor_Reading);

#endif /* HAL_HCSR04_ULTRASONIC_SENSOR_HCSR04_H_ */
