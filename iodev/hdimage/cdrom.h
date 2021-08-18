/////////////////////////////////////////////////////////////////////////
// $Id: cdrom.h 14116 2021-01-31 15:44:39Z vruppert $
/////////////////////////////////////////////////////////////////////////

// Header file for low-level OS specific CDROM emulation

extern unsigned int bx_cdrom_count;


class cdrom_base_c : public logfunctions {
public:
  cdrom_base_c() {}
  cdrom_base_c(const char *dev);
  virtual ~cdrom_base_c(void);

  // Load CD-ROM. Returns 0 if CD is not ready.
  virtual bool insert_cdrom(const char *dev = NULL);

  // Logically eject the CD.
  virtual void eject_cdrom();

  // Read CD TOC. Returns 0 if start track is out of bounds.
  virtual bool read_toc(Bit8u* buf, int* length, bool msf, int start_track, int format);

  // Return CD-ROM capacity (in 2048 byte frames)
  virtual Bit32u capacity();

  // Read a single block from the CD. Returns 0 on failure.
  virtual bool read_block(Bit8u* buf, Bit32u lba, int blocksize) BX_CPP_AttrRegparmN(3);

  // Start (spin up) the CD.
  virtual bool start_cdrom();

  // Seek for new block address.
  virtual bool seek(Bit32u lba);

protected:
  int fd;
  char *path;
  bool using_file;
};
