#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"DIO_interface.h"
#include	"DIO_private.h"
#include	"DIO_config.h"





void	DIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction)
{
	/*		Range Check 		*/
	if(port < 3 && pin < 16)
	{
		if(pin<8)	/*		Low	(PIN0:PIN7) CRL	*/
		{
			switch(port)
			{
				case	PORTA	:
				/*		Clear the 4 bits before writing		*/
				GPIOA_CRL &= ~((0b1111)<<(PIN * 4));
				/*		Assign the Direction value			*/
				GPIOA_CRL |=  ((Direction)<<(PIN * 4));
				break;
				
				case	PORTB	:
				/*		Clear the 4 bits before writing		*/
				GPIOB_CRL &= ~((0b1111)<<(PIN * 4));
				/*		Assign the Direction value			*/
				GPIOB_CRL |=  ((Direction)<<(PIN * 4));
				break;
				
				case	PORTC	:
				/*		Clear the 4 bits before writing		*/
				GPIOC_CRL &= ~((0b1111)<<(PIN * 4));
				/*		Assign the Direction value			*/
				GPIOC_CRL |=  ((Direction)<<(PIN * 4));
				break;
			}
		}else if(pin<16)	/*		Low	(PIN8:PIN15) CRL	*/
		{
			pin -= 8;
			switch(port)
			{
				case	PORTA	:
				/*		Clear the 4 bits before writing		*/
				GPIOA_CRH &= ~((0b1111)<<(PIN * 4));
				/*		Assign the Direction value			*/
				GPIOA_CRH |=  ((Direction)<<(PIN * 4));
				break;
				
				case	PORTB	:
				/*		Clear the 4 bits before writing		*/
				GPIOB_CRH &= ~((0b1111)<<(PIN * 4));
				/*		Assign the Direction value			*/
				GPIOB_CRH |=  ((Direction)<<(PIN * 4));
				break;
				
				case	PORTC	:
				/*		Clear the 4 bits before writing		*/
				GPIOC_CRH &= ~((0b1111)<<(PIN * 4));
				/*		Assign the Direction value			*/
				GPIOC_CRH |=  ((Direction)<<(PIN * 4));
				break;
			}

		}
	}else{/*	Return Error	*/}
}
void	DIO_voidSetPinValue(u8 port, u8 pin, u8 Value)
{
	/*		Range Check 		*/
	if(port < 3 && pin < 16)
	{
		if(Value == GPIO_HIGH)
		{
			switch(port)
			{
				case	PORTA	:	SET_BIT(GPIOA_ODR,pin);	break;
				case	PORTB	:	SET_BIT(GPIOB_ODR,pin);	break;
				case	PORTC	:	SET_BIT(GPIOC_ODR,pin);	break;
			}
		}
		else if(Value == GPIO_LOW)
		{
			switch(port)
			{
				case	PORTA	:	CLR_BIT(GPIOA_ODR,pin);	break;
				case	PORTB	:	CLR_BIT(GPIOB_ODR,pin);	break;
				case	PORTC	:	CLR_BIT(GPIOC_ODR,pin);	break;
			}			
		}
		
	}else{/*	Return Error	*/}
	
}
u8		DIO_u8GetPinValue(u8 port, u8 pin)
{
	/*		Range Check 		*/
	if(port < 3 && pin < 16)
	{
		u8	Local_u8Val = 0x99;
			switch(port)
			{
				case	PORTA	:	Local_u8Val	=	GET_BIT(GPIOA_IDR,pin);	break;
				case	PORTB	:	Local_u8Val	=	GET_BIT(GPIOB_IDR,pin);	break;
				case	PORTC	:	Local_u8Val	=	GET_BIT(GPIOC_IDR,pin);	break;
			}
	}else{/*	Return Error	*/}	
	return local_u8Val;
}