/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : buzzer_interface.h                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef BUZZER_BUZZER_INTERFACE_H_
#define BUZZER_BUZZER_INTERFACE_H_

/* Section : Includes */
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
u8 buzzer_port :2;
u8 buzzer_pin  :3;
}buzzer_cfg;
/* Section : Function Declarations */
void BUZZER_vInit(const buzzer_cfg *PTR_BUZZER);
void BUZZER_vShortBeep(const buzzer_cfg *PTR_BUZZER);
void BUZZER_vLongBeep(const buzzer_cfg *PTR_BUZZER);

#endif /* BUZZER_BUZZER_INTERFACE_H_ */
