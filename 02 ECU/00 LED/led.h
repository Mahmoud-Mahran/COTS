#ifndef LED_H_
#define LED_H_
//used driver includes


//helper macros for error handling
#define LED_OK					222
#define LED_OPERATION_FAILED	220
//struct to store led attributes
typedef struct LEDS{
	u8 port;
	u8 pin;
	u8 state;
}LEDS;
/*function that takes a "LEDS" struct and returns an int for error handling 
initializes led according to given arguments */
void LED_voidLED_init(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
turns on led */
void LED_voidLED_on(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
turns off led */
void LED_voidLED_off(LEDS *led);
/*function that takes a "LEDS" struct and returns an int for error handling
toggles led */
void LED_voidToggle(LEDS *led);
/*function that takes 2 "LEDS" structs, a blink delay and total blinking duration and returns an int for error handling
blinks two leds according to given arguments */
void LED_voidBlink(double led_delay_ms, double duration, LEDS *led1, LEDS *led2);





#endif /* LED_H_ */
