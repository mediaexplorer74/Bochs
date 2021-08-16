/////////////////////////////////////////////////////////////////////////
// $Id: bit.cc 13466 2018-02-16 07:57:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs_old/bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#if BX_CPU_LEVEL >= 3

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETO_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = getB_OF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETO_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), getB_OF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNO_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !getB_OF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNO_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !getB_OF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETB_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = getB_CF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETB_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), getB_CF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNB_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !getB_CF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNB_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !getB_CF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETZ_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = getB_ZF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETZ_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), getB_ZF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNZ_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !getB_ZF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNZ_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !getB_ZF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETBE_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = (getB_CF() | getB_ZF());
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETBE_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), (getB_CF() | getB_ZF()));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNBE_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !(getB_CF() | getB_ZF());
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNBE_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !(getB_CF() | getB_ZF()));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETS_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = getB_SF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETS_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), getB_SF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNS_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !getB_SF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNS_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !getB_SF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETP_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = getB_PF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETP_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), getB_PF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNP_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !getB_PF();
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNP_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !getB_PF());

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETL_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = (getB_SF() ^ getB_OF());
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETL_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), (getB_SF() ^ getB_OF()));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNL_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !(getB_SF() ^ getB_OF());
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNL_EbR(bxInstruction_c *i)
{
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), !(getB_SF() ^ getB_OF()));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETLE_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = getB_ZF() | (getB_SF() ^ getB_OF());
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETLE_EbR(bxInstruction_c *i)
{
  Bit8u result_8 = getB_ZF() | (getB_SF() ^ getB_OF());
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNLE_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u result_8 = !(getB_ZF() | (getB_SF() ^ getB_OF()));
  write_virtual_byte(i->seg(), eaddr, result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::SETNLE_EbR(bxInstruction_c *i)
{
  Bit8u result_8 = !(getB_ZF() | (getB_SF() ^ getB_OF()));
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), result_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BSWAP_RX(bxInstruction_c *i)
{
  BX_ERROR(("BSWAP with 16-bit opsize: undefined behavior !"));
  BX_WRITE_16BIT_REG(i->dst(), 0);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BSWAP_ERX(bxInstruction_c *i)
{
  Bit32u val32 = BX_READ_32BIT_REG(i->dst());

  BX_WRITE_32BIT_REGZ(i->dst(), bx_bswap32(val32));

  BX_NEXT_INSTR(i);
}

#if BX_SUPPORT_X86_64
void BX_CPP_AttrRegparmN(1) BX_CPU_C::BSWAP_RRX(bxInstruction_c *i)
{
  Bit64u val64 = BX_READ_64BIT_REG(i->dst());

  BX_WRITE_64BIT_REG(i->dst(), bx_bswap64(val64));

  BX_NEXT_INSTR(i);
}
#endif

#if BX_CPU_LEVEL >= 6

void BX_CPP_AttrRegparmN(1) BX_CPU_C::MOVBE_GwMw(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);
  Bit16u val16 = read_virtual_word(i->seg(), eaddr);
  BX_WRITE_16BIT_REG(i->dst(), bx_bswap16(val16));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::MOVBE_MwGw(bxInstruction_c *i)
{
  Bit16u val16 = BX_READ_16BIT_REG(i->src());
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);
  write_virtual_word(i->seg(), eaddr, bx_bswap16(val16));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::MOVBE_GdMd(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);
  Bit32u val32 = read_virtual_dword(i->seg(), eaddr);
  BX_WRITE_32BIT_REGZ(i->dst(), bx_bswap32(val32));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::MOVBE_MdGd(bxInstruction_c *i)
{
  Bit32u val32 = BX_READ_32BIT_REG(i->src());
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);
  write_virtual_dword(i->seg(), eaddr, bx_bswap32(val32));

  BX_NEXT_INSTR(i);
}

#if BX_SUPPORT_X86_64

void BX_CPP_AttrRegparmN(1) BX_CPU_C::MOVBE_GqMq(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR_64(i);
  Bit64u val64 = read_linear_qword(i->seg(), get_laddr64(i->seg(), eaddr));
  BX_WRITE_64BIT_REG(i->dst(), bx_bswap64(val64));

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::MOVBE_MqGq(bxInstruction_c *i)
{
  Bit64u val64 = BX_READ_64BIT_REG(i->src());
  bx_address eaddr = BX_CPU_RESOLVE_ADDR_64(i);
  write_linear_qword(i->seg(), get_laddr64(i->seg(), eaddr), bx_bswap64(val64));

  BX_NEXT_INSTR(i);
}

#endif // BX_SUPPORT_X86_64

#endif // BX_CPU_LEVEL >= 6

#endif // BX_CPU_LEVEL >= 3
