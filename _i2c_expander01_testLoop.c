/*
 * _i2c_expander01_testLoop.c
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

#include "_include_all.h"

uint8_t _vr61[6];
uint8_t _vr62[6];
uint8_t _vr63[6];
uint8_t _vr64[6];
uint8_t _vw61[6];
uint8_t _vw62[6];
uint8_t _vw63[6];
uint8_t _vw64[6];
uint8_t _vrt;

uint8_t _i2c_expander01_testLoopMainR(void){
    _vrt = _i2c_expander01_read6(0, _vr61);
    _delay_100us();
    _delay_100us();
    _vrt = _i2c_expander01_read6(1, _vr62);
    /*
    _vrt = _i2c_expander01_read6(2, _vr63);
    _vrt = _i2c_expander01_read6(3, _vr64);
    */
    return _vrt ;
}//_testLoopMain

uint8_t _ttt1;
uint8_t _i2c_expander01_testLoopMainW(void){
    if ( _ttt1 ) {
        _ttt1 = 0 ;
        _vw62[2] = 0x5A ;
    } else {
        _ttt1 = 1 ;
        _vw62[2] = 0xA5 ;
    }
    _vrt = _i2c_expander01_write6(2, _vw62);
    /*
    _vrt = _i2c_expander01_write6(0, _vw61);
    _vrt = _i2c_expander01_write6(1, _vw62);
    _vrt = _i2c_expander01_write6(2, _vw63);
    _vrt = _i2c_expander01_write6(3, _vw64);
    */
    return _vrt ;
}//_testLoopMain
