//#include <driverlib.h>
#include "_include_all.h"

void _delay_1ms(void){
    volatile uint32_t i;

    for(i=53; i>0; i--);
}

void _delay_10ms(void){
    volatile uint32_t i;

    for(i=579; i>0; i--);
}

void _delay_100ms(void){
    volatile uint32_t i;

    for(i=5810; i>0; i--);
}
