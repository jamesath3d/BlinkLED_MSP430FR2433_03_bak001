/*
 * _bit_set.c
 *
 *  Created on: Sep 20, 2021
 *      Author: james
 */


#include "_bit_set.h"
void _bit_and(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] ){
    uint8_t __ii ;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++ ) {
        ___O[__ii] = ___A[__ii] & ___B[__ii] ;
    }
} // _bit_and
void _bit_or(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] ){
    uint8_t __ii ;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++ ) {
        ___O[__ii] = ___A[__ii] | ___B[__ii] ;
    }
} // _bit_or
void _bit_xor(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] ){
    uint8_t __ii ;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++ ) {
        ___O[__ii] = ___A[__ii] ^ ___B[__ii] ;
    }
} // _bit_xor
void _bit_inv(uint8_t ___cnt, uint8_t ___A[], uint8_t ___O[] ){
    uint8_t __ii ;
    for ( __ii = 0 ; __ii < ___cnt ; __ii ++ ) {
        ___O[__ii] = ~___A[__ii] ;
    }
} // _bit_inv

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
} // _bit_count

uint8_t _bit_set(uint8_t ___idx){
    uint8_t __rt;
    __rt = 1 ;
    __rt <<= ___idx;
    return __rt ;
} // _bit_set

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

