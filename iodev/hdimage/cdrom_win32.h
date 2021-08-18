/////////////////////////////////////////////////////////////////////////
// $Id: cdrom_win32.h 14116 2021-01-31 15:44:39Z vruppert $
/////////////////////////////////////////////////////////////////////////


// Header file for low-level OS specific CDROM emulation

class cdrom_win32_c : public cdrom_base_c {
public:
  cdrom_win32_c(const char *dev);
  virtual ~cdrom_win32_c(void);
  bool insert_cdrom(const char *dev = NULL);
  void eject_cdrom();
  bool read_toc(Bit8u* buf, int* length, bool msf, int start_track, int format);
  Bit32u capacity();
  bool read_block(Bit8u* buf, Bit32u lba, int blocksize) BX_CPP_AttrRegparmN(3);
private:
#ifdef WIN32
  HANDLE hFile;
#endif
};
