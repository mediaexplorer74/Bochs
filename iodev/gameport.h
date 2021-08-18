/////////////////////////////////////////////////////////////////////////
// $Id: gameport.h 14112 2021-01-31 10:50:53Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_IODEV_GAMEPORT_H
#define BX_IODEV_GAMEPORT_H

#if BX_USE_GAMEPORT_SMF
#  define BX_GAMEPORT_SMF  static
#  define BX_GAMEPORT_THIS theGameport->
#else
#  define BX_GAMEPORT_SMF
#  define BX_GAMEPORT_THIS this->
#endif


class bx_gameport_c : public bx_game_stub_c {
public:
  bx_gameport_c();
  virtual ~bx_gameport_c();
  virtual void init(void);
  virtual void reset(unsigned type);
  virtual void register_state(void);
  virtual void set_enabled(bool val) {enabled = val;}

private:
  bool    enabled;
  int     joyfd;
  Bit8u   port;
  Bit16u  delay_x;
  Bit16u  delay_y;
  bool    timer_x;
  bool    timer_y;
  Bit64u  write_usec;

  BX_GAMEPORT_SMF void poll_joydev(void);

  static Bit32u read_handler(void *this_ptr, Bit32u address, unsigned io_len);
  static void   write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len);
#if !BX_USE_GAMEPORT_SMF
  Bit32u read(Bit32u address, unsigned io_len);
  void   write(Bit32u address, Bit32u value, unsigned io_len);
#endif
};

#endif
