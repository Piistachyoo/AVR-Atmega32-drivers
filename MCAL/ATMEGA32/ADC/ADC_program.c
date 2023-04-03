/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : ADC_program.c                                  	     */
/* Date          : Feb 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "ADC_interface.h"
#include "../DIO/DIO_private.h"

// This function shall initialize and enable ADC
void ADC_vInit(void){

	// Condition for setting ADC voltage
#if ADC_VOLTAGE == ADC_AREF_VOLTAGE
	CLR_BIT(ADMUX_REG, REFS0_PIN);
	CLR_BIT(ADMUX_REG, REFS1_PIN);
#elif ADC_VOLTAGE == ADC_AVCC_VOLTAGE
	SET_BIT(ADMUX_REG, REFS0_PIN);
	CLR_BIT(ADMUX_REG, REFS1_PIN);
#elif ADC_VOLTAGE == ADC_INTERNAL_VOLTAGE
	SET_BIT(ADMUX_REG, REFS0_PIN);
	SET_BIT(ADMUX_REG, REFS1_PIN);
#endif

	// Condition for setting ADC interrupt enable
#if ADC_IE == ADC_ENABLE_IE
	SET_BIT(ADCSRA_REG, ADIE_PIN);
#elif ADC_IE == ADC_DISABLE_IE
	CLR_BIT(ADCSRA_REG, ADIE_PIN);
#endif


	// Condition for setting Prescaler selection
#if ADC_PRESCALER == ADC_PRE2
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE2);
#elif ADC_PRESCALER == ADC_PRE4
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE4);
#elif ADC_PRESCALER == ADC_PRE8
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE8);
#elif ADC_PRESCALER == ADC_PRE16
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE16);
#elif ADC_PRESCALER == ADC_PRE32
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE32);
#elif ADC_PRESCALER == ADC_PRE64
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE64);
#elif ADC_PRESCALER == ADC_PRE128
	ADCSRA_REG = (ADCSRA_REG&0xF8) | (ADC_PRE128);
#endif

	// Make sure ADC is set to Right adjust
	CLR_BIT(ADMUX_REG, ADLAR_PIN);

	// Enable ADC
	SET_BIT(ADCSRA_REG, ADEN_PIN);
}

// This function shall read data from the ADC channel
u16 ADC_u16Read (u8 Copy_u8Channel){

	switch(Copy_u8Channel)
	{
	case ADC_SINGLE_PIN0: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN0&0x07); break;
	case ADC_SINGLE_PIN1: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN1&0x07); break;
	case ADC_SINGLE_PIN2: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN2&0x07); break;
	case ADC_SINGLE_PIN3: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN3&0x07); break;
	case ADC_SINGLE_PIN4: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN4&0x07); break;
	case ADC_SINGLE_PIN5: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN5&0x07); break;
	case ADC_SINGLE_PIN6: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN6&0x07); break;
	case ADC_SINGLE_PIN7: ADMUX_REG = (ADMUX_REG&0xE0) | (ADC_SINGLE_PIN7&0x07); break;
	}

	// Start single conversion
	SET_BIT(ADCSRA_REG, ADSC_PIN);

	// ADC Flag clear
#if ADC_IE == ADC_DISABLE_IE
	// Wait for the conversion
	while(! (ADCSRA_REG&(1<<ADIF_PIN) ));
	CLR_BIT(ADCSRA_REG, ADIF_PIN);
#elif ADC_IE == ADC_ENABLE_IE
	while (ADCSRA_REG&(1<<ADIF_PIN));
#endif
	return ADC_DATA;
}
