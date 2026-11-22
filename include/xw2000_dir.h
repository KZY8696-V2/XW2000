#ifndef XW2000_DIR_H
#define XW2000_DIR_H

#include "xw2000_native_fs.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void    *XW_DIR_HANDLE;
typedef uint32_t XW_ATTR_DWORD;
typedef int      XW_DIR_BOOL;

#define XW_INVALID_DIR_HANDLE ((XW_DIR_HANDLE)(intptr_t)-1)
#define XW_FILE_ATTRIBUTE_DIRECTORY 0x00000010u
#define XW_FILE_ATTRIBUTE_NORMAL    0x00000080u

typedef struct {
    XW_ATTR_DWORD dwFileAttributes;
    char          cFileName[260];
    uint32_t      nFileSizeLow;
} XW_WIN32_FIND_DATAA;

XW_DIR_BOOL   CreateDirectoryA(const char *lpPathName, void *lpSecurityAttributes);
XW_DIR_BOOL   RemoveDirectoryA(const char *lpPathName);
XW_ATTR_DWORD GetCurrentDirectoryA(XW_ATTR_DWORD nBufferLength, char *lpBuffer);
XW_DIR_BOOL   SetCurrentDirectoryA(const char *lpPathName);

XW_DIR_HANDLE FindFirstFileA(const char *lpFileName, XW_WIN32_FIND_DATAA *lpFindFileData);
XW_DIR_BOOL   FindNextFileA(XW_DIR_HANDLE hFindFile, XW_WIN32_FIND_DATAA *lpFindFileData);
XW_DIR_BOOL   FindClose(XW_DIR_HANDLE hFindFile);

#ifdef __cplusplus
}
#endif

#endif
