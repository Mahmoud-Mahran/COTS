//#include	"00 LIB/Std_Types.h"
//#include	"00 LIB/Bit_Math.h"
//
//#include	"01 MCAL/00 RCC/RCC_interface.h"
//#include	"01 MCAL/01 GPIO/DIO_interface.h"
//
//#include	"01 MCAL/02 NVIC/NVIC_interface.h"
//void EXTI0_MyIRQHandler(void);
//
//int main(void) {
//	/*	System Clock Init			*/
//	RCC_voidSysClkInt();
//
//	/*	Enable RCC for GPIOC 		*/
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//
//	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
//	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);
//
//	/*	Interrupt Initialization	*/
//	NVIC_voidInit();
//
//	/*	Set pending Flag EXTI0		*/
//	NVIC_voidSetPendingFlag(6);
//
//	/*	NVIC EXTI0 Enable 			*/
//	NVIC_voidEnablePerInt(6);
//	while (1) {
//
//	}
//	return 0;
//}
////void 	__vector_1(void)
//void EXTI0_MyIRQHandler(void) {
//	/*		Led On		*/
//	DIO_voidSetPinValue(PORTC, PIN13, GPIO_LOW);
//	_delay_ms(1000);
//	/*		Led Off		*/
//	DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
//	_delay_ms(1000);
//	/*	Clear EXTI0 Flag	*/
//}
//
