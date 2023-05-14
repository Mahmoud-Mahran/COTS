#include 	<00 LIB/Bit_Math.h>
#include 	<00 LIB/Std_Types.h>
#include	"01 MCAL/05 DMA/DMA_private.h"
#include	"01 MCAL/05 DMA/DMA_interface.h"
#include 	"01 MCAL/05 DMA/DMA_config.h"




void	DMA1_voidChannelInit()
{
	/*
	DMA1 ->Channel[0].CCR = 0x00007AC2;
	Memory to Memory
	priority very high
	Size (Source & Destination) u32
	MINC, PINC enabled
	Direction read from Peripheral
	Transfer Complete Interrupt
	Channel Disable
	*/
#if (DMA1_CHANNEL1 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[0].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL1_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 1);
	if(DMA1_CHANNEL1_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 2);
	if(DMA1_CHANNEL1_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 3);
	if(DMA1_CHANNEL1_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 4);
	if(DMA1_CHANNEL1_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 5);
	if(DMA1_CHANNEL1_PINC == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 6);
	if(DMA1_CHANNEL1_MINC == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 7);
	switch(DMA1_CHANNEL1_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[0].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[0].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL1_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[0].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[0].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL1_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[0].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[0].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[0].CCR, 12);
		SET_BIT(DMA1 -> Channel[0].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL1_M2M == ENABLED) SET_BIT(DMA1 -> Channel[0].CCR, 14);
#endif


#if (DMA1_CHANNEL2 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[1].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL2_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 1);
	if(DMA1_CHANNEL2_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 2);
	if(DMA1_CHANNEL2_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 3);
	if(DMA1_CHANNEL2_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 4);
	if(DMA1_CHANNEL2_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 5);
	if(DMA1_CHANNEL2_PINC == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 6);
	if(DMA1_CHANNEL2_MINC == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 7);
	switch(DMA1_CHANNEL2_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[1].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[1].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL2_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[1].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[1].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL2_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[1].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[1].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[1].CCR, 12);
		SET_BIT(DMA1 -> Channel[1].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL2_M2M == ENABLED) SET_BIT(DMA1 -> Channel[1].CCR, 14);
#endif


#if (DMA1_CHANNEL3 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[2].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL3_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 1);
	if(DMA1_CHANNEL3_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 2);
	if(DMA1_CHANNEL3_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 3);
	if(DMA1_CHANNEL3_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 4);
	if(DMA1_CHANNEL3_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 5);
	if(DMA1_CHANNEL3_PINC == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 6);
	if(DMA1_CHANNEL3_MINC == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 7);
	switch(DMA1_CHANNEL3_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[2].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[2].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL3_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[2].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[2].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL3_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[2].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[2].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[2].CCR, 12);
		SET_BIT(DMA1 -> Channel[2].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL3_M2M == ENABLED) SET_BIT(DMA1 -> Channel[2].CCR, 14);
#endif


#if (DMA1_CHANNEL4 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[3].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL4_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 1);
	if(DMA1_CHANNEL4_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 2);
	if(DMA1_CHANNEL4_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 3);
	if(DMA1_CHANNEL4_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 4);
	if(DMA1_CHANNEL4_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 5);
	if(DMA1_CHANNEL4_PINC == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 6);
	if(DMA1_CHANNEL4_MINC == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 7);
	switch(DMA1_CHANNEL4_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[3].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[3].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL4_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[3].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[3].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL4_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[3].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[3].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[3].CCR, 12);
		SET_BIT(DMA1 -> Channel[3].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL4_M2M == ENABLED) SET_BIT(DMA1 -> Channel[3].CCR, 14);
#endif


#if (DMA1_CHANNEL5 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[4].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL5_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 1);
	if(DMA1_CHANNEL5_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 2);
	if(DMA1_CHANNEL5_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 3);
	if(DMA1_CHANNEL5_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 4);
	if(DMA1_CHANNEL5_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 5);
	if(DMA1_CHANNEL5_PINC == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 6);
	if(DMA1_CHANNEL5_MINC == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 7);
	switch(DMA1_CHANNEL5_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[4].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[4].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL5_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[4].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[4].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL5_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[4].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[4].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[4].CCR, 12);
		SET_BIT(DMA1 -> Channel[4].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL5_M2M == ENABLED) SET_BIT(DMA1 -> Channel[4].CCR, 14);
#endif


#if (DMA1_CHANNEL6 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[5].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL6_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 1);
	if(DMA1_CHANNEL6_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 2);
	if(DMA1_CHANNEL6_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 3);
	if(DMA1_CHANNEL6_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 4);
	if(DMA1_CHANNEL6_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 5);
	if(DMA1_CHANNEL6_PINC == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 6);
	if(DMA1_CHANNEL6_MINC == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 7);
	switch(DMA1_CHANNEL6_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[5].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[5].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL6_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[5].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[5].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL6_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[5].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[5].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[5].CCR, 12);
		SET_BIT(DMA1 -> Channel[5].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL6_M2M == ENABLED) SET_BIT(DMA1 -> Channel[5].CCR, 14);
#endif

#if (DMA1_CHANNEL7 == ENABLED)
	/*		Make Sure that the channel is  disabled & clear all config bits */
	for(int i = 0; i < 15; i++) CLR_BIT(DMA1 -> Channel[6].CCR,i);
	/************************************************************************/
	if(DMA1_CHANNEL7_TCIE == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 1);
	if(DMA1_CHANNEL7_HTIE == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 2);
	if(DMA1_CHANNEL7_TEIE == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 3);
	if(DMA1_CHANNEL7_DIR_MEM == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 4);
	if(DMA1_CHANNEL7_CIRC == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 5);
	if(DMA1_CHANNEL7_PINC == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 6);
	if(DMA1_CHANNEL7_MINC == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 7);
	switch(DMA1_CHANNEL7_PSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[6].CCR, 8);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[6].CCR, 9);break;
	default: break;
	}

	switch(DMA1_CHANNEL7_MSIZE){
	case SIZE_16BIT: SET_BIT(DMA1 -> Channel[6].CCR, 10);break;
	case SIZE_32BIT: SET_BIT(DMA1 -> Channel[6].CCR, 11);break;
	default: break;
	}

	switch(DMA1_CHANNEL7_PL){
	case MEDIUM_PRIORITY: SET_BIT(DMA1 -> Channel[6].CCR, 12);break;
	case HIGH_PRIORITY: SET_BIT(DMA1 -> Channel[6].CCR, 13);break;
	case VERYHIGH_PRIORITY:
		SET_BIT(DMA1 -> Channel[6].CCR, 12);
		SET_BIT(DMA1 -> Channel[6].CCR, 13);
		break;
	default: break;
	}
	if(DMA1_CHANNEL7_M2M == ENABLED) SET_BIT(DMA1 -> Channel[6].CCR, 14);
#endif
}

void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength, u8 ChannelNumber)
{
	if( ChannelNumber < 8 && ChannelNumber >= 1){
		/*		Make Sure that the channel is  disabled */
		CLR_BIT(DMA1 -> Channel[ChannelNumber-1].CCR,0);

		DMA1 -> Channel[ChannelNumber-1].CPAR	=	SrcAdd;
		DMA1 -> Channel[ChannelNumber-1].CMAR	=	DestAdd;

		/*	Load the Block Length				*/
		DMA1 -> Channel[ChannelNumber-1].CNDTR	=	BlockLength;
	
		/*		Make Sure that the channel is  Enabled to start transfer */
		SET_BIT(DMA1 -> Channel[ChannelNumber-1].CCR,0);
	}
}








