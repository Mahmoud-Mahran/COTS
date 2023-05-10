#ifndef		DMA_INTERFACE_H
#define 	DMA_INTERFACE_H

void	DMA1_voidChannelInit();
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength, u8 ChannelNumber);

#define			ENABLED					1
#define			DISABLED				0

#define			SIZE_8BIT				2
#define			SIZE_16BIT				3
#define			SIZE_32BIT				4



#define			LOW_PRIORITY			5
#define			MEDIUM_PRIORITY			6
#define			HIGH_PRIORITY			7
#define			VERYHIGH_PRIORITY		8


#endif
