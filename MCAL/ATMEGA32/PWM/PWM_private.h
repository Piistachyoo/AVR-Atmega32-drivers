/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : PWM_private.h                                  	     */
/* Date          : Mar 28, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_PWM_PWM_PRIVATE_H_
#define MCAL_ATMEGA32_PWM_PWM_PRIVATE_H_

/* Section : Includes */

/* Section : Macro Declarations */
#define TCNT0_REG		*((volatile u8*) 0x52)
#define TCNT1_REG		*((volatile u16*) 0x4C)
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
#define ICR1_REG		*((volatile u16*) 0x46)


/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	CS20,
	CS21,
	CS22,
	WGM21,
	COM20,
	COM21,
	WGM20,
	FOC2
}TCCR2_bits;

//TCCR1A BITS
enum TCCR1A_BITS{
	WGM10=0,
	WGM11,
	FOC1B,
	FOC1A,
	COM1B0,
	COM1B1,
	COM1A0,
	COM1A1
};

enum TCCR1B_BITS{
	CS10=0,
	CS11,
	CS12,
	WGM12,
	WGM13,
	ICES1=6,
	ICNC1
};

typedef enum{
CS00,
CS01,
CS02,
WGM01,
COM00,
COM01,
WGM00,
FOC0
}TCCR0_BITS;

typedef enum{
TOIE0,
OCIE0,
TOIE1,
OCIE1B,
OCIE1A,
TICIE1,
TOIE2,
OCIE2
}TIMSK_BITS;

typedef enum{
TOV0,
OCF0,
TOV1,
OCF1B,
OCF1A,
ICF1,
TOV2,
OCF2
}TIFR_BITS;

/* Section : Function Declarations */

#endif /* MCAL_ATMEGA32_PWM_PWM_PRIVATE_H_ */
