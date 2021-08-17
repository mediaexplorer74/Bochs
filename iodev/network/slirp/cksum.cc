/////////////////////////////////////////////////////////////////////////
// $Id: cksum.cc 13932 2020-09-02 08:35:44Z vruppert $
/////////////////////////////////////////////////////////////////////////


#include "pch.h"

// NOTE: <stdint.h> included in slirp.h
#include "slirp.h"

#if BX_NETWORKING && BX_NETMOD_SLIRP

/*
 * Checksum routine for Internet Protocol family headers (Portable Version).
 *
 * This routine is very heavily used in the network
 * code and should be modified for each CPU to be as fast as possible.
 *
 * XXX Since we will never span more than 1 mbuf, we can optimise this
 */

#define ADDCARRY(x)  (x > 65535 ? x -= 65535 : x)
#define REDUCE {l_util.l = sum; sum = l_util.s[0] + l_util.s[1];        \
        (void)ADDCARRY(sum);}

int cksum(struct mbuf *m, int len)
{
	uint16_t *w;
	int sum = 0;
	int mlen = 0;
	int byte_swapped = 0;

	union {
		uint8_t  c[2];
		uint16_t s;
	} s_util;
	union {
		uint16_t s[2];
		uint32_t l;
	} l_util;

	if (m->m_len == 0)
	   goto cont;
	w = mtod(m, uint16_t *);

	mlen = m->m_len;

	if (len < mlen)
	   mlen = len;
#ifdef DEBUG
	len -= mlen;
#endif
	/*
	 * Force to even boundary.
	 */
	if ((1 & (uintptr_t)w) && (mlen > 0)) {
		REDUCE;
		sum <<= 8;
		s_util.c[0] = *(uint8_t *)w;
		w = (uint16_t *)((int8_t *)w + 1);
		mlen--;
		byte_swapped = 1;
	}
	/*
	 * Unroll the loop to make overhead from
	 * branches &c small.
	 */
	while ((mlen -= 32) >= 0) {
		sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
		sum += w[4]; sum += w[5]; sum += w[6]; sum += w[7];
		sum += w[8]; sum += w[9]; sum += w[10]; sum += w[11];
		sum += w[12]; sum += w[13]; sum += w[14]; sum += w[15];
		w += 16;
	}
	mlen += 32;
	while ((mlen -= 8) >= 0) {
		sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
		w += 4;
	}
	mlen += 8;
	if (mlen == 0 && byte_swapped == 0)
	   goto cont;
	REDUCE;
	while ((mlen -= 2) >= 0) {
		sum += *w++;
	}

	if (byte_swapped) {
		REDUCE;
		sum <<= 8;
		if (mlen == -1) {
			s_util.c[1] = *(uint8_t *)w;
			sum += s_util.s;
			mlen = 0;
		} else

		   mlen = -1;
	} else if (mlen == -1)
	   s_util.c[0] = *(uint8_t *)w;

cont:
#ifdef DEBUG
	if (len) {
		DEBUG_ERROR((dfd, "cksum: out of data\n"));
		DEBUG_ERROR((dfd, " len = %d\n", len));
	}
#endif
	if (mlen == -1) {
		/* The last mbuf has odd # of bytes. Follow the
		 standard (the odd byte may be shifted left by 8 bits
			   or not as determined by endian-ness of the machine) */
		s_util.c[1] = 0;
		sum += s_util.s;
	}
	REDUCE;
	return (~sum & 0xffff);
}

#endif
