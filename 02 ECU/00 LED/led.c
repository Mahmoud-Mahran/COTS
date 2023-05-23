#include 	<Bit_Math.h>
#include 	<Std_Types.h>
#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include 	"led.h"

void LED_voidLED_init(LEDS *led) {
	DIO_voidSetPinDirection(led->port, led->pin, GPIO_OUTPUT_2MHZ_PP);
}

void LED_voidLED_on(LEDS *led) {
	DIO_voidSetPinValue(led->port, led->pin, GPIO_HIGH);
	led->state = 2;
}
void LED_voidLED_off(LEDS *led) {
	DIO_voidSetPinValue(led->port, led->pin, GPIO_LOW);
	led->state = 1;
}
void LED_voidToggle(LEDS *led) {
	DIO_voidSetPinValue(led->port, led->pin,
			!(DIO_u8GetPinValue(led->port, led->pin)));
	if (led->state == 1)
		led->state = 2;
	if (led->state == 2)
		led->state = 1;
}
void LED_voidBlink(double led_delay_ms, double led_duration_ms, LEDS *led1,
		LEDS *led2) {
	double temp = 0;
	while (temp <= led_duration_ms) {
		LED_voidToggle(led1);
		LED_voidToggle(led2);
		_delay_ms(led_delay_ms);
		temp += led_delay_ms;
		led1->state = 3;
		led2->state = 3;
	}

}

/*int main(void)
 {
 LEDS blue,green;
 blue.pin = 0;
 blue.port = PORT_A;
 green.pin = 1;
 green.port = PORT_A;
 //testing drivers
 LED_init(&blue);
 LED_init(&green);
 Timer0_init();
 LED_on(&blue);
 LED_on(&green);
 Timer0_delay(1.0);
 LED_off(&blue);
 LED_off(&green);
 Timer0_delay(1.0);
 LED_toggle(&green);
 LED_toggle(&blue);
 Timer0_delay(1.0);
 LED_blink(0.2, 10, &blue, &green);

 }*/
