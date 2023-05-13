/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TMR_private.h                                  	     */
/* Date          : Feb 26, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_TMR_TMR_PRIVATE_H_
#define MCAL_ATMEGA32_TMR_TMR_PRIVATE_H_

/****************** SETTING ADDRESES FOR USED REGISTERS ******************/
#define TCNT0_REG		*((volatile u8*) 0x52)
#define TCNT1_REG		*((volatile u16*) 0x4C)
#define TCNT1L_REG		*((volatile u8*) 0x4C)
#define TCNT1H_REG		*((volatile u8*) 0x4D)
#define TCNT2_REG		*((volatile u8*) 0x44)
#define TCCR0_REG		*((volatile u8*) 0x53)
#define TCCR1A_REG		*((volatile u8*) 0x4F)
#define TCCR1B_REG		*((volatile u8*) 0x4E)
#define TCCR2_REG		*((volatile u8*) 0x45)
#define OCR0_REG		*((volatile u8*) 0x5C)
#define OCR1A_REG		*((volatile u16*) 0x4A)
#define OCR1B_REG		*((volatile u16*) 0x48)
#define OCR2_REG		*((volatile u8*) 0x43)
#define TIMSK_REG		*((volatile u8*) 0x59)
#define TIFR_REG		*((volatile u8*) 0x58)
#define ASSR_REG		*((volatile u8*) 0x42)
#define ICR1L_REG		*((volatile u8*) 0x46)
#define ICR1H_REG		*((volatile u8*) 0x47)

/****************** SETTING MACROS FOR PIN NAMES ******************/

// TCCR0 PINS
#define CS00_PIN		0
#define CS01_PIN		1
#define CS02_PIN		2
#define WGM01_PIN		3
#define COM00_PIN		4
#define COM01_PIN		5
#define WGM00_PIN		6
#define FOC0_PIN		7

// TCCR2 PINS
#define CS20_PIN		0
#define CS21_PIN		1
#define CS22_PIN		2
#define WGM21_PIN		3
#define COM20_PIN		4
#define COM21_PIN		5
#define WGM20_PIN		6
#define FOC2_PIN		7


//TIMSK PINS
#define TOIE0_PIN		0
#define OCIE0_PIN		1
#define TOIE1_PIN		2
#define OCIE1B_PIN		3
#define OCIE1A_PIN		4
#define TICIE1_PIN		5
#define TOIE2_PIN		6
#define OCIE2_PIN		7

//TIFR PINS
#define TOV0_PIN		0
#define OCF0_PIN		1
#define TOV1_PIN		2
#define OCF1B_PIN		3
#define OCF1A_PIN		4
#define ICF1_PIN		5
#define TOV2_PIN		6
#define OCF2_PIN		7

//SFIOR PINS
#define PSR2_PIN

//TCCR1A BITS
#define WGM10 0
#define WGM11 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A17

//TCCR1B BITS
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7


#endif /* MCAL_ATMEGA32_TMR_TMR_PRIVATE_H_ */
