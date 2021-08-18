/////////////////////////////////////////////////////////////////////////
// $Id: tag_w.h 12857 2015-10-09 19:33:36Z sshwarts $
/////////////////////////////////////////////////////////////////////////

#ifndef _TAG_W_H
#define _TAG_W_H

/* Tag Word */
enum {
  FPU_Tag_Valid   = 0x00,
  FPU_Tag_Zero    = 0x01,
  FPU_Tag_Special = 0x02,
  FPU_Tag_Empty   = 0x03
};

#endif
