//#include 	<Bit_Math.h>
//#include 	<Std_Types.h>
//#include 	"DIO_interface.h"
//#include	"RCC_interface.h"
//#include	"SEG_interface.h"
//#include	"SEG_config.h"
//int main()
// {
// //System Clock Init
// RCC_voidSysClkInt();
// //Enable RCC for GPIOC
// switch (SEG_port){
// case PORTA: RCC_voidEnablePerClk(RCC_APB2,2);break;
// case PORTB: RCC_voidEnablePerClk(RCC_APB2,3);break;
// case PORTC: RCC_voidEnablePerClk(RCC_APB2,4);break;
// }
// for(int i = 3; i < 10; i++) DIO_voidSetPinDirection(SEG_port, i, GPIO_OUTPUT_2MHZ_PP);
// for(int i = 3; i < 10; i++) DIO_voidSetPinValue(SEG_port, i, 1);
//
//
// while(1)
// {
// //for(int k = 9;k>=0;k--){
// for(int i = 3; i < 10; i++) DIO_voidSetPinValue(SEG_port, i, GET_BIT(SEG_u8DisplayNum(0),i-3));
// _delay_ms(1000);//}
//
// }
// return 0;
// }
