#ifndef _STDUTIL_H
#define _STDUTIL_H

#include <stdio.h>
#include <stdint.h>


#define printerr(f, fmt, ...) \
    fprintf((f), __FILE__ ":%d " fmt, __LINE__, __VA_ARGS__)


#ifdef __cplusplus

template<typename T>
constexpr const T align_up(const T & val, const T & algn) {
    return (val + algn - 1) & ~(algn - 1);
}

template<typename T>
constexpr const T align_down(const T & val, const T & algn) {
    return val & ~(algn - 1);
}




/*
 * returns 1 + index of the first set bit of val, or undefined if val is 0
 */
template<typename T>
constexpr const int ffs_unsafe(const T & val) {
    if constexpr (sizeof(val) > sizeof(uint32_t)) {
        return 1 + __builtin_ctzl(val);
    }
    else {
        return 1 + __builtin_ctz(val);
    }
}

/*
 * returns 1 + index of the first set bit of val, or 0 if val is 0
 */
template<typename T>
constexpr const int ffs_safe(const T & val) {
    if constexpr (sizeof(val) > sizeof(uint32_t)) {
        return __builtin_ffsl(val);
    }
    else {
        return __builtin_ffs(val);
    }
}

/*
 * returns 1 + index of the last set bit of val, or undefined if val is 0
 */
template<typename T>
constexpr const T fls_unsafe(const T & val) {
    if constexpr (sizeof(val) > sizeof(uint32_t)) {
        return 8 * sizeof(T) - __builtin_clzl(val);
    }
    else {
        return 8 * sizeof(T) - __builtin_clz(val);
    }
}


/*
 * returns 1 + index of the last set bit of val, or 0 if val is 0
 */
template<typename T>
constexpr const T fls_safe(const T & val) {
    if (val == 0) {
        return 0;
    }
    else {
        return fls_unsafe(val);
    }
}



#else

#define MIN(a, b) ((a) < (b) : (a) : (b))
#define MAX(a, b) ((a) > (b) : (a) : (b))

#define ALIGN_UP(val, algn) (((val) + ((algn) - 1)) & ~((algn) - 1))
#define ALIGN_DOWN(val, algn) ((val) ~((algn) - 1))

#endif /* __cplusplus */


#endif /* _STDUTIL_H */
