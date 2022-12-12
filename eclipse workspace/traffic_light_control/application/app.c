 /******************************************************************************
 *
 * Module: application
 *
 * File Name: app.c
 *
 * Description: source file for the application
 *
 * Author: Youssef osama
 *
 *******************************************************************************/
/***************************includes**************************************************/
#include "app.h"
#include "../HAL/push_button_module/pushButton.h"
#include "../MCAL/timer1_module/timer1.h"
#include "../HAL/led_module/led.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {_error,_done}error_handling;
/****************************functions declaration**************************************************/
/*this function will be the callback of button interrupt*/
void pushButtonFunction (void);
/*this function will be the callback of timer 1 interrupt*/
void timerFunction(void);
/*this function will handle the transition between each state*/
error_handling carsNormalMode(void);
/*this function handle car moving state
 * cars green lights are on
 * pedestrians red lights are on
 * all other lights are off*/
error_handling carsMove(void);
/*this function handle cars will stop state
 * it flashes yellow lights of cars and pedestrians
 * all other lights are turned off
 * */
error_handling carsWillStop(void);
/*this function handle car stop state
 * cars red lights are on
 * pedestrians green lights are on
 * all other lights are turned off
 * */
error_handling carsStop(void);
/*this function handle cars will move state
 * it flashes yellow lights of cars and pedestrians
 * all other lights are turned off
 * */
error_handling carsWillMove(void);
/****************************global variables**************************************************/
unsigned int g_tickCounter=0;
unsigned char g_button_pressed=0;
/****************************functions definitions**************************************************/
void application(void){
initializeSystem();
while(1){
carsNormalMode();
}
}
void initializeSystem(void){
/*initialization of bush button*/
	PUSHBUTTON_init(PUSHBUTTON_RISING);
	PUSHBUTTON_setISR(pushButtonFunction);
/*initialization of LEDS and turning them off*/
	 LED_setup(carsPort,carsGreenPin);
	 LED_setup(carsPort,carsYellowPin);
	 LED_setup(carsPort,carsRedPin);
	 LED_setup(pedestriansPort,pedestriansGreenPin);
	 LED_setup(pedestriansPort,pedestriansGreenPin);
	 LED_setup(pedestriansPort,pedestriansGreenPin);
/*initializing timer*/
	{
		Timer1_ConfigType config;
		config.mode=Timer1_compareMode;
		config.initial_value=0;
		/*this values will make timer fire every 0.5 second*/
		config.compare_value=15625/4;
		config.prescaler=Timer1_clk_1024_prescaler;
		Timer1_setCallBack(timerFunction);
		Timer1_init(&config);
	}
}
/*this function will be the callback of button interrupt*/
void pushButtonFunction(void){
g_button_pressed=1;
}
/*this function will be the callback of timer 1 interrupt*/
void timerFunction(void){
g_tickCounter++;
}
/*this function will handle the transition between each state*/
error_handling carsNormalMode(void){
carsMove();
carsWillStop();
carsStop();
carsWillMove();
return _done;
}
/*this function handle car moving state
 * cars green lights are on
 * pedestrians red lights are on
 * all other lights are off*/
error_handling carsMove(void){
	/*Cars move*/
	LED_control(carsPort,carsGreenPin,LED_TURN_ON);
	LED_control(carsPort,carsYellowPin,LED_TURN_OFF);
	LED_control(carsPort,carsRedPin,LED_TURN_OFF);
	/*pedestrian stop*/
	LED_control(pedestriansPort,pedestriansGreenPin,LED_TURN_OFF);
	LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_OFF);
	LED_control(pedestriansPort,pedestriansRedPin,LED_TURN_ON);
	while(g_tickCounter<10){
		if(g_button_pressed==1)
			return _done;
	}
	g_tickCounter=0;
	g_button_pressed=0;
	return _done;
}
/*this function handle cars will stop state
 * it flashes yellow lights of cars and pedestrians
 * all other lights are turned off
 * */
error_handling carsWillStop(void){
	/*Cars will stop*/
	LED_control(carsPort,carsGreenPin,LED_TURN_OFF);
	LED_control(carsPort,carsYellowPin,LED_TURN_ON);
	LED_control(carsPort,carsRedPin,LED_TURN_OFF);
	/*pedestrian will move*/
	LED_control(pedestriansPort,pedestriansGreenPin,LED_TURN_OFF);
	LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_ON);
	LED_control(pedestriansPort,pedestriansRedPin,LED_TURN_ON);
	while(g_tickCounter<10){
		if(g_tickCounter%2)
		{
			LED_control(carsPort,carsYellowPin,LED_TURN_ON);
			LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_ON);
		}else
		{
			LED_control(carsPort,carsYellowPin,LED_TURN_OFF);
			LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_OFF);
		}
	}
	g_button_pressed=0;
	g_tickCounter=0;
	return _done;
}
/*this function handle cars will move state
 * it flashes yellow lights of cars and pedestrians
 * all other lights are turned off
 * */
error_handling carsWillMove(void){
	/*Cars will stop*/
	LED_control(carsPort,carsGreenPin,LED_TURN_OFF);
	LED_control(carsPort,carsYellowPin,LED_TURN_ON);
	LED_control(carsPort,carsRedPin,LED_TURN_OFF);
	/*pedestrian will move*/
	LED_control(pedestriansPort,pedestriansGreenPin,LED_TURN_OFF);
	LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_ON);
	LED_control(pedestriansPort,pedestriansRedPin,LED_TURN_ON);

	while(g_tickCounter<10){
		if(g_tickCounter%2)
		{
			LED_control(carsPort,carsYellowPin,LED_TURN_ON);
			LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_ON);
		}else
		{
			LED_control(carsPort,carsYellowPin,LED_TURN_OFF);
			LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_OFF);
		}
		if(g_button_pressed==1)
			return _done;
	}
	g_button_pressed=0;
	g_tickCounter=0;
	return _done;
}
/*this function handle car stop state
 * cars red lights are on
 * pedestrians green lights are on
 * all other lights are turned off
 * */
error_handling carsStop(void){
	/*Cars stop*/
	LED_control(carsPort,carsGreenPin,LED_TURN_OFF);
	LED_control(carsPort,carsYellowPin,LED_TURN_OFF);
	LED_control(carsPort,carsRedPin,LED_TURN_ON);

	/*pedestrian cross*/
	LED_control(pedestriansPort,pedestriansGreenPin,LED_TURN_ON);
	LED_control(pedestriansPort,pedestriansYellowPin,LED_TURN_OFF);
	LED_control(pedestriansPort,pedestriansRedPin,LED_TURN_OFF);
	/*no action will be taken if button pressed pedestrians was just crossing*/
	while(g_tickCounter<10){}
	g_button_pressed=0;
	g_tickCounter=0;
	return _done;
}
