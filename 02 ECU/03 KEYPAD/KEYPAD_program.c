#include 	<00 LIB/Bit_Math.h>
#include 	<00 LIB/Std_Types.h>
#include	"02 ECU/03 KEYPAD/KEYPAD_interface.h"
#include	"02 ECU/03 KEYPAD/KEYPAD_config.h"
#include	"01 MCAL/01 GPIO/DIO_interface.h"

u8 keypad_chars[4][5] = { "147*", "2580", "369#", "ABCD" };
int rows[4][2] = { { row_1_port, row_1_pin }, { row_2_port, row_2_pin }, {
		row_3_port, row_3_pin }, { row_4_port, row_4_pin } };
int cols[4][2] = { { column_1_port, column_1_pin }, { column_2_port,
		column_2_pin }, { column_3_port, column_3_pin }, { column_4_port,
		column_4_pin } };

void KEYBAD_voidInit(void) {
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(rows[i][0], rows[i][1], GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinValue(rows[i][0], rows[i][1], 0);
		DIO_voidSetPinDirection(cols[i][0], cols[i][1],
				GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinValue(cols[i][0], cols[i][1], 1);
	}
}

void KEYBAD_toggle(void) {
	for (int i = 0; i < 4; i++) {
		DIO_voidSetPinDirection(rows[i][0], rows[i][1],
				GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinValue(rows[i][0], rows[i][1], 1);
		DIO_voidSetPinDirection(cols[i][0], cols[i][1], GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinValue(cols[i][0], cols[i][1], 0);
	}
}
u8 KEYBAD_u8GetPressed(void) {
	u8 pressed = 0xff;
	for (int i = 0; i < 4; i++) {
		if (DIO_u8GetPinValue(cols[i][0], cols[i][1]) == 0) {
			for (int j = 0; j < 4; j++) {
				DIO_voidSetPinValue(rows[j][0], rows[j][1], GPIO_HIGH);
				if (DIO_u8GetPinValue(cols[i][0], cols[i][1]) == 1)
					pressed = keypad_chars[i][j];
				DIO_voidSetPinValue(rows[j][0], rows[j][1], GPIO_LOW);
			}
		}
	}

	return pressed;

}

