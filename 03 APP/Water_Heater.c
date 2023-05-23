//#include 	<00 LIB/Bit_Math.h>
//#include 	<00 LIB/Std_Types.h>
//#include 	"01 MCAL/00 RCC/RCC_interface.h"
//#include 	"01 MCAL/01 GPIO/DIO_interface.h"
//#include 	"01 MCAL/02 NVIC/NVIC_interface.h"
//#include 	"01 MCAL/06 ADC/ADC_interface.h"
//#include 	"01 MCAL/03 EXTI/EXTI_interface.h"
//#include	"02 ECU/02 LCD/LCD.h"
//void EXTI_Stop_pressed(void);
//void EXTI_down_pressed(void);
//void EXTI_up_pressed(void);
//#include 	<stdio.h>
//typedef enum {
//	IDLE,INIT,NORMAL,SETTING,OFF
//}SYS_MODE;
//u16 required_temp = 25;
//int main(void) {
//	SYS_MODE mode = IDLE;
//	//System Clock Init
//	RCC_voidSysClkInt();
//	//Enable RCC for GPIOs, AFIO & ADC
//	RCC_voidEnablePerClk(RCC_APB2, 2);
//	RCC_voidEnablePerClk(RCC_APB2, 3);
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//	RCC_voidEnablePerClk(RCC_APB2, 0);
//	RCC_voidEnablePerClk(RCC_APB2, 9);
//	//init NVIC
//	NVIC_voidInit();
//	//set on/off button,temp up and temp down callbacks
//	EXTI_voidSetCallBack(EXTI_Stop_pressed, 0);
//	EXTI_voidSetCallBack(EXTI_up_pressed, 1);
//	EXTI_voidSetCallBack(EXTI_down_pressed, 2);
//	//init interrupts
//	EXTI_voidInit();
//	//enable exti0
//	NVIC_voidEnablePerInt(6);
//	//init GPIOS for system control
//	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);
//	DIO_voidSetPinValue(PORTA, PIN0, GPIO_HIGH);
//	DIO_voidSetPinValue(PORTA, PIN1, GPIO_HIGH);
//	DIO_voidSetPinValue(PORTA, PIN2, GPIO_HIGH);
//	DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
//	while (1) {
//		switch (mode){
//		case IDLE:
//			break;
//		case INIT:
//			LCD_init();
//			ADC_Init();
//			ADC_Start();
//			LCD_send_string("Temp = ");
//			LCD_GO_TO_cursor(1, 9);
//			LCD_send_char(223);
//			LCD_send_char('C');
//			mode = NORMAL;
//			break;
//		case NORMAL:
//			u16 temp;
//			u16 val;
//			char c[6];
//			val = ADC_Read();
//			temp = ((1.43 - ((float)(3.3*val/(float)4095))) / 0.0043) + 25;
//			sprintf(c, "%d", (int) temp);
//			LCD_GO_TO_cursor(1, 7);
//			LCD_send_string("  ");
//			LCD_GO_TO_cursor(1, 7);
//			LCD_send_string(c);
//			NVIC_voidEnablePerInt(7);
//			NVIC_voidEnablePerInt(8);
//			_delay_ms(2000);
//			break;
//		case SETTING:
//			/*set temp and disable up/down interrupts*/
//
//
//			break;
//		case OFF:
//			/*turn all off and go to idle*/
//			NVIC_voidDisablePerInt(7);
//			NVIC_voidDisablePerInt(8);
//			break;
//		default:
//			mode = IDLE;
//			break;
//		}
//
//	}
//}
//
//
//void EXTI_Stop_pressed(void){
//	mode = OFF;
//}
//
//void EXTI_down_pressed(void){
//	if(mode == SETTING){
//		required_temp--;
//	}else if(mode != SETTING){
//		mode = SETTING;
//	}
//}
//
//void EXTI_up_pressed(void){
//	if(mode == SETTING){
//		required_temp++;
//	}else if(mode != SETTING){
//		mode = SETTING;
//	}
//}
//
