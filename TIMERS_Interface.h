/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 19/10/2023      ****************/
/********** SWC  : TIMERS          ****************/
/********** VERSION: 1.0          ****************/
#ifndef  TIMERS_INTERFACE_H
#define  TIMERS_INTERFACE_H

#define TIMER_NormalMode   					0
#define TIMER_CTCMode      					1
#define TIMER_PhaseCorrectPWMMode			2
#define TIMER_FastPWMMode					3


#define TIMER0_CTCISR                    	0
#define TIMER0_OVFISR                   	1
#define TIMER1_OVFISR                   	2
	
u8 TIMERS_voidTIMER0Init(u8 Copy_u8TIMERMode);

void TIMERS_voidTIMER1Init(void);

u8 Timer0_u8SetCallBack(u8 Copy_u8ISRIndex, void(*Cpy_pf)(void));

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);

void TIMERS_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue);

u8   TIMERS_voidTimer0SetPrescalerValue(void);

u8 TIMERS_voidGetTimer0Value(void);

void TIMERS_voidTimer1SetCompareMatchValue(u16 Copy_u16OCRValue);

void TIMERS_voidTimer1SetTopValueOVF(u16 Copy_u16ICRValue);

u8 TIMERS_voidTimer1SetPrescalerValue(void);

u16 TIMERS_voidGetTimer1Value(void);

u8 Timer1_u8SetCallBack(u8 Copy_u8ISRIndex, void(*Cpy_pf)(void));





#endif 
