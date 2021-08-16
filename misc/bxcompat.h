/////////////////////////////////////////////////////////////////////////
// $Id: bxcompat.h 14074 2021-01-09 16:51:52Z vruppert $
/////////////////////////////////////////////////////////////////////////



#ifndef BX_COMPAT_H
#define BX_COMPAT_H

// copied from bochs.h

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef _MSC_VER
#include <unistd.h>
#else
#  include <io.h>
#endif

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// definitions for compatibility with Bochs
#ifndef UNUSED
#  define UNUSED(x) ((void)x)
#endif

#include <winioctl.h>
#include <fileapi.h>


#ifdef BXIMAGE
#define BX_DEBUG(x)
#define BX_INFO(x)  { if (bx_interactive) { (printf) x ; printf("\n"); } }
#define BX_ERROR(x) { (printf) x ; printf("\n"); }
#define BX_PANIC(x) { (printf) x ; printf("\n"); myexit(1); }
#define BX_FATAL(x) { (printf) x ; printf("\n"); myexit(1); }
#else
#define BX_DEBUG(x) { if (bx_loglev == 3) { (bx_printf) x ; } }
#define BX_INFO(x)  { if (bx_loglev >= 2) { (bx_printf) x ; } }
#define BX_ERROR(x) { if (bx_loglev >= 1) { (bx_printf) x ; } }
#endif
#define BX_ASSERT(x)

#ifdef BXIMAGE
extern int bx_interactive;

class device_image_t;

void myexit(int code);
device_image_t* init_image(const char *image_mode);

void create_flat_image_win32(const char* filename, Bit64u size)
{
    HANDLE hFile;
    LARGE_INTEGER pos;
    DWORD dwCount, errCode;
    USHORT mode;
    char buffer[1024];

    //TODO
    hFile = NULL;/*CreateFile
    (filename, 
        GENERIC_WRITE | GENERIC_READ, 0, 
        NULL, 
        CREATE_ALWAYS, 
        FILE_ATTRIBUTE_NORMAL, 
        NULL);*/
    
    if (hFile == INVALID_HANDLE_VALUE) 
    {
        // attempt to print an error
#ifdef HAVE_PERROR
        sprintf(buffer, "while opening '%s' for writing", filename);
        perror(buffer);
#endif
        //fatal("ERROR: Could not write disk image");
    }

    SetLastError(NO_ERROR);
    mode = COMPRESSION_FORMAT_DEFAULT;
    dwCount = 0;
    memset(buffer, 0, 512);
    WriteFile(hFile, buffer, 512, &dwCount, NULL); // set the first sector to 0, Win98 doesn't zero out the file
                                                   // if there is a write at/over the end

    //TODO
    /*
    bool b_res = DeviceIoControl
    (hFile,
        FSCTL_SET_COMPRESSION,
        &mode,
        sizeof(mode),
        NULL,
        0,
        &dwCount,
        NULL
    );
    */

    /*
    WINBASEAPI
    BOOL
    WINAPI
    DeviceIoControl(
    _In_ HANDLE hDevice,
    _In_ DWORD dwIoControlCode,
    _In_reads_bytes_opt_(nInBufferSize) LPVOID lpInBuffer,
    _In_ DWORD nInBufferSize,
    _Out_writes_bytes_to_opt_(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    _In_ DWORD nOutBufferSize,
    _Out_opt_ LPDWORD lpBytesReturned,
    _Inout_opt_ LPOVERLAPPED lpOverlapped
    );
    */

    pos.u.LowPart = (unsigned long)((size - 512));
    pos.u.HighPart = (unsigned long)((size - 512) >> 32);
    pos.u.LowPart = SetFilePointer(hFile, pos.u.LowPart, &pos.u.HighPart, FILE_BEGIN);
    memset(buffer, 0, 512);

    if ((pos.u.LowPart == 0xffffffff && GetLastError() != NO_ERROR) ||
        !WriteFile(hFile, buffer, 512, &dwCount, NULL) || (dwCount != 512))
    {
        errCode = GetLastError();
        CloseHandle(hFile);

        if (errCode == ERROR_DISK_FULL)
        {
            //fatal("\nERROR: Not enough space on disk for image!");
        }
        else
        {
#pragma warning(suppress : 4996)
            sprintf(buffer, "\nERROR: Disk image creation failed with error code %i!", errCode);
            //fatal(buffer);
        }
    }

    CloseHandle(hFile);
}

#define DEV_hdimage_init_image(a,b,c) init_image(a)

#else

#define BX_PATHNAME_LEN 512

extern int bx_loglev;

#endif

#endif
