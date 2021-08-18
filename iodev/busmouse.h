/////////////////////////////////////////////////////////////////////////
// $Id: busmouse.h 14112 2021-01-31 10:50:53Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef _PCBUSM_H
#define _PCBUSM_H

#if BX_SUPPORT_BUSMOUSE

// these keywords should only be used in busmouse.cc
#if BX_USE_BUSM_SMF
#  define BX_BUSM_SMF  static
#  define BX_BUSM_THIS theBusMouse->
#else
#  define BX_BUSM_SMF
#  define BX_BUSM_THIS
#endif

class bx_busm_c : public bx_devmodel_c {
public:
  bx_busm_c();
  virtual ~bx_busm_c();

  virtual void init(void);
  virtual void reset(unsigned type) {}
  virtual void register_state(void);

private:
  static void timer_handler(void *);
  void busm_timer(void);

  static void mouse_enq_static(void *dev, int delta_x, int delta_y, int delta_z, unsigned button_state, bool absxy);
  void mouse_enq(int delta_x, int delta_y, int delta_z, unsigned button_state);
  void update_mouse_data(void);

  static Bit32u read_handler(void *this_ptr, Bit32u address, unsigned io_len);
  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_BUSM_SMF
  void   write(Bit32u address, Bit32u value, unsigned io_len);
  Bit32u  read(Bit32u address, unsigned io_len);
#endif

  int   type;
  int   timer_index; // our timer index

  int   mouse_delayed_dx;
  int   mouse_delayed_dy;
  Bit8u mouse_buttons;
  Bit8u mouse_buttons_last;
  Bit8u current_x, current_y, current_b;

  Bit8u control_val;
  Bit8u command_val;     // current command val
  Bit8u config_val;
  Bit8u sig_val;
  Bit16u toggle_counter;
  bool interrupts;       // 0 or 1.  interrupts off or on.
};

#endif  // BX_SUPPORT_BUSMOUSE

#endif  // #ifndef _PCBUSM_H
