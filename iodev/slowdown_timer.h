/////////////////////////////////////////////////////////////////////////
// $Id: slowdown_timer.h 10209 2011-02-24 22:05:47Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_IODEV_SLOWDOWN_TIMER_H
#define BX_IODEV_SLOWDOWN_TIMER_H

class bx_slowdown_timer_c : public logfunctions {
private:
  struct {
    Bit64u start_time;
    Bit64u start_emulated_time;
    Bit64u lasttime;

    int timer_handle;

    float MAXmultiplier;
    Bit64u Q; // sleep rate in usec
  } s;

public:
  bx_slowdown_timer_c();

  void init(void);
  void exit(void);
  void after_restore_state(void);

  static void timer_handler(void * this_ptr);

  void handle_timer();

};

extern bx_slowdown_timer_c bx_slowdown_timer;

#endif
