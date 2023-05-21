#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


#define		PCLK2						8000000


#define		BAUDE_RATE					BR_9600


#define		WORD_LENGTH					DATA_8

#define		PARITY						DISABLED


#define		PARITY_MODE					EVEN


#define		PARITY__ERROR_INTERRUPT		DISABLED
#define		TX_REG_EMPTY_INTERRUPT		DISABLED
#define		TX_COMPLETE_INTERRUPT		DISABLED
#define		RX_REG_NOT_EMPTY_INTERRUPT	DISABLED //same interrupt generated for overrun error
#define		IDLE_LINE_INTERRUPT			DISABLED
#define		CTS_INTERRUPT				DISABLED
#define		ERROR_INTERRUPT				DISABLED


#define		STOP_BITS					ONE_SB


#define		CTS_MODE					DISABLED
#define		RTS_MODE					DISABLED

#define		DMAT_MODE					DISABLED
#define		DMAR_MODE					DISABLED


#endif /* UART_CONFIG_H_ */
