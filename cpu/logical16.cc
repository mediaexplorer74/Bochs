/////////////////////////////////////////////////////////////////////////
// $Id: logical16.cc 13573 2019-10-14 14:54:07Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs/bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

void BX_CPP_AttrRegparmN(1) BX_CPU_C::ZERO_IDIOM_GwR(bxInstruction_c *i)
{
  BX_WRITE_16BIT_REG(i->dst(), 0);
  SET_FLAGS_OSZAPC_LOGIC_16(0);
  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_EwGwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 ^= op2_16;
  write_RMW_linear_word(op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_GwEwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 ^= op2_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_GwEwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = read_virtual_word(i->seg(), eaddr);
  op1_16 ^= op2_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_EwIwM(bxInstruction_c *i)
{
  Bit16u op1_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op1_16 ^= i->Iw();
  write_RMW_linear_word(op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::XOR_EwIwR(bxInstruction_c *i)
{
  Bit16u op1_16 = BX_READ_16BIT_REG(i->dst());
  op1_16 ^= i->Iw();
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_EwIwM(bxInstruction_c *i)
{
  Bit16u op1_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op1_16 |= i->Iw();
  write_RMW_linear_word(op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_EwIwR(bxInstruction_c *i)
{
  Bit16u op1_16 = BX_READ_16BIT_REG(i->dst());
  op1_16 |= i->Iw();
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::NOT_EwM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit16u op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op1_16 = ~op1_16;
  write_RMW_linear_word(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::NOT_EwR(bxInstruction_c *i)
{
  Bit16u op1_16 = BX_READ_16BIT_REG(i->dst());
  op1_16 = ~op1_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_EwGwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 |= op2_16;
  write_RMW_linear_word(op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_GwEwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 |= op2_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::OR_GwEwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = read_virtual_word(i->seg(), eaddr);
  op1_16 |= op2_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_EwGwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 &= op2_16;
  write_RMW_linear_word(op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_GwEwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 &= op2_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_GwEwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = read_virtual_word(i->seg(), eaddr);
  op1_16 &= op2_16;
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_EwIwM(bxInstruction_c *i)
{
  Bit16u op1_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  op1_16 &= i->Iw();
  write_RMW_linear_word(op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::AND_EwIwR(bxInstruction_c *i)
{
  Bit16u op1_16 = BX_READ_16BIT_REG(i->dst());
  op1_16 &= i->Iw();
  BX_WRITE_16BIT_REG(i->dst(), op1_16);

  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EwGwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->dst());
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 &= op2_16;
  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EwGwM(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  op1_16 = read_virtual_word(i->seg(), eaddr);
  op2_16 = BX_READ_16BIT_REG(i->src());
  op1_16 &= op2_16;
  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EwIwR(bxInstruction_c *i)
{
  Bit16u op1_16 = BX_READ_16BIT_REG(i->dst());
  op1_16 &= i->Iw();
  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::TEST_EwIwM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_RESOLVE_ADDR(i);

  Bit16u op1_16 = read_virtual_word(i->seg(), eaddr);
  op1_16 &= i->Iw();
  SET_FLAGS_OSZAPC_LOGIC_16(op1_16);

  BX_NEXT_INSTR(i);
}
