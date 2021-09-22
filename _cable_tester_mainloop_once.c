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
static uint8_t _cidx;
static uint8_t _cGood;
static uint8_t _cBad;
static uint8_t _wireAmount ;

static uint8_t _zzz6x2[12]   ={0,0,0,0,0,0, 0,0,0,0,0,0 };
static uint8_t _inv6x2[12]   ={0xF0,0xF8, 0xFF,0xE0, 0xFF,0xFF, 0xF0,0xF0, 0xF0,0x00, 0xFF,0xFF};
static uint8_t _switch6x2[12]={0x00,0x00, 0x00,0xff, 0x00,0x00, 0xff,0x00, 0x00,0x00, 0x00,0x00};
static uint8_t _fff6x2[12];


static uint8_t _vvv6x2[12];
static uint8_t _ccc6x2[12];
static uint8_t _ttt6x2[12];

inline uint8_t _cable_tester_bit_calc_switch(uint8_t ___byte_idx, uint8_t ___bit_idx ){
    uint8_t __rt;
    __rt = _bit_set(___byte_idx);
    __rt >>= (___bit_idx + 1);
    return __rt ;
} // _cable_tester_bit_calc_switch
inline uint8_t _cable_tester_mainloop_onceX3Y(void){
    uint8_t __ii;
    uint8_t __jj;
    uint8_t __mm;
    uint8_t __rt;
    uint8_t __switch;

    __rt = 0 ;
    __switch = 0 ;
    _byte_set(12, _vvv6x2 , 0 );
    _byte_set(12, _ccc6x2 , 0 );

    __mm=_cidx;
    for (__ii=0; __ii < 12 ; __ii ++){
        __jj = _bit_count(_fff6x2[__ii]);
        if ( __mm < __jj ) {
            _vvv6x2[__ii] = _bit_set(__mm);
            __switch = _switch6x2[ __ii ] ;

            if ( __switch ) {
                _ccc6x2[__ii] = _cable_tester_bit_calc_switch(__jj, __mm);
            } else {
                _ccc6x2[__ii] = _vvv6x2[__ii] ;
            }

            break ;
        }
        __mm -= __jj ;
    }



    if ( 2 == 3 ) {
        _CB_PR_1hex_u8(" ii:", "", __ii);
        _CB_PR_1hex_u8(" jj:", "", __jj);
        _CB_PR_1hex_u8(" mm:", " ", __mm);
    }


    _CB_PR_12hex("wire vector : ", _cidx , _vvv6x2);
    if ( 12 == __ii ) {
        _CB_PR_rn();
        return 95 ;
    }
    _CB_PR_1hex(",", ", ", _ccc6x2[__ii] );

    _I2C_EXPANDER01_RESET_ON();
    _I2C_EXPANDER01_RESET_OFF();
    _i2c_expander01_write6(0, _vvv6x2);
    _i2c_expander01_write6(1, _vvv6x2 + 6);
    _i2c_expander01_read6(2, _up6x2);
    _i2c_expander01_read6(3, _up6x2 + 6 );
    _CB_PR_12hex(", Pos:", _cidx , _up6x2);

    if ( __switch ) {
        _bit_or( 12, _ccc6x2, _inv6x2, _ttt6x2 );
    } else {
        _bit_or( 12, _vvv6x2, _inv6x2, _ttt6x2 );
    }

    __ii = _byte_cmp(12, _ttt6x2, _up6x2 );

    if ( __ii ) {
        _CB_PR_12hex_rn(" failed. it should be : ", __ii , _ttt6x2);
        __rt ++ ;
    } else {
        _CB_PR_str(" ok.");
    }

    _bit_inv( 12, _vvv6x2, _ttt6x2 );

    _I2C_EXPANDER01_RESET_ON();
    _I2C_EXPANDER01_RESET_OFF();
    _i2c_expander01_write6(0, _ttt6x2);
    _i2c_expander01_write6(1, _ttt6x2 + 6);
    _i2c_expander01_read6(2, _up6x2);
    _i2c_expander01_read6(3, _up6x2 + 6 );
    _CB_PR_12hex(" Neg : ", _cidx , _up6x2);

    if ( __switch ) {
        _bit_inv( 12, _ccc6x2, _ttt6x2 );
    }

    __ii = _byte_cmp(12, _ttt6x2, _up6x2 );
    if ( __ii ) {
        _CB_PR_12hex(" failed, it should be : ", __ii , _ttt6x2);
        __rt ++ ;
    }

    if ( __rt ) {
        _cBad ++ ;
        _CB_PR_1hex_u8_rn(". bad.========", "", _cBad );
        return 92 ;
    }

    _cGood ++ ;
    //_CB_PR_str_rn(" ok.----------------------------------" );
    _CB_PR_1hex_u8_rn(" ok.----------------------------------", "", _cGood );
    return 0 ;
} // _cable_tester_mainloop_onceX3Y

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

    _CB_PR_1hex_u8_rn(" read bytes amount: 0x","<<-- it should be 0x18(24). OK.", _crt);
    if ( 0x18 != _crt ){
        _CB_err_return(11);
    }
    _CB_PR_str(" step 11: i2-expander's i2c bus test ok. \r\n");

    _byte_set(12, _ttt6x2, 0xff );
    _CB_PR_12hex_rn("_ttt6x2 : up  : ", 2 , _ttt6x2 );

    __rt =  _byte_cmp(12, _ttt6x2, _co6x2 );
    __rt += _byte_cmp(12, _ttt6x2, _up6x2 );

    _CB_PR_1hex_u8_rn(" step 12: i2c expander PIN's float tested differency : " , " <<-- should be zero.", __rt);

    if ( __rt ) {
        _CB_PR_str_rn(" some wires are short to GND. check the aboves init state of up and col");
    } else {
        _CB_PR_str_rn(" 13 : all looks good. no wires are short to GND.");
    }
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
    _CB_PR_12hex_rn("after zero , read up state : ", 2 , _up6x2);

    for ( __ii = 11 ; __ii >= 0 ; __ii -- ){
        _fff6x2[__ii] = (_inv6x2[__ii] ^ 0xff);
    }

    __ii = _byte_cmp(12, _inv6x2, _up6x2 );

    _CB_PR_12hex_rn("default INV  vector :        ", 2 , _inv6x2);
    _CB_PR_12hex_rn("default test vector :        ", 2 , _fff6x2);

    _CB_PR_1hex_u8_rn(" step 22 : comparing diffence between  amount : ", "<-- it should be zero", __ii );
    if( __ii ) {
        _CB_PR_1hex_u8(" step 23 : amount of diffences is : ", "", (( __ii >> 4 ) & 0x0f) );
        _CB_PR_1hex_u8(", the 1st diffence is index : ", "\r\n", (( __ii & 0x0f)+1) );
        _CB_err_return( 3 );
    } else {
        _CB_PR_str_rn("step 24 : all wires can be pulled down. No opened.");
    }

    return 0 ;
} // _cable_tester_mainloop_onceX2

uint8_t _cable_tester_mainloop_onceX3(void){
    int8_t __ii;

    _wireAmount = 0 ;
    for ( __ii = 11 ; __ii >= 0 ; __ii -- ){
        _wireAmount += _bit_count( _fff6x2[__ii]);
    }
    _CB_PR_1hex_u8_rn("==X3== total amount of the wires : ", "<-- it should be 0x20(32)", _wireAmount );

    _crt = 0 ;
    _cGood = 0 ;
    _cBad = 0 ;
    for ( _cidx = 0 ; _cidx < _wireAmount ; _cidx ++ ){
        if ( _cable_tester_mainloop_onceX3Y()) {
            _crt ++;
        }
    }
    if ( _crt ){
            _CB_err_return3( "error found at NO.(", "), please check it. Exit....", 32 );
        }

    _CB_PR_str( "All looks good. Sleep. 20 seconds later will try again.\r\n")
    return 0 ;
} // _cable_tester_mainloop_onceX3

uint8_t _cable_tester_mainloop_onceX(void){
    uint32_t __ii ;
    __ii += _cable_tester_mainloop_onceX1();

    __ii = _cable_tester_mainloop_onceX2();

    __ii = _cable_tester_mainloop_onceX3();

    if ( __ii ) { 
        if ( __ii > 0xff ) {
            return (__ii & 0xff) ;
        }
        _CB_PR_str(" step 11118222 : why so many error ? 0x");
        _CB_PR_uint32(__ii);
        _CB_PR_rn();
        return 0xFF ; 
    }

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
        _CB_PR_1hex_u8_rn(" End with error code : " , " <<-- should be zero \r\n", __rt);
    } else {
        _CB_PR_str("Cable tester succeed end.\r\n");
    }

    return __rt ;
}
