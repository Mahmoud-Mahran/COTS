#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

void 		I2C_init_master(void);
void 		I2C_start(void);
void 		I2C_add_select(u8 address);
void 		I2C_Write_Byte(u8 data);
void 		I2C_Read_Byte(u8 *data);
void 		I2C_stop(void);
void 		I2C_disable_pe(void);
void 		I2C_reset_pe(void);
void 		I2C_enable_pe(void);




#define		ENABLED							1
#define		DISABLED						0

#define		READ							2
#define		WRITE							3



#define		DEVICE							4
#define		HOST							5


#define		I2C								6
#define		SMBUS							7

#define		SM_MODE							8
#define		FM_MODE							9


#define		_2_								10
#define		_16_9_							11
//#define		__8MHZ							8
//#define		__16MHZ							9


#endif
