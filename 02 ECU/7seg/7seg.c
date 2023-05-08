#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
#include 	"7seg.h"


void 7seg_init(void){
	DIO_voidSetPinDirection(DATA_PORT, A, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT, B, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT, C, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT, D, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT, E, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT, F, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT, G, GPIO_OUTPUT_2MHZ_PP);
    DIO_voidSetPinDirection(DATA_PORT, H, GPIO_OUTPUT_2MHZ_PP);
}

void 7seg_number(u8 number) {
	switch(number){
		case 0 :  DIO_voidSethlafPortval(DATA_PORT , 0xc0) ; break ;
		case 1 :  DIO_voidSethlafPortval(DATA_PORT , 0xf9) ; break ;
		case 2 :  DIO_voidSethlafPortval(DATA_PORT , 0xa4) ; break ;
		case 3 :  DIO_voidSethlafPortval(DATA_PORT , 0xb0) ; break ;
		case 4 :  DIO_voidSethlafPortval(DATA_PORT , 0x99) ; break ;
		case 5 :  DIO_voidSethlafPortval(DATA_PORT , 0x92) ; break ;
		case 6 :  DIO_voidSethlafPortval(DATA_PORT , 0x82) ; break ;
		case 7 :  DIO_voidSethlafPortval(DATA_PORT , 0xf8) ; break ;
		case 8 :  DIO_voidSethlafPortval(DATA_PORT , 0x80) ; break ;
		case 9 :  DIO_voidSethlafPortval(DATA_PORT , 0x90) ; break ;
	}
}