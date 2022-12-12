 /******************************************************************************
 *
 * Module: led
 *
 * File Name: led.c
 *
 * Description: source file for led driver
 *
 * Author: Youssef Osama
 *
 *******************************************************************************/

#include "led.h"
#include "../../MCAL/gpio_module/gpio.h"
/*this function is made to setup the LEDS*/
LED_return LED_setup(uint8 port,uint8 pin)
{
	GPIO_setupPinDirection(port, pin, PIN_OUTPUT);
		GPIO_writePin(port, pin, LOGIC_LOW);
		return LED_DONE;
}
/*this function is made to control LEDS*/
LED_return LED_control(uint8 port,uint8 pin,LED_state state){
	GPIO_writePin(port, pin,state);
	return LED_DONE;
}
