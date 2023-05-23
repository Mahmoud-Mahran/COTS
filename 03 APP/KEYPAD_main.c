//#include 	<Bit_Math.h>
//#include 	<Std_Types.h>
//#include 	"DIO_interface.h"
//#include	"RCC_interface.h"
//#include	"KEYPAD_interface.h"
//#include	"LCD.h"
//int main(){
// RCC_voidSysClkInt();
// //Enable RCC
// RCC_voidEnablePerClk(RCC_APB2,2);
// RCC_voidEnablePerClk(RCC_APB2,3);
// RCC_voidEnablePerClk(RCC_APB2,4);
// KEYBAD_voidInit();
// LCD_init();
// //LCD_send_string("HELLO!");
// while(1){
// u8 pressed = 0xff;
// pressed = KEYBAD_u8GetPressed();
// if(pressed != 0xff){
// LCD_send_char(pressed);
// if(pressed == '0') LCD_init();
// _delay_ms(500);
// }
//
//
// }
// return 0;
// }
