/////////////////////////////////////////////////////////////////////////
// $Id: control_w.h 11415 2012-09-12 21:08:40Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef _CONTROL_W_H_
#define _CONTROL_W_H_

/* ************ */
/* Control Word */
/* ************ */

#define FPU_CW_Reserved_Bits    (0xe0c0)  /* reserved bits */

#define FPU_CW_Inf		(0x1000)  /* infinity control, legacy */

#define FPU_CW_RC		(0x0C00)  /* rounding control */
#define FPU_CW_PC		(0x0300)  /* precision control */

#define FPU_RC_RND		(0x0000)  /* rounding control */
#define FPU_RC_DOWN		(0x0400)
#define FPU_RC_UP		(0x0800)
#define FPU_RC_CHOP		(0x0C00)

#define FPU_CW_Precision	(0x0020)  /* loss of precision mask */
#define FPU_CW_Underflow	(0x0010)  /* underflow mask */
#define FPU_CW_Overflow		(0x0008)  /* overflow mask */
#define FPU_CW_Zero_Div		(0x0004)  /* divide by zero mask */
#define FPU_CW_Denormal		(0x0002)  /* denormalized operand mask */
#define FPU_CW_Invalid		(0x0001)  /* invalid operation mask */

#define FPU_CW_Exceptions_Mask 	(0x003f)  /* all masks */

/* Precision control bits affect only the following:
   ADD, SUB(R), MUL, DIV(R), and SQRT */
#define FPU_PR_32_BITS          (0x000)
#define FPU_PR_RESERVED_BITS    (0x100)
#define FPU_PR_64_BITS          (0x200)
#define FPU_PR_80_BITS          (0x300)

#endif
