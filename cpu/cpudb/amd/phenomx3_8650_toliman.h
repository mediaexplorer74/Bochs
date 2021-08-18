/////////////////////////////////////////////////////////////////////////
// $Id: phenomx3_8650_toliman.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_PHENOM_X3_8650_TOLIMAN_CPUID_DEFINITIONS_H
#define BX_PHENOM_X3_8650_TOLIMAN_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64

#include "../cpu/cpuid.h"

class phenom_8650_toliman_t : public bx_cpuid_t {
public:
  phenom_8650_toliman_t(BX_CPU_C *cpu);
  virtual ~phenom_8650_toliman_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "phenom_8650_toliman"; }

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
};

extern bx_cpuid_t *create_phenom_8650_toliman_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64

#endif
