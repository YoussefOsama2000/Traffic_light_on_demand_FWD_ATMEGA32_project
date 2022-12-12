 /******************************************************************************
 *
 * Module: PushButton
 *
 * File Name: pushButton.h
 *
 * Description: header file for pushButton driver
 *
 * Author: Youssef Osama
 *
 *******************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_
typedef enum  PUSHBUTTON_return {PUSHBUTTON_ERROR=0,PUSHBUTTON_DONE=1}PUSHBUTTON_return;
typedef enum PUSHBUTTON_interruptEvent {PUSHBUTTON_LOW_LVL,PUSHBUTTON_ANY_CHANGE,PUSHBUTTON_FALLING,PUSHBUTTON_RISING}PUSHBUTTON_interruptEvent;
/*this function is to initialize the push button*/
PUSHBUTTON_return PUSHBUTTON_init(PUSHBUTTON_interruptEvent event);
/*this function is to set the ISR of the button*/
PUSHBUTTON_return PUSHBUTTON_setISR( void (*fun_ptr)(void));
#endif
