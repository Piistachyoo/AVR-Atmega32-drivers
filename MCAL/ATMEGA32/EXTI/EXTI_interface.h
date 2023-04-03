/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EXTI_interface.h                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

/* Section : Includes */
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"


/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	enu_EXTI		INTx;
	enu_EXTI_MODES	INTx_MODE;
}EXTI_cfg;
/* Section : Function Declarations */
void EXTI_vEnableEXTI(const EXTI_cfg *INTx);

void EXTI_vDisableEXTI(const EXTI_cfg *INTx);

#endif /* EXTI_EXTI_INTERFACE_H_ */
