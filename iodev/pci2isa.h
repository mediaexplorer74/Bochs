/////////////////////////////////////////////////////////////////////////
// $Id: pci2isa.h 14111 2021-01-31 08:22:55Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_IODEV_PIC2ISA_H
#define BX_IODEV_PIC2ISA_H

#if BX_USE_P2I_SMF
#  define BX_P2I_SMF  static
#  define BX_P2I_THIS thePci2IsaBridge->
#else
#  define BX_P2I_SMF
#  define BX_P2I_THIS this->
#endif


class bx_piix3_c : public bx_pci2isa_stub_c {
public:
  bx_piix3_c();
  virtual ~bx_piix3_c();
  virtual void init(void);
  virtual void reset(unsigned type);
  virtual void pci_set_irq(Bit8u devfunc, unsigned line, bool level);
  virtual void register_state(void);
  virtual void after_restore_state(void);

  virtual void pci_write_handler(Bit8u address, Bit32u value, unsigned io_len);
#if BX_DEBUGGER
  virtual void debug_dump(int argc, char **argv);
#endif

private:

  struct {
    unsigned chipset;
    Bit8u devfunc;
    Bit8u map_slot_to_dev;
    Bit8u elcr1;
    Bit8u elcr2;
    Bit8u apmc;
    Bit8u apms;
    Bit8u irq_registry[16];
    Bit32u irq_level[4][16];
    Bit8u pci_reset;
  } s;

  static void pci_register_irq(unsigned pirq, Bit8u irq);
  static void pci_unregister_irq(unsigned pirq, Bit8u irq);

  static Bit32u read_handler(void *this_ptr, Bit32u address, unsigned io_len);
  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_P2I_SMF
  Bit32u read(Bit32u address, unsigned io_len);
  void   write(Bit32u address, Bit32u value, unsigned io_len);
#endif
};

#endif
