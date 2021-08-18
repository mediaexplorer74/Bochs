/////////////////////////////////////////////////////////////////////////
// $Id: scancodes.h 10209 2011-02-24 22:05:47Z sshwarts $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_SCANCODES_H
#define BX_SCANCODES_H

// Translation table of the 8042
extern unsigned char translation8042[256];

typedef struct {
  const char *make;
  const char *brek;
} scancode;

// Scancodes table
extern scancode scancodes[BX_KEY_NBKEYS][3];

#endif
