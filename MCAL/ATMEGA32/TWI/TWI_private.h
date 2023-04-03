/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TWI_private.h                                  	     */
/* Date          : Mar 22, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_TWI_TWI_PRIVATE_H_
#define MCAL_ATMEGA32_TWI_TWI_PRIVATE_H_

/* Section : Includes */
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"

/* Section : Macro Declarations */
#define TWCR_REG		HWREG8(0x56)
#define TWDR_REG		HWREG8(0x23)
#define TWAR_REG		HWREG8(0x22)
#define TWSR_REG		HWREG8(0x21)
#define TWBR_REG		HWREG8(0x20)

#define TWI_PORT		PORTC
#define SDA_PIN			PIN1
#define SCL_PIN			PIN0

typedef enum{
	TWIE=0,
	/* Bit 1 reserved */
	TWEN=2,
	TWWC,
	TWSTO,
	TWSTA,
	TWEA,
	TWINT
}enu_TWCR_Bits;

typedef enum{
	TWI_PRESCALE_1,
	TWI_PRESCALE_4,
	TWI_PRESCALE_16,
	TWI_PRESCALE_64
}enu_TWI_Prescaler;

#define CMD_START_CONDITION			0xA4

#define STATE_START_SENT			0x08
#define STATE_REPEATED_START_SENT	0x10
#define STATE_SLA_W_ACK				0x18
#define STATE_SLA_W_NACK			0x20
#define STATE_DATA_W_ACK			0x28
#define STATE_DATA_W_NACK			0x30
#define STATE_ARBIT_LOST			0x38
#define STATE_SLA_R_ACK				0x40
#define STATE_SLA_R_NACK			0x48
#define STATE_DATA_R_ACK			0x50
#define STATE_DATA_R_NACK			0x58

/* Section : Macro Functions Declarations */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))
/* Section : Data Type Declarations */

/* Section : Function Declarations */

#endif /* MCAL_ATMEGA32_TWI_TWI_PRIVATE_H_ */
