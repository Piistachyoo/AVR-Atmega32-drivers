/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : GIE_program.c                                  	     */
/* Date          : Feb 18, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "GIE_interface.h"

// This function is responsible for enabling GIE for interrupts
void GIE_vEnableInterrupts(){
	SET_BIT(SREG_REG, 7);
}

// This function is responsible for disabling GIE for interrupts
void GIE_vDisableInterrupts(){
	CLR_BIT(SREG_REG, 7);
}
