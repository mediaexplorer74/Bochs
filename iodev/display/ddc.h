////////////////////////////////////////////////////////////////////////
// $Id: ddc.h 14244 2021-05-13 17:58:57Z vruppert $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_DISPLAY_DDC_H
#define BX_DISPLAY_DDC_H

class bx_ddc_c : public logfunctions {
public:
  bx_ddc_c();
  virtual ~bx_ddc_c();

  Bit8u read(void);
  void write(bool dck, bool dda);

private:

  Bit8u get_edid_byte(void);

  struct {
    Bit8u ddc_mode;
    bool  DCKhost;
    bool  DDAhost;
    bool  DDAmon;
    Bit8u ddc_stage;
    Bit8u ddc_bitshift;
    bool  ddc_ack;
    bool  ddc_rw;
    Bit8u ddc_byte;
    Bit8u edid_index;
    bool  edid_extblock;
    Bit8u edid_data[256];
  } s;  // state information
};

#endif
