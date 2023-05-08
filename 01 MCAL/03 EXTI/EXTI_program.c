#include	"lib/Std_Types.h"
#include	"lib/Bit_Math.h"

#include	"EXTI_interface.h"
#include	"EXTI_private.h"
#include	"EXTI_config.h"



#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI_CallBack[16])	(void)	= {NULL};
void		EXTI_select_channel(u8 line_num);
void		EXTI_voidInit(void){
	#ifndef			AFIO_EXTICR1
		#define		AFIO_BASE_ADD			 (0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
		#define		AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
		#define		AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
		#define		AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))
	#endif


#if (EXTI0 == ENABLED)
	//EXTI_voidEnableInt(0);
	switch(EXTI0_ch){
	case EXTI_ch_A:	AFIO_EXTICR1 &= 0xfffffff0;break;
	case EXTI_ch_B:	AFIO_EXTICR1 &= 0xfffffff1;break;
	case EXTI_ch_C:	AFIO_EXTICR1 &= 0xfffffff2;break;
	}
	EXTI_voidChangeSenseMode(0,EXTI0_ch_mode);
#endif


#if (EXTI1 == ENABLED)
	switch(EXTI1_ch){
	case EXTI_ch_A:	AFIO_EXTICR1 &= 0xffffff0f;break;
	case EXTI_ch_B:	AFIO_EXTICR1 &= 0xffffff1f;break;
	case EXTI_ch_C:	AFIO_EXTICR1 &= 0xffffff2f;break;
	}
	EXTI_voidEnableInt(EXTI1);
	EXTI_voidChangeSenseMode(1,EXTI1_ch_mode);
#endif


#if (EXTI2 == ENABLED)
	switch(EXTI2_ch){
	case EXTI_ch_A:	AFIO_EXTICR1 &= 0xfffff0ff;break;
	case EXTI_ch_B:	AFIO_EXTICR1 &= 0xfffff1ff;break;
	case EXTI_ch_C:	AFIO_EXTICR1 &= 0xfffff2ff;break;
	}
	EXTI_voidChangeSenseMode(2,EXTI2_ch_mode);
#endif


#if (EXTI3 == ENABLED)
	switch(EXTI3_ch){
	case EXTI_ch_A:	AFIO_EXTICR1 &= 0xffff0fff;break;
	case EXTI_ch_B:	AFIO_EXTICR1 &= 0xffff1fff;break;
	case EXTI_ch_C:	AFIO_EXTICR1 &= 0xffff2fff;break;
	}
	EXTI_voidChangeSenseMode(3,EXTI3_ch_mode);
#endif


#if (EXTI4 == ENABLED)
	switch(EXTI4_ch){
	case EXTI_ch_A:	AFIO_EXTICR2 &= 0xfffffff0;break;
	case EXTI_ch_B:	AFIO_EXTICR2 &= 0xfffffff1;break;
	case EXTI_ch_C:	AFIO_EXTICR2 &= 0xfffffff2;break;
	}
	EXTI_voidChangeSenseMode(4,EXTI4_ch_mode);
#endif


#if (EXTI5 == ENABLED)
	switch(EXTI5_ch){
	case EXTI_ch_A:	AFIO_EXTICR2 &= 0xffffff0f;break;
	case EXTI_ch_B:	AFIO_EXTICR2 &= 0xffffff1f;break;
	case EXTI_ch_C:	AFIO_EXTICR2 &= 0xffffff2f;break;
	}
	EXTI_voidChangeSenseMode(5,EXTI5_ch_mode);
#endif


#if (EXTI6 == ENABLED)
	switch(EXTI6_ch){
	case EXTI_ch_A:	AFIO_EXTICR2 &= 0xfffff0ff;break;
	case EXTI_ch_B:	AFIO_EXTICR2 &= 0xfffff1ff;break;
	case EXTI_ch_C:	AFIO_EXTICR2 &= 0xfffff2ff;break;
	}
	EXTI_voidChangeSenseMode(6,EXTI6_ch_mode);
#endif


#if (EXTI7 == ENABLED)
	switch(EXTI7_ch){
	case EXTI_ch_A:	AFIO_EXTICR2 &= 0xffff0fff;break;
	case EXTI_ch_B:	AFIO_EXTICR2 &= 0xffff1fff;break;
	case EXTI_ch_C:	AFIO_EXTICR2 &= 0xffff2fff;break;
	}
	EXTI_voidChangeSenseMode(7,EXTI7_ch_mode);
#endif


#if (EXTI8 == ENABLED)
	switch(EXTI8_ch){
	case EXTI_ch_A:	AFIO_EXTICR3 &= 0xfffffff0;break;
	case EXTI_ch_B:	AFIO_EXTICR3 &= 0xfffffff1;break;
	case EXTI_ch_C:	AFIO_EXTICR3 &= 0xfffffff2;break;
	}
	EXTI_voidChangeSenseMode(8,EXTI8_ch_mode);
#endif


#if (EXTI9 == ENABLED)
	switch(EXTI9_ch){
	case EXTI_ch_A:	AFIO_EXTICR3 &= 0xffffff0f;break;
	case EXTI_ch_B:	AFIO_EXTICR3 &= 0xffffff1f;break;
	case EXTI_ch_C:	AFIO_EXTICR3 &= 0xffffff2f;break;
	}
	EXTI_voidChangeSenseMode(9,EXTI9_ch_mode);
#endif


#if (EXTI10 == ENABLED)
	switch(EXTI10_ch){
	case EXTI_ch_A:	AFIO_EXTICR3 &= 0xfffff0ff;break;
	case EXTI_ch_B:	AFIO_EXTICR3 &= 0xfffff1ff;break;
	case EXTI_ch_C:	AFIO_EXTICR3 &= 0xfffff2ff;break;
	}
	EXTI_voidChangeSenseMode(10,EXTI10_ch_mode);
#endif


#if (EXTI11 == ENABLED)
	switch(EXTI11_ch){
	case EXTI_ch_A:	AFIO_EXTICR3 &= 0xffff0fff;break;
	case EXTI_ch_B:	AFIO_EXTICR3 &= 0xffff1fff;break;
	case EXTI_ch_C:	AFIO_EXTICR3 &= 0xffff2fff;break;
	}
	EXTI_voidChangeSenseMode(11,EXTI11_ch_mode);
#endif


#if (EXTI12 == ENABLED)
	switch(EXTI12_ch){
	case EXTI_ch_A:	AFIO_EXTICR4 &= 0xfffffff0;break;
	case EXTI_ch_B:	AFIO_EXTICR4 &= 0xfffffff1;break;
	case EXTI_ch_C:	AFIO_EXTICR4 &= 0xfffffff2;break;
	}
	EXTI_voidChangeSenseMode(12,EXTI12_ch_mode);
#endif


#if (EXTI13 == ENABLED)
	switch(EXTI13_ch){
	case EXTI_ch_A:	AFIO_EXTICR4 &= 0xffffff0f;break;
	case EXTI_ch_B:	AFIO_EXTICR4 &= 0xffffff1f;break;
	case EXTI_ch_C:	AFIO_EXTICR4 &= 0xffffff2f;break;
	}
	EXTI_voidChangeSenseMode(13,EXTI13_ch_mode);
#endif


#if (EXTI14 == ENABLED)
	switch(EXTI14_ch){
	case EXTI_ch_A:	AFIO_EXTICR4 &= 0xfffff0ff;break;
	case EXTI_ch_B:	AFIO_EXTICR4 &= 0xfffff1ff;break;
	case EXTI_ch_C:	AFIO_EXTICR4 &= 0xfffff2ff;break;
	}
	EXTI_voidChangeSenseMode(14,EXTI14_ch_mode);
#endif


#if (EXTI15 == ENABLED)
	switch(EXTI15_ch){
	case EXTI_ch_A:	AFIO_EXTICR4 &= 0xffff0fff;break;
	case EXTI_ch_B:	AFIO_EXTICR4 &= 0xffff1ff;break;
	case EXTI_ch_C:	AFIO_EXTICR4 &= 0xffff2fff;break;
	}
	EXTI_voidChangeSenseMode(15,EXTI15_ch_mode);
#endif

}
void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}
void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR,line_num);
}

void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}

void		EXTI0_voidSetCallBack(void (*Fptr)(void), u8 EXTI_num)
{
	if(Fptr != NULL  && EXTI_num >= 0 && EXTI_num < 16)
	{
		EXTI_CallBack[EXTI_num] = Fptr;
	}
}

void	EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,0);
}

void	EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,1);
}

void	EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,2);
}

void	EXTI3_IRQHandler(void)
{
	EXTI_CallBack[3]();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,3);
}

void	EXTI4_IRQHandler(void)
{
	EXTI_CallBack[4]();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,4);
}

void	EXTI9_5_IRQHandler(void)
{
	if	(GET_BIT(EXTI -> PR, 5)){
		EXTI_CallBack[5]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,5);}
	if	(GET_BIT(EXTI -> PR, 6)){
		EXTI_CallBack[5]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,6);
	}

	if	(GET_BIT(EXTI -> PR, 7)){
		EXTI_CallBack[5]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,7);
	}


	if	(GET_BIT(EXTI -> PR, 8)){
		EXTI_CallBack[5]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,8);
	}


	if	(GET_BIT(EXTI -> PR, 9)){
		EXTI_CallBack[5]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,9);
	}

}


void	EXTI15_10_IRQHandler(void)
{

	if	(GET_BIT(EXTI -> PR,10)){
		EXTI_CallBack[10]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,10);
	}


	if	(GET_BIT(EXTI -> PR,11)){
		EXTI_CallBack[10]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,11);
	}


	if	(GET_BIT(EXTI -> PR,12)){
		EXTI_CallBack[10]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,12);
	}


	if	(GET_BIT(EXTI -> PR,13)){
		EXTI_CallBack[10]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,13);
	}


	if	(GET_BIT(EXTI -> PR,14)){
		EXTI_CallBack[10]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,14);
	}


	if	(GET_BIT(EXTI -> PR,15)){
		EXTI_CallBack[10]();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,15);
	}

}
