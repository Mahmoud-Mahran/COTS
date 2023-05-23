//#include	"Std_Types.h"
//#include	"Bit_Math.h"
//#include 	"DIO_interface.h"
//#include	"RCC_interface.h"
//#include	"lcd.h"
//
//int main() {
//	RCC_voidSysClkInt();
//	//Enable RCC for GPIOs
//	RCC_voidEnablePerClk(RCC_APB2, 2);
//	RCC_voidEnablePerClk(RCC_APB2, 3);
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//	LCD_init();
//	_delay_ms(50);
//
//	while (1) {
//		LCD_send_command(CLEAR_SC);
//		/*		Drawing the Base		*/
//		LCD_send_char(79);
//		LCD_GO_TO_cursor(2, 0);
//		LCD_send_char(79);
//		/*		Drawing the Body		*/
//		for (int i = 1; i < 15; i++) {
//			LCD_GO_TO_cursor(1, i);
//			LCD_send_char(161);
//			LCD_GO_TO_cursor(2, i);
//			LCD_send_char(223);
//		}
//		/*		Drawing the Head		*/
//		LCD_GO_TO_cursor(1, 15);
//		LCD_send_char(205);
//		LCD_GO_TO_cursor(2, 15);
//		LCD_send_char(47);
//		_delay_ms(800);
//	}
//	return 0;
//}
