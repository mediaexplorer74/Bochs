/////////////////////////////////////////////////////////////////////////
// $Id: p2_klamath.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_P2_KLAMATH_CPUID_DEFINITIONS_H
#define BX_P2_KLAMATH_CPUID_DEFINITIONS_H

#if BX_CPU_LEVEL >= 6

#include "../cpu/cpuid.h"

class p2_klamath_t : public bx_cpuid_t {
public:
  p2_klamath_t(BX_CPU_C *cpu);
  virtual ~p2_klamath_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "p2_klamath"; }

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

private:
  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_2(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_p2_klamath_cpuid(BX_CPU_C *cpu);

#endif // BX_CPU_LEVEL >= 6

#endif
