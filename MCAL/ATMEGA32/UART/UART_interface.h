/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : UART_interface.h                                  	     */
/* Date          : Mar 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef MCAL_ATMEGA32_UART_UART_INTERFACE_H_
#define MCAL_ATMEGA32_UART_UART_INTERFACE_H_

/* Section : Includes */
#include "UART_config.h"
#include "UART_private.h"


/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	CharSize_tcfg		GLOBAL_tcfgCharSize;
	ParityState_tcfg	GLOBAL_tcfgParityState;
	StopBitsNum_tcfg	GLOBAL_tcfgStopBits;
	UARTInterrupt_tcfg	GLOBAL_tcfgUartInterrupt;
	UARTBaudRate2X_tcfg	GLOBAL_tcfgUartBaudRate2X;
	UARTBaudRate1X_tcfg	GLOBAL_tcfgUartBaudRate1X;
	UART_ClkMode_tcfg	GLOBAL_tcfgUartClkMode;
	UARTCommMode_tcfg	GLOBAL_tcfgUartCommMode;
}UART_tcfgInitialize;

/* Section : Function Declarations */
void UART_vInit(const UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vEnable(const UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vDisable(const UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vSendData(u8 LOCAL_u8Data);

u8 UART_u8ReceiveData(void);

void UART_vSendString(u8 *Copy_u8Str);

void UART_vClearBuffer();

#endif /* MCAL_ATMEGA32_UART_UART_INTERFACE_H_ */
