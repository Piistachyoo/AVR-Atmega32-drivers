/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : PBD_program.c                                  	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "PBD_interface.h"

// This function is responsible for initializing a push button
Std_ReturnType PBD_vInit(const PB_cfg *PB){
	Std_ReturnType ret = E_NOT_OK;
	if(PB != NULL){

		if(PB->PBmode == MODE_PULLUP){
			DIO_vPinInit(PB->PortName, PB->PinNum, INPUT, HIGH);
		}
		else if(PB->PBmode == MODE_PULLDOWN){
			DIO_vPinInit(PB->PortName, PB->PinNum, INPUT, LOW);
		}
		ret = E_OK;
	}
	return ret;
}

// This function is responsible for getting button state
Std_ReturnType PBD_vGetButtonState(const PB_cfg *PB, u8 *Copy_u8State){
	Std_ReturnType ret = E_NOT_OK;
	u8 LOCAL_Button_State;
	if(PB != NULL){
		LOCAL_Button_State = DIO_u8ReadPinValue(PB->PortName, PB->PinNum);
		switch(PB->PBmode){
		case MODE_PULLUP:
			if(LOCAL_Button_State == 0)		{ *Copy_u8State = BUTTON_PRESSED;  }
			else if(LOCAL_Button_State == 1){ *Copy_u8State = BUTTON_RELEASED; }
			else{ /* Do Nothing */ }		  break;
		case MODE_PULLDOWN:
			if(LOCAL_Button_State == 0)		{ *Copy_u8State = BUTTON_RELEASED; }
			else if(LOCAL_Button_State == 1){ *Copy_u8State = BUTTON_PRESSED;  }
			else{ /* Do Nothing */ }		  break;
		default: /* Do Nothing */ break;
		}
		ret = E_OK;
	}
	return ret;
}

