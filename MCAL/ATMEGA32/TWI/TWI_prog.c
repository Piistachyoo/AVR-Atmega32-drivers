/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TWI_prog.c                                  	     	 */
/* Date          : Apr 7, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "TWI_interface.h"

void TWI_vInit(){
	DIO_vPinInit(PORTC, PIN0, INPUT, LOW);
	DIO_vPinInit(PORTC, PIN1, INPUT, LOW);
	// TWBR Value
	TWBR_REG = ((F_CPU/SCL_CLOCK)-16)/2; // 8Mhz oscillator and 100Khz bus freq.
	// Prescale value
	TWSR_REG = 0x00; // Set Prescaler to 1
	// Set address (TWAR = 0x02)
	TWAR_REG = DEVICE_ADDR;
	// Enable TWI
	TWCR_REG = (1<<TWEN);
}

void TWI_vStart(){
	/*// Clear TWI Flag
	TWCR_REG = (1<<TWINT);
	// Send Start Condition
	TWCR_REG |= (1<<TWSTA);
	// Enable TWI
	TWCR_REG |= (1<<TWEN);*/
	TWCR_REG = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// Polling until flag is set
	while(!(GET_BIT(TWCR_REG, TWINT)));
}

void TWI_vStop(){
	/*// Clear TWINT Flag
	TWCR_REG = (1<<TWINT);
	// Send stop condition
	TWCR_REG |= (1<<TWSTO);
	// Enable TWI
	TWCR_REG |= (1<<TWEN);*/
	TWCR_REG = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void TWI_vWriteData(u8 Copy_u8Data){
	// Write data on TWI DR
	TWDR_REG = Copy_u8Data;
	/*// Clear flag by setting to one
	TWCR_REG = (1<<TWINT);
	// Enable Ack
	TWCR_REG |= (1<<TWEA);
	// Enable TWI
	TWCR_REG |= (1<<TWEN);*/
	TWCR_REG = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	// Polling until flag is set
	while(!(GET_BIT(TWCR_REG, TWINT)));
}

u8 TWI_u8ReadWithAck(){
	u8 Data;
	// Clear flag
	while(!(GET_BIT(TWCR_REG, TWINT)));
	// Enable Ack
	TWCR_REG |= (1<<TWEA);
	// Enable TWI
	TWCR_REG |= (1<<TWEN);
	// Poll until flag is set
	while(!(GET_BIT(TWCR_REG, TWINT)));
	// Read received data
	Data = TWDR_REG;
	return Data;
}

u8 TWI_u8ReadWithNoAck(){
	u8 Data;
	// Clear flag
	while(!(GET_BIT(TWCR_REG, TWINT)));
	// Enable TWI
	CLR_BIT(TWCR_REG, TWEA);
	TWCR_REG |= (1<<TWEN);
	// Poll until flag is set
	while(!(GET_BIT(TWCR_REG, TWINT)));
	// Read received data
	Data = TWDR_REG;
	return Data;
}

u8 TWI_u8GetStatus(){
	u8 Status;
	// Read status register (&0xF8)
	Status = TWSR_REG & 0xF8;
	return Status;
}


