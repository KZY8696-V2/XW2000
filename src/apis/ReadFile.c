#include "xw2000_api_common.h"

XW_APIS_BOOL xw_impl_ReadFile(XW_APIS_HANDLE hFile,
                              void *lpBuffer,
                              XW_APIS_DWORD nNumberOfBytesToRead,
                              XW_APIS_DWORD *lpNumberOfBytesRead) {
    XW_ApiFileBox *box = (XW_ApiFileBox *)hFile;
    if (!box || !box->fp || !lpBuffer) {
        xw_state_set_last_error(XW_ERR_INVALID_HANDLE);
        return 0;
    }
    size_t n = fread(lpBuffer, 1u, (size_t)nNumberOfBytesToRead, box->fp);
    if (lpNumberOfBytesRead) {
        *lpNumberOfBytesRead = (XW_APIS_DWORD)n;
    }
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return 1;
}

__attribute__((weak)) XW_APIS_BOOL ReadFile(XW_APIS_HANDLE hFile,
                                              void *lpBuffer,
                                              XW_APIS_DWORD nNumberOfBytesToRead,
                                              XW_APIS_DWORD *lpNumberOfBytesRead,
                                              void *lpOverlapped) {
    (void)lpOverlapped;
    return xw_impl_ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead);
}
