/*
 * DIO_Private.h
 *
 *  Created on: Jan 28, 2023
 *      Author: omarm
 */

#include "STD_TYPES.h"
#include "BIT_OP.h"
#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_
//manually doing enum for port numbers
#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4
//manually doing enum for pin numbers
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//Initalizing PORT A registers
#define PORTA_REG *((volatile u8*)0x3B)//Defines the output of PORTD pins
#define DDRA_REG *((volatile u8*)0x3A)//Defines direction of PORTD pins
#define PINA_REG *((volatile u8*)0x39)//Gets input from PORTD pins
//Initalizing PORT B registers
#define PORTB_REG *((volatile u8*)0x38)//Defines the output of PORTD pins
#define DDRB_REG *((volatile u8*)0x37)//Defines direction of PORTD pins
#define PINB_REG *((volatile u8*)0x36)//Gets input from PORTD pins
//Initalizing PORT C registers
#define PORTC_REG *((volatile u8*)0x35)//Defines the output of PORTD pins
#define DDRC_REG *((volatile u8*)0x34)//Defines direction of PORTD pins
#define PINC_REG *((volatile u8*)0x33)//Gets input from PORTD pins
//Initalizing PORT D registers
#define PORTD_REG *((volatile u8*)0x32)//Defines the output of PORTD pins
#define DDRD_REG *((volatile u8*)0x31)//Defines direction of PORTD pins
#define PIND_REG *((volatile u8*)0x30)//Gets input from PORTD pins
//Macros for HIGH/LOW Keywords
#define HIGH 1
#define LOW 0
//Macros for INPUT/OUTPUT Keywords
#define INPUT 0
#define OUTPUT 1
//Configuration for pull up/down inputs
#define PULLUP 5
#define PULLDOWN 6
#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
