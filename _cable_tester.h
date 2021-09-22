/*
 * _cable_tester.h
 *
 *  Created on: Sep 20, 2021
 *      Author: james
 */

#ifndef CABLE_TESTER_H_
#define CABLE_TESTER_H_

#include "_include_all.h"

uint8_t _cable_tester_mainloop_once(void);

#define _CB_PR_str(aaa)                     { _uart_p1_5_tx_only_put_str(aaa); }
#define _CB_PR_str_rn(aaa)                  { _uart_p1_5_tx_only_put_str(aaa "\r\n"); }
#define _CB_PR_uint32(aaa)                  { _uart_p1_5_tx_only_put_uint32(aaa); }
#define _CB_PR_uint8(aaa)                   { _uart_p1_5_tx_only_put_hex(aaa); }
#define _uart_p1_5_tx_only_put_hex_u8X(aaa) { _uart_p1_5_tx_only_put_ch(' '); _uart_p1_5_tx_only_put_hex_u8(aaa); _uart_p1_5_tx_only_put_ch(' '); }
#define _CB_PR_rn()                         { _uart_p1_5_tx_only_put_rn(); }
#define _CB_PR_6hex(str1,idx2,hexS3)        { _uart_p1_5_tx_only_put_str(str1); _uart_p1_5_tx_only_put_hex(idx2);_uart_p1_5_tx_only_put_ch(',');_uart_p1_5_tx_only_put_hexS(6,hexS3);  }
#define _CB_PR_6hex_rn(str1,idx2,hexS3)     { _CB_PR_6hex(str1,idx2,hexS3);  _uart_p1_5_tx_only_put_rn();  }
#define _CB_PR_12hex(str1,idx2,hexS3)       { _uart_p1_5_tx_only_put_str(str1); _uart_p1_5_tx_only_put_hex(idx2);_uart_p1_5_tx_only_put_ch(',');_uart_p1_5_tx_only_put_hexS(12,hexS3); }
#define _CB_PR_12hex_rn(str1,idx2,hexS3)    { _CB_PR_12hex(str1,idx2,hexS3) ; _uart_p1_5_tx_only_put_rn(); }
#define _CB_PR_1hex(str1,str2,idx3)         { _uart_p1_5_tx_only_put_str(str1);_uart_p1_5_tx_only_put_str("0x"); _uart_p1_5_tx_only_put_hex(idx3); _uart_p1_5_tx_only_put_str(str2); }
#define _CB_PR_1hex_u8(str1,str2,idx3)      { _uart_p1_5_tx_only_put_str(str1);_uart_p1_5_tx_only_put_str("0x"); _uart_p1_5_tx_only_put_hex_u8(idx3); _uart_p1_5_tx_only_put_str(str2); }
#define _CB_PR_1hex_u8_rn(str1,str2,idx3)   { _CB_PR_1hex_u8(str1,str2 "\r\n",idx3); }
#define _CB_PR_1hex_rn(str1,str2,idx3)      { _CB_PR_1hex(str1,str2 "\r\n",idx3); }
#define _CB_err_return(aa)                  { _CB_PR_1hex_u8_rn("Error found. error number: 0x", " Exit.", aa) ; return aa ;}
#define _CB_err_return3(aa,bb,rt)           { _CB_PR_1hex_u8_rn(aa,bb,rt) ; return rt ;}

#endif /* CABLE_TESTER_H_ */
