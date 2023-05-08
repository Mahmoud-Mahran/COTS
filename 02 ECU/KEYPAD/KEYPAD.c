/*
 * KEYPAD.c
 *
 * Created: 3/13/2023 10:48:13 PM
 *  Author: ahmed
 */ 

//include part 
#include "KEYPAD.h"

//initialize function
void KEYPAD_init(void){
	DIO_initport(KEY_PORT, 0x0F) ;
	//TURN PULL UP RESISTANCE 
	DIO_writeport(KEY_PORT, 0xFF) ;
}

const uint8_t keypad[4][4] ={
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'!','0','=','+'},
	};
//read function
void KEYPAD_getpresskey(uint8_t *ptr){
	volatile uint8_t row = 4 ;
  volatile	 uint8_t colm=0  ; 
   uint8_t x  = 1     ; 
   *ptr =0xff ;
	for (colm=0 ;colm<4 ; colm++)
	{
		DIO_writepin(KEY_PORT, colm , LOW) ;
		for (row=4;row<8;row++)
		{
		 DIO_readpin(KEY_PORT,row, &x);
		 if (x==0)
		 {
			 *ptr = keypad[row-4][colm] ;
			 x=1 ;
		 }
		}
		DIO_writepin(KEY_PORT, colm , HIGH) ;
		
	}
}
