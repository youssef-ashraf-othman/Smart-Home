/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 17/10/2023     ****************/
/********** SWC  : GI            ****************/
/********** VERSION: 1.0          ****************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GI_Interface.h"
#include "GI_Private.h"

void GI_voidEnable(void)
{
	SET_BIT(EXTI_u8_SERG,EXIT_GI);
}

void GI_voidDisable(void)
{
	SET_BIT(EXTI_u8_SERG,EXIT_GI);
}