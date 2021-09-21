/*
 * _toggle_led_green_output.c
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */
#include "_include_all.h"


void _led_green_toggle(void){
    GPIO_toggleOutputOnPin(
        GPIO_PORT_P1,
        GPIO_PIN7  // Toggle P1.7 output
        );
}
