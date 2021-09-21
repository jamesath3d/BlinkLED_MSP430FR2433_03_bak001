/*
 * _bit_set.c
 *
 *  Created on: Sep 20, 2021
 *      Author: james
 */


#include "_bit_set.h"
uint8_t _bit_count(uint8_t ___byte){
    uint8_t __tt;
    uint8_t __rt;
    if ( 0 == ___byte) {
        return 0 ;
    }
    __rt = 0 ;
    for ( __tt = 8 ; __tt != 0 ; __tt -- ){
        if ( ___byte & 1 ) {
            __rt ++ ;
        }
        ___byte >>= 1 ;
    }

    return __rt ;
}

void _byte_set(uint8_t ___cnt, uint8_t ___arr[] , uint8_t ___byte){
    uint8_t __ii ; 
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++ ) {
        ___arr[__ii] = ___byte ;
    }
} // _byte_set

uint8_t _byte_cmp(uint8_t ___cnt, uint8_t ___arr1[], uint8_t ___arr2[]){
    uint8_t __rt ; 
    uint8_t __ii ; 
    __rt = 0 ;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++ ) {
        if ( ___arr1[__ii] != ___arr2[__ii]  ) {
            __rt ++ ;
        }
    }
    return __rt ;
} // _byte_cmp

