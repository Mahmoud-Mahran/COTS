#include <Std_Types.h>
#include <Bit_Math.h>
#include <UART1_config.h>
#include <UART1_interface.h>
#include <UART1_private.h>

void UART_init() {
	UART1 ->CR1 = 0x0000;
	/*		setting baud rate		*/
double usartdiv = (double)PCLK2/(16*BAUDE_RATE);
float frac = usartdiv - (int)usartdiv;
if(frac > 0){
	frac *= 16;
	frac  = (frac - (int)frac) >=0.5 ? (int)frac + 1 : (int)frac;
	UART1 ->BRR = frac;
}
	UART1 ->BRR |= ((int)usartdiv<<4);
	/*		configuring 1st CR settings		*/
#if WORD_LENGTH == DATA_9
	SET_BIT(UART1 ->CR1, 12);
#endif

#if PARITY == ENABLED
	SET_BIT(UART1 ->CR1, 10);
#endif

#if PARITY_MODE == ODD
	SET_BIT(UART1 ->CR1, 9);
#endif

#if PARITY__ERROR_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR1, 8);
#endif

#if TX_REG_EMPTY_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR1, 7);
#endif

#if TX_COMPLETE_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR1, 6);
#endif

#if RX_REG_NOT_EMPTY_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR1, 5);
#endif

#if IDLE_LINE_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR1, 4);
#endif
	/*		configuring 2nd CR settings		*/
	UART1 ->CR2 = 0x0000;
#if STOP_BITS == TWO_SB
	SET_BIT(UART1 ->CR2, 13);
#endif
	/*		configuring 3rd CR settings		*/
	UART1 ->CR3 = 0x0000;
#if CTS_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR3, 10);
#endif

#if ERROR_INTERRUPT == ENABLED
	SET_BIT(UART1 ->CR3, 0);
#endif

#if CTS_MODE == ENABLED
	SET_BIT(UART1 ->CR3, 9);
#endif

#if RTS_MODE == ENABLED
	SET_BIT(UART1 ->CR3, 8);
#endif

#if DMAT_MODE == ENABLED
	SET_BIT(UART1 ->CR3, 7);
#endif

#if DMAR_MODE == ENABLED
	SET_BIT(UART1 ->CR3, 6);
#endif
	/*		Enabling UART	*/
	SET_BIT(UART1 ->CR1, 13);
}


void UART_enableTX(void) {
	SET_BIT(UART1 ->CR1, 3);
}

void UART_enableRX(void) {
	SET_BIT(UART1 ->CR1, 2);
}

void UART_TXdata(u8 data){
	while(!GET_BIT(UART1 ->SR,7));
	UART1 ->DR = data;
}

u8 UART_RXdata (void) {
	while(!GET_BIT(UART1 ->SR,5));
	return ((u8)UART1 ->DR);
}
