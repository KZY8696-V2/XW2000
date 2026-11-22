#include "xw2000_api_common.h"
#include <stdlib.h>

XW_APIS_BOOL xw_impl_HeapFree(XW_APIS_HANDLE hHeap, XW_APIS_DWORD dwFlags, void *lpMem) {
    (void)hHeap;
    (void)dwFlags;
    if (!lpMem) {
        xw_state_set_last_error(XW_ERR_SUCCESS);
        return 1;
    }
    free(lpMem);
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return 1;
}

__attribute__((weak)) XW_APIS_BOOL HeapFree(XW_APIS_HANDLE hHeap, XW_APIS_DWORD dwFlags, void *lpMem) {
    return xw_impl_HeapFree(hHeap, dwFlags, lpMem);
}
