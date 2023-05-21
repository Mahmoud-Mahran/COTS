#ifndef UART_H_
#define UART_H_


void		UART_init(void);
void		UART_enableTX(void);
void		UART_enableRX(void);
void 		UART_TXdata(u8 data);
u8 			UART_RXdata (void) ;


#define		BR_2400					2400
#define		BR_9600					9600
#define		BR_19200				19200
#define		BR_57600				57600
#define		BR_115200				115200
#define		BR_230400				230400
#define		BR_460800				460800
#define		BR_921600				921600
#define		BR_2250000				2250000


#define		DISABLED				0
#define		ENABLED					1



#define		DATA_8					2
#define		DATA_9					3



#define		EVEN					4
#define		ODD						5


#define		ONE_SB					6
#define		TWO_SB					7


#endif /* UART_H_ */
