//#include <driverlib.h>
#include "_include_all.h"

void _delay_1s(void){
    volatile uint32_t i;

    for(i=30000; i>0; i--);
}

void _delay_10s(void){
    volatile uint32_t i;

    for(i=9; i>0; i--){
        _delay_1s();
    }
}

void _delay_100s(void){
    volatile uint32_t i;

    for(i=99; i>0; i--){
        _delay_1s();
    }
}
