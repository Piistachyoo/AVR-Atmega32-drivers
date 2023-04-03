/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TMR_program.c                                  	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/******************  ******************/

#include "TMR_interface.h"
#include "TMR_config.h"

// This function is responsible for enabling timer
void TMR_vEnable(u8 Copy_u8SelectedChannel)
{
	switch(Copy_u8SelectedChannel)
	{
	case TMR0_CHNL:
		//Enable/Disable interrupt
#if TIMER_INTERRUPT == CTC_IE_ENABLE
		TIMSK_REG = (TIMSK_REG&0xFC) | 2;
#elif TIMER_INTERRUPT == TOF_IE_ENABLE
		TIMSK_REG = (TIMSK_REG&0xFC) | 1;
#elif TIMER_INTERRUPT == TIE_DISABLE
		TIMSK_REG = TIMSK_REG&0xFC;
#endif
		// Select timer mode
#if MODE_SELECTION == NORMAL_MODE
		CLR_BIT(TCCR0_REG, WGM00_PIN);
		CLR_BIT(TCCR0_REG, WGM01_PIN);
		TCNT0_REG = PRE_LOAD0_VALUE;
#elif MODE_SELECTION == PWM_MODE
		SET_BIT(TCCR0_REG, WGM00_PIN);
		CLR_BIT(TCCR0_REG, WGM01_PIN);
#elif MODE_SELECTION == CTC_MODE
		CLR_BIT(TCCR0_REG, WGM00_PIN);
		SET_BIT(TCCR0_REG, WGM01_PIN);
		OCR0_REG = OCR0_VALUE;
#elif MODE_SELECTION == FAST_PWM_MODE
		SET_BIT(TCCR0_REG, WGM00_PIN);
		SET_BIT(TCCR0_REG, WGM01_PIN);
#endif
		break;
	case TMR1_CHNL:
#if TIMER_INTERRUPT == CTC_IE_ENABLE
		TIMSK_REG = (TIMSK_REG&0xC3) | (1<<OCIE1A_PIN);
#elif TIMER_INTERRUPT == TOF_IE_ENABLE
		TIMSK_REG = (TIMSK_REG&0xC3) | (1<<TOIE1_PIN);
#elif TIMER_INTERRUPT == TIE_DISABLE
		TIMSK_REG = TIMSK_REG&0xC3;
#endif
		// Select timer mode
#if MODE_SELECTION_16BIT == NORMAL_16_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_8_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_9_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_10_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == CTC_OCR1A_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == FAST_PWM_8_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == FAST_PWM_9_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == FAST_PWM_10_MODE
		CLR_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_PF_ICR_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_PF_OCR1A_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_ICR1_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == PWM_OCR1A_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		CLR_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == CTC_ICR1_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		CLR_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == FAST_PWM_ICR1_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1A_REG, WGM10);
#elif MODE_SELECTION_16BIT == FAST_PWM_OCR1A_MODE
		SET_BIT(TCCR1B_REG, WGM13);
		SET_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1A_REG, WGM10);
#endif
		// Adjust inverting or non inverting mode
#if INVERT_OR_NOT == INVERTING_MODE
		SET_BIT(TCCR1A_REG, COM1A0);
		SET_BIT(TCCR1A_REG, COM1A1);
#elif INVERT_OR_NOT == NON_INVERTING_MODE
		CLR_BIT(TCCR1A_REG, COM1A0);
		SET_BIT(TCCR1A_REG, COM1A1);
#elif INVERT_OR_NOT == NONE
		CLR_BIT(TCCR1A_REG, COM1A0);
		CLR_BIT(TCCR1A_REG, COM1A1);
#endif
		break;
	case TMR2_CHNL:
		//Enable/Disable interrupt
#if TIMER_INTERRUPT == CTC_IE_ENABLE
		CLR_BIT(TIMSK_REG, TOIE2_PIN);
		SET_BIT(TIMSK_REG, OCIE2_PIN);
#elif TIMER_INTERRUPT == TOF_IE_ENABLE
		SET_BIT(TIMSK_REG, TOIE2_PIN);
		CLR_BIT(TIMSK_REG, OCIE2_PIN);
#elif TIMER_INTERRUPT == TIE_DISABLE
		TIMSK_REG = TIMSK_REG&0x3F;
#endif
		// Select timer mode
#if MODE_SELECTION == NORMAL_MODE
		CLR_BIT(TCCR2_REG, WGM20_PIN);
		CLR_BIT(TCCR2_REG, WGM21_PIN);
		TCNT2_REG = PRE_LOAD2_VALUE;
#elif MODE_SELECTION == PWM_MODE
		SET_BIT(TCCR2_REG, WGM20_PIN);
		CLR_BIT(TCCR2_REG, WGM21_PIN);
#elif MODE_SELECTION == CTC_MODE
		CLR_BIT(TCCR2_REG, WGM20_PIN);
		SET_BIT(TCCR2_REG, WGM21_PIN);
		OCR2_REG = OCR2_VALUE;
#elif MODE_SELECTION == FAST_PWM_MODE
		SET_BIT(TCCR2_REG, WGM20_PIN);
		SET_BIT(TCCR2_REG, WGM21_PIN);
#endif
		// Adjust prescaler
#if PRESCALER_SELECTION == PRE_NO_CLK
		TCCR2_REG = (TCCR2_REG&0xF8);
#elif PRESCALER_SELECTION == PRE_0
		TCCR2_REG = (TCCR2_REG&0xF8) | (1);
#elif PRESCALER_SELECTION == PRE_8
		TCCR2_REG = (TCCR2_REG&0xF8) | (2);
#elif PRESCALER_SELECTION == PRE_32
		TCCR2_REG = (TCCR2_REG&0xF8) | (3);
#elif PRESCALER_SELECTION == PRE_64
		TCCR2_REG = (TCCR2_REG&0xF8) | (4);
#elif PRESCALER_SELECTION == PRE_128
		TCCR2_REG = (TCCR2_REG&0xF8) | (5);
#elif PRESCALER_SELECTION == PRE_256
		TCCR2_REG = (TCCR2_REG&0xF8) | (6);
#elif PRESCALER_SELECTION == PRE_1024
		TCCR2_REG = (TCCR2_REG&0xF8) | (7);
#endif
		break;
	}
}

// This function starts the timer0
void TMR_vStartTimer0(enu_prescale_modes prescale){
	TCCR0_REG = (TCCR0_REG&0xF8) | (prescale&0x07);
}

void TMR_vStartTimer1(enu_prescale_modes prescale){
	switch(prescale){
	case PRE_NO_CLK:
		TCCR1B_REG = (TCCR1B_REG&0xF8);
		break;
	case PRE_0:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 1;
		break;
	case PRE_8:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 2;
		break;
	case PRE_64:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 3;
		break;
	case PRE_256:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 4;
		break;
	case PRE_1024:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 5;
		break;
	case PRE_EXT_FALLING:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 6;
		break;
	case PRE_EXT_RISING:
		TCCR1B_REG = (TCCR1B_REG&0xF8) | 7;
		break;
	default: /* Do Nothing */ break;
	}
}

void TMR_vStartTimer2(enu_prescale_modes prescale){
	if (prescale == PRE_NO_CLK){
		TCCR2_REG = (TCCR2_REG&0xF8);}
	else if (prescale == PRE_0){
		TCCR2_REG = (TCCR2_REG&0xF8) | (1);}
	else if (prescale == PRE_8){
		TCCR2_REG = (TCCR2_REG&0xF8) | (2);}
	else if (prescale == PRE_32){
		TCCR2_REG = (TCCR2_REG&0xF8) | (3);}
	else if (prescale == PRE_64){
		TCCR2_REG = (TCCR2_REG&0xF8) | (4);}
	else if (prescale == PRE_128){
		TCCR2_REG = (TCCR2_REG&0xF8) | (5);}
	else if (prescale == PRE_256){
		TCCR2_REG = (TCCR2_REG&0xF8) | (6);}
	else if (prescale == PRE_1024){
		TCCR2_REG = (TCCR2_REG&0xF8) | (7);}
	else{ /* Do Nothing */ }
}


// This function is responsible for disabling timer
void TMR_vDisable(u8 Copy_u8SelectedChannel){
	switch(Copy_u8SelectedChannel)
	{
	case TMR0_CHNL: TCCR0_REG&=0xF8;  break;
	case TMR1_CHNL:	TCCR1B_REG&=0xD8; break;
	case TMR2_CHNL:	TCCR2_REG&=0xF8;  break;
	}
}

// This function is responsible for setting the ICR top value
void TMR_vSetICRTopValue(u16 Copy_u16TopValue){
	ICR1_REG = Copy_u16TopValue;
}

// This function is responsible for setting the OCR top value
void TMR_vSetOCRValue(u16 Copy_u16OCRValue){
	OCR1A_REG = Copy_u16OCRValue;
}
