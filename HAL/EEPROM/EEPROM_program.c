/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EEPROM_program.c                                  	     */
/* Date          : Apr 7, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "EEPROM_interface.h"
#include <util/delay.h>
#define F_CPU	8000000UL

void EEPROM_vinit(void){
	TWI_vInit();
}
u8 EEPROM_u8WriteByte(u8 Copy_u8Address, u8 Copy_u8Data, enu_EEPROM_Blocks Copy_enuBlock){
	TWI_vStart();
	if(TWI_u8GetStatus() != TW_START){
		return ERROR;
	}
	/* Send the device address, we need to get A8 A9 A10 address bits from
	 * memory location address and R/W=0 (write) */
	TWI_vWriteData( (EEPROM_Address | EEPROM_EN_CFG | Copy_enuBlock) & 0xFE );
	if(TWI_u8GetStatus() != TW_MT_SLA_W_ACK){
		return ERROR;
	}
	/* Send the required memory location address */
	TWI_vWriteData(Copy_u8Address);
	if(TWI_u8GetStatus() != TW_MT_DATA_ACK){
		return ERROR;
	}

	/* Write byte to eeprom */
	TWI_vWriteData(Copy_u8Data);

	TWI_vStop();

	_delay_ms(20);

	return SUCCESS;
}

u8 EEPROM_u8ReadByte(u8 Copy_u8Address, u8 *Copy_u8Data, enu_EEPROM_Blocks Copy_enuBlock){
	TWI_vStart();
	if(TWI_u8GetStatus() != TW_START){
		//return ERROR;
	}
	/* Send the device address, we need to get A8 A9 A10 address bits from
	 * memory location address and R/W=0 (write) */
	TWI_vWriteData( (EEPROM_Address | EEPROM_EN_CFG | Copy_enuBlock) & 0xFE );
	if(TWI_u8GetStatus() != TW_MT_SLA_W_ACK){
		//return ERROR;
	}
	/* Send the required memory location address */
	TWI_vWriteData(Copy_u8Address);
	if(TWI_u8GetStatus() != TW_MT_DATA_ACK){
		//return ERROR;
	}
	TWI_vStart();
	if(TWI_u8GetStatus() != TW_START){
		//return ERROR;
	}
	TWI_vWriteData( EEPROM_Address | EEPROM_EN_CFG | Copy_enuBlock | 1 );
	if(TWI_u8GetStatus() != TW_MT_SLA_R_ACK){
		//return ERROR;
	}
	*Copy_u8Data = TWI_u8ReadWithNoAck();
	if(TWI_u8GetStatus() != TW_MR_DATA_ACK){
		//return ERROR;
	}
	TWI_vStop();

	_delay_ms(20);
	return SUCCESS;
}

void EEPROM_vWriteString(u8 Copy_u8Address, u8 *Copy_u8String, enu_EEPROM_Blocks Copy_enuBlock){
	u8 local_u8StringIndex=0;
	u8 local_u8Address = Copy_u8Address;
	while(Copy_u8String[local_u8StringIndex] != '\0'){
		EEPROM_u8WriteByte(local_u8Address, Copy_u8String[local_u8StringIndex], Copy_enuBlock);
		local_u8Address++;
		local_u8StringIndex++;
	}
	EEPROM_u8WriteByte(local_u8Address, '\0', Copy_enuBlock);
}

void EEPROM_vReadString(u8 Copy_u8Address, u8 *Copy_u8String, enu_EEPROM_Blocks Copy_enuBlock){
	u8 local_u8StringIndex=0;
	u8 local_u8Address = Copy_u8Address;
	u8 local_temp;
	do{
		EEPROM_u8ReadByte(local_u8Address, &local_temp, Copy_enuBlock);
		if(local_temp == 0xFF){
			break;
		}
		else{ /* Do Nothing */ }
		Copy_u8String[local_u8StringIndex] = local_temp;
		local_u8StringIndex++;
		local_u8Address++;
	}while(local_temp != '\0');
}
