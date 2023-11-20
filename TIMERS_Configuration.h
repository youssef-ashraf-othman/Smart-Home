/*************************************************/
/********** Name : Youssef Ashraf ****************/
/********** DATE : 19/10/2023      ****************/
/********** SWC  : TIMERS          ****************/
/********** VERSION: 1.0          ****************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

/*Options 
1- TIMERS_Noclocksource		
2- TIMERS_Noprescaling			
3- TIMERS_8Prescaler			
4- TIMERS_64Prescaler			
5- TIMERS_256Prescaler			
6- TIMERS_1024Prescaler		
7- TIMERS_ExternalClkFallingEdge
8- TIMERS_ExternalClkRaisingEdge
*/
#define Timer0_Prescalervalue    TIMERS_8Prescaler
#define Timer1_Prescalervalue    TIMERS_8Prescaler
/*Options 
1- OC0_NormalOperation  
2- OC0_Toggle   		//for CTC       	
3- OC0_CLR   			//for CTC           		
4- OC0_SET 				//for CTC             		
5- OC0_NonInvertingMode //for PWM
6- OC0_InvertingMode    //for PWM
*/


#define OC0_operation			 OC0_NormalOperation	

#endif
