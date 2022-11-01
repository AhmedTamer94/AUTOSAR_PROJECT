/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "Std_Types.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW


/* Description: 1. Fill the led configurations structure 
 *              2. Set the PIN direction which the led is connected as OUTPUT pin
 *		3. Initialize the led ON/OFF according to the initial value 
 */
void LED_init(void);

/* Description: Set the LED state to ON */
void LED_setOn(void);

/* Description: Set the LED state to OFF */
void LED_setOff(void);

/*Description: Toggle the LED state */
void LED_toggle(void);

/* Description: Refresh the LED state */
void LED_refreshOutput(void);

#endif /* LED_H */
