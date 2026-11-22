#include "xw2000_api_common.h"

XW_APIS_BOOL xw_impl_WriteFile(XW_APIS_HANDLE hFile,
                               const void *lpBuffer,
                               XW_APIS_DWORD nNumberOfBytesToWrite,
                               XW_APIS_DWORD *lpNumberOfBytesWritten) {
    XW_ApiFileBox *box = (XW_ApiFileBox *)hFile;
    if (!box || !box->fp || !box->writable || !lpBuffer) {
        xw_state_set_last_error(XW_ERR_INVALID_HANDLE);
        return 0;
    }
    size_t n = fwrite(lpBuffer, 1u, (size_t)nNumberOfBytesToWrite, box->fp);
    if (lpNumberOfBytesWritten) {
        *lpNumberOfBytesWritten = (XW_APIS_DWORD)n;
    }
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return (n == (size_t)nNumberOfBytesToWrite) ? 1 : 0;
}

__attribute__((weak)) XW_APIS_BOOL WriteFile(XW_APIS_HANDLE hFile,
                                               const void *lpBuffer,
                                               XW_APIS_DWORD nNumberOfBytesToWrite,
                                               XW_APIS_DWORD *lpNumberOfBytesWritten,
                                               void *lpOverlapped) {
    (void)lpOverlapped;
    return xw_impl_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten);
}
