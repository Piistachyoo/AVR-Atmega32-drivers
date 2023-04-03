/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : ADC_private.h                                  	     */
/* Date          : Feb 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_ADC_ADC_PRIVATE_H_
#define MCAL_ATMEGA32_ADC_ADC_PRIVATE_H_

/********************* SETTING ADDRESSES FOR USED REGISTERS *********************/
#define ADMUX_REG 		*((volatile u8*) 0x27)
#define ADCSRA_REG 		*((volatile u8*) 0x26)
#define ADC_DATA		*((volatile u16*) 0x24)
#define SFIOR_REG		*((volatile u8*) 0x50)

/********************* SETTING MACROS FOR PIN NAMES *********************/

//ADMUX PINS
#define REFS1_PIN		7
#define REFS0_PIN		6
#define ADLAR_PIN		5

//ADCSRA PINS
#define ADEN_PIN 		7
#define ADSC_PIN		6
#define ADATE_PIN		5
#define ADIF_PIN		4
#define ADIE_PIN		3
#define ADPS2_PIN		2
#define ADPS1_PIN		1
#define ADPS0_PIN		0

#endif /* MCAL_ATMEGA32_ADC_ADC_PRIVATE_H_ */
