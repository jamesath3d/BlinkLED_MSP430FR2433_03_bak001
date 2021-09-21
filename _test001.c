/*
 * _test001.c
 *
 *  Created on: Sep 2, 2021
 *      Author: james
 */

#include "_test.h"

void _test001(void){

	//    volatile int8_t j;
	//    volatile uint8_t iii;

    P1OUT |= BIT3;// to 1
    P1OUT &= (~BIT3);// to 0
    P1OUT |= BIT3;// to 1
    P1OUT &= (~BIT3);// to 0
    P1OUT |= BIT3;// to 1
    P1OUT &= (~BIT3);// to 0
    P1OUT |= BIT3;// to 1


    return;


}
