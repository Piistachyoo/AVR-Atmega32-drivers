/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : SSD_private.h                                  	     */
/* Date          : Mar 3, 2023	                                         */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_

// Conditions
#define USE_DOT		0
#define NO_DOT		1


// Enum for SS PINS
enum SS_PINS
{
	SS_A,
	SS_B,
	SS_C,
	SS_D,
	SS_E,
	SS_F,
	SS_G,
	SS_DOT
};

// Enum for SS Numbers
enum SS_NUMBERS
{
	SS_ZERO,
	SS_ONE,
	SS_TWO,
	SS_THREE,
	SS_FOUR,
	SS_FIVE,
	SS_SIX,
	SS_SEVEN,
	SS_EIGHT,
	SS_NINE
};


#endif /* HAL_SSD_SSD_PRIVATE_H_ */
