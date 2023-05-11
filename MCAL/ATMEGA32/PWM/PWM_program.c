/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : PWM_program.c                                  	     */
/* Date          : Mar 28, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "PWM_interface.h"

void PWM_vInit(const PWM_cfg_t *PWM){
	if(PWM != NULL){
		/* Set PWM Mode */
		switch(PWM->PWM_TimerChannel){
		case TIMER0_PhaseCorrect:
			TCCR0_REG = (TCCR0_REG&0xB7) | 0x40;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x03;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER0_FastPWM:
			TCCR0_REG = (TCCR0_REG&0xB7) | 0x48;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x03;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR0_REG = (TCCR0_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
			/*
			 * WGM10 WGM11 bit 0,1 in TCCR1A
			 * WGM12 WGM13 bit 3,4 in TCCR1B
			 */
		case TIMER1_Phase8:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 1;
			TCCR1B_REG = (TCCR1B_REG & 0xE7);
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_Phase9:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 2;
			TCCR1B_REG = (TCCR1B_REG & 0xE7);
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_Phase10:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 3;
			TCCR1B_REG = (TCCR1B_REG & 0xE7);
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_Fast8:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 1;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x8;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_Fast9:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 2;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x8;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_Fast10:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 3;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x8;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_PhaseFreqICR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC);
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x10;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_PhaseFreqOCR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 1;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x10;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_PhaseICR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 2;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x10;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_PhaseOCR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 3;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x10;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_FastICR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 2;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x18;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER1_FastOCR:
			TCCR1A_REG = (TCCR1A_REG & 0xFC) | 3;
			TCCR1B_REG = (TCCR1B_REG & 0xE7) | 0x18;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0x3C;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR1A_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER2_PhaseCorrect:
			TCCR2_REG = (TCCR2_REG & 0xB7) | 0x40;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0xC0;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR2_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR2_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		case TIMER2_FastPWM:
			TCCR2_REG = (TCCR2_REG & 0xB7) | 0x48;
			if(PWM->PWM_ToggleMode == PWM_InterruptMode){
				TIMSK_REG |= 0xC0;
			}
			else if(PWM->PWM_ToggleMode == PWM_OCmode){
				if(PWM->PWM_InvertOrNot == PWM_NonInvertingMode){
					TCCR2_REG = (TCCR1A_REG & 0xCF) | 0x20;
				}
				else if(PWM->PWM_InvertOrNot == PWM_InvertingMode){
					TCCR2_REG = (TCCR1A_REG & 0xCF) | 0x30;
				}
				else { /* Do Nothing */ }
			}
			else{ /* Do Nothing */ }
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void PWM_vSetICR(const PWM_cfg_t *PWM, u16 Copy_u16ICRValue){
	if(PWM != NULL){
		switch(PWM->PWM_TimerChannel){
		case TIMER1_Phase8:
		case TIMER1_Phase9:
		case TIMER1_Phase10:
		case TIMER1_Fast8:
		case TIMER1_Fast9:
		case TIMER1_Fast10:
		case TIMER1_PhaseFreqICR:
		case TIMER1_PhaseFreqOCR:
		case TIMER1_PhaseICR:
		case TIMER1_PhaseOCR:
		case TIMER1_FastICR:
		case TIMER1_FastOCR:
			ICR1_REG = Copy_u16ICRValue;
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void PWM_vSetOCR(const PWM_cfg_t *PWM, u16 Copy_u16OCRValue){
	if(PWM != NULL){
		switch(PWM->PWM_TimerChannel){
		case TIMER0_PhaseCorrect:
		case TIMER0_FastPWM:
			OCR0_REG = (u8)Copy_u16OCRValue;
			break;
		case TIMER1_Phase8:
		case TIMER1_Phase9:
		case TIMER1_Phase10:
		case TIMER1_Fast8:
		case TIMER1_Fast9:
		case TIMER1_Fast10:
		case TIMER1_PhaseFreqICR:
		case TIMER1_PhaseFreqOCR:
		case TIMER1_PhaseICR:
		case TIMER1_PhaseOCR:
		case TIMER1_FastICR:
		case TIMER1_FastOCR:
			OCR1B_REG = Copy_u16OCRValue;
			break;
		case TIMER2_PhaseCorrect:
		case TIMER2_FastPWM:
			OCR2_REG = (u8)Copy_u16OCRValue;
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void PWM_vStart(const PWM_cfg_t *PWM){
	if(PWM != NULL){
		switch(PWM->PWM_TimerChannel){
		case TIMER0_PhaseCorrect:
		case TIMER0_FastPWM:
			DIO_vSetPinDir(PORTB, PIN3, OUTPUT);
			switch(PWM->PWM_TimerPrescale){
			case PRE_NO_CLK:
				TCCR0_REG = (TCCR0_REG&0xF8);
				break;
			case PRE_0:
				TCCR0_REG = (TCCR0_REG&0xF8) | 1;
				break;
			case PRE_8:
				TCCR0_REG = (TCCR0_REG&0xF8) | 2;
				break;
			case PRE_64:
				TCCR0_REG = (TCCR0_REG&0xF8) | 3;
				break;
			case PRE_256:
				TCCR0_REG = (TCCR0_REG&0xF8) | 4;
				break;
			case PRE_1024:
				TCCR0_REG = (TCCR0_REG&0xF8) | 5;
				break;
			case PRE_EXT_FALLING:
				TCCR0_REG = (TCCR0_REG&0xF8) | 6;
				break;
			case PRE_EXT_RISING:
				TCCR0_REG = (TCCR0_REG&0xF8) | 7;
				break;
			default: /* Do Nothing */ break;
			}
			break;
		case TIMER1_Phase8:
		case TIMER1_Phase9:
		case TIMER1_Phase10:
		case TIMER1_Fast8:
		case TIMER1_Fast9:
		case TIMER1_Fast10:
		case TIMER1_PhaseFreqICR:
		case TIMER1_PhaseFreqOCR:
		case TIMER1_PhaseICR:
		case TIMER1_PhaseOCR:
		case TIMER1_FastICR:
		case TIMER1_FastOCR:
			DIO_vSetPinDir(PORTD, PIN4, OUTPUT);
			switch(PWM->PWM_TimerPrescale){
			case PRE_NO_CLK:
				TCCR1B_REG = (TCCR1B_REG&0xF8);
				break;
			case PRE_0:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 1;
				break;
			case PRE_8:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 2;
				break;
			case PRE_64:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 3;
				break;
			case PRE_256:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 4;
				break;
			case PRE_1024:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 5;
				break;
			case PRE_EXT_FALLING:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 6;
				break;
			case PRE_EXT_RISING:
				TCCR1B_REG = (TCCR1B_REG&0xF8) | 7;
				break;
			default: /* Do Nothing */ break;
			}
			break;
		case TIMER2_PhaseCorrect:
		case TIMER2_FastPWM:
			DIO_vSetPinDir(PORTD, PIN7, OUTPUT);
			switch(PWM->PWM_TimerPrescale){
			case PRE_NO_CLK:
				TCCR2_REG = (TCCR2_REG&0xF8);
				break;
			case PRE_0:
				TCCR2_REG = (TCCR2_REG&0xF8) | 1;
				break;
			case PRE_8:
				TCCR2_REG = (TCCR2_REG&0xF8) | 2;
				break;
			case PRE_32:
				TCCR2_REG = (TCCR2_REG&0xF8) | 3;
				break;
			case PRE_64:
				TCCR2_REG = (TCCR2_REG&0xF8) | 4;
				break;
			case PRE_128:
				TCCR2_REG = (TCCR2_REG&0xF8) | 5;
				break;
			case PRE_256:
				TCCR2_REG = (TCCR2_REG&0xF8) | 6;
				break;
			case PRE_1024:
				TCCR2_REG = (TCCR2_REG&0xF8) | 7;
				break;
			default: /* Do Nothing */ break;
			}
			break;
		default: /* Do Nothing */ break;
		}
	}
}

void PWM_vStop(const PWM_cfg_t *PWM){
	if(PWM != NULL){
		switch(PWM->PWM_TimerChannel){
		case TIMER0_PhaseCorrect:
		case TIMER0_FastPWM:
			TCCR0_REG &= 0xF8;
			break;
		case TIMER1_Phase8:
		case TIMER1_Phase9:
		case TIMER1_Phase10:
		case TIMER1_Fast8:
		case TIMER1_Fast9:
		case TIMER1_Fast10:
		case TIMER1_PhaseFreqICR:
		case TIMER1_PhaseFreqOCR:
		case TIMER1_PhaseICR:
		case TIMER1_PhaseOCR:
		case TIMER1_FastICR:
		case TIMER1_FastOCR:
			TCCR1B_REG &= 0xF8;
			break;
		case TIMER2_PhaseCorrect:
		case TIMER2_FastPWM:
			TCCR2_REG &= 0xF8;
			break;
		default: /* Do Nothing */ break;
		}
	}
}
