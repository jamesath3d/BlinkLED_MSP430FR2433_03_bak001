#include "_include_all.h"

void _led_red_set_output(void){
    // Set P1.0 to output direction

    GPIO_setAsOutputPin(
        GPIO_PORT_P1, // LED red : P1.6
        GPIO_PIN6
        );

}
