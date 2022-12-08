 /******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: timer1.h
 *
 * Description: header file for timer 1 driver
 *
 * Author: Youssef Osama
 *
 *******************************************************************************/

#ifndef TIMER1_H_
#define TIMER1_H_
#include "common_macros.h"
#include "std_types.h"
typedef enum{
Timer1_clk_1_prescaler=1,
Timer1_clk_8_prescaler,
Timer1_clk_64_prescaler,
Timer1_clk_256_prescaler,
Timer1_clk_1024_prescaler,
Timer1_Ext_t1_falling_prescaler,
Timer1_Ext_t1_raising_prescaler,
}Timer1_Prescaler;
typedef enum{
Timer1_overflowMode=0,
Timer1_compareMode,
}Timer1_Mode;
typedef struct {
 uint16 initial_value;
 uint16 compare_value; // it will be used in compare mode only.
 Timer1_Prescaler prescaler;
 Timer1_Mode mode;
} Timer1_ConfigType;
/*this function initialize timer 1
 * configuration has initial value , compare value , pre-scaler ,operation mode
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr);
/*
 * this function is made to de-initialze timer 1
 */
void Timer1_deInit(void);
/*
 * this function is made to set the callback that will be called when timer fire
 */
void Timer1_setCallBack(void(*a_ptr)(void));


#endif
