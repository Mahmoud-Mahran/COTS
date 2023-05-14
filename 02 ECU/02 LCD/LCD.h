
#ifndef LCD_H_
#define LCD_H_

void LCD_init(void);
void LCD_send_command(u8 command);
void LCD_send_char(u8 data);
void LCD_send_string(char *data);
void LCD_GO_TO_cursor(u8 Row ,u8 column );



#define FUNC_SET			0b00111000
#define FUNC_SET_4BIT		0x28
#define DISPLAY_ON			0b00001111
#define CLEAR_SC			0b00000001
#define ENTRY_M_SET			0b00000110
#define NEXT_LINE			0b11000000
#define	BIT_4				0
#define	BIT_8				1



#endif /* LCD_H_ */
