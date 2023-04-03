/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : EXTI_private.h                                  	     */
/* Date          : Mar 27, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define MCUCR_REG	HWREG8(0x55)
#define MCUCSR_REG	HWREG8(0x54)
#define GICR_REG	HWREG8(0x5B)
#define GIFR_REG	HWREG8(0x5A)

#define GICR_INT0	6
#define GICR_INT1	7
#define GICR_INT2	5

#define MCUCR_INT0_M		0xFC
#define MCUCR_INT0_LOW		0x00
#define MCUCR_INT0_LOGICAL	0x01
#define MCUCR_INT0_FALLING	0x02
#define MCUCR_INT0_RISING	0x03

#define MCUCR_INT1_M		0xF3
#define MCUCR_INT1_LOW		0x00
#define MCUCR_INT1_LOGICAL	0x04
#define MCUCR_INT1_FALLING	0x08
#define MCUCR_INT1_RISING	0x0C

#define MCUCSR_INT2_M		0xBF
#define MCUCSR_INT2_FALLING	0x00
#define MCUCSR_INT2_RISING	0x40




#endif /* EXTI_EXTI_PRIVATE_H_ */
