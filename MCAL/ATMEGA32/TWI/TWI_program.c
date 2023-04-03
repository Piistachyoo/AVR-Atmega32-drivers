/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : TWI_program.c                                  	     */
/* Date          : Mar 22, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "TWI_interface.h"

Std_ReturnType TWI_Init(){
	TWSR_REG = 0x00;
	//TWBR_REG = BITRATE(TWSR_REG);
}

Std_ReturnType TWI_SendStartCondition(){
	// Clear Twint Flag, Enable TWI and enable start condition
	TWCR_REG = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(GET_BIT(TWCR_REG, TWINT)));
	if( (TWSR_REG&0xF8) == STATE_START_SENT ){
		return E_OK;
	}
	else{
		return E_NOT_OK;
	}
}

Std_ReturnType TWI_SendSlaveAddress(u8 Copy_u8SLAddress){
	TWDR_REG = Copy_u8SLAddress;
	TWCR_REG = (1<<TWINT)|(1<<TWEN);
	while(!(GET_BIT(TWCR_REG, TWINT)));
	if( (TWSR_REG&0xF8) ==  STATE_SLA_W_ACK ){
		return E_OK;
	}
	else{
		return E_NOT_OK;
	}
}

Std_ReturnType TWI_SendData(u8 Copy_u8Data){
	TWDR_REG = Copy_u8Data;
	TWCR_REG = (1<<TWINT)|(1<<TWEN);
	while(!(GET_BIT(TWCR_REG, TWINT)));
	if( (TWSR_REG&0xF8) == STATE_DATA_W_ACK ){
		return E_OK;
	}
	else{
		return E_NOT_OK;
	}
}


Std_ReturnType TWI_SendRepeatedStartCondition(){
	TWCR_REG = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(GET_BIT(TWCR_REG, TWINT)));
	if( (TWSR_REG&0xF8) == STATE_REPEATED_START_SENT ){
		return E_OK;
	}
	else{
		return E_NOT_OK;
	}
}
