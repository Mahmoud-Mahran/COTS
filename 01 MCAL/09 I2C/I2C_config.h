#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H
// Packet error checking
/*This bit is set and cleared by software, and cleared by hardware when PEC is transferred or
by a START or Stop condition or when PE( Prepheral enable)=0*/
//options are : { DISABLED, ENABLED }
#define		PE_CHECKING					DISABLED
//Acknowledge/PEC Position (for data reception)
/*This bit is set and cleared by software and cleared by hardware when PE=0.*/
//options are : { DISABLED, ENABLED }
#define		PEC_POSi					DISABLED
// Acknowledge enable
/*This bit is set and cleared by software and cleared by hardware when PE=0.*/
//options are : { DISABLED, ENABLED }
#define		ACK							ENABLED
//Clock stretching disable (Slave mode)
/*This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
it is reset by software*/
//options are : { DISABLED, ENABLED }
#define		NOSTRETCH					ENABLED
// General call enable
/*	0: General call disabled. Address 00h is NACKed.
	1: General call enabled. Address 00h is ACKed.		*/
//options are : { DISABLED, ENABLED }
#define		GENERAL_CALL				DISABLED
/*PEC enable
 *0: PEC calculation disabled
 *1:  PEC calculation enabled		*/
//options are : { DISABLED, ENABLED }
#define		PEC_CALCULATION				DISABLED
/* ARP enable
 *0: ARP disable
 *1: ARP enable
 *SMBus Device default address recognized if SMBTYPE=0
 *SMBus Host address recognized if SMBTYPE=1			*/
//options are : { DISABLED, ENABLED }
#define		ARP							DISABLED
//SMBus type
//0: SMBus Device
//1: SMBus Host
//options are : { DEVICE, HOST }
#define		SMBUS_TYPE					DEVICE
// SMBus mode
//0: I2C mode
//1: SMBus mode
//options are : { I2C, SMBUS }
#define		SMBBUS_MODE					I2C
//DMA requests enable
//0: DMA requests disabled
//1: DMA request enabled when TxE=1 or RxNE =1
//options are : { DISABLED, ENABLED }
#define		DMA_REQ						DISABLED
//Buffer interrupt enable
//0: TxE = 1 or RxNE = 1 does not generate any interrupt.
//1: TxE = 1 or RxNE = 1 generates Event Interrupt (whatever the state of DMAEN)
//options are : { DISABLED, ENABLED }
#define		BUFFER_INTERRUPT			DISABLED
//Event interrupt enable
//0: Event interrupt disabled
//1: Event interrupt enabled
/*This interrupt is generated when:
– SB = 1 (Master)
– ADDR = 1 (Master/Slave)
– ADD10= 1 (Master)
– STOPF = 1 (Slave)
– BTF = 1 with no TxE or RxNE event
– TxE event to 1 if ITBUFEN = 1
– RxNE event to 1if ITBUFEN = 1				*/
//options are : { DISABLED, ENABLED }
#define		EVENT_INTERRUPT				DISABLED
// Error interrupt enable
//0: Error interrupt disabled
//1: Error interrupt enabled
/*This interrupt is generated when:
– BERR = 1
– ARLO = 1
– AF = 1
– OVR = 1
– PECERR = 1
– TIMEOUT = 1
– SMBALERT = 1			*/
//options are : { DISABLED, ENABLED }
#define		ERROR_INTERRUPT				DISABLED
// Peripheral clock frequency in MHz
/*The FREQ bits must be configured with the APB clock frequency value (I2C peripheral
connected to APB). The FREQ field is used by the peripheral to generate data setup and
hold times compliant with the I2C specifications. The minimum allowed frequency is 2 MHz,
the maximum frequency is limited by the maximum APB frequency and cannot exceed
50 MHz (peripheral intrinsic maximum limit).*/
//options are : { 2 : 50 (depending on the allowed values from the APB1 prescaler calculations) }
#define		APB_CLK_FREQ				8
//Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged)
//options are : { 0, 1 }
#define		ADD_MODE					0
//Dual addressing mode enable
//0: Only OAR1 is recognized in 7-bit addressing mode
//1: Both OAR1 and OAR2 are recognized in 7-bit addressing mode
//options are : { 0, 1 }
#define		DUAL_ADD_MODE				0
//own address1(salve mode)
#define		ADDR_1						DISABLED
//own address2(salve mode)
#define		ADDR_2						DISABLED
// I2C master mode selection
//0: Sm mode I2C
//1: Fm mode I2C
//options are : { SM_MODE, FM_MODE }
#define		MASTER_MODE					SM_MODE //fm not supported yet
//Fm mode duty cycle
//0: Fm mode T_low/T_high = 2
//1: Fm mode T_low/T_high = 16/9
//options are : { _2_, _16_9_ }
#define 	FM_DUTY						_2_

//I2C required SCL Frequency in hz
//SCL frequency is < 100Khz in SM mode
//SCL frequency is < 400Khz in FM mode
#define		I2C_FREQ					100000
#endif
