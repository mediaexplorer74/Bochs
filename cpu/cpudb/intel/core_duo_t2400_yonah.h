/////////////////////////////////////////////////////////////////////////
// $Id: core_duo_t2400_yonah.h 13111 2017-03-13 19:44:14Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_CORE_DUO_T2400_YONAH_CPUID_DEFINITIONS_H
#define BX_CORE_DUO_T2400_YONAH_CPUID_DEFINITIONS_H

#if BX_CPU_LEVEL >= 6

#include "../cpu/cpuid.h"

class core_duo_t2400_yonah_t : public bx_cpuid_t {
public:
  core_duo_t2400_yonah_t(BX_CPU_C *cpu);
  virtual ~core_duo_t2400_yonah_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "core_duo_t2400_yonah"; }

#if BX_SUPPORT_VMX
  virtual Bit32u get_vmx_extensions_bitmask(void) const { return 0; } // only basic support
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
  void get_std_cpuid_leaf_A(cpuid_function_t *leaf) const;

  void get_ext_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_7(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_core_duo_t2400_yonah_cpuid(BX_CPU_C *cpu);

#endif // BX_CPU_LEVEL >= 6

#endif
