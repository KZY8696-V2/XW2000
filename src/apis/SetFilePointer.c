#include "xw2000_api_common.h"

XW_APIS_DWORD xw_impl_SetFilePointer(XW_APIS_HANDLE hFile,
                                   XW_APIS_LONG lDistanceToMove,
                                   XW_APIS_LONG *lpDistanceToMoveHigh,
                                   XW_APIS_DWORD dwMoveMethod) {
    (void)lpDistanceToMoveHigh;
    XW_ApiFileBox *box = (XW_ApiFileBox *)hFile;
    if (!box || !box->fp) {
        xw_state_set_last_error(XW_ERR_INVALID_HANDLE);
        return 0xFFFFFFFFu;
    }
    int origin = SEEK_SET;
    if (dwMoveMethod == XW_SEEK_CURRENT) origin = SEEK_CUR;
    else if (dwMoveMethod == XW_SEEK_END) origin = SEEK_END;

    if (fseek(box->fp, (long)lDistanceToMove, origin) != 0) {
        return 0xFFFFFFFFu;
    }
    long pos = ftell(box->fp);
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return (pos >= 0) ? (XW_APIS_DWORD)pos : 0xFFFFFFFFu;
}

__attribute__((weak)) XW_APIS_DWORD SetFilePointer(XW_APIS_HANDLE hFile,
                                                   XW_APIS_LONG lDistanceToMove,
                                                   XW_APIS_LONG *lpDistanceToMoveHigh,
                                                   XW_APIS_DWORD dwMoveMethod) {
    return xw_impl_SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod);
}
