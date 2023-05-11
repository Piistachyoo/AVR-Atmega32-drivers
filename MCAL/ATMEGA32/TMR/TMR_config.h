/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TMR_config.h                                  	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_TMR_TMR_CONFIG_H_
#define MCAL_ATMEGA32_TMR_TMR_CONFIG_H_

#define FLAG_ON		1
#define FLAG_OFF	0

typedef enum{
	TIMER0_NORMAL,
	TIMER0_CTC,
	TIMER1_NORMAL,
	TIMER1_CTC_OCR,
	TIMER1_CTC_ICR,
	TIMER2_NORMAL,
	TIMER2_CTC
}enu_TimerChannel;

typedef enum{
	TMR_PRE_NO_CLK,
	TMR_PRE_0,
	TMR_PRE_8,
	TMR_PRE_64,
	TMR_PRE_256,
	TMR_PRE_1024,
	TMR_PRE_EXT_FALLING,
	TMR_PRE_EXT_RISING,
	TMR_PRE_32,
	TMR_PRE_128
}enu_prescale_modes;


typedef enum{
	TMR_OCMode,
	TMR_InterruptMode
}enu_TimerToggleMode;

typedef enum{
	OC_Disconnected,
	OC_Toggle,
	OC_Clear,
	OC_Set
}enu_TimerOCMode;



#endif /* MCAL_ATMEGA32_TMR_TMR_CONFIG_H_ */
