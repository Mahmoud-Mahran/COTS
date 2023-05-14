#include 	<00 LIB/Bit_Math.h>
#include 	<00 LIB/Std_Types.h>
#include	"02 ECU/01 SEG/SEG_interface.h"
#include	"02 ECU/01 SEG/SEG_config.h"

u8	SEG_u8DisplayNum(u8 num){
	u8 temp = 0;
		if(num < 10){
			switch(num){
			case 0: temp = zero;break;
			case 1: temp = one;break;
			case 2: temp = two;break;
			case 3: temp = three;break;
			case 4: temp = four;break;
			case 5: temp = five;break;
			case 6: temp = six;break;
			case 7: temp = seven;break;
			case 8: temp = eight;break;
			case 9: temp = nine;break;
			}
		}
		return temp;
}
