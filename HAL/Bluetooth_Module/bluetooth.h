/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : bluetooth.h                                    	     */
/* Date          : May 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_BLUETOOTH_MODULE_BLUETOOTH_H_
#define HAL_BLUETOOTH_MODULE_BLUETOOTH_H_

#include "../../MCAL/ATMEGA32/UART/UART_interface.h"

void Bluetooth_vInit();

void Bluetooth_vEnable();

void Bluetooth_vDisable();

void Bluetooth_vSendData(u8 Copy_u8Data);

u8 Bluetooth_u8ReceiveData(void);

void Bluetooth_vSendString(u8 *Copy_u8Str);

void Bluetooth_vClearBuffer();

#endif /* HAL_BLUETOOTH_MODULE_BLUETOOTH_H_ */
