#ifndef		ADC_INTERFACE_H
#define		ADC_INTERFACE_H

void ADC_Init(void);
void ADC_Start(void);
u16  ADC_Read(void);
void ADC_Stop(void);
#define				ENABLED					1
#define				DISABLED				0

#define				ADCPRE0					14
#define 			ADCPRE1					15

#define				SINGLE					2
#define				CONTINUOUS				3

#define				RIGHT					7
#define				LEFT					8

#define				TIMER_1_CC1				9
#define				TIMER_1_CC2				10
#define				TIMER_1_CC3				11
#define				TIMER_2_CC2				12
#define				TIMER_3_TRGO			13
#define				TIMER_4_CC4				14
#define				EXTI_LINE_11			15
#define				TIMER_8_TRGO			155
#define				SWSTART					16

#define				SMP_1_5					17
#define				SMP_7_5					18
#define				SMP_13_5				19
#define				SMP_28_5				20
#define				SMP_41_5				21
#define				SMP_55_5				22
#define				SMP_71_5				23
#define				SMP_239_5				24

#define				TIMER_1_TRGO			25
#define				TIMER_1_CC4				26
#define				TIMER_2_TRGO			27
#define				TIMER_2_CC1				28
#define				TIMER_3_CC4				29
#define				TIMER_4_TRGO			30
#define				EXTI_LINE_15			31
#define				TIMER_8_CC4				32
#define				JSWSTART				33

#define				AW_SINGLE_CH			34
#define				AW_ALL_CH				35

#endif
