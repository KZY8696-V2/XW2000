#include "xw2000_api_common.h"
#include <time.h>

#ifdef _WIN32
  #include <windows.h>
#endif

XW_APIS_DWORD xw_impl_GetTickCount(void) {
#ifdef _WIN32
    return (XW_APIS_DWORD)GetTickCount();
#elif defined(CLOCK_MONOTONIC)
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
        xw_state_set_last_error(XW_ERR_SUCCESS);
        return (XW_APIS_DWORD)((uint64_t)ts.tv_sec * 1000u + (uint64_t)ts.tv_nsec / 1000000u);
    }
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return (XW_APIS_DWORD)(((uint64_t)clock() * 1000u) / CLOCKS_PER_SEC);
#else
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return (XW_APIS_DWORD)(((uint64_t)clock() * 1000u) / CLOCKS_PER_SEC);
#endif
}

__attribute__((weak)) XW_APIS_DWORD GetTickCount(void) {
    return xw_impl_GetTickCount();
}
