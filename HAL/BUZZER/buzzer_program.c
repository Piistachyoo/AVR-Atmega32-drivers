/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : buzzer_program.c                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "buzzer_interface.h"

void BUZZER_vInit(const buzzer_cfg *PTR_BUZZER){
	DIO_vSetPinDir(PTR_BUZZER->buzzer_port, PTR_BUZZER->buzzer_pin, OUTPUT);
}

void BUZZER_vShortBeep(const buzzer_cfg *PTR_BUZZER){
	DIO_vSetPinValue(PTR_BUZZER->buzzer_port, PTR_BUZZER->buzzer_pin, HIGH);
	for(int i=0;i<20000;i++);
	DIO_vSetPinValue(PTR_BUZZER->buzzer_port, PTR_BUZZER->buzzer_pin, LOW);
}

void BUZZER_vLongBeep(const buzzer_cfg *PTR_BUZZER){
	DIO_vSetPinValue(PTR_BUZZER->buzzer_port, PTR_BUZZER->buzzer_pin, HIGH);
	for(u32 i=0;i<80000;i++);
	DIO_vSetPinValue(PTR_BUZZER->buzzer_port, PTR_BUZZER->buzzer_pin, LOW);
}
