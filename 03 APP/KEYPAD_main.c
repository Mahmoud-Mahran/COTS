//
//#include 	"01 MCAL/01 GPIO/DIO_interface.h"
//#include	"01 MCAL/00 RCC/RCC_interface.h"
//#include	"02 ECU/03 KEYPAD/KEYPAD_interface.h"
//#include	"02 ECU/03 KEYPAD/KEYPAD_config.h"
//#include	"02 ECU/02 LCD/LCD.h"
///*int main(){
//	RCC_voidSysClkInt();
//		//Enable RCC
//	RCC_voidEnablePerClk(RCC_APB2,2);
//	RCC_voidEnablePerClk(RCC_APB2,3);
//	RCC_voidEnablePerClk(RCC_APB2,4);
//	KEYBAD_voidInit();
//	LCD_init_8BIT();
//	//LCD_send_string("HELLO!");
//	while(1){
//		u8 pressed = 0xff;
//		pressed = KEYBAD_u8GetPressed();
//		if(pressed != 0xff){
//			LCD_send_char(pressed);
//			if(pressed == '0') LCD_init_8BIT();
//			_delay_ms(500);
//		}
//
//
//	}
//	return 0;
//}*/
