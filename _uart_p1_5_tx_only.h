/*
 * _uart_p1_5_tx_only.h
 *
 *  Created on: Sep 16, 2021
 *      Author: james
 */

#ifndef UART_P1_5_TX_ONLY_H_
#define UART_P1_5_TX_ONLY_H_

#include "_include_all.h"

#define _UART_P1_5_TX_PUT_CH(ch) {while(!(UCA0IFG & UCTXIFG));UCA0TXBUF = ch;__delay_cycles(84);}

void _uart_p1_5_tx_only_init(void);
void _uart_p1_5_tx_only_testloop(void);

void _uart_p1_5_tx_only_put_ch(uint8_t ___hexbyte);
void _uart_p1_5_tx_only_put_str(uint8_t ___hexbyte[]);
void _uart_p1_5_tx_only_put_rn(void);
void _uart_p1_5_tx_only_put_uint32(uint32_t ___uuu);
void _uart_p1_5_tx_only_put_hex_half(uint8_t ___hexbyte);
void _uart_p1_5_tx_only_put_hex(uint8_t ___hexbyte);
void _uart_p1_5_tx_only_put_hex_u8(uint8_t ___hexbyte);
void _uart_p1_5_tx_only_put_u8(uint8_t ___hexbyte);
void _uart_p1_5_tx_only_put_hexS(uint8_t ___cnt , uint8_t ___hexbyte[]);

#endif /* UART_P1_5_TX_ONLY_H_ */
