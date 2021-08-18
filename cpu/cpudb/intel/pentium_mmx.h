/////////////////////////////////////////////////////////////////////////
// $Id: pentium_mmx.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_PENTIUM_MMX_CPUID_DEFINITIONS_H
#define BX_PENTIUM_MMX_CPUID_DEFINITIONS_H

#if BX_CPU_LEVEL >= 5

#include "../cpu/cpuid.h"

class pentium_mmx_t : public bx_cpuid_t {
public:
  pentium_mmx_t(BX_CPU_C *cpu);
  virtual ~pentium_mmx_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "pentium_mmx"; }

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

private:
  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_pentium_mmx_cpuid(BX_CPU_C *cpu);

#endif // BX_CPU_LEVEL >= 5

#endif
