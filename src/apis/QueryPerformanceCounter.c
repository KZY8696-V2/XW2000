#include "xw2000_api_common.h"
#include <time.h>

XW_APIS_BOOL xw_impl_QueryPerformanceCounter(XW_APIS_LARGE_INTEGER *lpPerformanceCount) {
    if (!lpPerformanceCount) {
        xw_state_set_last_error(XW_ERR_BAD_ARGUMENTS);
        return 0;
    }
#if defined(CLOCK_MONOTONIC)
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0) {
        lpPerformanceCount->QuadPart =
            (int64_t)ts.tv_sec * 1000000000LL + (int64_t)ts.tv_nsec;
        xw_state_set_last_error(XW_ERR_SUCCESS);
        return 1;
    }
#endif
    lpPerformanceCount->QuadPart = (int64_t)clock();
    xw_state_set_last_error(XW_ERR_SUCCESS);
    return 1;
}

__attribute__((weak)) XW_APIS_BOOL QueryPerformanceCounter(XW_APIS_LARGE_INTEGER *lpPerformanceCount) {
    return xw_impl_QueryPerformanceCounter(lpPerformanceCount);
}
