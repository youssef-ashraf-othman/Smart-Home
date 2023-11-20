/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 10/9/2022      ****************/
/********** SWC  : DIO            ****************/
/********** VERSION: 1.0     	  ****************/

/*1- اول حاجة بعمل انكلود للمكتبات اللي هستخدمها*/
/*2- include MCAL*/
 /*هعمل انكلود من تحت لفوق عموما*/
 /*-------------------------------------------------------------------------------------------*/ 
 /*lib layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/*MCAL */
#include "DIO_Interface.h"

/*HAL*/
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Configuration.h"

void LCD_voidInit(void)
{
	_delay_ms(35);
	LCD_voidSendCmnd(0b00111000);
	_delay_us(40);
	LCD_voidSendCmnd(0b00001111);
	_delay_us(40);
	LCD_voidSendCmnd(0b00000001);
	_delay_ms(2);
	LCD_voidSendCmnd(0b00000110);
	
	
}

void LCD_voidSendCmnd(u8 Copy_u8_Cmnd)
{
	/*Rs=0
	  RW=0
	  command
	  E=1
	  E=0
	  */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_u8SetPortValue(LCD_u8_DATA_Port ,Copy_u8_Cmnd);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	
}
void LCD_voidSendChar(u8 Copy_u8_Char)
{
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_u8SetPortValue(LCD_u8_DATA_Port ,Copy_u8_Char);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
}
void LCD_voidSendString(u8 *Copy_u8_Arr)
{
	u8 Local_u8_Iteration;

	while(Copy_u8_Arr[Local_u8_Iteration]!='\0')
	{
		LCD_voidSendChar(Copy_u8_Arr[Local_u8_Iteration]);
		Local_u8_Iteration++;
	}


}

void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	    u8  Local_u8_Arr[100];
	    u8  Local_u8_Mod,Local_u8_ArrLimit = 0;
	    s8  Local_s8_ForIteration;

	    if(Copy_u32Number==0)
	    {
	    	LCD_voidSendChar(48);
	    }
	    else
	    {
	    	while ( Copy_u32Number != 0)
	    	{


	           Local_u8_Mod = Copy_u32Number % 10;


	           Local_u8_Arr[Local_u8_ArrLimit] = Local_u8_Mod;
	           Local_u8_ArrLimit++;



	           Copy_u32Number= Copy_u32Number / 10;
	       }
	       Local_s8_ForIteration = Local_u8_ArrLimit  - 1 ;
	       while ( Local_s8_ForIteration >= 0 )
	    	{
	           LCD_voidSendChar(Local_u8_Arr[Local_s8_ForIteration]+48);
	           Local_s8_ForIteration--;

	       }



	    }

}

u8 LCD_voidu8GoToXY(u8 Copy_u8_LineNumber,u8 Copy_u8Location)
{
	u8 Local_u8ErrorState= STD_TYPES_OK;
	if(Copy_u8Location <=39)
	switch (Copy_u8_LineNumber)
	{
		case LCD_u8_LINE1: LCD_voidSendCmnd(0x80+Copy_u8Location);
		break;
		case LCD_u8_LINE2: LCD_voidSendCmnd(0xC0+Copy_u8Location);
		break;
		case LCD_u8_LINE3: LCD_voidSendCmnd(0x94+Copy_u8Location);
		break;
		case LCD_u8_LINE4: LCD_voidSendCmnd(0xD4+Copy_u8Location);
		break;
		default : Local_u8ErrorState= STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void LCD_voidClearScreen(void)
{
	LCD_voidSendCmnd(0x01);
	_delay_ms(2);
}
void LCD_voidClearCursor(void)
{
	LCD_voidSendCmnd(0b00001100);
	_delay_ms(2);
}
void LCD_voidSetCursor(void)
{
	LCD_voidSendCmnd(0b00001111);
	_delay_ms(2);
}












	

