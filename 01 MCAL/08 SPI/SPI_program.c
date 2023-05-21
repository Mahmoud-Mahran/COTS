#include "00 LIB/Bit_Math.h"
#include "00 LIB/Std_Types.h"
#include "01 MCAL/08 SPI/SPI_private.h"
#include "01 MCAL/08 SPI/SPI_interface.h"
#include "01 MCAL/08 SPI/SPI_config.h"
#include "01 MCAL/01 GPIO/DIO_interface.h"

void SPI_init_master(void)
{
//	DIO_init(PORT_B,SS,OUTPUT);
//	DIO_init(PORT_B,MOSI,OUTPUT);
//	DIO_init(PORT_B,MISO,INPUT);
//	DIO_init(PORT_B,SCK,OUTPUT);
//
//	DIO_write(PORT_B,SS,HIGH);

	SET_BIT(SPI1->CR1,0);//clock phase
	SET_BIT(SPI1->CR1,1);//clock polarity
	SPI1->CR1 |=(0<<3);//baud rate
	CLR_BIT(SPI1->CR1,7);//msb 1st
	SET_BIT(SPI1->CR1,9);//software slave management
	SET_BIT(SPI1->CR1,8);//internal slave select high
	CLR_BIT(SPI1->CR1,10);//full duplex
	CLR_BIT(SPI1->CR1,11);//8 bit data
	SET_BIT(SPI1->CR1,2);//master mode
	SET_BIT(SPI1->CR1,6);//enable spi
}
void SPI_send_receive_master(u8 data, u8 *buffer)
{
	SPI1->DR = data;
	while( !(SPI1->SR & (1<<1)) ) *buffer = (u8)SPI1->DR;
}





//void SPI_init_slave(void)
//{
//		DIO_init(PORT_B,SS,INPUT);
//		DIO_init(PORT_B,MOSI,INPUT);
//		DIO_init(PORT_B,MISO,OUTPUT);
//		DIO_init(PORT_B,SCK,INPUT);
//
//		SPCR = (1<<SPE);
//}
//void SPI_send_slave(uint8_t data)
//{
//	SPDR = data;
//	while(!(SPSR & (1<<SPIF)));
//}
//uint8_t SPI_receive_slave(void)
//{
//
//	while(!(SPSR & (1<<SPIF)));
//	return SPDR;
//}
