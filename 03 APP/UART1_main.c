//#include 	<00 LIB/Bit_Math.h>
//#include 	<00 LIB/Std_Types.h>
//#include 	"01 MCAL/00 RCC/RCC_interface.h"
//#include 	"01 MCAL/01 GPIO/DIO_interface.h"
//#include 	"01 MCAL/07 UART/UART1_interface.h"
//int main(void) {
//	//u8 dat;
//	RCC_voidSysClkInt();
//	//Enable RCC for GPIOs
//	RCC_voidEnablePerClk(RCC_APB2, 2);
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//	RCC_voidEnablePerClk(RCC_APB2, 14);
//	RCC_voidEnablePerClk(RCC_APB2, 0);
//	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_2MHZ_AFPP);
//	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_FLOAT);
//	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);
//	DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
//	UART_init();
//	UART_enableTX();
//	UART_enableRX();
//	u8 temp[] = "uart is working fine, wow";
//
//	while (1) {
//		for(int i = 0; i <25; i++){
//		//UART_TXdata('A');
//			UART_TXdata(temp[i]);
//			_delay_ms(5);
//		}
//
//		UART_TXdata('\n');
////		if(UART_RXdata() == 'A'){
////			DIO_voidSetPinValue(PORTC, PIN13, !DIO_u8GetPinValue(PORTC, PIN13));
////		}
//		_delay_ms(1000);
//	}
//
//}
