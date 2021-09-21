#ifndef I2C_EXPENDER01_
#define I2C_EXPENDER01_

#include "_include_all.h"

// i2c expender reset pin : p1.0/A0
#define _I2C_EXPENDER01_RESET_PORT_  1
#define _I2C_EXPENDER01_RESET_PIN_   0
#define _I2C_EXPENDER01_RESET_PORT   GPIO_PORT_P1
#define _I2C_EXPENDER01_RESET_PIN    GPIO_PIN0
#define _I2C_EXPENDER01_RESET_out    P1OUT
#define _I2C_EXPENDER01_RESET_dir    P1DIR
#define _I2C_EXPENDER01_RESET_bit    BIT0

//#define _I2C_EXPANDER01_RESET_ON()   { _I2C_EXPENDER01_RESET_out &= (~_I2C_EXPENDER01_RESET_bit); _I2C_EXPENDER01_RESET_dir |= _I2C_EXPENDER01_RESET_bit;  }     // pin to 0 , pin to out
//#define _I2C_EXPANDER01_RESET_OFF()  { _I2C_EXPENDER01_RESET_out |=   _I2C_EXPENDER01_RESET_bit;  _I2C_EXPENDER01_RESET_dir |= _I2C_EXPENDER01_RESET_bit;  }     // pin to 1 , pin to out
#define _I2C_EXPANDER01_RESET_ON()   { _Set0_(_I2C_EXPENDER01_RESET); _SetOUT_(_I2C_EXPENDER01_RESET);  }     // pin to 0 , pin to out
#define _I2C_EXPANDER01_RESET_OFF()  { _Set1_(_I2C_EXPENDER01_RESET); _SetOUT_(_I2C_EXPENDER01_RESET);  }     // pin to 1 , pin to out

//void _i2c_expander01_reset_on(void);
//void _i2c_expander01_reset_off(void);


#define _I2C_EXPANDER_START         _I2C01_START
#define _I2C_EXPANDER_STOP          _I2C01_STOP
#define _I2C_EXPANDER_SDA_to1       _I2C01_SDA_TO_1
#define _I2C_EXPANDER_SDA_to0       _I2C01_SDA_TO_0
#define _I2C_EXPANDER_SCL_to1       _I2C01_CLK_TO_1
#define _I2C_EXPANDER_SCL_to0       _I2C01_CLK_TO_0
#define _I2C_EXPANDER_SDA_read(aaa) _I2C01_SDA_read(aaa)

uint8_t _i2c_expander01_check_sda1(void);
uint8_t _i2c_expander01_r1w0_6(uint8_t ___r1w0, uint8_t ___i2cIdx, uint8_t ___r6[]);

uint8_t _i2c_expander01_testLoopMainW(void);
uint8_t _i2c_expander01_testLoopMainR(void);

//uint8_t _i2c_expander01_read6(uint8_t ___i2cIdx, uint8_t ___r6[]);
//uint8_t _i2c_expander01_write6(uint8_t ___i2cIdx, uint8_t ___r6[]);
#define _i2c_expander01_write6(bb,cc) _i2c_expander01_r1w0_6( 0, bb , cc )
#define _i2c_expander01_read6( bb,cc) _i2c_expander01_r1w0_6( 1, bb , cc )


#endif 
