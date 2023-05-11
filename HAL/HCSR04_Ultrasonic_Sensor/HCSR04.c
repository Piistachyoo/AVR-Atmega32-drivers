/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : HCSR04.c                                    	     */
/* Date          : May 11, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "HCSR04.h"

static u16 timer1_counter;

static TMR_cfg_t Sensor_Timer = {
		.TMR_TimerChannel = TIMER1_NORMAL,
		.TMR_Prescale = TMR_PRE_0,
		.TMR_ToggleMode = TMR_InterruptMode,
		.TMR_OCMode = OC_Disconnected
};

/* ISR for Timer 1 Overflow */
void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	timer1_counter++;
}

void HCSR04_vInit(){
	/* GPIO Pins Initialization */
	DIO_vPinInit(TRIG_PORT, TRIG_PIN, OUTPUT, LOW);
	DIO_vPinInit(ECHO_PORT, ECHO_PIN, INPUT, HIGH);

	/* Initialize Timer */
	TMR_vInit(&Sensor_Timer);

	/* Enable global interrupts */
	GIE_vEnableInterrupts();
}

void HCSR04_vGet_Reading(f64 *Copy_f64Sensor_Reading){
	u16 ICR_Reg_Value;
	u32 Elapsed_Time;
	f64 Real_Distance;
	TCNT1_REG = 0; // Clear timer register
	CLEAR_ICU_FLAG(); // Clear ICU interrupt flag
	ICU_Rising_Edge(); // Set ICU to rising edge trigger
	TMR_vStartTimer(&Sensor_Timer); // Start timer counting
	/* Send a 10uSec pulse to trig */
	DIO_vSetPinValue(TRIG_PORT, TRIG_PIN, HIGH);
	_delay_us(10);
	DIO_vSetPinValue(TRIG_PORT, TRIG_PIN, LOW);

	/* Wait for rising edge from ECHO */
	while(!(TIFR_REG & (1<<ICF1_PIN)));
	TCNT1_REG = 0; // Clear timer register
	timer1_counter = 0;
	CLEAR_ICU_FLAG(); // clear ICP flag
	ICU_Falling_Edge(); // Set ICU to falling edge trigger

	/* Wait for falling edge from ECHO */
	while(!(TIFR_REG & (1<<ICF1_PIN)));
	/* Read ICU Register */
	ICR_Reg_Value = (u16)(ICR1L_REG + (ICR1H_REG << 8));
	CLEAR_ICU_FLAG(); // Clear ICU interrupt flag

	/* Get total time for logic HIGH */
	Elapsed_Time = (u32)(ICR_Reg_Value + (65535 * timer1_counter));

	/* Calculate distance */
	/* 8MHZ Timer Frequency, Speed of Sound = 343 m/s */
	Real_Distance = (f64)Elapsed_Time / 466.47;
	*Copy_f64Sensor_Reading = Real_Distance;
}
