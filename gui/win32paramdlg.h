/////////////////////////////////////////////////////////////////////////
// $Id: win32paramdlg.h 12381 2014-06-20 09:31:56Z vruppert $
/////////////////////////////////////////////////////////////////////////

#ifndef BX_WIN32_PARAMDLG_H
#define BX_WIN32_PARAMDLG_H

#include "../bochs/config.h"

#if BX_USE_WIN32CONFIG

int AskFilename(HWND hwnd, bx_param_filename_c *param, char *buffer);
INT_PTR win32ParamDialog(HWND parent, const char *menu);
INT_PTR win32FloppyParamDialog(HWND parent, const char *menu);

#endif

#endif // BX_WIN32_PARAMDLG_H
