#include "xw2000_api_common.h"
#include <stdlib.h>
#include <string.h>

void *xw_impl_HeapAlloc(XW_APIS_HANDLE hHeap, XW_APIS_DWORD dwFlags, size_t dwBytes) {
    (void)hHeap;
    if (dwBytes == 0u) {
        dwBytes = 1u;
    }
    if (xw_state_get_heap_used() + dwBytes > XW_APIS_SAFE_RAM_BYTES) {
        fprintf(stderr, "[RAM_GUARD] HeapAlloc exceeds 48 MB safe Xbox budget (+%zu bytes)\n",
                dwBytes);
        xw_state_set_last_error(XW_ERR_NOT_ENOUGH_MEM);
        return NULL;
    }

    void *p = malloc(dwBytes);
    if (!p) {
        xw_state_set_last_error(XW_ERR_NOT_ENOUGH_MEM);
        return NULL;
    }
    if (dwFlags & 0x00000008u) {
        memset(p, 0, dwBytes);
    }
    xw_state_add_heap_used(dwBytes);
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return p;
}

__attribute__((weak)) void *HeapAlloc(XW_APIS_HANDLE hHeap, XW_APIS_DWORD dwFlags, size_t dwBytes) {
    return xw_impl_HeapAlloc(hHeap, dwFlags, dwBytes);
}
