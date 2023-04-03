/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : ADC_config.h                                  	     */
/* Date          : Feb 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_ADC_ADC_CONFIG_H_
#define MCAL_ATMEGA32_ADC_ADC_CONFIG_H_

/************** voltage condition values **************/
#define ADC_AREF_VOLTAGE		0
#define ADC_AVCC_VOLTAGE		1
#define ADC_INTERNAL_VOLTAGE	2

/************** interrupt enable condition values **************/
#define ADC_ENABLE_IE			0
#define ADC_DISABLE_IE			1

/************** interrupt prescaler selection condition values **************/
#define	ADC_PRE2				1
#define	ADC_PRE4				2
#define	ADC_PRE8				3
#define	ADC_PRE16				4
#define	ADC_PRE32				5
#define	ADC_PRE64				6
#define	ADC_PRE128				7

/************** ADC pins condition values **************/
#define ADC_SINGLE_PIN0			0x00
#define ADC_SINGLE_PIN1			0x01
#define ADC_SINGLE_PIN2			0x02
#define ADC_SINGLE_PIN3			0x03
#define ADC_SINGLE_PIN4			0x04
#define ADC_SINGLE_PIN5			0x05
#define ADC_SINGLE_PIN6			0x06
#define ADC_SINGLE_PIN7			0x07


#endif /* MCAL_ATMEGA32_ADC_ADC_CONFIG_H_ */
