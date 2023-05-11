/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : led_program.c                                  	     */
/* Date          : Apr 4, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "led_interface.h"

void LED_vInit(const LED_cfg *LED){
	if(LED != NULL){
		if(LED->InitialStatus == InitiallyOn){
			DIO_vPinInit(LED->PortName, LED->PinNum, OUTPUT, HIGH);
		}
		else if(LED->InitialStatus == InitiallyOff){
			DIO_vPinInit(LED->PortName, LED->PinNum, OUTPUT, LOW);
		}
		else{ /* Do Nothing */ }
	}
	else{ /* Do Nothing */ }
}

void LED_vTurnOn(const LED_cfg *LED){
	if(LED != NULL){
		DIO_vPinInit(LED->PortName, LED->PinNum, OUTPUT, HIGH);
	}
	else{ /* Do Nothing */ }
}

void LED_vTurnOff(const LED_cfg *LED){
	if(LED != NULL){
		DIO_vPinInit(LED->PortName, LED->PinNum, OUTPUT, LOW);
	}
	else{ /* Do Nothing */ }
}

void LED_vToggle(const LED_cfg *LED){
	if(LED != NULL){
		DIO_vTogglePinValue(LED->PortName, LED->PinNum);
	}
	else{ /* Do Nothing */ }
}
