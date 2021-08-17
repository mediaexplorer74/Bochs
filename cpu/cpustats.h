/////////////////////////////////////////////////////////////////////////
// $Id: cpustats.h 12846 2015-09-28 19:09:32Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_CPUSTATS_H
#define BX_CPUSTATS_H

#define InstrumentICACHE 0
#define InstrumentTLB 0
#define InstrumentTLBFlush 0
#define InstrumentStackPrefetch 0
#define InstrumentSMC 0

// indicate if any of the CPU statistics was compiled in
#define InstrumentCPU (InstrumentICACHE + InstrumentTLB + InstrumentTLBFlush + InstrumentStackPrefetch + InstrumentSMC)

struct bx_cpu_statistics
{
  // icache statistics
  Bit64u iCacheLookups;
  Bit64u iCachePrefetch;
  Bit64u iCacheMisses;

  // tlb lookup statistics
  Bit64u tlbLookups;
  Bit64u tlbExecuteLookups;
  Bit64u tlbWriteLookups;
  Bit64u tlbMisses;
  Bit64u tlbExecuteMisses;
  Bit64u tlbWriteMisses;

  // tlb flush statistics
  Bit64u tlbGlobalFlushes;
  Bit64u tlbNonGlobalFlushes;

  // stack prefetch statistics
  Bit64u stackPrefetch;

  // self modifying code statistics
  Bit64u smc;

  bx_cpu_statistics():
      iCacheLookups(0), iCachePrefetch(0), iCacheMisses(0),
      tlbLookups(0), tlbExecuteLookups(0), tlbWriteLookups(0),
      tlbMisses(0), tlbExecuteMisses(0), tlbWriteMisses(0),
      tlbGlobalFlushes(0), tlbNonGlobalFlushes(0),
      stackPrefetch(0), smc(0) {}
  
};

#define INC_CPU_STAT(stat) INC_STAT(BX_CPU_THIS_PTR stats -> stat)

#if InstrumentICACHE
  #define INC_ICACHE_STAT(stat) INC_CPU_STAT(stat)
#else
  #define INC_ICACHE_STAT(stat)
#endif

#if InstrumentTLBFlush
  #define INC_TLBFLUSH_STAT(stat) INC_CPU_STAT(stat)
#else
  #define INC_TLBFLUSH_STAT(stat)
#endif

#if InstrumentTLB
  #define INC_TLB_STAT(stat) INC_CPU_STAT(stat)
#else
  #define INC_TLB_STAT(stat)
#endif

#if InstrumentStackPrefetch
  #define INC_STACK_PREFETCH_STAT(stat) INC_CPU_STAT(stat)
#else
  #define INC_STACK_PREFETCH_STAT(stat)
#endif

#if InstrumentSMC
  #define INC_SMC_STAT(stat) INC_CPU_STAT(stat)
#else
  #define INC_SMC_STAT(stat)
#endif

#endif
