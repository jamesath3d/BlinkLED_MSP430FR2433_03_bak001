//#include <driverlib.h>
#include "_include_all.h"

void _delay_5us(void){
    //for(i=0; i>0; i--);
}

void _delay_100us(void){
    __delay_cycles(95);
}
