//#include <driverlib.h>
#include "_include_all.h"

void _delay_1ms(void){
    __delay_cycles(1000);
}

void _delay_10ms(void){
    __delay_cycles(10000);
}

void _delay_100ms(void){
    __delay_cycles(100000);
}
