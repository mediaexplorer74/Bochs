/////////////////////////////////////////////////////////////////////////
// $Id: fpu_cmov.cc 14160 2021-02-21 09:25:33Z vruppert $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs/bochs.h"
#include "../cpu/cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#if BX_SUPPORT_FPU

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVB_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (get_CF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVBE_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (get_CF() || get_ZF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVE_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (get_ZF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVNB_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (! get_CF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVNBE_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (! get_CF() && ! get_ZF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVNE_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (! get_ZF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVNU_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (! get_PF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FCMOVU_ST0_STj(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  if (IS_TAG_EMPTY(0) || IS_TAG_EMPTY(i->src())) {
     FPU_stack_underflow(i, 0);
  }
  else {
     if (get_PF())
        BX_WRITE_FPU_REG(BX_READ_FPU_REG(i->src()), 0);
  }

  BX_NEXT_INSTR(i);
}

#endif
