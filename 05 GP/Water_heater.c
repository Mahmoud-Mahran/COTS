#include 	<Bit_Math.h>
#include 	<Std_Types.h>
#include    "Water_heater.h"

extern SYS_MODE mode;
extern u8 required_temp;
extern u16 temp;
extern u8 pressed;

void EXTI_Stop_pressed(void){
	if(mode == IDLE){
		mode = INIT;
	} else{mode = OFF;}
	_delay_ms(100);
}

void EXTI_down_pressed(void){
	if(mode == SETTING){
		required_temp -= 5;
		_delay_ms(100);
	}else if(mode != SETTING){
		mode = SETTING;
	}
	STK_voidStopInterval();

}

void EXTI_up_pressed(void){
	if(mode == SETTING){
		required_temp += 5;
		_delay_ms(100);
	}else if(mode != SETTING){
		mode = SETTING;
	}
	STK_voidStopInterval();
}


void vMode_Switch_INIT(void){
	mode = INIT;
	pressed = 0;
}
void vRead_ADC(void){
	temp = ((1.43 - ((float)(3.3*ADC_Read()/(float)4095))) / 0.0043) + 45;
}
