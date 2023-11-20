#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KPD_interface.h"
#include <util/delay.h>
#include "Smart.h"
void Settings(u8 *Copy_r , u16 *Copy_Respassword)
{

	LCD_voidClearCursor();
	u8 KeyPressed,Flag=0;
	u8 str1[]="1-Change Password";
	u8 str2[]="2-Back to menu";

	while(1)
	{
		if(Flag==0)
		{
			LCD_voidClearScreen();
			LCD_voidu8GoToXY(LCD_u8_LINE1,0);
			LCD_voidSendString(str1);
			LCD_voidu8GoToXY(LCD_u8_LINE2,0);
			LCD_voidSendString(str2);
			Flag=1;
		}

		KPD_u8GetKeyState(&KeyPressed);
		if(KeyPressed==1)
		{
			ChangePassword(Copy_Respassword);
			Flag=0;

		}
		else if (KeyPressed==2)
		{

			*Copy_r=1;
			Flag=0;
			break;
		}
	}
}

void ChangePassword(u16 *Copy_ResPassword)
{
	u16 Password=0,DivisionFactor=1;
	u8 KeyPressed,Counter1=0;
	u8 str1[]="Old Password: ";
	u8 str2[]="New Password: ";
	u8 str3[]="Password Changed";
	u8 str4[]="Wrong Password";
	u8 str5[]="You Can't change";
	u8 str6[]="Password";



	//check for password
	while(1)
	{
		LCD_voidSetCursor();
		LCD_voidClearScreen();
		LCD_voidu8GoToXY(LCD_u8_LINE1,0);
		LCD_voidSendString(str1);
		while(KeyPressed!='C')
		{
			KPD_u8GetKeyState(&KeyPressed);
			if(KeyPressed!=KPD_u8_KEY_NOT_PRESSED)
			{
				LCD_voidSendChar('*');
				Password = Password + (KeyPressed*DivisionFactor) ;
				DivisionFactor=DivisionFactor*10;
			}
		}

		if(Password==*Copy_ResPassword)
		{
			KeyPressed=KPD_u8_KEY_NOT_PRESSED;
			DivisionFactor=1;
			Password=0;
			LCD_voidClearScreen();
			LCD_voidu8GoToXY(LCD_u8_LINE1,0);
			LCD_voidSendString(str2);
			while(KeyPressed!='C')
			{
				KPD_u8GetKeyState(&KeyPressed);
				if(KeyPressed!=KPD_u8_KEY_NOT_PRESSED)
				{
					LCD_voidSendChar('*');
					Password = Password + (KeyPressed*DivisionFactor) ;
					DivisionFactor=DivisionFactor*10;
				}
			}
			KeyPressed=KPD_u8_KEY_NOT_PRESSED;
			DivisionFactor=1;
			*Copy_ResPassword=Password;
			Password=0;
			LCD_voidClearScreen();
			LCD_voidClearCursor();
			LCD_voidu8GoToXY(LCD_u8_LINE1,0);
			LCD_voidSendString(str3);
			_delay_ms(1000);
			break;


		}
		else
		{
			Password=0;
			DivisionFactor=1;
			KeyPressed=KPD_u8_KEY_NOT_PRESSED;
			LCD_voidClearScreen();
			LCD_voidu8GoToXY(LCD_u8_LINE1,0);
			LCD_voidSendString(str4);
			_delay_ms(1000);
			Counter1++;
		}
		if(Counter1==3)
		{
			Counter1=0;
			LCD_voidClearCursor();
			LCD_voidClearScreen();
			LCD_voidu8GoToXY(LCD_u8_LINE1,0);
			LCD_voidSendString(str5);
			LCD_voidu8GoToXY(LCD_u8_LINE2,0);
			LCD_voidSendString(str6);
			_delay_ms(1000);
			LCD_voidClearScreen();
			break;
		}
	 }



}


