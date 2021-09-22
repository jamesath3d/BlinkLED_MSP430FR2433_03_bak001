
#include "_include_all.h"



int main(void) {

    //volatile uint32_t i;
    //volatile uint32_t j;
    uint8_t i,j;
    uint8_t __rt ;

    // "_led_all.h"
    main_init();


    //_uart_p1_5_tx_only_testloop();

    __delay_cycles(1000000);

    while(1)
    {
        _led_red_toggle();
        //_LED_red_on();
        //_LED_red_off();

        _cable_tester_mainloop_once();

        for ( j= 248 ; j>0 ; j--) {
            _led_green_toggle();
            for ( i=165 ; i>0 ; i--) {
                _delay_1ms();
            }
        }
        //_i2c_expander01_testLoopMainR();
        //_i2c_expander01_testLoopMainW();

    }
}

