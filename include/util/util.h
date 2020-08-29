#ifndef _STDUTIL_H
#define _STDUTIL_H

#include <stdio.h>


#define printerr(f, fmt, ...) \
    fprintf((f), __FILE__ ":%d " fmt, __LINE__, __VA_ARGS__)


#ifdef __cplusplus

template<typename T>
constexpr T & min(T a, T b) {
    return a < b ? a : b;
}

template<typename T>
inline T & min(const T & a, const T & b) {
    return a < b ? a : b;
}

template<typename T>
constexpr T & max(T a, T b) {
    return a < b ? b : a;
}

template<typename T>
inline T & max(const T & a, const T & b) {
    return a < b ? b : a;
}




#else

#define MIN(a, b) ((a) < (b) : (a) : (b))
#define MAX(a, b) ((a) > (b) : (a) : (b))

#define ALIGN_UP(val, algn) (((val) + ((algn) - 1)) & ~((algn) - 1))
#define ALIGN_DOWN(val, algn) ((val) ~((algn) - 1))

#endif /* __cplusplus */


#endif /* _STDUTIL_H */
