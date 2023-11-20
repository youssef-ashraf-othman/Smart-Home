/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 10/9/2022      ****************/
/********** SWC  : DIO            ****************/
/********** VERSION: 1.0          ****************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*Options: 1- DIO_u8_PORTA
		   2- DIO_u8_PORTB
           3- DIO_u8_PORTC      
           4- DIO_u8_PORTD  
*/		   
		   

#define LCD_u8_CONTROL_PORT               DIO_u8_PORTD
#define LCD_u8_RS_PIN                     DIO_u8_PIN2
#define LCD_u8_RW_PIN                     DIO_u8_PIN1
#define LCD_u8_E_PIN                      DIO_u8_PIN0

#define LCD_u8_DATA_Port                  DIO_u8_PORTC
            

#endif
