/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : led_interface.h                                  	     */
/* Date          : Apr 4, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/* Section : Includes */
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"
/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	InitiallyOff,
	InitiallyOn
}enu_led_InitialState;

typedef struct{
	enu_led_InitialState	InitialStatus  	:1;
	u8						PortName		:2;
	u8 						PinNum  		:3;
}LED_cfg;
/* Section : Function Declarations */
void LED_vInit(const LED_cfg *LED);

void LED_vTurnOn(const LED_cfg *LED);

void LED_vTurnOff(const LED_cfg *LED);

void LED_vToggle(const LED_cfg *LED);

#endif /* HAL_LED_LED_INTERFACE_H_ */
