
#include "_include_all.h"



int main(void) {

    //volatile uint32_t i;
    //volatile uint32_t j;
    uint8_t __ii ;
    uint8_t __jj ;
    uint8_t __rt ;

    // "_led_all.h"
    main_init();


    //_uart_p1_5_tx_only_testloop();

    __delay_cycles(1000000);

    while(1)
    {
        //_led_red_toggle();

        _LED_red_on();
        _LED_green_on();
        __rt = _cable_tester_mainloop_once();
        __delay_cycles(1000000);

        _CB_PR_1hex_u8_rn(" cable tester return code is : " , " <<==== 0 --> all ok ; others -> failed. \r\n", __rt);

        if ( __rt ) {
            _LED_red_on(); // turn on red --> error
        } else {
            _LED_red_off();
        }

        __rt = 10 ; // flash 10 time.

        for ( __ii= __rt ; __ii>0 ; __ii--) {
            __jj ++ ;
            if ( __jj & 1 ) {
                _LED_green_on();
            } else {
                _LED_green_off();
            }
            __delay_cycles(500000);
        }
        //_i2c_expander01_testLoopMainR();
        //_i2c_expander01_testLoopMainW();
    }
}

