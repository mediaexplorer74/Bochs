/////////////////////////////////////////////////////////////////////////
// $Id: avx512_bitalg.cc 13466 2018-02-16 07:57:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#define NEED_CPU_REG_SHORTCUTS 1
#include "pch.h"
#include "../bochs/bochs.h"
#include "../cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

// AVX-512 conflict detection instructions

#if BX_SUPPORT_EVEX

#include "simd_int.h"
#include "scalar_arith.h"

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPCONFLICTD_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < DWORD_ELEMENTS(len); n++) {
    op.vmm32u(n) = simd_pconflictd(&op, n);
  }

  if (i->opmask()) {
    avx512_write_regd_masked(i, &op, len, BX_READ_16BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPCONFLICTQ_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < QWORD_ELEMENTS(len); n++) {
    op.vmm64u(n) = simd_pconflictq(&op, n);
  }

  if (i->opmask()) {
    avx512_write_regq_masked(i, &op, len, BX_READ_8BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPBROADCASTMB2Q_VdqKEbR(bxInstruction_c *i)
{
  simd_pbroadcastq(&BX_AVX_REG(i->dst()), (Bit64u) BX_READ_8BIT_OPMASK(i->src()), QWORD_ELEMENTS(i->getVL()));
  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPBROADCASTMW2D_VdqKEwR(bxInstruction_c *i)
{
  simd_pbroadcastd(&BX_AVX_REG(i->dst()), (Bit32u) BX_READ_16BIT_OPMASK(i->src()), DWORD_ELEMENTS(i->getVL()));
  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPLZCNTD_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < DWORD_ELEMENTS(len); n++)
    op.vmm32u(n) = lzcntd(op.vmm32u(n));

  if (i->opmask()) {
    avx512_write_regd_masked(i, &op, len, BX_READ_16BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPLZCNTQ_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < QWORD_ELEMENTS(len); n++)
    op.vmm64u(n) = lzcntq(op.vmm64u(n));

  if (i->opmask()) {
    avx512_write_regq_masked(i, &op, len, BX_READ_8BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPOPCNTB_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < BYTE_ELEMENTS(len); n++)
    op.vmmubyte(n) = popcntb(op.vmmubyte(n));

  if (i->opmask()) {
    avx512_write_regb_masked(i, &op, len, BX_READ_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPOPCNTW_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < WORD_ELEMENTS(len); n++)
    op.vmm16u(n) = popcntw(op.vmm16u(n));

  if (i->opmask()) {
    avx512_write_regw_masked(i, &op, len, BX_READ_32BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPOPCNTD_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < DWORD_ELEMENTS(len); n++)
    op.vmm32u(n) = popcntd(op.vmm32u(n));

  if (i->opmask()) {
    avx512_write_regd_masked(i, &op, len, BX_READ_16BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPOPCNTQ_MASK_VdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op = BX_READ_AVX_REG(i->src());
  unsigned len = i->getVL();

  for (unsigned n=0; n < QWORD_ELEMENTS(len); n++)
    op.vmm64u(n) = popcntq(op.vmm64u(n));

  if (i->opmask()) {
    avx512_write_regq_masked(i, &op, len, BX_READ_8BIT_OPMASK(i->opmask()));
  }
  else {
    BX_WRITE_AVX_REGZ(i->dst(), op, len);
  }
  
  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::VPSHUFBITQMB_MASK_KGqHdqWdqR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->src1()), op2 = BX_READ_AVX_REG(i->src2());
  unsigned len = i->getVL();

  Bit64u result = 0;

  for (unsigned n=QWORD_ELEMENTS(len)-1;; n--) {
    Bit64u src = op1.vmm64u(n), ctrl = op2.vmm64u(n);

    Bit32u tmp = 0;
    for (unsigned i=0; i < 7; i++) {
      tmp |= Bit32u((src >> (ctrl & 0x3F)) & 0x1) << i;
      ctrl >>= 8;
    }

    result |= tmp;
    if (n == 0) break;
    result <<= 8;
  }

  if (i->opmask())
    result &= BX_READ_OPMASK(i->opmask());

  BX_WRITE_OPMASK(i->dst(), result);
  BX_NEXT_INSTR(i);
}

#endif
