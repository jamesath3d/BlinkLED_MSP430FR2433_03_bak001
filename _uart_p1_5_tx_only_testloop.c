/*
 * _uart_p1_5_tx_only_testloop.c
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

#include <msp430.h>
#include "_uart_p1_5_tx_only.h"

unsigned char _TXdata ;
void _uart_p1_5_tx_only_testloop(void){
    while (1)
    {
        //_delay_100us();        _delay_100us();        _delay_100us();
        if ( _TXdata ) {
            _TXdata = 0 ;
            _uart_p1_5_tx_only_put_ch( '5' );
            _uart_p1_5_tx_only_put_ch( 'A' );
        } else {
            _TXdata = 1 ;
            _uart_p1_5_tx_only_put_ch( 'A' );
            _uart_p1_5_tx_only_put_ch( '5' );
        }
        _uart_p1_5_tx_only_put_ch( '\r' );
        _uart_p1_5_tx_only_put_ch( '\n' );

        //__bis_SR_register(LPM0_bits|GIE);     // Enter LPM0
        //__no_operation();                     // For debugger

        _delay_100ms();
        _delay_1s();
    }
}
