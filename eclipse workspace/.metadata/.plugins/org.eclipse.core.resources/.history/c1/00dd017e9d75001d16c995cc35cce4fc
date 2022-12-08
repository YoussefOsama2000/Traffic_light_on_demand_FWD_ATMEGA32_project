/******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: Timer1.c
 *
 * Description: source file for timer 1 driver
 *
 * Author: Youssef Osama
 *
 *******************************************************************************/
#include "timer1.h"
#include "avr/io.h"
#include<avr/interrupt.h>

static void (*callback) (void)=NULL_PTR;
/*this function initialize timer 1
 * configuration has initial value , compare value , pre-scaler ,operation mode
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr){
	/*
	 * Enabling global interrupt
	 */
	SET_BIT(SREG,SPIE);
	/*
	 * enabling interrupt (overflow or compare)
	 */
	if(Config_Ptr->mode==Timer1_compareMode)
	TIMSK=(TIMSK&(~0x30))|(1<<OCIE1A);
	else TIMSK=(TIMSK&(~0x30))|(1<<TOIE1);
	/*
	 * setting timer initial value
	 */
	TCNT1=Config_Ptr->initial_value;
	TCCR1A = (1<<FOC1A)| (1<<FOC1B);
	/*
	 * choosing operation mode
	 */
	TCCR1B = (TCCR1B&(~(1<<WGM12)))|(Config_Ptr->mode<<WGM12);
	/*
	 * setting compare value if in compare mode
	 */
	if(Config_Ptr->mode==Timer1_compareMode){
		OCR1A=Config_Ptr->compare_value;
	}
	/*
	 * setting pre-scaler
	 */
	TCCR1B = (TCCR1B&(~((1<<CS12)|(1<<CS11)|(1<<CS10))))|(Config_Ptr->prescaler);

}
/*
 * this function is made to de-initialze timer 1
 */
void Timer1_deInit(void){
	TCCR1B = TCCR1B&(~((1<<CS12)|(1<<CS11)|(1<<CS10)));
}
/*
 * this function is made to set the callback that will be called when timer fire
 */
void Timer1_setCallBack(void(*a_ptr)(void)){
	callback=a_ptr;
}
ISR(TIMER1_COMPA_vect){
	if(callback!=NULL_PTR)
	{
	callback();
	}
}
ISR(TIMER1_OVF_vect){
	if(callback!=NULL_PTR)
		{
		callback();
		}
}
