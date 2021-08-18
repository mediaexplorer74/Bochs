/////////////////////////////////////////////////////////////////////////
// $Id: pit.h 14109 2021-01-30 23:55:24Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef _BX_PIT_H
#define _BX_PIT_H

#include "../bochs/bochs.h"
#include "pit82c54.h"

#if BX_USE_PIT_SMF
#  define BX_PIT_SMF  static
#  define BX_PIT_THIS thePit->
#else
#  define BX_PIT_SMF
#  define BX_PIT_THIS this->
#endif

class bx_pit_c : public bx_pit_stub_c {
public:
  bx_pit_c();
  virtual ~bx_pit_c();
  virtual void init(void);
  virtual void reset(unsigned type);
  virtual void register_state(void);
  virtual void after_restore_state(void);
  virtual void enable_irq(bool enabled) {
    s.irq_enabled = enabled;
  }
#if BX_DEBUGGER
  virtual void debug_dump(int argc, char **argv);
#endif

private:
  static Bit32u read_handler(void *this_ptr, Bit32u address, unsigned io_len);
  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_PIT_SMF
  Bit32u   read(Bit32u addr, unsigned len);
  void write(Bit32u addr, Bit32u Value, unsigned len);
#endif

  struct s_type {
    pit_82C54 timer;
    bool speaker_data_on;
    bool speaker_active;
    bool speaker_level;
    Bit64u  last_usec;
    Bit32u  last_next_event_time;
    Bit64u  total_ticks;
    Bit64u  total_usec;
    int     timer_handle[3];
    bool irq_enabled;
  } s;

  bool is_realtime;

  static void timer_handler(void *this_ptr);
  BX_PIT_SMF void handle_timer();
  BX_PIT_SMF bool periodic(Bit32u usec_delta);

  BX_PIT_SMF void  irq_handler(bool value);
  BX_PIT_SMF void  speaker_handler(bool value);

  BX_PIT_SMF Bit16u get_timer(int Timer);
  BX_PIT_SMF Bit16u new_timer_count(int Timer);
};

#endif  // #ifndef _BX_PIT_H
