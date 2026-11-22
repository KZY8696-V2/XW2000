#include "xw2000_api_common.h"

void xw_impl_SetLastError(XW_APIS_DWORD dwErrCode) {
    xw_state_set_last_error(dwErrCode);
}

__attribute__((weak)) void SetLastError(XW_APIS_DWORD dwErrCode) {
    xw_impl_SetLastError(dwErrCode);
}
