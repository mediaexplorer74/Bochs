/////////////////////////////////////////////////////////////////////////
// $Id: trinity_apu.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_AMD_TRINITY_CPUID_DEFINITIONS_H
#define BX_AMD_TRINITY_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64 && BX_SUPPORT_AVX

#include "../cpu/cpuid.h"

class trinity_apu_t : public bx_cpuid_t {
public:
  trinity_apu_t(BX_CPU_C *cpu);
  virtual ~trinity_apu_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "trinity_apu"; }

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
};

extern bx_cpuid_t *create_trinity_apu_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64 && BX_SUPPORT_AVX

#endif
