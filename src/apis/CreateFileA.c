#include "xw2000_api_common.h"
#include "xw2000_native_fs.h"
#include <stdlib.h>

XW_APIS_HANDLE xw_impl_CreateFileA(const char *lpFileName,
                                   XW_APIS_DWORD dwDesiredAccess,
                                   int want_write) {
    if (!lpFileName || lpFileName[0] == '\0') {
        xw_state_set_last_error(XW_ERR_BAD_ARGUMENTS);
        return XW_APIS_INVALID_HANDLE;
    }

    if (want_write || ((dwDesiredAccess & 0x40000000u) != 0u)) {
        uint32_t used_mb = (uint32_t)(xw_state_get_heap_used() / (1024u * 1024u));
        if (xw2000_native_fs_check_write(lpFileName, 4096u, used_mb, 48u, 0) != 0) {
            xw_state_set_last_error(XW_ERR_ACCESS_DENIED);
            return XW_APIS_INVALID_HANDLE;
        }
    } else {
        const XW_NativeFsNode *node = xw2000_native_fs_lookup(lpFileName);
        if (!node || node->risk_level == XW_NAT_RISK_HARDWARE_BRICK) {
            xw_state_set_last_error(XW_ERR_ACCESS_DENIED);
            return XW_APIS_INVALID_HANDLE;
        }
    }

    FILE *fp = fopen(lpFileName, want_write ? "wb" : "rb");
    if (!fp) {
        xw_state_set_last_error(XW_ERR_FILE_NOT_FOUND);
        return XW_APIS_INVALID_HANDLE;
    }

    XW_ApiFileBox *box = (XW_ApiFileBox *)calloc(1, sizeof(XW_ApiFileBox));
    if (!box) {
        fclose(fp);
        xw_state_set_last_error(XW_ERR_NOT_ENOUGH_MEM);
        return XW_APIS_INVALID_HANDLE;
    }

    box->fp = fp;
    box->writable = want_write ? 1 : 0;
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return (XW_APIS_HANDLE)box;
}

__attribute__((weak)) XW_APIS_HANDLE CreateFileA(const char *lpFileName,
                                                 XW_APIS_DWORD dwDesiredAccess,
                                                 XW_APIS_DWORD dwShareMode,
                                                 void *lpSecurityAttributes,
                                                 XW_APIS_DWORD dwCreationDisposition,
                                                 XW_APIS_DWORD dwFlagsAndAttributes,
                                                 XW_APIS_HANDLE hTemplateFile) {
    (void)dwShareMode;
    (void)lpSecurityAttributes;
    (void)dwFlagsAndAttributes;
    (void)hTemplateFile;
    int want_write = (dwCreationDisposition == 2u || dwCreationDisposition == 4u ||
                      (dwDesiredAccess & 0x40000000u) != 0u);
    return xw_impl_CreateFileA(lpFileName, dwDesiredAccess, want_write);
}
