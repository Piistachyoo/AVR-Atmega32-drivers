/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EXTI_config.h                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef EXTI_EXTI_CONFIG_H_
#define EXTI_EXTI_CONFIG_H_

/* Section : Includes */

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	MODE_LOW_LEVEL,
	MODE_LOGICAL_CHANGE,
	MODE_FALLING_EDGE,
	MODE_RISING_EDGE
}enu_EXTI_MODES;

typedef enum{
	INT0,
	INT1,
	INT2
}enu_EXTI;

/* Section : Function Declarations */

#endif /* EXTI_EXTI_CONFIG_H_ */
