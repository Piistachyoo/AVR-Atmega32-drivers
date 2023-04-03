/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : SPI_interface.h                                  	     */
/* Date          : Mar 21, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_SPI_SPI_INTERFACE_H_
#define MCAL_ATMEGA32_SPI_SPI_INTERFACE_H_

/* Section : Includes */
#include "SPI_config.h"
#include "SPI_private.h"
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"
#include "../DIO/DIO_interface.h"

/* Section : Macro Declarations */
#define SPI_PRESCALER			SPI_PRESC_4
#define SPI_SLAVE_NOTIFY_PORT	PORTB
#define SPI_SLAVE_NOTIFY_PIN	PIN0
/* Section : Data Type Declarations */
typedef enum{
	SPI_PRESC_4,
	SPI_PRESC_16,
	SPI_PRESC_64,
	SPI_PRESC_128,
	SPI_PRESC_2_DOUBLE_SPEED,
	SPI_PRESC_8_DOUBLE_SPEED,
	SPI_PRESC_32_DOUBLE_SPEED,
	SPI_PRESC_64_DOUBLE_SPEED
}SPI_FREQ_PERSCALE;

/* Section : Function Declarations */
void SPI_vMasterInit(u8 Copy_u8PreScale);
void SPI_vMasterSend(u8 Copy_u8Data);
u8 SPI_u8MasterReceive();

void SPI_vSlaveInit(u8 Copy_u8PreScale);
void SPI_vSlaveSend(u8 Copy_u8Data);
u8 SPI_u8SlaveReceive();
#endif /* MCAL_ATMEGA32_SPI_SPI_INTERFACE_H_ */
