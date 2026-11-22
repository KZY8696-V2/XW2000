#include "xw2000_api_common.h"

static XW_APIS_DWORD g_xw_last_error = XW_ERR_SUCCESS;
static size_t        g_xw_heap_used  = 8u * 1024u * 1024u;

XW_APIS_DWORD xw_state_get_last_error(void) {
    return g_xw_last_error;
}

void xw_state_set_last_error(XW_APIS_DWORD err) {
    g_xw_last_error = err;
}

size_t xw_state_get_heap_used(void) {
    return g_xw_heap_used;
}

void xw_state_add_heap_used(size_t bytes) {
    if (g_xw_heap_used + bytes <= XW_APIS_SAFE_RAM_BYTES) {
        g_xw_heap_used += bytes;
    } else {
        g_xw_heap_used = XW_APIS_SAFE_RAM_BYTES;
    }
}

void xw_state_sub_heap_used(size_t bytes) {
    if (g_xw_heap_used >= bytes) {
        g_xw_heap_used -= bytes;
    } else {
        g_xw_heap_used = 0u;
    }
}

XW_APIS_DWORD xw_impl_GetLastError(void) {
    return xw_state_get_last_error();
}

__attribute__((weak)) XW_APIS_DWORD GetLastError(void) {
    return xw_impl_GetLastError();
}
