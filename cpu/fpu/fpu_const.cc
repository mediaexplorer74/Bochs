/////////////////////////////////////////////////////////////////////////
// $Id: fpu_const.cc 13466 2018-02-16 07:57:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs/bochs.h"
#include "../cpu/cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#if BX_SUPPORT_FPU

#include "softfloatx80.h"

const floatx80 Const_QNaN = packFloatx80(0, floatx80_default_nan_exp, floatx80_default_nan_fraction);
const floatx80 Const_Z    = packFloatx80(0, 0x0000, 0);
const floatx80 Const_1    = packFloatx80(0, 0x3fff, BX_CONST64(0x8000000000000000));
const floatx80 Const_L2T  = packFloatx80(0, 0x4000, BX_CONST64(0xd49a784bcd1b8afe));
const floatx80 Const_L2E  = packFloatx80(0, 0x3fff, BX_CONST64(0xb8aa3b295c17f0bc));
const floatx80 Const_PI   = packFloatx80(0, 0x4000, BX_CONST64(0xc90fdaa22168c235));
const floatx80 Const_LG2  = packFloatx80(0, 0x3ffd, BX_CONST64(0x9a209a84fbcff799));
const floatx80 Const_LN2  = packFloatx80(0, 0x3ffe, BX_CONST64(0xb17217f7d1cf79ac));
const floatx80 Const_INF  = packFloatx80(0, 0x7fff, BX_CONST64(0x8000000000000000));

/* A fast way to find out whether x is one of RC_DOWN or RC_CHOP
   (and not one of RC_RND or RC_UP).
   */
#define DOWN_OR_CHOP()  (FPU_CONTROL_WORD & FPU_CW_RC & FPU_RC_DOWN)

BX_CPP_INLINE floatx80 FPU_round_const(const floatx80 &a, int adj)
{
  floatx80 result = a;
  result.fraction += adj;
  return result;
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLDL2T(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(FPU_round_const(Const_L2T, (FPU_CONTROL_WORD & FPU_CW_RC) == FPU_RC_UP), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLDL2E(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(FPU_round_const(Const_L2E, DOWN_OR_CHOP() ? -1 : 0), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLDPI(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(FPU_round_const(Const_PI, DOWN_OR_CHOP() ? -1 : 0), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLDLG2(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(FPU_round_const(Const_LG2, DOWN_OR_CHOP() ? -1 : 0), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLDLN2(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(FPU_round_const(Const_LN2, DOWN_OR_CHOP() ? -1 : 0), 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLD1(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(Const_1, 0);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::FLDZ(bxInstruction_c *i)
{
  BX_CPU_THIS_PTR prepareFPU(i);
  BX_CPU_THIS_PTR FPU_update_last_instruction(i);

  clear_C1();

  if (! IS_TAG_EMPTY(-1))
  {
    FPU_stack_overflow(i);
  }
  else {
    BX_CPU_THIS_PTR the_i387.FPU_push();
    BX_WRITE_FPU_REG(Const_Z, 0);
  }

  BX_NEXT_INSTR(i);
}

#endif
