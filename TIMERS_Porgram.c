/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 19/10/2023      ****************/
/********** SWC  : TIMERS        ****************/
/********** VERSION: 1.0     	  ****************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"
#include "TIMERS_Configuration.h"
 
static void (*TIMERS_ApfTIMER0[3])(void)={NULL,NULL,NULL};

u8 TIMERS_voidTIMER0Init(u8 Copy_u8TIMERMode)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	
	switch(Copy_u8TIMERMode)
	{
		case TIMER_NormalMode:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN6);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN3);
		/*enable pie for overflow interrupt*/
		SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_PIN0);
		break;
		case TIMER_CTCMode:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN6);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN3);
		/*enable pie for compare match interrupt*/
		SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_PIN1);
		switch(OC0_operation)
		{
			case OC0_NormalOperation:
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_Toggle:
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_CLR:
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_SET:
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			default:Local_u8ErrorState=STD_TYPES_NOK;
			
		}
		break;
		case TIMER_PhaseCorrectPWMMode:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN6);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN3);
		SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_PIN0);
		switch(OC0_operation)
		{
			case OC0_NormalOperation:
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_NonInvertingMode:
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_InvertingMode:
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			default:Local_u8ErrorState=STD_TYPES_NOK;
			
		}
		break;
		case TIMER_FastPWMMode:
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN6);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN3);
		SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_PIN0);
		switch(OC0_operation)
		{
			case OC0_NormalOperation:
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_NonInvertingMode:
			CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			case OC0_InvertingMode:
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN4);
			SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN5);
			break;
			default:Local_u8ErrorState=STD_TYPES_NOK;
			
		}
		break;
		default:Local_u8ErrorState=STD_TYPES_NOK;
		
	}
		
	return Local_u8ErrorState;
}
u8 TIMERS_voidGetTimer0Value(void)
{
	return TIMERS_u8_TCNT0_REG;
}

u8 TIMERS_voidTimer0SetPrescalerValue(void)
{
	u8 Local_u8ErrorState;
	switch(Timer0_Prescalervalue)
	{
		case TIMERS_Noclocksource:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_Noprescaling:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_8Prescaler:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_64Prescaler:
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_256Prescaler:
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_1024Prescaler:
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_ExternalClkFallingEdge:
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_ExternalClkRaisingEdge:
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_PIN1);
		break;
		default:Local_u8ErrorState=STD_TYPES_NOK;
			
	}
	return Local_u8ErrorState;
	
}

void TIMERS_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue)
{
	TIMERS_u8_TCNT0_REG = Copy_u8PreloadValue;
}


void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	if(TIMERS_ApfTIMER0[TIMER0_OVFISR]!=NULL)
		{
			TIMERS_ApfTIMER0[TIMER0_OVFISR]();
		}
	
}
/***********************************************/
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
   if(TIMERS_ApfTIMER0[TIMER0_CTCISR]!=NULL)
		{
			TIMERS_ApfTIMER0[TIMER0_CTCISR]();
		}
}

u8 Timer0_u8SetCallBack(u8 Copy_u8ISRIndex, void(*Cpy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8ISRIndex > 2 || Cpy_pf==NULL)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	TIMERS_ApfTIMER0[Copy_u8ISRIndex]=Cpy_pf;
	
	return Local_u8ErrorState;
}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
	TIMERS_u8_OCR0_REG = Copy_u8OCR0Value;
}

void TIMERS_voidTIMER1Init(void)
{
	/*select timer mode*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,TIMERS_u8_PIN1);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,TIMERS_u8_PIN0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN3);
	SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN4);
	/*select hw action on OC1A pin-> non_inverting*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,TIMERS_u8_PIN7);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,TIMERS_u8_PIN6);
	SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_PIN2);

}

void __vector_9(void)   __attribute__((signal));
void __vector_9(void)
{
   if(TIMERS_ApfTIMER0[TIMER1_OVFISR]!=NULL)
		{
			TIMERS_ApfTIMER0[TIMER1_OVFISR]();
		}
}


u8 Timer1_u8SetCallBack(u8 Copy_u8ISRIndex, void(*Cpy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8ISRIndex > 3 || Cpy_pf==NULL)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	TIMERS_ApfTIMER0[Copy_u8ISRIndex]=Cpy_pf;
	
	return Local_u8ErrorState;
}



u8 TIMERS_voidTimer1SetPrescalerValue(void)
{
	u8 Local_u8ErrorState;
	switch(Timer1_Prescalervalue)
	{
		case TIMERS_Noclocksource:
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_Noprescaling:
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_8Prescaler:
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_64Prescaler:
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_256Prescaler:
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_1024Prescaler:
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_ExternalClkFallingEdge:
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		CLR_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		case TIMERS_ExternalClkRaisingEdge:
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN2);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN0);
		SET_BIT(TIMERS_u8_TCCR1B_REG,TIMERS_u8_PIN1);
		break;
		default:Local_u8ErrorState=STD_TYPES_NOK;
			
	}
	return Local_u8ErrorState;
	
}


void TIMERS_voidTimer1SetCompareMatchValue(u16 Copy_u16OCRValue)
{
	TIMERS_u16_OCR1A_REG = Copy_u16OCRValue;
}
void TIMERS_voidTimer1SetTopValueOVF(u16 Copy_u16ICRValue)
{
	TIMERS_u16_ICR1_REG = Copy_u16ICRValue;
}
u16 TIMERS_voidGetTimer1Value(void)
{
	return TIMERS_u16_TCNT1_REG;
}




	

	
