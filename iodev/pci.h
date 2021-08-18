/////////////////////////////////////////////////////////////////////////
// $Id: pci.h 14112 2021-01-31 10:50:53Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_IODEV_PCI_BRIDGE_H
#define BX_IODEV_PCI_BRIDGE_H

#if BX_USE_PCI_SMF
#  define BX_PCI_SMF  static
#  define BX_PCI_THIS thePciBridge->
#else
#  define BX_PCI_SMF
#  define BX_PCI_THIS this->
#endif

#define BX_PCI_DEVICE(device, function) ((device)<<3 | (function))

#define BX_PCI_INTA 1
#define BX_PCI_INTB 2
#define BX_PCI_INTC 3
#define BX_PCI_INTD 4

class bx_pci_vbridge_c;

class bx_pci_bridge_c : public bx_pci_device_c {
public:
  bx_pci_bridge_c();
  virtual ~bx_pci_bridge_c();
  virtual void init(void);
  virtual void reset(unsigned type);
  virtual void register_state(void);
  virtual void after_restore_state(void);

  static bool agp_ap_read_handler(bx_phy_address addr, unsigned len, void *data, void *param);
  static bool agp_ap_write_handler(bx_phy_address addr, unsigned len, void *data, void *param);

  Bit32u agp_aperture_read(bx_phy_address addr, unsigned len, bool agp);
  void   agp_aperture_write(bx_phy_address addr, Bit32u value, unsigned len, bool agp);

  virtual void pci_write_handler(Bit8u address, Bit32u value, unsigned io_len);
#if BX_DEBUGGER
  virtual void debug_dump(int argc, char **argv);
#endif

private:
  void smram_control(Bit8u value);

  unsigned chipset;
  Bit8u DRBA[8];
  Bit8u dram_detect;
  Bit32u gart_base;
  bx_pci_vbridge_c *vbridge;
};

class bx_pci_vbridge_c : public bx_pci_device_c {
public:
  bx_pci_vbridge_c();
  virtual ~bx_pci_vbridge_c();
  virtual void init(void);
  virtual void reset(unsigned type);
  virtual void register_state(void);
  virtual void after_restore_state(void);

  virtual void pci_write_handler(Bit8u address, Bit32u value, unsigned io_len);
};
#endif
