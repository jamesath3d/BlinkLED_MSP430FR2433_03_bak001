/*
 * _test003.c
 *
 *  Created on: Sep 2, 2021
 *      Author: james
 */

#include "_test.h"

void _test003(void){

    volatile int8_t j;
    volatile uint8_t iii;


    _I2C01_CLK_TO_1();
    _I2C01_CLK_TO_0();

    // --- start
    _I2C01_CLK_TO_1();
    _I2C01_SDA_TO_1();
    _I2C01_SDA_TO_0();

    iii= 0x41 ; // 0100_A2_A1_A0_RW , 0x4 + R->1

    _I2C01_CLK_TO_0(); // ahead, SDA must change when clk0
    for (j=7; j>=0 ; j--){
        if (( iii & 0x80) == 0 ) {
            _I2C01_SDA_TO_0();
        }
        else {
            _I2C01_SDA_TO_1();
        }
        iii <<=1 ;
        _I2C01_CLK_TO_1();
        _I2C01_CLK_TO_0();
    }

    _I2C01_SDA_TO_1();
    _I2C01_CLK_TO_1();
    // check SDA for ACK here.....
    _I2C01_CLK_TO_0();


    // end
    //_delay_100us();
    //_delay_100us();
    //_delay_100us();
    _I2C01_CLK_TO_1();

}
