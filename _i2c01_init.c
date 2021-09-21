/*
 * 
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */


#include "_i2c01.h"

void _i2c01_init(void){

    GPIO_setAsOutputPin(
        _I2C01_CLK_PORT,
        _I2C01_CLK_PIN
        );

    GPIO_setAsInputPin(
        _I2C01_SDA_PORT,
        _I2C01_SDA_PIN
        );
    GPIO_setOutputLowOnPin(
        _I2C01_SDA_PORT,
        _I2C01_SDA_PIN
        );
}

