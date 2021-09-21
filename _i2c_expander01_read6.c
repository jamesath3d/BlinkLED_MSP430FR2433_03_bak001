/*
 * _i2c_expander01_read6.c
 *
 *  Created on: Sep 2, 2021
 *      Author: james
 */

#include "_i2c_expander01.h"

inline uint8_t _i2c_expander01_read6x(uint8_t ___i2cIdx, uint8_t ___r6[]){

    uint8_t __i2cAddrByte ;
    uint8_t __byteIdx ;
    uint8_t __bitIdx ;
    uint8_t __ack ;
    uint8_t __tmpByte ;

    __i2cAddrByte = ((___i2cIdx & 0x3)<<1);
    __i2cAddrByte |= 0x41 ; // 'b0100 + a3 + a2 + a1 + R1W0

    for ( __bitIdx =8 ; __bitIdx != 0 ; __bitIdx -- ) {
        _I2C_EXPANDER_SCL_to0();
        if (__i2cAddrByte & 0x80) { _I2C_EXPANDER_SDA_to1(); }
        else                      { _I2C_EXPANDER_SDA_to0(); }
        _I2C_EXPANDER_SCL_to1();
        __i2cAddrByte <<=1 ;
    }


    _I2C_EXPANDER_SCL_to0();
    _I2C_EXPANDER_SDA_read(__ack);
    _I2C_EXPANDER_SCL_to1();

    if ( __ack ) { // ack --> 1 ==> means no ACK.... stop at once, and try to release bus.
        return  0x21 ; // 0x21
    }
    //return  0x22 ; // 0x22 // don't read the followings. for debug only

    for( __byteIdx = 0 ; __byteIdx <= 5 ; __byteIdx ++){
        __tmpByte = 0 ;
        for ( __bitIdx = 8 ; __bitIdx != 0 ; __bitIdx -- ) {
            _I2C_EXPANDER_SCL_to0();
            _I2C_EXPANDER_SDA_read(__ack);
            _I2C_EXPANDER_SCL_to1();
            __tmpByte <<=1 ;
            if ( __ack ) {
                __tmpByte |=1 ;
            }
        }
        _I2C_EXPANDER_SCL_to0();
        //_I2C_EXPANDER_SDA_read(__ack);
        _I2C_EXPANDER_SDA_to0();
        _I2C_EXPANDER_SCL_to1();
        /*
        if ( __ack ) { // ack --> 1 ==> means no ACK.... stop at once, and try to release bus.
            //return __byteIdx & 0x60 ; // high 4-bit is 0x6, low 4-bit is the error index.
        }
        */
        ___r6[__byteIdx] = __tmpByte ;
    }

    return __byteIdx;
}

uint8_t _i2c_expander01_read6XXX(uint8_t ___i2cIdx, uint8_t ___r6[]){
    uint8_t __rt ;

    // the i2C bus is lock by the other end and can not be release. error 0x21. exit.
    if ( 0 == _i2c_expander01_check_sda1() ) {
        return 0x81 ;
    }


    _I2C_EXPANDER_START();
    __rt = _i2c_expander01_read6x(___i2cIdx, ___r6);

    // the i2C bus is lock by the other end and can not be release. error 0x91. exit.
    if ( 0 == _i2c_expander01_check_sda1() ){
        return 0x91 ;
    }

    _I2C_EXPANDER_STOP();
    return __rt;
}
