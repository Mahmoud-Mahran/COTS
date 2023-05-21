#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


typedef struct {
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
} UART_Type;

#define			UART1		((volatile UART_Type*)(0x40013800))
//#define		UART2		((volatile UART_Type*)(0x40004400))
//#define		UART3		((volatile UART_Type*)(0x40004800))

#endif





