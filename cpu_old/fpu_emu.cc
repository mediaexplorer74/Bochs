/////////////////////////////////////////////////////////////////////////
// $Id: fpu_emu.cc 13466 2018-02-16 07:57:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs_old/bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

/* 9B */
void BX_CPP_AttrRegparmN(1) BX_CPU_C::FWAIT(bxInstruction_c *i)
{
#if BX_SUPPORT_FPU
  if (BX_CPU_THIS_PTR cr0.get_TS() && BX_CPU_THIS_PTR cr0.get_MP())
    exception(BX_NM_EXCEPTION, 0);

  BX_CPU_THIS_PTR FPU_check_pending_exceptions();

  BX_NEXT_INSTR(i);
#endif
}

/* relevant only when FPU support is disabled */
#if BX_SUPPORT_FPU == 0
void BX_CPP_AttrRegparmN(1) BX_CPU_C::FPU_ESC(bxInstruction_c *i)
{
  if (BX_CPU_THIS_PTR cr0.get_EM() || BX_CPU_THIS_PTR cr0.get_TS())
    exception(BX_NM_EXCEPTION, 0);

  BX_NEXT_INSTR(i);
}
#endif
