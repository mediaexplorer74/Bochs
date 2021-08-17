/////////////////////////////////////////////////////////////////////////
// $Id: rdrand.cc 14300 2021-07-03 14:31:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#include "pch.h"

#define NEED_CPU_REG_SHORTCUTS 1
#include "../bochs/bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#include <stdlib.h>

#define HW_RANDOM_GENERATOR_READY (1)

void BX_CPP_AttrRegparmN(1) BX_CPU_C::RDRAND_Ew(bxInstruction_c *i)
{
#if BX_SUPPORT_VMX
  if (BX_CPU_THIS_PTR in_vmx_guest) {
    if (SECONDARY_VMEXEC_CONTROL(VMX_VM_EXEC_CTRL3_RDRAND_VMEXIT)) {
      VMexit_Instruction(i, VMX_VMEXIT_RDRAND, BX_READ);
    }
  }
#endif

  Bit16u val_16 = 0;

  clearEFlagsOSZAPC();

  if (HW_RANDOM_GENERATOR_READY) {
    val_16 |= rand() & 0xff;  // hack using std C rand() function
    val_16 <<= 8;
    val_16 |= rand() & 0xff;

    assert_CF();
  }

  BX_WRITE_16BIT_REG(i->dst(), val_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::RDRAND_Ed(bxInstruction_c *i)
{
#if BX_SUPPORT_VMX
  if (BX_CPU_THIS_PTR in_vmx_guest) {
    if (SECONDARY_VMEXEC_CONTROL(VMX_VM_EXEC_CTRL3_RDRAND_VMEXIT)) {
      VMexit_Instruction(i, VMX_VMEXIT_RDRAND, BX_READ);
    }
  }
#endif

  Bit32u val_32 = 0;

  clearEFlagsOSZAPC();

  if (HW_RANDOM_GENERATOR_READY) {
    val_32 |= rand() & 0xff;  // hack using std C rand() function
    val_32 <<= 8;
    val_32 |= rand() & 0xff;
    val_32 <<= 8;
    val_32 |= rand() & 0xff;
    val_32 <<= 8;
    val_32 |= rand() & 0xff;

    assert_CF();
  }

  BX_WRITE_32BIT_REGZ(i->dst(), val_32);

  BX_NEXT_INSTR(i);
}

#if BX_SUPPORT_X86_64
void BX_CPP_AttrRegparmN(1) BX_CPU_C::RDRAND_Eq(bxInstruction_c *i)
{
#if BX_SUPPORT_VMX
  if (BX_CPU_THIS_PTR in_vmx_guest) {
    if (SECONDARY_VMEXEC_CONTROL(VMX_VM_EXEC_CTRL3_RDRAND_VMEXIT)) {
      VMexit_Instruction(i, VMX_VMEXIT_RDRAND, BX_READ);
    }
  }
#endif

  Bit64u val_64 = 0;

  clearEFlagsOSZAPC();

  if (HW_RANDOM_GENERATOR_READY) {
    val_64 |= rand() & 0xff;  // hack using std C rand() function
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;

    assert_CF();
  }

  BX_WRITE_64BIT_REG(i->dst(), val_64);

  BX_NEXT_INSTR(i);
}
#endif

void BX_CPP_AttrRegparmN(1) BX_CPU_C::RDSEED_Ew(bxInstruction_c *i)
{
#if BX_SUPPORT_VMX
  if (BX_CPU_THIS_PTR in_vmx_guest) {
    if (SECONDARY_VMEXEC_CONTROL(VMX_VM_EXEC_CTRL3_RDSEED_VMEXIT)) {
      VMexit_Instruction(i, VMX_VMEXIT_RDSEED, BX_READ);
    }
  }
#endif

  Bit16u val_16 = 0;

  clearEFlagsOSZAPC();

  if (HW_RANDOM_GENERATOR_READY) {
    val_16 |= rand() & 0xff;  // hack using std C rand() function
    val_16 <<= 8;
    val_16 |= rand() & 0xff;

    assert_CF();
  }

  BX_WRITE_16BIT_REG(i->dst(), val_16);

  BX_NEXT_INSTR(i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::RDSEED_Ed(bxInstruction_c *i)
{
#if BX_SUPPORT_VMX
  if (BX_CPU_THIS_PTR in_vmx_guest) {
    if (SECONDARY_VMEXEC_CONTROL(VMX_VM_EXEC_CTRL3_RDSEED_VMEXIT)) {
      VMexit_Instruction(i, VMX_VMEXIT_RDSEED, BX_READ);
    }
  }
#endif

  Bit32u val_32 = 0;

  clearEFlagsOSZAPC();

  if (HW_RANDOM_GENERATOR_READY) {
    val_32 |= rand() & 0xff;  // hack using std C rand() function
    val_32 <<= 8;
    val_32 |= rand() & 0xff;
    val_32 <<= 8;
    val_32 |= rand() & 0xff;
    val_32 <<= 8;
    val_32 |= rand() & 0xff;

    assert_CF();
  }

  BX_WRITE_32BIT_REGZ(i->dst(), val_32);

  BX_NEXT_INSTR(i);
}

#if BX_SUPPORT_X86_64
void BX_CPP_AttrRegparmN(1) BX_CPU_C::RDSEED_Eq(bxInstruction_c *i)
{
#if BX_SUPPORT_VMX
  if (BX_CPU_THIS_PTR in_vmx_guest) {
    if (SECONDARY_VMEXEC_CONTROL(VMX_VM_EXEC_CTRL3_RDSEED_VMEXIT)) {
      VMexit_Instruction(i, VMX_VMEXIT_RDSEED, BX_READ);
    }
  }
#endif

  Bit64u val_64 = 0;

  clearEFlagsOSZAPC();

  if (HW_RANDOM_GENERATOR_READY) {
    val_64 |= rand() & 0xff;  // hack using std C rand() function
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;
    val_64 <<= 8;
    val_64 |= rand() & 0xff;

    assert_CF();
  }

  BX_WRITE_64BIT_REG(i->dst(), val_64);

  BX_NEXT_INSTR(i);
}
#endif
