/*
 * DIO_prog.c
 *
 *  Created on: Jan 28, 2023
 *      Author: omarm
 */

#include "DIO_Interface.h"

void SET_Direction(u8 Copy_PORT, u8 Copy_PIN, u8 Direction)//set a specific pin as input or output
{
	if(Direction == OUTPUT)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			SET_BIT(DDRA_REG, Copy_PIN);
			break;
		case PORTB:
			SET_BIT(DDRB_REG, Copy_PIN);
			break;
		case PORTC:
			SET_BIT(DDRC_REG, Copy_PIN);
			break;
		case PORTD:
			SET_BIT(DDRD_REG, Copy_PIN);
			break;
		}
	}
	else if(Direction == INPUT)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			CLR_BIT(DDRA_REG, Copy_PIN);
			break;
		case PORTB:
			CLR_BIT(DDRB_REG, Copy_PIN);
			break;
		case PORTC:
			CLR_BIT(DDRC_REG, Copy_PIN);
			break;
		case PORTD:
			CLR_BIT(DDRD_REG, Copy_PIN);
			break;
		}
	}
}

void SET_State(u8 Copy_PORT, u8 Copy_PIN, u8 State)//set a specific output pin as high or low
{
	if(State == HIGH)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			SET_BIT(PORTA_REG, Copy_PIN);
			break;
		case PORTB:
			SET_BIT(PORTB_REG, Copy_PIN);
			break;
		case PORTC:
			SET_BIT(PORTC_REG, Copy_PIN);
			break;
		case PORTD:
			SET_BIT(PORTD_REG, Copy_PIN);
			break;
		}
	}
	else if(State == LOW)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			CLR_BIT(PORTA_REG, Copy_PIN);
			break;
		case PORTB:
			CLR_BIT(PORTB_REG, Copy_PIN);
			break;
		case PORTC:
			CLR_BIT(PORTC_REG, Copy_PIN);
			break;
		case PORTD:
			CLR_BIT(PORTD_REG, Copy_PIN);
			break;
		}
	}
}

u8 GET_State(u8 Copy_PORT, u8 Copy_PIN)//read data from input pin
{
	switch(Copy_PORT)
	{
	case PORTA:
		return GET_BIT(PINA_REG, Copy_PIN);
		break;
	case PORTB:
		return GET_BIT(PINB_REG, Copy_PIN);
		break;
	case PORTC:
		return GET_BIT(PINC_REG, Copy_PIN);
		break;
	case PORTD:
		return GET_BIT(PIND_REG, Copy_PIN);
		break;
	}
}

void SET_Direction_4LSB(u8 Copy_PORT, u8 Direction)//set 4 LSB as input or output
{
	if(Direction == OUTPUT)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			DDRA_REG |= 0x0F;
			break;
		case PORTB:
			DDRB_REG |= 0x0F;
			break;
		case PORTC:
			DDRC_REG |= 0x0F;
			break;
		case PORTD:
			DDRD_REG |= 0x0F;
			break;
		}
	}
	if(Direction == INPUT)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			DDRA_REG &= 0xF0;
			break;
		case PORTB:
			DDRB_REG &= 0xF0;
			break;
		case PORTC:
			DDRC_REG &= 0xF0;
			break;
		case PORTD:
			DDRD_REG &= 0xF0;
			break;
		}
	}
}

void SET_Direction_4MSB(u8 Copy_PORT, u8 Direction)//set 4 MSB as input or output
{
	if(Direction == OUTPUT)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			DDRA_REG |= 0xF0;
			break;
		case PORTB:
			DDRB_REG |= 0xF0;
			break;
		case PORTC:
			DDRC_REG |= 0xF0;
			break;
		case PORTD:
			DDRD_REG |= 0xF0;
			break;
		}
	}
	if(Direction == INPUT)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			DDRA_REG &= 0x0F;
			break;
		case PORTB:
			DDRB_REG &= 0x0F;
			break;
		case PORTC:
			DDRC_REG &= 0x0F;
			break;
		case PORTD:
			DDRD_REG &= 0x0F;
			break;
		}
	}
}

void SET_State_4LSB(u8 Copy_PORT, u8 State)//set 4LSB output pins as high or low
{
	if(State == HIGH)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			PORTA_REG |= 0x0F;
			break;
		case PORTB:
			PORTB_REG |= 0x0F;
			break;
		case PORTC:
			PORTC_REG |= 0x0F;
			break;
		case PORTD:
			PORTD_REG |= 0x0F;
			break;
		}
	}
	else if(State == LOW)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			PORTA_REG &= 0xF0;
			break;
		case PORTB:
			PORTB_REG &= 0xF0;
			break;
		case PORTC:
			PORTC_REG &= 0xF0;
			break;
		case PORTD:
			PORTD_REG &= 0xF0;
			break;
		}
	}
}

void SET_State_4MSB(u8 Copy_PORT, u8 State)//set 4MSB output pins as high or low
{
	if(State == HIGH)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			PORTA_REG |= 0xF0;
			break;
		case PORTB:
			PORTB_REG |= 0xF0;
			break;
		case PORTC:
			PORTC_REG |= 0xF0;
			break;
		case PORTD:
			PORTD_REG |= 0xF0;
			break;
		}
	}
	else if(State == LOW)
	{
		switch(Copy_PORT)
		{
		case PORTA:
			PORTA_REG &= 0x0F;
			break;
		case PORTB:
			PORTB_REG &= 0x0F;
			break;
		case PORTC:
			PORTC_REG &= 0x0F;
			break;
		case PORTD:
			PORTD_REG &= 0x0F;
			break;
		}
	}
}
