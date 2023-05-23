//#include "Std_Types.h"
//#include "Bit_Math.h"
//#include "RCC_interface.h"
//#include "DIO_interface.h"
//#include "SPI_interface.h"
//
//
//
//
//int main(){
//		RCC_voidSysClkInt();
//		//Enable RCC for GPIOs
//		RCC_voidEnablePerClk(RCC_APB2, 2);
//		RCC_voidEnablePerClk(RCC_APB2, 3);
//		RCC_voidEnablePerClk(RCC_APB2, 4);
//		RCC_voidEnablePerClk(RCC_APB2, 12);
//		RCC_voidEnablePerClk(RCC_APB2, 0);
//		//nss,sck,miso,mosi
//		DIO_voidSetPinDirection(PORTA, PIN4,GPIO_OUTPUT_2MHZ_AFPP);
//		DIO_voidSetPinDirection(PORTA, PIN5,GPIO_OUTPUT_2MHZ_AFPP);
//		DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT);
//		DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_AFPP);
//		DIO_voidSetPinValue(PORTA, PIN4,GPIO_HIGH);
//
//		DIO_voidSetPinDirection(PORTC, PIN13,GPIO_OUTPUT_2MHZ_PP);
//		DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
//
//
//		SPI_init_master();
//		u8 temp = 0;
//		while (1) {
//			SPI_send_receive_master('A',&temp);
//
//			if(temp == 'A')
//				{
//				DIO_voidSetPinValue(PORTC, PIN13, !(DIO_u8GetPinValue(PORTC, PIN13)));
//				}
//			_delay_ms(1000);
//		}
//		return 0;
//}
