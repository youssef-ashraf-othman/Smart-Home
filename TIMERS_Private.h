/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 19/10/2023     ****************/
/********** SWC  : TIMERS           ****************/
/********** VERSION: 1.0          ****************/
#ifndef  TIMERS_PRIVATE_H
#define  TIMERS_PRIVATE_H
									       
#define  TIMERS_u8_TIMSK_REG               	*((volatile u8*)0x59)
#define  TIMERS_u8_TIFR_REG                	*((volatile u8*)0x58)
#define  TIMERS_u8_TCCR0_REG               	*((volatile u8*)0x53)
#define  TIMERS_u8_TCNT0_REG               	*((volatile u8*)0x52) 
#define  TIMERS_u8_OCR0_REG                	*((volatile u8*)0x5C)
											
#define  TIMERS_u8_TCCR1A_REG              	*((volatile u8*)0x4F)
#define  TIMERS_u8_TCCR1B_REG              	*((volatile u8*)0x4E)
#define  TIMERS_u8_TCNT1H_REG              	*((volatile u8*)0x4D) 
#define  TIMERS_u8_TCNT1L_REG              	*((volatile u8*)0x4C)
											
#define  TIMERS_u16_TCNT1_REG            	*((volatile u16*)0x4C)  /*for high and low*/
	
#define  TIMERS_u8_OCR1AH_REG            	*((volatile u8*)0x4B) 
#define  TIMERS_u8_OCR1AL_REG            	*((volatile u8*)0x4A)
											
#define  TIMERS_u16_OCR1A_REG            	*((volatile u16*)0x4A)  /*for high and low*/
	
#define  TIMERS_u8_ICR1H_REG             	*((volatile u8*)0x47)
#define  TIMERS_u8_ICR1L_REG             	*((volatile u8*)0x46)
											
#define  TIMERS_u16_ICR1_REG             	*((volatile u16*)0x46)  /*for high and low*/




#define  TIMERS_u8_PIN0               		0
#define  TIMERS_u8_PIN1               		1 
#define  TIMERS_u8_PIN2               		2  
#define  TIMERS_u8_PIN3               		3  
#define  TIMERS_u8_PIN4               		4  
#define  TIMERS_u8_PIN5               		5  
#define  TIMERS_u8_PIN6               		6
#define  TIMERS_u8_PIN7               		7   


#define TIMERS_Noclocksource				0
#define TIMERS_Noprescaling					1
#define TIMERS_8Prescaler					2
#define TIMERS_64Prescaler					3
#define TIMERS_256Prescaler					4
#define TIMERS_1024Prescaler				5
#define TIMERS_ExternalClkFallingEdge		6	
#define TIMERS_ExternalClkRaisingEdge		7   

											
#define OC0_Toggle                          0
#define OC0_CLR                             1
#define OC0_SET                             2
#define OC0_NormalOperation                 3
#define OC0_NonInvertingMode                4
#define OC0_InvertingMode                   5



		





#endif
