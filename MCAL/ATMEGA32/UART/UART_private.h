/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : UART_private.h                                  	     */
/* Date          : Mar 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_UART_UART_PRIVATE_H_
#define MCAL_ATMEGA32_UART_UART_PRIVATE_H_

/* Section : Includes */
#include "../../../Services/BIT_MATH/BIT_MATH.h"
#include "../../../Services/STD_TYPES/STD_TYPES.h"

/* Section : Macro Declarations */
#define UDR_REG			HWREG8(0x2C)
#define UCSRA_REG		HWREG8(0x2B)
#define UCSRB_REG		HWREG8(0x2A)
#define UCSRC_REG		HWREG8(0x40)
#define UBRRH_REG		HWREG8(0x40)
#define UBRRL_REG		HWREG8(0x29)

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
enum UCSRA_BITS{
	MPCM_BIT=0,
	U2X_BIT,
	PE_BIT,
	DOR_BIT,
	FE_BIT,
	UDRE_BIT,
	TXC_BIT,
	RXC_BIT
};

enum UCSRB_BITS{
	TXB8_BIT=0,
	RXB8_BIT,
	UCSZ2_BIT,
	TXEN_BIT,
	RXEN_BIT,
	UDRIE_BIT,
	TXCIE_BIT,
	RXCIE_BIT
};

enum UCSRC_BITS{
	UCPOL_BIT=0,
	UCSZ0_BIT,
	UCSZ1_BIT,
	USBS_BIT,
	UPM0_BIT,
	UPM1_BIT,
	UMSEL_BIT,
	URSEL_BIT
};

/* Section : Function Declarations */

#endif /* MCAL_ATMEGA32_UART_UART_PRIVATE_H_ */
