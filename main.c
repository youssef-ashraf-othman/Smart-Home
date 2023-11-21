#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KPD_interface.h"
#include "TIMERS_Interface.h"
#include "GI_Interface.h"
#include <util/delay.h>
#include "Smart.h"
int main()
{
	DIO_voidInit();
	LCD_voidInit();
	//Timer begins 
	GI_voidEnable();
	TIMERS_voidTIMER1Init();
	TIMERS_voidTimer1SetTopValueOVF(49999);
	Timer1_u8SetCallBack(TIMER1_OVFISR,&Timer);
	TIMERS_voidTimer1SetPrescalerValue();
	//----------------------------------------
	u8 str1[]="Welcome To System";
   	u8 str2[]="Set Your Password";
	u8 str3[]="Password : ";
	u8 str4[]="Password Was Set";
	u8 str5[]="Welcome to home";
	u8 str6[]="--------------------";
	u8 str7[]="1-Take Control";
	u8 str8[]="2-Settings";
	u8 str9[]="Wrong Password";
	u8 str10[]="Login blocked 5s";
	LCD_voidu8GoToXY(LCD_u8_LINE1,0);
	LCD_voidSendString(str1);
	LCD_voidu8GoToXY(LCD_u8_LINE2,0);
	LCD_voidSendString(str2);
	LCD_voidu8GoToXY(LCD_u8_LINE3,0);
	LCD_voidSendString(str3);
	u8 r1=1,Counter1=0,L;
	u16 DivisionFactor=1,ResPassword,Password;
	//Set system password
	while(L!='C')
	{
		KPD_u8GetKeyState(&L);
		if(L!=KPD_u8_KEY_NOT_PRESSED)
		{
			LCD_voidSendChar('*');
			ResPassword = ResPassword + (L*DivisionFactor) ;
			DivisionFactor=DivisionFactor*10;
		}
	}
	L=KPD_u8_KEY_NOT_PRESSED;
	DivisionFactor=1;
	LCD_voidClearScreen();
	LCD_voidClearCursor();
	LCD_voidu8GoToXY(LCD_u8_LINE1,0);
	LCD_voidSendString(str4);
	_delay_ms(1000);

	//chosing one mood
	LCD_voidClearScreen();
	while(1)
	{
			if(r1==1)
			{
				LCD_voidu8GoToXY(LCD_u8_LINE1,0);
				LCD_voidSendString(str5);
				LCD_voidu8GoToXY(LCD_u8_LINE2,0);
				LCD_voidSendString(str6);
				LCD_voidu8GoToXY(LCD_u8_LINE3,0);
				LCD_voidSendString(str7);
				LCD_voidu8GoToXY(LCD_u8_LINE4,0);
				LCD_voidSendString(str8);
				LCD_voidu8GoToXY(LCD_u8_LINE4,0);
				r1=0;
			}


			KPD_u8GetKeyState(&L);
			if(L==1)//Take Control of your home
			{
				//check for password
				while(1)
				{
					LCD_voidClearScreen();
					LCD_voidSetCursor();
					LCD_voidu8GoToXY(LCD_u8_LINE1,0);
					LCD_voidSendString(str3);
					while(L!='C')
					{
						KPD_u8GetKeyState(&L);
						if(L!=KPD_u8_KEY_NOT_PRESSED)
						{
							LCD_voidSendChar('*');
							Password = Password + (L*DivisionFactor) ;
							DivisionFactor=DivisionFactor*10;
						}
					}
					if(Password==ResPassword)
					{
						Password=0;
						DivisionFactor=1;
						r1=0;
						//if password is true 
						Admin(&r1);
						LCD_voidClearScreen();
						break;

					}
					else //password is wrong try again
					{
						Password=0;
						DivisionFactor=1;
						r1=0;
						L=KPD_u8_KEY_NOT_PRESSED;
						LCD_voidClearCursor();
						LCD_voidClearScreen();
						LCD_voidu8GoToXY(LCD_u8_LINE1,0);
						LCD_voidSendString(str9);
						_delay_ms(1000);
						Counter1++;
					}
					if(Counter1==3) //Too many trys blocks login
					{
						LCD_voidClearCursor();
						LCD_voidClearScreen();
						LCD_voidu8GoToXY(LCD_u8_LINE1,0);
						LCD_voidSendString(str10);
						Counter1=0;
						r1=1;
						_delay_ms(5000);
						LCD_voidClearScreen();
						break;
					}
		        }
	        }
			
			else if(L==2) //code for Settings 
			{
				Settings(&r1,&ResPassword);
				LCD_voidClearScreen();
			}





	}




	return 0;
}
