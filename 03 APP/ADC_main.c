#include 	<00 LIB/Bit_Math.h>
#include 	<00 LIB/Std_Types.h>
#include 	"01 MCAL/00 RCC/RCC_interface.h"
#include 	"01 MCAL/01 GPIO/DIO_interface.h"
#include 	"01 MCAL/06 ADC/ADC_interface.h"
#include	"01 MCAL/06 ADC/ADC_private.h"
#include	"02 ECU/02 LCD/LCD.h"

#include 	<stdio.h>
int main(void)
{
	u16	val;
	char	c[6];
			//System Clock Init
	RCC_voidSysClkInt();
			//Enable RCC for GPIOs
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	RCC_voidEnablePerClk(RCC_APB2,4);
	RCC_voidEnablePerClk(RCC_APB2,9);
	DIO_voidSetPinDirection(PORTB, PIN1, GPIO_INPUT_ANALOG);
	LCD_init();
	ADC_Init();
	ADC_Start();
	LCD_send_string("R = ");
	while (1)
	{

		val = ADC_Read();
		sprintf(c, "%d", (int)val);
		LCD_GO_TO_cursor(1,4);
		LCD_send_string("    ");
		LCD_GO_TO_cursor(1,4);
		LCD_send_string(c);
		_delay_ms(10);
	}

}
