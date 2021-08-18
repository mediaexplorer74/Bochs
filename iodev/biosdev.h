////////////////////////////////////////////////////////////////////////
// $Id: biosdev.h 14112 2021-01-31 10:50:53Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_IODEV_BIOSDEV_H
#define BX_IODEV_BIOSDEV_H

#define BX_BIOS_MESSAGE_SIZE 80

#if BX_USE_BIOS_SMF
#  define BX_BIOS_SMF  static
#  define BX_BIOS_THIS theBiosDevice->
#else
#  define BX_BIOS_SMF
#  define BX_BIOS_THIS this->
#endif

class bx_biosdev_c : public bx_devmodel_c {
public:
  bx_biosdev_c();
  virtual ~bx_biosdev_c();

  virtual void init(void);
  virtual void reset(unsigned type) {}

private:

  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_BIOS_SMF
  void   write(Bit32u address, Bit32u value, unsigned io_len);
#endif

  struct {
    Bit8u bios_message[BX_BIOS_MESSAGE_SIZE];
    unsigned int bios_message_i;
    bool bios_panic_flag;

    Bit8u vgabios_message[BX_BIOS_MESSAGE_SIZE];
    unsigned int vgabios_message_i;
    bool vgabios_panic_flag;
  } s;  // state information
};

#endif
