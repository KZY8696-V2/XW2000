#include "xw2000_api_common.h"
#include <stdlib.h>

XW_APIS_BOOL xw_impl_CloseHandle(XW_APIS_HANDLE hObject) {
    XW_ApiFileBox *box = (XW_ApiFileBox *)hObject;
    if (!box || hObject == XW_APIS_INVALID_HANDLE) {
        xw_state_set_last_error(XW_ERR_INVALID_HANDLE);
        return 0;
    }
    if (box->fp) {
        fclose(box->fp);
    }
    free(box);
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return 1;
}

__attribute__((weak)) XW_APIS_BOOL CloseHandle(XW_APIS_HANDLE hObject) {
    return xw_impl_CloseHandle(hObject);
}
