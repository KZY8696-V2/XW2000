#include "xw2000_api_common.h"
#include "xw2000_native_fs.h"

XW_APIS_BOOL xw_impl_DeleteFileA(const char *lpFileName) {
    if (!lpFileName || lpFileName[0] == '\0') {
        xw_state_set_last_error(XW_ERR_BAD_ARGUMENTS);
        return 0;
    }
    if (xw2000_native_fs_check_write(lpFileName, 0u, 8u, 48u, 0) != 0) {
        xw_state_set_last_error(XW_ERR_ACCESS_DENIED);
        return 0;
    }
    if (remove(lpFileName) == 0) {
        xw_state_set_last_error(XW_ERR_SUCCESS);
        return 1;
    }
    xw_state_set_last_error(XW_ERR_FILE_NOT_FOUND);
    return 0;
}

__attribute__((weak)) XW_APIS_BOOL DeleteFileA(const char *lpFileName) {
    return xw_impl_DeleteFileA(lpFileName);
}
