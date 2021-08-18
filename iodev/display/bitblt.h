/////////////////////////////////////////////////////////////////////////
// $Id: bitblt.h 13425 2018-01-05 17:43:51Z vruppert $
/////////////////////////////////////////////////////////////////////////


#ifndef BX_BITBLT_H
#define BX_BITBLT_H

typedef void (*bx_bitblt_rop_t)(
    Bit8u *dst,const Bit8u *src,
    int dstpitch,int srcpitch,
    int bltwidth,int bltheight);

#define IMPLEMENT_FORWARD_BITBLT(name,opline) \
  static void bitblt_rop_fwd_##name( \
    Bit8u *dst,const Bit8u *src, \
    int dstpitch,int srcpitch, \
    int bltwidth,int bltheight) \
  { \
    int x,y; \
    dstpitch -= bltwidth; \
    srcpitch -= bltwidth; \
    for (y = 0; y < bltheight; y++) { \
      for (x = 0; x < bltwidth; x++) { \
        opline; \
        dst++; \
        src++; \
      } \
      dst += dstpitch; \
      src += srcpitch; \
    } \
  }

#define IMPLEMENT_BACKWARD_BITBLT(name,opline) \
  static void bitblt_rop_bkwd_##name( \
    Bit8u *dst,const Bit8u *src, \
    int dstpitch,int srcpitch, \
    int bltwidth,int bltheight) \
  { \
    int x,y; \
    dstpitch += bltwidth; \
    srcpitch += bltwidth; \
    for (y = 0; y < bltheight; y++) { \
      for (x = 0; x < bltwidth; x++) { \
        opline; \
        dst--; \
        src--; \
      } \
      dst += dstpitch; \
      src += srcpitch; \
    } \
  }

#ifdef BX_USE_BINARY_ROP
IMPLEMENT_FORWARD_BITBLT(0, *dst = 0)
IMPLEMENT_FORWARD_BITBLT(src_and_dst, *dst = (*src) & (*dst))
IMPLEMENT_FORWARD_BITBLT(nop, (void)0)
IMPLEMENT_FORWARD_BITBLT(src_and_notdst, *dst = (*src) & (~(*dst)))
IMPLEMENT_FORWARD_BITBLT(notdst, *dst = ~(*dst))
IMPLEMENT_FORWARD_BITBLT(src, *dst = *src)
IMPLEMENT_FORWARD_BITBLT(1, *dst = 0xff)
IMPLEMENT_FORWARD_BITBLT(notsrc_and_dst, *dst = (~(*src)) & (*dst))
IMPLEMENT_FORWARD_BITBLT(src_xor_dst, *dst = (*src) ^ (*dst))
IMPLEMENT_FORWARD_BITBLT(src_or_dst, *dst = (*src) | (*dst))
IMPLEMENT_FORWARD_BITBLT(notsrc_or_notdst, *dst = (~(*src)) | (~(*dst)))
IMPLEMENT_FORWARD_BITBLT(src_notxor_dst, *dst = ~((*src) ^ (*dst)))
IMPLEMENT_FORWARD_BITBLT(src_or_notdst, *dst = (*src) | (~(*dst)))
IMPLEMENT_FORWARD_BITBLT(notsrc, *dst = (~(*src)))
IMPLEMENT_FORWARD_BITBLT(notsrc_or_dst, *dst = (~(*src)) | (*dst))
IMPLEMENT_FORWARD_BITBLT(notsrc_and_notdst, *dst = (~(*src)) & (~(*dst)))

IMPLEMENT_BACKWARD_BITBLT(0, *dst = 0)
IMPLEMENT_BACKWARD_BITBLT(src_and_dst, *dst = (*src) & (*dst))
IMPLEMENT_BACKWARD_BITBLT(nop, (void)0)
IMPLEMENT_BACKWARD_BITBLT(src_and_notdst, *dst = (*src) & (~(*dst)))
IMPLEMENT_BACKWARD_BITBLT(notdst, *dst = ~(*dst))
IMPLEMENT_BACKWARD_BITBLT(src, *dst = *src)
IMPLEMENT_BACKWARD_BITBLT(1, *dst = 0xff)
IMPLEMENT_BACKWARD_BITBLT(notsrc_and_dst, *dst = (~(*src)) & (*dst))
IMPLEMENT_BACKWARD_BITBLT(src_xor_dst, *dst = (*src) ^ (*dst))
IMPLEMENT_BACKWARD_BITBLT(src_or_dst, *dst = (*src) | (*dst))
IMPLEMENT_BACKWARD_BITBLT(notsrc_or_notdst, *dst = (~(*src)) | (~(*dst)))
IMPLEMENT_BACKWARD_BITBLT(src_notxor_dst, *dst = ~((*src) ^ (*dst)))
IMPLEMENT_BACKWARD_BITBLT(src_or_notdst, *dst = (*src) | (~(*dst)))
IMPLEMENT_BACKWARD_BITBLT(notsrc, *dst = (~(*src)))
IMPLEMENT_BACKWARD_BITBLT(notsrc_or_dst, *dst = (~(*src)) | (*dst))
IMPLEMENT_BACKWARD_BITBLT(notsrc_and_notdst, *dst = (~(*src)) & (~(*dst)))
#endif

#ifdef BX_USE_TERNARY_ROP
static void bx_ternary_rop(Bit8u rop0, Bit8u *dst_ptr, Bit8u *src_ptr, Bit8u *pat_ptr,
                    int dpxsize)
{
  Bit8u mask, inbits, outbits;

  for (int i = 0; i < dpxsize; i++) {
    mask = 0x80;
    outbits = 0;
    for (int b = 7; b >= 0; b--) {
      inbits = (*dst_ptr & mask) > 0;
      inbits |= ((*src_ptr & mask) > 0) << 1;
      inbits |= ((*pat_ptr & mask) > 0) << 2;
      outbits |= ((rop0 & (1 << inbits)) > 0) << b;
      mask >>= 1;
    }
    *dst_ptr++ = outbits;
    src_ptr++;
    pat_ptr++;
  }
}
#endif

#endif
