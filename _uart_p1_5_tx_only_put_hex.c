/*
 * _uart_p1_5_tx_only.c
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

#include "_uart_p1_5_tx_only.h"

void _uart_p1_5_tx_only_put_rn(void){
    _UART_P1_5_TX_PUT_CH('\r');
    _UART_P1_5_TX_PUT_CH('\n');
}

void _uart_p1_5_tx_only_put_uint32(uint32_t ___uuu){
    uint32_t __uu;
    uint8_t  __u;
    uint8_t  __ii;
    _UART_P1_5_TX_PUT_CH(' ');
    for ( __ii = 4 ; __ii > 0 ; __ii --) {
        __uu = 0xff000000 & ___uuu ;
        __uu >>=24 ;
        __u = __uu & 0xff;
        ___uuu <<=8;
        _uart_p1_5_tx_only_put_hex(__u);
    }
    _UART_P1_5_TX_PUT_CH(' ');
}


void _uart_p1_5_tx_only_put_hex_half(uint8_t ___hexhalf){
    ___hexhalf &= 0xf;
    if ( ___hexhalf >= 10 ) {
        ___hexhalf += ('A' - 10 );
    } else {
        ___hexhalf += '0' ;
    }
    _UART_P1_5_TX_PUT_CH(___hexhalf);
}

void _uart_p1_5_tx_only_put_hex(uint8_t ___hexbyte){
    uint8_t __hex;
    __hex = 0xf0 & ___hexbyte;
    __hex >>=4;
    _uart_p1_5_tx_only_put_hex_half( __hex );
    _uart_p1_5_tx_only_put_hex_half( ___hexbyte );
}

void _uart_p1_5_tx_only_put_hex_u8(uint8_t ___hexbyte){
    _uart_p1_5_tx_only_put_hex(___hexbyte);
    _uart_p1_5_tx_only_put_ch('(');
    _uart_p1_5_tx_only_put_u8(___hexbyte);
    _uart_p1_5_tx_only_put_ch(')');
}

void _uart_p1_5_tx_only_put_u8(uint8_t ___hexbyte){
    uint8_t __tt;

    __tt=0;
    if( ___hexbyte >= 100 ) {
        __tt = ___hexbyte - 100 ;
        if( __tt >= 100 ) {
            _uart_p1_5_tx_only_put_hex_half(2);
            ___hexbyte -= 200;
        } else {
            _uart_p1_5_tx_only_put_hex_half(1);
            ___hexbyte -= 100;
        }
    }
    if( ___hexbyte >= 10 ) {
        __tt = ___hexbyte / 10;
        _uart_p1_5_tx_only_put_hex_half(__tt);
        ___hexbyte -= (10 * __tt);
    } else {
        if ( 0 != __tt ) {
            _uart_p1_5_tx_only_put_hex_half(0);
        }
    }
    _uart_p1_5_tx_only_put_hex_half(___hexbyte);
}

void _uart_p1_5_tx_only_put_hexS(uint8_t ___cnt , uint8_t ___hexbyte[]){
    int8_t  __ii;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++) {
        if (__ii != 0 && 0 == __ii % 2 ) {
            _uart_p1_5_tx_only_put_ch('_');
        }
        _uart_p1_5_tx_only_put_hex(___hexbyte[__ii]);
    }
}

void _uart_p1_5_tx_only_put_ch(uint8_t ___ch){
    _UART_P1_5_TX_PUT_CH( ___ch );
}

void _uart_p1_5_tx_only_put_str(uint8_t ___str[]){
    uint8_t * __lp;
    uint8_t   __c;

    __lp = &(___str[0]);
    while ( 0 != __lp ) {
        __c = (*__lp);
        if (0 == __c) {
            break ;
        }
        _UART_P1_5_TX_PUT_CH(__c);
        __lp ++;
    }
}
