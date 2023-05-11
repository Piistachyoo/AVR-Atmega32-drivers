/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : servo_program.c                                       */
/* Date          : Apr 1, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "servo_interface.h"

void SERVO_vInit(const SERVO_PWM_cfg_t *Servo_PWM){
	if(Servo_PWM != NULL){
		PWM_vInit(&(Servo_PWM->ServoPWM));
		if( (Servo_PWM->ServoPWM.PWM_TimerChannel == TIMER1_PhaseFreqICR) || (Servo_PWM->ServoPWM.PWM_TimerChannel == TIMER1_PhaseICR) || (Servo_PWM->ServoPWM.PWM_TimerChannel == TIMER1_FastICR) ){
			PWM_vSetICR(&(Servo_PWM->ServoPWM), Servo_PWM->ICR_Value);
		}
		SERVO_vChangeDirection(Servo_PWM, Servo_PWM->ServoInitialDirection);
		PWM_vStart(&(Servo_PWM->ServoPWM));
	}
}

void SERVO_vChangeDirection(const SERVO_PWM_cfg_t *Servo_PWM, enu_servoDirections Copy_enuDirection){
	switch(Copy_enuDirection){
	case SERVO_0:
		PWM_vSetOCR(&(Servo_PWM->ServoPWM), Servo_PWM->OCR_0degree_Value);
		break;
	case SERVO_90:
		PWM_vSetOCR(&(Servo_PWM->ServoPWM), Servo_PWM->OCR_90degree_Value);
		break;
	case SERVO_180:
		PWM_vSetOCR(&(Servo_PWM->ServoPWM), Servo_PWM->OCR_180degree_Value);
		break;
	default: /* Do Nothing */ break;
	}
}

void SERVO_vStart(const SERVO_PWM_cfg_t *Servo_PWM){
	PWM_vStart(&(Servo_PWM->ServoPWM));
}

void SERVO_vStop(const SERVO_PWM_cfg_t *Servo_PWM){
	PWM_vStop(&(Servo_PWM->ServoPWM));
}
