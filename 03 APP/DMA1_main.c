//#include	"lib/Std_Types.h"
//#include	"lib/Bit_Math.h"
//
//#include "DMA_interface.h"
//#include "RCC_interface.h"
//#include "NVIC_interface.h"
//u32 Processor_Arr1[300];
//u32 Processor_Arr2[300];
//
//u32 DMA_Arr3[300];
//u32 DMA_Arr4[300];
//
//int main() {
//	for (u16 i = 0; i < 300; i++) {
//		Processor_Arr1[i] = i;
//		DMA_Arr3[i] = i;
//	}
//
//	/*	System init			*/
//	RCC_voidSysClkInt();
//	RCC_voidEnablePerClk(RCC_AHB, 0);
//	NVIC_voidInit();
//	DMA1_voidChannelInit();
//	NVIC_voidEnablePerInt(17);
//	/*	DMA1 Channel Transfer Round	*/
//	DMA1_voidStartChannel(DMA_Arr3, DMA_Arr4, 300, 7);
//
//	/*	Processor Transfer Round	*/
//	for (u16 i = 0; i < 300; i++) {
//		Processor_Arr2[i] = Processor_Arr1[i];
//	}
//
//	while (1) {
//
//	}
//
//	return 0;
//}
//
//void DMA1_Channel7_IRQHandler() {
//	/*		Toggle led		*/
//	int useless = 50;
//	GET_BIT(useless, 0);
//}
