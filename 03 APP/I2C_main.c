//#include "Std_Types.h"
//#include "Bit_Math.h"
//#include "RCC_interface.h"
//#include "DIO_interface.h"
//#include "I2C_interface.h"
//#include "lcd.h"
//
//
//void I2C_BUSY_FLAG_WORKAROUND(void);
//int main(){
//	RCC_voidSysClkInt();
//	//Enable RCC for GPIOs
//	RCC_voidEnablePerClk(RCC_APB2, 2);
//	RCC_voidEnablePerClk(RCC_APB2, 3);
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//	//Enable RCC i2c and AF
//	RCC_voidEnablePerClk(RCC_APB1, 21);
//	RCC_voidEnablePerClk(RCC_APB2, 0);
//
//	//u8 data[16] = "I2C is easy :)  ";
//	u8 r_data[16]  = {0};
//	u8 eeeprom_addr = 0b10100000;
//	LCD_init();
//	_delay_ms(500);
//	I2C_BUSY_FLAG_WORKAROUND();
//
//	I2C_init_master();
//	_delay_ms(20);
////	I2C_start();
////	_delay_ms(5);
////	I2C_add_select(eeeprom_addr);
////	_delay_ms(5);
////	I2C_Write_Byte(0x00);
////	_delay_ms(5);
////	for(int i = 0;i < 16; i++){
////	I2C_Write_Byte(data[i]);
////	_delay_ms(5);
////	}
////	I2C_stop();
////	_delay_ms(200);
//	I2C_start();
//	//_delay_ms(1);
//	I2C_add_select(eeeprom_addr);
//	//_delay_ms(5);
//	I2C_Write_Byte(0x00);
//	//_delay_ms(5);
//	I2C_start();
//	//_delay_ms(5);
//	I2C_add_select(eeeprom_addr + 1);
//	//_delay_ms(5);
//	for(int i = 0;i < 16; i++){
//	I2C_Read_Byte(&r_data[i]);
//	//_delay_ms(1);
//	}
//	I2C_stop();
//	while (1)
//	{
//		LCD_send_command(CLEAR_SC);
//		for(int i = 0;i < 16; i++){
//		LCD_send_char(r_data[i]);
//		_delay_ms(5);
//		}
//		_delay_ms(1000);
//	}
//
//		return 0;
//}
//void I2C_BUSY_FLAG_WORKAROUND(void){
//	//1
//	I2C_disable_pe();
//	//2
//	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_OD);
//	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_OD);
//	DIO_voidSetPinValue(PORTB, PIN6,GPIO_HIGH);
//	DIO_voidSetPinValue(PORTB, PIN7,GPIO_HIGH);
//	//4
//	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_OD);
//	DIO_voidSetPinValue(PORTB, PIN7,GPIO_LOW);
//	//6
//	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_OD);
//	DIO_voidSetPinValue(PORTB, PIN6,GPIO_LOW);
//	//8
//	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_OD);
//	DIO_voidSetPinValue(PORTB, PIN6,GPIO_HIGH);
//	//10
//	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_OD);
//	DIO_voidSetPinValue(PORTB, PIN7,GPIO_HIGH);
//	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_AFOD);
//	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_AFOD);
//	I2C_reset_pe();
//	_delay_ms(20);
//}
