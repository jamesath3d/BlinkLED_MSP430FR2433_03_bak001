/*
 * _toggle_led_red_output.c
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */

#include "_include_all.h"

void _led_red_toggle(void){
    GPIO_toggleOutputOnPin(
        GPIO_PORT_P1,
        GPIO_PIN6  // Toggle P1.6 output
        );
}
