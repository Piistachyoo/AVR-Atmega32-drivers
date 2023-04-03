/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EXTI_program.c                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "EXTI_interface.h"

void EXTI_vEnableEXTI(const EXTI_cfg *INTx){
	switch(INTx->INTx){
	case INT0:
		if(INTx->INTx_MODE == MODE_LOW_LEVEL){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT0_M) | MCUCR_INT0_LOW;
			SET_BIT(GICR_REG, GICR_INT0);
		}
		else if(INTx->INTx_MODE == MODE_LOGICAL_CHANGE){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT0_M) | MCUCR_INT0_LOGICAL;
			SET_BIT(GICR_REG, GICR_INT0);
		}
		else if(INTx->INTx_MODE == MODE_FALLING_EDGE){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT0_M) | MCUCR_INT0_FALLING;
			SET_BIT(GICR_REG, GICR_INT0);
		}
		else if(INTx->INTx_MODE == MODE_RISING_EDGE){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT0_M) | MCUCR_INT0_RISING;
			SET_BIT(GICR_REG, GICR_INT0);
		}
		else{ /* Do Nothing */ }
		break;
	case INT1:
		if(INTx->INTx_MODE == MODE_LOW_LEVEL){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT1_M) | MCUCR_INT1_LOW;
			SET_BIT(GICR_REG, GICR_INT1);
		}
		else if(INTx->INTx_MODE == MODE_LOGICAL_CHANGE){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT1_M) | MCUCR_INT1_LOGICAL;
			SET_BIT(GICR_REG, GICR_INT1);
		}
		else if(INTx->INTx_MODE == MODE_FALLING_EDGE){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT1_M) | MCUCR_INT1_FALLING;
			SET_BIT(GICR_REG, GICR_INT1);
		}
		else if(INTx->INTx_MODE == MODE_RISING_EDGE){
			MCUCR_REG = (MCUCR_REG & MCUCR_INT1_M) | MCUCR_INT1_RISING;
			SET_BIT(GICR_REG, GICR_INT1);
		}
		else{ /* Do Nothing */ }
		break;
	case INT2:
		if(INTx->INTx_MODE == MODE_FALLING_EDGE){
			MCUCSR_REG = (MCUCSR_REG & MCUCSR_INT2_M) | MCUCSR_INT2_FALLING;
			SET_BIT(GICR_REG, GICR_INT2);
		}
		else if(INTx->INTx_MODE == MODE_RISING_EDGE){
			MCUCSR_REG = (MCUCSR_REG & MCUCSR_INT2_M) | MCUCSR_INT2_RISING;
			SET_BIT(GICR_REG, GICR_INT2);
		}
		else{ /* Do Nothing */ }
		break;
	default: /* Do Nothing */ break;
	}
}

void EXTI_vDisableEXTI(const EXTI_cfg *INTx){
	switch(INTx->INTx){
	case INT0:
		CLR_BIT(GICR_REG, GICR_INT0);
		break;
	case INT1:
		CLR_BIT(GICR_REG, GICR_INT1);
		break;
	case INT2:
		CLR_BIT(GICR_REG, GICR_INT2);
		break;
	}
}
