/*
 * _set_led_green_output.c
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */

#include "_include_all.h"

void _led_green_set_output(void){

    GPIO_setAsOutputPin(
        GPIO_PORT_P1, // LED green : P1.7
        GPIO_PIN7
        );

}

