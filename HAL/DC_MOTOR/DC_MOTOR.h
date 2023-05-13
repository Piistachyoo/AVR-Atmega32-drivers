/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project		 : Obstacle_Avoidance_Car								 */
/* File          : DC_MOTOR.h                                  	    	 */
/* Date          : May 12, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

/* Section : Includes */
#include "../../MCAL/ATMEGA32/DIO/DIO_interface.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	u8 motor_port	:2;
	u8 motor_pin1	:3;
	u8 motor_pin2	:3;
	u8 motor_en_pin	:3;
}dc_motor_t;

typedef enum{
	motor_direction_right,
	motor_direction_left
}motor_direction_t;

/* Section : Function Declarations */
void DC_MOTOR_vInit(const dc_motor_t *_MOTOR);
void DC_MOTOR_Turn_Right(const dc_motor_t *_MOTOR);
void DC_MOTOR_Turn_Left(const dc_motor_t *_MOTOR);
void DC_MOTOR_Turn_Off(const dc_motor_t *_MOTOR);
void DC_MOTOR_Turn_On(const dc_motor_t *_MOTOR, motor_direction_t _direction);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
