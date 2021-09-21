/*
 * 
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */


#include "_i2c01.h"

void _i2c01_clk_to_1(void){
    GPIO_setOutputHighOnPin(
        _I2C01_CLK_PORT,
        _I2C01_CLK_PIN
        );
}

