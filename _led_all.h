/*
 * _led_all.h
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */

#ifndef LED_ALL_H_
#define LED_ALL_H_

#include "_include_all.h"

//#include "_i2c01.h"


// p1.0/red
#define _LED_red_PORT_            1
#define _LED_red_PIN_             6
#define _LED_red_TO_1()           { _Set1_(_LED_red); }     // to 1
#define _LED_red_TO_0()           { _Set0_(_LED_red); }     // to 0
#define _LED_red_set_out()        { _SetOUT_( _LED_red ); }     
#define _LED_red_on()             _LED_red_TO_0()
#define _LED_red_off()            _LED_red_TO_1()


// p1.7/green
#define _LED_green_PORT_            1
#define _LED_green_PIN_             7
#define _LED_green_TO_1()           { _Set1_(_LED_green); }     // to 1
#define _LED_green_TO_0()           { _Set0_(_LED_green); }     // to 0
#define _LED_green_set_out()        { _SetOUT_( _LED_green ); }     
#define _LED_green_on()             _LED_green_TO_0()
#define _LED_green_off()            _LED_green_TO_1()

void _led_red_set_output(void);
void _led_green_set_output(void);
void _led_red_toggle(void);
void _led_green_toggle(void);


#endif /* LED_ALL_H_ */
