/////////////////////////////////////////////////////////////////////////
// $Id: ryzen.h 13119 2017-03-15 22:14:10Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_AMD_RYZEN_CPUID_DEFINITIONS_H
#define BX_AMD_RYZEN_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64 && BX_SUPPORT_AVX

#include "../cpu/cpuid.h"

class ryzen_t : public bx_cpuid_t {
public:
  ryzen_t(BX_CPU_C *cpu);
  virtual ~ryzen_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "ryzen"; }

#if BX_SUPPORT_SVM
  virtual Bit32u get_svm_extensions_bitmask(void) const;
#endif

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

private:
  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;
#if BX_SUPPORT_MONITOR_MWAIT
  void get_std_cpuid_leaf_5(cpuid_function_t *leaf) const;
#endif
  void get_std_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_7(Bit32u subfunction, cpuid_function_t *leaf) const;

  void get_ext_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_5(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_7(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_8(cpuid_function_t *leaf) const;
#if BX_SUPPORT_SVM
  void get_ext_cpuid_leaf_A(cpuid_function_t *leaf) const;
#endif
  void get_ext_cpuid_leaf_19(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1A(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1B(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1C(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1D(Bit32u subfunction, cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1E(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1F(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_ryzen_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64 && BX_SUPPORT_AVX

#endif
