/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 10/9/2022      ****************/
/********** SWC  : DIO            ****************/
/********** VERSION: 1.0          ****************/
#ifndef  LCD_INTERFACE_H
#define  LCD_INTERFACE_H
#define  LCD_u8_LINE1  1
#define  LCD_u8_LINE2  2
#define  LCD_u8_LINE3  3
#define	 LCD_u8_LINE4  4

void LCD_voidInit(void);

void LCD_voidSendCmnd(u8 Copy_u8_Cmnd);

void LCD_voidSendChar(u8 Copy_u8_Char);

void LCD_voidSendString(u8 *Copy_u8_Arr);

void LCD_voidWriteNumber(u32 Copy_u32Number);

u8 LCD_voidu8GoToXY(u8 Copy_u8_LineNumber,u8 Copy_u8Location);

void LCD_voidClearScreen(void);
void LCD_voidClearCursor(void);
void LCD_voidSetCursor(void);

#endif 
