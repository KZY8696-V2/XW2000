#ifndef XW2000_API_COMMON_H
#define XW2000_API_COMMON_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void    *XW_APIS_HANDLE;
typedef uint32_t XW_APIS_DWORD;
typedef int32_t  XW_APIS_LONG;
typedef int      XW_APIS_BOOL;

typedef union {
    struct {
        XW_APIS_DWORD LowPart;
        XW_APIS_LONG  HighPart;
    } u;
    int64_t QuadPart;
} XW_APIS_LARGE_INTEGER;

#define XW_APIS_INVALID_HANDLE ((XW_APIS_HANDLE)(intptr_t)-1)
#define XW_APIS_SAFE_RAM_BYTES (48u * 1024u * 1024u)

#define XW_ERR_SUCCESS         0u
#define XW_ERR_FILE_NOT_FOUND  2u
#define XW_ERR_ACCESS_DENIED   5u
#define XW_ERR_INVALID_HANDLE  6u
#define XW_ERR_NOT_ENOUGH_MEM  8u
#define XW_ERR_BAD_ARGUMENTS   160u

#define XW_SEEK_BEGIN          0u
#define XW_SEEK_CURRENT        1u
#define XW_SEEK_END            2u

typedef struct {
    FILE *fp;
    int   writable;
} XW_ApiFileBox;

XW_APIS_DWORD xw_state_get_last_error(void);
void          xw_state_set_last_error(XW_APIS_DWORD err);

#ifdef __cplusplus
}
#endif

#endif
