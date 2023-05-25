#ifndef WATER_HEATER_H_
#define WATER_HEATER_H_
typedef enum {
	IDLE,INIT,NORMAL,SETTING,OFF
}SYS_MODE;

void EXTI_Stop_pressed(void);
void EXTI_down_pressed(void);
void EXTI_up_pressed(void);
void vMode_Switch_INIT(void);
void vRead_ADC(void);


#endif
