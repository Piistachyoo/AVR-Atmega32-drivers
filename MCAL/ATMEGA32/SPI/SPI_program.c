/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : SPI_program.c                                  	     */
/* Date          : Mar 21, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "SPI_interface.h"

void SPI_vMasterInit(u8 Copy_u8PreScale){
	// Set MISO as input, all others as output, SS to high
	DIO_vPinInit(SPI_PORT, MISO_PIN, INPUT, LOW);
	DIO_vPinInit(SPI_PORT, MOSI_PIN, OUTPUT, LOW);
	DIO_vPinInit(SPI_PORT, SCK_PIN, OUTPUT, LOW);
	DIO_vPinInit(SPI_PORT, SS_PIN, OUTPUT, HIGH);

	// Enable SPI in master mode
	SET_BIT(SPCR_REG, MSTR);
	// Choose prescaler
#if SPI_PRESCALER == SPI_PRESC_4
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC);
#elif SPI_PRESCALER == SPI_PRESC_16
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x01;
#elif SPI_PRESCALER == SPI_PRESC_64
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x02;
#elif SPI_PRESCALER == SPI_PRESC_128
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x03;
#elif SPI_PRESCALER == SPI_PRESC_2_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC);
#elif SPI_PRESCALER == SPI_PRESC_8_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x01;
#elif SPI_PRESCALER == SPI_PRESC_32_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x02;
#elif SPI_PRESCALER == SPI_PRESC_64_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x03;
#endif

	// Enable SPI
	SET_BIT(SPCR_REG, SPE);
}
void SPI_vMasterSend(u8 Copy_u8Data){
	u8 local_u8FlushBuffer;
	// Pull SS low
	DIO_vSetPinValue(SPI_PORT, SS_PIN, LOW);
	// Write data to SPI Data Register
	SPDR_REG = Copy_u8Data;
	// Wait till transmission is complete
	while(!(GET_BIT(SPSR_REG, SPIF)));
	// Flush received data
	local_u8FlushBuffer = SPDR_REG;
	// Set SS back to high
	DIO_vSetPinValue(SPI_PORT, SS_PIN, HIGH);
}
u8 SPI_u8MasterReceive(){
	u8 local_ReceivedData;
	// Set dummy value
	SPDR_REG = 0xFF;
	// Wait till reception is complete
	while(!(GET_BIT(SPSR_REG, SPIF)));
	// Read received data
	local_ReceivedData = SPDR_REG;
	return local_ReceivedData;
}

void SPI_vSlaveInit(u8 Copy_u8PreScale){
	// Set all pins as input except MOSI
	DIO_vPinInit(SPI_PORT, MISO_PIN, OUTPUT, LOW);
	DIO_vPinInit(SPI_PORT, MOSI_PIN, INPUT, LOW);
	DIO_vPinInit(SPI_PORT, SCK_PIN, INPUT, LOW);
	DIO_vPinInit(SPI_PORT, SS_PIN, INPUT, LOW);

	// Initialize notify pin
	DIO_vPinInit(SPI_SLAVE_NOTIFY_PORT, SPI_SLAVE_NOTIFY_PIN, OUTPUT, LOW);

	// Enable SPI in slave mode
	CLR_BIT(SPCR_REG, MSTR);
	// Choose prescaler
#if SPI_PRESCALER == SPI_PRESC_4
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC);
#elif SPI_PRESCALER == SPI_PRESC_16
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x01;
#elif SPI_PRESCALER == SPI_PRESC_64
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x02;
#elif SPI_PRESCALER == SPI_PRESC_128
	CLR_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x03;
#elif SPI_PRESCALER == SPI_PRESC_2_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC);
#elif SPI_PRESCALER == SPI_PRESC_8_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x01;
#elif SPI_PRESCALER == SPI_PRESC_32_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x02;
#elif SPI_PRESCALER == SPI_PRESC_64_DOUBLE_SPEED
	SET_BIT(SPSR_REG, SPI2X);
	SPCR_REG = (SPCR_REG&0xFC) | 0x03;
#endif

	// Enable SPI
	SET_BIT(SPCR_REG, SPE);
}
void SPI_vSlaveSend(u8 Copy_u8Data){
	u8 local_u8FlushBuffer;
	// Notify master
	DIO_vSetPinValue(SPI_SLAVE_NOTIFY_PORT, SPI_SLAVE_NOTIFY_PIN, HIGH);
	// Write data to SPI Data Register
	SPDR_REG = Copy_u8Data;
	// Wait till transmission is complete
	while(!(GET_BIT(SPSR_REG, SPIF)));
	// Flush received data
	local_u8FlushBuffer = SPDR_REG;
}
u8 SPI_u8SlaveReceive(){
	u8 local_u8ReceivedData;
	// Set dummy value
	SPDR_REG = 0xFF;
	// Wait till reception is complete
	while(!(GET_BIT(SPSR_REG, SPIF)));
	// Read received data
	local_u8ReceivedData = SPDR_REG;
	return local_u8ReceivedData;
}
