/*
 * KEYPAD.h
 *
 * Created: 3/13/2023 10:47:58 PM
 *  Author: ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
//include part
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/delay/DELAY.h"
//initialize function  
void KEYPAD_init(void );
//read function  
void KEYPAD_getpresskey(uint8_t *ptr);

#define KEY_PORT     PORTC 


#endif /* KEYPAD_H_ */