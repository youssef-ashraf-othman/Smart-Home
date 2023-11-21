#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KPD_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>
#include "Smart.h"
u8 Flag1=0;
static u8 Sec=0,Min=0,Hr=12;
static u16 Counter1=0;

void Admin(u8 *Copy_r)
{

	LCD_voidClearCursor();
	u8 KeyPressed;
	u8 str1[]="1-Adjust Temp";
	u8 str2[]="2-Lights Control";
	u8 str3[]="3-Show Time";
	u8 str4[]="4-Back to menu";

	while(1)
	{
		if(Flag1==0)//To display the screen for one time 
		{
			LCD_voidClearScreen();
			LCD_voidu8GoToXY(LCD_u8_LINE1,0);
			LCD_voidSendString(str1);
			LCD_voidu8GoToXY(LCD_u8_LINE2,0);
			LCD_voidSendString(str2);
			LCD_voidu8GoToXY(LCD_u8_LINE3,0);
			LCD_voidSendString(str3);
			LCD_voidu8GoToXY(LCD_u8_LINE4,0);
			LCD_voidSendString(str4);
			Flag1=1;
		}

		KPD_u8GetKeyState(&KeyPressed);
		if(KeyPressed==1)
		{
			TempAdjust();
		}
		else if (KeyPressed==2)
		{
			ControlLed();
		}
		else if (KeyPressed==3)
		{
			ShowTime();
		}
		else if (KeyPressed==4)//will break the loop to go back to main menu
		{

			*Copy_r=1;
			Flag1=0;
			break;
		}

	}
}

void ControlLed()
{
	//TIMERS_voidTIMER0Init(TIMER_CTCMode);
	//GI_voidEnable();
	u8 KeyPressed;
	u8 str5[]="1-Open Light";
	u8 str6[]="2-Change Light";
	u8 str7[]="3-Close Lights";
	u8 str8[]="4-Back to menu";
	LCD_voidClearScreen();
	LCD_voidu8GoToXY(LCD_u8_LINE1,0);
	LCD_voidSendString(str5);
	LCD_voidu8GoToXY(LCD_u8_LINE2,0);
	LCD_voidSendString(str6);
	LCD_voidu8GoToXY(LCD_u8_LINE3,0);
	LCD_voidSendString(str7);
	LCD_voidu8GoToXY(LCD_u8_LINE4,0);
	LCD_voidSendString(str8);
	static u8 flag=0;
	while(1)
	{
		KPD_u8GetKeyState(&KeyPressed);
		if(KeyPressed==1)//open the main light bulb
		{

			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
			flag=1;

		}
		else if (KeyPressed==2 && flag!=0)//Light must be opened to change it 
		{
			if (flag==1)
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_HIGH);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
				flag++;
			}
			else if (flag==2)
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_HIGH);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
				flag++;
			}
			else if (flag==3)
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
				flag++;
			}
			else if(flag==4)
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
				flag=1;
			}


		}
		else if (KeyPressed==3)//close all lights 
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN5,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
			flag=0;
		}
		else if (KeyPressed==4)//break loop to go back to maim menu
		{
			Flag1=0;
			break;
		}

	}
}

void TempAdjust()
{
	LCD_voidClearScreen();
	u8 str1[]="Temp : ";
	u8 str2[]="Cooler Is Opened";
	u8 str3[]="Heater Is Opened";
	u8 str4[]="Temp is Fine";
	u8 str5[]="1-Back To Menu";
	u8 str6[]="                ";
	u16 Local_Temp;
	u8  Temp2=255,KeyPressed;
	ADC_voidInit();
	while (1)
	{
		KPD_u8GetKeyState(&KeyPressed);
		if(KeyPressed==1)//Go back to main menu
		{
			Flag1=0;
			break;
		}

		ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&Local_Temp);//convert sensor's reading into degrees 
		Local_Temp=((Local_Temp*5000UL)/1024)/10;
		if(Temp2!=Local_Temp)//To display temp once and when it changes 
		{
			Temp2=Local_Temp;
			if(Local_Temp >= 25) //To open cooler

			{

				LCD_voidu8GoToXY(LCD_u8_LINE1,0);
				LCD_voidSendString(str1);
				LCD_voidWriteNumber(Local_Temp);
				LCD_voidu8GoToXY(LCD_u8_LINE2,0);
				LCD_voidSendString(str2);
				LCD_voidu8GoToXY(LCD_u8_LINE4,0);
				LCD_voidSendString(str5);
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_HIGH);
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_LOW);



			}
			else if (Temp2 <= 20) //to open heater 
			{

				LCD_voidu8GoToXY(LCD_u8_LINE1,0);
				LCD_voidSendString(str1);
				LCD_voidWriteNumber(Local_Temp);
				LCD_voidu8GoToXY(LCD_u8_LINE2,0);
				LCD_voidSendString(str3);
				LCD_voidu8GoToXY(LCD_u8_LINE4,0);
				LCD_voidSendString(str5);
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_HIGH);
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_LOW);

			}
			else //close both
			{

				LCD_voidu8GoToXY(LCD_u8_LINE1,0);
				LCD_voidSendString(str1);
				LCD_voidWriteNumber(Local_Temp+1);
				LCD_voidu8GoToXY(LCD_u8_LINE2,0);
				LCD_voidSendString(str6);
				LCD_voidu8GoToXY(LCD_u8_LINE2,0);
				LCD_voidSendString(str4);
				LCD_voidu8GoToXY(LCD_u8_LINE4,0);
				LCD_voidSendString(str5);
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN4,DIO_u8_LOW);
				DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_LOW);


			}
		}
	}
}

void ShowTime()
{
	u8 str1[]="1-Back To Menu",KeyPressed;
	LCD_voidClearScreen();
	LCD_voidu8GoToXY(LCD_u8_LINE4,0);
	LCD_voidSendString(str1);
	while(1)
	{
		KPD_u8GetKeyState(&KeyPressed);
		if(KeyPressed==1)
		{
			Flag1=0;
			break;
		}
		do
		{
			LCD_voidu8GoToXY(LCD_u8_LINE1,5);
			if(Hr<10)
			{
				LCD_voidWriteNumber(0);
			}
			LCD_voidWriteNumber(Hr);
			LCD_voidSendChar(':');
			if(Min<10)
			{
				LCD_voidWriteNumber(0);
			}
			LCD_voidWriteNumber(Min);
			LCD_voidSendChar(':');
			if(Sec<10)
			{
				LCD_voidWriteNumber(0);
			}
			LCD_voidWriteNumber(Sec);

		}while(Counter1==20 || Counter1==0);




	}
}

void Timer()
{
	if(Counter1==5) //Timer must interrupt five times to count 1 Sec
	{
		Counter1=0;
		Sec++;
		if(Sec==60)
		{
			Sec=0;
			Min++;
			if(Min==60)
			{
				Sec=0;
				Min=0;
				Hr++;
			}
		}


	}
	else
	{
		Counter1++;
	}
}












