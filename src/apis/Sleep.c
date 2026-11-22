#include "xw2000_api_common.h"
#include <time.h>

#ifdef _WIN32
  #include <windows.h>
#endif

void xw_impl_Sleep(XW_APIS_DWORD dwMilliseconds) {
#ifdef _WIN32
    Sleep(dwMilliseconds);
#else
    struct timespec req;
    req.tv_sec = (time_t)(dwMilliseconds / 1000u);
    req.tv_nsec = (long)((dwMilliseconds % 1000u) * 1000000u);
    while (nanosleep(&req, &req) != 0) {
    }
#endif
    xw_state_set_last_error(XW_ERR_SUCCESS);
}

__attribute__((weak)) void Sleep(XW_APIS_DWORD dwMilliseconds) {
    xw_impl_Sleep(dwMilliseconds);
}
