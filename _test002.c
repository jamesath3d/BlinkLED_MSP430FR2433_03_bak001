/*
 * _test002.c
 *
 *  Created on: Sep 2, 2021
 *      Author: james
 */

#include "_test.h"

void _test002(void){

    volatile int8_t j;
    volatile uint8_t iii;

    _i2c01_clk_to_1();
    _i2c01_clk_to_0();

    // --- start
    _i2c01_clk_to_1();
    _i2c01_sda_to_1();
    _i2c01_sda_to_0();

    iii= 0x41 ; // 0100_A2_A1_A0_RW , 0x4 + R->1

    _i2c01_clk_to_0(); // ahead, SDA must change when clk0
    for (j=7; j>=0 ; j--){
        if (( iii & 0x80) == 0 ) {
            _i2c01_sda_to_0();
        }
        else {
            _i2c01_sda_to_1();
        }
        iii <<=1 ;
        _i2c01_clk_to_1();
        _i2c01_clk_to_0();
    }

    _i2c01_sda_to_1();
    _i2c01_clk_to_1();
    // check SDA for ACK here.....
    _i2c01_clk_to_0();


    // end
    _delay_100us();
    _delay_100us();
    _delay_100us();
    _i2c01_clk_to_1();

}
