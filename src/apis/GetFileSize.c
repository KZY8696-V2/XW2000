#include "xw2000_api_common.h"

XW_APIS_DWORD xw_impl_GetFileSize(XW_APIS_HANDLE hFile, XW_APIS_DWORD *lpFileSizeHigh) {
    if (lpFileSizeHigh) {
        *lpFileSizeHigh = 0u;
    }
    XW_ApiFileBox *box = (XW_ApiFileBox *)hFile;
    if (!box || !box->fp) {
        xw_state_set_last_error(XW_ERR_INVALID_HANDLE);
        return 0xFFFFFFFFu;
    }
    long cur = ftell(box->fp);
    if (fseek(box->fp, 0, SEEK_END) != 0) {
        return 0xFFFFFFFFu;
    }
    long sz = ftell(box->fp);
    if (cur >= 0) {
        fseek(box->fp, cur, SEEK_SET);
    }
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return (sz >= 0) ? (XW_APIS_DWORD)sz : 0xFFFFFFFFu;
}

__attribute__((weak)) XW_APIS_DWORD GetFileSize(XW_APIS_HANDLE hFile, XW_APIS_DWORD *lpFileSizeHigh) {
    return xw_impl_GetFileSize(hFile, lpFileSizeHigh);
}
