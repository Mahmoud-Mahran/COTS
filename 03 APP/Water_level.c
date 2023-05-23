//#include	"00 LIB/Std_Types.h"
//#include	"00 LIB/Bit_Math.h"
//
//#include	"01 MCAL/00 RCC/RCC_interface.h"
//#include	"01 MCAL/01 GPIO/DIO_interface.h"
//#include	"02 ECU/02 LCD/LCD.h"
//
//
//int main() {
//	//System Clock Init
//	RCC_voidSysClkInt();
//	//Enable RCC for GPIOC
//	RCC_voidEnablePerClk(RCC_APB2, 2);
//	RCC_voidEnablePerClk(RCC_APB2, 3);
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//	LCD_init();
//	//	C13 Direction 	"Output @ 2MHz Push Pull"
//	DIO_voidSetPinDirection(PORTA, PIN8, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinValue(PORTA, PIN8, GPIO_LOW);
//	DIO_voidSetPinValue(PORTA, PIN9, GPIO_LOW);
//	DIO_voidSetPinValue(PORTA, PIN10, GPIO_LOW);
//	while (1) {
//		if (DIO_u8GetPinValue(PORTA, PIN8) == 0
//				&& DIO_u8GetPinValue(PORTA, PIN9) == 0
//				&& DIO_u8GetPinValue(PORTA, PIN10) > 0) {
//			LCD_send_command(CLEAR_SC);
//			LCD_send_string("Water Level 25%");
//		}
//		if (DIO_u8GetPinValue(PORTA, PIN8) == 0
//				&& DIO_u8GetPinValue(PORTA, PIN9) > 0
//				&& DIO_u8GetPinValue(PORTA, PIN10) > 0) {
//			LCD_send_command(CLEAR_SC);
//			LCD_send_string("Water Level 50%");
//		}
//		if (DIO_u8GetPinValue(PORTA, PIN8) > 0
//				&& DIO_u8GetPinValue(PORTA, PIN9) > 0
//				&& DIO_u8GetPinValue(PORTA, PIN10) > 0) {
//			LCD_send_command(CLEAR_SC);
//			LCD_send_string("Water Level 75%");
//		}
//		if (DIO_u8GetPinValue(PORTA, PIN8) == 0
//				&& DIO_u8GetPinValue(PORTA, PIN9) == 0
//				&& DIO_u8GetPinValue(PORTA, PIN10) == 0) {
//			LCD_send_command(CLEAR_SC);
//			LCD_send_string("NO WATER, WOW!");
//		}
//		_delay_ms(2000);
//
//	}
//	return 0;
//}
//
