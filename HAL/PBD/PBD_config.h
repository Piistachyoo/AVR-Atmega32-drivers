/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : PBD_config.h                                  	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_PBD_PBD_CONFIG_H_
#define HAL_PBD_PBD_CONFIG_H_

typedef enum{
	MODE_PULLUP,
	MODE_PULLDOWN
}enu_button_modes;

typedef enum{
	BUTTON_PRESSED,
	BUTTON_RELEASED
}enu_button_states;

#endif /* HAL_PBD_PBD_CONFIG_H_ */
