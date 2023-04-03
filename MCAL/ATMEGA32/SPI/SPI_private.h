/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : SPI_private.h                                  	     */
/* Date          : Mar 21, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_SPI_SPI_PRIVATE_H_
#define MCAL_ATMEGA32_SPI_SPI_PRIVATE_H_

/* Section : Includes */
#include "../../../Services/STD_TYPES/STD_TYPES.h"

#include "../DIO/DIO_private.h"

/* Section : Macro Declarations */

#define SPI_PORT	PORTB

#define	SS_PIN		PIN4
#define MOSI_PIN	PIN5
#define MISO_PIN	PIN6
#define	SCK_PIN		PIN7

#define SPDR_REG	HWREG8(0x2F)
#define SPSR_REG	HWREG8(0x2E)
#define SPCR_REG	HWREG8(0x2D)



/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	SPR0,
	SPR1,
	CPHA,
	CPOL,
	MSTR,
	DORD,
	SPE,
	SPIE
}SPCR_Bits;

typedef enum{
	SPI2X=0,
	/* 1-5 reserved */
	WCOL=6,
	SPIF
}SPSR_Bits;
/* Section : Function Declarations */

#endif /* MCAL_ATMEGA32_SPI_SPI_PRIVATE_H_ */
