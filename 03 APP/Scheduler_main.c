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
//	Task task_stack[3] = {0};
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
//	task_stack[0] = Create_task("task1", 1, 1,100, T1_func);
//	task_stack[1] = Create_task("task2", 5, 2,200, T2_func);
//	task_stack[2] = Create_task("task3", 7, 3,300, T3_func);
//
//
//
//	while (1) {
//		start_scheduler(task_stack);
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
