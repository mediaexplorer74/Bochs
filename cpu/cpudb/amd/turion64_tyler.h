/////////////////////////////////////////////////////////////////////////
// $Id: turion64_tyler.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_TURION64_TYLER_CPUID_DEFINITIONS_H
#define BX_TURION64_TYLER_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64

#include "../cpu/cpuid.h"

class turion64_tyler_t : public bx_cpuid_t {
public:
  turion64_tyler_t(BX_CPU_C *cpu);
  virtual ~turion64_tyler_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "turion64_tyler"; }

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

private:
  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;

  void get_ext_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_5(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_7(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_8(cpuid_function_t *leaf) const;
#if BX_SUPPORT_SVM
  void get_ext_cpuid_leaf_A(cpuid_function_t *leaf) const;
#endif
};

extern bx_cpuid_t *create_turion64_tyler_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64

#endif
