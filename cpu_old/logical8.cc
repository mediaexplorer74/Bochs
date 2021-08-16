/////////////////////////////////////////////////////////////////////////
// $Id: logical8.cc 13466 2018-02-16 07:57:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs_old/bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_EbGbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_RMW_virtual_byte(i->seg(), eaddr);
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 ^= op2;
  write_RMW_linear_byte(op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_GbEbR(bxInstruction_c *i)
{
  Bit8u op1, op2;

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 ^= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_GbEbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = read_virtual_byte(i->seg(), eaddr);
  op1 ^= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_EbIbM(bxInstruction_c *i)
{
  Bit8u op1, op2 = i->Ib();

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_RMW_virtual_byte(i->seg(), eaddr);
  op1 ^= op2;
  write_RMW_linear_byte(op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_EbIbR(bxInstruction_c *i)
{
  Bit8u op1, op2 = i->Ib();

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op1 ^= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_EbIbM(bxInstruction_c *i)
{
  Bit8u op1, op2 = i->Ib();

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_RMW_virtual_byte(i->seg(), eaddr);
  op1 |= op2;
  write_RMW_linear_byte(op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_EbIbR(bxInstruction_c *i)
{
  Bit8u op1, op2 = i->Ib();

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op1 |= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::NOT_EbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u op1_8 = read_RMW_virtual_byte(i->seg(), eaddr);
  op1_8 = ~op1_8;
  write_RMW_linear_byte(op1_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::NOT_EbR(bxInstruction_c *i)
{
  Bit8u op1_8 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op1_8 = ~op1_8;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1_8);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_EbGbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_RMW_virtual_byte(i->seg(), eaddr);
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 |= op2;
  write_RMW_linear_byte(op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_GbEbR(bxInstruction_c *i)
{
  Bit8u op1, op2;

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 |= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_GbEbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = read_virtual_byte(i->seg(), eaddr);
  op1 |= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_EbGbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_RMW_virtual_byte(i->seg(), eaddr);
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 &= op2;
  write_RMW_linear_byte(op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_GbEbR(bxInstruction_c *i)
{
  Bit8u op1, op2;

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 &= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_GbEbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = read_virtual_byte(i->seg(), eaddr);
  op1 &= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_EbIbM(bxInstruction_c *i)
{
  Bit8u op1, op2 = i->Ib();

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_RMW_virtual_byte(i->seg(), eaddr);
  op1 &= op2;
  write_RMW_linear_byte(op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_EbIbR(bxInstruction_c *i)
{
  Bit8u op1, op2 = i->Ib();

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op1 &= op2;
  BX_WRITE_8BIT_REGx(i->dst(), i->extend8bitL(), op1);

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EbGbR(bxInstruction_c *i)
{
  Bit8u op1, op2;

  op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 &= op2;

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EbGbM(bxInstruction_c *i)
{
  Bit8u op1, op2;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1 = read_virtual_byte(i->seg(), eaddr);
  op2 = BX_READ_8BIT_REGx(i->src(), i->extend8bitL());
  op1 &= op2;

  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EbIbR(bxInstruction_c *i)
{
  Bit8u op1 = BX_READ_8BIT_REGx(i->dst(), i->extend8bitL());
  op1 &= i->Ib();
  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EbIbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit8u op1 = read_virtual_byte(i->seg(), eaddr);
  op1 &= i->Ib();
  SET_FLAGS_OSZAPC_LOGIC_8(op1);

  BX_NEXT_INSTR(i);
}
