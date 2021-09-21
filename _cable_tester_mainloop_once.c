/*
 * _cable_tester_mainloop.c
 *
 *  Created on: Sep 20, 2021
 *      Author: james
 */


#include "_cable_tester.h"

static uint32_t _cbidx ;
static uint8_t _co6x2[12];
static uint8_t _up6x2[12];
static uint8_t _crt;
static uint8_t _wireAmount ;

static uint8_t _zzz6x2[12]={0,0,0,0,0,0, 0,0,0,0,0,0 };
static uint8_t _inv6x2[12]={0xF0,0xF8,0xFF, 0xE0,0xFF,0xFF, 0xF0,0xF0,0xF0, 0x00,0xFF,0xFF};
static uint8_t _fff6x2[12];


static uint8_t _ttt6x2[12];

inline uint8_t _cable_tester_mainloop_onceZ(uint8_t ___idx, uint8_t ___arr6[], uint8_t ___rowIdx ){
    return 0;
}

inline uint8_t _cable_tester_mainloop_onceXY(uint8_t ___idx){
    int8_t __ii;
    int8_t __ok;

    _CB_PR_1hex_rn(" checking No. <","> wire.", ___idx);
    for (__ii=11; __ii >= 0 ; __ii --){
        _ttt6x2[__ii] = 0;
    }
    __ok = _cable_tester_mainloop_onceZ( ___idx , _ttt6x2 , 0 );
    if ( 0 == __ok ) {        return 0;    }

    return 0xFF ;
}

// test the i2c bus's slave device and all the pins of the io-expanders.
uint8_t _cable_tester_mainloop_onceX1(void){ 
    //int8_t __ii;
    uint8_t __rt;

    _CB_PR_str("==X1==\r\n");
    _crt = 0 ;
    _crt  = _i2c_expander01_read6(0, _co6x2);
    _crt += _i2c_expander01_read6(1, _co6x2 + 6);
    _crt += _i2c_expander01_read6(2, _up6x2);
    _crt += _i2c_expander01_read6(3, _up6x2 + 6);

    _CB_PR_12hex_rn("init state : col : ", 0 , _co6x2);
    _CB_PR_12hex_rn("init state : up  : ", 2 , _up6x2 );

    _CB_PR_1hex_rn(" read bytes amount: 0x","<<-- it should be 0x18(24). OK.", _crt);
    if ( 0x18 != _crt ){
        _CB_err_return(11);
    }
    _CB_PR_str(" step 11: i2-expander's i2c bus test ok. \r\n");

    _byte_set(12, _ttt6x2, 0xff );
    _CB_PR_12hex_rn("_ttt6x2 : up  : ", 2 , _ttt6x2 );

    __rt = _byte_cmp(12, _ttt6x2, _co6x2 );
//        +  _byte_cmp(12, _ttt6x2, _up6x2 );

    _CB_PR_1hex_rn(" step 12: i2c expander PIN's float tested differency : " , " <<-- should be zero.", __rt);
    return __rt ;
} // _cable_tester_mainloop_onceX1

uint8_t _cable_tester_mainloop_onceX2(void){
    int8_t __ii;
    //uint8_t __rt;

    _CB_PR_str("==X2==\r\n");
    _i2c_expander01_write6(0, _zzz6x2);
    _i2c_expander01_write6(1, _zzz6x2);
    _i2c_expander01_read6(2, _up6x2);
    _i2c_expander01_read6(3, _up6x2 + 6);
    _CB_PR_12hex_rn("after zero , up state : ", 2 , _up6x2);

    _crt = 0 ;
    _wireAmount = 0 ;
    for ( __ii = 11 ; __ii >= 0 ; __ii -- ){
        _fff6x2[__ii] = (_inv6x2[__ii] ^ 0xff);
        if ( _up6x2[__ii] != _inv6x2[__ii]) { _crt ++ ; }
        _wireAmount += _bit_count( _fff6x2[__ii]);
    }
    _CB_PR_12hex_rn("default INV  vector :   ", 2 , _inv6x2);
    _CB_PR_12hex_rn("default test vector :   ", 2 , _fff6x2);

    _CB_PR_1hex_rn(" comparing diffence between  amount : ", "<-- it should be zero", _crt );
    if( _crt ) {_CB_err_return( 3 );}

    return 0 ;
} // _cable_tester_mainloop_onceX2

uint8_t _cable_tester_mainloop_onceX3(void){
    int8_t __ii;
    uint8_t __rt;

    _CB_PR_1hex_rn("==X3== total amount of the wires : ", "<-- it should be 0x20(32)", _wireAmount );
    for ( __ii = 0 ; __ii < _wireAmount ; __ii ++ ){
        __rt = _cable_tester_mainloop_onceXY(__ii);
        if ( __rt ){
            _CB_err_return3( "error found at NO.(", "), please check it. Exit....", 2 );
        }
    }

    _CB_PR_str( "All looks good. Sleep. 20 seconds later will try again.\r\n")
    return 0 ;
} // _cable_tester_mainloop_onceX3

uint8_t _cable_tester_mainloop_onceX(void){
    uint8_t __rt ;
    __rt = _cable_tester_mainloop_onceX1();
    if ( __rt ) { return __rt ; }

    __rt = _cable_tester_mainloop_onceX2();
    if ( __rt ) { return __rt ; }

    __rt = _cable_tester_mainloop_onceX3();
    if ( __rt ) { return __rt ; }

    return 0 ;
}

uint8_t _cable_tester_mainloop_once(void){
    uint8_t __rt ;
    _I2C_EXPANDER01_RESET_OFF();

    _CB_PR_str("\r\nCable tester start:");
    _CB_PR_uint32(_cbidx++);
    _CB_PR_rn();

    __rt = _cable_tester_mainloop_onceX();
    _I2C_EXPANDER01_RESET_ON();


    if ( __rt ) {
        _CB_PR_1hex_rn(" End with error code : " , " <<-- should be zero \r\n", __rt);
    } else {
        _CB_PR_str("Cable tester succeed end.\r\n");
    }

    return __rt ;
}
