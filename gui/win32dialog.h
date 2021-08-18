/////////////////////////////////////////////////////////////////////////
// $Id: win32dialog.h 14203 2021-03-26 19:12:09Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_WIN32_DIALOGS_H
#define BX_WIN32_DIALOGS_H

#include "../bochs/config.h"

// Compilation for WIN64 native require minimum 0x0500
#ifndef _WIN32_IE
#define _WIN32_IE 0x0500  /* Force a minimum "OS level" for commctrl.h */
#endif
#if _WIN32_IE < 0x0500
#undef _WIN32_IE
#define _WIN32_IE 0x0500
#endif

extern "C" {
#include <assert.h>
#include <stdio.h>
#include <windows.h>
#include <commctrl.h>
#include <shlobj.h>
#include <ctype.h>
}

#endif // BX_WIN32_DIALOGS_H
