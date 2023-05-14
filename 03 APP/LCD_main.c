//#include	"00 LIB/Std_Types.h"
//#include	"00 LIB/Bit_Math.h"
//#include 	"01 MCAL/01 GPIO/DIO_interface.h"
//#include	"01 MCAL/00 RCC/RCC_interface.h"
//#include	"02 ECU/02 LCD/lcd.h"
//
//
//int main()
//{
//	RCC_voidSysClkInt();
//		//Enable RCC for GPIOC
//	RCC_voidEnablePerClk(RCC_APB2,2);
//	RCC_voidEnablePerClk(RCC_APB2,3);
//	RCC_voidEnablePerClk(RCC_APB2,4);
//	LCD_init();
//	_delay_ms(50);
//
//	while(1)
//	{
//		LCD_send_command(CLEAR_SC);
//		/*		Drawing the Base		*/
//		LCD_send_char(79);
//		Lcd_goTo_cursor(2, 0);
//		LCD_send_char(79);
//		/*		Drawing the Body		*/
//		for(int i = 1; i < 15; i++){
//			Lcd_goTo_cursor(1, i);
//			LCD_send_char(161);
//			Lcd_goTo_cursor(2, i);
//			LCD_send_char(223);
//		}
//		/*		Drawing the Head		*/
//		Lcd_goTo_cursor(1, 15);
//		LCD_send_char(205);
//		Lcd_goTo_cursor(2, 15);
//		LCD_send_char(47);
//		_delay_ms(800);
//	}
//	return 0;
//}
