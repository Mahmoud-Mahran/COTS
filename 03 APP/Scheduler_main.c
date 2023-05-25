//#include	"Std_Types.h"
//#include	"Bit_Math.h"
//#include	 <Scheduler_prototype.h>
//#include	"RCC_interface.h"
//#include	"DIO_interface.h"
//#include	"STK_interface.h"
//#include 	"LCD.h"
//
//
//void T1_func(void);
//void T2_func(void);
//void T3_func(void);
//
//
//
//int main() {
//
//	/*	System Clock Init			*/
//	RCC_voidSysClkInt();
//	/*	Enable RCC for GPIOS 		*/
//	RCC_voidEnablePerClk(RCC_APB2, 2);
//	RCC_voidEnablePerClk(RCC_APB2, 3);
//	RCC_voidEnablePerClk(RCC_APB2, 4);
//	LCD_init();
//	_delay_ms(50);
//	LCD_send_command(CLEAR_SC);
//	LCD_send_string("LCD running");
//	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
//	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);
//
//	/*	SysTick	Init				*/
//	STK_voidInit();
//
////	/*	Call Single Periodic 		*/
////	STK_voidSetIntervalPeriodic(1000000, ToggleLed);
//	Create_task("task1", 1, 1,5, T1_func);
//	Create_task("task2", 3, 2,10, T2_func);
//	Create_task("task3", 6, 3,15, T3_func);
//
//	STK_voidSetIntervalPeriodic(1000000,start_scheduler);
//
//	while (1) {
//
////		for(int i = 0; i < 3; i++){
////		running_f = 1;
////		STK_voidSetIntervalPeriodic(task_stack[i].periodicity * 1000000, task_stack[i].ptrfunc);
////		while(running_f);
////		}
//
//	}
//	return 0;
//}
//
//void T1_func(void){
//	LCD_send_command(CLEAR_SC);
//	LCD_send_string("I'm task 1");
//}
//void T2_func(void){
//	LCD_send_command(CLEAR_SC);
//	LCD_send_string("I'm task 2");
//}
//void T3_func(void){
//	LCD_send_command(CLEAR_SC);
//	LCD_send_string("I'm task 3");
//}
//
//
//
