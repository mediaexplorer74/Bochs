/////////////////////////////////////////////////////////////////////////
// $Id: avx512_mask16.cc 13466 2018-02-16 07:57:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#define NEED_CPU_REG_SHORTCUTS 1
#include "pch.h"
#include "../bochs/bochs.h"
#include "../cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#if BX_SUPPORT_AVX

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KADDW_KGwKHwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = BX_READ_16BIT_OPMASK(i->src1()) + BX_READ_16BIT_OPMASK(i->src2());
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KANDW_KGwKHwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = BX_READ_16BIT_OPMASK(i->src1()) & BX_READ_16BIT_OPMASK(i->src2());
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KANDNW_KGwKHwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = ~(BX_READ_16BIT_OPMASK(i->src1())) & BX_READ_16BIT_OPMASK(i->src2());
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KMOVW_KGwKEwM(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);
  Bit16u opmask = read_virtual_word(i->seg(), eaddr);
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KMOVW_KGwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  BX_WRITE_OPMASK(i->dst(), BX_READ_16BIT_OPMASK(i->src()));
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KMOVW_KEwKGwM(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);
  write_virtual_word(i->seg(), eaddr, BX_READ_16BIT_OPMASK(i->src()));
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KMOVW_KGwEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  BX_WRITE_OPMASK(i->dst(), BX_READ_16BIT_REG(i->src()));
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KMOVW_GdKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  BX_WRITE_32BIT_REGZ(i->dst(), BX_READ_16BIT_OPMASK(i->src()));
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KUNPCKBW_KGwKHbKEbR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = BX_READ_8BIT_OPMASK(i->src1());
         opmask = (opmask << 8) | BX_READ_8BIT_OPMASK(i->src2());

  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KNOTW_KGwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = ~BX_READ_16BIT_OPMASK(i->src());
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KORW_KGwKHwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = BX_READ_16BIT_OPMASK(i->src1()) | BX_READ_16BIT_OPMASK(i->src2());
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KORTESTW_KGwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u tmp = BX_READ_16BIT_OPMASK(i->src1()) | BX_READ_16BIT_OPMASK(i->src2());
  clearEFlagsOSZAPC();
  if (tmp == 0)
    assert_ZF();
  else if (tmp == 0xffff)
    assert_CF();
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KSHIFTLW_KGwKEwIbR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  unsigned count = i->Ib();
  Bit16u opmask = 0;
  if (count < 15)
    opmask = BX_READ_16BIT_OPMASK(i->src()) << count;

  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KSHIFTRW_KGwKEwIbR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  unsigned count = i->Ib();
  Bit16u opmask = 0;
  if (count < 15)
    opmask = BX_READ_16BIT_OPMASK(i->src()) >> count;

  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KXNORW_KGwKHwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = ~(BX_READ_16BIT_OPMASK(i->src1()) ^ BX_READ_16BIT_OPMASK(i->src2()));
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KXORW_KGwKHwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u opmask = BX_READ_16BIT_OPMASK(i->src1()) ^ BX_READ_16BIT_OPMASK(i->src2());
  BX_WRITE_OPMASK(i->dst(), opmask);
#endif

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::KTESTW_KGwKEwR(bxInstruction_c *i)
{
#if BX_SUPPORT_EVEX
  Bit16u op1 = BX_READ_16BIT_OPMASK(i->src1()), op2 = BX_READ_16BIT_OPMASK(i->src2());
  clearEFlagsOSZAPC();
  if ((op1 & op2) == 0)
    assert_ZF();
  if ((~op1 & op2) == 0)
    assert_CF();
#endif

  BX_NEXT_INSTR(i);
}

#endif
