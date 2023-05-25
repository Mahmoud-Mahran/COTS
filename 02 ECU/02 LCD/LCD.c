#include 	<Bit_Math.h>
#include 	<Std_Types.h>
#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"LCD_config.h"
#include 	"LCD.h"

void LCD_init(void) {
	u8 Local_temp[8][2] = { { D0_PORT, D0_PIN }, { D1_PORT, D1_PIN }, { D2_PORT,
			D2_PIN }, { D3_PORT, D3_PIN }, { D4_PORT, D4_PIN }, { D5_PORT,
			D5_PIN }, { D6_PORT, D6_PIN }, { D7_PORT, D7_PIN } };
	DIO_voidSetPinDirection(RS_PORT, RS_PIN, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(RW_PORT, RW_PIN, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(E_PORT, E_PIN, GPIO_OUTPUT_2MHZ_PP);
#if	(LCD_MODE == BIT_4)
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(Local_temp[i + 4][0], Local_temp[i + 4][1],
				GPIO_OUTPUT_2MHZ_PP);
	}
	_delay_ms(50);
	LCD_send_command(FUNC_SET_4BIT);
#endif
#if	(LCD_MODE == BIT_8)
	for(int i = 0; i < 8; i++){
		DIO_voidSetPinDirection(Local_temp[i][0],Local_temp[i][1],GPIO_OUTPUT_2MHZ_PP);
	}
	_delay_ms(50);
	LCD_send_command(FUNC_SET);
#endif
	_delay_ms(5);
	LCD_send_command(DISPLAY_ON);
	_delay_ms(5);
	LCD_send_command(CLEAR_SC);
	_delay_ms(5);
	LCD_send_command(ENTRY_M_SET);
}

void LCD_send_command(u8 command) {
	u8 Local_temp[8][2] = { { D0_PORT, D0_PIN }, { D1_PORT, D1_PIN }, { D2_PORT,
			D2_PIN }, { D3_PORT, D3_PIN }, { D4_PORT, D4_PIN }, { D5_PORT,
			D5_PIN }, { D6_PORT, D6_PIN }, { D7_PORT, D7_PIN } };

	DIO_voidSetPinValue(RS_PORT, RS_PIN, GPIO_LOW);
	DIO_voidSetPinValue(RW_PORT, RW_PIN, GPIO_LOW);
#if	(LCD_MODE == BIT_4)
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinValue(Local_temp[i + 4][0], Local_temp[i + 4][1],
				GET_BIT(command, i + 4));

	}
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_LOW);
	_delay_ms(5);
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinValue(Local_temp[i + 4][0], Local_temp[i + 4][1],
				GET_BIT(command, i));

	}
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_LOW);
	_delay_ms(5);
#endif

#if	(LCD_MODE == BIT_8)
	for(int i = 0; i < 8; i++){
		DIO_voidSetPinValue(Local_temp[i][0],Local_temp[i][1],GET_BIT(command, i));
	}
	DIO_voidSetPinValue(E_PORT,E_PIN,GPIO_HIGH);
	_delay_ms(50);
#endif
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_LOW);
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_HIGH);
}

void LCD_send_char(u8 data) {
	u8 Local_temp[8][2] = { { D0_PORT, D0_PIN }, { D1_PORT, D1_PIN }, { D2_PORT,
			D2_PIN }, { D3_PORT, D3_PIN }, { D4_PORT, D4_PIN }, { D5_PORT,
			D5_PIN }, { D6_PORT, D6_PIN }, { D7_PORT, D7_PIN } };

	DIO_voidSetPinValue(RS_PORT, RS_PIN, GPIO_HIGH);
	DIO_voidSetPinValue(RW_PORT, RW_PIN, GPIO_LOW);
	_delay_ms(5);

#if	(LCD_MODE == BIT_4)
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinValue(Local_temp[i + 4][0], Local_temp[i + 4][1],
				GET_BIT(data, i + 4));
	}
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_LOW);
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinValue(Local_temp[i + 4][0], Local_temp[i + 4][1],
				GET_BIT(data, i));
	}

#endif
#if	(LCD_MODE == BIT_8)
	for(int i = 0; i < 8; i++){
		DIO_voidSetPinValue(Local_temp[i][0],Local_temp[i][1],GET_BIT(data, i));
	}
#endif
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(E_PORT, E_PIN, GPIO_LOW);
}
void LCD_send_string(char *data) {
	int i = 0;
	while (data[i] != '\0') {
		if (i == 16)
			LCD_send_command(NEXT_LINE);
		LCD_send_char(data[i]);
		_delay_ms(5);
		i++;
	}
}

void LCD_GO_TO_cursor(u8 Row, u8 column) {

	if (Row < 3 && column < 17) {
		switch (Row) {
		case 1:
			LCD_send_command(0X80 + column);
			break;
		case 2:
			LCD_send_command(0XC0 + column);
			break;
		}
	}
}
