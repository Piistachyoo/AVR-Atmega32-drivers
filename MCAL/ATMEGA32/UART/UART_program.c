/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : UART.program.c                                  	     */
/* Date          : Mar 24, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "UART_interface.h"

void UART_vInit(const UART_tcfgInitialize *LOCAL_tcfgUART){


	if(LOCAL_tcfgUART->GLOBAL_tcfgCharSize == CHAR_5_BITS){
		CLR_BIT(UCSRC_REG, UCSZ0_BIT);
		CLR_BIT(UCSRC_REG, UCSZ1_BIT);
		CLR_BIT(UCSRB_REG, UCSZ2_BIT);
	}
	else if((LOCAL_tcfgUART->GLOBAL_tcfgCharSize == CHAR_6_BITS)){
		SET_BIT(UCSRC_REG, UCSZ0_BIT);
		CLR_BIT(UCSRC_REG, UCSZ1_BIT);
		CLR_BIT(UCSRB_REG, UCSZ2_BIT);

	}
	else if((LOCAL_tcfgUART->GLOBAL_tcfgCharSize == CHAR_7_BITS)){
		CLR_BIT(UCSRC_REG, UCSZ0_BIT);
		SET_BIT(UCSRC_REG, UCSZ1_BIT);
		CLR_BIT(UCSRB_REG, UCSZ2_BIT);

	}
	else if((LOCAL_tcfgUART->GLOBAL_tcfgCharSize == CHAR_8_BITS)){
		SET_BIT(UCSRC_REG, UCSZ0_BIT);
		SET_BIT(UCSRC_REG, UCSZ1_BIT);
		CLR_BIT(UCSRB_REG, UCSZ2_BIT);
	}
	else if((LOCAL_tcfgUART->GLOBAL_tcfgCharSize == CHAR_9_BITS)){
		SET_BIT(UCSRC_REG, UCSZ0_BIT);
		SET_BIT(UCSRC_REG, UCSZ1_BIT);
		SET_BIT(UCSRB_REG, UCSZ2_BIT);
	}
	else { /* Do Nothing */ }

	if(LOCAL_tcfgUART->GLOBAL_tcfgParityState == PARITY_DISABLED){
		CLR_BIT(UCSRC_REG, UPM0_BIT);
		CLR_BIT(UCSRC_REG, UPM1_BIT);
	}
	else if(LOCAL_tcfgUART->GLOBAL_tcfgParityState == PARITY_EVEN){
		CLR_BIT(UCSRC_REG, UPM0_BIT);
		SET_BIT(UCSRC_REG, UPM1_BIT);
	}
	else if(LOCAL_tcfgUART->GLOBAL_tcfgParityState == PARITY_ODD){
		SET_BIT(UCSRC_REG, UPM0_BIT);
		SET_BIT(UCSRC_REG, UPM1_BIT);
	}
	else { /* Do Nothing */ }

	if(LOCAL_tcfgUART->GLOBAL_tcfgStopBits == STOP_BITS_1){
		CLR_BIT(UCSRC_REG, USBS_BIT);
	}
	else if(LOCAL_tcfgUART->GLOBAL_tcfgStopBits == STOP_BITS_2){
		SET_BIT(UCSRC_REG, USBS_BIT);
	}
	else { /* Do Nothing */ }

	if(LOCAL_tcfgUART->GLOBAL_tcfgUartInterrupt == UART_INTERRUPT_DISABLED){
		CLR_BIT(UCSRB_REG, RXCIE_BIT);
		CLR_BIT(UCSRB_REG, UDRIE_BIT);
		CLR_BIT(UCSRB_REG, TXCIE_BIT);
	}
	else if(LOCAL_tcfgUART->GLOBAL_tcfgUartInterrupt == UART_INTERRUPT_ENABLED){
		SET_BIT(UCSRB_REG, RXCIE_BIT);
		SET_BIT(UCSRB_REG, UDRIE_BIT);
		SET_BIT(UCSRB_REG, TXCIE_BIT);
	}
	else { /* Do Nothing */ }

	if(LOCAL_tcfgUART->GLOBAL_tcfgUartClkMode == UART_ASYNCHRONOUS){
		CLR_BIT(UCSRC_REG, UMSEL_BIT);
	}
	else if(LOCAL_tcfgUART->GLOBAL_tcfgUartClkMode == UART_SYNCHRONOUS){
		SET_BIT(UCSRC_REG, UMSEL_BIT);
	}
	else { /* Do Nothing */ }

	if(LOCAL_tcfgUART->GLOBAL_tcfgUartCommMode == UART_2X_SPEED){
		SET_BIT(UCSRA_REG, U2X_BIT);
		UBRRL_REG = LOCAL_tcfgUART->GLOBAL_tcfgUartBaudRate2X;
		UBRRH_REG = ((LOCAL_tcfgUART->GLOBAL_tcfgUartBaudRate2X)>>8);
	}
	else if(LOCAL_tcfgUART->GLOBAL_tcfgUartCommMode == UART_1X_SPEED){
		CLR_BIT(UCSRA_REG, U2X_BIT);
		UBRRL_REG = LOCAL_tcfgUART->GLOBAL_tcfgUartBaudRate1X;
		UBRRH_REG = ((LOCAL_tcfgUART->GLOBAL_tcfgUartBaudRate1X)>>8);
	}
	else { /* Do Nothing */ }
}

void UART_vEnable(const UART_tcfgInitialize *LOCAL_tcfgUART){
	SET_BIT(UCSRB_REG, RXEN_BIT);
	SET_BIT(UCSRB_REG, TXEN_BIT);
}

void UART_vDisable(const UART_tcfgInitialize *LOCAL_tcfgUART){
	CLR_BIT(UCSRB_REG, RXEN_BIT);
	CLR_BIT(UCSRB_REG, TXEN_BIT);
}

void UART_vSendData(u8 LOCAL_u8Data){
	while( GET_BIT(UCSRA_REG, UDRE_BIT) != 1 );
	UDR_REG = LOCAL_u8Data;
}

u8 UART_u8ReceiveData(void){
	u8 local_u8Data;
	while( GET_BIT(UCSRA_REG, RXC_BIT) != 1 );
	local_u8Data = UDR_REG;
	CLR_BIT(UCSRA_REG, RXC_BIT);
	return local_u8Data;
}

void UART_vSendString(u8 *Copy_u8Str){
	while(*Copy_u8Str){
		UART_vSendData(*(Copy_u8Str++));
	}
}

void UART_vClearBuffer(){
	u8 temp;
	temp = UDR_REG;
	CLR_BIT(UCSRA_REG, RXC_BIT);
}
