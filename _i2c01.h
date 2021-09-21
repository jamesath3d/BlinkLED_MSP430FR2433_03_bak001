/*
 * _i2c.h
 *
 *  Created on: Aug 30, 2021
 *      Author: james
 */

#ifndef I2C01_H_
#define I2C01_H_

#include "_include_all.h"

// p1.3/A3/i2cSCL
#define _I2C01_CLK_PORT_ 1
#define _I2C01_CLK_PIN_  3
#define _I2C01_CLK_PORT  GPIO_PORT_P1
#define _I2C01_CLK_PIN   GPIO_PIN3
#define _I2C01_CLK_out   P1OUT
#define _I2C01_CLK_dir   P1DIR
#define _I2C01_CLK_bit   BIT3

// p1.2/A2/i2cSDA
#define _I2C01_SDA_PORT_ 1
#define _I2C01_SDA_PIN_  2
#define _I2C01_SDA_PORT  GPIO_PORT_P1
#define _I2C01_SDA_PIN   GPIO_PIN2
#define _I2C01_SDA_out   P1OUT
#define _I2C01_SDA_dir   P1DIR
#define _I2C01_SDA_bit   BIT2


//#define _I2C01_CLK_TO_1() { _I2C01_CLK_out |=   _I2C01_CLK_bit;  }     // to 1
//#define _I2C01_CLK_TO_0() { _I2C01_CLK_out &= (~_I2C01_CLK_bit); }     // to 0
#define _I2C01_CLK_TO_1() { _Set1(_I2C01_CLK); }     // to 1
#define _I2C01_CLK_TO_0() { _Set0(_I2C01_CLK); }     // to 0

//#define _I2C01_SDA_TO_0() { _I2C01_SDA_dir |=   _I2C01_SDA_bit;  }     // to 1 -> output -> force-down by MOS   -> value to 0// set dir to out
//#define _I2C01_SDA_TO_1() { _I2C01_SDA_dir &= (~_I2C01_SDA_bit); }     // to 0 -> input  -> pull-up by resistor -> value to 1// set dir to in
//#define _I2C01_SDA_TO_0() { _SetOUT( _I2C01_SDA ); }     // to 1 -> output -> force-down by MOS   -> value to 0// set dir to out
//#define _I2C01_SDA_TO_1() { _SetIN(  _I2C01_SDA ); }     // to 0 -> input  -> pull-up by resistor -> value to 1// set dir to in
#define _I2C01_SDA_TO_0() { _SetOUT_( _I2C01_SDA ); }     // to 1 -> output -> force-down by MOS   -> value to 0// set dir to out
#define _I2C01_SDA_TO_1() { _SetIN_(  _I2C01_SDA ); }     // to 0 -> input  -> pull-up by resistor -> value to 1// set dir to in

//#define _I2C01_INIT()      { _I2C01_CLK_dir |=   _I2C01_CLK_bit;  _I2C01_SDA_dir &= (~_I2C01_SDA_bit); _I2C01_SDA_out &= (~_I2C01_SDA_bit); } // clk -> output, sda -> input + 0
#define _I2C01_INIT()        { _Set1_(_I2C01_CLK); _SetOUT_(_I2C01_CLK) ;  _SetIN_(_I2C01_SDA); _Set0_(_I2C01_SDA); } // clk -> output, sda -> input + 0

#define _I2C01_START()       { _I2C01_CLK_TO_1(); _I2C01_SDA_TO_1(); _I2C01_SDA_TO_0(); }
#define _I2C01_STOP()        { _I2C01_CLK_TO_0(); _I2C01_SDA_TO_0(); _I2C01_CLK_TO_1(); _I2C01_SDA_TO_1(); }
#define _I2C01_SDA_read(aaa) { _I2C01_SDA_TO_1(); aaa = _READbit_(_I2C01_SDA); aaa = _READbit_(_I2C01_SDA); }

void _i2c01_init(void);
void _i2c01_clk_to_0(void);
void _i2c01_clk_to_1(void);
void _i2c01_sda_to_0(void);
void _i2c01_sda_to_1(void);

#endif /* I2C01_H_ */
