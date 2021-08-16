/////////////////////////////////////////////////////////////////////////
// $Id: wide_int.h 13853 2020-05-19 16:01:23Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_WIDE_INT_H
#define BX_WIDE_INT_H

#include "../bochs_old/config.h"

#ifdef BX_LITTLE_ENDIAN
typedef
  struct {
    Bit64u lo;
    Bit64u hi;
  } Bit128u;
typedef
  struct {
    Bit64u lo;
    Bit64s hi;
  } Bit128s;
#else   // must be Big Endian
typedef
  struct {
    Bit64u hi;
    Bit64u lo;
  } Bit128u;
typedef
  struct {
    Bit64s hi;
    Bit64u lo;
  } Bit128s;
#endif

extern void long_mul(Bit128u *product, Bit64u op1, Bit64u op2);
extern void long_imul(Bit128s *product, Bit64s op1, Bit64s op2);
extern void long_div(Bit128u *quotient,Bit64u *remainder,const Bit128u *dividend,Bit64u divisor);
extern void long_idiv(Bit128s *quotient,Bit64s *remainder,Bit128s *dividend,Bit64s divisor);
                                                               
#endif
