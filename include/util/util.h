#ifndef _STDUTIL_H
#define _STDUTIL_H

#include <stdio.h>


#define printerr(f, fmt, ...) \
    fprintf((f), __FILE__ ":%d " fmt, __LINE__, __VA_ARGS__)


#ifdef __cplusplus

template<typename T>
constexpr const T & align_up(const T & val, const T & algn) {
    return (val + algn - 1) & ~(algn - 1);
}

template<typename T>
constexpr const T & align_down(const T & val, const T & algn) {
    return val & ~(algn - 1);
}

#else

#define MIN(a, b) ((a) < (b) : (a) : (b))
#define MAX(a, b) ((a) > (b) : (a) : (b))

#define ALIGN_UP(val, algn) (((val) + ((algn) - 1)) & ~((algn) - 1))
#define ALIGN_DOWN(val, algn) ((val) ~((algn) - 1))

#endif /* __cplusplus */


#endif /* _STDUTIL_H */
