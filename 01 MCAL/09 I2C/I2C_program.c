#include "Std_Types.h"
#include "Bit_Math.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"


void I2C_init_master(void)
{
	I2C1->CR1 = 0x0000;
	I2C1->CR2 = 0x0000;
	I2C1->CR2 |= APB_CLK_FREQ;

#if	PE_CHECKING == ENABLED
	SET_BIT(I2C1->CR1,12);
#endif

#if	PEC_POSi == ENABLED
	SET_BIT(I2C1->CR1,11);
#endif

#if	GENERAL_CALL == ENABLED
	SET_BIT(I2C1->CR1,6);
#endif

#if	PEC_CALCULATION == ENABLED
	SET_BIT(I2C1->CR1,5);
#endif

#if	ARP == ENABLED
	SET_BIT(I2C1->CR1,4);
#endif

#if	SMBUS_TYPE == HOST
	SET_BIT(I2C1->CR1,1);
#endif

#if	SMBBUS_MODE == SMBUS
	SET_BIT(I2C1->CR1,1);
#endif

#if	DMA_REQ == ENABLED
	SET_BIT(I2C1->CR2,1);
#endif

#if	BUFFER_INTERRUPT == ENABLED
	SET_BIT(I2C1->CR2,10);
#endif

#if	EVENT_INTERRUPT == ENABLED
	SET_BIT(I2C1->CR2,9);
#endif

#if	ERROR_INTERRUPT == ENABLED
	SET_BIT(I2C1->CR2,8);
#endif

#if	MASTER_MODE == FM_MODE
	SET_BIT(I2C1->CCR,15);
	#if	FM_DUTY == _16_9_
		SET_BIT(I2C1->CCR,14);
	#endif
		I2C1->CCR |= 0x00;//placeholder
		I2C1->TRISE |= 0;//placeholder
#elif MASTER_MODE == SM_MODE
	u8 temp = (APB_CLK_FREQ * 1000000) / (2 * I2C_FREQ);
	I2C1->CCR |= temp;
	I2C1->TRISE |= APB_CLK_FREQ + 1;
#endif

	SET_BIT(I2C1->CR1,0);

}
void I2C_start(void)
{
#if	ACK == ENABLED
	SET_BIT(I2C1->CR1,10);
#endif
	SET_BIT(I2C1->CR1,8);
	while (!(I2C1->SR1 & (1<<0)));
}

void I2C_add_select(u8 address)
{
	I2C1->DR = address;
	while (!(I2C1->SR1 & (1<<1)));
	//I2C1->CR1 &= ~(1<<10);
	u8 temp = I2C1->SR1 | I2C1->SR2;
}

void I2C_Write_Byte(u8 data)
{
	while (!(I2C1->SR1 & (1<<7)));  // wait for TXE bit to set
	I2C1->DR = data;
	while (!(I2C1->SR1 & (1<<2)));  // wait for BTF bit to set

}


void I2C_Read_Byte(u8 *data){

	while (!(I2C1->SR1 & (1<<6)));
	*data = I2C1->DR;
}


void I2C_stop(void)
{
	SET_BIT(I2C1->CR1,9);
//	while (!(I2C1->SR1 & (1<<6)));
}
void I2C_disable_pe(void){
	CLR_BIT(I2C1->CR1,0);
}
void I2C_reset_pe(void){
	SET_BIT(I2C1->CR1,15);
	CLR_BIT(I2C1->CR1,15);
}
void I2C_enable_pe(void){
	SET_BIT(I2C1->CR1,0);
}
