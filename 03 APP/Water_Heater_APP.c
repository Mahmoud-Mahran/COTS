#include 	<Bit_Math.h>
#include 	<Std_Types.h>
#include 	"RCC_interface.h"
#include 	"DIO_interface.h"
#include 	"NVIC_interface.h"
#include 	"STK_interface.h"
#include 	"ADC_interface.h"
#include 	"EXTI_interface.h"
#include 	"I2C_interface.h"
#include 	"led.h"
#include	"LCD.h"
#include    "Water_heater.h"


//system mode
SYS_MODE mode = IDLE;
//required set temp
u8 required_temp = 60;
//current temp
u16 temp;
//flag to only update the temp in setting mode
u8 pressed = 0;
//workaround for the i2c's busyflag being set before sending start, preventing the entry of master mode
void I2C_BUSY_FLAG_WORKAROUND(void);

int main(void) {
	//System Clock Init
	RCC_voidSysClkInt();
	//Enable RCC for GPIOs, AFIO, ADC & I2C
	RCC_voidEnablePerClk(RCC_APB2, 2);
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 4);
	RCC_voidEnablePerClk(RCC_APB2, 0);
	RCC_voidEnablePerClk(RCC_APB2, 9);
	RCC_voidEnablePerClk(RCC_APB1, 21);
	_delay_ms(5);
	//init NVIC,STK
	NVIC_voidInit();
	_delay_ms(5);
	STK_voidInit();
	_delay_ms(5);
	//init GPIOS for system control
	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTA, PIN11, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA, PIN9, GPIO_HIGH);
	DIO_voidSetPinValue(PORTA, PIN10, GPIO_HIGH);
	DIO_voidSetPinValue(PORTA, PIN11, GPIO_HIGH);
	//indicator led
	LEDS green_led;
	green_led.pin= PIN5;
	green_led.port = PORTB;
	green_led.state = 0;
	LED_voidLED_init(&green_led);
	//set on/off button,temp up and temp down callbacks
	EXTI_voidSetCallBack(EXTI_Stop_pressed, 9);
	EXTI_voidSetCallBack(EXTI_up_pressed, 10);
	EXTI_voidSetCallBack(EXTI_down_pressed, 11);
	//init interrupts
	EXTI_voidInit();
	//enable exti0(stop button
	NVIC_voidEnablePerInt(23);
	u8 eeeprom_addr = 0b10100000;
	u8 r_temp = 0;
	/**************************************************************************/
	/**							MAIN PROGRAM LOGIC							 **/
	/**************************************************************************/
	I2C_BUSY_FLAG_WORKAROUND();
	I2C_start();
	_delay_ms(1);
	I2C_add_select(eeeprom_addr);
	_delay_ms(5);
	I2C_Write_Byte(0x00);
	_delay_ms(5);
	I2C_start();
	_delay_ms(5);
	I2C_add_select(eeeprom_addr + 1);
	_delay_ms(5);
	I2C_Read_Byte(&r_temp);
	_delay_ms(1);
	I2C_stop();
	if( r_temp < 75 &&  r_temp > 35)
	{
		required_temp = r_temp;
	}
	LCD_init();
	_delay_ms(50);
	while (1) {
		switch (mode){
		case IDLE:
			break;
		case INIT:
			LCD_send_command(CLEAR_SC);
			ADC_Init();
			ADC_Start();
			LCD_send_string("Temp = ");
			LCD_GO_TO_cursor(1, 9);
			LCD_send_char(223);
			LCD_send_char('C');
			mode = NORMAL;
			break;
		case NORMAL:
			LCD_GO_TO_cursor(1, 7);
			LCD_send_string("  ");
			LCD_GO_TO_cursor(1, 7);
			LCD_send_char( (((u8)temp / 10) + '0') );
			LCD_send_char( (((u8)temp % 10) + '0') );
			LCD_GO_TO_cursor(2, 3);
			LCD_send_string("                ");
			NVIC_voidEnablePerInt(40);
//			NVIC_voidEnablePerInt(8);
			STK_voidSetIntervalPeriodic(100000, vRead_ADC);
			if( ( temp + 5 ) < required_temp ){
				LCD_GO_TO_cursor(2, 3);
				LCD_send_string("                ");
				LCD_GO_TO_cursor(2, 3);
				LCD_send_string("HEATING ON");
				LED_voidLED_on(&green_led);			}
			if( ( temp - 5 ) > required_temp ){
				LCD_GO_TO_cursor(2, 3);
				LCD_send_string("                ");
				LCD_GO_TO_cursor(2, 3);
				LCD_send_string("COOLING ON");
				LED_voidToggle(&green_led);
			}
			_delay_ms(1000);
			break;
		case SETTING:
			/*set temp and disable up/down interrupts*/
			if(pressed == 0){
			LCD_send_command(CLEAR_SC);
			LCD_send_string("Req_Temp = ");
			LCD_GO_TO_cursor(1, 13);
			LCD_send_char(223);
			LCD_send_char('C');
			LCD_GO_TO_cursor(2, 1);
			LCD_send_string("                ");
			LCD_GO_TO_cursor(2, 1);
			LCD_send_string("SETTING MODE");
			pressed = 1;
			}
			if( required_temp > 75 ){
				required_temp = 75;
			} else if( required_temp < 35 ){
				required_temp = 35;
			}
			LCD_GO_TO_cursor(1, 11);
			LCD_send_string("  ");
			LCD_GO_TO_cursor(1, 11);
			LCD_send_char( ((required_temp / 10) + '0') );
			LCD_send_char( ((required_temp % 10) + '0') );
			I2C_BUSY_FLAG_WORKAROUND();
			I2C_start();
			_delay_ms(5);
			I2C_add_select(eeeprom_addr);
			_delay_ms(5);
			I2C_Write_Byte(0x00);
			_delay_ms(5);
			I2C_Write_Byte(required_temp);
			_delay_ms(5);
			I2C_stop();
			STK_voidSetIntervalPeriodic(5000000, vMode_Switch_INIT);
			_delay_ms(1000);
			break;
		case OFF:
			/*turn all off and go to idle*/
			NVIC_voidDisablePerInt(7);
			NVIC_voidDisablePerInt(8);
			ADC_Stop();
			LCD_send_command(CLEAR_SC);
			mode = IDLE;
			break;
		default:
			mode = IDLE;
			break;
		}

	}
}

void I2C_BUSY_FLAG_WORKAROUND(void){
	//1
	I2C_disable_pe();
	//2
	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_OD);
	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_OD);
	DIO_voidSetPinValue(PORTB, PIN6,GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, PIN7,GPIO_HIGH);
	//4
	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_OD);
	DIO_voidSetPinValue(PORTB, PIN7,GPIO_LOW);
	//6
	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_OD);
	DIO_voidSetPinValue(PORTB, PIN6,GPIO_LOW);
	//8
	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_OD);
	DIO_voidSetPinValue(PORTB, PIN6,GPIO_HIGH);
	//10
	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_OD);
	DIO_voidSetPinValue(PORTB, PIN7,GPIO_HIGH);
	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_AFOD);
	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_AFOD);
	I2C_reset_pe();
	I2C_init_master();
	_delay_ms(20);
}
