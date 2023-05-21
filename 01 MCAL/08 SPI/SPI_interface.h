#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H


void SPI_init_master(void);
void SPI_send_receive_master(u8 data,u8 *buffer);

#endif
