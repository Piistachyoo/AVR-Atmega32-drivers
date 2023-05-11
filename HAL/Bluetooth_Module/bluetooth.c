/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : bluetooth.c                                    	     */
/* Date          : May 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "bluetooth.h"

static UART_tcfgInitialize UART1 = {
		.GLOBAL_tcfgCharSize = CHAR_8_BITS,
		.GLOBAL_tcfgParityState = PARITY_DISABLED,
		.GLOBAL_tcfgStopBits = STOP_BITS_1,
		.GLOBAL_tcfgUartBaudRate1X = UART_BR1X_9600,
		.GLOBAL_tcfgUartClkMode = UART_ASYNCHRONOUS,
		.GLOBAL_tcfgUartCommMode = UART_1X_SPEED,
		.GLOBAL_tcfgUartInterrupt = UART_INTERRUPT_DISABLED
};

void Bluetooth_vInit(){
	UART_vInit(&UART1);
}

void Bluetooth_vEnable(){
	UART_vEnable(&UART1);
}

void Bluetooth_vDisable(){
	UART_vDisable(&UART1);
}

void Bluetooth_vSendData(u8 Copy_u8Data){
	UART_vSendData(Copy_u8Data);
}

u8 Bluetooth_u8ReceiveData(void){
	static u8 LOCAL_u8ReceivedData;
	LOCAL_u8ReceivedData = UART_u8ReceiveData();

	return LOCAL_u8ReceivedData;
}

void Bluetooth_vSendString(u8 *Copy_u8Str){
	UART_vSendString(Copy_u8Str);
}

void Bluetooth_vClearBuffer(){
	UART_vClearBuffer();
}
