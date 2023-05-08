


#ifndef 7seg_H_
#define 7seg_H_
//include part
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"

void 7seg_init(void);
void 7seg_number(u8 number) ;

#define   DATA_PORT      PORTA
#define   A              PIN0
#define   B              PIN1
#define   C              PIN2
#define   D              PIN3
#define   E              PIN4
#define   F              PIN5
#define   G              PIN6
#define   H              PIN7
#endif /* KEYPAD_H_ */
