/////////////////////////////////////////////////////////////////////////
// $Id: corei7_ivy_bridge_3770K.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_COREI7_IVY_BRIDGE_3770K_CPUID_DEFINITIONS_H
#define BX_COREI7_IVY_BRIDGE_3770K_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64 && BX_SUPPORT_AVX

#include "../cpu/cpuid.h"

class corei7_ivy_bridge_3770k_t : public bx_cpuid_t {
public:
  corei7_ivy_bridge_3770k_t(BX_CPU_C *cpu);
  virtual ~corei7_ivy_bridge_3770k_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "corei7_ivy_bridge_3770k"; }

#if BX_SUPPORT_VMX >= 2
  virtual Bit32u get_vmx_extensions_bitmask(void) const;
#endif

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

private:
  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_2(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_4(Bit32u subfunction, cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_5(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_7(Bit32u subfunction, cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_A(cpuid_function_t *leaf) const;

  void get_ext_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_7(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_corei7_ivy_bridge_3770k_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64 && BX_SUPPORT_AVX

#endif
