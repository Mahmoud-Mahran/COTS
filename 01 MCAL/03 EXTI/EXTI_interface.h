#ifndef		EXIT_INTERFACE_H
#define		EXIT_INTERFACE_H


#define 	RISING_EDGE					11
#define 	FALLING_EDGE				00
#define 	IOC							22

#define		EXTI_ch_A					33
#define		EXTI_ch_B					44
#define		EXTI_ch_C					55


#define 	EXTI_Line_0					0
#define 	EXTI_Line_1					1
#define 	EXTI_Line_2					2
#define 	EXTI_Line_3					3
#define 	EXTI_Line_4					4
#define 	EXTI_Line_5					5
#define 	EXTI_Line_6					6
#define 	EXTI_Line_7					7
#define 	EXTI_Line_8					8
#define 	EXTI_Line_9					9
#define 	EXTI_Line_10				10
#define 	EXTI_Line_11				11
#define 	EXTI_Line_12				12
#define 	EXTI_Line_13				13
#define 	EXTI_Line_14				14
#define 	EXTI_Line_15				15


void		EXTI_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 EXTI_num);


#endif
