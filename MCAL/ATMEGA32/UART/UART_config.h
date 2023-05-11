/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : UART_config.h                                  	     */
/* Date          : Mar 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_UART_UART_CONFIG_H_
#define MCAL_ATMEGA32_UART_UART_CONFIG_H_

/**
 * Character size = 8 bits
 * Parity = no parity
 * stop bits = 1 bit
 * interrupt state = disabled
 * baud rate = 9600
 * Clock mode = asynchronous
 * Speed = 2X
 */

/* Section : Includes */

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	CHAR_5_BITS,
	CHAR_6_BITS,
	CHAR_7_BITS,
	CHAR_8_BITS,
	CHAR_9_BITS
}CharSize_tcfg;

typedef enum{
	PARITY_DISABLED,
	PARITY_EVEN,
	PARITY_ODD
}ParityState_tcfg;

typedef enum{
	STOP_BITS_1,
	STOP_BITS_2
}StopBitsNum_tcfg;

typedef enum{
	UART_INTERRUPT_DISABLED,
	UART_INTERRUPT_ENABLED
}UARTInterrupt_tcfg;

typedef enum{
	UART_BR2X_2400 = 416,
	UART_BR2X_4800 = 207,
	UART_BR2X_9600 = 103,
	UART_BR2X_38400 = 25
}UARTBaudRate2X_tcfg;

typedef enum{
	UART_BR1X_2400 = 207,
	UART_BR1X_4800 = 103,
	UART_BR1X_9600 = 51,
	UART_BR1X_38400 = 12
}UARTBaudRate1X_tcfg;

typedef enum{
	UART_1X_SPEED,
	UART_2X_SPEED
}UARTCommMode_tcfg;

typedef enum{
	UART_SYNCHRONOUS,
	UART_ASYNCHRONOUS
}UART_ClkMode_tcfg;

/* Section : Function Declarations */

#endif /* MCAL_ATMEGA32_UART_UART_CONFIG_H_ */
