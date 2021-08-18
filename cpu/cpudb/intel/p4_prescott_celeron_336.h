/////////////////////////////////////////////////////////////////////////
// $Id: p4_prescott_celeron_336.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_P4_PSC_CELERON_336_CPUID_DEFINITIONS_H
#define BX_P4_PSC_CELERON_336_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64

#include "../cpu/cpuid.h"

class p4_prescott_celeron_336_t : public bx_cpuid_t {
public:
  p4_prescott_celeron_336_t(BX_CPU_C *cpu);
  virtual ~p4_prescott_celeron_336_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "p4_prescott_celeron_336"; }

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

private:
  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_2(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_3(cpuid_function_t *leaf) const;

  void get_ext_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_7(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_p4_prescott_celeron_336_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64

#endif

