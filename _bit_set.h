
#ifndef BIT_SET_H_
#define BIT_SET_H_

#include "_include_all.h"
#define _CONCAT3(A,B,C)   A##B##C
#define _CONCAT2(A,B)     A##B

#define _Pdir_(ddd)   _CONCAT3(P,ddd,DIR)
#define _PdirT(pdpd)  _Pdir_(pdpd##_PORT_)

#define _Pout_(ddd)   _CONCAT3(P,ddd,OUT)
#define _PoutT(popo)  _Pout_(popo##_PORT_)

#define _Pin_(ddd)   _CONCAT3(P,ddd,IN)
#define _PinT(pipi)  _Pin_(pipi##_PORT_)

#define _Bbit_(bb)  _CONCAT2(BIT,bb)
#define _BbitT(bt)  _Bbit_(bt##_PIN_)

#define _SetIN(name)  { name##_dir &= ( ~ name##_bit ) ; }
#define _SetOUT(name) { name##_dir |=     name##_bit   ; }
#define _Set0(name)   { name##_out &= ( ~ name##_bit ) ; }
#define _Set1(name)   { name##_out |=     name##_bit   ; }

#define _SetIN_(name)  { _PdirT(name) &= ( ~ _BbitT(name) ) ; }
#define _SetOUT_(name) { _PdirT(name) |=     _BbitT(name)   ; }

#define _Set0_(name)   { _PoutT(name) &= ( ~ _BbitT(name) ) ; }
#define _Set1_(name)   { _PoutT(name) |=     _BbitT(name)   ; }

#define _READbit_(name) (_PinT(name) & _BbitT(name))

uint8_t _bit_count(uint8_t ___byte);
uint8_t _bit_set(uint8_t ___byte);
void _byte_set(uint8_t ___cnt, uint8_t ___arr[] , uint8_t ___byte);
uint8_t _byte_cmp(uint8_t ___cnt, uint8_t ___arr1[], uint8_t ___arr2[]);

void _bit_and(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] );
void _bit_or(uint8_t  ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] );
void _bit_xor(uint8_t ___cnt, uint8_t ___A[], uint8_t ___B[], uint8_t ___O[] );
void _bit_inv(uint8_t ___cnt, uint8_t ___A[], uint8_t ___O[] );

#endif
