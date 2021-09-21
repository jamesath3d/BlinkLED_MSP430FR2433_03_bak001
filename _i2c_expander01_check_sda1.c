/*
 * _i2c_expander01_read6.c
 *
 *  Created on: Sep 2, 2021
 *      Author: james
 */

#include "_i2c_expander01.h"

uint8_t _i2c_expander01_check_sda1(void){
    uint8_t __ii ;
    uint8_t __aa ;
    for( __ii = 18 ; __ii != 0 ; __ii -- ){
        _I2C_EXPANDER_SDA_read(__aa);
        if ( __aa ) break ; // SDA is 1. All looks good.
        _I2C_EXPANDER_SCL_to0();
        _I2C_EXPANDER_SCL_to1();// try to generate SCL to make the slave device to release the SDA.
    }
    return __aa;
}
