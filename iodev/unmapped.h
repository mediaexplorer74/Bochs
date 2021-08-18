/////////////////////////////////////////////////////////////////////////
// $Id: unmapped.h 14241 2021-05-11 14:42:31Z vruppert $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_IODEV_UNMAPPED_H
#define BX_IODEV_UNMAPPED_H

#if BX_USE_UM_SMF
#  define BX_UM_SMF  static
#  define BX_UM_THIS theUnmappedDevice->
#else
#  define BX_UM_SMF
#  define BX_UM_THIS this->
#endif

class bx_unmapped_c : public bx_devmodel_c {
public:
  bx_unmapped_c();
  virtual ~bx_unmapped_c();
  virtual void init(void);
  virtual void reset(unsigned type) {}

private:

  static Bit32u read_handler(void *this_ptr, Bit32u address, unsigned io_len);
  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_UM_SMF
  Bit32u read(Bit32u address, unsigned io_len);
  void   write(Bit32u address, Bit32u value, unsigned io_len);
#endif
  static Bit64s param_handler(bx_param_c *param, bool set, Bit64s val);

  struct {
    Bit8u port80;
    Bit8u port8e;
    Bit8u shutdown;
    bool port_e9_hack;
  } s;  // state information
};

#endif
