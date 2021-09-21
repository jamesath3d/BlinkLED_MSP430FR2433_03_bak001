/*
 * _uart_p1_5_tx_only_init.c
 *
 *  Created on: Sep 16, 2021
 *      Author: james
    // P1.4 -> uartTX
    // P1.5 -> uartRX
 */

#include "_uart_p1_5_tx_only.h"

void _uart_p1_5_tx_only_init(void){

    // Configure UART pins
        P1SEL0 |= BIT4;                           // set UART TX pin as second function

        // Configure UART
        UCA0CTLW0 |= UCSWRST;                     // Put eUSCI in reset
        UCA0CTLW0 |= UCSSEL__SMCLK;
        UCA0CTL0 |= BIT3 ;                        // UCSPB ; // set 8n2 (2 stop bits)
        // Baud Rate calculation
        UCA0BR0 = 8;                              // 1000000/115200 = 8.68
        UCA0MCTLW = 0xD600;                       // 1000000/115200 - INT(1000000/115200)=0.68
                                                  // UCBRSx value = 0xD6 (See UG)

        UCA0BR1 = 0;

        UCA0CTLW0 &= ~UCSWRST;                    // Initialize eUSCI

        //UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
}
