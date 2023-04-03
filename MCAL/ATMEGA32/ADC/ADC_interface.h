/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : ADC_interface.h                                 	     */
/* Date          : Feb 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_ADC_ADC_INTERFACE_H_
#define MCAL_ATMEGA32_ADC_ADC_INTERFACE_H_

#include "ADC_config.h"
#include "ADC_private.h"
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"

/************** Configuration for ADC **************/
#define ADC_VOLTAGE 	ADC_AREF_VOLTAGE
#define ADC_IE			ADC_DISABLE_IE
#define ADC_PRESCALER	ADC_PRE64 // 8MHZ/64=125KHZ

// This function shall initialize and enable ADC
void ADC_vInit(void);

// This function shall read data from the ADC channel
u16 ADC_u16Read (u8);


#endif /* MCAL_ATMEGA32_ADC_ADC_INTERFACE_H_ */
