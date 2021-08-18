/////////////////////////////////////////////////////////////////////////
// $Id: extfpuirq.h 10209 2011-02-24 22:05:47Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_IODEV_EXTFPUIRQ_H
#define BX_IODEV_EXTFPUIRQ_H


#if BX_USE_EFI_SMF
#  define BX_EXTFPUIRQ_SMF  static
#  define BX_EXTFPUIRQ_THIS theExternalFpuIrq->
#else
#  define BX_EXTFPUIRQ_SMF
#  define BX_EXTFPUIRQ_THIS this->
#endif


class bx_extfpuirq_c : public bx_devmodel_c {
public:
  bx_extfpuirq_c();
  virtual ~bx_extfpuirq_c();
  virtual void   init(void);
  virtual void   reset(unsigned type);

private:

  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_EFI_SMF
  void   write(Bit32u address, Bit32u value, unsigned io_len);
#endif
};

#endif
