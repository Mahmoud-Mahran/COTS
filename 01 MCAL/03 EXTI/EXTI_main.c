#include	"lib/Std_Types.h"
#include	"lib/Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"NVIC_interface.h"
#include	"EXTI_interface.h"
void		EXTI_callBack(void);

int main(void)
{
	/*	System Clock Init			*/
	RCC_voidSysClkInt();
	/*	Enable RCC 					*/
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	RCC_voidEnablePerClk(RCC_APB2,4);
	NVIC_voidInit();
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
	/*	A1 Direction 	"Input Pull-up"	*/
	DIO_voidSetPinDirection(PORTA,PIN1,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA,PIN1,GPIO_HIGH);
	EXTI0_voidSetCallBack(EXTI_callBack, 1);
	EXTI_voidInit();
	NVIC_voidEnablePerInt(7);
	while(1)
	{

	}
	return 0;
}
//void 	__vector_1(void)
void	EXTI_callBack(void)
{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,!DIO_u8GetPinValue(PORTC,PIN13));
		_delay_ms(500);
}

